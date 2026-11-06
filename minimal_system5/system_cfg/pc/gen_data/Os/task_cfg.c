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
 * Generation Time : 2026-10-24 23:59:26
 * Project Name    : minimal_system5
 * Tool Version    : V0.1.0-DEV
 */

/* Including File */
#include <nuttx/config.h>
#include "rtfw_thread_types.h"
#include "task_cfg.h"
#include "stack_cfg.h"
#include "rtfw_context.h"
#include "rtfw_compiler_cfg.h"
#include "application_cfg.h"
#include "rtfw_core.h"
#include "core_cfg.h"
#if defined(CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION) && (CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION == 1)
#include "memory_protection_cfg.h"
#endif

/* Extended Task Shared Stack */

DeclareThreadStack(OS_CORE0_SHELL_STACK_SECTION, CORE0_SHELL_CFG, CORE0_SHELL_CFG_STACK_SIZE);

DeclareExtendedTask(OS_CONST_SECTION, OS_SYSTEMAPPLICATION_CORE0_BSS_SECTION, CORE0_SHELL_CFG) = {
    /* .context =               */
    {
        /* .instance =             */ &TASKOBJVAR(CORE0_SHELL_CFG),
        /* .instance_name =        */ "core0_shell",
        /* .core =                 */ &OSCORECFGVAR(Os_Core0),
        /* .arch_ctx_cfg =         */
        {
            /* .stack_addr =       */ (OsStackAddrType)THREADSTACKVAR(CORE0_SHELL_CFG),
            /* .stack_size =       */ (OsStackSizeType)THREADSTACKSIZEVAR(CORE0_SHELL_CFG_STACK_SIZE),
            /* .entry_addr =       */ (os_context_entry_t)&os_task_core0_shell,
            /* .exit_addr =        */ (os_context_exit_t)NULL_PTR,
            /* .entry_param =      */ (os_context_entry_para_t)NULL_PTR,
        },
#if defined(CONFIG_RT_FRAMEWORK_MULTIAPP) && (CONFIG_RT_FRAMEWORK_MULTIAPP== 1)
        /* .app_owner_cfg =        */ &OSAPPCFGVAR(SystemApplication_Core0),
        /* .access_app_mask =      */ (RTFW_APPID2MASK(OS_CORE0_SYSTEMAPPLICATION_CORE0_ID)),
#endif /* #if defined(CONFIG_RT_FRAMEWORK_MULTIAPP) && (CONFIG_RT_FRAMEWORK_MULTIAPP== 1) */
        /* .initial_ctx_id =       */ OS_TASK_CONTEXT_ID,
#if defined(CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION) && (CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION == 1)
        /* .mpu_access_right =     */ &core0_shell_access_right,
#endif
    },
    /* .base_priority =            */ CORE0_SHELL_CFG_PRIORITY,
    /* .event_hdl =                */ &TASKEVENTOBJVAR(CORE0_SHELL_CFG),
#if defined(CONFIG_RT_FRAMEWORK_SHARE_TASK_STACK) && (CONFIG_RT_FRAMEWORK_SHARE_TASK_STACK == 1)
    /* .task_share_stack =         */ NULL_PTR,
#endif
    /* .task_id =                  */ OS_TASK_CORE0_SHELL_ID,
    /* .autostart_mode =           */ TRUE,
    /* .is_preemptive =            */ TRUE,
    /* .activation_limit =         */ 1,
};

DeclareThreadStack(OS_OSTASK_10MS_STACK_SECTION, OSTASK_10MS_CFG, OSTASK_10MS_CFG_STACK_SIZE);

DeclareExtendedTask(OS_CONST_SECTION, OS_SYSTEMAPPLICATION_CORE0_BSS_SECTION, OSTASK_10MS_CFG) = {
    /* .context =               */
    {
        /* .instance =             */ &TASKOBJVAR(OSTASK_10MS_CFG),
        /* .instance_name =        */ "OsTask_10ms",
        /* .core =                 */ &OSCORECFGVAR(Os_Core0),
        /* .arch_ctx_cfg =         */
        {
            /* .stack_addr =       */ (OsStackAddrType)THREADSTACKVAR(OSTASK_10MS_CFG),
            /* .stack_size =       */ (OsStackSizeType)THREADSTACKSIZEVAR(OSTASK_10MS_CFG_STACK_SIZE),
            /* .entry_addr =       */ (os_context_entry_t)&os_task_ostask_10ms,
            /* .exit_addr =        */ (os_context_exit_t)NULL_PTR,
            /* .entry_param =      */ (os_context_entry_para_t)NULL_PTR,
        },
#if defined(CONFIG_RT_FRAMEWORK_MULTIAPP) && (CONFIG_RT_FRAMEWORK_MULTIAPP== 1)
        /* .app_owner_cfg =        */ &OSAPPCFGVAR(SystemApplication_Core0),
        /* .access_app_mask =      */ (RTFW_APPID2MASK(OS_CORE0_SYSTEMAPPLICATION_CORE0_ID)),
#endif /* #if defined(CONFIG_RT_FRAMEWORK_MULTIAPP) && (CONFIG_RT_FRAMEWORK_MULTIAPP== 1) */
        /* .initial_ctx_id =       */ OS_TASK_CONTEXT_ID,
#if defined(CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION) && (CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION == 1)
        /* .mpu_access_right =     */ &ostask_10ms_access_right,
#endif
    },
    /* .base_priority =            */ OSTASK_10MS_CFG_PRIORITY,
    /* .event_hdl =                */ &TASKEVENTOBJVAR(OSTASK_10MS_CFG),
#if defined(CONFIG_RT_FRAMEWORK_SHARE_TASK_STACK) && (CONFIG_RT_FRAMEWORK_SHARE_TASK_STACK == 1)
    /* .task_share_stack =         */ NULL_PTR,
#endif
    /* .task_id =                  */ OS_TASK_OSTASK_10MS_ID,
    /* .autostart_mode =           */ FALSE,
    /* .is_preemptive =            */ TRUE,
    /* .activation_limit =         */ 1,
};

DeclareThreadStack(OS_OSTASK_INIT_STACK_SECTION, OSTASK_INIT_CFG, OSTASK_INIT_CFG_STACK_SIZE);

DeclareExtendedTask(OS_CONST_SECTION, OS_SYSTEMAPPLICATION_CORE0_BSS_SECTION, OSTASK_INIT_CFG) = {
    /* .context =               */
    {
        /* .instance =             */ &TASKOBJVAR(OSTASK_INIT_CFG),
        /* .instance_name =        */ "OsTask_Init",
        /* .core =                 */ &OSCORECFGVAR(Os_Core0),
        /* .arch_ctx_cfg =         */
        {
            /* .stack_addr =       */ (OsStackAddrType)THREADSTACKVAR(OSTASK_INIT_CFG),
            /* .stack_size =       */ (OsStackSizeType)THREADSTACKSIZEVAR(OSTASK_INIT_CFG_STACK_SIZE),
            /* .entry_addr =       */ (os_context_entry_t)&os_task_ostask_init,
            /* .exit_addr =        */ (os_context_exit_t)NULL_PTR,
            /* .entry_param =      */ (os_context_entry_para_t)NULL_PTR,
        },
#if defined(CONFIG_RT_FRAMEWORK_MULTIAPP) && (CONFIG_RT_FRAMEWORK_MULTIAPP== 1)
        /* .app_owner_cfg =        */ &OSAPPCFGVAR(SystemApplication_Core0),
        /* .access_app_mask =      */ (RTFW_APPID2MASK(OS_CORE0_SYSTEMAPPLICATION_CORE0_ID)),
#endif /* #if defined(CONFIG_RT_FRAMEWORK_MULTIAPP) && (CONFIG_RT_FRAMEWORK_MULTIAPP== 1) */
        /* .initial_ctx_id =       */ OS_TASK_CONTEXT_ID,
#if defined(CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION) && (CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION == 1)
        /* .mpu_access_right =     */ &ostask_init_access_right,
#endif
    },
    /* .base_priority =            */ OSTASK_INIT_CFG_PRIORITY,
    /* .event_hdl =                */ &TASKEVENTOBJVAR(OSTASK_INIT_CFG),
#if defined(CONFIG_RT_FRAMEWORK_SHARE_TASK_STACK) && (CONFIG_RT_FRAMEWORK_SHARE_TASK_STACK == 1)
    /* .task_share_stack =         */ NULL_PTR,
#endif
    /* .task_id =                  */ OS_TASK_OSTASK_INIT_ID,
    /* .autostart_mode =           */ TRUE,
    /* .is_preemptive =            */ TRUE,
    /* .activation_limit =         */ 1,
};

DeclareThreadStack(OS_OSTASK_100MS_STACK_SECTION, OSTASK_100MS_CFG, OSTASK_100MS_CFG_STACK_SIZE);

DeclareExtendedTask(OS_CONST_SECTION, OS_SYSTEMAPPLICATION_CORE0_BSS_SECTION, OSTASK_100MS_CFG) = {
    /* .context =               */
    {
        /* .instance =             */ &TASKOBJVAR(OSTASK_100MS_CFG),
        /* .instance_name =        */ "OsTask_100ms",
        /* .core =                 */ &OSCORECFGVAR(Os_Core0),
        /* .arch_ctx_cfg =         */
        {
            /* .stack_addr =       */ (OsStackAddrType)THREADSTACKVAR(OSTASK_100MS_CFG),
            /* .stack_size =       */ (OsStackSizeType)THREADSTACKSIZEVAR(OSTASK_100MS_CFG_STACK_SIZE),
            /* .entry_addr =       */ (os_context_entry_t)&os_task_ostask_100ms,
            /* .exit_addr =        */ (os_context_exit_t)NULL_PTR,
            /* .entry_param =      */ (os_context_entry_para_t)NULL_PTR,
        },
#if defined(CONFIG_RT_FRAMEWORK_MULTIAPP) && (CONFIG_RT_FRAMEWORK_MULTIAPP== 1)
        /* .app_owner_cfg =        */ &OSAPPCFGVAR(SystemApplication_Core0),
        /* .access_app_mask =      */ (RTFW_APPID2MASK(OS_CORE0_SYSTEMAPPLICATION_CORE0_ID)),
#endif /* #if defined(CONFIG_RT_FRAMEWORK_MULTIAPP) && (CONFIG_RT_FRAMEWORK_MULTIAPP== 1) */
        /* .initial_ctx_id =       */ OS_TASK_CONTEXT_ID,
#if defined(CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION) && (CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION == 1)
        /* .mpu_access_right =     */ &ostask_100ms_access_right,
#endif
    },
    /* .base_priority =            */ OSTASK_100MS_CFG_PRIORITY,
    /* .event_hdl =                */ &TASKEVENTOBJVAR(OSTASK_100MS_CFG),
#if defined(CONFIG_RT_FRAMEWORK_SHARE_TASK_STACK) && (CONFIG_RT_FRAMEWORK_SHARE_TASK_STACK == 1)
    /* .task_share_stack =         */ NULL_PTR,
#endif
    /* .task_id =                  */ OS_TASK_OSTASK_100MS_ID,
    /* .autostart_mode =           */ FALSE,
    /* .is_preemptive =            */ TRUE,
    /* .activation_limit =         */ 1,
};


#define OS_START_SEC_CONST
#include "rtfw_memmap.h"

CONSTP2CONST(os_task_cfg_t, OS_CONST, AUTOMATIC) systemapplication_core0_task_cfg_ref_table[] = {
    &TASKCFGVAR(CORE0_SHELL_CFG),
    &TASKCFGVAR(OSTASK_10MS_CFG),
    &TASKCFGVAR(OSTASK_INIT_CFG),
    &TASKCFGVAR(OSTASK_100MS_CFG),
};

CONST(OsObjIndexType, OS_CONST) systemapplication_core0_task_cfg_ref_table_size = NELEMENTS(systemapplication_core0_task_cfg_ref_table);

#define OS_STOP_SEC_CONST
#include "rtfw_memmap.h"

DeclareRtfwRefTable(OS_CONST_SECTION, task, OS_TASK_CNT) = {
    &TASKCFGVAR(CORE0_SHELL_CFG),
    &TASKCFGVAR(OSTASK_10MS_CFG),
    &TASKCFGVAR(OSTASK_INIT_CFG),
    &TASKCFGVAR(OSTASK_100MS_CFG),
};
