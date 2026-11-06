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
 * Description: Spinlock Configuration.
 * AutoGenerate Code, DO NOT EDIT!!!
 * Generation Time : 2026-10-24 23:59:27
 * Project Name    : minimal_system5
 * Tool Version    : V0.1.0-DEV
 */

/* Including File */
#include <nuttx/config.h>
#include "spinlock_cfg.h"
#include "rtfw_spinlock.h"
#include "rtfw_application.h"
#include "application_cfg.h"
#include "rtfw_compiler_cfg.h"

#if defined(CONFIG_RT_FRAMEWORK_SPINLOCK) && (CONFIG_RT_FRAMEWORK_SPINLOCK == 1)

DeclareRtfwRefTable(OS_CONST_SECTION, spinlock, OS_SPINLOCK_CNT) = {
};

#endif /* (CONFIG_RT_FRAMEWORK_SPINLOCK == 1) */
