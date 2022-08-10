/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2017 - 2019 Intel Corporation.
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

#ifndef __NCI_OFS_TYPES_H
#define __NCI_OFS_TYPES_H

#include "type_support.h"
#include "frame_support.h"
#include "ipu_buf_cfg_types.h"
#include "ipu_dma_cfg_types.h"
#include "ipu_event_cfg_types.h"
#include "ipu_dim_cfg_types.h"
#include "ipu_device_ofs_devices.h"

/* genpipe doesn't support B = A in enum definition */
#ifndef PIPE_GENERATION

typedef enum yuv_planar_frame_types_planes nci_ofs_ddr_terminal_plane;

#endif /* PIPE_GENERATION */

/* WARNING: DON'T CHANGE THE ORDER OF THE FIELDS AS THEY MIGHT REPRESENT THE REGISTER
 * LAYOUT.
 */

/**
 * OFS has two types of components: scaler and formatter.
 * of -> Output Formatter.
 * sc -> Scaler.
 */

struct nci_ofs_of_buf_cfg {
	struct ipu_buf_cfg buf_config;
	struct ipu_buf_properties y;
	struct ipu_buf_properties u;
	struct ipu_buf_properties v;
};

struct nci_ofs_of_hist_buf_cfg {
	uint32_t num_buf;
	struct ipu_buf_properties hist_prop;
};

struct nci_ofs_of_stream2gen_cfg {
	uint32_t wr_ptr_addr; /* address in Buttress where OFS sends progress updates for its wr_ptr (tptr) */
	uint32_t buffer_size;         /* streaming buffer size. Unit of buffer size are lines */
	/* FrameIDX is configured through the connect section for each new frame */
};

/* To be used by connection manager to set the DDR addresses and write to the HW
 * for each PIN
 */
struct nci_ofs_of_term_ptr_cfg {
	uint32_t y_addr;
	uint32_t u_addr;
	uint32_t v_addr;
	uint32_t y_stride;
	uint32_t uv_stride;
};

/**
 * Shared among all the Pins,
 * struct ipu_ofs_of_share_cfg_obj, as a blob, will be filled by PG Control Init code of OFS.
 * It will be written by Program Load to the HW of the Formatter.
 */
struct nci_ofs_of_share_cfg {
	uint32_t descriptor_rpwc;		/* Read Post Write Check for DMA Descriptor in T-DMEM */
	uint32_t ofa_control;			/* To enable Stream to GEN (1 if enabled) */
};

/**
 * For EACH PIN,
 * struct ipu_ofs_of_pin_cfg, as a blob, will be filled by PG Control Init code of OFS.
 * It will be written by Program Load to the HW of the Formatter.
 */
struct nci_ofs_of_pin_cfg {
	struct ipu_dim_cfg input_dim;			/* Input resolution to the Formatter */
	struct ipu_dim_cfg output_dim;			/* Output resolution of the Formatter (basically Terminal) */
	struct ipu_pos_cfg position;			/* Left and top position from the input resolution */
	struct nci_ofs_of_buf_cfg input_buf;		/* Consumer side of the formatter */
	struct nci_ofs_of_buf_cfg output_buf;		/* Producer side of the formatter */
	struct nci_ofs_of_hist_buf_cfg hist_buf;	/* History Buffer */
	/* To be filled by Connection manager */
 	struct nci_ofs_of_term_ptr_cfg output_ptr;
	struct ipu_dma_cfg dma_cfg;			/* Dma descriptor information required by the formatter */
	struct ipu_event_cfg frag_done_evt;		/* Ack configuration after fragment is done */
	struct nci_ofs_of_stream2gen_cfg stream2gen_cfg;	/* Stream2gen configuration */
};

/**
 * For EACH SCALER,
 * struct nci_ofs_sc_cfg, as a blob, will be filled by PG Control Init code of OFS.
 * It will be written by Program Load to the HW of the Formatter.
 */
struct nci_ofs_sc_cfg {
	uint32_t inp_buf_y_st_addr;
	uint32_t inp_buf_y_line_stride;
	uint32_t inp_buf_y_buffer_stride;
	uint32_t inp_buf_u_st_addr;
	uint32_t inp_buf_v_st_addr;
	uint32_t inp_buf_uv_line_stride;
	uint32_t inp_buf_uv_buffer_stride;
	uint32_t inp_buf_chunk_width;
	uint32_t inp_buf_nr_buffers;
	/* Output buffers */
	uint32_t out_buf_y_st_addr;
	uint32_t out_buf_y_line_stride;
	uint32_t out_buf_y_buffer_stride;
	uint32_t out_buf_u_st_addr;
	uint32_t out_buf_v_st_addr;
	uint32_t out_buf_uv_line_stride;
	uint32_t out_buf_uv_buffer_stride;
	uint32_t out_buf_nr_buffers;
	/* Intermediate buffers */
	uint32_t int_buf_y_st_addr;
	uint32_t int_buf_y_line_stride;
	uint32_t int_buf_u_st_addr;
	uint32_t int_buf_v_st_addr;
	uint32_t int_buf_uv_line_stride;
	uint32_t int_buf_height;
	uint32_t int_buf_chunk_width;
	uint32_t int_buf_chunk_height;
	/* Context buffers */
	uint32_t ctx_buf_hor_y_st_addr;
	uint32_t ctx_buf_hor_u_st_addr;
	uint32_t ctx_buf_hor_v_st_addr;
	uint32_t ctx_buf_ver_y_st_addr;
	uint32_t ctx_buf_ver_u_st_addr;
	uint32_t ctx_buf_ver_v_st_addr;
	/* Control addresses */
	uint32_t release_inp_buf_addr;
	uint32_t release_inp_buf_en;
	uint32_t process_out_buf_en;
	uint32_t process_out_buf_addr;
};

struct nci_ofs_sc_sid_pid_cfg {
	/* CMD PID and SID */
	uint32_t cmd_sid;
	uint32_t cmd_pid;
};

struct nci_ofs_cfg_pin_unscaled {
	struct nci_ofs_of_share_cfg of_share_cfg;
	struct nci_ofs_of_pin_cfg pin_cfg;
};

struct nci_ofs_cfg_pin_scaled {
	struct nci_ofs_of_share_cfg of_share_cfg;
	struct nci_ofs_of_pin_cfg pin_cfg;
	struct nci_ofs_sc_cfg sc_cfg;
	struct nci_ofs_sc_sid_pid_cfg sc_sid_pid_cfg;
};

#define NCI_OFS_OF_SHARE_SECTION           (0)
#define	NCI_OFS_OF_PIN0_SECTION            (NCI_OFS_OF_SHARE_SECTION + 1)
#define NCI_OFS_OF_PIN1_SECTION            (NCI_OFS_OF_SHARE_SECTION + 1)
#define NCI_OFS_OF_PIN2_SECTION            (NCI_OFS_OF_SHARE_SECTION + 1)
#define NCI_OFS_OF_SC0_SECTION             (NCI_OFS_OF_PIN1_SECTION + 1)
#define NCI_OFS_OF_SC0_SID_PID_SECTION     (NCI_OFS_OF_SC0_SECTION + 1)
#define NCI_OFS_OF_SC1_SECTION             (NCI_OFS_OF_PIN2_SECTION + 1)
#define NCI_OFS_OF_SC1_SID_PID_SECTION     (NCI_OFS_OF_SC1_SECTION + 1)

#define NCI_OFS_NUM_SECTIONS_PIN_MAIN      (NCI_OFS_OF_PIN0_SECTION + 1)
#define NCI_OFS_NUM_SECTIONS_PIN_DISPLAY   (NCI_OFS_OF_SC0_SID_PID_SECTION + 1)
#define NCI_OFS_NUM_SECTIONS_PIN_PP        (NCI_OFS_OF_SC1_SID_PID_SECTION + 1)

/* Interleaved chroma plane for semi-planer formats uses the plane index
 * of the second plane of the tri-planar format enumeration above
 */
#define NCI_OFS_DDR_TERM_U_V_PLANE NCI_OFS_DDR_TERM_U_PLANE

#endif /* __NCI_OFS_CFG_TYPES_H */
