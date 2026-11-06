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
 * @file        canif_can.h
 * @brief       CanIf Can配置头文件
 * @details     主要包含CanIf Can模块的配置相关信息
 * @date        2026-10-25 11:56:55
 * @toolversion V0.1.0-DEV
 **********************************************************************************************************************/

#ifndef CANIF_CAN_H
#define CANIF_CAN_H

#include "Can_17_McmCan.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define _canif_can_write(a, b) (Can_17_McmCan_Write((a), (b))) ///< can发送驱动接口
#define _canif_can_set_controller_mode(a, b) (Can_17_McmCan_SetControllerMode((a), (b))) ///< can设置控制器模式接口

#ifdef __cplusplus
}
#endif

#endif /* CANIF_CAN_H */
