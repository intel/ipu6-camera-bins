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

#ifndef _STATS_3A_PUBLIC_H_
#define _STATS_3A_PUBLIC_H_

/** @file
* CSS-API header file for 2500/Skycam 3A statistics datastructures.
*/

#include <awb_public.h>
#include <af_public.h>
#include <ae_public.h>
#include <awb_fr_public.h>
typedef enum{
	MAX_SIZE_OF_SET_AF=32,
	MAX_SIZE_OF_SET_AWB_FR=32,
	MAX_SIZE_OF_SET_AWB=160
}stat_max_size_of_set ;

typedef enum {
  stat_af,
  stat_awb_fr,
  stat_ae,
  stat_awb
} statistic_type_t;

struct ia_css_2500_4a_config {
	struct ae_public_config_grid_config			ae_grd_config;
	struct awb_public_config_grid_config		awb_grd_config;
	struct af_public_grid_config				af_grd_config;
	struct awb_fr_public_grid_config			awb_fr_grd_config;
};

 struct stats_4a_public_raw_buffer {
   awb_public_raw_buffer_t awb_raw_buffer;
   ae_public_raw_buffer_t  ae_raw_buffer;
   awb_fr_public_raw_buffer_t  awb_fr_raw_buffer;
   af_public_raw_buffer_t  af_raw_buffer;

};

 struct ia_css_4a_statistics {
 	struct ia_css_2500_4a_config * stats_4a_config;
 	struct stats_4a_public_raw_buffer *data;
};

/** use ia_css_s3a_roi_offset struct to set 3a ROI coordinates */
struct ia_css_s3a_roi_offset {
	unsigned short x_coord; /**< left coordinate */
	unsigned short y_coord; /**< top coordinate */
};

#endif /* _STATS_3A_PUBLIC_H_ */
