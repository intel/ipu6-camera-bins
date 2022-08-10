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

#ifndef __V2S_INIT_SHARED_H
#define __V2S_INIT_SHARED_H

#include "nci_v2s.h"
#include "bufqueue.shared.h"
#include "common_io.shared.h"
#include "storage_class.h"

#define V2S_RGB_OFFSET		ISP_VEC_BYTES /* RGB is a planar format, vectors are consecutive */
#define V2S_BAYER_INT_OFFSET	ISP_VEC_BYTES
#define V2S_BAYER_VEC_OFFSET	(4 * ISP_VEC_BYTES)
/* YYUVYY is a YUV-420 variety that has 1.5 components per pixel */
#define N_YYUVYY_SUBPIXELS(num_pix)	((num_pix) * 3 / 2)
#define N_YUV420_SUBPIXELS(num_pix)	(((num_pix) * 3) / 2)
#define N_BAYER_PLANAR_SUBPIXELS(num_pix)	(num_pix)

STORAGE_CLASS_INLINE void v2s_set_device_cfg(
		struct nci_v2s_dev_cfg *device_config,
		s_resolution_t res)
{
	device_config->frame_dim_height = res.height;
	device_config->frame_dim_width = res.width;
	/* Stop processing command when reaching EOL */
	device_config->cmd_cfg_cmd_eol_end_en = 0;
	/* Enable the "stride_on_eof" mode.
	 * An address stride is applied at completion of a PROC_N_VECS command or at end of line.
	 */
	device_config->stride_cfg_en = 1;
}


STORAGE_CLASS_INLINE void v2s_set_rgb_buffer_cfg(
		struct nci_v2s_buf_cfg *buffer_config,
		bufqueue_t q)
{
	int i;

	unsigned num_blocks = queue_get_numblocks(q);

	unsigned start_address_r = get_start_address_for_v2s(q.buffer.ptr);
	unsigned start_address_g = get_start_address_for_v2s(q.buffer1.ptr);
	unsigned start_address_b = get_start_address_for_v2s(q.buffer2.ptr);

	unsigned block_size_r = q.buffer.block_size;
	unsigned block_size_g = q.buffer1.block_size;
	unsigned block_size_b = q.buffer2.block_size;

	unsigned block_width_r = q.buffer.block_width;
	unsigned block_width_g = q.buffer1.block_width;
	unsigned block_width_b = q.buffer2.block_width;

	unsigned end_address_r = start_address_r + (num_blocks * block_size_r - 1) * ISP_VEC_BYTES;
	unsigned end_address_g = start_address_g + (num_blocks * block_size_g - 1) * ISP_VEC_BYTES;
	unsigned end_address_b = start_address_b + (num_blocks * block_size_b - 1) * ISP_VEC_BYTES;

	/* R0 */
	buffer_config[0].st_addr  = start_address_r;
	buffer_config[0].end_addr = end_address_r;
	buffer_config[0].stride   = block_size_r * ISP_VEC_BYTES;

	/* R1 */
	buffer_config[3].st_addr  = start_address_r + block_width_r * ISP_VEC_BYTES;
	buffer_config[3].end_addr = end_address_r;
	buffer_config[3].stride   = block_size_r * ISP_VEC_BYTES;

	/* G0 */
	buffer_config[1].st_addr  = start_address_g;
	buffer_config[1].end_addr = end_address_g;
	buffer_config[1].stride   = block_size_r * ISP_VEC_BYTES;

	/* G1 */
	buffer_config[4].st_addr  = start_address_g + block_width_g * ISP_VEC_BYTES;
	buffer_config[4].end_addr = end_address_g;
	buffer_config[4].stride   = block_size_r * ISP_VEC_BYTES;

	/* B0 */
	buffer_config[2].st_addr  = start_address_b;
	buffer_config[2].end_addr = end_address_b;
	buffer_config[2].stride   = block_size_r * ISP_VEC_BYTES;

	/* B1 */
	buffer_config[5].st_addr  = start_address_b + block_width_b * ISP_VEC_BYTES;
	buffer_config[5].end_addr = end_address_b;
	buffer_config[5].stride   = block_size_r * ISP_VEC_BYTES;

	for (i = 0; i < 6; i++) {
		buffer_config[i].buffer_en = 1;
		buffer_config[i].offset_0 = V2S_RGB_OFFSET;
		buffer_config[i].offset_1 = V2S_RGB_OFFSET;
	}
}

STORAGE_CLASS_INLINE void v2s_set_yyuvyy_buffer_cfg(
		struct nci_v2s_buf_cfg *buffer_config,
		bufqueue_t q)
{
	unsigned num_blocks = queue_get_numblocks(q);
	int i;

	/* S2V BAYER_YUV of ISL in PS
	Data is stored in Y00 Y10 U00 V00 Y01 Y11 format.

	s: start of the v2s buffer
                        s	s+1	s+2	s+3	s+4	s+5	s+6	s+7	s+8	....
	buffer0        	|Y00	|	|	|	|Y01	|	|Y00	|	|	|   	|Y01	|
	buffer1        	|	|Y10	|	|	|	|Y11	|	|Y10	|	|	|	|Y11
	buffer2        	|	|	|U	|	|	|	|	|	|U	|	|	|
	buffer3        	|	|	|	|V	|	|	|	|	|	|V	|	|

	buffer 0 will have offset 4 (from Y00 to Y01) and offset1 2 (from Y01 to next Y00)
	buffer 1 will have offset 4 (from Y10 to Y11) and offset1 2 (from Y11 to next Y10)
	buffer 2 will have offset= offset1 = 6 (from U to next U)
	buffer 3 will have offset= offset1 = 6 (from V to next V)
	*/

	unsigned block_size = q.buffer.block_size;

	unsigned start_address_y00 = get_start_address_for_v2s(q.buffer.ptr);
	unsigned start_address_y10 = start_address_y00 + 1 * ISP_VEC_BYTES;
	unsigned start_address_u   = start_address_y00 + 2 * ISP_VEC_BYTES;
	unsigned start_address_v   = start_address_y00 + 3 * ISP_VEC_BYTES;

	unsigned end_address_y00 = start_address_y00 + (num_blocks * block_size - 1) * ISP_VEC_BYTES;
	unsigned end_address_y10 = start_address_y10 + (num_blocks * block_size - 1) * ISP_VEC_BYTES;
	unsigned end_address_u   = start_address_u   + (num_blocks * block_size - 1) * ISP_VEC_BYTES;
	unsigned end_address_v   = start_address_v   + (num_blocks * block_size - 1) * ISP_VEC_BYTES;

	/* Y00, Y01 : Even line Y component */
	buffer_config[0].st_addr  = start_address_y00;
	buffer_config[0].end_addr = end_address_y00;
	buffer_config[0].stride   = block_size * ISP_VEC_BYTES;
	buffer_config[0].offset_0 = 4 * ISP_VEC_BYTES;
	buffer_config[0].offset_1 = 2 * ISP_VEC_BYTES;

	/* Y10, Y11 : Odd line Y component */
	buffer_config[1].st_addr  = start_address_y10;
	buffer_config[1].end_addr = end_address_y10;
	buffer_config[1].stride   = block_size * ISP_VEC_BYTES;
	buffer_config[1].offset_0 = 4 * ISP_VEC_BYTES;
	buffer_config[1].offset_1 = 2 * ISP_VEC_BYTES;

	/* U */
	buffer_config[2].st_addr  = start_address_u;
	buffer_config[2].end_addr = end_address_u;
	buffer_config[2].stride   = block_size * ISP_VEC_BYTES;
	buffer_config[2].offset_0 = 6 * ISP_VEC_BYTES;
	buffer_config[2].offset_1 = 6 * ISP_VEC_BYTES;

	/* V */
	buffer_config[3].st_addr  = start_address_v;
	buffer_config[3].end_addr = end_address_v;
	buffer_config[3].stride   = block_size * ISP_VEC_BYTES;
	buffer_config[3].offset_0 = 6 * ISP_VEC_BYTES;
	buffer_config[3].offset_1 = 6 * ISP_VEC_BYTES;

	for (i = 0; i < 4; i++) {
		buffer_config[i].buffer_en = 1;
	}
	for (i = 4; i < 6; i++) {
		buffer_config[i].buffer_en = 0;
	}
}

STORAGE_CLASS_INLINE void v2s_set_yuv_planar_buffer_cfg(
		struct nci_v2s_buf_cfg *buffer_config,
		bufqueue_t q)
{
	unsigned num_blocks = queue_get_numblocks(q);
	int i;

	unsigned block_size_y = q.buffer.block_size;
	unsigned block_size_u = q.buffer1.block_size;
	unsigned block_size_v = q.buffer2.block_size;

	unsigned start_address_y00 = get_start_address_for_v2s(q.buffer.ptr);
	unsigned start_address_y10 = start_address_y00 + (q.buffer.block_width * ISP_VEC_BYTES);
	unsigned start_address_u   = get_start_address_for_v2s(q.buffer1.ptr);
	unsigned start_address_v   = get_start_address_for_v2s(q.buffer2.ptr);

	unsigned end_address_y00 = start_address_y00 + (num_blocks * block_size_y - 1) * ISP_VEC_BYTES;
	unsigned end_address_y10 = start_address_y10 + (num_blocks * block_size_y - 1) * ISP_VEC_BYTES;
	unsigned end_address_u   = start_address_u   + (num_blocks * block_size_u - 1) * ISP_VEC_BYTES;
	unsigned end_address_v   = start_address_v   + (num_blocks * block_size_v - 1) * ISP_VEC_BYTES;

	/* Y00, Y01 : Even line Y component */
	buffer_config[0].st_addr  = start_address_y00;
	buffer_config[0].end_addr = end_address_y00;
	buffer_config[0].stride   = block_size_y * ISP_VEC_BYTES;
	buffer_config[0].offset_0 = ISP_VEC_BYTES;
	buffer_config[0].offset_1 = ISP_VEC_BYTES;

	/* Y10, Y11 : Odd line Y component */
	buffer_config[1].st_addr  = start_address_y10;
	buffer_config[1].end_addr = end_address_y10;
	buffer_config[1].stride   = block_size_y * ISP_VEC_BYTES;
	buffer_config[1].offset_0 = ISP_VEC_BYTES;
	buffer_config[1].offset_1 = ISP_VEC_BYTES;

	/* U */
	buffer_config[2].st_addr  = start_address_u;
	buffer_config[2].end_addr = end_address_u;
	buffer_config[2].stride   = block_size_u * ISP_VEC_BYTES;
	buffer_config[2].offset_0 = ISP_VEC_BYTES;
	buffer_config[2].offset_1 = ISP_VEC_BYTES;

	/* V */
	buffer_config[3].st_addr  = start_address_v;
	buffer_config[3].end_addr = end_address_v;
	buffer_config[3].stride   = block_size_v * ISP_VEC_BYTES;
	buffer_config[3].offset_0 = ISP_VEC_BYTES;
	buffer_config[3].offset_1 = ISP_VEC_BYTES;

	for (i = 0; i < 4; i++) {
		buffer_config[i].buffer_en = 1;
	}
	for (i = 4; i < 6; i++) {
		buffer_config[i].buffer_en = 0;
	}

}
STORAGE_CLASS_INLINE void v2s_set_bayer_int_buffer_cfg(
		struct nci_v2s_buf_cfg *buffer_config,
		bufqueue_t q)
{
	/* TODO: Interleaved bayer to be implemented yet */
	NOT_USED(buffer_config);
	NOT_USED(q);
}

STORAGE_CLASS_INLINE void v2s_set_bayer_vec_buffer_cfg(
		struct nci_v2s_buf_cfg *buffer_config,
		bufqueue_t q)
{
	int i;

	unsigned num_blocks = queue_get_numblocks(q);

	unsigned start_address_gr = get_start_address_for_v2s(q.buffer.ptr);
	unsigned start_address_r  = start_address_gr + 1 * ISP_VEC_BYTES;
	unsigned start_address_b  = start_address_gr + 2 * ISP_VEC_BYTES;
	unsigned start_address_gb = start_address_gr + 3 * ISP_VEC_BYTES;

	unsigned block_size_gr = q.buffer.block_size;
	unsigned block_size_r  = q.buffer.block_size;
	unsigned block_size_b  = q.buffer.block_size;
	unsigned block_size_gb = q.buffer.block_size;

	unsigned end_address_gr = start_address_gr + (num_blocks * block_size_gr - 1) * ISP_VEC_BYTES;
	unsigned end_address_r  = start_address_r  + (num_blocks * block_size_r - 1) * ISP_VEC_BYTES;
	unsigned end_address_b  = start_address_b  + (num_blocks * block_size_b - 1) * ISP_VEC_BYTES;
	unsigned end_address_gb = start_address_gb + (num_blocks * block_size_gb - 1) * ISP_VEC_BYTES;

	/* Gr */
	buffer_config[0].st_addr  = start_address_gr;
	buffer_config[0].end_addr = end_address_gr;
	buffer_config[0].stride   = block_size_gr * ISP_VEC_BYTES;

	/* R */
	buffer_config[1].st_addr  = start_address_r;
	buffer_config[1].end_addr = end_address_r;
	buffer_config[1].stride   = block_size_r * ISP_VEC_BYTES;

	/* B */
	buffer_config[2].st_addr  = start_address_b;
	buffer_config[2].end_addr = end_address_b;
	buffer_config[2].stride   = block_size_b * ISP_VEC_BYTES;

	/* Gb */
	buffer_config[3].st_addr  = start_address_gb;
	buffer_config[3].end_addr = end_address_gb;
	buffer_config[3].stride   = block_size_gb * ISP_VEC_BYTES;

	for (i = 0; i < 4; i++) {
		buffer_config[i].buffer_en = 1;
		buffer_config[i].offset_0 = V2S_BAYER_VEC_OFFSET;
		buffer_config[i].offset_1 = V2S_BAYER_VEC_OFFSET;
	}
	for (i = 4; i < 6; i++) {
		buffer_config[i].buffer_en = 0;
	}
}

STORAGE_CLASS_INLINE void v2s_set_bayer_planar_buffer_cfg(
		struct nci_v2s_buf_cfg *buffer_config,
		bufqueue_t q)
{
	unsigned num_blocks = queue_get_numblocks(q);
	int i;

	unsigned block_size = q.buffer.block_size;
	unsigned stride = (block_size >> 2) * ISP_VEC_BYTES;
	unsigned start_address_gr = get_start_address_for_v2s(q.buffer.ptr);
	unsigned start_address_r = start_address_gr + (num_blocks * stride);
	unsigned start_address_b   = start_address_gr + (2 * num_blocks * stride);
	unsigned start_address_gb   = start_address_gr + (3 * num_blocks * stride);

	unsigned end_address_gr = start_address_gr + num_blocks * stride - ISP_VEC_BYTES;
	unsigned end_address_r = start_address_r + num_blocks * stride - ISP_VEC_BYTES;
	unsigned end_address_b   = start_address_b   + num_blocks * stride - ISP_VEC_BYTES;
	unsigned end_address_gb   = start_address_gb   + num_blocks * stride - ISP_VEC_BYTES;

	/* Gr component */
	buffer_config[0].st_addr  = start_address_gr;
	buffer_config[0].end_addr = end_address_gr;
	buffer_config[0].stride   = stride;
	buffer_config[0].offset_0 = ISP_VEC_BYTES;
	buffer_config[0].offset_1 = ISP_VEC_BYTES;

	/* R component */
	buffer_config[1].st_addr  = start_address_r;
	buffer_config[1].end_addr = end_address_r;
	buffer_config[1].stride   = stride;
	buffer_config[1].offset_0 = ISP_VEC_BYTES;
	buffer_config[1].offset_1 = ISP_VEC_BYTES;

	/* B component */
	buffer_config[2].st_addr  = start_address_b;
	buffer_config[2].end_addr = end_address_b;
	buffer_config[2].stride   = stride;
	buffer_config[2].offset_0 = ISP_VEC_BYTES;
	buffer_config[2].offset_1 = ISP_VEC_BYTES;

	/* Gb component */
	buffer_config[3].st_addr  = start_address_gb;
	buffer_config[3].end_addr = end_address_gb;
	buffer_config[3].stride   = stride;
	buffer_config[3].offset_0 = ISP_VEC_BYTES;
	buffer_config[3].offset_1 = ISP_VEC_BYTES;

	for (i = 0; i < 4; i++) {
		buffer_config[i].buffer_en = 1;
	}
	for (i = 4; i < 6; i++) {
		buffer_config[i].buffer_en = 0;
	}

}


#endif /* __V2S_INIT_SHARED_H */
