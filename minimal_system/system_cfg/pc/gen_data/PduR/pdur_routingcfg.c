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
/*
 * Copyright (C) 2024 理想汽车股份有限公司版权所有.
 * Description:  文件描述, 说明此文件作用. 
 */

/* Including File */
#include "pdur_routingcfg.h"
#include "canif.h"
#include "com.h"
/* Local Macro Definition */
#define PDUR_ROUTE_TRANSMIT_TABLE_LEN                        1u
#define PDUR_ROUTE_TRIGGERTRANSMIT_TABLE_LEN                 0u
#define PDUR_ROUTE_RXINDICATION_TABLE_LEN                    1u
#define PDUR_ROUTE_TPRXINDICATION_TABLE_LEN                  0u
#define PDUR_ROUTE_TXCONFIRMATION_TABLE_LEN                  1u
#define PDUR_ROUTE_TPTXCONFIRMATION_TABLE_LEN                0u
#define PDUR_ROUTE_COPYRXDATA_TABLE_LEN                      0u
#define PDUR_ROUTE_COPYTXDATA_TABLE_LEN                      0u
#define PDUR_ROUTE_STARTOFRECEPTION_TABLE_LEN                0u
#define PDUR_ROUTE_CANCELTRANSMIT_TABLE_LEN                  0u
#define PDUR_ROUTE_CANCELRECEIVE_TABLE_LEN                   0u

/* Local Enumeration Definition */

/* Local Type & Structure Definition */

/* Global Variable Definition */
/* IF和TP类型Transmit函数指针表 */
#define PDUR_START_SEC_CONST
#include "pdur_memmap.h"
static const pdur_route_transmit_func_table_type pdur_route_transmit_func_table[PDUR_ROUTE_TRANSMIT_TABLE_LEN] = {
    {&canif_transmit,               PDUR_CANIF},
};
#define PDUR_STOP_SEC_CONST
#include "pdur_memmap.h"

/* IF类型TriggerTransmit函数指针表 */

/* IF类型RxIndication函数指针表 */
#define PDUR_START_SEC_CONST
#include "pdur_memmap.h"
static const pdur_route_rx_indication_func_table_type pdur_route_rx_indication_func_table[PDUR_ROUTE_RXINDICATION_TABLE_LEN] = {
    {&com_rx_indication,            PDUR_COM},
};
#define PDUR_STOP_SEC_CONST
#include "pdur_memmap.h"

/* TP类型RxIndication函数指针表 */

/* IF类型TxConfirmation函数指针表 */
#define PDUR_START_SEC_CONST
#include "pdur_memmap.h"
static const pdur_route_tx_confirmation_func_table_type pdur_route_tx_confirmation_func_table[PDUR_ROUTE_TXCONFIRMATION_TABLE_LEN] = {
    {&com_tx_confirmation,          PDUR_COM},
};
#define PDUR_STOP_SEC_CONST
#include "pdur_memmap.h"

/* TP类型TxConfirmation函数指针表 */

/* TP类型CopyRxData函数指针表 */

/* TP类型CopyTxData函数指针表 */

/* TP类型StartOfReception函数指针表 */

/* CancelTransmit函数指针表 */

/* CancelReceive函数指针表 */

/* Local Variable Definition */

/* Local Function Declaration */

/* Local Function Implementation */

/* Global Function Implementation */
#define PDUR_START_SEC_CODE
#include "pdur_memmap.h"
FUNC_P2CONST(pdur_route_transmit_func_table_type, AUTOMATIC, PDUR_CODE) pdur_get_route_transmit_func_table(void)
{
    return &pdur_route_transmit_func_table[0];
}

FUNC_P2CONST(pdur_route_trigger_transmit_func_table_type, AUTOMATIC, PDUR_CODE) pdur_get_route_trigger_transmit_func_table(void)
{
    return NULL;
}

FUNC_P2CONST(pdur_route_rx_indication_func_table_type, AUTOMATIC, PDUR_CODE) pdur_get_route_rx_indication_func_table(void)
{
    return &pdur_route_rx_indication_func_table[0];
}

FUNC_P2CONST(pdur_route_tp_rx_indication_func_table_type, AUTOMATIC, PDUR_CODE) pdur_get_route_tp_rx_indication_func_table(void)
{
    return NULL;
}

FUNC_P2CONST(pdur_route_tx_confirmation_func_table_type, AUTOMATIC, PDUR_CODE) pdur_get_route_tx_confirmation_func_table(void)
{
    return &pdur_route_tx_confirmation_func_table[0];
}

FUNC_P2CONST(pdur_route_tp_tx_confirmation_func_table_type, AUTOMATIC, PDUR_CODE) pdur_get_route_tp_tx_confirmation_func_table(void)
{
    return NULL;
}

FUNC_P2CONST(pdur_route_copy_rx_data_func_table_type, AUTOMATIC, PDUR_CODE) pdur_get_route_copy_rx_data_func_table(void)
{
    return NULL;
}

FUNC_P2CONST(pdur_route_copy_tx_data_func_table_type, AUTOMATIC, PDUR_CODE) pdur_get_route_copy_tx_data_func_table(void)
{
    return NULL;
}

FUNC_P2CONST(pdur_route_start_of_reception_func_table_type, AUTOMATIC, PDUR_CODE) pdur_get_route_start_of_reception_func_table(void)
{
    return NULL;
}

FUNC_P2CONST(pdur_route_cancel_transmit_func_table_type, AUTOMATIC, PDUR_CODE) pdur_get_route_cancel_transmit_func_table(void)
{
    return NULL;
}

FUNC_P2CONST(pdur_route_cancel_receive_func_table_type, AUTOMATIC, PDUR_CODE) pdur_get_route_cancel_receive_func_table(void)
{
    return NULL;
}

FUNC(uint8, PDUR_CODE) pdur_get_len_of_route_transmit_func_table(void)
{
    return PDUR_ROUTE_TRANSMIT_TABLE_LEN;
}

FUNC(uint8, PDUR_CODE) pdur_get_len_of_route_trigger_transmit_func_table(void)
{
    return PDUR_ROUTE_TRIGGERTRANSMIT_TABLE_LEN;
}

FUNC(uint8, PDUR_CODE) pdur_get_len_of_route_rx_indication_func_table(void)
{
    return PDUR_ROUTE_RXINDICATION_TABLE_LEN;
}

FUNC(uint8, PDUR_CODE) pdur_get_len_of_route_tp_rx_indication_func_table(void)
{
    return PDUR_ROUTE_TPRXINDICATION_TABLE_LEN;
}

FUNC(uint8, PDUR_CODE) pdur_get_len_of_route_tx_confirmation_func_table(void)
{
    return PDUR_ROUTE_TXCONFIRMATION_TABLE_LEN;
}

FUNC(uint8, PDUR_CODE) pdur_get_len_of_route_tp_tx_confirmation_func_table(void)
{
    return PDUR_ROUTE_TPTXCONFIRMATION_TABLE_LEN;
}

FUNC(uint8, PDUR_CODE) pdur_get_len_of_route_copy_rx_data_func_table(void)
{
    return PDUR_ROUTE_COPYRXDATA_TABLE_LEN;
}

FUNC(uint8, PDUR_CODE) pdur_get_len_of_route_copy_tx_data_func_table(void)
{
    return PDUR_ROUTE_COPYTXDATA_TABLE_LEN;
}

FUNC(uint8, PDUR_CODE) pdur_get_len_of_route_start_of_reception_func_table(void)
{
    return PDUR_ROUTE_STARTOFRECEPTION_TABLE_LEN;
}

FUNC(uint8, PDUR_CODE) pdur_get_len_of_route_cancel_transmit_func_table(void)
{
    return PDUR_ROUTE_CANCELTRANSMIT_TABLE_LEN;
}

FUNC(uint8, PDUR_CODE) pdur_get_len_of_route_cancel_receive_func_table(void)
{
    return PDUR_ROUTE_CANCELRECEIVE_TABLE_LEN;
}
#define PDUR_STOP_SEC_CODE
#include "pdur_memmap.h"