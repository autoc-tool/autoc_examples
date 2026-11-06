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
 * Generation Time : 2026-10-26 10:16:14
 * Project Name    : minimal_system
 * Tool Version    : V0.1.0-DEV
 * Description:  ComM PostBuild 配置源文件.
 */

/* Including File */
#include "comm.h"
#include "comm_cfg.h"
#if defined (VCOS_MODULE_CONFIG_RTE) && (VCOS_MODULE_CONFIG_RTE == 1)
#if defined(USE_RTE)
#include "Rte_ComM.h"
#endif
#endif

/* Local Type & Structure Definition */
#define COMM_START_SEC_CONST 
#include "comm_memmap.h"

/* 不同ComM 通信频道 */
static SECTION_POSTBUILD_DATA CONST(comm_channel_config_type, COMM_CONST) comm_channels[COMM_CHANNEL_COUNT] = {
    {
        .bus_type = COMM_BUS_TYPE_CAN,
        .comm_channel = 0,
        .nm_channel = COMM_NETWORK_HANDLE_CAN1,
        .nm_variant = COMM_NM_VARIANT_FULL,
        .main_func_period = 10,
    },
};


static SECTION_POSTBUILD_DATA CONSTP2CONST(comm_channel_config_type, AUTOMATIC, COMM_CONST)  ComM_ComMUser_ComMUser_0_Channels[] = {
    &comm_channels[ComMConf_ComMChannel_CAN1],
};

/* 不同ComM 用户 */
static SECTION_POSTBUILD_DATA CONST(comm_user_config_type, COMM_CONST) comm_users[COMM_USER_COUNT] = {
    {
        /* @req ComM995 */
        .channel_num = 1,
        .channels = ComM_ComMUser_ComMUser_0_Channels,
    },
};

/* ComM 配置数据 */
SECTION_POSTBUILD_DATA CONST(comm_config_type, COMM_CONST) comm_config = {
    .channels = comm_channels,
    .users = comm_users,
};
#define  COMM_STOP_SEC_CONST
#include "comm_memmap.h"