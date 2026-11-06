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
 * Description: Os IpiCall Configuration
 * AutoGenerate Code, DO NOT EDIT!!!
 * Generation Time : 2026-10-24 23:59:26
 * Project Name    : minimal_system5
 * Tool Version    : V0.1.0-DEV
 */

/* Including File */
#include <nuttx/config.h>
#include "rtfw_ipicall.h"
#include "ipicall_cfg.h"
#include "rtfw_core.h"
#include "core_cfg.h"
#include "rtfw_compiler_cfg.h"

#define OS_START_SEC_CONST
#include "rtfw_memmap.h"
extern CONST(os_ipicall_service_t, OS_CONST) os_ipicall_service_table[];
#define OS_STOP_SEC_CONST
#include "rtfw_memmap.h"
#define OS_START_SEC_CONST
#include "rtfw_memmap.h"
CONSTP2CONST(os_ipicall_cfg_t, OS_CONST, AUTOMATIC) os_core0_ipicalls_cfg_ref_table[] =
{
    NULL_PTR,
    NULL_PTR,
};
CONST(OsObjIndexType, OS_CONST) os_core0_ipicalls_cfg_ref_table_size = (OsObjIndexType)NELEMENTS(os_core0_ipicalls_cfg_ref_table);
#define OS_STOP_SEC_CONST
#include "rtfw_memmap.h"

DeclareRtfwRefTable(OS_CONST_SECTION, ipicall, OS_IPICALL_CNT) = {
};