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
 * @file        SchM_PduR.h
 * @brief       Header of BSW Scheduler for BSW Module PduR
 * @details     This header file provides the necessary declarations for the BSW Scheduler functionality specific to 
 *              the PduR module
 * @date        2026-10-24 23:59:29
 * @toolversion V0.1.0-DEV
 **********************************************************************************************************************/

#ifndef SCHM_PDUR_H
#define SCHM_PDUR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "SchM_PduR_Type.h"
#include "Os.h"
#include "spinlock_cfg.h"

/*
 * Exclusive Areas
 */
#define SchM_Enter_PDUR_EXCLUSIVE_AREA_0() SuspendOSInterrupts()
#define SchM_Exit_PDUR_EXCLUSIVE_AREA_0() ResumeOSInterrupts()

#define SchM_Enter_PDUR_EXCLUSIVE_AREA_1() SuspendOSInterrupts()
#define SchM_Exit_PDUR_EXCLUSIVE_AREA_1() ResumeOSInterrupts()

#define SchM_Enter_PDUR_EXCLUSIVE_AREA_2() SuspendOSInterrupts()
#define SchM_Exit_PDUR_EXCLUSIVE_AREA_2() ResumeOSInterrupts()

#define SchM_Enter_PDUR_EXCLUSIVE_AREA_3() SuspendOSInterrupts()
#define SchM_Exit_PDUR_EXCLUSIVE_AREA_3() ResumeOSInterrupts()

#ifdef __cplusplus
}
#endif

#endif /* SCHM_PDUR_H*/
