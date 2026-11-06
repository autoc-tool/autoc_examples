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
/***********************************************************************************************************************
 * @file        Com_PBCfg.h
 * @brief       Com公共配置头文件
 * @details     主要包含Com模块公共的配置相关信息
 * @date        2026-10-26 10:16:14
 * @toolversion V0.1.0-DEV
 **********************************************************************************************************************/

#ifndef COM_PBCFG_H
#define COM_PBCFG_H

#include "com_types.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* Global Macro Definition */
/* COM Tx IPDU IDs */
#define COM_PDU_ID_ECU_Status                                                   (0U)
#define COM_PDU_ID_Fault_Event                                                  (1U)

/* COM Rx IPDU IDs */
#define COM_PDU_ID_Cmd_Control                                                  (0U)

/* COM PDU GROUP IDs */
#define ComConf_ComIPduGroup_ComTxGroup                                         (0U)
#define ComConf_ComIPduGroup_ComRxGroup                                         (1U)

#define  COM_START_SEC_CONST
#include "com_memmap.h"
/*!*********************************************************************************************************************
 *  @brief  com配置类型
 **********************************************************************************************************************/
extern CONST(com_config_type, COM_CONST) com_configuration;
/*!*********************************************************************************************************************
 *  @brief  接收信息类型
 **********************************************************************************************************************/ 
/*!*********************************************************************************************************************
 *  @brief  接收消息信息类型
 **********************************************************************************************************************/
extern CONST(com_rx_tout_message_info_type, COM_CONST) com_rx_pdu_tout_struct[1]; 
/*!*********************************************************************************************************************
 *  @brief  发送消息消息类型
 **********************************************************************************************************************/
extern CONST(com_tx_tout_message_info_type, COM_CONST) com_tx_pdu_tout_struct[1]; 
/*!*********************************************************************************************************************
 *  @brief  com接收IPDU类型
 **********************************************************************************************************************/
extern CONST(com_rx_ipdu_type, COM_CONST) com_rx_ipdu_const[2];
/*!*********************************************************************************************************************
 *  @brief  com发送IPDU类型
 **********************************************************************************************************************/
extern CONST(com_tx_ipdu_type, COM_CONST) com_tx_ipdu_const[3];
/*!*********************************************************************************************************************
 *  @brief  com接收信号类型
 **********************************************************************************************************************/
extern CONST(com_rx_signal_type, COM_CONST) com_rx_signal_const[6];
/*!*********************************************************************************************************************
 *  @brief  com发送信号类型
 **********************************************************************************************************************/
extern CONST(com_tx_signal_type, COM_CONST) com_tx_signal_const[8];
/*!*********************************************************************************************************************
 *  @brief  com主发送函数结构类型
 **********************************************************************************************************************/
extern CONST(com_main_function_tx_struct_type, COM_CONST) com_tx_main_function_des[1];
/*!*********************************************************************************************************************
 *  @brief  com主接收函数结构类型
 **********************************************************************************************************************/
extern CONST(com_main_function_rx_struct_type, COM_CONST) com_rx_main_function_des[1];
#define  COM_STOP_SEC_CONST
#include "com_memmap.h"
/**********************************************************************************************************************
  com_const_init_value_u8
**********************************************************************************************************************/
#define COM_START_SEC_PRIVATE_BSS
#include "com_memmap.h"
/*!*********************************************************************************************************************
 *  @brief  com接收信号缓存uint8类型
 **********************************************************************************************************************/
extern VAR(uint8, COM_PRIVATE_BSS) com_rx_sig_buf_u8[5];
#define COM_STOP_SEC_PRIVATE_BSS
#include "com_memmap.h"

/*!*********************************************************************************************************************
 *  @brief  buffer memap
 **********************************************************************************************************************/
/*!*********************************************************************************************************************
 *  @brief  com_init_status com_config
 **********************************************************************************************************************/
#define COM_START_SEC_PRIVATE_BSS
#include "com_memmap.h"
extern VAR(com_status_type, COM_PRIVATE_BSS) com_init_status;
#define COM_STOP_SEC_PRIVATE_BSS
#include "com_memmap.h"

#define COM_START_SEC_PRIVATE_BSS
#include "com_memmap.h"
extern P2CONST(com_config_type, COM_PRIVATE_BSS, Com_VAR_Class) com_config;
#define COM_STOP_SEC_PRIVATE_BSS
#include "com_memmap.h"

#define COM_START_SEC_PRIVATE_BSS
#include "com_memmap.h"
/*!*********************************************************************************************************************
 *  @brief  CAN单核部署 Tx Rx IPDU Buff分配
 **********************************************************************************************************************/
extern VAR(com_self_tx_ipdu_type, COM_PRIVATE_BSS) com_self_tx_ipdu[COM_MAX_N_TXIPDUS];
extern VAR(com_self_rx_ipdu_type, COM_PRIVATE_BSS) com_self_rx_ipdu[COM_MAX_N_RXIPDUS];
#define COM_STOP_SEC_PRIVATE_BSS
#include "com_memmap.h"

/* Data, deferred data and shadow buffer */
#define COM_START_SEC_PRIVATE_BSS
#include "com_memmap.h"
extern VAR(uint8, COM_PRIVATE_BSS) com_self_tx_buffer[COM_MAX_TXBUFFER_SIZE];
extern VAR(uint8, COM_PRIVATE_BSS) com_self_rx_buffer[COM_MAX_RXBUFFER_SIZE];
#define COM_STOP_SEC_PRIVATE_BSS
#include "com_memmap.h"

#ifdef __cplusplus
}
#endif

#endif /* COM_PBCFG_H */