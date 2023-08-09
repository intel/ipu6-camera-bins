/*
 * Copyright 2017-2020 Intel Corporation
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

/*!
 * \file ia_isp_bxt_types.h
*/

#ifndef IA_ISP_BXT_TYPES_H_
#define IA_ISP_BXT_TYPES_H_

#include "ia_types.h"
#include <stdint.h>  /* defines fixed width integers */

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ia_isp_bxt_t ia_isp_bxt;

/*!
 * \brief Input structure for resolution changing ISP block.
 *
 * If ISP block changes resolution as part of its processing, this structure defines
 * resolutions and cropping parameters for one input and output pins. If ISP block has
 * multiple outputs, structure needs to be passed for each output pin. Order of operations:
 *
 * -# Input image is cropped according to input_crop structure parameters. New cropped input resolution is calculated.
 * -# Cropped input image is scaled from cropped input resolution to output resolution (output_width & output_height).
 * -# Output image is cropped according to output_crop structure parameters.
 *
 * If ISP block doesn't change resolution of the image as part of its processing, this structure defines
 * resolution changes done to the image from the beginning of the pipe until now. For example if some scaling or
 * cropping was done before, they are combined.
 *
 * Example:
 *
 * -# Sensor outputs 6528 x 4896. Sensor crops 3264 x 2448 ROI from bottom right corner.
 * -# ISP block downscales the image from 3264 x 2448 to 2176 x 1632 (scale 0.6667) and crops to 1920 x 1080 (RCB):
 *    - resolution_info { 6528, 4896, { 3264, 2448, 0, 0 }, 2176, 1632, { 128, 276, 128, 276 } }
 *
 * -# ISP block needs to know what resolution changes were done with respect to full sensor frame:
 *    - resolution_history { 6528, 4896, { 3264+(128/0.6667), 2448+(276/0.6667), (128/0.6667), (276/0.6667) }, 1920, 1080, { 0, 0, 0, 0 } }
 *
 * -# ISP block forther downscales the image to 1280 x 720 (RCB):
 *    - resolution_info { 1920, 1080, { 0, 0, 0, 0 }, 1280, 720, { 0, 0, 0, 0 } }
 *
 * -# ISP block needs to know what resolution changes were done:
 *    - resolution_history { 6528, 4896, { 3264+(128/0.6667), 2448+(276/0.6667), (128/0.6667), (276/0.6667) }, 1280, 720, { 0, 0, 0, 0 } }
 *
 */

/*!
* \brief Metadata buffer indices for ia_isp_bxt_run_kernels_t structure.
*/
typedef enum
{
    kernel_metadata_paf_frame_width = 0,                   /*!< Widht of PDAF frame buffer (used by DPC and PAF Statistics). */
    kernel_metadata_paf_frame_height                       /*!< Height of PDAF frame buffer (used by DPC and PAF Statistics). */
} run_kernels_metadata_t;

#pragma pack(push, IA_RESOLUTION_STATIC_GRAPH_PACK)
typedef struct ia_isp_bxt_resolution_info
{
    /*
     * IMPORTANT! do not do *ANY* change in this struct without coordinate with SW and Tools teams.
     * This struct is being used by casting data from a binary file and hence cannot be changed.
     */
    int input_width;          /*!< Input image width. */
    int input_height;         /*!< Input image height. */
    ia_rectangle input_crop;  /*!< Crop offsets for input image. Cropping happens before processing the input image. */
    int output_width;         /*!< Output image width. */
    int output_height;        /*!< Output image height. */
    ia_rectangle output_crop; /*!< Crop offsets for output image. Cropping happens after scaling to output resolution. */
} ia_isp_bxt_resolution_info_t;

/*!
* \brief Defines how ISP kernel should modify bit depth of image passing through it.
* Note: Not all ISP kernels are able to change depth of image data which it's processing.
*/
typedef struct ia_isp_bxt_bpp_info
{
    /*
     * IMPORTANT! do not do *ANY* change in this struct without coordinate with SW and Tools teams.
     * This struct is being used by casting data from a binary file and hence cannot be changed.
     */
    int32_t input_bpp;        /*!< Bit depth of image going in to a particular ISP kernel. */
    int32_t output_bpp;       /*!< Bit depth of output going out from a particular ISP kernel. */
} ia_isp_bxt_bpp_info_t;
#pragma pack(pop)

/*!
* \brief Describes options for run-time kernel control.
*/
typedef enum
{
    kernel_passthrough = 0,
    kernel_enable,
    kernel_disable
} ia_isp_bxt_enable_control_t;

typedef struct ia_isp_bxt_run_kernels
{
    uint32_t stream_id;                                     /*!< Used to identify, in which branch of the pipe the kernel is located. */
    uint32_t kernel_uuid;                                   /*!< ia_pal_uuid. ISP API (output) UUID. */
    int32_t enable;                                         /*!< Run-time control to passthrough, enable or disable kernel. */
    ia_isp_bxt_resolution_info_t *resolution_info;          /*!< Resolution change to be done in this kernel. NULL, if kernel doesn't change resolution. */
    ia_isp_bxt_resolution_info_t *resolution_history;       /*!< Resolution changes done before current kernel with respect to sensor output. NULL, if not available*/
    uint32_t metadata[4];                                   /*!< Kernel specific metadata. For example image data format etc. */
    ia_isp_bxt_bpp_info_t bpp_info;                         /*!< Kernel specific input and output bits per pixel values. */
    uint32_t output_count;                                  /*!< Number of outputs this kernel has, this means that in this structure the pointer to resolution_info can
                                                                 be interpreted as an array of this size */
    ia_binary_data system_api;                              /*!< Used by system devices to get system information from graph */
} ia_isp_bxt_run_kernels_t;

typedef struct
{
    uint32_t kernel_uuid;                                   /*!< ia_pal_uuid */
    uint32_t flags;
#define IA_ISP_BXT_PIPE_LAST     (1 << 0)                   /*!< this is the last kernel in the array */
#define IA_ISP_BXT_PIPE_FIRST    (1 << 1)                   /*!< this is the first kernel in a path */
#define IA_ISP_BXT_PIPE_TERMINAL (1 << 2)                   /*!< this is not a kernel but a terminal.
                                                                 In this case, kernel_uuid is the terminal id */
#define IA_ISP_BXT_PIPE_RCB      (1 << 3)                   /*!< this kernel is a resolution changing block */
} ia_isp_bxt_pipe_t;

typedef struct ia_isp_bxt_program_group
{
    unsigned int kernel_count;                    /*!< Number of kernels in the program group .*/
    ia_isp_bxt_run_kernels_t *run_kernels;        /*!< Array of kernels in the program group. */
    unsigned int operation_mode;                  /*!< Operation mode for selecting proper tunings. Is usually associated to different resolutions. */
    ia_isp_bxt_pipe_t *pipe;                      /*!< The graph of kernels in the program group .*/
} ia_isp_bxt_program_group;

/*!
* \brief ia_isp_pal_status_t keeps track of PAL kernel status.
*/
typedef struct ia_isp_pal_status_t
{
    int32_t uuid;
    int32_t status_id;
} ia_isp_pal_status_t;

typedef struct
{
    bool rgbs_grid;          /*!< If true, RGBS grid is available. */
    bool af_grid;            /*!< If true, AF grid is available. */
    bool histograms;         /*!< If true, histograms are available. */
    bool dvs_stats;          /*!< If true, DVS statistics are available. */
    bool rgbs_grids_hdr;     /*!< If true, RGBS HDR grids are available. */
    bool rgby_grids_hdr;     /*!< If true, RGBY stat for high precision histogram is available. */
    bool yv_grids_hdr;       /*!< If true, YV HDR grids are available. */
    bool paf_grid;           /*!< If true, PAF grid is available. */
} ia_isp_bxt_statistics_query_results_t;

/*!
 * \brief Describes options to decompress Y (luma).
 */
typedef enum
{
    ia_isp_bxt_hdr_y_decompression_max_rgb,   /*!< Use RGB max to calculate Y (luma). */
    ia_isp_bxt_hdr_y_decompression_avg_rgb    /*!< Use RGB average to calculate Y (luma). */
} ia_isp_bxt_hdr_y_compression_method_t;

/*!
 * \brief Describes the parameters used in HDR compression algorithm.
 * Sensor/ISP may merge the HDR image and then compress the data to preserve data from different parts of the dynamic range.
 * Compression is most often done to save memory. For example, merged 20 bit (input) image data could be compressed to fit into (output) 15 bits.
 * Parameters in this structure are used to decompress HDR statistics back to linear space.
 */
typedef struct
{
    ia_isp_bxt_hdr_y_compression_method_t y_compression_method; /*!< Used decompression method. */
    ia_isp_bxt_bpp_info_t                 bpp_info;             /*!< Input and output bits per pixel values. */
} ia_isp_bxt_hdr_compression_t;

/*!
 * \brief Structure describes the parameters used in HDR statistics.
 */
typedef struct
{
    unsigned char num_exposures;                               /*!< Mandatory. Number of exposures the sensor supports/outputs. */
    float *hdr_ratios;                                         /*!< Mandatory. HDR ratio of [L/S S/VS etc.] for stitching. The effective length is determined by num_exposures-1. */
    ia_isp_bxt_hdr_compression_t *ia_isp_bxt_hdr_compression;  /*!< Optional. NULL, if HDR statistics are already in linear space (no compression). */
} ia_isp_bxt_hdr_params_t;

#ifdef __cplusplus
}
#endif
#endif /* IA_ISP_BXT_TYPES_H_ */
