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
 * @file        comm_cfg.h
 * @brief       ComM 配置头文件
 * @details     主要包含 ComM 动态配置项
 * @date        Generation Time : 2026-10-24 23:59:19
 * @toolversion Tool Version    : V0.1.0-DEV
 **********************************************************************************************************************/

#ifndef COMM_CFG_H
#define COMM_CFG_H

#include "comm_types.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* Global Macro Definition */
#define COMM_DEV_ERROR_DETECT                     (STD_OFF)
#define COMM_MODE_LIMITATION_ENABLED              (STD_OFF)
#define COMM_FULL_COM_MIN_DURATION_TIME         (5000u)


/* 不同通信频道/网络 */
#define COMM_NETWORK_HANDLE_ComMChannel_0          (0u)          ///< ComMChannel_0的网络管理
#define ComMConf_ComMChannel_ComMChannel_0          (0u)         ///< ComM管理ComMChannel_0通道

#define COMM_CHANNEL_COUNT                         (1u)             ///< ComM 通道数量

/*!*********************************************************************************************************************
 * @brief       不同通信用户
 **********************************************************************************************************************/
#define COMM_USER_HANDLE_ComMUser_0           ((ComM_UserHandleType)0u) ///< ComMUser_0的handle
#define ComMConf_ComMUser_ComMUser_0          (0u)                      ///< ComM管理ComMUser_0用户

#define COMM_USER_COUNT                           (1u)             ///< ComM 用户数量

#define COMM_START_SEC_CONST 
#include "comm_memmap.h"
extern CONST(comm_config_type, COMM_CONST) comm_config;
#define  COMM_STOP_SEC_CONST
#include "comm_memmap.h"

#ifdef __cplusplus
}
#endif

#endif /* COMM_CFG_H */