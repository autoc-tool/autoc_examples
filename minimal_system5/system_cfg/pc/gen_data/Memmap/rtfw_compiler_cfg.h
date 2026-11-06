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
 * Description: Memmap Section Configuration
 * AutoGenerate Code, DO NOT EDIT!!!
 * Generation Time : 2026-10-19 20:10:13
 * Project Name    : nm_demo
 * Tool Version    : V0.1.0-DEV
 */

#ifndef RT_FRAMEWORK_INC_OS_COMPILER_CFG_H
#define RT_FRAMEWORK_INC_OS_COMPILER_CFG_H


/*---------------------------global sections--------------------------------*/
#define OS_CODE_SECTION ".text.code.all_apps.fw"
#define OS_CONST_SECTION ".rodata.const.all_apps.fw"
#define OS_GLOBAL_BSS_SECTION ".bss.multi_app_share.all_apps.fw"
#define OS_GLOBAL_DATA_SECTION ".data.multi_app_share.all_apps.fw"


/*------------------------Core Shared Varibles-----------------------*/
#define OS_CORE0_BSS_SECTION ".bss.multi_app_share.core0_apps.fw"
#define OS_CORE0_DATA_SECTION ".data.multi_app_share.core0_apps.fw"
#define OS_CORE1_BSS_SECTION ".bss.multi_app_share.core1_apps.fw"
#define OS_CORE1_DATA_SECTION ".data.multi_app_share.core1_apps.fw"
#define OS_CORE2_BSS_SECTION ".bss.multi_app_share.core2_apps.fw"
#define OS_CORE2_DATA_SECTION ".data.multi_app_share.core2_apps.fw"
#define OS_CORE3_BSS_SECTION ".bss.multi_app_share.core3_apps.fw"
#define OS_CORE3_DATA_SECTION ".data.multi_app_share.core3_apps.fw"


/*------------------------APP Variables-----------------------*/
#define OS_SYSTEMAPPLICATION_CORE0_BSS_SECTION ".bss.private.systemapplication_core0.fw"
#define OS_SYSTEMAPPLICATION_CORE0_DATA_SECTION ".data.private.systemapplication_core0.fw"
#define OS_SYSTEMAPPLICATION_CORE1_BSS_SECTION ".bss.private.systemapplication_core1.fw"
#define OS_SYSTEMAPPLICATION_CORE1_DATA_SECTION ".data.private.systemapplication_core1.fw"
#define OS_SYSTEMAPPLICATION_CORE2_BSS_SECTION ".bss.private.systemapplication_core2.fw"
#define OS_SYSTEMAPPLICATION_CORE2_DATA_SECTION ".data.private.systemapplication_core2.fw"
#define OS_SYSTEMAPPLICATION_CORE3_BSS_SECTION ".bss.private.systemapplication_core3.fw"
#define OS_SYSTEMAPPLICATION_CORE3_DATA_SECTION ".data.private.systemapplication_core3.fw"


/*------------------------stacks Variables-----------------------*/
#define OS_CORE0_INIT_STACK_SECTION ".bss.core0_stack.core0_init.fw"
#define OS_CORE0_SHELL_STACK_SECTION ".bss.core0_stack.core0_shell.fw"
#define OS_DEFAULT_TCPIP_TASK_STACK_SECTION ".bss.core0_stack.default_tcpip_task.fw"
#define OS_CORE0_DEMO_TASK_1MS_STACK_SECTION ".bss.core0_stack.core0_demo_task_1ms.fw"
#define OS_CORE0_DEMO_TASK_5MS_STACK_SECTION ".bss.core0_stack.core0_demo_task_5ms.fw"
#define OS_CORE0_DEMO_TASK_10MS_STACK_SECTION ".bss.core0_stack.core0_demo_task_10ms.fw"
#define OS_CORE1_INIT_STACK_SECTION ".bss.core1_stack.core1_init.fw"
#define OS_CORE1_SHELL_STACK_SECTION ".bss.core1_stack.core1_shell.fw"
#define OS_CORE1_BSWAPP_TASK_1MS_STACK_SECTION ".bss.core1_stack.core1_bswapp_task_1ms.fw"
#define OS_CORE1_BSWAPP_TASK_5MS_STACK_SECTION ".bss.core1_stack.core1_bswapp_task_5ms.fw"
#define OS_CORE1_BSWAPP_TASK_10MS_STACK_SECTION ".bss.core1_stack.core1_bswapp_task_10ms.fw"
#define OS_CORE2_INIT_STACK_SECTION ".bss.core2_stack.core2_init.fw"
#define OS_CORE2_SHELL_STACK_SECTION ".bss.core2_stack.core2_shell.fw"
#define OS_CORE2_BSW_TASK_1MS_STACK_SECTION ".bss.core2_stack.core2_bsw_task_1ms.fw"
#define OS_CORE2_BSW_TASK_5MS_STACK_SECTION ".bss.core2_stack.core2_bsw_task_5ms.fw"
#define OS_CORE2_BSW_TASK_10MS_STACK_SECTION ".bss.core2_stack.core2_bsw_task_10ms.fw"
#define OS_CORE3_INIT_STACK_SECTION ".bss.core3_stack.core3_init.fw"
#define OS_CORE3_SHELL_STACK_SECTION ".bss.core3_stack.core3_shell.fw"
#define OS_CORE3_BSW_TASK_1MS_STACK_SECTION ".bss.core3_stack.core3_bsw_task_1ms.fw"
#define OS_CORE3_BSW_TASK_5MS_STACK_SECTION ".bss.core3_stack.core3_bsw_task_5ms.fw"
#define OS_CORE3_BSW_TASK_10MS_STACK_SECTION ".bss.core3_stack.core3_bsw_task_10ms.fw"






/* ms4 PC harness: stack sections for OsTask_* (borrowed Memmap lacked these names) */
#define OS_OSTASK_INIT_STACK_SECTION  ".bss.core0_stack.ostask_init.fw"
#define OS_OSTASK_10MS_STACK_SECTION  ".bss.core0_stack.ostask_10ms.fw"
#define OS_OSTASK_100MS_STACK_SECTION ".bss.core0_stack.ostask_100ms.fw"

#endif	 /* RT_FRAMEWORK_INC_OS_COMPILER_CFG_H */
