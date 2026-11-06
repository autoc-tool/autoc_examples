#include <nuttx/config.h>
#include <unistd.h>
#include <nuttx/irq.h>

#include "Os_Types.h"
#include "rtfw_core.h"
#include "Os.h"
#include "rtfw_counter.h"
#include "counter_cfg.h"
#include "task_cfg.h"
#include "isr_cfg.h"
#include "event_cfg.h"
#include "syslog.h"

extern void SchM_Init(void);
extern void Rte_Start(void);

/* ISR only stamps time; SetEvent must run in task context (ISR SetEvent SEGV). */
volatile unsigned g_ms4_tick_ms;

void up_systick_isr_handler(void)
{
	g_ms4_tick_ms++;
}

/* Call from OsTask_Init loop: convert elapsed ticks into Rte cyclic SetEvents. */
void ms4_drive_rte_events_task(void)
{
	static unsigned last_tick;
	unsigned now = g_ms4_tick_ms;
	unsigned t;

	for (t = last_tick + 1u; t <= now; t++) {
		if ((t % 5u) == 0u) {
			(void)SetEvent((TaskType)OS_TASK_OSTASK_10MS_ID,
				(EventMaskType)RTE_EV_CYCLIC2_OSTASK_10MS_0_5MS);
		}
		if ((t % 10u) == 0u) {
			(void)SetEvent((TaskType)OS_TASK_OSTASK_10MS_ID,
				(EventMaskType)(RTE_EV_CYCLIC_OSTASK_10MS_0_10MS |
						RTE_EV_CYCLIC2_OSTASK_10MS_0_10MS));
		}
		if ((t % 100u) == 0u) {
			(void)SetEvent((TaskType)OS_TASK_OSTASK_100MS_ID,
				(EventMaskType)RTE_EV_CYCLIC_OSTASK_100MS_0_100MS);
		}
	}
	last_tick = now;
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

static int ms4_systick_isr(int irq, void *context, void *arg)
{
	(void)irq;
	(void)context;
	(void)arg;
	core0_systick_handler();
	return 0;
}

void platform_init(void)
{
	(void)irq_attach(TIMER_CORE0_IRQ_BASE, ms4_systick_isr, NULL);
}

void core0_systick_handler(void)
{
	up_systick_isr_handler();
}

#ifndef CONFIG_TRACED
void handshake_main_func(void) {}
void trace_dumpudp_main_func(void) {}
#endif

/* ms5 Os codegen includes CORE0_SHELL; ms4 did not. Idle stub — not used for TX path. */
void os_task_core0_shell(void *arg)
{
	(void)arg;
	for (;;) {
		/* Autostarted by Os codegen; yield so Init/10ms/100ms can run */
		(void)usleep(1000);
	}
}
