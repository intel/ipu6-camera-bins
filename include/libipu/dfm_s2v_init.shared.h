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

#ifndef __DFM_S2V_INIT_SHARED_H
#define __DFM_S2V_INIT_SHARED_H

#include "resource_types.h"
#include "dev_api_dfm_types.h"
#include "dfm_resource_types.h"
#include "bufqueue.shared.h"

struct elem_per_pix_s {
	uint32_t elem_per_pix_num;
	uint32_t elem_per_pix_denom;
};

static void dfm_s2v_open(p_terminal_config terminal,
			bufqueue_t q,
			struct elem_per_pix_s elem_pp,
			uint32_t ack_addr,
			uint32_t ack_data,
			struct dev_api_dfm_port *port,
			dfm_port_resource_t starting_port,
			unsigned *gather_multi_mask,
			enum dev_api_dfm_agent agent_id,
			uint32_t num_ports,
			unsigned ignore_first_event);

static void dfm_s2v_unused_port_open(
		const vied_nci_dev_dfm_id_t dfm_dev_id,
		unsigned port_num,
		uint8_t *payload_address_offset);

#ifndef PIPE_GENERATION
#include "dfm_s2v_init.shared.c"
#endif

#endif /* __DFM_S2V_YUV_INIT_SHARED_H */
