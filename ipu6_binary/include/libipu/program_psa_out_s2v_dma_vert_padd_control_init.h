/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2017 - 2020 Intel Corporation.
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

#ifndef __PROGRAM_PSA_OUT_S2V_DMA_VERT_PADD_CONTROL_INIT_H
#define __PROGRAM_PSA_OUT_S2V_DMA_VERT_PADD_CONTROL_INIT_H

#include "type_support.h"
#include "ia_css_psys_process_types.h"
#include "ia_css_terminal_types.h"
#include "math_support.h"
#include "isp_global.h"
#include "bufqueue.host.h"
#include "pg_control_init_support.h"
#include "ipu_resources_dfm_term.h"
#include "resource.host.h"

#define MAX_PSA_OUT_DMA_S2V_SIZE 9
#define MAX_VERTICAL_PADD_LINES 62
#define MIN_VERTICAL_PADD_LINES 2

#define CHROMA_SUBSAMPLE_SHIFT                          (1)

typedef struct {
	dfm_port_resource_t dfm_s2v_yuv;
	dfm_port_resource_t dfm_dma_yuv_out;
	dfm_port_resource_t dfm_dma_yuv_out_dummy_top;
	dfm_port_resource_t dfm_dma_yuv_out_dummy_bottom;
} vert_padd_dfm_resources_t;

typedef struct {
	resource_t dma_out_chan;
	resource_t dma_out_chan_dummy_top;
	resource_t dma_out_chan_dummy_bottom;
} vert_padd_pg_ext_resources_t;

struct program_psa_out_yuv_vert_padd_dma_desc_t {
	int terminal_id;
	int resource_id;
	int y_offset;
	int u_offset;
	int v_offset;
	int size;
};

struct program_psa_out_yuv_vert_padd_desc_t {
	int top_num_of_dummy_lines;
	int bottom_num_of_dummy_lines;
};



/**
 * @brief       Fill ctrlinit payload of the program
 * @param[in]   process_group           Process group
 * @param[in]   load_sec_desc           Progctrlinit terminal section descriptor
 * @param[in]   payload_address         Program's ctrlinit terminal payload start address
 * @param[in]   q                       The outout queue for OUT_VIDEO
 * @param[in]   vert_padd_desc          Vertical padd descriptor
 * @param[in]   vert_padd_dfm_resources Dfm resources desc
 * @param[in]   ext_resources           Dma out resources
 * @param[in]   terminal_id             Terminal id
 * @param[in]   frag_idx                Index of fragment or 0
 * @param[in]   stream_ids_array        An array of the stream IDs for the transfer
 * @param[in]   num_of_streams          The number of entries in stream_ids_array
 *
 * @retval 0    Successful.
 * @retval 1    Error.
 */
int
program_psa_out_s2v_dma_yuv_vert_padd_payload_fill(
		const ia_css_process_group_t * const process_group,
		load_section_desc_list_t load_sec_desc_list,
		void *payload_address,
		const bufqueue_t q,
		const struct program_psa_out_yuv_vert_padd_desc_t * const vert_padd_desc,
		const vert_padd_dfm_resources_t * const vert_padd_dfm_resources,
		const vert_padd_pg_ext_resources_t * const ext_resources,
		const int terminal_id,
		const uint16_t frag_idx,
		uint32_t *stream_ids_array,
		const unsigned int num_of_streams);

/*
 * @brief       Get ctrlinit payload size of the program
 *
 * @param[in]   dma_desc                DMA resource descriptor
 * @param[in]   num_of_streams          The number of entries in stream_ids_array
 *
 * @retval	Size of the program payload
 */
int
program_psa_out_s2v_dma_vert_padd_get_payload_size(
		const struct program_psa_out_yuv_vert_padd_dma_desc_t * const dma_desc,
		const vert_padd_dfm_resources_t * const vert_padd_dfm_resources,
		const unsigned int num_of_streams);

/*
 * @brief       Fill load section descriptor of the program
 *
 * @param[in]   prog_ctrl_init_prog_desc Pointer to the program descriptor
 * @param[in]   dma_desc                DMA resource descriptor
 * @param[in]   stream_ids_array        An array of the stream IDs for the transfer
 * @param[in]   num_of_streams          The number of entries in stream_ids_array
 *
 * @retval 0    Successful.
 * @retval 1    Error.
 */
unsigned int
program_psa_out_s2v_dma_vert_padd_fill_load_section_descriptor(
		ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc,
		const struct program_psa_out_yuv_vert_padd_dma_desc_t * const dma_desc,
		const vert_padd_dfm_resources_t * const vert_padd_dfm_resources,
		uint32_t *stream_ids_array,
		const unsigned int num_of_streams);

/*
 * @brief       Fill connect section descriptor of the program
 *
 * @param[in]   connect_sec_desc        Pointer to the section descriptor to fill
 * @param[in]   dma_desc                DMA resource descriptor
 * @param[in]   vert_padd_desc          Vertical padding descriptor
 * @param[in]   stream_ids_array        An array of the stream IDs for the transfer
 * @param[in]   num_of_streams          The number of entries in stream_ids_array
 *
 * @retval 0    Successful.
 * @retval 1    Error.
 */
int
program_psa_out_s2v_dma_vert_padd_fill_connect_section_descriptor(
		ia_css_program_control_init_connect_section_desc_t *connect_sec_desc,
		const struct program_psa_out_yuv_vert_padd_dma_desc_t * const dma_desc,
		const struct program_psa_out_yuv_vert_padd_dma_desc_t * const out_yuv_top_dummy_dma_desc,
		const struct program_psa_out_yuv_vert_padd_dma_desc_t * const out_yuv_bottom_dummy_dma_desc,
		const struct program_psa_out_yuv_vert_padd_desc_t * const vert_padd_desc,
		uint32_t *stream_ids_array,
		const unsigned int num_of_streams);

/*
 * @brief       set program descriptor sid pid
 *
 * @param[in]   prog_ctrl_init_prog_desc        Pointer to the program descriptor
 * @param[in]   compression_acks                The number of acks requiered for compression
 */
void
program_psa_out_s2v_dma_vert_padd_set_desc_sid_pid(
		ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc,
		const vert_padd_dfm_resources_t * const vert_padd_dfm_resources,
		const uint8_t compression_acks);

#endif /* __PROGRAM_PSA_OUT_S2V_DMA_YUV_VERT_PADD_CONTROL_INIT_H */
