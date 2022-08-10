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

#ifndef __PROGRAM_ISL_ACC_LSC_CONTROL_INIT_H
#define __PROGRAM_ISL_ACC_LSC_CONTROL_INIT_H

#include "type_support.h"
#include "ia_css_psys_process_types.h"
#include "ia_css_terminal_types.h"
#include "ipu_sequencer_info_descriptor.h" /* ipu_kernel_fragment_sequencer_info_desc_s */
#include "resource_types.h"
#include "dfm_resource_types.h"
#include "pg_control_init_support.h"

typedef struct {
	dfm_port_resource_t dfm_acb;
	dfm_port_resource_t dfm_dma;
} dfm_lsc_resources_t;

enum program_isl_acc_lsc_sensor_type_e {
	PROGRAM_ISL_ACC_LSC_SENSOR_TYPE_0 = 0,
	PROGRAM_ISL_ACC_LSC_SENSOR_TYPE_1 = 1,
	PROGRAM_ISL_ACC_LSC_SENSOR_TYPE_2 = 2,
	NUM_OF_ISL_ACC_LSC_SENSOR_TYPES,
	PROGRAM_ISL_ACC_LSC_SENSOR_ERROR
};

/*
 * @brief       Fill ctrlinit payload of the program
 *
 * @param[in]   process_group         Process group
 * @param[in]   load_sec_desc         Progctrlinit terminal section descriptor
 * @param[in]   payload_base_address  Program's ctrlinit terminal payload start address
 * @param[in]   spt_lsc_terminal_id   Terminal ID of process group this program is connected to
 *
 * @retval 0    Successful.
 * @retval 1    Error.
 */
int
program_isl_acc_lsc_payload_fill(
	struct ipu_kernel_fragment_sequencer_info_desc_s *kernel_frag_seq_info,
	const ia_css_process_group_t *process_group,
	load_section_desc_list_t load_sec_desc_list,
	void *payload_base_address,
	ia_css_terminal_ID_t terminal_id,
	unsigned int dma_id_api_model,
	dfm_lsc_resources_t dfm_resources,
	resource_t dma_spatial,
	enum program_isl_acc_lsc_sensor_type_e sensor_type,
	uint16_t frag_idx);
/*
 * @brief       Get ctrlinit payload size of the program
 *
 * @retval	Size of the program payload
 */
int
program_isl_acc_lsc_get_payload_size(
	unsigned int dma_id_api_model,
	dfm_lsc_resources_t dfm_resources,
	resource_t dma_spatial);

/*
 * @brief       Fill load section descriptor of the program
 *
 * @param[in]   prog_ctrl_init_prog_desc Pointer to the program descriptor in which the section descriptor has to be filled
 *
 * @retval 0    Successful.
 * @retval 1    Error.
 */
int
program_isl_acc_lsc_fill_load_section_descriptor(
	ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc,
		unsigned int dma_id_api_model,
		dfm_lsc_resources_t dfm_resources,
		resource_t dma_spatial);

/*
 * @brief       Fill connect section descriptor of the program
 *
 * @param[in]   connect_sec_desc    Pointer to the section descriptor to fill
 * @param[in]   spt_lsc_terminal_id Terminal ID of process group this program is connected to
 *
 * @retval 0    Successful.
 * @retval 1    Error.
 */
int
program_isl_acc_lsc_fill_connect_section_descriptor(
		unsigned int dma_id_api_model,
		ia_css_program_control_init_connect_section_desc_t *connect_sec_desc,
		ia_css_terminal_ID_t terminal_id,
		resource_t dma_spatial);

void
program_isl_acc_lsc_set_desc_sid_pid(
		ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc,
		dfm_port_resource_t dfm_dma);

enum program_isl_acc_lsc_sensor_type_e
program_isl_acc_lsc_set_sensor_type_by_kernel_bitmap(
		ia_css_kernel_bitmap_t kernel_bitmap,
		unsigned int lsc_sensor_type_kernels[]);

#endif /* __PROGRAM_ISL_ACC_LSC_CONTROL_INIT_H */

