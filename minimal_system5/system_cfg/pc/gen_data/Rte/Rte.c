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
 * @file        Rte.c
 * @brief       RTE implementation file
 * @details     Provides standardized APIs for the application layer and handles the communication mechanisms
 * @date        2026-10-24 23:59:29
 * @toolversion V0.1.0-DEV
 **********************************************************************************************************************/
#include "Os.h"
#include "Rte.h"
#include "Rte_Cbk.h"
#include "Rte_Type.h"
#include "Rte_Main.h"
#include "Rte_Dlog.h"
#include "core_cfg.h"
#include "task_cfg.h"
// #include "alarm_cfg.h"
#include "event_cfg.h"
#include "schedtable_cfg.h"
#include "spinlock_cfg.h"
#include "rte_memmap.h"
#define RTE_MEM32ALIGN (sizeof(uint32) - 1U)
/*
 * API for enable / disable interrupts global
 */
#define Rte_DisableAllInterrupts() DisableAllInterrupts()
#define Rte_EnableAllInterrupts()  EnableAllInterrupts()
#define Rte_DisableOSInterrupts()  SuspendOSInterrupts()
#define Rte_EnableOSInterrupts()   ResumeOSInterrupts()

#define Rte_DisableAllInterruptsOS() DisableAllInterrupts()
#define Rte_EnableAllInterruptsOS()  EnableAllInterrupts()
#define Rte_DisableOSInterruptsOS()  SuspendOSInterrupts()
#define Rte_EnableOSInterruptsOS()   ResumeOSInterrupts()

/*
 * Rte Init State Variable
 */
#define RTE_START_SEC_MULTI_APP_BSS
#include "rte_memmap.h"
volatile VAR(uint8, RTE_MULTI_APP_BSS) Rte_StartTiming_InitState;  // RTE_STATE_UNINIT, all core deinit
#define RTE_STOP_SEC_MULTI_APP_BSS
#include "rte_memmap.h"
#define RTE_START_SEC_MULTI_APP_BSS
#include "rte_memmap.h"
volatile VAR(uint8, RTE_MULTI_APP_BSS) Rte_InitState;  // RTE_STATE_UNINIT
#define RTE_STOP_SEC_MULTI_APP_BSS
#include "rte_memmap.h"


/*
 * RTE internal IOC replacement for C/S 1:N IOC
 */







/**
 * Activate the BSW Async task and set alarm, set Rte_InitState to RTE_STATE_SCHM_INIT
 */
#define RTE_START_SEC_CODE
#include "rte_memmap.h"
FUNC(void,RTE_CODE) SchM_Init(void)
{
#if (RTE_DLOG_ENABLED == STD_ON)
    Std_ReturnType ret;
#endif
    CoreIdType id = GetCoreID();
    if (id == OS_CORE_ID_0) {
        /* activate the tasks */
#if (RTE_DLOG_ENABLED == STD_ON)
        ret = ActivateTask((TaskType)OS_TASK_OSTASK_10MS_ID);
        if (ret != E_OK)
        {
            Rte_LogOs(SCHM_INIT_SERVICE_ID, RTE_DLOG_EMPTY_ID, OSServiceId_ActivateTask, OS_TASK_OSTASK_10MS_ID, ret);
        }
#else
        (void)ActivateTask((TaskType)OS_TASK_OSTASK_10MS_ID);
#endif
        /* activate the alarms used for TimingEvents */

        /* activate the schedule tables */
#if (RTE_DLOG_ENABLED == STD_ON)
#else
#endif
        Rte_InitState = RTE_STATE_SCHM_INIT;
    }
}

/**
 * Activate the Appl task and set alarm, set Rte_InitState to RTE_STATE_INIT
 *
 * @return Std_ReturnType
 *
 * @retval E_OK
 */
FUNC(Std_ReturnType,RTE_CODE) Rte_Start(void)
{
#if (RTE_DLOG_ENABLED == STD_ON)
    Std_ReturnType ret;
#endif
    CoreIdType id = GetCoreID();
    if (id == OS_CORE_ID_0) {
        /* activate the tasks */
#if (RTE_DLOG_ENABLED == STD_ON)
        ret = ActivateTask((TaskType)OS_TASK_OSTASK_100MS_ID);
        if (ret != E_OK)
        {
            Rte_LogOs(RTE_START_SERVICE_ID, RTE_DLOG_EMPTY_ID, OSServiceId_ActivateTask, OS_TASK_OSTASK_100MS_ID, ret);
        }
#else
        (void)ActivateTask((TaskType)OS_TASK_OSTASK_100MS_ID);
#endif
        /* activate the alarms used for TimingEvents */
        Rte_StartTiming_InitState = RTE_STATE_INIT;
        Rte_InitState = RTE_STATE_INIT;
    }
    return RTE_E_OK;
}

/**
 * Unset alarm, set Rte_StartTiming_InitState to RTE_STATE_UNINIT,
 * Set Rte_InitState to RTE_STATE_SCHM_INIT
 *
 * @return Std_ReturnType
 *
 * @retval RTE_E_OK
 */
FUNC(Std_ReturnType,RTE_CODE) Rte_Stop(void)
{
#if (RTE_DLOG_ENABLED == STD_ON)
    Std_ReturnType ret;
#endif
    return RTE_E_OK;
}

/**
 * Unset alarm, set Rte_InitState to RTE_STATE_UNINIT
 */
FUNC(void,RTE_CODE) SchM_Deinit(void)
{
#if (RTE_DLOG_ENABLED == STD_ON)
    Std_ReturnType ret;
#endif
    CoreIdType id = GetCoreID();
    if (id == OS_CORE_ID_0) {
        Rte_StartTiming_InitState = RTE_STATE_UNINIT;
        /* deactivate alarms */
#if (RTE_DLOG_ENABLED == STD_ON)
#else
#endif

        /* deactivate the schedule tables */
#if (RTE_DLOG_ENABLED == STD_ON)
#else
#endif
        Rte_InitState = RTE_STATE_UNINIT;
    }
}

FUNC(void,RTE_CODE) Rte_InitMemory(void)
{
    CoreIdType id = GetCoreID();
    if (id == OS_CORE_ID_0) {
        Rte_InitState = RTE_STATE_UNINIT;
        Rte_StartTiming_InitState = RTE_STATE_UNINIT;
        Rte_InitMemory_SystemApplication_Core0();
    }
}

/**
 * COM-Callbacks for DataReceivedEvent triggered runnables, inter-ECU client/server communication, for queued com. and for Rx timeout / Rx inv. flag (reset)
 */



#define RTE_STOP_SEC_CODE
#include "rte_memmap.h"
