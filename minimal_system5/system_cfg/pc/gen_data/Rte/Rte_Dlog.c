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
 * @file        Rte_Dlog.c
 * @brief       Implements diagnostic logging functionality for the system
 * @details     It provides functions to log various types of diagnostic messages and data
 * @date        2026-10-24 23:59:29
 * @toolversion V0.1.0-DEV
 **********************************************************************************************************************/

#include "Rte_Dlog.h"
#include "Det.h"
#include "Rte.h"

#define RTE_DLOG_RTE_INFO_LEN 4U
#define RTE_DLOG_OS_INFO_LEN 10U
#define RTE_DLOG_COM_INFO_LEN 10U

/**
 * RTE module ID is not yet defined by RTE, this value is defined according to "AUTOSAR_TR_BSWModuleList.pdf"
*/
#ifndef RTE_MODULE_ID
#define RTE_MODULE_ID 0x02U
#endif

#define RTE_E_OS_ERROR ((Std_ReturnType) 2U)
#define RTE_E_COM_ERROR ((Std_ReturnType) 3U)

/**********************************************************************************************************************
 * Function
 *********************************************************************************************************************/

#define Rte_GetErrorId(serviceId, errorCode) ((((uint32) RTE_MODULE_ID) << 16) | (((uint32) serviceId) << 8) | ((uint32) errorCode))

#define RTE_START_SEC_CODE
#include "rte_memmap.h"

static inline FUNC(void, RTE_CODE) Rte_ByteCpyReverseEndian(uint8 *dest, const uint8 *src, uint8 size)
{
    for (uint8 i = 0U; i < size; i++)
    {
        uint8 srcIndex = (uint8)(size - i - 1U);
        *(dest + i) = *(src + srcIndex);
    }
}

FUNC(void, RTE_CODE) Rte_DetRte(uint8 serviceId, uint32 apiId, uint8 errorCode)
{
    uint8 info[RTE_DLOG_RTE_INFO_LEN];
    Rte_ByteCpyReverseEndian(info, (uint8 *) &apiId, 4);
    (void) Det_ReportErrorWithInfo(Rte_GetErrorId(serviceId, errorCode), (uint8 *) &info, (uint8) RTE_DLOG_RTE_INFO_LEN);
}

FUNC(void, RTE_CODE) Rte_DetCom(uint8 rteServiceId, uint32 rteApiId, uint8 comServiceId, uint32 comApiId, uint8 errorCode)
{
    uint8 info[RTE_DLOG_COM_INFO_LEN];
    Rte_ByteCpyReverseEndian(info, (uint8 *) &rteApiId, 4);
    Rte_ByteCpyReverseEndian(info + 4, &comServiceId, 1);
    Rte_ByteCpyReverseEndian(info + 5, (uint8 *) &comApiId, 4);
    Rte_ByteCpyReverseEndian(info + 9, &errorCode, 1);
    (void) Det_ReportErrorWithInfo(Rte_GetErrorId(rteServiceId, RTE_E_COM_ERROR), (uint8 *) info, (uint8) RTE_DLOG_COM_INFO_LEN);
}

FUNC(void, RTE_CODE) Rte_DetOs(uint8 rteServiceId, uint32 rteApiId, uint8 osServiceId, uint32 osApiId, uint8 errorCode)
{
    uint8 info[RTE_DLOG_OS_INFO_LEN];
    Rte_ByteCpyReverseEndian(info, (uint8 *) &rteApiId, 4);
    Rte_ByteCpyReverseEndian(info + 4, &osServiceId, 1);
    Rte_ByteCpyReverseEndian(info + 5, (uint8 *) &osApiId, 4);
    Rte_ByteCpyReverseEndian(info + 9, &errorCode, 1);
    (void) Det_ReportErrorWithInfo(Rte_GetErrorId(rteServiceId, RTE_E_OS_ERROR), (uint8 *) info, (uint8) RTE_DLOG_OS_INFO_LEN);
}
#define RTE_STOP_SEC_CODE
#include "rte_memmap.h"