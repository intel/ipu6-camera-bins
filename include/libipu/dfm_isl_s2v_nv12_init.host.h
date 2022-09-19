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

#ifndef __DFM_ISA_S2V_NV12_INIT_HOST_H
#define __DFM_ISA_S2V_NV12_INIT_HOST_H

#include "bufqueue.host.h"
#include "dev_api_dfm_types.h"
#include "pg_control_init_support.h"

static void dfm_isl_s2v_nv12_host_open(p_terminal_config terminal,
					bufqueue_t q,
					uint32_t ack_addr,
					uint32_t ack_data,
					dfm_port_resource_t dfm_yuv_resource,
					load_section_desc_list_t load_sec_desc_list,
					void *payload_address,
					enum dev_api_dfm_agent agent_id,
					unsigned ignore_first_event,
					bool is_packed);

#ifndef PIPE_GENERATION
#include "dfm_isl_s2v_nv12_init.host.c"
#endif
#endif /* __DFM_ISA_S2V_NV12_INIT_HOST_H */
