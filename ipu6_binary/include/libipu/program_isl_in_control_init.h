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

#ifndef __PROGRAM_ISL_IN_CONTROL_INIT_H_
#define __PROGRAM_ISL_IN_CONTROL_INIT_H_

#include "type_support.h"
#include "ia_css_psys_process_types.h"
#include "ia_css_terminal_types.h"
#include "resource_types.h"
#include "dfm_resource_types.h"
#include "bufqueue.host.h"
#include "cio2str_control_init.h"
#include "pifconv_ctrl_control_init.h"
#include "pixel_formatter_control_init.h"
#include "ipu_resources_dma_term.h"
#include "pg_control_init_support.h"

typedef struct {
	resource_t bayer_in_dma_chan;
	resource_t isl_dma_chan;
} pg_in_ext_resources_t;

typedef struct {
	dfm_port_resource_t dfm_ext_dma_port;
	dfm_port_resource_t dfm_isl_dma_port;
} dfm_in_resources_t;

typedef enum isl_ps_in_frame_type {
	ISL_PS_IN_FRAME_TYPE_BAYER,
	ISL_PS_IN_FRAME_TYPE_PAF
} isl_ps_in_frame_type_t;

typedef struct program_isl_ps_in_frame_config {
	uint32_t num_lines_interleaved;
	uint32_t lines_per_pixel;
	uint32_t cio2str_height;
} program_isl_ps_in_frame_config_t;

/*
 * @brief       Fill ctrlinit payload of the program
 *
 * @param[in]   process_group           Process group
 * @param[in]   load_sec_desc           Progctrlinit terminal section descriptor
 * @param[in]   payload_base_address    Program's ctrlinit terminal payload start address
 * @param[in]   dma_cfg_buff            Temporary buffer to hold dma configuration
 *
 * @retval 0    Successful.
 * @retval 1    Error.
 */
int
program_isl_in_payload_fill(const ia_css_process_group_t *process_group,
		load_section_desc_list_t load_sec_desc_list,
		void *payload_base_address,
		ia_css_terminal_ID_t get_terminal_id,
		bufqueue_t q_in,
		unsigned int dma_id_api_model,
		enum ipu_device_cio2str_dev_id cio2str_id,
		vied_nci_pifconv_ctrl_id_t pifconv_a_id,
		vied_nci_pifconv_ctrl_id_t pifconv_b_id,
		dfm_in_resources_t dfm_resources,
		pg_in_ext_resources_t ext_resources,
		struct ipu_resources_dma_descriptor_config *dma_cfg_buff,
		isl_ps_in_frame_type_t in_frame_type,
		uint16_t frag_idx,
		uint32_t *stream_id,
		unsigned int num_of_streams);

/*
 * @brief       Get ctrlinit payload size of the program
 *
 * @retval	Size of the program payload
 */
int
program_isl_in_get_payload_size(dfm_in_resources_t dfm_resources,
		unsigned int dma_id_api_model,
		isl_ps_in_frame_type_t in_frame_type,
		unsigned int num_of_streams);

/*
 * @brief       Fill load section descriptor of the program
 *
 * @param[in]   prog_ctrl_init_prog_desc Pointer to the program descriptor in which the section descriptor has to be filled
 *
 * @retval 0    Successful.
 * @retval 1    Error.
 */
unsigned int
program_isl_in_fill_load_section_descriptor(ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc,
		unsigned int dma_id_api_model,
		pg_in_ext_resources_t ext_resources,
		dfm_in_resources_t dfm_resources,
		enum ipu_device_cio2str_dev_id cio2str_id,
		vied_nci_pifconv_ctrl_id_t pifconv_a_id,
		vied_nci_pifconv_ctrl_id_t pifconv_b_id,
		vied_nci_pixel_formatter_id_t pf_id,
		isl_ps_in_frame_type_t in_frame_type,
		uint32_t *stream_ids_array,
		unsigned int num_of_streams);

/*
 * @brief       Fill connect section descriptor of the program
 *
 * @param[in]   connect_sec_desc        Pointer to the section descriptor to fill
 *
 * @retval 0    Successful.
 * @retval 1    Error.
 */
int
program_isl_in_fill_connect_section_descriptor(ia_css_program_control_init_connect_section_desc_t *connect_sec_desc,
		ia_css_terminal_ID_t get_terminal_id,
		unsigned int dma_id_api_model,
		pg_in_ext_resources_t ext_resources,
		dfm_in_resources_t dfm_resources,
		isl_ps_in_frame_type_t in_frame_type,
		uint32_t *stream_ids_array,
		unsigned int num_of_streams);
void
program_isl_in_set_desc_sid_pid(ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc,
		dfm_in_resources_t dfm_resources);

void
program_isl_in_set_desc_sid_pid(ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc,
		dfm_in_resources_t dfm_resources);

#endif /* __PROGRAM_ISL_IN_CONTROL_INIT_H_ */
