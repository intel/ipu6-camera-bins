/**
* INTEL CONFIDENTIAL
*
* Copyright (C) 2015 - 2016 Intel Corporation.
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

#ifndef __IPU_DEVICE_OFS_PROPERTIES_FUNC_H
#define __IPU_DEVICE_OFS_PROPERTIES_FUNC_H

/* Use same implementation of the OFS_OF property functions for all subsystems */
/* Subsystems define property tables */

#include "type_support.h"
#include "ipu_device_ofs_properties_struct.h" /* from interface */
#include "ipu_device_ofs_devices.h" /* from the subsystem */
#include "assert_support.h"
#include "storage_class.h"

#ifdef __EXTERN_DATA_OFS_PROPERTIES__
#include "ipu_device_ofs_properties_decl.h" /* declaration only */
#else
#include "ipu_device_ofs_properties_impl.h" /* definition */
#endif

/***********************************************************
 *               OUTPUT FORMATTER
 ***********************************************************/
STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_of_base_addr(unsigned ofs_id, unsigned of_id)
{
	return ipu_device_ofs_prop[ofs_id].of[of_id].base_address;
}

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_of_chr_upsample_base_addr(unsigned ofs_id, unsigned of_id)
{
	return ipu_device_ofs_prop[ofs_id].of[of_id].base_address +
		(IPU_DEVICE_OFS_OF_CHR_UPSAMPLE_REG_OFFSET *
		 IPU_DEVICE_OFS_OF_REG_ALIGN);
}

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_of_cmd_addr(unsigned ofs_id, unsigned of_id)
{
	return ipu_device_ofs_prop[ofs_id].of[of_id].base_address +
		(IPU_DEVICE_OFS_OF_CMD_REG_OFFSET *
		 IPU_DEVICE_OFS_OF_REG_ALIGN);
}

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_of_sid_reg_addr(unsigned ofs_id, unsigned of_id)
{
	return ipu_device_ofs_prop[ofs_id].of[of_id].base_address +
		(IPU_DEVICE_OFS_OF_SID_REG_OFFSET *
		 IPU_DEVICE_OFS_OF_REG_ALIGN);
}

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_of_out_buf_nr_reg_addr(unsigned ofs_id, unsigned of_id)
{
	return ipu_device_ofs_prop[ofs_id].of[of_id].base_address +
		(IPU_DEVICE_OFS_OF_OUT_NR_BUF_REG_OFFSET *
		 IPU_DEVICE_OFS_OF_REG_ALIGN);
}

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_of_out_buf_start_addr_reg_addr(unsigned ofs_id, unsigned of_id)
{
	return ipu_device_ofs_prop[ofs_id].of[of_id].base_address +
		(IPU_DEVICE_OFS_OF_OUT_BUF_ST_ADDR_REG_OFFSET *
		 IPU_DEVICE_OFS_OF_REG_ALIGN);
}

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_of_out_buf_stride_reg_addr(unsigned ofs_id, unsigned of_id)
{
	return ipu_device_ofs_prop[ofs_id].of[of_id].base_address +
		(IPU_DEVICE_OFS_OF_OUT_BUF_STRIDE_REG_OFFSET *
		 IPU_DEVICE_OFS_OF_REG_ALIGN);
}

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_of_pid_reg_addr(unsigned ofs_id, unsigned of_id, unsigned pin_id)
{
	assert(pin_id < IPU_DEVICE_OFS_NUM_PINS);
	return ipu_device_ofs_prop[ofs_id].of[of_id].base_address +
		((IPU_DEVICE_OFS_OF_PID_REG_OFFSET +
		  ((pin_id + 1) * IPU_DEVICE_OFS_OF_NR_OUTPUT_IDX_REGS)) *
		 IPU_DEVICE_OFS_OF_REG_ALIGN);
}

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_of_rel_inp_addr_reg_addr(unsigned ofs_id, unsigned of_id, unsigned int pin_id)
{
	assert(pin_id < IPU_DEVICE_OFS_NUM_PINS);
	return ipu_device_ofs_prop[ofs_id].of[of_id].base_address +
		((IPU_DEVICE_OFS_OF_REG_REL_INP_ADDR_REG_OFFSET +
		  ((pin_id + 1) * IPU_DEVICE_OFS_OF_NR_OUTPUT_IDX_REGS)) *
		 IPU_DEVICE_OFS_OF_REG_ALIGN);
}

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_of_rel_inp_en_reg_addr(unsigned ofs_id, unsigned of_id, unsigned int pin_id)
{
	assert(pin_id < IPU_DEVICE_OFS_NUM_PINS);
	return ipu_device_ofs_prop[ofs_id].of[of_id].base_address +
		((IPU_DEVICE_OFS_OF_REG_REL_INP_EN_REG_OFFSET +
		  ((pin_id + 1) * IPU_DEVICE_OFS_OF_NR_OUTPUT_IDX_REGS)) *
		 IPU_DEVICE_OFS_OF_REG_ALIGN);
}

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_of_proc_out_addr_reg_addr(unsigned ofs_id, unsigned of_id, unsigned int pin_id)
{
	assert(pin_id < IPU_DEVICE_OFS_NUM_PINS);
	return ipu_device_ofs_prop[ofs_id].of[of_id].base_address +
		((IPU_DEVICE_OFS_OF_REG_PROC_OUT_ADDR_REG_OFFSET +
		  ((pin_id + 1) * IPU_DEVICE_OFS_OF_NR_OUTPUT_IDX_REGS)) *
		 IPU_DEVICE_OFS_OF_REG_ALIGN);
}

/***************************************************/
STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_of_device_base_addr(unsigned ofs_id, unsigned of_id, unsigned int pin_id)
{
	assert(pin_id < IPU_DEVICE_OFS_NUM_PINS);
	return ipu_device_ofs_prop[ofs_id].of[of_id].base_address +
		(((pin_id + 1) * IPU_DEVICE_OFS_OF_NR_OUTPUT_IDX_REGS) *
		 IPU_DEVICE_OFS_OF_REG_ALIGN);
}

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_of_pin_config_base_addr(unsigned ofs_id, unsigned of_id, unsigned int pin_id)
{
	assert(pin_id < IPU_DEVICE_OFS_NUM_PINS);
	return ipu_device_ofs_prop[ofs_id].of[of_id].base_address +
		((IPU_DEVICE_OFS_OF_IMAGE_WIDTH_VECS_REG_OFFSET +
		  ((pin_id + 1) * IPU_DEVICE_OFS_OF_NR_OUTPUT_IDX_REGS)) *
		 IPU_DEVICE_OFS_OF_REG_ALIGN);
}

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_buffer_databus_base_addr(unsigned ofs_id, unsigned buf_id)
{
	return ipu_device_ofs_prop[ofs_id].buffer[buf_id].databus_base_addr;
}

/*****************************************************************
 *               SCALER
 *****************************************************************/
STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_base_addr(unsigned ofs_id, unsigned int sc_device)
{
	assert(sc_device < IPU_DEVICE_OFS_NUM_SC);
	return ipu_device_ofs_prop[ofs_id].sc[sc_device].base_address;
}

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_cmd_addr(unsigned ofs_id, unsigned int sc_device)
{
	assert(sc_device < IPU_DEVICE_OFS_NUM_SC);
	return ipu_device_ofs_prop[ofs_id].sc[sc_device].base_address +
		(IPU_DEVICE_OFS_SC_CMD_REG_OFFSET *
		 IPU_DEVICE_OFS_SC_REG_ALIGN);
}

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_sid_reg_addr(unsigned ofs_id, unsigned int sc_device)
{
	assert(sc_device < IPU_DEVICE_OFS_NUM_SC);
	return ipu_device_ofs_prop[ofs_id].sc[sc_device].base_address +
		((IPU_DEVICE_OFS_SC_NR_GENERAL_REGS +
		  IPU_DEVICE_OFS_SC_SID_REG_OFFSET) *
		 IPU_DEVICE_OFS_SC_REG_ALIGN);
}

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_pid_reg_addr(unsigned ofs_id, unsigned int sc_device)
{
	assert(sc_device < IPU_DEVICE_OFS_NUM_SC);
	return ipu_device_ofs_prop[ofs_id].sc[sc_device].base_address +
		((IPU_DEVICE_OFS_SC_NR_GENERAL_REGS +
		  IPU_DEVICE_OFS_SC_PID_REG_OFFSET) *
		 IPU_DEVICE_OFS_SC_REG_ALIGN);
}

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_buf_config_base_addr(unsigned ofs_id, unsigned int sc_device)
{
	assert(sc_device < IPU_DEVICE_OFS_NUM_SC);
	return ipu_device_ofs_prop[ofs_id].sc[sc_device].base_address +
	        (IPU_DEVICE_OFS_SC_REG_ALIGN *
			(IPU_DEVICE_OFS_SC_NR_GENERAL_REGS +
			 IPU_DEVICE_OFS_SC_INP_BUF_Y_ST_ADDR_REG_OFFSET));
}

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_rel_inp_addr_reg_addr(unsigned ofs_id, unsigned int sc_device)
{
	assert(sc_device < IPU_DEVICE_OFS_NUM_SC);
	return ipu_device_ofs_prop[ofs_id].sc[sc_device].base_address +
		((IPU_DEVICE_OFS_SC_NR_GENERAL_REGS +
		  IPU_DEVICE_OFS_SC_REL_INP_ADDR_REG_OFFSET) *
		 IPU_DEVICE_OFS_SC_REG_ALIGN);
}

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_rel_inp_en_reg_addr(unsigned ofs_id, unsigned int sc_device)
{
	assert(sc_device < IPU_DEVICE_OFS_NUM_SC);
	return ipu_device_ofs_prop[ofs_id].sc[sc_device].base_address +
		((IPU_DEVICE_OFS_SC_NR_GENERAL_REGS +
		  IPU_DEVICE_OFS_SC_REL_INP_EN_REG_OFFSET) *
		 IPU_DEVICE_OFS_SC_REG_ALIGN);
}

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_rel_out_en_reg_addr(unsigned ofs_id, unsigned int sc_device)
{
	assert(sc_device < IPU_DEVICE_OFS_NUM_SC);
	return ipu_device_ofs_prop[ofs_id].sc[sc_device].base_address +
		((IPU_DEVICE_OFS_SC_NR_GENERAL_REGS +
		  IPU_DEVICE_OFS_SC_REL_OUT_EN_REG_OFFSET) *
		 IPU_DEVICE_OFS_SC_REG_ALIGN);
}

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_proc_out_addr_reg_addr(unsigned ofs_id, unsigned int sc_device)
{
	assert(sc_device < IPU_DEVICE_OFS_NUM_SC);
	return ipu_device_ofs_prop[ofs_id].sc[sc_device].base_address +
		((IPU_DEVICE_OFS_SC_NR_GENERAL_REGS +
		  IPU_DEVICE_OFS_SC_PROC_OUT_ADDR_REG_OFFSET) *
		 IPU_DEVICE_OFS_SC_REG_ALIGN);
}

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_mode_config_base_addr(unsigned ofs_id, unsigned int sc_device)
{
	assert(sc_device < IPU_DEVICE_OFS_NUM_SC);
	return ipu_device_ofs_prop[ofs_id].sc[sc_device].base_address +
		(IPU_DEVICE_OFS_SC_REG_ALIGN *
		(IPU_DEVICE_OFS_SC_NR_GENERAL_REGS +
		 IPU_DEVICE_OFS_SC_INPUT_IMAGE_Y_WIDTH_REG_OFFSET));
}

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_coeffs_lut_addr(unsigned ofs_id, unsigned int sc_device)
{
	assert(sc_device < IPU_DEVICE_OFS_NUM_SC);
	return ipu_device_ofs_prop[ofs_id].sc[sc_device].base_address +
		(IPU_DEVICE_OFS_SC_REG_ALIGN * IPU_DEVICE_OFS_SC_COEFFS_LUT_OFFSET);
}

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_elements_per_vector(unsigned ofs_id, unsigned int sc_device)
{
	assert(sc_device < IPU_DEVICE_OFS_NUM_SC);
	return ipu_device_ofs_prop[ofs_id].sc[sc_device].elements_per_vector;
}

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_num_polyphase_taps(unsigned ofs_id, unsigned int sc_device)
{
	assert(sc_device < IPU_DEVICE_OFS_NUM_SC);
	return ipu_device_ofs_prop[ofs_id].sc[sc_device].num_polyphase_taps;
}

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_num_phases(unsigned ofs_id, unsigned int sc_device)
{
	assert(sc_device < IPU_DEVICE_OFS_NUM_SC);
	return ipu_device_ofs_prop[ofs_id].sc[sc_device].num_phases;
}

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_input_data_bpp(unsigned ofs_id, unsigned int sc_device)
{
	assert(sc_device < IPU_DEVICE_OFS_NUM_SC);
	return ipu_device_ofs_prop[ofs_id].sc[sc_device].input_data_bpp;
}

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_output_data_bpp(unsigned ofs_id, unsigned int sc_device)
{
	assert(sc_device < IPU_DEVICE_OFS_NUM_SC);
	return ipu_device_ofs_prop[ofs_id].sc[sc_device].output_data_bpp;
}

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_inter_data_bpp(unsigned ofs_id, unsigned int sc_device)
{
	assert(sc_device < IPU_DEVICE_OFS_NUM_SC);
	return ipu_device_ofs_prop[ofs_id].sc[sc_device].inter_data_bpp;
}

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_max_bits_per_coef(unsigned ofs_id, unsigned int sc_device)
{
	assert(sc_device < IPU_DEVICE_OFS_NUM_SC);
	return ipu_device_ofs_prop[ofs_id].sc[sc_device].max_bits_per_coef;
}

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_of_to_scaler_rel_msg_q_addr(unsigned ofs_id, unsigned int sc_device)
{
	assert(sc_device < IPU_DEVICE_OFS_NUM_SC);
	return ipu_device_ofs_prop[ofs_id].sc[sc_device].of_to_scaler_rel_msg_q_addr;
}

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_scaler_to_of_rdy_msg_q_addr(unsigned ofs_id, unsigned int sc_device)
{
	assert(sc_device < IPU_DEVICE_OFS_NUM_SC);
	return ipu_device_ofs_prop[ofs_id].sc[sc_device].scaler_to_of_rdy_msg_q_addr;
}

#endif /* __IPU_DEVICE_OFS_PROPERTIES_FUNC_H */
