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

/*
 * Description: Os IpiCall Configuration
 * AutoGenerate Code, DO NOT EDIT!!!
 * Generation Time : 2026-10-25 11:39:37
 * Project Name    : minimal_system9
 * Tool Version    : V0.1.0-DEV
 */

#ifndef RT_FRAMEWORK_IPICALL_CFG_H
#define RT_FRAMEWORK_IPICALL_CFG_H

#ifdef __cplusplus
extern "C"
{
#endif

/* global Macro Definition */
/* TODO: read this config from UI*/
#define QUEUE_DEPTH 5U
typedef enum {
    OS_CORE0_IPICALL1_ID,
    OS_CORE0_IPICALL2_ID,
    OS_CORE0_IPICALL3_ID,
    OS_CORE1_IPICALL0_ID,
    OS_CORE1_IPICALL2_ID,
    OS_CORE1_IPICALL3_ID,
    OS_CORE2_IPICALL0_ID,
    OS_CORE2_IPICALL1_ID,
    OS_CORE2_IPICALL3_ID,
    OS_CORE3_IPICALL0_ID,
    OS_CORE3_IPICALL1_ID,
    OS_CORE3_IPICALL2_ID,
    OS_IPICALL_CNT
} OS_IPICALLID_DEF;
/* global type & Structure Definition */

#define OS_START_SEC_CONST
#include "rtfw_memmap.h"
extern CONSTP2CONST(os_ipicall_cfg_t, OS_CONST, AUTOMATIC) os_core0_ipicalls_cfg_ref_table[];
extern CONST(OsObjIndexType, OS_CONST) os_core0_ipicalls_cfg_ref_table_size;
extern CONSTP2CONST(os_ipicall_cfg_t, OS_CONST, AUTOMATIC) os_core1_ipicalls_cfg_ref_table[];
extern CONST(OsObjIndexType, OS_CONST) os_core1_ipicalls_cfg_ref_table_size;
extern CONSTP2CONST(os_ipicall_cfg_t, OS_CONST, AUTOMATIC) os_core2_ipicalls_cfg_ref_table[];
extern CONST(OsObjIndexType, OS_CONST) os_core2_ipicalls_cfg_ref_table_size;
extern CONSTP2CONST(os_ipicall_cfg_t, OS_CONST, AUTOMATIC) os_core3_ipicalls_cfg_ref_table[];
extern CONST(OsObjIndexType, OS_CONST) os_core3_ipicalls_cfg_ref_table_size;
#define OS_STOP_SEC_CONST
#include "rtfw_memmap.h"

/* global Function Declaration */
/* global Function Implementation */

#ifdef __cplusplus
}
#endif

#endif	 /* RT_FRAMEWORK_IPICALL_CFG_H */