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
 * Generation Time : 2026-10-24 23:59:11
 * Project Name    : minimal_system5
 * Tool Version    : V0.1.0-DEV
 */
/* Including File */
#include "pdur.h"
#include "pdur_pbcfg.h"
#include "pdur_internal.h"
#include "Compiler.h"
#include "pdur_routingcfg.h"
#include "canif.h"
#include "canif_pbcfg.h"
#include "com.h"
#include "com_pbcfg.h"

/* Routing Path Group, to be filled by user */
#define PDUR_START_SEC_CONST
#include "pdur_memmap.h"
/* 0 Cmd_Control */
static CONST(pdur_dest_pdu_type, PDUR_CONST) pdur_destcmd_control = {
    .dest_module           = PDUR_COM, // DestPdu对应的目的模块
    .pdur_dest_pdu_core      = 0u, // DestPdu所属的核编号
    .data_provision        = PDUR_DIRECT,
    .idx_num               = 0u, // DestPdu所属的RoutingPathGroup在List里的数量
    .start_idx             = 255u, // DestPdu所属的RoutingPathGroup在其List里的起始脚标
    .dest_pdu_id            = COM_PDU_ID_Cmd_Control, // DestPdu对应的编号
    .pdu_len_strategy       = PDUR_STRATEGY_UNUSED, // DestPdu超出设定长度时的处理逻辑
    .pdu_len_in_ecuc         = 8u, // DestPdu的设定长度
};
/* 1 ECU_Status */
static CONST(pdur_dest_pdu_type, PDUR_CONST) pdur_destecu_status = {
    .dest_module           = PDUR_CANIF, // DestPdu对应的目的模块
    .pdur_dest_pdu_core      = 0u, // DestPdu所属的核编号
    .data_provision        = PDUR_DIRECT,
    .idx_num               = 0u, // DestPdu所属的RoutingPathGroup在List里的数量
    .start_idx             = 255u, // DestPdu所属的RoutingPathGroup在其List里的起始脚标
    .dest_pdu_id            = CANIF_PDU_ID_ECU_Status, // DestPdu对应的编号
    .pdu_len_strategy       = PDUR_STRATEGY_UNUSED, // DestPdu超出设定长度时的处理逻辑
    .pdu_len_in_ecuc         = 8u, // DestPdu的设定长度
};
/* 2 Fault_Event */
static CONST(pdur_dest_pdu_type, PDUR_CONST) pdur_destfault_event = {
    .dest_module           = PDUR_CANIF, // DestPdu对应的目的模块
    .pdur_dest_pdu_core      = 0u, // DestPdu所属的核编号
    .data_provision        = PDUR_DIRECT,
    .idx_num               = 0u, // DestPdu所属的RoutingPathGroup在List里的数量
    .start_idx             = 255u, // DestPdu所属的RoutingPathGroup在其List里的起始脚标
    .dest_pdu_id            = CANIF_PDU_ID_Fault_Event, // DestPdu对应的编号
    .pdu_len_strategy       = PDUR_STRATEGY_UNUSED, // DestPdu超出设定长度时的处理逻辑
    .pdu_len_in_ecuc         = 2u, // DestPdu的设定长度
};
#define PDUR_STOP_SEC_CONST
#include "pdur_memmap.h"

#define PDUR_START_SEC_CONST
#include "pdur_memmap.h"
/* 0 Cmd_Control_Rx */
static const pdur_dest_pdu_type* const pdur_routing_dest_list_cmd_control_rx[] = {
    &pdur_destcmd_control,
};

/* 1 ECU_Status_Tx */
static const pdur_dest_pdu_type* const pdur_routing_dest_list_ecu_status_tx[] = {
    &pdur_destecu_status,
};

/* 2 Fault_Event_Tx */
static const pdur_dest_pdu_type* const pdur_routing_dest_list_fault_event_tx[] = {
    &pdur_destfault_event,
};

#define PDUR_STOP_SEC_CONST
#include "pdur_memmap.h"

#define PDUR_START_SEC_CONST
#include "pdur_memmap.h"
static CONST(pdur_routing_path_type, PDUR_CONST) pdur_routing_paths[] = {
    {   /* 0 Cmd_Contr */
        .src_module         = PDUR_CANIF,
        .pdur_destinatn_num  = 1u,
        .pdur_src_pdu_core    = 0u,
        .pdur_direct_gateway = PDUR_GATEWAY_DIRECT,
        .pdur_tp_threshld    = 0u,
        .pdur_queue_depth    = 1u,
        .src_pdu_id          = CANIF_PDU_ID_Cmd_Control,
        .pdur_dest_pdus      = pdur_routing_dest_list_cmd_control_rx,
        .pdur_tx_buffer_idx   = PDUR_NO_BUFFER,
    },
    {   /* 1 ECU_Stat */
        .src_module         = PDUR_COM,
        .pdur_destinatn_num  = 1u,
        .pdur_src_pdu_core    = 0u,
        .pdur_direct_gateway = PDUR_GATEWAY_DIRECT,
        .pdur_tp_threshld    = 0u,
        .pdur_queue_depth    = 1u,
        .src_pdu_id          = COM_PDU_ID_ECU_Status,
        .pdur_dest_pdus      = pdur_routing_dest_list_ecu_status_tx,
        .pdur_tx_buffer_idx   = PDUR_NO_BUFFER,
    },
    {   /* 2 Fault_Eve */
        .src_module         = PDUR_COM,
        .pdur_destinatn_num  = 1u,
        .pdur_src_pdu_core    = 0u,
        .pdur_direct_gateway = PDUR_GATEWAY_DIRECT,
        .pdur_tp_threshld    = 0u,
        .pdur_queue_depth    = 1u,
        .src_pdu_id          = COM_PDU_ID_Fault_Event,
        .pdur_dest_pdus      = pdur_routing_dest_list_fault_event_tx,
        .pdur_tx_buffer_idx   = PDUR_NO_BUFFER,
    },
};
#define PDUR_STOP_SEC_CONST
#include "pdur_memmap.h"

#define PDUR_START_SEC_CONST
#include "pdur_memmap.h"
/* Exported config */
CONST(pdur_pb_config_type, PDUR_CONST) pdur_config = {
    .pdur_configuration_id                = 0,
    .routing_paths                       = pdur_routing_paths,
    .n_routing_paths                      = (PduIdType)(sizeof(pdur_routing_paths) / sizeof(pdur_routing_paths[0u])),
    .routing_path_groups_init_value_list     = NULL,
    .routing_path_groups_dest_pdu_list       = NULL,
    .routing_path_group_list               = NULL,
};
#define PDUR_STOP_SEC_CONST
#include "pdur_memmap.h"
