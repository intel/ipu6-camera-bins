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

#ifndef _DVS_PUBLIC_H_
#define _DVS_PUBLIC_H_

/** @file
* CSS-API header file for 2500/Skycam Digital Video Stabilisation (DVS) kernel/accelerator.
*/

#define DVS_BLOCKDIM_X (64)
#define DVS_BLOCKDIM_Y (32)

/**
 * Max DVS coords table dimension
 * (covers 4224x3136 - max sensor resolution)
 */
/** max DVS coords table width */
#define MAX_DVS_COORDS_TABLE_WIDTH 67
/** max DVS coords table height */
#define MAX_DVS_COORDS_TABLE_HEIGHT 99


struct ia_css_2500_dvs_kernel_config
{
	unsigned int exp_id;
	unsigned int width_y;
	unsigned int height_y;
	unsigned int width_uv;
	unsigned int height_uv;
	unsigned int *xcoords_y;
	unsigned int *ycoords_y;
	unsigned int *xcoords_uv;
	unsigned int *ycoords_uv;
};

/**
 * @brief Dump gdc_v3 state.
 * [Currently support is only for SKC|GDC_V3]
 *
 * @return
 *	- none.
 */
void ia_css_debug_dump_gdc_v3_state(void);

#endif /*  _DVS_PUBLIC_H_ */
