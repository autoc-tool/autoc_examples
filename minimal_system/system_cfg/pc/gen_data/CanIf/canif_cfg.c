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
 * Generation Time : 2026-10-26 11:04:38
 * Project Name    : minimal_system
 * Tool Version    : V0.1.0-DEV
 * Description:  CanIf模块配置文件.
 */

#include "canif_internal.h"
#include "canif_cantrcv.h"
#include "canif_types.h"

#if defined(CONFIG_MODULE_PDUR) && (CONFIG_MODULE_PDUR == 1)
#include "pdur.h"
#include "pdur_canif.h"
#endif

#if defined(CONFIG_MODULE_CANNM) && (CONFIG_MODULE_CANNM == 1)
#include "cannm_cbk.h"
#include "cannm_lcfg.h"
#endif

#if defined(CONFIG_MODULE_CANSM) && (CONFIG_MODULE_CANSM == 1)
#include "cansm.h"
#include "cansm_canif.h"
#endif

#if defined(CONFIG_MODULE_CANTRCV1145) && (CONFIG_MODULE_CANTRCV1145 == 1)
#include "cantrcv_tja1145.h"
#endif

#if defined(CONFIG_SERVM_ECUM) && (CONFIG_SERVM_ECUM == 1)
#include "sysm_init.h"
#endif

#if defined(CONFIG_MODULE_CANTSYN) && (CONFIG_MODULE_CANTSYN == 1)
#include "cantsyn.h"
#endif

#if defined(CONFIG_MODULE_CANTP) && (CONFIG_MODULE_CANTP == 1)
#include "cantp.h"
#endif


#define CanHardwareObject_CanHardwareObject_Rx    1u


#define CANIF_INVALID_CANID                                    0xFFFFFFFFU

#define CANIF_START_SEC_CONST
#include "canif_memmap.h"

CONST(canif_rx_pdu_config_type, CANIF_CONST) hrh_rx_pdu_canif_hrh_cfg[CANIF_MAX_NOF_RX_PDU] = {
      /* CanIdIsExtended      CanIfUserRxIndication CanIfCanRxPduDlc     CanIfCanRxPduId                                                                       index                CanIf_RxCalloutFctPtr                    CanIfCanRxPduLowerCanId CanIfCanRxPduUpperCanId CanIfCanRxPduCanId   */
/*  0*/ {(boolean)FALSE      ,(uint8)0            ,(uint8)0            ,(PduIdType)PDUR_PDU_ID_Cmd_Control                                                   ,(uint16)0           ,NULL                                    ,CANIF_INVALID_CANID ,CANIF_INVALID_CANID ,0x200               },
};

CONST(canif_hth_config_type, CANIF_CONST) canif_hth_config_data_canif_init_hoh_cfg[CANIF_MAX_NOF_TX_BUFFERS] = {
  /*     0*/ {CANIF_HANDLE_TYPE_BASIC,                                0,        0,           0}, /* CanHardwareObject_Tx, CORE0 */
};

CONST(uint16, CANIF_CONST) canif_can_hoh_to_canif_hrh_map_canif_init_hoh_cfg[CANIF_MAX_NOF_HRH_COUNT] = {
 CanHardwareObject_CanHardwareObject_Rx,  
};

CONST(canif_hrh_config_type, CANIF_CONST) canif_hrh_config_data_canif_init_hoh_cfg[CANIF_MAX_NOF_HRH_COUNT] = {
/*1*/ {CANIF_HANDLE_TYPE_BASIC,   (boolean)TRUE        ,(canif_channel_id_type)0      ,  (uint16)1U,             NULL,             &hrh_rx_pdu_canif_hrh_cfg[0]}, 
};

CONST(canif_hoh_config_type, CANIF_CONST) canif_hoh_config_data[] = {
    {
        .hrh_list_size = sizeof(canif_can_hoh_to_canif_hrh_map_canif_init_hoh_cfg) / sizeof(canif_can_hoh_to_canif_hrh_map_canif_init_hoh_cfg[0]),
        .can_hoh_to_canif_hrh_map = canif_can_hoh_to_canif_hrh_map_canif_init_hoh_cfg,
        .canif_hrh_config = canif_hrh_config_data_canif_init_hoh_cfg,
        .canif_hth_config = canif_hth_config_data_canif_init_hoh_cfg,
    },
};

CONST(canif_tx_buffer_config_type, CANIF_CONST) canif_buffer_cfg_data[CANIF_MAX_NOF_TX_BUFFERS] = {
/* 0 */ {&canif_hth_config_data_canif_init_hoh_cfg[0],          0,                    0}, /* CanHardwareObject_Tx, CORE0 */
};

CONST(canif_tx_pdu_config_type, CANIF_CONST) canif_tx_pdu_config_data[CANIF_MAX_NOF_TX_PDU] = {
      /* CanIfTxPduPnFilterEnable  CanIfCanTxPduIdDlc        CanIfUserTxConfirmation   CanIfTxPduIdCanIdType          CanIfCanTxPduType              CanIfTxPduId                                                                          CanIfTxPduBufferRef                                     CanIfCanTxPduIdCanId      CanIfTxmessageCalloutFctPtr                   */
/*  0*/ {(boolean)FALSE           ,(uint8)8                 ,(uint8)0                 ,CANIF_CAN_ID_TYPE_11          ,CANIF_PDU_TYPE_STATIC         ,(PduIdType)PDUR_PDU_ID_ECU_Status                                                    ,&canif_buffer_cfg_data[0]                              ,0x100                    ,NULL                                         }, /* CanHardwareObject_Tx, ECU_Status, CORE0 */
/*  1*/ {(boolean)FALSE           ,(uint8)2                 ,(uint8)0                 ,CANIF_CAN_ID_TYPE_11          ,CANIF_PDU_TYPE_STATIC         ,(PduIdType)PDUR_PDU_ID_Fault_Event                                                   ,&canif_buffer_cfg_data[0]                              ,0x300                    ,NULL                                         }, /* CanHardwareObject_Tx, Fault_Event, CORE0 */
};

CONSTP2CONST(canif_tx_buffer_config_type, AUTOMATIC, CANIF_CONST) canif_ctrl_cfg_buffer_list[CANIF_MAX_NOF_TX_BUFFERS] = {
/* 0 */   &canif_buffer_cfg_data[0], /* CanHardwareObject_Tx, CORE0 */
};

CONST(canif_controller_config_type, CANIF_CONST) canif_controller_config[CANIF_CONTROLLER_CHANNEL_CNT] = {
{   /* CORE0, CanController_0  */
   .canif_ctrl_can_ctrl_id = 0,
   .canif_ctrl_tx_buf_num = 1,     
   .canif_ctrl_tx_buf_ref_list = &canif_ctrl_cfg_buffer_list[0],  /* start from: CanHardwareObject_Tx */
   .canif_ctrl_pn_filter_set = (boolean)STD_ON,
},
};

CONST(uint8, CANIF_CONST) ctrl_driver_idx_map[CANIF_MAX_CONTROLLER_COUNT] = {
/*  0 */    [0]                = 0, /* CORE0, CanController_0 */
};

#if (CANIF_TRCV_WAKEUP_SUPPORT == STD_ON)
#endif 

CONST(canif_init_config_type, CANIF_CONST) canif_init_config = {
    .canif_all_tx_pdu_num = 2,
    .canif_all_tx_pdu_cfg_ptr = canif_tx_pdu_config_data,
    .canif_all_tx_buf_cfg_ptr = canif_buffer_cfg_data,
    .canif_all_hoh_cfg_ptr = canif_hoh_config_data,
};

CONST(canif_config_type, CANIF_CONST) canif_config = {
    .canif_init_config = &canif_init_config,
#if (CANIF_TRCV_WAKEUP_SUPPORT == STD_ON)
    .canif_trcv_config = NULL,
    .cantrcv_drv_api = NULL,
#endif
    .canif_ctrl_config = canif_controller_config
};

CONST(canif_user_rx_indication_fct_list_type, CANIF_CONST) canif_user_rx_indications[CANIF_ULMOUDLE_COUNT] = {
    { /*     0 */  { &pdur_canif_rx_indication }, CANIF_RX_INDICATION_TYPE_ADVANCED_TYPE   },
    { /*     1 */  { NULL }, CANIF_RX_INDICATION_TYPE_ADVANCED_TYPE   },
    { /*     2 */  { NULL }, CANIF_RX_INDICATION_TYPE_ADVANCED_TYPE   },
    { /*     3 */  { NULL }, CANIF_RX_INDICATION_TYPE_ADVANCED_TYPE   },
    { /*     4 */  { NULL }, CANIF_RX_INDICATION_TYPE_CDD_TYPE   },
    { /*     5 */  { NULL }, CANIF_RX_INDICATION_TYPE_ADVANCED_TYPE   },
    { /*     6 */  { NULL }, CANIF_RX_INDICATION_TYPE_ADVANCED_TYPE   },
    { /*     7 */  { NULL }, CANIF_RX_INDICATION_TYPE_ADVANCED_TYPE   },
};

CONST(canif_user_tx_confirmation_type, CANIF_CONST) canif_user_tx_confirmations[CANIF_ULMOUDLE_COUNT] = {
    &pdur_canif_tx_confirmation,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

CONST(canif_dispatch_config_type, CANIF_CONST) canif_dispatch_config =
{
    .bus_off_notification_fct = &cansm_controller_bus_off,
    .controller_mode_indication_fct = &cansm_controller_mode_indication,

#if (CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_SUPPORT == STD_ON)
    .wakeup_valid_notification_fct = NULL,
#endif
    .trcv_check_wake_flag_indication_fct = NULL,
    .trcv_clear_wake_flag_indication_fct = NULL,
    .trcv_confirm_pn_availability_fct = NULL,
    .trcv_mode_indication_fct = NULL,
};

#define CANIF_STOP_SEC_CONST
#include "canif_memmap.h"


/* ----------------------------CANIF数据面资源---------------------------*/
#if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
#define CANIF_START_SEC_CONST
#include "canif_memmap.h"

CONST(canif_tx_buffer_index_range_type, CANIF_CONST) canif_tx_buffer_index_range[CANIF_MAX_ACTIVATED_CORE_CNT] = {
     {   0u,    0u},  /* CORE0 */
};

CONST(canif_tx_buffer_index_range_type, CANIF_CONST) canif_tx_buffer_lpdu_index_range[CANIF_MAX_ACTIVATED_CORE_CNT] = {
     {CANIF_INVALID_TXBUFFER_START_INDEX,     CANIF_INVALID_TXBUFFER_END_INDEX},  /* CORE0 */
};

#define CANIF_STOP_SEC_CONST
#include "canif_memmap.h"


#if (CANIF_TX_BUF_FIFO_ENABLE == STD_ON)
#define CANIF_START_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS
#include "canif_memmap.h"

VAR(canif_fifo_buffer_info_type, CANIF_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS) fifo_buffer_info_core0[CANIF_MAX_NOF_TX_BUFFERS_CORE0];

#define CANIF_STOP_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS
#include "canif_memmap.h"
#endif

#define CANIF_START_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS
#include "canif_memmap.h"
VAR(uint16, CANIF_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS) buffer_start_index_core0[CANIF_MAX_NOF_TX_BUFFERS_CORE0];

#define CANIF_STOP_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS
#include "canif_memmap.h"

#define CANIF_START_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA
#include "canif_memmap.h"

P2VAR(uint16, CANIF_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA, CanIf_VAR_Class) buffer_start_index[CANIF_MAX_ACTIVATED_CORE_CNT] = {
     buffer_start_index_core0,
};

#if (CANIF_TX_BUF_FIFO_ENABLE == STD_ON)
P2VAR(canif_fifo_buffer_info_type, CANIF_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA, CanIf_VAR_Class) fifo_buffer_info[CANIF_MAX_ACTIVATED_CORE_CNT] = {
     fifo_buffer_info_core0,
};
#endif 

#define CANIF_STOP_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA
#include "canif_memmap.h"

#define CANIF_START_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS
#include "canif_memmap.h"

P2VAR(canif_buffer_entry_type, CANIF_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS, CanIf_VAR_Class) tx_pdu_buffer[CANIF_MAX_ACTIVATED_CORE_CNT];

#define CANIF_STOP_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS
#include "canif_memmap.h"

#endif 

/* ----------------------------CANIF管理面资源---------------------------*/
#define CANIF_START_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS
#include "canif_memmap.h"

VAR(canif_runtime_state_type, CANIF_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS) canif_runtime_state;

#define CANIF_STOP_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS
#include "canif_memmap.h"

#define CANIF_START_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS
#include "canif_memmap.h"

VAR(canif_init_status_type, CANIF_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS)   canif_init_status[CANIF_MAX_ACTIVATED_CORE_CNT];

#define CANIF_STOP_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS
#include "canif_memmap.h"

/* ----------------------------CANIF全局配置指针---------------------------*/
#define CANIF_START_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS
#include "canif_memmap.h"

P2CONST(canif_config_type, CANIF_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS, CanIf_VAR_Class) canif_config_ptr;

#define CANIF_STOP_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS
#include "canif_memmap.h"

/* ----------------------------CANIF维测变量---------------------------*/
/* 报文收发维测变量 */
#define CANIF_START_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS
#include "canif_memmap.h"

#if (CANIF_PUBLIC_DEBUG_SUPPORT == STD_ON)
VAR(uint32, CANIF_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS) tx_messagestatistic[CANIF_MAX_NOF_TX_PDU];

VAR(uint32, CANIF_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS) rx_messagestatistic[CANIF_MAX_NOF_RX_PDU];

VAR(uint32, CANIF_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS) tx_message_busy_count[CANIF_MAX_NOF_TX_PDU];

VAR(uint32, CANIF_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS) tx_message_drop_count[CANIF_MAX_NOF_TX_PDU];

VAR(uint32, CANIF_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS) tx_message_ok_count[CANIF_MAX_NOF_TX_PDU];
#endif

/* 通道通知状态 */
#if (CANIF_PUBLIC_TXCONFIRM_POLLING_SUPPORT == STD_ON)
VAR(canif_notif_status_type, CANIF_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS) canif_tx_conf_state[CANIF_CONTROLLER_CHANNEL_CNT];
#endif

#define CANIF_STOP_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS
#include "canif_memmap.h"

/* CanIfTxBuffer最大深度维测变量 */
#if (CANIF_PUBLIC_TXBUFFER_MAX_DEPTH_FETCH_SUPPORT == STD_ON)
#define CANIF_START_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS
#include "canif_memmap.h"

VAR(uint16, CANIF_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS) canif_tx_buffer_max_depth_core0[CANIF_MAX_NOF_TX_BUFFERS_CORE0];

#define CANIF_STOP_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS
#include "canif_memmap.h"

#define CANIF_START_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA
#include "canif_memmap.h"
P2VAR(uint16, CANIF_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA, CanIf_VAR_Class) canif_tx_buffer_max_depth[CANIF_MAX_ACTIVATED_CORE_CNT] = {
     canif_tx_buffer_max_depth_core0,
};
#define CANIF_STOP_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA
#include "canif_memmap.h"
#endif

