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
 * Generation Time : 2026-10-24 03:20:26
 * Project Name    : minimal_system
 * Tool Version    : V0.1.0-DEV
 * Description:  sysm_init 模块中所有Callout函数的源文件.
 */

/* Including File */
#if (VCOS_MODULE_CONFIG_VCOSMTNCE == 1)
#include "vcosMtnce_Cfg.h"
#endif
#include "sysm_init.h"
#include "sysm_init_generated_types.h"
#if (CONFIG_RT_FRAMEWORK == 1)
#include "Os.h"
#include "rtfw_atomic.h"
#include "core_cfg.h"
#endif
#include "vcos_log.h"
#include "sysm_init_vcos_log.h"
#include "sysm_init_internals.h"
#include "SchM_EcuM.h"

/* Modules from UI */
#include "det.h"
#include "crc.h"
#include "can.h"

/* Other Modules */
#include "Rte_Main.h"
#include "SchM_EcuM.h"
#if defined(CONFIG_SERVM_BSWM)
#include "bswm.h"
#endif
#if (VCOS_MODULE_CONFIG_SHELL == 1)
#include "Shell.h"
#endif

#ifdef INFRA_TEST_ENABLED
#if (VCOS_MODULE_CONFIG_AUTOTEST == 1)
#include "startup.h"
#include "sleep.h"
#endif
#endif

/* Version check */
#if !(((ECUM_CALLOUT_SW_MAJOR_VERSION == 3) && (ECUM_CALLOUT_SW_MINOR_VERSION == 0)) )
#error EcuM: Configuration file expected EcuM Callout version to be 3.0.X*
#endif

/******************USER CODE STARTS!************THIS COMMENT WILL BE SAVED!***************/
/******************USER CODE ENDS!**************THIS COMMENT WILL BE SAVED!***************/

/* Local Variable Definition */

#define  ECUM_START_SEC_CONST
#include "ecum_memmap.h"
extern CONST(ecum_config_t, ECUM_CONST) ecum_config;
#define  ECUM_STOP_SEC_CONST
#include "ecum_memmap.h"

#define ECUM_START_SEC_CODE
#include "ecum_memmap.h"
#if (VCOS_CONSOLE_CONFIG_UART == 1)
extern FUNC(void, ECUM_CODE) sys_io_init(void);
#endif
#if (VCOS_MODULE_CONFIG_SHELL == 1)
extern int shell_init(void);
#endif
#define ECUM_STOP_SEC_CODE
#include "ecum_memmap.h"

/* Local Macro Definition */
#define ECUM_START_SEC_MULTI_APP_BSS
#include "ecum_memmap.h"
volatile VAR(uint32, ECUM_MULTI_APP_BSS)  rte_sync_state;
#if(EcuM_INITPHASEDOT == 1u)
VAR(ecum_init_zero_time_t,ECUM_MULTI_APP_BSS)  ecum_init_zero_time;
VAR(ecum_init_one_time_t,ECUM_MULTI_APP_BSS)   ecum_init_one_time;
VAR(ecum_init_two_time_t,ECUM_MULTI_APP_BSS)   ecum_init_two_time;
VAR(ecum_init_three_time_t,ECUM_MULTI_APP_BSS) ecum_init_three_time;

#if (ECUM_NUMBER_OF_CORES > 1)


VAR(ecum_init_core1_time_struct_t,ECUM_MULTI_APP_BSS) ecum_core1_start_up_two_time;
#endif
#endif
#define ECUM_STOP_SEC_MULTI_APP_BSS
#include "ecum_memmap.h"

#define ECUM_START_SEC_CODE
#include "ecum_memmap.h"
static FUNC(void, ECUM_CODE) set_initsync_state(uint8 core_id){
	uint8 ret = 0u;
	uint8 retry_times  = 0u;
	while((retry_times < (ECUM_NUMBER_OF_CORES + 1u)) && (ret == 0u)){
		uint32 old_value = rte_sync_state;
		uint32 new_value = rte_sync_state | ((uint32)(1u) << (core_id));
		ret = (uint8)Os_AtomicCmpSwap((Atomic *)&rte_sync_state, (sint32)old_value, (sint32)new_value);
		retry_times ++;
	}
}

FUNC(void, ECUM_CODE) sync_on_rte_init_state(uint8 core_id){
	set_initsync_state(core_id);
	while(
		(((uint32)rte_sync_state) != ECUM_STARTSYNC)
		)
		{
		}
	if (core_id == ECUM_CORE_ID_BSW) {
		ecum_get_timmertick(ecum_rte_sync_time_value);
	} else {
#if (VCOS_MODULE_CONFIG_AUTOTEST == 1) && defined(INFRA_TEST_ENABLED)
		ecum_get_timmertick(get_rte_sync_core(core_id));
#else
		/* If not AUTOTEST or INFRA_TEST is not enabled */
#endif
	}
}

/* Local Fuction Implementation */

FUNC(void, ECUM_CODE) ecum_error_hook(uint16 reason)
{
/******************USER CODE STARTS!************THIS COMMENT WILL BE SAVED!***************/
	(void)reason;
#if (MCU_PERFORM_RESET_API == STD_ON)
	Mcu_PerformReset();
#else
	ASSERT(0);
#endif
/******************USER CODE ENDS!**************THIS COMMENT WILL BE SAVED!***************/
}

struct FUNC(ecum_config_s*, ECUM_CODE)  ecum_determine_pb_configuration(void)
{
/******************USER CODE STARTS!************THIS COMMENT WILL BE SAVED!***************/
/******************USER CODE ENDS!**************THIS COMMENT WILL BE SAVED!***************/
	return (ecum_config_t*)&ecum_config;
}
/* Part of STARTUP I */
FUNC(void, ECUM_CODE) ecum_al_driver_init_zero(void)
{
#if (CONFIG_RT_FRAMEWORK == 1)
	uint8 core_id = (uint8)GetCoreID();
#else
	uint8 core_id = 0u;
#endif
	if (core_id == ECUM_CORE_ID_BSW) {

	/* sysm_init module initialization started */
	ecum_get_timmertick(ecum_init_start_time);

	EcuMDriverInitItem(NULL_PTR);
	ecum_get_timmertick(ecum_init_zero_time.m_EcuMDriverInitItem);
	}
/******************USER CODE STARTS!************THIS COMMENT WILL BE SAVED!***************/
/******************USER CODE ENDS!**************THIS COMMENT WILL BE SAVED!***************/
	ecum_get_timmertick(ecum_init_zero_end_time);
}

FUNC(void, ECUM_CODE) ecum_al_driver_init_one(const ecum_config_t *config_ptr)
{
	(void)config_ptr;
	ecum_get_timmertick(ecum_init_one_start_time);

	EcuMDriverInitItem(NULL_PTR);
	ecum_get_timmertick(ecum_init_one_time.m_EcuMDriverInitItem);

/******************USER CODE STARTS!************THIS COMMENT WILL BE SAVED!***************/
/******************USER CODE ENDS!**************THIS COMMENT WILL BE SAVED!***************/
	ecum_get_timmertick(ecum_init_one_end_time);
}

/* Part of STARTUP II */
FUNC(void, ECUM_CODE) ecum_al_driver_init_two(const ecum_config_t* config_ptr)
{
	(void)config_ptr;
	ecum_get_timmertick(ecum_init_two_start_time);

	can_init(&can_config);
	ecum_get_timmertick(ecum_init_two_time.m_can_init);
/******************USER CODE STARTS!************THIS COMMENT WILL BE SAVED!***************/
/******************USER CODE ENDS!**************THIS COMMENT WILL BE SAVED!***************/
	ecum_get_timmertick(ecum_init_two_end_time);
}

/* Part of STARTUP II */
FUNC(void, ECUM_CODE) ecum_al_driver_init_three(const ecum_config_t* config_ptr)
{
	(void)config_ptr;
	ecum_get_timmertick(ecum_init_three_start_time);
/******************USER CODE STARTS!************THIS COMMENT WILL BE SAVED!***************/
/******************USER CODE ENDS!**************THIS COMMENT WILL BE SAVED!***************/
	ecum_get_timmertick(ecum_init_three_end_time);
}

/* Multi-core initialization */
#if (ECUM_NUMBER_OF_CORES > 1)
FUNC(void, ECUM_CODE) ecum_al_driver_init_multi_core(void)
{
	uint32 core_id = (uint32)GetCoreID();
	if (core_id == OS_CORE_ID_0){
#if ((CONFIG_RT_FRAMEWORK == 1) && (EcuM_INITPHASEDOT == 1u))
		(void)VCOS_LOG(ECUM_MODULE_ID, VCOS_LOG_INFO, ECUM_DLT_STARTUP_TIME_DEFAULT,
				   ecum_startup_two_start_time,
				   ecum_calculate_time(ecum_rte_end_time_value, ecum_startup_two_start_time));
		(void)VCOS_LOG(ECUM_MODULE_ID, VCOS_LOG_INFO, ECUM_DLT_INITTWO_TIME_DEFAULT, ecum_init_two_start_time,
				   ecum_calculate_time(ecum_init_two_end_time, ecum_init_two_start_time));
		(void)VCOS_LOG(ECUM_MODULE_ID, VCOS_LOG_INFO, ECUM_DLT_INITTHREE_TIME_DEFAULT,
				   ecum_init_three_start_time,
				   ecum_calculate_time(ecum_init_three_end_time, ecum_init_three_start_time));
		(void)VCOS_LOG(ECUM_MODULE_ID, VCOS_LOG_INFO, ECUM_DLT_RTESYNC_TIME_DEFAULT, ecum_rte_sync_time_value,
				   ecum_calculate_time(ecum_rte_sync_time_value, ecum_init_three_end_time));
#endif
	}
	else if (core_id == OS_CORE_ID_1){
		ecum_get_timmertick(ecum_core1_start_up_two_time.core1_begin);
	}else
	{
		/* do nothing */
	}
/*the module cannot be initialized through UI configuration */
#if (VCOS_CONSOLE_CONFIG_UART == 1)
	Sys_IO_Init();
#endif

#if (VCOS_MODULE_CONFIG_SHELL == 1)
	(void)shell_init();
#endif
	set_initsync_state((uint8)core_id);
}

FUNC(void, ECUM_CODE) print_multicore_startup_dot(void)
{
#if(EcuM_INITPHASEDOT == 1u)
#endif
}

#endif


FUNC(void, ECUM_CODE) print_master_startup_dot(void)
{
#if(EcuM_INITPHASEDOT == 1u)
	SHELL_PRINT("--------------EcuMInitPhase_Zero-------------\r\n");
	SHELL_PRINT("ecum_init_zero_begin = %lu \r\n", ecum_init_start_time);
	SHELL_PRINT("EcuMDriverInitItem = %lu \r\n", ecum_init_zero_time.m_EcuMDriverInitItem);
	SHELL_PRINT("--------------EcuMInitPhase_One-------------\r\n");
	SHELL_PRINT("ecum_init_one_begin = %lu \r\n", ecum_init_one_start_time);
	SHELL_PRINT("EcuMDriverInitItem = %lu \r\n", ecum_init_one_time.m_EcuMDriverInitItem);
	SHELL_PRINT("--------------EcuMInitPhase_Two-------------\r\n");
	SHELL_PRINT("ecum_init_two_begin = %lu \r\n", ecum_init_two_start_time);
	SHELL_PRINT("can_init = %lu \r\n", ecum_init_two_time.m_can_init);
#endif
}


FUNC(void, ECUM_CODE) ecum_on_go_off_one(void)
{
/******************USER CODE STARTS!************THIS COMMENT WILL BE SAVED!***************/
/******************USER CODE ENDS!**************THIS COMMENT WILL BE SAVED!***************/
}

FUNC(void, ECUM_CODE) ecum_on_go_off_two(void)
{
/******************USER CODE STARTS!************THIS COMMENT WILL BE SAVED!***************/
/******************USER CODE ENDS!**************THIS COMMENT WILL BE SAVED!***************/
}

FUNC(void, ECUM_CODE) ecum_loop_detection(void)
{
/******************USER CODE STARTS!************THIS COMMENT WILL BE SAVED!***************/
/******************USER CODE ENDS!**************THIS COMMENT WILL BE SAVED!***************/
}

/**
 * This function should be the last this called before reset.
 * Normally this manipulates some pin that controls DC to power off
 * the board (ie it will never get to mcu_perform_reset())
 */
FUNC(void, ECUM_CODE) ecum_al_switch_off(void)
{
/******************USER CODE STARTS!************THIS COMMENT WILL BE SAVED!***************/
/******************USER CODE ENDS!**************THIS COMMENT WILL BE SAVED!***************/
}

FUNC(void, ECUM_CODE) ecum_al_reset(ecum_reset_t reset)
{
/******************USER CODE STARTS!************THIS COMMENT WILL BE SAVED!***************/
	(void)reset;

	if(reset == ECUM_RESET_MCU) {
#if (MCU_PERFORM_RESET_API == STD_ON)
		mcu_perform_reset();
#endif
	}
	else if(reset == ECUM_RESET_WDG) {
#if 0
		wdg_m_perform_reset();
#endif
	}
	else {
		/* Do Nothing */
	}
/******************USER CODE ENDS!**************THIS COMMENT WILL BE SAVED!***************/
}

FUNC(void, ECUM_CODE) ecum_check_wakeup(ecum_wakeup_source_t wakeup_source)
{
/******************USER CODE STARTS!************THIS COMMENT WILL BE SAVED!***************/
	(void)wakeup_source;
/******************USER CODE ENDS!**************THIS COMMENT WILL BE SAVED!***************/
}

FUNC(void, ECUM_CODE) ecum_enable_wakeup_sources(ecum_wakeup_source_t wakeup_source)
{
/******************USER CODE STARTS!************THIS COMMENT WILL BE SAVED!***************/
	(void)wakeup_source;
/******************USER CODE ENDS!**************THIS COMMENT WILL BE SAVED!***************/
}

FUNC(void, ECUM_CODE) ecum_disable_wakeup_sources(ecum_wakeup_source_t wakeup_source)
{
/******************USER CODE STARTS!************THIS COMMENT WILL BE SAVED!***************/
	(void)wakeup_source;
/******************USER CODE ENDS!**************THIS COMMENT WILL BE SAVED!***************/
}

FUNC(void, ECUM_CODE) ecum_start_wakeup_sources(ecum_wakeup_source_t wakeup_source)
{
/******************USER CODE STARTS!************THIS COMMENT WILL BE SAVED!***************/
	(void)wakeup_source;
/******************USER CODE ENDS!**************THIS COMMENT WILL BE SAVED!***************/
}

FUNC(void, ECUM_CODE) ecum_stop_wakeup_sources(ecum_wakeup_source_t wakeup_source)
{
/******************USER CODE STARTS!************THIS COMMENT WILL BE SAVED!***************/
	(void)wakeup_source;
/******************USER CODE ENDS!**************THIS COMMENT WILL BE SAVED!***************/
}

FUNC(void, ECUM_CODE) ecum_check_validation(ecum_wakeup_source_t wakeup_source)
{
/******************USER CODE STARTS!************THIS COMMENT WILL BE SAVED!***************/
	(void) wakeup_source;
	SHELL_PRINT(ECUM_DLT_WAKEUPSOURCE_ID, wakeup_source);
/******************USER CODE ENDS!**************THIS COMMENT WILL BE SAVED!***************/
}

/**
 * Restart drivers. Have no restart list, instead the
 * drivers restarted are drivers that have had it's hardware
 * registers reset.  If memory is also lost (=all memory is not
 * powered during sleep), this strategy does not work.
 *
 * This calls:
 * - ecum_al_driver_init_one()
 * - ecum_al_driver_init_two()
 * - ecum_al_driver_init_three()
 *
 */
FUNC(void, ECUM_CODE) ecum_al_driver_restart(const struct ecum_config_s *config_ptr)
{
	(void) *config_ptr;
	SHELL_PRINT(ECUM_DLT_DRIVER_RESTART);
	EcuMDriverInitItem(NULL_PTR);

/******************USER CODE STARTS!************THIS COMMENT WILL BE SAVED!***************/
/******************USER CODE ENDS!**************THIS COMMENT WILL BE SAVED!***************/
}

FUNC(ecum_wakeup_reaction_t, ECUM_CODE) ecum_on_wakeup_reaction(ecum_wakeup_reaction_t wact)
{
/******************USER CODE STARTS!************THIS COMMENT WILL BE SAVED!***************/
	return wact;
/******************USER CODE ENDS!**************THIS COMMENT WILL BE SAVED!***************/
}

FUNC(void, ECUM_CODE) ecum_generate_ram_hash(void)
{
/******************USER CODE STARTS!************THIS COMMENT WILL BE SAVED!***************/
/******************USER CODE ENDS!**************THIS COMMENT WILL BE SAVED!***************/
}

FUNC(uint8, ECUM_CODE) ecum_check_ram_hash(void)
{
/******************USER CODE STARTS!************THIS COMMENT WILL BE SAVED!***************/
	return (1u);
/******************USER CODE ENDS!**************THIS COMMENT WILL BE SAVED!***************/
}

FUNC(void, ECUM_CODE) ecum_sleep_activity(void)
{
/******************USER CODE STARTS!************THIS COMMENT WILL BE SAVED!***************/
	SHELL_PRINT(ECUM_DLT_SLEEP);
/******************USER CODE ENDS!**************THIS COMMENT WILL BE SAVED!***************/
}

FUNC(void, ECUM_CODE) ecum_remember_wakeup_event(uint32 reset_reason)
{
/******************USER CODE STARTS!************THIS COMMENT WILL BE SAVED!***************/
	switch (reset_reason) {
		// Handling of additional user defined wakeup sources can be added here
		default:
			ecum_validate_wakeup_event(ECUM_WKSOURCE_RESET); /* SWS_EcuM_02601 ECUM_WKSOURCE_RESET shall be reported if no specific wk source detected  */
			break;
	}
/******************USER CODE ENDS!**************THIS COMMENT WILL BE SAVED!***************/
}


FUNC(void, ECUM_CODE) ecum_start_os(ecum_app_mode_t appMode)
{
/******************USER CODE STARTS!************THIS COMMENT WILL BE SAVED!***************/
/******************USER CODE ENDS!**************THIS COMMENT WILL BE SAVED!***************/
}


FUNC(void, ECUM_CODE) ecum_shutdown_os(Std_ReturnType ErrCode)
{
/******************USER CODE STARTS!************THIS COMMENT WILL BE SAVED!***************/
/******************USER CODE ENDS!**************THIS COMMENT WILL BE SAVED!***************/
}

#if (ECUM_NUMBER_OF_CORES > 1u)
FUNC(void, ECUM_CODE) ecum_wait_for_slave_cores(void)
{
/******************USER CODE STARTS!************THIS COMMENT WILL BE SAVED!***************/
	return;
/******************USER CODE ENDS!**************THIS COMMENT WILL BE SAVED!***************/
}

FUNC(void, ECUM_CODE) ecum_shutdown_synchronization(ecum_core_status_t shutdown_state)
{
	uint8_least loop_count;
	boolean ecum_wait_for_slaves;

  /* Wait till all Slave Cores have switched back to the requested state. */
	do
	{
		ecum_wait_for_slave_cores();

		ecum_wait_for_slaves = FALSE;

		SchM_Enter_ECUM_EXCLUSIVE_AREA_0();

		/* Iterate over all cores and check for each core if it has reached the requested state. */
		for (loop_count = 0u; loop_count < ECUM_NUMBER_OF_CORES; loop_count++) {
			if (ecum_get_core_status_value(loop_count) != shutdown_state) {
				ecum_wait_for_slaves = TRUE;
				break;
			}
		}

		SchM_Exit_ECUM_EXCLUSIVE_AREA_0();
	}
	while (ecum_wait_for_slaves == TRUE);
}

/******************USER CODE STARTS!************THIS COMMENT WILL BE SAVED!***************/
/******************USER CODE ENDS!**************THIS COMMENT WILL BE SAVED!***************/
#endif
#define ECUM_STOP_SEC_CODE
#include "ecum_memmap.h"