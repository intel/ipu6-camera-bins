/*
 * Copyright (C) 2021 Intel Corporation.
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

#ifndef CCAMACRO_H_
#define CCAMACRO_H_

#include <stdint.h>

namespace cca {

/*
 * TODO:
 * This config file should be generated automatically to support different
 * platforms or products, because the below defintions should depend on
 * sensor, IPU, etc.
 */
const uint32_t MAX_CAM_NUM = 4U;
const uint32_t MAX_CPF_LEN = 1024 * 1024 * 4;
const uint32_t MAX_NVM_LEN = 1024 * 16;
const uint32_t MAX_AIQD_LEN = 1024 * 1024;
const uint32_t MAX_MKN_LEN = 64 * 1024;
const uint32_t MAX_MKN_SECTION_SIZE = 100000;
const uint32_t MAX_CMC_LEN = 1024 * 1024;
const uint32_t MAX_TAG_LIST_LEN = 8;
const uint32_t DEFAULT_FPS = 30;
const uint32_t MAX_NUM_EXPOSURE = 4;
const uint32_t MAX_NUM_STATS = 2;
const uint32_t MAX_NUM_AF_STATS = 1;
const uint32_t MAX_SENSOR = 2;
const uint32_t MAX_EXPO_PLAN = 4;
const uint32_t MAX_NUM_FLASH_LEDS = 1;
const uint32_t MAX_BAYER_ORDER_NUM = 4;
const uint32_t MAX_DVS_VECTOR_COUNT = 100 * 100;
const uint32_t MAX_SIS_FRAME_SIZE = 500 * 500 * 4;
const uint32_t MAX_PAL_TUNING_SIZE = 1024 * 1024;
const uint32_t MAX_CUSTOM_CONTROLS_PARAM_SIZE = 128;
const uint32_t MAX_KERNEL_NUMBERS_IN_PIPE = 128;
const uint32_t MAX_AF_GRID_WIDTH = 128;
const uint32_t MAX_AF_GRID_HEIGHT = 128;
const uint32_t MAX_WEIGHT_GRID_SIZE = 64 * 64;
const uint32_t MAX_AF_STATS_GRID_SIZE (MAX_AF_GRID_WIDTH * MAX_AF_GRID_HEIGHT);
const uint32_t MAX_GRBS_GRID_WIDTH = 150;
const uint32_t MAX_GRBS_GRID_HEIGHT = 150;
const uint32_t MAX_RGBS_STATS_GRID_SIZE (MAX_GRBS_GRID_WIDTH * MAX_GRBS_GRID_HEIGHT);
const uint32_t MAX_STATS_LEN = 1024 * 1024;
const uint32_t MAX_FACE_NUM = 32;
const uint32_t MAX_LSC_DIM  = 4;
const uint32_t MAX_LSC_DIM_SIZE = 4;
const uint32_t MAX_LSC_GRID_SIZE = 128 * 128;
const uint32_t MAX_GAMMA_LUT_SIZE = 2048;
const uint32_t MAX_TONE_MAP_LUT_SIZE = 2048;
const uint32_t MAX_NUM_SECTORS = 36;
const uint32_t MAX_IR_WEIGHT_GRID_SIZE = 480;

const uint32_t GDC_Y_BLOCK_WIDTH = 64;
const uint32_t GDC_UV_BLOCK_WIDTH = 64;
const uint32_t GDC_Y_BLOCK_HEIGHT = 32;
const uint32_t GDC_UV_BLOCK_HEIGHT = 16;
const uint32_t GDC_SPLIT_METADATA_LEN = 4;
const float GDC_CLIP_MAX_ANGLE = 3.5f;

const uint32_t MAX_KERNEL_NUM_IN_PG = 128;
const uint32_t MAX_PG_NUM = 5;
const uint32_t MAX_PG_TERMINAL_NUM = 16;

const uint64_t INVALID_FRAME_ID = static_cast<uint64_t>(-1);
}//cca
#endif //CCAMACRO_H_