
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

#ifndef __DFM_PSA_V2S_INIT_HOST_H
#define __DFM_PSA_V2S_INIT_HOST_H

enum v2s_cfg_type {
	V2S_CFG_YYUVYY,
	V2S_CFG_YUV420,
	V2S_CFG_BAYER_PLANAR
};
#include "bufqueue.host.h"
#include "pg_control_init_support.h"

static void dfm_psa_v2s_host_open(
		enum v2s_cfg_type v2s_type,
		s_resolution_t get_resolution,
		bufqueue_t q,
		uint32_t ack_addr,
		uint32_t ack_data,
		dfm_port_resource_t dfm_yuv_resource,
		unsigned dfm_yuv_resource_port_offset,
		load_section_desc_list_t load_sec_desc_list,
		void *payload_address,
		unsigned ignore_first_event);

#ifndef PIPE_GENERATION
#include "dfm_psa_v2s_init.host.c"
#endif
#endif /* __DFM_PSA_V2S_INIT_HOST_H */
