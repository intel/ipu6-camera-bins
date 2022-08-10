/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2018 - 2018 Intel Corporation.
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
#ifndef __DEC400_VPLESS_COMMON_CONFIG_H
#define __DEC400_VPLESS_COMMON_CONFIG_H

#include "nci_dec400.h"
#include "ia_css_common_io_types.h"
#include "storage_class.h"
#include "ia_css_terminal_types.h"

STORAGE_CLASS_INLINE
unsigned int dec400_common_fill_load_section_descriptor(
		ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc, nci_dec400_device_id dev_id,
		unsigned int num_of_streams, unsigned int stream_id_array[], unsigned int total_load_sections);

STORAGE_CLASS_INLINE
unsigned int dec400_common_fill_connect_section_descriptor(
		ia_css_program_control_init_connect_section_desc_t *connect_sec_desc, nci_dec400_device_id dev_id,
		int terminal_id, unsigned int num_of_streams, unsigned int stream_id_array[]);

STORAGE_CLASS_INLINE
unsigned int
dec400_common_get_payload_size(unsigned int num_of_streams);

STORAGE_CLASS_INLINE
unsigned int
dec400_common_get_numberof_load_sections(unsigned int num_of_streams);

STORAGE_CLASS_INLINE
unsigned int
dec400_common_get_numberof_connect_sections(unsigned int num_of_streams);

#ifndef PIPE_GENERATION
#include "dec400_vpless_common_config.c"
#endif

#endif /* __DEC400_VPLESS_COMMON_CONFIG_H */

