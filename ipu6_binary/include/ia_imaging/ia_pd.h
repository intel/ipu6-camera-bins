/*
* INTEL CONFIDENTIAL
* Copyright (c) 2017 Intel Corporation
* All Rights Reserved.
*
* The source code contained or described herein and all documents related to
* the source code ("Material") are owned by Intel Corporation or its
* suppliers or licensors. Title to the Material remains with Intel
* Corporation or its suppliers and licensors. The Material may contain trade
* secrets and proprietary and confidential information of Intel Corporation
* and its suppliers and licensors, and is protected by worldwide copyright
* and trade secret laws and treaty provisions. No part of the Material may be
* used, copied, reproduced, modified, published, uploaded, posted,
* transmitted, distributed, or disclosed in any way without Intel's prior
* express written permission.
*
* No license under any patent, copyright, trade secret or other intellectual
* property right is granted to or conferred upon you by disclosure or
* delivery of the Materials, either expressly, by implication, inducement,
* estoppel or otherwise. Any license under such intellectual property rights
* must be express and approved by Intel in writing.
*
* Unless otherwise agreed by Intel in writing, you may not remove or alter
* this notice or any other notice embedded in Materials by Intel or Intels
* suppliers or licensors in any way.
*/

/*!
 * \file ia_pd.h
 * \brief Definitions for phase difference statistics converter.
*/

#ifndef _IA_PD_H_
#define _IA_PD_H_

#include "ia_aiq_types.h"
#include "ia_types.h"
#include "ia_log.h"

#ifdef __cplusplus
extern "C" {
#endif
#define LOG_PD
#ifdef LOG_PD
#define IA_PD_LOG(fmt, ...) IA_LOG(ia_log_debug, "IAPD: " fmt, ## __VA_ARGS__)
#define IA_PD_ERROR(fmt, ...) IA_LOG(ia_log_error, "IAPD: " fmt, ## __VA_ARGS__)
#define IA_PD_INFO(fmt, ...) IA_LOG(ia_log_info, "IAPD: " fmt, ## __VA_ARGS__)
#else
#define IA_PD_LOG(...) ((void)0)
#define IA_PD_ERROR(...) ((void)0)
#define IA_PD_INFO(...) ((void)0)
#endif

typedef struct ia_pd_t ia_pd;

typedef struct
{
    unsigned long       points_num;                    /* Number of points on the threshold line. */
    unsigned long      *analog_gain;                   /* Array of x address of points on the threshold line. */
    unsigned long      *confidence;                    /* Array of y address of points on the threshold line. */
} ia_defocus_thr_t;

typedef struct
{
    unsigned short      image_width;                    /* X size of image in all-pixel mode */
    unsigned short      image_height;                   /* Y size of image in all-pixel mode. */
    unsigned short      grid_width;                     /* Number of windows horizontally */
    unsigned short      grid_height;                    /* Number of windows vertically */
    unsigned short      max_grid_width;                 /* Max supported number of windows horizontally */
    unsigned short      max_grid_height;                /* Max supported number of windows vertically */
    unsigned short      *window_start_horz;             /* Array of x address of PDAF window start position in all-pixel mode. */
    unsigned short      *window_start_vert;             /* Array of y address of PDAF window start position in all-pixel mode. */
    unsigned short      *window_end_horz;               /* Array of x address of PDAF window end position in all-pixel mode. */
    unsigned short      *window_end_vert;               /* Array of y address of PDAF window end position in all-pixel mode. */
    unsigned short      knots_slope_offset_num_horz;    /* Number of knots in x-direction. */
    unsigned short      knots_slope_offset_num_vert;    /* Number of knots in y-direction. */
    unsigned short     *knot_slope_offset_horz;         /* Array of x address of knots. */
    unsigned short     *knot_slope_offset_vert;         /* Array of y address of knots. */
    signed long         slope_adjustment_coeff;         /* Adjustment coefficient of slope. */
    unsigned long       analog_gain;                    /* Image sensor analog gain. */
    unsigned short      knots_defocus_num_horz;         /* Number of knots in x-direction. */
    unsigned short      knots_defocus_num_vert;         /* Number of knots in y-direction. */
    ia_defocus_thr_t   *defocus_thr;                    /* Array of threshold line data which determines Defocus OK/NG. */
    unsigned short     *knot_defocus_horz;              /* Array of x address of knots. */
    unsigned short     *knot_defocus_vert;              /* Array of y address of knots. */
    unsigned long       phase_pixel_density;            /* Density of phase detection pixel. */
} ia_pd_input_parameters_t;

/*!
 * \brief Phase difference converter initialization.
 *
 * \param[in] a_ia_cmc_ptr                    Mandatory.\n
 *                                            Pointer to parsed camera module characterization structure. Internal copy of the structure will be taken.
 * \param[in] a_ia_cmc_ptr                    Mandatory.\n
 *                                            Pointer to dynamic camera configuration file
 * \param[in] a_pd_input_parameters_ptr       Mandatory. \n
 *                                            Phase detection input parameters structure
 * \return                                    Pointer to phase difference converter handle.
 */
LIBEXPORT ia_pd *ia_pd_init(
    const ia_cmc_t *a_ia_cmc_ptr,
    const void *a_dcc_ptr,
    ia_pd_input_parameters_t *a_pd_input_parameters_ptr);

/*!
* \brief Phase difference convertion function.
*
* \param[in] a_statistics_ptr                Mandatory.\n
*                                            Input phase difference statistics.
* \param[in] a_pd_input_parameters_ptr       Mandatory. \n
*                                            Phase detection input parameters structure
* \param[out] a_out_depth_grid_ptr           Mandatory.\n
*                                            Pointer to output depth statistics.
*/
LIBEXPORT ia_err ia_pd_convert(
    void *a_statistics_ptr,
    ia_pd *a_pd_ptr,
    ia_aiq_depth_grid **a_out_depth_grid_ptr);

/*!
* \brief Phase difference deinitialization.
*
* \param[in] a_pd_ptr                        Mandatory.\n
*                                            Pointer to phase difference converter handle.
*/
LIBEXPORT void ia_pd_deinit(
    ia_pd *a_pd_ptr);

#ifdef __cplusplus
}
#endif

#endif /* _IA_PD_H_ */
