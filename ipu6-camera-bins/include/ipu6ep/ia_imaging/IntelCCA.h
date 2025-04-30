/*
 * Copyright (C) 2019-2023 Intel Corporation.
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

class IntelDVS;

/*!
 * \brief main entrance of CCA Flow lib.
 */
class LIBEXPORT IntelCCA {
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
     * \brief reconfigure dol.
     *
     * \param[in] dolMode               Mandatory.\n
     * \param[in] conversionGainRatio   Mandatory.\n
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err reconfigDol(ia_bcomp_dol_mode_t dolMode, float32_t conversionGainRatio);

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
     * \brief Set Sensor frame parameters. Describe frame scaling/cropping done in sensor.
     *
     * \param[in] frameParams           Mandatory.\n
     *
     */
    void   setAiqFrameParams(const ia_aiq_frame_params &frameParams);

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
     * \brief reconfigure DVS configuration info when GDC configuration are changed.
     *
     * \param[in] dvsInitParam          Mandatory.\n
     * \param[in] gdcConfig             Mandatory.\n
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err reconfigDvs(const cca_dvs_init_param& dvsInitParam, const cca_gdc_configurations& gdcConfigs);
    /*!
     * \brief update zoom factor/region/coordinate.
     * DVS algo supports to zoom the image. Set the zoom params before calling runDVS.
     *
     * \param[in] DvsId                 Mandatory.\n
     * \param[in] params                Mandatory.\n
     *                                  zoom related params.
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err updateZoom(uint32_t DvsId, const cca_dvs_zoom& params);
    /*!
     * \brief DVS Algorithm calculation based on dvs statistics.
     * DVS uses frameId to search the DVS statistic that decoded and stored in CCA Flow,
     * then calculates the morph table or image transformation for whole image that used by GDC.
     *
     * \param[in] streamsId             Mandatory.\n
     * \param[in] frameId               Mandatory.\n
     *                                  frame sequence Id.
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err runDVS(uint32_t DvsId, uint64_t frameId, bool enable_video_stablization = false);
    /*!
     * \need reconfigDvs params with usecase(zoom/digitial zoom/video stablization) changing.
     * driver update all related paramter, then call the interface.
     *
     *
     * \param[in] DvsId                 Mandatory.\n
     * \param[in] dvs_config            Mandatory.\n
     * \param[in] zoom_factor           Mandatory.\n
     *                                  dvs config params.
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err ConfigDvs(uint32_t DvsId, ia_dvs_configuration_v1* dvs_config, float32_t zoom_factor);
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
    ia_err getCMC(cca_cmc &cmc, const cca_cpf *aiq_cpf = nullptr);

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
     * \brief add MKN data
     *
     * \param[in] a_data_format_id      Mandatory.\n
     *                                  mkn format id
     * \param[in] a_data_name_id        Mandatory.\n
     *                                  mkn data name id
     * \param[in] a_data_ptr            Mandatory.\n
     *                                  pointer to data
     * \param[in] a_num_elements        Mandatory.\n
     *                                  element number
     * \param[in] a_key                 Mandatory.\n
     */
    ia_err addMKN(ia_mkn_dfid a_data_format_id, ia_mkn_dnid a_data_name_id, const void *a_data_ptr, uint32_t a_num_elements, const char *a_key);

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
     * \param[in] aicId                 Optional.\n
     *                                  the aic id for aic handle
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err updateTuning(uint8_t tag, const ia_lard_input_params &lardParams, const cca_nvm &nvm, int32_t aicId = -1);

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
     * \param[in] aicId                 Optional.\n
     *                                  the stream id for aic handle
     * \return                          Error code for status. zero on success, non-zero on failure
    */
    ia_err updateTuning(uint8_t tag, const ia_lard_input_params &lardParams, const cca_nvm &nvm, ia_lard_results **pLardResults, int32_t aicId = -1);

    /*!
     * \brief parse embedded data in run time.
     *
     * \param[in] bin                       Mandatory.\n
     *                                      embedded data
     * \param[in] mode                      Mandatory.\n
     *
     * \param[in] SnrDesc                   Mandatory.\n
     *                                      Sensor specific descriptor and limits of the used sensor mode for target frame use.
     * \param[out] result                   Mandatory.\n
     *                                      embedded results
     * \return                              Error code for status. zero on success, non-zero on failure
     */
    ia_err runEmdDecoder(const ia_binary_data &bin, const ia_emd_mode_t &mode, const ia_aiq_exposure_sensor_descriptor &snrDesc, ia_emd_result_t **result);

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

    /*!
    * \brief Get Aiq results.
    *  Get Aiq results parsed from CCAStorage.
    *
    * \param[in] frameId               Mandatory.\n
    *                                  Get Aiq result for frame with frameId.
    * \param[out] results              Mandatory.\n
    *                                  Aiq results
    * \return                          Error code for status. zero on success, non-zero on failure
    */
    ia_err queryAiqResults(uint64_t frameId, cca_aiq_results_storage* results);

    /*!
    * \brief Save Aiq results.
    *  Save Aiq results to internal CCAStorage.
    *
    * \param[out] results              Mandatory.\n
    *                                  Aiq results
    * \return                          Error code for status. zero on success, non-zero on failure
    */
    ia_err saveAiqResults(uint64_t frameId, const cca_aiq_results_storage &results);

#ifdef PAC_ENABLE
    /*!
    *
    * \brief configure the kernels of pipeline, register all kernel's offset, and return the terminal
    *  number and payload size
    *
    * \param [in]  conf         kernel list for the pipeline
    * \param [in]  offset       kernel offsets
    * \param [out] termConfig   terminal payload number and size
    * \param [in]  aicId        (Optional)The id for aic handle
    *
    * \return                   Error code for status. zero on success, non-zero on failure
    */
    ia_err configAIC(const cca_aic_config &conf, const cca_aic_kernel_offset &offset,
                     cca_aic_terminal_config &termConfig, int32_t aicId = -1);
    /*!
    *
    * \brief register payload buffers to AIC
    * \param [out] termConfig   terminal payload
    * \param [in]  aicId        (Optional)The id for aic handle
    *
    * \return                   Error code for status. zero on success, non-zero on failure
    */
    ia_err registerAICBuf(const cca_aic_terminal_config &termConfig, int32_t aicId = -1);
    /*!
    *
    * \brief query the PAL buffer filled by kernel parameters calculated by AIC
    * \param [out] termConfig   terminal payload
    * \param [in]  aicId        (Optional)The id for aic handle
    *
    * \return                   Error code for status. zero on success, non-zero on failure
    */
    ia_err getAICBuf(cca_aic_terminal_config &termConfig, int32_t aicId = -1);
    /*!
    *
    * \brief Decode statistics from HW.
    * Parse and decode different statistics from HW including AE/AWB/DVS/HDR
    *
    * \param [in]  groupId      statistics binary generated by CB (groupId)
    * \param [in]  seqId        statistics sequence number
    * \param [in]  aicId        (Optional)The id for aic handle
    *
    * \return                   Error code for status. zero on success, non-zero on failure
    */
    ia_err decodeStats(int32_t groupId, int64_t seqId, int32_t aicId = -1);

    /*!
    *
    * \brief  run AIC to get PAL binary for IPU7 HW.
    *  Calculate the PAL parameters according to 3A+ results and manual settings
    *
    * \param [in]  frameId      indicate PAL results for specia frame
    * \param [in]  params       manual settings for IPU pipeline
    * \param [in]  bitmap       bitmap to decide which CB will be run
    * \param [out] output       binary array of IPU parameters for each CB
    * \param [in]  aicId        (Optional)The id for aic handle
    *
    * \return                   Error code for status. zero on success, non-zero on failure
    */
    ia_err runAIC (uint64_t frameId, const cca_pal_input_params& params,
                   cca_multi_pal_output& output, uint8_t bitmap = UINT8_MAX, int32_t aicId = -1);

    static  uint32_t getPacOutputSize(const cca_program_group& programGroup);
    ia_err updateConfigurationResolutions(const cca_aic_config& conf, int32_t aicId, bool isKeyResolutionChanged);

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
    ia_err decodeStats(uint64_t statsPointer, uint32_t statsSize, uint32_t bitmap, ia_isp_bxt_statistics_query_results_t *results,
                        cca_out_stats *outStats = nullptr);

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
    * \param[in] aicId          Optional.\n
    *                           id for aic handle.
    * \return                   Error code for status. zero on success, non-zero on failure
    */
    ia_err runAIC (uint64_t frameId,
               const cca_pal_input_params& params,
               ia_binary_data* pal, int32_t aicId = -1);
#endif

    /*!
    * \brief get the max bin index of non-zero element
    *  from the AE histogram.
    *
    * \param[out] stats                 Mandatory.\n
    *                                   output the max bin.
    * \return                           Error code.
    */
    ia_err getBrightestIndex(uint32_t *outMaxBin);

    /*!
     * \brief calc the total pixel number in range [luminance_low, luminance_high]
     *
     * \param[in] luminance_low          Mandatory.\n
     *                                   the low pixel value
     *
     * \param[in] luminance_high         Mandatory.\n
     *                                   the high pixel value
     *
     * \param[out] outTotalPixels        Mandatory.\n
     *                                   the total pixel number in range [luminance_low, luminance_high]
     *
     * \return                           Error code.
     */
    ia_err getPixelCount(uint32_t luminance_low, uint32_t luminance_high, uint32_t *outTotalPixels);

private:
    ia_binary_data* getAiqData();
    ia_binary_data* getIspData();
    ia_binary_data* getOthersData();
    ia_err initCpfParse();
    void initSaResults();
    ia_err initIspAic(const cca_stream_ids& aic_stream_ids);
    void deInitIspAic();
    ia_err reInitIspAic(const cca_stream_ids& aic_stream_ids);
    ia_err initAiq();
    void deinitAiq();
    void deleteSaResultsGrids();
    void copySaResults(const ia_aiq_sa_results_v1* saResult);
#ifndef PAC_ENABLE
#ifdef ENABLE_DVS
    ia_err initDVS(const cca_init_params& initParams);
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
    bool mAicbInited;

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
    uint64_t mLastRunSaFrameIndex;
    uint32_t mMaxNumberOfStats;
    ia_mkn* mMknData;
    uint32_t mInitBitmap;
    cca_stream_ids mAicStreamIds;
    std::map<int32_t, uint32_t> mAicTuningModeMap;
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
    * Bcomp structs
    */
    ia_bcomp* mBcompState;
    ia_bcomp_results* mBcompResults;
    ia_bcomp_dol_mode_t mDolMode;
    float32_t mDolRatio;

    /*
    * ia_lard - a library for parsing the cpff and loading it in a dynamic way
    */
    ia_lard* mLard;
    cca_lard_data mLardData;

    /*
    * lard_result - the results which are returned after lard_run
    */
    ia_lard_results* mLardResult;

#ifdef ENABLE_DVS
    IntelDVS* mIntelDVSHandles;
#endif

    ia_emd_decoder_t *mEmdDecoder;

    /*
    * mEnableUsingLardResultToInitCCA - whether using lard result to init cca
    */
    bool mEnableUsingLardResultToInitCCA;
    int8_t reserve[24];
};
}//cca
#endif //INTELCCA_H_
