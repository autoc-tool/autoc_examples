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
 * @file        Rte_SystemApplication_Core0.c
 * @brief       RTE implementation file
 * @details     Encapsulates the setup and management of tasks, events, and inter-component communication
 *              for an OS application
 * @date        2026-10-25 11:50:41
 * @toolversion V0.1.0-DEV
 **********************************************************************************************************************/

/*
 * DESCRIPTION
 * This source file is the implementation of Tasks behaviors and
 * some Rte interfaces.
 *
 * When tasks are activated, Basic task will excute its code directly,
 * while extended task will wait some events. Extended task will excute
 * codes corresponding to the specific event when getting the event.
 */
#define RTE_CORE
#include "SchM_Com.h"
#include "SchM_ComM.h"
#include "SchM_CanSM.h"
#include "Os.h"
#include "Rte.h"
#include "Rte_Cbk.h"
#include "Rte_Main.h"
#include "task_cfg.h"
#include "event_cfg.h"
#include "spinlock_cfg.h"
#include "schedtable_cfg.h"
#include "Rte_IoHwAb.h"
#include "Rte_MinimalSystem.h"

#include "Rte_SystemApplication_Core0.h"
#include "Rte_Dlog.h"
#include "Rte_Hook.h"
#include "com.h"
/*
 * API to control global interrupt enable/disable
 */
#define Rte_DisableAllInterrupts() DisableAllInterrupts()
#define Rte_EnableAllInterrupts()  EnableAllInterrupts()
#define Rte_DisableOSInterrupts()  SuspendOSInterrupts()
#define Rte_EnableOSInterrupts()   ResumeOSInterrupts()

#define Rte_DisableAllInterruptsOS() DisableAllInterrupts()
#define Rte_EnableAllInterruptsOS()  EnableAllInterrupts()
#define Rte_DisableOSInterruptsOS()  SuspendOSInterrupts()
#define Rte_EnableOSInterruptsOS()   ResumeOSInterrupts()

#define RTE_TASK_TIMEOUT_EVENT_MASK   (1u)
#define RTE_TASK_WAITPOINT_EVENT_MASK (1u << 1)

#define RTE_MSEC_TO_TICKS(time_ms) ((uint32) ((((float32) time_ms) / (((float32) 0.001) * 1000.0F)) + 0.5F))
#define RTE_START_SCH_TBL_OFFSET (1U)
/*
 * compu-method of text table/bit field text table
 */
#  ifndef FALSE
#   define FALSE (0U)
#  endif
#  ifndef TRUE
#   define TRUE (1U)
#  endif

/*
 * Buffer extern for intra-osa S/R Non-Queue
*/
#define RTE_START_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA
#include "rte_memmap.h"
#define RTE_STOP_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA
#include "rte_memmap.h"
#define RTE_START_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS
#include "rte_memmap.h"
extern VAR(Rte_Private_SystemApplication_Core0_ZeroBool_VarType, RTE_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS) Rte_Private_SystemApplication_Core0_ZeroBool_Vars;
extern VAR(uint8, RTE_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS) Rte_MinimalSystem_IoOut_P_PwmDuty;
#define RTE_STOP_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS
#include "rte_memmap.h"

#define RTE_START_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA
#include "rte_memmap.h"
extern VAR(Rte_ts_OsTask_10ms, RTE_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA) Rte_OsTask_10ms;
#define RTE_STOP_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA
#include "rte_memmap.h"


/*
 * Buffers for intra-osa S/R Non-Queue
 */

#define RTE_START_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA
#include "rte_memmap.h"
#define RTE_STOP_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA
#include "rte_memmap.h"

#define RTE_START_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS
#include "rte_memmap.h"
VAR(Rte_Private_SystemApplication_Core0_ZeroBool_VarType, RTE_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS) Rte_Private_SystemApplication_Core0_ZeroBool_Vars;
VAR(uint8, RTE_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS) Rte_MinimalSystem_IoOut_P_PwmDuty;
#define RTE_STOP_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_BSS
#include "rte_memmap.h"




#define RTE_START_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA
#include "rte_memmap.h"
WARNING_542_DISABLE
VAR(Rte_ts_OsTask_10ms, RTE_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA) Rte_OsTask_10ms;
WARNING_542_RESTORE
#define RTE_STOP_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA
#include "rte_memmap.h"



#define RTE_START_SEC_CODE
#include "rte_memmap.h"
FUNC(void,RTE_CODE) os_task_ostask_5ms(void *arg)
{
    (void)arg;
#if (RTE_DLOG_ENABLED == STD_ON)
    Std_ReturnType ret;
#endif
    CanSM_MainFunction();
    Com_MainFunction_Rx();
    Com_MainFunction_Tx();
    Com_MainFunction_Gw();
    ComM_MainFunction_CAN1();

#if (RTE_DLOG_ENABLED == STD_ON)
    ret = TerminateTask();
    if (ret != E_OK)
    {
        Rte_LogOs(RTE_TASK_SERVICE_ID, OS_TASK_OsTask_5ms_ID, OSServiceId_TerminateTask, OS_TASK_OsTask_5ms_ID, ret);
    }
#else
    (void) TerminateTask();
#endif
}

FUNC(void,RTE_CODE) os_task_ostask_10ms(void *arg)
{
    (void)arg;
#if (RTE_DLOG_ENABLED == STD_ON)
    Std_ReturnType ret;
#endif
    /* read implicit data */
    
    ret |= com_receive_signal(ComConf_ComSignal_Cmd_AliveCnt_o_Cmd_Control_Rx, &Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_CmdControl_R_Cmd_AliveCnt);
#if (RTE_DLOG_ENABLED == STD_ON)
    if (ret != E_OK)
    {
        Rte_LogCom(RTE_TASK_SERVICE_ID, OS_TASK_OsTask_10ms_ID, RTE_COM_RECEIVESIGNAL_ID, ComConf_ComSignal_Cmd_AliveCnt_o_Cmd_Control_Rx, ret);
    }
#endif
    
    ret |= com_receive_signal(ComConf_ComSignal_Cmd_Crc8_o_Cmd_Control_Rx, &Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_CmdControl_R_Cmd_Crc8);
#if (RTE_DLOG_ENABLED == STD_ON)
    if (ret != E_OK)
    {
        Rte_LogCom(RTE_TASK_SERVICE_ID, OS_TASK_OsTask_10ms_ID, RTE_COM_RECEIVESIGNAL_ID, ComConf_ComSignal_Cmd_Crc8_o_Cmd_Control_Rx, ret);
    }
#endif
    
    ret |= com_receive_signal(ComConf_ComSignal_LedCmd_o_Cmd_Control_Rx, &Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_CmdControl_R_LedCmd);
#if (RTE_DLOG_ENABLED == STD_ON)
    if (ret != E_OK)
    {
        Rte_LogCom(RTE_TASK_SERVICE_ID, OS_TASK_OsTask_10ms_ID, RTE_COM_RECEIVESIGNAL_ID, ComConf_ComSignal_LedCmd_o_Cmd_Control_Rx, ret);
    }
#endif
    
    ret |= com_receive_signal(ComConf_ComSignal_PwmDuty_o_Cmd_Control_Rx, &Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_CmdControl_R_PwmDuty);
#if (RTE_DLOG_ENABLED == STD_ON)
    if (ret != E_OK)
    {
        Rte_LogCom(RTE_TASK_SERVICE_ID, OS_TASK_OsTask_10ms_ID, RTE_COM_RECEIVESIGNAL_ID, ComConf_ComSignal_PwmDuty_o_Cmd_Control_Rx, ret);
    }
#endif
    
    ret |= com_receive_signal(ComConf_ComSignal_TargetMode_o_Cmd_Control_Rx, &Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_CmdControl_R_TargetMode);
#if (RTE_DLOG_ENABLED == STD_ON)
    if (ret != E_OK)
    {
        Rte_LogCom(RTE_TASK_SERVICE_ID, OS_TASK_OsTask_10ms_ID, RTE_COM_RECEIVESIGNAL_ID, ComConf_ComSignal_TargetMode_o_Cmd_Control_Rx, ret);
    }
#endif
    MinimalSystem_10ms();
    
#if (RTE_DLOG_ENABLED == STD_ON)
    ret = com_send_signal(ComConf_ComSignal_ECU_AliveCnt_o_ECU_Status_Tx, &Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_EcuStatus_P_ECU_AliveCnt);
    if (ret != E_OK)
    {
        Rte_LogCom(RTE_TASK_SERVICE_ID, OS_TASK_OSTASK_10MS_ID, RTE_COM_SENDSIGNAL_ID, ComConf_ComSignal_ECU_AliveCnt_o_ECU_Status_Tx, ret);
    }
#else
    ret = com_send_signal(ComConf_ComSignal_ECU_AliveCnt_o_ECU_Status_Tx, &Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_EcuStatus_P_ECU_AliveCnt);
#endif
    
#if (RTE_DLOG_ENABLED == STD_ON)
    ret = com_send_signal(ComConf_ComSignal_ECU_State_o_ECU_Status_Tx, &Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_EcuStatus_P_ECU_State);
    if (ret != E_OK)
    {
        Rte_LogCom(RTE_TASK_SERVICE_ID, OS_TASK_OSTASK_10MS_ID, RTE_COM_SENDSIGNAL_ID, ComConf_ComSignal_ECU_State_o_ECU_Status_Tx, ret);
    }
#else
    ret = com_send_signal(ComConf_ComSignal_ECU_State_o_ECU_Status_Tx, &Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_EcuStatus_P_ECU_State);
#endif
    
#if (RTE_DLOG_ENABLED == STD_ON)
    ret = com_send_signal(ComConf_ComSignal_FaultFlags_o_ECU_Status_Tx, &Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_EcuStatus_P_FaultFlags);
    if (ret != E_OK)
    {
        Rte_LogCom(RTE_TASK_SERVICE_ID, OS_TASK_OSTASK_10MS_ID, RTE_COM_SENDSIGNAL_ID, ComConf_ComSignal_FaultFlags_o_ECU_Status_Tx, ret);
    }
#else
    ret = com_send_signal(ComConf_ComSignal_FaultFlags_o_ECU_Status_Tx, &Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_EcuStatus_P_FaultFlags);
#endif
    
#if (RTE_DLOG_ENABLED == STD_ON)
    ret = com_send_signal(ComConf_ComSignal_SupplyVoltage_o_ECU_Status_Tx, &Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_EcuStatus_P_SupplyVoltage);
    if (ret != E_OK)
    {
        Rte_LogCom(RTE_TASK_SERVICE_ID, OS_TASK_OSTASK_10MS_ID, RTE_COM_SENDSIGNAL_ID, ComConf_ComSignal_SupplyVoltage_o_ECU_Status_Tx, ret);
    }
#else
    ret = com_send_signal(ComConf_ComSignal_SupplyVoltage_o_ECU_Status_Tx, &Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_EcuStatus_P_SupplyVoltage);
#endif
    
#if (RTE_DLOG_ENABLED == STD_ON)
    ret = com_send_signal(ComConf_ComSignal_Temperature_o_ECU_Status_Tx, &Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_EcuStatus_P_Temperature);
    if (ret != E_OK)
    {
        Rte_LogCom(RTE_TASK_SERVICE_ID, OS_TASK_OSTASK_10MS_ID, RTE_COM_SENDSIGNAL_ID, ComConf_ComSignal_Temperature_o_ECU_Status_Tx, ret);
    }
#else
    ret = com_send_signal(ComConf_ComSignal_Temperature_o_ECU_Status_Tx, &Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_EcuStatus_P_Temperature);
#endif
    
#if (RTE_DLOG_ENABLED == STD_ON)
    ret = com_send_signal(ComConf_ComSignal_FaultActive_o_Fault_Event_Tx, &Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_FaultEvent_P_FaultActive);
    if (ret != E_OK)
    {
        Rte_LogCom(RTE_TASK_SERVICE_ID, OS_TASK_OSTASK_10MS_ID, RTE_COM_SENDSIGNAL_ID, ComConf_ComSignal_FaultActive_o_Fault_Event_Tx, ret);
    }
#else
    ret = com_send_signal(ComConf_ComSignal_FaultActive_o_Fault_Event_Tx, &Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_FaultEvent_P_FaultActive);
#endif
    
#if (RTE_DLOG_ENABLED == STD_ON)
    ret = com_send_signal(ComConf_ComSignal_FaultCode_o_Fault_Event_Tx, &Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_FaultEvent_P_FaultCode);
    if (ret != E_OK)
    {
        Rte_LogCom(RTE_TASK_SERVICE_ID, OS_TASK_OSTASK_10MS_ID, RTE_COM_SENDSIGNAL_ID, ComConf_ComSignal_FaultCode_o_Fault_Event_Tx, ret);
    }
#else
    ret = com_send_signal(ComConf_ComSignal_FaultCode_o_Fault_Event_Tx, &Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_FaultEvent_P_FaultCode);
#endif
    IoHwAb_10ms();

#if (RTE_DLOG_ENABLED == STD_ON)
    ret = TerminateTask();
    if (ret != E_OK)
    {
        Rte_LogOs(RTE_TASK_SERVICE_ID, OS_TASK_OsTask_10ms_ID, OSServiceId_TerminateTask, OS_TASK_OsTask_10ms_ID, ret);
    }
#else
    (void) TerminateTask();
#endif
}


/*
 * Extended Life-Cycle API implementation
 */
FUNC(void,RTE_CODE) Rte_InitMemory_SystemApplication_Core0(void)
{
}


/*
 * Internal/External Tx connections
 */



/*
 * Internal/External Rx connections
 */




/*
 * RTE Schedulable entity for COM-Access from different partitions
 */

#define RTE_STOP_SEC_CODE
#include "rte_memmap.h"
