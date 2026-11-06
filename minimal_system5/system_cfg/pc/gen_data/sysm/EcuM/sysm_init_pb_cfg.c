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
 * @file		sysm_init_pb_cfg.c
 * @brief	   	sysm_init PostBuild 配置源文件.
 * @date		Generation Time : 2026-10-24 23:59:22
 * @project	 	Project Name    : minimal_system5
 * @toolversion Tool Version    : V0.1.0-DEV
 **********************************************************************************************************************/

/* Including File */
#include "sysm_init.h"
#include "sysm_init_generated_types.h"
#include "sysm_init_internals.h"


/*------------- Global Shared Start-----------*/
#define ECUM_START_SEC_MULTI_APP_BSS
#include "ecum_memmap.h"
static VAR(ecum_core_status_t,ECUM_MULTI_APP_BSS)  ecum_core_status_os_application_non_trusted_core0;
#define ECUM_STOP_SEC_MULTI_APP_BSS
#include "ecum_memmap.h"
/*------------- Global Shared End-----------*/
/*------------- Const Start-----------*/
#define ECUM_START_SEC_CONST
#include "ecum_memmap.h"
CONST(ecum_core_status_array_t , ECUM_CONST) ecum_core_status[1] =
{
	&ecum_core_status_os_application_non_trusted_core0,
};
#define ECUM_STOP_SEC_CONST
#include "ecum_memmap.h"
/*------------- Const End-----------*/

/* Local Variable Definition */
#define  ECUM_START_SEC_CONST
#include "ecum_memmap.h"

extern CONST(postbuild_config_t, ECUM_CONST) postbuild_config;
extern CONST(cansm_config_type, ECUM_CONST) cansm_config;
#define ECUM_STOP_SEC_CONST
#include "ecum_memmap.h"

/* Local Type & Structure Definition */
#define ECUM_START_SEC_CONST
#include "ecum_memmap.h"
/* 休眠模式配置 */
CONST(ecum_sleep_mode_t, ECUM_CONST) ecum_sleep_mode_config[] = {
	{
		.ecum_sleep_mode_id = EcuMSleepMode,
		.ecum_wakeup_source_mask = (ECUM_WKSOURCE_POWER),
	},
};


/* 唤醒源配置 */
static CONST(ecum_wakeup_source_config_t, ECUM_CONST) ecum_wakeup_source_config[] = {
	{
		.ecum_wakeup_source_id = ECUM_WKSOURCE_POWER,
		.ecum_validation_timeout = 0u,
#if defined(ECUM_USE_COMM)
		.ecum_comm_channel = ECUM_COMM_CHANNEL_ILL
#endif
	},
	{
		.ecum_wakeup_source_id = ECUM_WKSOURCE_RESET,
		.ecum_validation_timeout = 0u,
#if defined(ECUM_USE_COMM)
		.ecum_comm_channel = ECUM_COMM_CHANNEL_ILL
#endif
	},
	{
		.ecum_wakeup_source_id = ECUM_WKSOURCE_INTERNAL_RESET,
		.ecum_validation_timeout = 0u,
#if defined(ECUM_USE_COMM)
		.ecum_comm_channel = ECUM_COMM_CHANNEL_ILL
#endif
	},
	{
		.ecum_wakeup_source_id = ECUM_WKSOURCE_INTERNAL_WDG,
		.ecum_validation_timeout = 0u,
#if defined(ECUM_USE_COMM)
		.ecum_comm_channel = ECUM_COMM_CHANNEL_ILL
#endif
	},
	{
		.ecum_wakeup_source_id = ECUM_WKSOURCE_EXTERNAL_WDG,
		.ecum_validation_timeout = 0u,
#if defined(ECUM_USE_COMM)
		.ecum_comm_channel = ECUM_COMM_CHANNEL_ILL
#endif
	},
};

#if(ECUM_MCURESETREFNUM != 0)
CONST(ecum_reset_reason_t, ECUM_CONST) ecum_reset_reasons[] = {
};
#endif


/* EcuM 使用ComM通道配置 */
#if (CONFIG_MODULE_COMM == 1)
CONST(ecum_comm_config_t, ECUM_CONST) ecum_comm_config[] = {
	{
		.ecum_comm_network_handle =  COMM_NETWORK_HANDLE_ComMChannel_0,
		.ecum_com_bus_t = COMM_BUS_TYPE_CAN
	},
};
#endif


/* SWS_EcuM_00793 */ /* SWS_EcuMf_00046 */
CONST(ecum_config_t, ECUM_CONST) ecum_config = {
	.ecum_post_build_variant = POST_BUILD_VARIANT,
	.ecum_config_consistency_hash_low = PRE_COMPILED_DATA_HASH_LOW,
	.ecum_config_consistency_hash_high = PRE_COMPILED_DATA_HASH_HIGH,  /* @req SWS_EcuM_02795 */
	.ecum_default_shutdown_target = ECUM_SHUTDOWN_TARGET_OFF,
	.ecum_default_sleep_mode = 0u,
	.ecum_nvram_read_all_timeout = ECUM_NVRAM_READALL_TIMEOUT,
	.ecum_nvram_write_all_timeout = ECUM_NVRAM_WRITEALL_TIMEOUT,
	.ecum_run_minimum_duration = ECUM_NVRAM_MIN_RUN_DURATION,
	.ecum_sleep_mode_config = ecum_sleep_mode_config,
	.ecum_wakeup_source_config = ecum_wakeup_source_config,
#if(ECUM_MCURESETREFNUM != 0)
	.ecum_reset_reason_config = ecum_reset_reasons,
#endif
/* SWS_EcuM_00809 */
#if defined(ECUM_USE_DEM)
	.ecum_dem_inconsistency_event_id			 = DEM_EVENT_ID_NULL,
	.ecum_dem_ram_check_failed_event_id			= DEM_EVENT_ID_NULL,
	.ecum_dem_all_run_requests_killed_event_id	  = DEM_EVENT_ID_NULL,
#endif
#if (CONFIG_MODULE_COMM == 1)
	.ecum_comm_config = &ecum_comm_config[0],
#endif
	.post_build_config = &postbuild_config,
	.cansm_config_ptr = &cansm_config,
};
#define ECUM_STOP_SEC_CONST
#include "ecum_memmap.h"