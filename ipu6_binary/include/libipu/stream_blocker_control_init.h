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

#ifndef __STREAM_BLOCKER_CONTROL_INIT_H
#define __STREAM_BLOCKER_CONTROL_INIT_H

#include "vied_nci_psys_resource_model_private.h"
#include "ia_css_psys_terminal_private_types.h"
#include "ipu_device_subsystem_ids.h"

enum stream_blocker_section_id {
	STREAM_BLOCKER_SECTION0 = 0,
	STREAM_BLOCKER_NUM_SECTIONS
};

int stream_blocker_get_payload_size (void);

int stream_blocker_get_size_of_sections (void);

int stream_blocker_get_number_of_sections (void);

int stream_blocker_get_offset_of_section (enum stream_blocker_section_id id);

int stream_blocker_get_size_of_section (enum stream_blocker_section_id id);

int stream_blocker_get_number_of_load_sections (void);

int stream_blocker_payload_fill(uint32_t regVal, vied_nci_stream_blocker_id_t stream_blocker_id,
		void *payload_address);

int stream_blocker_load_section_descriptor(
		vied_nci_stream_blocker_id_t stream_blocker_id,
		ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc);

#endif /* __STREAM_BLOCKER_CONTROL_INIT_H*/
