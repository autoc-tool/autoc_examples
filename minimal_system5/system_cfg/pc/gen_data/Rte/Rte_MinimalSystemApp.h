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
 * @file        Rte_MinimalSystemApp.h
 * @brief       Application header file for SWC (Software Component)
 * @details     Defines the RTE API and any associated data structures that
 *              are required by the SWC to use the RTE implementation
 * @date        2026-10-24 23:59:29
 * @toolversion V0.1.0-DEV
 **********************************************************************************************************************/

#ifndef RTE_MINIMALSYSTEMAPP_H_
#define RTE_MINIMALSYSTEMAPP_H_


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
#include "Rte_MinimalSystemApp_Type.h"


 
# ifndef RTE_CORE
/*
 * Rte Copy Buffers for implicit S/R
*/
#define RTE_START_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA
#include "rte_memmap.h"
extern VAR(Rte_ts_OsTask_10ms, RTE_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA) Rte_OsTask_10ms;
extern VAR(Rte_ts_OsTask_100ms, RTE_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA) Rte_OsTask_100ms;
#define RTE_STOP_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA
#include "rte_memmap.h"
# endif /* !defined(RTE_CORE) */
# ifndef RTE_CORE
/*
 * Rte_IWrite/IWriteRef_<r>_<p>_<d> (implicit S/R communication with isQueued = false)
 */
#define Rte_IWrite_RE_Cyclic_100ms_PP_ECU_AliveCnt_ECU_AliveCnt(data) \
    (Rte_OsTask_100ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_100ms.Rte_PP_ECU_AliveCnt_ECU_AliveCnt = (data))
#define Rte_IWriteRef_RE_Cyclic_100ms_PP_ECU_AliveCnt_ECU_AliveCnt() \
    ((uint4 *) (&Rte_OsTask_100ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_100ms.Rte_PP_ECU_AliveCnt_ECU_AliveCnt))
#define Rte_IWrite_RE_Cyclic_100ms_PP_ECU_State_ECU_State(data) \
    (Rte_OsTask_100ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_100ms.Rte_PP_ECU_State_ECU_State = (data))
#define Rte_IWriteRef_RE_Cyclic_100ms_PP_ECU_State_ECU_State() \
    ((uint4 *) (&Rte_OsTask_100ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_100ms.Rte_PP_ECU_State_ECU_State))
#define Rte_IWrite_RE_Cyclic_100ms_PP_SupplyVoltage_SupplyVoltage(data) \
    (Rte_OsTask_100ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_100ms.Rte_PP_SupplyVoltage_SupplyVoltage = (data))
#define Rte_IWriteRef_RE_Cyclic_100ms_PP_SupplyVoltage_SupplyVoltage() \
    ((uint16 *) (&Rte_OsTask_100ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_100ms.Rte_PP_SupplyVoltage_SupplyVoltage))
#define Rte_IWrite_RE_Cyclic_100ms_PP_Temperature_Temperature(data) \
    (Rte_OsTask_100ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_100ms.Rte_PP_Temperature_Temperature = (data))
#define Rte_IWriteRef_RE_Cyclic_100ms_PP_Temperature_Temperature() \
    ((uint8 *) (&Rte_OsTask_100ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_100ms.Rte_PP_Temperature_Temperature))
#define Rte_IWrite_RE_Cyclic_10ms_PP_FaultActive_FaultActive(data) \
    (Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_10ms.Rte_PP_FaultActive_FaultActive = (data))
#define Rte_IWriteRef_RE_Cyclic_10ms_PP_FaultActive_FaultActive() \
    ((uint1 *) (&Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_10ms.Rte_PP_FaultActive_FaultActive))
#define Rte_IWrite_RE_Cyclic_10ms_PP_FaultCode_FaultCode(data) \
    (Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_10ms.Rte_PP_FaultCode_FaultCode = (data))
#define Rte_IWriteRef_RE_Cyclic_10ms_PP_FaultCode_FaultCode() \
    ((uint8 *) (&Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_10ms.Rte_PP_FaultCode_FaultCode))
#define Rte_IWrite_RE_Cyclic_10ms_PP_FaultFlags_FaultFlags(data) \
    (Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_10ms.Rte_PP_FaultFlags_FaultFlags = (data))
#define Rte_IWriteRef_RE_Cyclic_10ms_PP_FaultFlags_FaultFlags() \
    ((uint8 *) (&Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_10ms.Rte_PP_FaultFlags_FaultFlags))
/*
 * Rte_IRead_<r>_<p>_<d> (implicit S/R communication with isQueued = false)
 */
#define Rte_IRead_RE_Cyclic_10ms_RP_Cmd_AliveCnt_Cmd_AliveCnt() \
    (Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_10ms.Rte_RP_Cmd_AliveCnt_Cmd_AliveCnt)
#define Rte_IRead_RE_Cyclic_10ms_RP_Cmd_Crc8_Cmd_Crc8() \
    (Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_10ms.Rte_RP_Cmd_Crc8_Cmd_Crc8)
#define Rte_IRead_RE_Cyclic_10ms_RP_LedCmd_LedCmd() \
    (Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_10ms.Rte_RP_LedCmd_LedCmd)
#define Rte_IRead_RE_Cyclic_10ms_RP_PwmDuty_PwmDuty() \
    (Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_10ms.Rte_RP_PwmDuty_PwmDuty)
#define Rte_IRead_RE_Cyclic_10ms_RP_TargetMode_TargetMode() \
    (Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystemApp_RE_Cyclic_10ms.Rte_RP_TargetMode_TargetMode)
# endif /* !defined(RTE_CORE) */

#define RTE_START_SEC_CODE
#include "rte_memmap.h"
#define RTE_STOP_SEC_CODE
#include "rte_memmap.h"

# ifndef RTE_CORE
# endif /* !defined(RTE_CORE) */




#define MinimalSystemApp_START_SEC_CODE
//#include "MinimalSystemApp_MemMap.h"
# ifdef RTE_CORE
/*
 * Runnable entity prototypes
 */
/* Schedulable entities are declared by the RTE and also by the BSW modules, No functional risk, Both adhere to the Autosar specification. */
extern void RE_Cyclic_100ms(void);
/* Schedulable entities are declared by the RTE and also by the BSW modules, No functional risk, Both adhere to the Autosar specification. */
extern void RE_Cyclic_10ms(void);
/* Schedulable entities are declared by the RTE and also by the BSW modules, No functional risk, Both adhere to the Autosar specification. */
extern void RE_Init(void);

# endif /* !defined(RTE_CORE) */

# define MinimalSystemApp_STOP_SEC_CODE
//#include "MinimalSystemApp_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* RTE_MINIMALSYSTEMAPP_H_ */
