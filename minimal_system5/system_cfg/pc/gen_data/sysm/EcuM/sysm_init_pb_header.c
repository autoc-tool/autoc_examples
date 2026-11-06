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
/*!*********************************************************************************************************************
 * @file		sysm_init_pb_header.c
 * @brief	   	sysm_init PostBuild 部分配置源文件.
 * @date		Generation Time : 2026-10-24 23:59:22
 * @project	 	Project Name    : minimal_system5
 * @toolversion Tool Version    : V0.1.0-DEV
 **********************************************************************************************************************/

/* Including File */
#include "sysm_init_pb_types.h"
#include "precompiled_data_hash.h"

/* Local Variable Definition */

#define  ECUM_START_SEC_CONST
#include "ecum_memmap.h"
// coverity[misra_c_2012_rule_8_5_violation:SUPPRESS]
extern CONST(bswm_config_type, ECUM_CONST) bswm_config;
// coverity[misra_c_2012_rule_8_5_violation:SUPPRESS]
extern CONST(canif_config_type, ECUM_CONST) canif_config;
// coverity[misra_c_2012_rule_8_5_violation:SUPPRESS]
extern CONST(com_config_type, ECUM_CONST) com_configuration;
// coverity[misra_c_2012_rule_8_5_violation:SUPPRESS]
extern CONST(comm_config_type, ECUM_CONST) comm_config;
// coverity[misra_c_2012_rule_8_5_violation:SUPPRESS]
extern CONST(pdur_pb_config_type, ECUM_CONST) pdur_config;

/* Local Type & Structure Definition */

CONST(postbuild_config_t, ECUM_CONST) postbuild_config = {
	.start_pattern = 0x5A5A5A5A,
	.post_build_variant = 1,
	.pre_compile_hash_low = PRE_COMPILED_DATA_HASH_LOW,
	.pre_compile_hash_high = PRE_COMPILED_DATA_HASH_HIGH,
	.bswm_config_ptr = &bswm_config,
	.canif_config_ptr = &canif_config,
	.com_config_ptr = &com_configuration,
	.comm_config_ptr = &comm_config,
	.pdur_config_ptr = &pdur_config,
};

#define ECUM_STOP_SEC_CONST
#include "ecum_memmap.h"