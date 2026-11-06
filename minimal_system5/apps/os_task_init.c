#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "Os.h"
#include "Can.h"
#include "canif.h"
#include "pdur.h"
#include "com.h"
#include "Rte_Main.h"
#include "event_cfg.h"

extern const Can_ConfigType Can_Config;
extern const canif_config_type canif_config;
extern const pdur_pb_config_type pdur_config;
extern const com_config_type com_configuration;
extern void RE_Init(void);
extern volatile unsigned g_re_init;
extern void ms4_drive_rte_events_task(void);

volatile unsigned g_can_ready;
volatile unsigned g_mode_ok;
volatile unsigned g_rte_started;
volatile unsigned g_bsw_inited;

void os_task_ostask_init(void *arg)
{
	Can_ControllerStateType mode = CAN_CS_UNINIT;
	com_ipg_vec ipg;
	Std_ReturnType st;
	(void)arg;
	printf("[Init] StartOS task: Can->CanIf->PduR->Com->Rte (autoc_mcal)\n");

	Can_Init(&Can_Config);
	canif_init(&canif_config);
	pdur_init(&pdur_config);
	com_init(&com_configuration);

	st = canif_set_controller_mode(0u, CAN_CS_STARTED);
	printf("[Init] canif_set_controller_mode STARTED -> %u\n", (unsigned)st);
	st = canif_set_pdu_mode(0u, CANIF_ONLINE);
	printf("[Init] canif_set_pdu_mode ONLINE -> %u\n", (unsigned)st);

	if (Can_GetControllerMode(0u, &mode) == E_OK) {
		printf("[Init] Can mode=%u (1=STARTED)\n", (unsigned)mode);
		g_can_ready = (mode == CAN_CS_STARTED) ? 1u : 0u;
		g_mode_ok = g_can_ready;
	}

	memset(ipg, 0, sizeof(ipg));
	com_set_ipdu_group(ipg, ComConf_ComIPduGroup_ComIPduGroup_0, TRUE);
	com_set_ipdu_group(ipg, ComConf_ComIPduGroup_ComIPduGroup_1, TRUE);
	com_ipdu_group_control(ipg, TRUE);
	g_bsw_inited = 1u;

	SchM_Init();
	if (Rte_Start() == RTE_E_OK) {
		g_rte_started = 1u;
		printf("[Init] Rte_Start OK\n");
	}
	RE_Init();
	printf("[Init] done can_ready=%u rte=%u re_init=%u\n",
	       g_can_ready, g_rte_started, g_re_init);

	for (;;) {
		/* Drain autoc_mcal RPC confirmations in Os task context */
		Can_MainFunction_Write();
		Can_MainFunction_Read();
		Can_MainFunction_Mode();
		Can_MainFunction_BusOff();
		ms4_drive_rte_events_task();
		/* Block so OsTask_10ms (lower prio) can run */
		(void)usleep(1000);
	}
}
