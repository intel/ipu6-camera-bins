/*
 * Copyright 2014-2017 Intel Corporation
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

#pragma once



class Sensor
{
public:

    Sensor(void)
    {
    }

    virtual ~Sensor(void)
    {
    }


    // TODO: check if this interface is suitable for all sensors.
    // TODO: check what happens with the assist light in presence of ZSL.
    virtual void SetLensPosition (
        long next_lens_position,   // Next lens position.
        bool use_af_assist = false // True if the assist light should be turned on at half-press.
        ) = 0;
    
    // TODO: add flash control
    // TODO: review the parameters--shall we use sensor units instead?
    virtual void SetExposure (
        long exposure_time_us,         // Exposure time in microseconds, -1 if N/A.
        float analog_gain = -1.0,      // Analog gain as a multiplier (e.g. 1.0), -1.0 if N/A.
        float digital_gain = -1.0,     // Digital gain as a multiplier (e.g. 1.0), -1.0 if N/A.
        float aperture_fn = -1.0,      // F-number of aperture (e.g. 2.8), -1.0 for N/A.
        bool nd_filter_enabled = false // true or false, false for N/A.
        ) = 0;

};

