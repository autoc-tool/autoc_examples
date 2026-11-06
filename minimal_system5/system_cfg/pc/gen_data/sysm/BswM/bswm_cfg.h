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
 * @file		bswm_cfg.h
 * @brief	    BswM配置头文件
 * @details	    声明BswM模块的配置相关相关信息
 * @date		Generation Time : 2026-10-24 23:59:17
 * @toolversion Tool Version    : V0.1.0-DEV
 **********************************************************************************************************************/

#ifndef BSWM_CFG_H
#define BSWM_CFG_H

#include "stdint.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* Global Macro Definition */

/* 和 BswM 交互的其他模块宏信息 */
#define BSWM_USE_COMM	   (STD_ON) ///< BswM 使能 BSWM_USE_COMM 交互
#define BSWM_USE_CANSM	   (STD_ON) ///< BswM 使能 BSWM_USE_CANSM 交互
#define BSWM_MULTICORE_USAGE (STD_ON)
#define BSWM_MAX_SUPPORT_CORENUM (1)

/* BswM 和其他BSW 模块交互开关 */
#define BSWM_CANSM_ENABLED						   (STD_ON)	///< BswM 使能/关闭 CANSM功能
#define BSWM_CANSMICOM_ENABLED						   (STD_OFF)	///< BswM 使能/关闭 CANSMICOM功能
#define BSWM_COMM_ENABLED						   (STD_ON)	///< BswM 使能/关闭 COMM功能
#define BSWM_DCM_ENABLED						   (STD_ON)	///< BswM 使能/关闭 DCM功能
#define BSWM_DEV_ERROR_DETECT							  (STD_ON)  ///< BswM 使能/关闭错误检测
#define BSWM_ECUM_ENABLED						   (STD_ON)	///< BswM 使能/关闭 ECUM功能
#define BSWM_ETHIF_ENABLED						   (STD_OFF)	///< BswM 使能/关闭 ETHIF功能
#define BSWM_ETHSM_ENABLED						   (STD_ON)	///< BswM 使能/关闭 ETHSM功能
#define BSWM_FRSM_ENABLED						   (STD_OFF)	///< BswM 使能/关闭 FRSM功能
#define BSWM_GENERICREQUEST_ENABLED						   (STD_ON)	///< BswM 使能/关闭 GENERICREQUEST功能
#define BSWM_J1939DCM_ENABLED						   (STD_OFF)	///< BswM 使能/关闭 J1939DCM功能
#define BSWM_J1939NM_ENABLED						   (STD_OFF)	///< BswM 使能/关闭 J1939NM功能
#define BSWM_LINSM_ENABLED						   (STD_OFF)	///< BswM 使能/关闭 LINSM功能
#define BSWM_LINTP_ENABLED						   (STD_OFF)	///< BswM 使能/关闭 LINTP功能
#define BSWM_NM_ENABLED						   (STD_OFF)	///< BswM 使能/关闭 NM功能
#define BSWM_NVM_ENABLED						   (STD_ON)	///< BswM 使能/关闭 NVM功能
#define BSWM_SCHM_ENABLED						   (STD_OFF)	///< BswM 使能/关闭 SCHM功能
#define BSWM_SD_ENABLED						   (STD_OFF)	///< BswM 使能/关闭 SD功能
#define BSWM_VERSION_INFO_API							  (STD_ON)  ///< BswM 使能/关闭获取版本信息宏
#define BSWM_WDGM_ENABLED						   (STD_OFF)	///< BswM 使能/关闭 WDGM功能
#define BSWM_MAIN_FUNCTION_PERIOD							  (10u)  ///< 定义主函数执行周期


/* 不同 BswM timers */
#define ESH_SelfRunRequestTimer										  (0u)		  ///< BswM ESH_SelfRunRequestTimer 宏定义
#define ESH_NvM_WriteAllTimer										  (1u)		  ///< BswM ESH_NvM_WriteAllTimer 宏定义

/* BswM Timer 的数量 */
#define BSWM_TIMERS_NUM										(2u)	  ///<  BswM Timer 的数量

/* 不同Actions的数量 */
#define BSWM_PDUGROUPSWITCH_ACTIONS							(0u)	  ///< PDU组切换相关的Actions数量
#define BSWM_DEADLINEMONITORING_ACTIONS						(0u)	  ///< 死线监控相关的Actions数量
#define BSWM_PDUROUTERCONTROL_ACTIONS						  (0u)	  ///< PDU路由控制相关的Actions数量
#define BSWM_NMCONTROL_ACTIONS								 (0u)	  ///< 网络管理控制相关的Actions数量
/* Atomic Actions 的索引 */
#define BSWM_ECUM_ACTION_BSW_INITTWO_ACTION_IDX			  (0u)  ///< ECUM_ACTION_BSW_INITTWOActions 的索引
#define BSWM_ECUM_ACTION_BSW_INITTHREE_ACTION_IDX			  (1u)  ///< ECUM_ACTION_BSW_INITTHREEActions 的索引
#define BSWM_ECUM_ACTION_RTE_INIT_ACTION_IDX			  (2u)  ///< ECUM_ACTION_RTE_INITActions 的索引
#define BSWM_ESH_ACTION_SELFRUNREQUESTTIMER_START_ACTION_IDX			  (3u)  ///< ESH_ACTION_SELFRUNREQUESTTIMER_STARTActions 的索引
#define BSWM_ESH_ACTION_WRITEALLTIMER_STOP_ACTION_IDX			  (4u)  ///< ESH_ACTION_WRITEALLTIMER_STOPActions 的索引
#define BSWM_ESH_ACTION_WRITEALLTIMER_START_ACTION_IDX			  (5u)  ///< ESH_ACTION_WRITEALLTIMER_STARTActions 的索引
#define BSWM_ESH_ACTION_ESH_WAKEUP_ACTION_IDX			  (6u)  ///< ESH_ACTION_ESH_WAKEUPActions 的索引
#define BSWM_ESH_ACTION_ESH_RUN_ACTION_IDX			  (7u)  ///< ESH_ACTION_ESH_RUNActions 的索引
#define BSWM_ESH_ACTION_ESH_POSTRUN_ACTION_IDX			  (8u)  ///< ESH_ACTION_ESH_POSTRUNActions 的索引
#define BSWM_ESH_ACTION_ESH_PREP_ACTION_IDX			  (9u)  ///< ESH_ACTION_ESH_PREPActions 的索引
#define BSWM_ESH_ACTION_ESH_WAIT_ACTION_IDX			  (10u)  ///< ESH_ACTION_ESH_WAITActions 的索引
#define BSWM_ESH_ACTION_ESH_WAITTOWAKEUP_ACTION_IDX			  (11u)  ///< ESH_ACTION_ESH_WAITTOWAKEUPActions 的索引
#define BSWM_ESH_ACTION_ESH_SHUTDOWN_ACTION_IDX			  (12u)  ///< ESH_ACTION_ESH_SHUTDOWNActions 的索引
#define BSWM_REQFULLCOMACTION_ACTION_IDX			  (13u)  ///< REQFULLCOMACTIONActions 的索引
#define BSWM_REQNOCOMACTION_ACTION_IDX			  (14u)  ///< REQNOCOMACTIONActions 的索引
#define BSWM_REQUESTFULLCOMACTION_ACTION_IDX			  (15u)  ///< REQUESTFULLCOMACTIONActions 的索引
#define BSWM_NUMBER_OF_ATOMIC_ACTIONS				   (16u)	 ///< BSWM Actions 索引总数
/* 逻辑表达式的索引 */
#define BSWM_ECUM_LE_INIT_EXP_IDX					 (0u) ///< ECUM_LE_INIT逻辑表达式索引
#define BSWM_ESH_LE_INITTOWAKEUP_EXP_IDX					 (1u) ///< ESH_LE_INITTOWAKEUP逻辑表达式索引
#define BSWM_ESH_LE_WAKEUPTORUN_EXP_IDX					 (2u) ///< ESH_LE_WAKEUPTORUN逻辑表达式索引
#define BSWM_ESH_LE_RUNTOPOSTRUN_EXP_IDX					 (3u) ///< ESH_LE_RUNTOPOSTRUN逻辑表达式索引
#define BSWM_ESH_LE_POSTRUN_EXP_IDX					 (4u) ///< ESH_LE_POSTRUN逻辑表达式索引
#define BSWM_ESH_LE_POSTRUNTORUN_EXP_IDX					 (5u) ///< ESH_LE_POSTRUNTORUN逻辑表达式索引
#define BSWM_ESH_LE_POSTRUNTOPREP_EXP_IDX					 (6u) ///< ESH_LE_POSTRUNTOPREP逻辑表达式索引
#define BSWM_ESH_LE_WAKEUPTOPREP_EXP_IDX					 (7u) ///< ESH_LE_WAKEUPTOPREP逻辑表达式索引
#define BSWM_ESH_LE_PREPTOWAIT_EXP_IDX					 (8u) ///< ESH_LE_PREPTOWAIT逻辑表达式索引
#define BSWM_ESH_LE_WAITTOWAKEUP_EXP_IDX					 (9u) ///< ESH_LE_WAITTOWAKEUP逻辑表达式索引
#define BSWM_ESH_LE_WAITTOSHUTDOWN_EXP_IDX					 (10u) ///< ESH_LE_WAITTOSHUTDOWN逻辑表达式索引
#define BSWM_STARTCOMMUNICATIONEXP_EXP_IDX					 (11u) ///< STARTCOMMUNICATIONEXP逻辑表达式索引
#define BSWM_KEEPCOMEXP_EXP_IDX					 (12u) ///< KEEPCOMEXP逻辑表达式索引
#define BSWM_NUMBER_OF_LOGICAL_EXPRESSIONS			  (13u) ///< BSWM逻辑表达式索引总数





#define BSWM_IMMEDIATE_REQUEST_NEED_RESET_MIRROR_IDX_MAX	   (11u) ///< 立刻请求需要重置镜像的最大索引

#define BSWM_NUMBER_OF_IMMEDIATE_REQUESTS					  (10u)   ///< 立刻请求的数量	 

#define BSWM_NUMBER_OF_IMMEDIATE_ONINIT_REQUESTS					  (10u) ///< 立刻请求OnInit的数量 


#define BSWM_ECUM_GETSTATEREQ_REQ_IDX				 (0u)  ///< ECUM_GETSTATEREQ请求索引编号
#define BSWM_ESH_ECUM_GETPENDINGWAKEUPEVENTS_REQ_IDX				 (1u)  ///< ESH_ECUM_GETPENDINGWAKEUPEVENTS请求索引编号
#define BSWM_ESH_ECUM_GETVALIDATEDWAKEUPEVENTS_REQ_IDX				 (2u)  ///< ESH_ECUM_GETVALIDATEDWAKEUPEVENTS请求索引编号
#define BSWM_ESH_SELFRUNREQUESTTIMER_REQ_IDX				 (3u)  ///< ESH_SELFRUNREQUESTTIMER请求索引编号
#define BSWM_ESH_RUNREQUEST_1_REQ_IDX				 (4u)  ///< ESH_RUNREQUEST_1请求索引编号
#define BSWM_ESH_POSTRUNREQUEST_1_REQ_IDX				 (5u)  ///< ESH_POSTRUNREQUEST_1请求索引编号
#define BSWM_ESH_NVM_WRITEALLTIMER_REQ_IDX				 (6u)  ///< ESH_NVM_WRITEALLTIMER请求索引编号
#define BSWM_ESH_STATE_REQ_IDX				 (7u)  ///< ESH_STATE请求索引编号
#define BSWM_KEEPCOMREQ_REQ_IDX				 (8u)  ///< KEEPCOMREQ请求索引编号
#define BSWM_BSWCOMMINDICATIONREQ_REQ_IDX				 (9u)  ///< BSWCOMMINDICATIONREQ请求索引编号
#define BSWM_STARTCOMMUNICATIONREQ_REQ_IDX				 (10u)  ///< STARTCOMMUNICATIONREQ请求索引编号
#define BSWM_NUMBER_OF_REQUESTS						 (11u)  ///< 请求索引总数



/* 规则的索引 */
#define BSWM_ECUM_MODULEINIT_RULE_IDX						 (0u) ///< ECUM_MODULEINIT索引规则编号
#define BSWM_ESH_INITTOWAKEUP_RULE_IDX						 (1u) ///< ESH_INITTOWAKEUP索引规则编号
#define BSWM_ESH_WAKEUPTORUN_RULE_IDX						 (2u) ///< ESH_WAKEUPTORUN索引规则编号
#define BSWM_ESH_RUNTOPOSTRUN_RULE_IDX						 (3u) ///< ESH_RUNTOPOSTRUN索引规则编号
#define BSWM_ESH_POSTRUN_RULE_IDX						 (4u) ///< ESH_POSTRUN索引规则编号
#define BSWM_ESH_POSTRUNNESTED_RULE_IDX						 (5u) ///< ESH_POSTRUNNESTED索引规则编号
#define BSWM_ESH_POSTRUNTOPREPNESTED_RULE_IDX						 (6u) ///< ESH_POSTRUNTOPREPNESTED索引规则编号
#define BSWM_ESH_WAKEUPTOPREP_RULE_IDX						 (7u) ///< ESH_WAKEUPTOPREP索引规则编号
#define BSWM_ESH_PREPTOWAIT_RULE_IDX						 (8u) ///< ESH_PREPTOWAIT索引规则编号
#define BSWM_ESH_WAITTOWAKEUP_RULE_IDX						 (9u) ///< ESH_WAITTOWAKEUP索引规则编号
#define BSWM_ESH_WAITTOSHUTDOWN_RULE_IDX						 (10u) ///< ESH_WAITTOSHUTDOWN索引规则编号
#define BSWM_STARTCOMMUNICATIONRULE_RULE_IDX						 (11u) ///< STARTCOMMUNICATIONRULE索引规则编号
#define BSWM_KEEPCOMRULE_RULE_IDX						 (12u) ///< KEEPCOMRULE索引规则编号
#define BSWM_NUMBER_OF_RULES						 (13u) ///< 索引规则总数


/* 规则的最大数量 */
#define BSWM_NUMBER_OF_RULES_MAX							   (14u) ///< 索引规则最大总数

#if (BSWM_NUMBER_OF_RULES > BSWM_NUMBER_OF_RULES_MAX)
#error BswM: Configured maximum number of rules is less than the number of rules in configuration!
#endif



#define BSWM_ECUM_AL_INIT_LIST_IDX			(0u) ///< ECUM_AL_INIT Action索引编号
#define BSWM_ESH_AL_INITTOWAKEUP_LIST_IDX			(1u) ///< ESH_AL_INITTOWAKEUP Action索引编号
#define BSWM_ESH_AL_WAKEUPTORUN_LIST_IDX			(2u) ///< ESH_AL_WAKEUPTORUN Action索引编号
#define BSWM_ESH_AL_RUNTOPOSTRUN_LIST_IDX			(3u) ///< ESH_AL_RUNTOPOSTRUN Action索引编号
#define BSWM_ESH_AL_EXITPOSTRUN_LIST_IDX			(4u) ///< ESH_AL_EXITPOSTRUN Action索引编号
#define BSWM_ESH_AL_POSTRUNTORUN_LIST_IDX			(5u) ///< ESH_AL_POSTRUNTORUN Action索引编号
#define BSWM_ESH_AL_ESH_POSTRUNTOPREPCHECK_LIST_IDX			(6u) ///< ESH_AL_ESH_POSTRUNTOPREPCHECK Action索引编号
#define BSWM_ESH_AL_POSTRUNTOPREP_LIST_IDX			(7u) ///< ESH_AL_POSTRUNTOPREP Action索引编号
#define BSWM_ESH_AL_PREPTOWAIT_LIST_IDX			(8u) ///< ESH_AL_PREPTOWAIT Action索引编号
#define BSWM_ESH_AL_WAITTOWAKEUP_LIST_IDX			(9u) ///< ESH_AL_WAITTOWAKEUP Action索引编号
#define BSWM_ESH_AL_WAITTOSHUTDOWN_LIST_IDX			(10u) ///< ESH_AL_WAITTOSHUTDOWN Action索引编号
#define BSWM_REQFULLCOMLIST_LIST_IDX			(11u) ///< REQFULLCOMLIST Action索引编号
#define BSWM_REQNOCOMLIST_LIST_IDX			(12u) ///< REQNOCOMLIST Action索引编号
#define BSWM_STARTCOMMUNICATIONLIST_LIST_IDX			(13u) ///< STARTCOMMUNICATIONLIST Action索引编号
#define BSWM_NUMBER_OF_ACTIONLISTS						 (14u)	 ///<	BSWM Action总数
/*!*********************************************************************************************************************
 * @brief		  BswM初始状态下的即刻执行规则集合
 **********************************************************************************************************************/
extern const sint16 bswm_immediate_rules_on_init[BSWM_NUMBER_OF_IMMEDIATE_ONINIT_REQUESTS];
/*!*********************************************************************************************************************
 * @brief		  更新BswM内部的通知镜像状态
 * @details		该函数负责更新基础软件模块管理器BswM内部的通知镜像
 * @reentrant	  不可重入
 * @synchronous	同步
 **********************************************************************************************************************/
extern void bswm_internal_update_notification_mirrors(void);
#ifdef __cplusplus
}
#endif

#endif /* BSWM_BSWM_CFG_H */