/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2012-2021 Intel Corporation
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
 * \file ia_nvm.h
 * \brief Definitions of NVM (Non-Volatile Memory) data parser.
*/

#ifndef _IA_NVM_H_
#define _IA_NVM_H_

#include <stdint.h>
#include "ia_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define IA_NVM_NUM_CHANNELS 4
#define IA_NVM_LSC_BIT_DEPTH_THRESHOLD 8U
#define IA_NVM_MIN_LSC_WIDTH 7
#define IA_NVM_MIN_LSC_HEIGHT 5
#define IA_NVM_SENSITIVITY_BIT_DEPTH 10U
#define IA_NVM_CIE_RANGE_MIN 0.270
#define IA_NVM_CIE_RANGE_MAX 0.490

#define IA_NVM_INTERFACE_PDAF_MAJOR_VERSION   2

#define IA_NVM_STATIC_BUFFER_SIZE_V1 10
#define IA_NVM_STATIC_BUFFER_SIZE_V2 12 /*new nvm format with PDAF fields added*/

/*!
 * \brief NVM parsing status codes.
 */
typedef enum
{
    ia_nvm_error_none,            /*!< No error. */
    ia_nvm_error_internal,        /*!< Parser internal failure (not enough memory). */
    ia_nvm_error_no_data,         /*!< NULL pointer as input or not enough input data. */
    ia_nvm_error_af,              /*!< Error parsing AF parameters. */
    ia_nvm_error_lsc,             /*!< Error parsing AF parameters. (lsc dimensions, lsc data) */
    ia_nvm_error_awb,             /*!< Error parsing AWB parameters (sensitivities, n_lights). */
    ia_nvm_error_crc,             /*!< CRC check error. */
    ia_nvm_error_not_used,        /*!< No error in NVM data but NVM data is not used. */
    ia_nvm_error_not_implemented, /*!< Parser for given data type has not been implemented. */
    ia_nvm_error_version,         /*!< invalid version. */
    ia_nvm_error_pdaf,            /*!< Error parsing PDAF parameters */
    ia_nvm_error_vcm,             /*!< Error parsing Closed loop vcm parameters*/
} ia_nvm_error;

/*!
 * \brief PDAF PS Table data layout in NVM (Non-Volatile Memory) data.
 */
typedef struct
{
    uint16_t* pdaf_ps_left;          /*!< PS Gain tables for Left Pixels */
    uint16_t* pdaf_ps_right;         /*!< PS Gain tables for Right Pixels */
} ia_nvm_pdaf_ps;

/*!
 * \brief PDAF data layout in NVM (Non-Volatile Memory) data.
 */
typedef struct
{
    uint8_t pdaf_ps_sensor_modes;                     /*!< number of sensor modes calibrated for PS */
    uint8_t pdaf_ps_knots_width;                      /*!< number of PS knots across width */
    uint8_t pdaf_ps_knots_height;                     /*!< number of PS knots across height */
    uint8_t pdaf_ps_frac_bits;                        /*!< PS Fractional Bit depth */
    ia_nvm_pdaf_ps *pdaf_ps_tables;                  /*!< PS tables for all the sensor modes */
    uint8_t pdaf_dlom_knots_width;                   /*!< number of DLOM knots across width */
    uint8_t pdaf_dlom_knots_height;                  /*!< number of DLOM knots across height */
    uint8_t pdaf_dlom_frac_bits;                     /*!< DLOM Fractional Bit Depth */
    int32_t* pdaf_dlom_tables;                      /*!< DLOM tables */
} ia_nvm_pdaf_data;

/*!
 * \brief Closed loop vcm calibration data layout in NVM (Non-Volatile Memory) data.
 */
typedef struct
{
    uint8_t  closed_loop_hall_offset_vert;  /*!< vertical distance b/w Hall sensor and Magnet */
    uint8_t  closed_loop_hall_bias_horz;    /*!< horizontal distance b/w Hall sensor and Magnet */
    uint16_t closed_loop_hall_min;          /*!< Hall sensor movement minimum limit */
    uint16_t closed_loop_hall_max;          /*!< Hall sensor movement maximum limit */
} ia_nvm_closed_loop_vcm;

/*!
 * \brief LSC table layout in NVM (Non-Volatile Memory) data.
 * LSC tables are one after another for N amount of lights. One LSC table consists of tables for 4 channels in order: Ch1, Ch2, Ch3 and Ch4.
 */
typedef struct
{
    uint8_t lsc_frac_bits;                    /*!< LSC fractional bit depth range 4-8. */
    void *lsc_tables[IA_NVM_NUM_CHANNELS];    /*!< LSC table for Ch1, Ch2, Ch3 and Ch4. Type depends on lsc_fraq_bits. If <= IA_NVM_LSC_BIT_DEPTH_THRESHOLD, then uint8_t, else uint16_t. */
} ia_nvm_lsc;


typedef struct
{
    uint8_t major_version;                            /*!< Calibration data major version. */
    uint8_t minor_version;                            /*!< Calibration data minor version. */
    uint8_t n_pos;                                    /*!< Number of AF measurement orientations. */
    uint8_t vcm_lps_bits;                             /*!< VCM lens position sensor bit depth (0 if N/A). */
    uint8_t vcm_bits;                                 /*!< VCM register bit depth (8 or 16). */
    int16_t *vcm_af_near;                             /*!< VCM register values for n_pos for AF at near calibration distance (supplier specific). */
    int16_t *vcm_af_far;                              /*!< VCM register values for n_pos for AF at far calibration distance (supplier specific). */
    int16_t *vcm_af_start;                            /*!< VCM register values for n_pos for AF at lens start.DEPRICATED.the parameter must not be used */
    int16_t *vcm_af_end;                              /*!< VCM register values for n_pos for AF at lens end.DEPRICATED the parameter must not be used */
    uint8_t n_lights;                                 /*!< Number of light sources used for LSC and AWB. */
    uint8_t *cie_coords_x;                            /*!< CIE x coordinates for n_lights light sources. */
    uint8_t *cie_coords_y;                            /*!< CIE y coordinates for n_lights light sources. */
    uint8_t lsc_width;                                /*!< Width of all LSC tables. */
    uint8_t lsc_height;                               /*!< Height of all LSC tables. */
    ia_nvm_lsc *lsc;                                  /*!< LSC tables for n_lights. */
    uint16_t *awb_sensitivities[IA_NVM_NUM_CHANNELS]; /*!< AWB sensitivities for n_lights in order: Ch1, Ch2, Ch3 and Ch4. */
    uint8_t pdaf_data_present;                        /*!< PDAF Calibration data present or not(0: no PDAF Data)*/
    ia_nvm_pdaf_data *pdaf_data;                      /*!< PDAF Calibration data */
    uint8_t closed_loop_data_present;                 /*!< closed loop vcm data present or not (0: no vcm data)*/
    ia_nvm_closed_loop_vcm *vcm;                      /*!< vcm data */
    uint16_t checksum;                                /*!< CRC-16 checksum calculated from all bytes before checksum. */
} ia_nvm;

/*!
 * \brief Parses intel specified camera NVM data into ia_nvm structure.
 * \param[in]  a_nvm_ptr        Camera NVM data in Intel specified format.
 * \param[out] a_parsed_nvm_ptr Camera NVM in parsed (ia_nvm) structure.
 * \return                NVM parsing error code.
 */
LIBEXPORT ia_nvm_error
ia_nvm_parse(const ia_binary_data * a_nvm_ptr,
             ia_nvm** a_parsed_nvm_ptr);

/*!
 * \brief Frees contents of ia_nvm structure.
 * \param[in] parsed_nvm Camera NVM in parsed (ia_nvm) structure.
 */
LIBEXPORT void
ia_nvm_deinit(ia_nvm *a_nvm_ptr);

/*!
 * \brief Allocates memory and creates Intel specified camera NVM data from input structure.
 * \param[in] parsed_nvm Structure containing values from which the binary will be created.
 * \return               Binary data containing the camera NVM in Intel specified format.
 */
LIBEXPORT ia_binary_data*
ia_nvm_binary_create(const ia_nvm *a_nvm_ptr);

/*!
 * \brief Deletes memory allocated by ia_nvm_binary_create() function.
 * \param[in] nvm_binary Binary data created by function ia_nvm_binary_create.
 */
LIBEXPORT void
ia_nvm_binary_delete(ia_binary_data *a_nvm_binary_ptr);

#ifdef __cplusplus
}
#endif

#endif /* _IA_NVM_H_ */
