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
 * @file        IoHwAb.h
 * @brief       Private header of the IoHwAb software component
 * @details     Declares the runnable entity of gen_data/Rte/Rte_IoHwAb.h and the
 *              simulated actuator state (SYS-FUN-001).
 **********************************************************************************************************************/

#ifndef IOHWAB_H_
#define IOHWAB_H_

#include "Std_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Runnable entity; Rte_IoHwAb.h declares it only for RTE_CORE builds. */
void IoHwAb_10ms(void);

/* SYS-FUN-001: no Dio/PWM MCAL on this target, the actuator state is the output.
 * 0 = LED off, 1 = LED on; duty is the physical PwmDuty in percent (0..100). */
extern volatile uint8 g_ecu_led_on;
extern volatile uint8 g_ecu_pwm_duty;

#ifdef __cplusplus
}
#endif

#endif /* IOHWAB_H_ */
