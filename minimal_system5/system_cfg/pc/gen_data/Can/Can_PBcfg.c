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
 * @file        Can_PBcfg.c
 * @brief       PC MCAL Can post-build configuration
 * @details     Controllers / HOHs / EcuBus-Pro JSON-RPC connection
 * @date        2026-10-24 23:59:48
 * @toolversion V0.1.0-DEV
 **********************************************************************************************************************/

#include "Can.h"

const Can_RpcConfigType Can_RpcConfig = {
    .host = "127.0.0.1",
    .port = 17320u,
    .socket_path = "",
    .auto_reconnect = TRUE,
    .reconnect_interval_ms = 500u
};


const Can_ControllerConfigType Can_ControllerConfig[CAN_CONTROLLER_NUM] = {
    {
        .controller_id = 0u,
        .activation = TRUE,
        .name = "CanController_0",
        .vendor = "simulate",
        .handle = 1u,
        .canfd = FALSE,
        .bitrate_bps = 500000u,
        .fd_bitrate_bps = 0u,
        .brs = FALSE,
        .hardware_name = "SIM-CAN-1",
        .baud_id = 0u
    }
};



const Can_HardwareObjectConfigType Can_HardwareObjectConfig[CAN_HOH_NUM] = {
    {
        .hoh_id = 0u,
        .controller_id = 0u,
        .object_type = CAN_OBJECT_TRANSMIT,
        .handle_type = CAN_HANDLE_BASIC,
        .id_type = CAN_ID_STANDARD,
        .padding = 0u,
        .has_filter = FALSE,
        .filter_code = 0u,
        .filter_mask = 0u
    },
    {
        .hoh_id = 1u,
        .controller_id = 0u,
        .object_type = CAN_OBJECT_RECEIVE,
        .handle_type = CAN_HANDLE_BASIC,
        .id_type = CAN_ID_STANDARD,
        .padding = 0u,
        .has_filter = FALSE,
        .filter_code = 0u,
        .filter_mask = 0u
    }
};


const Can_ConfigType Can_Config = {
    .rpc = &Can_RpcConfig,
    .controllers = Can_ControllerConfig,
    .controller_count = CAN_CONTROLLER_NUM,
    .hohs = Can_HardwareObjectConfig,
    .hoh_count = CAN_HOH_NUM
};