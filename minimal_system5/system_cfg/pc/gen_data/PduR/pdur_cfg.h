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
 * @file        pdur_cfg.h
 * @brief       PduR配置头文件
 * @details     主要包含PduR模块的配置
 * @date        2026-10-24 23:59:11
 * @toolversion V0.1.0-DEV
 **********************************************************************************************************************/

#ifndef PDUR_CFG_H
#define PDUR_CFG_H

#ifdef __cplusplus
extern "C"
{
#endif
#include "comstack_cfg.h"
#include "isr_cfg.h"

/* Global Macro Definition */
#define PDUR_CANIF_SUPPORT                                                      (STD_ON)  ///< PduR支持CanIf
#define PDUR_CANIF_CANCEL_RECEIVE_SUPPORT                                       (STD_ON)  ///< PduR支持CanIf取消接收
#define PDUR_CANIF_CANCEL_TRANSMIT_SUPPORT                                      (STD_ON)  ///< PduR支持CanIf取消发送
#define PDUR_CANIF_COMMUNICATION_INTERFACE_SUPPORT                              (STD_ON)  ///< PduR支持CanIf通信接口
#define PDUR_CANIF_LOWER_MODULE_SUPPORT                                         (STD_ON)  ///< PduR支持CanIf通信接口
#define PDUR_CANIF_RETRANSMISSION_SUPPORT                                       (STD_OFF)  ///< PduR不支持CanIf重传
#define PDUR_CANIF_TRANSPORT_PROTOCOL_SUPPORT                                   (STD_OFF) ///< PduR不支持CanIf传输协议
#define PDUR_CANIF_TRIGGER_TRANSMIT_SUPPORT                                     (STD_ON)  ///< PduR支持CanIf触发发送
#define PDUR_CANIF_TX_CONFIRMATION_SUPPORT                                      (STD_ON)  ///< PduR支持CanIf发送确认
#define PDUR_CANIF_UPPER_MODULE_SUPPORT                                         (STD_OFF) ///< PduR不支持CanIf上层模块
#define PDUR_CANIF_USE_TAG_SUPPORT                                              (STD_OFF) ///< PduR不支持CanIf用户标签
#define PDUR_COM_SUPPORT                                                        (STD_ON)  ///< PduR支持Com
#define PDUR_COM_CANCEL_RECEIVE_SUPPORT                                         (STD_ON)  ///< PduR支持Com取消接收
#define PDUR_COM_CANCEL_TRANSMIT_SUPPORT                                        (STD_ON)  ///< PduR支持Com取消发送
#define PDUR_COM_COMMUNICATION_INTERFACE_SUPPORT                                (STD_ON)  ///< PduR支持Com通信接口
#define PDUR_COM_LOWER_MODULE_SUPPORT                                           (STD_OFF)  ///< PduR不支持Com通信接口
#define PDUR_COM_RETRANSMISSION_SUPPORT                                         (STD_OFF)  ///< PduR不支持Com重传
#define PDUR_COM_TRANSPORT_PROTOCOL_SUPPORT                                     (STD_OFF) ///< PduR不支持Com传输协议
#define PDUR_COM_TRIGGER_TRANSMIT_SUPPORT                                       (STD_ON)  ///< PduR支持Com触发发送
#define PDUR_COM_TX_CONFIRMATION_SUPPORT                                        (STD_OFF) ///< PduR不支持Com发送确认
#define PDUR_COM_UPPER_MODULE_SUPPORT                                           (STD_ON)  ///< PduR支持Com上层模块
#define PDUR_COM_USE_TAG_SUPPORT                                                (STD_OFF) ///< PduR不支持Com用户标签
#define PDUR_SUPPORT_ROUTING_PATH_GROUP                                         (STD_OFF)
#define PDUR_DEV_ERROR_DETECT                                                   (STD_OFF) ///< 不支持日志接口
#define PDUR_META_DATA_SUPPORT                                                  (STD_OFF) ///< 不支持原始数据
#define PDUR_VERSION_INFO_API                                                   (STD_OFF) ///< 不支持版本信息接口
#define PDUR_ZERO_COST_OPERATION                                                (STD_OFF) ///< 不支持零消耗运行
#define PDUR_MULTICORE_SUPPORT                                                  (STD_OFF) ///< 不支持多核

#define PDUR_SPINLOCK_RETRY_COUNTER                    (3u)  ///< PduR 自旋锁重新尝试次数
#define PDUR_MAX_ROUTE_COUNT                           (3u)                          ///< 最大路由数
#define PDUR_DEFAULT_BUFFER_SIZE                       ((uint32)8u)       ///< PduR默认缓存大小
#define PDUR_NO_BUFFER                                 ((uint16)0xFFFFu)  ///< PduR无缓存
#define PDUR_EVC_FIFO_CORE_MAX_NUM                     ((uint32)1u)       ///< PduRTP路由最大核个数
#define PDUR_IF_EVC_FIFO_CORE_MAX_NUM                  ((uint32)1u)    ///< PduRIF路由最大核个数
#define PDUR_MAX_GW_DESTINATIONS                       (1u)              ///< GW目的模块最大值

#define PDUR_PDU_ID_BIT                                (12u)             ///< 从低12位中提取掩码，低12位代表PduId
#define PDUR_PDU_ID_RIGHT_MOVE_BIT                     (3u)              ///< 右移3位
#define PDUR_PDU_ID_LOW_BIT_MAX_NUM                    (7u)              ///< 除8的最大余数
#define PDUR_PDU_ID_UINT8_BIT_NUM                      (8u)              ///< uint8里面有8个bit
#define PDUR_INVALID_PDU_ID                            (0xFFFFU)          ///< 无效pduid
#define PDUR_SRC_PDUID_DEFAULT_INDEX                   (0u)              ///< 源PduId默认索引值
#define PDUR_ISR_TABLE_LEN                             (1) // 路由跨核中断处理函数表长度

#define pdur_dest_PDUID_MAPPING_SIZE                   (0u)             ///< 目的PduId映射数组大小

#define PDUR_SRC_PDUID_MAPPING_SIZE                    (0u)             ///< 源PduId映射数组大小
#define PDUR_ROUTING_PATH_NUM                          (3u)         ///< 真实的路由路径个数

/*!*********************************************************************************************************************
 * @brief    定义PduR路由状态类型
 **********************************************************************************************************************/
/* Buffer Manager */
#define PDUR_ROUTING_IDLE                            0u     ///< IDLE状态                   |
#define PDUR_GATEWAY_DIRECT_RX_READY                 1u     ///< 状态RX_READY               | StartOfRecetion后 - 
#define PDUR_GATEWAY_DIRECT_RX_ONGOING               2u     ///< 状态RX_ONGOING             | 开始CopyRxData后 - 
#define PDUR_GATEWAY_DIRECT_RX_FINISH                3u     ///< 状态RX_FINISH              | 收到RxIndication后 - 
#define PDUR_GATEWAY_DIRECT_TX_READY                 4u     ///< 状态TX_READY               | 准备调用Transmit前 - 
#define PDUR_GATEWAY_DIRECT_TX_ONGOING               5u     ///< 状态TX_ONGOING             | 调用CopyTxData后 - 
#define PDUR_GATEWAY_ONTHEFLY_RX_READY_TX_WAIT       6u     ///< 状态RX_READY_TX_WAIT       | 调用StartOfReception后 - 未达到Threshold,未调用Transmit
#define PDUR_GATEWAY_ONTHEFLY_RX_ONGOING_TX_WAIT     7u     ///< 状态RX_ONGOING_TX_WAIT     | 调用CopyRxData后 - 未达到Threshold,未调用Transmit
#define PDUR_GATEWAY_ONTHEFLY_RX_FINISH_TX_WAIT      8u     ///< 状态RX_FINISH_TX_WAIT      | 调用RxIndication后 - 未达到Threshold,未调用Transmit
#define PDUR_GATEWAY_ONTHEFLY_RX_READY_TX_READY      9u     ///< 状态RX_READY_TX_READY      | 调用StartOfReception后 - Threshold=0,已调用Transmit,未调用CopyTxData
#define PDUR_GATEWAY_ONTHEFLY_RX_ONGOING_TX_READY    10u    ///< 状态RX_ONGOING_TX_READY    | 调用CopyRxData后 - 已达到Threshold,调用Transmit,未调用CopyTxData
#define PDUR_GATEWAY_ONTHEFLY_RX_FINISH_TX_READY     11u    ///< 状态RX_FINISH_TX_READY     | 调用RxIndication后 - 调用Transmit,未调用CopyTxData
#define PDUR_GATEWAY_ONTHEFLY_RX_ONGOING_TX_ONGOING  12u    ///< 状态RX_ONGOING_TX_ONGOING  | 调用CopyRxData后 -  已达到Threshold 已调用CopyTxData
#define PDUR_GATEWAY_ONTHEFLY_RX_FINISH_TX_ONGOING   13u    ///< 状态RX_FINISH_TX_ONGOING   | 调用RxIndication后 - 已调用CopyTxData
#define PDUR_DIAG_UPPERLAYER_RX_READY                14u    ///< 状态UPPERLAYER_RX_READY    | 路由消息至其他核的上层模块 - PduR收到StartOfReception
#define PDUR_DIAG_UPPERLAYER_RX_ONGOING              15u    ///< 状态UPPERLAYER_RX_ONGOING  | 路由消息至其他核的上层模块 - PduR收到CopyRxData
#define PDUR_DIAG_UPPERLAYER_RX_FINISH               16u    ///< 状态UPPERLAYER_RX_FINISH   | 路由消息至其他核的上层模块 - PduR收到RxIndication
#define PDUR_DIAG_UPPERLAYER_TX_READY                17u    ///< 状态UPPERLAYER_TX_READY    | 路由消息至其他核的上层模块 - PduR接收完毕准备跨核传递
#define PDUR_DIAG_UPPERLAYER_TX_ONGOING              18u    ///< 状态UPPERLAYER_TX_ONGOING  | 路由消息至其他核的上层模块 - 接收端开始从PduR复制数据
#define PDUR_GATEWAY_IF_DIRECT_TX_FIFO_APPEND        19u    ///< 状态IF_DIRECT_TX           | 路由消息IF-Direct已经入队跨核FIFO
#define PDUR_GATEWAY_IF_TT_TX_FIFO_APPEND            20u    ///< 状态IF_TT_TX               | 路由消息IF-TriggerTransmit已经入队跨核FIFO
#define PDUR_GATEWAY_IF_TT_TX_TRIGGERTRANSMIT        21u    ///< 状态IF_TT_TX               | 路由消息IF-TriggerTransmit已经被调用TriggerTransmit复制数据
#define PDUR_GATEWAY_ONTHEFLY_FAILED                 22u    ///< 状态FAILED                 | 调用Transmit后发送失败,等待TxConfirmation

#define PDUR_N_TO_1_MAX_N_NUM                          (1u)    ///< N对1类型中N的最大值

/*!*********************************************************************************************************************
 * @brief    定义PduR目的PduId映射类型
 **********************************************************************************************************************/
typedef struct {
    PduIdType dest_pdu_id;                          ///< 目的PduId
    PduIdType src_pdu_id[PDUR_N_TO_1_MAX_N_NUM];    ///< 源PduId
} pdur_dest_pdu_id_mapping_struct_type;

/*!*********************************************************************************************************************
 * @brief    定义PduR源PduId映射类型
 **********************************************************************************************************************/
typedef struct {
    PduIdType src_pdu_id;                            ///< 源PduId
    PduIdType dest_pdu_id[PDUR_MAX_GW_DESTINATIONS]; ///< 目的PduId
} pdur_src_pdu_id_mapping_struct_type;
#ifndef PDUR_PDU_ID_Cmd_Control
#define PDUR_PDU_ID_Cmd_Control                                                           (0u) ///< 0x0u
#endif

#ifndef PDUR_PDU_ID_ECU_Status
#define PDUR_PDU_ID_ECU_Status                                                            (1u) ///< 0x1u
#endif

#ifndef PDUR_PDU_ID_Fault_Event
#define PDUR_PDU_ID_Fault_Event                                                           (2u) ///< 0x2u
#endif

#ifndef PDUR_PDU_ID_Cmd_Control
///< PduR配置目的消息Cmd_Control的PduId为4096 * 0 + 0
#define PDUR_PDU_ID_Cmd_Control                                                             (0u) ///< 0x0u
#endif


#ifndef PDUR_PDU_ID_ECU_Status
///< PduR配置目的消息ECU_Status的PduId为4096 * 0 + 1
#define PDUR_PDU_ID_ECU_Status                                                              (1u) ///< 0x1u
#endif


#ifndef PDUR_PDU_ID_Fault_Event
///< PduR配置目的消息Fault_Event的PduId为4096 * 0 + 2
#define PDUR_PDU_ID_Fault_Event                                                             (2u) ///< 0x2u
#endif


#define PDUR_START_SEC_CODE
#include "pdur_memmap.h"
 /*!*********************************************************************************************************************
 * @brief          设置变量pdur_src_pdu_id_mapping_table的接口
 * @details        设置变量pdur_src_pdu_id_mapping_table的接口
 * @retval         void
 * @reentrant      不可重入
 * @synchronous    同步
 **********************************************************************************************************************/
extern FUNC(void, PDUR_CODE) pdur_set_src_pdu_id_mapping(const pdur_src_pdu_id_mapping_struct_type* table_ptr);

 /*!*********************************************************************************************************************
 * @brief          设置变量pdur_dest_pdu_id_mapping_table的接口
 * @details        设置变量pdur_dest_pdu_id_mapping_table的接口
 * @retval         void
 * @reentrant      不可重入
 * @synchronous    同步
 **********************************************************************************************************************/
extern FUNC(void, PDUR_CODE) pdur_set_dest_pdu_id_mapping(const pdur_dest_pdu_id_mapping_struct_type* table_ptr);

 /*!*********************************************************************************************************************
 * @brief          获取变量pdur_src_pdu_id_mapping_table的接口
 * @details        获取变量pdur_src_pdu_id_mapping_table的接口
 * @retval         pdur_src_pdu_id_mapping_struct_type  pdur_src_pdu_id_mapping_table的首元素指针
 * @reentrant      不可重入
 * @synchronous    同步
 **********************************************************************************************************************/
extern FUNC_P2CONST(pdur_src_pdu_id_mapping_struct_type, AUTOMATIC, PDUR_CODE) pdur_get_src_pdu_id_mapping(void);

 /*!*********************************************************************************************************************
 * @brief          获取变量pdur_dest_pdu_id_mapping_table的接口
 * @details        获取变量pdur_dest_pdu_id_mapping_table的接口
 * @retval         pdur_dest_pdu_id_mapping_struct_type  pdur_dest_pdu_id_mapping_struct_type的首元素指针
 * @reentrant      不可重入
 * @synchronous    同步
 **********************************************************************************************************************/
extern FUNC_P2CONST(pdur_dest_pdu_id_mapping_struct_type, AUTOMATIC, PDUR_CODE) pdur_get_dest_pdu_id_mapping(void);

 /*!*********************************************************************************************************************
 * @brief          获取变量pdur_interrupt_service_routine_table的接口
 * @details        获取变量pdur_interrupt_service_routine_table的接口
 * @retval         OS_ISRID_DEF*  pdur_interrupt_service_routine_table首元素指针
 * @reentrant      不可重入
 * @synchronous    同步
 **********************************************************************************************************************/
FUNC_P2CONST(OS_ISRID_DEF, AUTOMATIC, PDUR_CODE) pdur_get_isr_table(void);

 /*!*********************************************************************************************************************
 * @brief          获取变量pdur_interrupt_service_routine_table的长度
 * @details        获取变量pdur_interrupt_service_routine_table的长度
 * @retval         uint8  长度
 * @reentrant      不可重入
 * @synchronous    同步
 **********************************************************************************************************************/
FUNC(uint8, PDUR_CODE) pdur_get_isr_table_len(void);

#define PDUR_STOP_SEC_CODE
#include "pdur_memmap.h"
#ifdef __cplusplus
}
#endif

#endif /* PDUR_CFG_H */
