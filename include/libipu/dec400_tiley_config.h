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

#ifndef __DEC400_TILEY_CONFIG_H
#define __DEC400_TILEY_CONFIG_H

#include "nci_dec400_fw_utils.h"

static inline void
dec400_calculate_tiley_config(p_terminal_config terminal, uint32_t *y_buffer_size, uint32_t *uv_buffer_size,
				uint32_t *y_buffer_end, uint32_t *uv_buffer_end)
{
	uint32_t height_y = terminal->height;
	uint32_t height_uv = height_y / 2;
	uint32_t vstride_y = CEIL_MUL(height_y, TILEY_TRANSFER_TILE_HEIGHT);
	uint32_t vstride_uv = CEIL_MUL(height_uv, TILEY_TRANSFER_TILE_HEIGHT);
	uint32_t byte_per_pix = CEIL_DIV(terminal->bpe, 8);

	/***********************************************************************/
	/*  |<--------------------stride--------------------------->|          */
	/*  |<------------------width--------------->|                         */
	/*  +-------------------------------------------------------+          */
	/*  |                                        :              | line #1  */
	/*  |                                        :              | line #2  */
	/*  .                                        .              .          */
	/*  .                                        .              .          */
	/*  .                                        .              .          */
	/*  |                                        :              | line #N  */
	/*  +-------------------------------------------------------+          */
	/* The end of the buffer is stride*(height-1)+width-1                  */
	/*                                                                     */
	/* P010-TileY format                                                   */
	/*   ____________w___________ ____                                     */
	/*  |Y0|Y1                   |    |                                    */
	/*  |                        |    |                                    */
	/*  h                        h    h'= align(h,32)                      */
	/*  |                        |    |                                    */
	/*  |                        |    |                                    */
	/*  |____________w___________|    |                                    */
	/*  :                             |                                    */
	/*  :________________________ ____|                                    */
	/*  |U|V|U|V                 |    :                                    */
	/* h/2                      h/2   :                                    */
	/*  |____________w___________|    h" = align(h/2,32)                   */
	/*  :.............................:                                    */
	/***********************************************************************/

	*y_buffer_size = vstride_y * terminal->stride;
	*uv_buffer_size = vstride_uv * terminal->stride;

	/* Note: DMA may transfer a bit more than the buffer_end's here if it transfers only
	 * full cache lines AND the width (in units of bytes) does not
	 * aligned to TRANSFER_TILE_WIDTH.  (This means some bytes beyond the end of image into
	 * the padding are transferred.)
	 */
	*y_buffer_end = nci_dec400_tiley_coord_to_offset(terminal->width - 1, height_y - 1,
						terminal->stride, vstride_y, byte_per_pix);
	*uv_buffer_end = nci_dec400_tiley_coord_to_offset(terminal->width - 1, height_uv - 1,
						terminal->stride, vstride_uv, byte_per_pix);
}

#endif /* __DEC400_TILEY_CONFIG_H */
