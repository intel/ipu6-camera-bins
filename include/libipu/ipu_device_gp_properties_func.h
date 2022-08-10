/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2019 - 2020 Intel Corporation.
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

#ifndef __IPU_DEVICE_GP_PROPERTIES_FUNC_H
#define __IPU_DEVICE_GP_PROPERTIES_FUNC_H

#include "ipu_device_gp_devices.h"
#include "storage_class.h"
#include "assert_support.h"
#include "ipu_device_gp_properties_struct.h"
#include "ipu_device_gp_properties_storage_class.h"
#include "dai/dai_device_access.h"
#ifdef __VIED_CELL
#include "dai_internal_routes_ipu_top_sp_control_tile_ps_sp.h"
#endif
#include "isa_ps_gp_regs_block_regmem.h"
#include "psa_1_gp_regs_block_regmem.h"
#include "psa_2_gp_regs_block_regmem.h"
#include "psa_3_gp_regs_block_regmem.h"

/* Include generated header files
 * todo clean up required
 * this can be removed once we switch to dai.
 */
#include "ipu_device_gp_properties_defs.h"

#define IPU_DEVICE_GP_REG_SIZE 4

STORAGE_CLASS_INLINE unsigned int
ipu_device_gp_mux_addr(const unsigned int device_id, const unsigned int mux_id)
{
	const dai_device_route_t *dai_handle = NULL;
	dai_type_id_t             dai_type;
	dai_device_id_t           dai_device;
	dai_device_port_id_t	  dai_port;
	unsigned int              dai_regidx = 0;

	assert(mux_id < IPU_DEVICE_GP_MAX_NUM);
	assert(device_id < IPU_DEVICE_GP_NUM_GP);

	switch (device_id) {
	case IPU_DEVICE_GP_PSA:
		switch (mux_id) {
		case IPU_DEVICE_GP_PSA_1_NOISE_MUX:
			dai_type   = DAI_TYPE_PSA_1_GP_REGS_BLOCK;
			dai_regidx = DAI_PSA_1_GP_REGS_BLOCK_REG_PSA_GP_REGS_NOISE_MUX_SEL;
			dai_device = DAI_IPU_TOP_PSA_1_TOP_PSA_1_FF_CLUSTER_ACC_GP_REG;
			dai_port   = DAI_PSA_1_GP_REGS_BLOCK_SLV_IN;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_PSA_2_STILLS_MODE_MUX:
			dai_type   = DAI_TYPE_PSA_2_GP_REGS_BLOCK;
			dai_regidx = DAI_PSA_2_GP_REGS_BLOCK_REG_PSA_GP_REGS_STILLS_MODE_MUX_SEL;
			dai_device = DAI_IPU_TOP_PSA_2_TOP_PSA_2_FF_CLUSTER_ACC_GP_REG;
			dai_port   = DAI_PSA_2_GP_REGS_BLOCK_SLV_IN;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_PSA_2_V2S_RGB_4_DEMUX:
			dai_type   = DAI_TYPE_PSA_2_GP_REGS_BLOCK;
			dai_regidx = DAI_PSA_2_GP_REGS_BLOCK_REG_PSA_GP_REGS_VEC2STR_RGB_4_DEMUX_SEL;
			dai_device = DAI_IPU_TOP_PSA_2_TOP_PSA_2_FF_CLUSTER_ACC_GP_REG;
			dai_port   = DAI_PSA_2_GP_REGS_BLOCK_SLV_IN;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_PSA_2_S2V_F_INPUT_MUX:
			dai_type   = DAI_TYPE_PSA_2_GP_REGS_BLOCK;
			dai_regidx = DAI_PSA_2_GP_REGS_BLOCK_REG_PSA_GP_REGS_STR2VEC_F_INPUT_MUX_SEL;
			dai_device = DAI_IPU_TOP_PSA_2_TOP_PSA_2_FF_CLUSTER_ACC_GP_REG;
			dai_port   = DAI_PSA_2_GP_REGS_BLOCK_SLV_IN;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_PSA_2_V2S_5_DEMUX:
			dai_type   = DAI_TYPE_PSA_2_GP_REGS_BLOCK;
			dai_regidx = DAI_PSA_2_GP_REGS_BLOCK_REG_PSA_GP_REGS_VEC2STR_5_DEMUX_SEL;
			dai_device = DAI_IPU_TOP_PSA_2_TOP_PSA_2_FF_CLUSTER_ACC_GP_REG;
			dai_port   = DAI_PSA_2_GP_REGS_BLOCK_SLV_IN;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_PSA_3_VCSC_BP_MUX:
			dai_type   = DAI_TYPE_PSA_3_GP_REGS_BLOCK;
			dai_regidx = DAI_PSA_3_GP_REGS_BLOCK_REG_PSA_GP_REGS_VCSC_BP_MUX_SEL;
			dai_device = DAI_IPU_TOP_PSA_3_TOP_PSA_3_FF_CLUSTER_ACC_GP_REG;
			dai_port   = DAI_PSA_3_GP_REGS_BLOCK_SLV_IN;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_LBFF_V2S_1_OUTPUT_MUX:
			dai_type   = DAI_TYPE_LBFF_INFRA_GP_REGS_BLOCK;
			dai_regidx = DAI_LBFF_INFRA_GP_REGS_BLOCK_REG_LBFF_INFRA_GP_REGS_V2S_1_OUTPUT_MUX_SEL;
			dai_device = DAI_IPU_TOP_LBFF_INFRA_TOP_LBFF_INFRA_GPREGS;
			dai_port   = DAI_LBFF_INFRA_GP_REGS_BLOCK_SLV_IN;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_PSA_1_BNLM_PIXEL_YUV_STRM_BLK:
			dai_type   = DAI_TYPE_PSA_1_GP_REGS_BLOCK;
			dai_regidx = DAI_PSA_1_GP_REGS_BLOCK_REG_PSA_GP_REGS_BNLM_PIXEL_YUV_STRM_BLOCK_EN;
			dai_device = DAI_IPU_TOP_PSA_1_TOP_PSA_1_FF_CLUSTER_ACC_GP_REG;
			dai_port   = DAI_PSA_1_GP_REGS_BLOCK_SLV_IN;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_PSA_1_BNLM_PIXEL_BAYER_STRM_BLK:
			dai_type   = DAI_TYPE_PSA_1_GP_REGS_BLOCK;
			dai_regidx = DAI_PSA_1_GP_REGS_BLOCK_REG_PSA_GP_REGS_BNLM_PIXEL_BAYER_STRM_BLOCK_EN;
			dai_device = DAI_IPU_TOP_PSA_1_TOP_PSA_1_FF_CLUSTER_ACC_GP_REG;
			dai_port   = DAI_PSA_1_GP_REGS_BLOCK_SLV_IN;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_PSA_1_BNLM_DELTA_STRM_BLK:
			dai_type   = DAI_TYPE_PSA_1_GP_REGS_BLOCK;
			dai_regidx = DAI_PSA_1_GP_REGS_BLOCK_REG_PSA_GP_REGS_BNLM_DELTA_STRM_BLOCK_EN;
			dai_device = DAI_IPU_TOP_PSA_1_TOP_PSA_1_FF_CLUSTER_ACC_GP_REG;
			dai_port   = DAI_PSA_1_GP_REGS_BLOCK_SLV_IN;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_PSA_3_VCSC_TO_GLTM_BLK:
			dai_type   = DAI_TYPE_PSA_3_GP_REGS_BLOCK;
			dai_regidx = DAI_PSA_3_GP_REGS_BLOCK_REG_PSA_GP_REGS_VCSC_TO_GLTM_BLOCK_EN;
			dai_device = DAI_IPU_TOP_PSA_3_TOP_PSA_3_FF_CLUSTER_ACC_GP_REG;
			dai_port   = DAI_PSA_3_GP_REGS_BLOCK_SLV_IN;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_PSA_3_BNLM_TO_GLTM_BLK:
			dai_type   = DAI_TYPE_PSA_3_GP_REGS_BLOCK;
			dai_regidx = DAI_PSA_3_GP_REGS_BLOCK_REG_PSA_GP_REGS_BNLM_TO_GLTM_BLOCK_EN;
			dai_device = DAI_IPU_TOP_PSA_3_TOP_PSA_3_FF_CLUSTER_ACC_GP_REG;
			dai_port   = DAI_PSA_3_GP_REGS_BLOCK_SLV_IN;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_LBFF_S2V_H_FRAME_SIZE:
			dai_type   = DAI_TYPE_LBFF_INFRA_GP_REGS_BLOCK;
			dai_regidx = DAI_LBFF_INFRA_GP_REGS_BLOCK_REG_LBFF_INFRA_GP_REGS_STR2VEC_H_FRAME_SIZE;
			dai_device = DAI_IPU_TOP_LBFF_INFRA_TOP_LBFF_INFRA_GPREGS;
			dai_port   = DAI_LBFF_INFRA_GP_REGS_BLOCK_SLV_IN;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		default:
			assert(mux_id < IPU_DEVICE_GP_PSA_MUX_NUM_MUX);
			return 0;
		}
		break;
	case IPU_DEVICE_GP_ISA_STATIC:
		dai_type = DAI_TYPE_ISA_PS_GP_REGS_BLOCK;
		dai_device = DAI_IPU_TOP_ISA_PS_TOP_ISA_PS_CLUSTER_ISA_PS_GP_REG;
		dai_port = DAI_ISA_PS_GP_REGS_BLOCK_SLV_IN;
		switch (mux_id) {
		case IPU_DEVICE_GP_ISA_STATIC_ISA_ORIG_OUT_DEMUX_SEL:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_ISA_ORIG_OUT_DEMUX_SEL;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_ISA_SCALED_A_OUT_DEMUX_SEL:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_ISA_SCALED_A_OUT_DEMUX_SEL;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_AWB_MUX_SEL:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_AWB_MUX_SEL;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_AE_MUX_SEL:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_AE_MUX_SEL;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_AF_MUX_SEL:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_AF_MUX_SEL;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_ISA_INPUT_CORR_DEMUX_SEL:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_ISA_INPUT_CORR_DEMUX_SEL;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_LSC_MUX_SEL:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_LSC_MUX_SEL;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_LSC_DEMUX_SEL:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_LSC_DEMUX_SEL;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_DPC_DEMUX_SEL:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_DPC_DEMUX_SEL;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_DPC_MUX_SEL:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_DPC_MUX_SEL;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_X2B_MUX_SEL:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_X2B_MUX_SEL;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_X2B_DEMUX_SEL:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_X2B_DEMUX_SEL;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_B2B_MUX_SEL:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_B2B_MUX_SEL;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_ISA_INPUT_CORR_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_ISA_INPUT_CORR_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_AWBMUX_INPUT_CORR_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_AWBMUX_INPUT_CORR_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_AEMUX_INPUT_CORR_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_AEMUX_INPUT_CORR_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_AFMUX_INPUT_CORR_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_AFMUX_INPUT_CORR_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_AWBMUX_B2B_MUX_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_AWBMUX_B2B_MUX_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_AEMUX_B2B_MUX_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_AEMUX_B2B_MUX_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_AFMUX_B2B_MUX_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_AFMUX_B2B_MUX_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_PAF_STREAM_SYNC_CFG:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_PAF_STRMSYNC_CFG;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_PAF_SRC_SEL:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_PAF_SRC_SEL;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_PAF_GDDPC_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_PAF_GDDPC_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_PAF_ISA_STREAM_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_PAF_ISA_PS_STREAM_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_PAF_X2B_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_PAF_X2B_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_SIS_A_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_SIS_A_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_SIS_B_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_SIS_B_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_LSC_MUX_INPUT_CORR_DEMUX_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_LSC_MUX_INPUT_CORR_DEMUX_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_DPC_MUX_INPUT_CORR_DEMUX_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_DPC_MUX_INPUT_CORR_DEMUX_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_X2B_MUX_INPUT_CORR_DEMUX_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_X2B_MUX_INPUT_CORR_DEMUX_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_DPC_MUX_LSC_DEMUX_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_DPC_MUX_LSC_DEMUX_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_X2B_MUX_LSC_DEMUX_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_X2B_MUX_LSC_DEMUX_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_LSC_MUX_X2B_DEMUX_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_LSC_MUX_X2B_DEMUX_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_DPC_MUX_X2B_DEMUX_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_DPC_MUX_X2B_DEMUX_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_B2B_MUX_LSC_DEMUX_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_B2B_MUX_LSC_DEMUX_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_B2B_MUX_X2B_DEMUX_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_B2B_MUX_X2B_DEMUX_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_LSC_MUX_DPC_DEMUX_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_LSC_MUX_DPC_DEMUX_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_B2B_MUX_DPC_DEMUX_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_B2B_MUX_DPC_DEMUX_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_X2B_MUX_DPC_DEMUX_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_X2B_MUX_DPC_DEMUX_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_B2B_B2B_MUX_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_B2B_B2B_MUX_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_3A_STAT_B2B_MUX_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_STAT_B2B_MUX_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_3A_STAT_INPUT_CORR_MUX_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_STAT_INPUT_CORR_MUX_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_SIS_A_B2B_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_SIS_A_B2B_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_SIS_B_B2B_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_SIS_B_B2B_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_ISA_ORIG_B2B_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_ISA_ORIG_B2B_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_B2R_B2B_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_B2R_B2B_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_ISA_SCALED_A_OUT_R2I_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_ISA_SCALED_A_OUT_R2I_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_ISA_FULL_OUT_R2I_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_ISA_FULL_OUT_R2I_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_IR_DEPTH_OUT_X2B_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_IR_DEPTH_OUT_X2B_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_SVE_RGBIR_BP_MUX_DEMUX_SEL:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_SVE_RGBIR_BP_MUX_DEMUX_SEL;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_IR_DEPTH_MUX_SEL:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_IR_DEPTH_MUX_SEL;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_PIF_YUV_MODE_EN:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_PIF_YUV_MODE;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_MAIN_INPUT_DOL_DEMUX_SEL:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_ISA_MAIN_INPUT_DOL_DEMUX_SEL;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_DOL_MUX_SEL:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_DOL_MUX_SEL;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		case IPU_DEVICE_GP_ISA_STATIC_MAIN_INPUT_DOL_DEMUX_PORT_BLK:
			dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_ISA_MAIN_INPUT_DOL_DEMUX_PORT_BLK;
			dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
			break;
		default:
			assert(mux_id < IPU_DEVICE_GP_ISA_STATIC_MUX_NUM_MUX);
			return 0;
		}
			break;
		case IPU_DEVICE_GP_ISA_RUNTIME:
			dai_type = DAI_TYPE_ISA_PS_GP_REGS_BLOCK;
			dai_device = DAI_IPU_TOP_ISA_PS_TOP_ISA_PS_CLUSTER_ISA_PS_GP_REG;
			dai_port = DAI_ISA_PS_GP_REGS_BLOCK_SLV_IN;
			switch (mux_id) {
			case IPU_DEVICE_GP_ISA_RUNTIME_FRAME_SIZE_ORIG_OUT:
				dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_ORIG_PADDED_FRAME_SIZE;
				dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
				break;
			case IPU_DEVICE_GP_ISA_RUNTIME_FRAME_SIZE_FULL_OUT:
				dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_FULL_FRAME_SIZE;
				dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
				break;
			case IPU_DEVICE_GP_ISA_RUNTIME_FRAME_SIZE_SCALED_A:
				dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_SCALED_A_FRAME_SIZE;
				dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
				break;
			case IPU_DEVICE_GP_ISA_RUNTIME_FRAME_SIZE_SIS_A:
				dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_SIS_A_FRAME_SIZE;
				dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
				break;
			case IPU_DEVICE_GP_ISA_RUNTIME_FRAME_SIZE_SIS_B:
				dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_SIS_B_FRAME_SIZE;
				dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
				break;
			case IPU_DEVICE_GP_ISA_RUNTIME_FRAME_SIZE_STRMCROP_A:
				dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_ORIG_FRAME_SIZE;
				dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
				break;
			case IPU_DEVICE_GP_ISA_RUNTIME_FRAME_SIZE_STRMCROP_B:
				dai_regidx = DAI_ISA_PS_GP_REGS_BLOCK_REG_ISA_GP_REGS_ORIG_FRAME_SIZE;
				dai_handle = dai_device_get_route(dai_type, dai_device, dai_port);
				break;
			default:
				assert(mux_id < IPU_DEVICE_GP_ISA_RUNTIME_MUX_NUM_MUX);
				return 0;
			}
				break;
		default:
			assert(device_id < IPU_DEVICE_GP_NUM_GP);
			return 0;
	}

	assert(NULL != dai_handle);
	return (unsigned int)(dai_handle->slave_address + dai_regidx * IPU_DEVICE_GP_REG_SIZE);
}


/* TODO the below addresses should be got by calling ipu_device_gp_mux_addr() and not defined directly */
#if 1
#define IPU_DMA_TOP_GP_DEVICES_IRQREG_IRQ0_IDX 0x0
/* The following define is required by isa_acc_init.isp.c */
#define  IPU_DEVICE_GP_ISA_STATIC_SCALED_OUT_YUV_MODE_ADDR (IPU_DEVICE_GP_ISA_BASE_ADDR \
+ IPU_ISA_PS_TOP_ISA_PS_CLUSTER_ISA_PS_GP_REG_PIF_YUV_MODE_IDX * IPU_DEVICE_GP_REG_SIZE)

/* The following define is required by dev_api_v2s/test/test_config.c */
#define IPU_DEVICE_GP_PSA_2_V2S_RGB_4_DEMUX_ADDR (IPU_DEVICE_GP_PSA_2_BASE_ADDR \
+ IPU_PSA_2_TOP_PSA_2_FF_CLUSTER_ACC_GP_REG_VEC2STR_RGB_4_DEMUX_SEL_IDX * IPU_DEVICE_GP_REG_SIZE)

/* The following define is required by psys_event_queue_fw_impl.h and sw_irq.c */
#define IPU_DEVICE_GP_IRQ0_REG_ADDR (IPU_DEVICE_GP_IRQREG_BASE_ADDR \
+ IPU_DMA_TOP_GP_DEVICES_IRQREG_IRQ0_IDX * IPU_DEVICE_GP_REG_SIZE)
#endif

#endif /* __IPU_DEVICE_GP_PROPERTIES_FUNC_H */
