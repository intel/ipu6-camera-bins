/*
 * Copyright 2012-2021 Intel Corporation
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
 * \file ia_aiq_types_deprecated.h
 * \brief Definitions of input/output structures of the Intel 3A library.
 */

#ifndef IA_AIQ_TYPES_DEPRECATED_H_
#define IA_AIQ_TYPES_DEPRECATED_H_

#include "ia_aiq_types.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!
* \brief Ambient Light EventsLIGHT_AMBIENTLIGHT
* NOTE: This should always match to libsensorhub API
*/
typedef struct
{
    unsigned long long ts;  /*!< Time stamp in usec (microseconds) */
    float data;             /*!< Ambient Light data ? */
    float sensitivity;      /*!< Sensitivity of Ambient Light sensor */
    unsigned long long fs;  /*!< Frame stamp in usec (microseconds) */
} ia_aiq_ambient_light_events;

/*!
* \brief Data from external sensors
*/
typedef struct
{
    ia_aiq_sensor_data* accelerometer_events;                       /*!< The data holds information on the acceleration of the device in mg/sec (miligravity per second).
                                                                    Acceleration = Gravity + Linear Acceleration*/
    unsigned int num_accelerometer_events;                          /*!< Number of accelerometer events */
    ia_aiq_sensor_data* gravity_events;                             /*!< The data holds information on the gravitation of the device in mg/sec (miligravity per second) */
    unsigned int num_gravity_events;                                /*!< Number of gravity events */
    ia_aiq_sensor_data* gyroscope_events;                           /*!< The data holds information on the angular velocity of the device in rad/sec */
    unsigned int num_gyroscope_events;                              /*!< Number of gyroscope events */
    ia_aiq_ambient_light_events* ambient_light_events;              /*!< The data holds information on the ambient light */
    unsigned int num_ambient_light_events;                          /*!< Number of ambient light events */
    ia_aiq_dmd_sensor_events* dmd_events;                           /*!< Device Movement Detector (DMD) virtual sensor */
    unsigned int num_dmd_events;                                    /*!< Number of DMD sensor events */
} ia_aiq_sensor_events;

/*!
* \brief Shading Adaptor results.
*/
typedef struct {
    unsigned short* lsc_grid[4][4];                   /*!< Pointers to the LSC grid for all color channels. Invalid channels are set to NULL. */
    unsigned short width;                             /*!< Width of LSC grid. */
    unsigned short height;                            /*!< Height of LSC grid. */
    unsigned int fraction_bits;                       /*!< Number of fraction bits for the shading table fix point representation. */
    cmc_bayer_order color_order;                      /*!< Color channels order. */
    bool lsc_update;                                  /*!< Indicates if LSC grid has been modified and shall be updated in ISP. false - no change, true - new LSC. */
    light_source_t light_source[CMC_NUM_LIGHTSOURCES];/*!< Weights per light source type used in calculation of the LSC tables. */
    float confidence;                                 /*!< Confidence in results. */
    ia_aiq_frame_params frame_params;                 /*!< Frame parameters that describe cropped area size and its position under LSC grid. */
} ia_aiq_sa_results;

#ifdef __cplusplus
}
#endif

#endif /* IA_AIQ_TYPES_DEPRECATED_H_ */


