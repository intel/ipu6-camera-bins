/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2017 - 2018 Intel Corporation.
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
#ifndef __DEC400_COMMON_CONFIG_H
#define __DEC400_COMMON_CONFIG_H

#include "nci_dec400.h"
#include "ia_css_common_io_types.h"
#include "storage_class.h"

/* The maximal address value is illegal for using as buffer end address, due to a HW bug (HSD #1305553012) */
#define DEC400_INVALID_END_ADDRESS 0xFFFFFFFF

/* This function initializes the common fields in the stream config structure of the DEC400.
*  It assumes that the stream_cfg structure is initialized to 0.
*/
STORAGE_CLASS_INLINE void dec400_config_common_part(struct nci_dec400_stream_cfg_t *stream_cfg,
	enum nci_dec400_config_bit_depth bit_depth, bool tile_y, bool p010, bool ts_cache_mode,
	uint32_t buffer_base_addr);

/* This function creates the DEC400 configuration of buffer boudaries.
*  it assumes that the buffer_base field of stream_cfg structure is initialized to the base address
*  of the previous plane. For the first plane, the assumption is that it is initialized to the image base address.
*/
STORAGE_CLASS_INLINE void configure_plane_buffer(struct nci_dec400_stream_cfg_t *stream_cfg,
	p_terminal_config terminal_ptr, uint32_t buffer_index, uint32_t image_buffer_base_addr,
	uint32_t previous_buffer_size, uint32_t buffer_end_offset, uint32_t stride);

/* This function checks that the terminal configuration meets the DEC400 constraints for compression.
*  Returned value is true, if the constraints are met and false, with assertions (if enabled), if not.
*/
STORAGE_CLASS_INLINE bool dec400_verify_compresseion_constraints(p_terminal_config terminal_ptr, bool is_tnr);

/* This function configures the buffer limits for NV12-linear format */
STORAGE_CLASS_INLINE
void dec400_config_semi_planar_linear_buffer(p_terminal_config terminal_ptr, uint32_t *y_buffer_size,
	uint32_t *y_buffer_end_offset, uint32_t *uv_buffer_end_offset);

#ifndef PIPE_GENERATION
#include "dec400_common_config.c"
#endif

#endif /* __DEC400_COMMON_CONFIG_H */

