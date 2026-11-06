/*
 * Copyright (c) 2025 Li Auto Inc. and its affiliates
 * Licensed under the Apache License, Version 2.0(the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*!*********************************************************************************************************************
 * @file        MinimalSystem.c
 * @brief       ECU status / command supervision software component
 * @details     Implements SYS-INI-001/003, SYS-COM-002/004/005,
 *              SYS-FUN-001/002 and SYS-DIA-001..005.
 *
 *              The port data exchange is implicit S/R: the state is refreshed
 *              through the generated RTE macros
 *                Rte_IRead_MinimalSystem_10ms_CmdControl_R_<element>()
 *                Rte_IWrite_MinimalSystem_10ms_<port>_<element>(value)
 *              Rte_MinimalSystem.h provides no Rte_Read_<port>_<element>() /
 *              Rte_Write_<port>_<element>() functions for this SWC; the RTE
 *              task body (Rte_SystemApplication_Core0.c) performs the Com
 *              exchange around this runnable (Com PDU is not accessed here).
 **********************************************************************************************************************/

#include <stdio.h>

#include "Rte_MinimalSystem.h" /* generated RTE: implicit S/R macros, types */
#include "MinimalSystem.h"

/* Period of the calling runnable (OsTask_10ms, SchTbl_10ms) */
#define MS_CYCLE_MS                    (10u)

/* SYS-DIA-001: no valid Cmd_Control for more than 500 ms */
#define MS_CMD_TIMEOUT_MS              (500u)

/* SYS-COM-005: alive counter cadence inside the 10 ms runnable (100 ms) */
#define MS_ALIVE_TICKS                 (10u)

/* SYS-DIA-004: calibratable under-voltage threshold (default 9000 mV) */
#ifndef MS_UNDERVOLTAGE_THRESHOLD_MV
#define MS_UNDERVOLTAGE_THRESHOLD_MV   (9000u)
#endif

/* SYS-FUN-002: simulated supply voltage default (raw = mV / 10) */
#define MS_SUPPLY_VOLTAGE_MV_DEFAULT   (12000u)

/* SYS-FUN-002: board temperature raw = physical + 40 (25 degC -> 65) */
#define MS_BOARD_TEMPERATURE_C         (25)
#define MS_TEMPERATURE_RAW_OFFSET      (40u)

/* Cmd_Control DBC layout */
#define MS_CMD_FRAME_SIZE              (8u)
#define MS_CMD_CRC_COVERED_BYTES       (7u) /* bytes 0..6, byte 7 = Cmd_Crc8 */
#define MS_CMD_ALIVE_MASK              (0x0Fu)
#define MS_CMD_TARGET_MASK             (0x07u)
#define MS_CMD_LED_MASK                (0x01u)

/* SYS-FUN-001: PwmDuty physical value = raw * 0.5 -> 0..100 % */
#define MS_PWM_DUTY_MAX                (100u)

static uint8 s_ecu_state;
static uint8 s_fault_flags;
static uint8 s_fault_code;
static uint8 s_target_mode;

static uint8 s_last_rx_alive;
static uint8 s_rx_alive_seen;
static uint8 s_rx_latched;      /* first Com read only latches the baseline */
static uint32 s_rx_signature;

static uint32 s_elapsed_ms;
static uint32 s_last_valid_cmd_ms;
static uint8 s_tx_alive;
static uint16 s_supply_voltage_mv;

static uint8 s_fault_active_sent;
static uint8 s_fault_code_sent;

/*--------------------------------------------------------------------------------------------------------------------*/
/* Helpers                                                                                                            */
/*--------------------------------------------------------------------------------------------------------------------*/

/* SYS-DIA-002: CRC8 SAE J1850, poly 0x1D, init 0xFF, xorout 0xFF */
uint8 MinimalSystem_Crc8SaeJ1850(const uint8 *data, uint32 length)
{
    uint8 crc = 0xFFu;
    uint32 idx;
    uint8 bit;

    if (data == NULL_PTR) {
        return 0u;
    }

    for (idx = 0u; idx < length; idx++) {
        crc = (uint8)(crc ^ data[idx]);
        for (bit = 0u; bit < 8u; bit++) {
            if ((crc & 0x80u) != 0u) {
                crc = (uint8)((uint8)(crc << 1) ^ 0x1Du);
            } else {
                crc = (uint8)(crc << 1);
            }
        }
    }

    return (uint8)(crc ^ 0xFFu);
}

/* SYS-DIA-001..004: Fault_Event.FaultCode priority */
static uint8 ms_fault_code_from_flags(uint8 flags)
{
    uint8 code = MINIMALSYSTEM_CODE_NO_FAULT;

    if ((flags & MINIMALSYSTEM_FLAG_CMD_TIMEOUT) != 0u) {
        code = MINIMALSYSTEM_CODE_CMD_TIMEOUT;
    } else if ((flags & MINIMALSYSTEM_FLAG_CMD_CRC) != 0u) {
        code = MINIMALSYSTEM_CODE_CMD_CRC;
    } else if ((flags & MINIMALSYSTEM_FLAG_CMD_ALIVE) != 0u) {
        code = MINIMALSYSTEM_CODE_CMD_ALIVE;
    } else if ((flags & MINIMALSYSTEM_FLAG_UNDERVOLTAGE) != 0u) {
        code = MINIMALSYSTEM_CODE_UNDERVOLTAGE;
    } else {
        /* no active fault */
    }

    return code;
}

/* SYS-FUN-001: LED on/off and PWM duty (0..100 %) are forwarded to IoHwAb */
static void ms_apply_actuators(uint8 led_cmd, uint8 pwm_raw)
{
    boolean led_on = ((led_cmd & MS_CMD_LED_MASK) != 0u) ? TRUE : FALSE;
    uint8 duty = (uint8)(pwm_raw / 2u);

    if (duty > MS_PWM_DUTY_MAX) {
        duty = MS_PWM_DUTY_MAX;
    }

    Rte_IWrite_MinimalSystem_10ms_IoOut_P_LedState(led_on);
    Rte_IWrite_MinimalSystem_10ms_IoOut_P_PwmDuty(duty);
}

/* SYS-COM-002: ECU_Status content is refreshed every 10 ms, Com is periodic 100 ms */
static void ms_update_status_tx(void)
{
    uint8 temperature = (uint8)((uint8)MS_BOARD_TEMPERATURE_C + MS_TEMPERATURE_RAW_OFFSET);
    uint16 supply_voltage = (uint16)(s_supply_voltage_mv / 10u);

    Rte_IWrite_MinimalSystem_10ms_EcuStatus_P_ECU_State(s_ecu_state);
    Rte_IWrite_MinimalSystem_10ms_EcuStatus_P_ECU_AliveCnt(s_tx_alive);
    Rte_IWrite_MinimalSystem_10ms_EcuStatus_P_Temperature(temperature);
    Rte_IWrite_MinimalSystem_10ms_EcuStatus_P_SupplyVoltage(supply_voltage);
    Rte_IWrite_MinimalSystem_10ms_EcuStatus_P_FaultFlags(s_fault_flags);
}

/*--------------------------------------------------------------------------------------------------------------------*/
/* Cmd_Control handling (SYS-DIA-002, SYS-DIA-003, SYS-INI-003, SYS-FUN-001)                                          */
/*--------------------------------------------------------------------------------------------------------------------*/

static void ms_process_cmd(uint8 led_cmd, uint8 target_mode, uint8 alive, uint8 pwm_raw, uint8 crc_received)
{
    uint8 frame[MS_CMD_FRAME_SIZE];
    uint8 crc_calculated;

    /* SYS-DIA-002: rebuild the Cmd_Control bytes that carry the CRC:
     * byte0 = LedCmd(bit0) | TargetMode(bits1..3) | Cmd_AliveCnt(bits4..7),
     * byte1 = PwmDuty, bytes 2..6 = 0 (not decoded as signals),
     * byte7 = Cmd_Crc8 (not covered). */
    frame[0] = (uint8)((led_cmd & MS_CMD_LED_MASK) |
                       ((target_mode & MS_CMD_TARGET_MASK) << 1) |
                       ((alive & MS_CMD_ALIVE_MASK) << 4));
    frame[1] = pwm_raw;
    frame[2] = 0u;
    frame[3] = 0u;
    frame[4] = 0u;
    frame[5] = 0u;
    frame[6] = 0u;
    frame[7] = crc_received;

    crc_calculated = MinimalSystem_Crc8SaeJ1850(frame, MS_CMD_CRC_COVERED_BYTES);
    if (crc_calculated != crc_received) {
        /* discard frame, raise CmdCrcError, no timeout refresh */
        s_fault_flags = (uint8)(s_fault_flags | MINIMALSYSTEM_FLAG_CMD_CRC);
        printf("[MinimalSystem] Cmd_Control CRC error: got 0x%02X expected 0x%02X\n",
               (unsigned)crc_received, (unsigned)crc_calculated);
        return;
    }

    s_fault_flags = (uint8)(s_fault_flags & (uint8)(~MINIMALSYSTEM_FLAG_CMD_CRC));

    /* SYS-DIA-003: Cmd_AliveCnt has to be previous + 1 (mod 16) */
    if (s_rx_alive_seen != 0u) {
        uint8 expected = (uint8)((s_last_rx_alive + 1u) & MS_CMD_ALIVE_MASK);

        if (alive != expected) {
            s_fault_flags = (uint8)(s_fault_flags | MINIMALSYSTEM_FLAG_CMD_ALIVE);
            printf("[MinimalSystem] Cmd_Control alive error: got %u expected %u\n",
                   (unsigned)alive, (unsigned)expected);
        } else {
            s_fault_flags = (uint8)(s_fault_flags & (uint8)(~MINIMALSYSTEM_FLAG_CMD_ALIVE));
        }
    } else {
        s_rx_alive_seen = 1u;
    }
    s_last_rx_alive = alive;

    /* a CRC-valid frame restarts the SYS-DIA-001 supervision */
    s_last_valid_cmd_ms = s_elapsed_ms;
    s_fault_flags = (uint8)(s_fault_flags & (uint8)(~MINIMALSYSTEM_FLAG_CMD_TIMEOUT));

    /* SYS-INI-003: TargetMode = Normal on a valid command -> Normal state */
    s_target_mode = (uint8)(target_mode & MS_CMD_TARGET_MASK);
    ms_apply_actuators(led_cmd, pwm_raw);
}

/*--------------------------------------------------------------------------------------------------------------------*/
/* Runnables                                                                                                           */
/*--------------------------------------------------------------------------------------------------------------------*/

void MinimalSystem_Init(void)
{
    /* SYS-INI-001: start in Init; the first 10 ms cycle moves to Standby */
    s_ecu_state = MINIMALSYSTEM_STATE_INIT;
    s_fault_flags = 0u;
    s_fault_code = MINIMALSYSTEM_CODE_NO_FAULT;
    s_target_mode = MINIMALSYSTEM_TARGET_MODE_OFF;

    s_last_rx_alive = 0u;
    s_rx_alive_seen = 0u;
    s_rx_latched = 0u;
    s_rx_signature = 0u;

    s_elapsed_ms = 0u;
    s_last_valid_cmd_ms = 0u;
    s_tx_alive = 0u;
    s_supply_voltage_mv = (uint16)MS_SUPPLY_VOLTAGE_MV_DEFAULT;

    s_fault_active_sent = 0u;
    s_fault_code_sent = MINIMALSYSTEM_CODE_NO_FAULT;

    /* seed ECU_Status so the very first Com period carries valid data (SYS-INI-002) */
    ms_update_status_tx();

    /* seed Fault_Event content, no transmission is requested here */
    Rte_IWrite_MinimalSystem_10ms_FaultEvent_P_FaultCode(MINIMALSYSTEM_CODE_NO_FAULT);
    Rte_IWrite_MinimalSystem_10ms_FaultEvent_P_FaultActive(0u);

    Rte_IWrite_MinimalSystem_10ms_IoOut_P_LedState(FALSE);
    Rte_IWrite_MinimalSystem_10ms_IoOut_P_PwmDuty(0u);

    printf("[MinimalSystem] init: state=%u supply=%umV\n",
           (unsigned)s_ecu_state, (unsigned)s_supply_voltage_mv);
}

void MinimalSystem_10ms(void)
{
    uint8 led_cmd;
    uint8 target_mode;
    uint8 alive;
    uint8 pwm_raw;
    uint8 crc_received;
    uint8 fault_active;
    uint8 previous_state;
    uint8 previous_code;
    uint32 signature;

    s_elapsed_ms += MS_CYCLE_MS;

    /* ---- Cmd_Control reception (implicit S/R refreshed by the RTE task) ---------------------- */
    led_cmd = (uint8)Rte_IRead_MinimalSystem_10ms_CmdControl_R_LedCmd();
    target_mode = (uint8)Rte_IRead_MinimalSystem_10ms_CmdControl_R_TargetMode();
    alive = (uint8)Rte_IRead_MinimalSystem_10ms_CmdControl_R_Cmd_AliveCnt();
    pwm_raw = (uint8)Rte_IRead_MinimalSystem_10ms_CmdControl_R_PwmDuty();
    crc_received = (uint8)Rte_IRead_MinimalSystem_10ms_CmdControl_R_Cmd_Crc8();

    /* A change of the decoded signal set is a new frame. The first read only
     * latches the Com baseline, so a silent tester does not raise a CRC error. */
    signature = (uint32)led_cmd |
                ((uint32)target_mode << 1) |
                ((uint32)alive << 4) |
                ((uint32)pwm_raw << 8) |
                ((uint32)crc_received << 16);

    if (s_rx_latched == 0u) {
        s_rx_latched = 1u;
        s_rx_signature = signature;
    } else if (signature != s_rx_signature) {
        s_rx_signature = signature;
        ms_process_cmd(led_cmd, target_mode, alive, pwm_raw, crc_received);
    } else {
        /* unchanged content, nothing new to validate */
    }

    /* ---- SYS-DIA-001: command timeout -------------------------------------------------------- */
    if ((uint32)(s_elapsed_ms - s_last_valid_cmd_ms) > MS_CMD_TIMEOUT_MS) {
        s_fault_flags = (uint8)(s_fault_flags | MINIMALSYSTEM_FLAG_CMD_TIMEOUT);
    }

    /* ---- SYS-DIA-004: under-voltage ---------------------------------------------------------- */
    if (s_supply_voltage_mv < (uint16)MS_UNDERVOLTAGE_THRESHOLD_MV) {
        s_fault_flags = (uint8)(s_fault_flags | MINIMALSYSTEM_FLAG_UNDERVOLTAGE);
    } else {
        s_fault_flags = (uint8)(s_fault_flags & (uint8)(~MINIMALSYSTEM_FLAG_UNDERVOLTAGE));
    }

    /* ---- fault / state resolution (fault > Normal > Standby) --------------------------------- */
    previous_state = s_ecu_state;
    previous_code = s_fault_code;

    s_fault_code = ms_fault_code_from_flags(s_fault_flags);
    fault_active = (s_fault_flags != 0u) ? 1u : 0u;

    if (fault_active != 0u) {
        s_ecu_state = MINIMALSYSTEM_STATE_FAULT;
    } else if (s_target_mode == MINIMALSYSTEM_TARGET_MODE_NORMAL) {
        s_ecu_state = MINIMALSYSTEM_STATE_NORMAL;
    } else {
        s_ecu_state = MINIMALSYSTEM_STATE_STANDBY; /* SYS-INI-001: Standby after init */
    }

    if (s_ecu_state != previous_state) {
        printf("[MinimalSystem] state %u -> %u (flags=0x%02X code=%u)\n",
               (unsigned)previous_state, (unsigned)s_ecu_state,
               (unsigned)s_fault_flags, (unsigned)s_fault_code);
    } else if (s_fault_code != previous_code) {
        printf("[MinimalSystem] fault code %u -> %u (flags=0x%02X)\n",
               (unsigned)previous_code, (unsigned)s_fault_code, (unsigned)s_fault_flags);
    } else {
        /* unchanged */
    }

    /* ---- SYS-COM-005: alive counter +1 per ECU_Status transmission (100 ms) ------------------- */
    if ((s_elapsed_ms % (MS_CYCLE_MS * MS_ALIVE_TICKS)) == 0u) {
        s_tx_alive = (uint8)((s_tx_alive + 1u) & MS_CMD_ALIVE_MASK);
    }

    ms_update_status_tx();

    /* ---- SYS-COM-004/005: Fault_Event only on a fault state change --------------------------- */
    if ((fault_active != s_fault_active_sent) || (s_fault_code != s_fault_code_sent)) {
        Rte_IWrite_MinimalSystem_10ms_FaultEvent_P_FaultCode(s_fault_code);
        Rte_IWrite_MinimalSystem_10ms_FaultEvent_P_FaultActive(fault_active);
        s_fault_active_sent = fault_active;
        s_fault_code_sent = s_fault_code;
        printf("[MinimalSystem] Fault_Event code=%u active=%u\n",
               (unsigned)s_fault_code, (unsigned)fault_active);
    }
}

/*--------------------------------------------------------------------------------------------------------------------*/
/* Test / integration hooks                                                                                            */
/*--------------------------------------------------------------------------------------------------------------------*/

uint8 MinimalSystem_GetState(void)
{
    return s_ecu_state;
}

uint8 MinimalSystem_GetFaultFlags(void)
{
    return s_fault_flags;
}

void MinimalSystem_SetSupplyVoltageMv(uint16 supply_voltage_mv)
{
    s_supply_voltage_mv = supply_voltage_mv;
}
