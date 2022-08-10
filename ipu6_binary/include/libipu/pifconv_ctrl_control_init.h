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
#ifndef __PIFCONV_CTRL_CONTROL_INIT_H
#define __PIFCONV_CTRL_CONTROL_INIT_H

#include "ia_css_common_io_types.h"
#include "ia_css_psys_terminal_private_types.h"
#include "vied_nci_psys_resource_model_private.h"
#include "common_io.host.h"	/* s_resolution_t */

int32_t
pifconv_ctrl_get_payload_size(void);

int32_t
pifconv_ctrl_fill_load_section_descriptor(
		vied_nci_pifconv_ctrl_id_t dev_id,
		ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc);

uint32_t
pifconv_ctrl_get_numberof_load_sections(void);

int32_t
pifconv_ctrl_payload_fill(
		vied_nci_pifconv_ctrl_id_t dev_id,
		s_resolution_t input_res,
		uint32_t buffer_width,
		void *payload_address,
		uint32_t num_lines_interleaved);

#endif /* __PIFCONV_CTRL_CONTROL_INIT_H */
