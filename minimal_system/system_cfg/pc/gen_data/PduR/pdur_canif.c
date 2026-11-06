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
 * Generation Time : 2026-10-26 10:16:14
 * Project Name    : minimal_system
 * Tool Version    : V0.1.0-DEV
 */
/* Description:  PduR - CanIf模块源文件 */

/* Including File */
#include "pdur.h"
#include "pdur_canif.h"
#include "pdur_routingcfg.h"
#define PDUR_SERVICE_DUMMY PDUR_CANIF

/* Global Fuction Implementation */
#define PDUR_START_SEC_CODE
#include "pdur_memmap.h" 
FUNC(void, PDUR_CODE) pdur_canif_rx_indication(PduIdType pdu_id, const PduInfoType *pdu_info_ptr)
{
    pdur_rx_indication(pdu_id, pdu_info_ptr, PDUR_SERVICE_DUMMY);
}

FUNC(void, PDUR_CODE) pdur_canif_tx_confirmation(PduIdType pdu_id, NotifResultType result)
{
    pdur_tx_confirmation(pdu_id, (uint8)result, PDUR_SERVICE_DUMMY);
}

FUNC(Std_ReturnType, PDUR_CODE) pdur_canif_trigger_transmit(PduIdType pdu_id, PduInfoType *pdu_info_ptr)
{
    return pdur_trigger_transmit(pdu_id, pdu_info_ptr, PDUR_SERVICE_DUMMY);
}
#define PDUR_STOP_SEC_CODE
#include "pdur_memmap.h"
