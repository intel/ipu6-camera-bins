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

/** @file
* CSS-API header file for 2500/Skycam Bayer Down-scaling (BDS) kernel/accelerator.
*
*  Created on: Aug 18, 2013
*      Author: ynahum
*/
//#include <type_support.h>

#ifndef BDS_PUBLIC_H_
#define BDS_PUBLIC_H_

#define BDS_MAX_SEQ_PATTERN_SIZE 8
#define BDS_MAX_PHASES 64
#define BDS_NUM_OF_TAPS 6

#define BDS_SCALE_RATIO_GRANULARITY 32
#define BDS_MAX_SF (BDS_SCALE_RATIO_GRANULARITY * 4)
#define BDS_MIN_SF (BDS_SCALE_RATIO_GRANULARITY)

#define BDS_NUM_OF_SF ( 1 + BDS_MAX_SF - BDS_MIN_SF )

struct bds_public_config {

	unsigned int hor_crop_enable;
	unsigned int hor_crop_start;
	unsigned int hor_crop_end;

	unsigned int hor_enable;
	int hor_coeffs[BDS_MAX_PHASES][BDS_NUM_OF_TAPS];
	unsigned int hor_nf[BDS_MAX_PHASES];

	unsigned int ver_enable;
	int ver_coeffs[BDS_MAX_PHASES][BDS_NUM_OF_TAPS];
	unsigned int ver_nf[BDS_MAX_PHASES];

	unsigned int phase_count;
	unsigned int sequence_len;
	unsigned int sequence_pat[BDS_MAX_SEQ_PATTERN_SIZE];


};

struct ia_css_2500_bds_kernel_config {
	struct bds_public_config bds;
};

/** @brief Print BDS public configuration
 *
 * @param	cfg	The pointer to configuration data
 * @return	None
 *
 * Print BDS public configuration.
 */
void ia_css_bds_public_cfg_dump(const struct ia_css_2500_bds_kernel_config *cfg);

/** @brief Compare two BDS public configurations
 *
 * @param	cfg1	The pointer to first configuration data
 * @param	cfg2	The pointer to second configuration data
 * @param	cfg_dump	Configurations are printed in case of
 *   			   mismatch
 * @return	true - match, false - not match
 *
 * Compare two BDS public configurations
 */
bool ia_css_bds_public_cfg_compare(
	const struct ia_css_2500_bds_kernel_config *cfg1,
	const struct ia_css_2500_bds_kernel_config *cfg2,
	bool cfg_dump);

#endif /* BDS_PUBLIC_H_ */
