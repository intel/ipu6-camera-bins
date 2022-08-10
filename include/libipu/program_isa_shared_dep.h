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

#ifndef __PROGRAM_ISA_SHARED_DEP_H
#define __PROGRAM_ISA_SHARED_DEP_H

#include "math_support.h"
#include "ia_css_vmem_resources.h"
#include "isa_shared_defs.h"


/* TERMINALS */

#define PUT_SIS_A_MIN_WIDTH	(256)
#define PUT_SIS_A_MIN_HEIGHT	(128)
#define PUT_SIS_A_MAX_WIDTH	(7168)
#define PUT_SIS_A_MAX_HEIGHT	(6400)

#define PUT_IR_DEPTH_MIN_WIDTH		(256)
#define PUT_IR_DEPTH_MIN_HEIGHT		(128)
#define PUT_IR_DEPTH_MAX_WIDTH		(7168)
#define PUT_IR_DEPTH_MAX_HEIGHT		(6400)

#define PUT_YUV_A_MIN_WIDTH	(256)
#define PUT_YUV_A_MIN_HEIGHT	(128)
#define PUT_YUV_A_MAX_WIDTH	(5120)
#define PUT_YUV_A_MAX_HEIGHT	(7168)

#define PUT_YUV_B_MIN_WIDTH	PUT_YUV_A_MIN_WIDTH
#define PUT_YUV_B_MIN_HEIGHT	PUT_YUV_A_MIN_HEIGHT
#define PUT_YUV_B_MAX_WIDTH	PUT_YUV_A_MAX_WIDTH
#define PUT_YUV_B_MAX_HEIGHT	PUT_YUV_A_MAX_HEIGHT

#define PUT_VIDEO_FULL_MIN_WIDTH	(256)
#define PUT_VIDEO_FULL_MIN_HEIGHT	(128)
#define PUT_VIDEO_FULL_MAX_WIDTH	(2560)
#define PUT_VIDEO_FULL_MAX_HEIGHT	(7168)

#define INPUT_BLOCK_WIDTH	(2048)
#define IPFD_PAF_NUMBUF		(3)

#define PUT_SIS_B_MIN_WIDTH	PUT_SIS_A_MIN_WIDTH
#define PUT_SIS_B_MIN_HEIGHT	PUT_SIS_A_MIN_HEIGHT
#define PUT_SIS_B_MAX_WIDTH	PUT_SIS_A_MAX_WIDTH
#define PUT_SIS_B_MAX_HEIGHT	PUT_SIS_A_MAX_HEIGHT


#define VIED_NCI_DEV_CHN_DMA_ISA_OFFSET		(0)
#define VIED_NCI_DEV_CHN_DMA_ISA_PAF_OFFSET	(1) /* VIED_NCI_DEV_CHN_DMA_ISA_MAX_SIZE = 2 */
#define VIED_NCI_DEV_CHN_DMA_EXT0_OFFSET	(2) /* FIXME - IA_CSS_DMA_RESOURCES_DMA_LB_CHN_OFFSET_ISL */
#define ISL_PS_AF_DMA_OFFSET			VIED_NCI_DEV_CHN_DMA_EXT0_OFFSET
#define ISL_PS_AWB_DMA_OFFSET			VIED_NCI_DEV_CHN_DMA_EXT0_OFFSET
#define ISL_PS_LSC_DMA_OFFSET			(ISL_PS_AF_DMA_OFFSET + AF_DMA_SIZE + AWB_DMA_SIZE)
#define ISL_PS_PAF_DMA_OFFSET			(ISL_PS_LSC_DMA_OFFSET + LSC_DMA_SIZE)
#define ISL_PS_AWB_DMA_EXT0_READ_OFFSET		VIED_NCI_DEV_CHN_DMA_EXT0_OFFSET
#define ISL_PS_AWB_DMA_EXT0_READ_SIZE		(2) /* TODO - update when moving to planar */
#define ISL_PS_AF_DMA_EXT0_READ_OFFSET		(ISL_PS_AWB_DMA_EXT0_READ_OFFSET + ISL_PS_AWB_DMA_EXT0_READ_SIZE)
#define ISL_PS_AF_DMA_EXT0_READ_SIZE		(2) /* TODO - update when moving to planar */

#define VIED_NCI_DEV_CHN_DMA_EXT1_WRITE_OFFSET	(21) /* FIXME - IA_CSS_DMA_RESOURCES_DMA_EXT1_CHN_WRITE_OFFSET_ISL */
#define VIED_NCI_DEV_CHN_DMA_EXT1_READ_OFFSET	(12) /* FIXME - IA_CSS_DMA_RESOURCES_DMA_EXT1_CHN_READ_OFFSET_ISL */

#if HAS_FF_DOL_DOL
#define VIED_NCI_DEV_CHN_DMA_EXT1_READ_DOL_INPUT_HIGH_OFFSET	(VIED_NCI_DEV_CHN_DMA_EXT1_READ_OFFSET + 1)
#define VIED_NCI_DEV_CHN_DMA_EXT1_READ_DOL_INPUT_SHORT_OFFSET	(VIED_NCI_DEV_CHN_DMA_EXT1_READ_DOL_INPUT_HIGH_OFFSET + 1)
#define VIED_NCI_DEV_CHN_DMA_EXT1_READ_DOL_INPUT_MEDIUM_OFFSET	(VIED_NCI_DEV_CHN_DMA_EXT1_READ_DOL_INPUT_SHORT_OFFSET + 1)

#define VIED_NCI_DEV_CHN_DMA_ISA_DOL_OFFSET	(0) /* DOL and BAYER cannot be co-existed, so DOL can share BAYER resource */

#define VIED_NCI_DEV_CHN_DMA_EXT1_READ_PAF_OFFSET		(VIED_NCI_DEV_CHN_DMA_EXT1_READ_DOL_INPUT_MEDIUM_OFFSET + 1)
#else
#define VIED_NCI_DEV_CHN_DMA_EXT1_READ_PAF_OFFSET		(VIED_NCI_DEV_CHN_DMA_EXT1_READ_OFFSET + 1)
#endif

/*
 * TODO: once it has become possible to make non-relocatable resources explicit in .pipe files, unify the offset
 * definition below. Currently, this must be hardcoded to match the program order.
 */
#define DMA_OUT_STILL_ORIG_RES_DMA_CHAN_OFFSET	VIED_NCI_DEV_CHN_DMA_EXT1_WRITE_OFFSET
#define DMA_OUT_SCALED_A_DMA_CHAN_OFFSET	(DMA_OUT_STILL_ORIG_RES_DMA_CHAN_OFFSET + DMA_OUT_STILL_ORIG_RES_SIZE)
#if HAS_FF_R2I_DS_B
#define DMA_OUT_SCALED_B_DMA_CHAN_OFFSET	(DMA_OUT_SCALED_A_DMA_CHAN_OFFSET + DMA_OUT_SCALED_DMA_NOF_CHANS)
#define DMA_OUT_SIS_A_DMA_CHAN_OFFSET		(DMA_OUT_SCALED_B_DMA_CHAN_OFFSET + DMA_OUT_SCALED_DMA_NOF_CHANS)
#else
#define DMA_OUT_SIS_A_DMA_CHAN_OFFSET		(DMA_OUT_SCALED_A_DMA_CHAN_OFFSET + DMA_OUT_SCALED_DMA_NOF_CHANS)
#endif
#define DMA_OUT_SIS_B_DMA_CHAN_OFFSET		(DMA_OUT_SIS_A_DMA_CHAN_OFFSET + DMA_OUT_SIS_DMA_NOF_CHANS)
#define DMA_OUT_VIDEO_FULL_DMA_CHAN_OFFSET	(DMA_OUT_SIS_B_DMA_CHAN_OFFSET + DMA_OUT_SIS_DMA_NOF_CHANS)

#define DMA_OUT_IR_DMA_CHAN_OFFSET		(DMA_OUT_VIDEO_FULL_DMA_CHAN_OFFSET + DMA_NCI_YUV_TRANSFER_NUM_DMA_CHANNELS)

#define DMA_OUT_IR_DMA_ID_API_MODEL		VIED_NCI_DEV_CHN_DMA_EXT1_WRITE_ID
#define DMA_OUT_IR_DMA_ID_ISP_MODEL		vied_nci_dev_chn_dma_ext1_write

/* Scaled B YUV Planar */
#define SCALED_B_Q_OUT_BUF_MEM			(VMEM_SECTION_ISA2PSA_ISA_OUTPUT_MEM_ID)
#define SCALED_B_Q_OUT_BUF_START_ADDR	(VMEM_SECTION_ISA2PSA_ISA_OUTPUT_OFFSET * VECTOR_SIZE_IN_BYTES)

/* Defines for output buffers - TRANSFER VMEM */
/* Scaled A YUV Planar */
#define SCALED_A_Q_OUT_BUF_MEM		VMEM_SECTION_ISLPS_OUTPUT_MEM_ID
#define SCALED_A_Q_OUT_BUF_START_ADDR	(VMEM_SECTION_ISLPS_OUTPUT_OFFSET * VECTOR_SIZE_IN_BYTES)

/* Bayer full resolution */
#define OUTPUT_STILL_ORIG_RES_BUF_MEM_TYPE		(VMEM_SECTION_ISLPS_OUTPUT_MEM_ID)
#define OUTPUT_STILL_ORIG_RES_BUF_START_ADDR	(SCALED_A_Q_OUT_BUF_START_ADDR + SCALED_A_Q_OUT_MEM_SIZE)

/* Video FULL YUV Planar - same definitions as for Bayer full resolution */
#define VIDEO_FULL_Q_OUT_BUF_MEM	(OUTPUT_STILL_ORIG_RES_BUF_MEM_TYPE)
#define VIDEO_FULL_Q_OUT_BUF_START_ADDR	(OUTPUT_STILL_ORIG_RES_BUF_START_ADDR) /* bayer still and YUV full resolutions are mutex */


/* IR/MD output */
#define OUTPUT_IR_BUF_MEM_TYPE		VMEM_SECTION_ISLPS_OUTPUT_MEM_ID
#define OUTPUT_IR_BUF_MEM_OFFSET	(VIDEO_FULL_Q_OUT_BUF_START_ADDR + VIDEO_FULL_Q_OUT_MEM_SIZE)


/* DEC connect sections */
#define DEC_CONNECT_SECTIONS_PER_PIN	(4)

/* DMA resources offsets */
#define VIED_NCI_ISL_VMEM_TYPE_OFFSET		(0)
#define VIED_NCI_TRANSFER_VMEM0_TYPE_OFFSET	(0)
#define VIED_NCI_TRANSFER_VMEM1_TYPE_OFFSET	(0)
#define ISL_PS_AF_DMA_ID_API_MODEL		VIED_NCI_DEV_CHN_DMA_EXT0_ID


/*
 * TODO: update once the duplicate, mismatching ISP resource model has been eliminated
 */
#define DMA_OUT_SCALED_DMA_ID_API_MODEL		VIED_NCI_DEV_CHN_DMA_EXT1_WRITE_ID
#define ISL_PS_DMA_ID_API_MODEL			VIED_NCI_DEV_CHN_DMA_EXT0_ID
#define ISL_PS_DMA_ID_ISP_MODEL			vied_nci_dev_chn_dma_ext0

#define DMA_OUT_STILL_ORIG_RES_DMA_ID_ISP_MODEL	vied_nci_dev_chn_dma_ext1_write
#define DMA_OUT_SCALED_DMA_ID_ISP_MODEL		vied_nci_dev_chn_dma_ext1_write
#define DMA_OUT_SIS_DMA_ID_API_MODEL		VIED_NCI_DEV_CHN_DMA_EXT1_WRITE_ID
#define DMA_OUT_SIS_DMA_ID_ISP_MODEL		vied_nci_dev_chn_dma_ext1_write


/* SIS bayer interleaved */
#define OUTPUT_SIS_BUF_MEM_TYPE		VMEM_SECTION_ISLPS_OUTPUT_MEM_ID
/* SIS A buffer allocated after video full*/
#define OUTPUT_SIS_BUF_MEM_OFFSET	(OUTPUT_IR_BUF_MEM_OFFSET + OUTPUT_IR_BUF_MEM_SIZE)
/* SIS b buffer allocated after SIS A*/
#define OUTPUT_SIS_B_BUF_MEM_OFFSET	(OUTPUT_SIS_BUF_MEM_OFFSET + OUTPUT_SIS_BUF_MEM_SIZE)


#define DFM_3A_AF_DMA_SPATIAL_NUM_DMA_CHANNELS	(2)
#define DFM_3A_AF_NUM_BUFFERS			(2)
#define DFM_3A_AWB_DMA_SPATIAL_NUM_DMA_CHANNELS	(2)
#define DFM_3A_AWB_NUM_BUFFERS			(2)
#define DFM_PAF_DMA_SPATIAL_NUM_DMA_CHANNELS	(1)
#define DFM_PAF_NUM_BUFFERS					(2)



#endif /* __PROGRAM_ISA_SHARED_H */
