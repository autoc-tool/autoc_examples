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
 * @file		EcuM_Generated_Types.h
 * @brief	   	EcuM 生成的自定义数据类型.
 * @date		Generation Time : 2026-10-24 23:59:22
 * @project	 	Project Name    : minimal_system5
 * @toolversion Tool Version    : V0.1.0-DEV
 **********************************************************************************************************************/

#ifndef ECUM_GENERATED_TYPES_H
#define ECUM_GENERATED_TYPES_H

#include "precompiled_data_hash.h"
#include "sysm_init_types.h"
#include "sysm_init_internal_types.h"
#include "sysm_init_pb_types.h"
#include "cansm.h"

#ifdef __cplusplus
extern "C"
{
#endif


/*!*********************************************************************************************************************
 * @brief	   EcuM 重置原因结构体
 **********************************************************************************************************************/
typedef struct ecum_reset_reason_t_s
{
	ecum_wakeup_source_t wkup_source; ///< 唤醒源
	uint32		 reset_reason; ///< 重置原因
} ecum_reset_reason_t;

/*!*********************************************************************************************************************
 * @brief	   EcuM 配置结构体
 **********************************************************************************************************************/
typedef struct ecum_config_s
{
	uint32 ecum_post_build_variant;							   ///< PostBuild变体
	uint64 ecum_config_consistency_hash_low;					   ///< 当编译整个软件时设置的Hash低位值
	uint64 ecum_config_consistency_hash_high;					  ///< 当编译整个软件时设置的Hash高位值
	ecum_state_t ecum_default_shutdown_target;				  ///< 默认的ShutdownTarget
	uint8 ecum_default_sleep_mode;								///< 默认的睡眠模式
	uint32 ecum_run_minimum_duration;							 ///< EcuM 运行最短持续时间
	uint32 ecum_nvram_read_all_timeout;							///< EcuM 使用NVM ReadAll读取超时时间
	uint32 ecum_nvram_write_all_timeout;						   ///< EcuM 使用NVM WriteAll读取超时时间
	uint32 ecum_normal_mcu_mode;							///< MCU 正常运行状态
#if defined(ECUM_USE_DEM)
	dem_event_id_type ecum_dem_inconsistency_event_id;			   ///< Dem 不一致事件ID
	dem_event_id_type ecum_dem_ram_check_failed_event_id;			  ///< Dem 验证 RAM 失败事件ID
	dem_event_id_type ecum_dem_all_run_requests_killed_event_id;		///< Dem 杀死所有 RUN 请求事件ID
#endif
	const ecum_sleep_mode_t *ecum_sleep_mode_config;			 ///< 睡眠模式配置
	const ecum_wakeup_source_config_t *ecum_wakeup_source_config; ///< 唤醒源配置
	const ecum_reset_reason_t *ecum_reset_reason_config;		 ///< 重置原因配置

#if (USE_ECUM_FIXED == STD_OFF)
	const ecum_user_t *ecum_go_down_allowed_users_config;		 ///< 允许关机的用户配置
#endif
#if (CONFIG_MODULE_COMM == 1)
	const ecum_comm_config_t *ecum_comm_config;				 ///< EcuM和ComM交互配置
#endif
	const cansm_config_type *cansm_config_ptr;		  ///< cansm 配置

	const postbuild_config_t *post_build_config;				///< Postbuild 配置
} ecum_config_t;

#ifdef __cplusplus
}
#endif

#endif /* ECUM_GENERATED_TYPES_H */