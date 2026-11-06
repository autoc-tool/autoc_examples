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
 * @file        Rte_MinimalSystem.h
 * @brief       Application header file for SWC (Software Component)
 * @details     Defines the RTE API and any associated data structures that
 *              are required by the SWC to use the RTE implementation
 * @date        2026-10-25 11:50:41
 * @toolversion V0.1.0-DEV
 **********************************************************************************************************************/

#ifndef RTE_MINIMALSYSTEM_H_
#define RTE_MINIMALSYSTEM_H_


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
#include "Rte_MinimalSystem_Type.h"


 
# ifndef RTE_CORE
/*
 * Rte Copy Buffers for implicit S/R
*/
#define RTE_START_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA
#include "rte_memmap.h"
extern VAR(Rte_ts_OsTask_10ms, RTE_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA) Rte_OsTask_10ms;
#define RTE_STOP_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA
#include "rte_memmap.h"
# endif /* !defined(RTE_CORE) */
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
extern VAR(uint8, RTE_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA) Rte_MinimalSystem_IoOut_P_PwmDuty;
#define RTE_STOP_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA
#include "rte_memmap.h"
# endif /* !defined(RTE_CORE) */
# ifndef RTE_CORE
/*
 * Rte_IWrite/IWriteRef_<r>_<p>_<d> (implicit S/R communication with isQueued = false)
 */
#define Rte_IWrite_MinimalSystem_10ms_EcuStatus_P_ECU_AliveCnt(data) \
    (Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_EcuStatus_P_ECU_AliveCnt = (data))
#define Rte_IWriteRef_MinimalSystem_10ms_EcuStatus_P_ECU_AliveCnt() \
    ((uint4 *) (&Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_EcuStatus_P_ECU_AliveCnt))
#define Rte_IWrite_MinimalSystem_10ms_EcuStatus_P_ECU_State(data) \
    (Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_EcuStatus_P_ECU_State = (data))
#define Rte_IWriteRef_MinimalSystem_10ms_EcuStatus_P_ECU_State() \
    ((uint4 *) (&Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_EcuStatus_P_ECU_State))
#define Rte_IWrite_MinimalSystem_10ms_EcuStatus_P_FaultFlags(data) \
    (Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_EcuStatus_P_FaultFlags = (data))
#define Rte_IWriteRef_MinimalSystem_10ms_EcuStatus_P_FaultFlags() \
    ((uint8 *) (&Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_EcuStatus_P_FaultFlags))
#define Rte_IWrite_MinimalSystem_10ms_EcuStatus_P_SupplyVoltage(data) \
    (Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_EcuStatus_P_SupplyVoltage = (data))
#define Rte_IWriteRef_MinimalSystem_10ms_EcuStatus_P_SupplyVoltage() \
    ((uint16 *) (&Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_EcuStatus_P_SupplyVoltage))
#define Rte_IWrite_MinimalSystem_10ms_EcuStatus_P_Temperature(data) \
    (Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_EcuStatus_P_Temperature = (data))
#define Rte_IWriteRef_MinimalSystem_10ms_EcuStatus_P_Temperature() \
    ((uint8 *) (&Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_EcuStatus_P_Temperature))
#define Rte_IWrite_MinimalSystem_10ms_FaultEvent_P_FaultActive(data) \
    (Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_FaultEvent_P_FaultActive = (data))
#define Rte_IWriteRef_MinimalSystem_10ms_FaultEvent_P_FaultActive() \
    ((uint1 *) (&Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_FaultEvent_P_FaultActive))
#define Rte_IWrite_MinimalSystem_10ms_FaultEvent_P_FaultCode(data) \
    (Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_FaultEvent_P_FaultCode = (data))
#define Rte_IWriteRef_MinimalSystem_10ms_FaultEvent_P_FaultCode() \
    ((uint8 *) (&Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_FaultEvent_P_FaultCode))
#define Rte_IWrite_MinimalSystem_10ms_IoOut_P_LedState(data) \
    (Rte_Private_SystemApplication_Core0_ZeroBool_Vars.Rte_MinimalSystem_IoOut_P_LedState = (data))
#define Rte_IWriteRef_MinimalSystem_10ms_IoOut_P_LedState() \
    ((boolean *) (&Rte_Private_SystemApplication_Core0_ZeroBool_Vars.Rte_MinimalSystem_IoOut_P_LedState))
#define Rte_IWrite_MinimalSystem_10ms_IoOut_P_PwmDuty(data) \
    (Rte_MinimalSystem_IoOut_P_PwmDuty = (data))
#define Rte_IWriteRef_MinimalSystem_10ms_IoOut_P_PwmDuty() \
    ((uint8 *) (&Rte_MinimalSystem_IoOut_P_PwmDuty))
/*
 * Rte_IRead_<r>_<p>_<d> (implicit S/R communication with isQueued = false)
 */
#define Rte_IRead_MinimalSystem_10ms_CmdControl_R_Cmd_AliveCnt() \
    (Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_CmdControl_R_Cmd_AliveCnt)
#define Rte_IRead_MinimalSystem_10ms_CmdControl_R_Cmd_Crc8() \
    (Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_CmdControl_R_Cmd_Crc8)
#define Rte_IRead_MinimalSystem_10ms_CmdControl_R_LedCmd() \
    (Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_CmdControl_R_LedCmd)
#define Rte_IRead_MinimalSystem_10ms_CmdControl_R_PwmDuty() \
    (Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_CmdControl_R_PwmDuty)
#define Rte_IRead_MinimalSystem_10ms_CmdControl_R_TargetMode() \
    (Rte_OsTask_10ms.Rte_RB.Rte_MinimalSystem_MinimalSystem_10ms.Rte_CmdControl_R_TargetMode)
# endif /* !defined(RTE_CORE) */

#define RTE_START_SEC_CODE
#include "rte_memmap.h"
#define RTE_STOP_SEC_CODE
#include "rte_memmap.h"

# ifndef RTE_CORE
# endif /* !defined(RTE_CORE) */




#define MinimalSystem_START_SEC_CODE
//#include "MinimalSystem_MemMap.h"
# ifdef RTE_CORE
/*
 * Runnable entity prototypes
 */
/* Schedulable entities are declared by the RTE and also by the BSW modules, No functional risk, Both adhere to the Autosar specification. */
extern void MinimalSystem_10ms(void);
/* Schedulable entities are declared by the RTE and also by the BSW modules, No functional risk, Both adhere to the Autosar specification. */
extern void MinimalSystem_Init(void);

# endif /* !defined(RTE_CORE) */

# define MinimalSystem_STOP_SEC_CODE
//#include "MinimalSystem_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* RTE_MINIMALSYSTEM_H_ */
