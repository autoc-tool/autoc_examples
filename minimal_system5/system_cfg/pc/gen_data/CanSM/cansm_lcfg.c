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
 * Generation Time : 2026-10-24 23:59:14
 * Project Name    : minimal_system5
 * Tool Version    : V0.1.0-DEV
 * Description:  CanSM的动态代码文件
 */

#include "cansm.h"
#include "cansm_cfg.h"
#include "cansm_lcfg.h"
#include "canif.h"
#include "cansm_types.h"
#include "comm.h"
#if (CONFIG_MODULE_DEM == 1)
#include "dem.h"
#endif


/* ComM的ChannelId映射到CanSM的网络Id 
 ComMChannel句柄                                CanSMNetworkIndex
 ComMConf_ComMChannel_ComMChannel_0        ->   0
*/
#define CANSM_CONFIG_TABLE_LEN_CORE0 1u
#define CANSM_START_SEC_CONST
#include "cansm_memmap.h"
static const cansm_network_type cansm_network_config_core0[] = {
    {
        .id_net = ComMConf_ComMChannel_ComMChannel_0,
        .cansm_en_bor_time_tx = 400,  //2000ms
        .cansm_l1_bor_tm = 20,  //100ms
        .cansm_l2_bor_tm = 200,  //1000ms
        .cansm_l1_to_l2_bor_cnt = 5,
        .cansm_val_comp = 2,
#if defined(CONFIG_MODULE_DEM) && (CONFIG_MODULE_DEM == 1)
        .cansm_bsof_dem_evt_id = DEM_EVENT_ID_NULL,
#endif
        .canif_id_ctrl = CanIfConf_CanIfCtrlCfg_CanController_0,
        .can_en_trcv = (boolean)FALSE,
        .cantrcv_en_pn = (boolean)FALSE,
        .canif_id_trcv = INVALID_TRANSCEIVER_ID,
        .cansm_req_md_rept_tm = 20,  //100ms 
    },
};
#define CANSM_STOP_SEC_CONST
#include "cansm_memmap.h"


#define CANSM_START_SEC_CONST
#include "cansm_memmap.h"
static const cansm_network_config_type cansm_network_config_core_table[] = {
    { /* Core0 */
        .net_cfg_tbl_add = &cansm_network_config_core0[0u],
        .network_cfg_tbl_len = CANSM_CONFIG_TABLE_LEN_CORE0,
    },
};
#define CANSM_STOP_SEC_CONST
#include "cansm_memmap.h"

#define CANSM_START_SEC_CONST
#include "cansm_memmap.h"
const cansm_config_type cansm_config = {
    .cansm_mode_request_repetition_max = 10,
    .networks = cansm_network_config_core_table,
    .bus_off_begin_fnc = CANSM_RUNNABLE_BUSOFF_BEGIN_FNC,
    .bus_off_end_fnc = CANSM_RUNNABLE_BUSOFF_END_FNC,
};
#define CANSM_STOP_SEC_CONST
#include "cansm_memmap.h"