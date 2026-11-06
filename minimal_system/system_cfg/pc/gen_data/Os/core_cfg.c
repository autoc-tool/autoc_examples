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
 * Description: Core Configuration
 * AutoGenerate Code, DO NOT EDIT!!!
 * Generation Time : 2026-10-26 10:16:14
 * Project Name    : minimal_system
 * Tool Version    : V0.1.0-DEV
 */

/* Including File */
#include <nuttx/config.h>
#include "rtfw_core.h"
#include "core_cfg.h"
#include "rtfw_compiler_cfg.h"
#include "application_cfg.h"
#if defined(CONFIG_RT_FRAMEWORK_IPICALL) && (CONFIG_RT_FRAMEWORK_IPICALL == 1)
#include "rtfw_ipicall.h"
#include "ipicall_cfg.h"
#endif
#if defined(CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION) && (CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION == 1)
#include "memory_protection_cfg.h"
#endif
#if defined(CONFIG_RT_FRAMEWORK_RESOURCE) && (CONFIG_RT_FRAMEWORK_RESOURCE == 1)
#include "rtfw_resource.h"
#include "resource_cfg.h"
#endif /* CONFIG_RT_FRAMEWORK_RESOURCE */
#if defined(CONFIG_RT_FRAMEWORK_HOOK) && (CONFIG_RT_FRAMEWORK_HOOK == 1)
#include "rtfw_hook.h"
#include "hook_cfg.h"
#endif /* CONFIG_RT_FRAMEWORK_HOOK */
#if defined(CONFIG_RT_FRAMEWORK_IOC) && (CONFIG_RT_FRAMEWORK_IOC == 1)
#include "rtfw_ioc.h"
#include "ioc_cfg.h"
#endif /* CONFIG_RT_FRAMEWORK_IOC */

#define OS_START_SEC_CONST
#include "rtfw_memmap.h"

/* Physical ID as index, Logical ID as Value */
CONST(uint32, OS_CONST) ulCoreIdTable[OS_CORE_PHYSICAL_CNT] = {
    (uint32)OS_CORE_ID_0,
    (uint32)OS_CORE_ID_1,
    (uint32)OS_CORE_ID_2,
    (uint32)OS_CORE_ID_3,
};
/* Logical ID as index, Physical ID as Value */
CONST(uint32, OS_CONST) ulCoreIdLog2PhyTable[OS_CORE_CNT] = {
    (uint32)OS_CORE_PHYSICAL_ID_0,
    (uint32)OS_CORE_PHYSICAL_ID_1,
    (uint32)OS_CORE_PHYSICAL_ID_2,
    (uint32)OS_CORE_PHYSICAL_ID_3,
};

#define OS_STOP_SEC_CONST
#include "rtfw_memmap.h"

/*! Core0 Configuration Implementation */
DeclareCore(OS_CONST_SECTION, OS_SYSTEMAPPLICATION_CORE0_BSS_SECTION, Os_Core0) = {
    /* .instance =               */ &OSCOREOBJVAR(Os_Core0),
    /* .core_id =                */ OS_CORE_ID_0,
    /* .physical_id =            */ (CoreIdType)OS_CORE_PHYSICAL_ID_0,
#if defined(CONFIG_RT_FRAMEWORK_MULTIAPP) && (CONFIG_RT_FRAMEWORK_MULTIAPP== 1)
    /* .kernel_app =             */ (os_app_cfg_t*)&OSAPPCFGVAR(SystemApplication_Core0),
    /* .app_ref =                */ os_core0_apps_cfg_ref_table,
    /* .app_count =              */ &os_core0_apps_cfg_ref_table_size,
#endif
#if defined(CONFIG_RT_FRAMEWORK_IOC) && (CONFIG_RT_FRAMEWORK_IOC == 1)
    /* .ioc_refs =               */ NULL_PTR,
    /* .ioc_count =              */ NULL_PTR,
#endif /* CONFIG_RT_FRAMEWORK_IOC */
#if defined(CONFIG_RT_FRAMEWORK_IPICALL) && (CONFIG_RT_FRAMEWORK_IPICALL == 1)
    /* .ipicall_refs =           */ os_core0_ipicalls_cfg_ref_table,
    /* .ipicall_count =          */ &os_core0_ipicalls_cfg_ref_table_size,
#endif /* CONFIG_RT_FRAMEWORK_IPICALL */
#if defined(CONFIG_RT_FRAMEWORK_RESOURCE) && (CONFIG_RT_FRAMEWORK_RESOURCE == 1)
    /* .resource_refs =          */ NULL_PTR,
    /* .resource_count =         */ NULL_PTR,
#endif /* CONFIG_RT_FRAMEWORK_RESOURCE */
#if defined(CONFIG_RT_FRAMEWORK_HOOK) && (CONFIG_RT_FRAMEWORK_HOOK == 1)
    /* .startup_hook =           */ NULL_PTR,
    /* .shutdown_hook =          */ NULL_PTR,
    /* .error_hook =             */ NULL_PTR,
    /* .protection_hook =        */ NULL_PTR,
    /* .hook_refs =              */ NULL_PTR,
    /* .hook_count =             */ NULL_PTR,
#endif
#if defined(CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION) && (CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION == 1)
    /* .mpu_access_right =       */ &core0_prestart_task_access_right,
#endif
};

/*! Core1 Configuration Implementation */
DeclareCore(OS_CONST_SECTION, OS_SYSTEMAPPLICATION_CORE1_BSS_SECTION, Os_Core1) = {
    /* .instance =               */ &OSCOREOBJVAR(Os_Core1),
    /* .core_id =                */ OS_CORE_ID_1,
    /* .physical_id =            */ (CoreIdType)OS_CORE_PHYSICAL_ID_1,
#if defined(CONFIG_RT_FRAMEWORK_MULTIAPP) && (CONFIG_RT_FRAMEWORK_MULTIAPP== 1)
    /* .kernel_app =             */ (os_app_cfg_t*)&OSAPPCFGVAR(SystemApplication_Core1),
    /* .app_ref =                */ os_core1_apps_cfg_ref_table,
    /* .app_count =              */ &os_core1_apps_cfg_ref_table_size,
#endif
#if defined(CONFIG_RT_FRAMEWORK_IOC) && (CONFIG_RT_FRAMEWORK_IOC == 1)
    /* .ioc_refs =               */ NULL_PTR,
    /* .ioc_count =              */ NULL_PTR,
#endif /* CONFIG_RT_FRAMEWORK_IOC */
#if defined(CONFIG_RT_FRAMEWORK_IPICALL) && (CONFIG_RT_FRAMEWORK_IPICALL == 1)
    /* .ipicall_refs =           */ os_core1_ipicalls_cfg_ref_table,
    /* .ipicall_count =          */ &os_core1_ipicalls_cfg_ref_table_size,
#endif /* CONFIG_RT_FRAMEWORK_IPICALL */
#if defined(CONFIG_RT_FRAMEWORK_RESOURCE) && (CONFIG_RT_FRAMEWORK_RESOURCE == 1)
    /* .resource_refs =          */ NULL_PTR,
    /* .resource_count =         */ NULL_PTR,
#endif /* CONFIG_RT_FRAMEWORK_RESOURCE */
#if defined(CONFIG_RT_FRAMEWORK_HOOK) && (CONFIG_RT_FRAMEWORK_HOOK == 1)
    /* .startup_hook =           */ NULL_PTR,
    /* .shutdown_hook =          */ NULL_PTR,
    /* .error_hook =             */ NULL_PTR,
    /* .protection_hook =        */ NULL_PTR,
    /* .hook_refs =              */ NULL_PTR,
    /* .hook_count =             */ NULL_PTR,
#endif
#if defined(CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION) && (CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION == 1)
    /* .mpu_access_right =       */ &core1_prestart_task_access_right,
#endif
};

/*! Core2 Configuration Implementation */
DeclareCore(OS_CONST_SECTION, OS_SYSTEMAPPLICATION_CORE2_BSS_SECTION, Os_Core2) = {
    /* .instance =               */ &OSCOREOBJVAR(Os_Core2),
    /* .core_id =                */ OS_CORE_ID_2,
    /* .physical_id =            */ (CoreIdType)OS_CORE_PHYSICAL_ID_2,
#if defined(CONFIG_RT_FRAMEWORK_MULTIAPP) && (CONFIG_RT_FRAMEWORK_MULTIAPP== 1)
    /* .kernel_app =             */ (os_app_cfg_t*)&OSAPPCFGVAR(SystemApplication_Core2),
    /* .app_ref =                */ os_core2_apps_cfg_ref_table,
    /* .app_count =              */ &os_core2_apps_cfg_ref_table_size,
#endif
#if defined(CONFIG_RT_FRAMEWORK_IOC) && (CONFIG_RT_FRAMEWORK_IOC == 1)
    /* .ioc_refs =               */ NULL_PTR,
    /* .ioc_count =              */ NULL_PTR,
#endif /* CONFIG_RT_FRAMEWORK_IOC */
#if defined(CONFIG_RT_FRAMEWORK_IPICALL) && (CONFIG_RT_FRAMEWORK_IPICALL == 1)
    /* .ipicall_refs =           */ os_core2_ipicalls_cfg_ref_table,
    /* .ipicall_count =          */ &os_core2_ipicalls_cfg_ref_table_size,
#endif /* CONFIG_RT_FRAMEWORK_IPICALL */
#if defined(CONFIG_RT_FRAMEWORK_RESOURCE) && (CONFIG_RT_FRAMEWORK_RESOURCE == 1)
    /* .resource_refs =          */ NULL_PTR,
    /* .resource_count =         */ NULL_PTR,
#endif /* CONFIG_RT_FRAMEWORK_RESOURCE */
#if defined(CONFIG_RT_FRAMEWORK_HOOK) && (CONFIG_RT_FRAMEWORK_HOOK == 1)
    /* .startup_hook =           */ NULL_PTR,
    /* .shutdown_hook =          */ NULL_PTR,
    /* .error_hook =             */ NULL_PTR,
    /* .protection_hook =        */ NULL_PTR,
    /* .hook_refs =              */ NULL_PTR,
    /* .hook_count =             */ NULL_PTR,
#endif
#if defined(CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION) && (CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION == 1)
    /* .mpu_access_right =       */ &core2_prestart_task_access_right,
#endif
};

/*! Core3 Configuration Implementation */
DeclareCore(OS_CONST_SECTION, OS_SYSTEMAPPLICATION_CORE3_BSS_SECTION, Os_Core3) = {
    /* .instance =               */ &OSCOREOBJVAR(Os_Core3),
    /* .core_id =                */ OS_CORE_ID_3,
    /* .physical_id =            */ (CoreIdType)OS_CORE_PHYSICAL_ID_3,
#if defined(CONFIG_RT_FRAMEWORK_MULTIAPP) && (CONFIG_RT_FRAMEWORK_MULTIAPP== 1)
    /* .kernel_app =             */ (os_app_cfg_t*)&OSAPPCFGVAR(SystemApplication_Core3),
    /* .app_ref =                */ os_core3_apps_cfg_ref_table,
    /* .app_count =              */ &os_core3_apps_cfg_ref_table_size,
#endif
#if defined(CONFIG_RT_FRAMEWORK_IOC) && (CONFIG_RT_FRAMEWORK_IOC == 1)
    /* .ioc_refs =               */ NULL_PTR,
    /* .ioc_count =              */ NULL_PTR,
#endif /* CONFIG_RT_FRAMEWORK_IOC */
#if defined(CONFIG_RT_FRAMEWORK_IPICALL) && (CONFIG_RT_FRAMEWORK_IPICALL == 1)
    /* .ipicall_refs =           */ os_core3_ipicalls_cfg_ref_table,
    /* .ipicall_count =          */ &os_core3_ipicalls_cfg_ref_table_size,
#endif /* CONFIG_RT_FRAMEWORK_IPICALL */
#if defined(CONFIG_RT_FRAMEWORK_RESOURCE) && (CONFIG_RT_FRAMEWORK_RESOURCE == 1)
    /* .resource_refs =          */ NULL_PTR,
    /* .resource_count =         */ NULL_PTR,
#endif /* CONFIG_RT_FRAMEWORK_RESOURCE */
#if defined(CONFIG_RT_FRAMEWORK_HOOK) && (CONFIG_RT_FRAMEWORK_HOOK == 1)
    /* .startup_hook =           */ NULL_PTR,
    /* .shutdown_hook =          */ NULL_PTR,
    /* .error_hook =             */ NULL_PTR,
    /* .protection_hook =        */ NULL_PTR,
    /* .hook_refs =              */ NULL_PTR,
    /* .hook_count =             */ NULL_PTR,
#endif
#if defined(CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION) && (CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION == 1)
    /* .mpu_access_right =       */ &core3_prestart_task_access_right,
#endif
};

DeclareRtfwRefTable(OS_CONST_SECTION, core, OS_CORE_CNT) = {
    &OSCORECFGVAR(Os_Core0),
    &OSCORECFGVAR(Os_Core1),
    &OSCORECFGVAR(Os_Core2),
    &OSCORECFGVAR(Os_Core3),
};
