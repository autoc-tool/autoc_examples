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
 * @file        Rte_Dlog.h
 * @brief       Interface for diagnostic logging functionality within the system
 * @details     This header file provides declarations for diagnostic logging features
 * @date        2026-10-25 11:50:41
 * @toolversion V0.1.0-DEV
 **********************************************************************************************************************/

#ifndef RTE_DLOG_H_
#define RTE_DLOG_H_

#include "Rte_Type.h"

#define RTE_DLOG_EMPTY_ID 0U

/**
 * function switch: "Rte/RteGeneration/RteDevErrorDetect"
 */

extern void Rte_DetRte(uint8 serviceId, uint32 apiId, uint8 errorCode);
extern void Rte_DetCom(uint8 rteServiceId, uint32 rteApiId, uint8 comServiceId, uint32 comApiId, uint8 errorCode);
extern void Rte_DetOs(uint8 rteServiceId, uint32 rteApiId, uint8 osServiceId, uint32 osApiId, uint8 errorCode);

/*
 * log API: Rte_LogRte / Rte_LogCom / Rte_LogOs
 */
#define Rte_LogRte(serviceId, apiId, errorCode) Rte_DetRte((uint8) serviceId, (uint32) apiId, (uint8) errorCode)
#define Rte_LogCom(rteServiceId, rteApiId, comServiceId, comApiId, errorCode) Rte_DetCom((uint8) rteServiceId, (uint32) rteApiId, (uint8) comServiceId, (uint32) comApiId, (uint8) errorCode)
#define Rte_LogOs(rteServiceId, rteApiId, osServiceId, osApiId, errorCode) Rte_DetOs((uint8) rteServiceId, (uint32) rteApiId, (uint8) osServiceId, (uint32) osApiId, (uint8) errorCode)
#define RTE_DLOG_ENABLED STD_OFF

#endif