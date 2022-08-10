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

#ifndef __V2S_INIT_HOST_H
#define __V2S_INIT_HOST_H

#include "bufqueue.host.h"
#include "common_io.shared.h"
#include "v2s_init.shared.h"

void v2s_bayer_with_dfm_open(bufqueue_t q, s_resolution_t res, unsigned ack_addr, void *payload_address);

void v2s_yyuvyy_with_dfm_open(bufqueue_t q, s_resolution_t res, unsigned ack_addr, void *payload_address);

void v2s_yuv_planar_with_dfm_open(bufqueue_t q, s_resolution_t res, unsigned ack_addr, void *payload_address);

void v2s_bayer_planar_with_dfm_open(bufqueue_t q, s_resolution_t res, unsigned ack_addr, void *payload_address);

#endif /* __V2S_INIT_HOST_H */
