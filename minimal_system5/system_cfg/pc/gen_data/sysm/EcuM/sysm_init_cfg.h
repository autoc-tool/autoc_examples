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
 * @file		EcuM_Cfg.h
 * @brief	    EcuM 模块配置宏定义头文件.
 * @date		Generation Time : 2026-10-24 23:59:22
 * @project	    Project Name    : minimal_system5
 * @toolversion Tool Version    : V0.1.0-DEV
 **********************************************************************************************************************/

#ifndef ECUM_CFG_H
#define ECUM_CFG_H

#include "Std_Types.h"
#ifdef __cplusplus
extern "C"
{
#endif







#define USE_ECUM_FIXED						 (STD_ON)	///< 是否使用 EcuM 固定模式
#define ECUM_USE_RTE	///< 和 EcuM 交互的其他模块宏定义
#define ECUM_USE_COMM	///< 和 EcuM 交互的其他模块宏定义
#define ECUM_USE_BSWM	///< 和 EcuM 交互的其他模块宏定义

#define ECUM_NUMBER_OF_CORES				   (1U)	///< 内核数量
#ifndef OS_CORE_ID_MASTER
#define ECUM_CORE_ID_BSW					   (0u)	///< BSW 内核ID
#else
#define ECUM_CORE_ID_BSW					   (OS_CORE_ID_MASTER)	///< 使用操作系统定义的BSW内核ID
#endif

/* PostBuildVariant */
#define POST_BUILD_VARIANT					 (1u)	///< 后构建变体

#ifndef OSDEFAULTAPPMODE
#define ECUM_DEFAULT_APPMODE				   (1u)	///< 默认应用模式
#else
#define ECUM_DEFAULT_APPMODE				   (OSDEFAULTAPPMODE)	///< 使用操作系统定义的默认应用模式
#endif

#define ECUM_VERSION_INFO_API				  STD_OFF	///< 版本信息API开关
#define ECUM_DEV_ERROR_DETECT				  STD_OFF	///< 错误检测开关

#define ECUM_MAIN_FUNCTION_PERIOD			  10u	///< 主函数周期

#define ECUM_NVRAM_READALL_TIMEOUT			 (10000)	///< NVM ReadAll 超时时间
#define ECUM_NVRAM_WRITEALL_TIMEOUT			(10000)	///< NVM WriteAll 超时时间
#define ECUM_NVRAM_MIN_RUN_DURATION			(10000)	///< NVM 最短运行时间


#define ECUM_RESET_LOOP_DETECTION			  (STD_OFF)	///< 复位环检测开关

/* 模式处理开关 */
#define ECUM_MODE_HANDLING					 (STD_OFF)	///< 模式处理开关
#define ECUM_VALIDATION_TIMEOUT				(1000u)	///< 唤醒验证超时时间


#define ECUM_EcuMFlexUserConfig						 (0u)	///< 定义 EcuMFlexUserConfig 的用户ID
#define ECUM_USER_ENDMARK					  (1u)	///< 用户结束标志


#define ECUM_WKSOURCE_POWER					  (ecum_wakeup_source_t)(1uL << 0u)	///< 定义 ECUM_WKSOURCE_POWER 的唤醒源ID
#define ECUM_WKSOURCE_RESET					  (ecum_wakeup_source_t)(1uL << 1u)	///< 定义 ECUM_WKSOURCE_RESET 的唤醒源ID
#define ECUM_WKSOURCE_INTERNAL_RESET					  (ecum_wakeup_source_t)(1uL << 2u)	///< 定义 ECUM_WKSOURCE_INTERNAL_RESET 的唤醒源ID
#define ECUM_WKSOURCE_INTERNAL_WDG					  (ecum_wakeup_source_t)(1uL << 3u)	///< 定义 ECUM_WKSOURCE_INTERNAL_WDG 的唤醒源ID
#define ECUM_WKSOURCE_EXTERNAL_WDG					  (ecum_wakeup_source_t)(1uL << 4u)	///< 定义 ECUM_WKSOURCE_EXTERNAL_WDG 的唤醒源ID

#define ECUM_MCURESETREFNUM					(0U)	///< MCU 复位参考数量
#ifndef ECUM_WKSOURCE_SYSTEM_CNT
#define ECUM_WKSOURCE_SYSTEM_CNT			   (5U)	///< 系统唤醒源数量
#endif
#ifndef ECUM_WKSOURCE_USER_CNT
#define ECUM_WKSOURCE_USER_CNT				 (0U)	///< 用户定义唤醒源通道数量
#endif
#define EcuM_SizeOfWakeupSourceList			(ECUM_WKSOURCE_SYSTEM_CNT)	///< 唤醒源列表长度

#define ECUM_COMM_NETWORKS_CNT				 (COMM_CHANNEL_COUNT)	///< 通信网络总数

#define VALIED_WAKEUP_SOURCES					   (ECUM_WKSOURCE_POWER | ECUM_WKSOURCE_RESET | ECUM_WKSOURCE_INTERNAL_RESET | ECUM_WKSOURCE_INTERNAL_WDG | ECUM_WKSOURCE_EXTERNAL_WDG | ECUM_WKSOURCE_NONE)	///< 有效唤醒源


#define EcuMShutdownCause					   (0u)	///< 定义 EcuMShutdownCause 的Shutdown原因


#define Conf_ECUM_RESET_MCU				   (256u)	///< 定义 ECUM_RESET_MCU 的复位模式ID


#define EcuMSleepMode						(0u)	///< 定义 EcuMSleepMode 的休眠模式ID

#ifdef __cplusplus
}
#endif

#endif /* ECUM_CFG_H */