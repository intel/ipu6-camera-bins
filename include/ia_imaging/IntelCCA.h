/*
 * Copyright (C) 2019-2021 Intel Corporation.
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

#pragma once

#include "IntelCCATypes.h"
#include "IIPUAic.h"
#include "CCAStorage.h"

namespace cca {

class IntelCCA {
public:
    IntelCCA();
    virtual ~IntelCCA();

    ia_err init(const cca_init_params& initParams);

    ia_err setStatsParams(const cca_stats_params& params);

    ia_err runAEC(uint64_t frameId, const cca_ae_input_params& params, cca_ae_results *results);

    ia_err runAIQ(uint64_t frameId, const cca_aiq_params& params, cca_aiq_results *results);
#ifdef ENABLE_LTM
    ia_err runLTM(uint64_t frameId, const cca_ltm_input_params& params);
#endif

#ifdef ENABLE_DVS
    ia_err updateZoom(const cca_dvs_zoom& params);
    ia_err runDVS(uint64_t frameId) const;
#endif

    ia_err getCMC(cca_cmc &cmc);
    ia_err getMKN(ia_mkn_trg type, cca_mkn &mkn);
    ia_err getAiqd(cca_aiqd &aiqd);
    ia_err updateTuning(uint8_t tag, const ia_lard_input_params &lardParams);
    ia_err deinit();
    const char* getVersion() const;

    /*! Get lard data
    *
    * Get lard results parsed from aiqb
    *
    * \param [out]  lard data
    *
    *
    * return ia_err_none in success. Errorcode on failure
    */
    ia_err getLardData(cca_lard_data *lard);

#ifdef PAC_ENABLE
    ia_err configAIC(const cca_aic_config &conf, const cca_aic_kernel_offset &offset, cca_aic_terminal_config &termConfig);
    ia_err registerAICBuf(const cca_aic_terminal_config &termConfig);
    ia_err getAICBuf(cca_aic_terminal_config &termConfig);
    ia_err decodeStats(int groupId, long seqId);

    /*! run AIC to get PAL binary for IPU7 HW
    *
    * Calculate the PAL parameters according to 3A+ results and manual settings
    *
    * \param [in]  frameId      indicate PAL results for specia frame
    * \param [in]  params       manual settings for IPU pipeline
    * \param [out] output          binary array of IPU parameters for each CB
    *
    *
    * return error code for status. zero on success, non-zero on failure
    */
    ia_err runAIC (uint64_t frameId, const cca_pal_input_params& params, cca_multi_pal_output& output);
#else
    /*! Decode statistics from HW
    *
    * Parse and decode different statistics from HW including AE/AWB/DVS/HDR
    *
    * \param [in]  stats        statistics binary from HW
    * \param [out] results      statistics type after parsing statistics
    *
    *
    * return ia_err_none in success. Errorcode on failure
    */
    ia_err decodeStats(const cca_stats_bin &stats, ia_isp_bxt_statistics_query_results_t *results);

    /*! Decode statistics from HW
    *
    * Parse and decode different statistics from HW including AE/AWB/DVS/HDR
    *
    * \param [in]  statsPointer pointer to share memory that stores the statistics binary from HW
    * \param [in]  statsSize    statistics size
    * \param [out] results      statistics type after parsing statistics
    *
    *
    * return ia_err_none in success. Errorcode on failure
    */
    ia_err decodeStats(uint64_t statsPointer, uint32_t statsSize, ia_isp_bxt_statistics_query_results_t *results);

    /*! Get PAL binary size
    *
    * Calculate the PAL size according to program group
    *
    * \param [in]  programGroup kernel info for special stream id
    *
    *
    * return Pal size in success. zero on failure
    */
    uint32_t getPalSize(const cca_program_group &programGroup);

    /*! run AIC to get PAL binary for IPU HW
    *
    * Calculate the PAL parameters according to 3A+ results and manual settings
    *
    * \param [in]  frameId      indicate PAL results for specia frame
    * \param [in]  params       manual settings for IPU pipeline
    * \param [out] pal          binary of IPU parameters for IPU HW
    *
    *
    * return error code for status. zero on success, non-zero on failure
    */
    ia_err runAIC (uint64_t frameId,
               const cca_pal_input_params& params,
               ia_binary_data* pal);
#endif

private:
    ia_binary_data* getAiqData();
    ia_binary_data* getIspData();
    ia_binary_data* getOthersData();
    ia_err initCpfParse();
    void initSaResults();
    ia_err initIspAic();
    void deInitIspAic();
    ia_err reInitIspAic();
    ia_err initAiq();
    void deinitAiq();
    void deleteSaResultsGrids();
    void copySaResults(const ia_aiq_sa_results_v1* saResult);
#ifdef ENABLE_DVS
    ia_err getDVSCfgFromGDCParam(const cca_gdc_configuration& GdcInputConfig,
                                 ia_dvs_configuration_v1& DVSConfig) const;
    ia_err initDVS(const cca_gdc_configuration& gdcConfig);
    void deInitDvs();
#endif
#ifdef ENABLE_LTM
    ia_err initLtm();
    void deInitLtm();
#endif
    ia_err initBcomp(ia_bcomp_dol_mode_t mode, float ratio);
    ia_err updateBcomp();
    void deinitBcomp();
    void runAIC_(uint64_t frameId, const cca_pal_input_params& params, cca_3a_plus_results* results);
    template<typename T, typename N>
    inline bool bitChecker(T bitmap, N bit) const{ return (bitmap & static_cast<T>(bit)) != 0U ? true : false; }

#ifndef PAC_ENABLE
    /*! Decode statistics from HW
    *
    * Parse and decode different statistics from HW including AE/AWB/DVS/HDR
    *
    * \param [in]  stats        binary to store the statistics binary from HW
    * \param [out] results      statistics type after parsing statistics
    *
    *
    * return ia_err_none in success. Errorcode on failure
    */
    ia_err decodeStats(const ia_binary_data &stats, ia_isp_bxt_statistics_query_results_t *results);
#endif

private:
    CCAStorage *mCCAStorage;

    /*
     * aiqb and cmc
     */
    ia_binary_data mAicb;
    ia_cmc_t* mParsedCMC;

    /*
     * NVM
     */
    ia_binary_data mNvmb;

    /*
     * aiqd
     */
    ia_binary_data mAiqd;

    /*
     * AIQ structs and params
     */
    ia_aiq* mAiqHandle;
    uint8_t mAECFrameDelay;
    uint64_t mFrameTimestamp;
    ia_aiq_pa_results_v1* mPaResults;
    ia_aiq_awb_results* mAwbResults;
    ia_aiq_ae_results* mAeResults;
    ia_aiq_af_results *mAfResults;
    ia_aiq_gbce_results* mGbceResults;
    ia_aiq_sa_results_v1 mSaResults;
    ia_aiq_sa_results_v1 mSaFakeResults;

    ia_aiq_frame_params mAiqFrameParams;

    ia_aiq_awb_input_params_v1 mAwbInput;
    ia_aiq_ae_input_params_v1 mAeInput;
    ia_aiq_af_input_params mAfInput;
    ia_aiq_sa_input_params_v1 mSaInput;
    ia_aiq_gbce_input_params mGbceInput;
    ia_aiq_pa_input_params mPaInput;

    uint64_t mFrameIndex;
    uint32_t mMaxNumberOfStats;
    ia_mkn* mMknData;
    uint32_t mInitBitmap;
    uint32_t mNumExpo;

    /*
     * RGBS grids
     */
    ia_aiq_grid** mCurrentIRGrid;

    /*
     * AIC structs and params
     */
    IIPUAic* mIspAicHandle;

    /*
    * LTM structs
    */
    ia_ltm_drc_params* mLtmDrcState;
    ia_ltm_results* mLtmResults;
    ia_ltm* mLtm;

    /*
    * DVS structs
    */
    ia_dvs_state *mDVSState;
    ia_dvs_morph_table* mDVSMorphingTableOutput;
    ia_dvs_image_transformation* mDVSImageTransformationOutput;
    ia_dvs_configuration_v1 mDVSConfig;
    bool mEnableVideoStablization;
    bool mEnableDVS;
    float mDvsZoomRatio;
    CCADVSOutputType mDvsOutputType;

    /*
    * Bcomp structs
    */
    ia_bcomp* mBcompState;
    ia_bcomp_results* mBcompResults;

    /*
    * ia_lard - a library for parsing the cpff and loading it in a dynamic way
    */
    ia_lard* mLard;
    cca_lard_data mLardData;

    /*
    * lard_result - the results which are returned after lard_run
    */
    ia_lard_results* mLardResult;

    /*
    * mEnableUsingLardResultToInitCCA - whether using lard result to init cca
    */
    bool mEnableUsingLardResultToInitCCA;
    char reserve[24];
};
}//cca
