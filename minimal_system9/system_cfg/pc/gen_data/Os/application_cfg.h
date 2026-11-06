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
 * Description: Os Application Configuration
 * AutoGenerate Code, DO NOT EDIT!!!
 * Generation Time : 2026-10-25 11:39:37
 * Project Name    : minimal_system9
 * Tool Version    : V0.1.0-DEV
 */

#ifndef RT_FRAMEWORK_INC_OS_APPLICATION_CFG_H
#define RT_FRAMEWORK_INC_OS_APPLICATION_CFG_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Including File */
#include "rtfw_application.h"

/* global Macro Definition */

/* global Enumeration Definition */
typedef enum {
    OS_CORE0_SYSTEMAPPLICATION_CORE0_ID,
    OS_CORE1_SYSTEMAPPLICATION_CORE1_ID,
    OS_CORE2_SYSTEMAPPLICATION_CORE2_ID,
    OS_CORE3_SYSTEMAPPLICATION_CORE3_ID,
    OS_APPLICATION_CNT,
} OS_APPLICATIONID_DEF;

#define OS_START_SEC_CONST
#include "rtfw_memmap.h"

extern const os_app_cfg_t OSAPPCFGVAR(SystemApplication_Core0);
extern const os_app_cfg_t OSAPPCFGVAR(SystemApplication_Core1);
extern const os_app_cfg_t OSAPPCFGVAR(SystemApplication_Core2);
extern const os_app_cfg_t OSAPPCFGVAR(SystemApplication_Core3);

/* Os_Core0 config referenc table */
extern CONSTP2CONST(os_app_cfg_t, OS_CONST, AUTOMATIC) os_core0_apps_cfg_ref_table[];
extern CONST(OsObjIndexType, OS_CONST) os_core0_apps_cfg_ref_table_size;

/* Os_Core1 config referenc table */
extern CONSTP2CONST(os_app_cfg_t, OS_CONST, AUTOMATIC) os_core1_apps_cfg_ref_table[];
extern CONST(OsObjIndexType, OS_CONST) os_core1_apps_cfg_ref_table_size;

/* Os_Core2 config referenc table */
extern CONSTP2CONST(os_app_cfg_t, OS_CONST, AUTOMATIC) os_core2_apps_cfg_ref_table[];
extern CONST(OsObjIndexType, OS_CONST) os_core2_apps_cfg_ref_table_size;

/* Os_Core3 config referenc table */
extern CONSTP2CONST(os_app_cfg_t, OS_CONST, AUTOMATIC) os_core3_apps_cfg_ref_table[];
extern CONST(OsObjIndexType, OS_CONST) os_core3_apps_cfg_ref_table_size;

#define OS_STOP_SEC_CONST
#include "rtfw_memmap.h"

#ifdef __cplusplus
}
#endif

#endif	 /* RT_FRAMEWORK_INC_OS_APPLICATION_CFG_H */
