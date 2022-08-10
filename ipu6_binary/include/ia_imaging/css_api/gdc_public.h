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


#ifndef __GDC_PUBLIC_H_INCLUDED__
#define __GDC_PUBLIC_H_INCLUDED__

/*! Write the bicubic interpolation table of GDC[ID]

 \param	ID[in]				GDC identifier
 \param data[in]			The data matrix to be written

 \pre
	- data must point to a matrix[4][HRT_GDC_N]

 \implementation dependent
	- The value of "HRT_GDC_N" is device specific
	- The LUT should not be partially written
	- The LUT format is a quadri-phase interpolation
	  table. The layout is device specific
	- The range of the values data[n][m] is device
	  specific

 \return none, GDC[ID].lut[0...3][0...HRT_GDC_N-1] = data
 */
STORAGE_CLASS_EXTERN void gdc_lut_store(
	const gdc_ID_t		ID,
	const int			data[4][HRT_GDC_N]);

/*! Convert the bicubic interpolation table of GDC[ID] to the ISP-specific format

 \param	ID[in]				GDC identifier
 \param in_lut[in]			The data matrix to be converted
 \param out_lut[out]			The data matrix as the output of conversion
 */
STORAGE_CLASS_EXTERN void gdc_lut_convert_to_isp_format(
	const int in_lut[4][HRT_GDC_N],
	int out_lut[4][HRT_GDC_N]);

/*! Return the integer representation of 1.0 of GDC[ID]
 
 \param	ID[in]				GDC identifier

 \return unity
 */
STORAGE_CLASS_EXTERN int gdc_get_unity(
	const gdc_ID_t		ID);

#endif /* __GDC_PUBLIC_H_INCLUDED__ */
