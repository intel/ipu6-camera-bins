/*
 * Copyright 2018 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _IA_PAC_FRAG_TYPES_H_
#define _IA_PAC_FRAG_TYPES_H_

#include <cstdlib>
#include <cstdint>

namespace pal {
typedef struct ia_pac_fragment_desc {
    uint16_t fragment_width;    /*!< The width of the fragment. */
    uint16_t fragment_height;   /*!< The height of the fragment. */
    uint16_t fragment_start_x;  /*!< The x offset from the top-left corner of the full image. */
    uint16_t fragment_start_y;  /*!< The y offset from the top-left corner of the full image. */
} ia_pal_fragment_desc_t;

/*!
*  Grid calculation mode.
*/
typedef enum
{
    fragment_grid_config_extend,        /*!< Extends the grid to fully contain the fragment, making the calculation in grid slots. */
    fragment_grid_config_extend_edges,  /*!< Extends the grid to fully contain the fragment, making the calculation in grid edges. */
    fragment_grid_config_clamp,         /*!< Clamps the grid to be inside the fragment. */
} ia_pac_fragment_grid_config_mode;

/*!
*  A helper grid configuration structure.
*/
typedef struct
{
    uint16_t grid_width;            /*!< The grid width. */
    uint16_t grid_height;           /*!< The grid height. */
    uint16_t block_width;           /*!< The block width. */
    uint16_t block_height;          /*!< The block height. */
    uint16_t grid_height_per_slice; /*!< The grid height per slice. */
    int16_t x_start;                /*!< The x pixel offset of the grid in relation to the fragment top-left corner. */
    int16_t y_start;                /*!< The y pixel offset of the grid in relation to the fragment top-left corner. */
} ia_pac_grid_config_t;

typedef enum {
    frag_calc_ignore = 0,
    frag_calc_output,           /*! Calculate the output fragment descriptors from input */
    frag_calc_input,            /*! Calculate the input fragment descriptors from output */
} ia_pac_fragment_calc_direction;

typedef enum {
    frag_output_ignore = 0,
    frag_output_kernel,               /*! Output of a kernel  fed to another kernel - no need to adjust the overlap cropping */
    frag_output_terminals,            /*! Output of a kernel is the output "put" terminal - need to crop the middle of the overlap */
} ia_pac_fragment_output_type;
}; // namespace pal
#endif /* _IA_PAC_FRAG_TYPES_H_ */
