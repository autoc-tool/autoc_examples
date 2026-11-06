/*!*********************************************************************************************************************
 * @file        Crc_Cfg.h
 * @brief       CRC 配置头文件
 * @details     主要包含 CRC 动态配置项
 * @date        Generation Time : 2026-10-24 23:59:21
 * @project     Project Name    : minimal_system5
 * @toolversion Tool Version    : V0.1.0-DEV
 **********************************************************************************************************************/

#ifndef CRC_CFG_H
#define CRC_CFG_H

#ifdef __cplusplus
extern "C"
{
#endif


#define CRC_8_Mode        (CRC_8_TABLE)       ///< CRC8 模式配置


#define CRC_8_8H2FMode    (CRC_8H2F_TABLE)    ///< CRC8H2F 模式配置


#define CRC_16_Mode       (CRC_16_TABLE)      ///< CRC16 模式配置


#define CRC_16ARC_Mode    (CRC_16_ARC_TABLE)   ///< CRC16 ARC 模式配置


#define CRC_32_Mode       (CRC_32_TABLE)      ///< CRC32 模式配置


#define CRC_32P4_Mode     (CRC_32P4_TABLE)    ///< CRC32P4 模式配置


#define CRC_64_Mode       (CRC_64_TABLE)      ///< CRC64 模式配置


#ifdef __cplusplus
}
#endif

#endif /* CRC_CFG_H */