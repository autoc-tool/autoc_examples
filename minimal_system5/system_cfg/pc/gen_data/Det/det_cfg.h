#ifndef DET_CFG_H
#define DET_CFG_H
#include "rtfw_atomic.h"
#include "Platform_Types.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define BSW_MODULE_NUM                                  (256u)   ///< Bsw模块数
#define DET_FORWARD_TO_DLT                              (STD_OFF)   ///< 将错误发送到DLT

#define DET_VERSIONINFO_API                             (STD_OFF) ///< 使能允许调用API获取版本信息

#define DET_BUCKET_CPPACITY                             (20) ///< 令牌桶个数
#define DET_BUCKET_PERIOD_MS                            (1024) ///< 令牌桶周期
#define DET_BUCKET_PERIOD_EXPONENT                      (10) ///< 令牌桶周期
#define DET_FLOW_CONTROL                                (STD_OFF)
/* 令牌桶的容量 */
#define MODULE_FLOW_CONTROL_NUM                         (0)

#define DET_ENABLE_ERROR_HOOK                           (STD_OFF)     ///< 使能开发错误回调

#define DET_ENABLE_TRANSIENT_FAULT_CALLOUT              (STD_OFF)     ///< 使能瞬态错误回调

#define DET_ENABLE_RUNTIME_ERROR_CALLOUT                (STD_OFF)       ///< 使能运行时错误回调

#define DET_RUNTIMEERR_CALLOUT_TABLE_NUMBER              (0u)   ///< 运行时错误回调数量

#define DET_ERROR_HOOK_TABLE_NUMBER                      (0u) ///< 开发错误回调数量

#define DET_TRANSIENT_FAULT_CALLOUT_NUMBER               (0u) ///< 瞬态错误回调数量

/*! DetModuleId symbolic name defines */
#define DetConf_DetModule_DetModule (4096uL)   ///< Det自定义ModuleNameId
/*! Service port defines */
#define DetConf_DetModule (4096u)                ///< Det Service Mapping 提供的Port
#define DetConf_DetModule_DetModuleInstance (0u)                ///< Det Service Mapping 提供的Port

typedef struct {
    sint32 capacity;     // 令牌桶容量
    Atomic tokens[1];       // 当前令牌数量
    Atomic detModuleLockFlag[1];
    uint64 last_time; // 上次令牌添加的时间
    Atomic globallockflag;     // 默认lockflag
    Atomic globaltokennum;        // 默认令牌桶个数
} Det_TokenBucket;

typedef struct {
    uint8 module_id_info;
    boolean module_enable_info;
} Det_ModuleInfo;

extern const Det_ModuleInfo Module_Flow_Info[BSW_MODULE_NUM];
extern Det_TokenBucket Det_Bucket;
#ifdef __cplusplus
}
#endif

#endif /* DET_CFG_H */

