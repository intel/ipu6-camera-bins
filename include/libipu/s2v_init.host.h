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
#ifndef __S2V_INIT_HOST_H
#define __S2V_INIT_HOST_H

#include "bufqueue.host.h"

#define S2V_INIT_ERROR (0)
#define S2V_INIT_SUCCESS (1)

int
s2v_bayer_isl_open(bufqueue_t q,
			unsigned int width,
			unsigned int height,
			unsigned int p_ack_addr,
			void *payload_address);

int
s2v_bayer_planar_open(bufqueue_t q,
			unsigned int width,
			unsigned int height,
			unsigned int p_ack_addr,
			void *payload_address);

int
s2v_yuv_output_open(bufqueue_t q,
		unsigned int width,
		unsigned int height,
		unsigned int p_ack_addr,
		void *payload_address);

int
s2v_bayer_yuv_isl_open(
		enum nci_s2v_device_id s2v_id,
		bufqueue_t q,
		unsigned int width,
		unsigned int height,
		unsigned int p_ack_addr,
		void *payload_address,
		unsigned int frame_format);

int
s2v_nv12_output_open(
		bufqueue_t q,
		unsigned int width,
		unsigned int height,
		unsigned int p_ack_addr,
		void *payload_address,
		unsigned int bpe_size_shift);

#define __INLINE_S2V_INIT__

#if defined(__INLINE_S2V_INIT__) && !defined(PIPE_GENERATION)
#include "s2v_init.host.c"
#endif

#endif /* __S2V_INIT_HOST_H */
