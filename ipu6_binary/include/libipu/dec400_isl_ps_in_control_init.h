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
#ifndef __DEC400_ISL_PS_IN_CONTROL_INIT_H
#define __DEC400_ISL_PS_IN_CONTROL_INIT_H

#include "ia_css_psys_process_group.h"
#include "ia_css_common_io_types.h" /* struct ia_css_terminal_descriptor_s */

/* This function configures the DEC400 for Bayer transfer at the ISL PS input
 * get_terminal - the input terminal of the Bayer stream 
 * payload_address - a pointer to the buffer where the configuration should be written
 * stream_id - the stream ID to be configued in the DEC400 (per MMU/DMA configuration)
 * num_of_streams - the number of streams (used for a common size calculation function but essentially always 1)
 * steam_index is the stream order in DOL
 */
unsigned int
dec400_isl_ps_in_payload_fill(
	struct ia_css_terminal_descriptor_s *get_terminal,
	void *payload_address,
	unsigned int stream_id,
	unsigned int num_of_streams,
	unsigned int stream_index);
#endif /* __DEC400_ISL_PS_IN_CONTROL_INIT_H */

