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
 * @file        cansm_cfg.h
 * @brief       CanSM动态生成的预编译阶段头文件
 * @details     CanSM模块的配置头文件
 * @date        Generation Time : 2026-10-25 11:39:36
 * @toolversion Tool Version    : V0.1.0-DEV
***********************************************************************************************************************/

#ifndef CANSM_CFG_H
#define CANSM_CFG_H

#include "Std_Types.h"
#include "cansm_types.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*!*********************************************************************************************************************
 * @brief          CanSM内部NetworkIdx
 **********************************************************************************************************************/

/*!*********************************************************************************************************************
 * @brief          控制器唤醒操作类型
 **********************************************************************************************************************/
typedef enum {
    CANSM_CLEAR_WUF = 0,   /* 清除Wuf */
    CANSM_CHECK_WUF        /* 检查Wuf */
} CanSM_WufActionType;

/*!*********************************************************************************************************************
 * @brief          控制器唤醒操作联合体
 **********************************************************************************************************************/
typedef union {
    cansm_canif_ctrl_mode ccMode;     /* 控制器模式 */
    CanTrcv_TrcvModeType trcv_mode;   /* 收发器模式 */
    CanSM_WufActionType wufAction;   /* 唤醒模式 */
} cansm_action_mode;

/*!*********************************************************************************************************************
 * @brief          CanSM唤醒操作类型
 **********************************************************************************************************************/
typedef enum {
    CANSM_A_CC_MODE = 0,     /* 控制器模式 */
    CANSM_A_TRCV_MODE,       /* 收发器模式 */
    CANSM_A_WUF,             /* 唤醒模式 */
    CANSM_A_NO_MODE
} cansm_action_type;

/*!*********************************************************************************************************************
 * @brief          CanSM收发器操作结构体
 **********************************************************************************************************************/
typedef struct {
    cansm_action_type FirstAction;    /* 第一次的动作 */
    cansm_action_mode FirstMode;      /* 第一次的模式 */
    cansm_action_type SecondAction;   /* 第二次的动作 */
    cansm_action_mode SecondMode;     /* 第二次的模式 */
} cansm_transition_type;

#define CANSM_DEV_ERROR_DETECT                (STD_OFF)        ///< 是否使能DET 
#define CANSM_PNC_SUPPORT                     (STD_OFF)        ///< 是否使能PNC
#define CANSM_TRCV_SUPPORT                    (STD_ON)        ///< 是否使能TRCV
#define CANSM_BUSOFF_BEGIN                    (STD_OFF)        ///< 是否使能BUSOFF BEGIN通知
#define CANSM_BUSOFF_END                      (STD_OFF)        ///< 是否使能BUSOFF END通知
#define CANSM_SUPPORT_MULTICORE               (STD_OFF)        ///< 是否支持CanSM模块多核
#define CANSM_SILENT_BOR_SUPPORT              (STD_OFF)        ///< 是否使能SILENT_BOR
#define CANSM_NETWORK_COUNT                   (1u)             ///< CanSM网络数量
#define CANSM_MULTICORE_CORE_NUMBER           (1u)      ///< CanSM分布的核最大编号
#define CANSM_SPINLOCK_RETRY_COUNTER          (uint16)255u ///< CANSM的自旋锁获取尝试最大次数
#define CANSM_MAIN_MAX_EXECUTE_TIME_INIT      (uint8)3u ///< CANSM的初始化阶段快速切换最大次数
#define CANSM_MAIN_MAX_EXECUTE_TIME_MAINFUNC  (uint8)3u ///< CANSM的周期函数阶段快速切换最大次数
#define CANSM_RUNNABLE_BUSOFF_BEGIN_FNC (NULL)                 ///< BUSOFF BEGIN回调函数
#define CANSM_RUNNABLE_BUSOFF_END_FNC (NULL)                   ///< BUSOFF END回调函数

#define CANSM_START_SEC_CODE
#include "cansm_memmap.h"
/*!*********************************************************************************************************************
 * @brief          获取CanSM模块状态标志位函数
 * @details        获取当前CanSM模块状态变量
 * @param[in]      void
 * @reentrant      可重入
 * @synchronous    同步
 **********************************************************************************************************************/
FUNC(cansm_internal_init_status_type, CANSM_CODE) cansm_get_module_status(void);

/*!*********************************************************************************************************************
 * @brief          设置CanSM模块状态标志位函数
 * @details        CanSM模块状态变量
 * @param[in]      ModuleStatus - 新状态
 * @reentrant      不可重入
 * @synchronous    同步
 **********************************************************************************************************************/
FUNC(void, CANSM_CODE) cansm_set_module_status(cansm_internal_init_status_type ModuleStatus);

/*!*********************************************************************************************************************
 * @brief          获取CanSM通道和核的关系对应表
 * @details        返回表的第一个元素位置，表长为CANSM_MULTICORE_CORE_NUMBER
 * @param[in]      void
 * @reentrant      可重入
 * @synchronous    同步
 **********************************************************************************************************************/
FUNC_P2CONST(cansm_network_core_table_type, AUTOMATIC, CANSM_CODE) cansm_get_network_core_table(void);

/*!*********************************************************************************************************************
 * @brief          获取CanSM通道中全局区的部分和核的关系对应表
 * @details        返回表的第一个元素位置，表长为CANSM_MULTICORE_CORE_NUMBER
 * @param[in]      void
 * @reentrant      可重入
 * @synchronous    同步
 **********************************************************************************************************************/
FUNC_P2CONST(cansm_global_network_core_table_type, AUTOMATIC, CANSM_CODE) cansm_get_global_network_core_table(void);

/*!*********************************************************************************************************************
 * @brief          获取CanSM静态配置信息
 * @details        静态配置信息地址
 * @param[in]      void
 * @reentrant      可重入
 * @synchronous    同步
 **********************************************************************************************************************/
FUNC_P2CONST(cansm_config_type, AUTOMATIC, CANSM_CODE) cansm_get_config_ptr(void);

/*!*********************************************************************************************************************
 * @brief          设置CanSM静态配置信息
 * @details        静态配置信息地址赋值
 * @param[in]      config_ptr - 地址信息
 * @reentrant      可重入
 * @synchronous    同步
 **********************************************************************************************************************/
FUNC(void, CANSM_CODE) cansm_set_config_ptr(const cansm_config_type* config_ptr);

/*!*********************************************************************************************************************
 * @brief          CanSM的主函数内核
 * @details        所有核上面的主函数实际调用该主函数
 * @param[in]      void
 * @reentrant      可重入
 * @synchronous    同步
 **********************************************************************************************************************/
FUNC(void, CANSM_CODE) cansm_internal_main_function(void);

/*!*********************************************************************************************************************
 * @brief          获取CanSM收发器信息变量
 * @details        获取CanSM收发器信息变量
 * @param[in]      void
 * @reentrant      可重入
 * @synchronous    同步
 **********************************************************************************************************************/
FUNC_P2CONST(cansm_transition_type, AUTOMATIC, CANSM_CODE) cansm_get_transition_config(void);
#define CANSM_STOP_SEC_CODE
#include "cansm_memmap.h"

#ifdef __cplusplus
}
#endif

#endif /* CANSM_CFG_H */
