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
 * \file ia_exc_deprecated.h
 * \brief Definitions of exposure parameters conversions between generic and sensor units (deprecated versions).
*/


#ifndef IA_EXC_DEPRECATED_H_
#define IA_EXC_DEPRECATED_H_

#include "ia_types.h"
#include "ia_aiq_types.h"
#include "ia_cmc_types.h"

#ifdef __cplusplus
extern "C" {
#endif


/*!
 * \brief Convert analog gain from generic units to sensor units.
 * Calculate analog gain code from analog gain, limiting it to the sensor specific values.
 * \param[in]  a_gain_conversion          Structure containing analog gain to gain code conversion tables.
 * \param[in]  a_analog_gain              Analog gain value to convert to sensor unit.
 * \param[out] a_analog_gain_code_global  Calculated analog gain code.
 * \return                                Error code.
 */
LIBEXPORT ia_err
ia_exc_analog_gain_to_sensor_units(
    const cmc_parsed_analog_gain_conversion_t *a_gain_conversion,
    const float32_t a_analog_gain,
    uint16_t *a_analog_gain_code_global);

/*!
 * \brief Converts digital gain from generic units to sensor units.
 * AEC will use default formulae for conversion, if not given
 * Converts digital gain value to sensor units, limiting the value according to sensor specific limits.
 * \param[in]  a_gain_conversion          Structure containing digital gain to code mapping information.
 * \param[in]  a_digital_gain             Digital gain in generic units.
 * \param[out] a_digital_gain_code_global Calculated digital gain code.
 * \return                                Error code.
 */
LIBEXPORT ia_err
ia_exc_digital_gain_to_sensor_units(
    const cmc_parsed_digital_gain_t * a_gain_conversion,
    const float32_t a_digital_gain,
    uint16_t *a_digital_gain_code_global);

/*!
 * \brief Convert analog gain from sensor units to generic units.
 * Using the sensor characteristics info, calculate analog gain from sensor register values.
 * \param[in]  a_gain_conversion   Structure containing analog gain to gain code conversion tables.
 * \param[in]  a_code              Analog gain code in sensor specific units.
 * \param[out] a_analog_gain       Calculated analog gain.
 * \return                         Error code.
 */
LIBEXPORT ia_err
ia_exc_sensor_units_to_analog_gain(
    const cmc_parsed_analog_gain_conversion_t * a_gain_conversion,
    const uint16_t a_code,
    float32_t *a_analog_gain);

/*!
 * \brief Converts digital gain from sensor units to generic units.
 * AEC will use default formula for conversion, if not given
 * \param[in]  a_gain_conversion   Structure containing digital gain to code mapping information.
 * \param[in]  a_gain_code         Digital gain code in sensor specific units.
 * \param[out] a_digital_gain      Calculated digital gain.
 * \return                         Error code.
 */
LIBEXPORT ia_err
ia_exc_sensor_units_to_digital_gain(
    const cmc_parsed_digital_gain_t * a_gain_conversion,
    const uint16_t a_code,
    float32_t *a_digital_gain);

/*!
 * \brief Gets analog gain and code based on current code.
 * Offset is used to retrieve previous or next analog gain code pairs from the CMC analog gain conversion tables.
 * \param[in]  a_gain_conversion   Structure containing analog gain to gain code conversion tables.
 * \param[in]  code                Analog gain code in sensor specific units.
 * \param[in]  gain_code_offset    Offset of code to resolve (-1 or 1).
 * \param[out] a_offset_code       Analog gain code matching the offset.
 * \return                         Error code.
 */
LIBEXPORT ia_err
ia_exc_get_analog_gain_code(
    const cmc_parsed_analog_gain_conversion_t * a_gain_conversion,
    const uint16_t code,
    const int32_t gain_code_offset,
    uint16_t *a_offset_code);

/*!
 * \brief Gets digital gain and code based on current code.
 * Offset is used to retrieve previous or next digital gain code pairs from the CMC digital gain conversion tables.
 * \param[in]  a_gain_conversion   Structure containing digital gain to gain code conversion tables.
 * \param[in]  code                Digital gain code in sensor specific units.
 * \param[in]  gain_code_offset    Offset of code to resolve (-1 or 1).
 * \param[out] a_offset_code       Analog gain code matching the offset.
 * \return                         Error code.
 */
LIBEXPORT ia_err
ia_exc_get_digital_gain_code(
    const cmc_parsed_digital_gain_t *a_gain_conversion,
    const uint16_t code,
    const int32_t gain_code_offset,
    uint16_t *a_offset_code);

/*!
 * \brief Converts ISO to analog gain and digital gain and codes.
 * Gains are round down except if given ISO is smaller than corresponding gain 1.0.
 * \param[in]  a_analog_gain_conversion   Structure containing analog gain to gain code conversion tables.  Can be NULL, if sensor doesn't support analog gain.
 * \param[in]  a_digital_gain_conversion  Structure containing digital gain to code mapping information. Can be NULL, if sensor doesn't support digital gain.
 * \param[in]  a_sensitivity              Structure containing sensor sensitivity information.
 * \param[in]  a_iso                      ISO value to be converted into gains.
 * \param[out] a_analog_gain              Calculated analog gain.-1.0 if not available.
 * \param[out] a_analog_gain_code         Calculated analog gain code. -1 if not available.
 * \param[out] a_digital_gain             Calculated digital gain. -1.0 if not available.
 * \param[out] a_digital_gain_code        Calculated digital gain code. -1 if not available.
 * \return                                Error code.
 */
LIBEXPORT ia_err
ia_exc_convert_iso_to_gains(
    const cmc_parsed_analog_gain_conversion_t *a_analog_gain_conversion,
    const cmc_parsed_digital_gain_t *a_digital_gain_conversion,
    const cmc_sensitivity_t *a_sensitivity,
    const int32_t a_iso,
    float32_t *a_analog_gain,
    int32_t *a_analog_gain_code,
    float32_t *a_digital_gain,
    int32_t *a_digital_gain_code);

/*!
 * \brief Converts analog gain and digital gain codes to ISO.
 * \param[in]  a_analog_gain_conversion   Structure containing analog gain to gain code conversion tables. Can be NULL, if sensor doesn't support analog gain.
 * \param[in]  a_digital_gain_conversion  Structure containing digital gain to code mapping information. Can be NULL, if sensor doesn't support digital gain.
 * \param[in]  a_sensitivity              Structure containing sensor sensitivity information.
 * \param[in]  a_analog_gain_code         Analog gain code. -1 if not available.
 * \param[in]  a_digital_gain_code        Digital gain code. -1 if not available.
 * \param[out] a_iso                      Analog and digital gain codes converted into ISO value. -1 if not available.
 * \return                                Error code.
 */
LIBEXPORT ia_err
ia_exc_convert_gain_codes_to_iso(
    const cmc_parsed_analog_gain_conversion_t * a_analog_gain_conversion,
    const cmc_parsed_digital_gain_t * a_digital_gain_conversion,
    const cmc_sensitivity_t * a_sensitivity,
    const int32_t a_analog_gain_code,
    const int32_t a_digital_gain_code,
    int32_t *a_iso);

#ifdef __cplusplus
}
#endif

#endif /* IA_EXC_H_ */
