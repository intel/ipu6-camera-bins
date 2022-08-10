/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2018 - 2018 Intel Corporation.
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

#ifndef __NCI_DEC400_FW_UTILS_H
#define __NCI_DEC400_FW_UTILS_H

#define DEC_TILEY_DMA_CACHE_LINE_IN_BYTES 64
/* Each DMA CL contains 4 rows of pixels */
#define DEC_TILEY_DMA_CACHE_LINE_ROWS 4

#define TILEY_BLOCK_HEIGHT (32)

/** "TRANSFER TILE" here is a sub-tiling that implements
 * the pixel transposition WITHIN tileY tiles.
 */
#define TILEY_TRANSFER_TILE_WIDTH	(DEC_TILEY_DMA_CACHE_LINE_IN_BYTES / DEC_TILEY_DMA_CACHE_LINE_ROWS)
#define TILEY_TRANSFER_TILE_HEIGHT	TILEY_BLOCK_HEIGHT
#define TILEY_TRANSFER_TILE_SIZE  (TILEY_TRANSFER_TILE_WIDTH * TILEY_TRANSFER_TILE_HEIGHT)

/** Convert x,y coordinates to a memory offset from the base of a PLANE in a tileY image */
static inline uint32_t nci_dec400_tiley_coord_to_offset(
	uint32_t x, uint32_t y, uint32_t stride, uint32_t vstride, uint32_t byte_per_pix)
{
	/* Number of horizontal transfer tiles across full buffer stride */
	uint32_t stride_tiles = stride / TILEY_TRANSFER_TILE_WIDTH;

	/* Tile coordinates (in units of tiles) of the transfer tile that contains pixel(x,y) */
	uint32_t tile_coord_x = (x * byte_per_pix) / TILEY_TRANSFER_TILE_WIDTH;
	uint32_t tile_coord_y = y / TILEY_TRANSFER_TILE_HEIGHT;

	/* x,y coordinates RELATIVE to the origin of the transfer tile that contains pixel(x,y) */
	uint32_t intra_tile_x = (x * byte_per_pix) % TILEY_TRANSFER_TILE_WIDTH;
	uint32_t intra_tile_y = y % TILEY_TRANSFER_TILE_HEIGHT;

	/* Here calculate the offset of the containing tile and then add calculate the
	 * internal offset from that tile.  Finally, add them together to get the aggregate
	 * offset.
	 * This works because each whole tile is transferred to linear memory (ignoring
	 * the internal layout of the tile - quantity is what is important here) and
	 * within a single transfer tile, the transfer is similar to a raster image
	 * of tile dimensions.
	 */
	uint32_t num_whole_tiles = (tile_coord_y * stride_tiles + tile_coord_x);
	uint32_t tile_origin_offset = num_whole_tiles * TILEY_TRANSFER_TILE_SIZE;
	uint32_t intra_tile_offset = intra_tile_y * TILEY_TRANSFER_TILE_WIDTH + intra_tile_x;

	uint32_t offset = tile_origin_offset + intra_tile_offset;

	assert((stride % TILEY_TRANSFER_TILE_WIDTH) == 0);
	assert((vstride % TILEY_TRANSFER_TILE_HEIGHT) == 0);

	return offset;
}

static inline uint32_t nci_dec400_calc_last_byte_offset_nontiled(
	uint32_t width,
	uint32_t height,
	uint32_t stride,
	uint32_t bytes_per_element)
{
	uint32_t offset = (stride * (height - 1)) + (width * bytes_per_element) - 1;
	return offset;
}

#endif /* __NCI_DEC400_FW_UTILS_H */
