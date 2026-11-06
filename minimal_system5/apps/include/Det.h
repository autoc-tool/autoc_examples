/* ms4 PC harness: Det stubs (MODULE_DET=n) */
#ifndef DET_H
#define DET_H
#include "Std_Types.h"

typedef uint8 Det_ConfigType;

#define DET_MODULE_ID (15u)

static inline void Det_Init(const Det_ConfigType *c) { (void)c; }
static inline void Det_Start(void) {}
static inline Std_ReturnType Det_ReportError(uint16 m, uint8 i, uint8 a, uint8 e)
{ (void)m;(void)i;(void)a;(void)e; return E_OK; }
static inline Std_ReturnType Det_ReportRuntimeError(uint16 m, uint8 i, uint8 a, uint8 e)
{ (void)m;(void)i;(void)a;(void)e; return E_OK; }
static inline Std_ReturnType Det_ReportTransientFault(uint16 m, uint8 i, uint8 a, uint8 e)
{ (void)m;(void)i;(void)a;(void)e; return E_OK; }
static inline Std_ReturnType Det_ReportErrorWithInfo(uint32 errId, uint8 *info, uint8 len)
{ (void)errId;(void)info;(void)len; return E_OK; }

#endif /* DET_H */
