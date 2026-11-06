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
 * Description: task Stack Configuration
 * AutoGenerate Code, DO NOT EDIT!!!
 * Generation Time : 2026-10-26 10:16:14
 * Project Name    : minimal_system
 * Tool Version    : V0.1.0-DEV
 */

#ifndef RT_FRAMEWORK_INC_OS_STACK_CFG_H
#define RT_FRAMEWORK_INC_OS_STACK_CFG_H

#ifdef __cplusplus
extern "C"
{
#endif

/* global Macro Definition */


#define CORE0_SHELL_CFG_STACK_SIZE         (4096U)

#define CORE0_SHELL_CFG_PRIORITY           (10U)


#define CORE1_SHELL_CFG_STACK_SIZE         (4096U)

#define CORE1_SHELL_CFG_PRIORITY           (10U)


#define CORE2_SHELL_CFG_STACK_SIZE         (4096U)

#define CORE2_SHELL_CFG_PRIORITY           (5U)


#define CORE3_SHELL_CFG_STACK_SIZE         (4096U)

#define CORE3_SHELL_CFG_PRIORITY           (5U)


#define OSTASK_INIT_CFG_STACK_SIZE         (8192U)

#define OSTASK_INIT_CFG_PRIORITY           (30U)


#define OSTASK_5MS_CFG_STACK_SIZE         (4096U)

#define OSTASK_5MS_CFG_PRIORITY           (20U)


#define OSTASK_10MS_CFG_STACK_SIZE         (8192U)

#define OSTASK_10MS_CFG_PRIORITY           (15U)


#ifdef __cplusplus
}
#endif

#endif /* RT_FRAMEWORK_INC_OS_STACK_CFG_H */
