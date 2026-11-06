#include "Det.h"
#include "Det_Internal.h"
#include "Compiler.h" // #include "MemMap_Compiler.h"
#define  DET_START_SEC_CONST
#include "det_memmap.h"
#if (DET_ENABLE_RUNTIME_ERROR_CALLOUT == STD_ON)

CONST(Det_CalloutTableType, DET_CONST) Det_RuntimeErrorCalloutTable[DET_RUNTIMEERR_CALLOUT_TABLE_NUMBER] =
{
};
#endif

#if (DET_ENABLE_TRANSIENT_FAULT_CALLOUT == STD_ON)

CONST(Det_CalloutTableType, DET_CONST) Det_TransientFaultCalloutTable[DET_TRANSIENT_FAULT_CALLOUT_NUMBER] =
{
};
#endif

#if (DET_ENABLE_ERROR_HOOK == STD_ON)

CONST(Det_CalloutTableType, DET_CONST) Det_ErrorHookTable[DET_ERROR_HOOK_TABLE_NUMBER] =
{
};

#endif /*(DET_ENABLE_ERROR_HOOK==STD_ON) */


CONST(Det_ModuleInfo, DET_CONST) Module_Flow_Info[BSW_MODULE_NUM] = {
    
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},
     {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE},      {0, (boolean)FALSE}

};
#define  DET_STOP_SEC_CONST
#include "det_memmap.h"
#define DET_START_SEC_MULTI_APP_DATA
#include "det_memmap.h"


VAR(Det_TokenBucket, DET_MULTI_APP_DATA) Det_Bucket= {
       .capacity = DET_BUCKET_CPPACITY,
       .tokens = {0},
       .last_time = 0,
       .detModuleLockFlag = {0},
       .globallockflag = 0,
       .globaltokennum = DET_BUCKET_CPPACITY,
};
#define DET_STOP_SEC_MULTI_APP_DATA
#include "det_memmap.h"