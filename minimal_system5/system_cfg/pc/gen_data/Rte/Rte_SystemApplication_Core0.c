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
 * @date        2026-10-24 23:59:29
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
#include "SchM_BswM.h"
#include "SchM_ComM.h"
#include "SchM_EcuM.h"
#include "SchM_CanSM.h"
#include "Os.h"
#include "Rte.h"
#include "Rte_Cbk.h"
#include "Rte_Main.h"
#include "task_cfg.h"
#include "event_cfg.h"
#include "spinlock_cfg.h"
#include "schedtable_cfg.h"
#include "Rte_MinimalSystemApp.h"

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

#define RTE_START_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA
#include "rte_memmap.h"
extern VAR(Rte_ts_OsTask_10ms, RTE_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA) Rte_OsTask_10ms;
extern VAR(Rte_ts_OsTask_100ms, RTE_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA) Rte_OsTask_100ms;
#define RTE_STOP_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA
#include "rte_memmap.h"






#define RTE_START_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA
#include "rte_memmap.h"
WARNING_542_DISABLE
VAR(Rte_ts_OsTask_10ms, RTE_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA) Rte_OsTask_10ms;
WARNING_542_RESTORE
WARNING_542_DISABLE
VAR(Rte_ts_OsTask_100ms, RTE_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA) Rte_OsTask_100ms;
WARNING_542_RESTORE
#define RTE_STOP_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA
#include "rte_memmap.h"



#define RTE_START_SEC_CODE
#include "rte_memmap.h"
FUNC(void,RTE_CODE) os_task_ostask_10ms(void *arg)
{
    (void)arg;
/* ms5 harness: always declare ret — VCOS gen only declares under DLOG_ON but uses it in #else */
    Std_ReturnType ret;
    EventMaskType ev;

    for (;;) {
#if (RTE_DLOG_ENABLED == STD_ON)
        ret = WaitEvent(((EventMaskType) RTE_EV_CYCLIC2_OSTASK_10MS_0_5MS) | ((EventMaskType) RTE_EV_CYCLIC_OSTASK_10MS_0_10MS) | ((EventMaskType) RTE_EV_CYCLIC2_OSTASK_10MS_0_10MS));
        if (ret != E_OK)
        {
            Rte_LogOs(RTE_TASK_SERVICE_ID, OS_TASK_OsTask_10ms_ID, OSServiceId_WaitEvent, OS_TASK_OsTask_10ms_ID, ret);
        }
        ret = GetEvent((TaskType) OS_TASK_OsTask_10ms_ID, &ev);
        if (ret != E_OK)
        {
            Rte_LogOs(RTE_TASK_SERVICE_ID, OS_TASK_OsTask_10ms_ID, OSServiceId_GetEvent, OS_TASK_OsTask_10ms_ID, ret);
        }
        ret = ClearEvent(ev & (((EventMaskType) RTE_EV_CYCLIC2_OSTASK_10MS_0_5MS) | ((EventMaskType) RTE_EV_CYCLIC_OSTASK_10MS_0_10MS) | ((EventMaskType) RTE_EV_CYCLIC2_OSTASK_10MS_0_10MS)));
        if (ret != E_OK)
        {
            Rte_LogOs(RTE_TASK_SERVICE_ID, OS_TASK_OsTask_10ms_ID, OSServiceId_ClearEvent, OS_TASK_OsTask_10ms_ID, ret);
        }
#else
        (void)WaitEvent(((EventMaskType) RTE_EV_CYCLIC2_OSTASK_10MS_0_5MS) | ((EventMaskType) RTE_EV_CYCLIC_OSTASK_10MS_0_10MS) | ((EventMaskType) RTE_EV_CYCLIC2_OSTASK_10MS_0_10MS));
        (void)GetEvent((TaskType) OS_TASK_OSTASK_10MS_ID, &ev);
        (void)ClearEvent(ev & (((EventMaskType) RTE_EV_CYCLIC2_OSTASK_10MS_0_5MS) | ((EventMaskType) RTE_EV_CYCLIC_OSTASK_10MS_0_10MS) | ((EventMaskType) RTE_EV_CYCLIC2_OSTASK_10MS_0_10MS)));
#endif
        if ((ev & (EventMaskType)RTE_EV_CYCLIC2_OSTASK_10MS_0_5MS) != (EventMaskType)0) {
            Com_MainFunction_Rx();
            Com_MainFunction_Tx();
            Com_MainFunction_Gw();
            CanSM_MainFunction();
        }
        if ((ev & (EventMaskType)RTE_EV_CYCLIC2_OSTASK_10MS_0_10MS) != (EventMaskType)0) {
            ComM_MainFunction_ComMChannel_0();
            bswm_mainfunction();
            ecum_mainfunction();
        }
        if ((ev & (EventMaskType)RTE_EV_CYCLIC_OSTASK_10MS_0_10MS) != (EventMaskType)0) {
            /* read implicit data */
            ret = E_OK;
            ret |= com_receive_signal(ComConf_ComSignal_Cmd_AliveCnt_o_Cmd_Control_Rx, &Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_10ms.Rte_RP_Cmd_AliveCnt_Cmd_AliveCnt);
#if (RTE_DLOG_ENABLED == STD_ON)
            if (ret != E_OK)
            {
                Rte_LogCom(RTE_TASK_SERVICE_ID, OS_TASK_OsTask_10ms_ID, RTE_COM_RECEIVESIGNAL_ID, ComConf_ComSignal_Cmd_AliveCnt_o_Cmd_Control_Rx, ret);
            }
#endif
            
            ret |= com_receive_signal(ComConf_ComSignal_Cmd_Crc8_o_Cmd_Control_Rx, &Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_10ms.Rte_RP_Cmd_Crc8_Cmd_Crc8);
#if (RTE_DLOG_ENABLED == STD_ON)
            if (ret != E_OK)
            {
                Rte_LogCom(RTE_TASK_SERVICE_ID, OS_TASK_OsTask_10ms_ID, RTE_COM_RECEIVESIGNAL_ID, ComConf_ComSignal_Cmd_Crc8_o_Cmd_Control_Rx, ret);
            }
#endif
            
            ret |= com_receive_signal(ComConf_ComSignal_LedCmd_o_Cmd_Control_Rx, &Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_10ms.Rte_RP_LedCmd_LedCmd);
#if (RTE_DLOG_ENABLED == STD_ON)
            if (ret != E_OK)
            {
                Rte_LogCom(RTE_TASK_SERVICE_ID, OS_TASK_OsTask_10ms_ID, RTE_COM_RECEIVESIGNAL_ID, ComConf_ComSignal_LedCmd_o_Cmd_Control_Rx, ret);
            }
#endif
            
            ret |= com_receive_signal(ComConf_ComSignal_PwmDuty_o_Cmd_Control_Rx, &Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_10ms.Rte_RP_PwmDuty_PwmDuty);
#if (RTE_DLOG_ENABLED == STD_ON)
            if (ret != E_OK)
            {
                Rte_LogCom(RTE_TASK_SERVICE_ID, OS_TASK_OsTask_10ms_ID, RTE_COM_RECEIVESIGNAL_ID, ComConf_ComSignal_PwmDuty_o_Cmd_Control_Rx, ret);
            }
#endif
            
            ret |= com_receive_signal(ComConf_ComSignal_TargetMode_o_Cmd_Control_Rx, &Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_10ms.Rte_RP_TargetMode_TargetMode);
#if (RTE_DLOG_ENABLED == STD_ON)
            if (ret != E_OK)
            {
                Rte_LogCom(RTE_TASK_SERVICE_ID, OS_TASK_OsTask_10ms_ID, RTE_COM_RECEIVESIGNAL_ID, ComConf_ComSignal_TargetMode_o_Cmd_Control_Rx, ret);
            }
#endif
            RE_Cyclic_10ms();
            
#if (RTE_DLOG_ENABLED == STD_ON)
            ret = com_send_signal(ComConf_ComSignal_FaultActive_o_Fault_Event_Tx, &Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_10ms.Rte_PP_FaultActive_FaultActive);
            if (ret != E_OK)
            {
                Rte_LogCom(RTE_TASK_SERVICE_ID, OS_TASK_OSTASK_10MS_ID, RTE_COM_SENDSIGNAL_ID, ComConf_ComSignal_FaultActive_o_Fault_Event_Tx, ret);
            }
#else
            (void)com_send_signal(ComConf_ComSignal_FaultActive_o_Fault_Event_Tx, &Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_10ms.Rte_PP_FaultActive_FaultActive);
#endif
            
#if (RTE_DLOG_ENABLED == STD_ON)
            ret = com_send_signal(ComConf_ComSignal_FaultCode_o_Fault_Event_Tx, &Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_10ms.Rte_PP_FaultCode_FaultCode);
            if (ret != E_OK)
            {
                Rte_LogCom(RTE_TASK_SERVICE_ID, OS_TASK_OSTASK_10MS_ID, RTE_COM_SENDSIGNAL_ID, ComConf_ComSignal_FaultCode_o_Fault_Event_Tx, ret);
            }
#else
            (void)com_send_signal(ComConf_ComSignal_FaultCode_o_Fault_Event_Tx, &Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_10ms.Rte_PP_FaultCode_FaultCode);
#endif
            
#if (RTE_DLOG_ENABLED == STD_ON)
            ret = com_send_signal(ComConf_ComSignal_FaultFlags_o_ECU_Status_Tx, &Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_10ms.Rte_PP_FaultFlags_FaultFlags);
            if (ret != E_OK)
            {
                Rte_LogCom(RTE_TASK_SERVICE_ID, OS_TASK_OSTASK_10MS_ID, RTE_COM_SENDSIGNAL_ID, ComConf_ComSignal_FaultFlags_o_ECU_Status_Tx, ret);
            }
#else
            (void)com_send_signal(ComConf_ComSignal_FaultFlags_o_ECU_Status_Tx, &Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_10ms.Rte_PP_FaultFlags_FaultFlags);
#endif
        }
    }
}

FUNC(void,RTE_CODE) os_task_ostask_100ms(void *arg)
{
    (void)arg;
/* ms5 harness: ret unused when DLOG_OFF (com_send void-casted) */
    Std_ReturnType ret __attribute__((unused));
    EventMaskType ev;

    for (;;) {
#if (RTE_DLOG_ENABLED == STD_ON)
        ret = WaitEvent((EventMaskType) RTE_EV_CYCLIC_OSTASK_100MS_0_100MS);
        if (ret != E_OK)
        {
            Rte_LogOs(RTE_TASK_SERVICE_ID, OS_TASK_OsTask_100ms_ID, OSServiceId_WaitEvent, OS_TASK_OsTask_100ms_ID, ret);
        }
        ret = GetEvent((TaskType) OS_TASK_OsTask_100ms_ID, &ev);
        if (ret != E_OK)
        {
            Rte_LogOs(RTE_TASK_SERVICE_ID, OS_TASK_OsTask_100ms_ID, OSServiceId_GetEvent, OS_TASK_OsTask_100ms_ID, ret);
        }
        ret = ClearEvent(ev & ((EventMaskType) RTE_EV_CYCLIC_OSTASK_100MS_0_100MS));
        if (ret != E_OK)
        {
            Rte_LogOs(RTE_TASK_SERVICE_ID, OS_TASK_OsTask_100ms_ID, OSServiceId_ClearEvent, OS_TASK_OsTask_100ms_ID, ret);
        }
#else
        (void)WaitEvent((EventMaskType) RTE_EV_CYCLIC_OSTASK_100MS_0_100MS);
        (void)GetEvent((TaskType) OS_TASK_OSTASK_100MS_ID, &ev);
        (void)ClearEvent(ev & ((EventMaskType) RTE_EV_CYCLIC_OSTASK_100MS_0_100MS));
#endif
            RE_Cyclic_100ms();
            
#if (RTE_DLOG_ENABLED == STD_ON)
            ret = com_send_signal(ComConf_ComSignal_ECU_AliveCnt_o_ECU_Status_Tx, &Rte_OsTask_100ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_100ms.Rte_PP_ECU_AliveCnt_ECU_AliveCnt);
            if (ret != E_OK)
            {
                Rte_LogCom(RTE_TASK_SERVICE_ID, OS_TASK_OSTASK_100MS_ID, RTE_COM_SENDSIGNAL_ID, ComConf_ComSignal_ECU_AliveCnt_o_ECU_Status_Tx, ret);
            }
#else
            (void)com_send_signal(ComConf_ComSignal_ECU_AliveCnt_o_ECU_Status_Tx, &Rte_OsTask_100ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_100ms.Rte_PP_ECU_AliveCnt_ECU_AliveCnt);
#endif
            
#if (RTE_DLOG_ENABLED == STD_ON)
            ret = com_send_signal(ComConf_ComSignal_ECU_State_o_ECU_Status_Tx, &Rte_OsTask_100ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_100ms.Rte_PP_ECU_State_ECU_State);
            if (ret != E_OK)
            {
                Rte_LogCom(RTE_TASK_SERVICE_ID, OS_TASK_OSTASK_100MS_ID, RTE_COM_SENDSIGNAL_ID, ComConf_ComSignal_ECU_State_o_ECU_Status_Tx, ret);
            }
#else
            (void)com_send_signal(ComConf_ComSignal_ECU_State_o_ECU_Status_Tx, &Rte_OsTask_100ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_100ms.Rte_PP_ECU_State_ECU_State);
#endif
            
#if (RTE_DLOG_ENABLED == STD_ON)
            ret = com_send_signal(ComConf_ComSignal_SupplyVoltage_o_ECU_Status_Tx, &Rte_OsTask_100ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_100ms.Rte_PP_SupplyVoltage_SupplyVoltage);
            if (ret != E_OK)
            {
                Rte_LogCom(RTE_TASK_SERVICE_ID, OS_TASK_OSTASK_100MS_ID, RTE_COM_SENDSIGNAL_ID, ComConf_ComSignal_SupplyVoltage_o_ECU_Status_Tx, ret);
            }
#else
            (void)com_send_signal(ComConf_ComSignal_SupplyVoltage_o_ECU_Status_Tx, &Rte_OsTask_100ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_100ms.Rte_PP_SupplyVoltage_SupplyVoltage);
#endif
            
#if (RTE_DLOG_ENABLED == STD_ON)
            ret = com_send_signal(ComConf_ComSignal_Temperature_o_ECU_Status_Tx, &Rte_OsTask_100ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_100ms.Rte_PP_Temperature_Temperature);
            if (ret != E_OK)
            {
                Rte_LogCom(RTE_TASK_SERVICE_ID, OS_TASK_OSTASK_100MS_ID, RTE_COM_SENDSIGNAL_ID, ComConf_ComSignal_Temperature_o_ECU_Status_Tx, ret);
            }
#else
            (void)com_send_signal(ComConf_ComSignal_Temperature_o_ECU_Status_Tx, &Rte_OsTask_100ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_100ms.Rte_PP_Temperature_Temperature);
#endif
    }
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
