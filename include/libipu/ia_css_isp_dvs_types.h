/**
* INTEL CONFIDENTIAL
*
* Copyright (C) 2015 - 2016 Intel Corporation.
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

#ifndef __IA_CSS_ISP_DVS_TYPES_H
#define __IA_CSS_ISP_DVS_TYPES_H

#include <type_support.h>

#define IA_CSS_PSYS_PARAMETER_TERMINAL_ISP_DVS_CONFIG_SECTION_COUNT  (1)
#define IA_CSS_PSYS_PARAMETER_TERMINAL_ISP_DVS_CONFIG_SIZE_SECTION_0 (sizeof(struct ia_css_isp_dvs_config))
#define IA_CSS_PSYS_PROGRAM_TERMINAL_ISP_DVS_CONFIG_SECTION_COUNT    (0)

#define IA_CSS_PSYS_SPATIAL_PARAMETER_TERMINAL_ISP_DVS_COORDS_SECTION_COUNT       1 /* only one section/plane is used */
#define IA_CSS_PSYS_SPATIAL_PARAMETER_TERMINAL_ISP_DVS_COORDS_REGION_ID           0 /* only have region 0 */
#define IA_CSS_PSYS_SPATIAL_PARAMETER_TERMINAL_ISP_DVS_COORDS_ELEM_SIZE           0x40 /*(sizeof(gdc_warp_param_mem_t)),  an element is of type gdc_warp_param_mem_t */


/** DVS frame
 *
 *  ISP block: dvs frame
 */

/** dvs params
 * The LUT has 256 entries, containing 6 coefficients each.
 * Each lut entry has to be stored in below format for 6x6 filter
 * LUT Entry	MSB Coeff	LSB Coeff
 * 0		C5		C4
 *			C3		C2
 *			C1		C0
 *			x		x
*/

struct ia_css_isp_dvs_config {
	uint32_t interpolation_type;
	uint32_t filter_size;
	uint32_t lut_sel;
	uint32_t nums_luts;
	uint16_t lut[6][256];
};


#endif /* __IA_CSS_ISP_DVS_TYPES_H */

