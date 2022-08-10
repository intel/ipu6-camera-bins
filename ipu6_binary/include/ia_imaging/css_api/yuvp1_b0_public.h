/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2010 - 2017 Intel Corporation.
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

#ifndef _YUVP1_PUBLIC_H_
#define _YUVP1_PUBLIC_H_

/** @file
* CSS-API header file for 2500/Skycam B0 specific noice reduction (YUV_P1 component) kernel/accelerator.
*/
//#include <type_support.h>

/* All structs in this file will be visible to the CSS API User.
 * The User will be able to set each one of the config params separately by
 * specifying a different config type (see sh_config_type in sh_css.h).
 * If one of those config structs is not set explicitly, a default value will
 * be use instead.
 */

#include "yuvp1_common_public.h"

struct yuvp1_y_ee_nr_lpf_public_config {
	unsigned char a_diag;
	unsigned char a_periph;
	unsigned char a_cent;
	unsigned char y_ee_nr_en;
};

struct yuvp1_y_ee_nr_sense_public_config {

	unsigned short edge_sense_0;
	unsigned short delta_edge_sense;
	unsigned short corner_sense_0;
	unsigned short delta_corner_sense;

};

struct yuvp1_y_ee_nr_gain_public_config {

	unsigned char gain_pos_0;
	unsigned char delta_gain_posi;
	unsigned char gain_neg_0;
	unsigned char delta_gain_neg;

};

struct yuvp1_y_ee_nr_clip_public_config {

	unsigned char clip_pos_0;
	unsigned char delta_clip_posi;
	unsigned char clip_neg_0;
	unsigned char delta_clip_neg;

};

struct yuvp1_y_ee_nr_frng_public_config {

	unsigned char gain_exp;
	unsigned short min_edge;
	unsigned char lin_seg_param;
	unsigned char t1;
	unsigned char t2;
};

struct yuvp1_y_ee_nr_diag_public_config {

	unsigned char diag_disc_g;
	unsigned char hvw_hor;
	unsigned char dw_hor;
	unsigned char hvw_diag;
	unsigned char dw_diag;
};

struct yuvp1_y_ee_nr_fc_coring_public_config {

	unsigned short pos_0;
	unsigned short pos_delta;
	unsigned short neg_0;
	unsigned short neg_delta;

};

struct yuvp1_y_ee_nr_public_config {

	struct yuvp1_y_ee_nr_lpf_public_config lpf;
	struct yuvp1_y_ee_nr_sense_public_config sense;
	struct yuvp1_y_ee_nr_gain_public_config gain;
	struct yuvp1_y_ee_nr_clip_public_config clip;
	struct yuvp1_y_ee_nr_frng_public_config frng;
	struct yuvp1_y_ee_nr_diag_public_config diag;
	struct yuvp1_y_ee_nr_fc_coring_public_config fc_coring;

};

struct ia_css_2500_yuvp1_b0_kernel_config {
	struct yuvp1_y_ee_nr_public_config y_ee_nr;
	struct yuvp1_yds_public_config yds;
	struct yuvp1_chnr_public_config chnr;
};

/** @brief Print YUVP1_B0 public configuration
 *
 * @param	cfg	The pointer to configuration data
 * @return	None
 *
 * Print YUVP1_B0 public configuration.
 */
void ia_css_yuvp1_b0_public_cfg_dump(
	const struct ia_css_2500_yuvp1_b0_kernel_config *cfg);

/** @brief Compare two YUVP1_B0 public configurations
 *
 * @param	cfg1	The pointer to first configuration data
 * @param	cfg2	The pointer to second configuration data
 * @param	cfg_dump	Configurations are printed in case of
 *   			   mismatch
 * @return	true - match, false - not match
 *
 * Compare two YUVP1_B0 public configurations
 */
bool ia_css_yuvp1_b0_public_cfg_compare(
	const struct ia_css_2500_yuvp1_b0_kernel_config *cfg1,
	const struct ia_css_2500_yuvp1_b0_kernel_config *cfg2,
	bool cfg_dump);

#endif
