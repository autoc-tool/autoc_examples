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
 * Generation Time : 2026-10-26 10:16:13
 * Project Name    : minimal_system
 * Tool Version    : V0.1.0-DEV
 */

/* Including File */
#include "com.h"
#define  COM_START_SEC_CONST
#include "com_memmap.h"
/**********************************************************************************************************************
  Notifications
**********************************************************************************************************************/
// Rx Notification
CONST(com_rx_signal_notification_callout_type, COM_CONST) com_rx_signal_notification[] = {
    NULL
};

// Rx TimeoutNotification
CONST(com_rx_signal_timeout_notification_callout_type, COM_CONST) com_rx_signal_timeout_notification[] = {
    NULL
};

// Rx InvalidNotification
CONST(com_rx_signal_invalid_notification_callout_type, COM_CONST) com_rx_signal_invalid_notification[] = {
    NULL
};

// Rx Error Notification
CONST(com_rx_signal_error_notification_callout_type, COM_CONST) com_rx_signal_error_notification[] = {
    NULL
};

// Tx Notification
CONST(com_tx_signal_notification_callout_type, COM_CONST) com_tx_signal_notification[] = {
    NULL
};

// Tx TimeoutNotification
CONST(com_tx_signal_timeout_notification_callout_type, COM_CONST) com_tx_signal_timeout_notification[] = {
    NULL
};

// Tx InvalidNotification
CONST(com_tx_signal_invalid_notification_callout_type, COM_CONST) com_tx_signal_invalid_notification[] = {
    NULL
};

// Tx Error Notification
CONST(com_tx_signal_error_notification_callout_type, COM_CONST) com_tx_signal_error_notification[] = {
    NULL
};

/**********************************************************************************************************************
  Callouts
**********************************************************************************************************************/
// Rx callouts
CONST(com_rx_ipdu_callout_type, COM_CONST) com_rx_ipdu_callouts[] = {
    NULL
};

// Tx callouts
CONST(com_tx_ipdu_callout_type, COM_CONST) com_tx_ipdu_callouts[] = {
    NULL
};

// Trigger transmit callouts
CONST(com_tx_ipdu_callout_type, COM_CONST) com_trigger_transmit_ipdu_callouts[] = {
    NULL
};
#define  COM_STOP_SEC_CONST
#include "com_memmap.h"