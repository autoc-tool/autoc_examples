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
 * Description: Os Application Configuration
 * AutoGenerate Code, DO NOT EDIT!!!
 * Generation Time : 2026-10-24 23:59:26
 * Project Name    : minimal_system5
 * Tool Version    : V0.1.0-DEV
 */

 /* Including File */
#include <nuttx/config.h>
#include "application_cfg.h"
#include "rtfw_compiler_cfg.h"
#include "task_cfg.h"
#include "isr_cfg.h"
#include "counter_cfg.h"
#include "rtfw_core.h"
#include "core_cfg.h"
#if defined(CONFIG_RT_FRAMEWORK_SCHTBL) && (CONFIG_RT_FRAMEWORK_SCHTBL == 1)
#include "schedtable_cfg.h"
#endif /* (CONFIG_RT_FRAMEWORK_SCHTBL == 1) */
#if defined(CONFIG_RT_FRAMEWORK_HOOK) && (CONFIG_RT_FRAMEWORK_HOOK == 1)
#include "hook_cfg.h"
#endif

#if defined(CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION) && (CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION == 1)
#include "memory_protection_cfg.h"
#endif

/* Local Macro Definition */

/* Local Enumeration Definition */
    
    
DeclareOsApplication(OS_CONST_SECTION, OS_SYSTEMAPPLICATION_CORE0_BSS_SECTION, SystemApplication_Core0) = {
    /* .instance =                */ &OSAPPOBJVAR(SystemApplication_Core0),
    /* .app_name =                */ "SystemApplication_Core0",
    /* .task_refs =               */ systemapplication_core0_task_cfg_ref_table,
    /* .task_count =              */ &systemapplication_core0_task_cfg_ref_table_size,
    /* .isr_refs =                */ NULL_PTR,
    /* .isr_count =               */ NULL_PTR,
#if defined(CONFIG_RT_FRAMEWORK_SCHTBL) && (CONFIG_RT_FRAMEWORK_SCHTBL == 1)
    /* .scht_refs =               */ NULL_PTR,
    /* .scht_count =              */ NULL_PTR,
#endif /* (CONFIG_RT_FRAMEWORK_SCHTBL == 1) */
#if defined(CONFIG_RT_FRAMEWORK_COUNTER) && (CONFIG_RT_FRAMEWORK_COUNTER == 1)
    /* .counter_refs =            */ systemapplication_core0_counter_cfg_ref_table,
    /* .counter_count =           */ &systemapplication_core0_counter_cfg_ref_table_size,
#endif
#if defined(CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION) && (CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION == 1)
    /* .mpu_access_right =        */ &systemapplication_core0_access_right,
#endif
#if defined(CONFIG_RT_FRAMEWORK_HOOK) && (CONFIG_RT_FRAMEWORK_HOOK == 1)
    /* .startup_hook =            */ NULL_PTR,
    /* .shutdown_hook =           */ NULL_PTR,
    /* .error_hook =              */ NULL_PTR,
    /* .hook_refs =               */ NULL_PTR,
    /* .hook_count =              */ NULL_PTR,
#endif
    /* .core_id =                 */ OS_CORE_ID_0,
    /* .app_id =                  */ OS_CORE0_SYSTEMAPPLICATION_CORE0_ID,
    /* .is_privileged =           */ TRUE,
};

#define OS_START_SEC_CONST
#include "rtfw_memmap.h"

/* Os_Core0 config referenc table */
CONSTP2CONST(os_app_cfg_t, OS_CONST, AUTOMATIC) os_core0_apps_cfg_ref_table[] = {
    &OSAPPCFGVAR(SystemApplication_Core0),
};
CONST(OsObjIndexType, OS_CONST) os_core0_apps_cfg_ref_table_size = (OsObjIndexType)NELEMENTS(os_core0_apps_cfg_ref_table);

#define OS_STOP_SEC_CONST
#include "rtfw_memmap.h"

DeclareRtfwRefTable(OS_CONST_SECTION, app, OS_APPLICATION_CNT) = {
    &OSAPPCFGVAR(SystemApplication_Core0),
};
