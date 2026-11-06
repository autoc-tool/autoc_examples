#include "Can.h"
#include "canif_cbk.h"
void CanIf_TxConfirmation(PduIdType CanTxPduId)
{ canif_tx_confirmation(CanTxPduId); }
void CanIf_RxIndication(Can_HwType *Mailbox, PduInfoType *PduInfoPtr)
{ canif_rx_indication(Mailbox, PduInfoPtr); }
void CanIf_ControllerModeIndication(uint8 ControllerId, Can_ControllerStateType ControllerMode)
{ canif_controller_mode_indication(ControllerId, ControllerMode); }
void CanIf_ControllerBusOff(uint8 ControllerId)
{ canif_controller_bus_off(ControllerId); }
