#ifndef RTE_MINIMALSYSTEM_H_
#define RTE_MINIMALSYSTEM_H_

#include "Std_Types.h"

/* Host stand-in for the generated implicit S/R buffers.
 * OsTask_10ms copies Com <-> these values around MinimalSystem_10ms. */

extern uint8 g_cmd_led;
extern uint8 g_cmd_target;
extern uint8 g_cmd_alive;
extern uint8 g_cmd_pwm;
extern uint8 g_cmd_crc;

extern uint8 g_tx_state;
extern uint8 g_tx_alive;
extern uint8 g_tx_temp;
extern uint8 g_tx_flags;
extern uint16 g_tx_voltage;
extern uint8 g_fault_code;
extern uint8 g_fault_active;
extern uint8 g_led_on;
extern uint8 g_pwm_duty;

#define Rte_IRead_SysCycle_CmdControl_LedCmd() (g_cmd_led)
#define Rte_IRead_SysCycle_CmdControl_TargetMode() (g_cmd_target)
#define Rte_IRead_SysCycle_CmdControl_Cmd_AliveCnt() (g_cmd_alive)
#define Rte_IRead_SysCycle_CmdControl_PwmDuty() (g_cmd_pwm)
#define Rte_IRead_SysCycle_CmdControl_Cmd_Crc8() (g_cmd_crc)

#define Rte_IWrite_SysCycle_EcuStatus_ECU_State(data) ((g_tx_state) = (uint8)(data))
#define Rte_IWrite_SysCycle_EcuStatus_ECU_AliveCnt(data) ((g_tx_alive) = (uint8)(data))
#define Rte_IWrite_SysCycle_EcuStatus_Temperature(data) ((g_tx_temp) = (uint8)(data))
#define Rte_IWrite_SysCycle_EcuStatus_SupplyVoltage(data) ((g_tx_voltage) = (uint16)(data))
#define Rte_IWrite_SysCycle_EcuStatus_FaultFlags(data) ((g_tx_flags) = (uint8)(data))
#define Rte_IWrite_SysCycle_FaultEvent_FaultCode(data) ((g_fault_code) = (uint8)(data))
#define Rte_IWrite_SysCycle_FaultEvent_FaultActive(data) ((g_fault_active) = (uint8)(data))
#define Rte_IWrite_SysCycle_IoOut_LedState(data) ((g_led_on) = (uint8)(data))
#define Rte_IWrite_SysCycle_IoOut_PwmDuty(data) ((g_pwm_duty) = (uint8)(data))

#endif /* RTE_MINIMALSYSTEM_H_ */
