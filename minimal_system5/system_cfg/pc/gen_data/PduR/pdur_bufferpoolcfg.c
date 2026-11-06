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
 * Generation Time : 2026-10-24 23:59:11
 * Project Name    : minimal_system5
 * Tool Version    : V0.1.0-DEV
 */

/* Including File */
#include "pdur.h"
#if defined (VCOS_OS_CONFIG_SPINLOCK) && (VCOS_OS_CONFIG_SPINLOCK == 1)
#include "Os.h"
#include "Spinlock_Cfg.h"
#endif
#include "pdur_bufferpoolcfg.h"
#include "Compiler.h"


#define PDUR_BUFFER_POOL_NUM 0u // BufferPool的总数
#define PDUR_BUFFER_BLOCK_NUM 0u // BufferPool中所有的BufferBlock的总数
#define PDUR_TX_BUFFER_NUM 0 // TxBuffer的总数


#define PDUR_START_SEC_MULTI_APP_DATA
#include "pdur_memmap.h"
/* 被使用的BufferManager的管理链表 */
static VAR(pdur_buffer_manager_header_type, PDUR_MULTI_APP_DATA) pdur_buffer_manager_busy_list = {
#if defined (VCOS_OS_CONFIG_SPINLOCK) && (VCOS_OS_CONFIG_SPINLOCK == 1)
    .spinlock_id = (SpinlockIdType)PDUR_BUFFER_MANAGER_BUSYLIST_SPINLOCK_ID,
#endif
    .block_length = PDUR_BUFFER_LENGTH_INVALID,
    .head_node_idx = PDUR_BUFFER_BLOCK_NUM,
};
#define PDUR_STOP_SEC_MULTI_APP_DATA
#include "pdur_memmap.h"



#define PDUR_START_SEC_CODE
#include "pdur_memmap.h"
FUNC_P2VAR(pdur_buffer_manager_header_type, AUTOMATIC, PDUR_CODE) pdur_get_buffer_manager_busy_header_addr(void)
{
    return &pdur_buffer_manager_busy_list;
}
FUNC_P2VAR(pdur_buffer_manager_header_type, AUTOMATIC, PDUR_CODE) pdur_get_buffer_manager_header_list_addr(void)
{
    return NULL;
}

FUNC_P2VAR(pdur_buffer_manager_type, AUTOMATIC, PDUR_CODE) pdur_get_buffer_manager_list_addr(void)
{
    return NULL;
}

FUNC(uint8, PDUR_CODE) pdur_get_buffer_manager_header_len(void)
{
    return 0u;
}

FUNC(uint8, PDUR_CODE) pdur_get_buffer_manager_len(void)
{
    return 0u;
}
FUNC_P2VAR(pdur_buffer_manager_type, AUTOMATIC, PDUR_CODE) pdur_get_tx_buffer_manager_list_addr(void)
{
    return NULL;
}

FUNC(uint8, PDUR_CODE) pdur_get_tx_buffer_manager_len(void)
{
    return 0u;
}
#define PDUR_STOP_SEC_CODE
#include "pdur_memmap.h"
