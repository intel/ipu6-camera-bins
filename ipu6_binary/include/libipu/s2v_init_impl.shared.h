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
#ifndef __S2V_INIT_SHARED_H
#define __S2V_INIT_SHARED_H

#include "bufqueue.shared.h"
#include "common_yuv_io.isp.h"
#include "vied_nci_s2v_types.h"
#include "storage_class.h"

#define BAYER_TO_YUV_CONVERSION_FACTOR (6/4)
#define BAYER_TO_RGB_CONVERSION_FACTOR (3)

#define NOF_VECTORS_IN_BAYER_QUAD 4
#define NOF_VECTORS_IN_YUV_420 6
#define S2V_420_PLANAR_FORMAT_OFFSET  1
#define S2V_BAYER_FORMAT_OFFSET       4
#define S2V_BAYER_PLANAR_FORMAT_OFFSET       1
#define CHROMA_SUBSAMPLE_YUV420_SHIFT 1
#define GET_YUV_420_WIDTH(width) ((width * NOF_VECTORS_IN_YUV_420)/NOF_VECTORS_IN_BAYER_QUAD)
#define GET_YUV_420_Y_SIZE(width, height) ((width * height) / 2)
#define GET_YUV_420_UV_SIZE(width, height) (GET_YUV_420_Y_SIZE(width, height) >> CHROMA_SUBSAMPLE_YUV420_SHIFT)
#define GET_YUV_420_NOF_VEC(width, height) (CEIL_MUL(width, 2) * height * NOF_VECTORS_IN_YUV_420 / NOF_VECTORS_IN_BAYER_QUAD)
#define GET_BAYER_PLANAR_WIDTH(width) ((width * NOF_VECTORS_IN_BAYER_QUAD)/NOF_VECTORS_IN_BAYER_QUAD)

#define NOF_VECTORS_IN_YUV_440 8
#define NOF_VECTORS_IN_YUV_444 12
#define S2V_444_PLANAR_FORMAT_OFFSET 1
#define GET_YUV_440_WIDTH(width) ((width * NOF_VECTORS_IN_YUV_440) / NOF_VECTORS_IN_BAYER_QUAD)
#define GET_YUV_444_WIDTH(width) ((width * NOF_VECTORS_IN_YUV_444) / NOF_VECTORS_IN_BAYER_QUAD)
#define GET_YUV_440_Y_SIZE(width, height) ((width * height) / 2)
#define GET_YUV_440_UV_SIZE(width, height) GET_YUV_440_Y_SIZE(width, height)

/* In YUV440 and YUV444 format, Y00 is in first line in VMEM, Y10 in second line */
#define YUV_Y0_LINE_OFFSET 0
#define YUV_Y1_LINE_OFFSET 1
/* In YUV440 format, U is in third line, V in fourth line */
#define YUV440_U_LINE_OFFSET 2
#define YUV440_V_LINE_OFFSET 3
/* In YUV444 format, U00 in third line, U10 in fourth line, V00 in fifth line and V10 in sixth line */
#define YUV444_U0_LINE_OFFSET 2
#define YUV444_U1_LINE_OFFSET 3
#define YUV444_V0_LINE_OFFSET 4
#define YUV444_V1_LINE_OFFSET 5

STORAGE_CLASS_INLINE unsigned s2v_bayer_set_params(
		struct nci_s2v_cfg *s2v_params,
		unsigned int width,
		unsigned int height,
		unsigned int start_address,
		unsigned int buf_size,
		unsigned int buf_width,
		unsigned int buf_height,
		unsigned int num_blocks)
{
	unsigned int pxls_per_line;
	unsigned int pxlcmp_per_pxl;
	block_dimensions_t s2v_data;
	unsigned end_address;

	/*
	 * Data is stored in GRBG vector interleaved format.
	 */
	assert(buf_height == 2);

	end_address = start_address + num_blocks * buf_size;

	s2v_data = calc_block_dimensions(buf_width,
					 buf_height,
					 width / ISP_NWAY,
					 height);

	/* streamToVec Bayer1 parameters */
	s2v_params->ack_vec_nr = s2v_data.block_width * s2v_data.block_height;
	s2v_params->lines_per_frame = height;
	s2v_params->frame_width_en = 0;
	s2v_params->frame_width = 0; /* feature not enabled */

	pxlcmp_per_pxl = 1; /* one pixel component per pixel in bayer */
	/* According to str2vec MAS the number of pixel components for Bayer 4ppc is 2 */
	pxls_per_line = width;
	s2v_params->pxlcmp_per_line = (pxls_per_line * pxlcmp_per_pxl);
	s2v_params->yuv420_enable  = 0;
	s2v_params->bayer_mode_enable = 1;
  	s2v_params->interleave_enable = 0;
	s2v_params->rpwc_enable = 1; /*Set it to its default value*/
	s2v_params->dev_null_enable = 0;	/* Incoming stream is stalled when s2v is not busy (no command in queue) */
	s2v_params->buf_addr_byte_aligned = 0;
	s2v_params->stride_on_eof_cmd_enable = 1;
	s2v_params->uv_interleaved_en = 0;

	/* streamToVec buffer administration */
	s2v_params->number_of_buffers = 4;
	s2v_params->buffers[0].offset  = S2V_BAYER_FORMAT_OFFSET;	/* Gr component */
	s2v_params->buffers[0].offset1 = S2V_BAYER_FORMAT_OFFSET;
	s2v_params->buffers[0].stride  = buf_size;
	s2v_params->buffers[0].start_address = start_address;
	s2v_params->buffers[0].end_address   = end_address;

	s2v_params->buffers[1].offset  = S2V_BAYER_FORMAT_OFFSET;	/* R component */
	s2v_params->buffers[1].offset1 = S2V_BAYER_FORMAT_OFFSET;
	s2v_params->buffers[1].stride  = buf_size;
	s2v_params->buffers[1].start_address = s2v_params->buffers[0].start_address + 1;
	s2v_params->buffers[1].end_address   = end_address;

	s2v_params->buffers[2].offset  = S2V_BAYER_FORMAT_OFFSET;	/* B component */
	s2v_params->buffers[2].offset1 = S2V_BAYER_FORMAT_OFFSET;
	s2v_params->buffers[2].stride  = buf_size;
	s2v_params->buffers[2].start_address = s2v_params->buffers[1].start_address + 1;
	s2v_params->buffers[2].end_address   = end_address;

	s2v_params->buffers[3].offset  = S2V_BAYER_FORMAT_OFFSET;	/* Gb component */
	s2v_params->buffers[3].offset1 = S2V_BAYER_FORMAT_OFFSET;
	s2v_params->buffers[3].stride  = buf_size;
	s2v_params->buffers[3].start_address = s2v_params->buffers[2].start_address + 1;
	s2v_params->buffers[3].end_address   = end_address;

	return s2v_params->ack_vec_nr;
}

STORAGE_CLASS_INLINE unsigned s2v_bayer_planar_set_params(
		struct nci_s2v_cfg *s2v_params,
		unsigned int width,
		unsigned int height,
		bufqueue_t q,
		unsigned int buf_size,
		unsigned int buf_width,
		unsigned int buf_height,
		unsigned int num_blocks)
{
	unsigned int pxls_per_line;
	unsigned int pxlcmp_per_pxl;
	block_dimensions_t s2v_data;
	uint32_t start_address;
	buf_blk_t buf_q;

	buf_size /= 4; /* 1 queue allocated for 4 planes */
	buf_q = queue_get_buf0(q);
	start_address = get_start_address_for_s2v(buf_q.ptr);

	s2v_data = calc_block_dimensions(buf_width,
					 buf_height,
					 width / ISP_NWAY,
					 height);

	assert(buf_height == 2);

	/* streamToVec Bayer1 parameters */
	s2v_params->ack_vec_nr = s2v_data.block_width * s2v_data.block_height;
	s2v_params->lines_per_frame = height;

	pxlcmp_per_pxl = 1; /* one pixel component per pixel in bayer */
	/* According to str2vec MAS the number of pixel components for Bayer 4ppc is 2 */
	pxls_per_line = width;

	s2v_params->pxlcmp_per_line = (pxls_per_line * pxlcmp_per_pxl);
	s2v_params->yuv420_enable  = 0;
	s2v_params->interleave_enable = 0;
	s2v_params->rpwc_enable = 1; /*Set it to its default value*/
	s2v_params->dev_null_enable = 0;	/* Incoming stream is stalled when s2v is not busy (no command in queue) */
	s2v_params->buf_addr_byte_aligned = 0;
	s2v_params->stride_on_eof_cmd_enable = 1;
	s2v_params->frame_width_en = 1;
	s2v_params->frame_width = width;

	/* streamToVec buffer administration */
	s2v_params->number_of_buffers = 4;
	s2v_params->buffers[0].offset  = S2V_BAYER_PLANAR_FORMAT_OFFSET;	/* Gr component */
	s2v_params->buffers[0].offset1 = S2V_BAYER_PLANAR_FORMAT_OFFSET;
	s2v_params->buffers[0].stride  = buf_size;
	s2v_params->buffers[0].start_address = start_address;
	s2v_params->buffers[0].end_address   = s2v_params->buffers[0].start_address + num_blocks * buf_size;

	s2v_params->buffers[1].offset  = S2V_BAYER_PLANAR_FORMAT_OFFSET;	/* R component */
	s2v_params->buffers[1].offset1 = S2V_BAYER_PLANAR_FORMAT_OFFSET;
	s2v_params->buffers[1].stride  = buf_size;
	s2v_params->buffers[1].start_address = s2v_params->buffers[0].end_address;
	s2v_params->buffers[1].end_address   = s2v_params->buffers[1].start_address + num_blocks * buf_size;

	s2v_params->buffers[2].offset  = S2V_BAYER_PLANAR_FORMAT_OFFSET;	/* B component */
	s2v_params->buffers[2].offset1 = S2V_BAYER_PLANAR_FORMAT_OFFSET;
	s2v_params->buffers[2].stride  = buf_size;
	s2v_params->buffers[2].start_address = s2v_params->buffers[1].end_address;
	s2v_params->buffers[2].end_address   = s2v_params->buffers[2].start_address + num_blocks * buf_size;

	s2v_params->buffers[3].offset  = S2V_BAYER_PLANAR_FORMAT_OFFSET;	/* Gb component */
	s2v_params->buffers[3].offset1 = S2V_BAYER_PLANAR_FORMAT_OFFSET;
	s2v_params->buffers[3].stride  = buf_size;
	s2v_params->buffers[3].start_address = s2v_params->buffers[2].end_address;
	s2v_params->buffers[3].end_address   = s2v_params->buffers[3].start_address + num_blocks * buf_size;

	return s2v_params->ack_vec_nr;
}

STORAGE_CLASS_INLINE unsigned s2v_yuv_planar_set_params(
		struct nci_s2v_cfg *s2v_params,
		unsigned int width,
		unsigned int height,
		bufqueue_t q_out,
		unsigned chroma_subsample_shift_x,
		unsigned chroma_subsample_shift_y)
{

	unsigned int pxls_per_line;
	unsigned int pxlcmp_per_pxl;
	block_dimensions_t s2v_data;
	unsigned end_address, buff_width_chroma;
	unsigned int buf_size;
	unsigned int buf_width;
	unsigned int buf_height;
	unsigned int num_blocks;
	uint32_t start_address_y;
	uint32_t start_address_u;
	uint32_t start_address_v;

	buf_size = queue_get_block_size(q_out),
	buf_width = queue_get_blockwidth(q_out),
	buf_height = queue_get_blockheight(q_out),
	num_blocks = queue_get_numblocks(q_out);

	start_address_y = get_start_address_for_s2v(yuv_io_get_luma_ptr(q_out, 0));
	start_address_u = get_start_address_for_s2v(
		yuv_io_get_chroma_u_ptr(q_out, chroma_subsample_shift_x, chroma_subsample_shift_y, 0)
		);
	start_address_v = get_start_address_for_s2v(
		yuv_io_get_chroma_v_ptr(q_out, chroma_subsample_shift_x, chroma_subsample_shift_y, 0)
		);
	/*
	 * current configuration assumes queue buffer width is greater than fragment width
	 * and queue buffer stores only one line pair per block.
	 */
	assert(buf_height == 2);

	/* calculate the dimensions for s2v_data, which */
	/* shows how much of the queue buffer is used */
	s2v_data = calc_block_dimensions(buf_width,
					 buf_height,
					 width / ISP_NWAY,
					 height);

	/* vectors per ack is determined by the s2v_data block dimension */
	s2v_params->ack_vec_nr = GET_YUV_420_NOF_VEC(s2v_data.block_width, s2v_data.block_height);
	pxlcmp_per_pxl = 1;
	s2v_params->lines_per_frame = height;
	s2v_params->frame_width_en = 0;
	s2v_params->frame_width = 0; /* feature not enabled */

	/* pixels per line is determined by the image fragment width */
	pxls_per_line   = GET_YUV_420_WIDTH(width);
	s2v_params->pxlcmp_per_line = (pxls_per_line * pxlcmp_per_pxl);
	s2v_params->yuv420_enable  = 0;
	s2v_params->interleave_enable = 0;
	s2v_params->rpwc_enable = 1; /*Set it to its default value*/
	s2v_params->dev_null_enable = 0;
	s2v_params->buf_addr_byte_aligned = 0;
	s2v_params->stride_on_eof_cmd_enable = 1;
	s2v_params->uv_interleaved_en = 0;
	s2v_params->number_of_buffers = 4;

	end_address =  start_address_y + num_blocks * buf_size;
	buff_width_chroma = buf_width >> chroma_subsample_shift_x;

	/*
	 * Data is stored in YUV planar format.
	 */
	s2v_params->buffers[0].offset = S2V_420_PLANAR_FORMAT_OFFSET;
	s2v_params->buffers[0].offset1 = S2V_420_PLANAR_FORMAT_OFFSET;
	s2v_params->buffers[0].stride = buf_size;
	s2v_params->buffers[0].start_address = start_address_y;
	s2v_params->buffers[0].end_address   = end_address;

	s2v_params->buffers[1].offset = S2V_420_PLANAR_FORMAT_OFFSET;
	s2v_params->buffers[1].offset1 = S2V_420_PLANAR_FORMAT_OFFSET;
	s2v_params->buffers[1].stride = buf_size;
	s2v_params->buffers[1].start_address  = start_address_y + buf_width;
	s2v_params->buffers[1].end_address    = end_address;

	s2v_params->buffers[2].offset = S2V_420_PLANAR_FORMAT_OFFSET;
	s2v_params->buffers[2].offset1 = S2V_420_PLANAR_FORMAT_OFFSET;
	s2v_params->buffers[2].stride = buff_width_chroma;
	s2v_params->buffers[2].start_address = start_address_u;
	s2v_params->buffers[2].end_address   = start_address_u + num_blocks * buff_width_chroma;

	s2v_params->buffers[3].offset = S2V_420_PLANAR_FORMAT_OFFSET;
	s2v_params->buffers[3].offset1 = S2V_420_PLANAR_FORMAT_OFFSET;
	s2v_params->buffers[3].stride = buff_width_chroma;
	s2v_params->buffers[3].start_address = start_address_v;
	s2v_params->buffers[3].end_address   = start_address_v + num_blocks * buff_width_chroma;

	return s2v_params->ack_vec_nr;
}

STORAGE_CLASS_INLINE unsigned s2v_yyuvyy_set_params(
		struct nci_s2v_cfg *s2v_params,
		unsigned int width,
		unsigned int height,
		unsigned int start_address,
		unsigned int buf_size,
		unsigned int buf_width,
		unsigned int buf_height,
		unsigned int num_blocks)
{

	unsigned int pxls_per_line;
	unsigned int pxlcmp_per_pxl;
	block_dimensions_t s2v_data;
	unsigned end_address;

	end_address = start_address + num_blocks * buf_size;

#ifdef DEBUG
	IA_CSS_TRACE_0(FFKER_ISP, INFO, "Setting parameters for stream2vec\n");
#endif
	/* current configuration assumes queue buffer stores only one line pair per block */
	assert(buf_height == 2);

	/* calculate the dimensions for s2v_data, which */
	/* shows how much of the queue buffer is used */
	s2v_data = calc_block_dimensions(buf_width,
					 buf_height,
					 width / ISP_NWAY,
					 height);

	/* vectors per ack is determined by the s2v_data block dimension */
	s2v_params->ack_vec_nr = GET_YUV_420_WIDTH(s2v_data.block_width) * s2v_data.block_height;
	pxlcmp_per_pxl = 1;
	s2v_params->lines_per_frame = height;
	s2v_params->frame_width_en = 0;
	s2v_params->frame_width = 0; /* feature not enabled */

	/* pixels per line is determined by the image fragment width */
	pxls_per_line   = GET_YUV_420_WIDTH(width);
	s2v_params->pxlcmp_per_line = (pxls_per_line * pxlcmp_per_pxl);
	s2v_params->yuv420_enable  = 0;
	s2v_params->bayer_mode_enable = 0;
	s2v_params->interleave_enable = 0;
	s2v_params->rpwc_enable = 1; /*Set it to its default value*/
	s2v_params->dev_null_enable = 0;
	s2v_params->buf_addr_byte_aligned = 0;
	s2v_params->stride_on_eof_cmd_enable = 1;
	s2v_params->uv_interleaved_en = 0;
	s2v_params->number_of_buffers = 4;

	/* S2V BAYER_YUV of ISL in PS
	Data is stored in Y00 Y10 U00 V00 Y01 Y11 format.

	start = start_address in vector memory where s2v writes to.

		start	start+1	start+2	start+3
	buffer0 |Y00	|	|	|	|Y01	|	|Y00	|	|	|   	|Y01	|
	buffer1 |	|Y10	|	|	|	|Y11	|	|Y10	|	|	|	|Y11
	buffer2 |	|	|U	|	|	|	|	|	|U	|	|	|
	buffer3 |	|	|	|V	|	|	|	|	|	|V	|	|

	buffer 0 will have offset 4 (from Y00 to Y01) and offset1 2 (from Y01 to next Y00)
	buffer 1 will have offset 4 (from Y10 to Y11) and offset1 2 (from Y11 to next Y10)
	buffer 2 will have offset= offset1 = 6 (from U to next U)
	buffer 3 will have offset= offset1 = 6 (from V to next V)
	*/

	/* buffer 0 -> Y00 and Y01 */
	s2v_params->buffers[0].offset = 4;
	s2v_params->buffers[0].offset1 = 2;
	s2v_params->buffers[0].stride = buf_size;
	s2v_params->buffers[0].start_address = start_address;
	s2v_params->buffers[0].end_address   = end_address;

	/* buffer 1 -> Y10 and Y11 */
	s2v_params->buffers[1].offset = 4;
	s2v_params->buffers[1].offset1 = 2;
	s2v_params->buffers[1].stride = buf_size;
	s2v_params->buffers[1].start_address  = start_address + 1;
	s2v_params->buffers[1].end_address    = end_address;

	/* buffer 2 -> U */
	s2v_params->buffers[2].offset = 6;
	s2v_params->buffers[2].offset1 = 6;
	s2v_params->buffers[2].stride = buf_size;
	s2v_params->buffers[2].start_address = start_address + 2;
	s2v_params->buffers[2].end_address   = end_address;

	/* buffer 3 -> V */
	s2v_params->buffers[3].offset = 6;
	s2v_params->buffers[3].offset1 = 6;
	s2v_params->buffers[3].stride = buf_size;
	s2v_params->buffers[3].start_address = start_address + 3;
	s2v_params->buffers[3].end_address   = end_address;

	return s2v_params->ack_vec_nr;
}

STORAGE_CLASS_INLINE unsigned s2v_nv12_set_params(
		struct nci_s2v_cfg *s2v_params,
		unsigned int width,
		unsigned int height,
		bufqueue_t q_out,
		unsigned chroma_subsample_shift_x,
		unsigned chroma_subsample_shift_y,
		unsigned bpe_size_shift)
{

	unsigned int pxls_per_line;
	unsigned int pxlcmp_per_pxl;
	block_dimensions_t s2v_data;
	unsigned end_address;
	unsigned int buf_size;
	unsigned int buf_width;
	unsigned int buf_height;
	unsigned int num_blocks;
	uint32_t start_address_y;
	uint32_t start_address_u;

	buf_size = queue_get_block_size(q_out),
	buf_width = queue_get_blockwidth(q_out),
	buf_height = queue_get_blockheight(q_out),
	num_blocks = queue_get_numblocks(q_out);

	start_address_y = get_start_address_for_s2v(yuv_io_get_luma_ptr(q_out, 0));
	start_address_u = get_start_address_for_s2v(
		yuv_io_get_chroma_u_ptr(q_out, chroma_subsample_shift_x,
			chroma_subsample_shift_y, 0)
		);
	/*
	 * current configuration assumes queue buffer width is greater than fragment width
	 * and queue buffer stores only one line pair per block.
	 */
	assert(buf_height == 2);

	/* calculate the dimensions for s2v_data, which */
	/* shows how much of the queue buffer is used */
	s2v_data = calc_block_dimensions(buf_width,
					 buf_height,
					 width / ISP_NWAY,
					 height);

	/* vectors per ack is determined by the s2v_data block dimension */
	s2v_params->ack_vec_nr = (GET_YUV_420_NOF_VEC(s2v_data.block_width, s2v_data.block_height)) >> bpe_size_shift;
	pxlcmp_per_pxl = 1;
	s2v_params->lines_per_frame = height;
	/* pixels per line is determined by the image fragment width */
	pxls_per_line   = (GET_YUV_420_WIDTH(width) >> bpe_size_shift);

	s2v_params->pxlcmp_per_line = (pxls_per_line * pxlcmp_per_pxl);
	s2v_params->yuv420_enable  = 0;
  	s2v_params->bayer_mode_enable = 0;
	s2v_params->interleave_enable = 0;
	s2v_params->rpwc_enable = 1; /*Set it to its default value*/
	s2v_params->dev_null_enable = 0;
	s2v_params->buf_addr_byte_aligned = 0;
	s2v_params->stride_on_eof_cmd_enable = 1;
	s2v_params->uv_interleaved_en = 1;
	s2v_params->number_of_buffers = 3;
	s2v_params->frame_width_en = 0;
	s2v_params->frame_width = 0;

	end_address =  start_address_y + num_blocks * (buf_size >> bpe_size_shift);

	/*
	 * Data is stored in YUV planar format.
	 */
	s2v_params->buffers[0].offset = S2V_420_PLANAR_FORMAT_OFFSET;
	s2v_params->buffers[0].offset1 = S2V_420_PLANAR_FORMAT_OFFSET;
	s2v_params->buffers[0].stride = (buf_size >> bpe_size_shift);
	s2v_params->buffers[0].start_address = start_address_y;
	s2v_params->buffers[0].end_address   = end_address;

	s2v_params->buffers[1].offset = S2V_420_PLANAR_FORMAT_OFFSET;
	s2v_params->buffers[1].offset1 = S2V_420_PLANAR_FORMAT_OFFSET;
	s2v_params->buffers[1].stride = (buf_size >> bpe_size_shift);
	s2v_params->buffers[1].start_address  = start_address_y + (buf_width >> bpe_size_shift);
	s2v_params->buffers[1].end_address    = end_address;

	s2v_params->buffers[2].offset = S2V_420_PLANAR_FORMAT_OFFSET;
	s2v_params->buffers[2].offset1 = S2V_420_PLANAR_FORMAT_OFFSET;
	s2v_params->buffers[2].stride = buf_size >> (chroma_subsample_shift_y + bpe_size_shift);
	s2v_params->buffers[2].start_address = start_address_u;
	s2v_params->buffers[2].end_address   = start_address_u +
	    (num_blocks * (buf_size >> (chroma_subsample_shift_y + bpe_size_shift)));

	return s2v_params->ack_vec_nr;
}


#endif /* __S2V_INIT_SHARED_H */

