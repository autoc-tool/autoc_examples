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
 * Generation Time : 2026-10-24 23:59:26
 * Project Name    : minimal_system5
 * Tool Version    : V0.1.0-DEV
 */

#ifndef RT_FRAMEWORK_INC_OS_ISR_CFG_H
#define RT_FRAMEWORK_INC_OS_ISR_CFG_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Including File */
#include "rtfw_isr.h"

/* global Macro Definition */

/* global Enumeration Definition */

typedef enum {
    OS_ISRHWSRC_CNT,
} OS_ISRHWSRC_DEF;

typedef enum {
    OS_ISR_CNT
} OS_ISRID_DEF;

/* global type & Structure Definition */

/* global Variable Declaration */

#define OS_START_SEC_CONST
#include "rtfw_memmap.h"

#define OS_STOP_SEC_CONST
#include "rtfw_memmap.h"

/* global Function Declaration */

/* global Function Implementation */

#ifdef __cplusplus
}
#endif

#endif	 /* RT_FRAMEWORK_INC_OS_ISR_CFG_H */
