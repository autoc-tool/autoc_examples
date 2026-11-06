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
 * Description: SchedTable配置源文件
 * AutoGenerate Code, DO NOT EDIT!!!
 * Generation Time : 2026-10-25 11:39:37
 * Project Name    : minimal_system9
 * Tool Version    : V0.1.0-DEV
 */

/* Including File */
#include <nuttx/config.h>
#include "Os.h"
#include "rtfw_types.h"
#include "schedtable_cfg.h"
#include "application_cfg.h"
#include "rtfw_task.h"
#include "task_cfg.h"
#include "event_cfg.h"
#include "rtfw_counter.h"
#include "counter_cfg.h"
#include "rtfw_compiler_cfg.h"

/* === SCHEDULE TABLE INSTANCE DEFINITIONS === */
/* SchTbl_5ms instance */
DeclareExpTaskList(OS_CONST_SECTION, SchedTable_ExpiryPoint_0_SchTbl_5ms_TaskList[]) =
{
    /* TaskType =               */ OS_TASK_OSTASK_5MS_ID,
};

DeclareExpiryPoint(OS_CONST_SECTION, SchedTable_SchTbl_5ms_ExpiryPointList[]) =
{
    {
        /* .task_list =            */ EXPIREPOINTCFGVAR(SchedTable_ExpiryPoint_0_SchTbl_5ms_TaskList),
        /* .event_list =           */ NULL_PTR,
        /* .adjust_expiry_point=   */ {
            /* .max_shorten =      */ 0,
            /* .max_lengthen =     */ 0,
        },
        /* .offset =               */ 0,
        /* .task_list_cnt =        */ NELEMENTS(EXPIREPOINTCFGVAR(SchedTable_ExpiryPoint_0_SchTbl_5ms_TaskList)),
        /* .event_list_cnt =       */ 0,
    },
};
DeclareSchedTable(OS_CONST_SECTION, OS_SYSTEMAPPLICATION_CORE0_BSS_SECTION, SCHEDTABLE_SCHTBL_5MS_CFG) = {
    /* .instance =                */ &SCHEDTABLEOBJVAR(SCHEDTABLE_SCHTBL_5MS_CFG),
    /* .schedtable_name =         */ "SchedTable_SchTbl_5ms",
    /* .expire_point_list =       */ EXPIREPOINTCFGVAR(SchedTable_SchTbl_5ms_ExpiryPointList),
    /* .action_config =           */ {
        /* .hrtimer =             */ &SCHEDTABLEOBJVAR(SCHEDTABLE_SCHTBL_5MS_CFG).hrtimer,
        /* .counter =             */ (os_counter_cfg_t*)&COUNTERCFGVAR(OsCounter_0_cfg),
        /* .action_callback =     */ &schedule_table_action_callback,
                                     },
    /* .autostart =               */ {
        /* .autostart_mode =      */ TRUE,
        /* .type =                */ SCHTBL_AUTOSTART_ABSOLUTE,
        /* .offset =              */ 0,
                                     },
    /* .duration =                */ 5,
    /* .expiry_point_cnt =        */ NELEMENTS(EXPIREPOINTCFGVAR(SchedTable_SchTbl_5ms_ExpiryPointList)),
    /* .precision =               */ 0,
#if defined(CONFIG_RT_FRAMEWORK_MULTIAPP) && (CONFIG_RT_FRAMEWORK_MULTIAPP == 1)
    /* .access_app_mask =         */ (RTFW_APPID2MASK(OS_CORE0_SYSTEMAPPLICATION_CORE0_ID)),
#endif /* #if defined(CONFIG_RT_FRAMEWORK_MULTIAPP) && (CONFIG_RT_FRAMEWORK_MULTIAPP == 1) */
    /* .schedtable_id =           */ OS_SCHEDTABLE_SCHTBL_5MS_ID,
    /* .repeating =               */ SCHTBL_REPEATING,
    /* .sync_strategy =           */ NONE,
#if defined(CONFIG_RT_FRAMEWORK_MULTIAPP) && (CONFIG_RT_FRAMEWORK_MULTIAPP == 1)
    /* .app_owner_id =            */ OS_CORE0_SYSTEMAPPLICATION_CORE0_ID,
#endif /* #if defined(CONFIG_RT_FRAMEWORK_MULTIAPP) && (CONFIG_RT_FRAMEWORK_MULTIAPP == 1) */
};
/* SchTbl_10ms instance */
DeclareExpTaskList(OS_CONST_SECTION, SchedTable_ExpiryPoint_0_SchTbl_10ms_TaskList[]) =
{
    /* TaskType =               */ OS_TASK_OSTASK_10MS_ID,
};

DeclareExpiryPoint(OS_CONST_SECTION, SchedTable_SchTbl_10ms_ExpiryPointList[]) =
{
    {
        /* .task_list =            */ EXPIREPOINTCFGVAR(SchedTable_ExpiryPoint_0_SchTbl_10ms_TaskList),
        /* .event_list =           */ NULL_PTR,
        /* .adjust_expiry_point=   */ {
            /* .max_shorten =      */ 0,
            /* .max_lengthen =     */ 0,
        },
        /* .offset =               */ 0,
        /* .task_list_cnt =        */ NELEMENTS(EXPIREPOINTCFGVAR(SchedTable_ExpiryPoint_0_SchTbl_10ms_TaskList)),
        /* .event_list_cnt =       */ 0,
    },
};
DeclareSchedTable(OS_CONST_SECTION, OS_SYSTEMAPPLICATION_CORE0_BSS_SECTION, SCHEDTABLE_SCHTBL_10MS_CFG) = {
    /* .instance =                */ &SCHEDTABLEOBJVAR(SCHEDTABLE_SCHTBL_10MS_CFG),
    /* .schedtable_name =         */ "SchedTable_SchTbl_10ms",
    /* .expire_point_list =       */ EXPIREPOINTCFGVAR(SchedTable_SchTbl_10ms_ExpiryPointList),
    /* .action_config =           */ {
        /* .hrtimer =             */ &SCHEDTABLEOBJVAR(SCHEDTABLE_SCHTBL_10MS_CFG).hrtimer,
        /* .counter =             */ (os_counter_cfg_t*)&COUNTERCFGVAR(OsCounter_0_cfg),
        /* .action_callback =     */ &schedule_table_action_callback,
                                     },
    /* .autostart =               */ {
        /* .autostart_mode =      */ TRUE,
        /* .type =                */ SCHTBL_AUTOSTART_ABSOLUTE,
        /* .offset =              */ 0,
                                     },
    /* .duration =                */ 10,
    /* .expiry_point_cnt =        */ NELEMENTS(EXPIREPOINTCFGVAR(SchedTable_SchTbl_10ms_ExpiryPointList)),
    /* .precision =               */ 0,
#if defined(CONFIG_RT_FRAMEWORK_MULTIAPP) && (CONFIG_RT_FRAMEWORK_MULTIAPP == 1)
    /* .access_app_mask =         */ (RTFW_APPID2MASK(OS_CORE0_SYSTEMAPPLICATION_CORE0_ID)),
#endif /* #if defined(CONFIG_RT_FRAMEWORK_MULTIAPP) && (CONFIG_RT_FRAMEWORK_MULTIAPP == 1) */
    /* .schedtable_id =           */ OS_SCHEDTABLE_SCHTBL_10MS_ID,
    /* .repeating =               */ SCHTBL_REPEATING,
    /* .sync_strategy =           */ NONE,
#if defined(CONFIG_RT_FRAMEWORK_MULTIAPP) && (CONFIG_RT_FRAMEWORK_MULTIAPP == 1)
    /* .app_owner_id =            */ OS_CORE0_SYSTEMAPPLICATION_CORE0_ID,
#endif /* #if defined(CONFIG_RT_FRAMEWORK_MULTIAPP) && (CONFIG_RT_FRAMEWORK_MULTIAPP == 1) */
};

#define OS_START_SEC_CONST
#include "rtfw_memmap.h"

/* Schedule Table Reference Tables */

CONSTP2CONST(os_schedtable_cfg_t, OS_CONST, AUTOMATIC) systemapplication_core0_schedtable_cfg_ref_table[] =
{
    &SCHEDTABLECFGVAR(SCHEDTABLE_SCHTBL_5MS_CFG),
    &SCHEDTABLECFGVAR(SCHEDTABLE_SCHTBL_10MS_CFG),
};
CONST(OsObjIndexType, OS_CONST) systemapplication_core0_schedtable_cfg_ref_table_size = NELEMENTS(systemapplication_core0_schedtable_cfg_ref_table);

#define OS_STOP_SEC_CONST
#include "rtfw_memmap.h"

DeclareRtfwRefTable(OS_CONST_SECTION, schedtable, OS_SCHED_TABLE_CNT) = {
    &SCHEDTABLECFGVAR(SCHEDTABLE_SCHTBL_5MS_CFG),
    &SCHEDTABLECFGVAR(SCHEDTABLE_SCHTBL_10MS_CFG),
};