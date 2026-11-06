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
 * @file        canif_mcal_adapter.c
 * @brief       autoc_mcal Can driver -> CanIf callback adapter
 * @details     Forwards the Can driver callbacks of the PC MCAL to the CanIf
 *              indication/confirmation services.
 **********************************************************************************************************************/

#include "Can.h"
#include "canif_cbk.h"

void CanIf_TxConfirmation(PduIdType CanTxPduId)
{
    canif_tx_confirmation(CanTxPduId);
}

void CanIf_RxIndication(Can_HwType *Mailbox, PduInfoType *PduInfoPtr)
{
    canif_rx_indication(Mailbox, PduInfoPtr);
}

void CanIf_ControllerModeIndication(uint8 ControllerId, Can_ControllerStateType ControllerMode)
{
    canif_controller_mode_indication(ControllerId, ControllerMode);
}

void CanIf_ControllerBusOff(uint8 ControllerId)
{
    canif_controller_bus_off(ControllerId);
}
