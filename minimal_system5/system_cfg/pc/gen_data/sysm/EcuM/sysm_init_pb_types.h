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
 * @file		EcuM_PBTypes.h
 * @brief	   	EcuM 部分模块的 PostBuild 配置数据结构定义
 * @date		Generation Time : 2026-10-24 23:59:22
 * @project	 	Project Name    : minimal_system5
 * @toolversion Tool Version    : V0.1.0-DEV
 **********************************************************************************************************************/

#ifndef ECUM_PBTYPES_H
#define ECUM_PBTYPES_H

#include "Std_Types.h"
#if (VCOS_MODULE_CONFIG_VCOSMTNCE == 1)
#include "vcosMtnce_Cfg.h"
#endif
#include "bswm.h"
#include "canif.h"
#include "com.h"
#include "comm.h"
#include "pdur.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*!*********************************************************************************************************************
 * @brief	   启动阶段打点trace功能开启标志位
 **********************************************************************************************************************/
#define EcuM_INITPHASEDOT			  (1U)

/*!*********************************************************************************************************************
 * @brief	   Postbuild配置结构体
 **********************************************************************************************************************/
typedef struct {
	const uint32 start_pattern; ///< 启动模式模式
	const uint32 post_build_variant; ///< Postbuild变体
#ifdef CFG_POSTBUILD_PARTNUMBER
	const post_build_part_no_t part_number; ///< Postbuild部件编号
#endif
	const uint64 pre_compile_hash_low; ///< 编译时的低位MD5哈希值
	const uint64 pre_compile_hash_high; ///< 编译时的高位MD5哈希值
	const bswm_config_type* const bswm_config_ptr; ///< bswm的配置指针
	const canif_config_type* const canif_config_ptr; ///< canif的配置指针
	const com_config_type* const com_config_ptr; ///< com的配置指针
	const comm_config_type* const comm_config_ptr; ///< comm的配置指针
	const pdur_pb_config_type *const pdur_config_ptr; ///< pdur的配置指针
	
	const uint32* const end_pattern; ///< 结束模式
} postbuild_config_t;

#if(EcuM_INITPHASEDOT == 1u)
/*!*********************************************************************************************************************
 * @brief	   EcuM零时初始化结构体
 **********************************************************************************************************************/
typedef struct ecum_init_zero_time_struct {
	
	uint32 m_EcuMDriverInitItem; ///< EcuMDriverInitItem 初始化时间戳
} ecum_init_zero_time_t;

/*!*********************************************************************************************************************
 * @brief	   EcuM第一次初始化结构体
 **********************************************************************************************************************/
typedef struct ecum_init_one_time_struct {
	
	uint32 m_EcuMDriverInitItem ; ///< EcuMDriverInitItem 初始化时间戳
} ecum_init_one_time_t;

/*!*********************************************************************************************************************
 * @brief	   EcuM第二次初始化结构体
 **********************************************************************************************************************/
typedef struct ecum_init_two_time_struct {
	
	uint32 m_can_init; ///< can_init 初始化时间戳
} ecum_init_two_time_t;

/*!*********************************************************************************************************************
 * @brief	   EcuM第三次初始化结构体
 **********************************************************************************************************************/
typedef struct ecum_init_three_time_struct {
	
	uint32 m_EcuMDriverInitItem_0; ///< EcuMDriverInitItem_0 初始化时间戳
} ecum_init_three_time_t;



#if (ECUM_NUMBER_OF_CORES > 1)
/*!*********************************************************************************************************************
 * @brief	   EcuM初始化结构体核心1
 **********************************************************************************************************************/
typedef struct ecum_init_core1_time_struct {
	uint32 core1_begin; ///< 核心1初始化开始标志
} ecum_init_core1_time_struct_t;

#endif
#endif

#ifdef __cplusplus
}
#endif

#endif /* ECUM_PBTYPES_H */