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
 * Generation Time : 2026-10-25 11:39:37
 * Project Name    : minimal_system9
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
    /* .scht_refs =               */ systemapplication_core0_schedtable_cfg_ref_table,
    /* .scht_count =              */ &systemapplication_core0_schedtable_cfg_ref_table_size,
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
    
    
DeclareOsApplication(OS_CONST_SECTION, OS_SYSTEMAPPLICATION_CORE1_BSS_SECTION, SystemApplication_Core1) = {
    /* .instance =                */ &OSAPPOBJVAR(SystemApplication_Core1),
    /* .app_name =                */ "SystemApplication_Core1",
    /* .task_refs =               */ systemapplication_core1_task_cfg_ref_table,
    /* .task_count =              */ &systemapplication_core1_task_cfg_ref_table_size,
    /* .isr_refs =                */ NULL_PTR,
    /* .isr_count =               */ NULL_PTR,
#if defined(CONFIG_RT_FRAMEWORK_SCHTBL) && (CONFIG_RT_FRAMEWORK_SCHTBL == 1)
    /* .scht_refs =               */ NULL_PTR,
    /* .scht_count =              */ NULL_PTR,
#endif /* (CONFIG_RT_FRAMEWORK_SCHTBL == 1) */
#if defined(CONFIG_RT_FRAMEWORK_COUNTER) && (CONFIG_RT_FRAMEWORK_COUNTER == 1)
    /* .counter_refs =            */ NULL_PTR,
    /* .counter_count =           */ NULL_PTR,
#endif
#if defined(CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION) && (CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION == 1)
    /* .mpu_access_right =        */ &systemapplication_core1_access_right,
#endif
#if defined(CONFIG_RT_FRAMEWORK_HOOK) && (CONFIG_RT_FRAMEWORK_HOOK == 1)
    /* .startup_hook =            */ NULL_PTR,
    /* .shutdown_hook =           */ NULL_PTR,
    /* .error_hook =              */ NULL_PTR,
    /* .hook_refs =               */ NULL_PTR,
    /* .hook_count =              */ NULL_PTR,
#endif
    /* .core_id =                 */ OS_CORE_ID_1,
    /* .app_id =                  */ OS_CORE1_SYSTEMAPPLICATION_CORE1_ID,
    /* .is_privileged =           */ TRUE,
};
    
    
DeclareOsApplication(OS_CONST_SECTION, OS_SYSTEMAPPLICATION_CORE2_BSS_SECTION, SystemApplication_Core2) = {
    /* .instance =                */ &OSAPPOBJVAR(SystemApplication_Core2),
    /* .app_name =                */ "SystemApplication_Core2",
    /* .task_refs =               */ systemapplication_core2_task_cfg_ref_table,
    /* .task_count =              */ &systemapplication_core2_task_cfg_ref_table_size,
    /* .isr_refs =                */ NULL_PTR,
    /* .isr_count =               */ NULL_PTR,
#if defined(CONFIG_RT_FRAMEWORK_SCHTBL) && (CONFIG_RT_FRAMEWORK_SCHTBL == 1)
    /* .scht_refs =               */ NULL_PTR,
    /* .scht_count =              */ NULL_PTR,
#endif /* (CONFIG_RT_FRAMEWORK_SCHTBL == 1) */
#if defined(CONFIG_RT_FRAMEWORK_COUNTER) && (CONFIG_RT_FRAMEWORK_COUNTER == 1)
    /* .counter_refs =            */ NULL_PTR,
    /* .counter_count =           */ NULL_PTR,
#endif
#if defined(CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION) && (CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION == 1)
    /* .mpu_access_right =        */ &systemapplication_core2_access_right,
#endif
#if defined(CONFIG_RT_FRAMEWORK_HOOK) && (CONFIG_RT_FRAMEWORK_HOOK == 1)
    /* .startup_hook =            */ NULL_PTR,
    /* .shutdown_hook =           */ NULL_PTR,
    /* .error_hook =              */ NULL_PTR,
    /* .hook_refs =               */ NULL_PTR,
    /* .hook_count =              */ NULL_PTR,
#endif
    /* .core_id =                 */ OS_CORE_ID_2,
    /* .app_id =                  */ OS_CORE2_SYSTEMAPPLICATION_CORE2_ID,
    /* .is_privileged =           */ TRUE,
};
    
    
DeclareOsApplication(OS_CONST_SECTION, OS_SYSTEMAPPLICATION_CORE3_BSS_SECTION, SystemApplication_Core3) = {
    /* .instance =                */ &OSAPPOBJVAR(SystemApplication_Core3),
    /* .app_name =                */ "SystemApplication_Core3",
    /* .task_refs =               */ systemapplication_core3_task_cfg_ref_table,
    /* .task_count =              */ &systemapplication_core3_task_cfg_ref_table_size,
    /* .isr_refs =                */ NULL_PTR,
    /* .isr_count =               */ NULL_PTR,
#if defined(CONFIG_RT_FRAMEWORK_SCHTBL) && (CONFIG_RT_FRAMEWORK_SCHTBL == 1)
    /* .scht_refs =               */ NULL_PTR,
    /* .scht_count =              */ NULL_PTR,
#endif /* (CONFIG_RT_FRAMEWORK_SCHTBL == 1) */
#if defined(CONFIG_RT_FRAMEWORK_COUNTER) && (CONFIG_RT_FRAMEWORK_COUNTER == 1)
    /* .counter_refs =            */ NULL_PTR,
    /* .counter_count =           */ NULL_PTR,
#endif
#if defined(CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION) && (CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION == 1)
    /* .mpu_access_right =        */ &systemapplication_core3_access_right,
#endif
#if defined(CONFIG_RT_FRAMEWORK_HOOK) && (CONFIG_RT_FRAMEWORK_HOOK == 1)
    /* .startup_hook =            */ NULL_PTR,
    /* .shutdown_hook =           */ NULL_PTR,
    /* .error_hook =              */ NULL_PTR,
    /* .hook_refs =               */ NULL_PTR,
    /* .hook_count =              */ NULL_PTR,
#endif
    /* .core_id =                 */ OS_CORE_ID_3,
    /* .app_id =                  */ OS_CORE3_SYSTEMAPPLICATION_CORE3_ID,
    /* .is_privileged =           */ TRUE,
};

#define OS_START_SEC_CONST
#include "rtfw_memmap.h"

/* Os_Core0 config referenc table */
CONSTP2CONST(os_app_cfg_t, OS_CONST, AUTOMATIC) os_core0_apps_cfg_ref_table[] = {
    &OSAPPCFGVAR(SystemApplication_Core0),
};
CONST(OsObjIndexType, OS_CONST) os_core0_apps_cfg_ref_table_size = (OsObjIndexType)NELEMENTS(os_core0_apps_cfg_ref_table);

/* Os_Core1 config referenc table */
CONSTP2CONST(os_app_cfg_t, OS_CONST, AUTOMATIC) os_core1_apps_cfg_ref_table[] = {
    &OSAPPCFGVAR(SystemApplication_Core1),
};
CONST(OsObjIndexType, OS_CONST) os_core1_apps_cfg_ref_table_size = (OsObjIndexType)NELEMENTS(os_core1_apps_cfg_ref_table);

/* Os_Core2 config referenc table */
CONSTP2CONST(os_app_cfg_t, OS_CONST, AUTOMATIC) os_core2_apps_cfg_ref_table[] = {
    &OSAPPCFGVAR(SystemApplication_Core2),
};
CONST(OsObjIndexType, OS_CONST) os_core2_apps_cfg_ref_table_size = (OsObjIndexType)NELEMENTS(os_core2_apps_cfg_ref_table);

/* Os_Core3 config referenc table */
CONSTP2CONST(os_app_cfg_t, OS_CONST, AUTOMATIC) os_core3_apps_cfg_ref_table[] = {
    &OSAPPCFGVAR(SystemApplication_Core3),
};
CONST(OsObjIndexType, OS_CONST) os_core3_apps_cfg_ref_table_size = (OsObjIndexType)NELEMENTS(os_core3_apps_cfg_ref_table);

#define OS_STOP_SEC_CONST
#include "rtfw_memmap.h"

DeclareRtfwRefTable(OS_CONST_SECTION, app, OS_APPLICATION_CNT) = {
    &OSAPPCFGVAR(SystemApplication_Core0),
    &OSAPPCFGVAR(SystemApplication_Core1),
    &OSAPPCFGVAR(SystemApplication_Core2),
    &OSAPPCFGVAR(SystemApplication_Core3),
};
