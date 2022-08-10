/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2020 Intel Corporation. All Rights Reserved.
 *
 * The source code contained or described herein and all documents related to
 * the source code ("Material") are owned by Intel Corporation or its suppliers
 * or licensors. Title to the Material remains with Intel Corporation or its
 * suppliers and licensors. The Material contains trade secrets and proprietary
 * and confidential information of Intel or its suppliers and licensors. The
 * Material is protected by worldwide copyright and trade secret laws and
 * treaty provisions. No part of the Material may be used, copied, reproduced,
 * modified, published, uploaded, posted, transmitted, distributed, or
 * disclosed in any way without Intel's prior express written permission.
 *
 * No license under any patent, copyright, trade secret or other intellectual
 * property right is granted to or conferred upon you by disclosure or delivery
 * of the Materials, either expressly, by implication, inducement, estoppel or
 * otherwise. Any license under such intellectual property rights must be
 * express and approved by Intel in writing.
 */

#ifndef IA_CIPR_DUMP_H_
#define IA_CIPR_DUMP_H_

#include "ia_tools/css_types.h"

extern char g_ia_log_dump_path[];

#ifdef __cplusplus
extern "C" {
#endif

css_err_t ia_dump_to_file(char* filename, void* buffer, unsigned int size);

typedef enum ia_cipr_dump_option
{
    IA_CSS_DUMP_DISABLED = 0,
    IA_CSS_DUMP_DVS = 1,
} ia_cipr_dump_option_t;

extern int32_t g_ia_dump_enabled;
extern int32_t g_ia_burstisp_dump_enable;

#ifdef IPU_SYSVER_ipu6v1
#define CAMERA_DUMP_CAPABILITY_DVS
#define TERMINAL_CACHED_OUT_DVS_FE_L0 24
#define TERMINAL_CACHED_OUT_DVS_FE_L1 25
#define TERMINAL_CACHED_OUT_DVS_FE_L2 26
#define TERMINAL_SPATIAL_OUT_DVS_MV_L0 17
#define TERMINAL_SPATIAL_OUT_DVS_MV_L1 18
#define TERMINAL_SPATIAL_OUT_DVS_MV_L2 19

#elif defined(IPU_SYSVER_ipu6v5) || defined(IPU_SYSVER_ipu6v6)
#define CAMERA_DUMP_CAPABILITY_DVS
#define TERMINAL_CACHED_OUT_DVS_FE_L0 23
#define TERMINAL_CACHED_OUT_DVS_FE_L1 24
#define TERMINAL_CACHED_OUT_DVS_FE_L2 25
#define TERMINAL_SPATIAL_OUT_DVS_MV_L0 16
#define TERMINAL_SPATIAL_OUT_DVS_MV_L1 17
#define TERMINAL_SPATIAL_OUT_DVS_MV_L2 18
#endif

#ifdef CAMERA_DUMP_CAPABILITY_DVS
#define is_dvs_param_out_terminal(x) \
    (x) == TERMINAL_CACHED_OUT_DVS_FE_L0 || \
    (x) == TERMINAL_CACHED_OUT_DVS_FE_L1 || \
    (x) == TERMINAL_CACHED_OUT_DVS_FE_L2 || \
    (x) == TERMINAL_SPATIAL_OUT_DVS_MV_L0 || \
    (x) == TERMINAL_SPATIAL_OUT_DVS_MV_L1 || \
    (x) == TERMINAL_SPATIAL_OUT_DVS_MV_L2

css_err_t ia_dump_dvs_terminal(uint8_t terminal_index, int bufid, void* buffer, unsigned int size);
#endif // CAMERA_DUMP_CAPABILITY_DVS

#ifdef __cplusplus
}
#endif // _cpp compiler
#endif // Header
