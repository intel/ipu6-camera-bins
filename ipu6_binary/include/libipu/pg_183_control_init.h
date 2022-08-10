
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

#ifndef __PG_183_CONTROL_INIT_H
#define __PG_183_CONTROL_INIT_H

#include "type_support.h"
#include "ia_css_psys_process_types.h"
#include "ia_css_terminal_types.h"
#include "ia_css_kernel_user_param_types.h"

/*
 * @brief       Fill payload for this PG
 *
 * @param[in]   process_group           Process group
 * @param[out]  payload_address         Address in payload to write
 *
 * @retval 0    Successful.
 * @retval 1    Error.
 */

int _pg_183_control_payload_init(
		const ia_css_process_group_t *process_group,
		const ia_css_kernel_user_param_t *params,
		void *payload_address,
		uint16_t frag_idx);


/*
 * @brief       Get payload size for this PG
 *
 * @param[in]   process_group           Process group
 * @param[out]  payload_size            The payload size to be allocated.
 *
 * @retval 0   Successful.
 * @retval 1   Error.
 */

int _pg_183_get_control_payload_init_buffer_size(
		const ia_css_process_group_t *process_group,
		unsigned int *payload_size);

/*
 * @brief       Fill the control init terminal section descriptor
 *
 *
 * @param[in]   process_group           Process group
 * @param[out]  terminal                terminal descriptor
 * @param[out]  payload_size            The payload size that has been used.
 *
 * @retval 0   Successful.
 * @retval 1   Error.
 */

int _pg_183_control_init_sec_desc_init(
		const ia_css_process_group_t *process_group,
		ia_css_program_control_init_terminal_t *terminal,
		unsigned int *payload_size);

#endif

