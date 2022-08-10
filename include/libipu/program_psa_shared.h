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

#ifndef __PROGRAM_PSA_SHARED_H
#define __PROGRAM_PSA_SHARED_H

#include "math_support.h"
#include "isp_global.h" /* ISP_NWAY needed by genpipe */
#include "ia_css_vmem_resources.h"
#include "ia_css_dma_resources.h"
#include "psa_shared_defs.h"

/* TERMINALS */
/* GET terminal */
#define GET_MIN_WIDTH    64  /* 2 vectors of 32 pixels in yuv420, corresponding to 1 set YYUVYY  */
#define RYNR_MIN_LINES   12  /* RYNR buffers 4 YYUVYY line pairs (sched) / 6 YYUVYY line pairs in (FPGA),
								so at  least 12 lines should be fed. */
#define GET_MIN_HEIGHT   (RYNR_MIN_LINES * 2)  /* Conversion from YYUVYY to yuv420 */
#define GET_MAX_WIDTH    4608 /* max fragment size (pixels), based on the line buffer size of the FF pipe*/
#define GET_MAX_HEIGHT   4608 /* TODO how to determine the right max height? */

/* GET_BAYER terminal */
#define GET_BAYER_MIN_WIDTH	64  /* 2 vectors of 32 pixels in yuv420, corresponding to 1 set YYUVYY  */
#define RYNR_MIN_LINES		12  /* RYNR buffers 4 YYUVYY line pairs (sched) / 6 YYUVYY line pairs in (FPGA),
								so at  least 12 lines should be fed. */
#define GET_BAYER_MIN_HEIGHT   (RYNR_MIN_LINES * 2)  /* Conversion from YYUVYY to yuv420 */
#define GET_BAYER_MAX_WIDTH    4608 /* max fragment size (pixels), based on the line buffer size of the FF pipe*/
#define GET_BAYER_MAX_HEIGHT   4608 /* TODO how to determine the right max height? */

/* PUT terminal */
#define PUT_MIN_WIDTH    2 /* minimal value for yuv420 */
#define PUT_MIN_HEIGHT   2 /* minimal value for yuv420 */
#define PUT_MAX_WIDTH    GET_MAX_WIDTH  /* same value as for GET, when no scaling and no cropping */
#define PUT_MAX_HEIGHT   GET_MAX_HEIGHT /* same value as for GET, when no scaling and no cropping */

/*****************************************/
/* Program control init required defines */
/*****************************************/
/* This macro depends on whether the exception handling in case of frame_w < buffer_w
 * is supported or not. If it is supported, then more than one channel is needed. */
#define DMA_NCI_YUV_TRANSFER_NUM_DMA_CHANNELS_PER_PLANE	(1)
#define DMA_NCI_YUV_TRANSFER_NUM_DMA_CHANNELS		(YUV_PLANAR_FRAME_TYPE_NUM_PLANES * DMA_NCI_YUV_TRANSFER_NUM_DMA_CHANNELS_PER_PLANE)

#define MAX_LINE_WIDTH                 GET_MAX_WIDTH
#define MAX_BLOCK_WIDTH                CEIL_DIV(MAX_LINE_WIDTH, ISP_NWAY)
#define MAX_BLOCK_HEIGHT               (2)

/* Queue defines */
#define YUV_PLANAR_Q_IN_BUF_MEM        buf_mem_lb_vmem
#define YUV_PLANAR_Q_IN_BUF_START_ADDR 0
#define YUV_PLANAR_Q_IN_NUMBUF         2
#define YUV_PLANAR_Q_IN_BLK_WIDTH      (MAX_BLOCK_WIDTH)
#define YUV_PLANAR_Q_IN_BLK_HEIGHT     (MAX_BLOCK_HEIGHT)

#define YUV_PLANAR_Q_IN_WIDTH_Y        (YUV_PLANAR_Q_IN_BLK_WIDTH)
#define YUV_PLANAR_Q_IN_HEIGHT_Y       (YUV_PLANAR_Q_IN_BLK_HEIGHT)
#define YUV_PLANAR_Q_IN_SIZE_Y         (YUV_PLANAR_Q_IN_WIDTH_Y * YUV_PLANAR_Q_IN_HEIGHT_Y)

#define YUV_PLANAR_Q_IN_WIDTH_U        (YUV_PLANAR_Q_IN_WIDTH_Y >> CHROMA_SUBSAMPLE_SHIFT)
#define YUV_PLANAR_Q_IN_HEIGHT_U       (YUV_PLANAR_Q_IN_HEIGHT_Y >> CHROMA_SUBSAMPLE_SHIFT)
#define YUV_PLANAR_Q_IN_SIZE_U         (YUV_PLANAR_Q_IN_WIDTH_U * YUV_PLANAR_Q_IN_HEIGHT_U)

#define YUV_PLANAR_Q_IN_WIDTH_V        (YUV_PLANAR_Q_IN_WIDTH_Y >> CHROMA_SUBSAMPLE_SHIFT)
#define YUV_PLANAR_Q_IN_HEIGHT_V       (YUV_PLANAR_Q_IN_HEIGHT_Y >> CHROMA_SUBSAMPLE_SHIFT)
#define YUV_PLANAR_Q_IN_SIZE_V         (YUV_PLANAR_Q_IN_WIDTH_V * YUV_PLANAR_Q_IN_HEIGHT_V)

#define YUV_PLANAR_Q_IN_SIZE           (YUV_PLANAR_Q_IN_SIZE_Y + \
					YUV_PLANAR_Q_IN_SIZE_U + \
					YUV_PLANAR_Q_IN_SIZE_V)

#define BAYER_PLANAR_Q_IN_BUF_MEM        buf_mem_lb_vmem
#define BAYER_PLANAR_Q_IN_BUF_START_ADDR (0)
#define BAYER_PLANAR_Q_IN_NUMBUF         (2)
#define BAYER_PLANAR_Q_IN_BLK_WIDTH      (MAX_BLOCK_WIDTH)
#define BAYER_PLANAR_Q_IN_BLK_HEIGHT     (MAX_BLOCK_HEIGHT)

#define BAYER_PLANAR_Q_IN_SIZE           (BAYER_PLANAR_Q_IN_BLK_WIDTH * BAYER_PLANAR_Q_IN_BLK_HEIGHT)

#define Q_IN_BUF_MEM                   buf_mem_lb_vmem
#define Q_IN_BUF_START_ADDR            0
#define Q_IN_NUMBUF                    2
#define Q_IN_BLK_WIDTH                 (MAX_BLOCK_WIDTH)
#define Q_IN_BLK_HEIGHT                (MAX_BLOCK_HEIGHT)
#define Q_IN_WIDTH_Y                   (Q_IN_BLK_WIDTH)
#define Q_IN_HEIGHT_Y                  (Q_IN_BLK_HEIGHT)
#define Q_IN_SIZE_Y                    (Q_IN_WIDTH_Y * Q_IN_HEIGHT_Y)
#define Q_IN_WIDTH_UV                  (Q_IN_WIDTH_Y >> CHROMA_SUBSAMPLE_SHIFT)
#define Q_IN_HEIGHT_UV                 (Q_IN_HEIGHT_Y >> CHROMA_SUBSAMPLE_SHIFT)
#define Q_IN_SIZE_UV                   (Q_IN_WIDTH_UV * Q_IN_HEIGHT_UV)
#define Q_IN_SIZE                      (Q_IN_SIZE_Y + 2 * Q_IN_SIZE_UV)

#define Q_IN_BAYER_BUF_MEM             buf_mem_lb_vmem
#define Q_IN_BAYER_BUF_START_ADDR      (0 * ISP_VEC_BYTES)
#define Q_IN_BAYER_NUMBUF              2
#define Q_IN_BAYER_BLK_WIDTH           (MAX_BLOCK_WIDTH)
#define Q_IN_BAYER_BLK_HEIGHT          (MAX_BLOCK_HEIGHT)
#define Q_IN_BAYER_WIDTH               (Q_IN_BAYER_BLK_WIDTH)
#define Q_IN_BAYER_HEIGHT              (Q_IN_BAYER_BLK_HEIGHT)
#define Q_IN_BAYER_SIZE                (Q_IN_BAYER_WIDTH * Q_IN_BAYER_HEIGHT)

#define Q_OUT_BUF_MEM                  (VMEM_SECTION_LBPS_OUTPUT_MEM_ID)
#define Q_OUT_BUF_START_ADDR           (VMEM_SECTION_LBPS_OUTPUT_OFFSET * ISP_VEC_BYTES)
#define Q_OUT_NUMBUF                   (3)
#define Q_OUT_BLK_WIDTH                CEIL_DIV(2048, ISP_NWAY)
#define Q_OUT_BLK_HEIGHT               (MAX_BLOCK_HEIGHT)
#define Q_OUT_WIDTH_Y                  (Q_OUT_BLK_WIDTH)
#define Q_OUT_HEIGHT_Y                 (Q_OUT_BLK_HEIGHT)
#define Q_OUT_SIZE_Y                   (Q_OUT_WIDTH_Y * Q_OUT_HEIGHT_Y)
#define Q_OUT_WIDTH_U                  (Q_OUT_WIDTH_Y >> CHROMA_SUBSAMPLE_SHIFT)
#define Q_OUT_HEIGHT_U                 (Q_OUT_HEIGHT_Y >> CHROMA_SUBSAMPLE_SHIFT)
#define Q_OUT_SIZE_U                   (Q_OUT_WIDTH_U * Q_OUT_HEIGHT_U)
#define Q_OUT_WIDTH_V                  (Q_OUT_WIDTH_Y >> CHROMA_SUBSAMPLE_SHIFT)
#define Q_OUT_HEIGHT_V                 (Q_OUT_HEIGHT_Y >> CHROMA_SUBSAMPLE_SHIFT)
#define Q_OUT_SIZE_V                   (Q_OUT_WIDTH_V * Q_OUT_HEIGHT_V)
#define Q_OUT_SIZE                     (Q_OUT_SIZE_Y + Q_OUT_SIZE_U + Q_OUT_SIZE_V)

/* For NV12 output */
#define Q_OUT_WIDTH_UV                  (Q_OUT_WIDTH_U)
#define Q_OUT_HEIGHT_UV                 (Q_OUT_HEIGHT_Y >> CHROMA_SUBSAMPLE_SHIFT)
#define Q_OUT_SIZE_UV                   (Q_OUT_WIDTH_UV * Q_OUT_HEIGHT_UV)

#define YYUVYY_HOR_INTERLEAVE_FACTOR   (3)
#define BYTES_PER_PIXEL                (2)
#define CHROMA_SUBSAMPLE_SHIFT         (1)
#define BAYER_SUBSAMPLE_SHIFT          (1)

#define DMA_NCI_INPUT_TRANSFER_RESOURCE_ID		vied_nci_dev_chn_dma_ext1_read
#define DMA_NCI_YYUVYY_INPUT_TRANSFER_DMA_RESOURCE_ID	DMA_NCI_INPUT_TRANSFER_RESOURCE_ID
#define DMA_NCI_YYUVYY_INPUT_TRANSFER_NUM_DMA_CHANNELS	(1)
#define DMA_BAYER_IN_SIZE      (1)
#define DMA_YYUVYY_IN_SIZE     (1)


#define DMA_NCI_YUV_PLANAR_INPUT_TRANSFER_DMA_RESOURCE_ID	DMA_NCI_INPUT_TRANSFER_RESOURCE_ID

#define DMA_NCI_YUV_OUTPUT_TRANSFER_DMA_RESOURCE_ID		vied_nci_dev_chn_dma_ext1_write

#define DFM_DMA_BAYER_INPUT_DMA_RESOURCE_ID			DMA_NCI_INPUT_TRANSFER_RESOURCE_ID
#define DMA_NCI_BAYER_INPUT_TRANSFER_DMA_RESOURCE_ID		vied_nci_dev_chn_dma_ext1_read
#define DMA_NCI_BAYER_INPUT_TRANSFER_NUM_DMA_CHANNELS		(1)
#define DMA_NCI_BAYER_INPUT_TRANSFER_NUM_LINES_INTERLEAVED	(2)

#define DMA_NCI_BAYER_PLANAR_INPUT_TRANSFER_NUM_DMA_CHANNELS	(4)

/*DMA resources offsets*/
#define	VIED_NCI_LB_VMEM_TYPE_OFFSET                    0
#define	VIED_NCI_DEV_CHN_DMA_EXT0_OFFSET                IA_CSS_DMA_RESOURCES_DMA_LB_CHN_OFFSET_PSA
#define VIED_NCI_DEV_CHN_DMA_EXT1_WRITE_OFFSET          IA_CSS_DMA_RESOURCES_DMA_EXT1_CHN_WRITE_OFFSET_PSA

/* NOTE: VIED_NCI_DEV_CHN_DMA_EXT1_READ_OFFSET is used by mutually excluse programs
 * program_psa_in_bayer_dma_v2s and program_psa_in_dma_v2s. */
#define VIED_NCI_DEV_CHN_DMA_EXT1_READ_OFFSET           IA_CSS_DMA_RESOURCES_DMA_EXT1_CHN_READ_OFFSET_PSA

#define PSA_IN_DMA_V2S_RESOURCE_OFFSET VIED_NCI_DEV_CHN_DMA_EXT1_READ_OFFSET
#define PSA_IN_DMA_V2S_SIZE MAX(MAX(DMA_NCI_YUV_TRANSFER_NUM_DMA_CHANNELS, DMA_NCI_BAYER_PLANAR_INPUT_TRANSFER_NUM_DMA_CHANNELS), \
			MAX(DMA_NCI_YYUVYY_INPUT_TRANSFER_NUM_DMA_CHANNELS, DMA_NCI_BAYER_INPUT_TRANSFER_NUM_DMA_CHANNELS))

#define PSA_GAMMASTAR_DMA_SPATIAL_NUM_DMA_CHANNELS	(1)
#define PSA_GAMMASTAR_DMA_ID_ISP_MODEL			vied_nci_dev_chn_dma_ext0
#define PSA_GAMMASTAR_DMA_ID_API_MODEL			VIED_NCI_DEV_CHN_DMA_EXT0_ID

#define PSA_OUT_DMA_S2V_SIZE                DMA_NCI_YUV_TRANSFER_NUM_DMA_CHANNELS
#define PSA_OUT_DMA_S2V_Y_RESOURCE_OFFSET   VIED_NCI_DEV_CHN_DMA_EXT1_WRITE_OFFSET

#define DMA_NCI_YUV_TRANSFER_NUM_DMA_CHANNELS_PER_PLANE_FOR_VERTICAL_PADDING   (1)
#define DMA_NCI_YUV_TRANSFER_NUM_PLANES                 (3)
#define PSA_OUT_NUMBER_OF_STREAMS DMA_NCI_YUV_TRANSFER_NUM_PLANES

#define DMA_OUT_Y_SIZE            (DMA_NCI_YUV_TRANSFER_NUM_DMA_CHANNELS_PER_PLANE)
#define DMA_OUT_U_SIZE            (DMA_NCI_YUV_TRANSFER_NUM_DMA_CHANNELS_PER_PLANE)
#define DMA_OUT_V_SIZE            (DMA_NCI_YUV_TRANSFER_NUM_DMA_CHANNELS_PER_PLANE)

#define DMA_OUT_Y_RESOURCE_OFFSET VIED_NCI_DEV_CHN_DMA_EXT1_WRITE_OFFSET
#define DMA_OUT_U_RESOURCE_OFFSET (DMA_OUT_Y_RESOURCE_OFFSET + DMA_OUT_Y_SIZE)
#define DMA_OUT_V_RESOURCE_OFFSET (DMA_OUT_U_RESOURCE_OFFSET + DMA_OUT_U_SIZE)

#define DMA_OUT_RESOURCE_ID		VIED_NCI_DEV_CHN_DMA_EXT1_WRITE_ID
#define DMA_OUT_RESOURCE_OFFSET DMA_OUT_Y_RESOURCE_OFFSET

#define DMA_OUT_DUMMY_TOP_Y_RESOURCE_OFFSET	(DMA_OUT_V_RESOURCE_OFFSET + DMA_OUT_V_SIZE)
#define DMA_OUT_DUMMY_TOP_Y_SIZE			(DMA_NCI_YUV_TRANSFER_NUM_DMA_CHANNELS_PER_PLANE_FOR_VERTICAL_PADDING)
#define DMA_OUT_DUMMY_TOP_U_RESOURCE_OFFSET	(DMA_OUT_DUMMY_TOP_Y_RESOURCE_OFFSET + DMA_OUT_DUMMY_TOP_Y_SIZE)
#define DMA_OUT_DUMMY_TOP_U_SIZE			(DMA_NCI_YUV_TRANSFER_NUM_DMA_CHANNELS_PER_PLANE_FOR_VERTICAL_PADDING)
#define DMA_OUT_DUMMY_TOP_V_RESOURCE_OFFSET	(DMA_OUT_DUMMY_TOP_U_RESOURCE_OFFSET + DMA_OUT_DUMMY_TOP_U_SIZE)
#define DMA_OUT_DUMMY_TOP_V_SIZE			(DMA_NCI_YUV_TRANSFER_NUM_DMA_CHANNELS_PER_PLANE_FOR_VERTICAL_PADDING)

#define DMA_OUT_DUMMY_TOP_RESOURCE_OFFSET	DMA_OUT_DUMMY_TOP_Y_RESOURCE_OFFSET
#define DMA_OUT_DUMMY_TOP_SIZE				(DMA_OUT_DUMMY_TOP_Y_SIZE + DMA_OUT_DUMMY_TOP_U_SIZE + DMA_OUT_DUMMY_TOP_V_SIZE)

#define DMA_OUT_DUMMY_BOTTOM_Y_RESOURCE_OFFSET	(DMA_OUT_DUMMY_TOP_V_RESOURCE_OFFSET + DMA_OUT_DUMMY_TOP_V_SIZE)
#define DMA_OUT_DUMMY_BOTTOM_Y_SIZE			(DMA_NCI_YUV_TRANSFER_NUM_DMA_CHANNELS_PER_PLANE_FOR_VERTICAL_PADDING)
#define DMA_OUT_DUMMY_BOTTOM_U_RESOURCE_OFFSET	(DMA_OUT_DUMMY_BOTTOM_Y_RESOURCE_OFFSET + DMA_OUT_DUMMY_BOTTOM_Y_SIZE)
#define DMA_OUT_DUMMY_BOTTOM_U_SIZE			(DMA_NCI_YUV_TRANSFER_NUM_DMA_CHANNELS_PER_PLANE_FOR_VERTICAL_PADDING)
#define DMA_OUT_DUMMY_BOTTOM_V_RESOURCE_OFFSET	(DMA_OUT_DUMMY_BOTTOM_U_RESOURCE_OFFSET + DMA_OUT_DUMMY_BOTTOM_U_SIZE)
#define DMA_OUT_DUMMY_BOTTOM_V_SIZE			(DMA_NCI_YUV_TRANSFER_NUM_DMA_CHANNELS_PER_PLANE_FOR_VERTICAL_PADDING)

#define DMA_OUT_DUMMY_BOTTOM_RESOURCE_OFFSET	DMA_OUT_DUMMY_BOTTOM_Y_RESOURCE_OFFSET
#define DMA_OUT_DUMMY_BOTTOM_SIZE			(DMA_OUT_DUMMY_BOTTOM_Y_SIZE + DMA_OUT_DUMMY_BOTTOM_U_SIZE + DMA_OUT_DUMMY_BOTTOM_V_SIZE)
/* Vertical padding DMA channels size is 9 instead of 3 (3 for image and another 6 for padding) */
#define DMA_OUT_S2V_VERTICAL_PADDING_SIZE	((DMA_OUT_Y_SIZE + DMA_OUT_U_SIZE + DMA_OUT_V_SIZE) + DMA_OUT_DUMMY_TOP_SIZE + DMA_OUT_DUMMY_BOTTOM_SIZE)

#endif /* __PROGRAM_PSA_SHARED_H */
