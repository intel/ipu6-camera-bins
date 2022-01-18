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

/*!
 * \mainpage CCA Flow API documentation
 *
 * Browse Files and Classes tabs for details.
 *
 * \section general General info
 *
 * CCA Flow APIs have been designed to be re-entrant. Each algorithm function can be called multiple times per frame.
 * Input parameters for the algorithms define what is the output ie. running an algorithm with same input parameters
 * and same statistics produce the same output.
 *
 * CCA Flow (Camera Control Algorithms Flow) library contains several algorithm which are used to modify RAW image.
 * Currently following features and algorithms are supported:
 * - \ref aec (Automatic Exposure Control)
 * - \ref aiq (Algorithms and Image Quality Algorithm Group) including sub-algorithm
 *  - awb (Automatic White Balance)
 *  - af (Automatic Focus)
 *  - sa (Shading Adaptor)
 *  - pa (Parameter Adaptor)
 *  - gbce (Global Brightness and Contrast Enhancement)
 *
 * Running AIQ algorithms and other standalone algorithms (LTM/DVS) requires following steps:
 * - \ref init
 * - \ref stats
 * - \ref running
 * - \ref deinit
 *
 * Some AIQ algorithms require coordinates as inputs to specify a certain area in the image. Coordinates are relative to
 * the statistics thus not necessarily the whole sensor area. Coordinates are not absolute but relative. See \link ia_coordinate.h \endlink
 * for detailed description of the used coordinate system.
 * <br><hr><br>
 *
 * \section init Initialization of CCA Flow library
 *
 * \copybrief cca::IntelCCA::init
 * To create an instance of CCA Flow library one must call function:
 * \code cca::IntelCCA::init \endcode
 * \copydetails cca::IntelCCA::init
 *
 * <br><hr><br>
 *
 * \section stats Setting of frame statistics
 *
 * Algorithms depend on statistics collected from the RAW image. Some or all of the statistics are
 * calculated by the ISP after RAW image capture from camera sensor. These statistics are always collected from
 * captured image data.
 *
 * \copybrief setStatsParams
 * To set statistics for algorithms CCA Flow library, one must call function:
 * \code cca::IntelCCA::setStatsParams \endcode
 * \copydetails cca::IntelCCA::setStatsParams
 *
 * Algorithms can also utilize external sensor data for making better decisions. For example external light sensor
 * can be used by AEC to determine correct cold start exposure parameters when AEC is called the first time without
 * statistics.
 *
 * <br><hr><br>
 *
 * \section running Running AIQ/AEC/LTM/DVS/AIC algorithms
 *
 * Once the CCA Flow instance is initialized and statistics are set, algorithms can be run in any order. But AIC must be last one, because the algo shall
 * collect other algo results to generate the PAL for IPU HW.
 *
 * \subsection aiq AIQ
 * \copybrief cca::IntelCCA::runAIQ
 * \code cca::IntelCCA::runAIQ \endcode
 * \copydetails cca::IntelCCA::runAIQ
 *
 * \subsection aec AEC
 * \copybrief cca::IntelCCA::runAEC
 * \code cca::IntelCCA::runAEC \endcode
 * \copydetails cca::IntelCCA::runAEC
 *
 * \subsection ltm LTM
 * \copybrief cca::IntelCCA::runLTM
 * \code cca::IntelCCA::runLTM \endcode
 * \copydetails cca::IntelCCA::runLTM
 *
 * \subsection dvs DVS
 * \copybrief cca::IntelCCA::runDVS
 * \code cca::IntelCCA::runDVS \endcode
 * \copydetails cca::IntelCCA::runDVS
 *
 * \subsection aic AIC
 * \copybrief cca::IntelCCA::runAIC
 * \code cca::IntelCCA::runAIC \endcode
 * \copydetails cca::IntelCCA::runAIC
 *
 *
 * <br><hr><br>
 *
 * \section deinit De-initialization of CCA Flow library
 *
 * To de-initialize and free memory CCA Flow library instance has allocated, one must call function:
 * \code
 * cca::IntelCCA::deinit
 * \endcode
 *
 * After this call CCA Flow library instance is destroyed and can't be used.
 */

#ifndef INTELCCA_H_
#define INTELCCA_H_

#include "IntelCCATypes.h"
#include "IIPUAic.h"
#include "CCAStorage.h"

namespace cca {

/*!
 * \brief main entrance of CCA Flow lib.
 */
class IntelCCA {
public:
    IntelCCA();
    virtual ~IntelCCA();
    /*!
     * \brief initialize the CCA Flow and sub-algos.
     * This function must be called before any other function in the library. It allocates memories for all CCA Flow algorithms based on input parameters
     * given by the user. AIQB (from CPFF) and NVM data are parsed and combined resulting camera module specific tuning parameters which the
     * AIQ algorithms use. Initialization returns a handle to the CCA Flow instance, which is given as input parameter for all the
     * algorithms. Therefore, multiple instances of CCA Flow library can running simultaneously. For example one instance per camera.
     *
     * \param[in] initParams            Mandatory.\n
     *                                  Input parameters containing tuning/nvm and configuration for sub-algos.
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err init(const cca_init_params& initParams);

    /*!
     * \brief Set input statistics and information (e.g faces) about the captured image.
     * CCA Flow algorithms need various information about the conditions in which the frame and statistics were captured in order to
     * calculate new parameters.
     *
     * \param[in] params                Mandatory.\n
     *                                  Input parameters containing statistics information about a frame.
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err setStatsParams(const cca_stats_params& params);

    /*!
     * \brief AEC calculation based on input parameters and frame statistics.
     * AE calculates new exposure parameters to be used for the next frame based on previously given statistics and user parameters.
     *
     * \param[in] frameId               Mandatory.\n
     *                                  frame sequence Id.
     * \param[in] params                Mandatory.\n
     *                                  Input parameters for AEC calculations.
     * \param[out] results              Mandatory.\n
     *                                  Results from AEC calculations. Results can be used directly as input for AIC/sensor driver.
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err runAEC(uint64_t frameId, const cca_ae_input_params& params, cca_ae_results *results);
    /*!
     * \brief Run AIQ (Algorithms and Image Quality) Algorithm Group about the captured image.
     * AIQ algorithms need various information about the conditions in which the frame and statistics were captured in order to
     * calculate new parameters.
     *
     * \param[in] frameId               Mandatory.\n
     *                                  run AIQ algo group for frame with frameId.
     * \param[in] params                Mandatory.\n
     *                                  Input parameters containing statistics information about a frame.
     * \param [out] results             Mandatory.\n
     *                                  AIQ results. AF results can be used by ACM driver.
     * \return                          Error code.
     */
    ia_err runAIQ(uint64_t frameId, const cca_aiq_params& params, cca_aiq_results *results);
#ifndef PAC_ENABLE
#ifdef ENABLE_LTM
    /*!
     * \brief LTM Algorithm calculation based on input parameters including sis statistics.
     * LTM calculates the tone mapping curve for each block that used by AIC to interpolate LUT.
     *
     * \param[in] frameId               Mandatory.\n
     *                                  frame sequence Id.
     * \param[in] params                Mandatory.\n
     *                                  Input parameters for LTM.
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err runLTM(uint64_t frameId, const cca_ltm_input_params& params);
#endif

#ifdef ENABLE_DVS
    /*!
     * \brief update zoom factor/region/coordinate.
     * DVS algo supports to zoom the image. Set the zoom params before calling runDVS.
     *
     * \param[in] params                Mandatory.\n
     *                                  zoom related params.
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err updateZoom(const cca_dvs_zoom& params);
    /*!
     * \brief DVS Algorithm calculation based on dvs statistics.
     * DVS uses frameId to search the DVS statistic that decoded and stored in CCA Flow,
     * then calculates the morph table or image transformation for whole image that used by GDC.
     *
     * \param[in] frameId               Mandatory.\n
     *                                  frame sequence Id.
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err runDVS(uint64_t frameId) const;
#endif
#endif
    /*!
     * \brief query the CMC data (camera module characteristic).
     * get the sensor specific data that stored in tuning file, for example optics/tnr...
     *
     * \param[out] cmc                  Mandatory.\n
     *                                  CMC data.
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err getCMC(cca_cmc &cmc);

    /*!
     * \brief query the MKN data (maker notes).
     * get the maker note data of AIQ generated by algorithms, mainly cover the exif info needs
     * by JPG and other data for debug purpose.
     *
     * \param[in] type                  Mandatory.\n
     *                                  mkn type.
     * \param[out] mkn                  Mandatory.\n
     *                                  mkn data.
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err getMKN(ia_mkn_trg type, cca_mkn &mkn);
    /*!
     * \brief get the AIQD (AIQ data).
     *  Contains various AIQ related information, collected during run-time and subject to
     *  be stored in a host file system. Host will copy this data, if ia_aiq_data->size > 0
     *  and ia_aiq_data->data != NULL; AIQ is responsible to deallocate data buffer
     *  during ia_aiq_deinit().
     *
     * \param[out] aiqd                 Mandatory.\n
     *                                  AIQD buffer.
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err getAiqd(cca_aiqd &aiqd);
    /*!
     * \brief Update tuning data in run time.
     *  Update the tuning data to CCA flow, the new tuning data will be taken effect immediately.
     *  For different use cases, the tuning data should be different, the function is used for the scenario.
     *
     * \param[in] tag                   Mandatory.\n
     *                                  the tag for updated group in tuning file.
     * \param[in] lardParams            Mandatory.\n
     *                                  lard data.
     * \param[in] nvm                   Mandatory.\n
     *                                  sensor nvm data.
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err updateTuning(uint8_t tag, const ia_lard_input_params &lardParams, const cca_nvm &nvm);

    /*!
     * \brief Update tuning data in run time.
     *  Update the tuning data to CCA flow, the new tuning data will be taken effect immediately.
     *  For different use cases, the tuning data should be different, the function is used for the scenario.
     *
     * \param[in] tag                   Mandatory.\n
     *                                  the tag for updated group in tuning file.
     * \param[in] lardParams            Mandatory.\n
     *                                  lard data.
     * \param[in] nvm                   Mandatory.\n
     *                                  sensor nvm data.
     * \param[out] pLardResults         Mandatory.\n
     *                                  lard results
     * \param[out] bSupportLard         Mandatory.\n
     *                                  indicate if lard is supported
     * \return                          Error code for status. zero on success, non-zero on failure
    */
    ia_err updateTuning(uint8_t tag, const ia_lard_input_params &lardParams, const cca_nvm &nvm, ia_lard_results **pLardResults);

    /*!
     * \brief De-initialize CCA Flow and its submodules.
     * All memory allocated by algoriths are freed. CCA Flow handle can no longer be used.
     *
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err deinit();

    /*!
     * \brief query the current CCA Flow version.
     *
     * \return                          version.
     */
    const char* getVersion() const;

    /*!
     * \brief Get lard data.
     *  Get lard results parsed from aiqb.
     *
     * \param[out] lard                 Mandatory.\n
     *                                  lard data
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err getLardData(cca_lard_data *lard);

#ifdef PAC_ENABLE
    /*!
    *
    * \brief configure the kernels of pipeline, register all kernel's offset, and return the terminal
    *  number and payload size
    *
    * \param [in]  conf         kernel list for the pipeline
    * \param [in]  offset       kernel offsets
    * \param [out] termConfig   terminal payload number and size
    *
    * \return                   Error code for status. zero on success, non-zero on failure
    */
    ia_err configAIC(const cca_aic_config &conf, const cca_aic_kernel_offset &offset, cca_aic_terminal_config &termConfig);
    /*!
    *
    * \brief register payload buffers to AIC
    * \param [out] termConfig   terminal payload
    *
    * \return                   Error code for status. zero on success, non-zero on failure
    */
    ia_err registerAICBuf(const cca_aic_terminal_config &termConfig);
    /*!
    *
    * \brief query the PAL buffer filled by kernel parameters calculated by AIC
    * \param [out] termConfig   terminal payload
    *
    * \return                   Error code for status. zero on success, non-zero on failure
    */
    ia_err getAICBuf(cca_aic_terminal_config &termConfig);
    /*!
    *
    * \brief Decode statistics from HW.
    * Parse and decode different statistics from HW including AE/AWB/DVS/HDR
    *
    * \param [in]  groupId      statistics binary generated by CB (groupId)
    * \param [in]  seqId        statistics sequence number
    *
    * \return                   Error code for status. zero on success, non-zero on failure
    */
    ia_err decodeStats(int32_t groupId, int64_t seqId);

    /*!
    *
    * \brief  run AIC to get PAL binary for IPU7 HW.
    *  Calculate the PAL parameters according to 3A+ results and manual settings
    *
    * \param [in]  frameId      indicate PAL results for specia frame
    * \param [in]  params       manual settings for IPU pipeline
    * \param [out] output       binary array of IPU parameters for each CB
    *
    * \return                   Error code for status. zero on success, non-zero on failure
    */
    ia_err runAIC (uint64_t frameId, const cca_pal_input_params& params, cca_multi_pal_output& output);
#else
    /*!
    *
    * \brief Decode statistics from HW.
    * Parse and decode different statistics from HW including AE/AWB/DVS/HDR
    *
    * \param [in]  stats        statistics binary from HW
    * \param [in]  bitmap       select RGBS, HIST, AF ... if needed to decode
    * \param [out] results      statistics type after parsing statistics
    * \param [out] outStats     output stats
    *
    * \return                   Error code for status. zero on success, non-zero on failure
    */
    ia_err decodeStats(const cca_stats_bin &stats, uint32_t bitmap, ia_isp_bxt_statistics_query_results_t *results, cca_out_stats *outStats = nullptr);

    /*!
    *
    * \brief Decode statistics from HW.
    * Parse and decode different statistics from HW including AE/AWB/DVS/HDR
    *
    * \param [in]  statsPointer pointer to share memory that stores the statistics binary from HW
    * \param [in]  statsSize    statistics size
    * \param [in]  bitmap       select RGBS, HIST, AF ... if needed to decode
    * \param [out] results      statistics type after parsing statistics
    * \param [out] outStats     output stats
    *
    * \return                   Error code for status. zero on success, non-zero on failure
    */
    ia_err decodeStats(uint64_t statsPointer, uint32_t statsSize, uint32_t bitmap, ia_isp_bxt_statistics_query_results_t *results, cca_out_stats *outStats = nullptr);

    /*!
    *
    * \brief  Get PAL binary size.
    *  Calculate the PAL size according to program group
    *
    * \param [in]  programGroup kernel info for special stream id
    *
    * \return Pal size in success. zero on failure
    */
    uint32_t getPalSize(const cca_program_group &programGroup);

    /*!
    *
    * \brief run AIC to get PAL binary for IPU HW.
    *  Calculate the parameters for each IPU kernel according to 3A+ results and manual settings.
    *
    * \param [in]  frameId      indicate PAL results for specia frame
    * \param [in]  params       manual settings for IPU pipeline
    * \param [out] pal          binary of IPU parameters for IPU HW
    *
    * \return                   Error code for status. zero on success, non-zero on failure
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
#ifndef PAC_ENABLE
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
#endif
    ia_err initBcomp(ia_bcomp_dol_mode_t mode, float32_t ratio);
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
    * \param [in]  bitmap       select RGBS, HIST, AF ... if needed to decode
    * \param [out] results      statistics type after parsing statistics
    * \param [out] outStats     output stats
    *
    * return ia_err_none in success. Errorcode on failure
    */
    ia_err decodeStats(const ia_binary_data &stats, uint32_t bitmap, ia_isp_bxt_statistics_query_results_t *results, cca_out_stats *outStats);
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
    bool mCCAIsEnabled;
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
    float32_t mDvsZoomRatio;
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
    int8_t reserve[24];
};
}//cca
#endif //INTELCCA_H_
