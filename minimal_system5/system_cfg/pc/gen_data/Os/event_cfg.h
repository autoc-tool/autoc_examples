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
 * Description: Event Mask Configuration
 * AutoGenerate Code, DO NOT EDIT!!!
 * Generation Time : 2026-10-24 23:59:27
 * Project Name    : minimal_system5
 * Tool Version    : V0.1.0-DEV
 */

#ifndef RT_FRAMEWORK_INC_OS_EVENT_CFG_H
#define RT_FRAMEWORK_INC_OS_EVENT_CFG_H

#ifdef __cplusplus
extern "C"
{
#endif

/* event mask for Os_Task_OsTask_100ms_ID */
#define RTE_EV_CYCLIC_OSTASK_100MS_0_100MS      (1u << 0)

/* event mask for Os_Task_OsTask_10ms_ID */
#define RTE_EV_CYCLIC2_OSTASK_10MS_0_10MS      (1u << 2)
#define RTE_EV_CYCLIC2_OSTASK_10MS_0_5MS      (1u << 0)
#define RTE_EV_CYCLIC_OSTASK_10MS_0_10MS      (1u << 1)

/* event mask for Os_Task_OsTask_Init_ID */
#define RTE_EV_RUN_MINIMALSYSTEMAPP_RE_INIT      (1u << 0)

#ifdef __cplusplus
}
#endif

#endif	 /* RT_FRAMEWORK_INC_OS_EVENT_CFG_H */
