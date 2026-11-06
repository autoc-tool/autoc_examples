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
 * @file        pdur_routingcfg.h
 * @brief       PduR路由配置头文件
 * @details     主要包含PduR路由的配置
 * @date        2026-10-25 11:39:37
 * @toolversion V0.1.0-DEV
 **********************************************************************************************************************/

#ifndef PDUR_ROUTINGCFG_H
#define PDUR_ROUTINGCFG_H

#include "pdur_types.h"
#include "comstack_types.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* Global Macro Definition */
#define PDUR_UP_MODULES                                                         0u ///< 上层模块
#define PDUR_COM                                                                1u
#define PDUR_LOIF_MODULES                                                       2u ///< 下层IF模块
#define PDUR_CANIF                                                              3u
#define PDUR_LOTP_MODULES                                                       4u ///< 下层TP模块
#define PDUR_END_OF_MODULES                                                     5u ///< 结束
#define PDUR_SUPPORT_CANCELTRANSMIT                                             STD_OFF
#define PDUR_SUPPORT_CANCELRECEIVE                                              STD_OFF
/* Global Enumeration Definition */

/* Global Type & Structure Definition */
/* IF和TP类型Transmit函数指针定义 */
typedef Std_ReturnType (*pdur_route_transmit_func_ptr)(PduIdType pdu_id, const PduInfoType *pdu_info_ptr);
/* IF类型TriggerTransmit函数指针定义 */
typedef Std_ReturnType (*pdur_route_trigger_transmit_func_Ptr)(PduIdType pdu_id, PduInfoType *pdu_info_ptr);
/* IF类型RxIndication函数指针定义 */
typedef void (*pdur_route_rx_indication_func_ptr)(PduIdType pdu_id, const PduInfoType *pdu_info_ptr);
/* TP类型RxIndication函数指针定义 */
typedef void (*pdur_route_tp_rx_indication_func_ptr)(PduIdType pdu_id, NotifResultType result);
/* IF类型TxConfirmation函数指针定义 */
typedef void (*pdur_route_tx_confirmation_func_ptr)(PduIdType pdu_id, NotifResultType result);
/* TP类型TxConfirmation函数指针定义 */
typedef void (*pdur_route_tp_tx_confirmation_func_ptr)(PduIdType pdu_id, NotifResultType result);
/* TP类型CopyRxData函数指针定义 */
typedef BufReq_ReturnType (*pdur_route_copy_rx_data_func_ptr)(PduIdType pdu_id, const PduInfoType *info,
    PduLengthType *buffer_size_ptr);
/* TP类型CopyTxData函数指针定义 */
typedef BufReq_ReturnType (*pdur_route_copy_tx_data_func_ptr)(PduIdType pdu_id, const PduInfoType *info,
    const RetryInfoType *retry, PduLengthType *available_data_ptr);
/* TP类型StartOfReception函数指针定义 */
typedef BufReq_ReturnType (*pdur_route_start_of_reception_func_ptr)(PduIdType pdu_id, const PduInfoType *info,
    PduLengthType TpSduLength, PduLengthType *buffer_size_ptr);
/* CancelTransmit函数指针定义 */
typedef Std_ReturnType (*pdur_route_cancel_transmit_func_ptr)(PduIdType pdu_id);
/* CancelReceive函数指针定义 */
typedef Std_ReturnType (*pdur_route_cancel_receive_func_ptr)(PduIdType pdu_id);

typedef struct {
    pdur_route_transmit_func_ptr func_ptr;
    pdur_module_type module_id;
} pdur_route_transmit_func_table_type;

typedef struct {
    pdur_route_trigger_transmit_func_Ptr func_ptr;
    pdur_module_type module_id;
} pdur_route_trigger_transmit_func_table_type;

typedef struct {
    pdur_route_rx_indication_func_ptr func_ptr;
    pdur_module_type module_id;
} pdur_route_rx_indication_func_table_type;

typedef struct {
    pdur_route_tp_rx_indication_func_ptr func_ptr;
    pdur_module_type module_id;
} pdur_route_tp_rx_indication_func_table_type;

typedef struct {
    pdur_route_tx_confirmation_func_ptr func_ptr;
    pdur_module_type module_id;
} pdur_route_tx_confirmation_func_table_type;

typedef struct {
    pdur_route_tp_tx_confirmation_func_ptr func_ptr;
    pdur_module_type module_id;
} pdur_route_tp_tx_confirmation_func_table_type;

typedef struct {
    pdur_route_copy_rx_data_func_ptr func_ptr;
    pdur_module_type module_id;
} pdur_route_copy_rx_data_func_table_type;

typedef struct {
    pdur_route_copy_tx_data_func_ptr func_ptr;
    pdur_module_type module_id;
} pdur_route_copy_tx_data_func_table_type;

typedef struct {
    pdur_route_start_of_reception_func_ptr func_ptr;
    pdur_module_type module_id;
} pdur_route_start_of_reception_func_table_type;

typedef struct {
    pdur_route_cancel_transmit_func_ptr func_ptr;
    pdur_module_type module_id;
} pdur_route_cancel_transmit_func_table_type;

typedef struct {
    pdur_route_cancel_receive_func_ptr func_ptr;
    pdur_module_type module_id;
} pdur_route_cancel_receive_func_table_type;


/* Global Variable Declaration */

/* Global Function Declaration */
#define PDUR_START_SEC_CODE
#include "pdur_memmap.h"
FUNC_P2CONST(pdur_route_transmit_func_table_type, AUTOMATIC, PDUR_CODE) pdur_get_route_transmit_func_table(void);
FUNC_P2CONST(pdur_route_trigger_transmit_func_table_type, AUTOMATIC, PDUR_CODE) pdur_get_route_trigger_transmit_func_table(void);
FUNC_P2CONST(pdur_route_rx_indication_func_table_type, AUTOMATIC, PDUR_CODE) pdur_get_route_rx_indication_func_table(void);
FUNC_P2CONST(pdur_route_tp_rx_indication_func_table_type, AUTOMATIC, PDUR_CODE) pdur_get_route_tp_rx_indication_func_table(void);
FUNC_P2CONST(pdur_route_tx_confirmation_func_table_type, AUTOMATIC, PDUR_CODE) pdur_get_route_tx_confirmation_func_table(void);
FUNC_P2CONST(pdur_route_tp_tx_confirmation_func_table_type, AUTOMATIC, PDUR_CODE) pdur_get_route_tp_tx_confirmation_func_table(void);
FUNC_P2CONST(pdur_route_copy_rx_data_func_table_type, AUTOMATIC, PDUR_CODE) pdur_get_route_copy_rx_data_func_table(void);
FUNC_P2CONST(pdur_route_copy_tx_data_func_table_type, AUTOMATIC, PDUR_CODE) pdur_get_route_copy_tx_data_func_table(void);
FUNC_P2CONST(pdur_route_start_of_reception_func_table_type, AUTOMATIC, PDUR_CODE) pdur_get_route_start_of_reception_func_table(void);
FUNC_P2CONST(pdur_route_cancel_transmit_func_table_type, AUTOMATIC, PDUR_CODE) pdur_get_route_cancel_transmit_func_table(void);
FUNC_P2CONST(pdur_route_cancel_receive_func_table_type, AUTOMATIC, PDUR_CODE) pdur_get_route_cancel_receive_func_table(void);
FUNC(uint8, PDUR_CODE) pdur_get_len_of_route_transmit_func_table(void);
FUNC(uint8, PDUR_CODE) pdur_get_len_of_route_trigger_transmit_func_table(void);
FUNC(uint8, PDUR_CODE) pdur_get_len_of_route_rx_indication_func_table(void);
FUNC(uint8, PDUR_CODE) pdur_get_len_of_route_tp_rx_indication_func_table(void);
FUNC(uint8, PDUR_CODE) pdur_get_len_of_route_tx_confirmation_func_table(void);
FUNC(uint8, PDUR_CODE) pdur_get_len_of_route_tp_tx_confirmation_func_table(void);
FUNC(uint8, PDUR_CODE) pdur_get_len_of_route_copy_rx_data_func_table(void);
FUNC(uint8, PDUR_CODE) pdur_get_len_of_route_copy_tx_data_func_table(void);
FUNC(uint8, PDUR_CODE) pdur_get_len_of_route_start_of_reception_func_table(void);
FUNC(uint8, PDUR_CODE) pdur_get_len_of_route_cancel_transmit_func_table(void);
FUNC(uint8, PDUR_CODE) pdur_get_len_of_route_cancel_receive_func_table(void);
FUNC(boolean, PDUR_CODE) pdur_is_up_module(uint8 input);
FUNC(boolean, PDUR_CODE) pdur_is_if_module(uint8 input);
FUNC(boolean, PDUR_CODE) pdur_is_tp_module(uint8 input);
FUNC(boolean, PDUR_CODE) pdur_is_lo_module(uint8 input);

#define PDUR_STOP_SEC_CODE
#include "pdur_memmap.h"
/* Global Function Implementation */

#ifdef __cplusplus
}
#endif


#endif	 /* PDUR_ROUTINGCFG_H */
