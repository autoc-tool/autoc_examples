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
#include "pdur_cfg.h"
#include "pdur_bufferpoolcfg.h"
#include "Compiler.h"

/* Global Variable Definition */
#define PDUR_START_SEC_CONST
#include "pdur_memmap.h"
static const OS_ISRID_DEF pdur_interrupt_service_routine_table[PDUR_ISR_TABLE_LEN] = {
    OS_ISR_CNT,
};
#define PDUR_STOP_SEC_CONST
#include "pdur_memmap.h"

#define PDUR_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#include "pdur_memmap.h"
static pdur_src_pdu_id_mapping_struct_type const * pdur_src_pdu_id_mapping_table_ptr = NULL;
static pdur_dest_pdu_id_mapping_struct_type const * pdur_dest_pdu_id_mapping_table_ptr = NULL;
#define PDUR_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#include "pdur_memmap.h"

#define PDUR_START_SEC_CODE
#include "pdur_memmap.h"
FUNC_P2CONST(OS_ISRID_DEF, AUTOMATIC, PDUR_CODE) pdur_get_isr_table(void)
{
    return &pdur_interrupt_service_routine_table[0];
}
#define PDUR_STOP_SEC_CODE
#include "pdur_memmap.h"

#define PDUR_START_SEC_CODE
#include "pdur_memmap.h"
FUNC(uint8, PDUR_CODE) pdur_get_isr_table_len(void)
{
    return PDUR_ISR_TABLE_LEN;
}
#define PDUR_STOP_SEC_CODE
#include "pdur_memmap.h"


#define PDUR_START_SEC_CODE
#include "pdur_memmap.h"
FUNC(void, PDUR_CODE) pdur_set_src_pdu_id_mapping(const pdur_src_pdu_id_mapping_struct_type* table_ptr)
{
    pdur_src_pdu_id_mapping_table_ptr = table_ptr;
    return;
}

FUNC(void, PDUR_CODE) pdur_set_dest_pdu_id_mapping(const pdur_dest_pdu_id_mapping_struct_type* table_ptr)
{
    pdur_dest_pdu_id_mapping_table_ptr = table_ptr;
    return;
}

FUNC_P2CONST(pdur_src_pdu_id_mapping_struct_type, AUTOMATIC, PDUR_CODE) pdur_get_src_pdu_id_mapping(void)
{
    return pdur_src_pdu_id_mapping_table_ptr;
}

FUNC_P2CONST(pdur_dest_pdu_id_mapping_struct_type, AUTOMATIC, PDUR_CODE) pdur_get_dest_pdu_id_mapping(void)
{
    return pdur_dest_pdu_id_mapping_table_ptr;
}
#define PDUR_STOP_SEC_CODE
#include "pdur_memmap.h"

