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
 * @file        Can_Cfg.h
 * @brief       PC MCAL Can pre-compile configuration
 * @details     Generated from Can ECUC (EcuBus-Pro JSON-RPC backend)
 * @date        2026-10-24 23:59:48
 * @toolversion V0.1.0-DEV
 **********************************************************************************************************************/

#ifndef CAN_CFG_H
#define CAN_CFG_H

#include "Std_Types.h"

#define CAN_VENDOR_ID                 (0u)
#define CAN_MODULE_ID                 (80u)
#define CAN_SW_MAJOR_VERSION          (1u)
#define CAN_SW_MINOR_VERSION          (0u)
#define CAN_SW_PATCH_VERSION          (0u)

#define CAN_DEV_ERROR_DETECT          STD_OFF
#define CAN_VERSION_INFO_API          STD_OFF
#define CAN_SET_BAUDRATE_API          STD_OFF

#define CAN_CONTROLLER_NUM            1u
#define CAN_HOH_NUM                   2u

#define CAN_RPC_HOST                  "127.0.0.1"
#define CAN_RPC_PORT                  17320u
#define CAN_RPC_SOCKET_PATH           ""
#define CAN_RPC_AUTO_RECONNECT        STD_ON
#define CAN_RPC_RECONNECT_INTERVAL_MS 500u


#define CanController_0_ID           0u


#define CanHardwareObject_0               0u
#define CanHardwareObject_1               1u

#endif /* CAN_CFG_H */