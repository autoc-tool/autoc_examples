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
 * Description: SchedTable Configuration
 * AutoGenerate Code, DO NOT EDIT!!!
 * Generation Time : 2026-10-25 11:39:37
 * Project Name    : minimal_system9
 * Tool Version    : V0.1.0-DEV
 */
#ifndef RT_FRAMEWORK_INC_OS_SCHED_TABLE_CFG_H
#define RT_FRAMEWORK_INC_OS_SCHED_TABLE_CFG_H
#ifdef __cplusplus
extern "C"
{
#endif
/* Including File */
#include "rtfw_schedtable.h"

typedef enum {
    OS_SCHEDTABLE_SCHTBL_5MS_ID,
    OS_SCHEDTABLE_SCHTBL_10MS_ID,
    OS_SCHED_TABLE_CNT,
    OS_SCHED_TABLE_NONE,
} OS_SCHEDTABLEID_DEF;

#define OS_START_SEC_CONST
#include "rtfw_memmap.h"
extern CONSTP2CONST(os_schedtable_cfg_t, OS_CONST, AUTOMATIC) systemapplication_core0_schedtable_cfg_ref_table[];
extern CONST(OsObjIndexType, OS_CONST) systemapplication_core0_schedtable_cfg_ref_table_size;
#define OS_STOP_SEC_CONST
#include "rtfw_memmap.h"

#ifdef __cplusplus
}
#endif
#endif /* RT_FRAMEWORK_INC_OS_SCHED_TABLE_CFG_H */