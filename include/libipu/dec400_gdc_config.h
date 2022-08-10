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
#ifndef __DEC400_GDC_CONFIG_H
#define __DEC400_GDC_CONFIG_H

#include "ia_css_common_io_types.h"

/* This function configures the DEC400 for YUV420 at the GDC input */
void dec400_config_yuv420_gdc(p_terminal_config terminal_ptr, uint8_t *payload_buffer_p, unsigned int stream_id_array[]);

#ifndef PIPE_GENERATION
#include "dec400_gdc_config.c"
#endif

#endif /* __DEC400_GDC_CONFIG_H */

