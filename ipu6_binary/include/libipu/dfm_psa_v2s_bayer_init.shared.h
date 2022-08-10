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

#ifndef __DFM_PSA_V2S_BAYER_INIT_SHARED_H
#define __DFM_PSA_V2S_BAYER_INIT_SHARED_H

#include "ia_css_common_io_types.h"
#include "bufqueue.shared.h"
#include "resource.shared.h"

static void dfm_psa_v2s_bayer_open(s_resolution_t res,
					bufqueue_t q,
					dfm_port_resource_t port_num,
					unsigned gather_multi_mask,
					unsigned ignore_first_event,
					uint32_t ack_addr,
					uint32_t ack_data,
					void *payload_pointer);

#ifndef PIPE_GENERATION
#include "dfm_psa_v2s_bayer_init.shared.c"
#endif
#endif /* __DFM_PSA_V2S_BAYER_INIT_SHARED_H */
