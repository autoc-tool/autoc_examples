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
 * Description: Counter Configuration.
 * AutoGenerate Code, DO NOT EDIT!!!
 * Generation Time : 2026-10-25 11:39:37
 * Project Name    : minimal_system9
 * Tool Version    : V0.1.0-DEV
 */

/* Including File */
#include <nuttx/config.h>
#include "rtfw_counter.h"
#include "counter_cfg.h"
#include "application_cfg.h"
#include "isr_cfg.h"
#include "rtfw_compiler_cfg.h"
DeclareCounter(OS_CONST_SECTION, OS_SYSTEMAPPLICATION_CORE0_BSS_SECTION, OsCounter_0_cfg, 4) = {
    /* .obj_desc =               */ &COUNTEROBJVAR(OsCounter_0_cfg),
    /* .action_queue =           */ COUNTERACTIONQUEUE(OsCounter_0_cfg),
    /* .queue_total_size =       */ 4u,
    /* .counter_id =             */ OsCounter_0,
    /* .counter_name =           */ "OsCounter_0",
    /* .max_allowed_value =      */ 2147483647uL,
    /* .tick_per_base =          */ 1uL,
    /* .min_cycle =              */ 1uL,
    /* .ticks_per_ms =           */ 1uL,
    /* .timer_type =             */ TIMERTYPE_SOFTWARE,
#if defined(CONFIG_RT_FRAMEWORK_MULTIAPP) && (CONFIG_RT_FRAMEWORK_MULTIAPP== 1)
    /* .owner_app_id =           */ OS_CORE0_SYSTEMAPPLICATION_CORE0_ID,
    /* .access_app_mask =        */ (RTFW_APPID2MASK(OS_CORE0_SYSTEMAPPLICATION_CORE0_ID)),
#endif
};

/* Counter table Declaration */

#define OS_START_SEC_CONST
#include "rtfw_memmap.h"

CONSTP2CONST(os_counter_cfg_t, OS_CONST, AUTOMATIC) systemapplication_core0_counter_cfg_ref_table[] = {
    (os_counter_cfg_t*) &COUNTERCFGVAR(OsCounter_0_cfg),
};

CONST(OsObjIndexType, OS_CONST) systemapplication_core0_counter_cfg_ref_table_size = (OsObjIndexType)NELEMENTS(systemapplication_core0_counter_cfg_ref_table);

CONSTP2CONST(os_counter_cfg_t, OS_CONST, AUTOMATIC) os_counter_cfg_ref_table[] = {
    (os_counter_cfg_t*) &COUNTERCFGVAR(OsCounter_0_cfg),
};

CONST(OsObjIndexType, OS_CONST) os_counter_cfg_ref_table_size = OS_COUNTER_CNT;
#define OS_STOP_SEC_CONST
#include "rtfw_memmap.h"