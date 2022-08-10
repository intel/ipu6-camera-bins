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

#ifndef __PROGRAM_TNR_MBR_CONTROL_INIT_H
#define __PROGRAM_TNR_MBR_CONTROL_INIT_H

#include "type_support.h"
#include "ia_css_psys_process_types.h"
#include "ia_css_terminal_types.h"

#include "ipu_dim_cfg_types.h"
#include "resource_types.h"
#include "ipu_device_mbr_devices.h"

#include "ia_css_common_io_types.h" /* For p_terminal_config */
#include "resource_types.h" /* For dma_resource_t */
#include "bufqueue.host.h" /* For bufqueue_t */
#include "nci_tnr_types.h" /* For TNR defines */

#include "ia_css_psys_terminal_private_types.h"
#include "ia_css_common_io_types.h"

#include "ia_css_vmem_resources.h"
#include "pg_control_init_support.h"

/* TNR Reference Input queue configuration */
#define REF_IN_BLK_WIDTH                  (192)
#define REF_IN_BLK_HEIGHT                 (52)
#define REF_IN_RECSIM_WIDTH               (96)
#define REF_IN_RECSIM_HEIGHT              (13)

#define Q_REF_IN_BUF_MEM                  (buf_mem_tnr_ref_vmem)
#define Q_REF_IN_BUF_START_ADDR           (0)
#define Q_REF_IN_NUMBUF                   (2)

#define Q_REF_IN_WIDTH_Y                  (CEIL_DIV(REF_IN_BLK_WIDTH, ISP_NWAY))
#define Q_REF_IN_HEIGHT_Y                 (REF_IN_BLK_HEIGHT)
#define Q_REF_IN_SIZE_Y                   (Q_REF_IN_WIDTH_Y * Q_REF_IN_HEIGHT_Y)

#define Q_REF_IN_WIDTH_UV                 (CEIL_DIV(REF_IN_BLK_WIDTH , ISP_NWAY))
#define Q_REF_IN_HEIGHT_UV                (REF_IN_BLK_HEIGHT >> 1)
#define Q_REF_IN_SIZE_UV                  (Q_REF_IN_WIDTH_UV * Q_REF_IN_HEIGHT_UV)

#define Q_REF_IN_WIDTH_RECSIM             (CEIL_DIV(REF_IN_RECSIM_WIDTH , ISP_NWAY))
#define Q_REF_IN_HEIGHT_RECSIM            (REF_IN_RECSIM_HEIGHT)
#define Q_REF_IN_SIZE_RECSIM              (Q_REF_IN_WIDTH_RECSIM * Q_REF_IN_HEIGHT_RECSIM)

/* TNR Reference Output queue configuration */
#define Q_REF_OUT_BUF_MEM                  VMEM_SECTION_BBPS_TNR_REFOUT_MEM_ID
#define Q_REF_OUT_BUF_START_ADDR           (VMEM_SECTION_BBPS_TNR_REFOUT_OFFSET * ISP_VEC_BYTES)
#define Q_REF_OUT_NUMBUF                   (NCI_TNR_NUM_BUF)
#define Q_REF_OUT_BLK_WIDTH                (NCI_TNR_REF_OXDIM)
#define Q_REF_OUT_BLK_HEIGHT               (NCI_TNR_REF_OYDIM)
#define Q_REF_OUT_RECSIM_WIDTH             (NCI_TNR_RECSIM_BUF_WIDTH)
#define Q_REF_OUT_RECSIM_HEIGHT            (NCI_TNR_RECSIM_BUF_HEIGHT)

#define Q_REF_OUT_WIDTH_Y                  (CEIL_DIV(Q_REF_OUT_BLK_WIDTH, ISP_NWAY))
#define Q_REF_OUT_HEIGHT_Y                 (Q_REF_OUT_BLK_HEIGHT)
#define Q_REF_OUT_SIZE_Y                   (Q_REF_OUT_WIDTH_Y * Q_REF_OUT_HEIGHT_Y)

#define Q_REF_OUT_WIDTH_UV                 (CEIL_DIV(Q_REF_OUT_BLK_WIDTH, ISP_NWAY))
#define Q_REF_OUT_HEIGHT_UV                (Q_REF_OUT_BLK_HEIGHT >> NCI_TNR_CHROMA_SUBSAMPLE_SHIFT)
#define Q_REF_OUT_SIZE_UV                  (Q_REF_OUT_WIDTH_UV * Q_REF_OUT_HEIGHT_UV)

#define Q_REF_OUT_WIDTH_RECSIM             (CEIL_DIV(Q_REF_OUT_RECSIM_WIDTH, ISP_NWAY))
#define Q_REF_OUT_HEIGHT_RECSIM            (Q_REF_OUT_RECSIM_HEIGHT)
#define Q_REF_OUT_SIZE_RECSIM              (Q_REF_OUT_WIDTH_RECSIM * Q_REF_OUT_HEIGHT_RECSIM)

typedef struct {
	vied_nci_dev_chn_ID_t    hb_ref_in_dev_id;    /*  Device ID of HB-Frx DMA controlled by TNR-MBR */
	vied_nci_resource_size_t hb_ref_in_size;      /*  Number of DMA channels reserved in HB-Frx DMA for TNR-MBR */
	uint32_t                 hb_ref_in_offset;    /*  DMA channel offset in HB-Frx DMA for TNR-MBR */
	vied_nci_dev_chn_ID_t    hb_ref_out_dev_id;   /*  Device ID of HB-Tx DMA controlled by TNR-MBR */
	vied_nci_resource_size_t hb_ref_out_size;     /*  Number of DMA channels reserved in HB-Tx DMA for TNR-MBR */
	uint32_t                 hb_ref_out_offset;   /*  DMA channel offset in HB-Tx DMA for TNR-MBR */
	vied_nci_dev_chn_ID_t    int_dev_id;          /*  Device ID of Internal DMA controlled by TNR */
	vied_nci_resource_size_t int_size;            /*  Number of DMA channels reserved in Internal  DMA for TNR */
	uint32_t                 int_offset;          /*  DMA channel offset in Internal DMA for TNR */
} program_tnr_mbr_dma_resources_t;

/*
 * @brief This function asserts whether section count matches the computed section count
 *
 * @param[in]   check_load_section_count        Expected section (load) count
 * @param[in]   dma_resources                   DMA resources reserved for TNR-MBR program
 * @param[in]   num_of_streams                  The number of either input/output stream of TNR
 *
 */
void
program_tnr_mbr_check_load_section_count(
		uint32_t check_load_section_count,
		program_tnr_mbr_dma_resources_t dma_resources,
		unsigned num_of_streams);

/*
 * @brief       Fill control init payload of the program
 *
 * @param[in]   load_sec_desc             Progctrlinit terminal section descriptor list
 * @param[in]   payload_address           Program's ctrlinit terminal payload start address
 * @param[in]   q_in		          Input queue connected to TNR
 * @param[in]   q_out 			  Output queue connected to TNR
 * @param[in]   ref_in_terminal           Terminal descriptor at reference input side
 * @param[in]   ref_out_terminal          Terminal descriptor at reference output side
 * @param[in]   rec_sim_in_terminal       Spatial terminal descriptor at reference input side
 * @param[in]   rec_sim_out_terminal      Spatial terminal descriptor at reference output side
 * @param[in]   tnr_ip_buf_rel_addr       Address to which TNR will send its input buffer release command
 * @param[in]   tnr_op_buf_enq_cmd_addr   Address to which TNR will send its output buffer enqueue command
 * @param[in]   dma_resources             DMA resources reserved for TNR-MBR program
 * @param[in]   dma_hb_ref_in_resource    DMA resource (device id and offset) for DMA HBfrX controlled by TNR MBR
 * @param[in]   dma_int_resource          DMA resource (device id and offset) for DMA internal controlled by TNR MBR
 * @param[in]   stream_ids_in_array       An array of the stream IDs for the TNR input transfer
 * @param[in]   stream_ids_out_array      An array of the stream IDs for the TNR output transfer
 * @param[in]   num_of_streams            The number of entries in both stream_ids_in_array and stream_ids_out_array
 *
 * @retval 0    Successful.
 * @retval 1    Error.
 */
int
program_tnr_mbr_payload_fill(
		load_section_desc_list_t load_sec_desc_list,
		void *payload_address,
		bufqueue_t q_in,
		bufqueue_t q_out,
		const p_terminal_config ref_in_terminal,
		const p_terminal_config ref_out,
		const p_spatial_terminal_config rec_sim_in_terminal,
		const p_spatial_terminal_config rec_sim_out_terminal,
		uint32_t tnr_ip_buf_rel_addr,
		uint32_t tnr_op_buf_enq_cmd_addr,
		program_tnr_mbr_dma_resources_t dma_resources,
		dma_resource_t dma_hb_ref_in_resource,
		dma_resource_t dma_int_resource,
		uint32_t *stream_ids_in_array,
		uint32_t *stream_ids_out_array,
		unsigned num_of_streams);

/*
 * @brief       Get control init payload size of the program
 *
 * @param[in]   dma_resources               DMA resources reserved for TNR-MBR program
 * @param[in]   num_of_streams            The number of entries in both stream_ids_in_array and stream_ids_out_array
 *
 * @retval	Size of the program payload
 */
unsigned int
program_tnr_mbr_get_payload_size(
		program_tnr_mbr_dma_resources_t dma_resources,
		unsigned num_of_streams);

/*
 * @brief       Fill load section descriptor of the program
 *
 * @param[in]   load_sec_desc           Pointer to the section descriptor to fill
 * @param[in]   payload_offset          Payload offset of the program (first device in the program
 * @param[in]   dma_resources           DMA resources reserved for TNR-MBR program
 * @param[in]   stream_ids_in_array     An array of the stream IDs for the TNR input transfer
 * @param[in]   stream_ids_out_array    An array of the stream IDs for the TNR output transfer
 * @param[in]   num_of_streams          The number of entries in both stream_ids_in_array and stream_ids_out_array
 *
 * @retval 0    Successful.
 * @retval 1    Error.
 */
unsigned int
program_tnr_mbr_fill_load_section_descriptor(
		ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc,
		program_tnr_mbr_dma_resources_t dma_resources,
		uint32_t *stream_ids_in_array,
		uint32_t *stream_ids_out_array,
		unsigned num_of_streams);

/*
 * @brief       Fill connect section descriptor of the program
 *
 * @param[in]   connect_sec_desc         Pointer to the section descriptor to fill
 * @param[in]   dma_resources            DMA resources reserved for TNR-MBR program
 * @param[in]   num_connect_sections     Total number of connect sections in TNR-MBR program
 * @param[in]   ref_in_terminal_id       Terminal id of the reference input data terminal
 * @param[in]   rec_sim_in_terminal_id   Terminal id of the reference spatial input terminal
 * @param[in]   ref_out_terminal_id      Terminal id of the reference output data terminal
 * @param[in]   rec_sim_out_terminal_id  Terminal id of the reference spatial output terminal
 * @param[in]   stream_ids_in_array       An array of the stream IDs for the TNR input transfer
 * @param[in]   stream_ids_out_array      An array of the stream IDs for the TNR output transfer
 * @param[in]   num_of_streams            The number of entries in both stream_ids_in_array and stream_ids_out_array
 *
 * @retval 0    Successful.
 * @retval 1    Error.
 */
int
program_tnr_mbr_fill_connect_section_descriptor(
		ia_css_program_control_init_connect_section_desc_t *connect_sec_desc,
		program_tnr_mbr_dma_resources_t dma_resources,
		uint32_t num_connect_sections,
		bool is_ref_in_enabled,
		bool is_ref_out_enabled,
		uint32_t ref_in_terminal_id,
		uint32_t rec_sim_in_terminal_id,
		uint32_t ref_out_terminal_id,
		uint32_t rec_sim_out_terminal_id,
		uint32_t *stream_ids_in_array,
		uint32_t *stream_ids_out_array,
		unsigned num_of_streams);

/*
 * @brief       Get process ID of TNR program
 *
 * @retval	ia_css_process_id_t process id
 */
ia_css_process_id_t
program_tnr_mbr_get_process_id(void);

/*
 * @brief       Calculate the totaa number of connect sections int tnr-mbr program
 *
 * @param[out]  load_section_count        Load section count in pg control init
 * @param[out]  connect_section_count     Connect section count in pg control init
 * @param[in]   dma_resources             DMA resources reserved for TNR-MBR program
 * @param[in]   num_of_streams            The number of entries in both stream_ids_in_array and stream_ids_out_array
 *
 * @retval 0    Successful.
 * @retval 1    Error.
 */
int
program_tnr_mbr_get_section_count(
		uint32_t *load_section_count,
		uint32_t *connect_section_count,
		program_tnr_mbr_dma_resources_t dma_resources,
		unsigned num_of_streams);

void
program_tnr_mbr_set_desc_sid_pid(ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc,
	uint8_t compression_acks);

#endif /* __PROGRAM_TNR_CONTROL_INIT_H */
