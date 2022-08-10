/*
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

#ifndef __IA_CSS_TERMINAL_PRINT_H
#define __IA_CSS_TERMINAL_PRINT_H

#include "type_support.h"
#include "ia_css_terminal.h"
#include "ia_css_terminal_manifest.h"

/** Pretty prints the descriptor of a parameter cached out terminal */
void ia_css_param_out_terminal_print(ia_css_param_terminal_t *terminal, unsigned int nof_fragments, unsigned int nof_sections);

/** Pretty prints the descriptor of a parameter cached in terminal */
void ia_css_param_in_terminal_print(ia_css_param_terminal_t *terminal, unsigned int nof_sections);
/** Pretty prints the descriptor of a parameter cached in terminal using terminal manifest */
void ia_css_param_in_terminal_print_with_manifest(ia_css_param_terminal_t *terminal, ia_css_param_terminal_manifest_t *manifest);

/** Pretty prints the descriptor of a program terminal */
void ia_css_program_terminal_print(ia_css_program_terminal_t *terminal, unsigned int nof_fragments, unsigned int nof_infos, unsigned int nof_fragment_param_sections);
/** Pretty prints the descriptor of a program terminal using terminal manifest */
void ia_css_program_terminal_print_with_manifest(ia_css_program_terminal_t *terminal, unsigned int nof_fragments, ia_css_program_terminal_manifest_t *manifest);

/** Pretty prints the descriptor of a spatial terminal */
void ia_css_spatial_terminal_print(ia_css_spatial_param_terminal_t *terminal, unsigned int nof_fragments, unsigned int nof_sections);

/** Pretty prints the descriptor of a sliced terminal */
void ia_css_sliced_terminal_print(ia_css_sliced_param_terminal_t *terminal, unsigned int nof_fragments, unsigned int nof_sections);

#endif /* __IA_CSS_TERMINAL_PRINT_H */
