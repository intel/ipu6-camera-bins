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

#ifndef _ANR_PUBLIC_H_
#define _ANR_PUBLIC_H_

/** @file
* CSS-API header file for 2500/Skycam Advanced Noice Reduction (ANR) kernel/accelerator.
*/
//#include <type_support.h>

/* All structs in this file will be visible to the CSS API User.
* The User will be able to set each one of the config params separately by
* specifying a different config type (see sh_config_type in sh_css.h).
* If one of those config structs is not set explicitly, a default value will
* be use instead.
*/

//////////////////////////////////////////////////////////////
//				ANR SEARCH                                  //
//////////////////////////////////////////////////////////////

/* NONE TO EXPOSE */


//////////////////////////////////////////////////////////////
//				ANR TRANSFORM                               //
//////////////////////////////////////////////////////////////


typedef struct alpha
{
	short Alpha_Gr;
	short Alpha_R;
	short Alpha_B;
	short Alpha_Gb;
	short Alpha_DC_Gr;
	short Alpha_DC_R;
	short Alpha_DC_B;
	short Alpha_DC_Gb;

}alpha_t;


typedef struct beta
{

	short Beta_Gr;
	short Beta_R;
	short Beta_B;
	short Beta_Gb;

}beta_t;


#define W_MATRIX_SIZE 16
typedef struct plain_color_w_matrix
{
	short Gr[W_MATRIX_SIZE];
	short R[W_MATRIX_SIZE];
	short B[W_MATRIX_SIZE];
	short Gb[W_MATRIX_SIZE];


}plain_color_w_matrix_t;


typedef struct anr_transform_plane
{
	alpha_t alpha;
	beta_t beta;
	plain_color_w_matrix_t color_reg_w;

}anr_transform_plane_t;



#define LUT_ENTRY_NUM 25


typedef struct anr_transform_R_CALC
{
	/** bits 0:12 - Xreset */
	short Xreset;
	/** bits 16:28 - Yreset */
	short Yreset;

	/** BITS 32:39 - A = RADIAL GAIN R^2 norm - shift */
	short R_NormFactor;

	/** bits 40:47 - a = Radial gain scale factor*2^6 */
	short radial_gain_scale_factor;

	/** calculated from Xreset */
	int X_sqr_reset;
	/** calculated from Yreset */
	int Y_sqr_reset;

}anr_transform_R_CALC_t;


typedef struct anr_transform_public
{

	short ADAPTIVE_TRESHHOLD_EN;
	anr_transform_plane_t plane_0;
	anr_transform_plane_t plane_1;
	anr_transform_plane_t plane_2;
	anr_transform_R_CALC_t CALC;

}anr_transform_public_t;




/////////////////////////////////////////////////////////////
//				ANR STITCH                                  //
//////////////////////////////////////////////////////////////


#define PYRAMID_ENTRY_NUM 64
typedef struct anr_stitch_public
{
	short pyramid_reg[PYRAMID_ENTRY_NUM];

}anr_stitch_public_t;



//////////////////////////////////////////////////////////////
//				ANR TILE 2 STRM                             //
//////////////////////////////////////////////////////////////

/* NONE to expose */


struct anr_public_config
{
	anr_transform_public_t transform;
	anr_stitch_public_t stitch;
};

struct ia_css_2500_anr_kernel_config
{
	struct anr_public_config anr;
};

/** @brief Print ANR public configuration
 *
 * @param	cfg	The pointer to configuration data
 * @return	None
 *
 * Print ANR public configuration.
 */
void ia_css_anr_public_cfg_dump(const struct ia_css_2500_anr_kernel_config *cfg);

/** @brief Compare two ANR public configurations
 *
 * @param	cfg1	The pointer to first configuration data
 * @param	cfg2	The pointer to second configuration data
 * @param	cfg_dump	Configurations are printed in case of
 *   			   mismatch
 * @return	true - match, false - not match
 *
 * Compare two ANR public configurations
 */
bool ia_css_anr_public_cfg_compare(
	const struct ia_css_2500_anr_kernel_config *cfg1,
	const struct ia_css_2500_anr_kernel_config *cfg2,
	bool cfg_dump);

#endif
