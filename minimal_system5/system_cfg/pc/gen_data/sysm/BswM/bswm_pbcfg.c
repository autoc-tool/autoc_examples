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
 * @file        BswM_PBCfg.c
 * @brief       BswM PostBuild 配置源文件.
 * @details     BswM PostBuild 配置源文件.
 * @date		Generation Time : 2026-10-24 23:59:17
 * @toolversion Tool Version    : V0.1.0-DEV
 **********************************************************************************************************************/
/* Including File */
#include "bswm.h"
#include "com.h"
#include "bswm_internal.h"
#include "bswm_bsw.h"

/* Include UserCallout File */
#include "bswm_user_callout.h"

#define  BSWM_START_SEC_CONST
#include "bswm_memmap.h"
/* Local Type & Structure Definition */
/* BswM内部使用的 PduGroup */



/* 不同的 PduRoutingPathGroup */



/* 不同ActionItems 具体内容 */

static CONST(bswm_action_list_item_t, BSWM_CONST) bswm_ECUM_AL_INIT_BswMActionListItem = {
	.action_t = BSWM_ATOMIC,
	.atomic_idx = BSWM_ECUM_ACTION_BSW_INITTWO_ACTION_IDX,
	.dem_fail_report_ref = -1,
	.stop_if_fail = (boolean)STD_OFF,
};

static CONST(bswm_action_list_item_t, BSWM_CONST) bswm_ECUM_AL_INIT_BswMActionListItem_1 = {
	.action_t = BSWM_ATOMIC,
	.atomic_idx = BSWM_ECUM_ACTION_BSW_INITTHREE_ACTION_IDX,
	.dem_fail_report_ref = -1,
	.stop_if_fail = (boolean)STD_OFF,
};

static CONST(bswm_action_list_item_t, BSWM_CONST) bswm_ECUM_AL_INIT_BswMActionListItem_2 = {
	.action_t = BSWM_ATOMIC,
	.atomic_idx = BSWM_ECUM_ACTION_RTE_INIT_ACTION_IDX,
	.dem_fail_report_ref = -1,
	.stop_if_fail = (boolean)STD_OFF,
};

static CONST(bswm_action_list_item_t, BSWM_CONST) bswm_ESH_AL_InitToWakeup_BswMActionListItem = {
	.action_t = BSWM_ATOMIC,
	.atomic_idx = BSWM_ESH_ACTION_ESH_WAKEUP_ACTION_IDX,
	.dem_fail_report_ref = -1,
	.stop_if_fail = (boolean)STD_OFF,
};

static CONST(bswm_action_list_item_t, BSWM_CONST) bswm_ESH_AL_WakeupToRun_BswMActionListItem = {
	.action_t = BSWM_ATOMIC,
	.atomic_idx = BSWM_ESH_ACTION_ESH_RUN_ACTION_IDX,
	.dem_fail_report_ref = -1,
	.stop_if_fail = (boolean)STD_OFF,
};

static CONST(bswm_action_list_item_t, BSWM_CONST) bswm_ESH_AL_WakeupToRun_BswMActionListItem_1 = {
	.action_t = BSWM_ATOMIC,
	.atomic_idx = BSWM_ESH_ACTION_SELFRUNREQUESTTIMER_START_ACTION_IDX,
	.dem_fail_report_ref = -1,
	.stop_if_fail = (boolean)STD_OFF,
	.timer_id = ESH_SelfRunRequestTimer,
	.timer_value = 500,
};

static CONST(bswm_action_list_item_t, BSWM_CONST) bswm_ESH_AL_RunToPostRun_BswMActionListItem = {
	.action_t = BSWM_ATOMIC,
	.atomic_idx = BSWM_ESH_ACTION_ESH_POSTRUN_ACTION_IDX,
	.dem_fail_report_ref = -1,
	.stop_if_fail = (boolean)STD_OFF,
};

static CONST(bswm_action_list_item_t, BSWM_CONST) bswm_ESH_AL_ExitPostRun_BswMActionListItem = {
	.action_t = BSWM_RULE,
	.rule_idx_ref = (sint16)BSWM_ESH_POSTRUNNESTED_RULE_IDX,
	.dem_fail_report_ref = -1,
	.stop_if_fail = (boolean)STD_OFF,
};

static CONST(bswm_action_list_item_t, BSWM_CONST) bswm_ESH_AL_PostRunToRun_BswMActionListItem = {
	.action_t = BSWM_ATOMIC,
	.atomic_idx = BSWM_ESH_ACTION_ESH_RUN_ACTION_IDX,
	.dem_fail_report_ref = -1,
	.stop_if_fail = (boolean)STD_OFF,
};

static CONST(bswm_action_list_item_t, BSWM_CONST) bswm_ESH_AL_ESH_PostRunToPrepCheck_BswMActionListItem = {
	.action_t = BSWM_RULE,
	.rule_idx_ref = (sint16)BSWM_ESH_POSTRUNTOPREPNESTED_RULE_IDX,
	.dem_fail_report_ref = -1,
	.stop_if_fail = (boolean)STD_OFF,
};

static CONST(bswm_action_list_item_t, BSWM_CONST) bswm_ESH_AL_PostRunToPrep_BswMActionListItem = {
	.action_t = BSWM_ATOMIC,
	.atomic_idx = BSWM_ESH_ACTION_ESH_PREP_ACTION_IDX,
	.dem_fail_report_ref = -1,
	.stop_if_fail = (boolean)STD_OFF,
};

static CONST(bswm_action_list_item_t, BSWM_CONST) bswm_ESH_AL_PrepToWait_BswMActionListItem = {
	.action_t = BSWM_ATOMIC,
	.atomic_idx = BSWM_ESH_ACTION_WRITEALLTIMER_START_ACTION_IDX,
	.dem_fail_report_ref = -1,
	.stop_if_fail = (boolean)STD_OFF,
	.timer_id = ESH_NvM_WriteAllTimer,
	.timer_value = 1000,
};

static CONST(bswm_action_list_item_t, BSWM_CONST) bswm_ESH_AL_PrepToWait_BswMActionListItem_1 = {
	.action_t = BSWM_ATOMIC,
	.atomic_idx = BSWM_ESH_ACTION_ESH_WAIT_ACTION_IDX,
	.dem_fail_report_ref = -1,
	.stop_if_fail = (boolean)STD_OFF,
};

static CONST(bswm_action_list_item_t, BSWM_CONST) bswm_ESH_AL_WaitToWakeup_BswMActionListItem = {
	.action_t = BSWM_ATOMIC,
	.atomic_idx = BSWM_ESH_ACTION_WRITEALLTIMER_STOP_ACTION_IDX,
	.dem_fail_report_ref = -1,
	.stop_if_fail = (boolean)STD_OFF,
	.timer_id = ESH_NvM_WriteAllTimer,
	.timer_value = 0,
};

static CONST(bswm_action_list_item_t, BSWM_CONST) bswm_ESH_AL_WaitToWakeup_BswMActionListItem_1 = {
	.action_t = BSWM_ATOMIC,
	.atomic_idx = BSWM_ESH_ACTION_ESH_WAITTOWAKEUP_ACTION_IDX,
	.dem_fail_report_ref = -1,
	.stop_if_fail = (boolean)STD_OFF,
};

static CONST(bswm_action_list_item_t, BSWM_CONST) bswm_ESH_AL_WaitToShutdown_BswMActionListItem = {
	.action_t = BSWM_ATOMIC,
	.atomic_idx = BSWM_ESH_ACTION_WRITEALLTIMER_STOP_ACTION_IDX,
	.dem_fail_report_ref = -1,
	.stop_if_fail = (boolean)STD_OFF,
	.timer_id = ESH_NvM_WriteAllTimer,
	.timer_value = 0,
};

static CONST(bswm_action_list_item_t, BSWM_CONST) bswm_ESH_AL_WaitToShutdown_BswMActionListItem_1 = {
	.action_t = BSWM_ATOMIC,
	.atomic_idx = BSWM_ESH_ACTION_ESH_SHUTDOWN_ACTION_IDX,
	.dem_fail_report_ref = -1,
	.stop_if_fail = (boolean)STD_OFF,
};

static CONST(bswm_action_list_item_t, BSWM_CONST) bswm_ReqFullcomList_BswMActionListItem = {
	.action_t = BSWM_ATOMIC,
	.atomic_idx = BSWM_REQFULLCOMACTION_ACTION_IDX,
	.dem_fail_report_ref = -1,
	.stop_if_fail = (boolean)STD_OFF,
};

static CONST(bswm_action_list_item_t, BSWM_CONST) bswm_ReqNocomList_BswMActionListItem = {
	.action_t = BSWM_ATOMIC,
	.atomic_idx = BSWM_REQNOCOMACTION_ACTION_IDX,
	.dem_fail_report_ref = -1,
	.stop_if_fail = (boolean)STD_OFF,
};

static CONST(bswm_action_list_item_t, BSWM_CONST) bswm_StartCommunicationList_BswMActionListItem = {
	.action_t = BSWM_ATOMIC,
	.atomic_idx = BSWM_REQUESTFULLCOMACTION_ACTION_IDX,
	.dem_fail_report_ref = -1,
	.stop_if_fail = (boolean)STD_OFF,
};

/* 不同ActionListItems 实体 */

static CONSTP2CONST(bswm_action_list_item_t, AUTOMATIC, BSWM_CONST) BswM_ActionList_ECUM_AL_INIT[] = {
	&bswm_ECUM_AL_INIT_BswMActionListItem,
	&bswm_ECUM_AL_INIT_BswMActionListItem_1,
	&bswm_ECUM_AL_INIT_BswMActionListItem_2,
};

static CONSTP2CONST(bswm_action_list_item_t, AUTOMATIC, BSWM_CONST) BswM_ActionList_ESH_AL_InitToWakeup[] = {
	&bswm_ESH_AL_InitToWakeup_BswMActionListItem,
};

static CONSTP2CONST(bswm_action_list_item_t, AUTOMATIC, BSWM_CONST) BswM_ActionList_ESH_AL_WakeupToRun[] = {
	&bswm_ESH_AL_WakeupToRun_BswMActionListItem,
	&bswm_ESH_AL_WakeupToRun_BswMActionListItem_1,
};

static CONSTP2CONST(bswm_action_list_item_t, AUTOMATIC, BSWM_CONST) BswM_ActionList_ESH_AL_RunToPostRun[] = {
	&bswm_ESH_AL_RunToPostRun_BswMActionListItem,
};

static CONSTP2CONST(bswm_action_list_item_t, AUTOMATIC, BSWM_CONST) BswM_ActionList_ESH_AL_ExitPostRun[] = {
	&bswm_ESH_AL_ExitPostRun_BswMActionListItem,
};

static CONSTP2CONST(bswm_action_list_item_t, AUTOMATIC, BSWM_CONST) BswM_ActionList_ESH_AL_PostRunToRun[] = {
	&bswm_ESH_AL_PostRunToRun_BswMActionListItem,
};

static CONSTP2CONST(bswm_action_list_item_t, AUTOMATIC, BSWM_CONST) BswM_ActionList_ESH_AL_ESH_PostRunToPrepCheck[] = {
	&bswm_ESH_AL_ESH_PostRunToPrepCheck_BswMActionListItem,
};

static CONSTP2CONST(bswm_action_list_item_t, AUTOMATIC, BSWM_CONST) BswM_ActionList_ESH_AL_PostRunToPrep[] = {
	&bswm_ESH_AL_PostRunToPrep_BswMActionListItem,
};

static CONSTP2CONST(bswm_action_list_item_t, AUTOMATIC, BSWM_CONST) BswM_ActionList_ESH_AL_PrepToWait[] = {
	&bswm_ESH_AL_PrepToWait_BswMActionListItem,
	&bswm_ESH_AL_PrepToWait_BswMActionListItem_1,
};

static CONSTP2CONST(bswm_action_list_item_t, AUTOMATIC, BSWM_CONST) BswM_ActionList_ESH_AL_WaitToWakeup[] = {
	&bswm_ESH_AL_WaitToWakeup_BswMActionListItem,
	&bswm_ESH_AL_WaitToWakeup_BswMActionListItem_1,
};

static CONSTP2CONST(bswm_action_list_item_t, AUTOMATIC, BSWM_CONST) BswM_ActionList_ESH_AL_WaitToShutdown[] = {
	&bswm_ESH_AL_WaitToShutdown_BswMActionListItem,
	&bswm_ESH_AL_WaitToShutdown_BswMActionListItem_1,
};

static CONSTP2CONST(bswm_action_list_item_t, AUTOMATIC, BSWM_CONST) BswM_ActionList_ReqFullcomList[] = {
	&bswm_ReqFullcomList_BswMActionListItem,
};

static CONSTP2CONST(bswm_action_list_item_t, AUTOMATIC, BSWM_CONST) BswM_ActionList_ReqNocomList[] = {
	&bswm_ReqNocomList_BswMActionListItem,
};

static CONSTP2CONST(bswm_action_list_item_t, AUTOMATIC, BSWM_CONST) BswM_ActionList_StartCommunicationList[] = {
	&bswm_StartCommunicationList_BswMActionListItem,
};

/* 行为列表配置数据 */

static CONST(bswm_action_list_t, BSWM_CONST) bswm_action_list_data[BSWM_NUMBER_OF_ACTIONLISTS] = {
	[BSWM_ECUM_AL_INIT_LIST_IDX] =
	{
		.exec_mode = BSWM_TRIGGER,
		.items_count = 3u,
		.items = &BswM_ActionList_ECUM_AL_INIT[0]
	},
	[BSWM_ESH_AL_INITTOWAKEUP_LIST_IDX] =
	{
		.exec_mode = BSWM_CONDITION,
		.items_count = 1u,
		.items = &BswM_ActionList_ESH_AL_InitToWakeup[0]
	},
	[BSWM_ESH_AL_WAKEUPTORUN_LIST_IDX] =
	{
		.exec_mode = BSWM_CONDITION,
		.items_count = 2u,
		.items = &BswM_ActionList_ESH_AL_WakeupToRun[0]
	},
	[BSWM_ESH_AL_RUNTOPOSTRUN_LIST_IDX] =
	{
		.exec_mode = BSWM_CONDITION,
		.items_count = 1u,
		.items = &BswM_ActionList_ESH_AL_RunToPostRun[0]
	},
	[BSWM_ESH_AL_EXITPOSTRUN_LIST_IDX] =
	{
		.exec_mode = BSWM_CONDITION,
		.items_count = 1u,
		.items = &BswM_ActionList_ESH_AL_ExitPostRun[0]
	},
	[BSWM_ESH_AL_POSTRUNTORUN_LIST_IDX] =
	{
		.exec_mode = BSWM_CONDITION,
		.items_count = 1u,
		.items = &BswM_ActionList_ESH_AL_PostRunToRun[0]
	},
	[BSWM_ESH_AL_ESH_POSTRUNTOPREPCHECK_LIST_IDX] =
	{
		.exec_mode = BSWM_CONDITION,
		.items_count = 1u,
		.items = &BswM_ActionList_ESH_AL_ESH_PostRunToPrepCheck[0]
	},
	[BSWM_ESH_AL_POSTRUNTOPREP_LIST_IDX] =
	{
		.exec_mode = BSWM_CONDITION,
		.items_count = 1u,
		.items = &BswM_ActionList_ESH_AL_PostRunToPrep[0]
	},
	[BSWM_ESH_AL_PREPTOWAIT_LIST_IDX] =
	{
		.exec_mode = BSWM_CONDITION,
		.items_count = 2u,
		.items = &BswM_ActionList_ESH_AL_PrepToWait[0]
	},
	[BSWM_ESH_AL_WAITTOWAKEUP_LIST_IDX] =
	{
		.exec_mode = BSWM_CONDITION,
		.items_count = 2u,
		.items = &BswM_ActionList_ESH_AL_WaitToWakeup[0]
	},
	[BSWM_ESH_AL_WAITTOSHUTDOWN_LIST_IDX] =
	{
		.exec_mode = BSWM_CONDITION,
		.items_count = 2u,
		.items = &BswM_ActionList_ESH_AL_WaitToShutdown[0]
	},
	[BSWM_REQFULLCOMLIST_LIST_IDX] =
	{
		.exec_mode = BSWM_TRIGGER,
		.items_count = 1u,
		.items = &BswM_ActionList_ReqFullcomList[0]
	},
	[BSWM_REQNOCOMLIST_LIST_IDX] =
	{
		.exec_mode = BSWM_TRIGGER,
		.items_count = 1u,
		.items = &BswM_ActionList_ReqNocomList[0]
	},
	[BSWM_STARTCOMMUNICATIONLIST_LIST_IDX] =
	{
		.exec_mode = BSWM_TRIGGER,
		.items_count = 1u,
		.items = &BswM_ActionList_StartCommunicationList[0]
	},
};


/* 规则配置数据 */

static CONST(bswm_rule_t, BSWM_CONST) bswm_rule_data[BSWM_NUMBER_OF_RULES] = {
	[BSWM_ECUM_MODULEINIT_RULE_IDX] =
	{
		.logic_expr_idx = BSWM_ECUM_LE_INIT_EXP_IDX,
		.initial_state = (bswm_rule_state_t)BSWM_FALSE,
		.true_list_idx = (sint32)BSWM_ECUM_AL_INIT_LIST_IDX,
		.false_list_idx = (sint32)BSWM__LIST_IDX
	},
	[BSWM_ESH_INITTOWAKEUP_RULE_IDX] =
	{
		.logic_expr_idx = BSWM_ESH_LE_INITTOWAKEUP_EXP_IDX,
		.initial_state = (bswm_rule_state_t)BSWM_FALSE,
		.true_list_idx = (sint32)BSWM_ESH_AL_INITTOWAKEUP_LIST_IDX,
		.false_list_idx = (sint32)BSWM__LIST_IDX
	},
	[BSWM_ESH_WAKEUPTORUN_RULE_IDX] =
	{
		.logic_expr_idx = BSWM_ESH_LE_WAKEUPTORUN_EXP_IDX,
		.initial_state = (bswm_rule_state_t)BSWM_FALSE,
		.true_list_idx = (sint32)BSWM_ESH_AL_WAKEUPTORUN_LIST_IDX,
		.false_list_idx = (sint32)BSWM__LIST_IDX
	},
	[BSWM_ESH_RUNTOPOSTRUN_RULE_IDX] =
	{
		.logic_expr_idx = BSWM_ESH_LE_RUNTOPOSTRUN_EXP_IDX,
		.initial_state = (bswm_rule_state_t)BSWM_FALSE,
		.true_list_idx = (sint32)BSWM_ESH_AL_RUNTOPOSTRUN_LIST_IDX,
		.false_list_idx = (sint32)BSWM__LIST_IDX
	},
	[BSWM_ESH_POSTRUN_RULE_IDX] =
	{
		.logic_expr_idx = BSWM_ESH_LE_POSTRUN_EXP_IDX,
		.initial_state = (bswm_rule_state_t)BSWM_FALSE,
		.true_list_idx = (sint32)BSWM_ESH_AL_EXITPOSTRUN_LIST_IDX,
		.false_list_idx = (sint32)BSWM__LIST_IDX
	},
	[BSWM_ESH_POSTRUNNESTED_RULE_IDX] =
	{
		.logic_expr_idx = BSWM_ESH_LE_POSTRUNTORUN_EXP_IDX,
		.initial_state = (bswm_rule_state_t)BSWM_FALSE,
		.true_list_idx = (sint32)BSWM_ESH_AL_WAKEUPTORUN_LIST_IDX,
		.false_list_idx = (sint32)BSWM_ESH_AL_ESH_POSTRUNTOPREPCHECK_LIST_IDX
	},
	[BSWM_ESH_POSTRUNTOPREPNESTED_RULE_IDX] =
	{
		.logic_expr_idx = BSWM_ESH_LE_POSTRUNTOPREP_EXP_IDX,
		.initial_state = (bswm_rule_state_t)BSWM_FALSE,
		.true_list_idx = (sint32)BSWM_ESH_AL_POSTRUNTOPREP_LIST_IDX,
		.false_list_idx = (sint32)BSWM__LIST_IDX
	},
	[BSWM_ESH_WAKEUPTOPREP_RULE_IDX] =
	{
		.logic_expr_idx = BSWM_ESH_LE_WAKEUPTOPREP_EXP_IDX,
		.initial_state = (bswm_rule_state_t)BSWM_FALSE,
		.true_list_idx = (sint32)BSWM_ESH_AL_POSTRUNTOPREP_LIST_IDX,
		.false_list_idx = (sint32)BSWM__LIST_IDX
	},
	[BSWM_ESH_PREPTOWAIT_RULE_IDX] =
	{
		.logic_expr_idx = BSWM_ESH_LE_PREPTOWAIT_EXP_IDX,
		.initial_state = (bswm_rule_state_t)BSWM_FALSE,
		.true_list_idx = (sint32)BSWM_ESH_AL_PREPTOWAIT_LIST_IDX,
		.false_list_idx = (sint32)BSWM__LIST_IDX
	},
	[BSWM_ESH_WAITTOWAKEUP_RULE_IDX] =
	{
		.logic_expr_idx = BSWM_ESH_LE_WAITTOWAKEUP_EXP_IDX,
		.initial_state = (bswm_rule_state_t)BSWM_FALSE,
		.true_list_idx = (sint32)BSWM_ESH_AL_WAITTOWAKEUP_LIST_IDX,
		.false_list_idx = (sint32)BSWM__LIST_IDX
	},
	[BSWM_ESH_WAITTOSHUTDOWN_RULE_IDX] =
	{
		.logic_expr_idx = BSWM_ESH_LE_WAITTOSHUTDOWN_EXP_IDX,
		.initial_state = (bswm_rule_state_t)BSWM_FALSE,
		.true_list_idx = (sint32)BSWM_ESH_AL_WAITTOSHUTDOWN_LIST_IDX,
		.false_list_idx = (sint32)BSWM__LIST_IDX
	},
	[BSWM_STARTCOMMUNICATIONRULE_RULE_IDX] =
	{
		.logic_expr_idx = BSWM_STARTCOMMUNICATIONEXP_EXP_IDX,
		.initial_state = (bswm_rule_state_t)BSWM_FALSE,
		.true_list_idx = (sint32)BSWM_STARTCOMMUNICATIONLIST_LIST_IDX,
		.false_list_idx = (sint32)BSWM__LIST_IDX
	},
	[BSWM_KEEPCOMRULE_RULE_IDX] =
	{
		.logic_expr_idx = BSWM_KEEPCOMEXP_EXP_IDX,
		.initial_state = (bswm_rule_state_t)BSWM_TRUE,
		.true_list_idx = (sint32)BSWM_REQFULLCOMLIST_LIST_IDX,
		.false_list_idx = (sint32)BSWM_REQNOCOMLIST_LIST_IDX
	},
};


/* 延期规则配置数据 */
static CONST(sint16, BSWM_CONST) bswm_deferred_rules[] = {
	(sint16)BSWM_ESH_WAKEUPTORUN_RULE_IDX,
	(sint16)BSWM_ESH_RUNTOPOSTRUN_RULE_IDX,
	(sint16)BSWM_ESH_WAKEUPTOPREP_RULE_IDX,
	(sint16)BSWM_ESH_WAITTOWAKEUP_RULE_IDX,
	(sint16)BSWM_ESH_WAITTOSHUTDOWN_RULE_IDX,
	(sint16)BSWM_STARTCOMMUNICATIONRULE_RULE_IDX,
	-1
};

/* 即时规则配置数据 */
static CONST(sint16, BSWM_CONST) bswm_immediate_rules[] = {
	(sint16)BSWM_ECUM_MODULEINIT_RULE_IDX,					/* extra extra */
	(sint16)BSWM_KEEPCOMRULE_RULE_IDX,					/* extra extra */
	(sint16)BSWM_ESH_INITTOWAKEUP_RULE_IDX,					/* Generic 1 */
	(sint16)BSWM_ESH_WAKEUPTORUN_RULE_IDX,					/* Generic 1 */
	(sint16)BSWM_ESH_RUNTOPOSTRUN_RULE_IDX,					/* Generic 1 */
	(sint16)BSWM_ESH_POSTRUN_RULE_IDX,					/* Generic 1 */
	(sint16)BSWM_ESH_WAKEUPTOPREP_RULE_IDX,					/* Generic 1 */
	(sint16)BSWM_ESH_PREPTOWAIT_RULE_IDX,					/* Generic 1 */
	(sint16)BSWM_ESH_WAITTOWAKEUP_RULE_IDX,					/* Generic 1 */
	(sint16)BSWM_ESH_WAITTOSHUTDOWN_RULE_IDX,					/* Generic 1 */
};

/* 即时规则配置数据 */
CONST(sint16, BSWM_CONST) bswm_immediate_rules_on_init[] = {
	(sint16)0,
	(sint16)1,
	(sint16)2,
	(sint16)3,
	(sint16)4,
	(sint16)5,
	(sint16)6,
	(sint16)7,
	(sint16)8,
	(sint16)9,
};



/* 模式请求初始状态 */
static CONST(uint32, BSWM_CONST) BswM_ModeReqMirrorsInit[BSWM_NUMBER_OF_REQUESTS] = {
	[BSWM_ECUM_GETSTATEREQ_REQ_IDX] = (uint32) BSWM_UNDEFINED_REQUEST_VALUE,
	[BSWM_ESH_ECUM_GETPENDINGWAKEUPEVENTS_REQ_IDX] = (uint32) BSWM_UNDEFINED_REQUEST_VALUE,
	[BSWM_ESH_ECUM_GETVALIDATEDWAKEUPEVENTS_REQ_IDX] = (uint32) BSWM_UNDEFINED_REQUEST_VALUE,
	[BSWM_ESH_SELFRUNREQUESTTIMER_REQ_IDX] = (uint32) BSWM_TIMER_STOPPED,
	[BSWM_ESH_RUNREQUEST_1_REQ_IDX] = (uint32) FALSE,
	[BSWM_ESH_POSTRUNREQUEST_1_REQ_IDX] = (uint32) FALSE,
	[BSWM_ESH_NVM_WRITEALLTIMER_REQ_IDX] = (uint32) BSWM_TIMER_STOPPED,
	[BSWM_ESH_STATE_REQ_IDX] = (uint32) BSWM_ESH_INIT,
	[BSWM_KEEPCOMREQ_REQ_IDX] = (uint32) COMM_FULL_COMMUNICATION,
	[BSWM_BSWCOMMINDICATIONREQ_REQ_IDX] = (uint32) COMM_NO_COMMUNICATION,
	[BSWM_STARTCOMMUNICATIONREQ_REQ_IDX] = (uint32) BSWM_UNDEFINED_REQUEST_VALUE,
};


/* 规则配置数据 */
static CONST(bswm_rule_config_t, BSWM_CONST) bswm_rule_config = {
	.deferred_rule_set  = &bswm_deferred_rules[0],				   /* 延期规则 */
	.immediate_rule_set = &bswm_immediate_rules[0],				  /* 即时规则 */
	.rule_list	   = &bswm_rule_data[0],						/* 规则数据 */
	.rules_count  = BSWM_NUMBER_OF_RULES					  /* 规则总数 */
};

/* 总配置数据 */
CONST(bswm_config_type, BSWM_CONST) bswm_config = {
	.rule_cfg		 = &bswm_rule_config,						/* 规则配置 */
	.action_list_data  = &bswm_action_list_data[0],				 /* 行为列表配置 */
	.mode_request_data = &BswM_ModeReqMirrorsInit[0]			  /* 模式请求配置 */
};
#define  BSWM_STOP_SEC_CONST
#include "bswm_memmap.h"