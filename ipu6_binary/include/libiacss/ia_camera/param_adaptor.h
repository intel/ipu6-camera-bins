/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2017 Intel Corporation. All Rights Reserved.
 *
 * The source code contained or described herein and all documents related to
 * the source code ("Material") are owned by Intel Corporation or its suppliers
 * or licensors. Title to the Material remains with Intel Corporation or its
 * suppliers and licensors. The Material contains trade secrets and proprietary
 * and confidential information of Intel or its suppliers and licensors. The
 * Material is protected by worldwide copyright and trade secret laws and
 * treaty provisions. No part of the Material may be used, copied, reproduced,
 * modified, published, uploaded, posted, transmitted, distributed, or
 * disclosed in any way without Intel's prior express written permission.
 *
 * No license under any patent, copyright, trade secret or other intellectual
 * property right is granted to or conferred upon you by disclosure or delivery
 * of the Materials, either expressly, by implication, inducement, estoppel or
 * otherwise. Any license under such intellectual property rights must be
 * express and approved by Intel in writing.
 */

#ifndef IA_CAMERA_PROCESSING_PIPELINE_PARAM_ADAPTOR_H_
#define IA_CAMERA_PROCESSING_PIPELINE_PARAM_ADAPTOR_H_

#include "ipu_statistics.h"
#include "gcss_aic_utils.h"

#include <vector>
#include <memory>

extern "C" {
#include <ia_tools/ia_macros.h>
#include <ia_types.h>
#include <ia_cmc_types.h>
#include <ia_isp_types.h>
#include <ia_isp_bxt.h>
}

struct ImageEnhancementSettings {
    char manualBrightness;
    char manualContrast;
    char manualHue;
    char manualSaturation;
    char manualSharpness;
};

struct IspSettings {
    ia_isp_feature_setting nrSetting;
    ia_isp_feature_setting eeSetting;
    ia_isp_effect effects;
    ImageEnhancementSettings manualSettings;
    IspSettings() { CLEAR(*this); }
};


/**
 * \class ParamAdaptor
 *
 * Program Group Parameter Adaptor
 * Objects of this class will convert from generic parameters provided by
 * the 3A algorithms (AIQ) to concrete Process group descriptor and terminal
 * payloads needed to execute one process group.
 *
 * This class wraps the Generic Automatic Isp Configuration (AIC) library
 * as well as PAL library for various IPU's
 *
 * Note: Clarification of FAS naming conventions:
 * Program Group is to a Process Group what a class is to an object of that
 * class

 * For now, this class can:
 * - convert statistics from HW specific format (output from PG) to AIQ format
 * - convert 3A results into HW specific configuration (PG descriptor + terminal
 *   payloads)
 */
class ParamAdaptor
{
public:
    ParamAdaptor(GCSS::BxtAicUtils &bxtAicUtils, int32_t execCtx);
   ~ParamAdaptor();

    css_err_t init(ia_binary_data &cpfData, ia_cmc_t &cmcData);
    css_err_t configure(ia_isp_bxt_input_params_v2 &initalParams);
    css_err_t convertStatistics(ia_binary_data *statistics,
                                IPUStatistics &algoStats);
    css_err_t convertDVSStatistics(ia_binary_data &hwStats,
                                   uint32_t width,
                                   uint32_t height,
                                   ia_dvs_statistics **dvsStats);

    css_err_t runIspAdapt(ia_isp_bxt_input_params_v2 &input,
                          const char *dumpName,
                          ia_binary_data *outputIpuParameters = NULL);

    static int32_t getMaxHistogramSize();
    static void getMaxGridSize(int32_t &maxW, int32_t &maxH);

    const ia_binary_data* getParameters() { return &mCurrentIpuParameters; }

private:  /* methods */
    // Disallow copy constructors and assignment operator
    ParamAdaptor(const ParamAdaptor&);
    void operator=(const ParamAdaptor&);


    // Dumping methods for debugging purposes.
    void _dumpStats(ia_aiq_rgbs_grid *out_rgbs_grid,
                    ia_aiq_af_grid *out_af_grid);
    void _dumpRunInputParams(ia_aiq_frame_use frame_use,
                            ia_aiq_frame_params *sensor_frame_params,
                            ia_aiq_exposure_parameters *exposure_results,
                            ia_aiq_awb_results *awb_results,
                            ia_aiq_gbce_results *gbce_results,
                            ia_aiq_pa_results_v1 *pa_results,
                            uint32_t isp_vamem_type,
                            ia_isp_feature_setting nr_setting,
                            ia_isp_feature_setting ee_setting,
                            char manual_brightness,
                            char manual_contrast,
                            char manual_hue,
                            char manual_saturation,
                            ia_isp_effect effects,
                            bool reduced_range_yuv,
                            ia_aiq_frame_params *isp_frame_params,
                            int32_t *custom_tunings_list);
    css_err_t _dumpBinaryToFile(int32_t reqId, const char *name,
                               const ia_binary_data &outputData);
private:

    int32_t mExecCtxId;  /**< identifier of the isp execution context (set of PG's) that
                              this adaptor is used for.*/
    ia_isp_bxt   *mIspAdaptHandle;
    ia_binary_data mCurrentIpuParameters;   /**< current output from AIC */
    ia_isp_bxt_program_group mProgramGroup;

    GCSS::BxtAicUtils &mBxtAicUtils;
};

#endif /* IA_CAMERA_PROCESSING_PIPELINE_PARAM_ADAPTOR_H_ */
