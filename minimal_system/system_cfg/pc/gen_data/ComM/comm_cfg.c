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
 * Description:  ComM 配置源文件.
 */

/* Including File */
#include "comm.h"
#include "comm_internal.h"
#include "SchM_ComM.h"

/* Global Variable Definition */

#define   COMM_START_SEC_CODE
#include "comm_memmap.h"

/* 所有通信通道整体主函数 */
FUNC(void, COMM_CODE) ComM_MainFunction_All_Channels(void)
{
    comm_main_function(ComMConf_ComMChannel_CAN1);
}

/* 不同通信通道的主函数 */
FUNC(void, COMM_CODE) ComM_MainFunction_CAN1(void)
{
    comm_main_function(ComMConf_ComMChannel_CAN1);
}
#define   COMM_STOP_SEC_CODE
#include "comm_memmap.h"