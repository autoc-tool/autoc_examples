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
 * @file        MinimalSystem.h
 * @brief       Private header of the MinimalSystem application software component
 * @details     Declares the runnable entities of
 *              gen_data/Rte/Rte_MinimalSystem.h and the value ranges of the
 *              Cmd_Control / ECU_Status / Fault_Event signals
 *              (SYS-INI, SYS-COM, SYS-FUN, SYS-DIA).
 **********************************************************************************************************************/

#ifndef MINIMALSYSTEM_H_
#define MINIMALSYSTEM_H_

#include "Std_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Schedulable entities; Rte_MinimalSystem.h declares them only for RTE_CORE
 * builds, the application declares/defines them here. */
void MinimalSystem_Init(void);
void MinimalSystem_10ms(void);

/* SYS-INI-001/SYS-INI-003: ECU state machine (DBC VAL_ 256 ECU_State) */
#define MINIMALSYSTEM_STATE_INIT    (0u)
#define MINIMALSYSTEM_STATE_STANDBY (1u)
#define MINIMALSYSTEM_STATE_NORMAL  (2u)
#define MINIMALSYSTEM_STATE_FAULT   (3u)

/* Cmd_Control.TargetMode (DBC VAL_ 512 TargetMode) */
#define MINIMALSYSTEM_TARGET_MODE_OFF     (0u)
#define MINIMALSYSTEM_TARGET_MODE_STANDBY (1u)
#define MINIMALSYSTEM_TARGET_MODE_NORMAL  (2u)

/* ECU_Status.FaultFlags bits (SYS-DIA-001..004) */
#define MINIMALSYSTEM_FLAG_CMD_TIMEOUT  (0x01u)
#define MINIMALSYSTEM_FLAG_CMD_CRC      (0x02u)
#define MINIMALSYSTEM_FLAG_CMD_ALIVE    (0x04u)
#define MINIMALSYSTEM_FLAG_UNDERVOLTAGE (0x08u)

/* Fault_Event.FaultCode (SYS-DIA-005, DBC VAL_ 768 FaultCode) */
#define MINIMALSYSTEM_CODE_NO_FAULT     (0u)
#define MINIMALSYSTEM_CODE_CMD_TIMEOUT  (1u)
#define MINIMALSYSTEM_CODE_CMD_CRC      (2u)
#define MINIMALSYSTEM_CODE_CMD_ALIVE    (3u)
#define MINIMALSYSTEM_CODE_UNDERVOLTAGE (4u)

/* SYS-DIA-002: CRC8 SAE J1850 (poly 0x1D, init 0xFF, xorout 0xFF) */
uint8 MinimalSystem_Crc8SaeJ1850(const uint8 *data, uint32 length);

/* Test / integration hooks */
uint8 MinimalSystem_GetState(void);
uint8 MinimalSystem_GetFaultFlags(void);

/* SYS-DIA-004: simulated supply voltage in mV (default 12000 mV) */
void MinimalSystem_SetSupplyVoltageMv(uint16 supply_voltage_mv);

#ifdef __cplusplus
}
#endif

#endif /* MINIMALSYSTEM_H_ */
