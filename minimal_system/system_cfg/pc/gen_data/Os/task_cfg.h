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
 * Description: task Configuration
 * AutoGenerate Code, DO NOT EDIT!!!
 * Generation Time : 2026-10-26 10:16:14
 * Project Name    : minimal_system
 * Tool Version    : V0.1.0-DEV
 */

#ifndef RT_FRAMEWORK_INC_OS_TASK_CFG_H
#define RT_FRAMEWORK_INC_OS_TASK_CFG_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Including File */
#include "rtfw_task.h"

typedef enum {
    OS_TASK_OSTASK_5MS_ID,
    OS_TASK_CORE0_SHELL_ID,
    OS_TASK_OSTASK_10MS_ID,
    OS_TASK_OSTASK_INIT_ID,
    OS_TASK_CORE1_SHELL_ID,
    OS_TASK_CORE2_SHELL_ID,
    OS_TASK_CORE3_SHELL_ID,
    OS_TASK_CNT,
    OS_TASK_NONE
} OS_TASKID_DEF;
#define OS_START_SEC_CONST
#include "rtfw_memmap.h"
extern CONSTP2CONST(os_task_cfg_t, OS_CONST, AUTOMATIC) systemapplication_core0_task_cfg_ref_table[];
extern CONST(OsObjIndexType, OS_CONST) systemapplication_core0_task_cfg_ref_table_size;
#define OS_STOP_SEC_CONST
#include "rtfw_memmap.h"
#define OS_START_SEC_CONST
#include "rtfw_memmap.h"
extern CONSTP2CONST(os_task_cfg_t, OS_CONST, AUTOMATIC) systemapplication_core1_task_cfg_ref_table[];
extern CONST(OsObjIndexType, OS_CONST) systemapplication_core1_task_cfg_ref_table_size;
#define OS_STOP_SEC_CONST
#include "rtfw_memmap.h"
#define OS_START_SEC_CONST
#include "rtfw_memmap.h"
extern CONSTP2CONST(os_task_cfg_t, OS_CONST, AUTOMATIC) systemapplication_core2_task_cfg_ref_table[];
extern CONST(OsObjIndexType, OS_CONST) systemapplication_core2_task_cfg_ref_table_size;
#define OS_STOP_SEC_CONST
#include "rtfw_memmap.h"
#define OS_START_SEC_CONST
#include "rtfw_memmap.h"
extern CONSTP2CONST(os_task_cfg_t, OS_CONST, AUTOMATIC) systemapplication_core3_task_cfg_ref_table[];
extern CONST(OsObjIndexType, OS_CONST) systemapplication_core3_task_cfg_ref_table_size;
#define OS_STOP_SEC_CONST
#include "rtfw_memmap.h"

/* global Function Declaration */
extern void os_task_ostask_5ms(void *arg);
extern void os_task_core0_shell(void *arg);
extern void os_task_ostask_10ms(void *arg);
extern void os_task_ostask_init(void *arg);
extern void os_task_core1_shell(void *arg);
extern void os_task_core2_shell(void *arg);
extern void os_task_core3_shell(void *arg);

#ifdef __cplusplus
}
#endif

#endif /* RT_FRAMEWORK_INC_OS_TASK_CFG_H */
