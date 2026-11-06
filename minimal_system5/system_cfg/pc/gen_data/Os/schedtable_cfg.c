#include <nuttx/config.h>
#include "Os.h"
#include "rtfw_types.h"
#include "schedtable_cfg.h"
#include "application_cfg.h"
#include "rtfw_task.h"
#include "task_cfg.h"
#include "event_cfg.h"
#include "rtfw_schedtable.h"
#include "rtfw_counter.h"
#include "counter_cfg.h"
#include "rtfw_compiler_cfg.h"

#define OS_START_SEC_CONST
#include "rtfw_memmap.h"

#if defined(_MSC_VER)
/* MSVC cannot expand empty DeclareRtfwRefTable the same way; use explicit empty table. */
const OsObjIndexType os_schedtable_cfg_ref_table_size = 0;
const os_schedtable_cfg_t *const os_schedtable_cfg_ref_table[1] = { (const os_schedtable_cfg_t *)0 };
#else
DeclareRtfwRefTable(OS_CONST_SECTION, schedtable, OS_SCHED_TABLE_CNT) = {
};
#endif

#define OS_STOP_SEC_CONST
#include "rtfw_memmap.h"