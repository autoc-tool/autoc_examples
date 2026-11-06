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
 * Description: ISR Configuration
 * AutoGenerate Code, DO NOT EDIT!!!
 * Generation Time : 2026-10-25 11:39:37
 * Project Name    : minimal_system9
 * Tool Version    : V0.1.0-DEV
 */

/* Including File */
#include <nuttx/config.h>
#include "isr_cfg.h"
#include "rtfw_context_types.h"
#include "rtfw_core.h"
#include "core_cfg.h"
#include "application_cfg.h"
#include "rtfw_compiler_cfg.h"
#include "rtfw_counter.h"
#include "counter_cfg.h"
#if defined(CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION) && (CONFIG_RT_FRAMEWORK_MEMORY_PROTECTION == 1)
#include "memory_protection_cfg.h"
#endif

#define OS_START_SEC_CONST
#include "rtfw_memmap.h"

#define OS_STOP_SEC_CONST
#include "rtfw_memmap.h"

DeclareRtfwRefTable(OS_CONST_SECTION, isr, OS_ISR_CNT) = {
};