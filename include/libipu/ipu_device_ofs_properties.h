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

#ifndef __IPU_DEVICE_OFS_PROPERTIES_H
#define __IPU_DEVICE_OFS_PROPERTIES_H

#include "storage_class.h"
#include "type_support.h"
#include "ipu_device_ofs_properties_defs.h" /* from the subsystem */
#include "ipu_device_ofs_type_properties.h"

/* Following Defines used for allocatinga array in Skycam Code and
 * hences need to be defined in BXT as we are re-using the code */
#define OFS_PHASES      (IPU_DEVICE_OFS_SC0_NUM_PHASES)
#define OFS_FILTER_TAPS (IPU_DEVICE_OFS_SC0_NUM_POLYPHASE_TAPS)

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_of_base_addr(unsigned ofs_id, unsigned of_device);

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_of_cmd_addr(unsigned ofs_id, unsigned of_device);

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_of_sid_reg_addr(unsigned ofs_id, unsigned of_device);

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_of_out_buf_nr_reg_addr(unsigned ofs_id, unsigned of_device);

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_of_out_buf_start_addr_reg_addr(unsigned ofs_id, unsigned of_device);

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_of_out_buf_stride_reg_addr(unsigned ofs_id, unsigned of_device);

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_of_rel_inp_addr_reg_addr(unsigned ofs_id, unsigned of_device, unsigned int pin_id);

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_of_rel_inp_en_reg_addr(unsigned ofs_id, unsigned of_device, unsigned int pin_id);

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_of_proc_out_addr_reg_addr(unsigned ofs_id, unsigned of_device, unsigned int pin_id);

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_of_pin_config_base_addr(unsigned ofs_id, unsigned of_device, unsigned int pin_id);

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_of_pid_reg_addr(unsigned ofs_id, unsigned of_device, unsigned int pin_id);

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_buffer_databus_base_addr(unsigned ofs_id, unsigned buf_id);

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_base_addr(unsigned ofs_id, unsigned sc_device);

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_cmd_addr(unsigned ofs_id, unsigned sc_device);

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_buf_config_base_addr(unsigned ofs_id, unsigned sc_device);

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_rel_inp_addr_reg_addr(unsigned ofs_id, unsigned sc_device);

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_rel_inp_en_reg_addr(unsigned ofs_id, unsigned sc_device);

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_rel_out_en_reg_addr(unsigned ofs_id, unsigned sc_device);

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_proc_out_addr_reg_addr(unsigned ofs_id, unsigned sc_device);

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_sid_reg_addr(unsigned ofs_id, unsigned sc_device);

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_pid_reg_addr(unsigned ofs_id, unsigned sc_device);

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_mode_config_base_addr(unsigned ofs_id, unsigned sc_device);

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_coeffs_lut_addr(unsigned ofs_id, unsigned sc_device);

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_elements_per_vector(unsigned ofs_id, unsigned sc_device);

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_num_polyphase_taps(unsigned ofs_id, unsigned sc_device);

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_num_phases(unsigned ofs_id, unsigned sc_device);

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_input_data_bpp(unsigned ofs_id, unsigned sc_device);

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_output_data_bpp(unsigned ofs_id, unsigned sc_device);

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_inter_data_bpp(unsigned ofs_id, unsigned sc_device);

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_max_bits_per_coef(unsigned ofs_id, unsigned sc_device);

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_of_to_scaler_rel_msg_q_addr(unsigned ofs_id, unsigned sc_device);

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_sc_scaler_to_of_rdy_msg_q_addr(unsigned ofs_id, unsigned sc_device);

#include "ipu_device_ofs_properties_func.h"

#endif /* __IPU_DEVICE_OFS_PROPERTIES_H */
