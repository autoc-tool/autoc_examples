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
 * Description: Counter Configuration
 * AutoGenerate Code, DO NOT EDIT!!!
 * Generation Time : 2026-10-24 23:59:27
 * Project Name    : minimal_system5
 * Tool Version    : V0.1.0-DEV
 */

#ifndef COUNTER_CFG_H
#define COUNTER_CFG_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Including File */
#include <nuttx/config.h>
#include "rtfw_counter.h"

/* global Macro Definition */
#define OS_MS2TICKS_OSCOUNTER_SYSTEM(ms)    ((ms) * 1U)

/* global Enumeration Definition */
typedef enum
{
    OsCounter_System,
    OS_COUNTER_CNT,
} OS_COUNTER_DEF;

/* global Variable Declaration */
extern const os_counter_cfg_t COUNTERCFGVAR(OsCounter_System_cfg);
#define OS_START_SEC_CONST
#include "rtfw_memmap.h"
extern CONSTP2CONST(os_counter_cfg_t, OS_CONST, AUTOMATIC) systemapplication_core0_counter_cfg_ref_table[];
extern CONST(OsObjIndexType, OS_CONST) systemapplication_core0_counter_cfg_ref_table_size;
#define OS_STOP_SEC_CONST
#include "rtfw_memmap.h"

#ifdef __cplusplus
}
#endif

#endif	 /* COUNTER_CFG_H */