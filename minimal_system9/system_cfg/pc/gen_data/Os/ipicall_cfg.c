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
 * Generation Time : 2026-10-25 11:39:37
 * Project Name    : minimal_system9
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
DeclareIpicall(OS_CONST_SECTION, OS_GLOBAL_BSS_SECTION, OS_CORE0_IPICALL1) = {
  /* .instance =                */ &IPICALLOBJVAR(OS_CORE0_IPICALL1),
  /* .ipicall_id =              */ OS_CORE0_IPICALL1_ID,
  /* .src_core_id =             */ OS_CORE_ID_0,
  /* .target_core_id =          */ OS_CORE_ID_1,
  /* .service_ref =             */ os_ipicall_service_table
};
DeclareIpicall(OS_CONST_SECTION, OS_GLOBAL_BSS_SECTION, OS_CORE0_IPICALL2) = {
  /* .instance =                */ &IPICALLOBJVAR(OS_CORE0_IPICALL2),
  /* .ipicall_id =              */ OS_CORE0_IPICALL2_ID,
  /* .src_core_id =             */ OS_CORE_ID_0,
  /* .target_core_id =          */ OS_CORE_ID_2,
  /* .service_ref =             */ os_ipicall_service_table
};
DeclareIpicall(OS_CONST_SECTION, OS_GLOBAL_BSS_SECTION, OS_CORE0_IPICALL3) = {
  /* .instance =                */ &IPICALLOBJVAR(OS_CORE0_IPICALL3),
  /* .ipicall_id =              */ OS_CORE0_IPICALL3_ID,
  /* .src_core_id =             */ OS_CORE_ID_0,
  /* .target_core_id =          */ OS_CORE_ID_3,
  /* .service_ref =             */ os_ipicall_service_table
};
DeclareIpicall(OS_CONST_SECTION, OS_GLOBAL_BSS_SECTION, OS_CORE1_IPICALL0) = {
  /* .instance =                */ &IPICALLOBJVAR(OS_CORE1_IPICALL0),
  /* .ipicall_id =              */ OS_CORE1_IPICALL0_ID,
  /* .src_core_id =             */ OS_CORE_ID_1,
  /* .target_core_id =          */ OS_CORE_ID_0,
  /* .service_ref =             */ os_ipicall_service_table
};
DeclareIpicall(OS_CONST_SECTION, OS_GLOBAL_BSS_SECTION, OS_CORE1_IPICALL2) = {
  /* .instance =                */ &IPICALLOBJVAR(OS_CORE1_IPICALL2),
  /* .ipicall_id =              */ OS_CORE1_IPICALL2_ID,
  /* .src_core_id =             */ OS_CORE_ID_1,
  /* .target_core_id =          */ OS_CORE_ID_2,
  /* .service_ref =             */ os_ipicall_service_table
};
DeclareIpicall(OS_CONST_SECTION, OS_GLOBAL_BSS_SECTION, OS_CORE1_IPICALL3) = {
  /* .instance =                */ &IPICALLOBJVAR(OS_CORE1_IPICALL3),
  /* .ipicall_id =              */ OS_CORE1_IPICALL3_ID,
  /* .src_core_id =             */ OS_CORE_ID_1,
  /* .target_core_id =          */ OS_CORE_ID_3,
  /* .service_ref =             */ os_ipicall_service_table
};
DeclareIpicall(OS_CONST_SECTION, OS_GLOBAL_BSS_SECTION, OS_CORE2_IPICALL0) = {
  /* .instance =                */ &IPICALLOBJVAR(OS_CORE2_IPICALL0),
  /* .ipicall_id =              */ OS_CORE2_IPICALL0_ID,
  /* .src_core_id =             */ OS_CORE_ID_2,
  /* .target_core_id =          */ OS_CORE_ID_0,
  /* .service_ref =             */ os_ipicall_service_table
};
DeclareIpicall(OS_CONST_SECTION, OS_GLOBAL_BSS_SECTION, OS_CORE2_IPICALL1) = {
  /* .instance =                */ &IPICALLOBJVAR(OS_CORE2_IPICALL1),
  /* .ipicall_id =              */ OS_CORE2_IPICALL1_ID,
  /* .src_core_id =             */ OS_CORE_ID_2,
  /* .target_core_id =          */ OS_CORE_ID_1,
  /* .service_ref =             */ os_ipicall_service_table
};
DeclareIpicall(OS_CONST_SECTION, OS_GLOBAL_BSS_SECTION, OS_CORE2_IPICALL3) = {
  /* .instance =                */ &IPICALLOBJVAR(OS_CORE2_IPICALL3),
  /* .ipicall_id =              */ OS_CORE2_IPICALL3_ID,
  /* .src_core_id =             */ OS_CORE_ID_2,
  /* .target_core_id =          */ OS_CORE_ID_3,
  /* .service_ref =             */ os_ipicall_service_table
};
DeclareIpicall(OS_CONST_SECTION, OS_GLOBAL_BSS_SECTION, OS_CORE3_IPICALL0) = {
  /* .instance =                */ &IPICALLOBJVAR(OS_CORE3_IPICALL0),
  /* .ipicall_id =              */ OS_CORE3_IPICALL0_ID,
  /* .src_core_id =             */ OS_CORE_ID_3,
  /* .target_core_id =          */ OS_CORE_ID_0,
  /* .service_ref =             */ os_ipicall_service_table
};
DeclareIpicall(OS_CONST_SECTION, OS_GLOBAL_BSS_SECTION, OS_CORE3_IPICALL1) = {
  /* .instance =                */ &IPICALLOBJVAR(OS_CORE3_IPICALL1),
  /* .ipicall_id =              */ OS_CORE3_IPICALL1_ID,
  /* .src_core_id =             */ OS_CORE_ID_3,
  /* .target_core_id =          */ OS_CORE_ID_1,
  /* .service_ref =             */ os_ipicall_service_table
};
DeclareIpicall(OS_CONST_SECTION, OS_GLOBAL_BSS_SECTION, OS_CORE3_IPICALL2) = {
  /* .instance =                */ &IPICALLOBJVAR(OS_CORE3_IPICALL2),
  /* .ipicall_id =              */ OS_CORE3_IPICALL2_ID,
  /* .src_core_id =             */ OS_CORE_ID_3,
  /* .target_core_id =          */ OS_CORE_ID_2,
  /* .service_ref =             */ os_ipicall_service_table
};
#define OS_START_SEC_CONST
#include "rtfw_memmap.h"
CONSTP2CONST(os_ipicall_cfg_t, OS_CONST, AUTOMATIC) os_core0_ipicalls_cfg_ref_table[] =
{
    NULL_PTR,
    &OSIPICALLCFGVAR(OS_CORE0_IPICALL1),
    &OSIPICALLCFGVAR(OS_CORE0_IPICALL2),
    &OSIPICALLCFGVAR(OS_CORE0_IPICALL3),
    NULL_PTR,
    &OSIPICALLCFGVAR(OS_CORE1_IPICALL0),
    &OSIPICALLCFGVAR(OS_CORE2_IPICALL0),
    &OSIPICALLCFGVAR(OS_CORE3_IPICALL0),
};
CONST(OsObjIndexType, OS_CONST) os_core0_ipicalls_cfg_ref_table_size = (OsObjIndexType)NELEMENTS(os_core0_ipicalls_cfg_ref_table);
#define OS_STOP_SEC_CONST
#include "rtfw_memmap.h"
#define OS_START_SEC_CONST
#include "rtfw_memmap.h"
CONSTP2CONST(os_ipicall_cfg_t, OS_CONST, AUTOMATIC) os_core1_ipicalls_cfg_ref_table[] =
{
    &OSIPICALLCFGVAR(OS_CORE1_IPICALL0),
    NULL_PTR,
    &OSIPICALLCFGVAR(OS_CORE1_IPICALL2),
    &OSIPICALLCFGVAR(OS_CORE1_IPICALL3),
    &OSIPICALLCFGVAR(OS_CORE0_IPICALL1),
    NULL_PTR,
    &OSIPICALLCFGVAR(OS_CORE2_IPICALL1),
    &OSIPICALLCFGVAR(OS_CORE3_IPICALL1),
};
CONST(OsObjIndexType, OS_CONST) os_core1_ipicalls_cfg_ref_table_size = (OsObjIndexType)NELEMENTS(os_core1_ipicalls_cfg_ref_table);
#define OS_STOP_SEC_CONST
#include "rtfw_memmap.h"
#define OS_START_SEC_CONST
#include "rtfw_memmap.h"
CONSTP2CONST(os_ipicall_cfg_t, OS_CONST, AUTOMATIC) os_core2_ipicalls_cfg_ref_table[] =
{
    &OSIPICALLCFGVAR(OS_CORE2_IPICALL0),
    &OSIPICALLCFGVAR(OS_CORE2_IPICALL1),
    NULL_PTR,
    &OSIPICALLCFGVAR(OS_CORE2_IPICALL3),
    &OSIPICALLCFGVAR(OS_CORE0_IPICALL2),
    &OSIPICALLCFGVAR(OS_CORE1_IPICALL2),
    NULL_PTR,
    &OSIPICALLCFGVAR(OS_CORE3_IPICALL2),
};
CONST(OsObjIndexType, OS_CONST) os_core2_ipicalls_cfg_ref_table_size = (OsObjIndexType)NELEMENTS(os_core2_ipicalls_cfg_ref_table);
#define OS_STOP_SEC_CONST
#include "rtfw_memmap.h"
#define OS_START_SEC_CONST
#include "rtfw_memmap.h"
CONSTP2CONST(os_ipicall_cfg_t, OS_CONST, AUTOMATIC) os_core3_ipicalls_cfg_ref_table[] =
{
    &OSIPICALLCFGVAR(OS_CORE3_IPICALL0),
    &OSIPICALLCFGVAR(OS_CORE3_IPICALL1),
    &OSIPICALLCFGVAR(OS_CORE3_IPICALL2),
    NULL_PTR,
    &OSIPICALLCFGVAR(OS_CORE0_IPICALL3),
    &OSIPICALLCFGVAR(OS_CORE1_IPICALL3),
    &OSIPICALLCFGVAR(OS_CORE2_IPICALL3),
    NULL_PTR,
};
CONST(OsObjIndexType, OS_CONST) os_core3_ipicalls_cfg_ref_table_size = (OsObjIndexType)NELEMENTS(os_core3_ipicalls_cfg_ref_table);
#define OS_STOP_SEC_CONST
#include "rtfw_memmap.h"

DeclareRtfwRefTable(OS_CONST_SECTION, ipicall, OS_IPICALL_CNT) = {
    &OSIPICALLCFGVAR(OS_CORE0_IPICALL1),
    &OSIPICALLCFGVAR(OS_CORE0_IPICALL2),
    &OSIPICALLCFGVAR(OS_CORE0_IPICALL3),
    &OSIPICALLCFGVAR(OS_CORE1_IPICALL0),
    &OSIPICALLCFGVAR(OS_CORE1_IPICALL2),
    &OSIPICALLCFGVAR(OS_CORE1_IPICALL3),
    &OSIPICALLCFGVAR(OS_CORE2_IPICALL0),
    &OSIPICALLCFGVAR(OS_CORE2_IPICALL1),
    &OSIPICALLCFGVAR(OS_CORE2_IPICALL3),
    &OSIPICALLCFGVAR(OS_CORE3_IPICALL0),
    &OSIPICALLCFGVAR(OS_CORE3_IPICALL1),
    &OSIPICALLCFGVAR(OS_CORE3_IPICALL2),
};