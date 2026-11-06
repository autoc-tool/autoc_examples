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
 * @file        os_task_init.c
 * @brief       OsTask_Init body for the PC_Common / mcal_pc harness
 * @details     Brings up the BSW stack (Can -> CanIf -> PduR -> Com -> SchM -> Rte)
 *              and then keeps the Os software counter OsCounter_0 running in
 *              1 ms steps, which is what advances SchTbl_5ms / SchTbl_10ms and
 *              therefore OsTask_5ms (BSW main functions) and OsTask_10ms
 *              (MinimalSystem_10ms + IoHwAb_10ms).
 *
 *              The generated Os configuration uses a TIMERTYPE_SOFTWARE counter
 *              and the PC board does not deliver a counter tick to the Os, so
 *              the init task is the counter source (same role as the manual
 *              SetEvent loop of the minimal_system8 harness).
 **********************************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#include "Os.h"
#include "Can.h"
#include "canif.h"
#include "pdur.h"
#include "com.h"
#include "Rte_Main.h"
#include "counter_cfg.h"
#include "task_cfg.h"
#include "MinimalSystem.h"

extern const Can_ConfigType Can_Config;
extern const canif_config_type canif_config;
extern const pdur_pb_config_type pdur_config;
extern const com_config_type com_configuration;

volatile unsigned g_bsw_inited;
volatile unsigned g_can_ready;
volatile unsigned g_rte_started;

/* Catch-up bound for the 1 ms counter loop (a long stall must not flood the
 * Os schedule tables) */
#define OS_TASK_INIT_MAX_CATCHUP_MS (100u)

static uint32 os_task_init_monotonic_ms(void)
{
    struct timespec now;

    (void)clock_gettime(CLOCK_MONOTONIC, &now);

    return (uint32)(((uint32)now.tv_sec * 1000u) + ((uint32)now.tv_nsec / 1000000u));
}

/* Advance OsCounter_0 once per elapsed millisecond: the schedule tables
 * SchTbl_5ms / SchTbl_10ms activate OsTask_5ms / OsTask_10ms on expiry. */
static void os_task_init_drive_counter(uint32 now_ms, uint32 *last_ms)
{
    uint32 elapsed = (uint32)(now_ms - *last_ms);

    if (elapsed > OS_TASK_INIT_MAX_CATCHUP_MS) {
        elapsed = OS_TASK_INIT_MAX_CATCHUP_MS;
    }

    while (elapsed > 0u) {
        (void)IncrementCounter((CounterType)OsCounter_0);
        elapsed--;
    }

    *last_ms = now_ms;
}

void os_task_ostask_init(void *arg)
{
    Can_ControllerStateType mode = CAN_CS_UNINIT;
    com_ipg_vec ipg;
    Std_ReturnType st;
    uint32 last_ms;
    (void)arg;

    printf("[Init] OsTask_Init: Can->CanIf->PduR->Com->SchM->Rte (mcal_pc)\n");

    /* ---- MCAL / BSW initialisation (SYS-INI-001) ---- */
    Can_Init(&Can_Config);
    canif_init(&canif_config);
    pdur_init(&pdur_config);
    com_init(&com_configuration);

    st = canif_set_controller_mode(0u, CAN_CS_STARTED);
    printf("[Init] canif_set_controller_mode(STARTED) -> %u\n", (unsigned)st);
    st = canif_set_pdu_mode(0u, CANIF_ONLINE);
    printf("[Init] canif_set_pdu_mode(ONLINE) -> %u\n", (unsigned)st);

    if (Can_GetControllerMode(0u, &mode) == E_OK) {
        g_can_ready = (mode == CAN_CS_STARTED) ? 1u : 0u;
        printf("[Init] Can mode=%u (STARTED=%u)\n", (unsigned)mode, (unsigned)CAN_CS_STARTED);
    }

    memset(ipg, 0, sizeof(ipg));
    com_set_ipdu_group(ipg, ComConf_ComIPduGroup_ComTxGroup, TRUE);
    com_set_ipdu_group(ipg, ComConf_ComIPduGroup_ComRxGroup, TRUE);
    com_ipdu_group_control(ipg, TRUE);
    g_bsw_inited = 1u;

    /* Seed the SWC state before the RTE activates OsTask_10ms */
    MinimalSystem_Init();

    SchM_Init();
    if (Rte_Start() == RTE_E_OK) {
        g_rte_started = 1u;
        printf("[Init] Rte_Start OK\n");
    }

    last_ms = os_task_init_monotonic_ms();
    printf("[Init] done: can_ready=%u rte=%u\n", (unsigned)g_can_ready, (unsigned)g_rte_started);

    for (;;) {
        /* OsCounter_0 drives SchTbl_5ms / SchTbl_10ms; Can polling runs in
         * IoHwAb_10ms (OsTask_10ms). */
        os_task_init_drive_counter(os_task_init_monotonic_ms(), &last_ms);

        /* Never busy-spin: let OsTask_5ms / OsTask_10ms run */
        (void)usleep(1000);
    }
}
