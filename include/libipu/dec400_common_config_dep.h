/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2017 - 2018 Intel Corporation.
 * All Rights Reserved.
 *
 * The source code contained or described herein and all documents
 * related to the source code ("Material") are owned by Intel Corporation
 * or licensors. Title to the Material remains with Intel
 * Corporation or its licensors. The Material contains trade
 * secrets and proprietary and confidential information of Intel or its
 * licensors. The Material is protected by worldwide copyright
 * and trade secret laws and treaty provisions. No part of the Material may
 * be used, copied, reproduced, modified, published, uploaded, posted,
 * transmitted, distributed, or disclosed in any way without Intel's prior
 * express written permission.
 *
 * No License under any patent, copyright, trade secret or other intellectual
 * property right is granted to or conferred upon you by disclosure or
 * delivery of the Materials, either expressly, by implication, inducement,
 * estoppel or otherwise. Any license under such intellectual property rights
 * must be express and approved by Intel in writing.
 */
#ifndef __DEC400_COMMON_CONFIG_DEP_H
#define __DEC400_COMMON_CONFIG_DEP_H

#include "dec400_common_interface_config_dep.h"

STORAGE_CLASS_INLINE
void dec400_psa_gdc_output_common_configuration(uint8_t is_compressed,
					uint8_t bpp, struct dec400_common_cfg_t *streams_common_cfg);

STORAGE_CLASS_INLINE
void dec400_tnr_in_out_common_configuration(uint8_t is_compressed,
					uint8_t bpp, struct dec400_common_cfg_t *streams_common_cfg);

STORAGE_CLASS_INLINE
void dec400_ofs_tiled_output_common_configuration(uint8_t is_compressed,
					uint8_t bpp, struct dec400_common_cfg_t *streams_common_cfg);

#ifndef PIPE_GENERATION
#include "dec400_common_config_dep.c"
#endif

#endif /* __DEC400_COMMON_CONFIG_DEP_H */

