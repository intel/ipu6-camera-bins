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

#ifndef __DFM_GATHER_MULTI_GEN_PORT_HOST_H
#define __DFM_GATHER_MULTI_GEN_PORT_HOST_H

#include "pg_control_init_support.h"

/*
 * This API can be used for gathering or multicasting to a agent where only 1 static token is enough.
 *
 * Example 1:
 * ----------
 * Gather from 3 events:
 *
 *            Event 0 ---> p0 -------> Agent
 *            Event 1 ---> p1 --> X
 *            Event 2 ---> p2 --> X
 *
 *	dfm_gather_multi_gen_port(
 *			dfm_dev_id,
 *			p0,
 *			(gath_multi_mask(p0) | gath_multi_mask(p1) | gath_multi_mask(p2)),
 *			agent_addr,
 *			agent_token,
 *			payload_address_offset_p0);
 *
 *	dfm_gather_multi_gen_port(
 *			dfm_dev_id,
 *			p1,
 *			0x0,
 *			agent_addr,
 *			agent_token,
 *			payload_address_offset_p1);
 *
 *	dfm_gather_multi_gen_port(
 *			dfm_dev_id,
 *			p2,
 *			0x0,
 *			agent_addr,
 *			agent_token,
 *			payload_address_offset_p2);
 *
 *
 * Example 2:
 * ----------
 * Multicast to 3 agents:
 *
 *            Event 0 ---> p0 --------> Agent A
 *                    X -> p1 --------> Agent B
 *                    X -> p2 --------> Agent C
 *
 *	dfm_gather_multi_gen_port(
 *			dfm_dev_id,
 *			p0,
 *			gath_multi_mask(p0),
 *			agent_A_addr,
 *			agent_A_token,
 *			payload_address_offset_p0);
 *
 *	dfm_gather_multi_gen_port(
 *			dfm_dev_id,
 *			p1,
 *			gath_multi_mask(p0),
 *			agent_B_addr,
 *			agent_B_token,
 *			payload_address_offset_p1);
 *
 *	dfm_gather_multi_gen_port(
 *			dfm_dev_id,
 *			p2,
 *			gath_multi_mask(p2),
 *			agent_C_addr,
 *			agent_C_token,
 *			payload_address_offset_p2);
 *
 */

STORAGE_CLASS_INLINE void
dfm_gather_multi_gen_port(
		dfm_port_resource_t dfm_port_res,
		unsigned gath_multi_mask,
		unsigned agent_addr,
		unsigned agent_token,
		unsigned in_threshold,
		unsigned out_count,
		uint8_t *payload_address_offset);

STORAGE_CLASS_INLINE void
dfm_gather_n(dfm_port_resource_t gather_ports,
		uint32_t num_gather_ports,
		uint32_t dest_addr,
		uint32_t token,
		uint32_t in_threshold,
		uint32_t out_count,
		load_section_desc_list_t load_sec_desc,
		uint8_t *payload_address);

STORAGE_CLASS_INLINE void
dfm_multicast_n(dfm_port_resource_t multicast_ports,
	uint32_t num_multicast_ports,
	uint32_t *op_ack_addrs,
	uint32_t *op_ack_token,
	uint32_t in_threshold,
	uint32_t out_count,
	load_section_desc_list_t load_sec_desc,
	uint8_t *payload_address);

#ifndef PIPE_GENERATION
#include "dfm_gather_multi_gen_port.host.c"
#endif
#endif /* __DFM_GATHER_MULTI_GEN_PORT_HOST_H */
