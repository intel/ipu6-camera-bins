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

#ifndef _DM_PUBLIC_H_
#define _DM_PUBLIC_H_

/** @file
* CSS-API header file for 2500/Skycam Demosaic (DM) kernel/accelerator.
*/
//#include <type_support.h>

struct dm_public_config {
    /** Demosaic enable flag */
    unsigned char dm_en;
    /** Checker Artifact Removal enable */
    unsigned char ch_ar_en;
    /** false color correction enable */
    unsigned char fcc_en;
    /** sharpening coefficient for green calculation [0..31] */
    unsigned char gamma_sc;
    /** control param for weights of Chroma Homogeneity metric [0..31] */
    unsigned char lc_ctrl;
    /** Control param for Checker artifact removal [0..31] */
    unsigned char cr_param1;
    /** Control param for Checker artifact removal [0..31] */
    unsigned char cr_param2;
    /** False color correction control [0..31] */
    unsigned char coring_param;
};

struct ia_css_2500_dm_kernel_config {
    struct dm_public_config dm;
};

/** @brief Print DM public configuration
 *
 * @param	cfg	The pointer to configuration data
 * @return	None
 *
 * Print DM public configuration.
 */
void ia_css_dm_public_cfg_dump(
	const struct ia_css_2500_dm_kernel_config *cfg);

/** @brief Compare two DM public configurations
 *
 * @param	cfg1	The pointer to first configuration data
 * @param	cfg2	The pointer to second configuration data
 * @param	cfg_dump	Configurations are printed in case of
 *   			   mismatch
 * @return	true - match, false - not match
 *
 * Compare two DM public configurations
 */
bool ia_css_dm_public_cfg_compare(
	const struct ia_css_2500_dm_kernel_config *cfg1,
	const struct ia_css_2500_dm_kernel_config *cfg2,
	bool cfg_dump);

#endif // _DM_PUBLIC_H_
