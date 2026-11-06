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
 * @file        Rte_IoHwAb.h
 * @brief       Application header file for SWC (Software Component)
 * @details     Defines the RTE API and any associated data structures that
 *              are required by the SWC to use the RTE implementation
 * @date        2026-10-26 10:37:47
 * @toolversion V0.1.0-DEV
 **********************************************************************************************************************/

#ifndef RTE_IOHWAB_H_
#define RTE_IOHWAB_H_


#ifndef RTE_CORE
# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include "Rte_Type.h"
#include "Rte_IoHwAb_Type.h"


 
# ifndef RTE_CORE
/*
 * Buffer extern for intra-osa implicit S/R Non-Queue
*/

#define RTE_START_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA
#include "rte_memmap.h"
#define RTE_STOP_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA
#include "rte_memmap.h"

#define RTE_START_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA
#include "rte_memmap.h"
extern VAR(Rte_Private_SystemApplication_Core0_ZeroBool_VarType, RTE_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA) Rte_Private_SystemApplication_Core0_ZeroBool_Vars;
extern VAR(uint8, RTE_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA) Rte_MinimalSystem_IoOut_PwmDuty;
#define RTE_STOP_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA
#include "rte_memmap.h"
# endif /* !defined(RTE_CORE) */
# ifndef RTE_CORE
/*
 * Rte_IRead_<r>_<p>_<d> (implicit S/R communication with isQueued = false)
 */
#define Rte_IRead_ActCycle_IoIn_LedState() \
    (Rte_Private_SystemApplication_Core0_ZeroBool_Vars.Rte_MinimalSystem_IoOut_LedState)
#define Rte_IRead_ActCycle_IoIn_PwmDuty() \
    (Rte_MinimalSystem_IoOut_PwmDuty)
# endif /* !defined(RTE_CORE) */

#define RTE_START_SEC_CODE
#include "rte_memmap.h"
#define RTE_STOP_SEC_CODE
#include "rte_memmap.h"

# ifndef RTE_CORE
# endif /* !defined(RTE_CORE) */




#define IoHwAb_START_SEC_CODE
//#include "IoHwAb_MemMap.h"
# ifdef RTE_CORE
/*
 * Runnable entity prototypes
 */
/* Schedulable entities are declared by the RTE and also by the BSW modules, No functional risk, Both adhere to the Autosar specification. */
extern void IoHwAb_10ms(void);

# endif /* !defined(RTE_CORE) */

# define IoHwAb_STOP_SEC_CODE
//#include "IoHwAb_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* RTE_IOHWAB_H_ */
