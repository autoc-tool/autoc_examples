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
 * @file        IoHwAb.c
 * @brief       I/O hardware abstraction software component
 * @details     Reads IoIn_R (Implicit S/R from MinimalSystem.IoOut_P) in the
 *              10 ms runnable and drives the simulated actuator output
 *              (SYS-FUN-001). Additionally polls the Can driver, because this
 *              PC target has no BSW timing event for Can: Can_MainFunction_Read /
 *              _Write / _BusOff / _Mode are only reached from here.
 **********************************************************************************************************************/

#include <stdio.h>

#include "Rte_IoHwAb.h" /* generated RTE: implicit S/R macros, types */
#include "IoHwAb.h"
#include "Can.h"        /* polled Can driver main functions */

/* SYS-FUN-001: simulated actuator state, read by the test harness */
volatile uint8 g_ecu_led_on;
volatile uint8 g_ecu_pwm_duty;

static uint8 s_led_on_reported;
static uint8 s_pwm_duty_reported;

void IoHwAb_10ms(void)
{
    uint8 led_on;
    uint8 pwm_duty;

    /* SYS-FUN-001: IoOut_P -> IoIn_R (implicit S/R, refreshed by the RTE task) */
    led_on = (Rte_IRead_IoHwAb_10ms_IoIn_R_LedState() != 0u) ? 1u : 0u;
    pwm_duty = (uint8)Rte_IRead_IoHwAb_10ms_IoIn_R_PwmDuty();

    if (pwm_duty > 100u) {
        pwm_duty = 100u;
    }

    g_ecu_led_on = led_on;
    g_ecu_pwm_duty = pwm_duty;

    if (led_on != s_led_on_reported) {
        s_led_on_reported = led_on;
        printf("[IoHwAb] LED %s\n", (led_on != 0u) ? "ON" : "OFF");
    }

    if (pwm_duty != s_pwm_duty_reported) {
        s_pwm_duty_reported = pwm_duty;
        printf("[IoHwAb] PwmDuty %u%%\n", (unsigned)pwm_duty);
    }

    /* The PC Can driver is polled: Can has no BSW timing event in this
     * project, so its main functions are serviced from this 10 ms runnable. */
    Can_MainFunction_Read();
    Can_MainFunction_Write();
    Can_MainFunction_BusOff();
    Can_MainFunction_Mode();
}
