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
 */

/* Including File */
#include "pdur.h"
#include "Os.h"
#if defined (VCOS_OS_CONFIG_SPINLOCK) && (VCOS_OS_CONFIG_SPINLOCK == 1)
#include "Spinlock_Cfg.h"
#endif
#include "pdur_evcfifo.h"
#include "Compiler.h"
#ifndef PDUR_EVCFIFO_EMPTY_SPINLOCK_ID
#define PDUR_EVCFIFO_EMPTY_SPINLOCK_ID
#endif
#ifndef PDUR_IFEVCFIFO_EMPTY_SPINLOCK_ID
#define PDUR_IFEVCFIFO_EMPTY_SPINLOCK_ID
#endif
#if (PDUR_MULTICORE_SUPPORT == STD_ON)

#define PDUR_START_SEC_CONST
#include "pdur_memmap.h"
static CONSTP2CONST(pdur_evc_fifo_desc_type, AUTOMATIC, PDUR_CONST) pdur_evc_fifo_desc_ref_table[PDUR_EVC_FIFO_CORE_MAX_NUM] = {
    NULL,
};
#define PDUR_STOP_SEC_CONST
#include "pdur_memmap.h"


#define PDUR_START_SEC_CONST
#include "pdur_memmap.h"
static CONSTP2CONST(pdur_evc_fifo_desc_type, AUTOMATIC, PDUR_CONST) pdur_if_evc_fifo_desc_ref_table[PDUR_IF_EVC_FIFO_CORE_MAX_NUM] = {
    NULL,
};
#define PDUR_STOP_SEC_CONST
#include "pdur_memmap.h"

#define PDUR_START_SEC_CODE
#include "pdur_memmap.h"
FUNC(const pdur_evc_fifo_desc_type * const *, PDUR_CODE) pdur_get_evc_fifo_desc_ref_table(void)
{
    return &pdur_evc_fifo_desc_ref_table[0];
}

FUNC(const pdur_evc_fifo_desc_type * const *, PDUR_CODE) pdur_get_if_evc_fifo_desc_ref_table(void)
{
    return &pdur_if_evc_fifo_desc_ref_table[0];
}
#define PDUR_STOP_SEC_CODE
#include "pdur_memmap.h"
#endif /* PDUR_MULTICORE_SUPPORT */
