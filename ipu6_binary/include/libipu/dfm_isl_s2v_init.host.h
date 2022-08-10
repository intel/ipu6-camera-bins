/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2017 - 2020 Intel Corporation.
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

#ifndef __DFM_ISL_S2V_INIT_HOST_H
#define __DFM_ISL_S2V_INIT_HOST_H

#include "bufqueue.host.h"
#include "storage_class.h"
#include "pg_control_init_support.h"

STORAGE_CLASS_INLINE void dfm_isl_s2v_yuv_host_open(p_terminal_config terminal,
					bufqueue_t q,
					uint32_t ack_addr,
					uint32_t ack_data,
					dfm_port_resource_t dfm_yuv_resource,
					load_section_desc_list_t load_sec_desc_list,
					void *payload_address,
					enum dev_api_dfm_agent agent_id,
					unsigned ignore_first_event,
					uint32_t elem_per_pix_num,
					uint32_t elem_per_pix_denom);

STORAGE_CLASS_INLINE void dfm_isl_s2v_bayer_host_open(p_terminal_config terminal,
					bufqueue_t q,
					uint32_t ack_addr,
					uint32_t ack_data,
					dfm_port_resource_t dfm_s2v_resource,
					load_section_desc_list_t load_sec_desc_list,
					void *payload_address,
					unsigned ignore_first_event);

STORAGE_CLASS_INLINE void dfm_isl_s2v_bayer_host_unused_port_open(
					const vied_nci_dev_dfm_id_t dfm_dev_id,
					unsigned port_num,
					uint8_t *payload_address_offset);

STORAGE_CLASS_INLINE void dfm_isl_s2v_bayer_planar_host_open(p_terminal_config terminal,
					bufqueue_t q,
					uint32_t ack_addr,
					uint32_t ack_data,
					dfm_port_resource_t dfm_s2v_resource,
					load_section_desc_list_t load_sec_desc_list,
					void *payload_address,
					unsigned ignore_first_event);

#ifndef PIPE_GENERATION
#include "dfm_isl_s2v_init.host.c"
#endif
#endif /* __DFM_ISL_S2V_INIT_HOST_H */
