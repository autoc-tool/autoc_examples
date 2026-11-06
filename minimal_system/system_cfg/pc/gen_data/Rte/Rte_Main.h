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
 * @file        Rte_Main.h
 * @brief       Provide declarations for RTE and SchM Lifecycle APIs
 * @details     This header file provides declarations responsible for system initialization, starting the RTE schedule
 * @date        2026-10-26 10:37:47
 * @toolversion V0.1.0-DEV
 **********************************************************************************************************************/

/*
 * DESCRIPTION
 * This header file implements Rte life-cycle apis.
 */

#ifndef RTE_MAIN_H
#define RTE_MAIN_H

#include "Rte.h"
#include "Os.h"

#ifdef __cplusplus
extern "C" {
#endif

/* BSW Scheduler Life-Cycle API */
extern void SchM_Init(void);
extern void SchM_Deinit(void);

/* RTE Life-Cycle API */
extern Std_ReturnType Rte_Start(void);
extern Std_ReturnType Rte_Stop(void);

/* Extended Life-Cycle API */
extern void Rte_InitMemory(void);
extern void Rte_InitMemory_SystemApplication_Core0(void);
extern void Rte_InitMemory_SystemApplication_Core1(void);
extern void Rte_InitMemory_SystemApplication_Core2(void);
extern void Rte_InitMemory_SystemApplication_Core3(void);



#ifdef __cplusplus
}
#endif

#endif /* RTE_MAIN_H */
