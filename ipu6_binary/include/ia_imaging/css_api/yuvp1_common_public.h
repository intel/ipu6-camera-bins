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

#ifndef _YUVP1_COMMON_PUBLIC_H_
#define _YUVP1_COMMON_PUBLIC_H_

/** @file
* CSS-API header file for 2500/Skycam specific noice reduction (YUV_P1 component) kernel/accelerator.
*/

/* All structs in this file will be visible to the CSS API User.
 * The User will be able to set each one of the config params separately by
 * specifying a different config type (see sh_config_type in sh_css.h).
 * If one of those config structs is not set explicitly, a default value will
 * be use instead.
 */

struct yuvp1_yds_public_config {

	unsigned char c00;
	unsigned char c01;
	unsigned char c02;
	unsigned char c03;
	unsigned char c10;
	unsigned char c11;
	unsigned char c12;
	unsigned char c13;
	unsigned char norm_factor;
	unsigned char bin_output;

};

struct yuvp1_chnr_coring_public_config {

	unsigned short u;
	unsigned short v;

};

struct yuvp1_chnr_sense_gain_public_config {

	unsigned char vy;
	unsigned char vu;
	unsigned char vv;

	unsigned char hy;
	unsigned char hu;
	unsigned char hv;
};

struct yuvp1_chnr_iir_fir_public_config {

	unsigned char fir_0h;
	unsigned char fir_1h;
	unsigned char fir_2h;
	unsigned short iir_min_prev; /* like in the ATE filter */

};

struct yuvp1_chnr_public_config {

	struct yuvp1_chnr_coring_public_config coring;
	struct yuvp1_chnr_sense_gain_public_config sense_gain;
	struct yuvp1_chnr_iir_fir_public_config iir_fir;

};

#endif
