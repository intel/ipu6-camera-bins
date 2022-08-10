/*
* INTEL CONFIDENTIAL
*
* Copyright (C) 2017 - 2017 Intel Corporation.
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

#ifndef __IA_CSS_KERNEL_USER_PARAM_H
#define __IA_CSS_KERNEL_USER_PARAM_H

#include "type_support.h"
#include "ia_css_kernel_user_param_types.h"

int get_resolution_from_kup(
	uint16_t *width,
	uint16_t *height,
	const ia_css_kernel_user_param_t *params,
	uint32_t kernel_id,
	uint32_t section_index,
	uint32_t fragment_index);

/*!
 * \brief Sets the payload buffer and size of a kernel user parameter object.
 * @param params[in]     Kernel user parameter object.
 * @param size[in]	 Payload buffer.
 * @return               0 on success.
 */
int
ia_css_kernel_user_param_set_payload_buffer(
	ia_css_kernel_user_param_t *params,
	void *payload_buffer,
	uint32_t payload_size);

/*!
 * \brief Gets the payload buffer of a kernel user parameter object.
 * @param params[in]     Kernel user parameter object.
 * @return               Payload buffer.
 */
void
*ia_css_kernel_user_param_get_payload_buffer(
	const ia_css_kernel_user_param_t *params);

/*!
 * \brief Gets/calculates the payload buffer size for a kernel user parameter object.
 * This function walks over all kernel configs and sums up all the kernel config sizes.
 * @param params[in]    Kernel user parameter object.
 * @return              Size.
 */
int
ia_css_kernel_user_param_get_payload_buffer_size(
	const ia_css_kernel_user_param_t *params);

/*!
 * \brief Gets the kernel user parameter (descriptor) object size.
 * Note that this module assumes that ia_css_kernel_user_param_get_descriptor_size(params)
 * bytes is allocated for pointer params. In addition:
 * ia_css_kernel_user_param_get_descriptor_size(params) > sizeof(ia_css_kernel_user_param_t).
 * @param params[in]     Kernel user parameter object.
 * @return               size, 0 on error.
 */
int
ia_css_kernel_user_param_get_descriptor_size(
	const ia_css_kernel_user_param_t *params);

/*!
 * \brief Gets an ia_css_kernel_user_param_kernel_desc_t (kernel) from an ia_css_kernel_user_param_t.
 * For typical scenario a user might only need to use ia_css_kernel_user_param_find_kernel_cfg_payload_buffer().
 * @param params[in]       Kernel user parameter object.
 * @param kernel_index[in] Kernel index (< params->kernel_count).
 * @return                 ia_css_kernel_user_param_kernel_desc_t object, NULL on error.
 */
ia_css_kernel_user_param_kernel_desc_t *
ia_css_kernel_user_param_get_kernel_desc(
	const ia_css_kernel_user_param_t *params,
	unsigned int kernel_index);

/*!
 * \brief Gets an ia_css_kernel_user_param_cfg_desc_t (kerenl config) from an ia_css_kernel_user_param_kernel_desc_t.
 * For typical scenario a user might only need to use ia_css_kernel_user_param_find_kernel_cfg_payload_buffer().
 * @param kernel[in]        Kernel user parameters descriptor object.
 * @param section_index[in] Kernel index (< kernel->cfg_desc_count).
 * @return                  ia_css_kernel_user_param_cfg_desc_t object, NULL on error.
 */
ia_css_kernel_user_param_cfg_desc_t *
ia_css_kernel_user_param_get_kernel_cfg_desc(
	const ia_css_kernel_user_param_kernel_desc_t *kernel,
	const unsigned int section_index);

/*!
 * \brief Gets the payload buffer for a given kernel index and section index.
 * @param params[in]         Kernel user parameters object.
 * @param kernel_index[in]   Kernel_index < params->kernel_count.
 * @param section_index[in]  Section index.
 * @param fragment_index[in] Fragment index.
 * @return                   Payload buffer, NULL on error.
 */
void *
ia_css_kernel_user_param_get_kernel_cfg_payload_buffer(
	const ia_css_kernel_user_param_t *params,
	uint32_t kernel_index,
	uint32_t section_index,
	uint32_t fragment_index);

/*!
 * \brief Gets the payload buffer for a given kernel ID (!) and section index.
 * @param params[in]         Kernel user parameters object.
 * @param kernel_id[in]      Kernel ID.
 * @param section_index[in]  Section index.
 * @param fragment_index[in] Fragment index.
 * @param size[out]          Size in bytes of payload buffer.
 * @return                   Payload buffer, NULL on error.
 */
void *
ia_css_kernel_user_param_find_kernel_cfg_payload_buffer(
	const ia_css_kernel_user_param_t *params,
	uint32_t kernel_id,
	uint32_t section_index,
	uint32_t fragment_index,
	uint32_t *size);

/*!
 * \brief Pretty prints a kernel user parameters object.
 * @param params         Kernel user parameters object.
 */
void
ia_css_kernel_user_param_print(
	const ia_css_kernel_user_param_t *params);

/*!
 * \brief Calculates the (descriptor) kernel user parameter object size.
 * The difference with ia_css_kernel_user_param_get_size is that
 * ia_css_kernel_user_param_get_descriptor_size_using_kernel_info does not need a valid
 * ia_css_kernel_user_param_t. It uses an array of kernel info's to calculate
 * the size.
 * @param kernels[in]        Array of size kernel_count with kernel information.
 * @param kernel_count[in]   Number of kernels.
 * @return                   size in bytes, 0 on error.
 */
int
ia_css_kernel_user_param_get_descriptor_size_using_kernel_info(
	ia_css_kernel_user_param_kernel_info_t *kernels,
	uint32_t kernel_count);

/*!
 * \brief Initializes a kernel user parameter object (descriptor).
 * Important: the buffer params must be of size as returned by
 * ia_css_kernel_user_param_get_descriptor_size_using_kernel_info.
 * @param params[in]         Kernel user parameters object.
 * @param kernels[in]        Array of size kernel_count with kernel information.
 * @param kernel_count[in]   Number of kernels.
 * @param fragment_count[in] Number of fragments in payload
 * @return                   size in bytes, 0 on error.
 */
int
ia_css_kernel_user_param_init(
	ia_css_kernel_user_param_t *params,
	ia_css_kernel_user_param_kernel_info_t *kernels,
	uint32_t kernel_count,
	uint32_t fragment_count);

#endif /* __IA_CSS_KERNEL_USER_PARAM_H */
