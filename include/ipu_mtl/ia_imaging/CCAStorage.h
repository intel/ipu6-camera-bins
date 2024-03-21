/*
 * Copyright (C) 2020-2024 Intel Corporation.
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
#ifndef CCASTORAGE_H_
#define CCASTORAGE_H_

#include "ia_abstraction.h"
#include "IntelCCATypes.h"
#include "CCAMacro.h"

#ifndef ENABLE_CUSTOMIZED_STD_LIB
#include <map>
#include <list>
#else
#include "FixedMap.h"
#include "FixedList.h"
#endif

namespace cca {

/*!
 * \brief aiq results structure used in CCAStorage
 */
typedef struct {
    //aec results
    ia_aiq_ae_exposure_result exposure_results[MAX_NUM_EXPOSURE];
    ia_aiq_aperture_control   aperture_control;
    ia_aiq_hist_weight_grid   weight_grid;
    uint8_t weights[MAX_WEIGHT_GRID_SIZE];
    ia_aiq_flash_parameters   flashes[MAX_NUM_FLASH_LEDS];
    ia_aiq_exposure_parameters        generic_exposure[MAX_NUM_EXPOSURE * MAX_EXPO_PLAN];
    ia_aiq_exposure_sensor_parameters sensor_exposure[MAX_NUM_EXPOSURE * MAX_EXPO_PLAN];

    //gbce results
    float32_t r_gamma_lut[MAX_GAMMA_LUT_SIZE];
    float32_t g_gamma_lut[MAX_GAMMA_LUT_SIZE];
    float32_t b_gamma_lut[MAX_GAMMA_LUT_SIZE];
    float32_t tone_map_lut[MAX_TONE_MAP_LUT_SIZE];

    //pa results
    ia_aiq_advanced_ccm_t preferred_acm;
    uint32_t hue_sectors[MAX_NUM_SECTORS];
    float32_t ACM[MAX_NUM_SECTORS][3][3];
    ia_aiq_ir_weight_t ir_weight;
    uint16_t ir_weight_r[MAX_IR_WEIGHT_GRID_SIZE];
    uint16_t ir_weight_g[MAX_IR_WEIGHT_GRID_SIZE];
    uint16_t ir_weight_b[MAX_IR_WEIGHT_GRID_SIZE];
    ia_aiq_rgbir_t rgbir;
    ia_aiq_rgbir_model_t models[MAX_RGBIR_MODELS];
    /*LDRA_INSPECTED 67 X */
    ia_aiq_pa_results_v1 pa_results;
    ia_aiq_awb_results awb_results;
    ia_aiq_ae_results aec_results;
    /*LDRA_INSPECTED 67 X */
    ia_aiq_gbce_results gbce_results;
    /*LDRA_INSPECTED 67 X */
    ia_aiq_sa_results_v1 sa_results;
    uint32_t result_bitmap;
} aiq_results;

/*!
 * \brief storage for aiq results
 */
struct cca_aiq_results_storage {
    aiq_results* aiq_results_ptr;
    ia_aiq_pa_results_v1* pa_results;
    ia_aiq_awb_results* awb_results;
    ia_aiq_ae_results* aec_results;
    ia_aiq_af_results* af_results;
    ia_aiq_gbce_results* gbce_results;
    ia_aiq_sa_results_v1 *sa_results;
    uint32_t *aiq_results_bitmap;
    cca_aiq_results_storage() :
        aiq_results_ptr(nullptr),
        pa_results(nullptr),
        awb_results(nullptr),
        aec_results(nullptr),
        af_results(nullptr),
        gbce_results(nullptr),
        sa_results(nullptr),
        aiq_results_bitmap(nullptr)
        {}
};

/*!
 * \brief interface exposed to IntelCCA for AIQ algorithm result storage.
 */
class CCAStorage {
public:
    explicit CCAStorage(uint8_t len);
    ia_err saveAiqResults(uint64_t frameId, const cca_aiq_results_storage& results);
    ia_err queryAiqResults(uint64_t frameId, cca_aiq_results_storage* results);
    virtual ~CCAStorage();

private:
    ia_err createAiqResult();
    void deleteAiqResult();
    ia_err resetAiqResult(aiq_results* results, CCAModuleBitMap bitmap) const;

    ia_err initAiqResultEle(aiq_results *aiqResults) const;

    ia_err queryColdStartResults(cca_aiq_results_storage *results);

#ifndef ENABLE_CUSTOMIZED_STD_LIB
    std::map<uint64_t, cca_aiq_results_storage> mAiqResultsMap;
    std::list<uint64_t> mFrameIdList;
#else
    static const uint8_t kAiqResultsMapCap = 5U;
    FixedMap<uint64_t, cca_aiq_results_storage, kAiqResultsMapCap> mAiqResultsMap;
    FixedList<uint64_t, kAiqResultsMapCap> mFrameIdList;
#endif

    uint8_t mStorageLen;
    mutex_t mStorageMutex;
    aiq_results *mAiqResults;
    aiq_results mColdStartAiqResults;
};
}//cca
#endif //CCASTORAGE_H_
