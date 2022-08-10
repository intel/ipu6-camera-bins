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
* CSS-API header file for 2500/Skycam Defect Pixel Correction (DPC) kernel/accelerator.
*/
//#include <type_support.h>

#ifndef DPC_PUBLIC_H_
#define DPC_PUBLIC_H_

/** DPC can correct due to hardware limitations up to 192 pixels per 50 lines.
  *  So for an input height of 3840 lines this results into 77 sets of 50 lines.
  *  As a result the maximum number of dead pixels is 192*77.
  */
#define DPC_MAX_NUMBER_OF_DP 14784

// lut entry
typedef struct dpc_public_lut_elem {

	unsigned int nghbr_sts:5;
	unsigned int skip:1;
	unsigned int nghbr_order:1;
	unsigned int column:13;
	unsigned int row_pair_delta:4;
	unsigned int spare0:8;

} dpc_public_lut_elem_t;


typedef struct dpc_public_lut {

	dpc_public_lut_elem_t elems[DPC_MAX_NUMBER_OF_DP];

} dpc_public_lut_t;

struct dpc_public_config {

	unsigned int grad_threshold;
	unsigned int num_of_dp_gr;
	unsigned int num_of_dp_bg;
	dpc_public_lut_t lut_gr;
	dpc_public_lut_t lut_bg;

};

struct ia_css_2500_dpc_kernel_config {

	struct dpc_public_config dpc;

};

/** @brief Print DPC public configuration
 *
 * @param	cfg	The pointer to configuration data
 * @return	None
 *
 * Print DPC public configuration.
 */
void ia_css_dpc_public_cfg_dump(
	const struct ia_css_2500_dpc_kernel_config *cfg);

/** @brief Compare two DPC public configurations
 *
 * @param	cfg1	The pointer to first configuration data
 * @param	cfg2	The pointer to second configuration data
 * @param	cfg_dump	Configurations are printed in case of
 *   			   mismatch
 * @return	true - match, false - not match
 *
 * Compare two DPC public configurations
 */
bool ia_css_dpc_public_cfg_compare(
	const struct ia_css_2500_dpc_kernel_config *cfg1,
	const struct ia_css_2500_dpc_kernel_config *cfg2,
	bool cfg_dump);

#endif /* DPC_PUBLIC_H_ */
