/*
 * Copyright (C) 2020-2022 Intel Corporation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef IIPUAIC_H_
#define IIPUAIC_H_

#include "CCAStorage.h"
#include "IntelCCATypes.h"
#ifdef PAC_ENABLE
#include "ia_aic_types.h"
#endif

namespace cca {
enum cfa_type_t
{
    type_1x1 = 0,
    type_2x2 = 1,
    type_4x4 = 2,
};
/*!
 * \brief decode stats input parameters
 */
typedef struct {
    long sequenceId;                            /*!< sequence id of the frame to decode from. */
    uint32_t bitmap;                            /*!< select RGBS, HIST, AF ... if needed to decode. */
    const ia_aiq_ae_results* ae_settings;       /*!< AE result for sensor exposure setting. */
    const ia_aiq_color_channels *wb_color_gains;/*!< wb gains for all channels. */
    const ia_bcomp_results* bcomp_settings;     /*!< BComp result for lens VCM and PWM setting. */
    ia_binary_data* stats;                      /*!< statistics binary. */
    bool need_decode_dvs_stats;                 /*!< need process DVS statistics. */
    const ia_aiq_ir_weight_t* ir_weight;        /*!< ir weight from PA. */
} cca_dec_stats_input;

/*!
 * \brief intel 3a plus results for AIC run
 */
typedef struct {
    ia_aiq_frame_params* frame_info;
    unsigned long long frame_timestamp;
    ia_aiq_pa_results_v1* pa_results;
    ia_aiq_awb_results* awb_results;
    ia_aiq_ae_results* aec_results;
    ia_aiq_af_results* af_results;
    ia_aiq_gbce_results* gbce_results;
    ia_aiq_sa_results_v1 *sa_results;
    ia_ltm_drc_params* drc_params;
    ia_ltm_results* ltm_results;
    ia_dvs_morph_table* morph_table;
    ia_dvs_image_transformation* dvs_image_transform;
    ia_bcomp_results* bcomp_results;
} cca_3a_plus_results;

#ifdef PAC_ENABLE
/*!
 * \brief configure the kernels in cb for AIC
 */
typedef struct {
    int group_id;
    int fragment_count;
    aic::ImagingKernelGroup *kernel_group;
} cca_cb_config;

/*!
 * \brief configure the kernels in whole pipe for AIC
 */
typedef struct {
    uint32_t cb_num;
    cca_cb_config cb_config[MAX_PG_NUM];
} cca_aic_config;

/*!
 * \brief terminal buffer struct
 */
typedef struct {
    uint32_t terminal_index;
    size_t buf_size;
    aic::IaAicBuffer *payload;
} cca_terminal_buf;

/*!
 * \brief terminals for one cb
 */
typedef struct {
    int group_id;
    uint32_t num_terminal;
    cca_terminal_buf terminal_buf[MAX_PG_TERMINAL_NUM];
} cca_cb_termal_buf;

typedef struct {
    uint32_t cb_num;
    cca_cb_termal_buf cb_terminal_buf[MAX_PG_NUM];
} cca_aic_terminal_config;

/*!
 * \brief kernel offset config for AIC
 */
typedef struct {
    int uuid;
    aic::IaAicBufferTypes terminal_type;
    uint32_t terminal_index;
    uint32_t *offsets;
    uint32_t *sizes;
    uint32_t num_offsets;
    uint32_t fragment;
} cca_kernel_offset;

/*!
 * \brief kernel offset config for special cb
 */
typedef struct {
    int group_id;
    uint32_t num_kernels;
    cca_kernel_offset kernels_offset[MAX_KERNEL_NUM_IN_PG];
} cca_cb_kernel_offset;

/*!
 * \brief configure the all kernel offsets in whole pipe for AIC
 */
typedef struct {
    uint32_t cb_num;
    cca_cb_kernel_offset cb_kernel_offset[MAX_PG_NUM];
} cca_aic_kernel_offset;

/*!
 * \brief struct of PAL bin dump
 */
typedef struct
{
    int group_id;
    aic::IaBinaryData bin;
}cca_pal_output;

typedef struct
{
    uint32_t cb_num;
    cca_pal_output cb_output[MAX_PG_NUM];
}cca_multi_pal_output;
#endif

/*!
 * \brief Pure interface exposed to IntelCCA for AIC operations.
 */
class IIPUAic {
public:
    virtual ~IIPUAic() = default;

    /*!
     * \brief init all the IPU handles with aiqb/cmc.
     *
     * \param[in] aiqb                   Mandatory.\n
     *                                   tuning file.
     * \param[in] cmc                    Mandatory.\n
     *                                   CCA global initial parameters.
     * \param[in] max_stats_width        Mandatory.\n
     *                                   max statistics grid width.
     * \param[in] max_stats_height       Mandatory.\n
     *                                   max statistics grid height.
     * \param[in] max_num_stats_in       Mandatory.\n
     *                                   max number of stats related to hdr/multi-sensor.
     * \param[in] mkn                    Mandatory.\n
     *                                   maker note buffer.
     * \param[in] aic_stream_ids         Optional.\n
     *                                   stream id info for aic handle.
     * \return                           Error code.
     */
    virtual ia_err init(const ia_binary_data *aiqb, const ia_cmc_t *cmc, uint32_t max_stats_width,
                        uint32_t max_stats_height, uint32_t max_num_stats_in, const ia_mkn *mkn,
                        const cca_stream_ids& aic_stream_ids) = 0;


    /*!
     * \brief update tuning file aiqb.
     *
     * \param[in] aiqb                       Mandatory.\n
     *                                       Tuning file.
     * \param[in] cmc                        Mandatory.\n
     *                                       Parsed cmc data.
     * \param[in] streamId                   Optional.\n
     *                                       The stream id for aic handle.
     * \return                               Error code.
     */
    virtual ia_err updateTuning(const ia_binary_data *aiqb, const ia_cmc_t *cmc,
                                int32_t streamId = -1) = 0;

    /*!
     * \brief pass parameters for statistic analysis.
     *
     * \param[in] params                     Mandatory.\n
     *                                       parameters for statistis.
     * \param[in] aiqResults                 Mandatory.\n
     *                                       last AIQ results for reference.
     * \return                               Error code.
     */
    virtual ia_err setStatsParams(ia_aiq* aiqHandle, const cca_stats_params &params,
                                  const cca_aiq_results_storage &aiqResults) = 0;

    /*!
    * \brief get the max bin index of non-zero element.
    *
    * \param[out] stats                 Mandatory.\n
    *                                   output the max bin index.
    * \return                           Error code.
    */
    virtual ia_err getBrightestIndex(uint32_t *outMaxBin) = 0;

#ifdef PAC_ENABLE
    /*!
     * \brief configure cb including kernels group and kernels offset.
     *
     * \param[in] conf                          Mandatory.\n
     *                                          graph config for all kernels.
     * \param[in] offset                        Mandatory.\n
     *                                          buffer offsets for all kernels.
     * \param[out] termConfig                   Mandatory.\n
     *                                          the memory needed by terminals of cb.
     * \param[in] aicId                         Optional.\n
     *                                          id for aic handle.
     * \return                                  Error code.
     */
    virtual ia_err config(const cca_aic_config &conf, const cca_aic_kernel_offset &offset,
                          cca_aic_terminal_config &termConfig, int32_t aicId = -1) = 0;
    /*!
     * \brief register terminal buffers.
     *
     * \param[in] termConfig                    Mandatory.\n
     *                                          the memory needed by terminals of cb.
     * \param[in] aicId                         Optional.\n
     *                                          id for aic handle.
     * \return                                  Error code.
     */
    virtual ia_err registerBuf(const cca_aic_terminal_config &termConfig, int32_t aicId = -1) = 0;
    /*!
     * \brief get AIC buffers for FW input after runing PAL.
     *
     * \param[out] termConfig                   Mandatory.\n
     *                                          terminal memory of cb filled with IPU params.
     * \param[in] aicId                         Optional.\n
     *                                          id for aic handle.
     * \return                                  Error code.
     */
    virtual ia_err getBuf(cca_aic_terminal_config &termConfig, int32_t aicId = -1) = 0;
    /*!
     * \brief decode statistics for a specific type(AIQ, LTM, DVS stats).
     *
     * \param[in] groupId                Mandatory.\n
     *                                   group id of CB.
     * \param[in] seqId                  Mandatory.\n
     *                                   sequence id for streaming.
     * \param[in] aicId                  Optional.\n
     *                                   id for aic handle.
     * \return                           Error code.
     */
    virtual ia_err decodeStats(int32_t groupId, int64_t seqId, int32_t aicId = -1) = 0;

    /*!
     * \brief run AIC parameters with graph config & Intel3A results.
     *
     * \param[in] params                 Mandatory.\n
     *                                   AIQ plus parameters and manual settings.
     * \param[in] aaaResults             Mandatory.\n
     *                                   AIQ plus results.
     *  \param[in] bitmap                Mandatory.\n
     *                                   Bitmap to decide which CB will be run.
     * \param[out] pal                   Mandatory.\n
     *                                   AIC results for each CB.
     * \return                           Error code.
     */
    virtual ia_err run(const cca_pal_input_params& params, cca_3a_plus_results& aaaResults,
                       cca_multi_pal_output& output, uint8_t bitmap) = 0;

    virtual ia_err UpdateConfigurationResolutions(const cca_aic_config& conf, bool isKeyResolutionChanged, int32_t aicId) = 0;

#else
    /*!
     * \brief query DVS statistics.
     *
     * \param[out] stats                 Mandatory.\n
     *                                   return DVS statistics.
     * \return                           Error code.
     */
    virtual ia_err getDvsStats(ia_dvs_statistics* stats) = 0;

    /*!
     * \brief decode statistics for a specific type(AIQ, LTM, DVS stats) <=IPU6.
     *
     * \param[in] decParams              Mandatory.\n
     *                                   statistics info from FW.
     * \param[out] results               Mandatory.\n
     *                                   results of parsing statistics from FW.
     * \param[out] outStats              Optional.\n
     *                                   Output the AIQ statistics data.
     * \return                           Error code.
     */
    virtual ia_err decodeStats(const cca_dec_stats_input &decParams, ia_isp_bxt_statistics_query_results_t *results,
                               cca_out_stats *outStats = nullptr) = 0;


    /*!
     * \brief run AIC parameters with graph config & Intel3A results.
     *
     * \param[in] params                 Mandatory.\n
     *                                   AIQ plus parameters and manual settings.
     * \param[in] aaaResults             Mandatory.\n
     *                                   AIQ plus results.
     * \param[out] pal                   Mandatory.\n
     *                                   AIC results.
     * \return                           Error code.
     */
    virtual ia_err run(const cca_pal_input_params& params, cca_3a_plus_results& aaaResults, ia_binary_data* pal) = 0;

#endif
     /*!
     * \brief deinit all the AIC handles.
     */
    virtual void deinit() = 0;

    /*!
     * \brief get the IPU HW version.
     *
     * \return                                  IPU HW version.
     */
    virtual const char* getVersion() const = 0;

};
}//cca
#endif //IIPUAIC_H_
