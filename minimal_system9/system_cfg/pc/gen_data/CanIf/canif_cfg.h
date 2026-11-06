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
 * @file        canif_cfg.h
 * @brief       CanIf 配置头文件
 * @details     主要包含CanIf模块的配置相关信息
 * @date        2026-10-25 11:56:55
 * @toolversion V0.1.0-DEV
 **********************************************************************************************************************/

#ifndef CANIF_CFG_H
#define CANIF_CFG_H

#include "comstack_types.h"

#ifdef __cplusplus
extern "C" 
{
#endif

#define CANIF_AUTOSAR_VERSION_431                   ///< 定义CanIf版本

#define CANIF_MULTICORE_SUPPORT							(STD_OFF)        ///< CANIF多核功能关闭
#define CANIF_MULTICORE_MASTER_COREID                    (0u)   ///< CANIF主核ID 

#define CANIF_CAN_HOH_ORDERED_TYPE          CANIF_CAN_HOH_ORDERED_IN_CAN_HRH_FIRST

#define CANIF_ACTIVATED_CORE_CNT                         (1u)  ///< CANIF使能核数量  
#define CANIF_MAX_ACTIVATED_CORE_CNT                         (1u)  ///< CANIF使能的核ID最大值 + 1  

#define CANIF_INVALID_TXBUFFER_START_INDEX   (0xFFFFU)
#define CANIF_INVALID_TXBUFFER_END_INDEX   (0xFFFFU)
#define CANIF_MAX_NOF_TX_BUFFERS_CORE0                           (2u)  ///< CORE0发送缓存个数

#define CANIF_RXPDU_USER_RXINDICATION_UL_CANNM             (1u)  ///< CANNM UL的RxIndication函数标号
#define CANIF_PRIVATE_DLC_CHECK							(STD_ON)        ///< 私有DLC检查

/* Macro definition of CanIfPublicCfg */
#define CANIF_PUBLIC_CANCEL_TRANSMIT_SUPPORT			(STD_OFF)        ///< 公共取消发送支持
#define CANIF_PUBLIC_CHANGE_BAUDRATE_SUPPORT			(STD_OFF)        ///< 公共改变边界支持
#define CANIF_PUBLIC_DEV_ERROR_DETECT					(STD_OFF)     ///< 开发错误探测
#define CANIF_PUBLIC_DEBUG_SUPPORT						(STD_OFF)   ///< 收发包维测支持

#define CANIF_PUBLIC_MULTIPLE_DRV_SUPPORT				(STD_OFF)     ///< 多驱动支持

#define CANIF_PUBLIC_PN_SUPPORT							(STD_OFF)   ///< 局部网络支持
#define CANIF_TRCV_PN_ENABLE						    (STD_OFF)   ///< 局部网络收发处理

#define CANIF_PUBLIC_TX_BUFFERING					    (STD_OFF) ///< 发送缓存
#define CANIF_PUBLIC_TXBUFFER_MAX_DEPTH_FETCH_SUPPORT	(STD_OFF) ///< TxBuffer最大使用深度捞取维测支持

#define CANIF_TX_BUF_FIFO_ENABLE                      (STD_ON) ///< 发送缓存FIFO
#define CANIF_PUBLIC_TXCONFIRM_POLLING_SUPPORT			(STD_ON) ///< 发送确认轮询

#define CANIF_CANFD_SUPPORT                             (STD_ON) ///< 支持CANFD

#define CANIF_TRANSCEIVER_API			                (STD_OFF)

#define CANIF_WAKEUP_FUN_ENABLE						    (STD_ON) ///< 唤醒支持
#define CANIF_CTRL_WAKEUP_SUPPORT						(STD_OFF) ///< 控制器唤醒支持
#define CANIF_TRCV_WAKEUP_SUPPORT						(STD_ON) ///< 收发器器唤醒支持
#define CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_NM			(STD_OFF) ///< 通过nm唤醒检查校验
#define CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_SUPPORT	(STD_OFF) ///< 唤醒检查校验

#define CANIF_PUBLIC_APPL_CANIF_TX_CALLOUT_SUPPORT	(STD_OFF) ///< appl_canif_tx_callout API支持
#define CANIF_PUBLIC_APPL_CANIF_TXCONFIRMATION_CALLOUT_SUPPORT	(STD_OFF) ///< appl_canif_tx_confirmation_callout API支持
#define CANIF_PUBLIC_APPL_CANIF_RXINDICATION_CALLOUT_SUPPORT	(STD_OFF) ///< appl_canif_rx_indication_callout API支持

#define CANIF_INVALID_CANIF_HRH                                    (0xFFFFu) ///< HRH
#define CANIF_MAX_CONTROLLER_COUNT                                 (1u)     ///< 最大控制器计数

/* Software filter */
#define CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_LINEAR ///< 软件过滤线性类型
/*!*********************************************************************************************************************
 * @brief   定义canif通道id类型
 **********************************************************************************************************************/
typedef uint8 canif_channel_id_type;

#define CanIfConf_CanIfCtrlCfg_CanController_0                    ((canif_channel_id_type)0u) ///< 控制器ID
#define CANIF_CONTROLLER_CHANNEL_CNT                                          (1u) ///< 通道个数

/*!*********************************************************************************************************************
 * @brief   定义canif收发器id类型
 **********************************************************************************************************************/
typedef uint8 canif_trcv_id_type;

#define CanIfConf_CanIfTrcvCfg_CanIfTrcvCfg                    ((canif_trcv_id_type)0u) ///< 收发器名称
#define CANIF_TRANSCEIVER_CHANNEL_CNT                              (1u) ///< 通道个数

#define CANIF_TRANSCEIVER_ENABLE_TYPE_CNT                              (0u) ///< 使能收发器型号的个数
#define CANIF_MAX_NOF_TX_BUFFERS                        (2u) ///< 发送缓存个数
#define CANIF_MAX_NOF_RX_PDU                            (1u) ///< 接收PDU个数
#define CANIF_MAX_NOF_HRH_COUNT                         (1u) ///< 接收最大计数
#define CANIF_MAX_NOF_TX_PDU                            (2u) ///< 发送PDU个数
#define CANIF_CFG_MAX_DYN_TXPDUS                        (2u) ///< 最大动态PDU
#define CANIF_ULMOUDLE_COUNT                            (8u) ///< 上层模块个数







#ifdef __cplusplus
}
#endif

#endif /* CANIF_CFG_H */
