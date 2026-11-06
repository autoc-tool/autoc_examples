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
/**********************************************************************************************************************
 * @file        com_cfg.h
 * @brief       Com配置头文件
 * @details     主要包含Com模块的配置相关信息
 * @date        2026-10-24 23:59:09
 * @toolversion V0.1.0-DEV
 **********************************************************************************************************************/

#ifndef COM_CFG_H
#define COM_CFG_H

#ifdef __cplusplus
extern "C"  
{
#endif

#define COM_DEV_ERROR_DETECT                         (STD_OFF)
#define COM_SIG_GATEWAY_ENABLE                       (STD_OFF)
#define COM_DEBUG_SUPPORT                            (STD_OFF)
#define COM_TXTOU_ENABLE                               (STD_OFF)
#define COM_RXTOU_ENABLE                               (STD_ON)
#define COM_TXNOTIFICATION                           (STD_OFF)
#define COM_SIGNAL_GROUP_ENABLE                      (STD_OFF)
#define COM_SIGNAL_UPDATEBIT_ENABLE                  (STD_OFF)
#define COM_IPDU_ALL_DEFERRED                        (STD_ON)
#define COM_RXIPDU_ALL_IMMEDIATE                     (STD_OFF)

#define COM_IPDU_RETRYFAILEDTRANS_ENABLE             (STD_OFF)

#define COM_TIMEOUT_DATA_ACTION_REPLACE_ENABLE       (STD_OFF)

#define COM_SIGNAL_DATAINVALIDVALUE_ENABLE           (STD_OFF)


#define COM_RXIPDU_SAME_TIMEOUT_ENABLE               (STD_ON)

#define COM_TXIPDU_SAME_TIMEOUT_ENABLE               (STD_ON)

#define COM_ERROR_NOTIFICATION_ENABLE                (STD_OFF)

#define COM_SIGNAL_ONCHANGE_ENABLE                   (STD_OFF)

#define COM_MAINFUNCTION_RX_NUM                      (1u)

#define COM_MAINFUNCTION_TX_NUM                      (1u)

#define COM_SUPPORTED_TXSIGNALPROX                   (STD_OFF)

#define COM_FIFO_DEQUEUECNT_CNT_MAX                  (0)

#define COM_UINT8_FIFONUMBER                         (0u)

#define COM_UINT16_FIFONUMBER                        (0u)

#define COM_UINT32_FIFONUMBER                        (0u)

#define COM_UINT8_NFIFONUMBER                        (0u)

#define COM_UINT8_NFIFO_ELEMENTSIZE                  (0u)


#define COM_UINT8_FIFOENABLE                         (STD_OFF)

#define COM_UINT16_FIFOENABLE                        (STD_OFF)

#define COM_UINT32_FIFOENABLE                        (STD_OFF)

#define COM_UINT8_NFIFOENABLE                        (STD_OFF)

#define COM_RUN_COREID                               (0u)

#define COM_MAX_COREID                               (0u)

#define COM_SUPPORT_MUTICORE                         (STD_OFF)

#define COM_CORE_NUM                                 (1)
#define COM_MAX_BUFFER_SIZE                          (18u)
#define COM_MAX_TXBUFFER_SIZE                        (10u)
#define COM_MAX_RXBUFFER_SIZE                        (8u)

#define COM_MAX_N_IPDUS                              (3u)
#define COM_MAX_N_TXIPDUS                            (2u)
#define COM_MAX_N_RXIPDUS                            (1u)

#define COM_MAX_N_SIGNALS                            (12u)
#define COM_MAX_N_TXSIGNALS                          (7u)
#define COM_MAX_N_RXSIGNALS                          (5u)

#define RXIPDU_MAXSIG_NUM                            (5u)
#define COM_HAVE_UINT8_TYPE                        (STD_ON)
#define COM_HAVE_UINT16_TYPE                       (STD_OFF)
#define COM_HAVE_UINT32_TYPE                       (STD_OFF)
#define COM_HAVE_UINT64_TYPE                       (STD_OFF)
#define COM_HAVE_UINT8_N_TYPE                      (STD_OFF)

#define COM_MAX_N_RXTOUTSIGNALS                      (5u)
#define COM_MAX_N_TXNOTIFICATION                     (0u)

#define COM_MAX_N_RXTOUTMESSAGES                     (1u)

#define COM_MAX_N_GWMAPPINGS                         (0u)


/**********************************************************************************************************************
  Rx Signal Notifications Idx
**********************************************************************************************************************/


/**********************************************************************************************************************
  Rx Signal Timeout Notifications Idx
**********************************************************************************************************************/

/**********************************************************************************************************************
  Rx InvalidNotification
**********************************************************************************************************************/

/**********************************************************************************************************************
  Rx Error Notification
**********************************************************************************************************************/


/**********************************************************************************************************************
  Tx Signal Notifications Idx
**********************************************************************************************************************/



/**********************************************************************************************************************
  Tx Signal Timeout Notifications Idx
**********************************************************************************************************************/


/**********************************************************************************************************************
  Tx InvalidNotification
**********************************************************************************************************************/

/**********************************************************************************************************************
  Tx Error Notification
**********************************************************************************************************************/


// TX COM SIGNAL IDs


// Tx GROUPS and SIGNAL
#define ComConf_ComSignal_ECU_State_o_ECU_Status_Tx                                                                       (0U)
#define ComConf_ComSignal_ECU_AliveCnt_o_ECU_Status_Tx                                                                    (1U)
#define ComConf_ComSignal_Temperature_o_ECU_Status_Tx                                                                     (2U)
#define ComConf_ComSignal_SupplyVoltage_o_ECU_Status_Tx                                                                   (3U)
#define ComConf_ComSignal_FaultFlags_o_ECU_Status_Tx                                                                      (4U)
#define ComConf_ComSignal_FaultCode_o_Fault_Event_Tx                                                                      (5U)
#define ComConf_ComSignal_FaultActive_o_Fault_Event_Tx                                                                    (6U)

// RX COM SIGNAL IDs


// Rx GROUPS and SIGNAL
#define ComConf_ComSignal_LedCmd_o_Cmd_Control_Rx                                                                         (0U)
#define ComConf_ComSignal_TargetMode_o_Cmd_Control_Rx                                                                     (1U)
#define ComConf_ComSignal_Cmd_AliveCnt_o_Cmd_Control_Rx                                                                   (2U)
#define ComConf_ComSignal_PwmDuty_o_Cmd_Control_Rx                                                                        (3U)
#define ComConf_ComSignal_Cmd_Crc8_o_Cmd_Control_Rx                                                                       (4U)

// Rx callouts

// Tx callouts

// Trigger transmit callouts

#ifdef __cplusplus
}
#endif

#endif /* COM_CFG_H */