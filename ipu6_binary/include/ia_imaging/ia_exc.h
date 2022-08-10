/*
 * Copyright 2014-2021 Intel Corporation
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
 * \file ia_exc.h
 * \brief Definitions of exposure parameters conversions between generic and sensor units.
*/


#ifndef IA_EXC_H_
#define IA_EXC_H_

#include "ia_types.h"
#include "ia_aiq_types.h"
#include "ia_cmc_types.h"

#include "ia_exc_deprecated.h"

#ifdef __cplusplus
extern "C" {
#endif


/*!
 * \brief Convert exposure time from generic units to sensor units (line & pixel values).
 * AEC will use default formula for conversion, if not given
 * \param[in]  a_exposure_range          Structure containing coarse and fine integration sensor register ranges. Can be set to NULL if not available.
 * \param[in]  a_sensor_limits           Structure containing coarse and fine integration time limits and step size.
 * \param[in]  a_exposure_time           Exposure time to convert.
 * \param[out] a_coarse_integration_time Coarse (rows of integration) for rolling shutter cameras.
 * \param[out] a_fine_integration_time   Fine (pixels of integration remaining after coarse quantization) for rolling shutter cameras.
 * \return                             Error code.
 */
LIBEXPORT ia_err
ia_exc_exposure_time_to_sensor_units(
    const cmc_exposure_range_t *a_exposure_range,
    const ia_aiq_exposure_sensor_descriptor *a_sensor_limits,
    const uint32_t a_exposure_time,
    uint16_t *a_coarse_integration_time,
    uint16_t *a_fine_integration_time);

/*!
 * \brief Converts gain from generic units to sensor units.
 * AEC will use default formulae for conversion, if not given
 * Converts gain value to sensor units, limiting the value according to sensor specific limits.
 * \param[in]  a_gain_conversion   Structure containing gain to code mapping information.
 * \param[in]  a_gain              Gain in generic units.
 * \param[out] a_gain_code         Calculated gain code.
 * \return                       Error code.
 */
/*LDRA_INSPECTED 67 x */
LIBEXPORT ia_err
ia_exc_gain_to_sensor_units(
    const cmc_gain_conversion_t *a_gain_conversion,
    const float32_t a_gain,
    uint16_t *a_gain_code);

/*!
 * \brief Convert exposure time from sensor units to generic units.
 * AEC will use default formula for conversion, if not given
 * \param[in]  a_sensor_limits       Structure containing pixel clock frequency needed in exposure conversion.
 * \param[in]  a_coarse_integration_time Coarse (rows of integration) for rolling shutter cameras.
 * \param[in]  a_fine_integration_time   Fine (pixels of integration remaining after coarse quantization) for rolling shutter cameras.
 * \param[out] a_exposure_time           Calculated exposure value in microseconds.
 * \return                             Error code.
 */
LIBEXPORT ia_err
ia_exc_sensor_units_to_exposure_time(
    const ia_aiq_exposure_sensor_descriptor *a_sensor_limits,
    const uint16_t a_coarse_integration_time,
    const uint16_t a_fine_integration_time,
    uint32_t *a_exposure_time);

/*!
* \brief Convert gain from sensor units to generic units.
* Using the sensor characteristics info, calculate gain from sensor register values.
* \param[in]  a_gain_conversion   Structure containing gain to gain code conversion tables.
* \param[in]  a_gain_code         Gain code in sensor specific units.
* \param[out] a_gain              Calculated gain.
* \return                       Error code.
*/
LIBEXPORT ia_err
ia_exc_sensor_units_to_gain(
    const cmc_gain_conversion_t *a_gain_conversion,
    const uint16_t a_gain_code,
    float32_t *a_gain);

/*!
* \brief Gets gain and code based on current code.
* Offset is used to retrieve previous or next gain code pairs from the CMC gain conversion tables.
* \param[in]  a_gain_conversion   Structure containing gain to gain code conversion tables.
* \param[in]  a_gain_code         Gain code in sensor specific units.
* \param[in]  a_gain_code_offset  Offset of code to resolve (-1 or 1).
* \param[out] a_indexed_gain_code Gain code matching the offset.
* \return                       Error code.
*/
LIBEXPORT ia_err
ia_exc_get_gain_code(
    const cmc_gain_conversion_t *a_gain_conversion,
    const uint16_t a_gain_code,
    const int32_t a_gain_code_offset,
    uint16_t* a_indexed_gain_code);

/*!
 * \brief Converts ISO to gains and codes.
 * Gains are round down except if given ISO is smaller than corresponding gain 1.0.
 * \param[in]  multi_gain_conversions   Structure containing gain to gain code conversion tables.
 * \param[in]  sensitivity              Structure containing sensor sensitivity information.
 * \param[in]  iso                      ISO value to be converted into gains.
 * \param[out] gains                    Array of calculated gains. -1.0 if not available.
 * \param[out] gain_codes               Array of calculated gain codes. -1 if not available.
 * \return                              Error code.
 */
LIBEXPORT ia_err
ia_exc_convert_iso_to_multi_gains(
    const cmc_multi_gain_conversions_t *a_multi_gain_conversions,
    const cmc_sensitivity_t * a_sensitivity,
    const int32_t a_iso,
    float32_t a_gains[IA_CMC_GAINS_MAX_NUM],
    int32_t a_gain_codes[IA_CMC_GAINS_MAX_NUM]);

/*!
 * \brief Converts gain codes to ISO.
 * \param[in]  a_multi_gain_conversions   Structure containing gain to gain code conversion tables. Can be NULL, if sensor doesn't support any gains.
 * \param[in]  a_sensitivity              Structure containing sensor sensitivity information.
 * \param[in]  a_gain_codes               Array of gain codes. Each element can be -1 if not available.
 * \param[out] a_iso                      Gain codes converted into ISO value. -1 if not available.
 * \return                              Error code.
 */
LIBEXPORT ia_err
ia_exc_convert_multi_gain_codes_to_iso(
    const cmc_multi_gain_conversions_t *a_multi_gain_conversions,
    const cmc_sensitivity_t *a_sensitivity,
    const int32_t a_gain_codes[IA_CMC_GAINS_MAX_NUM],
    int32_t *a_iso);

#ifdef __cplusplus
}
#endif

#endif /* IA_EXC_H_ */
