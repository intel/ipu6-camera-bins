/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2019 - 2019 Intel Corporation.
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

#ifndef __PROGRAM_ISL_OUT_SCALED_A_DIRECT_TO_PSA_CONTROL_INIT_H
#define __PROGRAM_ISL_OUT_SCALED_A_DIRECT_TO_PSA_CONTROL_INIT_H

#include "type_support.h"
#include "pg_control_init_support.h"
#include "ipu_device_strm_pack_devices.h"


/*
 * @brief       Fill ctrlinit payload of the program
 *
 * @param[in]   process_group           Process group
 * @param[in]   load_sec_desc           Progctrlinit terminal section descriptor
 * @param[in]   payload_base_address    Program's ctrlinit terminal payload start address
 * @retval 0    Successful.
 * @retval 1    Error.
 */
int
program_isl_out_scaled_a_direct_to_psa_payload_fill(
	const ia_css_process_group_t *process_group,
	load_section_desc_list_t load_sec_desc_list,
	void *payload_base_address);

/*
 * @brief       Get ctrlinit payload size of the program
 *
 *
 * @retval	Size of the program payload
 */
int
program_isl_out_scaled_a_direct_to_psa_get_payload_size(void);

/*
 * @brief       Fill load section descriptor of the program
 *
 * @param[in]   prog_ctrl_init_prog_desc Pointer to the program descriptor in
 *                                       which the section descriptor has to be filled
 *
 * @retval 0    Successful.
 * @retval 1    Error.
 */
int
program_isl_out_scaled_a_direct_to_psa_fill_load_section_descriptor(
	ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc,
	enum ipu_device_strm_pack_dev_id strm_pack_id);

/*
 * @brief       number of load section descriptor of the program
 *
 * @retval     return number of load sections.
 */
unsigned int
program_isl_out_scaled_a_direct_to_psa_get_numberof_load_sections(void);

#endif /* __PROGRAM_ISL_OUT_SCALED_A_DIRECT_TO_PSA_CONTROL_INIT_H */
