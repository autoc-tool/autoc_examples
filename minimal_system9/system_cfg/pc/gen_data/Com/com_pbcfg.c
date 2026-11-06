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
 * Generation Time : 2026-10-25 11:57:58
 * Project Name    : minimal_system9
 * Tool Version    : V0.1.0-DEV
 */

/* Including File */
#include "Platform_Types.h"
#include "pdur.h"
#include "com.h"
#include "com_pbcfg.h"
#include "com_lcfg.h"
#include "com_types.h"
#include "com_main.h"
#include "SchM_Com.h"

#define  COM_START_SEC_CONST
#include "com_memmap.h"
/**********************************************************************************************************************
  Com_Signal init values
**********************************************************************************************************************/
static CONST(uint8, COM_CONST) com_sig_init_value_uint8_default[64] = {0u};
                  
/* Signal init values from DBC */
#define  COM_STOP_SEC_CONST
#include "com_memmap.h"
/**********************************************************************************************************************
  Com_RxSignal Buff
**********************************************************************************************************************/
/**********************************************************************************************************************
  Com_ValueUInt8
**********************************************************************************************************************/
#define COM_START_SEC_PRIVATE_BSS
#include "com_memmap.h"
VAR(uint8, COM_PRIVATE_BSS) com_rx_sig_buf_u8[5];
#define COM_STOP_SEC_PRIVATE_BSS
#include "com_memmap.h"
/* Index                                                                         ComSignalName */
/*   0 *//*                                                         LedCmd_o_Cmd_Control_Rx */
/*   1 *//*                                                     TargetMode_o_Cmd_Control_Rx */
/*   2 *//*                                                   Cmd_AliveCnt_o_Cmd_Control_Rx */
/*   3 *//*                                                        PwmDuty_o_Cmd_Control_Rx */
/*   4 *//*                                                       Cmd_Crc8_o_Cmd_Control_Rx */

/*!*********************************************************************************************************************
 *  @brief  CAN单核部署 Tx IPDU Buff分配
 **********************************************************************************************************************/
#define COM_START_SEC_PRIVATE_BSS
#include "com_memmap.h"
VAR(com_status_type, COM_PRIVATE_BSS) com_init_status;
#define COM_STOP_SEC_PRIVATE_BSS
#include "com_memmap.h"

#define COM_START_SEC_PRIVATE_BSS
#include "com_memmap.h"
P2CONST(com_config_type, COM_PRIVATE_BSS, BSW_VAR_Class) com_config;
#define COM_STOP_SEC_PRIVATE_BSS
#include "com_memmap.h"

#define COM_START_SEC_PRIVATE_BSS
#include "com_memmap.h"
VAR(com_self_tx_ipdu_type, COM_PRIVATE_BSS) com_self_tx_ipdu[COM_MAX_N_TXIPDUS];
VAR(com_self_rx_ipdu_type, COM_PRIVATE_BSS) com_self_rx_ipdu[COM_MAX_N_RXIPDUS];
#define COM_STOP_SEC_PRIVATE_BSS
#include "com_memmap.h"

/*!*********************************************************************************************************************
 *  @brief  Tx Rx 数据面数据
 **********************************************************************************************************************/
#define COM_START_SEC_PRIVATE_BSS
#include "com_memmap.h"
VAR(uint8, COM_PRIVATE_BSS) com_self_tx_buffer[COM_MAX_TXBUFFER_SIZE];
VAR(uint8, COM_PRIVATE_BSS) com_self_rx_buffer[COM_MAX_RXBUFFER_SIZE];
#define COM_STOP_SEC_PRIVATE_BSS
#include "com_memmap.h"


/*!*********************************************************************************************************************
 *  @brief  Rx MainFunction Com_RxNotificationRecord Buffer
 **********************************************************************************************************************/

/*!*********************************************************************************************************************
 *  @brief  Rx MainFunction Com_RxNotificationRecord instance
 **********************************************************************************************************************/
#define COM_START_SEC_PRIVATE_BSS
#include "com_memmap.h"
VAR(uint16, COM_PRIVATE_BSS) RxNotificationRecordRef_Core0_Mf0[5];
#define COM_STOP_SEC_PRIVATE_BSS
#include "com_memmap.h" 


#define  COM_START_SEC_CONST
#include "com_memmap.h"
/**********************************************************************************************************************
  Signal Invalid values from DBC 
**********************************************************************************************************************/


/**********************************************************************************************************************
  Group Signal Refs
**********************************************************************************************************************/


/**********************************************************************************************************************
  Signal Group Shadow Buffer masks
**********************************************************************************************************************/

/*
 * Tx Signal definitions
 */
CONST(com_tx_signal_type, COM_CONST) com_tx_signal_const[8] = {
      /* Index                                                                    ComSignalName       com_self_eol ComSigInitValueIsZero ComSignalEndianess    ComSignalType                         ComTransferProperty   ComBitPosition ComEndBitPosition ComBitSize                                                                  ComIPduHandleId                                                                              ComSignalInitValue */
    {/*   0 *//*                                                       ECU_State_o_ECU_Status_Tx */            0u,        (boolean)TRUE, COM_LITTLE_ENDIAN,       COM_UINT8,                                COM_PENDING,               0u,               0u,        4u,                                                           COM_PDU_ID_ECU_Status,                                                               com_sig_init_value_uint8_default},
    {/*   1 *//*                                                    ECU_AliveCnt_o_ECU_Status_Tx */            0u,        (boolean)TRUE, COM_LITTLE_ENDIAN,       COM_UINT8,                                COM_PENDING,               4u,               0u,        4u,                                                           COM_PDU_ID_ECU_Status,                                                               com_sig_init_value_uint8_default},
    {/*   2 *//*                                                     Temperature_o_ECU_Status_Tx */            0u,        (boolean)TRUE, COM_LITTLE_ENDIAN,       COM_UINT8,                                COM_PENDING,               8u,               0u,        8u,                                                           COM_PDU_ID_ECU_Status,                                                               com_sig_init_value_uint8_default},
    {/*   3 *//*                                                   SupplyVoltage_o_ECU_Status_Tx */            0u,        (boolean)TRUE, COM_LITTLE_ENDIAN,      COM_UINT16,                                COM_PENDING,              16u,               0u,       16u,                                                           COM_PDU_ID_ECU_Status,                                                               com_sig_init_value_uint8_default},
    {/*   4 *//*                                                      FaultFlags_o_ECU_Status_Tx */            0u,        (boolean)TRUE, COM_LITTLE_ENDIAN,       COM_UINT8,                                COM_PENDING,              32u,               0u,        8u,                                                           COM_PDU_ID_ECU_Status,                                                               com_sig_init_value_uint8_default},
    {/*   5 *//*                                                      FaultCode_o_Fault_Event_Tx */            0u,        (boolean)TRUE, COM_LITTLE_ENDIAN,       COM_UINT8, COM_TRIGGERED_ON_CHANGE_WITHOUT_REPETITION,               0u,               0u,        8u,                                                          COM_PDU_ID_Fault_Event,                                                               com_sig_init_value_uint8_default},
    {/*   6 *//*                                                    FaultActive_o_Fault_Event_Tx */            0u,        (boolean)TRUE, COM_LITTLE_ENDIAN,     COM_BOOLEAN,                                COM_PENDING,               8u,               0u,        1u,                                                          COM_PDU_ID_Fault_Event,                                                               com_sig_init_value_uint8_default},

    /* Add ComSignal before this. */
    {.com_self_eol = 1u }
};

/*
 * Rx Signal definitions
 */
CONST(com_rx_signal_type, COM_CONST) com_rx_signal_const[6] = {
      /* Index                                                                    ComSignalName       com_self_eol ComSigInitValueIsZero ComSignalEndianess    ComSignalType   ComBitPosition ComEndBitPosition ComBitSize                                                                  ComIPduHandleId            BufferIdx                                                                                 ComNotification                                                                              ComSignalInitValue */
    {/*   0 *//*                                                         LedCmd_o_Cmd_Control_Rx */            0u,        (boolean)TRUE, COM_LITTLE_ENDIAN,     COM_BOOLEAN,               0u,               0u,        1u,                                                          COM_PDU_ID_Cmd_Control,                   0u,                                                                        COM_NO_FUNCTION_CALLOUT,                                                               com_sig_init_value_uint8_default},
    {/*   1 *//*                                                     TargetMode_o_Cmd_Control_Rx */            0u,        (boolean)TRUE, COM_LITTLE_ENDIAN,       COM_UINT8,               1u,               0u,        3u,                                                          COM_PDU_ID_Cmd_Control,                   1u,                                                                        COM_NO_FUNCTION_CALLOUT,                                                               com_sig_init_value_uint8_default},
    {/*   2 *//*                                                   Cmd_AliveCnt_o_Cmd_Control_Rx */            0u,        (boolean)TRUE, COM_LITTLE_ENDIAN,       COM_UINT8,               4u,               0u,        4u,                                                          COM_PDU_ID_Cmd_Control,                   2u,                                                                        COM_NO_FUNCTION_CALLOUT,                                                               com_sig_init_value_uint8_default},
    {/*   3 *//*                                                        PwmDuty_o_Cmd_Control_Rx */            0u,        (boolean)TRUE, COM_LITTLE_ENDIAN,       COM_UINT8,               8u,               0u,        8u,                                                          COM_PDU_ID_Cmd_Control,                   3u,                                                                        COM_NO_FUNCTION_CALLOUT,                                                               com_sig_init_value_uint8_default},
    {/*   4 *//*                                                       Cmd_Crc8_o_Cmd_Control_Rx */            0u,        (boolean)TRUE, COM_LITTLE_ENDIAN,       COM_UINT8,              56u,               0u,        8u,                                                          COM_PDU_ID_Cmd_Control,                   4u,                                                                        COM_NO_FUNCTION_CALLOUT,                                                               com_sig_init_value_uint8_default},

    /* Add ComSignal before this. */
    {.com_self_eol = 1u }
};

/*
 * Gateway Destination signal references
 */


/*
 * Gateway mappings
 */
static CONST(com_gw_mapping_type, COM_CONST) com_gw_mapping[1] = {
    /* Index    com_self_eol ComGwNoOfDesitnationRoutes                                                                                                  ComGwSourceSignalHandle                ComGwSourceSignalRef                                                                                                      ComGwDestinationRef */
    {.com_self_eol = 1u }
};

/*
 * I-PDU group definitions
 */
static CONST(com_ipg_type, COM_CONST) com_ipg[3] = {
    /* Index     com_self_eol                            com_ipg_handle_id */
    {/*    0 */           0u,                              ComConf_ComIPduGroup_ComTxGroup },
    {/*    1 */           0u,                              ComConf_ComIPduGroup_ComRxGroup },

    /* Add com_ipg before this. */
    {.com_self_eol = 1u }
};


/*
 * IPdu Counter list
 */

/*
 * I-PDU group ref lists
 */


static CONST(com_ipg_type, COM_CONST) ComIpduGroupRefs_ECU_Status[2] = {
    {.com_ipg_handle_id = ComConf_ComIPduGroup_ComTxGroup, .com_self_eol = 0u },
    {.com_self_eol = 1u }
};
static CONST(com_ipg_type, COM_CONST) ComIpduGroupRefs_Fault_Event[2] = {
    {.com_ipg_handle_id = ComConf_ComIPduGroup_ComTxGroup, .com_self_eol = 0u },
    {.com_self_eol = 1u }
};
static CONST(com_ipg_type, COM_CONST) ComIpduGroupRefs_Cmd_Control[2] = {
    {.com_ipg_handle_id = ComConf_ComIPduGroup_ComRxGroup, .com_self_eol = 0u },
    {.com_self_eol = 1u }
};

/*
 * ComTxModeTrue definitions
 */
static CONST(com_tx_mode_type, COM_CONST) comtxmode_true_cfg[2] = {
    /* Index                                                                   ComTxModeNumberOfRepetitions         ComTxModeMode         ComTxModeRepetitionPeriodFactor    ComTxModeTimeOffsetFactor    ComTxModeTimePeriodFactor */
    {/*    0 ECU_Status                                                  */                   0u,                  COM_PERIODIC,                              0u,                        0u,                        20u },
    {/*    1 Fault_Event                                                 */                   0u,                    COM_DIRECT,                              0u,                        0u,                         0u },
};

/*
 * ComTxModeFalse definitions
 */
static CONST(com_tx_mode_type, COM_CONST) comtxmode_false_cfg[2] = {
     /* Index                                                                   ComTxModeNumberOfRepetitions         ComTxModeMode         ComTxModeRepetitionPeriodFactor    ComTxModeTimeOffsetFactor    ComTxModeTimePeriodFactor */
    {/*    0 ECU_Status                                                  */                   0u,                  COM_PERIODIC,                              0u,                        0u,                        20u },
    {/*    1 Fault_Event                                                 */                   0u,                      COM_NONE,                              0u,                        0u,                         0u },
};

/*
 * ComTxIPdu definitions
 */
static CONST(com_ipdu_tx_type, COM_CONST) com_tx_ipdu_cfg[2] = {
    /* Index                                                                             EnableRetryFailedTransmitRequests ComTxIPduUnusedAreasDefault ComTxIPduMinimumDelayFactor                                      ComTxModeTrue                           ComTxModeFalse */
    {/*    0 ECU_Status                                                       */                        (boolean)FALSE,                          0u,                          0u,                             &comtxmode_true_cfg[0],                  &comtxmode_false_cfg[0]},
    {/*    1 Fault_Event                                                      */                        (boolean)FALSE,                          0u,                          0u,                             &comtxmode_true_cfg[1],                  &comtxmode_false_cfg[1]},
}; 

/*
 * Tx I-PDU definitions
 */
CONST(com_tx_ipdu_type, COM_CONST) com_tx_ipdu_const[3] = {
    /* Index                                                                              com_self_eol ComIPduSignalProcessing                                                     SelfIPduOutgoingId ComIPduSize Signal_StartIdx Signal_EndIdx                                                                           ComTxIPduCallout                                                              ComTriggerTransmitIPduCallout                                                               ComIPduGroupRefs           ComTxIPdu */
    {/*    0 ECU_Status                                                                 */           0u,           COM_DEFERRED,                                                PDUR_PDU_ID_ECU_Status,         8u,         0u,         5u,                                                                   COM_NO_FUNCTION_CALLOUT,                                                                   COM_NO_FUNCTION_CALLOUT,                                                   ComIpduGroupRefs_ECU_Status, &com_tx_ipdu_cfg[0]},
    {/*    1 Fault_Event                                                                */           0u,           COM_DEFERRED,                                               PDUR_PDU_ID_Fault_Event,         2u,         5u,         7u,                                                                   COM_NO_FUNCTION_CALLOUT,                                                                   COM_NO_FUNCTION_CALLOUT,                                                  ComIpduGroupRefs_Fault_Event, &com_tx_ipdu_cfg[1]},

    /* Add ComIPdu before this. */
    {.com_self_eol = 1u }
};

/**********************************************************************************************************************
  Rx I-PDU definitions
**********************************************************************************************************************/
CONST(com_rx_ipdu_type, COM_CONST) com_rx_ipdu_const[2] = {
    /* Index                                                                              com_self_eol ComIPduHasSignalGroup ComIPduSignalProcessing                                                     SelfIPduOutgoingId ComIPduSize Signal_StartIdx Signal_EndIdx                                                                           ComRxIPduCallout                                                               ComIPduGroupRefs */
    {/*    0 Cmd_Control                                                                */           0u,    (boolean)FALSE,           COM_DEFERRED,                                               PDUR_PDU_ID_Cmd_Control,         8u,         0u,         5u,                                                                   COM_NO_FUNCTION_CALLOUT,                                                  ComIpduGroupRefs_Cmd_Control},

    /* Add ComIPdu before this. */
    {.com_self_eol = 1 }
};
CONST(com_rx_tout_message_info_type, COM_CONST) com_rx_pdu_tout_struct[1] =  
{
    {/*   0 */    NO_PDU_REFERENCE,   NO_PDU_REFERENCE,   NO_PDU_REFERENCE, NO_PDU_REFERENCE} 
};
CONST(com_tx_tout_message_info_type, COM_CONST) com_tx_pdu_tout_struct[1] =  
{
    {/*   0 */    NO_PDU_REFERENCE,   NO_PDU_REFERENCE,   NO_PDU_REFERENCE, NO_PDU_REFERENCE} 
}; 

CONST(com_config_type, COM_CONST) com_configuration = {
    .com_ipg = com_ipg,
    .com_gw_mapping_ref = com_gw_mapping,
};

/**********************************************************************************************************************
  com_tx_main_function_des
**********************************************************************************************************************/
CONST(com_main_function_tx_struct_type, COM_CONST) com_tx_main_function_des[1] = {
    /* Index     TxComfirmationInfo StartIPduIdxOfMainFunctionTx IPduNumOfMainFunctionTx */
    {/*   0 */      (boolean)FALSE,                   0u,                   2u}
};

/**********************************************************************************************************************
  com_rx_main_function_des
**********************************************************************************************************************/
CONST(com_main_function_rx_struct_type, COM_CONST) com_rx_main_function_des[1] = {
    /* Index          RxTimeoutInfo StartIPduIdxOfMainFunctionRx IPduNumOfMainFunctionRx           RxToutmessagStartIdx      RxToutmessagNum        IpduMaxSigNum                       RxNotificationRecordRef */
    {/*   0 */      (boolean)FALSE,                   0u,                   1u,              NO_PDU_REFERENCE,                   0u,                   5u,            RxNotificationRecordRef_Core0_Mf0}
}; 
#define  COM_STOP_SEC_CONST
#include "com_memmap.h"

#define  COM_START_SEC_CODE
#include "com_memmap.h"
/**********************************************************************************************************************
  Com TX MainFunction definitions
**********************************************************************************************************************/

/*Com_MainFunction_Tx */
FUNC(void, COM_CODE) Com_MainFunction_Tx(void)
{
    uint8 id = 0;
    com_main_function_tx_run(id);
}



/**********************************************************************************************************************
  Com RX MainFunction definitions
**********************************************************************************************************************/

/*Com_MainFunction_Rx */
FUNC(void, COM_CODE) Com_MainFunction_Rx(void)
{
    uint8 id = 0;
    com_main_function_rx_run(id);
}



/**********************************************************************************************************************
  Com GW MainFunction definitions
**********************************************************************************************************************/

/*Com_MainFunction_Gw */
FUNC(void, COM_CODE) Com_MainFunction_Gw(void)
{
    uint8 id = 0;
    com_main_function_gw_run(id);
}

#define  COM_STOP_SEC_CODE
#include "com_memmap.h"