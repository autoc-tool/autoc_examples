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
 * @file        system.c
 * @brief       PC_Common / NuttX sim harness glue
 * @details     Provides the platform hooks the sim board expects
 *              (platform_init, up_systick_isr_handler) and the bodies of the
 *              Os shell tasks generated in gen_data/Os/task_cfg.c.
 *
 *              The board calls platform_init() and then StartOS(); the Os
 *              schedule tables are advanced by OsTask_Init (os_task_init.c),
 *              so the systick handler below only keeps a diagnostic
 *              millisecond tick.
 **********************************************************************************************************************/

#include <nuttx/config.h>
#include <unistd.h>
#include <nuttx/irq.h>

#include "Os_Types.h"
#include "Os.h"
#include "syslog.h"

volatile unsigned g_pc_tick_ms;

void up_systick_isr_handler(void)
{
    g_pc_tick_ms++;
}

int e3650_init_main(int argc, FAR char *argv[])
{
    (void)argc;
    (void)argv;
    return 0;
}

#ifndef TIMER_CORE0_IRQ_BASE
#define TIMER_CORE0_IRQ_BASE 30
#endif

void core0_systick_handler(void);

static int ms9_systick_isr(int irq, void *context, void *arg)
{
    (void)irq;
    (void)context;
    (void)arg;

    core0_systick_handler();

    return 0;
}

void platform_init(void)
{
    (void)irq_attach(TIMER_CORE0_IRQ_BASE, ms9_systick_isr, NULL);
}

void core0_systick_handler(void)
{
    up_systick_isr_handler();
}

#ifndef CONFIG_TRACED
void handshake_main_func(void) {}
void trace_dumpudp_main_func(void) {}
#endif

/* The Os shell tasks are autostarted by the Os codegen. The PC harness has no
 * interactive shell, so they idle with a sleep and leave the CPU to the RTE
 * tasks (OsTask_5ms / OsTask_10ms). */
static void os_shell_task_idle(void)
{
    for (;;) {
        (void)usleep(1000);
    }
}

void os_task_core0_shell(void *arg)
{
    (void)arg;
    os_shell_task_idle();
}

void os_task_core1_shell(void *arg)
{
    (void)arg;
    os_shell_task_idle();
}

void os_task_core2_shell(void *arg)
{
    (void)arg;
    os_shell_task_idle();
}

void os_task_core3_shell(void *arg)
{
    (void)arg;
    os_shell_task_idle();
}
