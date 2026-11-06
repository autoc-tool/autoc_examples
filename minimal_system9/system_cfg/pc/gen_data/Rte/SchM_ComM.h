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
 * @file        SchM_ComM.h
 * @brief       Header of BSW Scheduler for BSW Module ComM
 * @details     This header file provides the necessary declarations for the BSW Scheduler functionality specific to 
 *              the ComM module
 * @date        2026-10-25 11:50:41
 * @toolversion V0.1.0-DEV
 **********************************************************************************************************************/

#ifndef SCHM_COMM_H
#define SCHM_COMM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "SchM_ComM_Type.h"
#include "Os.h"
#include "spinlock_cfg.h"

/*
 * BSW SCHEDULABLE ENTITY
 */
void ComM_MainFunction_All_Channels(void);

void ComM_MainFunction_CAN1(void);

/*
 * Exclusive Areas
 */
#define SchM_Enter_COMM_EXCLUSIVE_AREA_0() SuspendOSInterrupts()
#define SchM_Exit_COMM_EXCLUSIVE_AREA_0() ResumeOSInterrupts()

#define SchM_Enter_COMM_EXCLUSIVE_AREA_1() SuspendOSInterrupts()
#define SchM_Exit_COMM_EXCLUSIVE_AREA_1() ResumeOSInterrupts()

#define SchM_Enter_COMM_EXCLUSIVE_AREA_2() SuspendOSInterrupts()
#define SchM_Exit_COMM_EXCLUSIVE_AREA_2() ResumeOSInterrupts()

#define SchM_Enter_COMM_EXCLUSIVE_AREA_3() SuspendOSInterrupts()
#define SchM_Exit_COMM_EXCLUSIVE_AREA_3() ResumeOSInterrupts()

#define SchM_Enter_COMM_EXCLUSIVE_AREA_4() SuspendOSInterrupts()
#define SchM_Exit_COMM_EXCLUSIVE_AREA_4() ResumeOSInterrupts()

#define SchM_Enter_COMM_EXCLUSIVE_AREA_5() SuspendOSInterrupts()
#define SchM_Exit_COMM_EXCLUSIVE_AREA_5() ResumeOSInterrupts()

#define SchM_Enter_COMM_EXCLUSIVE_AREA_6() SuspendOSInterrupts()
#define SchM_Exit_COMM_EXCLUSIVE_AREA_6() ResumeOSInterrupts()

#define SchM_Enter_COMM_EXCLUSIVE_AREA_7() SuspendOSInterrupts()
#define SchM_Exit_COMM_EXCLUSIVE_AREA_7() ResumeOSInterrupts()

#ifdef __cplusplus
}
#endif

#endif /* SCHM_COMM_H*/
