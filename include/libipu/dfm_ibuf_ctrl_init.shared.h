/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2017 - 2017 Intel Corporation.
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

#ifndef __DFM_IBUF_CTRL_INIT_SHARED_H
#define __DFM_IBUF_CTRL_INIT_SHARED_H

#include "ia_css_common_io_types.h"
#include "resource.shared.h"
#include "dfm_resource_types.h"
#include "type_support.h"

#ifndef DFM_IBUF_CTRL_NUM_LINES_INTERLEAVED
#define DFM_IBUF_CTRL_NUM_LINES_INTERLEAVED (2)
#endif

static void dfm_isys_ibuf_ctrl_open(p_terminal_config terminal,
					bufqueue_t q_in,
					uint32_t ack_addr,
					uint32_t ack_data,
					dfm_port_resource_t dfm_isys_ibuf_ctrl_port,
					uint32_t gather_multi_mask,
					uint32_t agent_type,
					uint32_t active,
					void *payload_pointer);

#ifndef PIPE_GENERATION
#include "dfm_ibuf_ctrl_init.shared.c"
#endif
#endif /* __DFM_IBUF_CTRL_INIT_ISP_H */
