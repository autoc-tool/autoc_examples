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
 * Generation Time : 2026-10-25 11:39:37
 * Project Name    : minimal_system9
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

DeclareThreadStack(OS_OSTASK_5MS_STACK_SECTION, OSTASK_5MS_CFG, OSTASK_5MS_CFG_STACK_SIZE);

DeclareBasicTask(OS_CONST_SECTION, OS_SYSTEMAPPLICATION_CORE0_BSS_SECTION, OSTASK_5MS_CFG) = {
    /* .context =               */
    {
        /* .instance =             */ &TASKOBJVAR(OSTASK_5MS_CFG),
        /* .instance_name =        */ "OsTask_5ms",
        /* .core =                 */ &OSCORECFGVAR(Os_Core0),
        /* .arch_ctx_cfg =         */
        {
            /* .stack_addr =       */ (OsStackAddrType)THREADSTACKVAR(OSTASK_5MS_CFG),
            /* .stack_size =       */ (OsStackSizeType)THREADSTACKSIZEVAR(OSTASK_5MS_CFG_STACK_SIZE),
            /* .entry_addr =       */ (os_context_entry_t)&os_task_ostask_5ms,
            /* .exit_addr =        */ (os_context_exit_t)NULL_PTR,
            /* .entry_param =      */ (os_context_entry_para_t)NULL_PTR,
        },
#if defined(CONFIG_RT_FRAMEWORK_MULTIAPP) && (CONFIG_RT_FRAMEWORK_MULTIAPP== 1)
        /* .app_owner_cfg =        */ &OSAPPCFGVAR(SystemApplication_Core0),
        /* .access_app_mask =      */ (RTFW_APPID2MASK(OS_CORE0_SYSTEMAPPLICATION_CORE0_ID)),
#endif /* #if defined(CONFIG_RT_FRAMEWORK_MULTIAPP) && (CONFIG_RT_FRAMEWORK_MULTIAPP== 1) */
        /* .initial_ctx_id =       */ OS_TASK_CONTEXT_ID,
#if defined(CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION) && (CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION == 1)
        /* .mpu_access_right =     */ &ostask_5ms_access_right,
#endif
    },
    /* .base_priority =            */ OSTASK_5MS_CFG_PRIORITY,
    /* .event_hdl =                */ NULL_PTR,
#if defined(CONFIG_RT_FRAMEWORK_SHARE_TASK_STACK) && (CONFIG_RT_FRAMEWORK_SHARE_TASK_STACK == 1)
    /* .task_share_stack =         */ NULL_PTR,
#endif
    /* .task_id =                  */ OS_TASK_OSTASK_5MS_ID,
    /* .autostart_mode =           */ FALSE,
    /* .is_preemptive =            */ TRUE,
    /* .activation_limit =         */ 1,
};

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

DeclareBasicTask(OS_CONST_SECTION, OS_SYSTEMAPPLICATION_CORE0_BSS_SECTION, OSTASK_10MS_CFG) = {
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
    /* .event_hdl =                */ NULL_PTR,
#if defined(CONFIG_RT_FRAMEWORK_SHARE_TASK_STACK) && (CONFIG_RT_FRAMEWORK_SHARE_TASK_STACK == 1)
    /* .task_share_stack =         */ NULL_PTR,
#endif
    /* .task_id =                  */ OS_TASK_OSTASK_10MS_ID,
    /* .autostart_mode =           */ FALSE,
    /* .is_preemptive =            */ TRUE,
    /* .activation_limit =         */ 1,
};

DeclareThreadStack(OS_OSTASK_INIT_STACK_SECTION, OSTASK_INIT_CFG, OSTASK_INIT_CFG_STACK_SIZE);

DeclareBasicTask(OS_CONST_SECTION, OS_SYSTEMAPPLICATION_CORE0_BSS_SECTION, OSTASK_INIT_CFG) = {
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
    /* .event_hdl =                */ NULL_PTR,
#if defined(CONFIG_RT_FRAMEWORK_SHARE_TASK_STACK) && (CONFIG_RT_FRAMEWORK_SHARE_TASK_STACK == 1)
    /* .task_share_stack =         */ NULL_PTR,
#endif
    /* .task_id =                  */ OS_TASK_OSTASK_INIT_ID,
    /* .autostart_mode =           */ TRUE,
    /* .is_preemptive =            */ TRUE,
    /* .activation_limit =         */ 1,
};

DeclareThreadStack(OS_CORE1_SHELL_STACK_SECTION, CORE1_SHELL_CFG, CORE1_SHELL_CFG_STACK_SIZE);

DeclareExtendedTask(OS_CONST_SECTION, OS_SYSTEMAPPLICATION_CORE1_BSS_SECTION, CORE1_SHELL_CFG) = {
    /* .context =               */
    {
        /* .instance =             */ &TASKOBJVAR(CORE1_SHELL_CFG),
        /* .instance_name =        */ "core1_shell",
        /* .core =                 */ &OSCORECFGVAR(Os_Core1),
        /* .arch_ctx_cfg =         */
        {
            /* .stack_addr =       */ (OsStackAddrType)THREADSTACKVAR(CORE1_SHELL_CFG),
            /* .stack_size =       */ (OsStackSizeType)THREADSTACKSIZEVAR(CORE1_SHELL_CFG_STACK_SIZE),
            /* .entry_addr =       */ (os_context_entry_t)&os_task_core1_shell,
            /* .exit_addr =        */ (os_context_exit_t)NULL_PTR,
            /* .entry_param =      */ (os_context_entry_para_t)NULL_PTR,
        },
#if defined(CONFIG_RT_FRAMEWORK_MULTIAPP) && (CONFIG_RT_FRAMEWORK_MULTIAPP== 1)
        /* .app_owner_cfg =        */ &OSAPPCFGVAR(SystemApplication_Core1),
        /* .access_app_mask =      */ (RTFW_APPID2MASK(OS_CORE1_SYSTEMAPPLICATION_CORE1_ID)),
#endif /* #if defined(CONFIG_RT_FRAMEWORK_MULTIAPP) && (CONFIG_RT_FRAMEWORK_MULTIAPP== 1) */
        /* .initial_ctx_id =       */ OS_TASK_CONTEXT_ID,
#if defined(CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION) && (CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION == 1)
        /* .mpu_access_right =     */ &core1_shell_access_right,
#endif
    },
    /* .base_priority =            */ CORE1_SHELL_CFG_PRIORITY,
    /* .event_hdl =                */ &TASKEVENTOBJVAR(CORE1_SHELL_CFG),
#if defined(CONFIG_RT_FRAMEWORK_SHARE_TASK_STACK) && (CONFIG_RT_FRAMEWORK_SHARE_TASK_STACK == 1)
    /* .task_share_stack =         */ NULL_PTR,
#endif
    /* .task_id =                  */ OS_TASK_CORE1_SHELL_ID,
    /* .autostart_mode =           */ TRUE,
    /* .is_preemptive =            */ TRUE,
    /* .activation_limit =         */ 1,
};

DeclareThreadStack(OS_CORE2_SHELL_STACK_SECTION, CORE2_SHELL_CFG, CORE2_SHELL_CFG_STACK_SIZE);

DeclareExtendedTask(OS_CONST_SECTION, OS_SYSTEMAPPLICATION_CORE2_BSS_SECTION, CORE2_SHELL_CFG) = {
    /* .context =               */
    {
        /* .instance =             */ &TASKOBJVAR(CORE2_SHELL_CFG),
        /* .instance_name =        */ "core2_shell",
        /* .core =                 */ &OSCORECFGVAR(Os_Core2),
        /* .arch_ctx_cfg =         */
        {
            /* .stack_addr =       */ (OsStackAddrType)THREADSTACKVAR(CORE2_SHELL_CFG),
            /* .stack_size =       */ (OsStackSizeType)THREADSTACKSIZEVAR(CORE2_SHELL_CFG_STACK_SIZE),
            /* .entry_addr =       */ (os_context_entry_t)&os_task_core2_shell,
            /* .exit_addr =        */ (os_context_exit_t)NULL_PTR,
            /* .entry_param =      */ (os_context_entry_para_t)NULL_PTR,
        },
#if defined(CONFIG_RT_FRAMEWORK_MULTIAPP) && (CONFIG_RT_FRAMEWORK_MULTIAPP== 1)
        /* .app_owner_cfg =        */ &OSAPPCFGVAR(SystemApplication_Core2),
        /* .access_app_mask =      */ (RTFW_APPID2MASK(OS_CORE2_SYSTEMAPPLICATION_CORE2_ID)),
#endif /* #if defined(CONFIG_RT_FRAMEWORK_MULTIAPP) && (CONFIG_RT_FRAMEWORK_MULTIAPP== 1) */
        /* .initial_ctx_id =       */ OS_TASK_CONTEXT_ID,
#if defined(CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION) && (CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION == 1)
        /* .mpu_access_right =     */ &core2_shell_access_right,
#endif
    },
    /* .base_priority =            */ CORE2_SHELL_CFG_PRIORITY,
    /* .event_hdl =                */ &TASKEVENTOBJVAR(CORE2_SHELL_CFG),
#if defined(CONFIG_RT_FRAMEWORK_SHARE_TASK_STACK) && (CONFIG_RT_FRAMEWORK_SHARE_TASK_STACK == 1)
    /* .task_share_stack =         */ NULL_PTR,
#endif
    /* .task_id =                  */ OS_TASK_CORE2_SHELL_ID,
    /* .autostart_mode =           */ TRUE,
    /* .is_preemptive =            */ TRUE,
    /* .activation_limit =         */ 1,
};

DeclareThreadStack(OS_CORE3_SHELL_STACK_SECTION, CORE3_SHELL_CFG, CORE3_SHELL_CFG_STACK_SIZE);

DeclareExtendedTask(OS_CONST_SECTION, OS_SYSTEMAPPLICATION_CORE3_BSS_SECTION, CORE3_SHELL_CFG) = {
    /* .context =               */
    {
        /* .instance =             */ &TASKOBJVAR(CORE3_SHELL_CFG),
        /* .instance_name =        */ "core3_shell",
        /* .core =                 */ &OSCORECFGVAR(Os_Core3),
        /* .arch_ctx_cfg =         */
        {
            /* .stack_addr =       */ (OsStackAddrType)THREADSTACKVAR(CORE3_SHELL_CFG),
            /* .stack_size =       */ (OsStackSizeType)THREADSTACKSIZEVAR(CORE3_SHELL_CFG_STACK_SIZE),
            /* .entry_addr =       */ (os_context_entry_t)&os_task_core3_shell,
            /* .exit_addr =        */ (os_context_exit_t)NULL_PTR,
            /* .entry_param =      */ (os_context_entry_para_t)NULL_PTR,
        },
#if defined(CONFIG_RT_FRAMEWORK_MULTIAPP) && (CONFIG_RT_FRAMEWORK_MULTIAPP== 1)
        /* .app_owner_cfg =        */ &OSAPPCFGVAR(SystemApplication_Core3),
        /* .access_app_mask =      */ (RTFW_APPID2MASK(OS_CORE3_SYSTEMAPPLICATION_CORE3_ID)),
#endif /* #if defined(CONFIG_RT_FRAMEWORK_MULTIAPP) && (CONFIG_RT_FRAMEWORK_MULTIAPP== 1) */
        /* .initial_ctx_id =       */ OS_TASK_CONTEXT_ID,
#if defined(CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION) && (CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION == 1)
        /* .mpu_access_right =     */ &core3_shell_access_right,
#endif
    },
    /* .base_priority =            */ CORE3_SHELL_CFG_PRIORITY,
    /* .event_hdl =                */ &TASKEVENTOBJVAR(CORE3_SHELL_CFG),
#if defined(CONFIG_RT_FRAMEWORK_SHARE_TASK_STACK) && (CONFIG_RT_FRAMEWORK_SHARE_TASK_STACK == 1)
    /* .task_share_stack =         */ NULL_PTR,
#endif
    /* .task_id =                  */ OS_TASK_CORE3_SHELL_ID,
    /* .autostart_mode =           */ TRUE,
    /* .is_preemptive =            */ TRUE,
    /* .activation_limit =         */ 1,
};


#define OS_START_SEC_CONST
#include "rtfw_memmap.h"

CONSTP2CONST(os_task_cfg_t, OS_CONST, AUTOMATIC) systemapplication_core0_task_cfg_ref_table[] = {
    &TASKCFGVAR(OSTASK_5MS_CFG),
    &TASKCFGVAR(CORE0_SHELL_CFG),
    &TASKCFGVAR(OSTASK_10MS_CFG),
    &TASKCFGVAR(OSTASK_INIT_CFG),
};

CONST(OsObjIndexType, OS_CONST) systemapplication_core0_task_cfg_ref_table_size = NELEMENTS(systemapplication_core0_task_cfg_ref_table);

CONSTP2CONST(os_task_cfg_t, OS_CONST, AUTOMATIC) systemapplication_core1_task_cfg_ref_table[] = {
    &TASKCFGVAR(CORE1_SHELL_CFG),
};

CONST(OsObjIndexType, OS_CONST) systemapplication_core1_task_cfg_ref_table_size = NELEMENTS(systemapplication_core1_task_cfg_ref_table);

CONSTP2CONST(os_task_cfg_t, OS_CONST, AUTOMATIC) systemapplication_core2_task_cfg_ref_table[] = {
    &TASKCFGVAR(CORE2_SHELL_CFG),
};

CONST(OsObjIndexType, OS_CONST) systemapplication_core2_task_cfg_ref_table_size = NELEMENTS(systemapplication_core2_task_cfg_ref_table);

CONSTP2CONST(os_task_cfg_t, OS_CONST, AUTOMATIC) systemapplication_core3_task_cfg_ref_table[] = {
    &TASKCFGVAR(CORE3_SHELL_CFG),
};

CONST(OsObjIndexType, OS_CONST) systemapplication_core3_task_cfg_ref_table_size = NELEMENTS(systemapplication_core3_task_cfg_ref_table);

#define OS_STOP_SEC_CONST
#include "rtfw_memmap.h"

DeclareRtfwRefTable(OS_CONST_SECTION, task, OS_TASK_CNT) = {
    &TASKCFGVAR(OSTASK_5MS_CFG),
    &TASKCFGVAR(CORE0_SHELL_CFG),
    &TASKCFGVAR(OSTASK_10MS_CFG),
    &TASKCFGVAR(OSTASK_INIT_CFG),
    &TASKCFGVAR(CORE1_SHELL_CFG),
    &TASKCFGVAR(CORE2_SHELL_CFG),
    &TASKCFGVAR(CORE3_SHELL_CFG),
};
