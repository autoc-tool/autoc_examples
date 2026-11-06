#include <stdio.h>
#include "Rte_MinimalSystemApp.h"

volatile unsigned g_re_init;
volatile unsigned g_re_10ms;
volatile unsigned g_re_100ms;

void RE_Init(void)
{
	g_re_init++;
	/* Implicit API: seed OsTask buffers before cyclic starts */
	Rte_IWrite_RE_Cyclic_100ms_PP_ECU_State_ECU_State(1u);
	Rte_IWrite_RE_Cyclic_100ms_PP_ECU_AliveCnt_ECU_AliveCnt(0u);
	Rte_IWrite_RE_Cyclic_100ms_PP_Temperature_Temperature(25u);
	Rte_IWrite_RE_Cyclic_100ms_PP_SupplyVoltage_SupplyVoltage(12000u);
	Rte_IWrite_RE_Cyclic_10ms_PP_FaultFlags_FaultFlags(0u);
	Rte_IWrite_RE_Cyclic_10ms_PP_FaultCode_FaultCode(0u);
	Rte_IWrite_RE_Cyclic_10ms_PP_FaultActive_FaultActive(0u);
	printf("[ASW] RE_Init count=%u\n", g_re_init);
}

void RE_Cyclic_10ms(void)
{
	static unsigned alive;
	g_re_10ms++;
	alive = (alive + 1u) & 0xFu;
	/* Ports owned by RE_Cyclic_10ms (Fault_Event 0x300 + FaultFlags on ECU_Status) */
	Rte_IWrite_RE_Cyclic_10ms_PP_FaultCode_FaultCode((uint8)(alive & 0xFFu));
	Rte_IWrite_RE_Cyclic_10ms_PP_FaultActive_FaultActive(0u);
	Rte_IWrite_RE_Cyclic_10ms_PP_FaultFlags_FaultFlags(0u);
	(void)Rte_IRead_RE_Cyclic_10ms_RP_LedCmd_LedCmd();
	(void)Rte_IRead_RE_Cyclic_10ms_RP_TargetMode_TargetMode();
	if ((g_re_10ms % 10u) == 1u) {
		printf("[ASW] RE_Cyclic_10ms count=%u alive=%u\n", g_re_10ms, alive);
	}
}

void RE_Cyclic_100ms(void)
{
	static unsigned alive;
	g_re_100ms++;
	alive = (alive + 1u) & 0xFu;
	/* Ports owned by RE_Cyclic_100ms → ECU_Status 0x100 */
	Rte_IWrite_RE_Cyclic_100ms_PP_ECU_State_ECU_State(2u);
	Rte_IWrite_RE_Cyclic_100ms_PP_ECU_AliveCnt_ECU_AliveCnt((uint4)alive);
	Rte_IWrite_RE_Cyclic_100ms_PP_Temperature_Temperature(25u + (uint8)(alive & 3u));
	Rte_IWrite_RE_Cyclic_100ms_PP_SupplyVoltage_SupplyVoltage(12000u);
	printf("[ASW] RE_Cyclic_100ms count=%u alive=%u\n", g_re_100ms, alive);
}
