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
 * @file        pdur_module_interface.h
 * @brief       PduR接口头文件
 * @details     主要包含PduR模块接口的配置
 * @date        2026-10-25 11:39:37
 * @toolversion V0.1.0-DEV
 **********************************************************************************************************************/
#ifndef PDUR_CANIF_H
#define PDUR_CANIF_H
/* Description:  PduR - CanIf模块头文件 */
#include "comstack_types.h"
#include "pdur_types.h"

/* Global Fuction Implementation */
#define PDUR_START_SEC_CODE
#include "pdur_memmap.h" 
/*!*********************************************************************************************************************
 * @brief          PduR提供给CanIf的RxIndication接口
 * @details        PduR提供给CanIf的RxIndication接口
 * @param[in]      pdu_id           报文标识
 * @param[in]      pdu_info_ptr      报文内容指针
 * @reentrant      不可重入
 * @synchronous    同步
 **********************************************************************************************************************/
FUNC(void, PDUR_CODE) pdur_canif_rx_indication(PduIdType pdu_id, const PduInfoType *pdu_info_ptr);

/*!*********************************************************************************************************************
 * @brief          PduR提供给CanIf的tx_confirmation接口
 * @details        PduR提供给CanIf的Tptx_confirmation
 * @param[in]      pdu_id           报文标识
 * @param[in]      result          接收结果
 * @reentrant      不可重入
 * @synchronous    同步
 **********************************************************************************************************************/
FUNC(void, PDUR_CODE) pdur_canif_tx_confirmation(PduIdType pdu_id, NotifResultType result);

/*!*********************************************************************************************************************
 * @brief          PduR提供给CanIf的Triggertransmit接口
 * @details        PduR提供给CanIf的Triggertransmit接口
 * @param[in]      pdu_id           报文标识
 * @param[in]      pdu_info_ptr      报文内容指针
 * @retval         E_OK            触发发送成功
 * @retval         E_NOT_OK        触发发送失败
 * @reentrant      不可重入
 * @synchronous    同步
 **********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) pdur_canif_trigger_transmit(PduIdType pdu_id, PduInfoType *pdu_info_ptr);
#define PDUR_STOP_SEC_CODE
#include "pdur_memmap.h"
#endif /* PDUR_CANIF_H */
