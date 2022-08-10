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

#ifndef __PROGRAM_OFS_H
#define __PROGRAM_OFS_H

#include "ia_css_psys_terminal_private_types.h"
#include "ia_css_psys_process_group.h"
#include "ia_css_psys_process.h"
#include "ia_css_psys_process_group.h"
#include "ia_css_terminal_types.h"
#include "ia_css_psys_terminal.hsys.user.h"
#include "ia_css_psys_terminal.h"
#include "bufqueue.host.h"
#include "ia_css_common_io_types.h"
#include "resource_types.h"
#include "ipu_device_ofs_devices.h"
#include "dfm_resource_types.h"
#include "ipu_dim_cfg_types.h"
#include "ia_css_kernel_user_param_instance_types.h"

unsigned program_ofs_get_payload_size(
		enum ipu_device_ofs_pin_id pin_id,
		bool is_compressed,
		vied_nci_dev_chn_ID_t mp_dev_chan_id,
		vied_nci_resource_size_t mp_nof_dma_chan,
		dfm_port_resource_t dfm_in_port,
		dfm_port_resource_t dfm_rel_port);

uint32_t program_ofs_fill_load_section_descriptor(
		ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc,
		bool is_compressed,
		enum ipu_device_ofs_pin_id pin_id,
		vied_nci_dev_chn_ID_t mp_dev_chan_id,
		uint16_t mp_dma_chan_offset,
		vied_nci_resource_size_t mp_nof_dma_chan,
		dfm_port_resource_t dfm_in_port,
		dfm_port_resource_t dfm_rel_port,
		uint32_t *stream_id_array);

int program_ofs_fill_cfg_payload(
		enum ipu_device_ofs_pin_id pin_id,
		struct ia_css_terminal_descriptor_s *put_terminal,
		const struct ia_css_kup_ofs *kup,
		ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc,
		void *payload_address,
		mem_ptr_t q_out_ptr,
		vied_nci_dev_chn_ID_t pin_dev_chan_id,
		uint16_t pin_dma_chan_offset,
		vied_nci_resource_size_t mp_nof_dma_chan,
		dfm_port_resource_t dfm_multicast_port,
		dfm_port_resource_t dfm_in_port,
		dfm_port_resource_t dfm_rel_port,
		unsigned *num_done_events,
		uint32_t *stream_id_array,
		unsigned num_of_streams);

ia_css_process_id_t program_ofs_get_process_id(enum ipu_device_ofs_pin_id pin_id);

int program_ofs_fill_connect_section_descriptor(
		enum ipu_device_ofs_pin_id pin_id,
		ia_css_program_control_init_connect_section_desc_t *connect_sec_desc,
		unsigned terminal_id,
		ia_css_frame_format_type_t format,
		dfm_port_resource_t dfm_ofs_in_rel,
		unsigned connect_section_count,
		unsigned num_planes,
		bool is_compressed,
		uint32_t *stream_id_array);

#endif /* __PROGRAM_OFS_H */
