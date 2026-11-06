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
 * @file		bswm_cfg.c
 * @brief	   	BswM 配置源文件.
 * @details	 	BswM模块的配置相关相关信息
 * @date		Generation Time : 2026-10-24 23:59:17
 * @toolversion Tool Version    : V0.1.0-DEV
 **********************************************************************************************************************/
/* Including File */
#include "bswm.h"
#include "bswm_internal.h"
#include "bswm_bsw.h"
#include "vcos_log.h"
#include "bswm_vcos_log.h"
extern void bswm_process_immediate_request(const uint32 index_start, const uint32 index_end);

/* Include UserCallout File */
#include "bswm_user_callout.h"

/* Local Variable Definition */
#define BSWM_START_SEC_MULTI_APP_BSS
#include "bswm_memmap.h"
VAR(uint32, BSWM_MULTI_APP_BSS) bswm_mode_req_mirrors[BSWM_NUMBER_OF_REQUESTS];
#if (BSWM_TIMERS_NUM > 0)
VAR(bswm_timer_t, BSWM_MULTI_APP_BSS) timers[BSWM_TIMERS_NUM];
#endif
#define BSWM_STOP_SEC_MULTI_APP_BSS
#include "bswm_memmap.h"
/* Local Function Declaration */
/* UserCondition 声明 */

/* Action 声明 */
#define BSWM_START_SEC_CODE
#include "bswm_memmap.h"
FUNC(Std_ReturnType, BSWM_CODE) ECUM_Action_BSW_InitTwo(const bswm_action_list_item_t *item);
FUNC(Std_ReturnType, BSWM_CODE) ECUM_Action_BSW_InitThree(const bswm_action_list_item_t *item);
FUNC(Std_ReturnType, BSWM_CODE) ECUM_Action_RTE_Init(const bswm_action_list_item_t *item);
FUNC(Std_ReturnType, BSWM_CODE) ESH_Action_SelfRunRequestTimer_Start(const bswm_action_list_item_t *item);
FUNC(Std_ReturnType, BSWM_CODE) ESH_Action_WriteAllTimer_Stop(const bswm_action_list_item_t *item);
FUNC(Std_ReturnType, BSWM_CODE) ESH_Action_WriteAllTimer_Start(const bswm_action_list_item_t *item);
FUNC(Std_ReturnType, BSWM_CODE) ESH_Action_ESH_Wakeup(const bswm_action_list_item_t *item);
FUNC(Std_ReturnType, BSWM_CODE) ESH_Action_ESH_Run(const bswm_action_list_item_t *item);
FUNC(Std_ReturnType, BSWM_CODE) ESH_Action_ESH_PostRun(const bswm_action_list_item_t *item);
FUNC(Std_ReturnType, BSWM_CODE) ESH_Action_ESH_Prep(const bswm_action_list_item_t *item);
FUNC(Std_ReturnType, BSWM_CODE) ESH_Action_ESH_Wait(const bswm_action_list_item_t *item);
FUNC(Std_ReturnType, BSWM_CODE) ESH_Action_ESH_WaitToWakeup(const bswm_action_list_item_t *item);
FUNC(Std_ReturnType, BSWM_CODE) ESH_Action_ESH_Shutdown(const bswm_action_list_item_t *item);
FUNC(Std_ReturnType, BSWM_CODE) ReqFullcomAction(const bswm_action_list_item_t *item);
FUNC(Std_ReturnType, BSWM_CODE) ReqNocomAction(const bswm_action_list_item_t *item);
FUNC(Std_ReturnType, BSWM_CODE) RequestFullcomAction(const bswm_action_list_item_t *item);

/* Expression 声明 */
FUNC(boolean, BSWM_CODE) ECUM_LE_INIT(void);
FUNC(boolean, BSWM_CODE) ESH_LE_InitToWakeup(void);
FUNC(boolean, BSWM_CODE) ESH_LE_WakeupToRun(void);
FUNC(boolean, BSWM_CODE) ESH_LE_RunToPostRun(void);
FUNC(boolean, BSWM_CODE) ESH_LE_PostRun(void);
FUNC(boolean, BSWM_CODE) ESH_LE_PostRunToRun(void);
FUNC(boolean, BSWM_CODE) ESH_LE_PostRunToPrep(void);
FUNC(boolean, BSWM_CODE) ESH_LE_WakeupToPrep(void);
FUNC(boolean, BSWM_CODE) ESH_LE_PrepToWait(void);
FUNC(boolean, BSWM_CODE) ESH_LE_WaitToWakeup(void);
FUNC(boolean, BSWM_CODE) ESH_LE_WaitToShutdown(void);
FUNC(boolean, BSWM_CODE) StartCommunicationExp(void);
FUNC(boolean, BSWM_CODE) KeepComExp(void);

/* Local Fuction Implementation */

/* Action 定义 */
FUNC(Std_ReturnType, BSWM_CODE) ECUM_Action_BSW_InitTwo(const bswm_action_list_item_t *item)
{
	(void)*item;
	ecum_al_driver_init_two(ecum_world.config);

	return E_OK;
}

FUNC(Std_ReturnType, BSWM_CODE) ECUM_Action_BSW_InitThree(const bswm_action_list_item_t *item)
{
	(void)*item;
	ecum_al_driver_init_three(ecum_world.config);

	return E_OK;
}

FUNC(Std_ReturnType, BSWM_CODE) ECUM_Action_RTE_Init(const bswm_action_list_item_t *item)
{
	(void)*item;
	BswM_SchM_Rte_Init();

	return E_OK;
}

FUNC(Std_ReturnType, BSWM_CODE) ESH_Action_SelfRunRequestTimer_Start(const bswm_action_list_item_t *item)
{
	(void)*item;
	bswm_update_timer(item);

	return E_OK;
}

FUNC(Std_ReturnType, BSWM_CODE) ESH_Action_WriteAllTimer_Stop(const bswm_action_list_item_t *item)
{
	(void)*item;
	bswm_update_timer(item);

	return E_OK;
}

FUNC(Std_ReturnType, BSWM_CODE) ESH_Action_WriteAllTimer_Start(const bswm_action_list_item_t *item)
{
	(void)*item;
	bswm_update_timer(item);

	return E_OK;
}

FUNC(Std_ReturnType, BSWM_CODE) ESH_Action_ESH_Wakeup(const bswm_action_list_item_t *item)
{
	(void)*item;
	BswM_RequestMode(BSWM_ESH_User, BSWM_ESH_WAKEUP);

	return E_OK;
}

FUNC(Std_ReturnType, BSWM_CODE) ESH_Action_ESH_Run(const bswm_action_list_item_t *item)
{
	(void)*item;
	BswM_ESH_EnterRun();

	return E_OK;
}

FUNC(Std_ReturnType, BSWM_CODE) ESH_Action_ESH_PostRun(const bswm_action_list_item_t *item)
{
	(void)*item;
	BswM_ESH_RunToPostRun();

	return E_OK;
}

FUNC(Std_ReturnType, BSWM_CODE) ESH_Action_ESH_Prep(const bswm_action_list_item_t *item)
{
	(void)*item;
	BswM_RequestMode(BSWM_ESH_User, BSWM_ESH_PREP_SHUTDOWN);

	return E_OK;
}

FUNC(Std_ReturnType, BSWM_CODE) ESH_Action_ESH_Wait(const bswm_action_list_item_t *item)
{
	(void)*item;
	BswM_ESH_EnterWait();

	return E_OK;
}

FUNC(Std_ReturnType, BSWM_CODE) ESH_Action_ESH_WaitToWakeup(const bswm_action_list_item_t *item)
{
	(void)*item;
	BswM_ESH_WaitToWakeup();

	return E_OK;
}

FUNC(Std_ReturnType, BSWM_CODE) ESH_Action_ESH_Shutdown(const bswm_action_list_item_t *item)
{
	(void)*item;
	BswM_RequestMode(BSWM_ESH_User, BSWM_ESH_SHUTDOWN);

	return E_OK;
}

FUNC(Std_ReturnType, BSWM_CODE) ReqFullcomAction(const bswm_action_list_item_t *item)
{
	(void)*item;
	BswM_RequestFullCom();

	return E_OK;
}

FUNC(Std_ReturnType, BSWM_CODE) ReqNocomAction(const bswm_action_list_item_t *item)
{
	(void)*item;
	BswM_RequestNoCom();

	return E_OK;
}

FUNC(Std_ReturnType, BSWM_CODE) RequestFullcomAction(const bswm_action_list_item_t *item)
{
	(void)*item;
	ReqFullcom_callout();

	return E_OK;
}

/* Expression 定义 */
FUNC(boolean, BSWM_CODE) ECUM_LE_INIT(void)
{
	// coverity[cert_exp46_c_violation:SUPPRESS]
	return ( (BswM_EcuM_GetState() == ECUM_STATE_STARTUP_TWO) );
}

FUNC(boolean, BSWM_CODE) ESH_LE_InitToWakeup(void)
{
	// coverity[cert_exp46_c_violation:SUPPRESS]
	return ( (bswm_mode_req_mirrors[BSWM_ESH_STATE_REQ_IDX] == (uint32)BSWM_ESH_INIT) );
}

FUNC(boolean, BSWM_CODE) ESH_LE_WakeupToRun(void)
{
	// coverity[cert_exp46_c_violation:SUPPRESS]
	return ( (bswm_mode_req_mirrors[BSWM_ESH_STATE_REQ_IDX] == (uint32)BSWM_ESH_WAKEUP) &&
             (EcuM_GetValidatedWakeupEvents() != 0U) );
}

FUNC(boolean, BSWM_CODE) ESH_LE_RunToPostRun(void)
{
	// coverity[cert_exp46_c_violation:SUPPRESS]
	return ( (bswm_mode_req_mirrors[BSWM_ESH_STATE_REQ_IDX] == (uint32)BSWM_ESH_RUN) &&
             (hasRunRequests() == FALSE) &&
             (bswm_get_timer_state(ESH_SelfRunRequestTimer) == BSWM_TIMER_EXPIRED) );
}

FUNC(boolean, BSWM_CODE) ESH_LE_PostRun(void)
{
	// coverity[cert_exp46_c_violation:SUPPRESS]
	return ( (bswm_mode_req_mirrors[BSWM_ESH_STATE_REQ_IDX] == (uint32)BSWM_ESH_POST_RUN) );
}

FUNC(boolean, BSWM_CODE) ESH_LE_PostRunToRun(void)
{
	// coverity[cert_exp46_c_violation:SUPPRESS]
	return ( (hasRunRequests() == TRUE) ||
             (EcuM_GetValidatedWakeupEvents() != 0U) );
}

FUNC(boolean, BSWM_CODE) ESH_LE_PostRunToPrep(void)
{
	// coverity[cert_exp46_c_violation:SUPPRESS]
	return ( (hasPostRunRequests() == FALSE) );
}

FUNC(boolean, BSWM_CODE) ESH_LE_WakeupToPrep(void)
{
	// coverity[cert_exp46_c_violation:SUPPRESS]
	return ( (bswm_mode_req_mirrors[BSWM_ESH_STATE_REQ_IDX] == (uint32)BSWM_ESH_WAKEUP) &&
             (EcuM_GetValidatedWakeupEvents() == 0U) );
}

FUNC(boolean, BSWM_CODE) ESH_LE_PrepToWait(void)
{
	// coverity[cert_exp46_c_violation:SUPPRESS]
	return ( (bswm_mode_req_mirrors[BSWM_ESH_STATE_REQ_IDX] == (uint32)BSWM_ESH_PREP_SHUTDOWN) );
}

FUNC(boolean, BSWM_CODE) ESH_LE_WaitToWakeup(void)
{
	// coverity[cert_exp46_c_violation:SUPPRESS]
	return ( (bswm_mode_req_mirrors[BSWM_ESH_STATE_REQ_IDX] == (uint32)BSWM_ESH_WAIT_FOR_NVM) &&
             (EcuM_GetValidatedWakeupEvents() != 0U) );
}

FUNC(boolean, BSWM_CODE) ESH_LE_WaitToShutdown(void)
{
	// coverity[cert_exp46_c_violation:SUPPRESS]
	return ( (bswm_mode_req_mirrors[BSWM_ESH_STATE_REQ_IDX] == (uint32)BSWM_ESH_WAIT_FOR_NVM) &&
             (EcuM_GetValidatedWakeupEvents() == 0U) );
}

FUNC(boolean, BSWM_CODE) StartCommunicationExp(void)
{
	// coverity[cert_exp46_c_violation:SUPPRESS]
	return ( !(bswm_mode_req_mirrors[BSWM_STARTCOMMUNICATIONREQ_REQ_IDX] != (uint32)BSWM_UNDEFINED_REQUEST_VALUE) );
}

FUNC(boolean, BSWM_CODE) KeepComExp(void)
{
	// coverity[cert_exp46_c_violation:SUPPRESS]
	return ( (bswm_mode_req_mirrors[BSWM_KEEPCOMREQ_REQ_IDX] == (uint32)COMM_FULL_COMMUNICATION) );
}

#define BSWM_STOP_SEC_CODE
#include "bswm_memmap.h"

/* Expressions/Actions Mapping */
#define BSWM_START_SEC_CONST
#include "bswm_memmap.h"
static CONST(atomic_action_func_t, BSWM_CONST) bswm_atomic_actions[BSWM_NUMBER_OF_ATOMIC_ACTIONS] = {
	[BSWM_ECUM_ACTION_BSW_INITTWO_ACTION_IDX] = &ECUM_Action_BSW_InitTwo,
	[BSWM_ECUM_ACTION_BSW_INITTHREE_ACTION_IDX] = &ECUM_Action_BSW_InitThree,
	[BSWM_ECUM_ACTION_RTE_INIT_ACTION_IDX] = &ECUM_Action_RTE_Init,
	[BSWM_ESH_ACTION_SELFRUNREQUESTTIMER_START_ACTION_IDX] = &ESH_Action_SelfRunRequestTimer_Start,
	[BSWM_ESH_ACTION_WRITEALLTIMER_STOP_ACTION_IDX] = &ESH_Action_WriteAllTimer_Stop,
	[BSWM_ESH_ACTION_WRITEALLTIMER_START_ACTION_IDX] = &ESH_Action_WriteAllTimer_Start,
	[BSWM_ESH_ACTION_ESH_WAKEUP_ACTION_IDX] = &ESH_Action_ESH_Wakeup,
	[BSWM_ESH_ACTION_ESH_RUN_ACTION_IDX] = &ESH_Action_ESH_Run,
	[BSWM_ESH_ACTION_ESH_POSTRUN_ACTION_IDX] = &ESH_Action_ESH_PostRun,
	[BSWM_ESH_ACTION_ESH_PREP_ACTION_IDX] = &ESH_Action_ESH_Prep,
	[BSWM_ESH_ACTION_ESH_WAIT_ACTION_IDX] = &ESH_Action_ESH_Wait,
	[BSWM_ESH_ACTION_ESH_WAITTOWAKEUP_ACTION_IDX] = &ESH_Action_ESH_WaitToWakeup,
	[BSWM_ESH_ACTION_ESH_SHUTDOWN_ACTION_IDX] = &ESH_Action_ESH_Shutdown,
	[BSWM_REQFULLCOMACTION_ACTION_IDX] = &ReqFullcomAction,
	[BSWM_REQNOCOMACTION_ACTION_IDX] = &ReqNocomAction,
	[BSWM_REQUESTFULLCOMACTION_ACTION_IDX] = &RequestFullcomAction,
};

#define BSWM_STOP_SEC_CONST
#include "bswm_memmap.h"
#define BSWM_START_SEC_CONST
#include "bswm_memmap.h"
static CONST(logical_expression_func_t, BSWM_CONST) bswm_logical_expressions[BSWM_NUMBER_OF_LOGICAL_EXPRESSIONS] = {
	[BSWM_ECUM_LE_INIT_EXP_IDX] = &ECUM_LE_INIT,
	[BSWM_ESH_LE_INITTOWAKEUP_EXP_IDX] = &ESH_LE_InitToWakeup,
	[BSWM_ESH_LE_WAKEUPTORUN_EXP_IDX] = &ESH_LE_WakeupToRun,
	[BSWM_ESH_LE_RUNTOPOSTRUN_EXP_IDX] = &ESH_LE_RunToPostRun,
	[BSWM_ESH_LE_POSTRUN_EXP_IDX] = &ESH_LE_PostRun,
	[BSWM_ESH_LE_POSTRUNTORUN_EXP_IDX] = &ESH_LE_PostRunToRun,
	[BSWM_ESH_LE_POSTRUNTOPREP_EXP_IDX] = &ESH_LE_PostRunToPrep,
	[BSWM_ESH_LE_WAKEUPTOPREP_EXP_IDX] = &ESH_LE_WakeupToPrep,
	[BSWM_ESH_LE_PREPTOWAIT_EXP_IDX] = &ESH_LE_PrepToWait,
	[BSWM_ESH_LE_WAITTOWAKEUP_EXP_IDX] = &ESH_LE_WaitToWakeup,
	[BSWM_ESH_LE_WAITTOSHUTDOWN_EXP_IDX] = &ESH_LE_WaitToShutdown,
	[BSWM_STARTCOMMUNICATIONEXP_EXP_IDX] = &StartCommunicationExp,
	[BSWM_KEEPCOMEXP_EXP_IDX] = &KeepComExp,
};

#define BSWM_STOP_SEC_CONST
#include "bswm_memmap.h"

/* Global Variable Definition */
#define BSWM_START_SEC_SEMISHARED_BSS
#include "bswm_memmap.h"
static VAR(bswm_rule_state_t, BSWM_SEMISHARED_BSS) bswm_rule_states[BSWM_NUMBER_OF_RULES_MAX];
static VAR(boolean, BSWM_SEMISHARED_BSS) bswm_delayed_request[BSWM_NUMBER_OF_IMMEDIATE_REQUESTS];
#define BSWM_STOP_SEC_SEMISHARED_BSS
#include "bswm_memmap.h"

#define BSWM_START_SEC_SEMISHARED_DATA
#include "bswm_memmap.h"
VAR(bswm_internal_t, BSWM_SEMISHARED_DATA) bswm_internal = {
	.bswm_rule_states = bswm_rule_states,
	.bswm_delayed_request = bswm_delayed_request,
	.init_status = BSWM_UNINIT,
	.timers = timers,
	.timer_index = {
		.begin = 0,
		.end = BSWM_TIMERS_NUM,
	},
	.bswm_mode_req_mirrors = bswm_mode_req_mirrors,
	.bswm_atomic_actions = bswm_atomic_actions,
	.bswm_logical_expressions = bswm_logical_expressions,
};

#define BSWM_STOP_SEC_SEMISHARED_DATA
#include "bswm_memmap.h"

#define BSWM_START_SEC_MULTI_APP_DATA
#include "bswm_memmap.h"
VAR(bswm_internal_t *, BSWM_MULTI_APP_DATA)
bswm_multicore[BSWM_MAX_SUPPORT_CORENUM] = {
	&bswm_internal,
};

#define BSWM_STOP_SEC_MULTI_APP_DATA
#include "bswm_memmap.h"

/* ModeIndication validation */
/*  ComM */
#if (BSWM_COMM_ENABLED == STD_ON)
#define is_valid_comm_mode(_x)																						 \
	((COMM_FULL_COMMUNICATION == (_x)) || (COMM_SILENT_COMMUNICATION == (_x)) ||								   \
	 (COMM_NO_COMMUNICATION == (_x))) ///< COMM模式是否可用

#define is_valid_comm_pncmode(_x)																					  \
	((COMM_PNC_REQUESTED == (_x)) || (COMM_PNC_READY_SLEEP == (_x)) || (COMM_PNC_PREPARE_SLEEP == (_x)) ||		 \
	 (COMM_PNC_NO_COMMUNICATION == (_x)))
#endif ///< COMM PNC模式是否可用

/*  Nm */
#if (BSWM_NM_ENABLED == STD_ON)
#define is_valid_nm_mode(_x)																						   \
	((NM_STATE_BUS_SLEEP == (_x)) || (NM_STATE_PREPARE_BUS_SLEEP == (_x)) ||		  \
	 (NM_STATE_READY_SLEEP == (_x)) || (NM_STATE_NORMAL_OPERATION == (_x)) || (NM_STATE_REPEAT_MESSAGE == (_x)) || \
	 (NM_STATE_SYNCHRONIZE == (_x))) ///< NM 模式是否可用
#endif

/* EcuM */
#if (BSWM_ECUM_ENABLED == STD_ON)
#define is_valid_ecum_mode(_x)																						 \
	((ECUM_STATE_STARTUP_ONE == (_x)) || (ECUM_STATE_STARTUP_TWO == (_x)) || (ECUM_STATE_WAKEUP_ONE == (_x)) ||	\
	 (ECUM_STATE_WAKEUP_VALIDATION == (_x)) || (ECUM_STATE_WAKEUP_REACTION == (_x)) ||							 \
	 (ECUM_STATE_WAKEUP_TWO == (_x)) || (ECUM_STATE_APP_RUN == (_x)) || (ECUM_STATE_APP_POST_RUN == (_x)) ||	   \
	 (ECUM_STATE_PREP_SHUTDOWN == (_x)) || (ECUM_STATE_GO_SLEEP == (_x)) || (ECUM_STATE_GO_OFF_ONE == (_x)) ||	 \
	 (ECUM_STATE_GO_OFF_TWO == (_x)) || (ECUM_STATE_SLEEP == (_x))) ///< ECUM 模式是否可用

#define is_valid_ecum_wkstatus(_x)																					 \
	((ECUM_WKSTATUS_NONE == (_x)) || (ECUM_WKSTATUS_PENDING == (_x)) || (ECUM_WKSTATUS_VALIDATED == (_x)) ||	   \
	 (ECUM_WKSTATUS_EXPIRED == (_x)) || (ECUM_WKSTATUS_DISABLED == (_x))) ///< ECUM 唤醒状态是否可用

#define is_valid_ecum_reqstate(_x)																					 \
	((ECUM_RUNSTATUS_UNKNOWN == (_x)) || (ECUM_RUNSTATUS_REQUESTED == (_x)) ||									 \
	 (ECUM_RUNSTATUS_RELEASED == (_x))) ///< ECUM 请求状态是否可用
#endif

/*  CanSM */
#if (BSWM_CANSM_ENABLED == STD_ON)
#define is_valid_cansm_mode(_x)																						\
	((CANSM_BSWM_NO_COMMUNICATION == (_x)) || (CANSM_BSWM_SILENT_COMMUNICATION == (_x)) ||						 \
	 (CANSM_BSWM_FULL_COMMUNICATION == (_x)) || (CANSM_BSWM_BUS_OFF == (_x)) ||									\
	 (CANSM_BSWM_CHANGE_BAUDRATE == (_x))) ///< CANSM 模式是否可用
#endif

/*  LinSM */
#if (BSWM_LINSM_ENABLED == STD_ON)
#define is_valid_linsm_mode(_x) ((LINSM_NO_COM == (_x)) || (LINSM_FULL_COM == (_x))) ///< LIN 模式是否可用
#endif

/*  EthSM */
#if (BSWM_ETHSM_ENABLED == STD_ON)
#define is_valid_ethsm_mode(_x)																						\
	((ETHSM_STATE_OFFLINE == (_x)) || (ETHSM_STATE_WAIT_TRCVLINK == (_x)) || (ETHSM_STATE_WAIT_ONLINE == (_x)) ||  \
	 (ETHSM_STATE_ONLINE == (_x)) || (ETHSM_STATE_ONHOLD == (_x)) || (ETHSM_STATE_WAIT_OFFLINE == (_x)))
#endif ///< EthSM 模式是否可用

#define BSWM_START_SEC_CODE
#include "bswm_memmap.h"
FUNC(void, BSWM_CODE) bswm_internal_update_notification_mirrors(void)
{
	/* modeswitch 执行的时机是在mainfunction中,未考虑立即执行 */
	/* notify更新通知镜像 */
	/* moderequest更新通知镜像 */
}


/* 模式请求汇报状态 */
/* ComM */
#if (BSWM_USE_COMM == STD_ON)
FUNC(void, BSWM_CODE) bswm_comm_current_mode(network_handle_type network, comm_mode_type requested_mode)
{
	uint8 core_id = bswm_get_core_id();
	const bswm_internal_t *bswm_internal_ptr = bswm_multicore[core_id];

	bswm_validate_pointer_withcoreid_norv(bswm_internal_ptr, core_id,
						BSWM_BSWM_SERVICEID_COMMCURRENTMODE_BSWM_E_NULL_CONTROL_POINTER);
	bswm_validate_init_norv(BSWM_BSWM_SERVICEID_COMMCURRENTMODE_BSWM_E_NO_INIT,
				bswm_internal_ptr); /* @req BswM0078 */

	(void)network;
	(void)requested_mode;
#if (BSWM_COMM_ENABLED == STD_ON)
	bswm_validate_requestmode_norv(is_valid_comm_mode(requested_mode),
					   BSWM_BSWM_SERVICEID_COMMCURRENTMODE_BSWM_E_REQ_MODE_OUT_OF_RANGE);
	switch (network) {
	default:
		break;
	}
}
#endif

FUNC(void, BSWM_CODE) bswm_comm_current_pnc_mode(PNCHandleType pnc, comm_pnc_mode_type current_pnc_mode)
{
	uint8 core_id = bswm_get_core_id();
	const bswm_internal_t *bswm_internal_ptr = bswm_multicore[core_id];

	bswm_validate_pointer_withcoreid_norv(bswm_internal_ptr, core_id,
						  BSWM_BSWM_SERVICEID_COMMCURRENTPNCMODE_BSWM_E_NULL_CONTROL_POINTER);
	bswm_validate_init_norv(BSWM_BSWM_SERVICEID_COMMCURRENTPNCMODE_BSWM_E_NO_INIT,
				bswm_internal_ptr); /* @req BswM0149 */

	(void)pnc;
	(void)current_pnc_mode;

#if (BSWM_COMM_ENABLED == STD_ON)
	bswm_validate_requestmode_norv(is_valid_comm_pncmode(current_pnc_mode),
					   BSWM_BSWM_SERVICEID_COMMCURRENTPNCMODE_BSWM_E_REQ_MODE_OUT_OF_RANGE);
	switch (pnc) {
	default:
		break;
	}
#endif
}
#endif

/* Nm */
#if (CONFIG_MODULE_NM == 1)
FUNC(void, BSWM_CODE) bswm_nm_state_change_notification(network_handle_type network, nm_state_type current_state)
{
	uint8 core_id = bswm_get_core_id();
	const bswm_internal_t *bswm_internal_ptr = bswm_multicore[core_id];

	bswm_validate_pointer_withcoreid_norv(bswm_internal_ptr, core_id,
						  BSWM_BSWM_SERVICEID_NMCURRENTMODE_BSWM_E_NULL_CONTROL_POINTER);
	bswm_validate_init_norv(BSWM_BSWM_SERVICEID_NMCURRENTMODE_BSWM_E_NO_INIT, bswm_internal_ptr);

	(void)network;
	(void)current_state;

#if (BSWM_NM_ENABLED == STD_ON)
	bswm_validate_requestmode_norv(is_valid_nm_mode(current_state),
					   BSWM_BSWM_SERVICEID_NMCURRENTMODE_BSWM_E_REQ_MODE_OUT_OF_RANGE);
	switch (network) {
		default:
			break;
	}
#endif
}
#endif

/* EcuM */
#if (CONFIG_SERVM_ECUM == 1)

FUNC(void, BSWM_CODE) bswm_ecum_current_state(ecum_state_t current_state)
{
	uint8 core_id = bswm_get_core_id();
	const bswm_internal_t *bswm_internal_ptr = bswm_multicore[core_id];

	bswm_validate_pointer_withcoreid_norv(bswm_internal_ptr, core_id,
						  BSWM_BSWM_SERVICEID_ECUMCURRENTSTATE_BSWM_E_NULL_CONTROL_POINTER);
	bswm_validate_init_norv(BSWM_BSWM_SERVICEID_ECUMCURRENTSTATE_BSWM_E_NO_INIT,
				bswm_internal_ptr); /* @req BswM0084 */
	/* !req BswM0103 */

	(void)current_state;

#if (BSWM_ECUM_ENABLED == STD_ON)
	bswm_validate_requestmode_norv(is_valid_ecum_mode(current_state),
					   BSWM_BSWM_SERVICEID_ECUMCURRENTSTATE_BSWM_E_REQ_MODE_OUT_OF_RANGE);
#endif
}

FUNC(void, BSWM_CODE) bswm_ecum_current_wakeup(ecum_wakeup_source_t source, ecum_wakeup_status_t state)
{
	uint8 core_id = bswm_get_core_id();
	const bswm_internal_t *bswm_internal_ptr = bswm_multicore[core_id];

	bswm_validate_pointer_withcoreid_norv(bswm_internal_ptr, core_id,
						  BSWM_BSWM_SERVICEID_ECUMCURRENTWAKEUP_BSWM_E_NULL_CONTROL_POINTER);
	bswm_validate_init_norv(BSWM_BSWM_SERVICEID_ECUMCURRENTWAKEUP_BSWM_E_NO_INIT,
				bswm_internal_ptr); /* @req BswM0132 */
	/* !req BswM0133 */

	(void)source;
	(void)state;

#if (BSWM_ECUM_ENABLED == STD_ON)
	bswm_validate_requestmode_norv(is_valid_ecum_wkstatus(state),
					   BSWM_BSWM_SERVICEID_ECUMCURRENTWAKEUP_BSWM_E_REQ_MODE_OUT_OF_RANGE);
	switch (source) {
	default:
		break;
	}
#endif
}

FUNC(void, BSWM_CODE) bswm_ecum_requested_state(ecum_state_t state, ecum_run_status_t current_status)
{
	(void)state;
	(void)current_status;
	uint8 core_id = bswm_get_core_id();
	const bswm_internal_t *bswm_internal_ptr = bswm_multicore[core_id];

	bswm_validate_pointer_withcoreid_norv(bswm_internal_ptr, core_id,
						  BSWM_BSWM_SERVICEID_ECUMREQUEST_BSWM_E_NULL_CONTROL_POINTER);
	bswm_validate_init_norv(BSWM_BSWM_SERVICEID_ECUMREQUEST_BSWM_E_NO_INIT, bswm_internal_ptr);

#if (BSWM_ECUM_ENABLED == STD_ON)
	bswm_validate_requestmode_norv(is_valid_ecum_reqstate(current_status),
					   BSWM_BSWM_SERVICEID_ECUMREQUEST_BSWM_E_REQ_MODE_OUT_OF_RANGE);
	switch (state) {
	default:
		break;
	}
#endif
}

#endif /* if defined(CONFIG_SERVM_ECUM) */

/* CanSM */
#if (CONFIG_MODULE_CANSM == 1)
FUNC(void, BSWM_CODE) bswm_cansm_current_state(network_handle_type network, cansm_bswm_current_state_type current_state)
{
	(void)network;
	(void)current_state;
	uint8 core_id = bswm_get_core_id();
	const bswm_internal_t *bswm_internal_ptr = bswm_multicore[core_id];

	if (bswm_internal_ptr != NULL_PTR) {
		bswm_validate_init_norv(BSWM_BSWM_SERVICEID_CANSMCURRENTSTATE_BSWM_E_NO_INIT, bswm_internal_ptr);
	}

#if (BSWM_CANSM_ENABLED == STD_ON)
	bswm_validate_requestmode_norv(is_valid_cansm_mode(current_state),
					   BSWM_BSWM_SERVICEID_CANSMCURRENTSTATE_BSWM_E_REQ_MODE_OUT_OF_RANGE);
	switch (network) {
	default:
		break;
	}
#endif
}
#endif

/* EthSM */
#if (BSWM_USE_ETHSM == STD_ON)
FUNC(void, BSWM_CODE) bswm_ethsm_current_state(network_handle_type network, ethsm_network_mode_state_type current_state)
{
	(void)network;
	(void)current_state;
	uint8 core_id = bswm_get_core_id();
	const bswm_internal_t *bswm_internal_ptr = bswm_multicore[core_id];

	if (bswm_internal_ptr != NULL_PTR) {
		bswm_validate_init_norv(BSWM_BSWM_SERVICEID_ETHSMCURRENTSTATE_BSWM_E_NO_INIT, bswm_internal_ptr);
	}

#if (BSWM_ETHSM_ENABLED == STD_ON)
	bswm_validate_requestmode_norv(is_valid_ethsm_mode(current_state),
					   BSWM_BSWM_SERVICEID_ETHSMCURRENTSTATE_BSWM_E_REQ_MODE_OUT_OF_RANGE);
	switch (network) {
	default:
		break;
	}
#endif
}
#endif



/* LinSM */
#if (BSWM_USE_LINSM == STD_ON)
FUNC(void, BSWM_CODE) bswm_linsm_current_schedule(network_handle_type network, linif_sch_handle_type current_schedule)
{
	(void)network;
	(void)current_schedule;
	uint8 core_id = bswm_get_core_id();
	const bswm_internal_t *bswm_internal_ptr = bswm_multicore[core_id];

	bswm_validate_pointer_withcoreid_norv(bswm_internal_ptr, core_id,
						  BSWM_BSWM_SERVICEID_LINSMCURRENTSCHEDULE_BSWM_E_NULL_CONTROL_POINTER);
	bswm_validate_init_norv(BSWM_BSWM_SERVICEID_LINSMCURRENTSCHEDULE_BSWM_E_NO_INIT, bswm_internal_ptr);

	(void)vcos_log(BSWM_MODULE_ID, VCOS_LOG_INFO, BSWM_DLT_LIN_SCHEDULE, network, current_schedule);

#if (BSWM_LINSM_ENABLED == STD_ON)
	switch (network) {
	default:
		break;
	}
#endif
}

FUNC(void, BSWM_CODE) bswm_linsm_current_state(network_handle_type network, linsm_mode_type current_state)
{
	(void)network;
	(void)current_state;
	uint8 core_id = bswm_get_core_id();
	const bswm_internal_t *bswm_internal_ptr = bswm_multicore[core_id];

	bswm_validate_pointer_withcoreid_norv(bswm_internal_ptr, core_id,
						  BSWM_BSWM_SERVICEID_LINSMCURRENTSTATE_BSWM_E_NULL_CONTROL_POINTER);
	bswm_validate_init_norv(BSWM_BSWM_SERVICEID_LINSMCURRENTSTATE_BSWM_E_NO_INIT, bswm_internal_ptr);

#if (BSWM_LINSM_ENABLED == STD_ON)
	bswm_validate_requestmode_norv(is_valid_linsm_mode(current_state),
					   BSWM_BSWM_SERVICEID_LINSMCURRENTSTATE_BSWM_E_REQ_MODE_OUT_OF_RANGE);
	switch (network) {
	default:
		reak;
	}
#endif
}

FUNC(void, BSWM_CODE) bswm_lintp_request_mode(network_handle_type network, lintp_mode lintp_requested_mode)
{
	(void)network;
	(void)lintp_requested_mode;

#if (BSWM_LINTP_ENABLED == STD_ON)
	switch (network) {
	default:
		break;
	}
#endif
}
#endif

/* Dcm */
#if (BSWM_USE_DCM == STD_ON)
FUNC(void, BSWM_CODE) bswm_dcm_application_updated(void)
{
}

FUNC(void, BSWM_CODE)
bswm_dcm_communication_mode_current_state(network_handle_type network, dcm_comm_mode_type requested_mode)
{
	(void)network;
	(void)requested_mode;

#if (BSWM_DCM_ENABLED == STD_ON)
	switch (network) {
	default:
		/* do nothing */
		break;
	}
#endif
}
#endif


FUNC(void, BSWM_CODE) bswm_request_mode(bswm_user_t requesting_user, bswm_mode_t requested_mode)
{
	(void)requesting_user;
	(void)requested_mode;

#if (BSWM_GENERICREQUEST_ENABLED == STD_ON)
	switch (requesting_user) {
	case 1:
		bswm_mode_req_mirrors[BSWM_ESH_STATE_REQ_IDX] = (uint32)requested_mode;
		bswm_process_immediate_request(2, 9);
		break;
	default:
		break;
	}
#endif
}

/* NvM */
#if (BSWM_USE_NVM == STD_ON)
FUNC(void, BSWM_CODE)
bswm_nvm_current_job_mode(nvm_multi_block_request_t multi_block_request, nvm_request_result_type current_job_mode)
{
	(void)multi_block_request;
	(void)current_job_mode;

#if (BSWM_NVM_ENABLED == STD_ON)
	switch (multi_block_request) {
	default:
		break;
	}
#endif
}

FUNC(void, BSWM_CODE) bswm_nvm_current_block_mode(nvm_block_id_t block, nvm_request_result_type current_block_mode)
{
	(void)block;
	(void)current_block_mode;

#if (BSWM_NVM_ENABLED == STD_ON)
	switch (block) {
	default:
		break;
	}
#endif
}
#endif
#define BSWM_STOP_SEC_CODE
#include "bswm_memmap.h"