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
 * @file        Rte_Type.h
 * @brief       Header file containing user defined AUTOSAR types and RTE structures
 * @details     Defines data structures that are required by the SWC to use the RTE implementation
 * @date        2026-10-25 11:50:41
 * @toolversion V0.1.0-DEV
 **********************************************************************************************************************/

#ifndef RTE_TYPE_H
#define RTE_TYPE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Platform_Types.h"
#include "Std_Types.h"
#include "Rte.h"

#define RTE_STATE_UNINIT          (0U)
#define RTE_STATE_SCHM_INIT       (1U)
#define RTE_STATE_INIT            (2U)

#define RTE_START_SEC_MULTI_APP_BSS
#include "rte_memmap.h"
extern volatile VAR(uint8, RTE_MULTI_APP_BSS) Rte_StartTiming_InitState;  // RTE_STATE_UNINIT
#define RTE_STOP_SEC_MULTI_APP_BSS
#include "rte_memmap.h"
#define RTE_START_SEC_MULTI_APP_BSS
#include "rte_memmap.h"
extern volatile VAR(uint8, RTE_MULTI_APP_BSS) Rte_InitState;
#define RTE_STOP_SEC_MULTI_APP_BSS
#include "rte_memmap.h"
typedef uint32 Rte_BitType;

/*
 * Type definitions for activation reasons of runnables
 */

/*
 * Data type definitions
 */
#define Rte_TypeDef_uint4
typedef uint8 uint4;
#define Rte_TypeDef_uint1
typedef uint8 uint1;
#define Rte_TypeDef_Rte_tsRB_MinimalSystem_MinimalSystem_10ms
typedef struct {
    uint16 Rte_EcuStatus_P_SupplyVoltage;
    uint4 Rte_EcuStatus_P_ECU_AliveCnt;
    uint4 Rte_EcuStatus_P_ECU_State;
    uint8 Rte_EcuStatus_P_FaultFlags;
    uint8 Rte_EcuStatus_P_Temperature;
    uint1 Rte_FaultEvent_P_FaultActive;
    uint8 Rte_FaultEvent_P_FaultCode;
    uint8 Rte_CmdControl_R_Cmd_AliveCnt;
    uint8 Rte_CmdControl_R_Cmd_Crc8;
    boolean Rte_CmdControl_R_LedCmd;
    uint8 Rte_CmdControl_R_PwmDuty;
    uint8 Rte_CmdControl_R_TargetMode;
} Rte_tsRB_MinimalSystem_MinimalSystem_10ms;
#define Rte_TypeDef_Rte_tuRB_OsTask_10ms
typedef struct {
    Rte_tsRB_MinimalSystem_MinimalSystem_10ms Rte_MinimalSystem_MinimalSystem_10ms;
} Rte_tuRB_OsTask_10ms;
#define Rte_TypeDef_Rte_ts_OsTask_10ms
typedef struct {
    Rte_tuRB_OsTask_10ms Rte_RB;
} Rte_ts_OsTask_10ms;
#define Rte_TypeDef_dtRef_VOID
typedef void * dtRef_VOID;
#define Rte_TypeDef_dtRef_const_VOID
typedef const void * dtRef_const_VOID;





/*
 * RTE internal IOC replacement for C/S 1:N IOC
 */












/*
 * CS multicore arguments
*/
#define RTE_START_SEC_CONST
#include "rte_memmap.h"
#define RTE_STOP_SEC_CONST
#include "rte_memmap.h"
/*
 * SR intra osa boolean buffer
 */
typedef struct
{
    Rte_BitType Rte_MinimalSystem_IoOut_P_LedState : 1;
} Rte_Private_SystemApplication_Core0_ZeroBool_VarType;
#define RTE_START_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA
#include "rte_memmap.h"
extern VAR(Rte_Private_SystemApplication_Core0_ZeroBool_VarType, RTE_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA) Rte_Private_SystemApplication_Core0_ZeroBool_Vars;
#define RTE_STOP_SEC_SYSTEMAPPLICATION_CORE0_PRIVATE_DATA
#include "rte_memmap.h"

#ifdef __cplusplus
}
#endif

#endif /* RTE_TYPE_H */
