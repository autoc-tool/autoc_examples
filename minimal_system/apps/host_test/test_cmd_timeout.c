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

/*
 * Host evidence for SYS-DIA-001.
 *
 * MinimalSystem_10ms does not read the CAN driver. It reads the implicit
 * Cmd_Control signals and, when no CRC-valid frame has changed those signals
 * for more than 500 ms, sets FaultFlags bit0 and FaultCode 1.
 *
 * Cmd_Control on the bus (DBC BO_ 512, requirement SYS-COM-003):
 *   standard id 0x200, DLC 8, Tester cycle 100 ms
 *   byte0 = LedCmd(bit0) | TargetMode(bits1..3) | Cmd_AliveCnt(bits4..7)
 *   byte1 = PwmDuty raw (physical percent = raw * 0.5)
 *   byte2..6 = 0
 *   byte7 = CRC8 SAE J1850 over byte0..6
 *   TargetMode 2 = Normal, 1 = Standby, 0 = Off
 *   Cmd_AliveCnt must be previous + 1 (mod 16) on each new frame
 *
 * Golden frames produced with that layout:
 *   LED on, Normal, alive 0, 50% PWM: 05 64 00 00 00 00 00 43
 *   same, alive 1:                     15 64 00 00 00 00 00 FA
 */

#include <stdio.h>
#include <string.h>

#include "Rte_MinimalSystem.h"
#include "MinimalSystem.h"

uint8 g_cmd_led;
uint8 g_cmd_target;
uint8 g_cmd_alive;
uint8 g_cmd_pwm;
uint8 g_cmd_crc;
uint8 g_tx_state;
uint8 g_tx_alive;
uint8 g_tx_temp;
uint8 g_tx_flags;
uint16 g_tx_voltage;
uint8 g_fault_code;
uint8 g_fault_active;
uint8 g_led_on;
uint8 g_pwm_duty;

static int g_failures;

static void expect_eq_u(const char *name, unsigned got, unsigned want)
{
	if (got != want) {
		fprintf(stderr, "FAIL %s: got %u want %u\n", name, got, want);
		g_failures++;
	}
}

static void reset_inputs(void)
{
	g_cmd_led = 0u;
	g_cmd_target = 0u;
	g_cmd_alive = 0u;
	g_cmd_pwm = 0u;
	g_cmd_crc = 0u;
}

/* Rebuild the on-bus byte0 the same way MinimalSystem_10ms will. */
static uint8 cmd_byte0(uint8 led, uint8 target, uint8 alive)
{
	return (uint8)((led & 1u) | ((target & 7u) << 1) | ((alive & 15u) << 4));
}

static void present_cmd(uint8 led, uint8 target, uint8 alive, uint8 pwm_raw, int corrupt_crc)
{
	uint8 frame[8];

	frame[0] = cmd_byte0(led, target, alive);
	frame[1] = pwm_raw;
	frame[2] = 0u;
	frame[3] = 0u;
	frame[4] = 0u;
	frame[5] = 0u;
	frame[6] = 0u;
	frame[7] = MinimalSystem_Crc8SaeJ1850(frame, 7u);
	if (corrupt_crc) {
		frame[7] = (uint8)(frame[7] ^ 0xFFu);
	}

	g_cmd_led = led;
	g_cmd_target = target;
	g_cmd_alive = alive;
	g_cmd_pwm = pwm_raw;
	g_cmd_crc = frame[7];
}

static void test_crc_golden(void)
{
	uint8 normal0[7] = {0x05u, 0x64u, 0u, 0u, 0u, 0u, 0u};
	uint8 normal1[7] = {0x15u, 0x64u, 0u, 0u, 0u, 0u, 0u};

	expect_eq_u("crc normal alive0", MinimalSystem_Crc8SaeJ1850(normal0, 7u), 0x43u);
	expect_eq_u("crc normal alive1", MinimalSystem_Crc8SaeJ1850(normal1, 7u), 0xFAu);
}

/* No Cmd_Control: Init -> Standby on the first 10 ms, Fault code 1 at 510 ms. */
static void test_timeout_without_command(void)
{
	unsigned cycle;

	reset_inputs();
	MinimalSystem_Init();
	expect_eq_u("init state", MinimalSystem_GetState(), MINIMALSYSTEM_STATE_INIT);
	expect_eq_u("init flags", MinimalSystem_GetFaultFlags(), 0u);
	expect_eq_u("init fault code", g_fault_code, MINIMALSYSTEM_CODE_NO_FAULT);

	MinimalSystem_10ms();
	expect_eq_u("standby state", MinimalSystem_GetState(), MINIMALSYSTEM_STATE_STANDBY);
	expect_eq_u("standby flags", MinimalSystem_GetFaultFlags(), 0u);

	for (cycle = 2u; cycle <= 50u; cycle++) {
		MinimalSystem_10ms();
	}
	expect_eq_u("at 500ms state", MinimalSystem_GetState(), MINIMALSYSTEM_STATE_STANDBY);
	expect_eq_u("at 500ms flags", MinimalSystem_GetFaultFlags(), 0u);
	expect_eq_u("at 500ms code", g_fault_code, MINIMALSYSTEM_CODE_NO_FAULT);

	MinimalSystem_10ms();
	expect_eq_u("at 510ms state", MinimalSystem_GetState(), MINIMALSYSTEM_STATE_FAULT);
	expect_eq_u("at 510ms flags", MinimalSystem_GetFaultFlags(), MINIMALSYSTEM_FLAG_CMD_TIMEOUT);
	expect_eq_u("at 510ms code", g_fault_code, MINIMALSYSTEM_CODE_CMD_TIMEOUT);
	expect_eq_u("at 510ms active", g_fault_active, 1u);
	expect_eq_u("status flags mirror", g_tx_flags, MINIMALSYSTEM_FLAG_CMD_TIMEOUT);
	expect_eq_u("status state mirror", g_tx_state, MINIMALSYSTEM_STATE_FAULT);
}

/*
 * One valid frame is a new signature and clears the timer, but an unchanged
 * repeat is ignored. Alive must advance so the 100 ms cycle keeps refreshing
 * the 500 ms supervision window.
 */
static void test_cyclic_command_holds_normal(void)
{
	unsigned cycle;
	uint8 alive = 0u;

	reset_inputs();
	MinimalSystem_Init();
	MinimalSystem_10ms(); /* latch the zero Com baseline */
	expect_eq_u("latched standby", MinimalSystem_GetState(), MINIMALSYSTEM_STATE_STANDBY);

	for (cycle = 2u; cycle <= 200u; cycle++) {
		if (((cycle - 2u) % 10u) == 0u) {
			present_cmd(1u, MINIMALSYSTEM_TARGET_MODE_NORMAL, alive, 100u, 0);
			alive = (uint8)((alive + 1u) & 0x0Fu);
		}
		MinimalSystem_10ms();
	}

	expect_eq_u("cyclic state", MinimalSystem_GetState(), MINIMALSYSTEM_STATE_NORMAL);
	expect_eq_u("cyclic flags", MinimalSystem_GetFaultFlags(), 0u);
	expect_eq_u("cyclic code", g_fault_code, MINIMALSYSTEM_CODE_NO_FAULT);
	expect_eq_u("led on", g_led_on, 1u);
	expect_eq_u("pwm percent", g_pwm_duty, 50u);
}

/* A single valid frame does not hold the bus. The same bytes are not a new command. */
static void test_unchanged_frame_still_times_out(void)
{
	unsigned cycle;

	reset_inputs();
	MinimalSystem_Init();
	MinimalSystem_10ms();
	present_cmd(1u, MINIMALSYSTEM_TARGET_MODE_NORMAL, 0u, 100u, 0);
	MinimalSystem_10ms();
	expect_eq_u("one frame -> normal", MinimalSystem_GetState(), MINIMALSYSTEM_STATE_NORMAL);

	for (cycle = 0u; cycle < 60u; cycle++) {
		MinimalSystem_10ms();
	}
	expect_eq_u("stale frame state", MinimalSystem_GetState(), MINIMALSYSTEM_STATE_FAULT);
	expect_eq_u("stale frame flags", MinimalSystem_GetFaultFlags(), MINIMALSYSTEM_FLAG_CMD_TIMEOUT);
	expect_eq_u("stale frame code", g_fault_code, MINIMALSYSTEM_CODE_CMD_TIMEOUT);
}

/* A later valid, changing command leaves Fault and reports FaultActive 0. */
static void test_valid_command_clears_timeout(void)
{
	unsigned cycle;

	reset_inputs();
	MinimalSystem_Init();
	for (cycle = 0u; cycle < 51u; cycle++) {
		MinimalSystem_10ms();
	}
	expect_eq_u("precondition fault", MinimalSystem_GetState(), MINIMALSYSTEM_STATE_FAULT);

	present_cmd(1u, MINIMALSYSTEM_TARGET_MODE_NORMAL, 0u, 100u, 0);
	MinimalSystem_10ms();
	expect_eq_u("recovered state", MinimalSystem_GetState(), MINIMALSYSTEM_STATE_NORMAL);
	expect_eq_u("recovered flags", MinimalSystem_GetFaultFlags(), 0u);
	expect_eq_u("recovered code", g_fault_code, MINIMALSYSTEM_CODE_NO_FAULT);
	expect_eq_u("recovered active", g_fault_active, 0u);
}

static void test_bad_crc_does_not_refresh(void)
{
	unsigned cycle;

	reset_inputs();
	MinimalSystem_Init();
	MinimalSystem_10ms();
	present_cmd(1u, MINIMALSYSTEM_TARGET_MODE_NORMAL, 0u, 100u, 1);
	MinimalSystem_10ms();
	expect_eq_u("crc state", MinimalSystem_GetState(), MINIMALSYSTEM_STATE_FAULT);
	expect_eq_u("crc flags", MinimalSystem_GetFaultFlags(), MINIMALSYSTEM_FLAG_CMD_CRC);
	expect_eq_u("crc code", g_fault_code, MINIMALSYSTEM_CODE_CMD_CRC);
	expect_eq_u("crc does not move actuators", g_led_on, 0u);

	for (cycle = 0u; cycle < 51u; cycle++) {
		MinimalSystem_10ms();
	}
	expect_eq_u("crc then timeout flags", MinimalSystem_GetFaultFlags(),
		    (unsigned)(MINIMALSYSTEM_FLAG_CMD_TIMEOUT | MINIMALSYSTEM_FLAG_CMD_CRC));
	expect_eq_u("timeout outranks crc", g_fault_code, MINIMALSYSTEM_CODE_CMD_TIMEOUT);
}

int main(void)
{
	test_crc_golden();
	test_timeout_without_command();
	test_cyclic_command_holds_normal();
	test_unchanged_frame_still_times_out();
	test_valid_command_clears_timeout();
	test_bad_crc_does_not_refresh();

	if (g_failures != 0) {
		fprintf(stderr, "%d assertion(s) failed\n", g_failures);
		return 1;
	}
	printf("minimal_system cmd timeout tests passed\n");
	return 0;
}
