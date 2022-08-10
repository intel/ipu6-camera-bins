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
#ifndef __S2V_CONTROL_INIT_DEP_H
#define __S2V_CONTROL_INIT_DEP_H

#include "ia_css_psys_process_group.h"
#include "ia_css_psys_terminal_private_types.h"
#include "vied_nci_psys_resource_model_private.h"
#include "bufqueue.host.h"	/* bufqueue_t */
#include "ia_css_common_io_types.h" /* struct ia_css_terminal_descriptor_s */

int
s2v_payload_fill_dep(
		vied_nci_s2v_id_t s2v_id,
		unsigned int s2v_ack_addr,
		struct ia_css_terminal_descriptor_s *put_terminal,
		bufqueue_t q,
		void *payload_address,
		unsigned payload_size);

#endif /* __S2V_CONTROL_INIT_DEP_H */
