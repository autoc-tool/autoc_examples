/* Minimal Det memmap for PC NuttX sim (ms4 Memmap was not codegen'd). */
#define _MEMMAP_HEADER_INCLUDE_TAG

#if defined(DET_STOP_SEC_CODE)
#undef DET_STOP_SEC_CODE
#undef DET_CODE
#define OS_STOP_SEC_BSW_APPS_CODE_BSW_TEXT
#include "memmap.h"
#elif defined(DET_START_SEC_CODE)
#undef DET_START_SEC_CODE
#define DET_CODE OS_BSW_APPS_CODE_BSW_TEXT
#define OS_START_SEC_BSW_APPS_CODE_BSW_TEXT
#include "memmap.h"
#endif

#if defined(DET_STOP_SEC_CONST)
#undef DET_STOP_SEC_CONST
#undef DET_CONST
#define OS_STOP_SEC_BSW_APPS_CONST_BSW_RODATA
#include "memmap.h"
#elif defined(DET_START_SEC_CONST)
#undef DET_START_SEC_CONST
#define DET_CONST OS_BSW_APPS_CONST_BSW_RODATA
#define OS_START_SEC_BSW_APPS_CONST_BSW_RODATA
#include "memmap.h"
#endif

#if defined(DET_STOP_SEC_MULTI_APP_BSS)
#undef DET_STOP_SEC_MULTI_APP_BSS
#undef DET_MULTI_APP_BSS
#define OS_STOP_SEC_ALL_APPS_MULTI_APP_SHARE_BSW_BSS
#include "memmap.h"
#elif defined(DET_START_SEC_MULTI_APP_BSS)
#undef DET_START_SEC_MULTI_APP_BSS
#define DET_MULTI_APP_BSS OS_ALL_APPS_MULTI_APP_SHARE_BSW_BSS
#define OS_START_SEC_ALL_APPS_MULTI_APP_SHARE_BSW_BSS
#include "memmap.h"
#endif
