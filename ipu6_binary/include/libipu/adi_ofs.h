/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2017 - 2019 Intel Corporation.
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

#ifndef __ADI_OFS_H
#define __ADI_OFS_H

#include "adi_ofs_types.h"
#include "nci_ofs_types.h"
#include "ipu_device_ofs_devices.h"
#include "ipu_dim_cfg_types.h"
#include "vied_nci_psys_resource_model.h"
#include "ia_css_program_group_data_defs.h"
#include "ia_css_kernel_user_param_instance_types.h"

/**
 * Following format information has been taken from HAS OFS.
 */
enum adi_ofs_of_format {
	ADI_OFS_OF_FORMAT_I420 = 0,
	ADI_OFS_OF_FORMAT_YV12,
	ADI_OFS_OF_FORMAT_NV12,
	ADI_OFS_OF_FORMAT_NV21,
	ADI_OFS_OF_FORMAT_M420,
	ADI_OFS_OF_FORMAT_YUY2,
	ADI_OFS_OF_FORMAT_YUYV = ADI_OFS_OF_FORMAT_YUY2,
	ADI_OFS_OF_FORMAT_NV16,
	ADI_OFS_OF_FORMAT_NV61,
	ADI_OFS_OF_FORMAT_P010_MSB,
	ADI_OFS_OF_FORMAT_P010_LSB,
	ADI_OFS_OF_FORMAT_P016_MSB,
	ADI_OFS_OF_FORMAT_P016_LSB,
};

/**
 * Convert PSYSAPI format into OFS format
 */
void adi_ofs_get_ofs_format(
		ia_css_frame_format_type_t psysapi_format,
		enum adi_ofs_of_format *ofs_format,
		unsigned *tiling);

/**
 * adi_ofs_of_share_config:
 *
 */
void adi_ofs_of_share_config(struct nci_ofs_of_share_cfg *of_share_cfg, struct adi_ofs_config *ofs_param);

/**
 * adi_ofs_of_resolution_config:
 * 	Set resolution config
 *
 */
void adi_ofs_of_resolution_config(
		struct nci_ofs_of_pin_cfg *pin_cfg_payload,
		const struct ia_css_kup_ofs *kup,
		struct ipu_dim_cfg output);

/**
 * adi_ofs_of_ddr_stride_config:
 * 	Set the DDR buffer stride configuration for luma and chroma
 */
void adi_ofs_of_ddr_stride_config(struct nci_ofs_of_pin_cfg *pin_cfg_payload,
				  uint32_t luma_stride,
				  ia_css_frame_format_type_t format);

/**
 * adi_ofs_of_vmem_config:
 * 	Prepare formatter vmem configuration and fill the blob at the payload pointer.
 *
 * Arg1: pin_id            :     Pin id for forrmatter pin configuration.
 * Arg2: pin_cfg_payload   :     Destination address in the DDR.
 * Arg3: pin_config        :     High level pin configuration based on which vmem will
 *                           be configured.
 * Arg4: rel_addr          : Release address where ack will be sent for
 * Arg5: out_bpe           : Bits per element of the output
 * releasing the input
 */
void adi_ofs_of_vmem_config(enum ipu_device_ofs_pin_id pin_id,
			    struct nci_ofs_of_pin_cfg *pin_cfg_payload,
			    struct adi_ofs_of_pin_config *pin_config,
			    uint32_t rel_addr,
			    uint8_t out_bpe);

/**
 * adi_ofs_of_stream2gen_config: Prepare the relevant parameters
 * in the ofs of, related to stream2gen in Ofs HW.
 *
 * Arg1: stream2gen_cfg     :    Pointer to steam2gen_cfg
 * struct.
 * Arg2: stream2gen_buffer_size : Size of the buffer used for
 * doing stream2gen.
 * Arg3: link_id  : stream2gen link_id. Will be used to choose
 * the Buttress resource for stream2gen.
 */
void adi_ofs_of_stream2gen_config(struct nci_ofs_of_stream2gen_cfg * const stream2gen_cfg,
				const uint16_t stream2gen_buffer_size, const uint8_t link_id);

/**
 * adi_ofs_get_sc_id_from_pin_id
 *	To get the scaler id which is mapped to the <pin_id>
 */
enum ipu_device_ofs_sc_id adi_ofs_get_sc_id_from_pin_id(enum ipu_device_ofs_pin_id pin_id);


/**
 * adi_ofs_sc_vmem_config:
 * 	Prepare scaler vmem configuration and fill the blob at the payload pointer.
 *
 * Arg1: sc_id     :     Scaler id.
 * Arg2: sc_vmem   :     payload/destination address in the DDR.
 */
void adi_ofs_sc_vmem_config(enum ipu_device_ofs_sc_id sc_dev_id, struct nci_ofs_sc_cfg *sc_vmem);

/**
 * adi_ofs_of_dma_descr_config
 * 	Prepare formatter dma descriptor registers and fill the blob at the
 * 	payload pointer.
 * Arg1: payload    : Destination address in the DDR.
 * Arg2: dev_chn_id : Dma resource id.
 * Arg3: dma_chan_offset: Starting channel id.
 * Arg4: nof_dma_chan : Number of channels allocated.
 * Arg5: format     : psys api format.
 */
void adi_ofs_of_dma_descr_config(struct ipu_dma_cfg *pin_dma_config_payload,
				 const vied_nci_dev_chn_ID_t dev_chn_id,
				 uint32_t dma_chan_offset,
				 uint32_t nof_dma_chan,
				 ia_css_frame_format_type_t format);

/**
 * adi_ofs_get_dma_descr_info
 * 	Get the dma descriptor information like channel id, span ids, terminal ids,
 * 	and unit ids used by the formatter based on the format.
 * Arg1: dev_chn_id : Dma resource id.
 * Arg2: dma_chan_offset: Starting channel id.
 * Arg3: nof_dma_chan : Number of channels allocated.
 * Arg4: format:     psysapi pixel format.
 * Arg5: ofs_pin_dma_config: pointer to pin dma configuration where this api
 * will set the configuration.
 */
void adi_ofs_get_dma_descr_info(const vied_nci_dev_chn_ID_t dev_chn_id,
				    uint32_t dma_chan_offset,
				    uint32_t nof_dma_chan,
				    ia_css_frame_format_type_t format,
				    struct adi_ofs_pin_dma_resource_id *ofs_pin_dma_config);

/**
 * adi_ofs_get_buf_line_stride
 * 	Get the buffer line stride for the particular format in memory with bpe.
 * Arg1: format    :    Format of the image.
 * Arg2: tiling    :    If the format is tiled.
 * Arg3: bpe       :    Bits per elements of the memory.
 * Arg4: is_chroma :    Is line stride is being asked for chroma? if yes, then 1
 * else 0.
 * Arg5: pin_id    :    Output pin of the OFA.
 *
 * return buffer line stride.
 */
unsigned adi_ofs_get_buf_line_stride(enum adi_ofs_of_format format,
				     unsigned tiling,
				     unsigned bpe,
				     unsigned is_chroma,
				     enum ipu_device_ofs_pin_id pin_id);

/**
 * adi_ofs_get_buf_stride
 * 	Get the buffer size, for the particular buffer width and height with bit precision "bpe".
 * Arg1: buf_width:     buffer width in elements
 * Arg2: buf_height:    buffer height
 * Arg3: bpe:           Bits per elements of the memory
 *
 * return buffer size.
 */
unsigned adi_ofs_get_buf_size(
		unsigned buf_width,
		unsigned buf_height,
		unsigned bpe);
/**
 * adi_ofs_get_out_buf_size
 *
 * 	Get the output buffer size for the particular format with bit precision "bpe".
 * Arg1: format:          Format of the image.
 * Arg2: bpe:             Bits per elements
 * Arg3: is_chroma:       0 for No, 1 for Yes
 *
 * return output buffer size.
 */
unsigned adi_ofs_get_out_buf_size(
		enum adi_ofs_of_format format,
		unsigned bpe,
		unsigned is_chroma);

/**
 * adi_ofs_get_max_out_queue_size
 *
 * 	Get the maximum queue size required for an output pin assuming
 * 	that the worst-case scenario is for YUV420 16-bpe
 * Arg1: void
 *
 * return maximum output queue size.
 */
unsigned adi_ofs_get_max_out_queue_size(void);

/**
 * adi_ofs_get_out_buf_offset
 *
 * 	Get the output buffer offset of a plane for the particular format with bit precision "bpe".
 * Arg1: format:          Format of the image.
 * Arg2: bpe:             Bits per elements
 * Arg3: plane_idx:       Plane index of the buffer within the output queue
 * Arg4: buf_idx:         Buffer index
 *
 * return output buffer offset.
 */
unsigned adi_ofs_get_out_buf_offset(
		enum adi_ofs_of_format ofs_format,
		unsigned bpe,
		unsigned plane_idx,
		unsigned buf_idx);

/**
 * adi_ofs_get_component_width
 *
 * 	Get the component width derived from luma width for the particular format.
 * Arg1: luma_width:          width of the luma line or block
 * Arg2: format:              Format of the image
 * Arg3: is_chroma :          0 for No, 1 for Yes
 *
 * return component width.
 */
unsigned adi_ofs_get_component_width(
		unsigned luma_width,
		enum adi_ofs_of_format format,
		unsigned is_chroma);

/**
 * adi_ofs_get_component_width
 *
 * 	Get the component height derived from luma height for the particular format.
 * Arg1: luma_height:         height of the luma block
 * Arg2: format:              Format of the image
 * Arg3: is_chroma :          0 for No, 1 for Yes
 *
 * return component height.
 */
unsigned adi_ofs_get_component_height(
		unsigned luma_height,
		enum adi_ofs_of_format format,
		unsigned is_chroma);

/**
 * adi_ofs_get_block_width_in_elements
 *
 * 	Get the OFS block width for the particular format.
 * Arg1: format:              Format of the image
 * Arg2: is_chroma :          0 for No, 1 for Yes
 *
 * return OFS block width.
 */
unsigned adi_ofs_get_block_width_in_elements(
		enum adi_ofs_of_format format,
		unsigned is_chroma);

/**
 * adi_ofs_get_block_height
 *
 * 	Get the OFS block height for the particular format.
 * Arg1: format:              Format of the image
 * Arg2: is_chroma :          0 for No, 1 for Yes
 *
 * return OFS block height.
 */
unsigned adi_ofs_get_block_height(
		enum adi_ofs_of_format format,
		unsigned is_chroma);

/**
 * adi_ofs_get_out_block_width_in_elements
 *
 * 	Get the OFS output block width for the particular format.
 * Arg1: format:              Format of the image
 * Arg2: is_chroma :          0 for No, 1 for Yes
 *
 * return output block width.
 */
unsigned adi_ofs_get_out_block_width_in_elements(
		enum adi_ofs_of_format format,
		unsigned is_chroma);

/**
 * adi_ofs_get_out_block_height
 *
 * 	Get the OFS output block height for the particular format.
 * Arg1: format:              Format of the image
 * Arg2: is_chroma :          0 for No, 1 for Yes
 *
 * return output block height.
 */
unsigned adi_ofs_get_out_block_height(
		enum adi_ofs_of_format format,
		unsigned is_chroma);

/**
 * adi_ofs_sc_sid_pid_config:
 * 	Set sid pid for scaler control configuration and fill the blob at the payload pointer.
 *
 * Arg1: pin_id       :     pin id.
 * Arg2: sc_sid_pid   :     payload/destination address in the DDR.
 */
void adi_ofs_sc_sid_pid_config(enum ipu_device_ofs_pin_id pin_id, struct nci_ofs_sc_sid_pid_cfg *sc_sid_pid);

/**
 * adi_ofs_sc_control_config:
 * 	Prepare scaler control configuration and fill the blob at the payload pointer.
 *
 * Arg1: sc_id     :     Scaler id.
 * Arg2: sc_ctrl   :     payload/destination address in the DDR.
 * Arg3: rel_addr  :     the address where release token will be sent.
 */
void adi_ofs_sc_control_config(enum ipu_device_ofs_sc_id sc_id,
			       struct nci_ofs_sc_cfg *sc_ctrl,
			       uint32_t rel_addr);

void
adi_ofs_kup_print(const struct ia_css_kup_ofs *kup);

int adi_ofs_kup_checker(
		const struct ia_css_kup_ofs *kup,
		enum ipu_device_ofs_pin_id pin_id);

/**
 * adi_ofs_output_stride_alignment_checker:
 * 	Checks if the stride of the output frame is properly aligned
 *
 * Arg1: stride:     Output frame stride
 * Arg2: format:     Output frame format
 */
int adi_ofs_output_stride_alignment_checker(
		unsigned stride,
		ia_css_frame_format_type_t format);

#endif /* __ADI_OFS_H */
