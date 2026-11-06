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
 * @file        Rte_SystemApplication_Core3.c
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
#include "Os.h"
#include "Rte.h"
#include "Rte_Cbk.h"
#include "Rte_Main.h"
#include "task_cfg.h"
#include "event_cfg.h"
#include "spinlock_cfg.h"
#include "schedtable_cfg.h"

#include "Rte_SystemApplication_Core3.h"
#include "Rte_Dlog.h"
#include "Rte_Hook.h"
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

#define RTE_MSEC_TO_TICKS(time_ms) ((uint32) ((((float32) time_ms) / (((float32) 0.0) * 1000.0F)) + 0.5F))
#define RTE_START_SCH_TBL_OFFSET (1U)









#define RTE_START_SEC_CODE
#include "rte_memmap.h"

/*
 * Extended Life-Cycle API implementation
 */
FUNC(void,RTE_CODE) Rte_InitMemory_SystemApplication_Core3(void)
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
