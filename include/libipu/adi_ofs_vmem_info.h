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

#ifndef __ADI_OFS_VMEM_INFO_H
#define __ADI_OFS_VMEM_INFO_H

#include "ipu_device_ofs_devices.h"

/* block dimension processed by OFS */
#define OFS_BLOCK_WIDTH         (128)  /* in pixels */
#define OFS_BLOCK_HEIGHT        (32)

#define OFS_TILE_UNIT_WIDTH   (16) /* bytes */
#define OFS_TILE_BLOCK_WIDTH  (OFS_TILE_UNIT_WIDTH * OFS_BLOCK_HEIGHT) /* bytes */
#define OFS_TILE_BLOCK_HEIGHT (8)

#define OFS_MAX_OUT_BLOCK_WIDTH                  (128) /* In elements */
#define OFS_MAX_OUT_BLOCK_HEIGHT_YUV420          (32)
#define OFS_MAX_OUT_BLOCK_HEIGHT_YUV422          (33)

/* ************ OFS VMEM INFORMATION at input, intermediate and 3 pins output buffers *****************/
#define OFS_INPUT_MEMORY_BPE           (12)
#define OFS_INTER_MEMORY_BPE           (8)
#define TVMEM_MEMORY_BPE               (16)
#define TVMEM_NWAY                     (32)
#define TVMEM_BYTES_PER_ELEM           (CEIL_DIV(TVMEM_MEMORY_BPE,8))
#define OFS_NUM_INPUT_BUFFERS          (3)
#define OFS_NUM_INTERM_BUFFERS         (OFS_NUM_INPUT_BUFFERS) /* Formatter intermediate buffers are input buffers */
#define OFS_PIN_NUM_OUTPUT_BUFFER      (2)

/* Generic formulae for OFS buffer for YUV420 in different bit precision memories */
#define VMEM_OFS_bytes_per_elem(bpe)	(CEIL_DIV((bpe),8))
#define VMEM_OFS_y_line_stride(bpe)	(OFS_BLOCK_WIDTH * VMEM_OFS_bytes_per_elem(bpe)) /* in bytes */
#define VMEM_OFS_y_buf_size(bpe)        (OFS_BLOCK_HEIGHT * VMEM_OFS_y_line_stride(bpe)) /* per buffer */
#define VMEM_OFS_uv_line_stride(bpe)    (VMEM_OFS_y_line_stride(bpe) / 2)
#define VMEM_OFS_uv_buf_size(bpe)       (VMEM_OFS_y_buf_size(bpe) / 4) /* per U or V buffer*/
#define VMEM_OFS_u_offset(bpe, num_buf)	(VMEM_OFS_y_buf_size(bpe) * (num_buf))
#define VMEM_OFS_v_offset(bpe, num_buf)	(VMEM_OFS_u_offset(bpe, num_buf) + (VMEM_OFS_uv_buf_size(bpe) * num_buf))
#define VMEM_OFS_yuv_buf_size(bpe)	(VMEM_OFS_y_buf_size(bpe) \
					 + VMEM_OFS_uv_buf_size(bpe) \
					 + VMEM_OFS_uv_buf_size(bpe))
						/* Y U V one buffer*/

#endif /* __ADI_OFS_VMEM_INFO_H */
