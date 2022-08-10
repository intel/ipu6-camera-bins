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

#ifndef _LACE_STAT_PUBLIC_H_
#define _LACE_STAT_PUBLIC_H_

/** @file
* CSS-API header file for 2500/Skycam Local Auto Contrast Enhancement (LACE) kernel/accelerator.
*/

#include "ia_css_types.h"

/** Total number of registers in set in the Y histogram */
#define ACC_LACE_STAT_NUM_OF_REGS_PER_SET 320
/** Total number of bins per block */
#define ACC_LACE_STAT_NUM_OF_BINS_PER_BLOCK 32
/** Total number of bins per register */
#define ACC_LACE_STAT_NUM_OF_BINS_PER_REG 4
/** Total number of registers per block */
#define ACC_LACE_STAT_NUM_OF_REGS_PER_BLOCK \
	(ACC_LACE_STAT_NUM_OF_BINS_PER_BLOCK / \
	ACC_LACE_STAT_NUM_OF_BINS_PER_REG)

/* All structs in this file will be visible to the CSS APU User.
   The User will be able to set each one of the config params separately by
   specifying a different config type (see sh_config_type in sh_css.h).
   If one of those config structs is not set explicitly, a default value will
   be use instead. */

struct lace_stat_public_lace_gbl_cfg {
	unsigned char lh_mode;
	unsigned char y_ds_mode;
	unsigned char uv_ds_mode_unsupported;
	unsigned char uv_input_unsupported;
};

struct lace_stat_public_y_grd_hor_cfg {
	unsigned char grid_width;
	unsigned char block_width;
};

struct lace_stat_public_y_grd_hor_roi {
	unsigned short x_start;
	unsigned short x_end;
};

struct lace_stat_public_uv_grd_hor_cfg {
	unsigned int not_supported;
};

struct lace_stat_public_uv_grd_hor_roi {
	unsigned int not_supported;
};

struct lace_stat_public_grd_vrt_cfg {
	unsigned char grid_h;
	unsigned char block_h;
	unsigned char grid_h_per_slice;
};

struct lace_stat_public_grd_vrt_roi {
	unsigned short y_start;
	unsigned short y_end;
};

struct lace_stat_hist_entry_public {
	unsigned char bin[4];
};

struct lace_stat_public_config {
	struct lace_stat_public_lace_gbl_cfg    lace_gbl_cfg;
	struct lace_stat_public_y_grd_hor_cfg   y_grd_hor_cfg;
	struct lace_stat_public_y_grd_hor_roi   y_grd_hor_roi;
	struct lace_stat_public_uv_grd_hor_cfg  uv_grd_hor_cfg;
	struct lace_stat_public_uv_grd_hor_roi  uv_grd_hor_roi;
	struct lace_stat_public_grd_vrt_cfg     grd_vrt_cfg;
	struct lace_stat_public_grd_vrt_roi     grd_vrt_roi;
};

/*//////////////////////////
// LACE_STAT Public Config //
//////////////////////////*/

struct ia_css_2500_lace_stat_kernel_config {
	struct lace_stat_public_config lace_stat;
};

struct ia_css_lace_statistics {
	unsigned char *lace_stat_hist_p;
	struct ia_css_2500_lace_stat_kernel_config lace_stat_cfg;
};

/** @brief Print LACE STAT public configuration
 *
 * @param	cfg	The pointer to configuration data
 * @return	None
 *
 * Print LACE STAT public configuration.
 */
void ia_css_lace_stat_public_cfg_dump(const struct ia_css_2500_lace_stat_kernel_config *cfg);

/** @brief Compare two LACE STAT public configurations
 *
 * @param	cfg1	The pointer to first configuration data
 * @param	cfg2	The pointer to second configuration data
 * @param	cfg_dump	Configurations are printed in case of
 *   			   mismatch
 * @return	true - match, false - not match
 *
 * Compare two LACE STAT public configurations
 */
bool ia_css_lace_stat_public_cfg_compare(
	const struct ia_css_2500_lace_stat_kernel_config *cfg1,
	const struct ia_css_2500_lace_stat_kernel_config *cfg2,
	bool cfg_dump);

#endif /* _LACE_STAT_PUBLIC_H_ */
