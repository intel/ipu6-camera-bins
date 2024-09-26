
/*
* INTEL CONFIDENTIAL
* Copyright (c) 2023 Intel Corporation
* All Rights Reserved.
*
* The source code contained or described herein and all documents related to
* the source code (Material) are owned by Intel Corporation or its
* suppliers or licensors. Title to the Material remains with Intel
* Corporation or its suppliers and licensors. The Material may contain trade
* secrets and proprietary and confidential information of Intel Corporation
* and its suppliers and licensors, and is protected by worldwide copyright
* and trade secret laws and treaty provisions. No part of the Material may be
* used, copied, reproduced, modified, published, uploaded, posted,
* transmitted, distributed, or disclosed in any way without Intel's prior
* express written permission.
*
* No license under any patent, copyright, trade secret or other intellectual
* property right is granted to or conferred upon you by disclosure or
* delivery of the Materials, either expressly, by implication, inducement,
* estoppel or otherwise. Any license under such intellectual property rights
* must be express and approved by Intel in writing.
*
* Unless otherwise agreed by Intel in writing, you may not remove or alter
* this notice or any other notice embedded in Materials by Intel or Intel's
* suppliers or licensors in any way.
*/

#ifndef IA_PAL_TYPES_ISP_PARAMETERS_AUTOGEN_H
#define IA_PAL_TYPES_ISP_PARAMETERS_AUTOGEN_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"{
#endif


/*! \isp struct acm_1_1

*/
typedef struct
{
    /*!< bypass Block bypass for HW use*/
    int32_t bypass;
    /*!< enable_chroma_lut Enable Chroma adaptation by LUT*/
    int32_t enable_chroma_lut;
    /*!< enable_luma_lut Enable Luma adaptation by LUT*/
    int32_t enable_luma_lut;
    /*!< enable_negative_pixels enable negative pixels in output*/
    int32_t enable_negative_pixels;
    /*!< enable_chroma_low_light_mode Enable Chroma adaptation in low light mode*/
    int32_t enable_chroma_low_light_mode;
    /*!< enable_luma_low_light_mode Enable Luma adaptation in low light mode*/
    int32_t enable_luma_low_light_mode;
    /*!< num_of_sectors number of sectors, U5.0*/
    int32_t num_of_sectors;
    /*!< chromagrid2uniformlut_cu_x[9] U12.0*/
    int32_t chromagrid2uniformlut_cu_x[9];
    /*!< chromagrid2uniformlut_cu_a[8] S4.10*/
    int32_t chromagrid2uniformlut_cu_a[8];
    /*!< lumagrid2uniformlut_cu_x[9] U12.0*/
    int32_t lumagrid2uniformlut_cu_x[9];
    /*!< lumagrid2uniformlut_cu_a[8] S4.10*/
    int32_t lumagrid2uniformlut_cu_a[8];
    /*!< ccm_matrix_arr[216] CCM's table (one per sector), S3.11*/
    int32_t ccm_matrix_arr[216];
    /*!< hue_boundary_arr[24] Table of sectors boundaries, U11.0*/
    int32_t hue_boundary_arr[24];
    /*!< ccm_index_arr[25] Table of the sectors indices, U5.0*/
    int32_t ccm_index_arr[25];
    /*!< offr CCM bias for R, S13.0*/
    int32_t offr;
    /*!< offg CCM bias for G, S13.0*/
    int32_t offg;
    /*!< offb CCM bias for B, S13.0*/
    int32_t offb;
    /*!< luma_coeff_arr[3] Luna coefficients (weights), U0.8*/
    int32_t luma_coeff_arr[3];
    /*!< adapt_chroma_lut[81] Chroma adaptation LUT, U2.7*/
    int32_t adapt_chroma_lut[81];
    /*!< adapt_luma_lut[81] Luma adaptation LUT, S13.0*/
    int32_t adapt_luma_lut[81];
    /*!< enable_low_light_mode Enable CC's adaptation low light mode*/
    int32_t enable_low_light_mode;
    /*!< enable_compand enable for the (de)companding*/
    int32_t enable_compand;
    /*!< cu_compression_x[13] U.24 linear, default log-limited*/
    int32_t cu_compression_x[13];
    /*!< cu_compression_y[12] U.15 companded output*/
    int32_t cu_compression_y[12];
    /*!< cu_compression_slope[12] U1.14 15bit slopes for companding*/
    int32_t cu_compression_slope[12];
    /*!< cu_decompression_x[13] U.15 companded input, default log-limited*/
    int32_t cu_decompression_x[13];
    /*!< cu_decompression_y[12] U.24 linear*/
    int32_t cu_decompression_y[12];
    /*!< cu_decompression_slope[12] U20.6 26bit slopes for decompanding*/
    int32_t cu_decompression_slope[12];
    /*!< linear_pedestal Pedestal subtracted (and added later) in linear domain, U.24*/
    int32_t linear_pedestal;
    /*!< use_pedestal If true, pedestal is used and the companded signal should be U15. If false, linear_pedestal should be 0*/
    int32_t use_pedestal;

} ia_pal_isp_acm_1_1_t;

/*! \isp struct aestatistics_2_0
AE Statistics (histogram)
*/
typedef struct
{
    /*!< cell0[96] weighted histogram grid values*/
    int32_t cell0[96];
    /*!< cell1[96] weighted histogram grid values*/
    int32_t cell1[96];
    /*!< cell2[96] weighted histogram grid values*/
    int32_t cell2[96];
    /*!< cell3[96] weighted histogram grid values*/
    int32_t cell3[96];
    /*!< cell4[96] weighted histogram grid values*/
    int32_t cell4[96];
    /*!< cell5[96] weighted histogram grid values*/
    int32_t cell5[96];
    /*!< cell6[96] weighted histogram grid values*/
    int32_t cell6[96];
    /*!< cell7[96] weighted histogram grid values*/
    int32_t cell7[96];
    /*!< grid_width represents number of horizontal grid cells*/
    int32_t grid_width;
    /*!< grid_height represents number of vertical grid cells*/
    int32_t grid_height;
    /*!< block_width Log2 the width of each grid cell (8,16,32,64,128, 256)*/
    int32_t block_width;
    /*!< block_height Log2 the height of each grid cell (8,16,32,64,128, 256)*/
    int32_t block_height;
    /*!< ae_en 0: FF will not write to the AE  array; 1: FF will write*/
    int32_t ae_en;
    /*!< rst_hist_array 1: triggers the reset mechanism for the GLB_HIST*/
    int32_t rst_hist_array;
    /*!< x_start X top left corner of the grid*/
    int32_t x_start;
    /*!< y_start Y top left corner of the grid*/
    int32_t y_start;
    /*!< x_end X bottom right corner of the grid*/
    int32_t x_end;
    /*!< y_end Y bottom right corner of the grid*/
    int32_t y_end;
    /*!< sensor_mode 0: 1x1 CFA (array sensor); 1: 2 x 2 CFA; 2: 4 x 4 CFA*/
    int32_t sensor_mode;
    /*!< pat_00 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_00;
    /*!< pat_01 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_01;
    /*!< pat_02 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_02;
    /*!< pat_03 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_03;
    /*!< pat_10 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_10;
    /*!< pat_11 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_11;
    /*!< pat_12 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_12;
    /*!< pat_13 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_13;
    /*!< pat_20 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_20;
    /*!< pat_21 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_21;
    /*!< pat_22 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_22;
    /*!< pat_23 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_23;
    /*!< pat_30 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_30;
    /*!< pat_31 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_31;
    /*!< pat_32 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_32;
    /*!< pat_33 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_33;
    /*!< shift_id[8] shifter for the histograms per color channel*/
    int32_t shift_id[8];

} ia_pal_isp_aestatistics_2_0_t;

/*! \isp struct aestatistics_2_1
AE Statistics (histogram)
*/
typedef struct
{
    /*!< cell0[96] weighted histogram grid values*/
    int32_t cell0[96];
    /*!< cell1[96] weighted histogram grid values*/
    int32_t cell1[96];
    /*!< cell2[96] weighted histogram grid values*/
    int32_t cell2[96];
    /*!< cell3[96] weighted histogram grid values*/
    int32_t cell3[96];
    /*!< cell4[96] weighted histogram grid values*/
    int32_t cell4[96];
    /*!< cell5[96] weighted histogram grid values*/
    int32_t cell5[96];
    /*!< cell6[96] weighted histogram grid values*/
    int32_t cell6[96];
    /*!< cell7[96] weighted histogram grid values*/
    int32_t cell7[96];
    /*!< grid_width represents number of horizontal grid cells*/
    int32_t grid_width;
    /*!< grid_height represents number of vertical grid cells*/
    int32_t grid_height;
    /*!< block_width Log2 the width of each grid cell (8,16,32,64,128, 256)*/
    int32_t block_width;
    /*!< block_height Log2 the height of each grid cell (8,16,32,64,128, 256)*/
    int32_t block_height;
    /*!< ae_en 0: FF will not write to the AE  array; 1: FF will write*/
    int32_t ae_en;
    /*!< rst_hist_array 1: triggers the reset mechanism for the GLB_HIST*/
    int32_t rst_hist_array;
    /*!< x_start X top left corner of the grid*/
    int32_t x_start;
    /*!< y_start Y top left corner of the grid*/
    int32_t y_start;
    /*!< x_end X bottom right corner of the grid*/
    int32_t x_end;
    /*!< y_end Y bottom right corner of the grid*/
    int32_t y_end;
    /*!< sensor_mode 0: 1x1 CFA (array sensor); 1: 2 x 2 CFA; 2: 4 x 4 CFA*/
    int32_t sensor_mode;
    /*!< pat_00 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_00;
    /*!< pat_01 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_01;
    /*!< pat_02 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_02;
    /*!< pat_03 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_03;
    /*!< pat_10 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_10;
    /*!< pat_11 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_11;
    /*!< pat_12 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_12;
    /*!< pat_13 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_13;
    /*!< pat_20 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_20;
    /*!< pat_21 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_21;
    /*!< pat_22 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_22;
    /*!< pat_23 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_23;
    /*!< pat_30 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_30;
    /*!< pat_31 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_31;
    /*!< pat_32 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_32;
    /*!< pat_33 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_33;
    /*!< shift_id[8] shifter for the histograms per color channel*/
    int32_t shift_id[8];

} ia_pal_isp_aestatistics_2_1_t;

/*! \isp struct af_awb_frstatistics_2_0

*/
typedef struct
{
    /*!< grid_width represents number of horizontal grid cells*/
    int32_t grid_width;
    /*!< grid_height represents number of vertical grid cells*/
    int32_t grid_height;
    /*!< block_width Log2 the width of each grid cell (8,16,32,64,128,256)*/
    int32_t block_width;
    /*!< block_height Log2 the height of each grid cell (8,16,32,64,128,256)*/
    int32_t block_height;
    /*!< grid_height_per_slice # of blocks in vert.axis per Meta-Data Slice*/
    int32_t grid_height_per_slice;
    /*!< y_fr_en 0: FF will not write to the Y  array; 1: FF will write  to the Y  array*/
    int32_t y_fr_en;
    /*!< awb_fr_en 0: FF will not write to the AWB_FR  array; 1: FF will write  to the AWB_FR  array*/
    int32_t awb_fr_en;
    /*!< x_start X top left corner of the grid*/
    int32_t x_start;
    /*!< y_start Y top left corner of the grid*/
    int32_t y_start;
    /*!< x_end X bottom right corner of the grid*/
    int32_t x_end;
    /*!< y_end Y bottom right corner of the grid*/
    int32_t y_end;
    /*!< shftr_val_x[7] Log2(num pixels of estimated colour component in a block). The binding as follows: m_ShftR_val_Y00 = shftr_val_x[0]; m_ShftR_val_Y01 = shftr_val_x[1];m_ShftR_val_Y10 = shftr_val_x[2];m_ShftR_val_Y11 = shftr_val_x[3];m_ShftR_val_R = shftr_val_x[4];m_ShftR_val_G = shftr_val_x[5];m_ShftR_val_B = shftr_val_x[6];*/
    int32_t shftr_val_x[7];
    /*!< gx_0[4] gx0 Y_calc contribution ratio for Pat_ij*/
    int32_t gx_0[4];
    /*!< gx_1[4] gx1 Y_calc contribution ratio for Pat_ij*/
    int32_t gx_1[4];
    /*!< gx_2[4] gx2 Y_calc contribution ratio for Pat_ij*/
    int32_t gx_2[4];
    /*!< gx_3[4] gx3 Y_calc contribution ratio for Pat_ij*/
    int32_t gx_3[4];
    /*!< mask_y0 selecting the relevant pixels for Y0; bit k = row * 4 + column*/
    int32_t mask_y0;
    /*!< mask_y1 selecting the relevant pixels for Y1; bit k = row * 4 + column*/
    int32_t mask_y1;
    /*!< oe_y0 output enable for Y0; bit k corresponds to row * 2 + column*/
    int32_t oe_y0;
    /*!< oe_y1 output enable for Y1; bit k corresponds to row * 2 + column*/
    int32_t oe_y1;
    /*!< on_x_y0[4] Y0 estimation normalization (00, 01, 10, 11)*/
    int32_t on_x_y0[4];
    /*!< on_x_y1[4] Y1 estimation normalization (00, 01, 10, 11)*/
    int32_t on_x_y1[4];
    /*!< r_select selecting the relevant R pixels; bit k corresponds to Row * 4 + Column*/
    int32_t r_select;
    /*!< g_select selecting the relevant G pixels; bit k corresponds to Row * 4 + Column*/
    int32_t g_select;
    /*!< b_select selecting the relevant B pixels; bit k corresponds to Row * 4 + Column*/
    int32_t b_select;
    /*!< y00_filter_coeff[6] filter coefficients for Y00 (A1, A2, A3, A4, A5, A6)*/
    int32_t y00_filter_coeff[6];
    /*!< y00_filter_sign_vec sign vector for Y00*/
    int32_t y00_filter_sign_vec;
    /*!< y01_filter_coeff[6] filter coefficients for Y01 (A1, A2, A3, A4, A5, A6)*/
    int32_t y01_filter_coeff[6];
    /*!< y01_filter_sign_vec sign vector for Y01*/
    int32_t y01_filter_sign_vec;
    /*!< y10_filter_coeff[6] filter coefficients for Y10 (A1, A2, A3, A4, A5, A6)*/
    int32_t y10_filter_coeff[6];
    /*!< y10_filter_sign_vec sign vector for Y10*/
    int32_t y10_filter_sign_vec;
    /*!< y11_filter_coeff[6] filter coefficients for Y11 (A1, A2, A3, A4, A5, A6)*/
    int32_t y11_filter_coeff[6];
    /*!< y11_filter_sign_vec sign vector for Y11*/
    int32_t y11_filter_sign_vec;
    /*!< r_filter_coeff[6] filter coefficients for R (A1, A2, A3, A4, A5, A6)*/
    int32_t r_filter_coeff[6];
    /*!< r_filter_sign_vec sign vector for R*/
    int32_t r_filter_sign_vec;
    /*!< g_filter_coeff[6] filter coefficients for G (A1, A2, A3, A4, A5, A6)*/
    int32_t g_filter_coeff[6];
    /*!< g_filter_sign_vec sign vector for G*/
    int32_t g_filter_sign_vec;
    /*!< b_filter_coeff[6] filter coefficients for B (A1, A2, A3, A4, A5, A6)*/
    int32_t b_filter_coeff[6];
    /*!< b_filter_sign_vec sign vector for B*/
    int32_t b_filter_sign_vec;
    /*!< nf_x[7] Filter response normalization factors for Y00, Y01, Y10, Y11, R, G, B*/
    int32_t nf_x[7];
    /*!< sensor_mode Sensor mode 0: 1x1,  1: 2x2, 2: 4x4*/
    int32_t sensor_mode;
    /*!< downscaling_factor Downscaling factor 0: 1x, 1: 2x, 2: 4x*/
    int32_t downscaling_factor;
    /*!< y00_blending_weight Median filter weight for Y00*/
    int32_t y00_blending_weight;
    /*!< y01_blending_weight Median filter weight for Y01*/
    int32_t y01_blending_weight;
    /*!< y10_blending_weight Median filter weight for Y10*/
    int32_t y10_blending_weight;
    /*!< y11_blending_weight Median filter weight for Y11*/
    int32_t y11_blending_weight;

} ia_pal_isp_af_awb_frstatistics_2_0_t;

/*! \isp struct awbstatistics_2_0
AWB Statistics (RGBS grid)
*/
typedef struct
{
    /*!< grid_width represents number of horizontal grid cells*/
    int32_t grid_width;
    /*!< grid_height represents number of vertical grid cells*/
    int32_t grid_height;
    /*!< block_width Log2 the width of each grid cell (8,16,32,64,128)*/
    int32_t block_width;
    /*!< block_height Log2 the height of each grid cell (8,16,32,64,128)*/
    int32_t block_height;
    /*!< grid_height_per_slice # of blocks in vert.axis per Meta-Data Slice (grid_height_per_slice * grid_width <= 192)*/
    int32_t grid_height_per_slice;
    /*!< awb_en 0: FF will not write to the AWB  array; 1: FF will write*/
    int32_t awb_en;
    /*!< rgbs_incl_sat 0: do not include saturated quads in the average; 1: include saturated quads in the average*/
    int32_t rgbs_incl_sat;
    /*!< x_start X top left corner of the grid. 0 <= x_start <= (frame_width - 1)*/
    int32_t x_start;
    /*!< y_start Y top left corner of the grid. 0 <= y_start <= (frame_height - 1)*/
    int32_t y_start;
    /*!< x_end X bottom right corner of the grid. x_end = x_start + (grid_width << block_width) - 1*/
    int32_t x_end;
    /*!< y_end Y bottom right corner of the grid. y_end = y_start + (grid_height << block_height) - 1*/
    int32_t y_end;
    /*!< sensor_mode 0: 1x1 CFA (array sensor); 1: 2 x 2 CFA; 2: 4 x 4 CFA*/
    int32_t sensor_mode;
    /*!< pat_00 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_00;
    /*!< pat_01 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_01;
    /*!< pat_02 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_02;
    /*!< pat_03 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_03;
    /*!< pat_10 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_10;
    /*!< pat_11 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_11;
    /*!< pat_12 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_12;
    /*!< pat_13 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_13;
    /*!< pat_20 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_20;
    /*!< pat_21 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_21;
    /*!< pat_22 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_22;
    /*!< pat_23 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_23;
    /*!< pat_30 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_30;
    /*!< pat_31 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_31;
    /*!< pat_32 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_32;
    /*!< pat_33 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_33;
    /*!< rgbs_thr_cx[8] RGBS threshold value (C0, C1, C2, C3, C4, C5, C6, C7)*/
    int32_t rgbs_thr_cx[8];
    /*!< shftr_val_cx[8] ShiftVal is derived from log2(number of pixels from C0-C7 color channel in a cell)*/
    int32_t shftr_val_cx[8];
    /*!< shftr_sat represents log2(num of pixels in cell)*/
    int32_t shftr_sat;
    /*!< output_packed Enabling Output packing. Use 0 if ColorID [0 3] are used, Use 1 if all ColorIDs i.e. [0 7] are used (i.e. multi-exposure (e.g. SVE) use-cases)*/
    int32_t output_packed;

} ia_pal_isp_awbstatistics_2_0_t;

/*! \isp struct b2i_bnr_1_0

*/
typedef struct
{
    /*!< enable enable B2I-BNR filter*/
    int32_t enable;
    /*!< bayer_noise_mod_poiss_coeff denoise: noise model alpha - TH=alpha*sqrt(gain*I)+beta*gain*sigma+gamma+texture(I)*/
    int32_t bayer_noise_mod_poiss_coeff;
    /*!< bayer_noise_mod_gauss_coeff denoise: noise model beta - TH=alpha*sqrt(gain*I)+beta*gain*sigma+gamma+texture(I)*/
    int32_t bayer_noise_mod_gauss_coeff;
    /*!< bayer_noise_mod_gain_gr denoise: noise model gain for gr - TH=alpha*sqrt(gain*I)+beta*gain*sigma+gamma+texture(I)*/
    int32_t bayer_noise_mod_gain_gr;
    /*!< bayer_noise_mod_gain_r denoise: noise model gain for r - TH=alpha*sqrt(gain*I)+beta*gain*sigma+gamma+texture(I)*/
    int32_t bayer_noise_mod_gain_r;
    /*!< bayer_noise_mod_gain_b denoise: noise model gain for b - TH=alpha*sqrt(gain*I)+beta*gain*sigma+gamma+texture(I)*/
    int32_t bayer_noise_mod_gain_b;
    /*!< bayer_noise_mod_gain_gb denoise: noise model gain for gb - TH=alpha*sqrt(gain*I)+beta*gain*sigma+gamma+texture(I)*/
    int32_t bayer_noise_mod_gain_gb;
    /*!< bayer_noise_spatial_Gcoeff[4] denoise: spatial kernel coefficients for G pixels*/
    int32_t bayer_noise_spatial_Gcoeff[4];
    /*!< bayer_noise_spatial_Rbcoeff[3] denoise: spatial kernel coefficients for R,B pixels*/
    int32_t bayer_noise_spatial_Rbcoeff[3];
    /*!< psdy_noise_th 0-use bayer pixel for noise TH, 1- use psdY pixel for noise TH*/
    int32_t psdy_noise_th;
    /*!< radial_x_initial Radial x coordinates of corner*/
    int32_t radial_x_initial;
    /*!< radial_y_initial Radial y coordinates of corner*/
    int32_t radial_y_initial;
    /*!< radial_coords_prec_reduc radial coordinates precision reduction - to bring sqrX+sqrY to [0-256]*/
    int32_t radial_coords_prec_reduc;
    /*!< cu_radial_coeff_gr_x[6] radial coeff function for Gr channel config unit - x values*/
    int32_t cu_radial_coeff_gr_x[6];
    /*!< cu_radial_coeff_gr_y[5] radial coeff function for Gr channel config unit - y values*/
    int32_t cu_radial_coeff_gr_y[5];
    /*!< cu_radial_coeff_gr_slope[5] radial coeff function for Gr channel config unit - slope values*/
    int32_t cu_radial_coeff_gr_slope[5];
    /*!< cu_radial_coeff_r_x[6] radial coeff function for R channel config unit - x values*/
    int32_t cu_radial_coeff_r_x[6];
    /*!< cu_radial_coeff_r_y[5] radial coeff function for R channel config unit - y values*/
    int32_t cu_radial_coeff_r_y[5];
    /*!< cu_radial_coeff_r_slope[5] radial coeff function for R channel config unit - slope values*/
    int32_t cu_radial_coeff_r_slope[5];
    /*!< cu_radial_coeff_b_x[6] radial coeff function for B channel config unit - x values*/
    int32_t cu_radial_coeff_b_x[6];
    /*!< cu_radial_coeff_b_y[5] radial coeff function for B channel config unit - y values*/
    int32_t cu_radial_coeff_b_y[5];
    /*!< cu_radial_coeff_b_slope[5] radial coeff function for B channel config unit - slope values*/
    int32_t cu_radial_coeff_b_slope[5];
    /*!< cu_radial_coeff_gb_x[6] radial coeff function for Gb channel config unit - x values*/
    int32_t cu_radial_coeff_gb_x[6];
    /*!< cu_radial_coeff_gb_y[5] radial coeff function for Gb channel config unit - y values*/
    int32_t cu_radial_coeff_gb_y[5];
    /*!< cu_radial_coeff_gb_slope[5] radial coeff function for Gb channel config unit - slope values*/
    int32_t cu_radial_coeff_gb_slope[5];

} ia_pal_isp_b2i_bnr_1_0_t;

/*! \isp struct b2i_dm_1_0

*/
typedef struct
{
    /*!< enable enable B2I-DM filter*/
    int32_t enable;
    /*!< local_median_bypass local_median_bypass*/
    int32_t local_median_bypass;
    /*!< cas_bypass cas_bypass*/
    int32_t cas_bypass;
    /*!< g_int_x_points[2] x_points for green interpolation CU*/
    int32_t g_int_x_points[2];
    /*!< g_int_a_points a_points for green interpolation CU*/
    int32_t g_int_a_points;
    /*!< g_int_b_points b_points for green interpolation CU*/
    int32_t g_int_b_points;
    /*!< cas_x_points[2] x_points for CAS CU*/
    int32_t cas_x_points[2];
    /*!< cas_a_points a_points for CAS CU*/
    int32_t cas_a_points;
    /*!< cas_b_points b_points for CAS CU*/
    int32_t cas_b_points;
    /*!< local_med_x_points[2] x_points forlocal median CU*/
    int32_t local_med_x_points[2];
    /*!< local_med_a_points a_points forlocal median CU*/
    int32_t local_med_a_points;
    /*!< local_med_b_points b_points forlocal median CU*/
    int32_t local_med_b_points;
    /*!< cas_low_level low level of the CAS config unit. [0 , 1024]*/
    int32_t cas_low_level;
    /*!< sharp_power power of DM sharpening - higher is more sharp [0 15]*/
    int32_t sharp_power;

} ia_pal_isp_b2i_dm_1_0_t;

/*! \isp struct b2i_ds_1_0_0

*/
typedef struct
{
    /*!< enable enable scaling filter*/
    int32_t enable;
    /*!< scaling_ratio Scaling factor, 16bit fixed point, greater than 1*/
    int32_t scaling_ratio;
    /*!< horizontal_offset Position of first output pixel for scaler*/
    int32_t horizontal_offset;
    /*!< vertical_offset Position of first output line for scaler*/
    int32_t vertical_offset;
    /*!< output_height Output image height for scaler*/
    int32_t output_height;
    /*!< output_width Output image width for scaler*/
    int32_t output_width;
    /*!< vkernel_LUT[129] interpolation vertical kernel coefficients for scaler*/
    int32_t vkernel_LUT[129];
    /*!< hkernel_LUT[129] interpolation horizontal kernel coefficients for scaler*/
    int32_t hkernel_LUT[129];
    /*!< input_height input image height*/
    int32_t input_height;

} ia_pal_isp_b2i_ds_1_0_0_t;

/*! \isp struct b2i_ds_1_0_1

*/
typedef struct
{
    /*!< enable enable scaling filter*/
    int32_t enable;
    /*!< scaling_ratio Scaling factor, 16bit fixed point, greater than 1*/
    int32_t scaling_ratio;
    /*!< horizontal_offset Position of first output pixel for scaler*/
    int32_t horizontal_offset;
    /*!< vertical_offset Position of first output line for scaler*/
    int32_t vertical_offset;
    /*!< output_height Output image height for scaler*/
    int32_t output_height;
    /*!< output_width Output image width for scaler*/
    int32_t output_width;
    /*!< vkernel_LUT[129] interpolation vertical kernel coefficients for scaler*/
    int32_t vkernel_LUT[129];
    /*!< hkernel_LUT[129] interpolation horizontal kernel coefficients for scaler*/
    int32_t hkernel_LUT[129];
    /*!< input_height input image height*/
    int32_t input_height;

} ia_pal_isp_b2i_ds_1_0_1_t;

/*! \isp struct b2i_sie_1_0

*/
typedef struct
{
    /*!< csc_enable csc_bypass*/
    int32_t csc_enable;
    /*!< sharp_enable sharp_bypass*/
    int32_t sharp_enable;
    /*!< gamma_lut_enable gamma lut enable*/
    int32_t gamma_lut_enable;
    /*!< tm_lut_enable TM enable*/
    int32_t tm_lut_enable;
    /*!< ccm_enable ccm_bypass*/
    int32_t ccm_enable;
    /*!< cnr_enable cnr_bypass*/
    int32_t cnr_enable;
    /*!< csc_matrix[9] conversion matrix for RGB2YUV*/
    int32_t csc_matrix[9];
    /*!< csc_matrix_norm normalization factor for RGB2YUV*/
    int32_t csc_matrix_norm;
    /*!< csc_bias_vec[3] conversion bias for RGB2YUV*/
    int32_t csc_bias_vec[3];
    /*!< cds_coeff_array[8] conversion kernel from 444->420*/
    int32_t cds_coeff_array[8];
    /*!< cds_coeff_array_norm normalization factor for 444->420 kernel*/
    int32_t cds_coeff_array_norm;
    /*!< sharp_undershoot_power sharpening undershoot enhancement.To enhance use positive. To weaken use a negative.*/
    int32_t sharp_undershoot_power;
    /*!< sharp_overshoot_power sharpening overshoot enhancement.To enhance use positive. To weaken use a negative.*/
    int32_t sharp_overshoot_power;
    /*!< glut_base_level[5] Gamma lut  - GLUT base levels*/
    int32_t glut_base_level[5];
    /*!< glut_start_bin[5] Gamma lut  - GLUT start bin*/
    int32_t glut_start_bin[5];
    /*!< glut_step[5] Gamma lut  - GLUT step*/
    int32_t glut_step[5];
    /*!< glut_gen_lut[385] Gamma lut  - GLUT values*/
    int32_t glut_gen_lut[385];
    /*!< gamma_prog_shift programable shift for the gamma output*/
    int32_t gamma_prog_shift;
    /*!< ccm_matrix[9] color space conversion matrix for color enhancement*/
    int32_t ccm_matrix[9];
    /*!< ccm_matrix_norm normalization factor for color enhancement*/
    int32_t ccm_matrix_norm;
    /*!< tmlut_base_level TM lut  - LUT base levels*/
    int32_t tmlut_base_level;
    /*!< tmlut_start_bin TM lut  - LUT start bin*/
    int32_t tmlut_start_bin;
    /*!< tmlut_step TM lut  - LUT step*/
    int32_t tmlut_step;
    /*!< tmlut_gen_lut[513] TM lut  - LUT values*/
    int32_t tmlut_gen_lut[513];
    /*!< x_points_for_sharp_pos_th[6] x points for sharpning overshoot config unit*/
    int32_t x_points_for_sharp_pos_th[6];
    /*!< a_points_for_sharp_pos_th[5] a points for sharpning overshoot config unit*/
    int32_t a_points_for_sharp_pos_th[5];
    /*!< b_points_for_sharp_pos_th[5] b points for sharpning overshoot config unit*/
    int32_t b_points_for_sharp_pos_th[5];
    /*!< x_points_for_sharp_neg_th[6] x points for sharpning undershoot config unit*/
    int32_t x_points_for_sharp_neg_th[6];
    /*!< a_points_for_sharp_neg_th[5] a points for sharpning undershoot config unit*/
    int32_t a_points_for_sharp_neg_th[5];
    /*!< b_points_for_sharp_neg_th[5] b points for sharpning undershoot config unit*/
    int32_t b_points_for_sharp_neg_th[5];
    /*!< x_points_for_sharp_pixval_th[6] x points for sharpning pixel value config unit*/
    int32_t x_points_for_sharp_pixval_th[6];
    /*!< a_points_for_sharp_pixval_th[5] a points for sharpning pixel value config unit*/
    int32_t a_points_for_sharp_pixval_th[5];
    /*!< b_points_for_sharp_pixval_th[5] b points for sharpning pixel value config unit*/
    int32_t b_points_for_sharp_pixval_th[5];
    /*!< sharp_texture_coeff_norm texture  metric normalization power*/
    int32_t sharp_texture_coeff_norm;
    /*!< sharp_texture_undershoot sharpening: allowed undershoot for textured pixels*/
    int32_t sharp_texture_undershoot;
    /*!< sharp_edge_undershoot sharpening: allowed undershoot for edge pixels*/
    int32_t sharp_edge_undershoot;
    /*!< sharp_texture_overshoot sharpening: allowed overshoot for textured pixels*/
    int32_t sharp_texture_overshoot;
    /*!< sharp_edge_overshoot sharpening: allowed overshoot for edge pixels*/
    int32_t sharp_edge_overshoot;
    /*!< sharp_kernel_coeffs[6] sharpening: kernel coefficients*/
    int32_t sharp_kernel_coeffs[6];
    /*!< x_points_for_noise_th[6] x points for sharpning noise th config unit*/
    int32_t x_points_for_noise_th[6];
    /*!< a_points_for_noise_th[5] a  points for sharpning noise th config unit*/
    int32_t a_points_for_noise_th[5];
    /*!< b_points_for_noise_th[5] b  points for sharpning noise th config unit*/
    int32_t b_points_for_noise_th[5];
    /*!< x_points_for_local_coring[6] x points for local coring config unit*/
    int32_t x_points_for_local_coring[6];
    /*!< a_points_for_local_coring[5] a points for local coring config unit*/
    int32_t a_points_for_local_coring[5];
    /*!< b_points_for_local_coring[5] b points for local coring config unit*/
    int32_t b_points_for_local_coring[5];
    /*!< x_points_for_global_coring[6] x points for global coring config unit*/
    int32_t x_points_for_global_coring[6];
    /*!< a_points_for_global_coring[5] a points for global coring config unit*/
    int32_t a_points_for_global_coring[5];
    /*!< b_points_for_global_coring[5] b points for global coring config unit*/
    int32_t b_points_for_global_coring[5];
    /*!< cnr_iir_weight weights for vertical iir filter (filter norm power = 6)*/
    int32_t cnr_iir_weight;
    /*!< cnr_fir_weight[3] weights for horizontal fir filter (filter norm power = 7)*/
    int32_t cnr_fir_weight[3];

} ia_pal_isp_b2i_sie_1_0_t;

/*! \isp struct b2i_sie_1_1

*/
typedef struct
{
    /*!< csc_enable csc_bypass*/
    int32_t csc_enable;
    /*!< sharp_enable sharp_bypass*/
    int32_t sharp_enable;
    /*!< gamma_lut_enable gamma lut enable*/
    int32_t gamma_lut_enable;
    /*!< tmlut_enable TM enable*/
    int32_t tmlut_enable;
    /*!< ccm_enable ccm_bypass*/
    int32_t ccm_enable;
    /*!< cnr_enable cnr_bypass*/
    int32_t cnr_enable;
    /*!< csc_matrix[9] conversion matrix for RGB2YUV*/
    int32_t csc_matrix[9];
    /*!< csc_matrix_norm normalization factor for RGB2YUV*/
    int32_t csc_matrix_norm;
    /*!< csc_bias_vec[3] conversion bias for RGB2YUV*/
    int32_t csc_bias_vec[3];
    /*!< cds_coeff_array[8] conversion kernel from 444->420*/
    int32_t cds_coeff_array[8];
    /*!< cds_coeff_array_norm normalization factor for 444->420 kernel*/
    int32_t cds_coeff_array_norm;
    /*!< sharp_undershoot_power sharpening undershoot enhancement.To enhance use positive. To weaken use a negative.*/
    int32_t sharp_undershoot_power;
    /*!< sharp_overshoot_power sharpening overshoot enhancement.To enhance use positive. To weaken use a negative.*/
    int32_t sharp_overshoot_power;
    /*!< glut_base_level[5] Gamma lut  - GLUT base levels*/
    int32_t glut_base_level[5];
    /*!< glut_start_bin[5] Gamma lut  - GLUT start bin*/
    int32_t glut_start_bin[5];
    /*!< glut_step[5] Gamma lut  - GLUT step*/
    int32_t glut_step[5];
    /*!< glut_gen_lut[385] Gamma lut  - GLUT values*/
    int32_t glut_gen_lut[385];
    /*!< gamma_prog_shift programable shift for the gamma output*/
    int32_t gamma_prog_shift;
    /*!< ccm_matrix[9] color space conversion matrix for color enhancement*/
    int32_t ccm_matrix[9];
    /*!< ccm_matrix_norm normalization factor for color enhancement*/
    int32_t ccm_matrix_norm;
    /*!< tmlut_base_level TM lut  - LUT base levels*/
    int32_t tmlut_base_level;
    /*!< tmlut_start_bin TM lut  - LUT start bin*/
    int32_t tmlut_start_bin;
    /*!< tmlut_step TM lut  - LUT step*/
    int32_t tmlut_step;
    /*!< tmlut_gen_lut[513] TM lut  - LUT values*/
    int32_t tmlut_gen_lut[513];
    /*!< x_points_for_sharp_pos_th[6] x points for sharpning overshoot config unit*/
    int32_t x_points_for_sharp_pos_th[6];
    /*!< a_points_for_sharp_pos_th[5] a points for sharpning overshoot config unit*/
    int32_t a_points_for_sharp_pos_th[5];
    /*!< b_points_for_sharp_pos_th[5] b points for sharpning overshoot config unit*/
    int32_t b_points_for_sharp_pos_th[5];
    /*!< x_points_for_sharp_neg_th[6] x points for sharpning undershoot config unit*/
    int32_t x_points_for_sharp_neg_th[6];
    /*!< a_points_for_sharp_neg_th[5] a points for sharpning undershoot config unit*/
    int32_t a_points_for_sharp_neg_th[5];
    /*!< b_points_for_sharp_neg_th[5] b points for sharpning undershoot config unit*/
    int32_t b_points_for_sharp_neg_th[5];
    /*!< x_points_for_sharp_pixval_th[6] x points for sharpning pixel value config unit*/
    int32_t x_points_for_sharp_pixval_th[6];
    /*!< a_points_for_sharp_pixval_th[5] a points for sharpning pixel value config unit*/
    int32_t a_points_for_sharp_pixval_th[5];
    /*!< b_points_for_sharp_pixval_th[5] b points for sharpning pixel value config unit*/
    int32_t b_points_for_sharp_pixval_th[5];
    /*!< sharp_texture_coeff_norm texture  metric normalization power*/
    int32_t sharp_texture_coeff_norm;
    /*!< sharp_texture_undershoot sharpening: allowed undershoot for textured pixels*/
    int32_t sharp_texture_undershoot;
    /*!< sharp_edge_undershoot sharpening: allowed undershoot for edge pixels*/
    int32_t sharp_edge_undershoot;
    /*!< sharp_texture_overshoot sharpening: allowed overshoot for textured pixels*/
    int32_t sharp_texture_overshoot;
    /*!< sharp_edge_overshoot sharpening: allowed overshoot for edge pixels*/
    int32_t sharp_edge_overshoot;
    /*!< sharp_kernel_coeffs[6] sharpening: kernel coefficients*/
    int32_t sharp_kernel_coeffs[6];
    /*!< x_points_for_noise_th[6] x points for sharpning noise th config unit*/
    int32_t x_points_for_noise_th[6];
    /*!< a_points_for_noise_th[5] a  points for sharpning noise th config unit*/
    int32_t a_points_for_noise_th[5];
    /*!< b_points_for_noise_th[5] b  points for sharpning noise th config unit*/
    int32_t b_points_for_noise_th[5];
    /*!< x_points_for_local_coring[6] x points for local coring config unit*/
    int32_t x_points_for_local_coring[6];
    /*!< a_points_for_local_coring[5] a points for local coring config unit*/
    int32_t a_points_for_local_coring[5];
    /*!< b_points_for_local_coring[5] b points for local coring config unit*/
    int32_t b_points_for_local_coring[5];
    /*!< x_points_for_global_coring[6] x points for global coring config unit*/
    int32_t x_points_for_global_coring[6];
    /*!< a_points_for_global_coring[5] a points for global coring config unit*/
    int32_t a_points_for_global_coring[5];
    /*!< b_points_for_global_coring[5] b points for global coring config unit*/
    int32_t b_points_for_global_coring[5];
    /*!< cnr_iir_weight weights for vertical iir filter (filter norm power = 6)*/
    int32_t cnr_iir_weight;
    /*!< cnr_fir_weight[3] weights for horizontal fir filter (filter norm power = 7)*/
    int32_t cnr_fir_weight[3];

} ia_pal_isp_b2i_sie_1_1_t;

/*! \isp struct bnlm_3_0
noise reduction
*/
typedef struct
{
    /*!< bayer_fmt Bayer format*/
    int32_t bayer_fmt;
    /*!< bypass bypass*/
    int32_t bypass;
    /*!< run_on_y a flag that indicates if the block used on Y input*/
    int32_t run_on_y;
    /*!< hv_edge_density_thr Edge density noise sigma thr*/
    int32_t hv_edge_density_thr;
    /*!< minmax_hv_edge_density_thr Edge density delta max - min thr*/
    int32_t minmax_hv_edge_density_thr;
    /*!< d_edge_density_thr Diagonal edge density noise sigma thr*/
    int32_t d_edge_density_thr;
    /*!< minmax_d_edge_density_thr Diagonal edge density delta max - min thr*/
    int32_t minmax_d_edge_density_thr;
    /*!< sigma_flat sigma flat*/
    int32_t sigma_flat;
    /*!< sigma_slope sigma slope*/
    int32_t sigma_slope;
    /*!< sigma_edge sigma edge*/
    int32_t sigma_edge;
    /*!< sigma_texture sigma texture*/
    int32_t sigma_texture;
    /*!< delta_flat delta flat*/
    int32_t delta_flat;
    /*!< delta_slope delta slope*/
    int32_t delta_slope;
    /*!< delta_edge delta edge*/
    int32_t delta_edge;
    /*!< delta_texture delta texture*/
    int32_t delta_texture;
    /*!< alpha_flat alpha flat*/
    int32_t alpha_flat;
    /*!< alpha_slope alpha slope*/
    int32_t alpha_slope;
    /*!< alpha_edge alpha edge*/
    int32_t alpha_edge;
    /*!< alpha_texture alpha texture*/
    int32_t alpha_texture;
    /*!< sigma_s spatial sigma of uniform filter*/
    int32_t sigma_s;
    /*!< sigma_s_b narrow sigma of elliptical filter*/
    int32_t sigma_s_b;
    /*!< sigma_s_a wide sigma of elliptical filter*/
    int32_t sigma_s_a;
    /*!< rx_sqr_start initial value of Rx^2*/
    int32_t rx_sqr_start;
    /*!< ry_sqr_start initial value of Ry^2*/
    int32_t ry_sqr_start;
    /*!< coordinates_shift coordinates shift*/
    int32_t coordinates_shift;
    /*!< color_penalty_weight color penalty weight*/
    int32_t color_penalty_weight;
    /*!< alpha_i_max alpha I max*/
    int32_t alpha_i_max;
    /*!< cu_ed_measure_x[4] edge density config unit - x values*/
    int32_t cu_ed_measure_x[4];
    /*!< cu_ed_measure_y[3] edge density config unit - y values*/
    int32_t cu_ed_measure_y[3];
    /*!< cu_ed_measure_slope[3] edge density config unit - slope values*/
    int32_t cu_ed_measure_slope[3];
    /*!< cu_ed_dir_measure_x[4] directional measure config unit - x values*/
    int32_t cu_ed_dir_measure_x[4];
    /*!< cu_ed_dir_measure_y[3] directional measure config unit - y values*/
    int32_t cu_ed_dir_measure_y[3];
    /*!< cu_ed_dir_measure_slope[3] directional measure config unit - slopes values*/
    int32_t cu_ed_dir_measure_slope[3];
    /*!< cu_lin_slope_measure_x[4] slope measure config unit - x values*/
    int32_t cu_lin_slope_measure_x[4];
    /*!< cu_lin_slope_measure_y[3] slope measure config unit - y values*/
    int32_t cu_lin_slope_measure_y[3];
    /*!< cu_lin_slope_measure_slope[3] slope measure config unit - slope values*/
    int32_t cu_lin_slope_measure_slope[3];
    /*!< cu_lin_slope_edge_measure_x[4] edge measure based on linear slope config unit - x values*/
    int32_t cu_lin_slope_edge_measure_x[4];
    /*!< cu_lin_slope_edge_measure_y[3] edge measure based on linear slope config unit - y values*/
    int32_t cu_lin_slope_edge_measure_y[3];
    /*!< cu_lin_slope_edge_measure_slope[3] edge measure based on linear slope config unit - slope values*/
    int32_t cu_lin_slope_edge_measure_slope[3];
    /*!< cu_var_measure_x[4] variance measure config unit - x values*/
    int32_t cu_var_measure_x[4];
    /*!< cu_var_measure_y[3] variance measure config unit - y values*/
    int32_t cu_var_measure_y[3];
    /*!< cu_var_measure_slope[3] variance measure config unit - slope values*/
    int32_t cu_var_measure_slope[3];
    /*!< cu_var_edge_measure_x[4] variance edge measure config unit - x values*/
    int32_t cu_var_edge_measure_x[4];
    /*!< cu_var_edge_measure_y[3] variance edge measure config unit - y values*/
    int32_t cu_var_edge_measure_y[3];
    /*!< cu_var_edge_measure_slope[3] variance edge measure config unit - slope values*/
    int32_t cu_var_edge_measure_slope[3];
    /*!< cu_alpha_i_x[4] alpha change with intensity config unit - x values*/
    int32_t cu_alpha_i_x[4];
    /*!< cu_alpha_i_y[3] alpha change with intensity config unit - y values*/
    int32_t cu_alpha_i_y[3];
    /*!< cu_alpha_i_slope[3] alpha change with intensity config unit - slopes values*/
    int32_t cu_alpha_i_slope[3];
    /*!< cu_lsc_coeff_gr_x[6] LSC coeff function for Gr channel config unit - x values*/
    int32_t cu_lsc_coeff_gr_x[6];
    /*!< cu_lsc_coeff_gr_y[5] LSC coeff function for Gr channel config unit - y values*/
    int32_t cu_lsc_coeff_gr_y[5];
    /*!< cu_lsc_coeff_gr_slope[5] LSC coeff function for Gr channel config unit - slope values*/
    int32_t cu_lsc_coeff_gr_slope[5];
    /*!< cu_lsc_coeff_r_x[6] LSC coeff function for R channel config unit - x values*/
    int32_t cu_lsc_coeff_r_x[6];
    /*!< cu_lsc_coeff_r_y[5] LSC coeff function for R channel config unit - y values*/
    int32_t cu_lsc_coeff_r_y[5];
    /*!< cu_lsc_coeff_r_slope[5] LSC coeff function for R channel config unit - slope values*/
    int32_t cu_lsc_coeff_r_slope[5];
    /*!< cu_lsc_coeff_b_x[6] LSC coeff function for B channel config unit - x values*/
    int32_t cu_lsc_coeff_b_x[6];
    /*!< cu_lsc_coeff_b_y[5] LSC coeff function for B channel config unit - y values*/
    int32_t cu_lsc_coeff_b_y[5];
    /*!< cu_lsc_coeff_b_slope[5] LSC coeff function for B channel config unit - slope values*/
    int32_t cu_lsc_coeff_b_slope[5];
    /*!< cu_lsc_coeff_gb_x[6] LSC coeff function for Gb channel config unit - x values*/
    int32_t cu_lsc_coeff_gb_x[6];
    /*!< cu_lsc_coeff_gb_y[5] LSC coeff function for Gb channel config unit - y values*/
    int32_t cu_lsc_coeff_gb_y[5];
    /*!< cu_lsc_coeff_gb_slope[5] LSC coeff function for Gb channel config unit - slope values*/
    int32_t cu_lsc_coeff_gb_slope[5];
    /*!< start_col The distance along the vertical axis of the first pixel of the frame*/
    int32_t start_col;
    /*!< start_row The distance along the horizontal axis of the first pixel of the frame*/
    int32_t start_row;
    /*!< delta_y_counter crop supporting register*/
    int32_t delta_y_counter;
    /*!< delta_x_counter crop supporting register*/
    int32_t delta_x_counter;
    /*!< cu_nm_patch_x[10] noise model config unit - x values*/
    int32_t cu_nm_patch_x[10];
    /*!< cu_nm_patch_y[9] noise model config unit - y values*/
    int32_t cu_nm_patch_y[9];
    /*!< cu_nm_patch_slope[9] noise model config unit - slope values*/
    int32_t cu_nm_patch_slope[9];
    /*!< cu_nm_block_x[10] content detectors noise model config unit - x values*/
    int32_t cu_nm_block_x[10];
    /*!< cu_nm_block_y[9] content detectors noise model config unit - y values*/
    int32_t cu_nm_block_y[9];
    /*!< cu_nm_block_slope[9] content detectors noise model config unit - slope values*/
    int32_t cu_nm_block_slope[9];
    /*!< cu_input_compression_x[16] input compression function (16 to 12 bits) - x values*/
    int32_t cu_input_compression_x[16];
    /*!< cu_input_compression_y[15] input compression function (16 to 12 bits) - y values*/
    int32_t cu_input_compression_y[15];
    /*!< cu_input_compression_slope[15] input compression function (16 to 12 bits) - slope values*/
    int32_t cu_input_compression_slope[15];
    /*!< cu_input_decompression_x[16] input decompression function (16 to 24 bits) - x values*/
    int32_t cu_input_decompression_x[16];
    /*!< cu_input_decompression_y[15] input decompression function (16 to 24 bits) - y values*/
    int32_t cu_input_decompression_y[15];
    /*!< cu_input_decompression_slope[15] input decompression function (16 to 24 bits) - slope values*/
    int32_t cu_input_decompression_slope[15];
    /*!< cu_output_compression_x[16] output compression function (24 to 16 bits) - x values*/
    int32_t cu_output_compression_x[16];
    /*!< cu_output_compression_y[15] output compression function (24 to 16 bits) - y values*/
    int32_t cu_output_compression_y[15];
    /*!< cu_output_compression_slope[15] output compression function (24 to 16 bits) - slope values*/
    int32_t cu_output_compression_slope[15];
    /*!< nm_norm_scale Amount of bits to normalize the noise model*/
    int32_t nm_norm_scale;

} ia_pal_isp_bnlm_3_0_t;

/*! \isp struct bnlm_3_1
noise reduction
*/
typedef struct
{
    /*!< bayer_fmt Bayer format*/
    int32_t bayer_fmt;
    /*!< bypass bypass*/
    int32_t bypass;
    /*!< run_on_y a flag that indicates if the block used on Y input*/
    int32_t run_on_y;
    /*!< hv_edge_density_thr Edge density noise sigma thr*/
    int32_t hv_edge_density_thr;
    /*!< minmax_hv_edge_density_thr Edge density delta max - min thr*/
    int32_t minmax_hv_edge_density_thr;
    /*!< d_edge_density_thr Diagonal edge density noise sigma thr*/
    int32_t d_edge_density_thr;
    /*!< minmax_d_edge_density_thr Diagonal edge density delta max - min thr*/
    int32_t minmax_d_edge_density_thr;
    /*!< sigma_flat sigma flat*/
    int32_t sigma_flat;
    /*!< sigma_slope sigma slope*/
    int32_t sigma_slope;
    /*!< sigma_edge sigma edge*/
    int32_t sigma_edge;
    /*!< sigma_texture sigma texture*/
    int32_t sigma_texture;
    /*!< delta_flat delta flat*/
    int32_t delta_flat;
    /*!< delta_slope delta slope*/
    int32_t delta_slope;
    /*!< delta_edge delta edge*/
    int32_t delta_edge;
    /*!< delta_texture delta texture*/
    int32_t delta_texture;
    /*!< alpha_flat alpha flat*/
    int32_t alpha_flat;
    /*!< alpha_slope alpha slope*/
    int32_t alpha_slope;
    /*!< alpha_edge alpha edge*/
    int32_t alpha_edge;
    /*!< alpha_texture alpha texture*/
    int32_t alpha_texture;
    /*!< sigma_s spatial sigma of uniform filter*/
    int32_t sigma_s;
    /*!< sigma_s_b narrow sigma of elliptical filter*/
    int32_t sigma_s_b;
    /*!< sigma_s_a wide sigma of elliptical filter*/
    int32_t sigma_s_a;
    /*!< rx_sqr_start initial value of Rx^2*/
    int32_t rx_sqr_start;
    /*!< ry_sqr_start initial value of Ry^2*/
    int32_t ry_sqr_start;
    /*!< coordinates_shift coordinates shift*/
    int32_t coordinates_shift;
    /*!< color_penalty_weight color penalty weight*/
    int32_t color_penalty_weight;
    /*!< alpha_i_max alpha I max*/
    int32_t alpha_i_max;
    /*!< cu_ed_measure_x[4] edge density config unit - x values*/
    int32_t cu_ed_measure_x[4];
    /*!< cu_ed_measure_y[3] edge density config unit - y values*/
    int32_t cu_ed_measure_y[3];
    /*!< cu_ed_measure_slope[3] edge density config unit - slope values*/
    int32_t cu_ed_measure_slope[3];
    /*!< cu_ed_dir_measure_x[4] directional measure config unit - x values*/
    int32_t cu_ed_dir_measure_x[4];
    /*!< cu_ed_dir_measure_y[3] directional measure config unit - y values*/
    int32_t cu_ed_dir_measure_y[3];
    /*!< cu_ed_dir_measure_slope[3] directional measure config unit - slopes values*/
    int32_t cu_ed_dir_measure_slope[3];
    /*!< cu_lin_slope_measure_x[4] slope measure config unit - x values*/
    int32_t cu_lin_slope_measure_x[4];
    /*!< cu_lin_slope_measure_y[3] slope measure config unit - y values*/
    int32_t cu_lin_slope_measure_y[3];
    /*!< cu_lin_slope_measure_slope[3] slope measure config unit - slope values*/
    int32_t cu_lin_slope_measure_slope[3];
    /*!< cu_lin_slope_edge_measure_x[4] edge measure based on linear slope config unit - x values*/
    int32_t cu_lin_slope_edge_measure_x[4];
    /*!< cu_lin_slope_edge_measure_y[3] edge measure based on linear slope config unit - y values*/
    int32_t cu_lin_slope_edge_measure_y[3];
    /*!< cu_lin_slope_edge_measure_slope[3] edge measure based on linear slope config unit - slope values*/
    int32_t cu_lin_slope_edge_measure_slope[3];
    /*!< cu_var_measure_x[4] variance measure config unit - x values*/
    int32_t cu_var_measure_x[4];
    /*!< cu_var_measure_y[3] variance measure config unit - y values*/
    int32_t cu_var_measure_y[3];
    /*!< cu_var_measure_slope[3] variance measure config unit - slope values*/
    int32_t cu_var_measure_slope[3];
    /*!< cu_var_edge_measure_x[4] variance edge measure config unit - x values*/
    int32_t cu_var_edge_measure_x[4];
    /*!< cu_var_edge_measure_y[3] variance edge measure config unit - y values*/
    int32_t cu_var_edge_measure_y[3];
    /*!< cu_var_edge_measure_slope[3] variance edge measure config unit - slope values*/
    int32_t cu_var_edge_measure_slope[3];
    /*!< cu_alpha_i_x[4] alpha change with intensity config unit - x values*/
    int32_t cu_alpha_i_x[4];
    /*!< cu_alpha_i_y[3] alpha change with intensity config unit - y values*/
    int32_t cu_alpha_i_y[3];
    /*!< cu_alpha_i_slope[3] alpha change with intensity config unit - slopes values*/
    int32_t cu_alpha_i_slope[3];
    /*!< cu_lsc_coeff_gr_x[6] LSC coeff function for Gr channel config unit - x values*/
    int32_t cu_lsc_coeff_gr_x[6];
    /*!< cu_lsc_coeff_gr_y[5] LSC coeff function for Gr channel config unit - y values*/
    int32_t cu_lsc_coeff_gr_y[5];
    /*!< cu_lsc_coeff_gr_slope[5] LSC coeff function for Gr channel config unit - slope values*/
    int32_t cu_lsc_coeff_gr_slope[5];
    /*!< cu_lsc_coeff_r_x[6] LSC coeff function for R channel config unit - x values*/
    int32_t cu_lsc_coeff_r_x[6];
    /*!< cu_lsc_coeff_r_y[5] LSC coeff function for R channel config unit - y values*/
    int32_t cu_lsc_coeff_r_y[5];
    /*!< cu_lsc_coeff_r_slope[5] LSC coeff function for R channel config unit - slope values*/
    int32_t cu_lsc_coeff_r_slope[5];
    /*!< cu_lsc_coeff_b_x[6] LSC coeff function for B channel config unit - x values*/
    int32_t cu_lsc_coeff_b_x[6];
    /*!< cu_lsc_coeff_b_y[5] LSC coeff function for B channel config unit - y values*/
    int32_t cu_lsc_coeff_b_y[5];
    /*!< cu_lsc_coeff_b_slope[5] LSC coeff function for B channel config unit - slope values*/
    int32_t cu_lsc_coeff_b_slope[5];
    /*!< cu_lsc_coeff_gb_x[6] LSC coeff function for Gb channel config unit - x values*/
    int32_t cu_lsc_coeff_gb_x[6];
    /*!< cu_lsc_coeff_gb_y[5] LSC coeff function for Gb channel config unit - y values*/
    int32_t cu_lsc_coeff_gb_y[5];
    /*!< cu_lsc_coeff_gb_slope[5] LSC coeff function for Gb channel config unit - slope values*/
    int32_t cu_lsc_coeff_gb_slope[5];
    /*!< start_col The distance along the vertical axis of the first pixel of the frame*/
    int32_t start_col;
    /*!< start_row The distance along the horizontal axis of the first pixel of the frame*/
    int32_t start_row;
    /*!< delta_y_counter crop supporting register*/
    int32_t delta_y_counter;
    /*!< delta_x_counter crop supporting register*/
    int32_t delta_x_counter;
    /*!< cu_nm_patch_x[10] noise model config unit - x values*/
    int32_t cu_nm_patch_x[10];
    /*!< cu_nm_patch_y[9] noise model config unit - y values*/
    int32_t cu_nm_patch_y[9];
    /*!< cu_nm_patch_slope[9] noise model config unit - slope values*/
    int32_t cu_nm_patch_slope[9];
    /*!< cu_nm_block_x[10] content detectors noise model config unit - x values*/
    int32_t cu_nm_block_x[10];
    /*!< cu_nm_block_y[9] content detectors noise model config unit - y values*/
    int32_t cu_nm_block_y[9];
    /*!< cu_nm_block_slope[9] content detectors noise model config unit - slope values*/
    int32_t cu_nm_block_slope[9];
    /*!< cu_input_compression_x[16] input compression function (16 to 12 bits) - x values*/
    int32_t cu_input_compression_x[16];
    /*!< cu_input_compression_y[15] input compression function (16 to 12 bits) - y values*/
    int32_t cu_input_compression_y[15];
    /*!< cu_input_compression_slope[15] input compression function (16 to 12 bits) - slope values*/
    int32_t cu_input_compression_slope[15];
    /*!< cu_input_decompression_x[16] input decompression function (16 to 24 bits) - x values*/
    int32_t cu_input_decompression_x[16];
    /*!< cu_input_decompression_y[15] input decompression function (16 to 24 bits) - y values*/
    int32_t cu_input_decompression_y[15];
    /*!< cu_input_decompression_slope[15] input decompression function (16 to 24 bits) - slope values*/
    int32_t cu_input_decompression_slope[15];
    /*!< cu_output_compression_x[16] output compression function (24 to 16 bits) - x values*/
    int32_t cu_output_compression_x[16];
    /*!< cu_output_compression_y[15] output compression function (24 to 16 bits) - y values*/
    int32_t cu_output_compression_y[15];
    /*!< cu_output_compression_slope[15] output compression function (24 to 16 bits) - slope values*/
    int32_t cu_output_compression_slope[15];
    /*!< nm_norm_scale Amount of bits to normalize the noise model*/
    int32_t nm_norm_scale;

} ia_pal_isp_bnlm_3_1_t;

/*! \isp struct bnlm_3_2
noise reduction
*/
typedef struct
{
    /*!< bayer_fmt Bayer format*/
    int32_t bayer_fmt;
    /*!< bypass bypass*/
    int32_t bypass;
    /*!< run_on_y a flag that indicates if the block used on Y input*/
    int32_t run_on_y;
    /*!< hv_edge_density_thr Edge density noise sigma thr*/
    int32_t hv_edge_density_thr;
    /*!< minmax_hv_edge_density_thr Edge density delta max - min thr*/
    int32_t minmax_hv_edge_density_thr;
    /*!< d_edge_density_thr Diagonal edge density noise sigma thr*/
    int32_t d_edge_density_thr;
    /*!< minmax_d_edge_density_thr Diagonal edge density delta max - min thr*/
    int32_t minmax_d_edge_density_thr;
    /*!< sigma_flat sigma flat*/
    int32_t sigma_flat;
    /*!< sigma_slope sigma slope*/
    int32_t sigma_slope;
    /*!< sigma_edge sigma edge*/
    int32_t sigma_edge;
    /*!< sigma_texture sigma texture*/
    int32_t sigma_texture;
    /*!< delta_flat delta flat*/
    int32_t delta_flat;
    /*!< delta_slope delta slope*/
    int32_t delta_slope;
    /*!< delta_edge delta edge*/
    int32_t delta_edge;
    /*!< delta_texture delta texture*/
    int32_t delta_texture;
    /*!< alpha_flat alpha flat*/
    int32_t alpha_flat;
    /*!< alpha_slope alpha slope*/
    int32_t alpha_slope;
    /*!< alpha_edge alpha edge*/
    int32_t alpha_edge;
    /*!< alpha_texture alpha texture*/
    int32_t alpha_texture;
    /*!< sigma_s spatial sigma of uniform filter*/
    int32_t sigma_s;
    /*!< sigma_s_b narrow sigma of elliptical filter*/
    int32_t sigma_s_b;
    /*!< sigma_s_a wide sigma of elliptical filter*/
    int32_t sigma_s_a;
    /*!< rx_sqr_start initial value of Rx^2*/
    int32_t rx_sqr_start;
    /*!< ry_sqr_start initial value of Ry^2*/
    int32_t ry_sqr_start;
    /*!< coordinates_shift coordinates shift*/
    int32_t coordinates_shift;
    /*!< color_penalty_weight color penalty weight*/
    int32_t color_penalty_weight;
    /*!< alpha_i_max alpha I max*/
    int32_t alpha_i_max;
    /*!< cu_ed_measure_x[4] edge density config unit - x values*/
    int32_t cu_ed_measure_x[4];
    /*!< cu_ed_measure_y[3] edge density config unit - y values*/
    int32_t cu_ed_measure_y[3];
    /*!< cu_ed_measure_slope[3] edge density config unit - slope values*/
    int32_t cu_ed_measure_slope[3];
    /*!< cu_ed_dir_measure_x[4] directional measure config unit - x values*/
    int32_t cu_ed_dir_measure_x[4];
    /*!< cu_ed_dir_measure_y[3] directional measure config unit - y values*/
    int32_t cu_ed_dir_measure_y[3];
    /*!< cu_ed_dir_measure_slope[3] directional measure config unit - slopes values*/
    int32_t cu_ed_dir_measure_slope[3];
    /*!< cu_lin_slope_measure_x[4] slope measure config unit - x values*/
    int32_t cu_lin_slope_measure_x[4];
    /*!< cu_lin_slope_measure_y[3] slope measure config unit - y values*/
    int32_t cu_lin_slope_measure_y[3];
    /*!< cu_lin_slope_measure_slope[3] slope measure config unit - slope values*/
    int32_t cu_lin_slope_measure_slope[3];
    /*!< cu_lin_slope_edge_measure_x[4] edge measure based on linear slope config unit - x values*/
    int32_t cu_lin_slope_edge_measure_x[4];
    /*!< cu_lin_slope_edge_measure_y[3] edge measure based on linear slope config unit - y values*/
    int32_t cu_lin_slope_edge_measure_y[3];
    /*!< cu_lin_slope_edge_measure_slope[3] edge measure based on linear slope config unit - slope values*/
    int32_t cu_lin_slope_edge_measure_slope[3];
    /*!< cu_var_measure_x[4] variance measure config unit - x values*/
    int32_t cu_var_measure_x[4];
    /*!< cu_var_measure_y[3] variance measure config unit - y values*/
    int32_t cu_var_measure_y[3];
    /*!< cu_var_measure_slope[3] variance measure config unit - slope values*/
    int32_t cu_var_measure_slope[3];
    /*!< cu_var_edge_measure_x[4] variance edge measure config unit - x values*/
    int32_t cu_var_edge_measure_x[4];
    /*!< cu_var_edge_measure_y[3] variance edge measure config unit - y values*/
    int32_t cu_var_edge_measure_y[3];
    /*!< cu_var_edge_measure_slope[3] variance edge measure config unit - slope values*/
    int32_t cu_var_edge_measure_slope[3];
    /*!< cu_alpha_i_x[4] alpha change with intensity config unit - x values*/
    int32_t cu_alpha_i_x[4];
    /*!< cu_alpha_i_y[3] alpha change with intensity config unit - y values*/
    int32_t cu_alpha_i_y[3];
    /*!< cu_alpha_i_slope[3] alpha change with intensity config unit - slopes values*/
    int32_t cu_alpha_i_slope[3];
    /*!< cu_lsc_coeff_gr_x[6] LSC coeff function for Gr channel config unit - x values*/
    int32_t cu_lsc_coeff_gr_x[6];
    /*!< cu_lsc_coeff_gr_y[5] LSC coeff function for Gr channel config unit - y values*/
    int32_t cu_lsc_coeff_gr_y[5];
    /*!< cu_lsc_coeff_gr_slope[5] LSC coeff function for Gr channel config unit - slope values*/
    int32_t cu_lsc_coeff_gr_slope[5];
    /*!< cu_lsc_coeff_r_x[6] LSC coeff function for R channel config unit - x values*/
    int32_t cu_lsc_coeff_r_x[6];
    /*!< cu_lsc_coeff_r_y[5] LSC coeff function for R channel config unit - y values*/
    int32_t cu_lsc_coeff_r_y[5];
    /*!< cu_lsc_coeff_r_slope[5] LSC coeff function for R channel config unit - slope values*/
    int32_t cu_lsc_coeff_r_slope[5];
    /*!< cu_lsc_coeff_b_x[6] LSC coeff function for B channel config unit - x values*/
    int32_t cu_lsc_coeff_b_x[6];
    /*!< cu_lsc_coeff_b_y[5] LSC coeff function for B channel config unit - y values*/
    int32_t cu_lsc_coeff_b_y[5];
    /*!< cu_lsc_coeff_b_slope[5] LSC coeff function for B channel config unit - slope values*/
    int32_t cu_lsc_coeff_b_slope[5];
    /*!< cu_lsc_coeff_gb_x[6] LSC coeff function for Gb channel config unit - x values*/
    int32_t cu_lsc_coeff_gb_x[6];
    /*!< cu_lsc_coeff_gb_y[5] LSC coeff function for Gb channel config unit - y values*/
    int32_t cu_lsc_coeff_gb_y[5];
    /*!< cu_lsc_coeff_gb_slope[5] LSC coeff function for Gb channel config unit - slope values*/
    int32_t cu_lsc_coeff_gb_slope[5];
    /*!< start_col The distance along the vertical axis of the first pixel of the frame*/
    int32_t start_col;
    /*!< start_row The distance along the horizontal axis of the first pixel of the frame*/
    int32_t start_row;
    /*!< delta_y_counter crop supporting register*/
    int32_t delta_y_counter;
    /*!< delta_x_counter crop supporting register*/
    int32_t delta_x_counter;
    /*!< cu_nm_patch_x[10] noise model config unit - x values*/
    int32_t cu_nm_patch_x[10];
    /*!< cu_nm_patch_y[9] noise model config unit - y values*/
    int32_t cu_nm_patch_y[9];
    /*!< cu_nm_patch_slope[9] noise model config unit - slope values*/
    int32_t cu_nm_patch_slope[9];
    /*!< cu_nm_block_x[10] content detectors noise model config unit - x values*/
    int32_t cu_nm_block_x[10];
    /*!< cu_nm_block_y[9] content detectors noise model config unit - y values*/
    int32_t cu_nm_block_y[9];
    /*!< cu_nm_block_slope[9] content detectors noise model config unit - slope values*/
    int32_t cu_nm_block_slope[9];
    /*!< cu_input_compression_x[16] input compression function (16 to 12 bits) - x values*/
    int32_t cu_input_compression_x[16];
    /*!< cu_input_compression_y[15] input compression function (16 to 12 bits) - y values*/
    int32_t cu_input_compression_y[15];
    /*!< cu_input_compression_slope[15] input compression function (16 to 12 bits) - slope values*/
    int32_t cu_input_compression_slope[15];
    /*!< cu_input_decompression_x[16] input decompression function (16 to 24 bits) - x values*/
    int32_t cu_input_decompression_x[16];
    /*!< cu_input_decompression_y[15] input decompression function (16 to 24 bits) - y values*/
    int32_t cu_input_decompression_y[15];
    /*!< cu_input_decompression_slope[15] input decompression function (16 to 24 bits) - slope values*/
    int32_t cu_input_decompression_slope[15];
    /*!< cu_output_compression_x[16] output compression function (24 to 16 bits) - x values*/
    int32_t cu_output_compression_x[16];
    /*!< cu_output_compression_y[15] output compression function (24 to 16 bits) - y values*/
    int32_t cu_output_compression_y[15];
    /*!< cu_output_compression_slope[15] output compression function (24 to 16 bits) - slope values*/
    int32_t cu_output_compression_slope[15];
    /*!< nm_norm_scale Amount of bits to normalize the noise model*/
    int32_t nm_norm_scale;

} ia_pal_isp_bnlm_3_2_t;

/*! \isp struct bnlm_3_3
noise reduction
*/
typedef struct
{
    /*!< bayer_fmt Bayer format*/
    int32_t bayer_fmt;
    /*!< bypass bypass*/
    int32_t bypass;
    /*!< run_on_y a flag that indicates if the block used on Y input*/
    int32_t run_on_y;
    /*!< hv_edge_density_thr Edge density noise sigma thr*/
    int32_t hv_edge_density_thr;
    /*!< minmax_hv_edge_density_thr Edge density delta max - min thr*/
    int32_t minmax_hv_edge_density_thr;
    /*!< d_edge_density_thr Diagonal edge density noise sigma thr*/
    int32_t d_edge_density_thr;
    /*!< minmax_d_edge_density_thr Diagonal edge density delta max - min thr*/
    int32_t minmax_d_edge_density_thr;
    /*!< sigma_flat sigma flat*/
    int32_t sigma_flat;
    /*!< sigma_slope sigma slope*/
    int32_t sigma_slope;
    /*!< sigma_edge sigma edge*/
    int32_t sigma_edge;
    /*!< sigma_texture sigma texture*/
    int32_t sigma_texture;
    /*!< delta_flat delta flat*/
    int32_t delta_flat;
    /*!< delta_slope delta slope*/
    int32_t delta_slope;
    /*!< delta_edge delta edge*/
    int32_t delta_edge;
    /*!< delta_texture delta texture*/
    int32_t delta_texture;
    /*!< alpha_flat alpha flat*/
    int32_t alpha_flat;
    /*!< alpha_slope alpha slope*/
    int32_t alpha_slope;
    /*!< alpha_edge alpha edge*/
    int32_t alpha_edge;
    /*!< alpha_texture alpha texture*/
    int32_t alpha_texture;
    /*!< sigma_s spatial sigma of uniform filter*/
    int32_t sigma_s;
    /*!< sigma_s_b narrow sigma of elliptical filter*/
    int32_t sigma_s_b;
    /*!< sigma_s_a wide sigma of elliptical filter*/
    int32_t sigma_s_a;
    /*!< rx_sqr_start initial value of Rx^2*/
    int32_t rx_sqr_start;
    /*!< ry_sqr_start initial value of Ry^2*/
    int32_t ry_sqr_start;
    /*!< coordinates_shift coordinates shift*/
    int32_t coordinates_shift;
    /*!< color_penalty_weight color penalty weight*/
    int32_t color_penalty_weight;
    /*!< alpha_i_max alpha I max*/
    int32_t alpha_i_max;
    /*!< cu_ed_measure_x[4] edge density config unit - x values*/
    int32_t cu_ed_measure_x[4];
    /*!< cu_ed_measure_y[3] edge density config unit - y values*/
    int32_t cu_ed_measure_y[3];
    /*!< cu_ed_measure_slope[3] edge density config unit - slope values*/
    int32_t cu_ed_measure_slope[3];
    /*!< cu_ed_dir_measure_x[4] directional measure config unit - x values*/
    int32_t cu_ed_dir_measure_x[4];
    /*!< cu_ed_dir_measure_y[3] directional measure config unit - y values*/
    int32_t cu_ed_dir_measure_y[3];
    /*!< cu_ed_dir_measure_slope[3] directional measure config unit - slopes values*/
    int32_t cu_ed_dir_measure_slope[3];
    /*!< cu_lin_slope_measure_x[4] slope measure config unit - x values*/
    int32_t cu_lin_slope_measure_x[4];
    /*!< cu_lin_slope_measure_y[3] slope measure config unit - y values*/
    int32_t cu_lin_slope_measure_y[3];
    /*!< cu_lin_slope_measure_slope[3] slope measure config unit - slope values*/
    int32_t cu_lin_slope_measure_slope[3];
    /*!< cu_lin_slope_edge_measure_x[4] edge measure based on linear slope config unit - x values*/
    int32_t cu_lin_slope_edge_measure_x[4];
    /*!< cu_lin_slope_edge_measure_y[3] edge measure based on linear slope config unit - y values*/
    int32_t cu_lin_slope_edge_measure_y[3];
    /*!< cu_lin_slope_edge_measure_slope[3] edge measure based on linear slope config unit - slope values*/
    int32_t cu_lin_slope_edge_measure_slope[3];
    /*!< cu_var_measure_x[4] variance measure config unit - x values*/
    int32_t cu_var_measure_x[4];
    /*!< cu_var_measure_y[3] variance measure config unit - y values*/
    int32_t cu_var_measure_y[3];
    /*!< cu_var_measure_slope[3] variance measure config unit - slope values*/
    int32_t cu_var_measure_slope[3];
    /*!< cu_var_edge_measure_x[4] variance edge measure config unit - x values*/
    int32_t cu_var_edge_measure_x[4];
    /*!< cu_var_edge_measure_y[3] variance edge measure config unit - y values*/
    int32_t cu_var_edge_measure_y[3];
    /*!< cu_var_edge_measure_slope[3] variance edge measure config unit - slope values*/
    int32_t cu_var_edge_measure_slope[3];
    /*!< cu_alpha_i_x[4] alpha change with intensity config unit - x values*/
    int32_t cu_alpha_i_x[4];
    /*!< cu_alpha_i_y[3] alpha change with intensity config unit - y values*/
    int32_t cu_alpha_i_y[3];
    /*!< cu_alpha_i_slope[3] alpha change with intensity config unit - slopes values*/
    int32_t cu_alpha_i_slope[3];
    /*!< start_col The distance along the vertical axis of the first pixel of the frame*/
    int32_t start_col;
    /*!< start_row The distance along the horizontal axis of the first pixel of the frame*/
    int32_t start_row;
    /*!< delta_y_counter crop supporting register*/
    int32_t delta_y_counter;
    /*!< delta_x_counter crop supporting register*/
    int32_t delta_x_counter;
    /*!< cu_nm_patch_x[10] noise model config unit - x values*/
    int32_t cu_nm_patch_x[10];
    /*!< cu_nm_patch_y[9] noise model config unit - y values*/
    int32_t cu_nm_patch_y[9];
    /*!< cu_nm_patch_slope[9] noise model config unit - slope values*/
    int32_t cu_nm_patch_slope[9];
    /*!< cu_nm_block_x[10] content detectors noise model config unit - x values*/
    int32_t cu_nm_block_x[10];
    /*!< cu_nm_block_y[9] content detectors noise model config unit - y values*/
    int32_t cu_nm_block_y[9];
    /*!< cu_nm_block_slope[9] content detectors noise model config unit - slope values*/
    int32_t cu_nm_block_slope[9];
    /*!< cu_input_compression_x[16] input compression function (16 to 12 bits) - x values*/
    int32_t cu_input_compression_x[16];
    /*!< cu_input_compression_y[15] input compression function (16 to 12 bits) - y values*/
    int32_t cu_input_compression_y[15];
    /*!< cu_input_compression_slope[15] input compression function (16 to 12 bits) - slope values*/
    int32_t cu_input_compression_slope[15];
    /*!< cu_input_decompression_x[16] input decompression function (16 to 24 bits) - x values*/
    int32_t cu_input_decompression_x[16];
    /*!< cu_input_decompression_y[15] input decompression function (16 to 24 bits) - y values*/
    int32_t cu_input_decompression_y[15];
    /*!< cu_input_decompression_slope[15] input decompression function (16 to 24 bits) - slope values*/
    int32_t cu_input_decompression_slope[15];
    /*!< cu_output_compression_x[16] output compression function (24 to 16 bits) - x values*/
    int32_t cu_output_compression_x[16];
    /*!< cu_output_compression_y[15] output compression function (24 to 16 bits) - y values*/
    int32_t cu_output_compression_y[15];
    /*!< cu_output_compression_slope[15] output compression function (24 to 16 bits) - slope values*/
    int32_t cu_output_compression_slope[15];
    /*!< nm_norm_scale Amount of bits to normalize the noise model*/
    int32_t nm_norm_scale;
    /*!< lsc_coeff_lut_gr[32] Shading coeffcients along the distance from the frame optical center*/
    int32_t lsc_coeff_lut_gr[32];
    /*!< lsc_coeff_lut_gb[32] Shading coeffcients along the distance from the frame optical center*/
    int32_t lsc_coeff_lut_gb[32];
    /*!< lsc_coeff_lut_r[32] Shading coeffcients along the distance from the frame optical center*/
    int32_t lsc_coeff_lut_r[32];
    /*!< lsc_coeff_lut_b[32] Shading coeffcients along the distance from the frame optical center*/
    int32_t lsc_coeff_lut_b[32];

} ia_pal_isp_bnlm_3_3_t;

/*! \isp struct burst_isp
3A results are passed to burstisp
*/
typedef struct
{
    /*!< exp_time_us exposure time*/
    int32_t exp_time_us;
    /*!< analog_gain Although the parameter is defined as analog_gain we are using it as total_gain. U24.8 precision*/
    int32_t analog_gain;
    /*!< wb_gain_gr Absolute WB gain for Gr in U3.13 format*/
    uint32_t wb_gain_gr;
    /*!< wb_gain_r Absolute WB gain for R in U3.13 format*/
    uint32_t wb_gain_r;
    /*!< wb_gain_b Absolute WB gain for Bin U3.13 format*/
    uint32_t wb_gain_b;
    /*!< wb_gain_gb Absolute WB gain for Gb in U3.13 format*/
    uint32_t wb_gain_gb;
    /*!< lut_width LUT width*/
    int32_t lut_width;
    /*!< lut_height LUT height*/
    int32_t lut_height;
    /*!< num_channel Number of channels*/
    int32_t num_channel;
    /*!< lut[16384] LUT_width*LUT_height*Num_channel*/
    int32_t lut[16384];

} ia_pal_isp_burst_isp_t;

/*! \isp struct bxt_3a_ccm

*/
typedef struct
{
    /*!< gain_cx[8] WB coefficients*/
    int32_t gain_cx[8];
    /*!< m_1x[4] CCM matrix coefficients M11 - M14*/
    int32_t m_1x[4];
    /*!< m_2x[4] CCM matrix coefficients M21 - M24*/
    int32_t m_2x[4];
    /*!< m_3x[4] CCM matrix coefficients M31 - M34*/
    int32_t m_3x[4];
    /*!< c_0x[8] Y-calc matrix coefficients C01 - C08*/
    int32_t c_0x[8];
    /*!< c_1x[8] Y-calc matrix coefficients C11 - C18*/
    int32_t c_1x[8];
    /*!< c_2x[8] Y-calc matrix coefficients C21 - C28*/
    int32_t c_2x[8];
    /*!< c_3x[8] Y-calc matrix coefficients C31 - C38*/
    int32_t c_3x[8];
    /*!< sensor_mode 0: 1x1 CFA (array sensor); 1: 2 x 2 CFA; 2: 4 x 4 CFA*/
    int32_t sensor_mode;
    /*!< ccm_ycalc_en 0: CCM_YCALC is bypassed; 1: CCM_YCALC is enabled*/
    int32_t ccm_ycalc_en;
    /*!< pat_00 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_00;
    /*!< pat_01 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_01;
    /*!< pat_02 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_02;
    /*!< pat_03 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_03;
    /*!< pat_10 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_10;
    /*!< pat_11 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_11;
    /*!< pat_12 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_12;
    /*!< pat_13 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_13;
    /*!< pat_20 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_20;
    /*!< pat_21 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_21;
    /*!< pat_22 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_22;
    /*!< pat_23 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_23;
    /*!< pat_30 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_30;
    /*!< pat_31 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_31;
    /*!< pat_32 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_32;
    /*!< pat_33 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_33;

} ia_pal_isp_bxt_3a_ccm_t;

/*! \isp struct bxt_acm

*/
typedef struct
{
    /*!< m_acm_bypass Block bypass for HW use*/
    int32_t m_acm_bypass;
    /*!< m_enable_chroma_lut Enable Chroma adaptation by LUT*/
    int32_t m_enable_chroma_lut;
    /*!< m_enable_luma_lut Enable Luma adaptation by LUT*/
    int32_t m_enable_luma_lut;
    /*!< m_enable_negative_pixels enable negative pixels in output*/
    int32_t m_enable_negative_pixels;
    /*!< m_enable_chroma_low_light_mode Enable Chroma adaptation in low light mode*/
    int32_t m_enable_chroma_low_light_mode;
    /*!< m_enable_luma_low_light_mode Enable Luma adaptation in low light mode*/
    int32_t m_enable_luma_low_light_mode;
    /*!< m_num_of_sectors number of sectors, U5.0*/
    int32_t m_num_of_sectors;
    /*!< m_chromagrid2uniformlut_cu_x[9] U12.0*/
    int32_t m_chromagrid2uniformlut_cu_x[9];
    /*!< m_chromagrid2uniformlut_cu_a[8] S4.10*/
    int32_t m_chromagrid2uniformlut_cu_a[8];
    /*!< m_lumagrid2uniformlut_cu_x[9] U12.0*/
    int32_t m_lumagrid2uniformlut_cu_x[9];
    /*!< m_lumagrid2uniformlut_cu_a[8] S4.10*/
    int32_t m_lumagrid2uniformlut_cu_a[8];
    /*!< m_ccm_matrix_arr[216] CCM's table (one per sector), S3.11*/
    int32_t m_ccm_matrix_arr[216];
    /*!< m_hue_boundary_arr[24] Table of sectors boundaries, U11.0*/
    int32_t m_hue_boundary_arr[24];
    /*!< m_ccm_index_arr[25] Table of the sectors indices, U5.0*/
    int32_t m_ccm_index_arr[25];
    /*!< m_offr CCM bias for R, S13.0*/
    int32_t m_offr;
    /*!< m_offg CCM bias for G, S13.0*/
    int32_t m_offg;
    /*!< m_offb CCM bias for B, S13.0*/
    int32_t m_offb;
    /*!< m_luma_coeff_arr[3] Luna coefficients (weights), U0.8*/
    int32_t m_luma_coeff_arr[3];
    /*!< m_adapt_chroma_lut[81] Chroma adaptation LUT, U2.7*/
    int32_t m_adapt_chroma_lut[81];
    /*!< m_adapt_luma_lut[81] Luma adaptation LUT, S13.0*/
    int32_t m_adapt_luma_lut[81];
    /*!< m_enable_low_light_mode Enable CC's adaptation low light mode*/
    int32_t m_enable_low_light_mode;

} ia_pal_isp_bxt_acm_t;

/*! \isp struct bxt_aestatistics

*/
typedef struct
{
    /*!< cell0[96] weighted histogram grid values*/
    int32_t cell0[96];
    /*!< cell1[96] weighted histogram grid values*/
    int32_t cell1[96];
    /*!< cell2[96] weighted histogram grid values*/
    int32_t cell2[96];
    /*!< cell3[96] weighted histogram grid values*/
    int32_t cell3[96];
    /*!< cell4[96] weighted histogram grid values*/
    int32_t cell4[96];
    /*!< cell5[96] weighted histogram grid values*/
    int32_t cell5[96];
    /*!< cell6[96] weighted histogram grid values*/
    int32_t cell6[96];
    /*!< cell7[96] weighted histogram grid values*/
    int32_t cell7[96];
    /*!< grid_width represents number of horizontal grid cells*/
    int32_t grid_width;
    /*!< grid_height represents number of vertical grid cells*/
    int32_t grid_height;
    /*!< block_width Log2 the width of each grid cell (8,16,32,64,128, 256)*/
    int32_t block_width;
    /*!< block_height Log2 the height of each grid cell (8,16,32,64,128, 256)*/
    int32_t block_height;
    /*!< ae_en 0: FF will not write to the AE  array; 1: FF will write*/
    int32_t ae_en;
    /*!< rst_hist_array 1: triggers the reset mechanism for the GLB_HIST*/
    int32_t rst_hist_array;
    /*!< x_start X top left corner of the grid. 0 <= x_start <= (frame_width - 1)*/
    int32_t x_start;
    /*!< y_start Y top left corner of the grid. 0 <= y_start <= (frame_height - 1)*/
    int32_t y_start;
    /*!< x_end X bottom right corner of the grid. x_end = x_start + (grid_width << block_width) - 1*/
    int32_t x_end;
    /*!< y_end Y bottom right corner of the grid. y_end = y_start + (grid_height << block_height) - 1*/
    int32_t y_end;
    /*!< sensor_mode 0: 1x1 CFA (array sensor); 1: 2 x 2 CFA; 2: 4 x 4 CFA*/
    int32_t sensor_mode;
    /*!< pat_00 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_00;
    /*!< pat_01 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_01;
    /*!< pat_02 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_02;
    /*!< pat_03 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_03;
    /*!< pat_10 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_10;
    /*!< pat_11 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_11;
    /*!< pat_12 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_12;
    /*!< pat_13 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_13;
    /*!< pat_20 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_20;
    /*!< pat_21 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_21;
    /*!< pat_22 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_22;
    /*!< pat_23 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_23;
    /*!< pat_30 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_30;
    /*!< pat_31 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_31;
    /*!< pat_32 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_32;
    /*!< pat_33 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_33;

} ia_pal_isp_bxt_aestatistics_t;

/*! \isp struct bxt_af_awb_fr_statistics

*/
typedef struct
{
    /*!< grid_width represents number of horizontal grid cells*/
    int32_t grid_width;
    /*!< grid_height represents number of vertical grid cells*/
    int32_t grid_height;
    /*!< block_width Log2 the width of each grid cell (8,16,32,64,128,256)*/
    int32_t block_width;
    /*!< block_height Log2 the height of each grid cell (8,16,32,64,128,256)*/
    int32_t block_height;
    /*!< grid_height_per_slice # of blocks (vert) per Meta-Data Slice (grid_height_per_slice * grid_width <= 32; grid_height_per_slice <= 2)*/
    int32_t grid_height_per_slice;
    /*!< y_fr_en 0: FF will not write to the Y array; 1: FF will write*/
    int32_t y_fr_en;
    /*!< awb_fr_en 0: FF will not write to the AWB_FR array; 1: FF will write*/
    int32_t awb_fr_en;
    /*!< ff_en 0: FF is bypassed; 1: FF is enabled*/
    int32_t ff_en;
    /*!< x_start X top left corner of the grid. 20 <= x_start <= (frame_width - 1)*/
    int32_t x_start;
    /*!< y_start Y top left corner of the grid. 0 <= x_start <= (frame_height - 1)*/
    int32_t y_start;
    /*!< x_end X bottom right corner of the grid. x_end <= (frame_width - 1 - 20)*/
    int32_t x_end;
    /*!< y_end Y bottom right corner of the grid. y_end <= (frame_height - 1)*/
    int32_t y_end;
    /*!< shftr_val_x[7] represents log2(num of pixels of the estimated colour component in a block) for Y00, Y01, Y10, Y11, R, G, B*/
    int32_t shftr_val_x[7];
    /*!< gx0[4] Ycalc contribution ratio for Pat_ij*/
    int32_t gx0[4];
    /*!< gx1[4] Ycalc contribution ratio for Pat_ij*/
    int32_t gx1[4];
    /*!< gx2[4] Ycalc contribution ratio for Pat_ij*/
    int32_t gx2[4];
    /*!< gx3[4] Ycalc contribution ratio for Pat_ij*/
    int32_t gx3[4];
    /*!< mask_y0 selecting the relevant pixels for Y0; bit k corresponds to Row * 4 + Column*/
    int32_t mask_y0;
    /*!< mask_y1 selecting the relevant pixels for Y1; bit k corresponds to Row * 4 + Column*/
    int32_t mask_y1;
    /*!< oe_y0 Output Enable for Y0; bit k corresponds to Row * 2 + Column*/
    int32_t oe_y0;
    /*!< oe_y1 Output Enable for Y1; bit k corresponds to Row * 2 + Column*/
    int32_t oe_y1;
    /*!< on_x_y0[4] Y0 estimation normalization (00, 01, 10, 11)*/
    int32_t on_x_y0[4];
    /*!< on_x_y1[4] Y1 estimation normalization (00, 01, 10, 11)*/
    int32_t on_x_y1[4];
    /*!< r_select selecting the relevant R pixels; bit k corresponds to Row * 4 + Column*/
    int32_t r_select;
    /*!< g_select selecting the relevant G pixels; bit k corresponds to Row * 4 + Column + 16*/
    int32_t g_select;
    /*!< b_select selecting the relevant B pixels; bit k corresponds to Row * 4 + Column*/
    int32_t b_select;
    /*!< y00_filter_coeff[6] filter coefficients for Y00 (A1, A2, A3, A4, A5, A6)*/
    int32_t y00_filter_coeff[6];
    /*!< y00_filter_sign_vec sign vector for Y00*/
    int32_t y00_filter_sign_vec;
    /*!< y01_filter_coeff[6] filter coefficients for Y01 (A1, A2, A3, A4, A5, A6)*/
    int32_t y01_filter_coeff[6];
    /*!< y01_filter_sign_vec sign vector for Y01*/
    int32_t y01_filter_sign_vec;
    /*!< y10_filter_coeff[6] filter coefficients for Y10 (A1, A2, A3, A4, A5, A6)*/
    int32_t y10_filter_coeff[6];
    /*!< y10_filter_sign_vec sign vector for Y10*/
    int32_t y10_filter_sign_vec;
    /*!< y11_filter_coeff[6] filter coefficients for Y11 (A1, A2, A3, A4, A5, A6)*/
    int32_t y11_filter_coeff[6];
    /*!< y11_filter_sign_vec sign vector for Y11*/
    int32_t y11_filter_sign_vec;
    /*!< r_filter_coeff[6] filter coefficients for R (A1, A2, A3, A4, A5, A6)*/
    int32_t r_filter_coeff[6];
    /*!< r_filter_sign_vec sign vector for R*/
    int32_t r_filter_sign_vec;
    /*!< g_filter_coeff[6] filter coefficients for G (A1, A2, A3, A4, A5, A6)*/
    int32_t g_filter_coeff[6];
    /*!< g_filter_sign_vec sign vector for G*/
    int32_t g_filter_sign_vec;
    /*!< b_filter_coeff[6] filter coefficients for B (A1, A2, A3, A4, A5, A6)*/
    int32_t b_filter_coeff[6];
    /*!< b_filter_sign_vec sign vector for B*/
    int32_t b_filter_sign_vec;
    /*!< nf_x[7] Filter response normalization factors for Y00, Y01, Y10, Y11, R, G, B*/
    int32_t nf_x[7];
    /*!< sensor_mode 0: 1x1 CFA (array sensor); 1: 2 x 2 CFA; 2: 4 x 4 CFA*/
    int32_t sensor_mode;

} ia_pal_isp_bxt_af_awb_fr_statistics_t;

/*! \isp struct bxt_applycorrection

*/
typedef struct
{
    /*!< global_enable global enable*/
    int32_t global_enable;
    /*!< gdc_enable gdc enable*/
    int32_t gdc_enable;
    /*!< dpc_enable dpc enable*/
    int32_t dpc_enable;
    /*!< green_pos gb position*/
    int32_t green_pos;

} ia_pal_isp_bxt_applycorrection_t;

/*! \isp struct bxt_awbstatistics

*/
typedef struct
{
    /*!< grid_width represents number of horizontal grid cells*/
    int32_t grid_width;
    /*!< grid_height represents number of vertical grid cells*/
    int32_t grid_height;
    /*!< block_width Log2 the width of each grid cell (8,16,32,64,128)*/
    int32_t block_width;
    /*!< block_height Log2 the height of each grid cell (8,16,32,64,128)*/
    int32_t block_height;
    /*!< grid_height_per_slice # of blocks in vert.axis per Meta-Data Slice (grid_height_per_slice * grid_width <= 160)*/
    int32_t grid_height_per_slice;
    /*!< awb_en 0: FF will not write to the AWB  array; 1: FF will write*/
    int32_t awb_en;
    /*!< rgbs_incl_sat 0: do not include saturated quads in the average; 1: include saturated quads in the average*/
    int32_t rgbs_incl_sat;
    /*!< x_start X top left corner of the grid. 0 <= x_start <= (frame_width - 1)*/
    int32_t x_start;
    /*!< y_start Y top left corner of the grid. 0 <= y_start <= (frame_height - 1)*/
    int32_t y_start;
    /*!< x_end X bottom right corner of the grid. x_end = x_start + (grid_width << block_width) - 1*/
    int32_t x_end;
    /*!< y_end Y bottom right corner of the grid. y_end = y_start + (grid_height << block_height) - 1*/
    int32_t y_end;
    /*!< sensor_mode 0: 1x1 CFA (array sensor); 1: 2 x 2 CFA; 2: 4 x 4 CFA*/
    int32_t sensor_mode;
    /*!< pat_00 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_00;
    /*!< pat_01 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_01;
    /*!< pat_02 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_02;
    /*!< pat_03 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_03;
    /*!< pat_10 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_10;
    /*!< pat_11 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_11;
    /*!< pat_12 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_12;
    /*!< pat_13 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_13;
    /*!< pat_20 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_20;
    /*!< pat_21 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_21;
    /*!< pat_22 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_22;
    /*!< pat_23 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_23;
    /*!< pat_30 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_30;
    /*!< pat_31 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_31;
    /*!< pat_32 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_32;
    /*!< pat_33 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_33;
    /*!< rgbs_thr_cx[8] RGBS threshold value (C0, C1, C2, C3, C4, C5, C6, C7)*/
    int32_t rgbs_thr_cx[8];
    /*!< shftr_val_cx[8] ShiftVal is derived from log2(number of pixels from C0-C7 color channel in a cell)*/
    int32_t shftr_val_cx[8];
    /*!< shftr_sat represents log2(num of pixels in cell)*/
    int32_t shftr_sat;

} ia_pal_isp_bxt_awbstatistics_t;

/*! \isp struct bxt_blc

*/
typedef struct
{
    /*!< cfa_type cfa type 0=1x1 1=2x2 2=4x4*/
    int32_t cfa_type;
    /*!< bypass bypass for the filter*/
    int32_t bypass;
    /*!< dummy_bypass dumy bypass for the filter. Required to allign block API to RTL registers*/
    int32_t dummy_bypass;
    /*!< fixobc00 black level value*/
    int32_t fixobc00;
    /*!< fixobc01 black level value*/
    int32_t fixobc01;
    /*!< fixobc02 black level value*/
    int32_t fixobc02;
    /*!< fixobc03 black level value*/
    int32_t fixobc03;
    /*!< fixobc10 black level value*/
    int32_t fixobc10;
    /*!< fixobc11 black level value*/
    int32_t fixobc11;
    /*!< fixobc12 black level value*/
    int32_t fixobc12;
    /*!< fixobc13 black level value*/
    int32_t fixobc13;
    /*!< fixobc20 black level value*/
    int32_t fixobc20;
    /*!< fixobc21 black level value*/
    int32_t fixobc21;
    /*!< fixobc22 black level value*/
    int32_t fixobc22;
    /*!< fixobc23 black level value*/
    int32_t fixobc23;
    /*!< fixobc30 black level value*/
    int32_t fixobc30;
    /*!< fixobc31 black level value*/
    int32_t fixobc31;
    /*!< fixobc32 black level value*/
    int32_t fixobc32;
    /*!< fixobc33 black level value*/
    int32_t fixobc33;

} ia_pal_isp_bxt_blc_t;

/*! \isp struct bxt_blc_b

*/
typedef struct
{
    /*!< cfa_type cfa type 0=1x1 1=2x2 2=4x4*/
    int32_t cfa_type;
    /*!< bypass bypass for the filter*/
    int32_t bypass;
    /*!< dummy_bypass dumy bypass for the filter. Required to allign block API to RTL registers*/
    int32_t dummy_bypass;
    /*!< fixobc00 black level value*/
    int32_t fixobc00;
    /*!< fixobc01 black level value*/
    int32_t fixobc01;
    /*!< fixobc02 black level value*/
    int32_t fixobc02;
    /*!< fixobc03 black level value*/
    int32_t fixobc03;
    /*!< fixobc10 black level value*/
    int32_t fixobc10;
    /*!< fixobc11 black level value*/
    int32_t fixobc11;
    /*!< fixobc12 black level value*/
    int32_t fixobc12;
    /*!< fixobc13 black level value*/
    int32_t fixobc13;
    /*!< fixobc20 black level value*/
    int32_t fixobc20;
    /*!< fixobc21 black level value*/
    int32_t fixobc21;
    /*!< fixobc22 black level value*/
    int32_t fixobc22;
    /*!< fixobc23 black level value*/
    int32_t fixobc23;
    /*!< fixobc30 black level value*/
    int32_t fixobc30;
    /*!< fixobc31 black level value*/
    int32_t fixobc31;
    /*!< fixobc32 black level value*/
    int32_t fixobc32;
    /*!< fixobc33 black level value*/
    int32_t fixobc33;

} ia_pal_isp_bxt_blc_b_t;

/*! \isp struct bxt_blc_c

*/
typedef struct
{
    /*!< cfa_type cfa type 0=1x1 1=2x2 2=4x4*/
    int32_t cfa_type;
    /*!< bypass bypass for the filter*/
    int32_t bypass;
    /*!< dummy_bypass dumy bypass for the filter. Required to allign block API to RTL registers*/
    int32_t dummy_bypass;
    /*!< fixobc00 black level value*/
    int32_t fixobc00;
    /*!< fixobc01 black level value*/
    int32_t fixobc01;
    /*!< fixobc02 black level value*/
    int32_t fixobc02;
    /*!< fixobc03 black level value*/
    int32_t fixobc03;
    /*!< fixobc10 black level value*/
    int32_t fixobc10;
    /*!< fixobc11 black level value*/
    int32_t fixobc11;
    /*!< fixobc12 black level value*/
    int32_t fixobc12;
    /*!< fixobc13 black level value*/
    int32_t fixobc13;
    /*!< fixobc20 black level value*/
    int32_t fixobc20;
    /*!< fixobc21 black level value*/
    int32_t fixobc21;
    /*!< fixobc22 black level value*/
    int32_t fixobc22;
    /*!< fixobc23 black level value*/
    int32_t fixobc23;
    /*!< fixobc30 black level value*/
    int32_t fixobc30;
    /*!< fixobc31 black level value*/
    int32_t fixobc31;
    /*!< fixobc32 black level value*/
    int32_t fixobc32;
    /*!< fixobc33 black level value*/
    int32_t fixobc33;

} ia_pal_isp_bxt_blc_c_t;

/*! \isp struct bxt_bnlm

*/
typedef struct
{
    /*!< div_unit_slope[15] DIV_UNIT_SLOPE - fixed value array for config unit*/
    int32_t div_unit_slope[15];
    /*!< div_unit_x[16] DIV_UNIT_X - fixed value array for config unit*/
    int32_t div_unit_x[16];
    /*!< div_unit_y[15] DIV_UNIT_Y - fixed value array for config unit*/
    int32_t div_unit_y[15];
    /*!< m_bypass Block bypass for HW use*/
    int32_t m_bypass;
    /*!< m_bcandshift1[4] m_BCandShift1: Group B candidate factoring params*/
    int32_t m_bcandshift1[4];
    /*!< m_bcandshift2[4] m_BCandShift2: Group B candidate factoring params*/
    int32_t m_bcandshift2[4];
    /*!< m_bcandsubflag[4] m_BCandSubFlag: Group B candidate factoring params*/
    int32_t m_bcandsubflag[4];
    /*!< m_ccandshift1[4] m_CCandShift1: Group C candidate factoring params*/
    int32_t m_ccandshift1[4];
    /*!< m_ccandshift2[4] m_CCandShift2:  Group C candidate factoring params*/
    int32_t m_ccandshift2[4];
    /*!< m_ccandsubflag[4] m_CCandSubFlag:  Group C candidate factoring params*/
    int32_t m_ccandsubflag[4];
    /*!< m_candconstellation[2] m_CandConstellation: (0,1,2)  (1=Dendse 10x10 for Y video  0=16x16 sparse for Bayer)    2=Obsolete   input format related params;   Only first element is in use*/
    int32_t m_candconstellation[2];
    /*!< m_dcandshift1[4] m_DCandShift1:  Group D candidate factoring params*/
    int32_t m_dcandshift1[4];
    /*!< m_dcandshift2[4] m_DCandShift2:   Group D candidate factoring params*/
    int32_t m_dcandshift2[4];
    /*!< m_dcandsubflag[4] m_DCandSubFlag:   Group D candidate factoring params*/
    int32_t m_dcandsubflag[4];
    /*!< m_detail_radial_lut_f1[12] m_DETAIL_RADIAL_LUT_f1*/
    int32_t m_detail_radial_lut_f1[12];
    /*!< m_detail_radial_lut_f2[12] m_DETAIL_RADIAL_LUT_f2*/
    int32_t m_detail_radial_lut_f2[12];
    /*!< m_detail_radial_lut_s1[12] m_DETAIL_RADIAL_LUT_s1*/
    int32_t m_detail_radial_lut_s1[12];
    /*!< m_detail_radial_lut_s2[12] m_DETAIL_RADIAL_LUT_s2*/
    int32_t m_detail_radial_lut_s2[12];
    /*!< m_detail_radial_lut_s3[12] m_DETAIL_RADIAL_LUT_s3*/
    int32_t m_detail_radial_lut_s3[12];
    /*!< m_detail_radial_lut_v[12] m_DETAIL_RADIAL_LUT_v*/
    int32_t m_detail_radial_lut_v[12];
    /*!< m_exp_lut_f1[12] m_EXP_LUT_f1*/
    int32_t m_exp_lut_f1[12];
    /*!< m_exp_lut_f2[12] m_EXP_LUT_f2*/
    int32_t m_exp_lut_f2[12];
    /*!< m_exp_lut_o[12] m_EXP_LUT_o*/
    int32_t m_exp_lut_o[12];
    /*!< m_exp_lut_s1[12] m_EXP_LUT_s1*/
    int32_t m_exp_lut_s1[12];
    /*!< m_exp_lut_s2[12] m_EXP_LUT_s2*/
    int32_t m_exp_lut_s2[12];
    /*!< m_exp_lut_s3[12] m_EXP_LUT_s3*/
    int32_t m_exp_lut_s3[12];
    /*!< m_exp_lut_v[12] m_EXP_LUT_v*/
    int32_t m_exp_lut_v[12];
    /*!< m_frame_width OBSOLETE*/
    int32_t m_frame_width;
    /*!< m_matchqualitymaxidx[4] OBSOLETE*/
    int32_t m_matchqualitymaxidx[4];
    /*!< m_mu_root_lut_f1[12] m_MU_ROOT_LUT_f1*/
    int32_t m_mu_root_lut_f1[12];
    /*!< m_mu_root_lut_f2[12] m_MU_ROOT_LUT_f2*/
    int32_t m_mu_root_lut_f2[12];
    /*!< m_mu_root_lut_s1[12] m_MU_ROOT_LUT_s1*/
    int32_t m_mu_root_lut_s1[12];
    /*!< m_mu_root_lut_s2[12] m_MU_ROOT_LUT_s2*/
    int32_t m_mu_root_lut_s2[12];
    /*!< m_mu_root_lut_s3[12] m_MU_ROOT_LUT_s3*/
    int32_t m_mu_root_lut_s3[12];
    /*!< m_mu_root_lut_v[12] m_MU_ROOT_LUT_v*/
    int32_t m_mu_root_lut_v[12];
    /*!< m_nl_lut1_f1[10] m_NL_LUT1_f1*/
    int32_t m_nl_lut1_f1[10];
    /*!< m_nl_lut1_f2[10] m_NL_LUT1_f1*/
    int32_t m_nl_lut1_f2[10];
    /*!< m_nl_lut1_s1[10] m_NL_LUT1_s1*/
    int32_t m_nl_lut1_s1[10];
    /*!< m_nl_lut1_s2[10] m_NL_LUT1_s2*/
    int32_t m_nl_lut1_s2[10];
    /*!< m_nl_lut1_s3[10] m_NL_LUT1_s2*/
    int32_t m_nl_lut1_s3[10];
    /*!< m_nl_lut1_v[10] m_NL_LUT1_v*/
    int32_t m_nl_lut1_v[10];
    /*!< m_nl_lut2_f1[10] m_NL_LUT2_f1*/
    int32_t m_nl_lut2_f1[10];
    /*!< m_nl_lut2_f2[10] m_NL_LUT2_f1*/
    int32_t m_nl_lut2_f2[10];
    /*!< m_nl_lut2_s1[10] m_NL_LUT2_s1*/
    int32_t m_nl_lut2_s1[10];
    /*!< m_nl_lut2_s2[10] m_NL_LUT2_s2*/
    int32_t m_nl_lut2_s2[10];
    /*!< m_nl_lut2_s3[10] m_NL_LUT2_s2*/
    int32_t m_nl_lut2_s3[10];
    /*!< m_nl_lut2_v[10] m_NL_LUT2_v*/
    int32_t m_nl_lut2_v[10];
    /*!< m_nl_lut3_f1[10] m_NL_LUT3_f1*/
    int32_t m_nl_lut3_f1[10];
    /*!< m_nl_lut3_f2[10] m_NL_LUT3_f1*/
    int32_t m_nl_lut3_f2[10];
    /*!< m_nl_lut3_s1[10] m_NL_LUT3_s1*/
    int32_t m_nl_lut3_s1[10];
    /*!< m_nl_lut3_s2[10] m_NL_LUT3_s2*/
    int32_t m_nl_lut3_s2[10];
    /*!< m_nl_lut3_s3[10] m_NL_LUT3_s2*/
    int32_t m_nl_lut3_s3[10];
    /*!< m_nl_lut3_v[10] m_NL_LUT3_v*/
    int32_t m_nl_lut3_v[10];
    /*!< m_nl_lut4_f1[10] m_NL_LUT4_f1*/
    int32_t m_nl_lut4_f1[10];
    /*!< m_nl_lut4_f2[10] m_NL_LUT4_f1*/
    int32_t m_nl_lut4_f2[10];
    /*!< m_nl_lut4_s1[10] m_NL_LUT4_s1*/
    int32_t m_nl_lut4_s1[10];
    /*!< m_nl_lut4_s2[10] m_NL_LUT4_s2*/
    int32_t m_nl_lut4_s2[10];
    /*!< m_nl_lut4_s3[10] m_NL_LUT4_s2*/
    int32_t m_nl_lut4_s3[10];
    /*!< m_nl_lut4_v[10] m_NL_LUT4_v*/
    int32_t m_nl_lut4_v[10];
    /*!< m_nl_th[3] m_NL_TH: detailIx-->detailType 3 THs for classification 1=Flat.vs.Weak; 2=Weak.vs.Texture 3=Texture.vs.Edge 4=OBSOLETE & not implemented*/
    int32_t m_nl_th[3];
    /*!< m_radial_power_lut_f1[12] m_RADIAL_POWER_LUT_f1*/
    int32_t m_radial_power_lut_f1[12];
    /*!< m_radial_power_lut_f2[12] m_RADIAL_POWER_LUT_f2*/
    int32_t m_radial_power_lut_f2[12];
    /*!< m_radial_power_lut_s1[12] m_RADIAL_POWER_LUT_s1*/
    int32_t m_radial_power_lut_s1[12];
    /*!< m_radial_power_lut_s2[12] m_RADIAL_POWER_LUT_s2*/
    int32_t m_radial_power_lut_s2[12];
    /*!< m_radial_power_lut_s3[12] m_RADIAL_POWER_LUT_s3*/
    int32_t m_radial_power_lut_s3[12];
    /*!< m_radial_power_lut_v[12] m_RADIAL_POWER_LUT_v*/
    int32_t m_radial_power_lut_v[12];
    /*!< m_rxinitial m_RxInitial: Radial  (coordinates of corner) - Initial X [0,m_frame_width-1]  Default=m_frame_width/2*/
    int32_t m_rxinitial;
    /*!< m_rxsqrinitial m_RxSqrInitial: m_RxInitial^2*/
    int32_t m_rxsqrinitial;
    /*!< m_ryinitial m_RyInitial: : Radial  (coordinates of corner) - Initial Y [0,m_frame_height-1]  Default=m_frame_height/2*/
    int32_t m_ryinitial;
    /*!< m_rysqrinitial m_RySqrInitial: m_RyInitial^2*/
    int32_t m_rysqrinitial;
    /*!< m_sad_norm_lut_f1[12] m_SAD_NORM_LUT_f1*/
    int32_t m_sad_norm_lut_f1[12];
    /*!< m_sad_norm_lut_f2[12] m_SAD_NORM_LUT_f2*/
    int32_t m_sad_norm_lut_f2[12];
    /*!< m_sad_norm_lut_s1[12] m_SAD_NORM_LUT_s1*/
    int32_t m_sad_norm_lut_s1[12];
    /*!< m_sad_norm_lut_s2[12] m_SAD_NORM_LUT_s2*/
    int32_t m_sad_norm_lut_s2[12];
    /*!< m_sad_norm_lut_s3[12] m_SAD_NORM_LUT_s3*/
    int32_t m_sad_norm_lut_s3[12];
    /*!< m_sad_norm_lut_v[12] m_SAD_NORM_LUT_v*/
    int32_t m_sad_norm_lut_v[12];
    /*!< m_sig_n_detail_lut_f1[10] m_SIG_N_DETAIL_LUT_f1*/
    int32_t m_sig_n_detail_lut_f1[10];
    /*!< m_sig_n_detail_lut_f2[10] m_SIG_N_DETAIL_LUT_f1*/
    int32_t m_sig_n_detail_lut_f2[10];
    /*!< m_sig_n_detail_lut_s1[10] m_SIG_N_DETAIL_LUT_s1*/
    int32_t m_sig_n_detail_lut_s1[10];
    /*!< m_sig_n_detail_lut_s2[10] m_SIG_N_DETAIL_LUT_s2*/
    int32_t m_sig_n_detail_lut_s2[10];
    /*!< m_sig_n_detail_lut_s3[10] m_SIG_N_DETAIL_LUT_s2*/
    int32_t m_sig_n_detail_lut_s3[10];
    /*!< m_sig_n_detail_lut_v[10] m_SIG_N_DETAIL_LUT_v*/
    int32_t m_sig_n_detail_lut_v[10];
    /*!< m_sig_n_rad_lut_f1[12] m_SIG_N_RAD_LUT_f1*/
    int32_t m_sig_n_rad_lut_f1[12];
    /*!< m_sig_n_rad_lut_f2[12] m_SIG_N_RAD_LUT_f2*/
    int32_t m_sig_n_rad_lut_f2[12];
    /*!< m_sig_n_rad_lut_s1[12] m_SIG_N_RAD_LUT_s1*/
    int32_t m_sig_n_rad_lut_s1[12];
    /*!< m_sig_n_rad_lut_s2[12] m_SIG_N_RAD_LUT_s2*/
    int32_t m_sig_n_rad_lut_s2[12];
    /*!< m_sig_n_rad_lut_s3[12] m_SIG_N_RAD_LUT_s3*/
    int32_t m_sig_n_rad_lut_s3[12];
    /*!< m_sig_n_rad_lut_v[12] m_SIG_N_RAD_LUT_v*/
    int32_t m_sig_n_rad_lut_v[12];
    /*!< m_sve_groups m_SVE_Groups: OBSOLETE*/
    int32_t m_sve_groups;
    /*!< m_sve_enable m_SVE_enable: OBSOLETE*/
    int32_t m_sve_enable;
    /*!< m_sve_gain[2] m_SVE_gain: OBSOLETE*/
    int32_t m_sve_gain[2];
    /*!< m_sve_shift[2] m_SVE_shift: OBSOLETE*/
    int32_t m_sve_shift[2];
    /*!< m_signglobal_shift1 m_SigNGlobal_SHIFT1: OBSOLETE*/
    int32_t m_signglobal_shift1;
    /*!< m_signglobal_shift2 m_SigNGlobal_SHIFT2: OBSOLETE*/
    int32_t m_signglobal_shift2;
    /*!< m_signglobal_sub_flag m_SigNGlobal_SUB_FLAG: OBSOLETE*/
    int32_t m_signglobal_sub_flag;
    /*!< m_detailidxshiftleft m_detailIdxShiftLeft: detail index shift left - Dynamic range normalization  Fixed=2  [2:7]*/
    int32_t m_detailidxshiftleft;
    /*!< m_matchqualitycands[16] m_matchQualityCands: match quality index weight pick  4X4   alpha0 inputs  (4 canidates [ 0*/
    int32_t m_matchqualitycands[16];
    /*!< m_ncandforavgpixel[4] m_nCandForAvgPixel: number of cands. for average pixel  per detail Type  (15..0)+1  Typically=[16 6 4 6]*/
    int32_t m_ncandforavgpixel[4];
    /*!< m_sortth[15] m_sortTh: sort th index set - THs for Pseudo SORT (Const not to be configured)*/
    int32_t m_sortth[15];
    /*!< m_statusetopleft m_statUseTopLeft: is top left pixel G/W  (for Bayer start)*/
    int32_t m_statusetopleft;
    /*!< m_wmaxminth m_wMaxMinTh: Final TH on Max(Weight) to overright Alpha*/
    int32_t m_wmaxminth;
    /*!< m_wsumminth m_wSumMinTh:  Final TH on Sum(Weight) to overright Alpha*/
    int32_t m_wsumminth;
    /*!< rad_enable OBSOLETE*/
    int32_t rad_enable;

} ia_pal_isp_bxt_bnlm_t;

/*! \isp struct bxt_ccm

*/
typedef struct
{
    /*!< bypass block bypass bit*/
    int32_t bypass;
    /*!< nb1 offset 1 for the transform*/
    int32_t nb1;
    /*!< nb2 offset 2 for the transform*/
    int32_t nb2;
    /*!< nb3 offset 3 for the transform*/
    int32_t nb3;
    /*!< configuration_matrix[9] ccm configuration matrix precision: S4.11*/
    int32_t configuration_matrix[9];

} ia_pal_isp_bxt_ccm_t;

/*! \isp struct bxt_convert16sto8u

*/
typedef struct
{
    /*!< m_bypass Bypass     {0,1}*/
    int32_t m_bypass;

} ia_pal_isp_bxt_convert16sto8u_t;

/*! \isp struct bxt_cropstills

*/
typedef struct
{
    /*!< Bypass block bypass*/
    int32_t Bypass;
    /*!< LeftBorder crop left border*/
    int32_t LeftBorder;
    /*!< TopBorder crop top border*/
    int32_t TopBorder;
    /*!< RightBorder crop right border*/
    int32_t RightBorder;
    /*!< BottomBorder crop bottom border*/
    int32_t BottomBorder;

} ia_pal_isp_bxt_cropstills_t;

/*! \isp struct bxt_cropvideo

*/
typedef struct
{
    /*!< Bypass block bypass*/
    int32_t Bypass;
    /*!< LeftBorder crop left border*/
    int32_t LeftBorder;
    /*!< TopBorder crop top border*/
    int32_t TopBorder;
    /*!< RightBorder crop right border*/
    int32_t RightBorder;
    /*!< BottomBorder crop bottom border*/
    int32_t BottomBorder;

} ia_pal_isp_bxt_cropvideo_t;

/*! \isp struct bxt_csc

*/
typedef struct
{
    /*!< m_csc_c_matrix_arr[9] CSC Matrix components (S0.14)*/
    int32_t m_csc_c_matrix_arr[9];
    /*!< m_csc_b_vec_arr[3] CSC Vector components (S0.13)*/
    int32_t m_csc_b_vec_arr[3];
    /*!< m_chroma_ds_coeff_arr[8] Chroma downsample 4x2 filter coefficients (U2.0)*/
    int32_t m_chroma_ds_coeff_arr[8];
    /*!< m_chroma_ds_nf Chroma downsample 4x2 filter normalization factor*/
    int32_t m_chroma_ds_nf;
    /*!< m_bypass Bypassing CSC. Outputting RGB to the Chroma downscale*/
    int32_t m_bypass;
    /*!< m_uv_bin_output 0 = YUV4:2:0 output, 1 = YUV4:2:2 output*/
    int32_t m_uv_bin_output;

} ia_pal_isp_bxt_csc_t;

/*! \isp struct bxt_csc_yuv2rgb
CSC YUV2RGB Block
*/
typedef struct
{
    /*!< coeff_shift coeff_shift*/
    int32_t coeff_shift;
    /*!< yuv_calibration[3] yuv_calibration*/
    int32_t yuv_calibration[3];
    /*!< yuv2rgb_coef[9] yuv2rgb_coef*/
    int32_t yuv2rgb_coef[9];

} ia_pal_isp_bxt_csc_yuv2rgb_t;

/*! \isp struct bxt_csc2
Color Space Conversion and down-sample to 4:2:0
*/
typedef struct
{
    /*!< bypass_0_1 Bypass CSC2*/
    int32_t bypass_0_1;
    /*!< use_fir_flag use ani-aliasing filter before decimation*/
    int32_t use_fir_flag;
    /*!< rgb2yuv_coef[3] 3 coefs for Y , 1 for U and 1 for V , Q15*/
    int32_t rgb2yuv_coef[3];

} ia_pal_isp_bxt_csc2_t;

/*! \isp struct bxt_demosaic

*/
typedef struct
{
    /*!< bypass Block bypass for HW use*/
    int32_t bypass;
    /*!< frame_width Frame width*/
    int32_t frame_width;
    /*!< gammasg Sharpening coefficient*/
    int32_t gammasg;
    /*!< lcctrl Checkers removal control*/
    int32_t lcctrl;
    /*!< crparam1 High frequency denoise param1*/
    int32_t crparam1;
    /*!< crparam2 High frequency denoise param2*/
    int32_t crparam2;
    /*!< coringparam False color correction gain*/
    int32_t coringparam;
    /*!< char_en Checkers removal enable*/
    int32_t char_en;
    /*!< fcc_en False color correction enable*/
    int32_t fcc_en;
    /*!< car_en Chroam artifacts removal enable*/
    int32_t car_en;
    /*!< hfar_en High frequency aliasing reduction correction enable*/
    int32_t hfar_en;
    /*!< es_enable Edge smoothing enable*/
    int32_t es_enable;
    /*!< es_pow Edge smoohing enable.*/
    int32_t es_pow;
    /*!< diag_car_trade_off_th Diagonal regions protection param1*/
    int32_t diag_car_trade_off_th;
    /*!< diag_car_trade_off_slope Diagonal regions protection param2*/
    int32_t diag_car_trade_off_slope;
    /*!< stream_ylp_c Coefficient for the YLP for central element of 3x3 neighborhood*/
    int32_t stream_ylp_c;
    /*!< stream_ylp_p Coefficient for the YLP for peripheral element of 3x3 neighborhood*/
    int32_t stream_ylp_p;
    /*!< stream_ylp_d Coefficient for the YLP for diagonal element of 3x3 neighborhood*/
    int32_t stream_ylp_d;
    /*!< stream_ylp_mul_norm Coefficient for multiplier in YLP stream*/
    int32_t stream_ylp_mul_norm;
    /*!< stream_ylp_norm_shift Coefficient for YLP stream*/
    int32_t stream_ylp_norm_shift;
    /*!< configunitdiag1_x[2] CU_DIAG1 - x input*/
    int32_t configunitdiag1_x[2];
    /*!< configunitdiag2_x[2] CU_DIAG2 - x input*/
    int32_t configunitdiag2_x[2];
    /*!< configunitdiag3_x[2] CU_DIAG3 - x input*/
    int32_t configunitdiag3_x[2];
    /*!< configunitcar_sat_x[2] CU_CAR_SAT - x input*/
    int32_t configunitcar_sat_x[2];
    /*!< configunitdiag1_y[1] CU_DIAG1 - y input*/
    int32_t configunitdiag1_y[1];
    /*!< configunitdiag1_slope[1] CU_DIAG1 - slope input*/
    int32_t configunitdiag1_slope[1];
    /*!< configunitdiag2_y[1] CU_DIAG2 - y input*/
    int32_t configunitdiag2_y[1];
    /*!< configunitdiag2_slope[1] CU_DIAG2 - slope input*/
    int32_t configunitdiag2_slope[1];
    /*!< configunitdiag3_y[1] CU_DIAG3 - y input*/
    int32_t configunitdiag3_y[1];
    /*!< configunitdiag3_slope[1] CU_DIAG3 - slope input*/
    int32_t configunitdiag3_slope[1];
    /*!< configunitcar_sat_y[1] CU_CAR_SAT - y input*/
    int32_t configunitcar_sat_y[1];
    /*!< configunitcar_sat_slope[1] CU_CAR_SAT - slope input*/
    int32_t configunitcar_sat_slope[1];

} ia_pal_isp_bxt_demosaic_t;

/*! \isp struct bxt_disparity

*/
typedef struct
{
    /*!< green_pos gb position*/
    int32_t green_pos;
    /*!< lc_cu_x[4] local contrast config unit x*/
    int32_t lc_cu_x[4];
    /*!< lc_cu_y[3] local contrast config unit y*/
    int32_t lc_cu_y[3];
    /*!< lc_cu_slope[3] local contrast config unit slope*/
    int32_t lc_cu_slope[3];
    /*!< delta_cu_x[4] delta config unit x*/
    int32_t delta_cu_x[4];
    /*!< delta_cu_y[3] delta config unit y*/
    int32_t delta_cu_y[3];
    /*!< delta_cu_slope[3] delta config unit slope*/
    int32_t delta_cu_slope[3];
    /*!< inv_lc_cu_x[8] inverse local contarst config unit x*/
    int32_t inv_lc_cu_x[8];
    /*!< inv_lc_cu_y[7] inverse local contarst config unit y*/
    int32_t inv_lc_cu_y[7];
    /*!< inv_lc_cu_slope[7] inverse local contarst config unit slope*/
    int32_t inv_lc_cu_slope[7];
    /*!< inv_delta_cu_x[8] inverse delta config unit x*/
    int32_t inv_delta_cu_x[8];
    /*!< inv_delta_cu_y[7] inverse delta config unit y*/
    int32_t inv_delta_cu_y[7];
    /*!< inv_delta_cu_slope[7] inverse delta config unit slope*/
    int32_t inv_delta_cu_slope[7];
    /*!< detail_pres detail preservation factor*/
    int32_t detail_pres;
    /*!< invscale scale factor after normalizing by inverse*/
    int32_t invscale;

} ia_pal_isp_bxt_disparity_t;

/*! \isp struct bxt_dpc

*/
typedef struct
{
    /*!< afxoffset[8] 8 Autofocus pixels X axis offset U14.0, should be smaller than afxperiod*/
    int32_t afxoffset[8];
    /*!< afxperiod[8] 8 Autofocus pixels X axis period*/
    int32_t afxperiod[8];
    /*!< afyoffset[8] 8 Autofocus pixels Y axis offset U14.0, should be smaller than afyperiod*/
    int32_t afyoffset[8];
    /*!< afyperiod[8] 8 Autofocus pixels Y axis period*/
    int32_t afyperiod[8];
    /*!< hdrfactors[16] 4x4 HDR exposure factor U6.8*/
    int32_t hdrfactors[16];
    /*!< hdrfactorsinverse[16] 4x4 HDR exposure inverse factor U6.8 - should be inverse of hdrfactors*/
    int32_t hdrfactorsinverse[16];
    /*!< configunitcolddistvsmedian_slope[7] cold dist vs median config unit classifier*/
    int32_t configunitcolddistvsmedian_slope[7];
    /*!< configunitcolddistvsmedian_x[8] cold dist vs median config unit classifier*/
    int32_t configunitcolddistvsmedian_x[8];
    /*!< configunitcolddistvsmedian_y[7] cold dist vs median config unit classifier*/
    int32_t configunitcolddistvsmedian_y[7];
    /*!< configunitcolddistvsneighb_slope[7] cold dist vs neigb config unit classifier*/
    int32_t configunitcolddistvsneighb_slope[7];
    /*!< configunitcolddistvsneighb_x[8] cold dist vs neigb config unit classifier*/
    int32_t configunitcolddistvsneighb_x[8];
    /*!< configunitcolddistvsneighb_y[7] cold dist vs neigb config unit classifier*/
    int32_t configunitcolddistvsneighb_y[7];
    /*!< configunitfix_slope[3] fix config unit*/
    int32_t configunitfix_slope[3];
    /*!< configunitfix_x[4] fix config unit*/
    int32_t configunitfix_x[4];
    /*!< configunitfix_y[3] fix config unit*/
    int32_t configunitfix_y[3];
    /*!< configunithotdistvsmedian_slope[7] hot dist vs median classifier*/
    int32_t configunithotdistvsmedian_slope[7];
    /*!< configunithotdistvsmedian_x[8] hot dist vs median classifier*/
    int32_t configunithotdistvsmedian_x[8];
    /*!< configunithotdistvsmedian_y[7] hot dist vs median classifier*/
    int32_t configunithotdistvsmedian_y[7];
    /*!< configunithotdistvsneighb_slope[7] hot dist vs neigb config unit classifier*/
    int32_t configunithotdistvsneighb_slope[7];
    /*!< configunithotdistvsneighb_x[8] hot dist vs neigb config unit classifier*/
    int32_t configunithotdistvsneighb_x[8];
    /*!< configunithotdistvsneighb_y[7] hot dist vs neigb config unit classifier*/
    int32_t configunithotdistvsneighb_y[7];
    /*!< configunitrawvslb_slope[7] configunitrawvslb_slope*/
    int32_t configunitrawvslb_slope[7];
    /*!< configunitrawvslb_x[8] configunitrawvslb_x*/
    int32_t configunitrawvslb_x[8];
    /*!< configunitrawvslb_y[7] configunitrawvslb_y*/
    int32_t configunitrawvslb_y[7];
    /*!< configunitrawvsub_slope[7] configunitrawvsub_slope*/
    int32_t configunitrawvsub_slope[7];
    /*!< configunitrawvsub_x[8] configunitrawvsub_x*/
    int32_t configunitrawvsub_x[8];
    /*!< configunitrawvsub_y[7] configunitrawvsub_y*/
    int32_t configunitrawvsub_y[7];
    /*!< curx[1024] x locations of the static bad pixels*/
    int32_t curx[1024];
    /*!< cury[1024] y locations of the static bad pixels*/
    int32_t cury[1024];
    /*!< lbtype[16] 0 - B1,   1 - B2,  2 - B3*/
    int32_t lbtype[16];
    /*!< ubtype[16] 0 - B1,   1 - B2,  2 - B3*/
    int32_t ubtype[16];
    /*!< pelesttype[16] 0-P1, 1-P2, 2-P3, 3-P4, 4-P5, 5-P6*/
    int32_t pelesttype[16];
    /*!< dtype[16] 0-D1 1-D2  2-D3*/
    int32_t dtype[16];
    /*!< lbmasks[64] configurations related to the bayer pattern*/
    int32_t lbmasks[64];
    /*!< ubmasks[64] configurations related to the bayer pattern*/
    int32_t ubmasks[64];
    /*!< pmasks[384] configurations related to the bayer pattern*/
    int32_t pmasks[384];
    /*!< dmasks[48] configurations related to the bayer pattern*/
    int32_t dmasks[48];
    /*!< bitreduceshift Shift value for bit reduce block*/
    int32_t bitreduceshift;
    /*!< afenable enable for the AF unit block*/
    int32_t afenable;
    /*!< staticenable enable for the static LUT block*/
    int32_t staticenable;
    /*!< dynamicenable enable for the dynamic detection block*/
    int32_t dynamicenable;
    /*!< n_static_lut_entries number of static lut entries*/
    int32_t n_static_lut_entries;
    /*!< frame_width frame width*/
    int32_t frame_width;
    /*!< frame_height frame height*/
    int32_t frame_height;
    /*!< paf_grid0_en paf enable0*/
    int32_t paf_grid0_en;
    /*!< paf_grid1_en paf enable1*/
    int32_t paf_grid1_en;
    /*!< paf_grid2_en paf enable2*/
    int32_t paf_grid2_en;
    /*!< paf_grid3_en paf enable3*/
    int32_t paf_grid3_en;
    /*!< paf_grid4_en paf enable4*/
    int32_t paf_grid4_en;
    /*!< paf_grid5_en paf enable5*/
    int32_t paf_grid5_en;
    /*!< paf_grid6_en paf enable6*/
    int32_t paf_grid6_en;
    /*!< paf_grid7_en paf enable7*/
    int32_t paf_grid7_en;

} ia_pal_isp_bxt_dpc_t;

/*! \isp struct bxt_dpcm_decode

*/
typedef struct
{
    /*!< first_pix_res first pixel resolution*/
    int32_t first_pix_res;
    /*!< bypass block bypass bit*/
    int32_t bypass;
    /*!< code[6] The codes array*/
    int32_t code[6];
    /*!< codethr[6] The threshold for using the next code*/
    int32_t codethr[6];
    /*!< codemask[6] Used for extracting the code from the coded word*/
    int32_t codemask[6];
    /*!< valuemask[6] Used for extracting the value from the coded word*/
    int32_t valuemask[6];
    /*!< signmask[6] Used for extracting the sign from the coded word*/
    int32_t signmask[6];
    /*!< lowresthrnum Code threshold for lower resolution coding*/
    int32_t lowresthrnum;

} ia_pal_isp_bxt_dpcm_decode_t;

/*! \isp struct bxt_dpcm_encode

*/
typedef struct
{
    /*!< first_pix_res first pixel resolution*/
    int32_t first_pix_res;
    /*!< bypass block bypass bit*/
    int32_t bypass;
    /*!< code[6] The codes array*/
    int32_t code[6];
    /*!< codethr[6] The threshold for using the next code*/
    int32_t codethr[6];
    /*!< codemask[6] Used for extracting the code from the coded word*/
    int32_t codemask[6];
    /*!< valuemask[6] Used for extracting the value from the coded word*/
    int32_t valuemask[6];
    /*!< signmask[6] Used for extracting the sign from the coded word*/
    int32_t signmask[6];
    /*!< lowresthrnum Code threshold for lower resolution coding*/
    int32_t lowresthrnum;

} ia_pal_isp_bxt_dpcm_encode_t;

/*! \isp struct bxt_dvsstatistics

*/
typedef struct
{
    /*!< kappa Global configuration - kappa*/
    int32_t kappa;
    /*!< match_shift Global configuration - match_shift*/
    int32_t match_shift;
    /*!< ybin_mode Global configuration - y binning mode*/
    int32_t ybin_mode;
    /*!< grid_width_l0 DVS statistics grid width level 0*/
    int32_t grid_width_l0;
    /*!< grid_height_l0 DVS statistics grid height level 0*/
    int32_t grid_height_l0;
    /*!< block_width_l0 DVS statistics block width level 0*/
    int32_t block_width_l0;
    /*!< block_height_l0 DVS statistics block height level 0*/
    int32_t block_height_l0;
    /*!< x_start_l0 DVS statistics level 0 x start*/
    int32_t x_start_l0;
    /*!< y_start_l0 DVS statistics level 0 y start*/
    int32_t y_start_l0;
    /*!< enabled_l0 DVS statistics level 0 enable*/
    int32_t enabled_l0;
    /*!< x_end_l0 DVS statistics level 0 x end*/
    int32_t x_end_l0;
    /*!< y_end_l0 DVS statistics level 0 y end*/
    int32_t y_end_l0;
    /*!< grid_width_l1 DVS statistics grid width level 1*/
    int32_t grid_width_l1;
    /*!< grid_height_l1 DVS statistics grid height level 1*/
    int32_t grid_height_l1;
    /*!< block_width_l1 DVS statistics block width level 1*/
    int32_t block_width_l1;
    /*!< block_height_l1 DVS statistics block height level 1*/
    int32_t block_height_l1;
    /*!< x_start_l1 DVS statistics level 1 x start*/
    int32_t x_start_l1;
    /*!< y_start_l1 DVS statistics level 1 y start*/
    int32_t y_start_l1;
    /*!< enabled_l1 DVS statistics level 1 enable*/
    int32_t enabled_l1;
    /*!< x_end_l1 DVS statistics level 1 x end*/
    int32_t x_end_l1;
    /*!< y_end_l1 DVS statistics level 1 y end*/
    int32_t y_end_l1;
    /*!< grid_width_l2 DVS statistics grid width level 2*/
    int32_t grid_width_l2;
    /*!< grid_height_l2 DVS statistics grid height level 2*/
    int32_t grid_height_l2;
    /*!< block_width_l2 DVS statistics block width level 2*/
    int32_t block_width_l2;
    /*!< block_height_l2 DVS statistics block height level 2*/
    int32_t block_height_l2;
    /*!< x_start_l2 DVS statistics level 2 x start*/
    int32_t x_start_l2;
    /*!< y_start_l2 DVS statistics level 2 y start*/
    int32_t y_start_l2;
    /*!< enabled_l2 DVS statistics level 2 enable*/
    int32_t enabled_l2;
    /*!< x_end_l2 DVS statistics level 2 x end*/
    int32_t x_end_l2;
    /*!< y_end_l2 DVS statistics level 2 y end*/
    int32_t y_end_l2;
    /*!< feroi_x_start_l0 DVS statistics fe-roi level 0 x start*/
    int32_t feroi_x_start_l0;
    /*!< feroi_y_start_l0 DVS statistics fe-roi level 0 y start*/
    int32_t feroi_y_start_l0;
    /*!< feroi_x_end_l0 DVS statistics fe-roi level 0 x end*/
    int32_t feroi_x_end_l0;
    /*!< feroi_y_end_l0 DVS statistics fe-roi level 0 y end*/
    int32_t feroi_y_end_l0;
    /*!< feroi_x_start_l1 DVS statistics fe-roi level 1 x start*/
    int32_t feroi_x_start_l1;
    /*!< feroi_y_start_l1 DVS statistics fe-roi level 1 y start*/
    int32_t feroi_y_start_l1;
    /*!< feroi_x_end_l1 DVS statistics fe-roi level 1 x end*/
    int32_t feroi_x_end_l1;
    /*!< feroi_y_end_l1 DVS statistics fe-roi level 1 y end*/
    int32_t feroi_y_end_l1;
    /*!< feroi_x_start_l2 DVS statistics fe-roi level 2 x start*/
    int32_t feroi_x_start_l2;
    /*!< feroi_y_start_l2 DVS statistics fe-roi level 2 y start*/
    int32_t feroi_y_start_l2;
    /*!< feroi_x_end_l2 DVS statistics fe-roi level 2 x end*/
    int32_t feroi_x_end_l2;
    /*!< feroi_y_end_l2 DVS statistics fe-roi level 2 y end*/
    int32_t feroi_y_end_l2;

} ia_pal_isp_bxt_dvsstatistics_t;

/*! \isp struct bxt_gammatm

*/
typedef struct
{
    /*!< enable enable for the filter*/
    int32_t enable;
    /*!< gammaBeforeTM order of operations whether Gamma correction should precede TM or vise versa. 0- TM --> Gamma. 1- Gamma-->TM*/
    int32_t gammaBeforeTM;
    /*!< a1 shift amount at stage 1*/
    int32_t a1;
    /*!< a2 shift amount at stage 2*/
    int32_t a2;
    /*!< a3 shift amount at stage 3*/
    int32_t a3;
    /*!< gamma_lut_enable enable for gamma lut*/
    int32_t gamma_lut_enable;
    /*!< gamma_lut_base_level[5] base level for gamma lut*/
    int32_t gamma_lut_base_level[5];
    /*!< gamma_lut_step[5] step for gamma lut*/
    int32_t gamma_lut_step[5];
    /*!< gamma_lut_start_bin[5] start bin for gamma lut*/
    int32_t gamma_lut_start_bin[5];
    /*!< gamma_lut_size gamma lut size*/
    int32_t gamma_lut_size;
    /*!< gamma_lut_gen_lut[385] generalized lut for gamma lut*/
    int32_t gamma_lut_gen_lut[385];
    /*!< tm_lut_enable enable for tone mapping lut*/
    int32_t tm_lut_enable;
    /*!< tm_lut_base_level[1] base level for  tone mapping lut*/
    int32_t tm_lut_base_level[1];
    /*!< tm_lut_step[1] step for  tone mapping lut*/
    int32_t tm_lut_step[1];
    /*!< tm_lut_start_bin[1] start bin for  tone mapping lut*/
    int32_t tm_lut_start_bin[1];
    /*!< tm_lut_size tone mapping lut size*/
    int32_t tm_lut_size;
    /*!< tm_lut_gen_lut[513] generalized lut for tone mapping lut*/
    int32_t tm_lut_gen_lut[513];

} ia_pal_isp_bxt_gammatm_t;

/*! \isp struct bxt_gridbaseob

*/
typedef struct
{
    /*!< cfa_type cfa type 0=1x1 1=2x2 2=4x4*/
    int32_t cfa_type;
    /*!< blc_log2gridwidth log2 of grid of each subplane width*/
    int32_t blc_log2gridwidth;
    /*!< blc_log2gridheight log2 of grid of each subplane height*/
    int32_t blc_log2gridheight;
    /*!< blc_col_start X value of top left corner of sensor relative to ROI*/
    int32_t blc_col_start;
    /*!< blc_row_start Y value of top left corner of sensor relative to ROI*/
    int32_t blc_row_start;
    /*!< blc_grid_tablec00[4096] gridob grid table*/
    int32_t blc_grid_tablec00[4096];
    /*!< blc_grid_tablec01[4096] gridob grid table*/
    int32_t blc_grid_tablec01[4096];
    /*!< blc_grid_tablec02[4096] gridob grid table*/
    int32_t blc_grid_tablec02[4096];
    /*!< blc_grid_tablec03[4096] gridob grid table*/
    int32_t blc_grid_tablec03[4096];
    /*!< blc_grid_tablec10[4096] gridob grid table*/
    int32_t blc_grid_tablec10[4096];
    /*!< blc_grid_tablec11[4096] gridob grid table*/
    int32_t blc_grid_tablec11[4096];
    /*!< blc_grid_tablec12[4096] gridob grid table*/
    int32_t blc_grid_tablec12[4096];
    /*!< blc_grid_tablec13[4096] gridob grid table*/
    int32_t blc_grid_tablec13[4096];
    /*!< blc_grid_tablec20[4096] gridob grid table*/
    int32_t blc_grid_tablec20[4096];
    /*!< blc_grid_tablec21[4096] gridob grid table*/
    int32_t blc_grid_tablec21[4096];
    /*!< blc_grid_tablec22[4096] gridob grid table*/
    int32_t blc_grid_tablec22[4096];
    /*!< blc_grid_tablec23[4096] gridob grid table*/
    int32_t blc_grid_tablec23[4096];
    /*!< blc_grid_tablec30[4096] gridob grid table*/
    int32_t blc_grid_tablec30[4096];
    /*!< blc_grid_tablec31[4096] gridob grid table*/
    int32_t blc_grid_tablec31[4096];
    /*!< blc_grid_tablec32[4096] gridob grid table*/
    int32_t blc_grid_tablec32[4096];
    /*!< blc_grid_tablec33[4096] gridob grid table*/
    int32_t blc_grid_tablec33[4096];
    /*!< blc_table_width table width*/
    int32_t blc_table_width;
    /*!< blc_table_height table height*/
    int32_t blc_table_height;
    /*!< bypass bypass for the filter*/
    int32_t bypass;

} ia_pal_isp_bxt_gridbaseob_t;

/*! \isp struct bxt_gridbaseob_b

*/
typedef struct
{
    /*!< cfa_type cfa type 0=1x1 1=2x2 2=4x4*/
    int32_t cfa_type;
    /*!< blc_log2gridwidth log2 of grid of each subplane width*/
    int32_t blc_log2gridwidth;
    /*!< blc_log2gridheight log2 of grid of each subplane height*/
    int32_t blc_log2gridheight;
    /*!< blc_col_start X value of top left corner of sensor relative to ROI*/
    int32_t blc_col_start;
    /*!< blc_row_start Y value of top left corner of sensor relative to ROI*/
    int32_t blc_row_start;
    /*!< blc_grid_tablec00[4096] gridob grid table*/
    int32_t blc_grid_tablec00[4096];
    /*!< blc_grid_tablec01[4096] gridob grid table*/
    int32_t blc_grid_tablec01[4096];
    /*!< blc_grid_tablec02[4096] gridob grid table*/
    int32_t blc_grid_tablec02[4096];
    /*!< blc_grid_tablec03[4096] gridob grid table*/
    int32_t blc_grid_tablec03[4096];
    /*!< blc_grid_tablec10[4096] gridob grid table*/
    int32_t blc_grid_tablec10[4096];
    /*!< blc_grid_tablec11[4096] gridob grid table*/
    int32_t blc_grid_tablec11[4096];
    /*!< blc_grid_tablec12[4096] gridob grid table*/
    int32_t blc_grid_tablec12[4096];
    /*!< blc_grid_tablec13[4096] gridob grid table*/
    int32_t blc_grid_tablec13[4096];
    /*!< blc_grid_tablec20[4096] gridob grid table*/
    int32_t blc_grid_tablec20[4096];
    /*!< blc_grid_tablec21[4096] gridob grid table*/
    int32_t blc_grid_tablec21[4096];
    /*!< blc_grid_tablec22[4096] gridob grid table*/
    int32_t blc_grid_tablec22[4096];
    /*!< blc_grid_tablec23[4096] gridob grid table*/
    int32_t blc_grid_tablec23[4096];
    /*!< blc_grid_tablec30[4096] gridob grid table*/
    int32_t blc_grid_tablec30[4096];
    /*!< blc_grid_tablec31[4096] gridob grid table*/
    int32_t blc_grid_tablec31[4096];
    /*!< blc_grid_tablec32[4096] gridob grid table*/
    int32_t blc_grid_tablec32[4096];
    /*!< blc_grid_tablec33[4096] gridob grid table*/
    int32_t blc_grid_tablec33[4096];
    /*!< blc_table_width table width*/
    int32_t blc_table_width;
    /*!< blc_table_height table height*/
    int32_t blc_table_height;
    /*!< bypass bypass for the filter*/
    int32_t bypass;

} ia_pal_isp_bxt_gridbaseob_b_t;

/*! \isp struct bxt_gridbaseob_c

*/
typedef struct
{
    /*!< cfa_type cfa type 0=1x1 1=2x2 2=4x4*/
    int32_t cfa_type;
    /*!< blc_log2gridwidth log2 of grid of each subplane width*/
    int32_t blc_log2gridwidth;
    /*!< blc_log2gridheight log2 of grid of each subplane height*/
    int32_t blc_log2gridheight;
    /*!< blc_col_start X value of top left corner of sensor relative to ROI*/
    int32_t blc_col_start;
    /*!< blc_row_start Y value of top left corner of sensor relative to ROI*/
    int32_t blc_row_start;
    /*!< blc_grid_tablec00[4096] gridob grid table*/
    int32_t blc_grid_tablec00[4096];
    /*!< blc_grid_tablec01[4096] gridob grid table*/
    int32_t blc_grid_tablec01[4096];
    /*!< blc_grid_tablec02[4096] gridob grid table*/
    int32_t blc_grid_tablec02[4096];
    /*!< blc_grid_tablec03[4096] gridob grid table*/
    int32_t blc_grid_tablec03[4096];
    /*!< blc_grid_tablec10[4096] gridob grid table*/
    int32_t blc_grid_tablec10[4096];
    /*!< blc_grid_tablec11[4096] gridob grid table*/
    int32_t blc_grid_tablec11[4096];
    /*!< blc_grid_tablec12[4096] gridob grid table*/
    int32_t blc_grid_tablec12[4096];
    /*!< blc_grid_tablec13[4096] gridob grid table*/
    int32_t blc_grid_tablec13[4096];
    /*!< blc_grid_tablec20[4096] gridob grid table*/
    int32_t blc_grid_tablec20[4096];
    /*!< blc_grid_tablec21[4096] gridob grid table*/
    int32_t blc_grid_tablec21[4096];
    /*!< blc_grid_tablec22[4096] gridob grid table*/
    int32_t blc_grid_tablec22[4096];
    /*!< blc_grid_tablec23[4096] gridob grid table*/
    int32_t blc_grid_tablec23[4096];
    /*!< blc_grid_tablec30[4096] gridob grid table*/
    int32_t blc_grid_tablec30[4096];
    /*!< blc_grid_tablec31[4096] gridob grid table*/
    int32_t blc_grid_tablec31[4096];
    /*!< blc_grid_tablec32[4096] gridob grid table*/
    int32_t blc_grid_tablec32[4096];
    /*!< blc_grid_tablec33[4096] gridob grid table*/
    int32_t blc_grid_tablec33[4096];
    /*!< blc_table_width table width*/
    int32_t blc_table_width;
    /*!< blc_table_height table height*/
    int32_t blc_table_height;
    /*!< bypass bypass for the filter*/
    int32_t bypass;

} ia_pal_isp_bxt_gridbaseob_c_t;

/*! \isp struct bxt_inputscaler

*/
typedef struct
{
    /*!< block_bypass block bypass bit. Note that in ATE this parameters is 'bypass' (0 - enable. 1 - disable) while in HW it is 'enable' (0 - bypass. 1 - enable). In case block_bypass = 1, demo_bypass and scaler_bypass will turn to 1.*/
    int32_t block_bypass;
    /*!< demo_bypass demosaic bypass bit.  Note that in ATE this parameters is 'bypass' (0 - enable. 1 - disable) while in HW it is 'enable' (0 - bypass. 1 - enable).*/
    int32_t demo_bypass;
    /*!< scaler_bypass scaler bypass bit.  Note that in ATE this parameters is 'bypass' (0 - enable. 1 - disable) while in HW it is 'enable' (0 - bypass. 1 - enable).*/
    int32_t scaler_bypass;
    /*!< vnumerator Vertical SF Numerator*/
    int32_t vnumerator;
    /*!< hnumerator Horizontal SF Numerator*/
    int32_t hnumerator;
    /*!< vdenominator Vertical SF Denominator*/
    int32_t vdenominator;
    /*!< hdenominator Horizontal SF Denominator*/
    int32_t hdenominator;
    /*!< norm_mul Normalization multiply coefficient*/
    int32_t norm_mul;
    /*!< norm_shift Normalization shift*/
    int32_t norm_shift;
    /*!< output_sensor_mode Output Sensor mode 0-1x1, 1-2x2, 2-4x4. Input scaler can't work in 1x1 sensor mode.*/
    int32_t output_sensor_mode;
    /*!< output_format_matrix[16] Output format matrix [4,4]. 0=R. 1=G. 2=G. 3=W*/
    int32_t output_format_matrix[16];
    /*!< Input_Frame_Width Input frame width.*/
    int32_t Input_Frame_Width;
    /*!< input_is_bayer 0 - RGBC, 1 - Bayer,*/
    int32_t input_is_bayer;
    /*!< output_height Has to be a multiple of 4.*/
    int32_t output_height;
    /*!< output_width Better be a mutiplication of 32 to avoid RTL zero padding (?). When block is stationed in isla (isla=on) then maximum is 2560. Has to be a multiple of 4.*/
    int32_t output_width;
    /*!< shift_to_lb Shifting before LB*/
    int32_t shift_to_lb;
    /*!< input_sensor_mode Input Sensor mode 0-1x1, 1-2x2, 2-4x4. Input scaler can't work in 1x1 sensor mode.*/
    int32_t input_sensor_mode;
    /*!< is_ul_w Is the first pixel in frame G/W 1-true, 0-false*/
    int32_t is_ul_w;
    /*!< bayer_type Bayer Type - BGGR(0), RGGB(1), GRBG(2), GBRG(3)*/
    int32_t bayer_type;
    /*!< lut_values[16] QNN LUT - Values. Restriction - rising monotonic.*/
    int32_t lut_values[16];
    /*!< lut_shifts1[16] QNN LUT - Shift1. lut_shift2 >= lut_shift1.*/
    int32_t lut_shifts1[16];
    /*!< lut_shifts2[16] QNN LUT - Shift2. lut_shift2 >= lut_shift1.*/
    int32_t lut_shifts2[16];
    /*!< lut_subtraction_flags[16] QNN LUT - Flags*/
    int32_t lut_subtraction_flags[16];
    /*!< lut_output_values[16] QNN LUT - Output Values*/
    int32_t lut_output_values[16];
    /*!< kernel_g_coef[6] G kernel - Coefs*/
    int32_t kernel_g_coef[6];
    /*!< kernel_g_norm File for G kernel - Norm*/
    int32_t kernel_g_norm;
    /*!< cbf_div_cu_x[12] Config unit division - X points*/
    int32_t cbf_div_cu_x[12];
    /*!< cbf_div_cu_y[11] Config unit division - Y points*/
    int32_t cbf_div_cu_y[11];
    /*!< cbf_div_cu_slope[11] Config unit division - Slopes*/
    int32_t cbf_div_cu_slope[11];
    /*!< cbi_r_pos[96] .CBI R Positions. Valid range {0-17}*/
    int32_t cbi_r_pos[96];
    /*!< cbi_r_wgt[96] CBI R Weights. Valid range: {0-4 , 7}*/
    int32_t cbi_r_wgt[96];
    /*!< cbi_g_pos[96] CBI G Positions. Valid range {0-17}*/
    int32_t cbi_g_pos[96];
    /*!< cbi_g_wgt[96] CBI G Weights. Valid range {0-4 , 7}*/
    int32_t cbi_g_wgt[96];
    /*!< cbi_b_pos[96] CBI B Positions. Valid range {0-17}*/
    int32_t cbi_b_pos[96];
    /*!< cbi_b_wgt[96] CBI B Weights. Valid range {0-4 , 7}*/
    int32_t cbi_b_wgt[96];
    /*!< wb_matrix[16] Matrix[4][4] for WB. 0=no gain. 1=R. 2=B. 3=G. (in each quad must use at least two zeros (no gain)).*/
    int32_t wb_matrix[16];
    /*!< r_wb_gain WB R gain*/
    int32_t r_wb_gain;
    /*!< g_wb_gain WB G gain*/
    int32_t g_wb_gain;
    /*!< b_wb_gain WB B gain*/
    int32_t b_wb_gain;

} ia_pal_isp_bxt_inputscaler_t;

/*! \isp struct bxt_inputscalerv2

*/
typedef struct
{
    /*!< block_bypass block bypass bit. Note that in ATE this parameters is 'bypass' (0 - enable. 1 - disable) while in HW it is 'enable' (0 - bypass. 1 - enable). In case block_bypass = 1, demo_bypass and scaler_bypass will turn to 1.*/
    int32_t block_bypass;
    /*!< demo_bypass demosaic bypass bit.  Note that in ATE this parameters is 'bypass' (0 - enable. 1 - disable) while in HW it is 'enable' (0 - bypass. 1 - enable).*/
    int32_t demo_bypass;
    /*!< scaler_bypass scaler bypass bit.  Note that in ATE this parameters is 'bypass' (0 - enable. 1 - disable) while in HW it is 'enable' (0 - bypass. 1 - enable).*/
    int32_t scaler_bypass;
    /*!< vnumerator Vertical   SF Numerator*/
    int32_t vnumerator;
    /*!< hnumerator Horizontal SF Numerator*/
    int32_t hnumerator;
    /*!< vdenominator Vertical   SF Denominator*/
    int32_t vdenominator;
    /*!< hdenominator Horizontal SF Denominator*/
    int32_t hdenominator;
    /*!< norm_mul Normalization multiply coeffiecient*/
    int32_t norm_mul;
    /*!< norm_shift Normalization shift*/
    int32_t norm_shift;
    /*!< output_sensor_mode Output Sensor mode 0-1x1, 1-2x2, 2-4x4. Input scaler can't work in 1x1 sensor mode.*/
    int32_t output_sensor_mode;
    /*!< output_format_matrix[16] Output format matrix [4,4]. 0=R. 1=G. 2=G. 3=W*/
    int32_t output_format_matrix[16];
    /*!< Input_Frame_Width Input frame width. Has to be a multiple of 4.*/
    int32_t Input_Frame_Width;
    /*!< input_is_bayer 0 - RGBC, 1 - Bayer,*/
    int32_t input_is_bayer;
    /*!< output_height Has to be a multiple of 4.*/
    int32_t output_height;
    /*!< output_width Better be a mutiplication of 32 to avoid RTL zero padding (?). When block is stationed in isla (isla=on) then maximum is 2560. Has to be a multiple of 4.*/
    int32_t output_width;
    /*!< shift_to_lb Shifting before LB*/
    int32_t shift_to_lb;
    /*!< input_sensor_mode Input Sensor mode 0-1x1, 1-2x2, 2-4x4. Input scaler can't work in 1x1 sensor mode.*/
    int32_t input_sensor_mode;
    /*!< is_ul_w Is the first pixel in frame G/W 1-true, 0-false*/
    int32_t is_ul_w;
    /*!< bayer_type Bayer Type - BGGR(0), RGGB(1), GRBG(2), GBRG(3)*/
    int32_t bayer_type;
    /*!< lut_values[16] QNN LUT - Values. Restriction - rising monotonic.*/
    int32_t lut_values[16];
    /*!< lut_shifts1[16] QNN LUT - Shift1. lut_shift2 >= lut_shift1.*/
    int32_t lut_shifts1[16];
    /*!< lut_shifts2[16] QNN LUT - Shift2. lut_shift2 >= lut_shift1.*/
    int32_t lut_shifts2[16];
    /*!< lut_subtraction_flags[16] QNN LUT - Flags*/
    int32_t lut_subtraction_flags[16];
    /*!< lut_output_values[16] QNN LUT - Output Values*/
    int32_t lut_output_values[16];
    /*!< kernel_g_coef[6] G kernel - Coefs*/
    int32_t kernel_g_coef[6];
    /*!< kernel_g_norm File for G kernel - Norm*/
    int32_t kernel_g_norm;
    /*!< cbf_div_cu_x[12] Config unit division - X points*/
    int32_t cbf_div_cu_x[12];
    /*!< cbf_div_cu_y[11] Config unit division - Y points*/
    int32_t cbf_div_cu_y[11];
    /*!< cbf_div_cu_slope[11] Config unit division - Slopes*/
    int32_t cbf_div_cu_slope[11];
    /*!< cbi_r_pos[96] .CBI R Positions. Valid range {0-17}*/
    int32_t cbi_r_pos[96];
    /*!< cbi_r_wgt[96] CBI R Weights. Valid range: {0-4 , 7}*/
    int32_t cbi_r_wgt[96];
    /*!< cbi_g_pos[96] CBI G Positions. Valid range {0-17}. Not used in Bayer (only in RGBC).*/
    int32_t cbi_g_pos[96];
    /*!< cbi_g_wgt[96] CBI G Weights. Valid range {0-4 , 7}. Not used in Bayer (only in RGBC).*/
    int32_t cbi_g_wgt[96];
    /*!< cbi_b_pos[96] CBI B Positions. Valid range {0-17}*/
    int32_t cbi_b_pos[96];
    /*!< cbi_b_wgt[96] CBI B Weights. Valid range {0-4 , 7}*/
    int32_t cbi_b_wgt[96];
    /*!< wb_matrix[16] Matrix[4][4] for WB. 0=no gain. 1=R. 2=B. 3=G. (in each quad must use at least two zeros (no gain)).*/
    int32_t wb_matrix[16];
    /*!< r_wb_gain WB R gain. 4096 is equal to gain 1.*/
    int32_t r_wb_gain;
    /*!< g_wb_gain WB G gain. 4096 is equal to gain 1.*/
    int32_t g_wb_gain;
    /*!< b_wb_gain WB B gain. 4096 is equal to gain 1.*/
    int32_t b_wb_gain;
    /*!< g_min_r_en Enable 'G-R' mode*/
    int32_t g_min_r_en;

} ia_pal_isp_bxt_inputscalerv2_t;

/*! \isp struct bxt_isl_inputcrop

*/
typedef struct
{
    /*!< m_xstart Horizontal Starting Pixel. FIXME: Put correct max and default values*/
    int32_t m_xstart;
    /*!< m_ystart Vertical   Starting Pixel. FIXME: Put correct max and default values*/
    int32_t m_ystart;
    /*!< m_xsize Horizontal Frame Size. FIXME: Put correct max and default values*/
    int32_t m_xsize;
    /*!< m_ysize Vertical   Frame Size. FIXME: Put correct max and default values*/
    int32_t m_ysize;

} ia_pal_isp_bxt_isl_inputcrop_t;

/*! \isp struct bxt_linearization

*/
typedef struct
{
    /*!< cfa_type cfa type 0=1x1 1=2x2 2=4x4*/
    int32_t cfa_type;
    /*!< linc00[65] linearization grid table*/
    int32_t linc00[65];
    /*!< linc01[65] linearization grid table*/
    int32_t linc01[65];
    /*!< linc02[65] linearization grid table*/
    int32_t linc02[65];
    /*!< linc03[65] linearization grid table*/
    int32_t linc03[65];
    /*!< linc10[65] linearization grid table*/
    int32_t linc10[65];
    /*!< linc11[65] linearization grid table*/
    int32_t linc11[65];
    /*!< linc12[65] linearization grid table*/
    int32_t linc12[65];
    /*!< linc13[65] linearization grid table*/
    int32_t linc13[65];
    /*!< linc20[65] linearization grid table*/
    int32_t linc20[65];
    /*!< linc21[65] linearization grid table*/
    int32_t linc21[65];
    /*!< linc22[65] linearization grid table*/
    int32_t linc22[65];
    /*!< linc23[65] linearization grid table*/
    int32_t linc23[65];
    /*!< linc30[65] linearization grid table*/
    int32_t linc30[65];
    /*!< linc31[65] linearization grid table*/
    int32_t linc31[65];
    /*!< linc32[65] linearization grid table*/
    int32_t linc32[65];
    /*!< linc33[65] linearization grid table*/
    int32_t linc33[65];
    /*!< bypass bypass for the filter*/
    int32_t bypass;

} ia_pal_isp_bxt_linearization_t;

/*! \isp struct bxt_lsc

*/
typedef struct
{
    /*!< cfa_type cfa type 0=1x1 1=2x2 2=4x4*/
    int32_t cfa_type;
    /*!< lsclog2gridwidth log2 width of each subplane*/
    int32_t lsclog2gridwidth;
    /*!< lsclog2gridheight log2 height of each subplane*/
    int32_t lsclog2gridheight;
    /*!< lsc_col_start X value of top left corner of sensor relative to ROI*/
    int32_t lsc_col_start;
    /*!< lsc_row_start Y value of top left corner of sensor relative to ROI*/
    int32_t lsc_row_start;
    /*!< lsc_exp resolution modifier of the lsc tables*/
    int32_t lsc_exp;
    /*!< lsc_grid_tablec00[4096] lsc grid table*/
    int32_t lsc_grid_tablec00[4096];
    /*!< lsc_grid_tablec01[4096] lsc grid table*/
    int32_t lsc_grid_tablec01[4096];
    /*!< lsc_grid_tablec02[4096] lsc grid table*/
    int32_t lsc_grid_tablec02[4096];
    /*!< lsc_grid_tablec03[4096] lsc grid table*/
    int32_t lsc_grid_tablec03[4096];
    /*!< lsc_grid_tablec10[4096] lsc grid table*/
    int32_t lsc_grid_tablec10[4096];
    /*!< lsc_grid_tablec11[4096] lsc grid table*/
    int32_t lsc_grid_tablec11[4096];
    /*!< lsc_grid_tablec12[4096] lsc grid table*/
    int32_t lsc_grid_tablec12[4096];
    /*!< lsc_grid_tablec13[4096] lsc grid table*/
    int32_t lsc_grid_tablec13[4096];
    /*!< lsc_grid_tablec20[4096] lsc grid table*/
    int32_t lsc_grid_tablec20[4096];
    /*!< lsc_grid_tablec21[4096] lsc grid table*/
    int32_t lsc_grid_tablec21[4096];
    /*!< lsc_grid_tablec22[4096] lsc grid table*/
    int32_t lsc_grid_tablec22[4096];
    /*!< lsc_grid_tablec23[4096] lsc grid table*/
    int32_t lsc_grid_tablec23[4096];
    /*!< lsc_grid_tablec30[4096] lsc grid table*/
    int32_t lsc_grid_tablec30[4096];
    /*!< lsc_grid_tablec31[4096] lsc grid table*/
    int32_t lsc_grid_tablec31[4096];
    /*!< lsc_grid_tablec32[4096] lsc grid table*/
    int32_t lsc_grid_tablec32[4096];
    /*!< lsc_grid_tablec33[4096] lsc grid table*/
    int32_t lsc_grid_tablec33[4096];
    /*!< lsc_table_width table width*/
    int32_t lsc_table_width;
    /*!< lsc_table_height table height*/
    int32_t lsc_table_height;
    /*!< bypass bypass for the filter*/
    int32_t bypass;

} ia_pal_isp_bxt_lsc_t;

/*! \isp struct bxt_norm_lin

*/
typedef struct
{
    /*!< lut[257] Normalization lut*/
    int32_t lut[257];
    /*!< lin_en Linearization enable*/
    int32_t lin_en;
    /*!< lshift The size of normalized shift (signed)*/
    int32_t lshift;
    /*!< bypass bypass*/
    int32_t bypass;

} ia_pal_isp_bxt_norm_lin_t;

/*! \isp struct bxt_norm_lin_b

*/
typedef struct
{
    /*!< lut[257] Normalization lut*/
    int32_t lut[257];
    /*!< lin_en Linearization enable*/
    int32_t lin_en;
    /*!< lshift The size of normalized shift (signed)*/
    int32_t lshift;
    /*!< bypass bypass*/
    int32_t bypass;

} ia_pal_isp_bxt_norm_lin_b_t;

/*! \isp struct bxt_norm_lin_c

*/
typedef struct
{
    /*!< lut[257] Normalization lut*/
    int32_t lut[257];
    /*!< lin_en Linearization enable*/
    int32_t lin_en;
    /*!< lshift The size of normalized shift (signed)*/
    int32_t lshift;
    /*!< bypass bypass*/
    int32_t bypass;

} ia_pal_isp_bxt_norm_lin_c_t;

/*! \isp struct bxt_ofa_dp

*/
typedef struct
{
    /*!< y_tiling tiling parameter for NV12 y_tiled format*/
    int32_t y_tiling;
    /*!< pack_mode pack mode for packer*/
    int32_t pack_mode;
    /*!< bypass_flip bypass flip*/
    int32_t bypass_flip;
    /*!< bypass_mirror bypass mirror*/
    int32_t bypass_mirror;
    /*!< bypass_reduced_range bypass reduced range*/
    int32_t bypass_reduced_range;
    /*!< p_e[2] Multiplication parameters for pixel with even vertical index*/
    int32_t p_e[2];
    /*!< p_o[2] Multiplication parameters for pixel with odd vertical index*/
    int32_t p_o[2];

} ia_pal_isp_bxt_ofa_dp_t;

/*! \isp struct bxt_ofa_mp

*/
typedef struct
{
    /*!< y_tiling tiling parameter for NV12 y_tiled format*/
    int32_t y_tiling;
    /*!< pack_mode pack mode for packer*/
    int32_t pack_mode;
    /*!< bypass_flip bypass flip*/
    int32_t bypass_flip;
    /*!< bypass_mirror bypass mirror*/
    int32_t bypass_mirror;
    /*!< bypass_reduced_range bypass reduced range*/
    int32_t bypass_reduced_range;
    /*!< p_e[2] Multiplication parameters for pixel with even vertical index*/
    int32_t p_e[2];
    /*!< p_o[2] Multiplication parameters for pixel with odd vertical index*/
    int32_t p_o[2];

} ia_pal_isp_bxt_ofa_mp_t;

/*! \isp struct bxt_ofa_ppp

*/
typedef struct
{
    /*!< y_tiling tiling parameter for NV12 y_tiled format*/
    int32_t y_tiling;
    /*!< pack_mode pack mode for packer*/
    int32_t pack_mode;
    /*!< bypass_flip bypass flip*/
    int32_t bypass_flip;
    /*!< bypass_mirror bypass mirror*/
    int32_t bypass_mirror;
    /*!< bypass_reduced_range bypass reduced range*/
    int32_t bypass_reduced_range;
    /*!< p_e[2] Multiplication parameters for pixel with even vertical index*/
    int32_t p_e[2];
    /*!< p_o[2] Multiplication parameters for pixel with odd vertical index*/
    int32_t p_o[2];

} ia_pal_isp_bxt_ofa_ppp_t;

/*! \isp struct bxt_paddingsupport

*/
typedef struct
{
    /*!< m_bypass Bypass     {0,1}*/
    int32_t m_bypass;
    /*!< m_xsize Horizontal Frame Size. FIXME: Put correct max and default values*/
    int32_t m_xsize;
    /*!< m_ysize Vertical   Frame Size. FIXME: Put correct max and default values*/
    int32_t m_ysize;
    /*!< m_padval Padding value : zero(0), MaxVal(1), DuplicateLast(2)*/
    int32_t m_padval;

} ia_pal_isp_bxt_paddingsupport_t;

/*! \isp struct bxt_pafstatistics

*/
typedef struct
{
    /*!< paf_en 0: FF will not write to the PAF  array; 1: FF will write*/
    int32_t paf_en;
    /*!< paf_frame_width width of PAF frame (in PAF pixels)*/
    int32_t paf_frame_width;
    /*!< paf_frame_height height of PAF frame (in PAF lines)*/
    int32_t paf_frame_height;
    /*!< skip_horizontal_start number of skipped PAF pixel pairs at the start of each line pair*/
    int32_t skip_horizontal_start;
    /*!< skip_vertical_start number of skipped PAF line pairs at the start of the frame*/
    int32_t skip_vertical_start;
    /*!< block_width number of PAF pixel pairs per block in horizontal direction*/
    int32_t block_width;
    /*!< block_height number of PAF pixel pairs per block in vertical direction*/
    int32_t block_height;
    /*!< accum_horizontal number of consecutive PAF pixel pairs accumulated in horizontal direction*/
    int32_t accum_horizontal;
    /*!< skip_horizontal number of PAF pixel pairs skipped between accumulated pixel pairs in horizontal direction*/
    int32_t skip_horizontal;
    /*!< accum_vertical number of consecutive PAF pixel pairs accumulated in vertical direction*/
    int32_t accum_vertical;
    /*!< skip_vertical number of PAF line pairs skipped between accumulated pixel pairs in vertical direction*/
    int32_t skip_vertical;
    /*!< min_shift minimum evaluation shift in steps*/
    int32_t min_shift;
    /*!< shift_steps number of evaluation points, starting from m_paf_min_shift*/
    int32_t shift_steps;
    /*!< paf_shift_step_size phase evaluation step size in pixels*/
    int32_t paf_shift_step_size;
    /*!< paf_shifter configured so that the accumulated phase difference fits in the output register*/
    int32_t paf_shifter;
    /*!< split_accross_multiple_lines 0: SOP = SOL, EOP = EOL; 1: SOF determined by the reset, EOL determined by pixels per line*/
    int32_t split_accross_multiple_lines;
    /*!< pixels_per_line number of pixels per line; pixels_per_line <= paf_frame_width*/
    int32_t pixels_per_line;
    /*!< input_modes 0: RRRR + LLLL; 1: LLLL + RRRR; 2: RLRL; 3: LRLR; 4: RRRR + LLLL alternate; 5: LLLL + RRRR alternate; 6: RLRL alternate; 7: LRLR alternate*/
    int32_t input_modes;
    /*!< input_bpp 0: 8 bits; 1: 10 bits; 2: 12 bits; 3: 14 bits; 4: 16 bits*/
    int32_t input_bpp;
    /*!< int_prec internal precision of PAF pixels*/
    int32_t int_prec;

} ia_pal_isp_bxt_pafstatistics_t;

/*! \isp struct bxt_pixelformatter

*/
typedef struct
{
    /*!< m_bypass Bypass     {0,1}*/
    int32_t m_bypass;
    /*!< m_ColRemoval col removal- for setting bayer pattern*/
    int32_t m_ColRemoval;
    /*!< m_RowRemoval row removal- for setting bayer pattern*/
    int32_t m_RowRemoval;
    /*!< m_xstart Horizontal Starting Pixel. FIXME: Put correct max and default values*/
    int32_t m_xstart;
    /*!< m_ystart Vertical   Starting Pixel. FIXME: Put correct max and default values*/
    int32_t m_ystart;
    /*!< m_xsize Horizontal Frame Size. FIXME: Put correct max and default values*/
    int32_t m_xsize;
    /*!< m_ysize Vertical   Frame Size. FIXME: Put correct max and default values*/
    int32_t m_ysize;
    /*!< m_padval Padding value : zero(0), MaxVal(1), DuplicateLast(2)*/
    int32_t m_padval;

} ia_pal_isp_bxt_pixelformatter_t;

/*! \isp struct bxt_pixprecadapter

*/
typedef struct
{
    /*!< m_pixinprec HW Parameter  - Input Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixinprec;
    /*!< m_pixoutprec HW Parameter  - Output Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixoutprec;
    /*!< m_pixminprec HW Parameter - Minimum possible pixel precision for the input/output Pixel : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixminprec;
    /*!< m_isbayer Is Bayer? - RGB(0) Bayer(1)*/
    int32_t m_isbayer;
    /*!< m_cliptous 0 - Do not clip, 1 - Clip to unsigned*/
    int32_t m_cliptous;
    /*!< m_shiftlen 0 - Perform ShiftR Round, 1 - Perfom ShiftL*/
    int32_t m_shiftlen;
    /*!< m_shiftval Shift Value {0..7}*/
    int32_t m_shiftval;

} ia_pal_isp_bxt_pixprecadapter_t;

/*! \isp struct bxt_pixprecadapter_postvcr

*/
typedef struct
{
    /*!< m_pixinprec HW Parameter  - Input Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixinprec;
    /*!< m_pixoutprec HW Parameter  - Output Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixoutprec;
    /*!< m_pixminprec HW Parameter - Minimum possible pixel precision for the input/output Pixel : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixminprec;
    /*!< m_isbayer Is Bayer? - RGB(0) Bayer(1)*/
    int32_t m_isbayer;
    /*!< m_cliptous 0 - Do not clip, 1 - Clip to unsigned*/
    int32_t m_cliptous;
    /*!< m_shiftlen 0 - Perform ShiftR Round, 1 - Perfom ShiftL*/
    int32_t m_shiftlen;
    /*!< m_shiftval Shift Value {0..7}*/
    int32_t m_shiftval;

} ia_pal_isp_bxt_pixprecadapter_postvcr_t;

/*! \isp struct bxt_pixprecadapter_precropstills

*/
typedef struct
{
    /*!< m_pixinprec HW Parameter  - Input Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixinprec;
    /*!< m_pixoutprec HW Parameter  - Output Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixoutprec;
    /*!< m_pixminprec HW Parameter - Minimum possible pixel precision for the input/output Pixel : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixminprec;
    /*!< m_isbayer Is Bayer? - RGB(0) Bayer(1)*/
    int32_t m_isbayer;
    /*!< m_cliptous 0 - Do not clip, 1 - Clip to unsigned*/
    int32_t m_cliptous;
    /*!< m_shiftlen 0 - Perform ShiftR Round, 1 - Perfom ShiftL*/
    int32_t m_shiftlen;
    /*!< m_shiftval Shift Value {0..7}*/
    int32_t m_shiftval;

} ia_pal_isp_bxt_pixprecadapter_precropstills_t;

/*! \isp struct bxt_pixprecadapter_precropvideo

*/
typedef struct
{
    /*!< m_pixinprec HW Parameter  - Input Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixinprec;
    /*!< m_pixoutprec HW Parameter  - Output Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixoutprec;
    /*!< m_pixminprec HW Parameter - Minimum possible pixel precision for the input/output Pixel : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixminprec;
    /*!< m_isbayer Is Bayer? - RGB(0) Bayer(1)*/
    int32_t m_isbayer;
    /*!< m_cliptous 0 - Do not clip, 1 - Clip to unsigned*/
    int32_t m_cliptous;
    /*!< m_shiftlen 0 - Perform ShiftR Round, 1 - Perfom ShiftL*/
    int32_t m_shiftlen;
    /*!< m_shiftval Shift Value {0..7}*/
    int32_t m_shiftval;

} ia_pal_isp_bxt_pixprecadapter_precropvideo_t;

/*! \isp struct bxt_pixprecadapter_precsc2

*/
typedef struct
{
    /*!< m_pixinprec HW Parameter  - Input Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixinprec;
    /*!< m_pixoutprec HW Parameter  - Output Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixoutprec;
    /*!< m_pixminprec HW Parameter - Minimum possible pixel precision for the input/output Pixel : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixminprec;
    /*!< m_isbayer Is Bayer? - RGB(0) Bayer(1)*/
    int32_t m_isbayer;
    /*!< m_cliptous 0 - Do not clip, 1 - Clip to unsigned*/
    int32_t m_cliptous;
    /*!< m_shiftlen 0 - Perform ShiftR Round, 1 - Perfom ShiftL*/
    int32_t m_shiftlen;
    /*!< m_shiftval Shift Value {0..7}*/
    int32_t m_shiftval;

} ia_pal_isp_bxt_pixprecadapter_precsc2_t;

/*! \isp struct bxt_pixprecadapter_pregdc

*/
typedef struct
{
    /*!< m_pixinprec HW Parameter  - Input Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixinprec;
    /*!< m_pixoutprec HW Parameter  - Output Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixoutprec;
    /*!< m_pixminprec HW Parameter - Minimum possible pixel precision for the input/output Pixel : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixminprec;
    /*!< m_isbayer Is Bayer? - RGB(0) Bayer(1)*/
    int32_t m_isbayer;
    /*!< m_cliptous 0 - Do not clip, 1 - Clip to unsigned*/
    int32_t m_cliptous;
    /*!< m_shiftlen 0 - Perform ShiftR Round, 1 - Perfom ShiftL*/
    int32_t m_shiftlen;
    /*!< m_shiftval Shift Value {0..7}*/
    int32_t m_shiftval;

} ia_pal_isp_bxt_pixprecadapter_pregdc_t;

/*! \isp struct bxt_pixprecadapter_prevcud

*/
typedef struct
{
    /*!< m_pixinprec HW Parameter  - Input Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixinprec;
    /*!< m_pixoutprec HW Parameter  - Output Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixoutprec;
    /*!< m_pixminprec HW Parameter - Minimum possible pixel precision for the input/output Pixel : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixminprec;
    /*!< m_isbayer Is Bayer? - RGB(0) Bayer(1)*/
    int32_t m_isbayer;
    /*!< m_cliptous 0 - Do not clip, 1 - Clip to unsigned*/
    int32_t m_cliptous;
    /*!< m_shiftlen 0 - Perform ShiftR Round, 1 - Perfom ShiftL*/
    int32_t m_shiftlen;
    /*!< m_shiftval Shift Value {0..7}*/
    int32_t m_shiftval;

} ia_pal_isp_bxt_pixprecadapter_prevcud_t;

/*! \isp struct bxt_pixprecadapter_prewb

*/
typedef struct
{
    /*!< m_pixinprec HW Parameter  - Input Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixinprec;
    /*!< m_pixoutprec HW Parameter  - Output Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixoutprec;
    /*!< m_pixminprec HW Parameter - Minimum possible pixel precision for the input/output Pixel : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixminprec;
    /*!< m_isbayer Is Bayer? - RGB(0) Bayer(1)*/
    int32_t m_isbayer;
    /*!< m_cliptous 0 - Do not clip, 1 - Clip to unsigned*/
    int32_t m_cliptous;
    /*!< m_shiftlen 0 - Perform ShiftR Round, 1 - Perfom ShiftL*/
    int32_t m_shiftlen;
    /*!< m_shiftval Shift Value {0..7}*/
    int32_t m_shiftval;

} ia_pal_isp_bxt_pixprecadapter_prewb_t;

/*! \isp struct bxt_rynr_collector

*/
typedef struct
{
    /*!< input_pin dummy parameter for HW purpose; 1 - Stills, 0 - Video*/
    int32_t input_pin;

} ia_pal_isp_bxt_rynr_collector_t;

/*! \isp struct bxt_rynr_splitter

*/
typedef struct
{
    /*!< input_pin Which input pin connect to output: if 1 (Stills), output pin is InputPin1 (pcsBayer), if 0 (Video), output pin is InputPin0 (pcsYUV420)*/
    int32_t input_pin;

} ia_pal_isp_bxt_rynr_splitter_t;

/*! \isp struct bxt_shift14to16bit

*/
typedef struct
{
    /*!< m_bypass Bypass        {0,1}*/
    int32_t m_bypass;
    /*!< m_shiftmode Shift : 14To16(0), 16To14(1)*/
    int32_t m_shiftmode;
    /*!< m_isbayer Is Bayer? - Bayer(0) RGB(1)*/
    int32_t m_isbayer;

} ia_pal_isp_bxt_shift14to16bit_t;

/*! \isp struct bxt_tnr5v1

*/
typedef struct
{
    /*!< nm_luma_lut[64] Noise model LUMA lut (for I core)*/
    int32_t nm_luma_lut[64];
    /*!< nm_chroma_lut[64] Noise model Chroma LUT (for I core)*/
    int32_t nm_chroma_lut[64];
    /*!< nm_spnr_lut[64] Noise model LUMA lut, for II core, beem used by spNR*/
    int32_t nm_spnr_lut[64];
    /*!< nm_radial_lut[128] Noise model radial Lut*/
    int32_t nm_radial_lut[128];
    /*!< nm_radial_r2_shift Noise model radial shift*/
    int32_t nm_radial_r2_shift;
    /*!< nm_radial_x_center Noise model radial- center of image x corr*/
    int32_t nm_radial_x_center;
    /*!< nm_radial_y_center Noise model radial- center of image y corr*/
    int32_t nm_radial_y_center;
    /*!< co_max_content maximal value for the content*/
    int32_t co_max_content;
    /*!< co_content_shift shift right for content*/
    int32_t co_content_shift;
    /*!< fm_sim_lut[64] FMVE Similarity LUT for grade calculation*/
    int32_t fm_sim_lut[64];
    /*!< fm_dist_weights[128] FMVE distance weight for the tow BMA unit*/
    int32_t fm_dist_weights[128];
    /*!< fm_sad_shift shift for the SAD values in the FMVE sub-block (using realigning)*/
    int32_t fm_sad_shift;
    /*!< fm_sim_arg_shift shift for FMVE similarity arg values.*/
    int32_t fm_sim_arg_shift;
    /*!< mvd_sim_lut[64] MVD Similarity LUT*/
    int32_t mvd_sim_lut[64];
    /*!< mvd_sad_shift shift for the SAD values in the MVD sub-block (using realigning)*/
    int32_t mvd_sad_shift;
    /*!< mvd_arg_g_static The gain for the recursive similarity at case of static MV . together  with neighbors*/
    int32_t mvd_arg_g_static;
    /*!< mvd_arg_g_static_local The gain for the recursive similarity at case of static MV, neighbors have a different MV*/
    int32_t mvd_arg_g_static_local;
    /*!< mvd_arg_g_move The gain for the recursive similarity at case of non-static MV,  together  with neighbors*/
    int32_t mvd_arg_g_move;
    /*!< mvd_arg_g_move_local The gain for the recursive similarity at case of non-static MV,neighbors have a different MV*/
    int32_t mvd_arg_g_move_local;
    /*!< spnr_lut_h[64] spNR BF lut for horizontal direction*/
    int32_t spnr_lut_h[64];
    /*!< spnr_lut_v[64] spNR BF lut for vertical direction*/
    int32_t spnr_lut_v[64];
    /*!< pb_weight_pre_max maximal spTNR weight*/
    int32_t pb_weight_pre_max;
    /*!< pb_weight_in_min The minimal weight of the input frame at the blended output image.*/
    int32_t pb_weight_in_min;
    /*!< no_fmve FMVE debug flag, 0-run, 1-don't run, 2- don't run, but run content*/
    int32_t no_fmve;
    /*!< bypass bypass flag, output is 4 bit shifted input*/
    int32_t bypass;
    /*!< framenumber frame number. Should be in PAL*/
    int32_t framenumber;
    /*!< g_mv_x global  MV_X. Should be in PAL*/
    int32_t g_mv_x;
    /*!< g_mv_y global  MV_Y. Should be in PAL*/
    int32_t g_mv_y;

} ia_pal_isp_bxt_tnr5v1_t;

/*! \isp struct bxt_vcr

*/
typedef struct
{
    /*!< bypass_0_1 Bypass VCR*/
    int32_t bypass_0_1;

} ia_pal_isp_bxt_vcr_t;

/*! \isp struct bxt_vcr2

*/
typedef struct
{
    /*!< bypass_0_1 Bypass VCR2*/
    int32_t bypass_0_1;
    /*!< input_format_420 0 - input 4:4:4 , 1 - input 4:2:0*/
    int32_t input_format_420;
    /*!< lpf_p0_c0 Phase 0 - coef 0*/
    int32_t lpf_p0_c0;
    /*!< lpf_p0_c1 Phase 0 - coef 1*/
    int32_t lpf_p0_c1;
    /*!< lpf_p0_c2 Phase 0 - coef 2*/
    int32_t lpf_p0_c2;
    /*!< lpf_p0_c3 Phase 0 - coef 3*/
    int32_t lpf_p0_c3;
    /*!< lpf_p1_c0 Phase 1 - coef 0*/
    int32_t lpf_p1_c0;
    /*!< lpf_p1_c1 Phase 1 - coef 1*/
    int32_t lpf_p1_c1;
    /*!< lpf_p1_c2 Phase 1 - coef 2*/
    int32_t lpf_p1_c2;
    /*!< lpf_p1_c3 Phase 1 - coef 3*/
    int32_t lpf_p1_c3;

} ia_pal_isp_bxt_vcr2_t;

/*! \isp struct bxt_vcsc

*/
typedef struct
{
    /*!< bypass Block bypass for HW use*/
    int32_t bypass;
    /*!< gain Matrix table gain exponent*/
    int32_t gain;
    /*!< coef_matrix[12] 3x4 Matrix coeffcients, Q10*/
    int32_t coef_matrix[12];
    /*!< t0 matrix offeset 0 (y)*/
    int32_t t0;
    /*!< t1 matrix offeset 1 (u)*/
    int32_t t1;
    /*!< t2 matrix offeset y (v)*/
    int32_t t2;
    /*!< fir_alpha_h Horizontal filter 2nd tap coeffcient [0.0…0.33], Q10*/
    int32_t fir_alpha_h;
    /*!< fir_alpha_v Vertical filter 2nd tap coeffcient [0.0…0.33], Q10*/
    int32_t fir_alpha_v;

} ia_pal_isp_bxt_vcsc_t;

/*! \isp struct bxt_vcsc_stills

*/
typedef struct
{
    /*!< bypass Block bypass for HW use*/
    int32_t bypass;
    /*!< gain Matrix table gain exponent*/
    int32_t gain;
    /*!< coef_matrix[12] 3x4 Matrix coeffcients, Q10*/
    int32_t coef_matrix[12];
    /*!< t0 matrix offeset 0 (y)*/
    int32_t t0;
    /*!< t1 matrix offeset 1 (u)*/
    int32_t t1;
    /*!< t2 matrix offeset y (v)*/
    int32_t t2;
    /*!< fir_alpha_h Horizontal filter 2nd tap coeffcient [0.0…0.33], Q10*/
    int32_t fir_alpha_h;
    /*!< fir_alpha_v Vertical filter 2nd tap coeffcient [0.0…0.33], Q10*/
    int32_t fir_alpha_v;

} ia_pal_isp_bxt_vcsc_stills_t;

/*! \isp struct bxt_vcsc_video

*/
typedef struct
{
    /*!< bypass Block bypass for HW use*/
    int32_t bypass;
    /*!< gain Matrix table gain exponent*/
    int32_t gain;
    /*!< coef_matrix[12] 3x4 Matrix coeffcients, Q10*/
    int32_t coef_matrix[12];
    /*!< t0 matrix offeset 0 (y)*/
    int32_t t0;
    /*!< t1 matrix offeset 1 (u)*/
    int32_t t1;
    /*!< t2 matrix offeset y (v)*/
    int32_t t2;
    /*!< fir_alpha_h Horizontal filter 2nd tap coeffcient [0.0…0.33], Q10*/
    int32_t fir_alpha_h;
    /*!< fir_alpha_v Vertical filter 2nd tap coeffcient [0.0…0.33], Q10*/
    int32_t fir_alpha_v;

} ia_pal_isp_bxt_vcsc_video_t;

/*! \isp struct bxt_vcud

*/
typedef struct
{
    /*!< bypass Block bypass for HW use*/
    int32_t bypass;
    /*!< chm_offset_u U bias*/
    int32_t chm_offset_u;
    /*!< chm_offset_v V bias*/
    int32_t chm_offset_v;
    /*!< chm_gain gain exponent of chroma metric*/
    int32_t chm_gain;
    /*!< lcs_th_low Low Chroma suppression threshold low*/
    int32_t lcs_th_low;
    /*!< lcs_th_high Low Chroma suppression threshold high*/
    int32_t lcs_th_high;
    /*!< cu_lcs_x_points[6] CU LCS X points*/
    int32_t cu_lcs_x_points[6];
    /*!< cu_lcs_y_points[5] CU LCS Y points*/
    int32_t cu_lcs_y_points[5];
    /*!< cu_lcs_slopes[5] CU LCS Slopes, Q4*/
    int32_t cu_lcs_slopes[5];
    /*!< cu_noise_x_points[7] CU Noise X points*/
    int32_t cu_noise_x_points[7];
    /*!< cu_noise_y_points[6] CU Noise Y points*/
    int32_t cu_noise_y_points[6];
    /*!< cu_noise_slopes[6] CU Noise Slopes, Q5*/
    int32_t cu_noise_slopes[6];
    /*!< cu_radial_x_points[6] CU Radial X points*/
    int32_t cu_radial_x_points[6];
    /*!< cu_radial_y_points[5] CU Radial Y points*/
    int32_t cu_radial_y_points[5];
    /*!< cu_radial_slopes[5] CU Radial Slopes, Q8*/
    int32_t cu_radial_slopes[5];
    /*!< cu_psdiv_lcs_x_points[12] CU psdiv_lcs X points*/
    int32_t cu_psdiv_lcs_x_points[12];
    /*!< cu_psdiv_lcs_y_points[11] CU psdiv_lcs Y points*/
    int32_t cu_psdiv_lcs_y_points[11];
    /*!< cu_psdiv_lcs_slopes[11] CU psdiv_lcs Slopes, Q10*/
    int32_t cu_psdiv_lcs_slopes[11];
    /*!< cu_psdiv_jbl_x_points[12] CU psdiv_jbl X points*/
    int32_t cu_psdiv_jbl_x_points[12];
    /*!< cu_psdiv_jbl_y_points[11] CU psdiv_jbl Y points*/
    int32_t cu_psdiv_jbl_y_points[11];
    /*!< cu_psdiv_jbl_slopes[11] CU psdiv_jbl Slopes, Q10*/
    int32_t cu_psdiv_jbl_slopes[11];
    /*!< noise_beta[9] Noise model Beta coefficients*/
    int32_t noise_beta[9];
    /*!< lpf_coefs[6] Bilatheral Spatial filter coefficients , Q10, {c0, c3,c4,c6,c7,c8}*/
    int32_t lpf_coefs[6];
    /*!< jbl_center_loc JBL center location for noise model*/
    int32_t jbl_center_loc;
    /*!< jbl_sigma_y JBL Y noise sigma power, Q6*/
    int32_t jbl_sigma_y;
    /*!< jbl_sigma_u JBL U noise  sigma power, Q6*/
    int32_t jbl_sigma_u;
    /*!< jbl_sigma_v JBL V noise sigma power, Q6*/
    int32_t jbl_sigma_v;
    /*!< jbl_dist_epsilon JBL minmum distance*/
    int32_t jbl_dist_epsilon;
    /*!< jbl_noise_epsilon2 JBL minimum noise estimation*/
    int32_t jbl_noise_epsilon2;
    /*!< jbl_exp2_min JBL minimum value similarity weight (exp^1/2x^2)*/
    int32_t jbl_exp2_min;
    /*!< jbl_weight_th JBL minimum weight threshold*/
    int32_t jbl_weight_th;
    /*!< upscale_only_en 0 - VCUD do denoising and duplicate chroma to 4:4:4, 1 - VCUD do only bicubic chroma upsampling to 4:4:4*/
    int32_t upscale_only_en;
    /*!< rad_en Enable Radial parameters*/
    int32_t rad_en;
    /*!< rad_x_reset top left pixel X location relative to the optical center point*/
    int32_t rad_x_reset;
    /*!< rad_y_reset top left pixel Y location relative to the optical center point*/
    int32_t rad_y_reset;
    /*!< rad_x2_reset rad_x_reset * rad_x_reset*/
    int32_t rad_x2_reset;
    /*!< rad_y2_reset rad_y_reset * rad_y_reset*/
    int32_t rad_y2_reset;
    /*!< rad_nf exponent gain for rad_inv_r2*/
    int32_t rad_nf;
    /*!< rad_inv_r2 1/radius * 2^???*/
    int32_t rad_inv_r2;
    /*!< rad_jbl_sigma_y Radial*/
    int32_t rad_jbl_sigma_y;
    /*!< rad_jbl_sigma_u Radial*/
    int32_t rad_jbl_sigma_u;
    /*!< rad_jbl_sigma_v Radial*/
    int32_t rad_jbl_sigma_v;
    /*!< rad_jbl_dist_epsilon Radial*/
    int32_t rad_jbl_dist_epsilon;
    /*!< rad_jbl_noise_epsilon2 Radial*/
    int32_t rad_jbl_noise_epsilon2;

} ia_pal_isp_bxt_vcud_t;

/*! \isp struct bxt_wb

*/
typedef struct
{
    /*!< m_bypass Bypass            {0,1}*/
    int32_t m_bypass;
    /*!< m_gainch0 Gain Channel0 (Gr) (U4.12)*/
    int32_t m_gainch0;
    /*!< m_gainch1 Gain Channel1 (Gb) (U4.12)*/
    int32_t m_gainch1;
    /*!< m_gainch2 Gain Channel2 (G)  (U4.12)*/
    int32_t m_gainch2;
    /*!< m_gainch3 Gain Channel3 (B)  (U4.12)*/
    int32_t m_gainch3;
    /*!< m_gainch4 Gain Channel4 (R)  (U4.12)*/
    int32_t m_gainch4;
    /*!< m_gainch5 Gain Channel5 (W)  (U4.12)*/
    int32_t m_gainch5;
    /*!< m_gainch6 Gain Channel6 (U4.12)*/
    int32_t m_gainch6;
    /*!< m_gainch7 Gain Channel7 (U4.12)*/
    int32_t m_gainch7;
    /*!< m_sensormode 1x1 (0), 2x2 (1), 4x4 (2)*/
    int32_t m_sensormode;
    /*!< m_wbindmat[16] Vector WB matrix*/
    int32_t m_wbindmat[16];

} ia_pal_isp_bxt_wb_t;

/*! \isp struct bxt_wb_stills

*/
typedef struct
{
    /*!< m_bypass Bypass            {0,1}*/
    int32_t m_bypass;
    /*!< m_gainch0 Gain Channel0 (Gr) (U4.12)*/
    int32_t m_gainch0;
    /*!< m_gainch1 Gain Channel1 (Gb) (U4.12)*/
    int32_t m_gainch1;
    /*!< m_gainch2 Gain Channel2 (G)  (U4.12)*/
    int32_t m_gainch2;
    /*!< m_gainch3 Gain Channel3 (B)  (U4.12)*/
    int32_t m_gainch3;
    /*!< m_gainch4 Gain Channel4 (R)  (U4.12)*/
    int32_t m_gainch4;
    /*!< m_gainch5 Gain Channel5 (W)  (U4.12)*/
    int32_t m_gainch5;
    /*!< m_gainch6 Gain Channel6 (U4.12)*/
    int32_t m_gainch6;
    /*!< m_gainch7 Gain Channel7 (U4.12)*/
    int32_t m_gainch7;
    /*!< m_sensormode 1x1 (0), 2x2 (1), 4x4 (2)*/
    int32_t m_sensormode;
    /*!< m_wbindmat[16] Vector WB matrix*/
    int32_t m_wbindmat[16];

} ia_pal_isp_bxt_wb_stills_t;

/*! \isp struct bxt_xnr4_m
Scalable Chroma and Luma Denoise, Medium and High Frequency
*/
typedef struct
{
    /*!< jbl_mf_bypass_y Bypass JBL MF Luma*/
    int32_t jbl_mf_bypass_y;
    /*!< jbl_mf_bypass_c Bypass MF Chroma*/
    int32_t jbl_mf_bypass_c;
    /*!< noise_sigma_mf_y_y Noise Sigma MF Luma per Luma*/
    int32_t noise_sigma_mf_y_y;
    /*!< noise_sigma_mf_y_s Noise Sigma MF Luma per Satoration*/
    int32_t noise_sigma_mf_y_s;
    /*!< noise_sigma_mf_c_y Noise Sigma MF Chroma per Luma*/
    int32_t noise_sigma_mf_c_y;
    /*!< noise_sigma_mf_c_u Noise Sigma MF Chroma per U*/
    int32_t noise_sigma_mf_c_u;
    /*!< noise_sigma_mf_c_v Noise Sigma MF Chroma per V*/
    int32_t noise_sigma_mf_c_v;
    /*!< rad_noise_sigma_mf_y_y Noise Sigma MF Luma per Luma - radial*/
    int32_t rad_noise_sigma_mf_y_y;
    /*!< rad_noise_sigma_mf_y_s Noise Sigma MF Luma per Satoration - radial*/
    int32_t rad_noise_sigma_mf_y_s;
    /*!< rad_noise_sigma_mf_c_y Noise Sigma MF Chroma per Luma - radial*/
    int32_t rad_noise_sigma_mf_c_y;
    /*!< rad_noise_sigma_mf_c_u Noise Sigma MF Chroma per U - radial*/
    int32_t rad_noise_sigma_mf_c_u;
    /*!< rad_noise_sigma_mf_c_v Noise Sigma MF Chroma per V - radial*/
    int32_t rad_noise_sigma_mf_c_v;
    /*!< noise_epsilon_mf_y_y Luma min noise variance per Luma , Q12*/
    int32_t noise_epsilon_mf_y_y;
    /*!< noise_epsilon_mf_c_y Chroma min noise variance per Luma , Q12*/
    int32_t noise_epsilon_mf_c_y;
    /*!< noise_epsilon_mf_c_u Chroma min noise variance per U , Q12*/
    int32_t noise_epsilon_mf_c_u;
    /*!< noise_epsilon_mf_c_v Chroma min noise variance per V , Q12*/
    int32_t noise_epsilon_mf_c_v;
    /*!< rad_noise_epsilon_mf_y_y Luma min noise variance per Luma , Q12 - radial*/
    int32_t rad_noise_epsilon_mf_y_y;
    /*!< rad_noise_epsilon_mf_c_y Chroma min noise variance per Luma , Q12 - radial*/
    int32_t rad_noise_epsilon_mf_c_y;
    /*!< rad_noise_epsilon_mf_c_u Chroma min noise variance per U , Q12 - radial*/
    int32_t rad_noise_epsilon_mf_c_u;
    /*!< rad_noise_epsilon_mf_c_v Chroma min noise variance per V , Q12 - radial*/
    int32_t rad_noise_epsilon_mf_c_v;
    /*!< jbl_weight_th_mf_y Luma Weight threshold of MF JBL*/
    int32_t jbl_weight_th_mf_y;
    /*!< jbl_weight_th_mf_c Chroma Weight threshold of MF JBL*/
    int32_t jbl_weight_th_mf_c;
    /*!< lpf_mf_coef_y[49] MF JBL Spatial coefs for Luma*/
    int32_t lpf_mf_coef_y[49];
    /*!< lpf_mf_coef_c[49] MF JBL Spatial coefs for Chroma*/
    int32_t lpf_mf_coef_c[49];
    /*!< range_weight_lut[7] JBL range Weight LUT*/
    int32_t range_weight_lut[7];
    /*!< blend_mf_power_y MF denoise blending power y*/
    int32_t blend_mf_power_y;
    /*!< blend_mf_power_c MF denoise blending power chroma*/
    int32_t blend_mf_power_c;
    /*!< rad_blend_mf_power_y MF denoise blending power y - radial*/
    int32_t rad_blend_mf_power_y;
    /*!< rad_blend_mf_power_c MF denoise blending power chroma -radial*/
    int32_t rad_blend_mf_power_c;
    /*!< noise_beta_y_0 noise model for y - coef 0, Q12*/
    int32_t noise_beta_y_0;
    /*!< noise_beta_u_0 noise model for u - coef 0, Q12*/
    int32_t noise_beta_u_0;
    /*!< noise_beta_u_1 noise model for u - coef 1, Q12*/
    int32_t noise_beta_u_1;
    /*!< noise_beta_v_0 noise model for v - coef 0, Q12*/
    int32_t noise_beta_v_0;
    /*!< noise_beta_v_2 noise model for v - coef 2, Q12*/
    int32_t noise_beta_v_2;
    /*!< rad_center_x X location of the radial center location relative to the top left pixel*/
    int32_t rad_center_x;
    /*!< rad_center_y Y location of the radial center location relative to the top left pixel*/
    int32_t rad_center_y;
    /*!< rad_exp Radial scale bit into the Lut*/
    int32_t rad_exp;
    /*!< rad_lut[128] Radial LUT*/
    int32_t rad_lut[128];
    /*!< one_div_64_lut[64] 1/SQRT(x), first 64 values LUT*/
    int32_t one_div_64_lut[64];
    /*!< xcu_divsqrt_exp XCU divsqrt exponent*/
    int32_t xcu_divsqrt_exp;
    /*!< xcu_divsqrt_slp_a_res XCU divsqrt slope precision*/
    int32_t xcu_divsqrt_slp_a_res;
    /*!< xcu_divsqrt_offset[16] XCU divsqrt offset(y) vector*/
    int32_t xcu_divsqrt_offset[16];
    /*!< xcu_divsqrt_slope[16] XCU divsqrt slope vector*/
    int32_t xcu_divsqrt_slope[16];
    /*!< xcu_divsqrt_x[17] XCU divsqrt x points vector + maximal x value*/
    int32_t xcu_divsqrt_x[17];

} ia_pal_isp_bxt_xnr4_m_t;

/*! \isp struct bxt_xnr4_mh
Scalable Chroma and Luma Denoise, Medium and High Frequency
*/
typedef struct
{
    /*!< jbl_mf_bypass_y Bypass JBL MF Luma*/
    int32_t jbl_mf_bypass_y;
    /*!< jbl_mf_bypass_c Bypass MF Chroma*/
    int32_t jbl_mf_bypass_c;
    /*!< noise_sigma_mf_y_y Noise Sigma MF Luma per Luma*/
    int32_t noise_sigma_mf_y_y;
    /*!< noise_sigma_mf_y_s Noise Sigma MF Luma per Satoration*/
    int32_t noise_sigma_mf_y_s;
    /*!< noise_sigma_mf_c_y Noise Sigma MF Chroma per Luma*/
    int32_t noise_sigma_mf_c_y;
    /*!< noise_sigma_mf_c_u Noise Sigma MF Chroma per U*/
    int32_t noise_sigma_mf_c_u;
    /*!< noise_sigma_mf_c_v Noise Sigma MF Chroma per V*/
    int32_t noise_sigma_mf_c_v;
    /*!< rad_noise_sigma_mf_y_y Noise Sigma MF Luma per Luma - radial*/
    int32_t rad_noise_sigma_mf_y_y;
    /*!< rad_noise_sigma_mf_y_s Noise Sigma MF Luma per Satoration - radial*/
    int32_t rad_noise_sigma_mf_y_s;
    /*!< rad_noise_sigma_mf_c_y Noise Sigma MF Chroma per Luma - radial*/
    int32_t rad_noise_sigma_mf_c_y;
    /*!< rad_noise_sigma_mf_c_u Noise Sigma MF Chroma per U - radial*/
    int32_t rad_noise_sigma_mf_c_u;
    /*!< rad_noise_sigma_mf_c_v Noise Sigma MF Chroma per V - radial*/
    int32_t rad_noise_sigma_mf_c_v;
    /*!< noise_epsilon_mf_y_y Luma min noise variance per Luma , Q12*/
    int32_t noise_epsilon_mf_y_y;
    /*!< noise_epsilon_mf_c_y Chroma min noise variance per Luma , Q12*/
    int32_t noise_epsilon_mf_c_y;
    /*!< noise_epsilon_mf_c_u Chroma min noise variance per U , Q12*/
    int32_t noise_epsilon_mf_c_u;
    /*!< noise_epsilon_mf_c_v Chroma min noise variance per V , Q12*/
    int32_t noise_epsilon_mf_c_v;
    /*!< rad_noise_epsilon_mf_y_y Luma min noise variance per Luma , Q12 - radial*/
    int32_t rad_noise_epsilon_mf_y_y;
    /*!< rad_noise_epsilon_mf_c_y Chroma min noise variance per Luma , Q12 - radial*/
    int32_t rad_noise_epsilon_mf_c_y;
    /*!< rad_noise_epsilon_mf_c_u Chroma min noise variance per U , Q12 - radial*/
    int32_t rad_noise_epsilon_mf_c_u;
    /*!< rad_noise_epsilon_mf_c_v Chroma min noise variance per V , Q12 - radial*/
    int32_t rad_noise_epsilon_mf_c_v;
    /*!< jbl_weight_th_mf_y Luma Weight threshold of MF JBL*/
    int32_t jbl_weight_th_mf_y;
    /*!< jbl_weight_th_mf_c Chroma Weight threshold of MF JBL*/
    int32_t jbl_weight_th_mf_c;
    /*!< lpf_mf_coef_y[49] MF JBL Spatial coefs for Luma*/
    int32_t lpf_mf_coef_y[49];
    /*!< lpf_mf_coef_c[49] MF JBL Spatial coefs for Chroma*/
    int32_t lpf_mf_coef_c[49];
    /*!< range_weight_lut[7] JBL range Weight LUT*/
    int32_t range_weight_lut[7];
    /*!< blend_mf_power_y MF denoise blending power y*/
    int32_t blend_mf_power_y;
    /*!< blend_mf_power_c MF denoise blending power chroma*/
    int32_t blend_mf_power_c;
    /*!< rad_blend_mf_power_y MF denoise blending power y - radial*/
    int32_t rad_blend_mf_power_y;
    /*!< rad_blend_mf_power_c MF denoise blending power chroma -radial*/
    int32_t rad_blend_mf_power_c;
    /*!< noise_beta_y_0 noise model for y - coef 0, Q12*/
    int32_t noise_beta_y_0;
    /*!< noise_beta_u_0 noise model for u - coef 0, Q12*/
    int32_t noise_beta_u_0;
    /*!< noise_beta_u_1 noise model for u - coef 1, Q12*/
    int32_t noise_beta_u_1;
    /*!< noise_beta_v_0 noise model for v - coef 0, Q12*/
    int32_t noise_beta_v_0;
    /*!< noise_beta_v_2 noise model for v - coef 2, Q12*/
    int32_t noise_beta_v_2;
    /*!< rad_center_x X location of the radial center location relative to the top left pixel*/
    int32_t rad_center_x;
    /*!< rad_center_y Y location of the radial center location relative to the top left pixel*/
    int32_t rad_center_y;
    /*!< rad_exp Radial scale bit into the Lut*/
    int32_t rad_exp;
    /*!< rad_lut[128] Radial LUT*/
    int32_t rad_lut[128];
    /*!< one_div_64_lut[64] 1/SQRT(x), first 64 values LUT*/
    int32_t one_div_64_lut[64];
    /*!< xcu_divsqrt_exp XCU divsqrt exponent*/
    int32_t xcu_divsqrt_exp;
    /*!< xcu_divsqrt_slp_a_res XCU divsqrt slope precision*/
    int32_t xcu_divsqrt_slp_a_res;
    /*!< xcu_divsqrt_offset[16] XCU divsqrt offset(y) vector*/
    int32_t xcu_divsqrt_offset[16];
    /*!< xcu_divsqrt_slope[16] XCU divsqrt slope vector*/
    int32_t xcu_divsqrt_slope[16];
    /*!< xcu_divsqrt_x[17] XCU divsqrt x points vector + maximal x value*/
    int32_t xcu_divsqrt_x[17];
    /*!< jbl_hf_bypass_c Bypass HF Chroma*/
    int32_t jbl_hf_bypass_c;
    /*!< noise_sigma_hf_c_y Noise Sigma HF Chroma per Luma*/
    int32_t noise_sigma_hf_c_y;
    /*!< noise_sigma_hf_c_u Noise Sigma HF Chroma per U*/
    int32_t noise_sigma_hf_c_u;
    /*!< noise_sigma_hf_c_v Noise Sigma HF Chroma per V*/
    int32_t noise_sigma_hf_c_v;
    /*!< rad_noise_sigma_hf_c_y Noise Sigma HF Chroma per Luma - radial*/
    int32_t rad_noise_sigma_hf_c_y;
    /*!< rad_noise_sigma_hf_c_u Noise Sigma HF Chroma per U - radial*/
    int32_t rad_noise_sigma_hf_c_u;
    /*!< rad_noise_sigma_hf_c_v Noise Sigma HF Chroma per V - radial*/
    int32_t rad_noise_sigma_hf_c_v;
    /*!< noise_epsilon_hf_c_y Chroma min noise variance per Luma , Q12*/
    int32_t noise_epsilon_hf_c_y;
    /*!< noise_epsilon_hf_c_u Chroma min noise variance per U , Q12*/
    int32_t noise_epsilon_hf_c_u;
    /*!< noise_epsilon_hf_c_v Chroma min noise variance per V , Q12*/
    int32_t noise_epsilon_hf_c_v;
    /*!< rad_noise_epsilon_hf_c_y Chroma min noise variance per Luma , Q12 - radial*/
    int32_t rad_noise_epsilon_hf_c_y;
    /*!< rad_noise_epsilon_hf_c_u Chroma min noise variance per U , Q12 -radial*/
    int32_t rad_noise_epsilon_hf_c_u;
    /*!< rad_noise_epsilon_hf_c_v Chroma min noise variance per V , Q12 -radial*/
    int32_t rad_noise_epsilon_hf_c_v;
    /*!< lpf_hf_coef_c[49] HF JBL Spatial coefs for Chroma*/
    int32_t lpf_hf_coef_c[49];
    /*!< jbl_weight_th_hf_c Chroma Weight threshold of HF JBL*/
    int32_t jbl_weight_th_hf_c;
    /*!< lcs_th_low Low Chroma Suppertion threshold for black level*/
    int32_t lcs_th_low;
    /*!< lcs_th_high_delta Low Chroma Suppertion threshold for white level (delta from black)*/
    int32_t lcs_th_high_delta;
    /*!< rad_lcs_th_low Low Chroma Suppertion threshold for black level - radial (delta from low)*/
    int32_t rad_lcs_th_low;
    /*!< rad_lcs_th_high_delta Low Chroma Suppertion threshold for white level -radial (delta form high delta)*/
    int32_t rad_lcs_th_high_delta;
    /*!< xcu_lcs_exp XCU ed exponent*/
    int32_t xcu_lcs_exp;
    /*!< xcu_lcs_slp_a_res XCU ed slope precision*/
    int32_t xcu_lcs_slp_a_res;
    /*!< xcu_lcs_offset[32] XCU ed offset(y) vector*/
    int32_t xcu_lcs_offset[32];
    /*!< xcu_lcs_slope[32] XCU ed slope vector*/
    int32_t xcu_lcs_slope[32];
    /*!< xcu_lcs_x[33] XCU ed x points vector + maximal x value*/
    int32_t xcu_lcs_x[33];
    /*!< nncu_hf_luma_blend_exp NNCU HF Luma blend  exponent*/
    int32_t nncu_hf_luma_blend_exp;
    /*!< nncu_hf_luma_blend_offset[64] NNCU HF Luma blend offset vector*/
    int32_t nncu_hf_luma_blend_offset[64];
    /*!< nncu_hf_luma_blend_x_0 NNCU HF Luma blend first X cordinate*/
    int32_t nncu_hf_luma_blend_x_0;
    /*!< nncu_hf_luma_blend_x_max NNCU HF Luma blend last X cordinate ( the #65 corrdinate -1)*/
    int32_t nncu_hf_luma_blend_x_max;
    /*!< hf_luma_power HF Luma denoise power, Q15*/
    int32_t hf_luma_power;
    /*!< rad_hf_luma_power HF Luma denoise power, Q15 -radial*/
    int32_t rad_hf_luma_power;
    /*!< blend_hf_power_c blend_mf_power_c HF denoise blending power chroma*/
    int32_t blend_hf_power_c;

} ia_pal_isp_bxt_xnr4_mh_t;

/*! \isp struct call_info
Call info contains timestamp of current call to calculate ISP parameters. This information is used to determine run rate of each PAL component.
*/
typedef struct
{
    /*!< timestamp[2] Timestamp of current iteration. 64 bit value (using both int32 values in the array as one).*/
    int32_t timestamp[2];

} ia_pal_isp_call_info_t;

/*! \isp struct cas_1_0

*/
typedef struct
{
    /*!< enable Block enable for HW use*/
    int32_t enable;
    /*!< x_center Optical center x. Bittage is enough to fit 16K resolution*/
    int32_t x_center;
    /*!< y_center Optical center y. Bittage is enough to fit 16K resolution*/
    int32_t y_center;
    /*!< x_start Starting column of the fragment. Max number of pixels per line in a stripe is 4096*/
    int32_t x_start;
    /*!< y_start Starting row of the fragment (Usualy will be 0)*/
    int32_t y_start;
    /*!< inv_spatial_model[16] Describes the inverse spatial noise*/
    int32_t inv_spatial_model[16];
    /*!< spatial_step_log2 log2 of spatial lut step size. Bittage is enough for supporting 8192x4320 resulotion*/
    int32_t spatial_step_log2;
    /*!< nm_lut[16] noise model for luma. Save&restore register (will be ovveride in video mode)*/
    int32_t nm_lut[16];
    /*!< apu_alpha_limit update mechanism in apu - as limit increases, we need more measurements for the histogram bins to be considered as reliable.*/
    int32_t apu_alpha_limit;
    /*!< apu_alpha_power update mechanism in apu - as power increase, we count more on the new val calculated then the one from previous frame.*/
    int32_t apu_alpha_power;
    /*!< hist_vals[256] histogram valuse of APU to flow between fragments. save and restore. 2D array of size 16*(2^(4))( HWP_APU_N_VALUES*(1<<HWP_APU_HIST_N_BINS_EXP)). precision is 20 (HWP_APU_HIST_BIN_BITTAGE)*/
    int32_t hist_vals[256];
    /*!< skin_sharp_suppression_power Suppress sharpening in human skin areas*/
    int32_t skin_sharp_suppression_power;
    /*!< signal_metric_low_th low threshold for normalizing signal metric map*/
    int32_t signal_metric_low_th;
    /*!< signal_metric_slope slope for normalizing signal metric map*/
    int32_t signal_metric_slope;
    /*!< texture_noise_regulator detects less textures for higher values [0,0.2]*/
    int32_t texture_noise_regulator;
    /*!< texture_low_th low threshold for normalizing texture map. Values below this threshold will be consider as none texture.*/
    int32_t texture_low_th;
    /*!< texture_slope slope for normalizing texture map. This will be used to calculate the high threshold*/
    int32_t texture_slope;
    /*!< unsharpfilter[15] Unsharp-mask filter coefficients*/
    int32_t unsharpfilter[15];
    /*!< power_luma_control_enable enables the luma control mechanism*/
    int32_t power_luma_control_enable;
    /*!< cu_power_luma_control_x[4] x axis values for luma sharpening config-unit*/
    int32_t cu_power_luma_control_x[4];
    /*!< cu_power_luma_control_y[3] y axis values for luma sharpening config-unit*/
    int32_t cu_power_luma_control_y[3];
    /*!< cu_power_luma_control_slope[3] slope values for luma sharpening config-unit*/
    int32_t cu_power_luma_control_slope[3];
    /*!< power_spatial_control_th adapts the power sharpening to spatial location - this threshold is the distance from which the adaptation begins*/
    int32_t power_spatial_control_th;
    /*!< power_spatial_control_multiply_factor adapts the power sharpening to spatial location - this it the factor for the power sharpening in the periphrial regions.*/
    int32_t power_spatial_control_multiply_factor;
    /*!< power_spatial_control_slope adapts the power sharpening to spatial location - this slope is how fast the adaptation with respect to the distance from the center. In order to bypass spatial control mechanism assign this variable to 0*/
    int32_t power_spatial_control_slope;
    /*!< sharpening_power_texture Power of unsharp-mask sharpening for texture regions*/
    int32_t sharpening_power_texture;
    /*!< sharpening_power_edges Power of unsharp-mask sharpening for edges regions*/
    int32_t sharpening_power_edges;
    /*!< skin_uv_center[2] center of the UV ellipse in UV space*/
    int32_t skin_uv_center[2];
    /*!< skin_uv_ellipse[3] minor and major axis UV ellipse. Symetric matrix therfore reducing values to 3 instead of 4*/
    int32_t skin_uv_ellipse[3];
    /*!< skin_uv_low_th low threshold for normalizing non-skin area map. Values below this threshold will be consider as skin.*/
    int32_t skin_uv_low_th;
    /*!< skin_uv_slope slope for normalizing non-skin map. This will be used to calculate the high threshold*/
    int32_t skin_uv_slope;
    /*!< skin_smoothing blending factor for smooting human skin using the bilateral*/
    int32_t skin_smoothing;
    /*!< inv_denoise_power 0 - strong denoiser, 63 - weak denoiser*/
    int32_t inv_denoise_power;
    /*!< sort_low_undershoots Sorting low undershoots*/
    int32_t sort_low_undershoots;
    /*!< alfa_os controls edged overshoot. 0 - no overshoot allowed, 63 - max overshoot allowed*/
    int32_t alfa_os;
    /*!< alfa_us controls edged undershoot. 0 - no undershoot allowed, 63 - max undershoot allowed*/
    int32_t alfa_us;
    /*!< os_us_delta_compression_threshold overshood/undershood delta which exceed threshold will be compressed. 0-no OS/US allowed. 511-no OS/US clipping.*/
    int32_t os_us_delta_compression_threshold;
    /*!< saturated_color_shrap_suppression_th the sharpening for max(u,v) above this threshold wll be suppressed*/
    int32_t saturated_color_shrap_suppression_th;
    /*!< saturated_color_shrap_suppression_factor the sharpening for max(u,v) above threshold wll be suppressed by this factor*/
    int32_t saturated_color_shrap_suppression_factor;
    /*!< os_us_delta_compression_factor overshoot / undershoot compression factor*/
    int32_t os_us_delta_compression_factor;
    /*!< conf_low_th the minimum number of samples consider reliable for APU estimation*/
    int32_t conf_low_th;
    /*!< conf_slope slope for normalizing confidence map. This will be used to calculate the high threshold*/
    int32_t conf_slope;

} ia_pal_isp_cas_1_0_t;

/*! \isp struct cas_lite_1_0

*/
typedef struct
{
    /*!< enable block enable*/
    int32_t enable;
    /*!< yuv420_format operate on YUV420*/
    int32_t yuv420_format;
    /*!< upscale150 toggle internal upscale by factor 1.5*/
    int32_t upscale150;
    /*!< nm_lut[16] noise model for luma. Save&restore register (will be ovveride in video mode)*/
    int32_t nm_lut[16];
    /*!< apu_alpha_limit update mechanism in apu - as limit increases, we need more measurements for the histogram bins to be considered as reliable.*/
    int32_t apu_alpha_limit;
    /*!< apu_alpha_power update mechanism in apu - as power increase, we count more on the new val calculated then the one from previous frame.*/
    int32_t apu_alpha_power;
    /*!< signal_metric_low_th low threshold for normalizing signal metric map*/
    int32_t signal_metric_low_th;
    /*!< signal_metric_slope slope for normalizing signal metric map*/
    int32_t signal_metric_slope;
    /*!< texture_noise_regulator detects less textures for higher values [0,0.2]*/
    int32_t texture_noise_regulator;
    /*!< texture_low_th low threshold for normalizing texture map. Values below this threshold will be consider as none texture.*/
    int32_t texture_low_th;
    /*!< texture_slope slope for normalizing texture map. This will be used to calculate the high threshold*/
    int32_t texture_slope;
    /*!< kernel1 Unsharp-mask filter center coefficient*/
    int32_t kernel1;
    /*!< kernel7[4] Unsharp-mask filter high-pass coefficients*/
    int32_t kernel7[4];
    /*!< sharpening_power_edges Power of unsharp-mask sharpening for edges regions*/
    int32_t sharpening_power_edges;
    /*!< alfa_os controls edged overshoot. 0 - no overshoot allowed, 63 - max overshoot allowed*/
    int32_t alfa_os;
    /*!< alfa_us controls edged undershoot. 0 - no undershoot allowed, 63 - max undershoot allowed*/
    int32_t alfa_us;
    /*!< os_us_delta_compression_threshold overshood/undershood delta which exceed threshold will be compressed. 0-no OS/US allowed. 511-no OS/US clipping.*/
    int32_t os_us_delta_compression_threshold;
    /*!< os_us_delta_compression_factor overshoot / undershoot compression factor*/
    int32_t os_us_delta_compression_factor;

} ia_pal_isp_cas_lite_1_0_t;

/*! \isp struct ccm_3a_2_0
AE color correction
*/
typedef struct
{
    /*!< gain_cx[8] WB coefficients*/
    int32_t gain_cx[8];
    /*!< m_1x[4] CCM matrix coefficients M11 - M14 (-4..4)*/
    int32_t m_1x[4];
    /*!< m_2x[4] CCM matrix coefficients M21 - M24 (-4..4)*/
    int32_t m_2x[4];
    /*!< m_3x[4] CCM matrix coefficients M21 - M24 (-4..4)*/
    int32_t m_3x[4];
    /*!< c_x[4] Y-calc matrix coefficients C01 - C04*/
    int32_t c_x[4];
    /*!< sensor_mode 0: 1x1 CFA (array sensor); 1: 2 x 2 CFA; 2: 4 x 4 CFA*/
    int32_t sensor_mode;
    /*!< pat_00 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_00;
    /*!< pat_01 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_01;
    /*!< pat_02 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_02;
    /*!< pat_03 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_03;
    /*!< pat_10 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_10;
    /*!< pat_11 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_11;
    /*!< pat_12 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_12;
    /*!< pat_13 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_13;
    /*!< pat_20 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_20;
    /*!< pat_21 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_21;
    /*!< pat_22 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_22;
    /*!< pat_23 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_23;
    /*!< pat_30 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_30;
    /*!< pat_31 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_31;
    /*!< pat_32 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_32;
    /*!< pat_33 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_33;

} ia_pal_isp_ccm_3a_2_0_t;

/*! \isp struct comp_spliter

*/
typedef struct
{
    /*!< m_bypass bypass*/
    int32_t m_bypass;

} ia_pal_isp_comp_spliter_t;

/*! \isp struct compand_1_0
Companding 24bit --> 15bit
*/
typedef struct
{
    /*!< enable enable the companding*/
    int32_t enable;
    /*!< compand_enable enable the companding CU*/
    int32_t compand_enable;
    /*!< cu_companding_x[13] U24 linear, default log-limited*/
    int32_t cu_companding_x[13];
    /*!< cu_companding_y[12] U15 companded output*/
    int32_t cu_companding_y[12];
    /*!< cu_companding_slope[12] U1.14 15bit slopes for companding*/
    int32_t cu_companding_slope[12];
    /*!< linear_pedestal U24, Pedestal added in linear domain*/
    int32_t linear_pedestal;

} ia_pal_isp_compand_1_0_t;

/*! \isp struct compression

*/
typedef struct
{
    /*!< enable When set, this frame is being compressed/decompressed.*/
    int32_t enable;
    /*!< cmp_enable[2] When set, this frame is being compressed/decompressed.*/
    int32_t cmp_enable[2];
    /*!< max_quanta_8b_y[20] MAX Quanta per QP, 8bits, Y plane*/
    int32_t max_quanta_8b_y[20];
    /*!< max_quanta_8b_uv[20] MAX Quanta per QP, 8bits, UV plane*/
    int32_t max_quanta_8b_uv[20];
    /*!< max_quanta_10b_y[24] MAX Quanta per QP, 10bits, Y plane*/
    int32_t max_quanta_10b_y[24];
    /*!< max_quanta_10b_uv[24] MAX Quanta per QP, 10bits, UV plane*/
    int32_t max_quanta_10b_uv[24];
    /*!< max_quanta_12b_y[28] MAX Quanta per QP, 12bits, Y plane*/
    int32_t max_quanta_12b_y[28];
    /*!< max_quanta_12b_uv[28] MAX Quanta per QP, 12bits, UV plane*/
    int32_t max_quanta_12b_uv[28];
    /*!< lossy_cfg[2] decides lossless or lossy*/
    int32_t lossy_cfg[2];
    /*!< fp_comp_enable[2] when lossy is enabled, this decides if compression is BW or FP*/
    int32_t fp_comp_enable[2];
    /*!< bitdepth[2] bitdepth of source*/
    int32_t bitdepth[2];
    /*!< fp_cmp_ratio[2] Specifies the hard constraint on the compressed size of each macro-page.*/
    int32_t fp_cmp_ratio[2];
    /*!< src_stride[2] Surface stride in bytes. Stride is the distance in bytes between the first pixel of the first tile to the first pixel is the tile which is below the first tile.*/
    int32_t src_stride[2];
    /*!< bw_cmp_ratio_plus[2] Upper bound on compression ratio + hysteresis.*/
    int32_t bw_cmp_ratio_plus[2];
    /*!< bw_cmp_ratio_minus[2] Lower threshold on compression ratio - hysteresis.*/
    int32_t bw_cmp_ratio_minus[2];
    /*!< bw_inst_upper[2] Upper threshold for the instant compression value to QP generation*/
    int32_t bw_inst_upper[2];
    /*!< bw_inst_lower[2] Lower threshold for the instant compression value to QP generation*/
    int32_t bw_inst_lower[2];
    /*!< init_history[2] Value with which the elements in the moving average window are initialized.*/
    int32_t init_history[2];
    /*!< init_qp[2] Specifies the value to which current QP is initialized at the beginning of each frame*/
    int32_t init_qp[2];
    /*!< min_qp[2] Specifies the maximum QP that the bitrate control algorithm is allowed to use*/
    int32_t min_qp[2];
    /*!< max_qp[2] Specifies the minimum QP that the bitrate control algorithm is allowed to use*/
    int32_t max_qp[2];
    /*!< ma_win_size[2] Window size (i.e. number of history element) for moving average*/
    int32_t ma_win_size[2];
    /*!< max_qp_inc[2] Counter that determines how quickly the upper limit of QP can be increased to keep footprint under control.*/
    int32_t max_qp_inc[2];
    /*!< max_qp_dec[2] Counter that determines how quickly the upper limit of QP can be decreased after footprint is under control.*/
    int32_t max_qp_dec[2];
    /*!< qp_inc_rst_val[2] When maximal QP is incremented or decremented, the counters are initiated with this values*/
    int32_t qp_inc_rst_val[2];
    /*!< fp_guard_band_log[2] Guard band for FP compression that reduces probability of needing evasive action towards the end of the macro-page*/
    int32_t fp_guard_band_log[2];

} ia_pal_isp_compression_t;

/*! \isp struct crop_sis

*/
typedef struct
{
    /*!< enable Enable pre SIS crop*/
    int32_t enable;
    /*!< crop_col_start crop_col_start*/
    int32_t crop_col_start;
    /*!< crop_row_start Start row of image data (rows before will be cropped)*/
    int32_t crop_row_start;
    /*!< crop_col_end End column of image data (excess will be cropped)*/
    int32_t crop_col_end;
    /*!< crop_row_end End line of image data (excess will be cropped)*/
    int32_t crop_row_end;

} ia_pal_isp_crop_sis_t;

/*! \isp struct cvt_1_0

*/
typedef struct
{
    /*!< enable enables the filter*/
    int32_t enable;
    /*!< enable_upsample enables upsampling (YUV422 --> YUV444)*/
    int32_t enable_upsample;
    /*!< enable_downsample enables downsampling (YUV444 --> YUV422)*/
    int32_t enable_downsample;
    /*!< enable_csc enables color space conversion (YUV  <--> RGB)*/
    int32_t enable_csc;
    /*!< enable_vertical_decimation enables vertical decimation*/
    int32_t enable_vertical_decimation;
    /*!< enable_horizontal_decimation enabled horizontal decimation*/
    int32_t enable_horizontal_decimation;
    /*!< enable_shuffle enables_shuffle*/
    int32_t enable_shuffle;
    /*!< csc_matrix[9] yuv to rgb to yuv conversion matrix, S4.11*/
    int32_t csc_matrix[9];
    /*!< shuffle_map_component_0 shuffle mapping of component 0*/
    int32_t shuffle_map_component_0;
    /*!< shuffle_map_component_1 shuffle mapping of component 1*/
    int32_t shuffle_map_component_1;
    /*!< shuffle_map_component_2 shuffle mapping of component 2*/
    int32_t shuffle_map_component_2;
    /*!< shuffle_map_component_3 shuffle mapping of component 3*/
    int32_t shuffle_map_component_3;
    /*!< shuffle_map_component_4 shuffle mapping of component 4*/
    int32_t shuffle_map_component_4;
    /*!< shuffle_map_component_5 shuffle mapping of component 5*/
    int32_t shuffle_map_component_5;
    /*!< decimation_type 0-Y, 1-RGB, 2-YUV420, 3-YUV422*/
    int32_t decimation_type;

} ia_pal_isp_cvt_1_0_t;

/*! \isp struct debug_info

*/
typedef struct
{
    /*!< output_data_id Output data ID. Debugging data to match P2P call sequence with correct PAL output data. AIC increments this value by 1 on every call to ia_isp_bxt_run().*/
    int32_t output_data_id;

} ia_pal_isp_debug_info_t;

/*! \isp struct decompand_1_0
Decompanding 15bit --> 24bit
*/
typedef struct
{
    /*!< enable enable the decompanding*/
    int32_t enable;
    /*!< decompand_enable enable the decompanding CU*/
    int32_t decompand_enable;
    /*!< cu_decompanding_x[13] U15 linear, companded*/
    int32_t cu_decompanding_x[13];
    /*!< cu_decompanding_y[12] U24 decompanded output, default log-limited*/
    int32_t cu_decompanding_y[12];
    /*!< cu_decompanding_slope[12] U20.6 26bit slopes for companding*/
    int32_t cu_decompanding_slope[12];
    /*!< linear_pedestal U24, Pedestal added in linear domain*/
    int32_t linear_pedestal;

} ia_pal_isp_decompand_1_0_t;

/*! \isp struct decompression

*/
typedef struct
{
    /*!< enable When set, this frame is being compressed/decompressed.*/
    int32_t enable;
    /*!< cmp_enable[2] When set, this frame is being compressed/decompressed.*/
    int32_t cmp_enable[2];
    /*!< lossy_cfg[2] decides lossless or lossy*/
    int32_t lossy_cfg[2];
    /*!< fp_comp_enable[2] when lossy is enabled, this decides if compression is BW or FP*/
    int32_t fp_comp_enable[2];
    /*!< bitdepth[2] bitdepth of source*/
    int32_t bitdepth[2];
    /*!< fp_cmp_ratio[2] Specifies the hard constraint on the compressed size of each macro-page.*/
    int32_t fp_cmp_ratio[2];
    /*!< src_stride[2] Surface stride in bytes. Stride is the distance in bytes between the first pixel of the first tile to the first pixel is the tile which is below the first tile.*/
    int32_t src_stride[2];

} ia_pal_isp_decompression_t;

/*! \isp struct dehaze_1_0

*/
typedef struct
{
    /*!< enable enabling the block. If enable is false, output is RGB obtained w/o 'dehazing'*/
    int32_t enable;
    /*!< dehaze_power the strength of the dehazing - obtained from previous frame*/
    int32_t dehaze_power;
    /*!< coeff_al overall airlight intrusion parameter*/
    int32_t coeff_al;
    /*!< airlight_color[3] airlight color - obtained from previouse frame*/
    int32_t airlight_color[3];
    /*!< trans_min minimal accepted tranmission used for transmition map calculation*/
    int32_t trans_min;
    /*!< trans_max maximal accepted tranmission used for transmition map calculation*/
    int32_t trans_max;
    /*!< quasi_satur_coeff quasi saturation coefficient*/
    int32_t quasi_satur_coeff;
    /*!< high_th threshold defining 'edges'*/
    int32_t high_th;
    /*!< low_th threshold defining 'flats'*/
    int32_t low_th;
    /*!< low_sim_alpha weight of the haze calculated on area used on 'edges'*/
    int32_t low_sim_alpha;
    /*!< med_sim_alpha weigh of the haze calculated on area used everwhere except edges and 'flats'*/
    int32_t med_sim_alpha;
    /*!< saturation_amp color saturation boost*/
    int32_t saturation_amp;
    /*!< update_power_weight mixing coefficient between the old and the new power (defines dynamic behaviour)*/
    int32_t update_power_weight;
    /*!< update_haze_color_weight mixing coefficient between the old and the new haze color (defines dynamic behaviour)*/
    int32_t update_haze_color_weight;
    /*!< min_tr_for_haze_color minimal transmision value for haze color calculation*/
    int32_t min_tr_for_haze_color;
    /*!< max_tr_for_haze_color maximal transmision value for haze color calculation*/
    int32_t max_tr_for_haze_color;
    /*!< cu_trans_x[7] power config unit x values*/
    int32_t cu_trans_x[7];
    /*!< cu_trans_y[6] power config unit y values*/
    int32_t cu_trans_y[6];
    /*!< cu_trans_slopes[6] power config unit slopes values*/
    int32_t cu_trans_slopes[6];
    /*!< cu_power_x[4] transmission config unit x values*/
    int32_t cu_power_x[4];
    /*!< cu_power_y[3] transmission config unit y values*/
    int32_t cu_power_y[3];
    /*!< cu_power_slopes[3] transmission config unit y values*/
    int32_t cu_power_slopes[3];
    /*!< max_h_for_update max H value to use for haze color and power updates*/
    int32_t max_h_for_update;
    /*!< CCM_yuv2rgb_matrix[9] S3.14, matrix for conversion from Yuv to RGB*/
    int32_t CCM_yuv2rgb_matrix[9];
    /*!< max_uv_haze_color maximal u and v values of haze color*/
    int32_t max_uv_haze_color;
    /*!< fragment_h_acc accumulator for haze coordinate value sum on the fragment*/
    int32_t fragment_h_acc;
    /*!< fragment_x1_acc accumulator for x1 coordinate value sum on the fragment*/
    int32_t fragment_x1_acc;
    /*!< fragment_x2_acc accumulator for x2 coordinate value sum on the fragment*/
    int32_t fragment_x2_acc;
    /*!< fragment_pixel_counter accumulator for pixel counter on the fragment*/
    int32_t fragment_pixel_counter;
    /*!< fragment_number number of the fragment [0..15]*/
    int32_t fragment_number;
    /*!< fragments_in_total fragments in total*/
    int32_t fragments_in_total;
    /*!< fragments_overlap fragments overlap*/
    int32_t fragments_overlap;
    /*!< pixels_in_total overall pixels in the frame (fragmentation support for 8K maximum)*/
    int32_t pixels_in_total;
    /*!< fragment_height fragment height*/
    int32_t fragment_height;
    /*!< fragment_width fragment width*/
    int32_t fragment_width;

} ia_pal_isp_dehaze_1_0_t;

/*! \isp struct dma_cropper_dp

*/
typedef struct
{
    /*!< Bypass bypass the DMA_Cropper*/
    int32_t Bypass;
    /*!< crop_left number of pixels to crop from left*/
    int32_t crop_left;
    /*!< crop_top number of pixels to crop from top*/
    int32_t crop_top;
    /*!< uncropped_output_width output width before any cropping is done*/
    int32_t uncropped_output_width;
    /*!< uncropped_output_height output height before any cropping is done*/
    int32_t uncropped_output_height;
    /*!< cropped_width input crop width*/
    int32_t cropped_width;
    /*!< cropped_height input crop height*/
    int32_t cropped_height;

} ia_pal_isp_dma_cropper_dp_t;

/*! \isp struct dma_cropper_mp

*/
typedef struct
{
    /*!< Bypass bypass the DMA_Cropper*/
    int32_t Bypass;
    /*!< crop_left number of pixels to crop from left*/
    int32_t crop_left;
    /*!< crop_top number of pixels to crop from top*/
    int32_t crop_top;
    /*!< uncropped_output_width output width before any cropping is done*/
    int32_t uncropped_output_width;
    /*!< uncropped_output_height output height before any cropping is done*/
    int32_t uncropped_output_height;
    /*!< cropped_width input crop width*/
    int32_t cropped_width;
    /*!< cropped_height input crop height*/
    int32_t cropped_height;

} ia_pal_isp_dma_cropper_mp_t;

/*! \isp struct dma_cropper_ppp

*/
typedef struct
{
    /*!< Bypass bypass the DMA_Cropper*/
    int32_t Bypass;
    /*!< crop_left number of pixels to crop from left*/
    int32_t crop_left;
    /*!< crop_top number of pixels to crop from top*/
    int32_t crop_top;
    /*!< uncropped_output_width output width before any cropping is done*/
    int32_t uncropped_output_width;
    /*!< uncropped_output_height output height before any cropping is done*/
    int32_t uncropped_output_height;
    /*!< cropped_width input crop width*/
    int32_t cropped_width;
    /*!< cropped_height input crop height*/
    int32_t cropped_height;

} ia_pal_isp_dma_cropper_ppp_t;

/*! \isp struct dol_1_0
Digital OverLap images 3 to 1 merge
*/
typedef struct
{
    /*!< enable enabling the block. If enable == false, Output = input_long*/
    int32_t enable;
    /*!< wb_multiplied_etr_short[4] U4.14, exposure ratio of short / short multiplied by WB gains, {Gr,R,B Gb}, 0…1*/
    int32_t wb_multiplied_etr_short[4];
    /*!< wb_multiplied_etr_med[4] U4.14, exposure ratio of med / short multiplied by WB gains, {Gr,R,B Gb}, 0…1*/
    int32_t wb_multiplied_etr_med[4];
    /*!< wb_multiplied_etr_long[4] U4.19, exposure ratio of long / short multiplied by WB gains, {Gr,R,B Gb}, 0…1*/
    int32_t wb_multiplied_etr_long[4];
    /*!< max_input_val U.0.20 - max value of input pixel*/
    int32_t max_input_val;
    /*!< is_medium_used indicates if medium image is valid*/
    int32_t is_medium_used;
    /*!< noise_model_beta_0_short[4] U.0.30, short exposure noise estimation, sigma^2 = beta_0 + beta_1*I + beta_2*I^2, derived from alpha_0 by PAL*/
    int32_t noise_model_beta_0_short[4];
    /*!< noise_model_beta_1_short[4] U.0.15, short exposure noise estimation, sigma^2 = beta_0 + beta_1*I + beta_2*I^2, derived from alpha_1 by PAL, {R,G,B}, 0…1*/
    int32_t noise_model_beta_1_short[4];
    /*!< noise_model_beta_2_short[4] U.0.15, short exposure noise estimation, sigma^2 = beta_0 + beta_1*I + beta_2*I^2, derived from alpha_2 by PAL, {R,G,B}, 0…1*/
    int32_t noise_model_beta_2_short[4];
    /*!< noise_model_beta_0_med[4] U.0.30, medium/LCG exposure noise estimation, sigma^2 = beta_0 + beta_1*I + beta_2*I^2, derived from alpha_0 by PAL*/
    int32_t noise_model_beta_0_med[4];
    /*!< noise_model_beta_1_med[4] U.0.15, medium/LCG exposure noise estimation, sigma^2 = beta_0 + beta_1*I + beta_2*I^2, derived from alpha_1 by PAL, {R,G,B}, 0…1*/
    int32_t noise_model_beta_1_med[4];
    /*!< noise_model_beta_2_med[4] U.0.15, medium/LCG exposure noise estimation, sigma^2 = beta_0 + beta_1*I + beta_2*I^2, derived from alpha_2 by PAL, {R,G,B}, 0…1*/
    int32_t noise_model_beta_2_med[4];
    /*!< noise_model_beta_0_long[4] U.0.30, long/HCG exposure noise estimation, sigma^2 = beta_0 + beta_1*I + beta_2*I^2, derived from alpha_0 by PAL*/
    int32_t noise_model_beta_0_long[4];
    /*!< noise_model_beta_1_long[4] U.0.15, long/HCG exposure noise estimation, sigma^2 = beta_0 + beta_1*I + beta_2*I^2, derived from alpha_1 by PAL, {R,G,B}, 0…1*/
    int32_t noise_model_beta_1_long[4];
    /*!< noise_model_beta_2_long[4] U.0.15, long/HCG exposure noise estimation, sigma^2 = beta_0 + beta_1*I + beta_2*I^2, derived from alpha_2 by PAL, {R,G,B}, 0…1*/
    int32_t noise_model_beta_2_long[4];
    /*!< motion_detector_gain U.2.7 motion detector gain, g_md*/
    int32_t motion_detector_gain;
    /*!< motion_detector_falarm_th U.3.5 motion detector false alarm threshold, FM_md*/
    int32_t motion_detector_falarm_th;
    /*!< cu_long_not_burnt_x[4] U 15.0 long exposure not-burnt soft threshold - x values*/
    int32_t cu_long_not_burnt_x[4];
    /*!< cu_long_not_burnt_y[3] U 1.7 long exposure not-burnt soft threshold  - y values*/
    int32_t cu_long_not_burnt_y[3];
    /*!< cu_long_not_burnt_slope[3] S 3.12 long exposure not-burnt soft threshold  - slope values*/
    int32_t cu_long_not_burnt_slope[3];
    /*!< cu_med_not_burnt_x[4] U 15.0 medium exposure not-burnt soft threshold  - x values*/
    int32_t cu_med_not_burnt_x[4];
    /*!< cu_med_not_burnt_y[3] U 1.7 medium exposure not-burnt soft threshold - y values*/
    int32_t cu_med_not_burnt_y[3];
    /*!< cu_med_not_burnt_slope[3] S 3.12 medium exposure not-burnt soft threshold - slope values*/
    int32_t cu_med_not_burnt_slope[3];
    /*!< cu_short_not_shadow_x[4] U 15.0 short exposure not-shadow soft threshold  - x values*/
    int32_t cu_short_not_shadow_x[4];
    /*!< cu_short_not_shadow_y[3] U 1.7 short exposure not-shadow soft threshold - y values*/
    int32_t cu_short_not_shadow_y[3];
    /*!< cu_short_not_shadow_slope[3] S 3.12 short exposure not-shadow soft threshold - slope values*/
    int32_t cu_short_not_shadow_slope[3];
    /*!< rad_blur_not_shadow_not_burnt_power U.1.7 the power of the blurred vs. blurred not shadow not burnt*/
    int32_t rad_blur_not_shadow_not_burnt_power;
    /*!< hdr_blending_weight_1 U.1.7 - HDR blending weight 1*/
    int32_t hdr_blending_weight_1;
    /*!< hdr_blending_weight_2 U.1.7 - HDR blending weight 2*/
    int32_t hdr_blending_weight_2;
    /*!< hdr_blending_weight_3 U.1.7 - HDR blending weight 3*/
    int32_t hdr_blending_weight_3;
    /*!< hdr_blending_weight_4 U.1.7 - HDR blending weight 4*/
    int32_t hdr_blending_weight_4;
    /*!< radiance_long_max_val_for_motion[4] U.0.20 - long max radiance value for motion detector, {Gr,R,B Gb}, 0…1*/
    int32_t radiance_long_max_val_for_motion[4];
    /*!< radiance_long_min_val_for_motion[4] S.0.21 - long min radiance value for motion detector, {Gr,R,B Gb}, 0…1*/
    int32_t radiance_long_min_val_for_motion[4];
    /*!< radiance_med_max_val_for_motion[4] U.0.20 - med max radiance value for motion detector, {Gr,R,B Gb}, 0…1*/
    int32_t radiance_med_max_val_for_motion[4];
    /*!< radiance_med_min_val_for_motion[4] S.0.21 - med min radiance value for motion detector, {Gr,R,B Gb}, 0…1*/
    int32_t radiance_med_min_val_for_motion[4];
    /*!< radiance_short_or_med_max_val_for_motion_vs_long[4] U.0.20 - short or med max radiance value vs long for motion detector, {Gr,R,B Gb}, 0…1*/
    int32_t radiance_short_or_med_max_val_for_motion_vs_long[4];
    /*!< radiance_short_or_med_min_val_for_motion_vs_long[4] S.0.21 - short or med min radiance value vs long for motion detector, {Gr,R,B Gb}, 0…1*/
    int32_t radiance_short_or_med_min_val_for_motion_vs_long[4];
    /*!< radiance_short_max_val_for_motion_vs_med[4] U.0.20 - short max radiance value vs medium for motion detector, {Gr,R,B Gb}, 0…1*/
    int32_t radiance_short_max_val_for_motion_vs_med[4];
    /*!< radiance_short_min_val_for_motion[4] S.0.21 - short min radiacne value for motion detector, {Gr,R,B Gb}, 0…1*/
    int32_t radiance_short_min_val_for_motion[4];
    /*!< cu_compression_x[8] U.20 cu_compression_x*/
    int32_t cu_compression_x[8];
    /*!< cu_compression_y[7] U.15 cu_compression_y*/
    int32_t cu_compression_y[7];
    /*!< cu_compression_slope[7] S.2.10 cu_compression_slope (12 bit include sign)*/
    int32_t cu_compression_slope[7];
    /*!< motion_dilation_enable enabling dilation on motion-detection map.*/
    int32_t motion_dilation_enable;
    /*!< noise_model_var_min_val_long[4] U.0.30 - min value of noise model variance for long/HCG exposure, {Gr,R,B Gb}*/
    int32_t noise_model_var_min_val_long[4];
    /*!< noise_model_var_min_val_med[4] U.0.30- min value of noise model variance for medium exposure, {Gr,R,B Gb}*/
    int32_t noise_model_var_min_val_med[4];
    /*!< noise_model_var_min_val_short[4] U.0.30 - min value of noise model variance for short exposure, {Gr,R,B Gb}*/
    int32_t noise_model_var_min_val_short[4];
    /*!< noise_norm_shift_long U.4.0 long exposure variance normalization*/
    int32_t noise_norm_shift_long;
    /*!< noise_norm_shift_med U.4.0 medium exposure variance normalization*/
    int32_t noise_norm_shift_med;
    /*!< noise_norm_shift_short U.4.0 short exposure variance normalization*/
    int32_t noise_norm_shift_short;
    /*!< dp_enable U1.0 bypass defective pixel sensitive motion detection*/
    int32_t dp_enable;
    /*!< dpreduce_prec_long U4.0 long exposure DP sensitive motion detection parameter precision*/
    int32_t dpreduce_prec_long;
    /*!< dpreduce_prec_med U4.0 medium exposure DP sensitive motion detection parameter precision*/
    int32_t dpreduce_prec_med;
    /*!< dpreduce_slope_long[4] U0.16 long exposure slope value for DP sensitive motion detection*/
    int32_t dpreduce_slope_long[4];
    /*!< dpreduce_slope_med[4] U0.16 medium exposure slope value for DP sensitive motion detection*/
    int32_t dpreduce_slope_med[4];
    /*!< dpreduce_thre_long[4] U0.16 long exposure threshold for DP sensitive motion detection*/
    int32_t dpreduce_thre_long[4];
    /*!< dpreduce_thre_med[4] U0.16 medium exposure threshold for DP sensitive motion detection*/
    int32_t dpreduce_thre_med[4];
    /*!< blf_scale_med U0.8 bilateral filter noise model scaling factor for medium exposure*/
    int32_t blf_scale_med;
    /*!< blf_scale_short U0.8 bilateral filter noise model scaling factor for short exposure*/
    int32_t blf_scale_short;
    /*!< chroma_coring_med U0.8 moving object chroma coring in medium exposure*/
    int32_t chroma_coring_med;
    /*!< chroma_coring_short U0.8 moving object chroma coring in short exposure*/
    int32_t chroma_coring_short;
    /*!< lfm_enable enabling LFM function*/
    int32_t lfm_enable;
    /*!< lfm_rshift1 U5.0*/
    int32_t lfm_rshift1;
    /*!< lfm_rshift2 U5.0*/
    int32_t lfm_rshift2;
    /*!< lfm_rshift3 S16.0*/
    int32_t lfm_rshift3;
    /*!< lfm_clipval1 U5.0*/
    int32_t lfm_clipval1;
    /*!< lfm_clipval2 U5.0*/
    int32_t lfm_clipval2;
    /*!< lfm_clipval3 U5.0*/
    int32_t lfm_clipval3;
    /*!< lfm_maxval_long U20.0*/
    int32_t lfm_maxval_long;
    /*!< lfm_maxval_med U20.0*/
    int32_t lfm_maxval_med;
    /*!< lfm_smf_th U5.0*/
    int32_t lfm_smf_th;
    /*!< lfm_flicker_thre U5.0*/
    int32_t lfm_flicker_thre;
    /*!< lfm_flicker_gain U3.6*/
    int32_t lfm_flicker_gain;
    /*!< lfm_a2 U5.6*/
    int32_t lfm_a2;
    /*!< lfm_b2 U10.0*/
    int32_t lfm_b2;
    /*!< lfm_a3 U5.6*/
    int32_t lfm_a3;
    /*!< lfm_b3 U10.0*/
    int32_t lfm_b3;
    /*!< lfm_blend_shift_long U4.0*/
    int32_t lfm_blend_shift_long;
    /*!< lfm_blend_shift_long_med U4.0*/
    int32_t lfm_blend_shift_long_med;
    /*!< lfm_blend_shift_long_med_short U4.0*/
    int32_t lfm_blend_shift_long_med_short;

} ia_pal_isp_dol_1_0_t;

/*! \isp struct dol_2_0
Exposure image merger
*/
typedef struct
{
    /*!< bypass Bypass mode; 0: HDR image, 1: long exposure image*/
    int32_t bypass;
    /*!< cfaBayer[4] Bayer CFA descriptor; 0: R, 1: Gr; 2: Gb, 3: B*/
    int32_t cfaBayer[4];
    /*!< decompandX0[5] Decompanding input 0*/
    int32_t decompandX0[5];
    /*!< decompandY0[4] Decompanding output 0*/
    int32_t decompandY0[4];
    /*!< decompandS0[4] Decompanding slope 0*/
    int32_t decompandS0[4];
    /*!< decompandX1[5] Decompanding input 1*/
    int32_t decompandX1[5];
    /*!< decompandY1[4] Decompanding output 1*/
    int32_t decompandY1[4];
    /*!< decompandS1[4] Decompanding slope 1*/
    int32_t decompandS1[4];
    /*!< decompandX2[5] Decompanding input 2*/
    int32_t decompandX2[5];
    /*!< decompandY2[4] Decompanding output 2*/
    int32_t decompandY2[4];
    /*!< decompandS2[4] Decompanding slope 2*/
    int32_t decompandS2[4];
    /*!< decompandX3[5] Decompanding input 3*/
    int32_t decompandX3[5];
    /*!< decompandY3[4] Decompanding output 3*/
    int32_t decompandY3[4];
    /*!< decompandS3[4] Decompanding slope 3*/
    int32_t decompandS3[4];
    /*!< dolStats[16] DOL statistic extraction descriptor*/
    int32_t dolStats[16];
    /*!< dolStatsMode DOL statistic extraction mode, 0: single, 1: pair, 2:  quad*/
    int32_t dolStatsMode;
    /*!< wbGains[16] White balancing gains {R G G B}; 1 refers to 4096*/
    int32_t wbGains[16];
    /*!< combGains[16] Additional gains {LEr, LEg, LEg, LEb, MEr,…, VEb}; 1 refers to 4096*/
    int32_t combGains[16];
    /*!< blackLevel[16] Black level {LEr, LEg, LEg, LEb, MEr,…, VEb};*/
    int32_t blackLevel[16];
    /*!< residualBlackLevel[16] Residual black level {LEr, LEg, LEg, LEb, MEr,…, VEb}; 1 refers to 4096*/
    int32_t residualBlackLevel[16];
    /*!< residualBlackLevel2[4] Residual black level {LE, ME, SE, VE} for luma; 1 refers to 4096*/
    int32_t residualBlackLevel2[4];
    /*!< numExp Number of exposure images*/
    int32_t numExp;
    /*!< expRatio[4] Exposure ratios {LE, ME, SE, VE}*/
    int32_t expRatio[4];
    /*!< satvalMax[4] Saturation value {LE, ME, SE, VE}*/
    int32_t satvalMax[4];
    /*!< satThr[4] Saturation range as bit shift {LE, ME, SE, VE}*/
    int32_t satThr[4];
    /*!< satvalMin[4] Minimum saturation value {LE, ME, SE, VE}*/
    int32_t satvalMin[4];
    /*!< desatModel[3] Desaturation model; details TBA*/
    int32_t desatModel[3];
    /*!< motionIndex Baseline exposure image for motion detection*/
    int32_t motionIndex;
    /*!< motionModel[6] Motion model {LM, LM, LM, MS, MS, MS}; details TBA*/
    int32_t motionModel[6];
    /*!< motionLo[4] Low signal range {L, L, M, M}; details TBA*/
    int32_t motionLo[4];
    /*!< motionHi[4] High signal range; details TBA*/
    int32_t motionHi[4];
    /*!< motionLimit[2] Motion map limits {Lo, Hi}*/
    int32_t motionLimit[2];
    /*!< flickerModel[6] Flicker model {LE, LE, LE, ME, ME, ME, SE, SE, SE}*/
    int32_t flickerModel[6];
    /*!< flickerMaxval[4] Flicker signal upper threshold {LE, ME, SE, VE}*/
    int32_t flickerMaxval[4];
    /*!< flickerLimit[2] Flicker map limits {Lo, Hi}*/
    int32_t flickerLimit[2];
    /*!< blendingLimit[2] Blending map limits {Lo, Hi}*/
    int32_t blendingLimit[2];
    /*!< pedestal Linear output image pedestal*/
    int32_t pedestal;
    /*!< compandX[12] Input*/
    int32_t compandX[12];
    /*!< compandY[11] Output*/
    int32_t compandY[11];
    /*!< compandS[11] Slope*/
    int32_t compandS[11];

} ia_pal_isp_dol_2_0_t;

/*! \isp struct dol_lite_1_0

*/
typedef struct
{
    /*!< log_downscale_ratio log2 of downscale ratio*/
    int32_t log_downscale_ratio;
    /*!< smthnrm_slope[4] estimated short-smoothed normalization coefficient*/
    int32_t smthnrm_slope[4];
    /*!< smthnrm_slope_user[4] estimated short-smoothed normalization coefficient - user override*/
    int32_t smthnrm_slope_user[4];
    /*!< etr_slope[4] estimated ETR coefficient*/
    int32_t etr_slope[4];
    /*!< etr_slope_user[4] estimated ETR coefficient - user override*/
    int32_t etr_slope_user[4];
    /*!< smthnrm_bias[4] estimated short-smoothed normalization bias*/
    int32_t smthnrm_bias[4];
    /*!< smthnrm_bias_user[4] estimated short-smoothed normalization bias - user override*/
    int32_t smthnrm_bias_user[4];
    /*!< etr_bias[4] estimated ETR bias*/
    int32_t etr_bias[4];
    /*!< etr_bias_user[4] estimated ETR bias - user override*/
    int32_t etr_bias_user[4];
    /*!< deghost_bias deghost indicator constant*/
    int32_t deghost_bias;
    /*!< deghost_coeff deghost indicator coefficient*/
    int32_t deghost_coeff;
    /*!< update_limit Limit of S&R parameter update mechanism*/
    int32_t update_limit;
    /*!< update_coeff S&R parameter update coefficient*/
    int32_t update_coeff;
    /*!< d_ml[32] Maximum-likelihood of distance distribution*/
    int32_t d_ml[32];
    /*!< outofbounds[32] is ML value out of histogram bounds?*/
    int32_t outofbounds[32];
    /*!< is_first_frame If first frame, ignore input rec-sim*/
    int32_t is_first_frame;
    /*!< is_steady_state if change in S&R values is small, apply strong temporal smoothing*/
    int32_t is_steady_state;
    /*!< long_saturation_bias saturation indicator constant*/
    int32_t long_saturation_bias;
    /*!< long_saturation_full saturation indicator full value*/
    int32_t long_saturation_full;
    /*!< long_saturation_coeff saturation indicator coefficient*/
    int32_t long_saturation_coeff;
    /*!< long_saturation_transition relative width of transition between fully saturated and unsaturated*/
    int32_t long_saturation_transition;
    /*!< long_saturation_tracking enable tracking of long-exposure saturation based on noise model*/
    int32_t long_saturation_tracking;
    /*!< etr_estim_enable enable online ETR estimation*/
    int32_t etr_estim_enable;
    /*!< wb_gains[4] white-balance gains for curr frame*/
    int32_t wb_gains[4];
    /*!< wb_gains_prev[4] white-balance gains from prev frame*/
    int32_t wb_gains_prev[4];
    /*!< pedestal_out output pedestal level*/
    int32_t pedestal_out;
    /*!< bpp_sensor sensor BPP*/
    int32_t bpp_sensor;
    /*!< bayer_order bayer-pattern (for shrt-smooth remosaic)*/
    int32_t bayer_order;
    /*!< yuv2rgb[9] YUV to RGB conversion*/
    int32_t yuv2rgb[9];
    /*!< shrt_smth_bpp shrt-smth bpp*/
    int32_t shrt_smth_bpp;
    /*!< shrt_smth_padding_top shrt-smth padding on top*/
    int32_t shrt_smth_padding_top;
    /*!< shrt_smth_padding_lft shrt-smth padding on left*/
    int32_t shrt_smth_padding_lft;
    /*!< black_level[4] black level*/
    int32_t black_level[4];
    /*!< short_is_invalid If on, the blend is 100% long exposure (back door)*/
    int32_t short_is_invalid;
    /*!< max_use_long Max use of long exposure in the output blend*/
    int32_t max_use_long;
    /*!< min_use_long Min use of long exposure in the output blend [GPU only]*/
    int32_t min_use_long;
    /*!< short_denoise_power use of denoised short-exposure in blend*/
    int32_t short_denoise_power;
    /*!< use_shrt_smth_for_dist use short-smoothed for calculating distance*/
    int32_t use_shrt_smth_for_dist;
    /*!< enable block enable*/
    int32_t enable;

} ia_pal_isp_dol_lite_1_0_t;

/*! \isp struct dol_lite_1_1

*/
typedef struct
{
    /*!< smthnrm_slope[4] estimated short-smoothed normalization coefficient*/
    int32_t smthnrm_slope[4];
    /*!< etr_slope[4] estimated ETR coefficient*/
    int32_t etr_slope[4];
    /*!< smthnrm_bias[4] estimated short-smoothed normalization bias*/
    int32_t smthnrm_bias[4];
    /*!< etr_bias[4] estimated ETR bias*/
    int32_t etr_bias[4];
    /*!< deghost_bias deghost indicator constant*/
    int32_t deghost_bias;
    /*!< deghost_coeff deghost indicator coefficient*/
    int32_t deghost_coeff;
    /*!< max_use_long Max use of long exposure in the output blend*/
    int32_t max_use_long;
    /*!< update_limit Limit of S&R parameter update mechanism*/
    int32_t update_limit;
    /*!< update_coeff S&R parameter update coefficient*/
    int32_t update_coeff;
    /*!< d_ml[32] Maximum-likelihood of distance distribution*/
    int32_t d_ml[32];
    /*!< outofbounds[32] is ML value out of histogram bounds?*/
    int32_t outofbounds[32];
    /*!< is_first_stripe If first stripe in frame*/
    int32_t is_first_stripe;
    /*!< is_last_stripe Iflast stripe in frame*/
    int32_t is_last_stripe;
    /*!< is_first_frame If first frame*/
    int32_t is_first_frame;
    /*!< is_steady_state if change in S&R values is small, apply strong temporal smoothing*/
    int32_t is_steady_state;
    /*!< long_saturation_bias saturation indicator constant*/
    int32_t long_saturation_bias;
    /*!< long_saturation_full saturation indicator full value*/
    int32_t long_saturation_full;
    /*!< long_saturation_coeff saturation indicator coefficient*/
    int32_t long_saturation_coeff;
    /*!< long_saturation_transition relative width of transition between fully saturated and unsaturated*/
    int32_t long_saturation_transition;
    /*!< long_saturation_tracking enable tracking of long-exposure saturation based on noise model*/
    int32_t long_saturation_tracking;
    /*!< etr_estim_enable enable online ETR estimation*/
    int32_t etr_estim_enable;
    /*!< wb_gains[4] white-balance gains for curr frame*/
    int32_t wb_gains[4];
    /*!< wb_gains_prev[4] white-balance gains from prev frame*/
    int32_t wb_gains_prev[4];
    /*!< pedestal_out output pedestal level*/
    int32_t pedestal_out;
    /*!< bpp_sensor sensor BPP*/
    int32_t bpp_sensor;
    /*!< shrt_smth_padding_top shrt-smth padding on top*/
    int32_t shrt_smth_padding_top;
    /*!< shrt_smth_padding_lft shrt-smth padding on left*/
    int32_t shrt_smth_padding_lft;
    /*!< black_level[4] black level*/
    int32_t black_level[4];
    /*!< short_denoise_power use of denoised short-exposure in blend*/
    int32_t short_denoise_power;
    /*!< short_denoise_sensitivity denoise bilateral sensitivity*/
    int32_t short_denoise_sensitivity;
    /*!< three_input_mode enable third input (pre-processed short)*/
    int32_t three_input_mode;
    /*!< psve_gains_short[4] PSVE output - gains for short exposure*/
    int32_t psve_gains_short[4];
    /*!< psve_bias_short[4] PSVE output - black level for short exposure*/
    int32_t psve_bias_short[4];
    /*!< psve_gains_long[4] PSVE output - gains for long exposure*/
    int32_t psve_gains_long[4];
    /*!< psve_bias_long[4] PSVE output - black level for long exposure*/
    int32_t psve_bias_long[4];
    /*!< psve_long_max_val PSVE output - max-val for long exposure*/
    int32_t psve_long_max_val;
    /*!< enable block enable*/
    int32_t enable;

} ia_pal_isp_dol_lite_1_1_t;

/*! \isp struct dol_mapper
DOL color ID mapper
*/
typedef struct
{
    /*!< bypass Bypass mode; 0: HDR image, 1: long exposure image*/
    int32_t bypass;
    /*!< exposures Number of exposure images*/
    int32_t exposures;
    /*!< mapping[16] Pixel extraction descriptor*/
    int32_t mapping[16];
    /*!< mode Extraction mode: single (0), pair (1), quad (2)*/
    int32_t mode;

} ia_pal_isp_dol_mapper_t;

/*! \isp struct dol_parser

*/
typedef struct
{
    /*!< vbp Vertical Blanking Period Before SE starts*/
    int32_t vbp;
    /*!< crop_x Pixels to be cropped along the width of the fragment*/
    int32_t crop_x;
    /*!< crop_y Pixels to be cropped along the height of the fragment*/
    int32_t crop_y;
    /*!< cropped_width Width of the fragment*/
    int32_t cropped_width;
    /*!< cropped_height Height of the fragment*/
    int32_t cropped_height;

} ia_pal_isp_dol_parser_t;

/*! \isp struct dpc_1_1

*/
typedef struct
{
    /*!< afxoffset[32] 8 Autofocus pixels X axis offset U14.0, should be smaller than afxperiod*/
    int32_t afxoffset[32];
    /*!< afxperiod[32] 8 Autofocus pixels X axis period*/
    int32_t afxperiod[32];
    /*!< afyoffset[32] 8 Autofocus pixels Y axis offset U14.0, should be smaller than afyperiod*/
    int32_t afyoffset[32];
    /*!< afyperiod[32] 8 Autofocus pixels Y axis period*/
    int32_t afyperiod[32];
    /*!< hdrfactors[16] 4x4 HDR exposure factor U6.8*/
    int32_t hdrfactors[16];
    /*!< hdrfactorsinverse[16] 4x4 HDR exposure inverse factor U6.8 - should be inverse of hdrfactors*/
    int32_t hdrfactorsinverse[16];
    /*!< configunitcolddistvsmedian_slope[7] cold dist vs median config unit classifier*/
    int32_t configunitcolddistvsmedian_slope[7];
    /*!< configunitcolddistvsmedian_x[8] cold dist vs median config unit classifier*/
    int32_t configunitcolddistvsmedian_x[8];
    /*!< configunitcolddistvsmedian_y[7] cold dist vs median config unit classifier*/
    int32_t configunitcolddistvsmedian_y[7];
    /*!< configunitcolddistvsneighb_slope[7] cold dist vs neigb config unit classifier*/
    int32_t configunitcolddistvsneighb_slope[7];
    /*!< configunitcolddistvsneighb_x[8] cold dist vs neigb config unit classifier*/
    int32_t configunitcolddistvsneighb_x[8];
    /*!< configunitcolddistvsneighb_y[7] cold dist vs neigb config unit classifier*/
    int32_t configunitcolddistvsneighb_y[7];
    /*!< configunitfix_slope[3] fix config unit*/
    int32_t configunitfix_slope[3];
    /*!< configunitfix_x[4] fix config unit*/
    int32_t configunitfix_x[4];
    /*!< configunitfix_y[3] fix config unit*/
    int32_t configunitfix_y[3];
    /*!< configunithotdistvsmedian_slope[7] hot dist vs median classifier*/
    int32_t configunithotdistvsmedian_slope[7];
    /*!< configunithotdistvsmedian_x[8] hot dist vs median classifier*/
    int32_t configunithotdistvsmedian_x[8];
    /*!< configunithotdistvsmedian_y[7] hot dist vs median classifier*/
    int32_t configunithotdistvsmedian_y[7];
    /*!< configunithotdistvsneighb_slope[7] hot dist vs neigb config unit classifier*/
    int32_t configunithotdistvsneighb_slope[7];
    /*!< configunithotdistvsneighb_x[8] hot dist vs neigb config unit classifier*/
    int32_t configunithotdistvsneighb_x[8];
    /*!< configunithotdistvsneighb_y[7] hot dist vs neigb config unit classifier*/
    int32_t configunithotdistvsneighb_y[7];
    /*!< configunitrawvslb_slope[7] configunitrawvslb_slope*/
    int32_t configunitrawvslb_slope[7];
    /*!< configunitrawvslb_x[8] configunitrawvslb_x*/
    int32_t configunitrawvslb_x[8];
    /*!< configunitrawvslb_y[7] configunitrawvslb_y*/
    int32_t configunitrawvslb_y[7];
    /*!< configunitrawvsub_slope[7] configunitrawvsub_slope*/
    int32_t configunitrawvsub_slope[7];
    /*!< configunitrawvsub_x[8] configunitrawvsub_x*/
    int32_t configunitrawvsub_x[8];
    /*!< configunitrawvsub_y[7] configunitrawvsub_y*/
    int32_t configunitrawvsub_y[7];
    /*!< curx[1024] x locations of the static bad pixels*/
    int32_t curx[1024];
    /*!< cury[1024] y locations of the static bad pixels*/
    int32_t cury[1024];
    /*!< lbtype[16] 0 - B1,   1 - B2,  2 - B3*/
    int32_t lbtype[16];
    /*!< ubtype[16] 0 - B1,   1 - B2,  2 - B3*/
    int32_t ubtype[16];
    /*!< pelesttype[16] 0-P1, 1-P2, 2-P3, 3-P4, 4-P5, 5-P6*/
    int32_t pelesttype[16];
    /*!< dtype[16] 0-D1 1-D2  2-D3*/
    int32_t dtype[16];
    /*!< lbmasks[64] configurations related to the bayer pattern*/
    int32_t lbmasks[64];
    /*!< ubmasks[64] configurations related to the bayer pattern*/
    int32_t ubmasks[64];
    /*!< pmasks[384] configurations related to the bayer pattern*/
    int32_t pmasks[384];
    /*!< dmasks[48] configurations related to the bayer pattern*/
    int32_t dmasks[48];
    /*!< bitreduceshift Shift value for bit reduce block*/
    int32_t bitreduceshift;
    /*!< afenable enable for the AF unit block*/
    int32_t afenable;
    /*!< staticenable enable for the static LUT block*/
    int32_t staticenable;
    /*!< dynamicenable enable for the dynamic detection block*/
    int32_t dynamicenable;
    /*!< n_static_lut_entries number of static lut entries*/
    int32_t n_static_lut_entries;
    /*!< frame_width frame width*/
    int32_t frame_width;
    /*!< frame_height frame height*/
    int32_t frame_height;
    /*!< paf_grid_en[32] paf grid enables*/
    int32_t paf_grid_en[32];
    /*!< paf_output_mode 0)disables, do not pass anything 1) first line sent to memset0 second line sent to memset1  2)first line sent to memset0 second to memset 1 and afterward alternate every two lines 3) passthrough –send to memset0 everything*/
    int32_t paf_output_mode;
    /*!< swapping1stbc Apply swapping of BC inputs for 1st/3rd/etc.  0: no swapping  1: swap B/C inputs*/
    int32_t swapping1stbc;
    /*!< swapping1stcd Apply swapping of CD inputs for 1st/3rd/etc.  0: no swapping 1: swap C/D inputs*/
    int32_t swapping1stcd;
    /*!< swapping2ndbc Apply swapping of BC inputs for 2nd/4th/etc. lines  0: no swapping  1: swap A/B inputs*/
    int32_t swapping2ndbc;
    /*!< swapping2ndcd Apply swapping of CD inputs for 2nd/4th/etc. lines  0: no swapping 1: swap C/D inputs*/
    int32_t swapping2ndcd;
    /*!< pdaf_width Width in units of PDAF pixels. After Width pixels – Pext knows there is a new line coming in. In Modes1..3 – max line length is as in the internal buffer size which is 1024 pixels.*/
    int32_t pdaf_width;
    /*!< pdaf_height Height in units of pdaf lines*/
    int32_t pdaf_height;
    /*!< drop_pattern[32] Drop pattern for AF pixels. 1=drop the lines 0=use the line*/
    int32_t drop_pattern[32];
    /*!< drop_period Period of the drop pattern*/
    int32_t drop_period;

} ia_pal_isp_dpc_1_1_t;

/*! \isp struct dpc_1_3

*/
typedef struct
{
    /*!< afxoffset[32] 8 Autofocus pixels X axis offset U14.0, should be smaller than afxperiod*/
    int32_t afxoffset[32];
    /*!< afxperiod[32] 8 Autofocus pixels X axis period*/
    int32_t afxperiod[32];
    /*!< afyoffset[32] 8 Autofocus pixels Y axis offset U14.0, should be smaller than afyperiod*/
    int32_t afyoffset[32];
    /*!< afyperiod[32] 8 Autofocus pixels Y axis period*/
    int32_t afyperiod[32];
    /*!< hdrfactors[16] 4x4 HDR exposure factor U6.8*/
    int32_t hdrfactors[16];
    /*!< hdrfactorsinverse[16] 4x4 HDR exposure inverse factor U6.8 - should be inverse of hdrfactors*/
    int32_t hdrfactorsinverse[16];
    /*!< configunitcolddistvsmedian_slope[7] cold dist vs median config unit classifier*/
    int32_t configunitcolddistvsmedian_slope[7];
    /*!< configunitcolddistvsmedian_x[8] cold dist vs median config unit classifier*/
    int32_t configunitcolddistvsmedian_x[8];
    /*!< configunitcolddistvsmedian_y[7] cold dist vs median config unit classifier*/
    int32_t configunitcolddistvsmedian_y[7];
    /*!< configunitcolddistvsneighb_slope[7] cold dist vs neigb config unit classifier*/
    int32_t configunitcolddistvsneighb_slope[7];
    /*!< configunitcolddistvsneighb_x[8] cold dist vs neigb config unit classifier*/
    int32_t configunitcolddistvsneighb_x[8];
    /*!< configunitcolddistvsneighb_y[7] cold dist vs neigb config unit classifier*/
    int32_t configunitcolddistvsneighb_y[7];
    /*!< configunitfix_slope[3] fix config unit*/
    int32_t configunitfix_slope[3];
    /*!< configunitfix_x[4] fix config unit*/
    int32_t configunitfix_x[4];
    /*!< configunitfix_y[3] fix config unit*/
    int32_t configunitfix_y[3];
    /*!< configunithotdistvsmedian_slope[7] hot dist vs median classifier*/
    int32_t configunithotdistvsmedian_slope[7];
    /*!< configunithotdistvsmedian_x[8] hot dist vs median classifier*/
    int32_t configunithotdistvsmedian_x[8];
    /*!< configunithotdistvsmedian_y[7] hot dist vs median classifier*/
    int32_t configunithotdistvsmedian_y[7];
    /*!< configunithotdistvsneighb_slope[7] hot dist vs neigb config unit classifier*/
    int32_t configunithotdistvsneighb_slope[7];
    /*!< configunithotdistvsneighb_x[8] hot dist vs neigb config unit classifier*/
    int32_t configunithotdistvsneighb_x[8];
    /*!< configunithotdistvsneighb_y[7] hot dist vs neigb config unit classifier*/
    int32_t configunithotdistvsneighb_y[7];
    /*!< configunitrawvslb_slope[7] configunitrawvslb_slope*/
    int32_t configunitrawvslb_slope[7];
    /*!< configunitrawvslb_x[8] configunitrawvslb_x*/
    int32_t configunitrawvslb_x[8];
    /*!< configunitrawvslb_y[7] configunitrawvslb_y*/
    int32_t configunitrawvslb_y[7];
    /*!< configunitrawvsub_slope[7] configunitrawvsub_slope*/
    int32_t configunitrawvsub_slope[7];
    /*!< configunitrawvsub_x[8] configunitrawvsub_x*/
    int32_t configunitrawvsub_x[8];
    /*!< configunitrawvsub_y[7] configunitrawvsub_y*/
    int32_t configunitrawvsub_y[7];
    /*!< curx[1024] x locations of the static bad pixels*/
    int32_t curx[1024];
    /*!< cury[1024] y locations of the static bad pixels*/
    int32_t cury[1024];
    /*!< lbtype[16] 0 - B1,   1 - B2,  2 - B3*/
    int32_t lbtype[16];
    /*!< ubtype[16] 0 - B1,   1 - B2,  2 - B3*/
    int32_t ubtype[16];
    /*!< pelesttype[16] 0-P1, 1-P2, 2-P3, 3-P4, 4-P5, 5-P6*/
    int32_t pelesttype[16];
    /*!< dtype[16] 0-D1 1-D2  2-D3*/
    int32_t dtype[16];
    /*!< lbmasks[64] configurations related to the bayer pattern*/
    int32_t lbmasks[64];
    /*!< ubmasks[64] configurations related to the bayer pattern*/
    int32_t ubmasks[64];
    /*!< pmasks[384] configurations related to the bayer pattern*/
    int32_t pmasks[384];
    /*!< dmasks[48] configurations related to the bayer pattern*/
    int32_t dmasks[48];
    /*!< bitreduceshift Shift value for bit reduce block*/
    int32_t bitreduceshift;
    /*!< afenable enable for the AF unit block*/
    int32_t afenable;
    /*!< staticenable enable for the static LUT block*/
    int32_t staticenable;
    /*!< dynamicenable enable for the dynamic detection block*/
    int32_t dynamicenable;
    /*!< n_static_lut_entries number of static lut entries*/
    int32_t n_static_lut_entries;
    /*!< frame_width frame width*/
    int32_t frame_width;
    /*!< paf_grid_en[32] paf grid enables*/
    int32_t paf_grid_en[32];
    /*!< paf_output_mode 0)disables, do not pass anything\n 1) first line sent to memset0 second\n line sent to memset1\n 2)first line sent to memset0 second to memset 1 and afterward alternate every two lines 3) passthrough –send to memset0 everything*/
    int32_t paf_output_mode;
    /*!< swapping1stbc Apply swapping of BC inputs for 1st/3rd/etc.\n0: no swapping\n1: swap B/C inputs*/
    int32_t swapping1stbc;
    /*!< swapping1stcd Apply swapping of CD inputs for 1st/3rd/etc.\n0: no swapping\n1: swap C/D inputs*/
    int32_t swapping1stcd;
    /*!< swapping2ndbc Apply swapping of BC inputs for 2nd/4th/etc. lines\n0: no swapping\n1: swap A/B inputs*/
    int32_t swapping2ndbc;
    /*!< swapping2ndcd Apply swapping of CD inputs for 2nd/4th/etc. lines\n0: no swapping\n1: swap C/D inputs*/
    int32_t swapping2ndcd;
    /*!< pdaf_width Width in units of PDAF pixels. After Width pixels – Pext knows there is a new line coming in. In Modes1..3 – max line length is as in the internal buffer size which is 1024 pixels.*/
    int32_t pdaf_width;
    /*!< pdaf_height Height in units of pdaf lines*/
    int32_t pdaf_height;
    /*!< drop_pattern[32] Drop pattern for AF pixels. 1=drop the lines\n0=use the line*/
    int32_t drop_pattern[32];
    /*!< drop_period Period of the drop pattern*/
    int32_t drop_period;
    /*!< paf_pattern_rearrangement_en Enable pattern rearrangement unit after AF Pels detection*/
    int32_t paf_pattern_rearrangement_en;
    /*!< afsXStart AF pixel detection crop - start X position*/
    int32_t afsXStart;
    /*!< afsYStart AF pixel detection crop - start Y position*/
    int32_t afsYStart;
    /*!< afsXEnd AF pixel detection crop - end X position*/
    int32_t afsXEnd;
    /*!< afsYEnd AF pixel detection crop - end Y position*/
    int32_t afsYEnd;
    /*!< afsXStartCropEn AF pixel crop enable - start X position*/
    int32_t afsXStartCropEn;
    /*!< afsYStartCropEn AF pixel crop enable - start Y position*/
    int32_t afsYStartCropEn;
    /*!< afsXEndCropEn AF pixel crop enable - end X position*/
    int32_t afsXEndCropEn;
    /*!< afsYEndCropEn AF pixel crop enable - end Y position*/
    int32_t afsYEndCropEn;
    /*!< bypass bypass to the block*/
    int32_t bypass;
    /*!< use_nlm[16] use non local means mechanism*/
    int32_t use_nlm[16];
    /*!< sad1_thr threshold on the first sad*/
    int32_t sad1_thr;
    /*!< sad2_thr threshold on the second sad*/
    int32_t sad2_thr;
    /*!< pixel_diff_thr threshold on the pixel difference*/
    int32_t pixel_diff_thr;
    /*!< min_direction_sad_thr threshold on the min direction*/
    int32_t min_direction_sad_thr;
    /*!< max_direction_sad_thr threshold on the max direction*/
    int32_t max_direction_sad_thr;
    /*!< saturation_thr protect pixels in saturated areas*/
    int32_t saturation_thr;
    /*!< ignore_ver_direction[16] ignore vertical direction for certain types of pdaf sensors*/
    int32_t ignore_ver_direction[16];
    /*!< configunit_med_protection_slope[3] nlm fix config unit*/
    int32_t configunit_med_protection_slope[3];
    /*!< configunit_med_protection_x[4] nlm fix config unit*/
    int32_t configunit_med_protection_x[4];
    /*!< configunit_med_protection_y[3] nlm fix config unit*/
    int32_t configunit_med_protection_y[3];
    /*!< clamping_disable disable clamping to support previous version of dpc*/
    int32_t clamping_disable;
    /*!< median_blend_coef median blending parameter*/
    int32_t median_blend_coef;

} ia_pal_isp_dpc_1_3_t;

/*! \isp struct dpc_2_0

*/
typedef struct
{
    /*!< afxoffset[32] 8 Autofocus pixels X axis offset U14.0, should be smaller than afxperiod*/
    int32_t afxoffset[32];
    /*!< afxperiod[32] 8 Autofocus pixels X axis period*/
    int32_t afxperiod[32];
    /*!< afyoffset[32] 8 Autofocus pixels Y axis offset U14.0, should be smaller than afyperiod*/
    int32_t afyoffset[32];
    /*!< afyperiod[32] 8 Autofocus pixels Y axis period*/
    int32_t afyperiod[32];
    /*!< hdrfactors[16] 4x4 HDR exposure factor U6.8*/
    int32_t hdrfactors[16];
    /*!< hdrfactorsinverse[16] 4x4 HDR exposure inverse factor U6.8 - should be inverse of hdrfactors*/
    int32_t hdrfactorsinverse[16];
    /*!< configunitcolddistvsmedian_slope[7] cold dist vs median config unit classifier*/
    int32_t configunitcolddistvsmedian_slope[7];
    /*!< configunitcolddistvsmedian_x[8] cold dist vs median config unit classifier*/
    int32_t configunitcolddistvsmedian_x[8];
    /*!< configunitcolddistvsmedian_y[7] cold dist vs median config unit classifier*/
    int32_t configunitcolddistvsmedian_y[7];
    /*!< configunitcolddistvsneighb_slope[7] cold dist vs neigb config unit classifier*/
    int32_t configunitcolddistvsneighb_slope[7];
    /*!< configunitcolddistvsneighb_x[8] cold dist vs neigb config unit classifier*/
    int32_t configunitcolddistvsneighb_x[8];
    /*!< configunitcolddistvsneighb_y[7] cold dist vs neigb config unit classifier*/
    int32_t configunitcolddistvsneighb_y[7];
    /*!< configunitfix_slope[3] fix config unit*/
    int32_t configunitfix_slope[3];
    /*!< configunitfix_x[4] fix config unit*/
    int32_t configunitfix_x[4];
    /*!< configunitfix_y[3] fix config unit*/
    int32_t configunitfix_y[3];
    /*!< configunithotdistvsmedian_slope[7] hot dist vs median classifier*/
    int32_t configunithotdistvsmedian_slope[7];
    /*!< configunithotdistvsmedian_x[8] hot dist vs median classifier*/
    int32_t configunithotdistvsmedian_x[8];
    /*!< configunithotdistvsmedian_y[7] hot dist vs median classifier*/
    int32_t configunithotdistvsmedian_y[7];
    /*!< configunithotdistvsneighb_slope[7] hot dist vs neigb config unit classifier*/
    int32_t configunithotdistvsneighb_slope[7];
    /*!< configunithotdistvsneighb_x[8] hot dist vs neigb config unit classifier*/
    int32_t configunithotdistvsneighb_x[8];
    /*!< configunithotdistvsneighb_y[7] hot dist vs neigb config unit classifier*/
    int32_t configunithotdistvsneighb_y[7];
    /*!< pelesttype[16] 0-P1, 1-P2, 2-P3, 3-P4, 4-P5, 5-P6*/
    int32_t pelesttype[16];
    /*!< dtype[16] 0-D1 1-D2  2-D3*/
    int32_t dtype[16];
    /*!< pmasks[384] configurations related to the bayer pattern*/
    int32_t pmasks[384];
    /*!< dmasks[48] configurations related to the bayer pattern*/
    int32_t dmasks[48];
    /*!< bitreduceshift Shift value for bit reduce block*/
    int32_t bitreduceshift;
    /*!< afenable enable for the AF unit block*/
    int32_t afenable;
    /*!< dynamicenable enable for the dynamic detection block*/
    int32_t dynamicenable;
    /*!< frame_width frame width*/
    int32_t frame_width;
    /*!< paf_grid_en[32] paf grid enables*/
    int32_t paf_grid_en[32];
    /*!< paf_output_mode 0)disables, do not pass anything\n 1) first line sent to memset0 second\n line sent to memset1\n 2)first line sent to memset0 second to memset 1 and afterward alternate every two lines 3) passthrough –send to memset0 everything*/
    int32_t paf_output_mode;
    /*!< swapping1stbc Apply swapping of BC inputs for 1st/3rd/etc.\n0: no swapping\n1: swap B/C inputs*/
    int32_t swapping1stbc;
    /*!< swapping1stcd Apply swapping of CD inputs for 1st/3rd/etc.\n0: no swapping\n1: swap C/D inputs*/
    int32_t swapping1stcd;
    /*!< swapping2ndbc Apply swapping of BC inputs for 2nd/4th/etc. lines\n0: no swapping\n1: swap A/B inputs*/
    int32_t swapping2ndbc;
    /*!< swapping2ndcd Apply swapping of CD inputs for 2nd/4th/etc. lines\n0: no swapping\n1: swap C/D inputs*/
    int32_t swapping2ndcd;
    /*!< pdaf_width Width in units of PDAF pixels. After Width pixels – Pext knows there is a new line coming in. In Modes1..3 – max line length is as in the internal buffer size which is 1024 pixels.*/
    int32_t pdaf_width;
    /*!< pdaf_height Height in units of pdaf lines*/
    int32_t pdaf_height;
    /*!< drop_pattern[32] Drop pattern for AF pixels. 1=drop the lines\n0=use the line*/
    int32_t drop_pattern[32];
    /*!< drop_period Period of the drop pattern*/
    int32_t drop_period;
    /*!< paf_pattern_rearrangement_en Enable pattern rearrangement unit after AF Pels detection*/
    int32_t paf_pattern_rearrangement_en;
    /*!< afsXStart AF pixel detection crop - start X position*/
    int32_t afsXStart;
    /*!< afsYStart AF pixel detection crop - start Y position*/
    int32_t afsYStart;
    /*!< afsXEnd AF pixel detection crop - end X position*/
    int32_t afsXEnd;
    /*!< afsYEnd AF pixel detection crop - end Y position*/
    int32_t afsYEnd;
    /*!< afsXStartCropEn AF pixel crop enable - start X position*/
    int32_t afsXStartCropEn;
    /*!< afsYStartCropEn AF pixel crop enable - start Y position*/
    int32_t afsYStartCropEn;
    /*!< afsXEndCropEn AF pixel crop enable - end X position*/
    int32_t afsXEndCropEn;
    /*!< afsYEndCropEn AF pixel crop enable - end Y position*/
    int32_t afsYEndCropEn;
    /*!< bypass bypass to the block*/
    int32_t bypass;
    /*!< use_nlm[16] use non local means mechanism*/
    int32_t use_nlm[16];
    /*!< sad1_thr threshold on the first sad*/
    int32_t sad1_thr;
    /*!< sad2_thr threshold on the second sad*/
    int32_t sad2_thr;
    /*!< pixel_diff_thr threshold on the pixel difference*/
    int32_t pixel_diff_thr;
    /*!< min_direction_sad_thr threshold on the min direction*/
    int32_t min_direction_sad_thr;
    /*!< max_direction_sad_thr threshold on the max direction*/
    int32_t max_direction_sad_thr;
    /*!< saturation_thr protect pixels in saturated areas*/
    int32_t saturation_thr;
    /*!< ignore_ver_direction[16] ignore vertical direction for certain types of pdaf sensors*/
    int32_t ignore_ver_direction[16];
    /*!< configunit_med_protection_slope[3] nlm fix config unit*/
    int32_t configunit_med_protection_slope[3];
    /*!< configunit_med_protection_x[4] nlm fix config unit*/
    int32_t configunit_med_protection_x[4];
    /*!< configunit_med_protection_y[3] nlm fix config unit*/
    int32_t configunit_med_protection_y[3];
    /*!< clamping_disable disable clamping to support previous version of dpc*/
    int32_t clamping_disable;
    /*!< sensor_type 0=simple_bayer 1=2pd 2=sve_2pd 3=sve_zigzag1 4=sve_zigzag2*/
    int32_t sensor_type;
    /*!< fix_dist when 0 - opposite sign distances around the pixel are ignored*/
    int32_t fix_dist;
    /*!< flip_neigb_axis flip neigb vs dist axis*/
    int32_t flip_neigb_axis;
    /*!< g_locations_for_sve[16] g on 4x4 grid*/
    int32_t g_locations_for_sve[16];
    /*!< config_median_blend_slope[3] blend coef cfg*/
    int32_t config_median_blend_slope[3];
    /*!< config_median_blend_x[4] blend coef cfg*/
    int32_t config_median_blend_x[4];
    /*!< config_median_blend_y[3] blend coef cfg*/
    int32_t config_median_blend_y[3];
    /*!< config_ridges_slope[3] ridge coef cfg*/
    int32_t config_ridges_slope[3];
    /*!< config_ridges_x[4] ridge coef cfg*/
    int32_t config_ridges_x[4];
    /*!< config_ridges_y[3] ridge coef cfg*/
    int32_t config_ridges_y[3];

} ia_pal_isp_dpc_2_0_t;

/*! \isp struct drc_1
DRC filter
*/
typedef struct
{
    /*!< Bypass Bypass filter*/
    int32_t Bypass;
    /*!< blus_ds_factor downscale factor: 8 or 16*/
    int32_t blus_ds_factor;
    /*!< blus_sp_coef_a[256] spatial coefficients A (top left), 0.0.15*/
    int32_t blus_sp_coef_a[256];
    /*!< blus_sp_coef_b[256] spatial coefficients B (top right), 0.0.15*/
    int32_t blus_sp_coef_b[256];
    /*!< blus_sp_coef_c[256] spatial coefficients C (bottom left), 0.0.15*/
    int32_t blus_sp_coef_c[256];
    /*!< blus_sp_coef_d[256] spatial coefficients D (bottom right), 0.0.15*/
    int32_t blus_sp_coef_d[256];
    /*!< blus_sim_min min value of similarity, 0.0.15*/
    int32_t blus_sim_min;
    /*!< lce_bypass LCE bypass*/
    int32_t lce_bypass;
    /*!< lce_model_slope LCE model slope, 1.7.8*/
    int32_t lce_model_slope;
    /*!< lce_model_offset LCE model offset, 1.7.8*/
    int32_t lce_model_offset;
    /*!< lce_viir_sp_weight VIIR spatial weight, 1.0.15*/
    int32_t lce_viir_sp_weight;
    /*!< lce_power LCE power, 0.3.12*/
    int32_t lce_power;
    /*!< lce_deadzone LCE deadzone, 0.0.15*/
    int32_t lce_deadzone;
    /*!< lce_clip LCE clip, 0.0.15*/
    int32_t lce_clip;
    /*!< lr_gain_map[133584] LRGain, 0.7.8*/
    int32_t lr_gain_map[133584];
    /*!< lr_wgt_map[133584] LRWgt*/
    int32_t lr_wgt_map[133584];
    /*!< lr_map_width map width*/
    int32_t lr_map_width;
    /*!< lr_map_height map height*/
    int32_t lr_map_height;
    /*!< gtm_bypass GTM bypass*/
    int32_t gtm_bypass;
    /*!< xcu_gtm_slope_vec[32] GTM xcu slope vector, 1.15-xcu_gtm_slope_resolution.xcu_gtm_slope_resolution*/
    int32_t xcu_gtm_slope_vec[32];
    /*!< xcu_gtm_offset_vec[32] GTM xcu offset vector, 0.0.15*/
    int32_t xcu_gtm_offset_vec[32];
    /*!< xcu_gtm_x_cord_vec[32] GTM xcu x cord vector, 0.0.15*/
    int32_t xcu_gtm_x_cord_vec[32];
    /*!< xcu_gtm_x_cord_max GTM xcu x cord max, 0.0.15*/
    int32_t xcu_gtm_x_cord_max;
    /*!< xcu_gtm_exponent GTM xcu exponent*/
    int32_t xcu_gtm_exponent;
    /*!< xcu_gtm_slope_resolution GTM xcu slope resolution*/
    int32_t xcu_gtm_slope_resolution;
    /*!< gtm_gain_frac_bit GTM gain fractional bit*/
    int32_t gtm_gain_frac_bit;

} ia_pal_isp_drc_1_t;

/*! \isp struct drc_2
LUT based DRC and Defog
*/
typedef struct
{
    /*!< bypass Bypass filter*/
    int32_t bypass;
    /*!< gtm_resolution GTM slope resolution*/
    int32_t gtm_resolution;
    /*!< gtm_slope_vec[32] GTM slope vector*/
    int32_t gtm_slope_vec[32];
    /*!< gtm_offset_vec[32] GTM offset vector*/
    int32_t gtm_offset_vec[32];
    /*!< gtm_x_cord_vec[32] GTM x cord vector*/
    int32_t gtm_x_cord_vec[32];
    /*!< gtm_x_cord_max GTM xcu x cord max, 0.0.15(for assertion)*/
    int32_t gtm_x_cord_max;
    /*!< gtm_exponent GTM xcu exponent(for assertion)*/
    int32_t gtm_exponent;
    /*!< gce_defog_resolution LCE&Defog slope resolution*/
    int32_t gce_defog_resolution;
    /*!< gce_defog_slope_vec[64] LCE&Defog slope vector*/
    int32_t gce_defog_slope_vec[64];
    /*!< gce_defog_offset_vec[64] LCE&Defog offset vector*/
    int32_t gce_defog_offset_vec[64];
    /*!< gce_defog_x_cord_vec[64] LCE&Defog x cord vector*/
    int32_t gce_defog_x_cord_vec[64];
    /*!< gce_defog_x_cord_max LCE&Defog xcu x cord max, 0.0.15(for assertion)*/
    int32_t gce_defog_x_cord_max;
    /*!< gce_defog_exponent LCE&Defog xcu exponent(for assertion)*/
    int32_t gce_defog_exponent;
    /*!< defog_A0 Control threshold for defog*/
    int32_t defog_A0;
    /*!< defog_A1 Control threshold for defog*/
    int32_t defog_A1;
    /*!< sharp_amountL Control sharpening strength L*/
    int32_t sharp_amountL;
    /*!< sharp_maxL Control sharpening max L*/
    int32_t sharp_maxL;
    /*!< sharp_thrL Control sharpening threshold L*/
    int32_t sharp_thrL;
    /*!< sharp_amountS Control sharpening strength S*/
    int32_t sharp_amountS;
    /*!< sharp_maxS Control sharpening max S*/
    int32_t sharp_maxS;
    /*!< sharp_thrS Control sharpening threshold S*/
    int32_t sharp_thrS;
    /*!< ltm_enable ltm enable*/
    int32_t ltm_enable;
    /*!< ltm_weight ltm weight*/
    int32_t ltm_weight;

} ia_pal_isp_drc_2_t;

/*! \isp struct ds_dynamic
Position in 2x2 QUAD form
*/
typedef struct
{
    /*!< extract_pos Position in 2x2 QUAD form - to extract pixel or pixel position in (00, 01, 10, 11) to perform downscale*/
    int32_t extract_pos;

} ia_pal_isp_ds_dynamic_t;

/*! \isp struct dvsstatistics_2

*/
typedef struct
{
    /*!< kappa Global configuration - kappa*/
    int32_t kappa;
    /*!< match_shift Global configuration - match_shift*/
    int32_t match_shift;
    /*!< ybin_mode Global configuration - y binning mode*/
    int32_t ybin_mode;
    /*!< grid_width_l0 DVS statistics grid width level 0*/
    int32_t grid_width_l0;
    /*!< grid_height_l0 DVS statistics grid height level 0*/
    int32_t grid_height_l0;
    /*!< block_width_l0 DVS statistics block width level 0*/
    int32_t block_width_l0;
    /*!< block_height_l0 DVS statistics block height level 0*/
    int32_t block_height_l0;
    /*!< x_start_l0 DVS statistics level 0 x start*/
    int32_t x_start_l0;
    /*!< y_start_l0 DVS statistics level 0 y start*/
    int32_t y_start_l0;
    /*!< enabled_l0 DVS statistics level 0 enable*/
    int32_t enabled_l0;
    /*!< x_end_l0 DVS statistics level 0 x end*/
    int32_t x_end_l0;
    /*!< y_end_l0 DVS statistics level 0 y end*/
    int32_t y_end_l0;
    /*!< grid_width_l1 DVS statistics grid width level 1*/
    int32_t grid_width_l1;
    /*!< grid_height_l1 DVS statistics grid height level 1*/
    int32_t grid_height_l1;
    /*!< block_width_l1 DVS statistics block width level 1*/
    int32_t block_width_l1;
    /*!< block_height_l1 DVS statistics block height level 1*/
    int32_t block_height_l1;
    /*!< x_start_l1 DVS statistics level 1 x start*/
    int32_t x_start_l1;
    /*!< y_start_l1 DVS statistics level 1 y start*/
    int32_t y_start_l1;
    /*!< enabled_l1 DVS statistics level 1 enable*/
    int32_t enabled_l1;
    /*!< x_end_l1 DVS statistics level 1 x end*/
    int32_t x_end_l1;
    /*!< y_end_l1 DVS statistics level 1 y end*/
    int32_t y_end_l1;
    /*!< grid_width_l2 DVS statistics grid width level 2*/
    int32_t grid_width_l2;
    /*!< grid_height_l2 DVS statistics grid height level 2*/
    int32_t grid_height_l2;
    /*!< block_width_l2 DVS statistics block width level 2*/
    int32_t block_width_l2;
    /*!< block_height_l2 DVS statistics block height level 2*/
    int32_t block_height_l2;
    /*!< x_start_l2 DVS statistics level 2 x start*/
    int32_t x_start_l2;
    /*!< y_start_l2 DVS statistics level 2 y start*/
    int32_t y_start_l2;
    /*!< enabled_l2 DVS statistics level 2 enable*/
    int32_t enabled_l2;
    /*!< x_end_l2 DVS statistics level 2 x end*/
    int32_t x_end_l2;
    /*!< y_end_l2 DVS statistics level 2 y end*/
    int32_t y_end_l2;
    /*!< feroi_x_start_l0 DVS statistics fe-roi level 0 x start*/
    int32_t feroi_x_start_l0;
    /*!< feroi_y_start_l0 DVS statistics fe-roi level 0 y start*/
    int32_t feroi_y_start_l0;
    /*!< feroi_x_end_l0 DVS statistics fe-roi level 0 x end*/
    int32_t feroi_x_end_l0;
    /*!< feroi_y_end_l0 DVS statistics fe-roi level 0 y end*/
    int32_t feroi_y_end_l0;
    /*!< feroi_x_start_l1 DVS statistics fe-roi level 1 x start*/
    int32_t feroi_x_start_l1;
    /*!< feroi_y_start_l1 DVS statistics fe-roi level 1 y start*/
    int32_t feroi_y_start_l1;
    /*!< feroi_x_end_l1 DVS statistics fe-roi level 1 x end*/
    int32_t feroi_x_end_l1;
    /*!< feroi_y_end_l1 DVS statistics fe-roi level 1 y end*/
    int32_t feroi_y_end_l1;
    /*!< feroi_x_start_l2 DVS statistics fe-roi level 2 x start*/
    int32_t feroi_x_start_l2;
    /*!< feroi_y_start_l2 DVS statistics fe-roi level 2 y start*/
    int32_t feroi_y_start_l2;
    /*!< feroi_x_end_l2 DVS statistics fe-roi level 2 x end*/
    int32_t feroi_x_end_l2;
    /*!< feroi_y_end_l2 DVS statistics fe-roi level 2 y end*/
    int32_t feroi_y_end_l2;

} ia_pal_isp_dvsstatistics_2_t;

/*! \isp struct espa_1_0
Extendedn Stream Precsion Adapter
*/
typedef struct
{
    /*!< Shift_l_comp_0 Shif_Left_enable_for_channel_0: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_0;
    /*!< Shift_l_comp_1 Shif_Left_enable_for_channel_1: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_1;
    /*!< Shift_l_comp_2 Shif_Left_enable_for_channel_2: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_2;
    /*!< Shift_l_comp_3 Shif_Left_enable_for_channel_3: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_3;
    /*!< Shift_l_comp_4 Shif_Left_enable_for_channel_4: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_4;
    /*!< Shift_l_comp_5 Shif_Left_enable_for_channel_5: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_5;
    /*!< Shift_val_comp_0 Shif_value_for_channel_0*/
    int32_t Shift_val_comp_0;
    /*!< Shift_val_comp_1 Shif_value_for_channel_1*/
    int32_t Shift_val_comp_1;
    /*!< Shift_val_comp_2 Shif_value_for_channel_2*/
    int32_t Shift_val_comp_2;
    /*!< Shift_val_comp_3 Shif_value_for_channel_3*/
    int32_t Shift_val_comp_3;
    /*!< Shift_val_comp_4 Shif_value_for_channel_4*/
    int32_t Shift_val_comp_4;
    /*!< Shift_val_comp_5 Shif_value_for_channel_5*/
    int32_t Shift_val_comp_5;
    /*!< Clip_min_comp_0 Clip_to_positive_for_channel_0*/
    int32_t Clip_min_comp_0;
    /*!< Clip_min_comp_1 Clip_to_positive_for_channel_1*/
    int32_t Clip_min_comp_1;
    /*!< Clip_min_comp_2 Clip_to_positive_for_channel_2*/
    int32_t Clip_min_comp_2;
    /*!< Clip_min_comp_3 Clip_to_positive_for_channel_3*/
    int32_t Clip_min_comp_3;
    /*!< Clip_min_comp_4 Clip_to_positive_for_channel_4*/
    int32_t Clip_min_comp_4;
    /*!< Clip_min_comp_5 Clip_to_positive_for_channel_5*/
    int32_t Clip_min_comp_5;
    /*!< Clip_max_comp_0 Clip_to_negative_for_channel_0*/
    int32_t Clip_max_comp_0;
    /*!< Clip_max_comp_1 Clip_to_negative_for_channel_1*/
    int32_t Clip_max_comp_1;
    /*!< Clip_max_comp_2 Clip_to_negative_for_channel_2*/
    int32_t Clip_max_comp_2;
    /*!< Clip_max_comp_3 Clip_to_negative_for_channel_3*/
    int32_t Clip_max_comp_3;
    /*!< Clip_max_comp_4 Clip_to_negative_for_channel_4*/
    int32_t Clip_max_comp_4;
    /*!< Clip_max_comp_5 Clip_to_negative_for_channel_5*/
    int32_t Clip_max_comp_5;
    /*!< Offset_comp_0 Ofset_value_for_channel_0*/
    int32_t Offset_comp_0;
    /*!< Offset_comp_1 Ofset_value_for_channel_1*/
    int32_t Offset_comp_1;
    /*!< Offset_comp_2 Ofset_value_for_channel_2*/
    int32_t Offset_comp_2;
    /*!< Offset_comp_3 Ofset_value_for_channel_3*/
    int32_t Offset_comp_3;
    /*!< Offset_comp_4 Ofset_value_for_channel_4*/
    int32_t Offset_comp_4;
    /*!< Offset_comp_5 Ofset_value_for_channel_5*/
    int32_t Offset_comp_5;
    /*!< Clip_min_val_0 Clip_min_value_for_channel_0*/
    int32_t Clip_min_val_0;
    /*!< Clip_max_val_0 Clip_max_value_for_channel_0*/
    int32_t Clip_max_val_0;
    /*!< Clip_min_val_1 Clip_min_value_for_channel_1*/
    int32_t Clip_min_val_1;
    /*!< Clip_max_val_1 Clip_max_value_for_channel_1*/
    int32_t Clip_max_val_1;
    /*!< Clip_min_val_2 Clip_min_value_for_channel_2*/
    int32_t Clip_min_val_2;
    /*!< Clip_max_val_2 Clip_max_value_for_channel_2*/
    int32_t Clip_max_val_2;
    /*!< Clip_min_val_3 Clip_min_value_for_channel_3*/
    int32_t Clip_min_val_3;
    /*!< Clip_max_val_3 Clip_max_value_for_channel_3*/
    int32_t Clip_max_val_3;
    /*!< Clip_min_val_4 Clip_min_value_for_channel_4*/
    int32_t Clip_min_val_4;
    /*!< Clip_max_val_4 Clip_max_value_for_channel_4*/
    int32_t Clip_max_val_4;
    /*!< Clip_min_val_5 Clip_min_value_for_channel_5*/
    int32_t Clip_min_val_5;
    /*!< Clip_max_val_5 Clip_max_value_for_channel_5*/
    int32_t Clip_max_val_5;

} ia_pal_isp_espa_1_0_t;

/*! \isp struct espa_1_1
Extended Stream Precsion Adapter
*/
typedef struct
{
    /*!< Shift_l_comp_0 Shif_Left_enable_for_channel_0: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_0;
    /*!< Shift_l_comp_1 Shif_Left_enable_for_channel_1: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_1;
    /*!< Shift_l_comp_2 Shif_Left_enable_for_channel_2: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_2;
    /*!< Shift_l_comp_3 Shif_Left_enable_for_channel_3: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_3;
    /*!< Shift_l_comp_4 Shif_Left_enable_for_channel_4: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_4;
    /*!< Shift_l_comp_5 Shif_Left_enable_for_channel_5: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_5;
    /*!< Shift_val_comp_0 Shif_value_for_channel_0*/
    int32_t Shift_val_comp_0;
    /*!< Shift_val_comp_1 Shif_value_for_channel_1*/
    int32_t Shift_val_comp_1;
    /*!< Shift_val_comp_2 Shif_value_for_channel_2*/
    int32_t Shift_val_comp_2;
    /*!< Shift_val_comp_3 Shif_value_for_channel_3*/
    int32_t Shift_val_comp_3;
    /*!< Shift_val_comp_4 Shif_value_for_channel_4*/
    int32_t Shift_val_comp_4;
    /*!< Shift_val_comp_5 Shif_value_for_channel_5*/
    int32_t Shift_val_comp_5;
    /*!< Clip_min_comp_0 Clip_to_positive_for_channel_0*/
    int32_t Clip_min_comp_0;
    /*!< Clip_min_comp_1 Clip_to_positive_for_channel_1*/
    int32_t Clip_min_comp_1;
    /*!< Clip_min_comp_2 Clip_to_positive_for_channel_2*/
    int32_t Clip_min_comp_2;
    /*!< Clip_min_comp_3 Clip_to_positive_for_channel_3*/
    int32_t Clip_min_comp_3;
    /*!< Clip_min_comp_4 Clip_to_positive_for_channel_4*/
    int32_t Clip_min_comp_4;
    /*!< Clip_min_comp_5 Clip_to_positive_for_channel_5*/
    int32_t Clip_min_comp_5;
    /*!< Clip_max_comp_0 Clip_to_negative_for_channel_0*/
    int32_t Clip_max_comp_0;
    /*!< Clip_max_comp_1 Clip_to_negative_for_channel_1*/
    int32_t Clip_max_comp_1;
    /*!< Clip_max_comp_2 Clip_to_negative_for_channel_2*/
    int32_t Clip_max_comp_2;
    /*!< Clip_max_comp_3 Clip_to_negative_for_channel_3*/
    int32_t Clip_max_comp_3;
    /*!< Clip_max_comp_4 Clip_to_negative_for_channel_4*/
    int32_t Clip_max_comp_4;
    /*!< Clip_max_comp_5 Clip_to_negative_for_channel_5*/
    int32_t Clip_max_comp_5;
    /*!< Offset_comp_0 Ofset_value_for_channel_0*/
    int32_t Offset_comp_0;
    /*!< Offset_comp_1 Ofset_value_for_channel_1*/
    int32_t Offset_comp_1;
    /*!< Offset_comp_2 Ofset_value_for_channel_2*/
    int32_t Offset_comp_2;
    /*!< Offset_comp_3 Ofset_value_for_channel_3*/
    int32_t Offset_comp_3;
    /*!< Offset_comp_4 Ofset_value_for_channel_4*/
    int32_t Offset_comp_4;
    /*!< Offset_comp_5 Ofset_value_for_channel_5*/
    int32_t Offset_comp_5;
    /*!< Clip_min_val_0 Clip_min_value_for_channel_0*/
    int32_t Clip_min_val_0;
    /*!< Clip_max_val_0 Clip_max_value_for_channel_0*/
    int32_t Clip_max_val_0;
    /*!< Clip_min_val_1 Clip_min_value_for_channel_1*/
    int32_t Clip_min_val_1;
    /*!< Clip_max_val_1 Clip_max_value_for_channel_1*/
    int32_t Clip_max_val_1;
    /*!< Clip_min_val_2 Clip_min_value_for_channel_2*/
    int32_t Clip_min_val_2;
    /*!< Clip_max_val_2 Clip_max_value_for_channel_2*/
    int32_t Clip_max_val_2;
    /*!< Clip_min_val_3 Clip_min_value_for_channel_3*/
    int32_t Clip_min_val_3;
    /*!< Clip_max_val_3 Clip_max_value_for_channel_3*/
    int32_t Clip_max_val_3;
    /*!< Clip_min_val_4 Clip_min_value_for_channel_4*/
    int32_t Clip_min_val_4;
    /*!< Clip_max_val_4 Clip_max_value_for_channel_4*/
    int32_t Clip_max_val_4;
    /*!< Clip_min_val_5 Clip_min_value_for_channel_5*/
    int32_t Clip_min_val_5;
    /*!< Clip_max_val_5 Clip_max_value_for_channel_5*/
    int32_t Clip_max_val_5;
    /*!< range_reduction_en range_reduction_en*/
    int32_t range_reduction_en;
    /*!< output_resolution bpp of output image. 8, 10 and 12 are valid.*/
    int32_t output_resolution;
    /*!< MSB_alignment_en 6 bit shift left for P010, 4 for P012*/
    int32_t MSB_alignment_en;

} ia_pal_isp_espa_1_1_t;

/*! \isp struct espa_isa_bayer_a
Extended Stream Precsion Adapter
*/
typedef struct
{
    /*!< Shift_l_comp_0 Shif_Left_enable_for_channel_0: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_0;
    /*!< Shift_l_comp_1 Shif_Left_enable_for_channel_1: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_1;
    /*!< Shift_l_comp_2 Shif_Left_enable_for_channel_2: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_2;
    /*!< Shift_l_comp_3 Shif_Left_enable_for_channel_3: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_3;
    /*!< Shift_l_comp_4 Shif_Left_enable_for_channel_4: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_4;
    /*!< Shift_l_comp_5 Shif_Left_enable_for_channel_5: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_5;
    /*!< Shift_val_comp_0 Shif_value_for_channel_0*/
    int32_t Shift_val_comp_0;
    /*!< Shift_val_comp_1 Shif_value_for_channel_1*/
    int32_t Shift_val_comp_1;
    /*!< Shift_val_comp_2 Shif_value_for_channel_2*/
    int32_t Shift_val_comp_2;
    /*!< Shift_val_comp_3 Shif_value_for_channel_3*/
    int32_t Shift_val_comp_3;
    /*!< Shift_val_comp_4 Shif_value_for_channel_4*/
    int32_t Shift_val_comp_4;
    /*!< Shift_val_comp_5 Shif_value_for_channel_5*/
    int32_t Shift_val_comp_5;
    /*!< Clip_min_comp_0 Clip_to_positive_for_channel_0*/
    int32_t Clip_min_comp_0;
    /*!< Clip_min_comp_1 Clip_to_positive_for_channel_1*/
    int32_t Clip_min_comp_1;
    /*!< Clip_min_comp_2 Clip_to_positive_for_channel_2*/
    int32_t Clip_min_comp_2;
    /*!< Clip_min_comp_3 Clip_to_positive_for_channel_3*/
    int32_t Clip_min_comp_3;
    /*!< Clip_min_comp_4 Clip_to_positive_for_channel_4*/
    int32_t Clip_min_comp_4;
    /*!< Clip_min_comp_5 Clip_to_positive_for_channel_5*/
    int32_t Clip_min_comp_5;
    /*!< Clip_max_comp_0 Clip_to_negative_for_channel_0*/
    int32_t Clip_max_comp_0;
    /*!< Clip_max_comp_1 Clip_to_negative_for_channel_1*/
    int32_t Clip_max_comp_1;
    /*!< Clip_max_comp_2 Clip_to_negative_for_channel_2*/
    int32_t Clip_max_comp_2;
    /*!< Clip_max_comp_3 Clip_to_negative_for_channel_3*/
    int32_t Clip_max_comp_3;
    /*!< Clip_max_comp_4 Clip_to_negative_for_channel_4*/
    int32_t Clip_max_comp_4;
    /*!< Clip_max_comp_5 Clip_to_negative_for_channel_5*/
    int32_t Clip_max_comp_5;
    /*!< Offset_comp_0 Ofset_value_for_channel_0*/
    int32_t Offset_comp_0;
    /*!< Offset_comp_1 Ofset_value_for_channel_1*/
    int32_t Offset_comp_1;
    /*!< Offset_comp_2 Ofset_value_for_channel_2*/
    int32_t Offset_comp_2;
    /*!< Offset_comp_3 Ofset_value_for_channel_3*/
    int32_t Offset_comp_3;
    /*!< Offset_comp_4 Ofset_value_for_channel_4*/
    int32_t Offset_comp_4;
    /*!< Offset_comp_5 Ofset_value_for_channel_5*/
    int32_t Offset_comp_5;
    /*!< Clip_min_val_0 Clip_min_value_for_channel_0*/
    int32_t Clip_min_val_0;
    /*!< Clip_max_val_0 Clip_max_value_for_channel_0*/
    int32_t Clip_max_val_0;
    /*!< Clip_min_val_1 Clip_min_value_for_channel_1*/
    int32_t Clip_min_val_1;
    /*!< Clip_max_val_1 Clip_max_value_for_channel_1*/
    int32_t Clip_max_val_1;
    /*!< Clip_min_val_2 Clip_min_value_for_channel_2*/
    int32_t Clip_min_val_2;
    /*!< Clip_max_val_2 Clip_max_value_for_channel_2*/
    int32_t Clip_max_val_2;
    /*!< Clip_min_val_3 Clip_min_value_for_channel_3*/
    int32_t Clip_min_val_3;
    /*!< Clip_max_val_3 Clip_max_value_for_channel_3*/
    int32_t Clip_max_val_3;
    /*!< Clip_min_val_4 Clip_min_value_for_channel_4*/
    int32_t Clip_min_val_4;
    /*!< Clip_max_val_4 Clip_max_value_for_channel_4*/
    int32_t Clip_max_val_4;
    /*!< Clip_min_val_5 Clip_min_value_for_channel_5*/
    int32_t Clip_min_val_5;
    /*!< Clip_max_val_5 Clip_max_value_for_channel_5*/
    int32_t Clip_max_val_5;
    /*!< range_reduction_en range_reduction_en*/
    int32_t range_reduction_en;
    /*!< output_resolution bpp of output image. 8, 10 and 12 are valid.*/
    int32_t output_resolution;
    /*!< MSB_alignment_en 6 bit shift left for P010, 4 for P012*/
    int32_t MSB_alignment_en;

} ia_pal_isp_espa_isa_bayer_a_t;

/*! \isp struct espa_isa_ir_md
Extended Stream Precision Adapter
*/
typedef struct
{
    /*!< Shift_l_comp_0 Shif_Left_enable_for_channel_0: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_0;
    /*!< Shift_l_comp_1 Shif_Left_enable_for_channel_1: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_1;
    /*!< Shift_l_comp_2 Shif_Left_enable_for_channel_2: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_2;
    /*!< Shift_l_comp_3 Shif_Left_enable_for_channel_3: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_3;
    /*!< Shift_l_comp_4 Shif_Left_enable_for_channel_4: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_4;
    /*!< Shift_l_comp_5 Shif_Left_enable_for_channel_5: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_5;
    /*!< Shift_val_comp_0 Shif_value_for_channel_0*/
    int32_t Shift_val_comp_0;
    /*!< Shift_val_comp_1 Shif_value_for_channel_1*/
    int32_t Shift_val_comp_1;
    /*!< Shift_val_comp_2 Shif_value_for_channel_2*/
    int32_t Shift_val_comp_2;
    /*!< Shift_val_comp_3 Shif_value_for_channel_3*/
    int32_t Shift_val_comp_3;
    /*!< Shift_val_comp_4 Shif_value_for_channel_4*/
    int32_t Shift_val_comp_4;
    /*!< Shift_val_comp_5 Shif_value_for_channel_5*/
    int32_t Shift_val_comp_5;
    /*!< Clip_min_comp_0 Clip_to_positive_for_channel_0*/
    int32_t Clip_min_comp_0;
    /*!< Clip_min_comp_1 Clip_to_positive_for_channel_1*/
    int32_t Clip_min_comp_1;
    /*!< Clip_min_comp_2 Clip_to_positive_for_channel_2*/
    int32_t Clip_min_comp_2;
    /*!< Clip_min_comp_3 Clip_to_positive_for_channel_3*/
    int32_t Clip_min_comp_3;
    /*!< Clip_min_comp_4 Clip_to_positive_for_channel_4*/
    int32_t Clip_min_comp_4;
    /*!< Clip_min_comp_5 Clip_to_positive_for_channel_5*/
    int32_t Clip_min_comp_5;
    /*!< Clip_max_comp_0 Clip_to_negative_for_channel_0*/
    int32_t Clip_max_comp_0;
    /*!< Clip_max_comp_1 Clip_to_negative_for_channel_1*/
    int32_t Clip_max_comp_1;
    /*!< Clip_max_comp_2 Clip_to_negative_for_channel_2*/
    int32_t Clip_max_comp_2;
    /*!< Clip_max_comp_3 Clip_to_negative_for_channel_3*/
    int32_t Clip_max_comp_3;
    /*!< Clip_max_comp_4 Clip_to_negative_for_channel_4*/
    int32_t Clip_max_comp_4;
    /*!< Clip_max_comp_5 Clip_to_negative_for_channel_5*/
    int32_t Clip_max_comp_5;
    /*!< Offset_comp_0 Ofset_value_for_channel_0*/
    int32_t Offset_comp_0;
    /*!< Offset_comp_1 Ofset_value_for_channel_1*/
    int32_t Offset_comp_1;
    /*!< Offset_comp_2 Ofset_value_for_channel_2*/
    int32_t Offset_comp_2;
    /*!< Offset_comp_3 Ofset_value_for_channel_3*/
    int32_t Offset_comp_3;
    /*!< Offset_comp_4 Ofset_value_for_channel_4*/
    int32_t Offset_comp_4;
    /*!< Offset_comp_5 Ofset_value_for_channel_5*/
    int32_t Offset_comp_5;
    /*!< Clip_min_val_0 Clip_min_value_for_channel_0*/
    int32_t Clip_min_val_0;
    /*!< Clip_max_val_0 Clip_max_value_for_channel_0*/
    int32_t Clip_max_val_0;
    /*!< Clip_min_val_1 Clip_min_value_for_channel_1*/
    int32_t Clip_min_val_1;
    /*!< Clip_max_val_1 Clip_max_value_for_channel_1*/
    int32_t Clip_max_val_1;
    /*!< Clip_min_val_2 Clip_min_value_for_channel_2*/
    int32_t Clip_min_val_2;
    /*!< Clip_max_val_2 Clip_max_value_for_channel_2*/
    int32_t Clip_max_val_2;
    /*!< Clip_min_val_3 Clip_min_value_for_channel_3*/
    int32_t Clip_min_val_3;
    /*!< Clip_max_val_3 Clip_max_value_for_channel_3*/
    int32_t Clip_max_val_3;
    /*!< Clip_min_val_4 Clip_min_value_for_channel_4*/
    int32_t Clip_min_val_4;
    /*!< Clip_max_val_4 Clip_max_value_for_channel_4*/
    int32_t Clip_max_val_4;
    /*!< Clip_min_val_5 Clip_min_value_for_channel_5*/
    int32_t Clip_min_val_5;
    /*!< Clip_max_val_5 Clip_max_value_for_channel_5*/
    int32_t Clip_max_val_5;
    /*!< range_reduction_en range_reduction_en*/
    int32_t range_reduction_en;
    /*!< output_resolution bpp of output image. 8, 10 and 12 are valid.*/
    int32_t output_resolution;
    /*!< MSB_alignment_en 6 bit shift left for P010, 4 for P012*/
    int32_t MSB_alignment_en;

} ia_pal_isp_espa_isa_ir_md_t;

/*! \isp struct espa_isa_sis_a
Extended Stream Precsion Adapter
*/
typedef struct
{
    /*!< Shift_l_comp_0 Shif_Left_enable_for_channel_0: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_0;
    /*!< Shift_l_comp_1 Shif_Left_enable_for_channel_1: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_1;
    /*!< Shift_l_comp_2 Shif_Left_enable_for_channel_2: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_2;
    /*!< Shift_l_comp_3 Shif_Left_enable_for_channel_3: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_3;
    /*!< Shift_l_comp_4 Shif_Left_enable_for_channel_4: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_4;
    /*!< Shift_l_comp_5 Shif_Left_enable_for_channel_5: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_5;
    /*!< Shift_val_comp_0 Shif_value_for_channel_0*/
    int32_t Shift_val_comp_0;
    /*!< Shift_val_comp_1 Shif_value_for_channel_1*/
    int32_t Shift_val_comp_1;
    /*!< Shift_val_comp_2 Shif_value_for_channel_2*/
    int32_t Shift_val_comp_2;
    /*!< Shift_val_comp_3 Shif_value_for_channel_3*/
    int32_t Shift_val_comp_3;
    /*!< Shift_val_comp_4 Shif_value_for_channel_4*/
    int32_t Shift_val_comp_4;
    /*!< Shift_val_comp_5 Shif_value_for_channel_5*/
    int32_t Shift_val_comp_5;
    /*!< Clip_min_comp_0 Clip_to_positive_for_channel_0*/
    int32_t Clip_min_comp_0;
    /*!< Clip_min_comp_1 Clip_to_positive_for_channel_1*/
    int32_t Clip_min_comp_1;
    /*!< Clip_min_comp_2 Clip_to_positive_for_channel_2*/
    int32_t Clip_min_comp_2;
    /*!< Clip_min_comp_3 Clip_to_positive_for_channel_3*/
    int32_t Clip_min_comp_3;
    /*!< Clip_min_comp_4 Clip_to_positive_for_channel_4*/
    int32_t Clip_min_comp_4;
    /*!< Clip_min_comp_5 Clip_to_positive_for_channel_5*/
    int32_t Clip_min_comp_5;
    /*!< Clip_max_comp_0 Clip_to_negative_for_channel_0*/
    int32_t Clip_max_comp_0;
    /*!< Clip_max_comp_1 Clip_to_negative_for_channel_1*/
    int32_t Clip_max_comp_1;
    /*!< Clip_max_comp_2 Clip_to_negative_for_channel_2*/
    int32_t Clip_max_comp_2;
    /*!< Clip_max_comp_3 Clip_to_negative_for_channel_3*/
    int32_t Clip_max_comp_3;
    /*!< Clip_max_comp_4 Clip_to_negative_for_channel_4*/
    int32_t Clip_max_comp_4;
    /*!< Clip_max_comp_5 Clip_to_negative_for_channel_5*/
    int32_t Clip_max_comp_5;
    /*!< Offset_comp_0 Ofset_value_for_channel_0*/
    int32_t Offset_comp_0;
    /*!< Offset_comp_1 Ofset_value_for_channel_1*/
    int32_t Offset_comp_1;
    /*!< Offset_comp_2 Ofset_value_for_channel_2*/
    int32_t Offset_comp_2;
    /*!< Offset_comp_3 Ofset_value_for_channel_3*/
    int32_t Offset_comp_3;
    /*!< Offset_comp_4 Ofset_value_for_channel_4*/
    int32_t Offset_comp_4;
    /*!< Offset_comp_5 Ofset_value_for_channel_5*/
    int32_t Offset_comp_5;
    /*!< Clip_min_val_0 Clip_min_value_for_channel_0*/
    int32_t Clip_min_val_0;
    /*!< Clip_max_val_0 Clip_max_value_for_channel_0*/
    int32_t Clip_max_val_0;
    /*!< Clip_min_val_1 Clip_min_value_for_channel_1*/
    int32_t Clip_min_val_1;
    /*!< Clip_max_val_1 Clip_max_value_for_channel_1*/
    int32_t Clip_max_val_1;
    /*!< Clip_min_val_2 Clip_min_value_for_channel_2*/
    int32_t Clip_min_val_2;
    /*!< Clip_max_val_2 Clip_max_value_for_channel_2*/
    int32_t Clip_max_val_2;
    /*!< Clip_min_val_3 Clip_min_value_for_channel_3*/
    int32_t Clip_min_val_3;
    /*!< Clip_max_val_3 Clip_max_value_for_channel_3*/
    int32_t Clip_max_val_3;
    /*!< Clip_min_val_4 Clip_min_value_for_channel_4*/
    int32_t Clip_min_val_4;
    /*!< Clip_max_val_4 Clip_max_value_for_channel_4*/
    int32_t Clip_max_val_4;
    /*!< Clip_min_val_5 Clip_min_value_for_channel_5*/
    int32_t Clip_min_val_5;
    /*!< Clip_max_val_5 Clip_max_value_for_channel_5*/
    int32_t Clip_max_val_5;
    /*!< range_reduction_en range_reduction_en*/
    int32_t range_reduction_en;
    /*!< output_resolution bpp of output image. 8, 10 and 12 are valid.*/
    int32_t output_resolution;
    /*!< MSB_alignment_en 6 bit shift left for P010, 4 for P012*/
    int32_t MSB_alignment_en;

} ia_pal_isp_espa_isa_sis_a_t;

/*! \isp struct espa_isa_sis_b
Extended Stream Precsion Adapter
*/
typedef struct
{
    /*!< Shift_l_comp_0 Shif_Left_enable_for_channel_0: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_0;
    /*!< Shift_l_comp_1 Shif_Left_enable_for_channel_1: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_1;
    /*!< Shift_l_comp_2 Shif_Left_enable_for_channel_2: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_2;
    /*!< Shift_l_comp_3 Shif_Left_enable_for_channel_3: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_3;
    /*!< Shift_l_comp_4 Shif_Left_enable_for_channel_4: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_4;
    /*!< Shift_l_comp_5 Shif_Left_enable_for_channel_5: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_5;
    /*!< Shift_val_comp_0 Shif_value_for_channel_0*/
    int32_t Shift_val_comp_0;
    /*!< Shift_val_comp_1 Shif_value_for_channel_1*/
    int32_t Shift_val_comp_1;
    /*!< Shift_val_comp_2 Shif_value_for_channel_2*/
    int32_t Shift_val_comp_2;
    /*!< Shift_val_comp_3 Shif_value_for_channel_3*/
    int32_t Shift_val_comp_3;
    /*!< Shift_val_comp_4 Shif_value_for_channel_4*/
    int32_t Shift_val_comp_4;
    /*!< Shift_val_comp_5 Shif_value_for_channel_5*/
    int32_t Shift_val_comp_5;
    /*!< Clip_min_comp_0 Clip_to_positive_for_channel_0*/
    int32_t Clip_min_comp_0;
    /*!< Clip_min_comp_1 Clip_to_positive_for_channel_1*/
    int32_t Clip_min_comp_1;
    /*!< Clip_min_comp_2 Clip_to_positive_for_channel_2*/
    int32_t Clip_min_comp_2;
    /*!< Clip_min_comp_3 Clip_to_positive_for_channel_3*/
    int32_t Clip_min_comp_3;
    /*!< Clip_min_comp_4 Clip_to_positive_for_channel_4*/
    int32_t Clip_min_comp_4;
    /*!< Clip_min_comp_5 Clip_to_positive_for_channel_5*/
    int32_t Clip_min_comp_5;
    /*!< Clip_max_comp_0 Clip_to_negative_for_channel_0*/
    int32_t Clip_max_comp_0;
    /*!< Clip_max_comp_1 Clip_to_negative_for_channel_1*/
    int32_t Clip_max_comp_1;
    /*!< Clip_max_comp_2 Clip_to_negative_for_channel_2*/
    int32_t Clip_max_comp_2;
    /*!< Clip_max_comp_3 Clip_to_negative_for_channel_3*/
    int32_t Clip_max_comp_3;
    /*!< Clip_max_comp_4 Clip_to_negative_for_channel_4*/
    int32_t Clip_max_comp_4;
    /*!< Clip_max_comp_5 Clip_to_negative_for_channel_5*/
    int32_t Clip_max_comp_5;
    /*!< Offset_comp_0 Ofset_value_for_channel_0*/
    int32_t Offset_comp_0;
    /*!< Offset_comp_1 Ofset_value_for_channel_1*/
    int32_t Offset_comp_1;
    /*!< Offset_comp_2 Ofset_value_for_channel_2*/
    int32_t Offset_comp_2;
    /*!< Offset_comp_3 Ofset_value_for_channel_3*/
    int32_t Offset_comp_3;
    /*!< Offset_comp_4 Ofset_value_for_channel_4*/
    int32_t Offset_comp_4;
    /*!< Offset_comp_5 Ofset_value_for_channel_5*/
    int32_t Offset_comp_5;
    /*!< Clip_min_val_0 Clip_min_value_for_channel_0*/
    int32_t Clip_min_val_0;
    /*!< Clip_max_val_0 Clip_max_value_for_channel_0*/
    int32_t Clip_max_val_0;
    /*!< Clip_min_val_1 Clip_min_value_for_channel_1*/
    int32_t Clip_min_val_1;
    /*!< Clip_max_val_1 Clip_max_value_for_channel_1*/
    int32_t Clip_max_val_1;
    /*!< Clip_min_val_2 Clip_min_value_for_channel_2*/
    int32_t Clip_min_val_2;
    /*!< Clip_max_val_2 Clip_max_value_for_channel_2*/
    int32_t Clip_max_val_2;
    /*!< Clip_min_val_3 Clip_min_value_for_channel_3*/
    int32_t Clip_min_val_3;
    /*!< Clip_max_val_3 Clip_max_value_for_channel_3*/
    int32_t Clip_max_val_3;
    /*!< Clip_min_val_4 Clip_min_value_for_channel_4*/
    int32_t Clip_min_val_4;
    /*!< Clip_max_val_4 Clip_max_value_for_channel_4*/
    int32_t Clip_max_val_4;
    /*!< Clip_min_val_5 Clip_min_value_for_channel_5*/
    int32_t Clip_min_val_5;
    /*!< Clip_max_val_5 Clip_max_value_for_channel_5*/
    int32_t Clip_max_val_5;
    /*!< range_reduction_en range_reduction_en*/
    int32_t range_reduction_en;
    /*!< output_resolution bpp of output image. 8, 10 and 12 are valid.*/
    int32_t output_resolution;
    /*!< MSB_alignment_en 6 bit shift left for P010, 4 for P012*/
    int32_t MSB_alignment_en;

} ia_pal_isp_espa_isa_sis_b_t;

/*! \isp struct espa_isa_wb
Extended Stream Precsion Adapter
*/
typedef struct
{
    /*!< Shift_l_comp_0 Shif_Left_enable_for_channel_0: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_0;
    /*!< Shift_l_comp_1 Shif_Left_enable_for_channel_1: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_1;
    /*!< Shift_l_comp_2 Shif_Left_enable_for_channel_2: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_2;
    /*!< Shift_l_comp_3 Shif_Left_enable_for_channel_3: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_3;
    /*!< Shift_l_comp_4 Shif_Left_enable_for_channel_4: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_4;
    /*!< Shift_l_comp_5 Shif_Left_enable_for_channel_5: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_5;
    /*!< Shift_val_comp_0 Shif_value_for_channel_0*/
    int32_t Shift_val_comp_0;
    /*!< Shift_val_comp_1 Shif_value_for_channel_1*/
    int32_t Shift_val_comp_1;
    /*!< Shift_val_comp_2 Shif_value_for_channel_2*/
    int32_t Shift_val_comp_2;
    /*!< Shift_val_comp_3 Shif_value_for_channel_3*/
    int32_t Shift_val_comp_3;
    /*!< Shift_val_comp_4 Shif_value_for_channel_4*/
    int32_t Shift_val_comp_4;
    /*!< Shift_val_comp_5 Shif_value_for_channel_5*/
    int32_t Shift_val_comp_5;
    /*!< Clip_min_comp_0 Clip_to_positive_for_channel_0*/
    int32_t Clip_min_comp_0;
    /*!< Clip_min_comp_1 Clip_to_positive_for_channel_1*/
    int32_t Clip_min_comp_1;
    /*!< Clip_min_comp_2 Clip_to_positive_for_channel_2*/
    int32_t Clip_min_comp_2;
    /*!< Clip_min_comp_3 Clip_to_positive_for_channel_3*/
    int32_t Clip_min_comp_3;
    /*!< Clip_min_comp_4 Clip_to_positive_for_channel_4*/
    int32_t Clip_min_comp_4;
    /*!< Clip_min_comp_5 Clip_to_positive_for_channel_5*/
    int32_t Clip_min_comp_5;
    /*!< Clip_max_comp_0 Clip_to_negative_for_channel_0*/
    int32_t Clip_max_comp_0;
    /*!< Clip_max_comp_1 Clip_to_negative_for_channel_1*/
    int32_t Clip_max_comp_1;
    /*!< Clip_max_comp_2 Clip_to_negative_for_channel_2*/
    int32_t Clip_max_comp_2;
    /*!< Clip_max_comp_3 Clip_to_negative_for_channel_3*/
    int32_t Clip_max_comp_3;
    /*!< Clip_max_comp_4 Clip_to_negative_for_channel_4*/
    int32_t Clip_max_comp_4;
    /*!< Clip_max_comp_5 Clip_to_negative_for_channel_5*/
    int32_t Clip_max_comp_5;
    /*!< Offset_comp_0 Ofset_value_for_channel_0*/
    int32_t Offset_comp_0;
    /*!< Offset_comp_1 Ofset_value_for_channel_1*/
    int32_t Offset_comp_1;
    /*!< Offset_comp_2 Ofset_value_for_channel_2*/
    int32_t Offset_comp_2;
    /*!< Offset_comp_3 Ofset_value_for_channel_3*/
    int32_t Offset_comp_3;
    /*!< Offset_comp_4 Ofset_value_for_channel_4*/
    int32_t Offset_comp_4;
    /*!< Offset_comp_5 Ofset_value_for_channel_5*/
    int32_t Offset_comp_5;
    /*!< Clip_min_val_0 Clip_min_value_for_channel_0*/
    int32_t Clip_min_val_0;
    /*!< Clip_max_val_0 Clip_max_value_for_channel_0*/
    int32_t Clip_max_val_0;
    /*!< Clip_min_val_1 Clip_min_value_for_channel_1*/
    int32_t Clip_min_val_1;
    /*!< Clip_max_val_1 Clip_max_value_for_channel_1*/
    int32_t Clip_max_val_1;
    /*!< Clip_min_val_2 Clip_min_value_for_channel_2*/
    int32_t Clip_min_val_2;
    /*!< Clip_max_val_2 Clip_max_value_for_channel_2*/
    int32_t Clip_max_val_2;
    /*!< Clip_min_val_3 Clip_min_value_for_channel_3*/
    int32_t Clip_min_val_3;
    /*!< Clip_max_val_3 Clip_max_value_for_channel_3*/
    int32_t Clip_max_val_3;
    /*!< Clip_min_val_4 Clip_min_value_for_channel_4*/
    int32_t Clip_min_val_4;
    /*!< Clip_max_val_4 Clip_max_value_for_channel_4*/
    int32_t Clip_max_val_4;
    /*!< Clip_min_val_5 Clip_min_value_for_channel_5*/
    int32_t Clip_min_val_5;
    /*!< Clip_max_val_5 Clip_max_value_for_channel_5*/
    int32_t Clip_max_val_5;
    /*!< range_reduction_en range_reduction_en*/
    int32_t range_reduction_en;
    /*!< output_resolution bpp of output image. 8, 10 and 12 are valid.*/
    int32_t output_resolution;
    /*!< MSB_alignment_en 6 bit shift left for P010, 4 for P012*/
    int32_t MSB_alignment_en;

} ia_pal_isp_espa_isa_wb_t;

/*! \isp struct espa_isa_yuv_a
Extended Stream Precsion Adapter
*/
typedef struct
{
    /*!< Shift_l_comp_0 Shif_Left_enable_for_channel_0: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_0;
    /*!< Shift_l_comp_1 Shif_Left_enable_for_channel_1: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_1;
    /*!< Shift_l_comp_2 Shif_Left_enable_for_channel_2: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_2;
    /*!< Shift_l_comp_3 Shif_Left_enable_for_channel_3: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_3;
    /*!< Shift_l_comp_4 Shif_Left_enable_for_channel_4: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_4;
    /*!< Shift_l_comp_5 Shif_Left_enable_for_channel_5: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_5;
    /*!< Shift_val_comp_0 Shif_value_for_channel_0*/
    int32_t Shift_val_comp_0;
    /*!< Shift_val_comp_1 Shif_value_for_channel_1*/
    int32_t Shift_val_comp_1;
    /*!< Shift_val_comp_2 Shif_value_for_channel_2*/
    int32_t Shift_val_comp_2;
    /*!< Shift_val_comp_3 Shif_value_for_channel_3*/
    int32_t Shift_val_comp_3;
    /*!< Shift_val_comp_4 Shif_value_for_channel_4*/
    int32_t Shift_val_comp_4;
    /*!< Shift_val_comp_5 Shif_value_for_channel_5*/
    int32_t Shift_val_comp_5;
    /*!< Clip_min_comp_0 Clip_to_positive_for_channel_0*/
    int32_t Clip_min_comp_0;
    /*!< Clip_min_comp_1 Clip_to_positive_for_channel_1*/
    int32_t Clip_min_comp_1;
    /*!< Clip_min_comp_2 Clip_to_positive_for_channel_2*/
    int32_t Clip_min_comp_2;
    /*!< Clip_min_comp_3 Clip_to_positive_for_channel_3*/
    int32_t Clip_min_comp_3;
    /*!< Clip_min_comp_4 Clip_to_positive_for_channel_4*/
    int32_t Clip_min_comp_4;
    /*!< Clip_min_comp_5 Clip_to_positive_for_channel_5*/
    int32_t Clip_min_comp_5;
    /*!< Clip_max_comp_0 Clip_to_negative_for_channel_0*/
    int32_t Clip_max_comp_0;
    /*!< Clip_max_comp_1 Clip_to_negative_for_channel_1*/
    int32_t Clip_max_comp_1;
    /*!< Clip_max_comp_2 Clip_to_negative_for_channel_2*/
    int32_t Clip_max_comp_2;
    /*!< Clip_max_comp_3 Clip_to_negative_for_channel_3*/
    int32_t Clip_max_comp_3;
    /*!< Clip_max_comp_4 Clip_to_negative_for_channel_4*/
    int32_t Clip_max_comp_4;
    /*!< Clip_max_comp_5 Clip_to_negative_for_channel_5*/
    int32_t Clip_max_comp_5;
    /*!< Offset_comp_0 Ofset_value_for_channel_0*/
    int32_t Offset_comp_0;
    /*!< Offset_comp_1 Ofset_value_for_channel_1*/
    int32_t Offset_comp_1;
    /*!< Offset_comp_2 Ofset_value_for_channel_2*/
    int32_t Offset_comp_2;
    /*!< Offset_comp_3 Ofset_value_for_channel_3*/
    int32_t Offset_comp_3;
    /*!< Offset_comp_4 Ofset_value_for_channel_4*/
    int32_t Offset_comp_4;
    /*!< Offset_comp_5 Ofset_value_for_channel_5*/
    int32_t Offset_comp_5;
    /*!< Clip_min_val_0 Clip_min_value_for_channel_0*/
    int32_t Clip_min_val_0;
    /*!< Clip_max_val_0 Clip_max_value_for_channel_0*/
    int32_t Clip_max_val_0;
    /*!< Clip_min_val_1 Clip_min_value_for_channel_1*/
    int32_t Clip_min_val_1;
    /*!< Clip_max_val_1 Clip_max_value_for_channel_1*/
    int32_t Clip_max_val_1;
    /*!< Clip_min_val_2 Clip_min_value_for_channel_2*/
    int32_t Clip_min_val_2;
    /*!< Clip_max_val_2 Clip_max_value_for_channel_2*/
    int32_t Clip_max_val_2;
    /*!< Clip_min_val_3 Clip_min_value_for_channel_3*/
    int32_t Clip_min_val_3;
    /*!< Clip_max_val_3 Clip_max_value_for_channel_3*/
    int32_t Clip_max_val_3;
    /*!< Clip_min_val_4 Clip_min_value_for_channel_4*/
    int32_t Clip_min_val_4;
    /*!< Clip_max_val_4 Clip_max_value_for_channel_4*/
    int32_t Clip_max_val_4;
    /*!< Clip_min_val_5 Clip_min_value_for_channel_5*/
    int32_t Clip_min_val_5;
    /*!< Clip_max_val_5 Clip_max_value_for_channel_5*/
    int32_t Clip_max_val_5;
    /*!< range_reduction_en range_reduction_en*/
    int32_t range_reduction_en;
    /*!< output_resolution bpp of output image. 8, 10 and 12 are valid.*/
    int32_t output_resolution;
    /*!< MSB_alignment_en 6 bit shift left for P010, 4 for P012*/
    int32_t MSB_alignment_en;

} ia_pal_isp_espa_isa_yuv_a_t;

/*! \isp struct espa_isa_yuv_b
Extended Stream Precsion Adapter
*/
typedef struct
{
    /*!< Shift_l_comp_0 Shif_Left_enable_for_channel_0: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_0;
    /*!< Shift_l_comp_1 Shif_Left_enable_for_channel_1: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_1;
    /*!< Shift_l_comp_2 Shif_Left_enable_for_channel_2: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_2;
    /*!< Shift_l_comp_3 Shif_Left_enable_for_channel_3: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_3;
    /*!< Shift_l_comp_4 Shif_Left_enable_for_channel_4: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_4;
    /*!< Shift_l_comp_5 Shif_Left_enable_for_channel_5: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_5;
    /*!< Shift_val_comp_0 Shif_value_for_channel_0*/
    int32_t Shift_val_comp_0;
    /*!< Shift_val_comp_1 Shif_value_for_channel_1*/
    int32_t Shift_val_comp_1;
    /*!< Shift_val_comp_2 Shif_value_for_channel_2*/
    int32_t Shift_val_comp_2;
    /*!< Shift_val_comp_3 Shif_value_for_channel_3*/
    int32_t Shift_val_comp_3;
    /*!< Shift_val_comp_4 Shif_value_for_channel_4*/
    int32_t Shift_val_comp_4;
    /*!< Shift_val_comp_5 Shif_value_for_channel_5*/
    int32_t Shift_val_comp_5;
    /*!< Clip_min_comp_0 Clip_to_positive_for_channel_0*/
    int32_t Clip_min_comp_0;
    /*!< Clip_min_comp_1 Clip_to_positive_for_channel_1*/
    int32_t Clip_min_comp_1;
    /*!< Clip_min_comp_2 Clip_to_positive_for_channel_2*/
    int32_t Clip_min_comp_2;
    /*!< Clip_min_comp_3 Clip_to_positive_for_channel_3*/
    int32_t Clip_min_comp_3;
    /*!< Clip_min_comp_4 Clip_to_positive_for_channel_4*/
    int32_t Clip_min_comp_4;
    /*!< Clip_min_comp_5 Clip_to_positive_for_channel_5*/
    int32_t Clip_min_comp_5;
    /*!< Clip_max_comp_0 Clip_to_negative_for_channel_0*/
    int32_t Clip_max_comp_0;
    /*!< Clip_max_comp_1 Clip_to_negative_for_channel_1*/
    int32_t Clip_max_comp_1;
    /*!< Clip_max_comp_2 Clip_to_negative_for_channel_2*/
    int32_t Clip_max_comp_2;
    /*!< Clip_max_comp_3 Clip_to_negative_for_channel_3*/
    int32_t Clip_max_comp_3;
    /*!< Clip_max_comp_4 Clip_to_negative_for_channel_4*/
    int32_t Clip_max_comp_4;
    /*!< Clip_max_comp_5 Clip_to_negative_for_channel_5*/
    int32_t Clip_max_comp_5;
    /*!< Offset_comp_0 Ofset_value_for_channel_0*/
    int32_t Offset_comp_0;
    /*!< Offset_comp_1 Ofset_value_for_channel_1*/
    int32_t Offset_comp_1;
    /*!< Offset_comp_2 Ofset_value_for_channel_2*/
    int32_t Offset_comp_2;
    /*!< Offset_comp_3 Ofset_value_for_channel_3*/
    int32_t Offset_comp_3;
    /*!< Offset_comp_4 Ofset_value_for_channel_4*/
    int32_t Offset_comp_4;
    /*!< Offset_comp_5 Ofset_value_for_channel_5*/
    int32_t Offset_comp_5;
    /*!< Clip_min_val_0 Clip_min_value_for_channel_0*/
    int32_t Clip_min_val_0;
    /*!< Clip_max_val_0 Clip_max_value_for_channel_0*/
    int32_t Clip_max_val_0;
    /*!< Clip_min_val_1 Clip_min_value_for_channel_1*/
    int32_t Clip_min_val_1;
    /*!< Clip_max_val_1 Clip_max_value_for_channel_1*/
    int32_t Clip_max_val_1;
    /*!< Clip_min_val_2 Clip_min_value_for_channel_2*/
    int32_t Clip_min_val_2;
    /*!< Clip_max_val_2 Clip_max_value_for_channel_2*/
    int32_t Clip_max_val_2;
    /*!< Clip_min_val_3 Clip_min_value_for_channel_3*/
    int32_t Clip_min_val_3;
    /*!< Clip_max_val_3 Clip_max_value_for_channel_3*/
    int32_t Clip_max_val_3;
    /*!< Clip_min_val_4 Clip_min_value_for_channel_4*/
    int32_t Clip_min_val_4;
    /*!< Clip_max_val_4 Clip_max_value_for_channel_4*/
    int32_t Clip_max_val_4;
    /*!< Clip_min_val_5 Clip_min_value_for_channel_5*/
    int32_t Clip_min_val_5;
    /*!< Clip_max_val_5 Clip_max_value_for_channel_5*/
    int32_t Clip_max_val_5;
    /*!< range_reduction_en range_reduction_en*/
    int32_t range_reduction_en;
    /*!< output_resolution bpp of output image. 8, 10 and 12 are valid.*/
    int32_t output_resolution;
    /*!< MSB_alignment_en 6 bit shift left for P010, 4 for P012*/
    int32_t MSB_alignment_en;

} ia_pal_isp_espa_isa_yuv_b_t;

/*! \isp struct espa_isa_yuv_c
Extended Stream Precsion Adapter
*/
typedef struct
{
    /*!< Shift_l_comp_0 Shif_Left_enable_for_channel_0: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_0;
    /*!< Shift_l_comp_1 Shif_Left_enable_for_channel_1: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_1;
    /*!< Shift_l_comp_2 Shif_Left_enable_for_channel_2: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_2;
    /*!< Shift_l_comp_3 Shif_Left_enable_for_channel_3: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_3;
    /*!< Shift_l_comp_4 Shif_Left_enable_for_channel_4: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_4;
    /*!< Shift_l_comp_5 Shif_Left_enable_for_channel_5: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_5;
    /*!< Shift_val_comp_0 Shif_value_for_channel_0*/
    int32_t Shift_val_comp_0;
    /*!< Shift_val_comp_1 Shif_value_for_channel_1*/
    int32_t Shift_val_comp_1;
    /*!< Shift_val_comp_2 Shif_value_for_channel_2*/
    int32_t Shift_val_comp_2;
    /*!< Shift_val_comp_3 Shif_value_for_channel_3*/
    int32_t Shift_val_comp_3;
    /*!< Shift_val_comp_4 Shif_value_for_channel_4*/
    int32_t Shift_val_comp_4;
    /*!< Shift_val_comp_5 Shif_value_for_channel_5*/
    int32_t Shift_val_comp_5;
    /*!< Clip_min_comp_0 Clip_to_positive_for_channel_0*/
    int32_t Clip_min_comp_0;
    /*!< Clip_min_comp_1 Clip_to_positive_for_channel_1*/
    int32_t Clip_min_comp_1;
    /*!< Clip_min_comp_2 Clip_to_positive_for_channel_2*/
    int32_t Clip_min_comp_2;
    /*!< Clip_min_comp_3 Clip_to_positive_for_channel_3*/
    int32_t Clip_min_comp_3;
    /*!< Clip_min_comp_4 Clip_to_positive_for_channel_4*/
    int32_t Clip_min_comp_4;
    /*!< Clip_min_comp_5 Clip_to_positive_for_channel_5*/
    int32_t Clip_min_comp_5;
    /*!< Clip_max_comp_0 Clip_to_negative_for_channel_0*/
    int32_t Clip_max_comp_0;
    /*!< Clip_max_comp_1 Clip_to_negative_for_channel_1*/
    int32_t Clip_max_comp_1;
    /*!< Clip_max_comp_2 Clip_to_negative_for_channel_2*/
    int32_t Clip_max_comp_2;
    /*!< Clip_max_comp_3 Clip_to_negative_for_channel_3*/
    int32_t Clip_max_comp_3;
    /*!< Clip_max_comp_4 Clip_to_negative_for_channel_4*/
    int32_t Clip_max_comp_4;
    /*!< Clip_max_comp_5 Clip_to_negative_for_channel_5*/
    int32_t Clip_max_comp_5;
    /*!< Offset_comp_0 Ofset_value_for_channel_0*/
    int32_t Offset_comp_0;
    /*!< Offset_comp_1 Ofset_value_for_channel_1*/
    int32_t Offset_comp_1;
    /*!< Offset_comp_2 Ofset_value_for_channel_2*/
    int32_t Offset_comp_2;
    /*!< Offset_comp_3 Ofset_value_for_channel_3*/
    int32_t Offset_comp_3;
    /*!< Offset_comp_4 Ofset_value_for_channel_4*/
    int32_t Offset_comp_4;
    /*!< Offset_comp_5 Ofset_value_for_channel_5*/
    int32_t Offset_comp_5;
    /*!< Clip_min_val_0 Clip_min_value_for_channel_0*/
    int32_t Clip_min_val_0;
    /*!< Clip_max_val_0 Clip_max_value_for_channel_0*/
    int32_t Clip_max_val_0;
    /*!< Clip_min_val_1 Clip_min_value_for_channel_1*/
    int32_t Clip_min_val_1;
    /*!< Clip_max_val_1 Clip_max_value_for_channel_1*/
    int32_t Clip_max_val_1;
    /*!< Clip_min_val_2 Clip_min_value_for_channel_2*/
    int32_t Clip_min_val_2;
    /*!< Clip_max_val_2 Clip_max_value_for_channel_2*/
    int32_t Clip_max_val_2;
    /*!< Clip_min_val_3 Clip_min_value_for_channel_3*/
    int32_t Clip_min_val_3;
    /*!< Clip_max_val_3 Clip_max_value_for_channel_3*/
    int32_t Clip_max_val_3;
    /*!< Clip_min_val_4 Clip_min_value_for_channel_4*/
    int32_t Clip_min_val_4;
    /*!< Clip_max_val_4 Clip_max_value_for_channel_4*/
    int32_t Clip_max_val_4;
    /*!< Clip_min_val_5 Clip_min_value_for_channel_5*/
    int32_t Clip_min_val_5;
    /*!< Clip_max_val_5 Clip_max_value_for_channel_5*/
    int32_t Clip_max_val_5;
    /*!< range_reduction_en range_reduction_en*/
    int32_t range_reduction_en;
    /*!< output_resolution bpp of output image. 8, 10 and 12 are valid.*/
    int32_t output_resolution;
    /*!< MSB_alignment_en 6 bit shift left for P010, 4 for P012*/
    int32_t MSB_alignment_en;

} ia_pal_isp_espa_isa_yuv_c_t;

/*! \isp struct espa_psa_1

*/
typedef struct
{
    /*!< Shift_l_comp_0 Shif_Left_enable_for_channel_0: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_0;
    /*!< Shift_l_comp_1 Shif_Left_enable_for_channel_1: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_1;
    /*!< Shift_l_comp_2 Shif_Left_enable_for_channel_2: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_2;
    /*!< Shift_l_comp_3 Shif_Left_enable_for_channel_3: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_3;
    /*!< Shift_l_comp_4 Shif_Left_enable_for_channel_4: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_4;
    /*!< Shift_l_comp_5 Shif_Left_enable_for_channel_5: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_5;
    /*!< Shift_val_comp_0 Shif_value_for_channel_0*/
    int32_t Shift_val_comp_0;
    /*!< Shift_val_comp_1 Shif_value_for_channel_1*/
    int32_t Shift_val_comp_1;
    /*!< Shift_val_comp_2 Shif_value_for_channel_2*/
    int32_t Shift_val_comp_2;
    /*!< Shift_val_comp_3 Shif_value_for_channel_3*/
    int32_t Shift_val_comp_3;
    /*!< Shift_val_comp_4 Shif_value_for_channel_4*/
    int32_t Shift_val_comp_4;
    /*!< Shift_val_comp_5 Shif_value_for_channel_5*/
    int32_t Shift_val_comp_5;
    /*!< Clip_min_comp_0 Clip_to_positive_for_channel_0*/
    int32_t Clip_min_comp_0;
    /*!< Clip_min_comp_1 Clip_to_positive_for_channel_1*/
    int32_t Clip_min_comp_1;
    /*!< Clip_min_comp_2 Clip_to_positive_for_channel_2*/
    int32_t Clip_min_comp_2;
    /*!< Clip_min_comp_3 Clip_to_positive_for_channel_3*/
    int32_t Clip_min_comp_3;
    /*!< Clip_min_comp_4 Clip_to_positive_for_channel_4*/
    int32_t Clip_min_comp_4;
    /*!< Clip_min_comp_5 Clip_to_positive_for_channel_5*/
    int32_t Clip_min_comp_5;
    /*!< Clip_max_comp_0 Clip_to_negative_for_channel_0*/
    int32_t Clip_max_comp_0;
    /*!< Clip_max_comp_1 Clip_to_negative_for_channel_1*/
    int32_t Clip_max_comp_1;
    /*!< Clip_max_comp_2 Clip_to_negative_for_channel_2*/
    int32_t Clip_max_comp_2;
    /*!< Clip_max_comp_3 Clip_to_negative_for_channel_3*/
    int32_t Clip_max_comp_3;
    /*!< Clip_max_comp_4 Clip_to_negative_for_channel_4*/
    int32_t Clip_max_comp_4;
    /*!< Clip_max_comp_5 Clip_to_negative_for_channel_5*/
    int32_t Clip_max_comp_5;
    /*!< Offset_comp_0 Ofset_value_for_channel_0*/
    int32_t Offset_comp_0;
    /*!< Offset_comp_1 Ofset_value_for_channel_1*/
    int32_t Offset_comp_1;
    /*!< Offset_comp_2 Ofset_value_for_channel_2*/
    int32_t Offset_comp_2;
    /*!< Offset_comp_3 Ofset_value_for_channel_3*/
    int32_t Offset_comp_3;
    /*!< Offset_comp_4 Ofset_value_for_channel_4*/
    int32_t Offset_comp_4;
    /*!< Offset_comp_5 Ofset_value_for_channel_5*/
    int32_t Offset_comp_5;
    /*!< Clip_min_val_0 Clip_min_value_for_channel_0*/
    int32_t Clip_min_val_0;
    /*!< Clip_max_val_0 Clip_max_value_for_channel_0*/
    int32_t Clip_max_val_0;
    /*!< Clip_min_val_1 Clip_min_value_for_channel_1*/
    int32_t Clip_min_val_1;
    /*!< Clip_max_val_1 Clip_max_value_for_channel_1*/
    int32_t Clip_max_val_1;
    /*!< Clip_min_val_2 Clip_min_value_for_channel_2*/
    int32_t Clip_min_val_2;
    /*!< Clip_max_val_2 Clip_max_value_for_channel_2*/
    int32_t Clip_max_val_2;
    /*!< Clip_min_val_3 Clip_min_value_for_channel_3*/
    int32_t Clip_min_val_3;
    /*!< Clip_max_val_3 Clip_max_value_for_channel_3*/
    int32_t Clip_max_val_3;
    /*!< Clip_min_val_4 Clip_min_value_for_channel_4*/
    int32_t Clip_min_val_4;
    /*!< Clip_max_val_4 Clip_max_value_for_channel_4*/
    int32_t Clip_max_val_4;
    /*!< Clip_min_val_5 Clip_min_value_for_channel_5*/
    int32_t Clip_min_val_5;
    /*!< Clip_max_val_5 Clip_max_value_for_channel_5*/
    int32_t Clip_max_val_5;
    /*!< range_reduction_en range_reduction_en*/
    int32_t range_reduction_en;
    /*!< output_resolution bpp of output image. 8, 10 and 12 are valid.*/
    int32_t output_resolution;
    /*!< MSB_alignment_en 6 bit shift left for P010, 4 for P012*/
    int32_t MSB_alignment_en;

} ia_pal_isp_espa_psa_1_t;

/*! \isp struct espa_psa_4

*/
typedef struct
{
    /*!< Shift_l_comp_0 Shif_Left_enable_for_channel_0: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_0;
    /*!< Shift_l_comp_1 Shif_Left_enable_for_channel_1: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_1;
    /*!< Shift_l_comp_2 Shif_Left_enable_for_channel_2: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_2;
    /*!< Shift_l_comp_3 Shif_Left_enable_for_channel_3: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_3;
    /*!< Shift_l_comp_4 Shif_Left_enable_for_channel_4: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_4;
    /*!< Shift_l_comp_5 Shif_Left_enable_for_channel_5: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_5;
    /*!< Shift_val_comp_0 Shif_value_for_channel_0*/
    int32_t Shift_val_comp_0;
    /*!< Shift_val_comp_1 Shif_value_for_channel_1*/
    int32_t Shift_val_comp_1;
    /*!< Shift_val_comp_2 Shif_value_for_channel_2*/
    int32_t Shift_val_comp_2;
    /*!< Shift_val_comp_3 Shif_value_for_channel_3*/
    int32_t Shift_val_comp_3;
    /*!< Shift_val_comp_4 Shif_value_for_channel_4*/
    int32_t Shift_val_comp_4;
    /*!< Shift_val_comp_5 Shif_value_for_channel_5*/
    int32_t Shift_val_comp_5;
    /*!< Clip_min_comp_0 Clip_to_positive_for_channel_0*/
    int32_t Clip_min_comp_0;
    /*!< Clip_min_comp_1 Clip_to_positive_for_channel_1*/
    int32_t Clip_min_comp_1;
    /*!< Clip_min_comp_2 Clip_to_positive_for_channel_2*/
    int32_t Clip_min_comp_2;
    /*!< Clip_min_comp_3 Clip_to_positive_for_channel_3*/
    int32_t Clip_min_comp_3;
    /*!< Clip_min_comp_4 Clip_to_positive_for_channel_4*/
    int32_t Clip_min_comp_4;
    /*!< Clip_min_comp_5 Clip_to_positive_for_channel_5*/
    int32_t Clip_min_comp_5;
    /*!< Clip_max_comp_0 Clip_to_negative_for_channel_0*/
    int32_t Clip_max_comp_0;
    /*!< Clip_max_comp_1 Clip_to_negative_for_channel_1*/
    int32_t Clip_max_comp_1;
    /*!< Clip_max_comp_2 Clip_to_negative_for_channel_2*/
    int32_t Clip_max_comp_2;
    /*!< Clip_max_comp_3 Clip_to_negative_for_channel_3*/
    int32_t Clip_max_comp_3;
    /*!< Clip_max_comp_4 Clip_to_negative_for_channel_4*/
    int32_t Clip_max_comp_4;
    /*!< Clip_max_comp_5 Clip_to_negative_for_channel_5*/
    int32_t Clip_max_comp_5;
    /*!< Offset_comp_0 Ofset_value_for_channel_0*/
    int32_t Offset_comp_0;
    /*!< Offset_comp_1 Ofset_value_for_channel_1*/
    int32_t Offset_comp_1;
    /*!< Offset_comp_2 Ofset_value_for_channel_2*/
    int32_t Offset_comp_2;
    /*!< Offset_comp_3 Ofset_value_for_channel_3*/
    int32_t Offset_comp_3;
    /*!< Offset_comp_4 Ofset_value_for_channel_4*/
    int32_t Offset_comp_4;
    /*!< Offset_comp_5 Ofset_value_for_channel_5*/
    int32_t Offset_comp_5;
    /*!< Clip_min_val_0 Clip_min_value_for_channel_0*/
    int32_t Clip_min_val_0;
    /*!< Clip_max_val_0 Clip_max_value_for_channel_0*/
    int32_t Clip_max_val_0;
    /*!< Clip_min_val_1 Clip_min_value_for_channel_1*/
    int32_t Clip_min_val_1;
    /*!< Clip_max_val_1 Clip_max_value_for_channel_1*/
    int32_t Clip_max_val_1;
    /*!< Clip_min_val_2 Clip_min_value_for_channel_2*/
    int32_t Clip_min_val_2;
    /*!< Clip_max_val_2 Clip_max_value_for_channel_2*/
    int32_t Clip_max_val_2;
    /*!< Clip_min_val_3 Clip_min_value_for_channel_3*/
    int32_t Clip_min_val_3;
    /*!< Clip_max_val_3 Clip_max_value_for_channel_3*/
    int32_t Clip_max_val_3;
    /*!< Clip_min_val_4 Clip_min_value_for_channel_4*/
    int32_t Clip_min_val_4;
    /*!< Clip_max_val_4 Clip_max_value_for_channel_4*/
    int32_t Clip_max_val_4;
    /*!< Clip_min_val_5 Clip_min_value_for_channel_5*/
    int32_t Clip_min_val_5;
    /*!< Clip_max_val_5 Clip_max_value_for_channel_5*/
    int32_t Clip_max_val_5;
    /*!< range_reduction_en range_reduction_en*/
    int32_t range_reduction_en;
    /*!< output_resolution bpp of output image. 8, 10 and 12 are valid.*/
    int32_t output_resolution;
    /*!< MSB_alignment_en 6 bit shift left for P010, 4 for P012*/
    int32_t MSB_alignment_en;

} ia_pal_isp_espa_psa_4_t;

/*! \isp struct espa_psa_5

*/
typedef struct
{
    /*!< Shift_l_comp_0 Shif_Left_enable_for_channel_0: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_0;
    /*!< Shift_l_comp_1 Shif_Left_enable_for_channel_1: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_1;
    /*!< Shift_l_comp_2 Shif_Left_enable_for_channel_2: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_2;
    /*!< Shift_l_comp_3 Shif_Left_enable_for_channel_3: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_3;
    /*!< Shift_l_comp_4 Shif_Left_enable_for_channel_4: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_4;
    /*!< Shift_l_comp_5 Shif_Left_enable_for_channel_5: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_5;
    /*!< Shift_val_comp_0 Shif_value_for_channel_0*/
    int32_t Shift_val_comp_0;
    /*!< Shift_val_comp_1 Shif_value_for_channel_1*/
    int32_t Shift_val_comp_1;
    /*!< Shift_val_comp_2 Shif_value_for_channel_2*/
    int32_t Shift_val_comp_2;
    /*!< Shift_val_comp_3 Shif_value_for_channel_3*/
    int32_t Shift_val_comp_3;
    /*!< Shift_val_comp_4 Shif_value_for_channel_4*/
    int32_t Shift_val_comp_4;
    /*!< Shift_val_comp_5 Shif_value_for_channel_5*/
    int32_t Shift_val_comp_5;
    /*!< Clip_min_comp_0 Clip_to_positive_for_channel_0*/
    int32_t Clip_min_comp_0;
    /*!< Clip_min_comp_1 Clip_to_positive_for_channel_1*/
    int32_t Clip_min_comp_1;
    /*!< Clip_min_comp_2 Clip_to_positive_for_channel_2*/
    int32_t Clip_min_comp_2;
    /*!< Clip_min_comp_3 Clip_to_positive_for_channel_3*/
    int32_t Clip_min_comp_3;
    /*!< Clip_min_comp_4 Clip_to_positive_for_channel_4*/
    int32_t Clip_min_comp_4;
    /*!< Clip_min_comp_5 Clip_to_positive_for_channel_5*/
    int32_t Clip_min_comp_5;
    /*!< Clip_max_comp_0 Clip_to_negative_for_channel_0*/
    int32_t Clip_max_comp_0;
    /*!< Clip_max_comp_1 Clip_to_negative_for_channel_1*/
    int32_t Clip_max_comp_1;
    /*!< Clip_max_comp_2 Clip_to_negative_for_channel_2*/
    int32_t Clip_max_comp_2;
    /*!< Clip_max_comp_3 Clip_to_negative_for_channel_3*/
    int32_t Clip_max_comp_3;
    /*!< Clip_max_comp_4 Clip_to_negative_for_channel_4*/
    int32_t Clip_max_comp_4;
    /*!< Clip_max_comp_5 Clip_to_negative_for_channel_5*/
    int32_t Clip_max_comp_5;
    /*!< Offset_comp_0 Ofset_value_for_channel_0*/
    int32_t Offset_comp_0;
    /*!< Offset_comp_1 Ofset_value_for_channel_1*/
    int32_t Offset_comp_1;
    /*!< Offset_comp_2 Ofset_value_for_channel_2*/
    int32_t Offset_comp_2;
    /*!< Offset_comp_3 Ofset_value_for_channel_3*/
    int32_t Offset_comp_3;
    /*!< Offset_comp_4 Ofset_value_for_channel_4*/
    int32_t Offset_comp_4;
    /*!< Offset_comp_5 Ofset_value_for_channel_5*/
    int32_t Offset_comp_5;
    /*!< Clip_min_val_0 Clip_min_value_for_channel_0*/
    int32_t Clip_min_val_0;
    /*!< Clip_max_val_0 Clip_max_value_for_channel_0*/
    int32_t Clip_max_val_0;
    /*!< Clip_min_val_1 Clip_min_value_for_channel_1*/
    int32_t Clip_min_val_1;
    /*!< Clip_max_val_1 Clip_max_value_for_channel_1*/
    int32_t Clip_max_val_1;
    /*!< Clip_min_val_2 Clip_min_value_for_channel_2*/
    int32_t Clip_min_val_2;
    /*!< Clip_max_val_2 Clip_max_value_for_channel_2*/
    int32_t Clip_max_val_2;
    /*!< Clip_min_val_3 Clip_min_value_for_channel_3*/
    int32_t Clip_min_val_3;
    /*!< Clip_max_val_3 Clip_max_value_for_channel_3*/
    int32_t Clip_max_val_3;
    /*!< Clip_min_val_4 Clip_min_value_for_channel_4*/
    int32_t Clip_min_val_4;
    /*!< Clip_max_val_4 Clip_max_value_for_channel_4*/
    int32_t Clip_max_val_4;
    /*!< Clip_min_val_5 Clip_min_value_for_channel_5*/
    int32_t Clip_min_val_5;
    /*!< Clip_max_val_5 Clip_max_value_for_channel_5*/
    int32_t Clip_max_val_5;
    /*!< range_reduction_en range_reduction_en*/
    int32_t range_reduction_en;
    /*!< output_resolution bpp of output image. 8, 10 and 12 are valid.*/
    int32_t output_resolution;
    /*!< MSB_alignment_en 6 bit shift left for P010, 4 for P012*/
    int32_t MSB_alignment_en;

} ia_pal_isp_espa_psa_5_t;

/*! \isp struct espa_psa_c

*/
typedef struct
{
    /*!< Shift_l_comp_0 Shif_Left_enable_for_channel_0: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_0;
    /*!< Shift_l_comp_1 Shif_Left_enable_for_channel_1: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_1;
    /*!< Shift_l_comp_2 Shif_Left_enable_for_channel_2: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_2;
    /*!< Shift_l_comp_3 Shif_Left_enable_for_channel_3: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_3;
    /*!< Shift_l_comp_4 Shif_Left_enable_for_channel_4: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_4;
    /*!< Shift_l_comp_5 Shif_Left_enable_for_channel_5: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_5;
    /*!< Shift_val_comp_0 Shif_value_for_channel_0*/
    int32_t Shift_val_comp_0;
    /*!< Shift_val_comp_1 Shif_value_for_channel_1*/
    int32_t Shift_val_comp_1;
    /*!< Shift_val_comp_2 Shif_value_for_channel_2*/
    int32_t Shift_val_comp_2;
    /*!< Shift_val_comp_3 Shif_value_for_channel_3*/
    int32_t Shift_val_comp_3;
    /*!< Shift_val_comp_4 Shif_value_for_channel_4*/
    int32_t Shift_val_comp_4;
    /*!< Shift_val_comp_5 Shif_value_for_channel_5*/
    int32_t Shift_val_comp_5;
    /*!< Clip_min_comp_0 Clip_to_positive_for_channel_0*/
    int32_t Clip_min_comp_0;
    /*!< Clip_min_comp_1 Clip_to_positive_for_channel_1*/
    int32_t Clip_min_comp_1;
    /*!< Clip_min_comp_2 Clip_to_positive_for_channel_2*/
    int32_t Clip_min_comp_2;
    /*!< Clip_min_comp_3 Clip_to_positive_for_channel_3*/
    int32_t Clip_min_comp_3;
    /*!< Clip_min_comp_4 Clip_to_positive_for_channel_4*/
    int32_t Clip_min_comp_4;
    /*!< Clip_min_comp_5 Clip_to_positive_for_channel_5*/
    int32_t Clip_min_comp_5;
    /*!< Clip_max_comp_0 Clip_to_negative_for_channel_0*/
    int32_t Clip_max_comp_0;
    /*!< Clip_max_comp_1 Clip_to_negative_for_channel_1*/
    int32_t Clip_max_comp_1;
    /*!< Clip_max_comp_2 Clip_to_negative_for_channel_2*/
    int32_t Clip_max_comp_2;
    /*!< Clip_max_comp_3 Clip_to_negative_for_channel_3*/
    int32_t Clip_max_comp_3;
    /*!< Clip_max_comp_4 Clip_to_negative_for_channel_4*/
    int32_t Clip_max_comp_4;
    /*!< Clip_max_comp_5 Clip_to_negative_for_channel_5*/
    int32_t Clip_max_comp_5;
    /*!< Offset_comp_0 Ofset_value_for_channel_0*/
    int32_t Offset_comp_0;
    /*!< Offset_comp_1 Ofset_value_for_channel_1*/
    int32_t Offset_comp_1;
    /*!< Offset_comp_2 Ofset_value_for_channel_2*/
    int32_t Offset_comp_2;
    /*!< Offset_comp_3 Ofset_value_for_channel_3*/
    int32_t Offset_comp_3;
    /*!< Offset_comp_4 Ofset_value_for_channel_4*/
    int32_t Offset_comp_4;
    /*!< Offset_comp_5 Ofset_value_for_channel_5*/
    int32_t Offset_comp_5;
    /*!< Clip_min_val_0 Clip_min_value_for_channel_0*/
    int32_t Clip_min_val_0;
    /*!< Clip_max_val_0 Clip_max_value_for_channel_0*/
    int32_t Clip_max_val_0;
    /*!< Clip_min_val_1 Clip_min_value_for_channel_1*/
    int32_t Clip_min_val_1;
    /*!< Clip_max_val_1 Clip_max_value_for_channel_1*/
    int32_t Clip_max_val_1;
    /*!< Clip_min_val_2 Clip_min_value_for_channel_2*/
    int32_t Clip_min_val_2;
    /*!< Clip_max_val_2 Clip_max_value_for_channel_2*/
    int32_t Clip_max_val_2;
    /*!< Clip_min_val_3 Clip_min_value_for_channel_3*/
    int32_t Clip_min_val_3;
    /*!< Clip_max_val_3 Clip_max_value_for_channel_3*/
    int32_t Clip_max_val_3;
    /*!< Clip_min_val_4 Clip_min_value_for_channel_4*/
    int32_t Clip_min_val_4;
    /*!< Clip_max_val_4 Clip_max_value_for_channel_4*/
    int32_t Clip_max_val_4;
    /*!< Clip_min_val_5 Clip_min_value_for_channel_5*/
    int32_t Clip_min_val_5;
    /*!< Clip_max_val_5 Clip_max_value_for_channel_5*/
    int32_t Clip_max_val_5;
    /*!< range_reduction_en range_reduction_en*/
    int32_t range_reduction_en;
    /*!< output_resolution bpp of output image. 8, 10 and 12 are valid.*/
    int32_t output_resolution;
    /*!< MSB_alignment_en 6 bit shift left for P010, 4 for P012*/
    int32_t MSB_alignment_en;

} ia_pal_isp_espa_psa_c_t;

/*! \isp struct espa_psa_d

*/
typedef struct
{
    /*!< Shift_l_comp_0 Shif_Left_enable_for_channel_0: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_0;
    /*!< Shift_l_comp_1 Shif_Left_enable_for_channel_1: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_1;
    /*!< Shift_l_comp_2 Shif_Left_enable_for_channel_2: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_2;
    /*!< Shift_l_comp_3 Shif_Left_enable_for_channel_3: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_3;
    /*!< Shift_l_comp_4 Shif_Left_enable_for_channel_4: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_4;
    /*!< Shift_l_comp_5 Shif_Left_enable_for_channel_5: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_5;
    /*!< Shift_val_comp_0 Shif_value_for_channel_0*/
    int32_t Shift_val_comp_0;
    /*!< Shift_val_comp_1 Shif_value_for_channel_1*/
    int32_t Shift_val_comp_1;
    /*!< Shift_val_comp_2 Shif_value_for_channel_2*/
    int32_t Shift_val_comp_2;
    /*!< Shift_val_comp_3 Shif_value_for_channel_3*/
    int32_t Shift_val_comp_3;
    /*!< Shift_val_comp_4 Shif_value_for_channel_4*/
    int32_t Shift_val_comp_4;
    /*!< Shift_val_comp_5 Shif_value_for_channel_5*/
    int32_t Shift_val_comp_5;
    /*!< Clip_min_comp_0 Clip_to_positive_for_channel_0*/
    int32_t Clip_min_comp_0;
    /*!< Clip_min_comp_1 Clip_to_positive_for_channel_1*/
    int32_t Clip_min_comp_1;
    /*!< Clip_min_comp_2 Clip_to_positive_for_channel_2*/
    int32_t Clip_min_comp_2;
    /*!< Clip_min_comp_3 Clip_to_positive_for_channel_3*/
    int32_t Clip_min_comp_3;
    /*!< Clip_min_comp_4 Clip_to_positive_for_channel_4*/
    int32_t Clip_min_comp_4;
    /*!< Clip_min_comp_5 Clip_to_positive_for_channel_5*/
    int32_t Clip_min_comp_5;
    /*!< Clip_max_comp_0 Clip_to_negative_for_channel_0*/
    int32_t Clip_max_comp_0;
    /*!< Clip_max_comp_1 Clip_to_negative_for_channel_1*/
    int32_t Clip_max_comp_1;
    /*!< Clip_max_comp_2 Clip_to_negative_for_channel_2*/
    int32_t Clip_max_comp_2;
    /*!< Clip_max_comp_3 Clip_to_negative_for_channel_3*/
    int32_t Clip_max_comp_3;
    /*!< Clip_max_comp_4 Clip_to_negative_for_channel_4*/
    int32_t Clip_max_comp_4;
    /*!< Clip_max_comp_5 Clip_to_negative_for_channel_5*/
    int32_t Clip_max_comp_5;
    /*!< Offset_comp_0 Ofset_value_for_channel_0*/
    int32_t Offset_comp_0;
    /*!< Offset_comp_1 Ofset_value_for_channel_1*/
    int32_t Offset_comp_1;
    /*!< Offset_comp_2 Ofset_value_for_channel_2*/
    int32_t Offset_comp_2;
    /*!< Offset_comp_3 Ofset_value_for_channel_3*/
    int32_t Offset_comp_3;
    /*!< Offset_comp_4 Ofset_value_for_channel_4*/
    int32_t Offset_comp_4;
    /*!< Offset_comp_5 Ofset_value_for_channel_5*/
    int32_t Offset_comp_5;
    /*!< Clip_min_val_0 Clip_min_value_for_channel_0*/
    int32_t Clip_min_val_0;
    /*!< Clip_max_val_0 Clip_max_value_for_channel_0*/
    int32_t Clip_max_val_0;
    /*!< Clip_min_val_1 Clip_min_value_for_channel_1*/
    int32_t Clip_min_val_1;
    /*!< Clip_max_val_1 Clip_max_value_for_channel_1*/
    int32_t Clip_max_val_1;
    /*!< Clip_min_val_2 Clip_min_value_for_channel_2*/
    int32_t Clip_min_val_2;
    /*!< Clip_max_val_2 Clip_max_value_for_channel_2*/
    int32_t Clip_max_val_2;
    /*!< Clip_min_val_3 Clip_min_value_for_channel_3*/
    int32_t Clip_min_val_3;
    /*!< Clip_max_val_3 Clip_max_value_for_channel_3*/
    int32_t Clip_max_val_3;
    /*!< Clip_min_val_4 Clip_min_value_for_channel_4*/
    int32_t Clip_min_val_4;
    /*!< Clip_max_val_4 Clip_max_value_for_channel_4*/
    int32_t Clip_max_val_4;
    /*!< Clip_min_val_5 Clip_min_value_for_channel_5*/
    int32_t Clip_min_val_5;
    /*!< Clip_max_val_5 Clip_max_value_for_channel_5*/
    int32_t Clip_max_val_5;
    /*!< range_reduction_en range_reduction_en*/
    int32_t range_reduction_en;
    /*!< output_resolution bpp of output image. 8, 10 and 12 are valid.*/
    int32_t output_resolution;
    /*!< MSB_alignment_en 6 bit shift left for P010, 4 for P012*/
    int32_t MSB_alignment_en;

} ia_pal_isp_espa_psa_d_t;

/*! \isp struct espa_psa_e

*/
typedef struct
{
    /*!< Shift_l_comp_0 Shif_Left_enable_for_channel_0: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_0;
    /*!< Shift_l_comp_1 Shif_Left_enable_for_channel_1: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_1;
    /*!< Shift_l_comp_2 Shif_Left_enable_for_channel_2: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_2;
    /*!< Shift_l_comp_3 Shif_Left_enable_for_channel_3: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_3;
    /*!< Shift_l_comp_4 Shif_Left_enable_for_channel_4: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_4;
    /*!< Shift_l_comp_5 Shif_Left_enable_for_channel_5: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_5;
    /*!< Shift_val_comp_0 Shif_value_for_channel_0*/
    int32_t Shift_val_comp_0;
    /*!< Shift_val_comp_1 Shif_value_for_channel_1*/
    int32_t Shift_val_comp_1;
    /*!< Shift_val_comp_2 Shif_value_for_channel_2*/
    int32_t Shift_val_comp_2;
    /*!< Shift_val_comp_3 Shif_value_for_channel_3*/
    int32_t Shift_val_comp_3;
    /*!< Shift_val_comp_4 Shif_value_for_channel_4*/
    int32_t Shift_val_comp_4;
    /*!< Shift_val_comp_5 Shif_value_for_channel_5*/
    int32_t Shift_val_comp_5;
    /*!< Clip_min_comp_0 Clip_to_positive_for_channel_0*/
    int32_t Clip_min_comp_0;
    /*!< Clip_min_comp_1 Clip_to_positive_for_channel_1*/
    int32_t Clip_min_comp_1;
    /*!< Clip_min_comp_2 Clip_to_positive_for_channel_2*/
    int32_t Clip_min_comp_2;
    /*!< Clip_min_comp_3 Clip_to_positive_for_channel_3*/
    int32_t Clip_min_comp_3;
    /*!< Clip_min_comp_4 Clip_to_positive_for_channel_4*/
    int32_t Clip_min_comp_4;
    /*!< Clip_min_comp_5 Clip_to_positive_for_channel_5*/
    int32_t Clip_min_comp_5;
    /*!< Clip_max_comp_0 Clip_to_negative_for_channel_0*/
    int32_t Clip_max_comp_0;
    /*!< Clip_max_comp_1 Clip_to_negative_for_channel_1*/
    int32_t Clip_max_comp_1;
    /*!< Clip_max_comp_2 Clip_to_negative_for_channel_2*/
    int32_t Clip_max_comp_2;
    /*!< Clip_max_comp_3 Clip_to_negative_for_channel_3*/
    int32_t Clip_max_comp_3;
    /*!< Clip_max_comp_4 Clip_to_negative_for_channel_4*/
    int32_t Clip_max_comp_4;
    /*!< Clip_max_comp_5 Clip_to_negative_for_channel_5*/
    int32_t Clip_max_comp_5;
    /*!< Offset_comp_0 Ofset_value_for_channel_0*/
    int32_t Offset_comp_0;
    /*!< Offset_comp_1 Ofset_value_for_channel_1*/
    int32_t Offset_comp_1;
    /*!< Offset_comp_2 Ofset_value_for_channel_2*/
    int32_t Offset_comp_2;
    /*!< Offset_comp_3 Ofset_value_for_channel_3*/
    int32_t Offset_comp_3;
    /*!< Offset_comp_4 Ofset_value_for_channel_4*/
    int32_t Offset_comp_4;
    /*!< Offset_comp_5 Ofset_value_for_channel_5*/
    int32_t Offset_comp_5;
    /*!< Clip_min_val_0 Clip_min_value_for_channel_0*/
    int32_t Clip_min_val_0;
    /*!< Clip_max_val_0 Clip_max_value_for_channel_0*/
    int32_t Clip_max_val_0;
    /*!< Clip_min_val_1 Clip_min_value_for_channel_1*/
    int32_t Clip_min_val_1;
    /*!< Clip_max_val_1 Clip_max_value_for_channel_1*/
    int32_t Clip_max_val_1;
    /*!< Clip_min_val_2 Clip_min_value_for_channel_2*/
    int32_t Clip_min_val_2;
    /*!< Clip_max_val_2 Clip_max_value_for_channel_2*/
    int32_t Clip_max_val_2;
    /*!< Clip_min_val_3 Clip_min_value_for_channel_3*/
    int32_t Clip_min_val_3;
    /*!< Clip_max_val_3 Clip_max_value_for_channel_3*/
    int32_t Clip_max_val_3;
    /*!< Clip_min_val_4 Clip_min_value_for_channel_4*/
    int32_t Clip_min_val_4;
    /*!< Clip_max_val_4 Clip_max_value_for_channel_4*/
    int32_t Clip_max_val_4;
    /*!< Clip_min_val_5 Clip_min_value_for_channel_5*/
    int32_t Clip_min_val_5;
    /*!< Clip_max_val_5 Clip_max_value_for_channel_5*/
    int32_t Clip_max_val_5;
    /*!< range_reduction_en range_reduction_en*/
    int32_t range_reduction_en;
    /*!< output_resolution bpp of output image. 8, 10 and 12 are valid.*/
    int32_t output_resolution;
    /*!< MSB_alignment_en 6 bit shift left for P010, 4 for P012*/
    int32_t MSB_alignment_en;

} ia_pal_isp_espa_psa_e_t;

/*! \isp struct espa_psa_f
Extended Stream Precsion Adapter
*/
typedef struct
{
    /*!< Shift_l_comp_0 Shif_Left_enable_for_channel_0: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_0;
    /*!< Shift_l_comp_1 Shif_Left_enable_for_channel_1: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_1;
    /*!< Shift_l_comp_2 Shif_Left_enable_for_channel_2: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_2;
    /*!< Shift_l_comp_3 Shif_Left_enable_for_channel_3: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_3;
    /*!< Shift_l_comp_4 Shif_Left_enable_for_channel_4: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_4;
    /*!< Shift_l_comp_5 Shif_Left_enable_for_channel_5: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_5;
    /*!< Shift_val_comp_0 Shif_value_for_channel_0*/
    int32_t Shift_val_comp_0;
    /*!< Shift_val_comp_1 Shif_value_for_channel_1*/
    int32_t Shift_val_comp_1;
    /*!< Shift_val_comp_2 Shif_value_for_channel_2*/
    int32_t Shift_val_comp_2;
    /*!< Shift_val_comp_3 Shif_value_for_channel_3*/
    int32_t Shift_val_comp_3;
    /*!< Shift_val_comp_4 Shif_value_for_channel_4*/
    int32_t Shift_val_comp_4;
    /*!< Shift_val_comp_5 Shif_value_for_channel_5*/
    int32_t Shift_val_comp_5;
    /*!< Clip_min_comp_0 Clip_to_positive_for_channel_0*/
    int32_t Clip_min_comp_0;
    /*!< Clip_min_comp_1 Clip_to_positive_for_channel_1*/
    int32_t Clip_min_comp_1;
    /*!< Clip_min_comp_2 Clip_to_positive_for_channel_2*/
    int32_t Clip_min_comp_2;
    /*!< Clip_min_comp_3 Clip_to_positive_for_channel_3*/
    int32_t Clip_min_comp_3;
    /*!< Clip_min_comp_4 Clip_to_positive_for_channel_4*/
    int32_t Clip_min_comp_4;
    /*!< Clip_min_comp_5 Clip_to_positive_for_channel_5*/
    int32_t Clip_min_comp_5;
    /*!< Clip_max_comp_0 Clip_to_negative_for_channel_0*/
    int32_t Clip_max_comp_0;
    /*!< Clip_max_comp_1 Clip_to_negative_for_channel_1*/
    int32_t Clip_max_comp_1;
    /*!< Clip_max_comp_2 Clip_to_negative_for_channel_2*/
    int32_t Clip_max_comp_2;
    /*!< Clip_max_comp_3 Clip_to_negative_for_channel_3*/
    int32_t Clip_max_comp_3;
    /*!< Clip_max_comp_4 Clip_to_negative_for_channel_4*/
    int32_t Clip_max_comp_4;
    /*!< Clip_max_comp_5 Clip_to_negative_for_channel_5*/
    int32_t Clip_max_comp_5;
    /*!< Offset_comp_0 Ofset_value_for_channel_0*/
    int32_t Offset_comp_0;
    /*!< Offset_comp_1 Ofset_value_for_channel_1*/
    int32_t Offset_comp_1;
    /*!< Offset_comp_2 Ofset_value_for_channel_2*/
    int32_t Offset_comp_2;
    /*!< Offset_comp_3 Ofset_value_for_channel_3*/
    int32_t Offset_comp_3;
    /*!< Offset_comp_4 Ofset_value_for_channel_4*/
    int32_t Offset_comp_4;
    /*!< Offset_comp_5 Ofset_value_for_channel_5*/
    int32_t Offset_comp_5;
    /*!< Clip_min_val_0 Clip_min_value_for_channel_0*/
    int32_t Clip_min_val_0;
    /*!< Clip_max_val_0 Clip_max_value_for_channel_0*/
    int32_t Clip_max_val_0;
    /*!< Clip_min_val_1 Clip_min_value_for_channel_1*/
    int32_t Clip_min_val_1;
    /*!< Clip_max_val_1 Clip_max_value_for_channel_1*/
    int32_t Clip_max_val_1;
    /*!< Clip_min_val_2 Clip_min_value_for_channel_2*/
    int32_t Clip_min_val_2;
    /*!< Clip_max_val_2 Clip_max_value_for_channel_2*/
    int32_t Clip_max_val_2;
    /*!< Clip_min_val_3 Clip_min_value_for_channel_3*/
    int32_t Clip_min_val_3;
    /*!< Clip_max_val_3 Clip_max_value_for_channel_3*/
    int32_t Clip_max_val_3;
    /*!< Clip_min_val_4 Clip_min_value_for_channel_4*/
    int32_t Clip_min_val_4;
    /*!< Clip_max_val_4 Clip_max_value_for_channel_4*/
    int32_t Clip_max_val_4;
    /*!< Clip_min_val_5 Clip_min_value_for_channel_5*/
    int32_t Clip_min_val_5;
    /*!< Clip_max_val_5 Clip_max_value_for_channel_5*/
    int32_t Clip_max_val_5;
    /*!< range_reduction_en range_reduction_en*/
    int32_t range_reduction_en;
    /*!< output_resolution bpp of output image. 8, 10 and 12 are valid.*/
    int32_t output_resolution;
    /*!< MSB_alignment_en 6 bit shift left for P010, 4 for P012*/
    int32_t MSB_alignment_en;

} ia_pal_isp_espa_psa_f_t;

/*! \isp struct espa_psa_g

*/
typedef struct
{
    /*!< Shift_l_comp_0 Shif_Left_enable_for_channel_0: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_0;
    /*!< Shift_l_comp_1 Shif_Left_enable_for_channel_1: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_1;
    /*!< Shift_l_comp_2 Shif_Left_enable_for_channel_2: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_2;
    /*!< Shift_l_comp_3 Shif_Left_enable_for_channel_3: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_3;
    /*!< Shift_l_comp_4 Shif_Left_enable_for_channel_4: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_4;
    /*!< Shift_l_comp_5 Shif_Left_enable_for_channel_5: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_5;
    /*!< Shift_val_comp_0 Shif_value_for_channel_0*/
    int32_t Shift_val_comp_0;
    /*!< Shift_val_comp_1 Shif_value_for_channel_1*/
    int32_t Shift_val_comp_1;
    /*!< Shift_val_comp_2 Shif_value_for_channel_2*/
    int32_t Shift_val_comp_2;
    /*!< Shift_val_comp_3 Shif_value_for_channel_3*/
    int32_t Shift_val_comp_3;
    /*!< Shift_val_comp_4 Shif_value_for_channel_4*/
    int32_t Shift_val_comp_4;
    /*!< Shift_val_comp_5 Shif_value_for_channel_5*/
    int32_t Shift_val_comp_5;
    /*!< Clip_min_comp_0 Clip_to_positive_for_channel_0*/
    int32_t Clip_min_comp_0;
    /*!< Clip_min_comp_1 Clip_to_positive_for_channel_1*/
    int32_t Clip_min_comp_1;
    /*!< Clip_min_comp_2 Clip_to_positive_for_channel_2*/
    int32_t Clip_min_comp_2;
    /*!< Clip_min_comp_3 Clip_to_positive_for_channel_3*/
    int32_t Clip_min_comp_3;
    /*!< Clip_min_comp_4 Clip_to_positive_for_channel_4*/
    int32_t Clip_min_comp_4;
    /*!< Clip_min_comp_5 Clip_to_positive_for_channel_5*/
    int32_t Clip_min_comp_5;
    /*!< Clip_max_comp_0 Clip_to_negative_for_channel_0*/
    int32_t Clip_max_comp_0;
    /*!< Clip_max_comp_1 Clip_to_negative_for_channel_1*/
    int32_t Clip_max_comp_1;
    /*!< Clip_max_comp_2 Clip_to_negative_for_channel_2*/
    int32_t Clip_max_comp_2;
    /*!< Clip_max_comp_3 Clip_to_negative_for_channel_3*/
    int32_t Clip_max_comp_3;
    /*!< Clip_max_comp_4 Clip_to_negative_for_channel_4*/
    int32_t Clip_max_comp_4;
    /*!< Clip_max_comp_5 Clip_to_negative_for_channel_5*/
    int32_t Clip_max_comp_5;
    /*!< Offset_comp_0 Ofset_value_for_channel_0*/
    int32_t Offset_comp_0;
    /*!< Offset_comp_1 Ofset_value_for_channel_1*/
    int32_t Offset_comp_1;
    /*!< Offset_comp_2 Ofset_value_for_channel_2*/
    int32_t Offset_comp_2;
    /*!< Offset_comp_3 Ofset_value_for_channel_3*/
    int32_t Offset_comp_3;
    /*!< Offset_comp_4 Ofset_value_for_channel_4*/
    int32_t Offset_comp_4;
    /*!< Offset_comp_5 Ofset_value_for_channel_5*/
    int32_t Offset_comp_5;
    /*!< Clip_min_val_0 Clip_min_value_for_channel_0*/
    int32_t Clip_min_val_0;
    /*!< Clip_max_val_0 Clip_max_value_for_channel_0*/
    int32_t Clip_max_val_0;
    /*!< Clip_min_val_1 Clip_min_value_for_channel_1*/
    int32_t Clip_min_val_1;
    /*!< Clip_max_val_1 Clip_max_value_for_channel_1*/
    int32_t Clip_max_val_1;
    /*!< Clip_min_val_2 Clip_min_value_for_channel_2*/
    int32_t Clip_min_val_2;
    /*!< Clip_max_val_2 Clip_max_value_for_channel_2*/
    int32_t Clip_max_val_2;
    /*!< Clip_min_val_3 Clip_min_value_for_channel_3*/
    int32_t Clip_min_val_3;
    /*!< Clip_max_val_3 Clip_max_value_for_channel_3*/
    int32_t Clip_max_val_3;
    /*!< Clip_min_val_4 Clip_min_value_for_channel_4*/
    int32_t Clip_min_val_4;
    /*!< Clip_max_val_4 Clip_max_value_for_channel_4*/
    int32_t Clip_max_val_4;
    /*!< Clip_min_val_5 Clip_min_value_for_channel_5*/
    int32_t Clip_min_val_5;
    /*!< Clip_max_val_5 Clip_max_value_for_channel_5*/
    int32_t Clip_max_val_5;
    /*!< range_reduction_en range_reduction_en*/
    int32_t range_reduction_en;
    /*!< output_resolution bpp of output image. 8, 10 and 12 are valid.*/
    int32_t output_resolution;
    /*!< MSB_alignment_en 6 bit shift left for P010, 4 for P012*/
    int32_t MSB_alignment_en;

} ia_pal_isp_espa_psa_g_t;

/*! \isp struct espa_psa_h

*/
typedef struct
{
    /*!< Shift_l_comp_0 Shif_Left_enable_for_channel_0: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_0;
    /*!< Shift_l_comp_1 Shif_Left_enable_for_channel_1: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_1;
    /*!< Shift_l_comp_2 Shif_Left_enable_for_channel_2: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_2;
    /*!< Shift_l_comp_3 Shif_Left_enable_for_channel_3: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_3;
    /*!< Shift_l_comp_4 Shif_Left_enable_for_channel_4: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_4;
    /*!< Shift_l_comp_5 Shif_Left_enable_for_channel_5: 0 -shift right with round, 1- shift left*/
    int32_t Shift_l_comp_5;
    /*!< Shift_val_comp_0 Shif_value_for_channel_0*/
    int32_t Shift_val_comp_0;
    /*!< Shift_val_comp_1 Shif_value_for_channel_1*/
    int32_t Shift_val_comp_1;
    /*!< Shift_val_comp_2 Shif_value_for_channel_2*/
    int32_t Shift_val_comp_2;
    /*!< Shift_val_comp_3 Shif_value_for_channel_3*/
    int32_t Shift_val_comp_3;
    /*!< Shift_val_comp_4 Shif_value_for_channel_4*/
    int32_t Shift_val_comp_4;
    /*!< Shift_val_comp_5 Shif_value_for_channel_5*/
    int32_t Shift_val_comp_5;
    /*!< Clip_min_comp_0 Clip_to_positive_for_channel_0*/
    int32_t Clip_min_comp_0;
    /*!< Clip_min_comp_1 Clip_to_positive_for_channel_1*/
    int32_t Clip_min_comp_1;
    /*!< Clip_min_comp_2 Clip_to_positive_for_channel_2*/
    int32_t Clip_min_comp_2;
    /*!< Clip_min_comp_3 Clip_to_positive_for_channel_3*/
    int32_t Clip_min_comp_3;
    /*!< Clip_min_comp_4 Clip_to_positive_for_channel_4*/
    int32_t Clip_min_comp_4;
    /*!< Clip_min_comp_5 Clip_to_positive_for_channel_5*/
    int32_t Clip_min_comp_5;
    /*!< Clip_max_comp_0 Clip_to_negative_for_channel_0*/
    int32_t Clip_max_comp_0;
    /*!< Clip_max_comp_1 Clip_to_negative_for_channel_1*/
    int32_t Clip_max_comp_1;
    /*!< Clip_max_comp_2 Clip_to_negative_for_channel_2*/
    int32_t Clip_max_comp_2;
    /*!< Clip_max_comp_3 Clip_to_negative_for_channel_3*/
    int32_t Clip_max_comp_3;
    /*!< Clip_max_comp_4 Clip_to_negative_for_channel_4*/
    int32_t Clip_max_comp_4;
    /*!< Clip_max_comp_5 Clip_to_negative_for_channel_5*/
    int32_t Clip_max_comp_5;
    /*!< Offset_comp_0 Ofset_value_for_channel_0*/
    int32_t Offset_comp_0;
    /*!< Offset_comp_1 Ofset_value_for_channel_1*/
    int32_t Offset_comp_1;
    /*!< Offset_comp_2 Ofset_value_for_channel_2*/
    int32_t Offset_comp_2;
    /*!< Offset_comp_3 Ofset_value_for_channel_3*/
    int32_t Offset_comp_3;
    /*!< Offset_comp_4 Ofset_value_for_channel_4*/
    int32_t Offset_comp_4;
    /*!< Offset_comp_5 Ofset_value_for_channel_5*/
    int32_t Offset_comp_5;
    /*!< Clip_min_val_0 Clip_min_value_for_channel_0*/
    int32_t Clip_min_val_0;
    /*!< Clip_max_val_0 Clip_max_value_for_channel_0*/
    int32_t Clip_max_val_0;
    /*!< Clip_min_val_1 Clip_min_value_for_channel_1*/
    int32_t Clip_min_val_1;
    /*!< Clip_max_val_1 Clip_max_value_for_channel_1*/
    int32_t Clip_max_val_1;
    /*!< Clip_min_val_2 Clip_min_value_for_channel_2*/
    int32_t Clip_min_val_2;
    /*!< Clip_max_val_2 Clip_max_value_for_channel_2*/
    int32_t Clip_max_val_2;
    /*!< Clip_min_val_3 Clip_min_value_for_channel_3*/
    int32_t Clip_min_val_3;
    /*!< Clip_max_val_3 Clip_max_value_for_channel_3*/
    int32_t Clip_max_val_3;
    /*!< Clip_min_val_4 Clip_min_value_for_channel_4*/
    int32_t Clip_min_val_4;
    /*!< Clip_max_val_4 Clip_max_value_for_channel_4*/
    int32_t Clip_max_val_4;
    /*!< Clip_min_val_5 Clip_min_value_for_channel_5*/
    int32_t Clip_min_val_5;
    /*!< Clip_max_val_5 Clip_max_value_for_channel_5*/
    int32_t Clip_max_val_5;
    /*!< range_reduction_en range_reduction_en*/
    int32_t range_reduction_en;
    /*!< output_resolution bpp of output image. 8, 10 and 12 are valid.*/
    int32_t output_resolution;
    /*!< MSB_alignment_en 6 bit shift left for P010, 4 for P012*/
    int32_t MSB_alignment_en;

} ia_pal_isp_espa_psa_h_t;

/*! \isp struct exy

*/
typedef struct
{
    /*!< bypass Bypass filter*/
    int32_t bypass;
    /*!< Coef[2] filter coefficients*/
    int32_t Coef[2];
    /*!< NS_shift shifting noise stream to the relevant range*/
    int32_t NS_shift;

} ia_pal_isp_exy_t;

/*! \isp struct fr_grid_1_0
FR Statistics
*/
typedef struct
{
    /*!< grid_width represents number of horizontal grid cells*/
    int32_t grid_width;
    /*!< grid_height represents number of vertical grid cells*/
    int32_t grid_height;
    /*!< block_width Log2 the width of each grid cell (8,16,32,64,128,256)*/
    int32_t block_width;
    /*!< block_height Log2 the height of each grid cell (8,16,32,64,128,256)*/
    int32_t block_height;
    /*!< y_fr_en 0: FF will not write to the Y  array; 1: FF will write  to the Y  array*/
    int32_t y_fr_en;
    /*!< x_start X top left corner of the grid*/
    int32_t x_start;
    /*!< y_start Y top left corner of the grid*/
    int32_t y_start;
    /*!< x_end X bottom right corner of the grid*/
    int32_t x_end;
    /*!< y_end Y bottom right corner of the grid*/
    int32_t y_end;
    /*!< shftr_val_x[4] Log2(num pixels of estimated colour component in a block). The binding as follows: m_ShftR_val_Y00 = shftr_val_x[0]; m_ShftR_val_Y01 = shftr_val_x[1];m_ShftR_val_Y10 = shftr_val_x[2];m_ShftR_val_Y11 = shftr_val_x[3];*/
    int32_t shftr_val_x[4];
    /*!< gx_0[4] gx0 Y_calc contribution ratio for Pat_ij*/
    int32_t gx_0[4];
    /*!< gx_1[4] gx1 Y_calc contribution ratio for Pat_ij*/
    int32_t gx_1[4];
    /*!< gx_2[4] gx2 Y_calc contribution ratio for Pat_ij*/
    int32_t gx_2[4];
    /*!< gx_3[4] gx3 Y_calc contribution ratio for Pat_ij*/
    int32_t gx_3[4];
    /*!< mask_y0 selecting the relevant pixels for Y0; bit k = row * 4 + column*/
    int32_t mask_y0;
    /*!< mask_y1 selecting the relevant pixels for Y1; bit k = row * 4 + column*/
    int32_t mask_y1;
    /*!< oe_y0 output enable for Y0; bit k corresponds to row * 2 + column*/
    int32_t oe_y0;
    /*!< oe_y1 output enable for Y1; bit k corresponds to row * 2 + column*/
    int32_t oe_y1;
    /*!< on_x_y0[4] Y0 estimation normalization (00, 01, 10, 11)*/
    int32_t on_x_y0[4];
    /*!< on_x_y1[4] Y1 estimation normalization (00, 01, 10, 11)*/
    int32_t on_x_y1[4];
    /*!< y00_filter_coeff[6] filter coefficients for Y00 (A1, A2, A3, A4, A5, A6)*/
    int32_t y00_filter_coeff[6];
    /*!< y00_filter_sign_vec sign vector for Y00*/
    int32_t y00_filter_sign_vec;
    /*!< y01_filter_coeff[6] filter coefficients for Y01 (A1, A2, A3, A4, A5, A6)*/
    int32_t y01_filter_coeff[6];
    /*!< y01_filter_sign_vec sign vector for Y01*/
    int32_t y01_filter_sign_vec;
    /*!< y10_filter_coeff[6] filter coefficients for Y10 (A1, A2, A3, A4, A5, A6)*/
    int32_t y10_filter_coeff[6];
    /*!< y10_filter_sign_vec sign vector for Y10*/
    int32_t y10_filter_sign_vec;
    /*!< y11_filter_coeff[6] filter coefficients for Y11 (A1, A2, A3, A4, A5, A6)*/
    int32_t y11_filter_coeff[6];
    /*!< y11_filter_sign_vec sign vector for Y11*/
    int32_t y11_filter_sign_vec;
    /*!< nf_x[4] Filter response normalization factors for Y00, Y01, Y10, Y11*/
    int32_t nf_x[4];
    /*!< sensor_mode Sensor mode 0: 1x1,  1: 2x2, 2: 4x4*/
    int32_t sensor_mode;
    /*!< downscaling_factor Downscaling factor 0: 1x, 1: 2x, 2: 4x*/
    int32_t downscaling_factor;
    /*!< y00_blending_weight Median filter weight for Y00*/
    int32_t y00_blending_weight;
    /*!< y01_blending_weight Median filter weight for Y01*/
    int32_t y01_blending_weight;
    /*!< y10_blending_weight Median filter weight for Y10*/
    int32_t y10_blending_weight;
    /*!< y11_blending_weight Median filter weight for Y11*/
    int32_t y11_blending_weight;

} ia_pal_isp_fr_grid_1_0_t;

/*! \isp struct gammastar_1
Initial Gamma* filter
*/
typedef struct
{
    /*!< gamma_star_en Bypass filter*/
    int32_t gamma_star_en;
    /*!< crop_enable Enable Crop by EDE block*/
    int32_t crop_enable;
    /*!< crop_parameters[4] Crop parameters*/
    int32_t crop_parameters[4];
    /*!< saturation_enable Saturation sub-block bypass*/
    int32_t saturation_enable;
    /*!< frame_width frame width*/
    int32_t frame_width;
    /*!< rgb2y_coef[5] RGB to luma conversion coefficients*/
    int32_t rgb2y_coef[5];
    /*!< extrap_blend_alpha blending coefficient used in extrapolation*/
    int32_t extrap_blend_alpha;
    /*!< tm_num_rows number of rows in TM grid*/
    int32_t tm_num_rows;
    /*!< tm_num_cols number of columns in TM grid*/
    int32_t tm_num_cols;
    /*!< spatial_weight[64] List of spatial weights*/
    int32_t spatial_weight[64];
    /*!< tm_blk_sz_shift Log2 of Number of pixels in row/column of TM block*/
    int32_t tm_blk_sz_shift;
    /*!< init_row First image pixel offset relative to the TM grid and the initial pixel*/
    int32_t init_row;
    /*!< init_col First image pixel offset relative to the TM grid and the initial pixel*/
    int32_t init_col;
    /*!< spatial_index_shift Shift value between index in Blk and index in spatial weights vector*/
    int32_t spatial_index_shift;
    /*!< output_shift Final shift, at end of block, converting working precision to required output precision*/
    int32_t output_shift;
    /*!< cu_similarity_weight_mapping_x[11] config unit mapping luma diff to similarity weights , X values*/
    int32_t cu_similarity_weight_mapping_x[11];
    /*!< cu_similarity_weight_mapping_b[10] config unit mapping luma diff to similarity weights,  Y values*/
    int32_t cu_similarity_weight_mapping_b[10];
    /*!< cu_similarity_weight_mapping_a[10] config unit mapping luma diff to similarity weights, Slope values*/
    int32_t cu_similarity_weight_mapping_a[10];
    /*!< cu_chroma_control_x[10] config unit for chroma control, X values*/
    int32_t cu_chroma_control_x[10];
    /*!< cu_chroma_control_b[9] config unit for chroma control, Y values*/
    int32_t cu_chroma_control_b[9];
    /*!< cu_chroma_control_a[9] config unit for chroma control, Slope values*/
    int32_t cu_chroma_control_a[9];
    /*!< tm_grid_xay[1595000] LUT that holds gammastar grid points x, slope and y values*/
    uint16_t tm_grid_xay[1595000];

} ia_pal_isp_gammastar_1_t;

/*! \isp struct gammatm_v3

*/
typedef struct
{
    /*!< enable enable for the filter*/
    int32_t enable;
    /*!< gammaBeforeTM order of operations whether Gamma correction should precede TM or vise versa*/
    int32_t gammaBeforeTM;
    /*!< a1 shift amount at stage 1*/
    int32_t a1;
    /*!< a2 shift amount at stage 2*/
    int32_t a2;
    /*!< a3 shift amount at stage 3*/
    int32_t a3;
    /*!< gamma_lut_enable enable for gamma lut*/
    int32_t gamma_lut_enable;
    /*!< gamma_lut_base_level[8] base level for gamma lut*/
    int32_t gamma_lut_base_level[8];
    /*!< gamma_lut_step[8] step for gamma lut*/
    int32_t gamma_lut_step[8];
    /*!< gamma_lut_start_bin[8] start bin for gamma lut*/
    int32_t gamma_lut_start_bin[8];
    /*!< gamma_lut_size gamma lut size*/
    int32_t gamma_lut_size;
    /*!< gamma_lut_gen_lut[1537] generalized lut for gamma lut*/
    int32_t gamma_lut_gen_lut[1537];
    /*!< tm_lut_enable enable for tone mapping lut*/
    int32_t tm_lut_enable;
    /*!< tm_lut_base_level[3] base level for  tone mapping lut*/
    int32_t tm_lut_base_level[3];
    /*!< tm_lut_step[3] step for  tone mapping lut*/
    int32_t tm_lut_step[3];
    /*!< tm_lut_start_bin[3] start bin for  tone mapping lut*/
    int32_t tm_lut_start_bin[3];
    /*!< tm_lut_size tone mapping lut size*/
    int32_t tm_lut_size;
    /*!< tm_lut_gen_lut[2049] generalized lut for tone mapping lut*/
    int32_t tm_lut_gen_lut[2049];
    /*!< prog_shift programable shift for the gamma output*/
    int32_t prog_shift;

} ia_pal_isp_gammatm_v3_t;

/*! \isp struct gd_dpc_2_1

*/
typedef struct
{
    /*!< green_pos gb position*/
    int32_t green_pos;
    /*!< lc_cu_x[4] local contrast config unit x*/
    int32_t lc_cu_x[4];
    /*!< lc_cu_y[3] local contrast config unit y*/
    int32_t lc_cu_y[3];
    /*!< lc_cu_slope[3] local contrast config unit slope*/
    int32_t lc_cu_slope[3];
    /*!< delta_cu_x[4] delta config unit x*/
    int32_t delta_cu_x[4];
    /*!< delta_cu_y[3] delta config unit y*/
    int32_t delta_cu_y[3];
    /*!< delta_cu_slope[3] delta config unit slope*/
    int32_t delta_cu_slope[3];
    /*!< inv_lc_cu_x[8] inverse local contarst config unit x*/
    int32_t inv_lc_cu_x[8];
    /*!< inv_lc_cu_y[7] inverse local contarst config unit y*/
    int32_t inv_lc_cu_y[7];
    /*!< inv_lc_cu_slope[7] inverse local contarst config unit slope*/
    int32_t inv_lc_cu_slope[7];
    /*!< inv_delta_cu_x[8] inverse delta config unit x*/
    int32_t inv_delta_cu_x[8];
    /*!< inv_delta_cu_y[7] inverse delta config unit y*/
    int32_t inv_delta_cu_y[7];
    /*!< inv_delta_cu_slope[7] inverse delta config unit slope*/
    int32_t inv_delta_cu_slope[7];
    /*!< detail_pres detail preservation factor*/
    int32_t detail_pres;
    /*!< invscale scale factor after normalizing by inverse*/
    int32_t invscale;
    /*!< afxoffset[32] 8 Autofocus pixels X axis offset U14.0, should be smaller than afxperiod*/
    int32_t afxoffset[32];
    /*!< afxperiod[32] 8 Autofocus pixels X axis period*/
    int32_t afxperiod[32];
    /*!< afyoffset[32] 8 Autofocus pixels Y axis offset U14.0, should be smaller than afyperiod*/
    int32_t afyoffset[32];
    /*!< afyperiod[32] 8 Autofocus pixels Y axis period*/
    int32_t afyperiod[32];
    /*!< hdrfactors[16] 4x4 HDR exposure factor U6.8*/
    int32_t hdrfactors[16];
    /*!< hdrfactorsinverse[16] 4x4 HDR exposure inverse factor U6.8 - should be inverse of hdrfactors*/
    int32_t hdrfactorsinverse[16];
    /*!< configunitcolddistvsmedian_slope[7] cold dist vs median config unit classifier*/
    int32_t configunitcolddistvsmedian_slope[7];
    /*!< configunitcolddistvsmedian_x[8] cold dist vs median config unit classifier*/
    int32_t configunitcolddistvsmedian_x[8];
    /*!< configunitcolddistvsmedian_y[7] cold dist vs median config unit classifier*/
    int32_t configunitcolddistvsmedian_y[7];
    /*!< configunitcolddistvsneighb_slope[7] cold dist vs neigb config unit classifier*/
    int32_t configunitcolddistvsneighb_slope[7];
    /*!< configunitcolddistvsneighb_x[8] cold dist vs neigb config unit classifier*/
    int32_t configunitcolddistvsneighb_x[8];
    /*!< configunitcolddistvsneighb_y[7] cold dist vs neigb config unit classifier*/
    int32_t configunitcolddistvsneighb_y[7];
    /*!< configunitfix_slope[3] fix config unit*/
    int32_t configunitfix_slope[3];
    /*!< configunitfix_x[4] fix config unit*/
    int32_t configunitfix_x[4];
    /*!< configunitfix_y[3] fix config unit*/
    int32_t configunitfix_y[3];
    /*!< configunithotdistvsmedian_slope[7] hot dist vs median classifier*/
    int32_t configunithotdistvsmedian_slope[7];
    /*!< configunithotdistvsmedian_x[8] hot dist vs median classifier*/
    int32_t configunithotdistvsmedian_x[8];
    /*!< configunithotdistvsmedian_y[7] hot dist vs median classifier*/
    int32_t configunithotdistvsmedian_y[7];
    /*!< configunithotdistvsneighb_slope[7] hot dist vs neigb config unit classifier*/
    int32_t configunithotdistvsneighb_slope[7];
    /*!< configunithotdistvsneighb_x[8] hot dist vs neigb config unit classifier*/
    int32_t configunithotdistvsneighb_x[8];
    /*!< configunithotdistvsneighb_y[7] hot dist vs neigb config unit classifier*/
    int32_t configunithotdistvsneighb_y[7];
    /*!< pelesttype[16] 0-P1, 1-P2, 2-P3, 3-P4, 4-P5, 5-P6*/
    int32_t pelesttype[16];
    /*!< dtype[16] 0-D1 1-D2  2-D3*/
    int32_t dtype[16];
    /*!< pmasks[384] configurations related to the bayer pattern*/
    int32_t pmasks[384];
    /*!< dmasks[48] configurations related to the bayer pattern*/
    int32_t dmasks[48];
    /*!< bitreduceshift Shift value for bit reduce block*/
    int32_t bitreduceshift;
    /*!< afenable enable for the AF unit block*/
    int32_t afenable;
    /*!< dynamicenable enable for the dynamic detection block*/
    int32_t dynamicenable;
    /*!< frame_width frame width*/
    int32_t frame_width;
    /*!< paf_grid_en[32] paf grid enables*/
    int32_t paf_grid_en[32];
    /*!< paf_pattern_rearrangement_en Enable pattern rearrangement unit after AF Pels detection*/
    int32_t paf_pattern_rearrangement_en;
    /*!< afsXStart AF pixel detection crop - start X position*/
    int32_t afsXStart;
    /*!< afsYStart AF pixel detection crop - start Y position*/
    int32_t afsYStart;
    /*!< afsXEnd AF pixel detection crop - end X position*/
    int32_t afsXEnd;
    /*!< afsYEnd AF pixel detection crop - end Y position*/
    int32_t afsYEnd;
    /*!< afsXStartCropEn AF pixel crop enable - start X position*/
    int32_t afsXStartCropEn;
    /*!< afsYStartCropEn AF pixel crop enable - start Y position*/
    int32_t afsYStartCropEn;
    /*!< afsXEndCropEn AF pixel crop enable - end X position*/
    int32_t afsXEndCropEn;
    /*!< afsYEndCropEn AF pixel crop enable - end Y position*/
    int32_t afsYEndCropEn;
    /*!< use_nlm[16] use non local means mechanism*/
    int32_t use_nlm[16];
    /*!< sad1_thr threshold on the first sad*/
    int32_t sad1_thr;
    /*!< sad2_thr threshold on the second sad*/
    int32_t sad2_thr;
    /*!< pixel_diff_thr threshold on the pixel difference*/
    int32_t pixel_diff_thr;
    /*!< min_direction_sad_thr threshold on the min direction*/
    int32_t min_direction_sad_thr;
    /*!< max_direction_sad_thr threshold on the max direction*/
    int32_t max_direction_sad_thr;
    /*!< saturation_thr protect pixels in saturated areas*/
    int32_t saturation_thr;
    /*!< ignore_ver_direction[16] ignore vertical direction for certain types of pdaf sensors*/
    int32_t ignore_ver_direction[16];
    /*!< configunit_med_protection_slope[3] nlm fix config unit*/
    int32_t configunit_med_protection_slope[3];
    /*!< configunit_med_protection_x[4] nlm fix config unit*/
    int32_t configunit_med_protection_x[4];
    /*!< configunit_med_protection_y[3] nlm fix config unit*/
    int32_t configunit_med_protection_y[3];
    /*!< clamping_disable disable clamping to support previous version of dpc*/
    int32_t clamping_disable;
    /*!< sensor_type 0=simple_bayer 1=2pd 2=sve_2pd 3=sve_zigzag1 4=sve_zigzag2*/
    int32_t sensor_type;
    /*!< fix_dist when 0 - opposite sign distances around the pixel are ignored*/
    int32_t fix_dist;
    /*!< flip_neigb_axis flip neigb vs dist axis*/
    int32_t flip_neigb_axis;
    /*!< g_locations_for_sve[16] g on 4x4 grid*/
    int32_t g_locations_for_sve[16];
    /*!< config_median_blend_slope[3] blend coef cfg*/
    int32_t config_median_blend_slope[3];
    /*!< config_median_blend_x[4] blend coef cfg*/
    int32_t config_median_blend_x[4];
    /*!< config_median_blend_y[3] blend coef cfg*/
    int32_t config_median_blend_y[3];
    /*!< config_ridges_slope[3] ridge coef cfg*/
    int32_t config_ridges_slope[3];
    /*!< config_ridges_x[4] ridge coef cfg*/
    int32_t config_ridges_x[4];
    /*!< config_ridges_y[3] ridge coef cfg*/
    int32_t config_ridges_y[3];
    /*!< global_enable global enable*/
    int32_t global_enable;
    /*!< gdc_enable gdc enable*/
    int32_t gdc_enable;
    /*!< dpc_enable dpc enable*/
    int32_t dpc_enable;

} ia_pal_isp_gd_dpc_2_1_t;

/*! \isp struct gdc3
HW filter reference with FW ISP API
*/
typedef struct
{
    /*!< filter_size filter size. {4-BCI, 6-Lancos}*/
    int32_t filter_size;
    /*!< nums_luts number of LUTs partioning. {1-4}*/
    int32_t nums_luts;
    /*!< lut_sel LUT part selection. {0:nums_lut}*/
    int32_t lut_sel;
    /*!< lut[1536] LUT s5.10*/
    int32_t lut[1536];
    /*!< interpolation_type interpolation type*/
    int32_t interpolation_type;
    /*!< nums_hgrid_luma size of horizontal grig for luma. {}*/
    int32_t nums_hgrid_luma;
    /*!< nums_vgrid_luma size of vertical grig for luma. {}*/
    int32_t nums_vgrid_luma;
    /*!< nums_hgrid_chroma size of horizontal grig for chroma. {}*/
    int32_t nums_hgrid_chroma;
    /*!< nums_vgrid_chroma size of vertical grig for chroma {}*/
    int32_t nums_vgrid_chroma;
    /*!< luma_block_width_power luma_block_width_power*/
    int32_t luma_block_width_power;
    /*!< luma_block_height_power luma_block_height_power*/
    int32_t luma_block_height_power;
    /*!< chroma_block_width_power chroma_block_width_power*/
    int32_t chroma_block_width_power;
    /*!< chroma_block_height_power chroma_block_height_power*/
    int32_t chroma_block_height_power;
    /*!< luma_origin_x[10584] luma_origin_x*/
    int32_t luma_origin_x[10584];
    /*!< luma_origin_y[10584] luma_origin_y*/
    int32_t luma_origin_y[10584];
    /*!< luma_in_block_width[10584] luma_in_block_width*/
    int32_t luma_in_block_width[10584];
    /*!< luma_in_block_height[10584] luma_in_block_heght*/
    int32_t luma_in_block_height[10584];
    /*!< luma_p0_x[10584] luma_p0_x*/
    int32_t luma_p0_x[10584];
    /*!< luma_p0_y[10584] luma_p0_y*/
    int32_t luma_p0_y[10584];
    /*!< luma_p1_x[10584] luma_p1_x*/
    int32_t luma_p1_x[10584];
    /*!< luma_p1_y[10584] luma_p1_y*/
    int32_t luma_p1_y[10584];
    /*!< luma_p2_x[10584] luma_p2_x*/
    int32_t luma_p2_x[10584];
    /*!< luma_p2_y[10584] luma_p2_y*/
    int32_t luma_p2_y[10584];
    /*!< luma_p3_x[10584] luma_p3_x*/
    int32_t luma_p3_x[10584];
    /*!< luma_p3_y[10584] luma_p3_y*/
    int32_t luma_p3_y[10584];
    /*!< chroma_origin_x[10584] chroma_origin_x*/
    int32_t chroma_origin_x[10584];
    /*!< chroma_origin_y[10584] chroma_origin_y*/
    int32_t chroma_origin_y[10584];
    /*!< chroma_in_block_width[10584] chroma_in_block_width*/
    int32_t chroma_in_block_width[10584];
    /*!< chroma_in_block_height[10584] chroma_in_block_heght*/
    int32_t chroma_in_block_height[10584];
    /*!< chroma_p0_x[10584] chroma_p0_x*/
    int32_t chroma_p0_x[10584];
    /*!< chroma_p0_y[10584] chroma_p0_y*/
    int32_t chroma_p0_y[10584];
    /*!< chroma_p1_x[10584] chroma_p1_x*/
    int32_t chroma_p1_x[10584];
    /*!< chroma_p1_y[10584] chroma_p1_y*/
    int32_t chroma_p1_y[10584];
    /*!< chroma_p2_x[10584] chroma_p2_x*/
    int32_t chroma_p2_x[10584];
    /*!< chroma_p2_y[10584] chroma_p2_y*/
    int32_t chroma_p2_y[10584];
    /*!< chroma_p3_x[10584] chroma_p3_x*/
    int32_t chroma_p3_x[10584];
    /*!< chroma_p3_y[10584] chroma_p3_y*/
    int32_t chroma_p3_y[10584];

} ia_pal_isp_gdc3_t;

/*! \isp struct gdc3_1
HW filter reference with FW ISP API
*/
typedef struct
{
    /*!< filter_size */
    int32_t filter_size;
    /*!< nums_luts */
    int32_t nums_luts;
    /*!< lut_sel */
    int32_t lut_sel;
    /*!< lut[1536] */
    int32_t lut[1536];
    /*!< interpolation_type */
    int32_t interpolation_type;
    /*!< nums_hgrid_luma */
    int32_t nums_hgrid_luma;
    /*!< nums_vgrid_luma */
    int32_t nums_vgrid_luma;
    /*!< nums_hgrid_chroma */
    int32_t nums_hgrid_chroma;
    /*!< nums_vgrid_chroma */
    int32_t nums_vgrid_chroma;
    /*!< luma_block_width_power */
    int32_t luma_block_width_power;
    /*!< luma_block_height_power */
    int32_t luma_block_height_power;
    /*!< chroma_block_width_power */
    int32_t chroma_block_width_power;
    /*!< chroma_block_height_power */
    int32_t chroma_block_height_power;
    /*!< luma_origin_x[5292] */
    int32_t luma_origin_x[5292];
    /*!< luma_origin_y[5292] */
    int32_t luma_origin_y[5292];
    /*!< luma_in_block_width[5292] */
    int32_t luma_in_block_width[5292];
    /*!< luma_in_block_height[5292] */
    int32_t luma_in_block_height[5292];
    /*!< luma_p0_x[5292] */
    int32_t luma_p0_x[5292];
    /*!< luma_p0_y[5292] */
    int32_t luma_p0_y[5292];
    /*!< luma_p1_x[5292] */
    int32_t luma_p1_x[5292];
    /*!< luma_p1_y[5292] */
    int32_t luma_p1_y[5292];
    /*!< luma_p2_x[5292] */
    int32_t luma_p2_x[5292];
    /*!< luma_p2_y[5292] */
    int32_t luma_p2_y[5292];
    /*!< luma_p3_x[5292] */
    int32_t luma_p3_x[5292];
    /*!< luma_p3_y[5292] */
    int32_t luma_p3_y[5292];
    /*!< chroma_origin_x[5292] */
    int32_t chroma_origin_x[5292];
    /*!< chroma_origin_y[5292] */
    int32_t chroma_origin_y[5292];
    /*!< chroma_in_block_width[5292] */
    int32_t chroma_in_block_width[5292];
    /*!< chroma_in_block_height[5292] */
    int32_t chroma_in_block_height[5292];
    /*!< chroma_p0_x[5292] */
    int32_t chroma_p0_x[5292];
    /*!< chroma_p0_y[5292] */
    int32_t chroma_p0_y[5292];
    /*!< chroma_p1_x[5292] */
    int32_t chroma_p1_x[5292];
    /*!< chroma_p1_y[5292] */
    int32_t chroma_p1_y[5292];
    /*!< chroma_p2_x[5292] */
    int32_t chroma_p2_x[5292];
    /*!< chroma_p2_y[5292] */
    int32_t chroma_p2_y[5292];
    /*!< chroma_p3_x[5292] */
    int32_t chroma_p3_x[5292];
    /*!< chroma_p3_y[5292] */
    int32_t chroma_p3_y[5292];

} ia_pal_isp_gdc3_1_t;

/*! \isp struct gdc3_1_1
HW filter reference with FW ISP API
*/
typedef struct
{
    /*!< filter_size filter size. {4-BCI, 6-Lancos}*/
    int32_t filter_size;
    /*!< nums_luts number of LUTs partioning. {1-4}*/
    int32_t nums_luts;
    /*!< lut_sel LUT part selection. {0:nums_lut}*/
    int32_t lut_sel;
    /*!< lut[1536] LUT s5.10*/
    int32_t lut[1536];
    /*!< interpolation_type interpolation type*/
    int32_t interpolation_type;
    /*!< nums_hgrid_luma size of horizontal grig for luma. {}*/
    int32_t nums_hgrid_luma;
    /*!< nums_vgrid_luma size of vertical grig for luma. {}*/
    int32_t nums_vgrid_luma;
    /*!< nums_hgrid_chroma size of horizontal grig for chroma. {}*/
    int32_t nums_hgrid_chroma;
    /*!< nums_vgrid_chroma size of vertical grig for chroma {}*/
    int32_t nums_vgrid_chroma;
    /*!< luma_block_width_power luma_block_width_power*/
    int32_t luma_block_width_power;
    /*!< luma_block_height_power luma_block_height_power*/
    int32_t luma_block_height_power;
    /*!< chroma_block_width_power chroma_block_width_power*/
    int32_t chroma_block_width_power;
    /*!< chroma_block_height_power chroma_block_height_power*/
    int32_t chroma_block_height_power;
    /*!< gdc_warp_grid_luma[84672] gdc_warp_grid_luma*/
    int32_t gdc_warp_grid_luma[84672];
    /*!< gdc_warp_grid_chroma[84672] gdc_warp_grid_chroma*/
    int32_t gdc_warp_grid_chroma[84672];

} ia_pal_isp_gdc3_1_1_t;

/*! \isp struct gdc4_2
HW filter reference with FW ISP API
*/
typedef struct
{
    /*!< in_bpp image input bpp*/
    int32_t in_bpp;
    /*!< interpolation_type */
    int32_t interpolation_type;
    /*!< filter_size */
    int32_t filter_size;
    /*!< lut_sel */
    int32_t lut_sel;
    /*!< out_bpp image output bpp*/
    int32_t out_bpp;
    /*!< gro Group reorder, convert 2D to 1D access, 0: bypass, 1: reorder (needed for 2y mode)*/
    int32_t gro;
    /*!< perf_mode Perf mode, 0: 1x1y, 1: 2x1y, 2: 1x2y, 3: 2x2y*/
    int32_t perf_mode;
    /*!< ch1_in_bpp image input bpp*/
    int32_t ch1_in_bpp;
    /*!< ch1_interpolation_type */
    int32_t ch1_interpolation_type;
    /*!< ch1_filter_size */
    int32_t ch1_filter_size;
    /*!< ch1_lut_sel */
    int32_t ch1_lut_sel;
    /*!< ch1_out_bpp image output bpp*/
    int32_t ch1_out_bpp;
    /*!< ch1_gro Group reorder, convert 2D to 1D access, 0: bypass, 1: reorder (needed for 2y mode)*/
    int32_t ch1_gro;
    /*!< ch1_perf_mode Perf mode, 0: 1x1y, 1: 2x1y, 2: 1x2y, 3: 2x2y*/
    int32_t ch1_perf_mode;
    /*!< ch2_in_bpp image input bpp*/
    int32_t ch2_in_bpp;
    /*!< ch2_interpolation_type */
    int32_t ch2_interpolation_type;
    /*!< ch2_filter_size */
    int32_t ch2_filter_size;
    /*!< ch2_lut_sel */
    int32_t ch2_lut_sel;
    /*!< ch2_out_bpp image output bpp*/
    int32_t ch2_out_bpp;
    /*!< ch2_gro Group reorder, convert 2D to 1D access, 0: bypass, 1: reorder (needed for 2y mode)*/
    int32_t ch2_gro;
    /*!< ch2_perf_mode Perf mode, 0: 1x1y, 1: 2x1y, 2: 1x2y, 3: 2x2y*/
    int32_t ch2_perf_mode;
    /*!< nums_luts */
    int32_t nums_luts;
    /*!< lut[1536] */
    int32_t lut[1536];
    /*!< nums_hgrid_luma */
    int32_t nums_hgrid_luma;
    /*!< nums_vgrid_luma */
    int32_t nums_vgrid_luma;
    /*!< nums_hgrid_chroma */
    int32_t nums_hgrid_chroma;
    /*!< nums_vgrid_chroma */
    int32_t nums_vgrid_chroma;
    /*!< luma_block_width_power */
    int32_t luma_block_width_power;
    /*!< luma_block_height_power */
    int32_t luma_block_height_power;
    /*!< chroma_block_width_power */
    int32_t chroma_block_width_power;
    /*!< chroma_block_height_power */
    int32_t chroma_block_height_power;
    /*!< luma_tetragons[84672] */
    int32_t luma_tetragons[84672];
    /*!< chroma_tetragons[84672] */
    int32_t chroma_tetragons[84672];

} ia_pal_isp_gdc4_2_t;

/*! \isp struct gdc5
HW filter reference with FW ISP API
*/
typedef struct
{
    /*!< filter_size filter size. {4-BCI, 6-Lancos}*/
    int32_t filter_size;
    /*!< nums_luts number of LUTs partioning. {1-4}*/
    int32_t nums_luts;
    /*!< lut_sel LUT part selection. {0:nums_lut}*/
    int32_t lut_sel;
    /*!< lut[1536] LUT s1.10*/
    int32_t lut[1536];
    /*!< interpolation_type interpolation type*/
    int32_t interpolation_type;
    /*!< nums_hgrid_luma size of horizontal grig for luma. {}*/
    int32_t nums_hgrid_luma;
    /*!< nums_vgrid_luma size of vertical grig for luma. {}*/
    int32_t nums_vgrid_luma;
    /*!< nums_hgrid_chroma size of horizontal grig for chroma. {}*/
    int32_t nums_hgrid_chroma;
    /*!< nums_vgrid_chroma size of vertical grig for chroma {}*/
    int32_t nums_vgrid_chroma;
    /*!< luma_block_width_power luma_block_width_power*/
    int32_t luma_block_width_power;
    /*!< luma_block_height_power luma_block_height_power*/
    int32_t luma_block_height_power;
    /*!< chroma_block_width_power chroma_block_width_power*/
    int32_t chroma_block_width_power;
    /*!< chroma_block_height_power chroma_block_height_power*/
    int32_t chroma_block_height_power;
    /*!< luma_origin_x[10584] luma_origin_x*/
    int32_t luma_origin_x[10584];
    /*!< luma_origin_y[10584] luma_origin_y*/
    int32_t luma_origin_y[10584];
    /*!< luma_in_block_width[10584] luma_in_block_width*/
    int32_t luma_in_block_width[10584];
    /*!< luma_in_block_height[10584] luma_in_block_heght*/
    int32_t luma_in_block_height[10584];
    /*!< luma_p0_x[10584] luma_p0_x*/
    int32_t luma_p0_x[10584];
    /*!< luma_p0_y[10584] luma_p0_y*/
    int32_t luma_p0_y[10584];
    /*!< luma_p1_x[10584] luma_p1_x*/
    int32_t luma_p1_x[10584];
    /*!< luma_p1_y[10584] luma_p1_y*/
    int32_t luma_p1_y[10584];
    /*!< luma_p2_x[10584] luma_p2_x*/
    int32_t luma_p2_x[10584];
    /*!< luma_p2_y[10584] luma_p2_y*/
    int32_t luma_p2_y[10584];
    /*!< luma_p3_x[10584] luma_p3_x*/
    int32_t luma_p3_x[10584];
    /*!< luma_p3_y[10584] luma_p3_y*/
    int32_t luma_p3_y[10584];
    /*!< chroma_origin_x[10584] chroma_origin_x*/
    int32_t chroma_origin_x[10584];
    /*!< chroma_origin_y[10584] chroma_origin_y*/
    int32_t chroma_origin_y[10584];
    /*!< chroma_in_block_width[10584] chroma_in_block_width*/
    int32_t chroma_in_block_width[10584];
    /*!< chroma_in_block_height[10584] chroma_in_block_heght*/
    int32_t chroma_in_block_height[10584];
    /*!< chroma_p0_x[10584] chroma_p0_x*/
    int32_t chroma_p0_x[10584];
    /*!< chroma_p0_y[10584] chroma_p0_y*/
    int32_t chroma_p0_y[10584];
    /*!< chroma_p1_x[10584] chroma_p1_x*/
    int32_t chroma_p1_x[10584];
    /*!< chroma_p1_y[10584] chroma_p1_y*/
    int32_t chroma_p1_y[10584];
    /*!< chroma_p2_x[10584] chroma_p2_x*/
    int32_t chroma_p2_x[10584];
    /*!< chroma_p2_y[10584] chroma_p2_y*/
    int32_t chroma_p2_y[10584];
    /*!< chroma_p3_x[10584] chroma_p3_x*/
    int32_t chroma_p3_x[10584];
    /*!< chroma_p3_y[10584] chroma_p3_y*/
    int32_t chroma_p3_y[10584];
    /*!< in_bpp image input bpp*/
    int32_t in_bpp;
    /*!< out_bpp image output bpp*/
    int32_t out_bpp;
    /*!< gdc_operating_mode 0: GDC calculates tetragons; 1: tetragons from API are used, 2: GDC5_1 WFOV*/
    int32_t gdc_operating_mode;
    /*!< gdc_mode 0: bypass, 1: High Distortion only, 2: Homography only, 6: Homography and high distortion, 9: High distortion and homography*/
    int32_t gdc_mode;
    /*!< crop_top Top border for cropping*/
    int32_t crop_top;
    /*!< crop_left Left border for cropping*/
    int32_t crop_left;
    /*!< crop_bottom Bottom border for cropping*/
    int32_t crop_bottom;
    /*!< crop_right Right border for cropping*/
    int32_t crop_right;
    /*!< homography_transformation_luma_0[64] homography transformation matrices for luma channel,  1, 2, 4, 5. elements S2.20,*/
    int32_t homography_transformation_luma_0[64];
    /*!< homography_transformation_luma_1[32] homography transformation matrices for luma channel,  7. and 8. S0.31 but only 25 lower bits used*/
    int32_t homography_transformation_luma_1[32];
    /*!< homography_transformation_luma_2[48] homography transformation matrices for luma channel, 3, 6, 9. S15.16*/
    int32_t homography_transformation_luma_2[48];
    /*!< homography_matrices_offset[16] Offsets from the top for homography matrices*/
    int32_t homography_matrices_offset[16];
    /*!< homography_matrices_count number of homography matrices*/
    int32_t homography_matrices_count;
    /*!< ldc_r_lut[256] LDC (R) LUT table, format Q14.16*/
    int32_t ldc_r_lut[256];
    /*!< ldc_max_distance_from_center Maximum distance from the radial center from the full sensor resolution. Q16.8*/
    int32_t ldc_max_distance_from_center;
    /*!< ldc_r_x_center x coordinate of LDC (R) correction center of symmerty*/
    int32_t ldc_r_x_center;
    /*!< ldc_r_y_center y coordinate of LDC (R) correction center of symmerty*/
    int32_t ldc_r_y_center;
    /*!< ldc_r_y_scale_factor y coordinate scaling factor for elliptical distortion of LDC (R) correction, format Q4.16*/
    int32_t ldc_r_y_scale_factor;
    /*!< gdc_modep 0:PreAffine/Projections/LDC/PostAffine, 1:PreAffine/Projections/Rotation/LDC/PostAffine, 2:PreAffine/Projections/Rotation/PostAffine, 3:Homography/PreAffine/Projections/Rotation/LDC/PostAffine, 4:PreAffine/Homography/Projections/Rotation/LDC/PostAffine*/
    int32_t gdc_modep;
    /*!< rotationmatrix[9] Rotational Matrix for applying rotation (S1.20)*/
    int32_t rotationmatrix[9];
    /*!< projectionsf_1[2] Scaling factor for Projections. (Elements 1 and 2 of scaling factor: S4.20)*/
    int32_t projectionsf_1[2];
    /*!< projectionsf_2[2] Scaling factor for Projections. (Elements 3 and 4 of scaling factor: S14.8)*/
    int32_t projectionsf_2[2];
    /*!< projection_type 0: Rectilinear, 1: Conic, 2: Equirectangular*/
    int32_t projection_type;
    /*!< projections_inv_f_pi Inv_f_pi = (1/f*pi) where f corresponds to View_Width/HFOV (Q0.31)*/
    int32_t projections_inv_f_pi;
    /*!< ldc_mode 0:Rd/Ru mode, 1: SqLUT mode, 2: Rd/Ru mode with normalization*/
    int32_t ldc_mode;
    /*!< ldc_max_a Maximum distance from the radial center from the full sensor resolution. Q3.16*/
    int32_t ldc_max_a;
    /*!< ldc_inv_max_a Inv of ldc_max_a, Q0.26*/
    int32_t ldc_inv_max_a;
    /*!< ldc_lut_shift_bits LDC LUT Shift bits*/
    int32_t ldc_lut_shift_bits;
    /*!< preaffine_matrix_scale[4] PreAffine Matrix for scale S4.15*/
    int32_t preaffine_matrix_scale[4];
    /*!< preaffine_matrix_translation[2] PreAffine Matrix for translation integer value S18.8*/
    int32_t preaffine_matrix_translation[2];
    /*!< postaffine_matrix_scale[4] PostAffine Matrix for scale S4.15*/
    int32_t postaffine_matrix_scale[4];
    /*!< postaffine_matrix_translation[2] PostAffine Matrix for translation integer value S18.8*/
    int32_t postaffine_matrix_translation[2];
    /*!< invalid_coord_mask[4] Invalid Coordinate Mask to be set. Default value set is for 8 bits.*/
    int32_t invalid_coord_mask[4];
    /*!< normalization_sf Normalization scaling factor (Q20)*/
    int32_t normalization_sf;
    /*!< MSB_alignment_en 0: LSB Alignment 1:MSB Alignment*/
    int32_t MSB_alignment_en;

} ia_pal_isp_gdc5_t;

/*! \isp struct gdc7

*/
typedef struct
{
    /*!< gdc_coord_enable coord calculation bypass*/
    int32_t gdc_coord_enable;
    /*!< crop_top Top border for cropping*/
    int32_t crop_top;
    /*!< crop_left Left border for cropping*/
    int32_t crop_left;
    /*!< crop_bottom Bottom border for cropping*/
    int32_t crop_bottom;
    /*!< crop_right Right border for cropping*/
    int32_t crop_right;
    /*!< homography_transformation_luma_0[64] homography transformation matrices for luma channel,  1, 2, 4, 5. elements S4.18,*/
    int32_t homography_transformation_luma_0[64];
    /*!< homography_transformation_luma_1[32] homography transformation matrices for luma channel,  7. and 8. S0.31 but only 25 lower bits used*/
    int32_t homography_transformation_luma_1[32];
    /*!< homography_transformation_luma_2[48] homography transformation matrices for luma channel, 3, 6, 9. S18.13*/
    int32_t homography_transformation_luma_2[48];
    /*!< homography_matrices_offset[16] Offsets from the top for homography matrices*/
    int32_t homography_matrices_offset[16];
    /*!< homography_matrices_count number of homography matrices*/
    int32_t homography_matrices_count;
    /*!< ldc_r_lut[256] LDC (R) LUT table, format Q14.16*/
    int32_t ldc_r_lut[256];
    /*!< gdc_modep 0:Homography/Projections/LDC/PostAffine, 1:Homography/Projections/Rotation/LDC/PostAffine, 2:Homography/Projections/Rotation/PostAffine*/
    int32_t gdc_modep;
    /*!< rotationmatrix[9] Rotational Matrix for applying rotation (S1.20)*/
    int32_t rotationmatrix[9];
    /*!< projectionsf_1[2] Scaling factor for Projections. (Elements 1 and 2 of scaling factor: S4.20)*/
    int32_t projectionsf_1[2];
    /*!< projectionsf_2[2] Scaling factor for Projections. (Elements 3 and 4 of scaling factor: S14.8)*/
    int32_t projectionsf_2[2];
    /*!< projection_type 0: Rectilinear, 1: Conic, 2: Equirectangular, 3: 2D Bowl*/
    int32_t projection_type;
    /*!< projections_inv_f_pi Inv_f_pi = (1/f*pi) where f corresponds to View_Width/HFOV (Q0.31)*/
    int32_t projections_inv_f_pi;
    /*!< ldc_max_a Maximum distance from the radial center from the full sensor resolution. Q3.16*/
    int32_t ldc_max_a;
    /*!< ldc_inv_max_a Inv of ldc_max_a, Q0.26*/
    int32_t ldc_inv_max_a;
    /*!< ldc_lut_shift_bits LDC LUT Shift bits*/
    int32_t ldc_lut_shift_bits;
    /*!< postaffine_matrix_scale[4] PostAffine Matrix for scale S4.15*/
    int32_t postaffine_matrix_scale[4];
    /*!< postaffine_matrix_translation[2] PostAffine Matrix for translation integer value S18.8*/
    int32_t postaffine_matrix_translation[2];
    /*!< invalid_coord_mask[3] Invalid Coordinate Mask to be set. Default value set is for 8 bits.*/
    int32_t invalid_coord_mask[3];
    /*!< translation3d[3] 3D translation for bowl projection (S14.8)*/
    int32_t translation3d[3];
    /*!< bowl_radius_sqr_2d 2D Bowl Radius Square (Q28.0)*/
    int32_t bowl_radius_sqr_2d;
    /*!< bowl_scale_2d 2D Bowl Scale Value (Q0.31)*/
    int32_t bowl_scale_2d;
    /*!< IRS_interpolation_enable Use NN for interpolation*/
    int32_t IRS_interpolation_enable;
    /*!< input_height input image height*/
    int32_t input_height;
    /*!< input_width input image width*/
    int32_t input_width;
    /*!< GDC_SP_coord_conv_enable GDC SP 1:4 coord conversion mechanism*/
    int32_t GDC_SP_coord_conv_enable;
    /*!< max_distortion_reporting_enable Report position within input image of last processed row for internal rolling buffer support 0-off, 1-on*/
    int32_t max_distortion_reporting_enable;
    /*!< max_distortion Maximum lens distortion in input image domain, which defines stagger of last processed input row relative to output row*/
    int32_t max_distortion;

} ia_pal_isp_gdc7_t;

/*! \isp struct glim_1_0
Global inverse tone mapping
*/
typedef struct
{
    /*!< glim_enable Enable GLIM*/
    int32_t glim_enable;
    /*!< glu_base_level[8] GLU base level offset*/
    int32_t glu_base_level[8];
    /*!< glu_step[8] GLU step amount per stage*/
    int32_t glu_step[8];
    /*!< glu_start_bin[8] GLU stage start offset in LUT*/
    int32_t glu_start_bin[8];
    /*!< glu_gen_lut_size Utilized LUT size*/
    int32_t glu_gen_lut_size;
    /*!< glu_gen_lut[385] LUT samples*/
    int32_t glu_gen_lut[385];
    /*!< gain_prec Gain precision bits*/
    int32_t gain_prec;

} ia_pal_isp_glim_1_0_t;

/*! \isp struct glim_2_0
Global inverse tone mapping
*/
typedef struct
{
    /*!< glim_enable Enable GLIM*/
    int32_t glim_enable;
    /*!< glu_base_level[8] GLU base level offset*/
    int32_t glu_base_level[8];
    /*!< glu_step[8] GLU step amount per stage*/
    int32_t glu_step[8];
    /*!< glu_start_bin[8] GLU stage start offset in LUT*/
    int32_t glu_start_bin[8];
    /*!< glu_gen_lut_size Utilized LUT size*/
    int32_t glu_gen_lut_size;
    /*!< glu_gen_lut[385] LUT samples*/
    int32_t glu_gen_lut[385];
    /*!< gain_prec Gain precision bits*/
    int32_t gain_prec;

} ia_pal_isp_glim_2_0_t;

/*! \isp struct gltm_1_0
Global tone mapping
*/
typedef struct
{
    /*!< gltm_enable Enable GLTM*/
    int32_t gltm_enable;
    /*!< fc_m[9] YUV2RGB format conversion matrix (coeffs S2.13)*/
    int32_t fc_m[9];
    /*!< glu_base_level[8] GLU base level offset*/
    int32_t glu_base_level[8];
    /*!< glu_step[8] GLU step amount per stage*/
    int32_t glu_step[8];
    /*!< glu_start_bin[8] GLU stage start offset in LUT*/
    int32_t glu_start_bin[8];
    /*!< glu_gen_lut_size Utilized LUT size*/
    int32_t glu_gen_lut_size;
    /*!< glu_gen_lut[385] LUT samples*/
    int32_t glu_gen_lut[385];
    /*!< gain_prec Gain precision bits*/
    int32_t gain_prec;

} ia_pal_isp_gltm_1_0_t;

/*! \isp struct gltm_2_0
Global tone mapping
*/
typedef struct
{
    /*!< gltm_enable Enable GLTM*/
    int32_t gltm_enable;
    /*!< fc_m[9] YUV2RGB format conversion matrix (coeffs S2.13)*/
    int32_t fc_m[9];
    /*!< glu_base_level[8] GLU base level offset*/
    int32_t glu_base_level[8];
    /*!< glu_step[8] GLU step amount per stage*/
    int32_t glu_step[8];
    /*!< glu_start_bin[8] GLU stage start offset in LUT*/
    int32_t glu_start_bin[8];
    /*!< glu_gen_lut_size Utilized LUT size*/
    int32_t glu_gen_lut_size;
    /*!< glu_gen_lut[385] LUT samples*/
    int32_t glu_gen_lut[385];
    /*!< gain_prec Gain precision bits*/
    int32_t gain_prec;

} ia_pal_isp_gltm_2_0_t;

/*! \isp struct gmv_statistics_1_0

*/
typedef struct
{
    /*!< gmv_en ff enable/disable flag*/
    int32_t gmv_en;
    /*!< is_first_frame Set to 1 on first frame. If 1, the input features are ignored, fixed (fake) matches are produced*/
    int32_t is_first_frame;
    /*!< additional_bin_input set to 1 if 4x binning is required before processing, otherwise image is binned 2x*/
    int32_t additional_bin_input;
    /*!< kappa kappa for Harris grade calculation*/
    int32_t kappa;
    /*!< counter_shifter Shifter for the good feature point and good match point counter*/
    int32_t counter_shifter;
    /*!< good_corner_threshold Threshold for the good corner counter.*/
    int32_t good_corner_threshold;
    /*!< good_match_threshold Threshold for the good match counter.*/
    int32_t good_match_threshold;
    /*!< block_width Block width*/
    int32_t block_width;
    /*!< block_height Block height*/
    int32_t block_height;
    /*!< x_start x start for best feature search*/
    int32_t x_start;
    /*!< y_start y start for best feature search*/
    int32_t y_start;
    /*!< x_end x end for best feature search*/
    int32_t x_end;
    /*!< y_end y end for best feature search*/
    int32_t y_end;

} ia_pal_isp_gmv_statistics_1_0_t;

/*! \isp struct hdr_blc_1
HDR black level correction filter
*/
typedef struct
{
    /*!< bl_cc00 Black level, color channel (0,0) (adjusted for MSB aligned image)*/
    int32_t bl_cc00;
    /*!< bl_cc01 Black level, color channel (0,1) (adjusted for MSB aligned image)*/
    int32_t bl_cc01;
    /*!< bl_cc10 Black level, color channel (1,0) (adjusted for MSB aligned image)*/
    int32_t bl_cc10;
    /*!< bl_cc11 Black level, color channel (1,1) (adjusted for MSB aligned image)*/
    int32_t bl_cc11;

} ia_pal_isp_hdr_blc_1_t;

/*! \isp struct hdr_pwldecomp_1
PWL decompression filter
*/
typedef struct
{
    /*!< idx_shift Shift for computing LUT index*/
    int32_t idx_shift;
    /*!< delta_x_0_to_31[32] PWL decompression curve delta x (for each segment)*/
    int32_t delta_x_0_to_31[32];
    /*!< delta_x_32_to_63[32] PWL decompression curve delta x (for each segment)*/
    int32_t delta_x_32_to_63[32];
    /*!< slope_shift_0_to_31[32] PWL decompression curve shift representing slope (for each segment)*/
    int32_t slope_shift_0_to_31[32];
    /*!< slope_shift_32_to_63[32] PWL decompression curve shift representing slope (for each segment)*/
    int32_t slope_shift_32_to_63[32];
    /*!< offset_y_0_to_31[32] PWL decompression curve y offset (for each segment)*/
    int32_t offset_y_0_to_31[32];
    /*!< offset_y_32_to_63[32] PWL decompression curve y offset (for each segment)*/
    int32_t offset_y_32_to_63[32];
    /*!< use64 Switch for using 64-element LUTs*/
    int32_t use64;
    /*!< range_shift Shift for MSB alignment*/
    int32_t range_shift;

} ia_pal_isp_hdr_pwldecomp_1_t;

/*! \isp struct hdr_sqrtcomp_2
HDR compression filter
*/
typedef struct
{
    /*!< noSQRTcomp SQRT compression switch: 0 - enable SQRT compression, 1 - no SQRT compression, pass top 15-bits (approx.)*/
    int32_t noSQRTcomp;

} ia_pal_isp_hdr_sqrtcomp_2_t;

/*! \isp struct hdr_sqrtcomp_3

*/
typedef struct
{
    /*!< bypass SQRT compression switch: 0 - enable SQRT compression, 1 - no SQRT compression, pass top 15-bits (approx.)*/
    int32_t bypass;
    /*!< invsqrt_offset_vec[128] */
    int32_t invsqrt_offset_vec[128];
    /*!< invsqrt_slope_vec[128] */
    int32_t invsqrt_slope_vec[128];
    /*!< invsqrt_x_cord_vec[128] */
    int32_t invsqrt_x_cord_vec[128];
    /*!< invsqrt_exponent */
    int32_t invsqrt_exponent;
    /*!< invsqrt_resolution */
    int32_t invsqrt_resolution;
    /*!< invsqrt_x_cord_max */
    int32_t invsqrt_x_cord_max;

} ia_pal_isp_hdr_sqrtcomp_3_t;

/*! \isp struct hdr_stitch_1w

*/
typedef struct
{
    /*!< blend_hithr Blending mask transfer fn upper threshold*/
    int32_t blend_hithr;
    /*!< blend_maxblendval Max. blending mask value before normalization*/
    int32_t blend_maxblendval;
    /*!< blend_blendshift Normalization shift for blending mask values*/
    int32_t blend_blendshift;
    /*!< blend_maxblendval2 Max. blending mask value after normalization*/
    int32_t blend_maxblendval2;
    /*!< dg_Yshift Shift for luminance in deghosting*/
    int32_t dg_Yshift;
    /*!< dg_A Ghost map transfer fn. parameter A*/
    int32_t dg_A;
    /*!< dg_S Ghost map transfer fn. parameter S*/
    int32_t dg_S;
    /*!< dg_Yfactshift Shift for luminance factor in deghosting*/
    int32_t dg_Yfactshift;
    /*!< dg_Yfactoffset Offset for luminance factor in deghosting*/
    int32_t dg_Yfactoffset;
    /*!< dg_ylothr Low threshold deghosting luminance sensitivity (15bit)*/
    int32_t dg_ylothr;
    /*!< dg_blur Factor for controling blurring in ghost locations (0 no blur , 128 max blur)*/
    int32_t dg_blur;
    /*!< ng_factor Normalization gain factor (ISP gain * HDR gain)*/
    int32_t ng_factor;
    /*!< ng_shift Normalization gain shift*/
    int32_t ng_shift;
    /*!< cgl_R Long exposure channel gain, R (fixed point)*/
    int32_t cgl_R;
    /*!< cgl_Gr Long exposure channel gain, Gr (fixed point)*/
    int32_t cgl_Gr;
    /*!< cgl_Gb Long exposure channel gain, Gb (fixed point)*/
    int32_t cgl_Gb;
    /*!< cgl_B Long exposure channel gain, B (fixed point)*/
    int32_t cgl_B;
    /*!< cgs_R Short exposure channel gain, R (fixed point)*/
    int32_t cgs_R;
    /*!< cgs_Gr Short exposure channel gain, Gr (fixed point)*/
    int32_t cgs_Gr;
    /*!< cgs_Gb Short exposure channel gain, Gb (fixed point)*/
    int32_t cgs_Gb;
    /*!< cgs_B Short exposure channel gain, B (fixed point)*/
    int32_t cgs_B;
    /*!< bll_cc00 Long exposure black level, color channel (0,0), WB corrected*/
    int32_t bll_cc00;
    /*!< bll_cc01 Long exposure black level, color channel (0,0), WB corrected*/
    int32_t bll_cc01;
    /*!< bll_cc10 Long exposure black level, color channel (0,0), WB corrected*/
    int32_t bll_cc10;
    /*!< bll_cc11 Long exposure black level, color channel (0,0), WB corrected*/
    int32_t bll_cc11;
    /*!< bls_cc00 Short exposure black level, color channel (0,0), fixed point*/
    int32_t bls_cc00;
    /*!< bls_cc01 Short exposure black level, color channel (0,1), fixed point*/
    int32_t bls_cc01;
    /*!< bls_cc10 Short exposure black level, color channel (1,0), fixed point*/
    int32_t bls_cc10;
    /*!< bls_cc11 Short exposure black level, color channel (1,1), fixed point*/
    int32_t bls_cc11;
    /*!< blr_cc00 Short exposure residual black level, color channel (0,0), WB corrected and exposure aligned*/
    int32_t blr_cc00;
    /*!< blr_cc01 Short exposure residual black level, color channel (0,1), WB corrected and exposure aligned*/
    int32_t blr_cc01;
    /*!< blr_cc10 Short exposure residual black level, color channel (1,0), WB corrected and exposure aligned*/
    int32_t blr_cc10;
    /*!< blr_cc11 Short exposure residual black level, color channel (1,1), WB corrected and exposure aligned*/
    int32_t blr_cc11;
    /*!< dpc_enable DPC weight parameter*/
    int32_t dpc_enable;
    /*!< lowlight_value Low light threshold*/
    int32_t lowlight_value;
    /*!< lowlight_shift Low light filter shift*/
    int32_t lowlight_shift;
    /*!< lowlight_filterStrength Low light filter strength*/
    int32_t lowlight_filterStrength;

} ia_pal_isp_hdr_stitch_1w_t;

/*! \isp struct hdr_wb_1
HDR white balance correction filter
*/
typedef struct
{
    /*!< gain_R Integer representation of adjusted WB gain, R*/
    int32_t gain_R;
    /*!< gain_Gr Integer representation of adjusted WB gain, Gr*/
    int32_t gain_Gr;
    /*!< gain_Gb Integer representation of adjusted WB gain, Gb*/
    int32_t gain_Gb;
    /*!< gain_B Integer representation of adjusted WB gain, B*/
    int32_t gain_B;
    /*!< gain_shift_R Adjusted WB gain shift, R*/
    int32_t gain_shift_R;
    /*!< gain_shift_Gr Adjusted WB gain shift, Gr*/
    int32_t gain_shift_Gr;
    /*!< gain_shift_Gb Adjusted WB gain shift, Gb*/
    int32_t gain_shift_Gb;
    /*!< gain_shift_B Adjusted WB gain shift, B*/
    int32_t gain_shift_B;
    /*!< clipval Clip value for input signal*/
    int32_t clipval;

} ia_pal_isp_hdr_wb_1_t;

/*! \isp struct hdrstats_1
HDR Statistics Extraction filter
*/
typedef struct
{
    /*!< rgbsstat_en StatR/G/B/S enable: 0 - disable, 1 - enable*/
    int32_t rgbsstat_en;
    /*!< histstat_en HistStatR/G/B/Y enable: 0 - disable, 1 - enable*/
    int32_t histstat_en;
    /*!< drcstat_en DRCStatY/V enable: 0 - disable, 1 - enable*/
    int32_t drcstat_en;
    /*!< bayer_startcolor Bayer Start Color: 0 - R, 1 - Gr, 2 - Gb, 3 - B*/
    int32_t bayer_startcolor;
    /*!< dcn_mode DCN mode: 0 - bypass, 1 - DC2, 2 - DC4, 3 - DC8, Saturation grid size: 0 - 8x8, 1 - 16x16, 2 - 32x32, 3 - 64x64*/
    int32_t dcn_mode;
    /*!< sat_thrsh Saturation threshold*/
    int32_t sat_thrsh;
    /*!< sat_rshift Saturation right shift value for converting to saturation ratio: DCN mode * 2*/
    int32_t sat_rshift;
    /*!< drcstat_xx2x_bypass Bypass XX2x sub-block*/
    int32_t drcstat_xx2x_bypass;
    /*!< decomp_bypass Bypass decompression sub-block*/
    int32_t decomp_bypass;
    /*!< decomp_y_mode decompression Y mode: 0 - average, 1 - max*/
    int32_t decomp_y_mode;
    /*!< rgbs_grid_width StatR/G/B/S grid width*/
    int32_t rgbs_grid_width;
    /*!< rgbs_grid_height StatR/G/B/S grid height*/
    int32_t rgbs_grid_height;
    /*!< hist_grid_width HistStatR/G/B/Y grid width*/
    int32_t hist_grid_width;
    /*!< hist_grid_height HistStatR/G/B/Y grid height*/
    int32_t hist_grid_height;
    /*!< drc_grid_width DRCStatY/V grid width*/
    int32_t drc_grid_width;
    /*!< drc_grid_height DRCStatY/V grid height*/
    int32_t drc_grid_height;

} ia_pal_isp_hdrstats_1_t;

/*! \isp struct input_system_drainer

*/
typedef struct
{
    /*!< binning_bayer_enable Bayer binning enable*/
    int32_t binning_bayer_enable;
    /*!< binning_4cell_enable 4cell binning enable*/
    int32_t binning_4cell_enable;
    /*!< crop_enable 0 - Line cropping enabled, 1 - Line cropping enabled*/
    int32_t crop_enable;
    /*!< crop_line_top When cropping is enabled, all lines before this line will be cropped*/
    int32_t crop_line_top;
    /*!< crop_line_bot When cropping is enabled, all lines after this line will be cropped*/
    int32_t crop_line_bot;

} ia_pal_isp_input_system_drainer_t;

/*! \isp struct io_buffer

*/
typedef struct
{
    /*!< input_width Input width counted in number of pixels components per line*/
    int32_t input_width;
    /*!< input_height Input height counted in number of lines*/
    int32_t input_height;
    /*!< output_width Output width counted in number of pixels components per line*/
    int32_t output_width;
    /*!< output_height Output height counted in number of lines*/
    int32_t output_height;
    /*!< x_output_offset Output horizontal offset from the input, counted in number of pixels components per line, 16b signed (if negative padding is required)*/
    int32_t x_output_offset;
    /*!< y_output_offset Output vertical offset from the input counted in number of lines, 16b signed*/
    int32_t y_output_offset;
    /*!< use_attributes This capability impact the ODR. When set, ODR should use the EOL/EOF attributes to detect frame dimensions. In general, this capability is used when the height or width or both are not known or cannot be expressed. Using this capability disable the option using crop/pad mechanism and force SW to provide the same dimension in input/output region (if known) and zero the offset values.*/
    int32_t use_attributes;
    /*!< espa_luma_shift_left 1-perform shift left on the luma/bayer componenets, 0-perfrom shift right on the luma/bayer components*/
    int32_t espa_luma_shift_left;
    /*!< espa_luma_shift_count shift amount to the luma/bayer component where sign is kept and shift right done with rounding*/
    int32_t espa_luma_shift_count;
    /*!< espa_chroma_shift_left 1-perform shift left on the chroma componenets, 0-perfrom shift right on the chroma components*/
    int32_t espa_chroma_shift_left;
    /*!< espa_chroma_shift_count shift amount to the chroma component where sign is kept and shift right done with rounding*/
    int32_t espa_chroma_shift_count;
    /*!< espa_range_reduction_output_resolution Set the output resolution to be used at the range reduction calculation*/
    int32_t espa_range_reduction_output_resolution;
    /*!< espa_range_reduction_enable enable range reduction calculation for all components*/
    int32_t espa_range_reduction_enable;
    /*!< espa_luma_clipping_min_enable clipping the luma components to clipping_min value*/
    int32_t espa_luma_clipping_min_enable;
    /*!< espa_luma_clipping_max_enable clipping the luma components to clipping_max value*/
    int32_t espa_luma_clipping_max_enable;
    /*!< espa_chroma_clipping_min_enable clipping the chroma components to clipping_min value*/
    int32_t espa_chroma_clipping_min_enable;
    /*!< espa_chroma_clipping_max_enable clipping the chroma components to clipping_max value*/
    int32_t espa_chroma_clipping_max_enable;
    /*!< espa_luma_clipping_min_value Min value (S15) to clip the component after the shift using sign arithmetic*/
    int32_t espa_luma_clipping_min_value;
    /*!< espa_luma_clipping_max_value Max value (S15) to clip the component after the shift using sign arithmetic*/
    int32_t espa_luma_clipping_max_value;
    /*!< espa_luma_offset_value Offset value (S15) to be added to the component using sign arithmetic*/
    int32_t espa_luma_offset_value;
    /*!< espa_chroma_clipping_min_value Min value (S15) to clip the component after the shift using sign arithmetic*/
    int32_t espa_chroma_clipping_min_value;
    /*!< espa_chroma_clipping_max_value Max value (S15) to clip the component after the shift using sign arithmetic*/
    int32_t espa_chroma_clipping_max_value;
    /*!< espa_chroma_offset_value Offset value (S15) to be added to the component using sign arithmetic*/
    int32_t espa_chroma_offset_value;
    /*!< espa_enable Enable espa*/
    int32_t espa_enable;
    /*!< component_precision Pixel element precision in bits: 0=>8b, 1=>10b, 2=>12b, 3=>16, 4=>32, 5=>2, 6=>4, 7..15=>reserved*/
    int32_t component_precision;
    /*!< unpack_alignment Valid for unpacked vectors: 0-element located at LSB and MSB is zero; 1-element located at MSB and LSB is zero*/
    int32_t unpack_alignment;
    /*!< vertical_ordering_enable If set, the walking order should be vertical using the sub_line value to indicate how many CL generate vertical movement*/
    int32_t vertical_ordering_enable;
    /*!< vertical_ordering_sub_line valid when vertical_ordering is set, indicates the size of the sub line to generate vertical step in CL granularity*/
    int32_t vertical_ordering_sub_line;
    /*!< num_of_queues Amount of total active queues (YUV FP - 4, YUV SP - 3 YUV SP Tile - 2. RGB - 1,1,1. Bayer -2). Must be up to amount of maximum queue supported. Can be changed per frame. At LBFF used dynamicly for PDAF*/
    int32_t num_of_queues;
    /*!< vector_format Vector CL format: 0-unpacked using 2B container; 1-packed*/
    int32_t vector_format;
    /*!< tile_mode Valid for IO that can provide tile format: 0-no tiling; 1-the IO should use tiling with the configured height, width, and tiling type (internal tiling or external Tile-4)*/
    int32_t tile_mode;
    /*!< tiling_type Tiling Type: 0 - internal tiling; 1 - external tiling (Tile-4)*/
    int32_t tiling_type;
    /*!< compression_mode Valid for streaming that are tiled: 1-the stream is written/fetched to/from DDR through compression engine; 0-not going through compression*/
    int32_t compression_mode;
    /*!< buffer_1d_enable Valid only for 1 plane and 1 queue streams. 0-the buffer is described as 2D; 1-the buffer is described as 1D (continues from start to end w/o stride ignoring lines)*/
    int32_t buffer_1d_enable;
    /*!< num_of_planes Amount of valid planes (supported 1, 2, 3, 4 - depends also on HW parameter of max planes and data type)*/
    int32_t num_of_planes;
    /*!< plane_stride[3] Per plane: provides the difference between two horizontal pixels, in bytes, CL aligned, unsigned.  At tile mode - provide the difference between two lines of tiles in bytes*/
    uint32_t plane_stride[3];
    /*!< plane_offset_start_address[3] Per plane: Start offset address of plane with regarding to the base_offset, in bytes, CL aligned, unsigned.*/
    uint32_t plane_offset_start_address[3];
    /*!< plane_offset_end_address[3] Per plane: End offset address of plane with regarding to the base_offset, in bytes, CL aligned, unsigned.*/
    uint32_t plane_offset_end_address[3];
    /*!< plane_tile_width[3] Per plane: buffer tile width configuration in bytes*/
    int32_t plane_tile_width[3];
    /*!< plane_tile_height[3] Per plane: buffer tile height configuration in lines*/
    int32_t plane_tile_height[3];
    /*!< chroma_planes_order Chroma planes ordering: 0 - U before V; 1 - V before U (valid for half planer configuration)*/
    int32_t chroma_planes_order;
    /*!< chroma_duplication Valid when format 420 is configured to provide 422 (2P2Q with SIF count of 4 or 2). when reset - duplicate the chroma and provide the same value each two Y lines, when set - send the chroma components only with the even Y (at odd Y lines doesn’t send any chroma)*/
    int32_t chroma_duplication;
    /*!< onep_pixel_order Set the ordering of the first plane (lines-N, pixels-M) 4PPC: 0-(N, M), (N, M+1), (N+1, M), (N+1, M+1), horizontal raster; 1-(N, M), (N+1, M), (N, M+1), (N+1, M+1), vertical raster 2PPC: 0-first cyc: (N, M), (N+1, M), second cyc: (N, M+1), (N+1, M+1); 1-first cyc: (N, M), (N, M+1),*/
    int32_t onep_pixel_order;
    /*!< zlr_transaction_enable when set enable sending zlr request for prefetch address translation and compression status*/
    int32_t zlr_transaction_enable;
    /*!< streaming_mode The streaming unified buffer protocol:  0-static offline (producer/consumer write/read from DDR after kick);  1-dynamic offline (producer/consumer send wr/rd EOF/SOF, producer write after kick, consumer read after full frame at DDR);  2-buffer chasing large memory (producer/consumer send wr/rd EOF/SOF, producer send wr update, consumer read according to wr update);  3-buffer chasing on small memory (producer/consumer send wr/rd EOF/SOF, producer write released buffers and sends wr pointers, consumer read valid buffer and sends rd pointer);  4-S&R like 3 with option to change the link (supporting modes 2 and 3 with dynamic change) 5-buffer chasing small memory - fix starting point, single buffer 6-buffer chasing small memory - float starting point 7-buffer chasing small memory - fix starting point, double buffer*/
    int32_t streaming_mode;
    /*!< streaming_sw_managed When set - the SW verify the shared buffer is fully consumed by  the producer and can be written immediately*/
    int32_t streaming_sw_managed;
    /*!< local_link_id indicates the stream used at the current connectlon*/
    int32_t local_link_id;
    /*!< stride_ratio provides the BCSM max_stride/stride ratio with possible values of 1-8, 16, 32, 64, 128*/
    int32_t stride_ratio;
    /*!< granularity_pointer_update Valid according the streaming mode: number of lines (LB)/lines of blocks (BB) to be written/release before sending a pointer update (reporting always done with producer view)*/
    int32_t granularity_pointer_update;
    /*!< max_stride provides the maximum stride value to be used at the connection*/
    uint32_t max_stride;
    /*!< block_width buffer block width configuration in pixels*/
    int32_t block_width;
    /*!< block_height buffer block height configuration in lines*/
    int32_t block_height;
    /*!< first_row_blocks_height buffer block height configuration in lines of all the blocks in the first row of blocks. If zero - use streaming_buffer_blocks_height*/
    int32_t first_row_blocks_height;
    /*!< last_row_blocks_height buffer block height configuration in lines of all the blocks in the last row of blocks. If zero - use streaming_buffer_blocks_height*/
    int32_t last_row_blocks_height;
    /*!< plane_max_burst_size[3] Plane maximum burst size: used to specify the transfer size in CL granularity (Max limited to 16, possible values - 1, 2, 4, 8, 16)*/
    int32_t plane_max_burst_size[3];
    /*!< plane_horiz_subsample_config[3] Plane Horiz subsample (width>>N).  Affect tile width and width resolution=>Bayer - 0, Y/UV at YUV SP - 0, Y at YUV FP -0, UV U/V at YUV FP-1)*/
    int32_t plane_horiz_subsample_config[3];
    /*!< plane_vert_subsample_config[3] Plane Vertical subsample (height>>N). Affect tile highet and highet resolution=>Bayer - 0, Y atYUV SP - 0, UV at YUV SP - 1, Y at YUV FP -0, U/V at YUV FP-1)*/
    int32_t plane_vert_subsample_config[3];
    /*!< plane_zlr_granularity[3] Plane ZLR page granularity: if 0 - 4KB, if 1 - 2KB. Valid only if ZLR is enalbe*/
    int32_t plane_zlr_granularity[3];
    /*!< progress_message_line Provides the line number that when is done generate progress message (IFD - last byte of the line arrive, ODR - last byte of the line acked by nbuf)*/
    int32_t progress_message_line;
    /*!< pace_message_ref_line Provides the line number that when start indicating start measuring the pace and active  (ODR - send first WR of the line, IFD send first RD of line)*/
    int32_t pace_message_ref_line;
    /*!< pace_message_pace_line Provides the line number indicating to stop measuring the activity and pace and sending pace meesage (at IFD - get the last data of the line, at ODR - getnon-buf ack on last data of the line)*/
    int32_t pace_message_pace_line;
    /*!< component_in_valid_pixel Provides amount of valid component per valid pixel*/
    int32_t component_in_valid_pixel;
    /*!< pixels_in_valid_cycle Provides amount of valid pixels per valid cycle*/
    int32_t pixels_in_valid_cycle;
    /*!< subsample_YUV444_to_YUV422 Used by ODR to convert YUV444 to YUV422: 0-use amount of element as written at components_in_valid_cycle, 1-drop the chroma components any odd cycle*/
    int32_t subsample_YUV444_to_YUV422;
    /*!< middle_ack_line_number Valid if ack enable  If enabled, the device should generate middle ack when delivers the EOL of the configured line (global number) assuming the first line delievered at SOF is zero.  In case of multiple planes the counting is done using plane1 but only when all the planes are synced*/
    int32_t middle_ack_line_number;
    /*!< middle_ack_enable If set, enable the mechansim to generate middle ack when consumed amount of configured lines*/
    int32_t middle_ack_enable;
    /*!< middle_ack_mode_stall Valid only when ack_enable is set When set, the device should stall once sending the middle ack*/
    int32_t middle_ack_mode_stall;
    /*!< stream_dt stream data type as need to be used by the MIPI*/
    int32_t stream_dt;
    /*!< stream_vc stream virtual channel number as need to be used in MIPI*/
    int32_t stream_vc;
    /*!< proc_ff_bypass when set indicates the FF in the pipe (FCVT & ESPA) need to be bypass*/
    int32_t proc_ff_bypass;
    /*!< dpa_bypass When set indicate the end of MIPI frame (used for MIPI CSI sub frames)*/
    int32_t dpa_bypass;
    /*!< stream_dt_for_mipi_packet stream data type as need to be used in the header of mipi packet - not affect the proc*/
    int32_t stream_dt_for_mipi_packet;
    /*!< arbiter_pin MIPI CSI arbiter pin location of the stream*/
    int32_t arbiter_pin;
    /*!< user_reserved user_reserved*/
    int32_t user_reserved;
    /*!< aligner_data_size amount of valid bits per valid cycle to be accumulate and use the aligner (valid when dpa_bypass is set). LSB represent 2b resolution (meaning value can be 2, 4, 6, 8, … up to 72 which is the size bus)*/
    int32_t aligner_data_size;
    /*!< mipi_csi_eof When set indicate the end of MIPI frame (used for MIPI CSI sub frames)*/
    int32_t mipi_csi_eof;
    /*!< ppc provides the amount of pixel per cycle*/
    int32_t ppc;
    /*!< stream_wc stream word count as need to be used by the MIPI*/
    int32_t stream_wc;
    /*!< max_credits provides the maximum amount of credits for eliminating the need to calculate it in HW according the next formula: (end_address-start_address)/Max_Stride*/
    uint32_t max_credits;
    /*!< reserved_0_0 Reserved for future use*/
    int32_t reserved_0_0;
    /*!< reserved_0_1 Reserved for future use*/
    int32_t reserved_0_1;
    /*!< reserved_0_2 Reserved for future use*/
    int32_t reserved_0_2;
    /*!< reserved_0_3 Reserved for future use*/
    int32_t reserved_0_3;
    /*!< reserved_1_0 Reserved for future use*/
    int32_t reserved_1_0;
    /*!< reserved_1_1 Reserved for future use*/
    int32_t reserved_1_1;
    /*!< reserved_1_2 Reserved for future use*/
    int32_t reserved_1_2;
    /*!< reserved_1_3 Reserved for future use*/
    int32_t reserved_1_3;

} ia_pal_isp_io_buffer_t;

/*! \isp struct io_buffer_1_1

*/
typedef struct
{
    /*!< input_width Input width counted in number of pixels components per line*/
    int32_t input_width;
    /*!< input_height Input height counted in number of lines*/
    int32_t input_height;
    /*!< output_width Output width counted in number of pixels components per line*/
    int32_t output_width;
    /*!< output_height Output height counted in number of lines*/
    int32_t output_height;
    /*!< x_output_offset Output horizontal offset from the input, counted in number of pixels components per line, 16b signed (if negative padding is required)*/
    int32_t x_output_offset;
    /*!< y_output_offset Output vertical offset from the input counted in number of lines, 16b signed*/
    int32_t y_output_offset;
    /*!< use_attributes This capability impact the ODR. When set, ODR should use the EOL/EOF attributes to detect frame dimensions. In general, this capability is used when the height or width or both are not known or cannot be expressed. Using this capability disable the option using crop/pad mechanism and force SW to provide the same dimension in input/output region (if known) and zero the offset values.*/
    int32_t use_attributes;
    /*!< espa_luma_shift_left 1-perform shift left on the luma/bayer componenets, 0-perfrom shift right on the luma/bayer components*/
    int32_t espa_luma_shift_left;
    /*!< espa_luma_shift_count shift amount to the luma/bayer component where sign is kept and shift right done with rounding*/
    int32_t espa_luma_shift_count;
    /*!< espa_chroma_shift_left 1-perform shift left on the chroma componenets, 0-perfrom shift right on the chroma components*/
    int32_t espa_chroma_shift_left;
    /*!< espa_chroma_shift_count shift amount to the chroma component where sign is kept and shift right done with rounding*/
    int32_t espa_chroma_shift_count;
    /*!< espa_range_reduction_output_resolution Set the output resolution to be used at the range reduction calculation*/
    int32_t espa_range_reduction_output_resolution;
    /*!< espa_range_reduction_enable enable range reduction calculation for all components*/
    int32_t espa_range_reduction_enable;
    /*!< espa_luma_clipping_min_enable clipping the luma components to clipping_min value*/
    int32_t espa_luma_clipping_min_enable;
    /*!< espa_luma_clipping_max_enable clipping the luma components to clipping_max value*/
    int32_t espa_luma_clipping_max_enable;
    /*!< espa_chroma_clipping_min_enable clipping the chroma components to clipping_min value*/
    int32_t espa_chroma_clipping_min_enable;
    /*!< espa_chroma_clipping_max_enable clipping the chroma components to clipping_max value*/
    int32_t espa_chroma_clipping_max_enable;
    /*!< espa_luma_clipping_min_value Min value (S15) to clip the component after the shift using sign arithmetic*/
    int32_t espa_luma_clipping_min_value;
    /*!< espa_luma_clipping_max_value Max value (S15) to clip the component after the shift using sign arithmetic*/
    int32_t espa_luma_clipping_max_value;
    /*!< espa_luma_offset_value Offset value (S15) to be added to the component using sign arithmetic*/
    int32_t espa_luma_offset_value;
    /*!< espa_chroma_clipping_min_value Min value (S15) to clip the component after the shift using sign arithmetic*/
    int32_t espa_chroma_clipping_min_value;
    /*!< espa_chroma_clipping_max_value Max value (S15) to clip the component after the shift using sign arithmetic*/
    int32_t espa_chroma_clipping_max_value;
    /*!< espa_chroma_offset_value Offset value (S15) to be added to the component using sign arithmetic*/
    int32_t espa_chroma_offset_value;
    /*!< espa_enable Enable espa*/
    int32_t espa_enable;
    /*!< component_precision Pixel element precision in bits: 0=>8b, 1=>10b, 2=>12b, 3=>16, 4=>32, 5=>2, 6=>4, 7..15=>reserved*/
    int32_t component_precision;
    /*!< unpack_alignment Valid for unpacked vectors: 0-element located at LSB and MSB is zero; 1-element located at MSB and LSB is zero*/
    int32_t unpack_alignment;
    /*!< vertical_ordering_enable If set, the walking order should be vertical using the sub_line value to indicate how many CL generate vertical movement*/
    int32_t vertical_ordering_enable;
    /*!< vertical_ordering_sub_line valid when vertical_ordering is set, indicates the size of the sub line to generate vertical step in CL granularity*/
    int32_t vertical_ordering_sub_line;
    /*!< num_of_queues Amount of total active queues (YUV FP - 4, YUV SP - 3 YUV SP Tile - 2. RGB - 1,1,1. Bayer -2). Must be up to amount of maximum queue supported. Can be changed per frame. At LBFF used dynamicly for PDAF*/
    int32_t num_of_queues;
    /*!< vector_format Vector CL format: 0-unpacked using 2B container; 1-packed*/
    int32_t vector_format;
    /*!< tile_mode Valid for IO that can provide tile format: 0-no tiling; 1-the IO should use tiling with the configured height, width, and tiling type (internal tiling or external Tile-4)*/
    int32_t tile_mode;
    /*!< tiling_type Tiling Type: 0 - internal tiling; 1 - external tiling (Tile-4)*/
    int32_t tiling_type;
    /*!< compression_mode Valid for streaming that are tiled: 1-the stream is written/fetched to/from DDR through compression engine; 0-not going through compression*/
    int32_t compression_mode;
    /*!< buffer_1d_enable Valid only for 1 plane and 1 queue streams. 0-the buffer is described as 2D; 1-the buffer is described as 1D (continues from start to end w/o stride ignoring lines)*/
    int32_t buffer_1d_enable;
    /*!< num_of_planes Amount of valid planes (supported 1, 2, 3, 4 - depends also on HW parameter of max planes and data type)*/
    int32_t num_of_planes;
    /*!< plane_stride[3] Per plane: provides the difference between two horizontal pixels, in bytes, CL aligned, unsigned.  At tile mode - provide the difference between two lines of tiles in bytes*/
    uint32_t plane_stride[3];
    /*!< plane_offset_start_address[3] Per plane: Start offset address of plane with regarding to the base_offset, in bytes, CL aligned, unsigned.*/
    uint32_t plane_offset_start_address[3];
    /*!< plane_offset_end_address[3] Per plane: End offset address of plane with regarding to the base_offset, in bytes, CL aligned, unsigned.*/
    uint32_t plane_offset_end_address[3];
    /*!< plane_tile_width[3] Per plane: buffer tile width configuration in bytes*/
    int32_t plane_tile_width[3];
    /*!< plane_tile_height[3] Per plane: buffer tile height configuration in lines*/
    int32_t plane_tile_height[3];
    /*!< chroma_planes_order Chroma planes ordering: 0 - U before V; 1 - V before U (valid for half planer configuration)*/
    int32_t chroma_planes_order;
    /*!< chroma_duplication Valid when format 420 is configured to provide 422 (2P2Q with SIF count of 4 or 2). when reset - duplicate the chroma and provide the same value each two Y lines, when set - send the chroma components only with the even Y (at odd Y lines doesn’t send any chroma)*/
    int32_t chroma_duplication;
    /*!< onep_pixel_order Set the ordering of the first plane (lines-N, pixels-M) 4PPC: 0-(N, M), (N, M+1), (N+1, M), (N+1, M+1), horizontal raster; 1-(N, M), (N+1, M), (N, M+1), (N+1, M+1), vertical raster 2PPC: 0-first cyc: (N, M), (N+1, M), second cyc: (N, M+1), (N+1, M+1); 1-first cyc: (N, M), (N, M+1),*/
    int32_t onep_pixel_order;
    /*!< zlr_transaction_enable when set enable sending zlr request for prefetch address translation and compression status*/
    int32_t zlr_transaction_enable;
    /*!< streaming_mode The streaming unified buffer protocol:  0-static offline (producer/consumer write/read from DDR after kick);  1-dynamic offline (producer/consumer send wr/rd EOF/SOF, producer write after kick, consumer read after full frame at DDR);  2-buffer chasing large memory (producer/consumer send wr/rd EOF/SOF, producer send wr update, consumer read according to wr update);  3-buffer chasing on small memory (producer/consumer send wr/rd EOF/SOF, producer write released buffers and sends wr pointers, consumer read valid buffer and sends rd pointer);  4-S&R like 3 with option to change the link (supporting modes 2 and 3 with dynamic change) 5-buffer chasing small memory - fix starting point, single buffer 6-buffer chasing small memory - float starting point 7-buffer chasing small memory - fix starting point, double buffer*/
    int32_t streaming_mode;
    /*!< streaming_sw_managed When set - the SW verify the shared buffer is fully consumed by  the producer and can be written immediately*/
    int32_t streaming_sw_managed;
    /*!< local_link_id indicates the stream used at the current connectlon*/
    int32_t local_link_id;
    /*!< stride_ratio provides the BCSM max_stride/stride ratio with possible values of 1-8, 16, 32, 64, 128*/
    int32_t stride_ratio;
    /*!< granularity_pointer_update Valid according the streaming mode: number of lines (LB)/lines of blocks (BB) to be written/release before sending a pointer update (reporting always done with producer view)*/
    int32_t granularity_pointer_update;
    /*!< max_stride provides the maximum stride value to be used at the connection*/
    uint32_t max_stride;
    /*!< block_width buffer block width configuration in pixels*/
    int32_t block_width;
    /*!< block_height buffer block height configuration in lines*/
    int32_t block_height;
    /*!< first_row_blocks_height buffer block height configuration in lines of all the blocks in the first row of blocks. If zero - use streaming_buffer_blocks_height*/
    int32_t first_row_blocks_height;
    /*!< last_row_blocks_height buffer block height configuration in lines of all the blocks in the last row of blocks. If zero - use streaming_buffer_blocks_height*/
    int32_t last_row_blocks_height;
    /*!< plane_max_burst_size[3] Plane maximum burst size: used to specify the transfer size in CL granularity (Max limited to 16, possible values - 1, 2, 4, 8, 16)*/
    int32_t plane_max_burst_size[3];
    /*!< plane_horiz_subsample_config[3] Plane Horiz subsample (width>>N).  Affect tile width and width resolution=>Bayer - 0, Y/UV at YUV SP - 0, Y at YUV FP -0, UV U/V at YUV FP-1)*/
    int32_t plane_horiz_subsample_config[3];
    /*!< plane_vert_subsample_config[3] Plane Vertical subsample (height>>N). Affect tile highet and highet resolution=>Bayer - 0, Y atYUV SP - 0, UV at YUV SP - 1, Y at YUV FP -0, U/V at YUV FP-1)*/
    int32_t plane_vert_subsample_config[3];
    /*!< plane_zlr_granularity[3] Plane ZLR page granularity: if 0 - 4KB, if 1 - 2KB. Valid only if ZLR is enalbe*/
    int32_t plane_zlr_granularity[3];
    /*!< progress_message_line Provides the line number that when is done generate progress message (IFD - last byte of the line arrive, ODR - last byte of the line acked by nbuf)*/
    int32_t progress_message_line;
    /*!< pace_message_ref_line Provides the line number that when start indicating start measuring the pace and active  (ODR - send first WR of the line, IFD send first RD of line)*/
    int32_t pace_message_ref_line;
    /*!< pace_message_pace_line Provides the line number indicating to stop measuring the activity and pace and sending pace meesage (at IFD - get the last data of the line, at ODR - getnon-buf ack on last data of the line)*/
    int32_t pace_message_pace_line;
    /*!< component_in_valid_pixel Provides amount of valid component per valid pixel*/
    int32_t component_in_valid_pixel;
    /*!< pixels_in_valid_cycle Provides amount of valid pixels per valid cycle*/
    int32_t pixels_in_valid_cycle;
    /*!< subsample_YUV444_to_YUV422 Used by ODR to convert YUV444 to YUV422: 0-use amount of element as written at components_in_valid_cycle, 1-drop the chroma components any odd cycle*/
    int32_t subsample_YUV444_to_YUV422;
    /*!< middle_ack_line_number Valid if ack enable  If enabled, the device should generate middle ack when delivers the EOL of the configured line (global number) assuming the first line delievered at SOF is zero.  In case of multiple planes the counting is done using plane1 but only when all the planes are synced*/
    int32_t middle_ack_line_number;
    /*!< middle_ack_enable If set, enable the mechansim to generate middle ack when consumed amount of configured lines*/
    int32_t middle_ack_enable;
    /*!< middle_ack_mode_stall Valid only when ack_enable is set When set, the device should stall once sending the middle ack*/
    int32_t middle_ack_mode_stall;
    /*!< stream_dt stream data type as need to be used by the MIPI*/
    int32_t stream_dt;
    /*!< stream_vc stream virtual channel number as need to be used in MIPI*/
    int32_t stream_vc;
    /*!< proc_ff_bypass when set indicates the FF in the pipe (FCVT & ESPA) need to be bypass*/
    int32_t proc_ff_bypass;
    /*!< dpa_bypass When set indicate the end of MIPI frame (used for MIPI CSI sub frames)*/
    int32_t dpa_bypass;
    /*!< stream_dt_for_mipi_packet stream data type as need to be used in the header of mipi packet - not affect the proc*/
    int32_t stream_dt_for_mipi_packet;
    /*!< arbiter_pin MIPI CSI arbiter pin location of the stream*/
    int32_t arbiter_pin;
    /*!< user_reserved user_reserved*/
    int32_t user_reserved;
    /*!< aligner_data_size amount of valid bits per valid cycle to be accumulate and use the aligner (valid when dpa_bypass is set). LSB represent 2b resolution (meaning value can be 2, 4, 6, 8, … up to 72 which is the size bus)*/
    int32_t aligner_data_size;
    /*!< mipi_csi_eof When set indicate the end of MIPI frame (used for MIPI CSI sub frames)*/
    int32_t mipi_csi_eof;
    /*!< ppc provides the amount of pixel per cycle*/
    int32_t ppc;
    /*!< stream_wc stream word count as need to be used by the MIPI*/
    int32_t stream_wc;
    /*!< max_credits provides the maximum amount of credits for eliminating the need to calculate it in HW according the next formula: (end_address-start_address)/Max_Stride*/
    uint32_t max_credits;
    /*!< reserved_0_0 Reserved for future use*/
    int32_t reserved_0_0;
    /*!< reserved_0_1 Reserved for future use*/
    int32_t reserved_0_1;
    /*!< reserved_0_2 Reserved for future use*/
    int32_t reserved_0_2;
    /*!< reserved_0_3 Reserved for future use*/
    int32_t reserved_0_3;
    /*!< reserved_1_0 Reserved for future use*/
    int32_t reserved_1_0;
    /*!< reserved_1_1 Reserved for future use*/
    int32_t reserved_1_1;
    /*!< reserved_1_2 Reserved for future use*/
    int32_t reserved_1_2;
    /*!< reserved_1_3 Reserved for future use*/
    int32_t reserved_1_3;
    /*!< chroma_non_duplication_location Valid when format 420 is configured to provide 422 (2P2Q with SIF count of 4 or 2) and chroma_duplication is disabled. when reset - add the chroma lines w/ the even luma lines, when set - add the chroma lines w/ the odd luma lines*/
    int32_t chroma_non_duplication_location;
    /*!< input_width_msb provides bits [19:16] to the input width resolution*/
    int32_t input_width_msb;
    /*!< output_width_msb provides bits [19:16] to the output width resolution*/
    int32_t output_width_msb;

} ia_pal_isp_io_buffer_1_1_t;

/*! \isp struct irs_1_0

*/
typedef struct
{
    /*!< enable Enable IRS*/
    int32_t enable;
    /*!< passThrough Pass throught algorithm*/
    int32_t passThrough;
    /*!< block_height */
    int32_t block_height;
    /*!< block_width */
    int32_t block_width;
    /*!< top_left_x */
    int32_t top_left_x;
    /*!< top_left_y */
    int32_t top_left_y;
    /*!< interpolation_enable */
    int32_t interpolation_enable;
    /*!< unclipped_a_max */
    int32_t unclipped_a_max;
    /*!< mask_val_Y */
    int32_t mask_val_Y;
    /*!< mask_val_U */
    int32_t mask_val_U;
    /*!< mask_val_V */
    int32_t mask_val_V;
    /*!< mask_val_Z */
    int32_t mask_val_Z;
    /*!< coord_stride stride of the given coordinates grid*/
    int32_t coord_stride;
    /*!< mode MC1/MC2/MCFR/GDC_SP/GDC_FR mode*/
    int32_t mode;

} ia_pal_isp_irs_1_0_t;

/*! \isp struct lca_1_0
Lateral Chromatic Aberration Correction
*/
typedef struct
{
    /*!< radial_enable radial_enable*/
    int32_t radial_enable;
    /*!< grid_enable grid_enable*/
    int32_t grid_enable;
    /*!< bypass bypass flag*/
    int32_t bypass;
    /*!< pixel_format_matrix[4] Bayer type: Gr -> 0, Gb ->1, R -> 2, B -> 3*/
    int32_t pixel_format_matrix[4];
    /*!< rx_initial rx_initial*/
    int32_t rx_initial;
    /*!< ry_initial ry_initial*/
    int32_t ry_initial;
    /*!< opt_center_x opt_center_x*/
    int32_t opt_center_x;
    /*!< opt_center_y opt_center_y*/
    int32_t opt_center_y;
    /*!< bits_per_pixel_in_map_x bits_per_pixel_in_map_x*/
    int32_t bits_per_pixel_in_map_x;
    /*!< bits_per_pixel_in_map_y bits_per_pixel_in_map_y*/
    int32_t bits_per_pixel_in_map_y;
    /*!< grid_shift_map_blue_x[324] grid_shift_map_blue_x*/
    int32_t grid_shift_map_blue_x[324];
    /*!< grid_shift_map_blue_y[324] grid_shift_map_blue_y*/
    int32_t grid_shift_map_blue_y[324];
    /*!< grid_shift_map_red_x[324] grid_shift_map_red_x*/
    int32_t grid_shift_map_red_x[324];
    /*!< grid_shift_map_red_y[324] grid_shift_map_red_y*/
    int32_t grid_shift_map_red_y[324];
    /*!< cu_blue_rad_shift_x[16] cu_blue_rad_shift_x*/
    int32_t cu_blue_rad_shift_x[16];
    /*!< cu_blue_rad_shift_y[15] cu_blue_rad_shift_y*/
    int32_t cu_blue_rad_shift_y[15];
    /*!< cu_blue_rad_shift_slope[15] cu_blue_rad_shift_slope*/
    int32_t cu_blue_rad_shift_slope[15];
    /*!< cu_red_rad_shift_x[16] cu_red_rad_shift_x*/
    int32_t cu_red_rad_shift_x[16];
    /*!< cu_red_rad_shift_y[15] cu_red_rad_shift_y*/
    int32_t cu_red_rad_shift_y[15];
    /*!< cu_red_rad_shift_slope[15] cu_red_rad_shift_slope*/
    int32_t cu_red_rad_shift_slope[15];
    /*!< resample_type resample type: 0 - bilinear, 1 - bicubic*/
    int32_t resample_type;
    /*!< rad_sqr_prec_reduction radius square precision reduction*/
    int32_t rad_sqr_prec_reduction;
    /*!< grid_shift_precision_increment grid shift precision increment*/
    int32_t grid_shift_precision_increment;
    /*!< radial_shift_precision_alignment radial shift precision alignment*/
    int32_t radial_shift_precision_alignment;
    /*!< correction_power sensitivity correction*/
    int32_t correction_power;
    /*!< binning_factor_x binnig factor for x dimension*/
    int32_t binning_factor_x;
    /*!< binning_factor_y binning factor for y dimension*/
    int32_t binning_factor_y;

} ia_pal_isp_lca_1_0_t;

/*! \isp struct ldr_blc_1
LDR black level correction filter
*/
typedef struct
{
    /*!< bl_cc00 Black level, color channel (0,0)*/
    int32_t bl_cc00;
    /*!< bl_cc01 Black level, color channel (0,1)*/
    int32_t bl_cc01;
    /*!< bl_cc10 Black level, color channel (1,0)*/
    int32_t bl_cc10;
    /*!< bl_cc11 Black level, color channel (1,1)*/
    int32_t bl_cc11;

} ia_pal_isp_ldr_blc_1_t;

/*! \isp struct ldr_wb_1
LDR white balance correction filter
*/
typedef struct
{
    /*!< gain_R WB gain, R (fixed point)*/
    int32_t gain_R;
    /*!< gain_Gr WB gain, Gr (fixed point)*/
    int32_t gain_Gr;
    /*!< gain_Gb WB gain, Gb (fixed point)*/
    int32_t gain_Gb;
    /*!< gain_B WB gain, B (fixed point)*/
    int32_t gain_B;
    /*!< gain_fract No. of fractional places in WB gain fixed pt. representation*/
    int32_t gain_fract;
    /*!< saturation_value Saturation value after WB*/
    int32_t saturation_value;

} ia_pal_isp_ldr_wb_1_t;

/*! \isp struct linearization2_0
Linearization
*/
typedef struct
{
    /*!< Linearization2_0_enable Enable Linearization2_0*/
    int32_t Linearization2_0_enable;
    /*!< glu_base_level0[5] GLU base level offset*/
    int32_t glu_base_level0[5];
    /*!< glu_base_level1[5] GLU1 base level offset*/
    int32_t glu_base_level1[5];
    /*!< glu_base_level2[5] GLU2 base level offset*/
    int32_t glu_base_level2[5];
    /*!< glu_base_level3[5] GLU3 base level offset*/
    int32_t glu_base_level3[5];
    /*!< glu_base_level4[5] GLU4 base level offset*/
    int32_t glu_base_level4[5];
    /*!< glu_base_level5[5] GLU5 base level offset*/
    int32_t glu_base_level5[5];
    /*!< glu_base_level6[5] GLU6 base level offset*/
    int32_t glu_base_level6[5];
    /*!< glu_base_level7[5] GLU7 base level offset*/
    int32_t glu_base_level7[5];
    /*!< glu_step0[5] GLU step amount per stage*/
    int32_t glu_step0[5];
    /*!< glu_step1[5] GLU1 step amount per stage*/
    int32_t glu_step1[5];
    /*!< glu_step2[5] GLU2 step amount per stage*/
    int32_t glu_step2[5];
    /*!< glu_step3[5] GLU3 step amount per stage*/
    int32_t glu_step3[5];
    /*!< glu_step4[5] GLU4 step amount per stage*/
    int32_t glu_step4[5];
    /*!< glu_step5[5] GLU5 step amount per stage*/
    int32_t glu_step5[5];
    /*!< glu_step6[5] GLU6 step amount per stage*/
    int32_t glu_step6[5];
    /*!< glu_step7[5] GLU7 step amount per stage*/
    int32_t glu_step7[5];
    /*!< glu_start_bin0[5] GLU stage start offset in LUT*/
    int32_t glu_start_bin0[5];
    /*!< glu_start_bin1[5] GLU stage start offset in LUT1*/
    int32_t glu_start_bin1[5];
    /*!< glu_start_bin2[5] GLU stage start offset in LUT2*/
    int32_t glu_start_bin2[5];
    /*!< glu_start_bin3[5] GLU stage start offset in LUT3*/
    int32_t glu_start_bin3[5];
    /*!< glu_start_bin4[5] GLU stage start offset in LUT4*/
    int32_t glu_start_bin4[5];
    /*!< glu_start_bin5[5] GLU stage start offset in LUT5*/
    int32_t glu_start_bin5[5];
    /*!< glu_start_bin6[5] GLU stage start offset in LUT6*/
    int32_t glu_start_bin6[5];
    /*!< glu_start_bin7[5] GLU stage start offset in LUT7*/
    int32_t glu_start_bin7[5];
    /*!< glu_gen_lut_size0 Utilized LUT size*/
    int32_t glu_gen_lut_size0;
    /*!< glu_gen_lut_size1 Utilized LUT1 size*/
    int32_t glu_gen_lut_size1;
    /*!< glu_gen_lut_size2 Utilized LUT2 size*/
    int32_t glu_gen_lut_size2;
    /*!< glu_gen_lut_size3 Utilized LUT3 size*/
    int32_t glu_gen_lut_size3;
    /*!< glu_gen_lut_size4 Utilized LUT4 size*/
    int32_t glu_gen_lut_size4;
    /*!< glu_gen_lut_size5 Utilized LUT5 size*/
    int32_t glu_gen_lut_size5;
    /*!< glu_gen_lut_size6 Utilized LUT6 size*/
    int32_t glu_gen_lut_size6;
    /*!< glu_gen_lut_size7 Utilized LUT7 size*/
    int32_t glu_gen_lut_size7;
    /*!< glu_gen_lut0[512] LUT samples*/
    int32_t glu_gen_lut0[512];
    /*!< glu_gen_lut1[512] LUT1 samples*/
    int32_t glu_gen_lut1[512];
    /*!< glu_gen_lut2[512] LUT2 samples*/
    int32_t glu_gen_lut2[512];
    /*!< glu_gen_lut3[512] LUT3 samples*/
    int32_t glu_gen_lut3[512];
    /*!< glu_gen_lut4[512] LUT4 samples*/
    int32_t glu_gen_lut4[512];
    /*!< glu_gen_lut5[512] LUT5 samples*/
    int32_t glu_gen_lut5[512];
    /*!< glu_gen_lut6[512] LUT6 samples*/
    int32_t glu_gen_lut6[512];
    /*!< glu_gen_lut7[512] LUT7 samples*/
    int32_t glu_gen_lut7[512];
    /*!< mask0[4] Mask of quad 0*/
    int32_t mask0[4];
    /*!< mask1[4] Mask of quad 1*/
    int32_t mask1[4];
    /*!< mask2[4] Mask of quad 2*/
    int32_t mask2[4];
    /*!< mask3[4] Mask of quad 3*/
    int32_t mask3[4];

} ia_pal_isp_linearization2_0_t;

/*! \isp struct linearization2_0_b
Linearization
*/
typedef struct
{
    /*!< Linearization2_0_enable Enable Linearization2_0*/
    int32_t Linearization2_0_enable;
    /*!< glu_base_level0[5] GLU base level offset*/
    int32_t glu_base_level0[5];
    /*!< glu_base_level1[5] GLU1 base level offset*/
    int32_t glu_base_level1[5];
    /*!< glu_base_level2[5] GLU2 base level offset*/
    int32_t glu_base_level2[5];
    /*!< glu_base_level3[5] GLU3 base level offset*/
    int32_t glu_base_level3[5];
    /*!< glu_base_level4[5] GLU4 base level offset*/
    int32_t glu_base_level4[5];
    /*!< glu_base_level5[5] GLU5 base level offset*/
    int32_t glu_base_level5[5];
    /*!< glu_base_level6[5] GLU6 base level offset*/
    int32_t glu_base_level6[5];
    /*!< glu_base_level7[5] GLU7 base level offset*/
    int32_t glu_base_level7[5];
    /*!< glu_step0[5] GLU step amount per stage*/
    int32_t glu_step0[5];
    /*!< glu_step1[5] GLU1 step amount per stage*/
    int32_t glu_step1[5];
    /*!< glu_step2[5] GLU2 step amount per stage*/
    int32_t glu_step2[5];
    /*!< glu_step3[5] GLU3 step amount per stage*/
    int32_t glu_step3[5];
    /*!< glu_step4[5] GLU4 step amount per stage*/
    int32_t glu_step4[5];
    /*!< glu_step5[5] GLU5 step amount per stage*/
    int32_t glu_step5[5];
    /*!< glu_step6[5] GLU6 step amount per stage*/
    int32_t glu_step6[5];
    /*!< glu_step7[5] GLU7 step amount per stage*/
    int32_t glu_step7[5];
    /*!< glu_start_bin0[5] GLU stage start offset in LUT*/
    int32_t glu_start_bin0[5];
    /*!< glu_start_bin1[5] GLU stage start offset in LUT1*/
    int32_t glu_start_bin1[5];
    /*!< glu_start_bin2[5] GLU stage start offset in LUT2*/
    int32_t glu_start_bin2[5];
    /*!< glu_start_bin3[5] GLU stage start offset in LUT3*/
    int32_t glu_start_bin3[5];
    /*!< glu_start_bin4[5] GLU stage start offset in LUT4*/
    int32_t glu_start_bin4[5];
    /*!< glu_start_bin5[5] GLU stage start offset in LUT5*/
    int32_t glu_start_bin5[5];
    /*!< glu_start_bin6[5] GLU stage start offset in LUT6*/
    int32_t glu_start_bin6[5];
    /*!< glu_start_bin7[5] GLU stage start offset in LUT7*/
    int32_t glu_start_bin7[5];
    /*!< glu_gen_lut_size0 Utilized LUT size*/
    int32_t glu_gen_lut_size0;
    /*!< glu_gen_lut_size1 Utilized LUT1 size*/
    int32_t glu_gen_lut_size1;
    /*!< glu_gen_lut_size2 Utilized LUT2 size*/
    int32_t glu_gen_lut_size2;
    /*!< glu_gen_lut_size3 Utilized LUT3 size*/
    int32_t glu_gen_lut_size3;
    /*!< glu_gen_lut_size4 Utilized LUT4 size*/
    int32_t glu_gen_lut_size4;
    /*!< glu_gen_lut_size5 Utilized LUT5 size*/
    int32_t glu_gen_lut_size5;
    /*!< glu_gen_lut_size6 Utilized LUT6 size*/
    int32_t glu_gen_lut_size6;
    /*!< glu_gen_lut_size7 Utilized LUT7 size*/
    int32_t glu_gen_lut_size7;
    /*!< glu_gen_lut0[512] LUT samples*/
    int32_t glu_gen_lut0[512];
    /*!< glu_gen_lut1[512] LUT1 samples*/
    int32_t glu_gen_lut1[512];
    /*!< glu_gen_lut2[512] LUT2 samples*/
    int32_t glu_gen_lut2[512];
    /*!< glu_gen_lut3[512] LUT3 samples*/
    int32_t glu_gen_lut3[512];
    /*!< glu_gen_lut4[512] LUT4 samples*/
    int32_t glu_gen_lut4[512];
    /*!< glu_gen_lut5[512] LUT5 samples*/
    int32_t glu_gen_lut5[512];
    /*!< glu_gen_lut6[512] LUT6 samples*/
    int32_t glu_gen_lut6[512];
    /*!< glu_gen_lut7[512] LUT7 samples*/
    int32_t glu_gen_lut7[512];
    /*!< mask0[4] Mask of quad 0*/
    int32_t mask0[4];
    /*!< mask1[4] Mask of quad 1*/
    int32_t mask1[4];
    /*!< mask2[4] Mask of quad 2*/
    int32_t mask2[4];
    /*!< mask3[4] Mask of quad 3*/
    int32_t mask3[4];

} ia_pal_isp_linearization2_0_b_t;

/*! \isp struct linearization2_0_c
Linearization
*/
typedef struct
{
    /*!< Linearization2_0_enable Enable Linearization2_0*/
    int32_t Linearization2_0_enable;
    /*!< glu_base_level0[5] GLU base level offset*/
    int32_t glu_base_level0[5];
    /*!< glu_base_level1[5] GLU1 base level offset*/
    int32_t glu_base_level1[5];
    /*!< glu_base_level2[5] GLU2 base level offset*/
    int32_t glu_base_level2[5];
    /*!< glu_base_level3[5] GLU3 base level offset*/
    int32_t glu_base_level3[5];
    /*!< glu_base_level4[5] GLU4 base level offset*/
    int32_t glu_base_level4[5];
    /*!< glu_base_level5[5] GLU5 base level offset*/
    int32_t glu_base_level5[5];
    /*!< glu_base_level6[5] GLU6 base level offset*/
    int32_t glu_base_level6[5];
    /*!< glu_base_level7[5] GLU7 base level offset*/
    int32_t glu_base_level7[5];
    /*!< glu_step0[5] GLU step amount per stage*/
    int32_t glu_step0[5];
    /*!< glu_step1[5] GLU1 step amount per stage*/
    int32_t glu_step1[5];
    /*!< glu_step2[5] GLU2 step amount per stage*/
    int32_t glu_step2[5];
    /*!< glu_step3[5] GLU3 step amount per stage*/
    int32_t glu_step3[5];
    /*!< glu_step4[5] GLU4 step amount per stage*/
    int32_t glu_step4[5];
    /*!< glu_step5[5] GLU5 step amount per stage*/
    int32_t glu_step5[5];
    /*!< glu_step6[5] GLU6 step amount per stage*/
    int32_t glu_step6[5];
    /*!< glu_step7[5] GLU7 step amount per stage*/
    int32_t glu_step7[5];
    /*!< glu_start_bin0[5] GLU stage start offset in LUT*/
    int32_t glu_start_bin0[5];
    /*!< glu_start_bin1[5] GLU stage start offset in LUT1*/
    int32_t glu_start_bin1[5];
    /*!< glu_start_bin2[5] GLU stage start offset in LUT2*/
    int32_t glu_start_bin2[5];
    /*!< glu_start_bin3[5] GLU stage start offset in LUT3*/
    int32_t glu_start_bin3[5];
    /*!< glu_start_bin4[5] GLU stage start offset in LUT4*/
    int32_t glu_start_bin4[5];
    /*!< glu_start_bin5[5] GLU stage start offset in LUT5*/
    int32_t glu_start_bin5[5];
    /*!< glu_start_bin6[5] GLU stage start offset in LUT6*/
    int32_t glu_start_bin6[5];
    /*!< glu_start_bin7[5] GLU stage start offset in LUT7*/
    int32_t glu_start_bin7[5];
    /*!< glu_gen_lut_size0 Utilized LUT size*/
    int32_t glu_gen_lut_size0;
    /*!< glu_gen_lut_size1 Utilized LUT1 size*/
    int32_t glu_gen_lut_size1;
    /*!< glu_gen_lut_size2 Utilized LUT2 size*/
    int32_t glu_gen_lut_size2;
    /*!< glu_gen_lut_size3 Utilized LUT3 size*/
    int32_t glu_gen_lut_size3;
    /*!< glu_gen_lut_size4 Utilized LUT4 size*/
    int32_t glu_gen_lut_size4;
    /*!< glu_gen_lut_size5 Utilized LUT5 size*/
    int32_t glu_gen_lut_size5;
    /*!< glu_gen_lut_size6 Utilized LUT6 size*/
    int32_t glu_gen_lut_size6;
    /*!< glu_gen_lut_size7 Utilized LUT7 size*/
    int32_t glu_gen_lut_size7;
    /*!< glu_gen_lut0[512] LUT samples*/
    int32_t glu_gen_lut0[512];
    /*!< glu_gen_lut1[512] LUT1 samples*/
    int32_t glu_gen_lut1[512];
    /*!< glu_gen_lut2[512] LUT2 samples*/
    int32_t glu_gen_lut2[512];
    /*!< glu_gen_lut3[512] LUT3 samples*/
    int32_t glu_gen_lut3[512];
    /*!< glu_gen_lut4[512] LUT4 samples*/
    int32_t glu_gen_lut4[512];
    /*!< glu_gen_lut5[512] LUT5 samples*/
    int32_t glu_gen_lut5[512];
    /*!< glu_gen_lut6[512] LUT6 samples*/
    int32_t glu_gen_lut6[512];
    /*!< glu_gen_lut7[512] LUT7 samples*/
    int32_t glu_gen_lut7[512];
    /*!< mask0[4] Mask of quad 0*/
    int32_t mask0[4];
    /*!< mask1[4] Mask of quad 1*/
    int32_t mask1[4];
    /*!< mask2[4] Mask of quad 2*/
    int32_t mask2[4];
    /*!< mask3[4] Mask of quad 3*/
    int32_t mask3[4];

} ia_pal_isp_linearization2_0_c_t;

/*! \isp struct linearization2hdr

*/
typedef struct
{
    /*!< bypass */
    int32_t bypass;
    /*!< lut_vec_00[128] */
    int32_t lut_vec_00[128];
    /*!< lut_vec_01[128] */
    int32_t lut_vec_01[128];
    /*!< lut_vec_10[128] */
    int32_t lut_vec_10[128];
    /*!< lut_vec_11[128] */
    int32_t lut_vec_11[128];
    /*!< base_level[16] */
    int32_t base_level[16];
    /*!< start_bin[16] */
    int32_t start_bin[16];
    /*!< step[16] */
    int32_t step[16];
    /*!< slope_vec_00[128] */
    int32_t slope_vec_00[128];
    /*!< slope_vec_01[128] */
    int32_t slope_vec_01[128];
    /*!< slope_vec_10[128] */
    int32_t slope_vec_10[128];
    /*!< slope_vec_11[128] */
    int32_t slope_vec_11[128];
    /*!< slope_resolution[16] */
    int32_t slope_resolution[16];

} ia_pal_isp_linearization2hdr_t;

/*! \isp struct linearizationdg_dss

*/
typedef struct
{
    /*!< cfa_type cfa type 0=1x1 1=2x2 2=4x4*/
    int32_t cfa_type;
    /*!< linc00[65] linearization grid table*/
    int32_t linc00[65];
    /*!< linc01[65] linearization grid table*/
    int32_t linc01[65];
    /*!< linc02[65] linearization grid table*/
    int32_t linc02[65];
    /*!< linc03[65] linearization grid table*/
    int32_t linc03[65];
    /*!< linc10[65] linearization grid table*/
    int32_t linc10[65];
    /*!< linc11[65] linearization grid table*/
    int32_t linc11[65];
    /*!< linc12[65] linearization grid table*/
    int32_t linc12[65];
    /*!< linc13[65] linearization grid table*/
    int32_t linc13[65];
    /*!< linc20[65] linearization grid table*/
    int32_t linc20[65];
    /*!< linc21[65] linearization grid table*/
    int32_t linc21[65];
    /*!< linc22[65] linearization grid table*/
    int32_t linc22[65];
    /*!< linc23[65] linearization grid table*/
    int32_t linc23[65];
    /*!< linc30[65] linearization grid table*/
    int32_t linc30[65];
    /*!< linc31[65] linearization grid table*/
    int32_t linc31[65];
    /*!< linc32[65] linearization grid table*/
    int32_t linc32[65];
    /*!< linc33[65] linearization grid table*/
    int32_t linc33[65];
    /*!< bypass bypass for the filter*/
    int32_t bypass;

} ia_pal_isp_linearizationdg_dss_t;

/*! \isp struct linearizationwb_dss

*/
typedef struct
{
    /*!< cfa_type cfa type 0=1x1 1=2x2 2=4x4*/
    int32_t cfa_type;
    /*!< linc00[65] linearization grid table*/
    int32_t linc00[65];
    /*!< linc01[65] linearization grid table*/
    int32_t linc01[65];
    /*!< linc02[65] linearization grid table*/
    int32_t linc02[65];
    /*!< linc03[65] linearization grid table*/
    int32_t linc03[65];
    /*!< linc10[65] linearization grid table*/
    int32_t linc10[65];
    /*!< linc11[65] linearization grid table*/
    int32_t linc11[65];
    /*!< linc12[65] linearization grid table*/
    int32_t linc12[65];
    /*!< linc13[65] linearization grid table*/
    int32_t linc13[65];
    /*!< linc20[65] linearization grid table*/
    int32_t linc20[65];
    /*!< linc21[65] linearization grid table*/
    int32_t linc21[65];
    /*!< linc22[65] linearization grid table*/
    int32_t linc22[65];
    /*!< linc23[65] linearization grid table*/
    int32_t linc23[65];
    /*!< linc30[65] linearization grid table*/
    int32_t linc30[65];
    /*!< linc31[65] linearization grid table*/
    int32_t linc31[65];
    /*!< linc32[65] linearization grid table*/
    int32_t linc32[65];
    /*!< linc33[65] linearization grid table*/
    int32_t linc33[65];
    /*!< bypass bypass for the filter*/
    int32_t bypass;

} ia_pal_isp_linearizationwb_dss_t;

/*! \isp struct lossycomp_1_0
Lossy compression for DDR
*/
typedef struct
{
    /*!< enable enable the lossy compression*/
    int32_t enable;

} ia_pal_isp_lossycomp_1_0_t;

/*! \isp struct lossydecomp_1_0
Lossy decompression for DDR
*/
typedef struct
{
    /*!< enable enable the lossy decompression*/
    int32_t enable;

} ia_pal_isp_lossydecomp_1_0_t;

/*! \isp struct lsc_1_1

*/
typedef struct
{
    /*!< cfa_type cfa type 0=1x1 1=2x2 2=4x4*/
    int32_t cfa_type;
    /*!< lsclog2gridwidth log2 width of each subplane*/
    int32_t lsclog2gridwidth;
    /*!< lsclog2gridheight log2 height of each subplane*/
    int32_t lsclog2gridheight;
    /*!< lsc_col_start X value of top left corner of sensor relative to ROI*/
    int32_t lsc_col_start;
    /*!< lsc_row_start Y value of top left corner of sensor relative to ROI*/
    int32_t lsc_row_start;
    /*!< lsc_exp resolution modifier of the lsc tables*/
    int32_t lsc_exp;
    /*!< lsc_grid_tablec00[4096] lsc grid table*/
    int32_t lsc_grid_tablec00[4096];
    /*!< lsc_grid_tablec01[4096] lsc grid table*/
    int32_t lsc_grid_tablec01[4096];
    /*!< lsc_grid_tablec02[4096] lsc grid table*/
    int32_t lsc_grid_tablec02[4096];
    /*!< lsc_grid_tablec03[4096] lsc grid table*/
    int32_t lsc_grid_tablec03[4096];
    /*!< lsc_grid_tablec10[4096] lsc grid table*/
    int32_t lsc_grid_tablec10[4096];
    /*!< lsc_grid_tablec11[4096] lsc grid table*/
    int32_t lsc_grid_tablec11[4096];
    /*!< lsc_grid_tablec12[4096] lsc grid table*/
    int32_t lsc_grid_tablec12[4096];
    /*!< lsc_grid_tablec13[4096] lsc grid table*/
    int32_t lsc_grid_tablec13[4096];
    /*!< lsc_grid_tablec20[4096] lsc grid table*/
    int32_t lsc_grid_tablec20[4096];
    /*!< lsc_grid_tablec21[4096] lsc grid table*/
    int32_t lsc_grid_tablec21[4096];
    /*!< lsc_grid_tablec22[4096] lsc grid table*/
    int32_t lsc_grid_tablec22[4096];
    /*!< lsc_grid_tablec23[4096] lsc grid table*/
    int32_t lsc_grid_tablec23[4096];
    /*!< lsc_grid_tablec30[4096] lsc grid table*/
    int32_t lsc_grid_tablec30[4096];
    /*!< lsc_grid_tablec31[4096] lsc grid table*/
    int32_t lsc_grid_tablec31[4096];
    /*!< lsc_grid_tablec32[4096] lsc grid table*/
    int32_t lsc_grid_tablec32[4096];
    /*!< lsc_grid_tablec33[4096] lsc grid table*/
    int32_t lsc_grid_tablec33[4096];
    /*!< lsc_table_width table width*/
    int32_t lsc_table_width;
    /*!< lsc_table_height table height*/
    int32_t lsc_table_height;
    /*!< bypass bypass for the filter*/
    int32_t bypass;
    /*!< bypass_compression bypass for the compression/decompression*/
    int32_t bypass_compression;
    /*!< cu_compression_x[8] U.20 cu_compression_x*/
    int32_t cu_compression_x[8];
    /*!< cu_compression_y[7] U.15 cu_compression_y*/
    int32_t cu_compression_y[7];
    /*!< cu_compression_slope[7] U.1.10 cu_compression_slope (11 bit)*/
    int32_t cu_compression_slope[7];
    /*!< cu_decompression_x[8] U.15 cu_decompression_y*/
    int32_t cu_decompression_x[8];
    /*!< cu_decompression_y[7] U.20 cu_decompression_x*/
    int32_t cu_decompression_y[7];
    /*!< cu_decompression_slope[7] U.8.6 cu_decompression_slope (14 bit)*/
    int32_t cu_decompression_slope[7];

} ia_pal_isp_lsc_1_1_t;

/*! \isp struct lsc_1_2
Lens shading correction up to 24 bit
*/
typedef struct
{
    /*!< cfa_type cfa type 0=1x1 1=2x2 2=4x4*/
    int32_t cfa_type;
    /*!< lsclog2gridwidth log2 width of each subplane*/
    int32_t lsclog2gridwidth;
    /*!< lsclog2gridheight log2 height of each subplane*/
    int32_t lsclog2gridheight;
    /*!< lsc_col_start X value of top left corner of sensor relative to ROI*/
    int32_t lsc_col_start;
    /*!< lsc_row_start Y value of top left corner of sensor relative to ROI*/
    int32_t lsc_row_start;
    /*!< lsc_exp resolution modifier of the lsc tables*/
    int32_t lsc_exp;
    /*!< lsc_grid_tablec00[4096] lsc grid table*/
    int32_t lsc_grid_tablec00[4096];
    /*!< lsc_grid_tablec01[4096] lsc grid table*/
    int32_t lsc_grid_tablec01[4096];
    /*!< lsc_grid_tablec02[4096] lsc grid table*/
    int32_t lsc_grid_tablec02[4096];
    /*!< lsc_grid_tablec03[4096] lsc grid table*/
    int32_t lsc_grid_tablec03[4096];
    /*!< lsc_grid_tablec10[4096] lsc grid table*/
    int32_t lsc_grid_tablec10[4096];
    /*!< lsc_grid_tablec11[4096] lsc grid table*/
    int32_t lsc_grid_tablec11[4096];
    /*!< lsc_grid_tablec12[4096] lsc grid table*/
    int32_t lsc_grid_tablec12[4096];
    /*!< lsc_grid_tablec13[4096] lsc grid table*/
    int32_t lsc_grid_tablec13[4096];
    /*!< lsc_grid_tablec20[4096] lsc grid table*/
    int32_t lsc_grid_tablec20[4096];
    /*!< lsc_grid_tablec21[4096] lsc grid table*/
    int32_t lsc_grid_tablec21[4096];
    /*!< lsc_grid_tablec22[4096] lsc grid table*/
    int32_t lsc_grid_tablec22[4096];
    /*!< lsc_grid_tablec23[4096] lsc grid table*/
    int32_t lsc_grid_tablec23[4096];
    /*!< lsc_grid_tablec30[4096] lsc grid table*/
    int32_t lsc_grid_tablec30[4096];
    /*!< lsc_grid_tablec31[4096] lsc grid table*/
    int32_t lsc_grid_tablec31[4096];
    /*!< lsc_grid_tablec32[4096] lsc grid table*/
    int32_t lsc_grid_tablec32[4096];
    /*!< lsc_grid_tablec33[4096] lsc grid table*/
    int32_t lsc_grid_tablec33[4096];
    /*!< lsc_table_width table width*/
    int32_t lsc_table_width;
    /*!< lsc_table_height table height*/
    int32_t lsc_table_height;
    /*!< bypass bypass for the filter*/
    int32_t bypass;
    /*!< enable_compand enable for the (de)companding*/
    int32_t enable_compand;
    /*!< cu_compression_x[13] U.24 linear, default log-limited*/
    int32_t cu_compression_x[13];
    /*!< cu_compression_y[12] U.15 companded output*/
    int32_t cu_compression_y[12];
    /*!< cu_compression_slope[12] U1.14 15bit slopes for companding*/
    int32_t cu_compression_slope[12];
    /*!< cu_decompression_x[13] U.15 companded input, default log-limited*/
    int32_t cu_decompression_x[13];
    /*!< cu_decompression_y[12] U.24 linear*/
    int32_t cu_decompression_y[12];
    /*!< cu_decompression_slope[12] U20.6 26bit slopes for decompanding*/
    int32_t cu_decompression_slope[12];
    /*!< linear_pedestal Pedestal subtracted (and added later) in linear domain, U.24*/
    int32_t linear_pedestal;
    /*!< use_pedestal If true, pedestal is used and the companded signal should be U15. If false, linear_pedestal should be 0*/
    int32_t use_pedestal;

} ia_pal_isp_lsc_1_2_t;

/*! \isp struct ltm_cd_1_0
Local Tone Maping Coarse Detail Extruction
*/
typedef struct
{
    /*!< enable enabling the block. If enable == false, Output is zero*/
    int32_t enable;
    /*!< LTM_Power_8 Power gain for 1/8 band*/
    int32_t LTM_Power_8;
    /*!< LTM_Power_16 Power gain for 1/16 band*/
    int32_t LTM_Power_16;
    /*!< cu_thr8_x[15] threshold for variance - x values*/
    int32_t cu_thr8_x[15];
    /*!< cu_thr8_y[14] threshold for variance - y values*/
    int32_t cu_thr8_y[14];
    /*!< cu_thr8_slopes[14] threshold for variance - slopes values*/
    int32_t cu_thr8_slopes[14];
    /*!< cu_thr16_x[15] threshold for variance - x values*/
    int32_t cu_thr16_x[15];
    /*!< cu_thr16_y[14] threshold for variance - y values*/
    int32_t cu_thr16_y[14];
    /*!< cu_thr16_slopes[14] threshold for variance - slopes values*/
    int32_t cu_thr16_slopes[14];
    /*!< cu_sqrt_x[15] sqrt-x values*/
    int32_t cu_sqrt_x[15];
    /*!< cu_sqrt_y[14] sqrt-y values*/
    int32_t cu_sqrt_y[14];
    /*!< cu_sqrt_slopes[14] sqrt-slopes values*/
    int32_t cu_sqrt_slopes[14];
    /*!< cu_gtm_x[15] gtm-x values*/
    int32_t cu_gtm_x[15];
    /*!< cu_gtm_y[14] gtm-y values*/
    int32_t cu_gtm_y[14];
    /*!< cu_gtm_slopes[14] gtm-slopes values*/
    int32_t cu_gtm_slopes[14];
    /*!< gradual_saturation_on enable gradual saturaion*/
    int32_t gradual_saturation_on;
    /*!< frame_width width of current frame*/
    int32_t frame_width;
    /*!< frame_height only for HW purposes*/
    int32_t frame_height;
    /*!< luma_correction_on enable luma correction*/
    int32_t luma_correction_on;

} ia_pal_isp_ltm_cd_1_0_t;

/*! \isp struct ltm_de_gamma_1_0

*/
typedef struct
{
    /*!< enable enable for the filter*/
    int32_t enable;
    /*!< enable_decomp enabling the tone mapping*/
    int32_t enable_decomp;
    /*!< enable_gtm enabling the tone mapping*/
    int32_t enable_gtm;
    /*!< enable_df enabling the ltm*/
    int32_t enable_df;
    /*!< enable_gamma enabling the gamma*/
    int32_t enable_gamma;
    /*!< gamma_lut_base_level[8] base level for gamma lut*/
    int32_t gamma_lut_base_level[8];
    /*!< gamma_lut_step[8] step for gamma lut*/
    int32_t gamma_lut_step[8];
    /*!< gamma_lut_start_bin[8] start bin for gamma lut*/
    int32_t gamma_lut_start_bin[8];
    /*!< gamma_lut_size gamma lut size*/
    int32_t gamma_lut_size;
    /*!< gamma_lut_gen_lut[1537] generalized lut for gamma lut*/
    int32_t gamma_lut_gen_lut[1537];
    /*!< tm_lut_base_level[7] base level for  tone mapping lut*/
    int32_t tm_lut_base_level[7];
    /*!< tm_lut_start_bin[7] start bin for  tone mapping lut*/
    int32_t tm_lut_start_bin[7];
    /*!< tm_lut_size tone mapping lut size*/
    int32_t tm_lut_size;
    /*!< tm_lut_step[7] step size for generalized LUT*/
    int32_t tm_lut_step[7];
    /*!< tm_lut_gen_lut[2049] generalized lut for tone mapping lut. The lut is with the fixed point format 9.10*/
    int32_t tm_lut_gen_lut[2049];
    /*!< gtm_gain_shift shift for gain*/
    int32_t gtm_gain_shift;
    /*!< cu_decompand_x[13] cu_decompand_x*/
    int32_t cu_decompand_x[13];
    /*!< cu_decompand_y[12] cu_decompand_y*/
    int32_t cu_decompand_y[12];
    /*!< cu_decompand_slopes[12] cu_decompand_slopes*/
    int32_t cu_decompand_slopes[12];
    /*!< linear_pedestal Pedestal subtracted in linear domain*/
    int32_t linear_pedestal;
    /*!< use_pedestal If true, pedestal is used and the companded signal should be U15. If false, linear_pedestal should be 0*/
    int32_t use_pedestal;

} ia_pal_isp_ltm_de_gamma_1_0_t;

/*! \isp struct ltm_fd_1_0
Local Tone Maping Fine Detail Extruction
*/
typedef struct
{
    /*!< enable enabling the block. If enable == false, Output is zero*/
    int32_t enable;
    /*!< LTM_Power_4 Power gain for 1/4 band*/
    int32_t LTM_Power_4;
    /*!< LTM_Power_2 Power gain for 1/2 band*/
    int32_t LTM_Power_2;
    /*!< LTM_Power_1 Power gain for full band*/
    int32_t LTM_Power_1;
    /*!< cu_thr1_x[15] threshold for variance - x values*/
    int32_t cu_thr1_x[15];
    /*!< cu_thr1_y[14] threshold for variance - y values*/
    int32_t cu_thr1_y[14];
    /*!< cu_thr1_slopes[14] threshold for variance - slopes values*/
    int32_t cu_thr1_slopes[14];
    /*!< cu_thr2_x[15] threshold for variance - x values*/
    int32_t cu_thr2_x[15];
    /*!< cu_thr2_y[14] threshold for variance - y values*/
    int32_t cu_thr2_y[14];
    /*!< cu_thr2_slopes[14] threshold for variance - slopes values*/
    int32_t cu_thr2_slopes[14];
    /*!< cu_thr4_x[15] threshold for variance - x values*/
    int32_t cu_thr4_x[15];
    /*!< cu_thr4_y[14] threshold for variance - y values*/
    int32_t cu_thr4_y[14];
    /*!< cu_thr4_slopes[14] threshold for variance - slopes values*/
    int32_t cu_thr4_slopes[14];
    /*!< cu_sqrt_x[15] sqrt-x values*/
    int32_t cu_sqrt_x[15];
    /*!< cu_sqrt_y[14] sqrt-y values*/
    int32_t cu_sqrt_y[14];
    /*!< cu_sqrt_slopes[14] sqrt-slopes values*/
    int32_t cu_sqrt_slopes[14];
    /*!< cu_gtm_x[15] gtm-x values*/
    int32_t cu_gtm_x[15];
    /*!< cu_gtm_y[14] gtm-y values*/
    int32_t cu_gtm_y[14];
    /*!< cu_gtm_slopes[14] gtm-slopes values*/
    int32_t cu_gtm_slopes[14];
    /*!< gradual_saturation_on enable gradual saturaion*/
    int32_t gradual_saturation_on;
    /*!< luma_correction_on enable luma correction*/
    int32_t luma_correction_on;
    /*!< cu_norm_x[15] norm-x values*/
    int32_t cu_norm_x[15];
    /*!< cu_norm_y[14] norm-y values*/
    int32_t cu_norm_y[14];
    /*!< cu_norm_slopes[14] norm-slopes values*/
    int32_t cu_norm_slopes[14];
    /*!< frame_height frame height - only for HW needs*/
    int32_t frame_height;
    /*!< frame_width frame width - only for HW needs*/
    int32_t frame_width;

} ia_pal_isp_ltm_fd_1_0_t;

/*! \isp struct ltm_vrt_ctrl

*/
typedef struct
{
    /*!< frame_height height of current frame*/
    int32_t frame_height;
    /*!< frame_width width of current frame*/
    int32_t frame_width;

} ia_pal_isp_ltm_vrt_ctrl_t;

/*! \isp struct mas
Motion artifact suppression ofr IMX185
*/
typedef struct
{
    /*!< gain_motion Threshold for MapMotion*/
    int32_t gain_motion;
    /*!< th_low_r Threshold for MapRange Rmin*/
    int32_t th_low_r;
    /*!< th_high_r Threshold for MapRange Gmax*/
    int32_t th_high_r;
    /*!< th_low_g Threshold for MapRange Gmin*/
    int32_t th_low_g;
    /*!< th_high_g Threshold for MapRange Gmax*/
    int32_t th_high_g;
    /*!< th_low_b Threshold for MapRange Bmin*/
    int32_t th_low_b;
    /*!< th_high_b Threshold for MapRange Bmax*/
    int32_t th_high_b;
    /*!< index_color Gain for MapColor*/
    int32_t index_color;
    /*!< offset_color Offset for MapColor*/
    int32_t offset_color;
    /*!< th_map Threshold for Map*/
    int32_t th_map;
    /*!< enable enable:1, bypass:0*/
    int32_t enable;
    /*!< frame_id first frame:0, second or after:1*/
    int32_t frame_id;
    /*!< flag_by Flag for color map. 0:magenta/green, 1:blue/yellow*/
    int32_t flag_by;

} ia_pal_isp_mas_t;

/*! \isp struct mrc_1_0
Motion refinement and compensation - standalone algorithm
*/
typedef struct
{
    /*!< bypass bypass*/
    int32_t bypass;
    /*!< reference_image_bittage bittage of reference input image*/
    int32_t reference_image_bittage;
    /*!< low_res_search_range_y low res search range - bottom*/
    int32_t low_res_search_range_y;
    /*!< low_res_search_range_x low res search range - left*/
    int32_t low_res_search_range_x;
    /*!< invalid_search_edge_y motion refinement range - bottom*/
    int32_t invalid_search_edge_y;
    /*!< invalid_search_edge_x motion refinement range - left*/
    int32_t invalid_search_edge_x;
    /*!< SAD_chroma_weight weight of chroma in SAD calculation*/
    int32_t SAD_chroma_weight;
    /*!< std_thr_flat confidenceSTD lower limit (dY below this value considered flat)*/
    int32_t std_thr_flat;
    /*!< std_thr_info confidenceSTD upper limit (dY above this value considered informative)*/
    int32_t std_thr_info;
    /*!< alpha_confidence bla bla*/
    int32_t alpha_confidence;
    /*!< center_motion_bias_LUT[18] bla bla*/
    int32_t center_motion_bias_LUT[18];
    /*!< neighbor_motion_bias_LUT[18] bla bla*/
    int32_t neighbor_motion_bias_LUT[18];
    /*!< full_res_center_bias_LUT[18] bla bla*/
    int32_t full_res_center_bias_LUT[18];
    /*!< full_res_neighbor_bias_LUT[18] bla bla*/
    int32_t full_res_neighbor_bias_LUT[18];
    /*!< motion_magnitude_low bla bla*/
    int32_t motion_magnitude_low;
    /*!< motion_magnitude_coeff bla bla*/
    int32_t motion_magnitude_coeff;
    /*!< motion_magnitude_platau bla bla*/
    int32_t motion_magnitude_platau;
    /*!< rad_sqr_prec_reduction Bit shift bumber to calculate index for nm_R_xcu*/
    int32_t rad_sqr_prec_reduction;
    /*!< ry_initial Opical center y coordinate in chroma resolution*/
    int32_t ry_initial;
    /*!< rx_initial Opical center x coordinate in chroma resolution*/
    int32_t rx_initial;
    /*!< nm_R_xcu[128] LUT for radial noise model*/
    int32_t nm_R_xcu[128];
    /*!< nm_Y_xcu[128] LUT for C noise model – Y dependency*/
    int32_t nm_Y_xcu[128];
    /*!< nm_C_xcu[128] LUT for C noise model – C dependency*/
    int32_t nm_C_xcu[128];
    /*!< nm_Y_log_est_min Min value for log space Y noise model*/
    int32_t nm_Y_log_est_min;
    /*!< nm_Y_log_est_max Max value for log space Y noise model*/
    int32_t nm_Y_log_est_max;
    /*!< nm_C_log_est_min Min value for log space C noise model*/
    int32_t nm_C_log_est_min;
    /*!< nm_C_log_est_max Max value for log space C noise model*/
    int32_t nm_C_log_est_max;
    /*!< nm_lut_frac Fractional bit for noise model LUT*/
    int32_t nm_lut_frac;
    /*!< nm_idx_frac Bit number for adjusting to POW LUT index*/
    int32_t nm_idx_frac;
    /*!< nm_pow[64] LUT for power function*/
    int32_t nm_pow[64];
    /*!< nm_pow_frac Fractional bit for POW LUT*/
    int32_t nm_pow_frac;
    /*!< nm_shift_num Pre-calculation of nm_lut_frac - nm_idx_frac*/
    int32_t nm_shift_num;
    /*!< nm_Y_alpha Scaling coefficient for Y noise model*/
    int32_t nm_Y_alpha;
    /*!< nm_C_alpha Scaling coefficient for C noise model*/
    int32_t nm_C_alpha;
    /*!< co_var_thres Variance threshold*/
    int32_t co_var_thres;
    /*!< co_var_gain Variance gain*/
    int32_t co_var_gain;
    /*!< alignment_control Control alignement confidence*/
    int32_t alignment_control;
    /*!< alignment_confidence_control Control alignement confidence*/
    int32_t alignment_confidence_control;
    /*!< min_normed_sad minimal normed y sad value*/
    int32_t min_normed_sad;
    /*!< max_normed_sad maximal normed y sad value*/
    int32_t max_normed_sad;
    /*!< min_normed_sad_c minimal normed c sad value*/
    int32_t min_normed_sad_c;
    /*!< max_normed_sad_c maximal normed c sad value*/
    int32_t max_normed_sad_c;
    /*!< input_bpp bit reduction in feedback loop*/
    int32_t input_bpp;
    /*!< output_bpp bit reduction in feedback loop*/
    int32_t output_bpp;

} ia_pal_isp_mrc_1_0_t;

/*! \isp struct norm_lin_dss

*/
typedef struct
{
    /*!< lut[257] Normalization lut*/
    int32_t lut[257];
    /*!< lin_en Linearization enable*/
    int32_t lin_en;
    /*!< lshift The size of normalized shift (signed)*/
    int32_t lshift;
    /*!< bypass bypass*/
    int32_t bypass;

} ia_pal_isp_norm_lin_dss_t;

/*! \isp struct nrf_6_00

*/
typedef struct
{
    /*!< Bypass iBypass*/
    int32_t Bypass;
    /*!< GNE_consistency_check iGNE consistency check*/
    int32_t GNE_consistency_check;
    /*!< GNE_luma_threshold_for_consistency_check iGNE luma threshold for consistency check*/
    int32_t GNE_luma_threshold_for_consistency_check;
    /*!< GNE_chroma_threshold_for_consistency_check iGNE chroma threshold for consistency check*/
    int32_t GNE_chroma_threshold_for_consistency_check;
    /*!< Block_Noise_Estimate_Edge_Threshold iBlock Noise Estimate Edge Threshold (u14)*/
    int32_t Block_Noise_Estimate_Edge_Threshold;
    /*!< Block_Noise_Estimate_Noise_Threshold iBlock Noise Estimate Noise Threshold (u14)*/
    int32_t Block_Noise_Estimate_Noise_Threshold;
    /*!< Eight_edge_Threshold iEight-edge Threshold (u16)*/
    int32_t Eight_edge_Threshold;
    /*!< Valid_Pixel_Range iValid Pixel Range (u12)*/
    int32_t Valid_Pixel_Range;
    /*!< Small_Sobel_Threshold iSmall Sobel Threshold (u14)*/
    int32_t Small_Sobel_Threshold;
    /*!< Large_Sobel_Threshold iLarge Sobel Threshold (u14)*/
    int32_t Large_Sobel_Threshold;
    /*!< Number_of_Large_Sobel_Threshold iNumber of Large Sobel Threshold (u6)*/
    int32_t Number_of_Large_Sobel_Threshold;
    /*!< Number_of_Mediam_Sobel_Threshold iNumber of Mediam Sobel Threshold (u6)*/
    int32_t Number_of_Mediam_Sobel_Threshold;
    /*!< Number_of_Small_Sobel_Threshold iNumber of Small Sobel Threshold (u6)*/
    int32_t Number_of_Small_Sobel_Threshold;
    /*!< Block_Sigma_Diff_Threshold iBlock Sigma Diff Threshold (u14)*/
    int32_t Block_Sigma_Diff_Threshold;
    /*!< Max_Sobel_Threshold iMax Sobel Threshold (u14)*/
    int32_t Max_Sobel_Threshold;
    /*!< Denoise_Maximum_History iDenoise Maximum History (u8)*/
    int32_t Denoise_Maximum_History;
    /*!< Denoise_History_Increase iDenoise History Increase (u4)*/
    int32_t Denoise_History_Increase;
    /*!< Denoise_Moving_Pixel_Threshold iDenoise Moving Pixel Threshold (u5)*/
    int32_t Denoise_Moving_Pixel_Threshold;
    /*!< Denoise_Threshold_for_Sum_of_Complexity_Measure iDenoise Threshold for Sum of Complexity Measure (u12)*/
    int32_t Denoise_Threshold_for_Sum_of_Complexity_Measure;
    /*!< Denoise_ASD_Threshold iDenoise ASD Threshold (u12)*/
    int32_t Denoise_ASD_Threshold;
    /*!< Progressive_DN iProgressive DN (0, 1)*/
    int32_t Progressive_DN;
    /*!< Initial_Denoise_History iInitial Denoise History (u6)*/
    int32_t Initial_Denoise_History;
    /*!< Denoise_STAD_Threshold iDenoise STAD Threshold (u15)*/
    int32_t Denoise_STAD_Threshold;
    /*!< Temporal_Difference_Threshold iTemporal Difference Threshold (u12)*/
    int32_t Temporal_Difference_Threshold;
    /*!< Low_Temporal_Difference_Threshold iLow Temporal Difference Threshold (u12)*/
    int32_t Low_Temporal_Difference_Threshold;
    /*!< Chroma_Denoise_Enable iChroma Denoise Enable*/
    int32_t Chroma_Denoise_Enable;
    /*!< Chroma_Denoise_Moving_Pixel_Threshold iChroma Denoise Moving Pixel Threshold (u5)*/
    int32_t Chroma_Denoise_Moving_Pixel_Threshold;
    /*!< Chroma_Denoise_Threshold_for_Sum_of_Complexity_Measure iChroma Denoise Threshold for Sum of Complexity Measure (u12)*/
    int32_t Chroma_Denoise_Threshold_for_Sum_of_Complexity_Measure;
    /*!< Chroma_Denoise_ASD_Threshold iChroma Denoise ASD Threshold (u12)*/
    int32_t Chroma_Denoise_ASD_Threshold;
    /*!< Chroma_Denoise_Temporal_Difference_Threshold iChroma Denoise Temporal Difference Threshold (u12)*/
    int32_t Chroma_Denoise_Temporal_Difference_Threshold;
    /*!< Chroma_Low_Temporal_Difference_Threshold iChroma Low Temporal Difference Threshold (u12)*/
    int32_t Chroma_Low_Temporal_Difference_Threshold;
    /*!< Chroma_Denoise_STAD_Threshold iChroma Denoise STAD Threshold (u15)*/
    int32_t Chroma_Denoise_STAD_Threshold;
    /*!< Low_Noise_Level iLow Noise Level*/
    int32_t Low_Noise_Level;
    /*!< Strong_Noise_Level iStrong Noise Level*/
    int32_t Strong_Noise_Level;
    /*!< DnY_prt0 iDnY_prt0 (RangeThreshold 0, u13)*/
    int32_t DnY_prt0;
    /*!< DnY_prt1 iDnY_prt1 (RangeThreshold 1, u13)*/
    int32_t DnY_prt1;
    /*!< DnY_prt2 iDnY_prt2 (RangeThreshold 2, u13)*/
    int32_t DnY_prt2;
    /*!< DnY_prt3 iDnY_prt3 (RangeThreshold 3, u13)*/
    int32_t DnY_prt3;
    /*!< DnY_prt4 iDnY_prt4 (RangeThreshold 4, u13)*/
    int32_t DnY_prt4;
    /*!< DnY_prt5 iDnY_prt5 (RangeThreshold 5, u13)*/
    int32_t DnY_prt5;
    /*!< DnY_Wr0 iDnY_Wr0 (RangeWgt0, u5)*/
    int32_t DnY_Wr0;
    /*!< DnY_Wr1 iDnY_Wr1 (RangeWgt1, u5)*/
    int32_t DnY_Wr1;
    /*!< DnY_Wr2 iDnY_Wr2 (RangeWgt2, u5)*/
    int32_t DnY_Wr2;
    /*!< DnY_Wr3 iDnY_Wr3 (RangeWgt3, u5)*/
    int32_t DnY_Wr3;
    /*!< DnY_Wr4 iDnY_Wr4 (RangeWgt4, u5)*/
    int32_t DnY_Wr4;
    /*!< DnY_Wr5 iDnY_Wr5 (RangeWgt5, u5)*/
    int32_t DnY_Wr5;
    /*!< DnY_wd00 iDnY_wd00 (DistWeight[0][0], u5)*/
    int32_t DnY_wd00;
    /*!< DnY_wd01 iDnY_wd01 (DistWeight[0][1], u5)*/
    int32_t DnY_wd01;
    /*!< DnY_wd02 iDnY_wd02 (DistWeight[0][2], u5)*/
    int32_t DnY_wd02;
    /*!< DnY_wd10 iDnY_wd10 (DistWeight[1][0], u5)*/
    int32_t DnY_wd10;
    /*!< DnY_wd11 iDnY_wd11 (DistWeight[1][1], u5)*/
    int32_t DnY_wd11;
    /*!< DnY_wd12 iDnY_wd12 (DistWeight[1][2], u5)*/
    int32_t DnY_wd12;
    /*!< DnY_wd20 iDnY_wd20 (DistWeight[2][0], u5)*/
    int32_t DnY_wd20;
    /*!< DnY_wd21 iDnY_wd21 (DistWeight[2][1], u5)*/
    int32_t DnY_wd21;
    /*!< DnY_wd22 iDnY_wd22 (DistWeight[2][2], u5)*/
    int32_t DnY_wd22;
    /*!< DnY_dyn_thmin iDnY_dyn_thmin (Min Dynamic Threshold, u13)*/
    int32_t DnY_dyn_thmin;
    /*!< DnY_thmin iDnY_thmin (Min Threshold Value for luma, u13)*/
    int32_t DnY_thmin;
    /*!< DnY_thmax iDnY_thmax (Max Threshold Value for luma, u13)*/
    int32_t DnY_thmax;
    /*!< DnU_prt0 iDnU_prt0 (U RangeThreshold 0, u13)*/
    int32_t DnU_prt0;
    /*!< DnU_prt1 iDnU_prt1 (U RangeThreshold 1, u13)*/
    int32_t DnU_prt1;
    /*!< DnU_prt2 iDnU_prt2 (U RangeThreshold 2, u13)*/
    int32_t DnU_prt2;
    /*!< DnU_prt3 iDnU_prt3 (U RangeThreshold 3, u13)*/
    int32_t DnU_prt3;
    /*!< DnU_prt4 iDnU_prt4 (U RangeThreshold 4, u13)*/
    int32_t DnU_prt4;
    /*!< DnU_prt5 iDnU_prt5 (U RangeThreshold 5, u13)*/
    int32_t DnU_prt5;
    /*!< DnU_Wr0 iDnU_Wr0 (U RangeWgt0, u5)*/
    int32_t DnU_Wr0;
    /*!< DnU_Wr1 iDnU_Wr1 (U RangeWgt1, u5)*/
    int32_t DnU_Wr1;
    /*!< DnU_Wr2 iDnU_Wr2 (U RangeWgt2, u5)*/
    int32_t DnU_Wr2;
    /*!< DnU_Wr3 iDnU_Wr3 (U RangeWgt3, u5)*/
    int32_t DnU_Wr3;
    /*!< DnU_Wr4 iDnU_Wr4 (U RangeWgt4, u5)*/
    int32_t DnU_Wr4;
    /*!< DnU_Wr5 iDnU_Wr5 (U RangeWgt5, u5)*/
    int32_t DnU_Wr5;
    /*!< DnU_wd00 iDnU_wd00 (U DistWeight[0][0], u5)*/
    int32_t DnU_wd00;
    /*!< DnU_wd01 iDnU_wd01 (U DistWeight[0][1], u5)*/
    int32_t DnU_wd01;
    /*!< DnU_wd02 iDnU_wd02 (U DistWeight[0][2], u5)*/
    int32_t DnU_wd02;
    /*!< DnU_wd10 iDnU_wd10 (U DistWeight[1][0], u5)*/
    int32_t DnU_wd10;
    /*!< DnU_wd11 iDnU_wd11 (U DistWeight[1][1], u5)*/
    int32_t DnU_wd11;
    /*!< DnU_wd12 iDnU_wd12 (U DistWeight[1][2], u5)*/
    int32_t DnU_wd12;
    /*!< DnU_wd20 iDnU_wd20 (U DistWeight[2][0], u5)*/
    int32_t DnU_wd20;
    /*!< DnU_wd21 iDnU_wd21 (U DistWeight[2][1], u5)*/
    int32_t DnU_wd21;
    /*!< DnU_wd22 iDnU_wd22 (U DistWeight[2][2], u5)*/
    int32_t DnU_wd22;
    /*!< DnU_dyn_thmin iDnU_dyn_thmin (U Min Dynamic Threshold, u13)*/
    int32_t DnU_dyn_thmin;
    /*!< DnU_thmin iDnU_thmin (Min Threshold Value for U, u13)*/
    int32_t DnU_thmin;
    /*!< DnU_thmax iDnU_thmax (Max Threshold Value for U, u13)*/
    int32_t DnU_thmax;
    /*!< DnV_prt0 iDnV_prt0 (V RangeThreshold 0, u13)*/
    int32_t DnV_prt0;
    /*!< DnV_prt1 iDnV_prt1 (V RangeThreshold 1, u13)*/
    int32_t DnV_prt1;
    /*!< DnV_prt2 iDnV_prt2 (V RangeThreshold 2, u13)*/
    int32_t DnV_prt2;
    /*!< DnV_prt3 iDnV_prt3 (V RangeThreshold 3, u13)*/
    int32_t DnV_prt3;
    /*!< DnV_prt4 iDnV_prt4 (V RangeThreshold 4, u13)*/
    int32_t DnV_prt4;
    /*!< DnV_prt5 iDnV_prt5 (V RangeThreshold 5, u13)*/
    int32_t DnV_prt5;
    /*!< DnV_Wr0 iDnV_Wr0 (V RangeWgt0, u5)*/
    int32_t DnV_Wr0;
    /*!< DnV_Wr1 iDnV_Wr1 (V RangeWgt1, u5)*/
    int32_t DnV_Wr1;
    /*!< DnV_Wr2 iDnV_Wr2 (V RangeWgt2, u5)*/
    int32_t DnV_Wr2;
    /*!< DnV_Wr3 iDnV_Wr3 (V RangeWgt3, u5)*/
    int32_t DnV_Wr3;
    /*!< DnV_Wr4 iDnV_Wr4 (V RangeWgt4, u5)*/
    int32_t DnV_Wr4;
    /*!< DnV_Wr5 iDnV_Wr5 (V RangeWgt5, u5)*/
    int32_t DnV_Wr5;
    /*!< DnV_wd00 iDnV_wd00 (V DistWeight[0][0], u5)*/
    int32_t DnV_wd00;
    /*!< DnV_wd01 iDnV_wd01 (V DistWeight[0][1], u5)*/
    int32_t DnV_wd01;
    /*!< DnV_wd02 iDnV_wd02 (V DistWeight[0][2], u5)*/
    int32_t DnV_wd02;
    /*!< DnV_wd10 iDnV_wd10 (V DistWeight[1][0], u5)*/
    int32_t DnV_wd10;
    /*!< DnV_wd11 iDnV_wd11 (V DistWeight[1][1], u5)*/
    int32_t DnV_wd11;
    /*!< DnV_wd12 iDnV_wd12 (V DistWeight[1][2], u5)*/
    int32_t DnV_wd12;
    /*!< DnV_wd20 iDnV_wd20 (V DistWeight[2][0], u5)*/
    int32_t DnV_wd20;
    /*!< DnV_wd21 iDnV_wd21 (V DistWeight[2][1], u5)*/
    int32_t DnV_wd21;
    /*!< DnV_wd22 iDnV_wd22 (V DistWeight[2][2], u5)*/
    int32_t DnV_wd22;
    /*!< DnV_dyn_thmin iDnV_dyn_thmin (V Min Dynamic Threshold, u13)*/
    int32_t DnV_dyn_thmin;
    /*!< DnV_thmin iDnV_thmin (Min Threshold Value for V, u13)*/
    int32_t DnV_thmin;
    /*!< DnV_thmax iDnV_thmax (Max Threshold Value for V, u13)*/
    int32_t DnV_thmax;
    /*!< Y_RangeThr_Adp2NLvl iY RangeThr Adp2NLvl {0/1}*/
    int32_t Y_RangeThr_Adp2NLvl;
    /*!< Y_RangeThr_Adp2NLvl_Min iY RangeThr Adp2NLvl Min*/
    int32_t Y_RangeThr_Adp2NLvl_Min;
    /*!< Y_RangeThr_Adp2NLvl_Max iY RangeThr Adp2NLvl Max*/
    int32_t Y_RangeThr_Adp2NLvl_Max;
    /*!< Y_RangeThrNLvlMaxIncr0 iY RangeThrNLvlMaxIncr0*/
    int32_t Y_RangeThrNLvlMaxIncr0;
    /*!< Y_RangeThrNLvlMaxIncr1 iY RangeThrNLvlMaxIncr1*/
    int32_t Y_RangeThrNLvlMaxIncr1;
    /*!< Y_RangeThrNLvlMaxIncr2 iY RangeThrNLvlMaxIncr2*/
    int32_t Y_RangeThrNLvlMaxIncr2;
    /*!< Y_RangeThrNLvlMaxIncr3 iY RangeThrNLvlMaxIncr3*/
    int32_t Y_RangeThrNLvlMaxIncr3;
    /*!< Y_RangeThrNLvlMaxIncr4 iY RangeThrNLvlMaxIncr4*/
    int32_t Y_RangeThrNLvlMaxIncr4;
    /*!< Y_RangeThrNLvlMaxIncr5 iY RangeThrNLvlMaxIncr5*/
    int32_t Y_RangeThrNLvlMaxIncr5;
    /*!< U_RangeThr_Adp2NLvl iU RangeThr Adp2NLvl {0/1}*/
    int32_t U_RangeThr_Adp2NLvl;
    /*!< U_RangeThr_Adp2NLvl_Min iU RangeThr Adp2NLvl Min*/
    int32_t U_RangeThr_Adp2NLvl_Min;
    /*!< U_RangeThr_Adp2NLvl_Max iU RangeThr Adp2NLvl Max*/
    int32_t U_RangeThr_Adp2NLvl_Max;
    /*!< U_RangeThrNLvlMaxIncr0 iU RangeThrNLvlMaxIncr0*/
    int32_t U_RangeThrNLvlMaxIncr0;
    /*!< U_RangeThrNLvlMaxIncr1 iU RangeThrNLvlMaxIncr1*/
    int32_t U_RangeThrNLvlMaxIncr1;
    /*!< U_RangeThrNLvlMaxIncr2 iU RangeThrNLvlMaxIncr2*/
    int32_t U_RangeThrNLvlMaxIncr2;
    /*!< U_RangeThrNLvlMaxIncr3 iU RangeThrNLvlMaxIncr3*/
    int32_t U_RangeThrNLvlMaxIncr3;
    /*!< U_RangeThrNLvlMaxIncr4 iU RangeThrNLvlMaxIncr4*/
    int32_t U_RangeThrNLvlMaxIncr4;
    /*!< U_RangeThrNLvlMaxIncr5 iU RangeThrNLvlMaxIncr5*/
    int32_t U_RangeThrNLvlMaxIncr5;
    /*!< V_RangeThr_Adp2NLvl iV RangeThr Adp2NLvl {0/1}*/
    int32_t V_RangeThr_Adp2NLvl;
    /*!< V_RangeThr_Adp2NLvl_Min iV RangeThr Adp2NLvl Min*/
    int32_t V_RangeThr_Adp2NLvl_Min;
    /*!< V_RangeThr_Adp2NLvl_Max iV RangeThr Adp2NLvl Max*/
    int32_t V_RangeThr_Adp2NLvl_Max;
    /*!< V_RangeThrNLvlMaxIncr0 iV RangeThrNLvlMaxIncr0*/
    int32_t V_RangeThrNLvlMaxIncr0;
    /*!< V_RangeThrNLvlMaxIncr1 iV RangeThrNLvlMaxIncr1*/
    int32_t V_RangeThrNLvlMaxIncr1;
    /*!< V_RangeThrNLvlMaxIncr2 iV RangeThrNLvlMaxIncr2*/
    int32_t V_RangeThrNLvlMaxIncr2;
    /*!< V_RangeThrNLvlMaxIncr3 iV RangeThrNLvlMaxIncr3*/
    int32_t V_RangeThrNLvlMaxIncr3;
    /*!< V_RangeThrNLvlMaxIncr4 iV RangeThrNLvlMaxIncr4*/
    int32_t V_RangeThrNLvlMaxIncr4;
    /*!< V_RangeThrNLvlMaxIncr5 iV RangeThrNLvlMaxIncr5*/
    int32_t V_RangeThrNLvlMaxIncr5;
    /*!< Hot_Pixel_Enable iHot Pixel Enable (0,1)*/
    int32_t Hot_Pixel_Enable;
    /*!< Hot_Pixel_Y_Threshold iHot Pixel Y Threshold (u8)*/
    int32_t Hot_Pixel_Y_Threshold;
    /*!< Hot_Pixel_Y_Count iHot Pixel Y Count (u4)*/
    int32_t Hot_Pixel_Y_Count;
    /*!< Hot_Pixel_U_Threshold iHot Pixel U Threshold (u8)*/
    int32_t Hot_Pixel_U_Threshold;
    /*!< Hot_Pixel_U_Count iHot Pixel U Count (u4)*/
    int32_t Hot_Pixel_U_Count;
    /*!< Hot_Pixel_V_Threshold iHot Pixel V Threshold (u8)*/
    int32_t Hot_Pixel_V_Threshold;
    /*!< Hot_Pixel_V_Count iHot Pixel V Count (u4)*/
    int32_t Hot_Pixel_V_Count;
    /*!< Validation_mode iValidation mode*/
    int32_t Validation_mode;
    /*!< Block_Width iBlock Width*/
    int32_t Block_Width;
    /*!< Block_Height iBlock Height*/
    int32_t Block_Height;
    /*!< Block_Size iBlock Size*/
    int32_t Block_Size;
    /*!< Chroma_Denoise_Block_Size_H iChroma Denoise Block Size H*/
    int32_t Chroma_Denoise_Block_Size_H;
    /*!< Chroma_Denoise_Block_Size_V iChroma Denoise Block Size V*/
    int32_t Chroma_Denoise_Block_Size_V;
    /*!< Bayer_input_for_capture_pipe iBayer input for capture pipe*/
    int32_t Bayer_input_for_capture_pipe;
    /*!< RGB_input iRGB input*/
    int32_t RGB_input;
    /*!< Right_Edge iRight Edge*/
    int32_t Right_Edge;
    /*!< Left_Edge iLeft Edge*/
    int32_t Left_Edge;
    /*!< PADDING_X_MARGIN_LEFT iPADDING X_MARGIN_LEFT*/
    int32_t PADDING_X_MARGIN_LEFT;
    /*!< PADDING_X_MARGIN_RIGHT iPADDING X_MARGIN_RIGHT*/
    int32_t PADDING_X_MARGIN_RIGHT;
    /*!< PADDING_Y_MARGIN_TOP iPADDING Y_MARGIN_TOP*/
    int32_t PADDING_Y_MARGIN_TOP;
    /*!< PADDING_Y_MARGIN_BOTTOM iPADDING Y_MARGIN_BOTTOM*/
    int32_t PADDING_Y_MARGIN_BOTTOM;
    /*!< Bayer_Partial_Column_Padding iBayer Partial Column Padding*/
    int32_t Bayer_Partial_Column_Padding;
    /*!< Bayer_Partial_Row_Padding iBayer Partial Row Padding*/
    int32_t Bayer_Partial_Row_Padding;
    /*!< Enable_CUI_Manual_Bar iEnable CUI Manual Bar*/
    int32_t Enable_CUI_Manual_Bar;
    /*!< CUI_Strength_Value iCUI Strength Value[0 - 64]*/
    int32_t CUI_Strength_Value;
    /*!< Monochrome_Support_Force_Zero_UV_OUTPUT iMonochrome Support : Force Zero UV OUTPUT*/
    int32_t Monochrome_Support_Force_Zero_UV_OUTPUT;
    /*!< Only_enable_spatial_denoise iOnly enable spatial denoise*/
    int32_t Only_enable_spatial_denoise;
    /*!< Treat_frame_as_first_frame_for_still_image_sequence iTreat frame as first frame for still image sequence*/
    int32_t Treat_frame_as_first_frame_for_still_image_sequence;
    /*!< Fulsim_Output_Bit_Precision iFulsim Output Bit Precision*/
    int32_t Fulsim_Output_Bit_Precision;

} ia_pal_isp_nrf_6_00_t;

/*! \isp struct nv12reader

*/
typedef struct
{
    /*!< im_width input image width*/
    int32_t im_width;
    /*!< im_height input image height*/
    int32_t im_height;
    /*!< input_bpp input image bpp*/
    int32_t input_bpp;
    /*!< output_bpp output image bpp*/
    int32_t output_bpp;
    /*!< input_pixel_container input pixel container (in bits)*/
    int32_t input_pixel_container;

} ia_pal_isp_nv12reader_t;

/*! \isp struct nv12writer

*/
typedef struct
{
    /*!< output_bpp output image bpp*/
    int32_t output_bpp;
    /*!< input_pixel_container input pixel container (in bits)*/
    int32_t input_pixel_container;

} ia_pal_isp_nv12writer_t;

/*! \isp struct ofa_1_dp
Output Fornatting Accelerator
*/
typedef struct
{
    /*!< y_tiling_dp tiling parameter for NV12 y_tiled format*/
    int32_t y_tiling_dp;
    /*!< pack_mode_dp pack mode for packer*/
    int32_t pack_mode_dp;
    /*!< enable_flip_dp bypass flip*/
    int32_t enable_flip_dp;
    /*!< enable_mirror_dp bypass mirror*/
    int32_t enable_mirror_dp;
    /*!< enable_reduced_range_dp bypass reduced range*/
    int32_t enable_reduced_range_dp;
    /*!< p_e_0 Multiplication parameters for pixel with even vertical index*/
    int32_t p_e_0;
    /*!< p_e_1 Multiplication parameters for pixel with even vertical index*/
    int32_t p_e_1;
    /*!< p_o_0 Multiplication parameters for pixel with odd vertical index*/
    int32_t p_o_0;
    /*!< p_o_1 Multiplication parameters for pixel with odd vertical index*/
    int32_t p_o_1;
    /*!< enable_dp display pin is active*/
    int32_t enable_dp;

} ia_pal_isp_ofa_1_dp_t;

/*! \isp struct ofa_1_mp
Output Fornatting Accelerator
*/
typedef struct
{
    /*!< y_tiling_mp tiling parameter for NV12 y_tiled format*/
    int32_t y_tiling_mp;
    /*!< pack_mode_mp pack mode for packer*/
    int32_t pack_mode_mp;
    /*!< enable_flip_mp bypass flip*/
    int32_t enable_flip_mp;
    /*!< enable_mirror_mp bypass mirror*/
    int32_t enable_mirror_mp;
    /*!< enable_reduced_range_mp bypass reduced range*/
    int32_t enable_reduced_range_mp;
    /*!< p_e_0 Multiplication parameters for pixel with even vertical index*/
    int32_t p_e_0;
    /*!< p_e_1 Multiplication parameters for pixel with even vertical index*/
    int32_t p_e_1;
    /*!< p_o_0 Multiplication parameters for pixel with odd vertical index*/
    int32_t p_o_0;
    /*!< p_o_1 Multiplication parameters for pixel with odd vertical index*/
    int32_t p_o_1;
    /*!< enable_mp main pin is active*/
    int32_t enable_mp;

} ia_pal_isp_ofa_1_mp_t;

/*! \isp struct ofa_1_ppp
Output Fornatting Accelerator
*/
typedef struct
{
    /*!< y_tiling_ppp tiling parameter for NV12 y_tiled format*/
    int32_t y_tiling_ppp;
    /*!< pack_mode_ppp pack mode for packer*/
    int32_t pack_mode_ppp;
    /*!< enable_flip_ppp bypass flip*/
    int32_t enable_flip_ppp;
    /*!< enable_mirror_ppp bypass mirror*/
    int32_t enable_mirror_ppp;
    /*!< enable_reduced_range_ppp bypass reduced range*/
    int32_t enable_reduced_range_ppp;
    /*!< p_e_0 Multiplication parameters for pixel with even vertical index*/
    int32_t p_e_0;
    /*!< p_e_1 Multiplication parameters for pixel with even vertical index*/
    int32_t p_e_1;
    /*!< p_o_0 Multiplication parameters for pixel with odd vertical index*/
    int32_t p_o_0;
    /*!< p_o_1 Multiplication parameters for pixel with odd vertical index*/
    int32_t p_o_1;
    /*!< enable_ppp post proc. Pin is active*/
    int32_t enable_ppp;

} ia_pal_isp_ofa_1_ppp_t;

/*! \isp struct ofa_2_dp
Output Fornatting Accelerator
*/
typedef struct
{
    /*!< y_tiling_dp tiling parameter for NV12 y_tiled format*/
    int32_t y_tiling_dp;
    /*!< input_bpp_dp input bpp parameter for OFA*/
    int32_t input_bpp_dp;
    /*!< pack_mode_dp pack mode for packer*/
    int32_t pack_mode_dp;
    /*!< enable_flip_dp bypass flip*/
    int32_t enable_flip_dp;
    /*!< enable_mirror_dp bypass mirror*/
    int32_t enable_mirror_dp;
    /*!< enable_reduced_range_dp bypass reduced range*/
    int32_t enable_reduced_range_dp;
    /*!< p_e_0 Multiplication parameters for pixel with even vertical index*/
    int32_t p_e_0;
    /*!< p_e_1 Multiplication parameters for pixel with even vertical index*/
    int32_t p_e_1;
    /*!< p_o_0 Multiplication parameters for pixel with odd vertical index*/
    int32_t p_o_0;
    /*!< p_o_1 Multiplication parameters for pixel with odd vertical index*/
    int32_t p_o_1;
    /*!< enable_dp display pin is active*/
    int32_t enable_dp;
    /*!< input_left_crop_pixels_dp left pixels to crop*/
    int32_t input_left_crop_pixels_dp;
    /*!< input_top_crop_pixels_dp top pixels to crop*/
    int32_t input_top_crop_pixels_dp;
    /*!< output_height_dp output height after padding*/
    int32_t output_height_dp;
    /*!< output_width_dp output width after padding*/
    int32_t output_width_dp;

} ia_pal_isp_ofa_2_dp_t;

/*! \isp struct ofa_2_mp
Output Fornatting Accelerator
*/
typedef struct
{
    /*!< y_tiling_mp tiling parameter for NV12 y_tiled format*/
    int32_t y_tiling_mp;
    /*!< input_bpp_mp input bpp parameter for OFA*/
    int32_t input_bpp_mp;
    /*!< pack_mode_mp pack mode for packer*/
    int32_t pack_mode_mp;
    /*!< enable_flip_mp bypass flip*/
    int32_t enable_flip_mp;
    /*!< enable_mirror_mp bypass mirror*/
    int32_t enable_mirror_mp;
    /*!< enable_reduced_range_mp bypass reduced range*/
    int32_t enable_reduced_range_mp;
    /*!< p_e_0 Multiplication parameters for pixel with even vertical index*/
    int32_t p_e_0;
    /*!< p_e_1 Multiplication parameters for pixel with even vertical index*/
    int32_t p_e_1;
    /*!< p_o_0 Multiplication parameters for pixel with odd vertical index*/
    int32_t p_o_0;
    /*!< p_o_1 Multiplication parameters for pixel with odd vertical index*/
    int32_t p_o_1;
    /*!< enable_mp main pin is active*/
    int32_t enable_mp;
    /*!< input_left_crop_pixels_mp left pixels to crop*/
    int32_t input_left_crop_pixels_mp;
    /*!< input_top_crop_pixels_mp top pixels to crop*/
    int32_t input_top_crop_pixels_mp;
    /*!< output_height_mp output height after padding*/
    int32_t output_height_mp;
    /*!< output_width_mp output width after padding*/
    int32_t output_width_mp;

} ia_pal_isp_ofa_2_mp_t;

/*! \isp struct ofa_2_ppp
Output Fornatting Accelerator
*/
typedef struct
{
    /*!< y_tiling_ppp tiling parameter for NV12 y_tiled format*/
    int32_t y_tiling_ppp;
    /*!< input_bpp_ppp input bpp parameter for OFA*/
    int32_t input_bpp_ppp;
    /*!< pack_mode_ppp pack mode for packer*/
    int32_t pack_mode_ppp;
    /*!< enable_flip_ppp bypass flip*/
    int32_t enable_flip_ppp;
    /*!< enable_mirror_ppp bypass mirror*/
    int32_t enable_mirror_ppp;
    /*!< enable_reduced_range_ppp bypass reduced range*/
    int32_t enable_reduced_range_ppp;
    /*!< p_e_0 Multiplication parameters for pixel with even vertical index*/
    int32_t p_e_0;
    /*!< p_e_1 Multiplication parameters for pixel with even vertical index*/
    int32_t p_e_1;
    /*!< p_o_0 Multiplication parameters for pixel with odd vertical index*/
    int32_t p_o_0;
    /*!< p_o_1 Multiplication parameters for pixel with odd vertical index*/
    int32_t p_o_1;
    /*!< enable_ppp post proc. Pin is active*/
    int32_t enable_ppp;
    /*!< input_left_crop_pixels_ppp left pixels to crop*/
    int32_t input_left_crop_pixels_ppp;
    /*!< input_top_crop_pixels_ppp top pixels to crop*/
    int32_t input_top_crop_pixels_ppp;
    /*!< output_height_pp output height after padding*/
    int32_t output_height_pp;
    /*!< output_width_pp output width after padding*/
    int32_t output_width_pp;

} ia_pal_isp_ofa_2_ppp_t;

/*! \isp struct outputscaler_2_0

*/
typedef struct
{
    /*!< enable enable scaling filter*/
    int32_t enable;
    /*!< scaling_ratio U5.16 , downscale - greater than 1*/
    int32_t scaling_ratio;
    /*!< horizontal_offset_luma S12.16(29 incl S bit),Position of first output pixel luma channel for scaler*/
    int32_t horizontal_offset_luma;
    /*!< vertical_offset_luma S12.16(29 incl S bit), Position of first output line luma channel for scaler*/
    int32_t vertical_offset_luma;
    /*!< horizontal_offset_chroma S12.16(29 incl S bit), Position of first output pixel chroma channel for scaler*/
    int32_t horizontal_offset_chroma;
    /*!< vertical_offset_chroma S12.16(29 incl S bit), Position of first output line chroma channel for scaler*/
    int32_t vertical_offset_chroma;
    /*!< output_height U13.0, Height of output image Y plane for scaler (even)*/
    int32_t output_height;
    /*!< output_width U13.0, Width of output image Y plane for scaler (even)*/
    int32_t output_width;
    /*!< kernel_LUT[129] S1.10 Y channel Interpolation vertical kernel coefficients for scaler*/
    int32_t kernel_LUT[129];
    /*!< chroma_kernel_LUT[129] S1.10 UV channel Interpolation vertical kernel coefficients for scaler*/
    int32_t chroma_kernel_LUT[129];

} ia_pal_isp_outputscaler_2_0_t;

/*! \isp struct packer_isa_bayer_a
Bayer Planar output formatter
*/
typedef struct
{
    /*!< format Output format: 0 - Bayer planar, 1 - Bayer packed*/
    int32_t format;

} ia_pal_isp_packer_isa_bayer_a_t;

/*! \isp struct packer_isa_yuv_a
NV12 output formatter
*/
typedef struct
{
    /*!< format Output format: 0 - I420, 1 - NV12, 2 - NV21, 3 - P010MSB, 4 - P016MSB*/
    int32_t format;

} ia_pal_isp_packer_isa_yuv_a_t;

/*! \isp struct packer_isa_yuv_b
NV12 output formatter
*/
typedef struct
{
    /*!< format Output format: 0 - I420, 1 - NV12, 2 - NV21, 3 - P010MSB, 4 - P016MSB*/
    int32_t format;

} ia_pal_isp_packer_isa_yuv_b_t;

/*! \isp struct packer_isa_yuv_c
NV12 output formatter
*/
typedef struct
{
    /*!< format Output format: 0 - I420, 1 - NV12, 2 - NV21, 3 - P010MSB, 4 - P016MSB*/
    int32_t format;

} ia_pal_isp_packer_isa_yuv_c_t;

/*! \isp struct padder_bayer_a

*/
typedef struct
{
    /*!< Padder_en 0- disable filter. 1- enable filter.*/
    int32_t Padder_en;
    /*!< sol_pad Left side padding quad number.*/
    int32_t sol_pad;
    /*!< eol_pad Right side padding quad number.*/
    int32_t eol_pad;
    /*!< Frame_width The width of the frame in number of quads.*/
    int32_t Frame_width;
    /*!< Strm_format 0- YUV. 1- Bayer.*/
    int32_t Strm_format;

} ia_pal_isp_padder_bayer_a_t;

/*! \isp struct padder_yuv_a

*/
typedef struct
{
    /*!< Padder_en 0- disable filter. 1- enable filter.*/
    int32_t Padder_en;
    /*!< sol_pad Left side padding quad number.*/
    int32_t sol_pad;
    /*!< eol_pad Right side padding quad number.*/
    int32_t eol_pad;
    /*!< Frame_width The width of the frame in number of quads.*/
    int32_t Frame_width;
    /*!< Strm_format 0- YUV. 1- Bayer.*/
    int32_t Strm_format;

} ia_pal_isp_padder_yuv_a_t;

/*! \isp struct padder_yuv_b

*/
typedef struct
{
    /*!< Padder_en 0- disable filter. 1- enable filter.*/
    int32_t Padder_en;
    /*!< sol_pad Left side padding quad number.*/
    int32_t sol_pad;
    /*!< eol_pad Right side padding quad number.*/
    int32_t eol_pad;
    /*!< Frame_width The width of the frame in number of quads.*/
    int32_t Frame_width;
    /*!< Strm_format 0- YUV. 1- Bayer.*/
    int32_t Strm_format;

} ia_pal_isp_padder_yuv_b_t;

/*! \isp struct padder_yuv_c

*/
typedef struct
{
    /*!< Padder_en 0- disable filter. 1- enable filter.*/
    int32_t Padder_en;
    /*!< sol_pad Left side padding quad number.*/
    int32_t sol_pad;
    /*!< eol_pad Right side padding quad number.*/
    int32_t eol_pad;
    /*!< Frame_width The width of the frame in number of quads.*/
    int32_t Frame_width;
    /*!< Strm_format 0- YUV. 1- Bayer.*/
    int32_t Strm_format;

} ia_pal_isp_padder_yuv_c_t;

/*! \isp struct pafstatistics_1
PAF Statistics
*/
typedef struct
{
    /*!< paf_en 0: FF will not write to the PAF  array; 1: FF will write*/
    int32_t paf_en;
    /*!< paf_frame_width width of PAF frame (in PAF pixels)*/
    int32_t paf_frame_width;
    /*!< paf_frame_height height of PAF frame (in PAF lines)*/
    int32_t paf_frame_height;
    /*!< skip_horizontal_start number of skipped PAF pixel pairs at the start of each line pair*/
    int32_t skip_horizontal_start;
    /*!< skip_vertical_start number of skipped PAF line pairs at the start of the frame*/
    int32_t skip_vertical_start;
    /*!< block_width number of PAF pixel pairs per block in horizontal direction*/
    int32_t block_width;
    /*!< block_height number of PAF pixel pairs per block in vertical direction*/
    int32_t block_height;
    /*!< accum_horizontal number of consecutive PAF pixel pairs accumulated in horizontal direction*/
    int32_t accum_horizontal;
    /*!< skip_horizontal number of PAF pixel pairs skipped between accumulated pixel pairs in horizontal direction*/
    int32_t skip_horizontal;
    /*!< accum_vertical number of consecutive PAF pixel pairs accumulated in vertical direction*/
    int32_t accum_vertical;
    /*!< skip_vertical number of PAF line pairs skipped between accumulated pixel pairs in vertical direction*/
    int32_t skip_vertical;
    /*!< min_shift minimum evaluation shift in steps*/
    int32_t min_shift;
    /*!< shift_steps number of evaluation points, starting from m_paf_min_shift*/
    int32_t shift_steps;
    /*!< paf_shift_step_size phase evaluation step size in pixels*/
    int32_t paf_shift_step_size;
    /*!< paf_shifter configured so that the accumulated phase difference fits in the output register*/
    int32_t paf_shifter;
    /*!< split_accross_multiple_lines 0: SOP = SOL, EOP = EOL; 1: SOF determined by the reset, EOL determined by pixels per line*/
    int32_t split_accross_multiple_lines;
    /*!< pixels_per_line number of pixels per line; pixels_per_line <= paf_frame_width*/
    int32_t pixels_per_line;
    /*!< input_modes 0: RRRR+LLLL; 1: LLLL+RRRR; 2: RLRL; 3: LRLR; 4: RRRR+LLLL_ALT; 5: LLLL+RRRR_ALT; 6: RLRL_ALT; 7: LRLR_ALT*/
    int32_t input_modes;
    /*!< input_bpp 0: 8 bits; 1: 10 bits; 2: 12 bits; 3: 14 bits; 4: 16 bits*/
    int32_t input_bpp;
    /*!< int_prec internal precision of PAF pixels*/
    int32_t int_prec;
    /*!< paf_blacklevel Black level to be subtracted from raw PDAF pixel values*/
    int32_t paf_blacklevel;
    /*!< shading_coeff_l[192] Shading correction coefficients for L PDAF values (arrangement is the same as PDAF grid: 16x12)*/
    int32_t shading_coeff_l[192];
    /*!< shading_coeff_r[192] Shading correction coefficients for R PDAF values (arrangement is the same as PDAF grid: 16x12)*/
    int32_t shading_coeff_r[192];
    /*!< paf_abs_shifter Bit right shift after abs-operation, to compensate for the shading gains*/
    int32_t paf_abs_shifter;

} ia_pal_isp_pafstatistics_1_t;

/*! \isp struct pafstatistics_1_1
PAF Statistics
*/
typedef struct
{
    /*!< paf_en 0: FF will not write to the PAF  array; 1: FF will write*/
    int32_t paf_en;
    /*!< paf_frame_width width of PAF frame (in PAF pixels)*/
    int32_t paf_frame_width;
    /*!< paf_frame_height height of PAF frame (in PAF lines)*/
    int32_t paf_frame_height;
    /*!< skip_horizontal_start number of skipped PAF pixel pairs at the start of each line pair*/
    int32_t skip_horizontal_start;
    /*!< skip_vertical_start number of skipped PAF line pairs at the start of the frame*/
    int32_t skip_vertical_start;
    /*!< block_width number of PAF pixel pairs per block in horizontal direction*/
    int32_t block_width;
    /*!< block_height number of PAF pixel pairs per block in vertical direction*/
    int32_t block_height;
    /*!< accum_horizontal number of consecutive PAF pixel pairs accumulated in horizontal direction*/
    int32_t accum_horizontal;
    /*!< skip_horizontal number of PAF pixel pairs skipped between accumulated pixel pairs in horizontal direction*/
    int32_t skip_horizontal;
    /*!< accum_vertical number of consecutive PAF pixel pairs accumulated in vertical direction*/
    int32_t accum_vertical;
    /*!< skip_vertical number of PAF line pairs skipped between accumulated pixel pairs in vertical direction*/
    int32_t skip_vertical;
    /*!< min_shift minimum evaluation shift in steps*/
    int32_t min_shift;
    /*!< shift_steps number of evaluation points, starting from m_paf_min_shift*/
    int32_t shift_steps;
    /*!< paf_shift_step_size phase evaluation step size in pixels*/
    int32_t paf_shift_step_size;
    /*!< paf_shifter configured so that the accumulated phase difference fits in the output register*/
    int32_t paf_shifter;
    /*!< split_accross_multiple_lines 0: SOP = SOL, EOP = EOL; 1: SOF determined by the reset, EOL determined by pixels per line*/
    int32_t split_accross_multiple_lines;
    /*!< pixels_per_line number of pixels per line; pixels_per_line <= paf_frame_width*/
    int32_t pixels_per_line;
    /*!< input_modes 0: RRRR+LLLL; 1: LLLL+RRRR; 2: RLRL; 3: LRLR; 4: RRRR+LLLL_ALT; 5: LLLL+RRRR_ALT; 6: RLRL_ALT; 7: LRLR_ALT*/
    int32_t input_modes;
    /*!< input_bpp 0: 8 bits; 1: 10 bits; 2: 12 bits; 3: 14 bits; 4: 16 bits*/
    int32_t input_bpp;
    /*!< int_prec internal precision of PAF pixels*/
    int32_t int_prec;
    /*!< paf_blacklevel Black level to be subtracted from raw PDAF pixel values*/
    int32_t paf_blacklevel;
    /*!< shading_coeff_l[192] Shading correction coefficients for L PDAF values (arrangement is the same as PDAF grid: 16x12)*/
    int32_t shading_coeff_l[192];
    /*!< shading_coeff_r[192] Shading correction coefficients for R PDAF values (arrangement is the same as PDAF grid: 16x12)*/
    int32_t shading_coeff_r[192];
    /*!< paf_abs_shifter Bit right shift after abs-operation, to compensate for the shading gains*/
    int32_t paf_abs_shifter;

} ia_pal_isp_pafstatistics_1_1_t;

/*! \isp struct pafstatistics_1_2
PAF Statistics
*/
typedef struct
{
    /*!< paf_en 0: FF will not write to the PAF  array; 1: FF will write*/
    int32_t paf_en;
    /*!< paf_frame_width width of PAF frame (in PAF pixels)*/
    int32_t paf_frame_width;
    /*!< paf_frame_height height of PAF frame (in PAF lines)*/
    int32_t paf_frame_height;
    /*!< skip_horizontal_start number of skipped PAF pixel pairs at the start of each line pair*/
    int32_t skip_horizontal_start;
    /*!< skip_vertical_start number of skipped PAF line pairs at the start of the frame*/
    int32_t skip_vertical_start;
    /*!< block_width number of PAF pixel pairs per block in horizontal direction*/
    int32_t block_width;
    /*!< block_height number of PAF pixel pairs per block in vertical direction*/
    int32_t block_height;
    /*!< accum_horizontal number of consecutive PAF pixel pairs accumulated in horizontal direction*/
    int32_t accum_horizontal;
    /*!< skip_horizontal number of PAF pixel pairs skipped between accumulated pixel pairs in horizontal direction*/
    int32_t skip_horizontal;
    /*!< accum_vertical number of consecutive PAF pixel pairs accumulated in vertical direction*/
    int32_t accum_vertical;
    /*!< skip_vertical number of PAF line pairs skipped between accumulated pixel pairs in vertical direction*/
    int32_t skip_vertical;
    /*!< min_shift minimum evaluation shift in steps*/
    int32_t min_shift;
    /*!< shift_steps number of evaluation points, starting from m_paf_min_shift*/
    int32_t shift_steps;
    /*!< paf_shift_step_size phase evaluation step size in pixels*/
    int32_t paf_shift_step_size;
    /*!< paf_shifter configured so that the accumulated phase difference fits in the output register*/
    int32_t paf_shifter;
    /*!< split_accross_multiple_lines 0: SOP = SOL, EOP = EOL; 1: SOF determined by the reset, EOL determined by pixels per line*/
    int32_t split_accross_multiple_lines;
    /*!< pixels_per_line number of pixels per line; pixels_per_line <= paf_frame_width*/
    int32_t pixels_per_line;
    /*!< input_modes 0: RRRR+LLLL; 1: LLLL+RRRR; 2: RLRL; 3: LRLR; 4: RRRR+LLLL_ALT; 5: LLLL+RRRR_ALT; 6: RLRL_ALT; 7: LRLR_ALT*/
    int32_t input_modes;
    /*!< input_bpp 0: 8 bits; 1: 10 bits; 2: 12 bits; 3: 14 bits; 4: 16 bits; 5: 15 bits (for PDAF3type)*/
    int32_t input_bpp;
    /*!< int_prec internal precision of PAF pixels*/
    int32_t int_prec;
    /*!< paf_blacklevel Black level to be subtracted from raw PDAF pixel values*/
    int32_t paf_blacklevel;
    /*!< shading_coeff_l[192] Shading correction coefficients for L PDAF values (arrangement is the same as PDAF grid: 16x12)*/
    int32_t shading_coeff_l[192];
    /*!< shading_coeff_r[192] Shading correction coefficients for R PDAF values (arrangement is the same as PDAF grid: 16x12)*/
    int32_t shading_coeff_r[192];
    /*!< paf_abs_shifter Bit right shift after abs-operation, to compensate for the shading gains*/
    int32_t paf_abs_shifter;

} ia_pal_isp_pafstatistics_1_2_t;

/*! \isp struct pext_1_0

*/
typedef struct
{
    /*!< paf_output_mode 0)disables, do not pass anything\n 1) first line sent to memset0 second\n line sent to memset1\n 2)first line sent to memset0 second to memset 1 and afterward alternate every two lines 3) passthrough –send to memset0 everything*/
    int32_t paf_output_mode;
    /*!< swapping1stbc Apply swapping of BC inputs for 1st/3rd/etc.\n0: no swapping\n1: swap B/C inputs*/
    int32_t swapping1stbc;
    /*!< swapping1stcd Apply swapping of CD inputs for 1st/3rd/etc.\n0: no swapping\n1: swap C/D inputs*/
    int32_t swapping1stcd;
    /*!< swapping2ndbc Apply swapping of BC inputs for 2nd/4th/etc. lines\n0: no swapping\n1: swap A/B inputs*/
    int32_t swapping2ndbc;
    /*!< swapping2ndcd Apply swapping of CD inputs for 2nd/4th/etc. lines\n0: no swapping\n1: swap C/D inputs*/
    int32_t swapping2ndcd;
    /*!< pdaf_width Width in units of PDAF pixels. After Width pixels – Pext knows there is a new line coming in. In Modes1..3 – max line length is as in the internal buffer size which is 1024 pixels.*/
    int32_t pdaf_width;
    /*!< pdaf_height Height in units of pdaf lines*/
    int32_t pdaf_height;
    /*!< drop_pattern[32] Drop pattern for AF pixels. 1=drop the lines\n0=use the line*/
    int32_t drop_pattern[32];
    /*!< drop_period Period of the drop pattern*/
    int32_t drop_period;

} ia_pal_isp_pext_1_0_t;

/*! \isp struct pix_crop_ir_md

*/
typedef struct
{
    /*!< enable Enable Crop for IR MD output*/
    int32_t enable;
    /*!< crop_col_start Start column of image data (columns before will be cropped)*/
    int32_t crop_col_start;
    /*!< crop_row_start Start row of image data (rows before will be cropped)*/
    int32_t crop_row_start;
    /*!< crop_col_end End column of image data (excess will be cropped)*/
    int32_t crop_col_end;
    /*!< crop_row_end End line of image data (excess will be cropped)*/
    int32_t crop_row_end;

} ia_pal_isp_pix_crop_ir_md_t;

/*! \isp struct pixcomp_1_0
Input system pixel compression
*/
typedef struct
{
    /*!< pixcomp_enable Enable PixComp*/
    int32_t pixcomp_enable;
    /*!< glu_base_level[6] GLU base level offset*/
    int32_t glu_base_level[6];
    /*!< glu_step[6] GLU step amount per stage*/
    int32_t glu_step[6];
    /*!< glu_start_bin[6] GLU stage start offset in LUT*/
    int32_t glu_start_bin[6];
    /*!< glu_gen_lut_size Utilized LUT size*/
    int32_t glu_gen_lut_size;
    /*!< glu_gen_lut[128] LUT samples*/
    int32_t glu_gen_lut[128];

} ia_pal_isp_pixcomp_1_0_t;

/*! \isp struct pixelformatter

*/
typedef struct
{
    /*!< m_bypass Bypass     {0,1}*/
    int32_t m_bypass;
    /*!< m_ColRemoval col removal- for setting bayer pattern*/
    int32_t m_ColRemoval;
    /*!< m_xstart Horizontal Starting Pixel. FIXME: Put correct max and default values*/
    int32_t m_xstart;
    /*!< m_ystart Vertical   Starting Pixel. FIXME: Put correct max and default values*/
    int32_t m_ystart;
    /*!< m_xsize Horizontal Frame Size. FIXME: Put correct max and default values*/
    int32_t m_xsize;
    /*!< m_ysize Vertical   Frame Size. FIXME: Put correct max and default values*/
    int32_t m_ysize;

} ia_pal_isp_pixelformatter_t;

/*! \isp struct pixelformatter_b

*/
typedef struct
{
    /*!< m_bypass Bypass     {0,1}*/
    int32_t m_bypass;
    /*!< m_ColRemoval col removal- for setting bayer pattern*/
    int32_t m_ColRemoval;
    /*!< m_xstart Horizontal Starting Pixel. FIXME: Put correct max and default values*/
    int32_t m_xstart;
    /*!< m_ystart Vertical   Starting Pixel. FIXME: Put correct max and default values*/
    int32_t m_ystart;
    /*!< m_xsize Horizontal Frame Size. FIXME: Put correct max and default values*/
    int32_t m_xsize;
    /*!< m_ysize Vertical   Frame Size. FIXME: Put correct max and default values*/
    int32_t m_ysize;

} ia_pal_isp_pixelformatter_b_t;

/*! \isp struct pixelformatter_c

*/
typedef struct
{
    /*!< m_bypass Bypass     {0,1}*/
    int32_t m_bypass;
    /*!< m_ColRemoval col removal- for setting bayer pattern*/
    int32_t m_ColRemoval;
    /*!< m_xstart Horizontal Starting Pixel. FIXME: Put correct max and default values*/
    int32_t m_xstart;
    /*!< m_ystart Vertical   Starting Pixel. FIXME: Put correct max and default values*/
    int32_t m_ystart;
    /*!< m_xsize Horizontal Frame Size. FIXME: Put correct max and default values*/
    int32_t m_xsize;
    /*!< m_ysize Vertical   Frame Size. FIXME: Put correct max and default values*/
    int32_t m_ysize;

} ia_pal_isp_pixelformatter_c_t;

/*! \isp struct pixprecadapter_post_sis

*/
typedef struct
{
    /*!< m_pixinprec HW Parameter  - Input Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixinprec;
    /*!< m_pixoutprec HW Parameter  - Output Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixoutprec;
    /*!< m_pixminprec HW Parameter - Minimum possible pixel precision for the input/output Pixel : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixminprec;
    /*!< m_isbayer Is Bayer? - RGB(0) Bayer(1)*/
    int32_t m_isbayer;
    /*!< m_cliptous 0 - Do not clip, 1 - Clip to unsigned*/
    int32_t m_cliptous;
    /*!< m_shiftlen 0 - Perform ShiftR Round, 1 - Perfom ShiftL*/
    int32_t m_shiftlen;
    /*!< m_shiftval Shift Value {0..7}*/
    int32_t m_shiftval;

} ia_pal_isp_pixprecadapter_post_sis_t;

/*! \isp struct pixprecadapter_s2v_c

*/
typedef struct
{
    /*!< m_pixinprec HW Parameter  - Input Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixinprec;
    /*!< m_pixoutprec HW Parameter  - Output Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixoutprec;
    /*!< m_pixminprec HW Parameter - Minimum possible pixel precision for the input/output Pixel : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixminprec;
    /*!< m_isbayer Is Bayer? - RGB(0) Bayer(1)*/
    int32_t m_isbayer;
    /*!< m_cliptous 0 - Do not clip, 1 - Clip to unsigned*/
    int32_t m_cliptous;
    /*!< m_shiftlen 0 - Perform ShiftR Round, 1 - Perfom ShiftL*/
    int32_t m_shiftlen;
    /*!< m_shiftval Shift Value {0..7}*/
    int32_t m_shiftval;

} ia_pal_isp_pixprecadapter_s2v_c_t;

/*! \isp struct pixprecadapter_v2s_4

*/
typedef struct
{
    /*!< m_pixinprec HW Parameter  - Input Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixinprec;
    /*!< m_pixoutprec HW Parameter  - Output Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixoutprec;
    /*!< m_pixminprec HW Parameter - Minimum possible pixel precision for the input/output Pixel : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixminprec;
    /*!< m_isbayer Is Bayer? - RGB(0) Bayer(1)*/
    int32_t m_isbayer;
    /*!< m_cliptous 0 - Do not clip, 1 - Clip to unsigned*/
    int32_t m_cliptous;
    /*!< m_shiftlen 0 - Perform ShiftR Round, 1 - Perfom ShiftL*/
    int32_t m_shiftlen;
    /*!< m_shiftval Shift Value {0..7}*/
    int32_t m_shiftval;

} ia_pal_isp_pixprecadapter_v2s_4_t;

/*! \isp struct pme_1_0
PME for 'standalone TNR6'
*/
typedef struct
{
    /*!< bypass bypass*/
    int32_t bypass;
    /*!< frame_height frame height*/
    int32_t frame_height;
    /*!< frame_width frame width*/
    int32_t frame_width;
    /*!< search_range_y search range - bottom*/
    int32_t search_range_y;
    /*!< search_range_x search range - left*/
    int32_t search_range_x;
    /*!< dest_block_size_max_y[4] maximal block size - vertical*/
    int32_t dest_block_size_max_y[4];
    /*!< dest_block_size_max_x maximal block size - horizontal*/
    int32_t dest_block_size_max_x;
    /*!< iy_dest_image_min the first row of the destination image available in the DDR buffer*/
    int32_t iy_dest_image_min;
    /*!< ix_dest_image_min the first column of the destination image available in the DDR buffer*/
    int32_t ix_dest_image_min;
    /*!< homography_matrix_0[4] homography base->destination; elements 1,2,4,5 [S2.20]*/
    int32_t homography_matrix_0[4];
    /*!< homography_matrix_1[2] homography base->destination; elements 7, 8 [S0.31, only 25 LSBs used]*/
    int32_t homography_matrix_1[2];
    /*!< homography_matrix_2[3] homography base->destination; elements 3, 6, 9 [S15.16]*/
    int32_t homography_matrix_2[3];
    /*!< homography_confidence the confidence of the homography model*/
    int32_t homography_confidence;
    /*!< no_motion_confidence the confidence of the no-motion model*/
    int32_t no_motion_confidence;
    /*!< motion_complexity[2176] bypass*/
    int32_t motion_complexity[2176];
    /*!< motion_complexity_bin_exp_y motion-complexity read configuration*/
    int32_t motion_complexity_bin_exp_y;

} ia_pal_isp_pme_1_0_t;

/*! \isp struct pxl_crop_bayer_a

*/
typedef struct
{
    /*!< enable Enable Crop for bayer output A*/
    int32_t enable;
    /*!< crop_col_start Start column of image data (columns before will be cropped)*/
    int32_t crop_col_start;
    /*!< crop_row_start Start row of image data (rows before will be cropped)*/
    int32_t crop_row_start;
    /*!< crop_col_end End column of image data (excess will be cropped)*/
    int32_t crop_col_end;
    /*!< crop_row_end End line of image data (excess will be cropped)*/
    int32_t crop_row_end;

} ia_pal_isp_pxl_crop_bayer_a_t;

/*! \isp struct pxl_crop_psa

*/
typedef struct
{
    /*!< enable Enable Crop for bayer output A*/
    int32_t enable;
    /*!< crop_col_start Start column of image data (columns before will be cropped)*/
    int32_t crop_col_start;
    /*!< crop_row_start Start row of image data (rows before will be cropped)*/
    int32_t crop_row_start;
    /*!< crop_col_end End column of image data (excess will be cropped)*/
    int32_t crop_col_end;
    /*!< crop_row_end End line of image data (excess will be cropped)*/
    int32_t crop_row_end;

} ia_pal_isp_pxl_crop_psa_t;

/*! \isp struct pxl_crop_sis_a

*/
typedef struct
{
    /*!< enable Enable post SIS Crop*/
    int32_t enable;
    /*!< crop_col_start Start column of image data (columns before will be cropped)*/
    int32_t crop_col_start;
    /*!< crop_row_start Start row of image data (rows before will be cropped)*/
    int32_t crop_row_start;
    /*!< crop_col_end End column of image data (excess will be cropped)*/
    int32_t crop_col_end;
    /*!< crop_row_end End line of image data (excess will be cropped)*/
    int32_t crop_row_end;

} ia_pal_isp_pxl_crop_sis_a_t;

/*! \isp struct pxl_crop_sis_b

*/
typedef struct
{
    /*!< enable Enable post SIS Crop*/
    int32_t enable;
    /*!< crop_col_start Start column of image data (columns before will be cropped)*/
    int32_t crop_col_start;
    /*!< crop_row_start Start row of image data (rows before will be cropped)*/
    int32_t crop_row_start;
    /*!< crop_col_end End column of image data (excess will be cropped)*/
    int32_t crop_col_end;
    /*!< crop_row_end End line of image data (excess will be cropped)*/
    int32_t crop_row_end;

} ia_pal_isp_pxl_crop_sis_b_t;

/*! \isp struct pxl_crop_yuv_a

*/
typedef struct
{
    /*!< enable Enable Crop for YUV output A*/
    int32_t enable;
    /*!< crop_col_start Start column of image data (columns before will be cropped)*/
    int32_t crop_col_start;
    /*!< crop_row_start Start row of image data (rows before will be cropped)*/
    int32_t crop_row_start;
    /*!< crop_col_end End column of image data (excess will be cropped)*/
    int32_t crop_col_end;
    /*!< crop_row_end End line of image data (excess will be cropped)*/
    int32_t crop_row_end;

} ia_pal_isp_pxl_crop_yuv_a_t;

/*! \isp struct pxl_crop_yuv_b

*/
typedef struct
{
    /*!< enable Enable Crop for YUV output B*/
    int32_t enable;
    /*!< crop_col_start Start column of image data (columns before will be cropped)*/
    int32_t crop_col_start;
    /*!< crop_row_start Start row of image data (rows before will be cropped)*/
    int32_t crop_row_start;
    /*!< crop_col_end End column of image data (excess will be cropped)*/
    int32_t crop_col_end;
    /*!< crop_row_end End line of image data (excess will be cropped)*/
    int32_t crop_row_end;

} ia_pal_isp_pxl_crop_yuv_b_t;

/*! \isp struct pxl_crop_yuv_c

*/
typedef struct
{
    /*!< enable Enable Crop for YUV output C*/
    int32_t enable;
    /*!< crop_col_start Start column of image data (columns before will be cropped)*/
    int32_t crop_col_start;
    /*!< crop_row_start Start row of image data (rows before will be cropped)*/
    int32_t crop_row_start;
    /*!< crop_col_end End column of image data (excess will be cropped)*/
    int32_t crop_col_end;
    /*!< crop_row_end End line of image data (excess will be cropped)*/
    int32_t crop_row_end;

} ia_pal_isp_pxl_crop_yuv_c_t;

/*! \isp struct rgb_ir_2_0
RGB-IR
*/
typedef struct
{
    /*!< Bypass Bypass (0,1)*/
    int32_t Bypass;
    /*!< CFArgbir[16] RGB-IR CFA descriptor for 4x4 repetitive pattern (0: R, 1: G, 2: B, 3: IR)*/
    int32_t CFArgbir[16];
    /*!< CFAbayer[4] Bayer CFA descriptor for 2x2 repetitive pattern (0: R, 1: G, 2: B)*/
    int32_t CFAbayer[4];
    /*!< SensorDim[2] Sensor dimensions (height,width) for IR contamination correction (optical center calculation)*/
    int32_t SensorDim[2];
    /*!< ImageDim[2] Image dimensions (height,width)*/
    int32_t ImageDim[2];
    /*!< IRimageDim[2] IR image dimensions (height,width)*/
    int32_t IRimageDim[2];
    /*!< IRtype Type of IR pixel layout (2: IRtype2, 1: IRtype1, 0: any other supported, -1: unsupported)*/
    int32_t IRtype;
    /*!< IRrefloc Pixel location corresponding to the reference (first) IR pixel within a 4x4 repetitive pattern*/
    int32_t IRrefloc;
    /*!< LumaWeights11[25] Filter mask for luminance calculations in CFA locations 11; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights11[25];
    /*!< LumaWeights12[25] Filter mask for luminance calculations in CFA locations 12; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights12[25];
    /*!< LumaWeights13[25] Filter mask for luminance calculations in CFA locations 13; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights13[25];
    /*!< LumaWeights14[25] Filter mask for luminance calculations in CFA locations 14; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights14[25];
    /*!< LumaWeights21[25] Filter mask for luminance calculations in CFA locations 21; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights21[25];
    /*!< LumaWeights22[25] Filter mask for luminance calculations in CFA locations 22; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights22[25];
    /*!< LumaWeights23[25] Filter mask for luminance calculations in CFA locations 23; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights23[25];
    /*!< LumaWeights24[25] Filter mask for luminance calculations in CFA locations 24; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights24[25];
    /*!< LumaWeights31[25] Filter mask for luminance calculations in CFA locations 31; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights31[25];
    /*!< LumaWeights32[25] Filter mask for luminance calculations in CFA locations 32; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights32[25];
    /*!< LumaWeights33[25] Filter mask for luminance calculations in CFA locations 33; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights33[25];
    /*!< LumaWeights34[25] Filter mask for luminance calculations in CFA locations 34; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights34[25];
    /*!< LumaWeights41[25] Filter mask for luminance calculations in CFA locations 41; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights41[25];
    /*!< LumaWeights42[25] Filter mask for luminance calculations in CFA locations 42; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights42[25];
    /*!< LumaWeights43[25] Filter mask for luminance calculations in CFA locations 43; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights43[25];
    /*!< LumaWeights44[25] Filter mask for luminance calculations in CFA locations 44; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights44[25];
    /*!< LumaWeightSums[16] Right bit shifts equivalent to the sum of the luminance filter mask coefficients for all 16 channels (11,12,44) within 4x4 repetitive pattern.*/
    int32_t LumaWeightSums[16];
    /*!< BayerRestNeighbors11[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 11; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors11[8];
    /*!< BayerRestNeighbors12[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 12; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors12[8];
    /*!< BayerRestNeighbors13[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations ; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors13[8];
    /*!< BayerRestNeighbors14[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 14; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors14[8];
    /*!< BayerRestNeighbors21[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 21; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors21[8];
    /*!< BayerRestNeighbors22[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 22; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors22[8];
    /*!< BayerRestNeighbors23[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 23; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors23[8];
    /*!< BayerRestNeighbors24[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 24; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors24[8];
    /*!< BayerRestNeighbors31[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 31; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors31[8];
    /*!< BayerRestNeighbors32[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 32; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors32[8];
    /*!< BayerRestNeighbors33[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 33; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors33[8];
    /*!< BayerRestNeighbors34[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 34; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors34[8];
    /*!< BayerRestNeighbors41[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 41; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors41[8];
    /*!< BayerRestNeighbors42[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 42; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors42[8];
    /*!< BayerRestNeighbors43[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 43; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors43[8];
    /*!< BayerRestNeighbors44[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 44; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors44[8];
    /*!< BayerRestLuma Disable the use of the luminance in Bayer CFA restoration (0: disable, 1: enable)*/
    int32_t BayerRestLuma;
    /*!< BayerRestWeights Disable the use of the weights in Bayer CFA restoration (0: disable, 1: enable)*/
    int32_t BayerRestWeights;
    /*!< IRspatialOffset[2] Spatial shift (y,x) of pixel locations for IR contamination correction*/
    int32_t IRspatialOffset[2];
    /*!< IRbinningFactor[2] Binning factors (y,x) for IR contamination correction*/
    int32_t IRbinningFactor[2];
    /*!< IRcormode IR contamination correction mode (0: disable, 1: enable)*/
    int32_t IRcormode;
    /*!< IRmodelSigma[3] IR contamination model sigma (R,G,B)*/
    int32_t IRmodelSigma[3];
    /*!< IRmodelOffset[3] IR contamination model offset (R,G,B)*/
    int32_t IRmodelOffset[3];
    /*!< IRmodelHeight[3] IR contamination model height (R,G,B)*/
    int32_t IRmodelHeight[3];
    /*!< IRmodelWidth[3] IR contamination model width (R,G,B)*/
    int32_t IRmodelWidth[3];
    /*!< IRmodelMax[3] IR contamination model maximum (R,G,B)*/
    int32_t IRmodelMax[3];
    /*!< IRmodelCUxR[12] IR contamination model configuration unit parameter set X for R channel*/
    int32_t IRmodelCUxR[12];
    /*!< IRmodelCUaR[11] IR contamination model configuration unit parameter set A for R channel*/
    int32_t IRmodelCUaR[11];
    /*!< IRmodelCUbR[11] IR contamination model configuration unit parameter set B for R channel*/
    int32_t IRmodelCUbR[11];
    /*!< IRmodelCUxG[12] IR contamination model configuration unit parameter set X for G channel*/
    int32_t IRmodelCUxG[12];
    /*!< IRmodelCUaG[11] IR contamination model configuration unit parameter set A for G channel*/
    int32_t IRmodelCUaG[11];
    /*!< IRmodelCUbG[11] IR contamination model configuration unit parameter set B for G channel*/
    int32_t IRmodelCUbG[11];
    /*!< IRmodelCUxB[12] IR contamination model configuration unit parameter set X for B channel*/
    int32_t IRmodelCUxB[12];
    /*!< IRmodelCUaB[11] IR contamination model configuration unit parameter set A for B channel*/
    int32_t IRmodelCUaB[11];
    /*!< IRmodelCUbB[11] IR contamination model configuration unit parameter set B for B channel*/
    int32_t IRmodelCUbB[11];
    /*!< IRinterpNeighbors11[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 11*/
    int32_t IRinterpNeighbors11[12];
    /*!< IRinterpNeighbors12[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 12*/
    int32_t IRinterpNeighbors12[12];
    /*!< IRinterpNeighbors13[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 13*/
    int32_t IRinterpNeighbors13[12];
    /*!< IRinterpNeighbors14[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 14*/
    int32_t IRinterpNeighbors14[12];
    /*!< IRinterpNeighbors21[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 21*/
    int32_t IRinterpNeighbors21[12];
    /*!< IRinterpNeighbors22[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 22*/
    int32_t IRinterpNeighbors22[12];
    /*!< IRinterpNeighbors23[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 23*/
    int32_t IRinterpNeighbors23[12];
    /*!< IRinterpNeighbors24[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 24*/
    int32_t IRinterpNeighbors24[12];
    /*!< IRinterpNeighbors31[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 31*/
    int32_t IRinterpNeighbors31[12];
    /*!< IRinterpNeighbors32[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 32*/
    int32_t IRinterpNeighbors32[12];
    /*!< IRinterpNeighbors33[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 33*/
    int32_t IRinterpNeighbors33[12];
    /*!< IRinterpNeighbors34[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 34*/
    int32_t IRinterpNeighbors34[12];
    /*!< IRinterpNeighbors41[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 41*/
    int32_t IRinterpNeighbors41[12];
    /*!< IRinterpNeighbors42[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 42*/
    int32_t IRinterpNeighbors42[12];
    /*!< IRinterpNeighbors43[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 43*/
    int32_t IRinterpNeighbors43[12];
    /*!< IRinterpNeighbors44[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 44*/
    int32_t IRinterpNeighbors44[12];
    /*!< IRscaledSensorDim[2] Scaled sensor dimensions (height,width) for IR contamination correction (optical center calculation); (1 << SHVAL)/SensorDim, for SHVAL = 24. Maximum value assumes that sensor dimensions are larger than 256*/
    int32_t IRscaledSensorDim[2];
    /*!< IRscaledModelSigma[3] Scaled IR contamination model sigma (R,G,B); (1 << SMVAL)/IRmodelSigma, for SMVAL = 16*/
    int32_t IRscaledModelSigma[3];

} ia_pal_isp_rgb_ir_2_0_t;

/*! \isp struct rgb_ir_2_1
RGB-IR
*/
typedef struct
{
    /*!< Bypass Bypass (0,1)*/
    int32_t Bypass;
    /*!< CFArgbir[16] RGB-IR CFA descriptor for 4x4 repetitive pattern (0: R, 1: G, 2: B, 3: IR)*/
    int32_t CFArgbir[16];
    /*!< CFAbayer[4] Bayer CFA descriptor for 2x2 repetitive pattern (0: R, 1: G, 2: B)*/
    int32_t CFAbayer[4];
    /*!< SensorDim[2] Sensor dimensions (height,width) for IR contamination correction (optical center calculation)*/
    int32_t SensorDim[2];
    /*!< ImageDim[2] Image dimensions (height,width)*/
    int32_t ImageDim[2];
    /*!< IRimageDim[2] IR image dimensions (height,width)*/
    int32_t IRimageDim[2];
    /*!< IRtype Type of IR pixel layout (2: IRtype2, 1: IRtype1, 0: any other supported, -1: unsupported)*/
    int32_t IRtype;
    /*!< IRrefloc Pixel location corresponding to the reference (first) IR pixel within a 4x4 repetitive pattern*/
    int32_t IRrefloc;
    /*!< LumaWeights11[25] Filter mask for luminance calculations in CFA locations 11; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights11[25];
    /*!< LumaWeights12[25] Filter mask for luminance calculations in CFA locations 12; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights12[25];
    /*!< LumaWeights13[25] Filter mask for luminance calculations in CFA locations 13; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights13[25];
    /*!< LumaWeights14[25] Filter mask for luminance calculations in CFA locations 14; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights14[25];
    /*!< LumaWeights21[25] Filter mask for luminance calculations in CFA locations 21; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights21[25];
    /*!< LumaWeights22[25] Filter mask for luminance calculations in CFA locations 22; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights22[25];
    /*!< LumaWeights23[25] Filter mask for luminance calculations in CFA locations 23; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights23[25];
    /*!< LumaWeights24[25] Filter mask for luminance calculations in CFA locations 24; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights24[25];
    /*!< LumaWeights31[25] Filter mask for luminance calculations in CFA locations 31; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights31[25];
    /*!< LumaWeights32[25] Filter mask for luminance calculations in CFA locations 32; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights32[25];
    /*!< LumaWeights33[25] Filter mask for luminance calculations in CFA locations 33; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights33[25];
    /*!< LumaWeights34[25] Filter mask for luminance calculations in CFA locations 34; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights34[25];
    /*!< LumaWeights41[25] Filter mask for luminance calculations in CFA locations 41; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights41[25];
    /*!< LumaWeights42[25] Filter mask for luminance calculations in CFA locations 42; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights42[25];
    /*!< LumaWeights43[25] Filter mask for luminance calculations in CFA locations 43; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights43[25];
    /*!< LumaWeights44[25] Filter mask for luminance calculations in CFA locations 44; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights44[25];
    /*!< LumaWeightSums[16] Right bit shifts equivalent to the sum of the luminance filter mask coefficients for all 16 channels (11,12,44) within 4x4 repetitive pattern.*/
    int32_t LumaWeightSums[16];
    /*!< BayerRestNeighbors11[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 11; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors11[8];
    /*!< BayerRestNeighbors12[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 12; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors12[8];
    /*!< BayerRestNeighbors13[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations ; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors13[8];
    /*!< BayerRestNeighbors14[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 14; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors14[8];
    /*!< BayerRestNeighbors21[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 21; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors21[8];
    /*!< BayerRestNeighbors22[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 22; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors22[8];
    /*!< BayerRestNeighbors23[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 23; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors23[8];
    /*!< BayerRestNeighbors24[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 24; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors24[8];
    /*!< BayerRestNeighbors31[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 31; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors31[8];
    /*!< BayerRestNeighbors32[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 32; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors32[8];
    /*!< BayerRestNeighbors33[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 33; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors33[8];
    /*!< BayerRestNeighbors34[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 34; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors34[8];
    /*!< BayerRestNeighbors41[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 41; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors41[8];
    /*!< BayerRestNeighbors42[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 42; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors42[8];
    /*!< BayerRestNeighbors43[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 43; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors43[8];
    /*!< BayerRestNeighbors44[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 44; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors44[8];
    /*!< BayerRestLuma Disable the use of the luminance in Bayer CFA restoration (0: disable, 1: enable)*/
    int32_t BayerRestLuma;
    /*!< BayerRestWeights Disable the use of the weights in Bayer CFA restoration (0: disable, 1: enable)*/
    int32_t BayerRestWeights;
    /*!< IRspatialOffset[2] Spatial shift (y,x) of pixel locations for IR contamination correction*/
    int32_t IRspatialOffset[2];
    /*!< IRbinningFactor[2] Binning factors (y,x) for IR contamination correction*/
    int32_t IRbinningFactor[2];
    /*!< IRcormode IR contamination correction mode (0: disable, 1: enable)*/
    int32_t IRcormode;
    /*!< IRmodelSigma[3] IR contamination model sigma (R,G,B)*/
    int32_t IRmodelSigma[3];
    /*!< IRmodelOffset[3] IR contamination model offset (R,G,B)*/
    int32_t IRmodelOffset[3];
    /*!< IRmodelHeight[3] IR contamination model height (R,G,B)*/
    int32_t IRmodelHeight[3];
    /*!< IRmodelWidth[3] IR contamination model width (R,G,B)*/
    int32_t IRmodelWidth[3];
    /*!< IRmodelMax[3] IR contamination model maximum (R,G,B)*/
    int32_t IRmodelMax[3];
    /*!< IRmodelCUxR[12] IR contamination model configuration unit parameter set X for R channel*/
    int32_t IRmodelCUxR[12];
    /*!< IRmodelCUaR[11] IR contamination model configuration unit parameter set A for R channel*/
    int32_t IRmodelCUaR[11];
    /*!< IRmodelCUbR[11] IR contamination model configuration unit parameter set B for R channel*/
    int32_t IRmodelCUbR[11];
    /*!< IRmodelCUxG[12] IR contamination model configuration unit parameter set X for G channel*/
    int32_t IRmodelCUxG[12];
    /*!< IRmodelCUaG[11] IR contamination model configuration unit parameter set A for G channel*/
    int32_t IRmodelCUaG[11];
    /*!< IRmodelCUbG[11] IR contamination model configuration unit parameter set B for G channel*/
    int32_t IRmodelCUbG[11];
    /*!< IRmodelCUxB[12] IR contamination model configuration unit parameter set X for B channel*/
    int32_t IRmodelCUxB[12];
    /*!< IRmodelCUaB[11] IR contamination model configuration unit parameter set A for B channel*/
    int32_t IRmodelCUaB[11];
    /*!< IRmodelCUbB[11] IR contamination model configuration unit parameter set B for B channel*/
    int32_t IRmodelCUbB[11];
    /*!< IRinterpNeighbors11[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 11*/
    int32_t IRinterpNeighbors11[12];
    /*!< IRinterpNeighbors12[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 12*/
    int32_t IRinterpNeighbors12[12];
    /*!< IRinterpNeighbors13[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 13*/
    int32_t IRinterpNeighbors13[12];
    /*!< IRinterpNeighbors14[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 14*/
    int32_t IRinterpNeighbors14[12];
    /*!< IRinterpNeighbors21[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 21*/
    int32_t IRinterpNeighbors21[12];
    /*!< IRinterpNeighbors22[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 22*/
    int32_t IRinterpNeighbors22[12];
    /*!< IRinterpNeighbors23[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 23*/
    int32_t IRinterpNeighbors23[12];
    /*!< IRinterpNeighbors24[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 24*/
    int32_t IRinterpNeighbors24[12];
    /*!< IRinterpNeighbors31[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 31*/
    int32_t IRinterpNeighbors31[12];
    /*!< IRinterpNeighbors32[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 32*/
    int32_t IRinterpNeighbors32[12];
    /*!< IRinterpNeighbors33[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 33*/
    int32_t IRinterpNeighbors33[12];
    /*!< IRinterpNeighbors34[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 34*/
    int32_t IRinterpNeighbors34[12];
    /*!< IRinterpNeighbors41[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 41*/
    int32_t IRinterpNeighbors41[12];
    /*!< IRinterpNeighbors42[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 42*/
    int32_t IRinterpNeighbors42[12];
    /*!< IRinterpNeighbors43[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 43*/
    int32_t IRinterpNeighbors43[12];
    /*!< IRinterpNeighbors44[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 44*/
    int32_t IRinterpNeighbors44[12];
    /*!< IRscaledSensorDim[2] Scaled sensor dimensions (height,width) for IR contamination correction (optical center calculation); (1 << SHVAL)/SensorDim, for SHVAL = 24. Maximum value assumes that sensor dimensions are larger than 256*/
    int32_t IRscaledSensorDim[2];
    /*!< IRscaledModelSigma[3] Scaled IR contamination model sigma (R,G,B); (1 << SMVAL)/IRmodelSigma, for SMVAL = 16*/
    int32_t IRscaledModelSigma[3];
    /*!< NormLinLshift NormLin lshift*/
    int32_t NormLinLshift;
    /*!< BL[16] Black level values for 4x4 CFA repetitive pattern*/
    int32_t BL[16];
    /*!< DPCmode DPC mode (0: disable, 1: enable)*/
    int32_t DPCmode;
    /*!< DPCneighbors11[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 11*/
    int32_t DPCneighbors11[16];
    /*!< DPCneighbors12[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 12*/
    int32_t DPCneighbors12[16];
    /*!< DPCneighbors13[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 13*/
    int32_t DPCneighbors13[16];
    /*!< DPCneighbors14[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 14*/
    int32_t DPCneighbors14[16];
    /*!< DPCneighbors21[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 21*/
    int32_t DPCneighbors21[16];
    /*!< DPCneighbors22[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 22*/
    int32_t DPCneighbors22[16];
    /*!< DPCneighbors23[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 23*/
    int32_t DPCneighbors23[16];
    /*!< DPCneighbors24[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 24*/
    int32_t DPCneighbors24[16];
    /*!< DPCneighbors31[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 31*/
    int32_t DPCneighbors31[16];
    /*!< DPCneighbors32[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 32*/
    int32_t DPCneighbors32[16];
    /*!< DPCneighbors33[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 33*/
    int32_t DPCneighbors33[16];
    /*!< DPCneighbors34[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 34*/
    int32_t DPCneighbors34[16];
    /*!< DPCneighbors41[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 41*/
    int32_t DPCneighbors41[16];
    /*!< DPCneighbors42[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 42*/
    int32_t DPCneighbors42[16];
    /*!< DPCneighbors43[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 43*/
    int32_t DPCneighbors43[16];
    /*!< DPCneighbors44[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 44*/
    int32_t DPCneighbors44[16];
    /*!< DPCnoiseModel[2] Noise model {a,b} with offset term a and linear term b to calculate noise variance as a+(b*x)>>8*/
    int32_t DPCnoiseModel[2];
    /*!< DPCnorm[5] DPC normalization*/
    int32_t DPCnorm[5];
    /*!< IRblocksize_log2 log2 of IR Block size*/
    int32_t IRblocksize_log2;
    /*!< IRgridX IR grid width*/
    int32_t IRgridX;
    /*!< IRgridY IR grid height*/
    int32_t IRgridY;
    /*!< IRweightsR[170] IR weights (R channel)*/
    int32_t IRweightsR[170];
    /*!< IRweightsG[170] IR weights (G channel)*/
    int32_t IRweightsG[170];
    /*!< IRweightsB[170] IR weights (B channel)*/
    int32_t IRweightsB[170];

} ia_pal_isp_rgb_ir_2_1_t;

/*! \isp struct rgb_ir_2_1_bbb
RGB-IR_BBB Filter
*/
typedef struct
{
    /*!< Bypass Bypass (0,1)*/
    int32_t Bypass;
    /*!< CFArgbir[16] RGB-IR CFA descriptor for 4x4 repetitive pattern (0: R, 1: G, 2: B, 3: IR)*/
    int32_t CFArgbir[16];
    /*!< CFAbayer[4] Bayer CFA descriptor for 2x2 repetitive pattern (0: R, 1: G, 2: B)*/
    int32_t CFAbayer[4];
    /*!< SensorDim[2] Sensor dimensions (height,width) for IR contamination correction (optical center calculation)*/
    int32_t SensorDim[2];
    /*!< ImageDim[2] Image dimensions (height,width)*/
    int32_t ImageDim[2];
    /*!< IRimageDim[2] IR image dimensions (height,width)*/
    int32_t IRimageDim[2];
    /*!< IRtype Type of IR pixel layout (2: IRtype2, 1: IRtype1, 0: any other supported, -1: unsupported)*/
    int32_t IRtype;
    /*!< IRrefloc Pixel location corresponding to the reference (first) IR pixel within a 4x4 repetitive pattern*/
    int32_t IRrefloc;
    /*!< LumaWeights11[9] Filter mask for luminance calculations in CFA locations 11; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights11[9];
    /*!< LumaWeights12[9] Filter mask for luminance calculations in CFA locations 12; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights12[9];
    /*!< LumaWeights13[9] Filter mask for luminance calculations in CFA locations 13; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights13[9];
    /*!< LumaWeights14[9] Filter mask for luminance calculations in CFA locations 14; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights14[9];
    /*!< LumaWeights21[9] Filter mask for luminance calculations in CFA locations 21; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights21[9];
    /*!< LumaWeights22[9] Filter mask for luminance calculations in CFA locations 22; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights22[9];
    /*!< LumaWeights23[9] Filter mask for luminance calculations in CFA locations 23; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights23[9];
    /*!< LumaWeights24[9] Filter mask for luminance calculations in CFA locations 24; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights24[9];
    /*!< LumaWeights31[9] Filter mask for luminance calculations in CFA locations 31; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights31[9];
    /*!< LumaWeights32[9] Filter mask for luminance calculations in CFA locations 32; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights32[9];
    /*!< LumaWeights33[9] Filter mask for luminance calculations in CFA locations 33; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights33[9];
    /*!< LumaWeights34[9] Filter mask for luminance calculations in CFA locations 34; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights34[9];
    /*!< LumaWeights41[9] Filter mask for luminance calculations in CFA locations 41; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights41[9];
    /*!< LumaWeights42[9] Filter mask for luminance calculations in CFA locations 42; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights42[9];
    /*!< LumaWeights43[9] Filter mask for luminance calculations in CFA locations 43; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights43[9];
    /*!< LumaWeights44[9] Filter mask for luminance calculations in CFA locations 44; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights44[9];
    /*!< LumaWeightSums[16] Right bit shifts equivalent to the sum of the luminance filter mask coefficients for all 16 channels (11,12,44) within 4x4 repetitive pattern.*/
    int32_t LumaWeightSums[16];
    /*!< BayerRestNeighbors11[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 11; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors11[8];
    /*!< BayerRestNeighbors12[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 12; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors12[8];
    /*!< BayerRestNeighbors13[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations ; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors13[8];
    /*!< BayerRestNeighbors14[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 14; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors14[8];
    /*!< BayerRestNeighbors21[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 21; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors21[8];
    /*!< BayerRestNeighbors22[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 22; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors22[8];
    /*!< BayerRestNeighbors23[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 23; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors23[8];
    /*!< BayerRestNeighbors24[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 24; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors24[8];
    /*!< BayerRestNeighbors31[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 31; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors31[8];
    /*!< BayerRestNeighbors32[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 32; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors32[8];
    /*!< BayerRestNeighbors33[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 33; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors33[8];
    /*!< BayerRestNeighbors34[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 34; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors34[8];
    /*!< BayerRestNeighbors41[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 41; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors41[8];
    /*!< BayerRestNeighbors42[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 42; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors42[8];
    /*!< BayerRestNeighbors43[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 43; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors43[8];
    /*!< BayerRestNeighbors44[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 44; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors44[8];
    /*!< BayerRestLuma Disable the use of the luminance in Bayer CFA restoration (0: disable, 1: enable)*/
    int32_t BayerRestLuma;
    /*!< BayerRestWeights Disable the use of the weights in Bayer CFA restoration (0: disable, 1: enable)*/
    int32_t BayerRestWeights;
    /*!< IRspatialOffset[2] Spatial shift (y,x) of pixel locations for IR contamination correction*/
    int32_t IRspatialOffset[2];
    /*!< IRbinningFactor[2] Binning factors (y,x) for IR contamination correction*/
    int32_t IRbinningFactor[2];
    /*!< IRcormode IR contamination correction mode (0: disable, 1: enable)*/
    int32_t IRcormode;
    /*!< IRmodelSigma[3] IR contamination model sigma (R,G,B)*/
    int32_t IRmodelSigma[3];
    /*!< IRmodelOffset[3] IR contamination model offset (R,G,B)*/
    int32_t IRmodelOffset[3];
    /*!< IRmodelHeight[3] IR contamination model height (R,G,B)*/
    int32_t IRmodelHeight[3];
    /*!< IRmodelWidth[3] IR contamination model width (R,G,B)*/
    int32_t IRmodelWidth[3];
    /*!< IRmodelMax[3] IR contamination model maximum (R,G,B)*/
    int32_t IRmodelMax[3];
    /*!< IRmodelCUxR[12] IR contamination model configuration unit parameter set X for R channel*/
    int32_t IRmodelCUxR[12];
    /*!< IRmodelCUaR[11] IR contamination model configuration unit parameter set A for R channel*/
    int32_t IRmodelCUaR[11];
    /*!< IRmodelCUbR[11] IR contamination model configuration unit parameter set B for R channel*/
    int32_t IRmodelCUbR[11];
    /*!< IRmodelCUxG[12] IR contamination model configuration unit parameter set X for G channel*/
    int32_t IRmodelCUxG[12];
    /*!< IRmodelCUaG[11] IR contamination model configuration unit parameter set A for G channel*/
    int32_t IRmodelCUaG[11];
    /*!< IRmodelCUbG[11] IR contamination model configuration unit parameter set B for G channel*/
    int32_t IRmodelCUbG[11];
    /*!< IRmodelCUxB[12] IR contamination model configuration unit parameter set X for B channel*/
    int32_t IRmodelCUxB[12];
    /*!< IRmodelCUaB[11] IR contamination model configuration unit parameter set A for B channel*/
    int32_t IRmodelCUaB[11];
    /*!< IRmodelCUbB[11] IR contamination model configuration unit parameter set B for B channel*/
    int32_t IRmodelCUbB[11];
    /*!< IRinterpNeighbors11[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 11*/
    int32_t IRinterpNeighbors11[12];
    /*!< IRinterpNeighbors12[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 12*/
    int32_t IRinterpNeighbors12[12];
    /*!< IRinterpNeighbors13[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 13*/
    int32_t IRinterpNeighbors13[12];
    /*!< IRinterpNeighbors14[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 14*/
    int32_t IRinterpNeighbors14[12];
    /*!< IRinterpNeighbors21[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 21*/
    int32_t IRinterpNeighbors21[12];
    /*!< IRinterpNeighbors22[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 22*/
    int32_t IRinterpNeighbors22[12];
    /*!< IRinterpNeighbors23[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 23*/
    int32_t IRinterpNeighbors23[12];
    /*!< IRinterpNeighbors24[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 24*/
    int32_t IRinterpNeighbors24[12];
    /*!< IRinterpNeighbors31[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 31*/
    int32_t IRinterpNeighbors31[12];
    /*!< IRinterpNeighbors32[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 32*/
    int32_t IRinterpNeighbors32[12];
    /*!< IRinterpNeighbors33[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 33*/
    int32_t IRinterpNeighbors33[12];
    /*!< IRinterpNeighbors34[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 34*/
    int32_t IRinterpNeighbors34[12];
    /*!< IRinterpNeighbors41[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 41*/
    int32_t IRinterpNeighbors41[12];
    /*!< IRinterpNeighbors42[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 42*/
    int32_t IRinterpNeighbors42[12];
    /*!< IRinterpNeighbors43[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 43*/
    int32_t IRinterpNeighbors43[12];
    /*!< IRinterpNeighbors44[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 44*/
    int32_t IRinterpNeighbors44[12];
    /*!< IRscaledSensorDim[2] Scaled sensor dimensions (height,width) for IR contamination correction (optical center calculation); (1 << SHVAL)/SensorDim, for SHVAL = 24. Maximum value assumes that sensor dimensions are larger than 256*/
    int32_t IRscaledSensorDim[2];
    /*!< IRscaledModelSigma[3] Scaled IR contamination model sigma (R,G,B); (1 << SMVAL)/IRmodelSigma, for SMVAL = 16*/
    int32_t IRscaledModelSigma[3];
    /*!< NormLinLshift NormLin lshift*/
    int32_t NormLinLshift;
    /*!< BL[16] Black level values for 4x4 CFA repetitive pattern*/
    int32_t BL[16];
    /*!< DPCmode DPC mode (0: disable, 1: enable)*/
    int32_t DPCmode;
    /*!< DPCneighbors11[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 11*/
    int32_t DPCneighbors11[16];
    /*!< DPCneighbors12[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 12*/
    int32_t DPCneighbors12[16];
    /*!< DPCneighbors13[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 13*/
    int32_t DPCneighbors13[16];
    /*!< DPCneighbors14[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 14*/
    int32_t DPCneighbors14[16];
    /*!< DPCneighbors21[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 21*/
    int32_t DPCneighbors21[16];
    /*!< DPCneighbors22[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 22*/
    int32_t DPCneighbors22[16];
    /*!< DPCneighbors23[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 23*/
    int32_t DPCneighbors23[16];
    /*!< DPCneighbors24[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 24*/
    int32_t DPCneighbors24[16];
    /*!< DPCneighbors31[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 31*/
    int32_t DPCneighbors31[16];
    /*!< DPCneighbors32[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 32*/
    int32_t DPCneighbors32[16];
    /*!< DPCneighbors33[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 33*/
    int32_t DPCneighbors33[16];
    /*!< DPCneighbors34[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 34*/
    int32_t DPCneighbors34[16];
    /*!< DPCneighbors41[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 41*/
    int32_t DPCneighbors41[16];
    /*!< DPCneighbors42[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 42*/
    int32_t DPCneighbors42[16];
    /*!< DPCneighbors43[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 43*/
    int32_t DPCneighbors43[16];
    /*!< DPCneighbors44[16] Spatial offsets (y1,x1,y2,x2,...,y8,x8) of eight neighboring pixels for DPC in CFA locations 44*/
    int32_t DPCneighbors44[16];
    /*!< DPCnoiseModel[2] Noise model {a,b} with offset term a and linear term b to calculate noise variance as a+(b*x)>>8*/
    int32_t DPCnoiseModel[2];
    /*!< IRbinningH Horizontal binning IR output (0 no-binning, 1 2x horizontal binning)*/
    int32_t IRbinningH;
    /*!< IRbinningV Vertical binning IR output (0 no-binning, 1 2x vertical binning)*/
    int32_t IRbinningV;
    /*!< OutputMode Output Mode (0 bayer, 1 ir)*/
    int32_t OutputMode;
    /*!< block_dim Block_dimension (WxH). Log2 block dimension of each grid cell (8x8,16x16,32x32,64x64,128x128, 256x256)*/
    int32_t block_dim;
    /*!< awb_en Enable IR AWB statistics output (0 disable, 1 enable)*/
    int32_t awb_en;
    /*!< shftr_val Shift right average value. Derived from log2 number of pixels in a cell). Note: 1) RGB_IR_2_1 AWB works internally with U11 input. 2) Val will be clipped to U15 after shift*/
    int32_t shftr_val;
    /*!< shftr_sat Shift right saturation. Represents log2(num of pixels in cell). Note: Sat value will be clipped to U8 after shift.*/
    int32_t shftr_sat;
    /*!< rgbs_thr Threshold value for IR saturation calculation. Note: RGB_IR_2_1 AWB works internally with U11 input, so limit max value to (1<<11)-1'))*/
    int32_t rgbs_thr;
    /*!< DPCnorm[5] DPC normalization*/
    int32_t DPCnorm[5];
    /*!< IRblocksize_log2 log2 of IR Block size*/
    int32_t IRblocksize_log2;
    /*!< IRgridX IR grid width*/
    int32_t IRgridX;
    /*!< IRgridY IR grid height*/
    int32_t IRgridY;
    /*!< IRweightsR[170] IR weights (R channel)*/
    int32_t IRweightsR[170];
    /*!< IRweightsG[170] IR weights (G channel)*/
    int32_t IRweightsG[170];
    /*!< IRweightsB[170] IR weights (B channel)*/
    int32_t IRweightsB[170];

} ia_pal_isp_rgb_ir_2_1_bbb_t;

/*! \isp struct rgbs_grid_1_0
RGBS grid (AWB statistics)
*/
typedef struct
{
    /*!< grid_width represents number of horizontal grid cells*/
    int32_t grid_width;
    /*!< grid_height represents number of vertical grid cells*/
    int32_t grid_height;
    /*!< block_width Log2 the width of each grid cell (8,16,32,64,128)*/
    int32_t block_width;
    /*!< block_height Log2 the height of each grid cell (8,16,32,64,128)*/
    int32_t block_height;
    /*!< min_out_bytes_per_cell Minimum bytes per grid cell in output buffer (pad with '0's in MSB side if not met otherwise)*/
    int32_t min_out_bytes_per_cell;
    /*!< rgbs_en 0: FF will not write to the RGBS array; 1: FF will write*/
    int32_t rgbs_en;
    /*!< rgbs_incl_sat 0: do not include saturated quads in the average; 1: include saturated quads in the average*/
    int32_t rgbs_incl_sat;
    /*!< x_start X top left corner of the grid. 0 <= x_start <= (frame_width - 1)*/
    int32_t x_start;
    /*!< y_start Y top left corner of the grid. 0 <= y_start <= (frame_height - 1)*/
    int32_t y_start;
    /*!< x_end X bottom right corner of the grid. x_end = x_start + (grid_width << block_width) - 1*/
    int32_t x_end;
    /*!< y_end Y bottom right corner of the grid. y_end = y_start + (grid_height << block_height) - 1*/
    int32_t y_end;
    /*!< sensor_mode 0: 1x1 CFA (array sensor); 1: 2 x 2 CFA; 2: 4 x 4 CFA*/
    int32_t sensor_mode;
    /*!< pat_00 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_00;
    /*!< pat_01 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_01;
    /*!< pat_02 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_02;
    /*!< pat_03 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_03;
    /*!< pat_10 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_10;
    /*!< pat_11 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_11;
    /*!< pat_12 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_12;
    /*!< pat_13 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_13;
    /*!< pat_20 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_20;
    /*!< pat_21 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_21;
    /*!< pat_22 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_22;
    /*!< pat_23 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_23;
    /*!< pat_30 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_30;
    /*!< pat_31 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_31;
    /*!< pat_32 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_32;
    /*!< pat_33 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_33;
    /*!< rgbs_thr_cx[8] RGBS threshold value (C0, C1, C2, C3, C4, C5, C6, C7)*/
    int32_t rgbs_thr_cx[8];
    /*!< shftr_val_cx[8] ShiftVal is derived from log2(number of pixels from C0-C7 color channel in a cell)*/
    int32_t shftr_val_cx[8];
    /*!< shftr_sat represents log2(num of pixels in cell)*/
    int32_t shftr_sat;
    /*!< output_packed Enabling Output packing. Use 0 if ColorID [0 3] are used, Use 1 if all ColorIDs i.e. [0 7] are used (i.e. multi-exposure (e.g. SVE) use-cases)*/
    int32_t output_packed;
    /*!< copy_out_components bit0: copy_enable_colorid0, bit1..3: copy_src_colorid, bit4: copy_enable_colorid1, bit5..7: copy_src_colorid, ... , bit28: copy_enable_colorid7, bit29..31: copy_src_colorid*/
    uint32_t copy_out_components;

} ia_pal_isp_rgbs_grid_1_0_t;

/*! \isp struct rgbs_statistics_1_0

*/
typedef struct
{
    /*!< grid_width represents number of horizontal grid cells*/
    int32_t grid_width;
    /*!< grid_height represents number of vertical grid cells*/
    int32_t grid_height;
    /*!< block_width Log2 the width of each grid cell (8,16,32,64,128)*/
    int32_t block_width;
    /*!< block_height Log2 the height of each grid cell (8,16,32,64,128)*/
    int32_t block_height;
    /*!< grid_height_per_slice # of blocks in vert.axis per Meta-Data Slice (grid_height_per_slice * grid_width <= 192)*/
    int32_t grid_height_per_slice;
    /*!< awb_en 0: FF will not write to the AWB  array; 1: FF will write*/
    int32_t awb_en;
    /*!< rgbs_incl_sat 0: do not include saturated quads in the average; 1: include saturated quads in the average*/
    int32_t rgbs_incl_sat;
    /*!< x_start X top left corner of the grid. 0 <= x_start <= (frame_width - 1)*/
    int32_t x_start;
    /*!< y_start Y top left corner of the grid. 0 <= y_start <= (frame_height - 1)*/
    int32_t y_start;
    /*!< x_end X bottom right corner of the grid. x_end = x_start + (grid_width << block_width) - 1*/
    int32_t x_end;
    /*!< y_end Y bottom right corner of the grid. y_end = y_start + (grid_height << block_height) - 1*/
    int32_t y_end;
    /*!< sensor_mode 0: 1x1 CFA (array sensor); 1: 2 x 2 CFA; 2: 4 x 4 CFA*/
    int32_t sensor_mode;
    /*!< pat_00 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_00;
    /*!< pat_01 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_01;
    /*!< pat_02 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_02;
    /*!< pat_03 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_03;
    /*!< pat_10 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_10;
    /*!< pat_11 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_11;
    /*!< pat_12 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_12;
    /*!< pat_13 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_13;
    /*!< pat_20 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_20;
    /*!< pat_21 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_21;
    /*!< pat_22 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_22;
    /*!< pat_23 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_23;
    /*!< pat_30 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_30;
    /*!< pat_31 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_31;
    /*!< pat_32 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_32;
    /*!< pat_33 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_33;
    /*!< rgbs_thr_cx[8] RGBS threshold value (C0, C1, C2, C3, C4, C5, C6, C7)*/
    int32_t rgbs_thr_cx[8];
    /*!< shftr_val_cx[8] ShiftVal is derived from log2(number of pixels from C0-C7 color channel in a cell)*/
    int32_t shftr_val_cx[8];
    /*!< shftr_sat Shifter for saturation grid. Represents log2(num of pixels in cell) + 1. In SVE/RGB-IR use cases represent the shifter for saturation grid 0. In SVE, this correspond to long exposure colorIDs[0-3]. In RGB-IR this correspond to RGB colorID[0-2]*/
    int32_t shftr_sat;
    /*!< output_packed Enabling Output packing. Use 0 if ColorID [0 3] are used, Use 1 if all ColorIDs i.e. [0 7] are used (i.e. multi-exposure (e.g. SVE) use-cases)*/
    int32_t output_packed;
    /*!< output_sat_packed Enabling Saturation Output packing for SVE & RGB-IR so that two saturation grids can be used to represent short/long in SVE and  RGB/IR in RGB-IR use cases.*/
    int32_t output_sat_packed;
    /*!< cx_sat_id mapping of ColorIDs 0-7 to saturation grid 0(long exp) or 1(short exp/IR)*/
    int32_t cx_sat_id;
    /*!< shftr_sat_1 Shifter for saturation grid 1. Used only in SVE & RGB-IR. In SVE, this correspond to short exposure colorIDs[4-7]. In RGB-IR this correspond to IR colorID[3]. Represents log2(num of pixels in cell) + 1.*/
    int32_t shftr_sat_1;

} ia_pal_isp_rgbs_statistics_1_0_t;

/*! \isp struct sc_iefd

*/
typedef struct
{
    /*!< bypass Block bypass for HW use*/
    int32_t bypass;
    /*!< horver_diag_coeff Coefficient that compensates for different distnace of vertical/horizontal and diagonal gradient metric*/
    int32_t horver_diag_coeff;
    /*!< ed_horver_diag_coeff Coefficient that compensates for different distnace of vertical/horizontal and diagonal edge metric*/
    int32_t ed_horver_diag_coeff;
    /*!< dir_far_sharp_w Weight of wide kernel direct sharpening*/
    int32_t dir_far_sharp_w;
    /*!< dir_far_dns_w Weight of wide kernel direct denoising*/
    int32_t dir_far_dns_w;
    /*!< ndir_dns_power Power of non-direct denoising*/
    int32_t ndir_dns_power;
    /*!< shrpn_posi_lmt_dir Overshoot limit for edge*/
    int32_t shrpn_posi_lmt_dir;
    /*!< shrpn_nega_lmt_dir Undershoot limit for edge*/
    int32_t shrpn_nega_lmt_dir;
    /*!< shrpn_posi_lmt_txt Overshoot limit for texture*/
    int32_t shrpn_posi_lmt_txt;
    /*!< shrpn_nega_lmt_txt Undershoot limit for texture*/
    int32_t shrpn_nega_lmt_txt;
    /*!< clamp_stitch Slope to stitch between clamped and unclamped edge values*/
    int32_t clamp_stitch;
    /*!< denoise_en Denoise enable flag*/
    int32_t denoise_en;
    /*!< cu6_ndir_shrpn_pwr Power of direct sharpening*/
    int32_t cu6_ndir_shrpn_pwr;
    /*!< cuunsharpen_power Power of unsharp-mask sharpening*/
    int32_t cuunsharpen_power;
    /*!< unsharp_weight Blending weight between unsharp-mask and direct sharpening*/
    int32_t unsharp_weight;
    /*!< unsharp_amount Unsharp-mask extra sharpening power*/
    int32_t unsharp_amount;
    /*!< direct_metric_update Update coefficient for direction metric with 2nd direction*/
    int32_t direct_metric_update;
    /*!< directional_smooth_en Enable smoothing of best direction with second best direction*/
    int32_t directional_smooth_en;
    /*!< rad_enable Enable radial dependency flag*/
    int32_t rad_enable;
    /*!< rad_xreset Radial reset of  x (width)*/
    int32_t rad_xreset;
    /*!< rad_yreset Radial reset of y (height)*/
    int32_t rad_yreset;
    /*!< rad_x2reset Radial reset of x^2 (width^2)*/
    int32_t rad_x2reset;
    /*!< rad_y2reset Radial reset of y^2 (height^2)*/
    int32_t rad_y2reset;
    /*!< rad_nf Scaling down factor of radius^2*/
    int32_t rad_nf;
    /*!< rad_inv_r2 Normalization factor of inverse of radius^2*/
    int32_t rad_inv_r2;
    /*!< rad_dir_far_sharp_w Weight of wide kernel direct sharpening in the periphery*/
    int32_t rad_dir_far_sharp_w;
    /*!< rad_cu6_ndir_shrpn_pwr Power of direct sharpening n the periphery*/
    int32_t rad_cu6_ndir_shrpn_pwr;
    /*!< rad_cuun_shrpn_pwr Power of unsharp-mask sharpening in the periphery*/
    int32_t rad_cuun_shrpn_pwr;
    /*!< rad_cu6_x1 X1 point of ConfigUnit1 in the periphery*/
    int32_t rad_cu6_x1;
    /*!< rad_cuunshrp_x1 X1 point of ConfigUnitUnsharpMask in the periphery*/
    int32_t rad_cuunshrp_x1;
    /*!< rad_dir_far_dns_w Weight of wide kernel direct denoising in the periphery*/
    int32_t rad_dir_far_dns_w;
    /*!< rad_ndir_dns_power Power of non-direct denoising in the periphery*/
    int32_t rad_ndir_dns_power;
    /*!< vssnlm_enable Enable of edge denoising flag*/
    int32_t vssnlm_enable;
    /*!< vs_x0 Edge denoising LUT x0*/
    int32_t vs_x0;
    /*!< vs_x1 Edge denoising LUT x1*/
    int32_t vs_x1;
    /*!< vs_x2 Edge denoising LUT x2*/
    int32_t vs_x2;
    /*!< vs_y1 Edge denoising LUT y0*/
    int32_t vs_y1;
    /*!< vs_y2 Edge denoising LUT y1*/
    int32_t vs_y2;
    /*!< vs_y3 Edge denoising LUT y2*/
    int32_t vs_y3;
    /*!< unsharpfilter[15] Unsharp-mask filter coefficients*/
    int32_t unsharpfilter[15];
    /*!< denoisefilter[6] Denoising filter coefficients*/
    int32_t denoisefilter[6];
    /*!< configunit1_x[2] CU1 x points*/
    int32_t configunit1_x[2];
    /*!< configunit1_slope[1] CU1 slope vlaues*/
    int32_t configunit1_slope[1];
    /*!< configunit3_x[2] CU3 x points*/
    int32_t configunit3_x[2];
    /*!< configunit3_slope[1] CU3 slope vlaues*/
    int32_t configunit3_slope[1];
    /*!< configunit5_x[2] CU5 x points*/
    int32_t configunit5_x[2];
    /*!< configunit5_y[1] CU5 y points*/
    int32_t configunit5_y[1];
    /*!< configunit5_slope[1] CU5 x slope values*/
    int32_t configunit5_slope[1];
    /*!< configunit6_opt_x[4] CU6 x points*/
    int32_t configunit6_opt_x[4];
    /*!< configunit6_opt_y[3] CU6 y points*/
    int32_t configunit6_opt_y[3];
    /*!< configunit6_opt_slope[3] CU6 slope values*/
    int32_t configunit6_opt_slope[3];
    /*!< configunit7_x[2] CU7 x points*/
    int32_t configunit7_x[2];
    /*!< configunit7_slope[1] CU7 slope vlaues*/
    int32_t configunit7_slope[1];
    /*!< configunited_x[6] CU_ED x points*/
    int32_t configunited_x[6];
    /*!< configunited_y[5] CU_ED y points*/
    int32_t configunited_y[5];
    /*!< configunited_slope[5] CU_ED slope vlaues*/
    int32_t configunited_slope[5];
    /*!< configunitunsharp_opt_x[4] CU_UnsharpMask x points*/
    int32_t configunitunsharp_opt_x[4];
    /*!< configunitunsharp_opt_y[3] CU_UnsharpMask y points*/
    int32_t configunitunsharp_opt_y[3];
    /*!< configunitunsharp_opt_slope[3] CU_UnsharpMask slope vlaues*/
    int32_t configunitunsharp_opt_slope[3];
    /*!< configunitradial_x[6] CU_RAD x points*/
    int32_t configunitradial_x[6];
    /*!< configunitradial_y[5] CU_RAD y points*/
    int32_t configunitradial_y[5];
    /*!< configunitradial_slope[5] CU_RAD slope vlaues*/
    int32_t configunitradial_slope[5];
    /*!< configunitvssnlm_x[2] CU_VSSNLM x points*/
    int32_t configunitvssnlm_x[2];
    /*!< configunitvssnlm_slope[1] C_VSSNLM slope vlaues*/
    int32_t configunitvssnlm_slope[1];

} ia_pal_isp_sc_iefd_t;

/*! \isp struct sc_iefd_v2

*/
typedef struct
{
    /*!< enable Block enable for HW use*/
    int32_t enable;
    /*!< horver_diag_coeff Coefficient that compensates for different distnace of vertical/horizontal and diagonal gradient metric*/
    int32_t horver_diag_coeff;
    /*!< ed_horver_diag_coeff Coefficient that compensates for different distnace of vertical/horizontal and diagonal edge metric*/
    int32_t ed_horver_diag_coeff;
    /*!< dir_far_sharp_w Weight of wide kernel direct sharpening*/
    int32_t dir_far_sharp_w;
    /*!< dir_far_dns_w Weight of wide kernel direct denoising*/
    int32_t dir_far_dns_w;
    /*!< ndir_dns_power Power of non-direct denoising*/
    int32_t ndir_dns_power;
    /*!< shrpn_posi_lmt_dir Overshoot limit for edge*/
    int32_t shrpn_posi_lmt_dir;
    /*!< shrpn_nega_lmt_dir Undershoot limit for edge*/
    int32_t shrpn_nega_lmt_dir;
    /*!< shrpn_posi_lmt_txt Overshoot limit for texture*/
    int32_t shrpn_posi_lmt_txt;
    /*!< shrpn_nega_lmt_txt Undershoot limit for texture*/
    int32_t shrpn_nega_lmt_txt;
    /*!< clamp_stitch Slope to stitch between clamped and unclamped edge values*/
    int32_t clamp_stitch;
    /*!< denoise_en Denoise enable flag*/
    int32_t denoise_en;
    /*!< cu6_ndir_shrpn_pwr Power of direct sharpening*/
    int32_t cu6_ndir_shrpn_pwr;
    /*!< cuunsharpen_power Power of unsharp-mask sharpening*/
    int32_t cuunsharpen_power;
    /*!< unsharp_weight Blending weight between unsharp-mask and direct sharpening*/
    int32_t unsharp_weight;
    /*!< unsharp_amount Unsharp-mask extra sharpening power*/
    int32_t unsharp_amount;
    /*!< direct_metric_update Update coefficient for direction metric with 2nd direction*/
    int32_t direct_metric_update;
    /*!< directional_smooth_en Enable smoothing of best direction with second best direction*/
    int32_t directional_smooth_en;
    /*!< rad_enable Enable radial dependency flag*/
    int32_t rad_enable;
    /*!< rad_xreset Radial reset of  x (width)*/
    int32_t rad_xreset;
    /*!< rad_yreset Radial reset of y (height)*/
    int32_t rad_yreset;
    /*!< rad_x2reset Radial reset of x^2 (width^2)*/
    int32_t rad_x2reset;
    /*!< rad_y2reset Radial reset of y^2 (height^2)*/
    int32_t rad_y2reset;
    /*!< rad_nf Scaling down factor of radius^2*/
    int32_t rad_nf;
    /*!< rad_inv_r2 Normalization factor of inverse of radius^2*/
    int32_t rad_inv_r2;
    /*!< rad_dir_far_sharp_w Weight of wide kernel direct sharpening in the periphery*/
    int32_t rad_dir_far_sharp_w;
    /*!< rad_cu6_ndir_shrpn_pwr Power of direct sharpening n the periphery*/
    int32_t rad_cu6_ndir_shrpn_pwr;
    /*!< rad_cuun_shrpn_pwr Power of unsharp-mask sharpening in the periphery*/
    int32_t rad_cuun_shrpn_pwr;
    /*!< rad_cu6_x1 X1 point of ConfigUnit1 in the periphery*/
    int32_t rad_cu6_x1;
    /*!< rad_cuunshrp_x1 X1 point of ConfigUnitUnsharpMask in the periphery*/
    int32_t rad_cuunshrp_x1;
    /*!< rad_dir_far_dns_w Weight of wide kernel direct denoising in the periphery*/
    int32_t rad_dir_far_dns_w;
    /*!< rad_ndir_dns_power Power of non-direct denoising in the periphery*/
    int32_t rad_ndir_dns_power;
    /*!< vssnlm_enable Enable of edge denoising flag*/
    int32_t vssnlm_enable;
    /*!< vs_x0 Edge denoising LUT x0*/
    int32_t vs_x0;
    /*!< vs_x1 Edge denoising LUT x1*/
    int32_t vs_x1;
    /*!< vs_x2 Edge denoising LUT x2*/
    int32_t vs_x2;
    /*!< vs_y1 Edge denoising LUT y0*/
    int32_t vs_y1;
    /*!< vs_y2 Edge denoising LUT y1*/
    int32_t vs_y2;
    /*!< vs_y3 Edge denoising LUT y2*/
    int32_t vs_y3;
    /*!< unsharpfilter[15] Unsharp-mask filter coefficients*/
    int32_t unsharpfilter[15];
    /*!< denoisefilter[6] Denoising filter coefficients*/
    int32_t denoisefilter[6];
    /*!< configunit1_x[2] CU1 x points*/
    int32_t configunit1_x[2];
    /*!< configunit1_slope[1] CU1 slope values*/
    int32_t configunit1_slope[1];
    /*!< configunit3_x[2] CU3 x points*/
    int32_t configunit3_x[2];
    /*!< configunit3_slope[1] CU3 slope values*/
    int32_t configunit3_slope[1];
    /*!< configunit5_x[2] CU5 x points*/
    int32_t configunit5_x[2];
    /*!< configunit5_y[1] CU5 y points*/
    int32_t configunit5_y[1];
    /*!< configunit5_slope[1] CU5 x slope values*/
    int32_t configunit5_slope[1];
    /*!< configunit6_opt_x[4] CU6 x points*/
    int32_t configunit6_opt_x[4];
    /*!< configunit6_opt_y[3] CU6 y points*/
    int32_t configunit6_opt_y[3];
    /*!< configunit6_opt_slope[3] CU6 slope values*/
    int32_t configunit6_opt_slope[3];
    /*!< configunit7_x[2] CU7 x points*/
    int32_t configunit7_x[2];
    /*!< configunit7_slope[1] CU7 slope vlaues*/
    int32_t configunit7_slope[1];
    /*!< configunited_x[6] CU_ED x points*/
    int32_t configunited_x[6];
    /*!< configunited_y[5] CU_ED y points*/
    int32_t configunited_y[5];
    /*!< configunited_slope[5] CU_ED slope values*/
    int32_t configunited_slope[5];
    /*!< configunitunsharp_opt_x[4] CU_UnsharpMask x points*/
    int32_t configunitunsharp_opt_x[4];
    /*!< configunitunsharp_opt_y[3] CU_UnsharpMask y points*/
    int32_t configunitunsharp_opt_y[3];
    /*!< configunitunsharp_opt_slope[3] CU_UnsharpMask slope values*/
    int32_t configunitunsharp_opt_slope[3];
    /*!< configunitradial_x[6] CU_RAD x points*/
    int32_t configunitradial_x[6];
    /*!< configunitradial_y[5] CU_RAD y points*/
    int32_t configunitradial_y[5];
    /*!< configunitradial_slope[5] CU_RAD slope values*/
    int32_t configunitradial_slope[5];
    /*!< configunitvssnlm_x[2] CU_VSSNLM x points*/
    int32_t configunitvssnlm_x[2];
    /*!< configunitvssnlm_slope[1] CU_VSSNLM slope values*/
    int32_t configunitvssnlm_slope[1];
    /*!< configunitusmpownorm_x[6] CU_USM_POW x points*/
    int32_t configunitusmpownorm_x[6];
    /*!< configunitusmpownorm_y[5] CU_USM_POW y points*/
    int32_t configunitusmpownorm_y[5];
    /*!< configunitusmpownorm_slope[5] CU_USM_POW slope values*/
    int32_t configunitusmpownorm_slope[5];
    /*!< unsharpmet Enable gradient protection*/
    int32_t unsharpmet;
    /*!< gradth Threshold for zeroing derivative*/
    int32_t gradth;

} ia_pal_isp_sc_iefd_v2_t;

/*! \isp struct sc_outputscaler_dp

*/
typedef struct
{
    /*!< bypass bypass the scaler*/
    int32_t bypass;
    /*!< block_width Horizontal size of output block*/
    int32_t block_width;
    /*!< block_height Vertical size of output block*/
    int32_t block_height;
    /*!< chunk_width Horizontal size of input chunk*/
    int32_t chunk_width;
    /*!< chunk_height Vertical size of input chunk*/
    int32_t chunk_height;
    /*!< input_image_y_start_column AKA 'Start column' of the Y plane: support for left croping. Always 0 unless striping mode is applied.*/
    int32_t input_image_y_start_column;
    /*!< input_image_uv_start_column AKA 'Start column' of the UV plane: support for left croping. Always 0 unless striping mode is applied.*/
    int32_t input_image_uv_start_column;
    /*!< in_width_y Width of the input image Y plane (in pixels)*/
    int32_t in_width_y;
    /*!< in_height_y Height of the input image Y plane (in pixels)*/
    int32_t in_height_y;
    /*!< in_width_uv Width of the input image UV plane (in pixels)*/
    int32_t in_width_uv;
    /*!< in_height_uv Height of the input image UV plane (in pixels)*/
    int32_t in_height_uv;
    /*!< out_width_y Width of the output image Y plane (in pixels)*/
    int32_t out_width_y;
    /*!< out_height_y Height of the output image Y plane (in pixels)*/
    int32_t out_height_y;
    /*!< out_width_uv Width of the output image UV plane (in pixels)*/
    int32_t out_width_uv;
    /*!< out_height_uv Height of the output image UV plane (in pixels)*/
    int32_t out_height_uv;
    /*!< updown_sel Processing mode: 0-bypass. 1-upscale. 2-downscale*/
    int32_t updown_sel;
    /*!< coeff_lut_y[128] Polyphase Y look-up table*/
    int32_t coeff_lut_y[128];
    /*!< coeff_lut_uv[64] Polyphase U/V look-up table*/
    int32_t coeff_lut_uv[64];
    /*!< scaling_ratio AKA 'phase_step' - defines up- or downscaling factor. For up-scaling minimum is 682 and for down scaling minimum is 171. maximum is for both 2048.*/
    int32_t scaling_ratio;
    /*!< phase_init_y_top Starting phase of polyphase Y filter on top image boundary*/
    int32_t phase_init_y_top;
    /*!< phase_init_y_left Starting phase of polyphase Y filter on left image boundary*/
    int32_t phase_init_y_left;
    /*!< phase_init_uv_top Starting phase of polyphase U/V filter on top image boundary*/
    int32_t phase_init_uv_top;
    /*!< phase_init_uv_left Starting phase of polyphase U/V filter on left image boundary*/
    int32_t phase_init_uv_left;
    /*!< pad_left_y Image left padding: Y component*/
    int32_t pad_left_y;
    /*!< pad_left_uv Image left padding: U/V components*/
    int32_t pad_left_uv;
    /*!< pad_right_y Image right padding: Y component*/
    int32_t pad_right_y;
    /*!< pad_right_uv Image right padding: U/V components*/
    int32_t pad_right_uv;
    /*!< pad_top_y Image top padding: Y component*/
    int32_t pad_top_y;
    /*!< pad_top_uv Image top padding: U/V components*/
    int32_t pad_top_uv;
    /*!< pad_bttm_y Image bottom padding: Y component*/
    int32_t pad_bttm_y;
    /*!< pad_bttm_uv Image bottom padding: U/V components*/
    int32_t pad_bttm_uv;
    /*!< exp_shift Scaling filter coefficients exponent shift*/
    int32_t exp_shift;
    /*!< output0_out_y_left_crop Left cropping of filter output Y plane*/
    int32_t output0_out_y_left_crop;
    /*!< output0_out_uv_left_crop Left cropping of filter output U/V planes*/
    int32_t output0_out_uv_left_crop;
    /*!< output0_out_y_top_crop Top cropping of filter output Y plane*/
    int32_t output0_out_y_top_crop;
    /*!< output0_out_uv_top_crop Top cropping of filter output U/V planes*/
    int32_t output0_out_uv_top_crop;

} ia_pal_isp_sc_outputscaler_dp_t;

/*! \isp struct sc_outputscaler_dp_1_1

*/
typedef struct
{
    /*!< bypass bypass the scaler*/
    int32_t bypass;
    /*!< block_width Horizontal size of output block*/
    int32_t block_width;
    /*!< block_height Vertical size of output block*/
    int32_t block_height;
    /*!< chunk_width Horizontal size of input chunk*/
    int32_t chunk_width;
    /*!< chunk_height Vertical size of input chunk*/
    int32_t chunk_height;
    /*!< input_image_y_start_column AKA 'Start column' of the Y plane: support for left croping. Always 0 unless striping mode is applied.*/
    int32_t input_image_y_start_column;
    /*!< input_image_uv_start_column AKA 'Start column' of the UV plane: support for left croping. Always 0 unless striping mode is applied.*/
    int32_t input_image_uv_start_column;
    /*!< in_width_y Width of the input image Y plane (in pixels)*/
    int32_t in_width_y;
    /*!< in_height_y Height of the input image Y plane (in pixels)*/
    int32_t in_height_y;
    /*!< in_width_uv Width of the input image UV plane (in pixels)*/
    int32_t in_width_uv;
    /*!< in_height_uv Height of the input image UV plane (in pixels)*/
    int32_t in_height_uv;
    /*!< out_width_y Width of the output image Y plane (in pixels)*/
    int32_t out_width_y;
    /*!< out_height_y Height of the output image Y plane (in pixels)*/
    int32_t out_height_y;
    /*!< out_width_uv Width of the output image UV plane (in pixels)*/
    int32_t out_width_uv;
    /*!< out_height_uv Height of the output image UV plane (in pixels)*/
    int32_t out_height_uv;
    /*!< updown_sel Processing mode: 0-bypass. 1-upscale. 2-downscale*/
    int32_t updown_sel;
    /*!< coeff_lut_y[128] Polyphase Y look-up table*/
    int32_t coeff_lut_y[128];
    /*!< coeff_lut_uv[64] Polyphase U/V look-up table*/
    int32_t coeff_lut_uv[64];
    /*!< scaling_ratio AKA 'phase_step' - defines up- or downscaling factor. For up-scaling minimum is 682 and for down scaling minimum is 171. maximum is for both 2048.*/
    int32_t scaling_ratio;
    /*!< phase_init_y_top Starting phase of polyphase Y filter on top image boundary*/
    int32_t phase_init_y_top;
    /*!< phase_init_y_left Starting phase of polyphase Y filter on left image boundary*/
    int32_t phase_init_y_left;
    /*!< phase_init_uv_top Starting phase of polyphase U/V filter on top image boundary*/
    int32_t phase_init_uv_top;
    /*!< phase_init_uv_left Starting phase of polyphase U/V filter on left image boundary*/
    int32_t phase_init_uv_left;
    /*!< pad_left_y Image left padding: Y component*/
    int32_t pad_left_y;
    /*!< pad_left_uv Image left padding: U/V components*/
    int32_t pad_left_uv;
    /*!< pad_right_y Image right padding: Y component*/
    int32_t pad_right_y;
    /*!< pad_right_uv Image right padding: U/V components*/
    int32_t pad_right_uv;
    /*!< pad_top_y Image top padding: Y component*/
    int32_t pad_top_y;
    /*!< pad_top_uv Image top padding: U/V components*/
    int32_t pad_top_uv;
    /*!< pad_bttm_y Image bottom padding: Y component*/
    int32_t pad_bttm_y;
    /*!< pad_bttm_uv Image bottom padding: U/V components*/
    int32_t pad_bttm_uv;
    /*!< exp_shift Scaling filter coefficients exponent shift*/
    int32_t exp_shift;
    /*!< output0_out_y_left_crop Left cropping of filter output Y plane*/
    int32_t output0_out_y_left_crop;
    /*!< output0_out_uv_left_crop Left cropping of filter output U/V planes*/
    int32_t output0_out_uv_left_crop;
    /*!< output0_out_y_top_crop Top cropping of filter output Y plane*/
    int32_t output0_out_y_top_crop;
    /*!< output0_out_uv_top_crop Top cropping of filter output U/V planes*/
    int32_t output0_out_uv_top_crop;
    /*!< input_bpp 0- 8 bpp 1 -10 bpp 2- 12 bpp*/
    int32_t input_bpp;

} ia_pal_isp_sc_outputscaler_dp_1_1_t;

/*! \isp struct sc_outputscaler_ppp

*/
typedef struct
{
    /*!< bypass bypass the scaler*/
    int32_t bypass;
    /*!< block_width Horizontal size of output block*/
    int32_t block_width;
    /*!< block_height Vertical size of output block*/
    int32_t block_height;
    /*!< chunk_width Horizontal size of input chunk*/
    int32_t chunk_width;
    /*!< chunk_height Vertical size of input chunk*/
    int32_t chunk_height;
    /*!< input_image_y_start_column AKA 'Start column' of the Y plane: support for left croping. Always 0 unless striping mode is applied.*/
    int32_t input_image_y_start_column;
    /*!< input_image_uv_start_column AKA 'Start column' of the UV plane: support for left croping. Always 0 unless striping mode is applied.*/
    int32_t input_image_uv_start_column;
    /*!< in_width_y Width of the input image Y plane (in pixels)*/
    int32_t in_width_y;
    /*!< in_height_y Height of the input image Y plane (in pixels)*/
    int32_t in_height_y;
    /*!< in_width_uv Width of the input image UV plane (in pixels)*/
    int32_t in_width_uv;
    /*!< in_height_uv Height of the input image UV plane (in pixels)*/
    int32_t in_height_uv;
    /*!< out_width_y Width of the output image Y plane (in pixels)*/
    int32_t out_width_y;
    /*!< out_height_y Height of the output image Y plane (in pixels)*/
    int32_t out_height_y;
    /*!< out_width_uv Width of the output image UV plane (in pixels)*/
    int32_t out_width_uv;
    /*!< out_height_uv Height of the output image UV plane (in pixels)*/
    int32_t out_height_uv;
    /*!< updown_sel Processing mode: 0-bypass. 1-upscale. 2-downscale*/
    int32_t updown_sel;
    /*!< coeff_lut_y[128] Polyphase Y look-up table*/
    int32_t coeff_lut_y[128];
    /*!< coeff_lut_uv[64] Polyphase U/V look-up table*/
    int32_t coeff_lut_uv[64];
    /*!< scaling_ratio AKA 'phase_step' - defines up- or downscaling factor. For up-scaling minimum is 682 and for down scaling minimum is 171. maximum is for both 2048.*/
    int32_t scaling_ratio;
    /*!< phase_init_y_top Starting phase of polyphase Y filter on top image boundary*/
    int32_t phase_init_y_top;
    /*!< phase_init_y_left Starting phase of polyphase Y filter on left image boundary*/
    int32_t phase_init_y_left;
    /*!< phase_init_uv_top Starting phase of polyphase U/V filter on top image boundary*/
    int32_t phase_init_uv_top;
    /*!< phase_init_uv_left Starting phase of polyphase U/V filter on left image boundary*/
    int32_t phase_init_uv_left;
    /*!< pad_left_y Image left padding: Y component*/
    int32_t pad_left_y;
    /*!< pad_left_uv Image left padding: U/V components*/
    int32_t pad_left_uv;
    /*!< pad_right_y Image right padding: Y component*/
    int32_t pad_right_y;
    /*!< pad_right_uv Image right padding: U/V components*/
    int32_t pad_right_uv;
    /*!< pad_top_y Image top padding: Y component*/
    int32_t pad_top_y;
    /*!< pad_top_uv Image top padding: U/V components*/
    int32_t pad_top_uv;
    /*!< pad_bttm_y Image bottom padding: Y component*/
    int32_t pad_bttm_y;
    /*!< pad_bttm_uv Image bottom padding: U/V components*/
    int32_t pad_bttm_uv;
    /*!< exp_shift Scaling filter coefficients exponent shift*/
    int32_t exp_shift;
    /*!< output0_out_y_left_crop Left cropping of filter output Y plane*/
    int32_t output0_out_y_left_crop;
    /*!< output0_out_uv_left_crop Left cropping of filter output U/V planes*/
    int32_t output0_out_uv_left_crop;
    /*!< output0_out_y_top_crop Top cropping of filter output Y plane*/
    int32_t output0_out_y_top_crop;
    /*!< output0_out_uv_top_crop Top cropping of filter output U/V planes*/
    int32_t output0_out_uv_top_crop;

} ia_pal_isp_sc_outputscaler_ppp_t;

/*! \isp struct sc_outputscaler_ppp_1_1

*/
typedef struct
{
    /*!< bypass bypass the scaler*/
    int32_t bypass;
    /*!< block_width Horizontal size of output block*/
    int32_t block_width;
    /*!< block_height Vertical size of output block*/
    int32_t block_height;
    /*!< chunk_width Horizontal size of input chunk*/
    int32_t chunk_width;
    /*!< chunk_height Vertical size of input chunk*/
    int32_t chunk_height;
    /*!< input_image_y_start_column AKA 'Start column' of the Y plane: support for left croping. Always 0 unless striping mode is applied.*/
    int32_t input_image_y_start_column;
    /*!< input_image_uv_start_column AKA 'Start column' of the UV plane: support for left croping. Always 0 unless striping mode is applied.*/
    int32_t input_image_uv_start_column;
    /*!< in_width_y Width of the input image Y plane (in pixels)*/
    int32_t in_width_y;
    /*!< in_height_y Height of the input image Y plane (in pixels)*/
    int32_t in_height_y;
    /*!< in_width_uv Width of the input image UV plane (in pixels)*/
    int32_t in_width_uv;
    /*!< in_height_uv Height of the input image UV plane (in pixels)*/
    int32_t in_height_uv;
    /*!< out_width_y Width of the output image Y plane (in pixels)*/
    int32_t out_width_y;
    /*!< out_height_y Height of the output image Y plane (in pixels)*/
    int32_t out_height_y;
    /*!< out_width_uv Width of the output image UV plane (in pixels)*/
    int32_t out_width_uv;
    /*!< out_height_uv Height of the output image UV plane (in pixels)*/
    int32_t out_height_uv;
    /*!< updown_sel Processing mode: 0-bypass. 1-upscale. 2-downscale*/
    int32_t updown_sel;
    /*!< coeff_lut_y[128] Polyphase Y look-up table*/
    int32_t coeff_lut_y[128];
    /*!< coeff_lut_uv[64] Polyphase U/V look-up table*/
    int32_t coeff_lut_uv[64];
    /*!< scaling_ratio AKA 'phase_step' - defines up- or downscaling factor. For up-scaling minimum is 682 and for down scaling minimum is 171. maximum is for both 2048.*/
    int32_t scaling_ratio;
    /*!< phase_init_y_top Starting phase of polyphase Y filter on top image boundary*/
    int32_t phase_init_y_top;
    /*!< phase_init_y_left Starting phase of polyphase Y filter on left image boundary*/
    int32_t phase_init_y_left;
    /*!< phase_init_uv_top Starting phase of polyphase U/V filter on top image boundary*/
    int32_t phase_init_uv_top;
    /*!< phase_init_uv_left Starting phase of polyphase U/V filter on left image boundary*/
    int32_t phase_init_uv_left;
    /*!< pad_left_y Image left padding: Y component*/
    int32_t pad_left_y;
    /*!< pad_left_uv Image left padding: U/V components*/
    int32_t pad_left_uv;
    /*!< pad_right_y Image right padding: Y component*/
    int32_t pad_right_y;
    /*!< pad_right_uv Image right padding: U/V components*/
    int32_t pad_right_uv;
    /*!< pad_top_y Image top padding: Y component*/
    int32_t pad_top_y;
    /*!< pad_top_uv Image top padding: U/V components*/
    int32_t pad_top_uv;
    /*!< pad_bttm_y Image bottom padding: Y component*/
    int32_t pad_bttm_y;
    /*!< pad_bttm_uv Image bottom padding: U/V components*/
    int32_t pad_bttm_uv;
    /*!< exp_shift Scaling filter coefficients exponent shift*/
    int32_t exp_shift;
    /*!< output0_out_y_left_crop Left cropping of filter output Y plane*/
    int32_t output0_out_y_left_crop;
    /*!< output0_out_uv_left_crop Left cropping of filter output U/V planes*/
    int32_t output0_out_uv_left_crop;
    /*!< output0_out_y_top_crop Top cropping of filter output Y plane*/
    int32_t output0_out_y_top_crop;
    /*!< output0_out_uv_top_crop Top cropping of filter output U/V planes*/
    int32_t output0_out_uv_top_crop;
    /*!< input_bpp 0- 8 bpp 1 -10 bpp 2- 12 bpp*/
    int32_t input_bpp;

} ia_pal_isp_sc_outputscaler_ppp_1_1_t;

/*! \isp struct sc_ylpf

*/
typedef struct
{
    /*!< m_bypass Block Bypass. Must be set to 0 for operatinal mode*/
    int32_t m_bypass;
    /*!< m_vec_kernels[8] configuration DS kernel vector*/
    int32_t m_vec_kernels[8];
    /*!< m_decimationmode decimationMode{0.m444,1.m422,2.m420}*/
    int32_t m_decimationmode;

} ia_pal_isp_sc_ylpf_t;

/*! \isp struct sdp_scp

*/
typedef struct
{
    /*!< remove_thresh Threshold for Outlier removal in RSM. 8bit integer (8.0)*/
    uint32_t remove_thresh;
    /*!< slo_rau_diff_thresh Threshold for SLO and RAU disparity difference in RSM. Fixed point 7bit (2.5)*/
    uint32_t slo_rau_diff_thresh;
    /*!< diff_thresh Threshold for SLO disparity difference to Center in RSM. Fixed point 8bit (3.5)*/
    uint32_t diff_thresh;
    /*!< rsm_bypass RSM Bypass mode. 1=Bypass (default). At Bypass mode, SLO disparity input will be bypassed to RSM disparity output.*/
    uint32_t rsm_bypass;
    /*!< rsm_bypass_cg Clock gate control for the block which is not used at RSM Bypass mode. 1=Clock gate. 0=Clock enabled (default). RSM_Bypass_CG must be 0 (=clock enabled) at least 1 clock period before and after RSM_Bypass_SD transition.*/
    uint32_t rsm_bypass_cg;
    /*!< rsm_bypass_sd SRAM shutdown control for SRAM1 which is not used at RSM Bypass mode in RSM. 1=Shutdown. 0=Enabled (default). RSM_Bypass_CG must be 0 (=clock enabled) at least 1 clock period before and after RSM_Bypass_SD transition. Also need to not read/write SRAM for 30 sclk cycle when SD goes low (waking up)*/
    uint32_t rsm_bypass_sd;
    /*!< additional_vblank Define number of scan line to add to 4 scan line censusPipeStall for V blank. When set N at this additional_vblank, censusPipeStall will be high for 4 + N scan line period for V blank. N can be set as 0 (default) to 15. For RSM bypass mode, please set 3. For RSM mode, please set 9.*/
    uint32_t additional_vblank;
    /*!< en_scp_local_clk_gate Enable SCP local clock gate for DS5-B0. 1=Enable (default). 0=Disable.*/
    uint32_t en_scp_local_clk_gate;
    /*!< en One bit per census pixel*/
    uint32_t en;
    /*!< width Number of pixels per line in the input/output images. Valid values 256 to 1280*/
    uint32_t width;
    /*!< height Number of lines in the input/output images. Valid values 40 to 1024*/
    uint32_t height;
    /*!< plus_increment This value is added to the running-median estimate of the estimate is below the sequentially-sampled correlation score.*/
    uint32_t plus_increment;
    /*!< minus_decrement This value is subtracted from the running-median estimate of the estimate is above the sequentially-sampled correlation score.*/
    uint32_t minus_decrement;
    /*!< score_thresh_a Contains a 10-bit binary number used directly as a threshold for the winning Left-Right score. Interest operator bit 0 asserts if the winning score is greater than or equal Score Thresh A .*/
    uint32_t score_thresh_a;
    /*!< score_thresh_b Contains a 12-bit binary threshold for the winning Left-Right score. Interest operator bit 1 asserts if the winning score is greater than Score Thresh B.*/
    uint32_t score_thresh_b;
    /*!< deepsea_neighbor_threshold Contains a 10-bit binary number compared against the difference of the pre (and post) score and the winning score. Interest operator bit 2 asserts if the post score is greater than Neighbor Threshold. Interest operator bit 3 asserts if the pre score is greater than Neighbor Threshold.*/
    uint32_t deepsea_neighbor_threshold;
    /*!< lr_agree_threshold Contain an 11-bit binary number used directly as LR threshold. Interest operator bit 8 asserts if difference between the LR and RL disparities are less than threshold.*/
    uint32_t lr_agree_threshold;
    /*!< lr_score_average_disable Disables the averaging of LR and RL scores when set.*/
    uint32_t lr_score_average_disable;
    /*!< texture_difference_threshold Bits 0..11 of the {Texture Thresh} configuration register contain a 12-bit binary number which is used directly. This value defines the threshold to use in the the Texture operator difference calculation.*/
    uint32_t texture_difference_threshold;
    /*!< texture_count_threshold Bits 12..17 of the {Texture Thresh} configuration register contain a 5-bit binary number which is used directly to compare to the count of the number of significantly different pixel locations in the active census kernel neighborhood.*/
    uint32_t texture_count_threshold;
    /*!< deepsea_second_peak_threshold Second Peak Threshold*/
    uint32_t deepsea_second_peak_threshold;
    /*!< deepsea_median_threshold Median Threshold*/
    uint32_t deepsea_median_threshold;
    /*!< or_mask_bits_zencoder0 Bits [15:0] are ORed with the Z output data to generate prs_dout*/
    uint32_t or_mask_bits_zencoder0;
    /*!< and_mask_bits_zencoder0 Bits [31:16] are ANDed with the Z output data to generate prs_dout*/
    uint32_t and_mask_bits_zencoder0;
    /*!< or_mask_bits_zencoder1 Bits [15:0] are ORed with the Z output data to generate prs_dout*/
    uint32_t or_mask_bits_zencoder1;
    /*!< and_mask_bits_zencoder1 Bits [31:16] are ANDed with the Z output data to generate prs_dout*/
    uint32_t and_mask_bits_zencoder1;
    /*!< minwest Sets the left Horizontal Minimum when the color differences calculation has Fewer than horizontalSumMin pixels. If the Color Control register has RAU color disabled, then minWest defines the west offset for a fixed region.*/
    uint32_t minwest;
    /*!< mineast Sets the right Horizontal Minimum when the color differences calculation has Fewer than horizontalSumMin pixels. If the Color Control register has RAU color disabled, then minEast defines the east offset for a fixed region.*/
    uint32_t mineast;
    /*!< minwesum Sets the horizontal sum minimum, usually leftMin + rightMin +1. Valid values 3 through 15.*/
    uint32_t minwesum;
    /*!< minnorth Sets the up vertical minimimum when the color differences calculation has Fewer than verticalSumMin pixels. If the Color Control register has RAU color disabled, then minNorth defines the north offset for a fixed region.*/
    uint32_t minnorth;
    /*!< minsouth Sets the down Vertical Minimum when the color differences calculation has Fewer than verticalSumMin pixels. If the Color Control register has RAU color disabled, then minSouth defines the south offset for a fixed region.*/
    uint32_t minsouth;
    /*!< minnssum Sets the vertical sum minimum- usually upMin+downMin+1. Valid values 1 through 7.*/
    uint32_t minnssum;
    /*!< ushrink Sets the horizontal shrink factor. Valid values 0 through 4.*/
    uint32_t ushrink;
    /*!< vshrink Sets the vertical shrink factor. Valid values 0 and 1.*/
    uint32_t vshrink;
    /*!< disablesadcolor Disables Sum of Absolute Differences function*/
    uint32_t disablesadcolor;
    /*!< disableraucolor disable RAU color function and use region defined by minimum support vectors*/
    uint32_t disableraucolor;
    /*!< disableslorightcolor disable SLO right image color function and use default penalties*/
    uint32_t disableslorightcolor;
    /*!< disablesloleftcolor disable SLO left image color function and use default penalties*/
    uint32_t disablesloleftcolor;
    /*!< disablesadnormalize In the SAD function, disable normalization and use the unmodified RGB values.*/
    uint32_t disablesadnormalize;
    /*!< raudiffthresholdred Sets the RAU color difference comparison threshold for the Red component.*/
    uint32_t raudiffthresholdred;
    /*!< raudiffthresholdgreen Sets the RAU color difference comparison threshold for the Green component.*/
    uint32_t raudiffthresholdgreen;
    /*!< raudiffthresholdblue Sets the RAU color difference comparison threshold for the Blue component.*/
    uint32_t raudiffthresholdblue;
    /*!< diffthresholdred Sets the SLO color difference comparison threshold for the Red component.*/
    uint32_t diffthresholdred;
    /*!< diffthresholdgreen Sets the SLO color difference comparison threshold for the Green component.*/
    uint32_t diffthresholdgreen;
    /*!< diffthresholdblue Sets the SLO color difference comparison threshold for the Blue component.*/
    uint32_t diffthresholdblue;
    /*!< k1penalty Sets the SLO K1 Penalty to apply when not modified by color comparisons. Valid values 1 through 511.*/
    uint32_t k1penalty;
    /*!< k2penalty Sets the SLO K2 Penalty to apply when not modified by color comparisons. Valid values 1 through 511.*/
    uint32_t k2penalty;
    /*!< k1penaltymod1 Sets the SLO K1 Penalty to apply when modified by one color comparison. Valid values 1 through 511.*/
    uint32_t k1penaltymod1;
    /*!< k1penaltymod2 Sets the SLO K2 Penalty to apply when not modified by color comparisons. Valid values 1 through 511.*/
    uint32_t k1penaltymod2;
    /*!< k2penaltymod1 Sets the SLO K1 Penalty to apply when modified by one color comparison. Valid values 1 through 511.*/
    uint32_t k2penaltymod1;
    /*!< k2penaltymod2 Sets the SLO K2 Penalty to apply when modified by one color comparison. Valid values 1 through 511.*/
    uint32_t k2penaltymod2;
    /*!< x_start First pixel in the row for the WOI of the FFC, min value 0, max value 1279*/
    uint32_t x_start;
    /*!< y_start First pixel in the column for the WOI of the FFC, min value 0, max value 1023*/
    uint32_t y_start;
    /*!< woi_width Width of the WOI for the FFC, min value 1, max value 1280*/
    uint32_t woi_width;
    /*!< woi_height Height of the WOI for the FFC, min value 1, max value 1024*/
    uint32_t woi_height;
    /*!< nonvalid_mask Mask the map values for identifying nonvalid pixels*/
    uint32_t nonvalid_mask;
    /*!< nonvalid_value Expected value of nonvalid pixels*/
    uint32_t nonvalid_value;
    /*!< pmu_scp_pre_clk_gate_enable if set, enable clock gating for SCP-PRE module managed by pmu*/
    uint32_t pmu_scp_pre_clk_gate_enable;
    /*!< pmu_scp_rau_clk_gate_enable if set, enable clock gating for SCP-RAU module managed by pmu*/
    uint32_t pmu_scp_rau_clk_gate_enable;
    /*!< pmu_scp_post_clk_gate_enable if set, enable clock gating for SCP-POST module managed by pmu*/
    uint32_t pmu_scp_post_clk_gate_enable;
    /*!< hamming_dist_lut[32] 32 deep by 8-bit lookup table for scaling Hamming Distance Values in bcc. Addressed by Hamming Distance, output is scaled value*/
    uint32_t hamming_dist_lut[32];
    /*!< sad_lut[256] 256 deep by 8-bit lookup table for scaling color Sum Of Distance Values in bcc. Addressed by SAD, output is scaled value*/
    uint32_t sad_lut[256];
    /*!< rau_inverse_lut[106] 106 deep by 16-bit lookup table for scaling color Sum Of Distance Values in bcc. addressed by RAU pixel sum, output is inverse value*/
    uint32_t rau_inverse_lut[106];
    /*!< interest_lut[512] 512 deep lookup table for converting thresholds to interest. Data is the 2 bit interest value*/
    uint32_t interest_lut[512];
    /*!< alpha_lut[128] 128 deep Alpha lookup table for RSM. Data is the 5 bit Weighting Factor Alpha value*/
    uint32_t alpha_lut[128];
    /*!< sub_pixel_lut[4096] 4096 entry lookup table for converting left-right score values to a 5-bit sub-pixel value. Data is 5 bits sub pixel value*/
    uint32_t sub_pixel_lut[4096];
    /*!< data_range_lookup[16384] 4 sets of 4096 deep lookup table for converting disparity to range data. Data is the 16 bit range value*/
    uint32_t data_range_lookup[16384];

} ia_pal_isp_sdp_scp_t;

/*! \isp struct see

*/
typedef struct
{
    /*!< Alpha_LUT[64] edge enhance gain*/
    int32_t Alpha_LUT[64];
    /*!< Edge_Max max edge value for clamping*/
    int32_t Edge_Max;
    /*!< Edge_Thres threshold for coring*/
    int32_t Edge_Thres;

} ia_pal_isp_see_t;

/*! \isp struct see2

*/
typedef struct
{
    /*!< Alpha_LUT[64] edge enhance gain*/
    int32_t Alpha_LUT[64];
    /*!< Edge_Max max edge value for clamping*/
    int32_t Edge_Max;
    /*!< Edge_Thres threshold for coring*/
    int32_t Edge_Thres;

} ia_pal_isp_see2_t;

/*! \isp struct sharpening_1_0

*/
typedef struct
{
    /*!< enable Enable sharpening*/
    int32_t enable;

} ia_pal_isp_sharpening_1_0_t;

/*! \isp struct sie_vcsc1_1

*/
typedef struct
{
    /*!< csc_enable csc_bypass*/
    int32_t csc_enable;
    /*!< csc_matrix[9] conversion matrix for RGB2YUV*/
    int32_t csc_matrix[9];
    /*!< csc_matrix_norm normalization factor for RGB2YUV*/
    int32_t csc_matrix_norm;
    /*!< csc_bias_vec[3] conversion bias for RGB2YUV*/
    int32_t csc_bias_vec[3];
    /*!< cds_coeff_array[8] conversion kernel from 444->420*/
    int32_t cds_coeff_array[8];
    /*!< cds_coeff_array_norm normalization factor for 444->420 kernel*/
    int32_t cds_coeff_array_norm;

} ia_pal_isp_sie_vcsc1_1_t;

/*! \isp struct sis_1

*/
typedef struct
{
    /*!< enable 0- disable filter. 1- enable filter.*/
    int32_t enable;
    /*!< DSF Down Scale Factor: 0- scale factor 2. 1- scale factor 4. 2- scale factor 8. 3- scale factor 16.*/
    int32_t DSF;

} ia_pal_isp_sis_1_t;

/*! \isp struct sis_1_0_a

*/
typedef struct
{
    /*!< enable 0- disable filter. 1- enable filter.*/
    int32_t enable;
    /*!< DSF Down Scale Factor: 0- scale factor 2. 1- scale factor 4. 2- scale factor 8. 3- scale factor 16.*/
    int32_t DSF;

} ia_pal_isp_sis_1_0_a_t;

/*! \isp struct sis_1_0_b

*/
typedef struct
{
    /*!< enable 0- disable filter. 1- enable filter.*/
    int32_t enable;
    /*!< DSF Down Scale Factor: 0- scale factor 2. 1- scale factor 4. 2- scale factor 8. 3- scale factor 16.*/
    int32_t DSF;

} ia_pal_isp_sis_1_0_b_t;

/*! \isp struct spa_sis_a

*/
typedef struct
{
    /*!< m_pixinprec HW Parameter  - Input Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixinprec;
    /*!< m_pixoutprec HW Parameter  - Output Pixel precision (with sign) : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixoutprec;
    /*!< m_pixminprec HW Parameter - Minimum possible pixel precision for the input/output Pixel : FIXME needs to be removed as this is a HW Parameter*/
    int32_t m_pixminprec;
    /*!< m_isbayer Is Bayer? - RGB(0) Bayer(1)*/
    int32_t m_isbayer;
    /*!< m_cliptous 0 - Do not clip, 1 - Clip to unsigned*/
    int32_t m_cliptous;
    /*!< m_shiftlen 0 - Perform ShiftR Round, 1 - Perfom ShiftL*/
    int32_t m_shiftlen;
    /*!< m_shiftval Shift Value {0..7}*/
    int32_t m_shiftval;

} ia_pal_isp_spa_sis_a_t;

/*! \isp struct stream2mmio
Stream2mmio
*/
typedef struct
{
    /*!< m_bypass bypass*/
    int32_t m_bypass;
    /*!< m_TopCrop Top crop; the row cropping is enabled when this value is odd*/
    int32_t m_TopCrop;

} ia_pal_isp_stream2mmio_t;

/*! \isp struct stream2mmio_b
Stream2mmio
*/
typedef struct
{
    /*!< m_bypass bypass*/
    int32_t m_bypass;
    /*!< m_TopCrop Top crop; the row cropping is enabled when this value is odd*/
    int32_t m_TopCrop;

} ia_pal_isp_stream2mmio_b_t;

/*! \isp struct stream2mmio_c
Stream2mmio
*/
typedef struct
{
    /*!< m_bypass bypass*/
    int32_t m_bypass;
    /*!< m_TopCrop Top crop; the row cropping is enabled when this value is odd*/
    int32_t m_TopCrop;

} ia_pal_isp_stream2mmio_c_t;

/*! \isp struct strm_crop_psa

*/
typedef struct
{
    /*!< enable Enable PSA Crop*/
    int32_t enable;
    /*!< crop_col_start Start column of image data (columns before will be cropped)*/
    int32_t crop_col_start;
    /*!< crop_row_start Start row of image data (rows before will be cropped)*/
    int32_t crop_row_start;
    /*!< crop_col_end End column of image data (excess will be cropped)*/
    int32_t crop_col_end;
    /*!< crop_row_end End line of image data (excess will be cropped)*/
    int32_t crop_row_end;

} ia_pal_isp_strm_crop_psa_t;

/*! \isp struct strm_crop_psa_c

*/
typedef struct
{
    /*!< enable Enable PSA C Crop*/
    int32_t enable;
    /*!< crop_col_start Start column of image data (columns before will be cropped)*/
    int32_t crop_col_start;
    /*!< crop_row_start Start row of image data (rows before will be cropped)*/
    int32_t crop_row_start;
    /*!< crop_col_end End column of image data (excess will be cropped)*/
    int32_t crop_col_end;
    /*!< crop_row_end End line of image data (excess will be cropped)*/
    int32_t crop_row_end;

} ia_pal_isp_strm_crop_psa_c_t;

/*! \isp struct strm_crop_psa_d

*/
typedef struct
{
    /*!< enable Enable PSA D Crop*/
    int32_t enable;
    /*!< crop_col_start Start column of image data (columns before will be cropped)*/
    int32_t crop_col_start;
    /*!< crop_row_start Start row of image data (rows before will be cropped)*/
    int32_t crop_row_start;
    /*!< crop_col_end End column of image data (excess will be cropped)*/
    int32_t crop_col_end;
    /*!< crop_row_end End line of image data (excess will be cropped)*/
    int32_t crop_row_end;

} ia_pal_isp_strm_crop_psa_d_t;

/*! \isp struct strm_crop_psa_e

*/
typedef struct
{
    /*!< enable Enable PSA E Crop*/
    int32_t enable;
    /*!< crop_col_start Start column of image data (columns before will be cropped)*/
    int32_t crop_col_start;
    /*!< crop_row_start Start row of image data (rows before will be cropped)*/
    int32_t crop_row_start;
    /*!< crop_col_end End column of image data (excess will be cropped)*/
    int32_t crop_col_end;
    /*!< crop_row_end End line of image data (excess will be cropped)*/
    int32_t crop_row_end;

} ia_pal_isp_strm_crop_psa_e_t;

/*! \isp struct strm_crop_psa_f

*/
typedef struct
{
    /*!< enable Enable PSA J Crop*/
    int32_t enable;
    /*!< crop_col_start Start column of image data (columns before will be cropped)*/
    int32_t crop_col_start;
    /*!< crop_row_start Start row of image data (rows before will be cropped)*/
    int32_t crop_row_start;
    /*!< crop_col_end End column of image data (excess will be cropped)*/
    int32_t crop_col_end;
    /*!< crop_row_end End line of image data (excess will be cropped)*/
    int32_t crop_row_end;

} ia_pal_isp_strm_crop_psa_f_t;

/*! \isp struct strm_crop_psa_g

*/
typedef struct
{
    /*!< enable Enable PSA G Crop*/
    int32_t enable;
    /*!< crop_col_start Start column of image data (columns before will be cropped)*/
    int32_t crop_col_start;
    /*!< crop_row_start Start row of image data (rows before will be cropped)*/
    int32_t crop_row_start;
    /*!< crop_col_end End column of image data (excess will be cropped)*/
    int32_t crop_col_end;
    /*!< crop_row_end End line of image data (excess will be cropped)*/
    int32_t crop_row_end;

} ia_pal_isp_strm_crop_psa_g_t;

/*! \isp struct strm_crop_psa_h

*/
typedef struct
{
    /*!< enable Enable PSA H Crop*/
    int32_t enable;
    /*!< crop_col_start Start column of image data (columns before will be cropped)*/
    int32_t crop_col_start;
    /*!< crop_row_start Start row of image data (rows before will be cropped)*/
    int32_t crop_row_start;
    /*!< crop_col_end End column of image data (excess will be cropped)*/
    int32_t crop_col_end;
    /*!< crop_row_end End line of image data (excess will be cropped)*/
    int32_t crop_row_end;

} ia_pal_isp_strm_crop_psa_h_t;

/*! \isp struct strm_crop_sis_a

*/
typedef struct
{
    /*!< enable Enable pre SIS crop*/
    int32_t enable;
    /*!< crop_col_start crop_col_start*/
    int32_t crop_col_start;
    /*!< crop_row_start Start row of image data (rows before will be cropped)*/
    int32_t crop_row_start;
    /*!< crop_col_end End column of image data (excess will be cropped)*/
    int32_t crop_col_end;
    /*!< crop_row_end End line of image data (excess will be cropped)*/
    int32_t crop_row_end;

} ia_pal_isp_strm_crop_sis_a_t;

/*! \isp struct strm_crop_sis_b

*/
typedef struct
{
    /*!< enable Enable post SIS Crop*/
    int32_t enable;
    /*!< crop_col_start Start column of image data (columns before will be cropped)*/
    int32_t crop_col_start;
    /*!< crop_row_start Start row of image data (rows before will be cropped)*/
    int32_t crop_row_start;
    /*!< crop_col_end End column of image data (excess will be cropped)*/
    int32_t crop_col_end;
    /*!< crop_row_end End line of image data (excess will be cropped)*/
    int32_t crop_row_end;

} ia_pal_isp_strm_crop_sis_b_t;

/*! \isp struct sve_1_0
SVE
*/
typedef struct
{
    /*!< enable enable*/
    int32_t enable;
    /*!< sve_bayer_pattern_cropped_mask_bit[16] bit mask define pixel type, according to exp length and bayer color*/
    int32_t sve_bayer_pattern_cropped_mask_bit[16];
    /*!< label_long_pixels_mask bit mask for define long pixels in radiance*/
    int32_t label_long_pixels_mask;
    /*!< max_saturation_val U.0.15 define pixel saturation level in radiance*/
    int32_t max_saturation_val;
    /*!< wb_multiplied_etr[16] U.4.14 - WB * ETR*/
    int32_t wb_multiplied_etr[16];
    /*!< max_input_val U.0.20 - max value of input pixel*/
    int32_t max_input_val;
    /*!< wb_etr_post_noise_beta0[16] U.0.30 - noise model alpha_0*WB * ETR*POST_NOISE_GAIN*/
    int32_t wb_etr_post_noise_beta0[16];
    /*!< wb_etr_post_noise_beta1[16] U.0.15 - noise model alpha_1*WB * ETR*POST_NOISE_GAIN*/
    int32_t wb_etr_post_noise_beta1[16];
    /*!< wb_etr_post_noise_beta2[16] U.0.15 - noise model alpha_2*WB * ETR*POST_NOISE_GAIN*/
    int32_t wb_etr_post_noise_beta2[16];
    /*!< wb_etr_post_noise_clip_negative[16] U.0.30 - noise model clip negative values*/
    int32_t wb_etr_post_noise_clip_negative[16];
    /*!< etr_noise_norm_shift[16] U.4.0 - etr normalization*/
    int32_t etr_noise_norm_shift[16];
    /*!< sve_bayer_pattern_cropped_mask[16] enum define pixel type, according to exp length and bayer color*/
    int32_t sve_bayer_pattern_cropped_mask[16];
    /*!< interp_kernels_arr[64] U.6.0 define which pixel to use for interpolation according to pattern, 3lsb X 3msb Y location*/
    int32_t interp_kernels_arr[64];
    /*!< interp_max_weight_th U.1.7 max weight threshold for interpolation*/
    int32_t interp_max_weight_th;
    /*!< interp_bayer_pattern_mask bit mask for define pixels for interpolation*/
    int32_t interp_bayer_pattern_mask;
    /*!< short_blur_kernels_arr[144] U.6.0 define which pixel to use for short blur according to pattern,  val 63 mens pixel not valid for filtering 3lsb X 3msb Y location*/
    int32_t short_blur_kernels_arr[144];
    /*!< short_blur_sow_th U.4.7 sow threshold for pixel blur*/
    int32_t short_blur_sow_th;
    /*!< short_blur_power U.1.7 power for pixel blur*/
    int32_t short_blur_power;
    /*!< content_short_kernels_arr[144] U.6.0 define which short pixel to use for content detector according to pattern,  val 63 mens pixel not valid for filtering 3lsb X 3msb Y location*/
    int32_t content_short_kernels_arr[144];
    /*!< content_long_kernels_arr[144] U.6.0 define which long pixel to use for content detector according to pattern, val 63 mens pixel not valid for filtering 3lsb X 3msb Y location*/
    int32_t content_long_kernels_arr[144];
    /*!< motion_short_g_th U.0.15 threshold for content*/
    int32_t motion_short_g_th;
    /*!< motion_detector_gain U.4.4  motion detector sensitivity for content*/
    int32_t motion_detector_gain;
    /*!< motion_detector_power U.1.7 motion detector power for content*/
    int32_t motion_detector_power;
    /*!< signal_detector_power U.1.7 signal detector power for content*/
    int32_t signal_detector_power;
    /*!< signal_detector_gain S.4.0 signal detector sensitivity for content (4bit include sign )*/
    int32_t signal_detector_gain;
    /*!< enable_wh_interp U.1 allow to ignore the horizontal interpolation in interlace use case*/
    int32_t enable_wh_interp;
    /*!< enable_wv_interp U.1 allow to ignore the vertical interpolation in interlace use case*/
    int32_t enable_wv_interp;
    /*!< cu_blend_x[4] U.20 cu_blend_x*/
    int32_t cu_blend_x[4];
    /*!< cu_blend_y[3] U.11 cu_compression_y*/
    int32_t cu_blend_y[3];
    /*!< cu_blend_slope[3] U.6.10 cu_blend_slope (16 bit )*/
    int32_t cu_blend_slope[3];
    /*!< cu_compression_x[8] U.20 cu_compression_x*/
    int32_t cu_compression_x[8];
    /*!< cu_compression_y[7] U.15 cu_compression_y*/
    int32_t cu_compression_y[7];
    /*!< cu_compression_slope[7] U.1.10 cu_compression_slope (11 bit )*/
    int32_t cu_compression_slope[7];
    /*!< long_burnt_dilut_mode U.2, 0 - pass-through, 1 - directional dilation 2 - traditional dilation*/
    int32_t long_burnt_dilut_mode;
    /*!< max_resolution_quantization_th S.1.20 define max resolution quantization threshold in signal detector (21 bit include sign)*/
    int32_t max_resolution_quantization_th;
    /*!< rad_enable U.1.0 enable radial compensation when LSC before SVE*/
    int32_t rad_enable;
    /*!< rad_x_center U.13.0 rad_x_center*/
    int32_t rad_x_center;
    /*!< rad_y_center U.13.0 rad_y_center*/
    int32_t rad_y_center;
    /*!< rad_norm_shift U.5.0 radial normalization factor according to image resolution*/
    int32_t rad_norm_shift;
    /*!< rad_lut_4_channels[256] U.4.6 - 4 radial luts each lut 64 entries for radial compensation according to LSC tables*/
    int32_t rad_lut_4_channels[256];

} ia_pal_isp_sve_1_0_t;

/*! \isp struct sve_1_1
SVE
*/
typedef struct
{
    /*!< enable enable*/
    int32_t enable;
    /*!< sve_bayer_pattern_cropped_mask_bit[16] bit mask define pixel type, according to exp length and bayer color*/
    int32_t sve_bayer_pattern_cropped_mask_bit[16];
    /*!< label_long_pixels_mask bit mask for define long pixels in radiance*/
    int32_t label_long_pixels_mask;
    /*!< max_saturation_val U.0.15 define pixel saturation level in radiance*/
    int32_t max_saturation_val;
    /*!< wb_multiplied_etr[16] U.4.14 - WB * ETR*/
    int32_t wb_multiplied_etr[16];
    /*!< max_input_val U.0.20 - max value of input pixel*/
    int32_t max_input_val;
    /*!< wb_etr_post_noise_beta0[16] U.0.30 - noise model alpha_0*WB * ETR*POST_NOISE_GAIN*/
    int32_t wb_etr_post_noise_beta0[16];
    /*!< wb_etr_post_noise_beta1[16] U.0.15 - noise model alpha_1*WB * ETR*POST_NOISE_GAIN*/
    int32_t wb_etr_post_noise_beta1[16];
    /*!< wb_etr_post_noise_beta2[16] U.0.15 - noise model alpha_2*WB * ETR*POST_NOISE_GAIN*/
    int32_t wb_etr_post_noise_beta2[16];
    /*!< wb_etr_post_noise_clip_negative[16] U.0.30 - noise model clip negative values*/
    int32_t wb_etr_post_noise_clip_negative[16];
    /*!< etr_noise_norm_shift[16] U.4.0 - etr normalization*/
    int32_t etr_noise_norm_shift[16];
    /*!< sve_bayer_pattern_cropped_mask[16] enum define pixel type, according to exp length and bayer color*/
    int32_t sve_bayer_pattern_cropped_mask[16];
    /*!< interp_kernels_arr[64] U.6.0 define which pixel to use for interpolation according to pattern, 3lsb X 3msb Y location*/
    int32_t interp_kernels_arr[64];
    /*!< interp_max_weight_th U.1.7 max weight threshold for interpolation*/
    int32_t interp_max_weight_th;
    /*!< interp_bayer_pattern_mask bit mask for define pixels for interpolation*/
    int32_t interp_bayer_pattern_mask;
    /*!< short_blur_kernels_arr[144] U.6.0 define which pixel to use for short blur according to pattern,  val 63 mens pixel not valid for filtering 3lsb X 3msb Y location*/
    int32_t short_blur_kernels_arr[144];
    /*!< short_blur_sow_th U.4.7 sow threshold for pixel blur*/
    int32_t short_blur_sow_th;
    /*!< short_blur_power U.1.7 power for pixel blur*/
    int32_t short_blur_power;
    /*!< content_short_kernels_arr[144] U.6.0 define which short pixel to use for content detector according to pattern,  val 63 mens pixel not valid for filtering 3lsb X 3msb Y location*/
    int32_t content_short_kernels_arr[144];
    /*!< content_long_kernels_arr[144] U.6.0 define which long pixel to use for content detector according to pattern, val 63 mens pixel not valid for filtering 3lsb X 3msb Y location*/
    int32_t content_long_kernels_arr[144];
    /*!< motion_short_g_th U.0.15 threshold for content*/
    int32_t motion_short_g_th;
    /*!< motion_detector_gain U.4.4  motion detector sensitivity for content*/
    int32_t motion_detector_gain;
    /*!< motion_detector_power U.1.7 motion detector power for content*/
    int32_t motion_detector_power;
    /*!< signal_detector_power U.1.7 signal detector power for content*/
    int32_t signal_detector_power;
    /*!< signal_detector_gain S.4.0 signal detector sensitivity for content (4bit include sign )*/
    int32_t signal_detector_gain;
    /*!< enable_wh_interp U.1 allow to ignore the horizontal interpolation in interlace use case*/
    int32_t enable_wh_interp;
    /*!< enable_wv_interp U.1 allow to ignore the vertical interpolation in interlace use case*/
    int32_t enable_wv_interp;
    /*!< cu_blend_x[4] U.20 cu_blend_x*/
    int32_t cu_blend_x[4];
    /*!< cu_blend_y[3] U.11 cu_compression_y*/
    int32_t cu_blend_y[3];
    /*!< cu_blend_slope[3] U.6.10 cu_blend_slope (16 bit )*/
    int32_t cu_blend_slope[3];
    /*!< cu_compression_x[8] U.20 cu_compression_x*/
    int32_t cu_compression_x[8];
    /*!< cu_compression_y[7] U.15 cu_compression_y*/
    int32_t cu_compression_y[7];
    /*!< cu_compression_slope[7] U.1.10 cu_compression_slope (11 bit )*/
    int32_t cu_compression_slope[7];
    /*!< long_burnt_dilut_mode U.2, 0 - pass-through, 1 - directional dilation 2 - traditional dilation*/
    int32_t long_burnt_dilut_mode;
    /*!< max_resolution_quantization_th S.1.20 define max resolution quantization threshold in signal detector (21 bit include sign)*/
    int32_t max_resolution_quantization_th;
    /*!< rad_enable U.1.0 enable radial compensation when LSC before SVE*/
    int32_t rad_enable;
    /*!< rad_x_center U.13.0 rad_x_center*/
    int32_t rad_x_center;
    /*!< rad_y_center U.13.0 rad_y_center*/
    int32_t rad_y_center;
    /*!< rad_norm_shift U.5.0 radial normalization factor according to image resolution*/
    int32_t rad_norm_shift;
    /*!< rad_lut_4_channels[256] U.4.6 - 4 radial luts each lut 64 entries for radial compensation according to LSC tables*/
    int32_t rad_lut_4_channels[256];
    /*!< enable_four_cell U.1 Allows the block to work in 4Cell mode*/
    int32_t enable_four_cell;
    /*!< four_cell_pattern[16] 4Cell pattern of CFA and exposures, 0-3 - RGGB short, 4-7 - RGGB long*/
    int32_t four_cell_pattern[16];

} ia_pal_isp_sve_1_1_t;

/*! \isp struct tm_app

*/
typedef struct
{
    /*!< Bypass bypass for the filter*/
    int32_t Bypass;
    /*!< tm_lut[2049] generalized lut for tone mapping lut*/
    int32_t tm_lut[2049];
    /*!< gtm4_a polynomial chromaticity model degree*/
    int32_t gtm4_a;
    /*!< gtm4_b color saturation in highlights*/
    int32_t gtm4_b;
    /*!< gtm4_c overall color desaturation*/
    int32_t gtm4_c;
    /*!< gammaType type of Gamma used to get to RGB and back (currently out of use)*/
    int32_t gammaType;
    /*!< gtm4_offset_yuv2rgb[3] yuv2rgb offset*/
    int32_t gtm4_offset_yuv2rgb[3];
    /*!< gtm4_yuv2rgb[9] yuv2rgb calibration*/
    int32_t gtm4_yuv2rgb[9];
    /*!< gtm4_offset_rgb2yuv[3] rgb2yuv offset*/
    int32_t gtm4_offset_rgb2yuv[3];
    /*!< gtm4_rgb2yuv[9] rgb2yuv calibration*/
    int32_t gtm4_rgb2yuv[9];
    /*!< Bit_Precision input bit precision*/
    int32_t Bit_Precision;
    /*!< compression_gamma compression curve gamma*/
    int32_t compression_gamma;
    /*!< input_range_restricted input range is restricted flag*/
    int32_t input_range_restricted;
    /*!< output_range_restricted output range is restricted flag*/
    int32_t output_range_restricted;

} ia_pal_isp_tm_app_t;

/*! \isp struct tnr_6_0
Hardware fixed-function temporal noise reduction
*/
typedef struct
{
    /*!< bypass bypass*/
    int32_t bypass;
    /*!< feedback_image_bittage bit reduction in feedback loop*/
    int32_t feedback_image_bittage;
    /*!< spatial_luma_kernel[25] Spatial filtering spatial kernel (Luma, 5x5)*/
    int32_t spatial_luma_kernel[25];
    /*!< spatial_chroma_kernel[9] Spatial filtering spatial kernel (Chroma, 3x3)*/
    int32_t spatial_chroma_kernel[9];
    /*!< spatial_luma_denoise_control Control weight deviation in Luma spatial denoising*/
    int32_t spatial_luma_denoise_control;
    /*!< spatial_chroma_denoise_luma_control Control weight deviation in Chroma spatial denoising*/
    int32_t spatial_chroma_denoise_luma_control;
    /*!< spatial_chroma_denoise_chroma_control Control weight deviation in Chroma spatial denoising*/
    int32_t spatial_chroma_denoise_chroma_control;
    /*!< blending_inlier_th_motion blending:*/
    int32_t blending_inlier_th_motion;
    /*!< blending_inlier_th_static blending:*/
    int32_t blending_inlier_th_static;
    /*!< blending_inlier_gain blending:*/
    int32_t blending_inlier_gain;
    /*!< blending_da_rec_sim_motion_knees[2] blending:*/
    int32_t blending_da_rec_sim_motion_knees[2];
    /*!< blending_da_rec_sim_motion_a[2] blending:*/
    int32_t blending_da_rec_sim_motion_a[2];
    /*!< blending_da_rec_sim_motion_b[2] blending:*/
    int32_t blending_da_rec_sim_motion_b[2];
    /*!< blending_da_rec_sim_static_knees[2] blending:*/
    int32_t blending_da_rec_sim_static_knees[2];
    /*!< blending_da_rec_sim_static_a[2] blending:*/
    int32_t blending_da_rec_sim_static_a[2];
    /*!< blending_da_rec_sim_static_b[2] blending:*/
    int32_t blending_da_rec_sim_static_b[2];
    /*!< blending_da_winp_knees[2] blending:*/
    int32_t blending_da_winp_knees[2];
    /*!< blending_da_winp_a[2] blending:*/
    int32_t blending_da_winp_a[2];
    /*!< blending_da_winp_b[2] blending:*/
    int32_t blending_da_winp_b[2];
    /*!< sharpening_rec_sim_damp sharpening: rec-sim based damping*/
    int32_t sharpening_rec_sim_damp;
    /*!< sharpening_texture_coeff_norm sharpening: texture metric normalization power*/
    int32_t sharpening_texture_coeff_norm;
    /*!< sharpening_texture_undershoot sharpening: allowed undershoot for textured pixels*/
    int32_t sharpening_texture_undershoot;
    /*!< sharpening_edge_undershoot sharpening: allowed undershoot for edge pixels*/
    int32_t sharpening_edge_undershoot;
    /*!< sharpening_texture_overshoot sharpening: allowed overshoot for textured pixels*/
    int32_t sharpening_texture_overshoot;
    /*!< sharpening_edge_overshoot sharpening: allowed overshoot for edge pixels*/
    int32_t sharpening_edge_overshoot;
    /*!< sharpening_undershoot_power sharpening: undershoot enhancement. To enhance use positive, to weaken use a negative.*/
    int32_t sharpening_undershoot_power;
    /*!< sharpening_overshoot_power sharpening: overshoot enhancement. To enhance use positive, to weaken use a negative.*/
    int32_t sharpening_overshoot_power;
    /*!< sharpening_cu_x_points_pos_th[6] sharpening: x points for overshoot config unit*/
    int32_t sharpening_cu_x_points_pos_th[6];
    /*!< sharpening_cu_a_points_pos_th[5] sharpening: a points for overshoot config unit*/
    int32_t sharpening_cu_a_points_pos_th[5];
    /*!< sharpening_cu_b_points_pos_th[5] sharpening: b points for overshoot config unit*/
    int32_t sharpening_cu_b_points_pos_th[5];
    /*!< sharpening_cu_x_points_neg_th[6] sharpening: x points for undershoot config unit*/
    int32_t sharpening_cu_x_points_neg_th[6];
    /*!< sharpening_cu_a_points_neg_th[5] sharpening: a points for undershoot config unit*/
    int32_t sharpening_cu_a_points_neg_th[5];
    /*!< sharpening_cu_b_points_neg_th[5] sharpening: b points for undershoot config unit*/
    int32_t sharpening_cu_b_points_neg_th[5];
    /*!< sharpening_cu_x_points_pixval_th[6] sharpening: x points for pixel value config unit*/
    int32_t sharpening_cu_x_points_pixval_th[6];
    /*!< sharpening_cu_a_points_pixval_th[5] sharpening: a points for pixel value config unit*/
    int32_t sharpening_cu_a_points_pixval_th[5];
    /*!< sharpening_cu_b_points_pixval_th[5] sharpening: b points for pixel value config unit*/
    int32_t sharpening_cu_b_points_pixval_th[5];
    /*!< sharpening_cu_x_points_noise_th[6] sharpening: x points for noise th config unit*/
    int32_t sharpening_cu_x_points_noise_th[6];
    /*!< sharpening_cu_a_points_noise_th[5] sharpening: a  points for noise th config unit*/
    int32_t sharpening_cu_a_points_noise_th[5];
    /*!< sharpening_cu_b_points_noise_th[5] sharpening: b  points for noise th config unit*/
    int32_t sharpening_cu_b_points_noise_th[5];
    /*!< sharpening_kernel_coeffs[6] sharpening: kernel coefficients*/
    int32_t sharpening_kernel_coeffs[6];
    /*!< op_fragment_width fragmentation*/
    int32_t op_fragment_width;
    /*!< op_fragment_height fragmentation*/
    int32_t op_fragment_height;
    /*!< start_block_id_X fragmentation*/
    int32_t start_block_id_X;
    /*!< start_block_id_Y fragmentation*/
    int32_t start_block_id_Y;
    /*!< frame_width fragmentation*/
    int32_t frame_width;
    /*!< frame_height fragmentation*/
    int32_t frame_height;
    /*!< tnr_top_i_tnr6_reg_tnr6_bpp_control_Info_type bit reduction in feedback loop*/
    int32_t tnr_top_i_tnr6_reg_tnr6_bpp_control_Info_type;
    /*!< output_bpp bit reduction in feedback loop*/
    int32_t output_bpp;

} ia_pal_isp_tnr_6_0_t;

/*! \isp struct tnr_scale_1_0

*/
typedef struct
{
    /*!< enable enable TNR_SCALE_1_0 filter*/
    int32_t enable;
    /*!< inWidth Number of pixels per row at output*/
    int32_t inWidth;
    /*!< inHeight Number of rows at output*/
    int32_t inHeight;
    /*!< bitReductionBypass bypass of bit reduction of input pixels*/
    int32_t bitReductionBypass;
    /*!< inputShift shift on input pixels*/
    int32_t inputShift;
    /*!< cu_bit_reduce_x[6] input bit reduction config unit - x values*/
    int32_t cu_bit_reduce_x[6];
    /*!< cu_bit_reduce_y[5] input bit reduction config unit - y values*/
    int32_t cu_bit_reduce_y[5];
    /*!< cu_bit_reduce_slope[5] input bit reduction config unit - slope values*/
    int32_t cu_bit_reduce_slope[5];

} ia_pal_isp_tnr_scale_1_0_t;

/*! \isp struct tnr5_21

*/
typedef struct
{
    /*!< NM_Rad2_Shift Bit shift bumber to calculate index for nm_R_xcu*/
    int32_t NM_Rad2_Shift;
    /*!< nm_radial_y_center Opical center y coordinate in chroma resolution*/
    int32_t nm_radial_y_center;
    /*!< nm_radial_x_center Opical center x coordinate in chroma resolution*/
    int32_t nm_radial_x_center;
    /*!< nm_R_xcu[128] LUT for radial noise model*/
    int32_t nm_R_xcu[128];
    /*!< nm_YY_xcu[64] LUT for Y noise model – Y dependency*/
    int32_t nm_YY_xcu[64];
    /*!< nm_YC_xcu[64] LUT for Y noise model – C dependency*/
    int32_t nm_YC_xcu[64];
    /*!< nm_CY_xcu[64] LUT for C noise model – Y dependency*/
    int32_t nm_CY_xcu[64];
    /*!< nm_CC_xcu[64] LUT for C noise model – C dependency*/
    int32_t nm_CC_xcu[64];
    /*!< nm_Y_log_est_min Min value for log space Y noise model*/
    int32_t nm_Y_log_est_min;
    /*!< nm_Y_log_est_max Max value for log space Y noise model*/
    int32_t nm_Y_log_est_max;
    /*!< nm_C_log_est_min Min value for log space C noise model*/
    int32_t nm_C_log_est_min;
    /*!< nm_C_log_est_max Max value for log space C noise model*/
    int32_t nm_C_log_est_max;
    /*!< nm_lut_frac Fractional bit for noise model LUT*/
    int32_t nm_lut_frac;
    /*!< nm_idx_frac Bit number for adjusting to POW LUT index*/
    int32_t nm_idx_frac;
    /*!< nm_pow[64] LUT for power function*/
    int32_t nm_pow[64];
    /*!< nm_pow_frac Fractional bit for POW LUT*/
    int32_t nm_pow_frac;
    /*!< nm_shift_num Pre-calculation of nm_lut_frac - nm_idx_frac*/
    int32_t nm_shift_num;
    /*!< nm_Y_alpha Scaling coefficient for Y noise model*/
    int32_t nm_Y_alpha;
    /*!< nm_C_alpha Scaling coefficient for C noise model*/
    int32_t nm_C_alpha;
    /*!< co_var_thres Variance threshold*/
    int32_t co_var_thres;
    /*!< co_var_gain Variance gain*/
    int32_t co_var_gain;
    /*!< tbd_sad_Y_gain Y SAD sensitivity gain*/
    int32_t tbd_sad_Y_gain;
    /*!< tbd_sim_arg_gain_m Similarity argument gain for dynamic*/
    int32_t tbd_sim_arg_gain_m;
    /*!< tbd_con_thres Content level threshold*/
    int32_t tbd_con_thres;
    /*!< tbd_con_gain Content level gain*/
    int32_t tbd_con_gain;
    /*!< tbd_sim_lut[64] Similarity LUT*/
    int32_t tbd_sim_lut[64];
    /*!< tbd_rec_sim_thres Similarity threshold for recursive filter*/
    int32_t tbd_rec_sim_thres;
    /*!< tbd_rec_gain0 Gain of recursive filter for static region*/
    int32_t tbd_rec_gain0;
    /*!< tbd_rec_gain1 Gain of recursive filter for dynamic region*/
    int32_t tbd_rec_gain1;
    /*!< pb_weight_in input weight*/
    int32_t pb_weight_in;
    /*!< pb_weight_pre_max max weight of temporal filter output*/
    int32_t pb_weight_pre_max;
    /*!< pb_weight_sp_thres Spatial filter weight threshold*/
    int32_t pb_weight_sp_thres;
    /*!< pb_weight_sp_gain Spatial filter weight gain*/
    int32_t pb_weight_sp_gain;
    /*!< pb_weight_sp_max0 Spatial filter weight max at high similarity region*/
    int32_t pb_weight_sp_max0;
    /*!< pb_weight_sp_max1 Spatial filter weight max at low similarity region*/
    int32_t pb_weight_sp_max1;
    /*!< NS_weight_LUT[64] LUT for Noise stream weight control by similarity*/
    int32_t NS_weight_LUT[64];
    /*!< NS_ConLv_w_LUT[64] LUT for Noise stream weight control by content*/
    int32_t NS_ConLv_w_LUT[64];
    /*!< NS_out_max Max value for clipping noise stream*/
    int32_t NS_out_max;
    /*!< NS_Norm_bias Bias for noise stream luma dependency model*/
    int32_t NS_Norm_bias;
    /*!< NS_Norm_coef Slope for noise stream luma dependency model*/
    int32_t NS_Norm_coef;
    /*!< bypass bypass*/
    int32_t bypass;
    /*!< framenumber frame number*/
    int32_t framenumber;
    /*!< g_mv_x global  MV_X*/
    int32_t g_mv_x;
    /*!< g_mv_y global  MV_Y*/
    int32_t g_mv_y;
    /*!< bypass_NS bypass noise stream*/
    int32_t bypass_NS;

} ia_pal_isp_tnr5_21_t;

/*! \isp struct tnr5_22

*/
typedef struct
{
    /*!< NM_Rad2_Shift Bit shift bumber to calculate index for nm_R_xcu*/
    int32_t NM_Rad2_Shift;
    /*!< nm_radial_y_center Opical center y coordinate in chroma resolution*/
    int32_t nm_radial_y_center;
    /*!< nm_radial_x_center Opical center x coordinate in chroma resolution*/
    int32_t nm_radial_x_center;
    /*!< nm_R_xcu[128] LUT for radial noise model*/
    int32_t nm_R_xcu[128];
    /*!< nm_YY_xcu[64] LUT for Y noise model – Y dependency*/
    int32_t nm_YY_xcu[64];
    /*!< nm_YC_xcu[64] LUT for Y noise model – C dependency*/
    int32_t nm_YC_xcu[64];
    /*!< nm_CY_xcu[64] LUT for C noise model – Y dependency*/
    int32_t nm_CY_xcu[64];
    /*!< nm_CC_xcu[64] LUT for C noise model – C dependency*/
    int32_t nm_CC_xcu[64];
    /*!< nm_Y_log_est_min Min value for log space Y noise model*/
    int32_t nm_Y_log_est_min;
    /*!< nm_Y_log_est_max Max value for log space Y noise model*/
    int32_t nm_Y_log_est_max;
    /*!< nm_C_log_est_min Min value for log space C noise model*/
    int32_t nm_C_log_est_min;
    /*!< nm_C_log_est_max Max value for log space C noise model*/
    int32_t nm_C_log_est_max;
    /*!< nm_lut_frac Fractional bit for noise model LUT*/
    int32_t nm_lut_frac;
    /*!< nm_idx_frac Bit number for adjusting to POW LUT index*/
    int32_t nm_idx_frac;
    /*!< nm_pow_Y[64] LUT for power function for Y*/
    int32_t nm_pow_Y[64];
    /*!< nm_pow_C[64] LUT for power function for C*/
    int32_t nm_pow_C[64];
    /*!< nm_pow_frac Fractional bit for POW LUT*/
    int32_t nm_pow_frac;
    /*!< nm_shift_num Pre-calculation of nm_lut_frac - nm_idx_frac*/
    int32_t nm_shift_num;
    /*!< co_var_thres Variance threshold*/
    int32_t co_var_thres;
    /*!< co_var_gain Variance gain*/
    int32_t co_var_gain;
    /*!< tbd_sad_Y_gain Y SAD sensitivity gain*/
    int32_t tbd_sad_Y_gain;
    /*!< tbd_sim_arg_gain_m Similarity argument gain for dynamic*/
    int32_t tbd_sim_arg_gain_m;
    /*!< tbd_con_thres Content level threshold*/
    int32_t tbd_con_thres;
    /*!< tbd_con_gain Content level gain*/
    int32_t tbd_con_gain;
    /*!< tbd_sim_lut[64] Similarity LUT*/
    int32_t tbd_sim_lut[64];
    /*!< tbd_rec_sim_thres Similarity threshold for recursive filter*/
    int32_t tbd_rec_sim_thres;
    /*!< tbd_rec_gain0 Gain of recursive filter for static region*/
    int32_t tbd_rec_gain0;
    /*!< tbd_rec_gain1 Gain of recursive filter for dynamic region*/
    int32_t tbd_rec_gain1;
    /*!< pb_weight_in input weight*/
    int32_t pb_weight_in;
    /*!< pb_weight_pre_max max weight of temporal filter output*/
    int32_t pb_weight_pre_max;
    /*!< pb_weight_sp_thres Spatial filter weight threshold*/
    int32_t pb_weight_sp_thres;
    /*!< pb_weight_sp_gain Spatial filter weight gain*/
    int32_t pb_weight_sp_gain;
    /*!< pb_weight_sp_max0 Spatial filter weight max at high similarity region*/
    int32_t pb_weight_sp_max0;
    /*!< pb_weight_sp_max1 Spatial filter weight max at low similarity region*/
    int32_t pb_weight_sp_max1;
    /*!< NS_weight_LUT[64] LUT for Noise stream weight control by similarity*/
    int32_t NS_weight_LUT[64];
    /*!< NS_ConLv_w_LUT[64] LUT for Noise stream weight control by content*/
    int32_t NS_ConLv_w_LUT[64];
    /*!< NS_out_max Max value for clipping noise stream*/
    int32_t NS_out_max;
    /*!< NS_Norm_bias Bias for noise stream luma dependency model*/
    int32_t NS_Norm_bias;
    /*!< NS_Norm_coef Slope for noise stream luma dependency model*/
    int32_t NS_Norm_coef;
    /*!< bypass bypass*/
    int32_t bypass;
    /*!< framenumber frame number*/
    int32_t framenumber;
    /*!< g_mv_x global  MV_X*/
    int32_t g_mv_x;
    /*!< g_mv_y global  MV_Y*/
    int32_t g_mv_y;
    /*!< bypass_NS bypass noise stream*/
    int32_t bypass_NS;

} ia_pal_isp_tnr5_22_t;

/*! \isp struct tnr5_25

*/
typedef struct
{
    /*!< NM_Rad2_Shift Bit shift bumber to calculate index for nm_R_xcu*/
    int32_t NM_Rad2_Shift;
    /*!< nm_radial_y_center Opical center y coordinate in chroma resolution*/
    int32_t nm_radial_y_center;
    /*!< nm_radial_x_center Opical center x coordinate in chroma resolution*/
    int32_t nm_radial_x_center;
    /*!< nm_R_xcu[128] LUT for radial noise model*/
    int32_t nm_R_xcu[128];
    /*!< nm_YY_xcu[64] LUT for Y noise model – Y dependency*/
    int32_t nm_YY_xcu[64];
    /*!< nm_YC_xcu[64] LUT for Y noise model – C dependency*/
    int32_t nm_YC_xcu[64];
    /*!< nm_CY_xcu[64] LUT for C noise model – Y dependency*/
    int32_t nm_CY_xcu[64];
    /*!< nm_CC_xcu[64] LUT for C noise model – C dependency*/
    int32_t nm_CC_xcu[64];
    /*!< nm_Y_log_est_min Min value for log space Y noise model*/
    int32_t nm_Y_log_est_min;
    /*!< nm_Y_log_est_max Max value for log space Y noise model*/
    int32_t nm_Y_log_est_max;
    /*!< nm_C_log_est_min Min value for log space C noise model*/
    int32_t nm_C_log_est_min;
    /*!< nm_C_log_est_max Max value for log space C noise model*/
    int32_t nm_C_log_est_max;
    /*!< nm_lut_frac Fractional bit for noise model LUT*/
    int32_t nm_lut_frac;
    /*!< nm_idx_frac Bit number for adjusting to POW LUT index*/
    int32_t nm_idx_frac;
    /*!< nm_pow[64] LUT for power function*/
    int32_t nm_pow[64];
    /*!< nm_pow_frac Fractional bit for POW LUT*/
    int32_t nm_pow_frac;
    /*!< nm_shift_num Pre-calculation of nm_lut_frac - nm_idx_frac*/
    int32_t nm_shift_num;
    /*!< nm_Y_alpha Scaling coefficient for Y noise model*/
    int32_t nm_Y_alpha;
    /*!< nm_C_alpha Scaling coefficient for C noise model*/
    int32_t nm_C_alpha;
    /*!< tbd_sad_Y_gain Y SAD sensitivity gain*/
    int32_t tbd_sad_Y_gain;
    /*!< tbd_sim_arg_gain_m Similarity argument gain for dynamic*/
    int32_t tbd_sim_arg_gain_m;
    /*!< tbd_sim_lut[64] Similarity LUT*/
    int32_t tbd_sim_lut[64];
    /*!< tbd_rec_sim_thres Similarity threshold for recursive filter*/
    int32_t tbd_rec_sim_thres;
    /*!< tbd_rec_gain0 Gain of recursive filter for static region*/
    int32_t tbd_rec_gain0;
    /*!< tbd_rec_gain1 Gain of recursive filter for dynamic region*/
    int32_t tbd_rec_gain1;
    /*!< pb_weight_in input weight*/
    int32_t pb_weight_in;
    /*!< pb_weight_pre_max max weight of temporal filter output*/
    int32_t pb_weight_pre_max;
    /*!< bypass bypass*/
    int32_t bypass;
    /*!< framenumber frame number*/
    int32_t framenumber;
    /*!< g_mv_x global  MV_X*/
    int32_t g_mv_x;
    /*!< g_mv_y global  MV_Y*/
    int32_t g_mv_y;

} ia_pal_isp_tnr5_25_t;

/*! \isp struct tnr5_3

*/
typedef struct
{
    /*!< nm_luma_lut[256] Noise model LUMA lut (for I core)*/
    int32_t nm_luma_lut[256];
    /*!< nm_chroma_lut[256] Noise model Chroma LUT (for I core)*/
    int32_t nm_chroma_lut[256];
    /*!< nm_radial_lut[128] Noise model radial Lut*/
    int32_t nm_radial_lut[128];
    /*!< nm_radial_r2_shift Noise model radial shift*/
    int32_t nm_radial_r2_shift;
    /*!< nm_radial_x_center Noise model radial- center of image x corr*/
    int32_t nm_radial_x_center;
    /*!< nm_radial_y_center Noise model radial- center of image y corr*/
    int32_t nm_radial_y_center;
    /*!< co_max_content maximal value for the content*/
    int32_t co_max_content;
    /*!< co_content_shift shift right for content*/
    int32_t co_content_shift;
    /*!< fm_bma_sad_shift shift value for the BMA*/
    int32_t fm_bma_sad_shift;
    /*!< fm_chroma_shift shift value for chroma in fmve*/
    int32_t fm_chroma_shift;
    /*!< fm_sim_lut[256] FMVE Similarity LUT for grade calculation*/
    int32_t fm_sim_lut[256];
    /*!< fm_dist_weights[128] FMVE distance weight for the tow BMA unit*/
    int32_t fm_dist_weights[128];
    /*!< mvd_sim_lut[256] MVD Similarity LUT*/
    int32_t mvd_sim_lut[256];
    /*!< mvd_sad_shift shift for the SAD values in the MVD sub-block (using realigning)*/
    int32_t mvd_sad_shift;
    /*!< mvd_arg_g_static The gain for the recursive similarity at case of static MV . together  with neighbors*/
    int32_t mvd_arg_g_static;
    /*!< mvd_arg_g_static_local The gain for the recursive similarity at case of static MV, neighbors have a different MV*/
    int32_t mvd_arg_g_static_local;
    /*!< mvd_arg_g_move The gain for the recursive similarity at case of non-static MV,  together  with neighbors*/
    int32_t mvd_arg_g_move;
    /*!< mvd_arg_g_move_local The gain for the recursive similarity at case of non-static MV,neighbors have a different MV*/
    int32_t mvd_arg_g_move_local;
    /*!< mvd_chroma_l_shift shift value for chroma in mvd*/
    int32_t mvd_chroma_l_shift;
    /*!< mvd_central_pix_l_shift shift value for centeral pixel in mvd*/
    int32_t mvd_central_pix_l_shift;
    /*!< spnr_range_lut[7] range lut for the BFA*/
    int32_t spnr_range_lut[7];
    /*!< spnr_spatial_lut[25] spatial lut for the BFA*/
    int32_t spnr_spatial_lut[25];
    /*!< spnr_shift shift value for the BFA*/
    int32_t spnr_shift;
    /*!< spnr_nm_shift shift value for the noise model of SPNR*/
    int32_t spnr_nm_shift;
    /*!< pb_weight_pre_max maximal spTNR weight*/
    int32_t pb_weight_pre_max;
    /*!< pb_weight_spnr_max maximal spNR weight (vs. input)*/
    int32_t pb_weight_spnr_max;
    /*!< g_mv_x global  MV_X. Should be in PAL*/
    int32_t g_mv_x;
    /*!< g_mv_y global  MV_Y. Should be in PAL*/
    int32_t g_mv_y;

} ia_pal_isp_tnr5_3_t;

/*! \isp struct tnr5_3_1

*/
typedef struct
{
    /*!< nm_luma_lut[256] Noise model LUMA lut (for I core)*/
    int32_t nm_luma_lut[256];
    /*!< nm_chroma_lut[256] Noise model Chroma LUT (for I core)*/
    int32_t nm_chroma_lut[256];
    /*!< nm_radial_lut[128] Noise model radial Lut*/
    int32_t nm_radial_lut[128];
    /*!< nm_radial_r2_shift Noise model radial shift*/
    int32_t nm_radial_r2_shift;
    /*!< nm_radial_x_center Noise model radial- center of image x corr*/
    int32_t nm_radial_x_center;
    /*!< nm_radial_y_center Noise model radial- center of image y corr*/
    int32_t nm_radial_y_center;
    /*!< co_max_content maximal value for the content*/
    int32_t co_max_content;
    /*!< co_content_shift shift right for content*/
    int32_t co_content_shift;
    /*!< fm_bma_sad_shift shift value for the BMA*/
    int32_t fm_bma_sad_shift;
    /*!< fm_chroma_shift shift value for chroma in fmve*/
    int32_t fm_chroma_shift;
    /*!< fm_sim_lut[256] FMVE Similarity LUT for grade calculation*/
    int32_t fm_sim_lut[256];
    /*!< fm_dist_weights[128] FMVE distance weight for the tow BMA unit*/
    int32_t fm_dist_weights[128];
    /*!< mvd_sim_lut[256] MVD Similarity LUT*/
    int32_t mvd_sim_lut[256];
    /*!< mvd_sad_shift shift for the SAD values in the MVD sub-block (using realigning)*/
    int32_t mvd_sad_shift;
    /*!< mvd_arg_g_static The gain for the recursive similarity at case of static MV . together  with neighbors*/
    int32_t mvd_arg_g_static;
    /*!< mvd_arg_g_static_local The gain for the recursive similarity at case of static MV, neighbors have a different MV*/
    int32_t mvd_arg_g_static_local;
    /*!< mvd_arg_g_move The gain for the recursive similarity at case of non-static MV,  together  with neighbors*/
    int32_t mvd_arg_g_move;
    /*!< mvd_arg_g_move_local The gain for the recursive similarity at case of non-static MV,neighbors have a different MV*/
    int32_t mvd_arg_g_move_local;
    /*!< mvd_chroma_l_shift shift value for chroma in mvd*/
    int32_t mvd_chroma_l_shift;
    /*!< mvd_central_pix_l_shift shift value for centeral pixel in mvd*/
    int32_t mvd_central_pix_l_shift;
    /*!< spnr_range_lut[7] range lut for the BFA*/
    int32_t spnr_range_lut[7];
    /*!< spnr_spatial_lut[25] spatial lut for the BFA*/
    int32_t spnr_spatial_lut[25];
    /*!< spnr_shift shift value for the BFA*/
    int32_t spnr_shift;
    /*!< spnr_nm_shift shift value for the noise model of SPNR*/
    int32_t spnr_nm_shift;
    /*!< pb_weight_pre_max maximal spTNR weight*/
    int32_t pb_weight_pre_max;
    /*!< pb_weight_spnr_max maximal spNR weight (vs. input)*/
    int32_t pb_weight_spnr_max;
    /*!< g_mv_x global  MV_X. Should be in PAL*/
    int32_t g_mv_x;
    /*!< g_mv_y global  MV_Y. Should be in PAL*/
    int32_t g_mv_y;

} ia_pal_isp_tnr5_3_1_t;

/*! \isp struct tnr7_bc_1_0

*/
typedef struct
{
    /*!< enable block enable*/
    int32_t enable;
    /*!< is_first_frame If first frame, ignore input rec-sim*/
    int32_t is_first_frame;
    /*!< do_update Limit of S&R parameter update mechanism*/
    int32_t do_update;
    /*!< coeffs[3] Per-region mult-and-clamp coefficients*/
    int32_t coeffs[3];
    /*!< coeffs_user[3] Per-region mult-and-clamp coefficients (specified by user during offline calibration)*/
    int32_t coeffs_user[3];
    /*!< gpu_mode meta parameter controlling convolution implementation: 0 - HW implementation  1 - GPU implementation*/
    int32_t gpu_mode;
    /*!< tune_sensitivity user tuning - alignment-conf sensitivity*/
    int32_t tune_sensitivity;
    /*!< global_protection global protection enable*/
    int32_t global_protection;
    /*!< global_protection_sensitivity_lut_values[3] global protection - LUT values*/
    int32_t global_protection_sensitivity_lut_values[3];
    /*!< global_protection_sensitivity_lut_slopes[2] global protection - LUT slopes*/
    int32_t global_protection_sensitivity_lut_slopes[2];
    /*!< global_protection_motion_level average alignment conf of previous frame*/
    int32_t global_protection_motion_level;
    /*!< global_protection_motion_level_user average alignment conf of previous frame (specified by user during offline calibration)*/
    int32_t global_protection_motion_level_user;

} ia_pal_isp_tnr7_bc_1_0_t;

/*! \isp struct tnr7_bc_1_1

*/
typedef struct
{
    /*!< enable block enable*/
    int32_t enable;
    /*!< is_first_frame If first frame, ignore input rec-sim*/
    int32_t is_first_frame;
    /*!< do_update Limit of S&R parameter update mechanism*/
    int32_t do_update;
    /*!< coeffs[3] Per-region mult-and-clamp coefficients*/
    int32_t coeffs[3];
    /*!< coeffs_user[3] Per-region mult-and-clamp coefficients (specified by user during offline calibration)*/
    int32_t coeffs_user[3];
    /*!< gpu_mode meta parameter controlling convolution implementation: 0 - HW implementation  1 - GPU implementation*/
    int32_t gpu_mode;
    /*!< tune_sensitivity user tuning - alignment-conf sensitivity*/
    int32_t tune_sensitivity;
    /*!< global_protection global protection enable*/
    int32_t global_protection;
    /*!< global_protection_sensitivity_lut_values[3] global protection - LUT values*/
    int32_t global_protection_sensitivity_lut_values[3];
    /*!< global_protection_sensitivity_lut_slopes[2] global protection - LUT slopes*/
    int32_t global_protection_sensitivity_lut_slopes[2];
    /*!< global_protection_motion_level average alignment conf of previous frame*/
    int32_t global_protection_motion_level;
    /*!< global_protection_motion_level_user average alignment conf of previous frame (specified by user during offline calibration)*/
    int32_t global_protection_motion_level_user;
    /*!< global_protection_inv_num_pixels inverse of number of pixels in frame - prec is U0.20*/
    int32_t global_protection_inv_num_pixels;

} ia_pal_isp_tnr7_bc_1_1_t;

/*! \isp struct tnr7_blend_1_0

*/
typedef struct
{
    /*!< enable Enable TNR7 blend*/
    int32_t enable;
    /*!< enable_main_output Enable blend main output*/
    int32_t enable_main_output;
    /*!< enable_vision_output Enable blend computer vision output*/
    int32_t enable_vision_output;
    /*!< single_output_mode Both outputs use the same blend*/
    int32_t single_output_mode;
    /*!< spatial_weight_coeff Spatial weight coeff to be used in single_output_mode*/
    int32_t spatial_weight_coeff;
    /*!< max_recursive_similarity Maximum value of recursive similarity*/
    int32_t max_recursive_similarity;
    /*!< spatial_alpha Use of spatial filtering in the feedback output*/
    int32_t spatial_alpha;
    /*!< w_out_prev_LUT[32] Weight of reference in the main output*/
    int32_t w_out_prev_LUT[32];
    /*!< w_out_spl_LUT[32] Weight of spatial in the main output*/
    int32_t w_out_spl_LUT[32];
    /*!< output_cu_x[6] output config unit - x values*/
    int32_t output_cu_x[6];
    /*!< output_cu_a[5] output config unit - slope values*/
    int32_t output_cu_a[5];
    /*!< output_cu_b[5] output config unit - b values*/
    int32_t output_cu_b[5];
    /*!< max_recursive_similarity_vsn Vision - Maximum value of recursive similarity*/
    int32_t max_recursive_similarity_vsn;
    /*!< w_vsn_out_prev_LUT[32] Vision - Weight of reference in the main output*/
    int32_t w_vsn_out_prev_LUT[32];
    /*!< w_vsn_out_spl_LUT[32] Vision - Weight of spatial in the main output*/
    int32_t w_vsn_out_spl_LUT[32];

} ia_pal_isp_tnr7_blend_1_0_t;

/*! \isp struct tnr7_cme_1_0

*/
typedef struct
{
    /*!< enable Enable TNR7 CME (Course Motion Estimation)*/
    int32_t enable;
    /*!< input_width Input Base and Dest Image Width*/
    int32_t input_width;
    /*!< input_height Input Base and Dest Image Height*/
    int32_t input_height;
    /*!< hor_search_enable Enable Horizontal MV Estimation*/
    int32_t hor_search_enable;
    /*!< ver_search_enable Enable Vertical MV Estimation*/
    int32_t ver_search_enable;
    /*!< half_pel_enable Enable Half-Pixel MV Estimation*/
    int32_t half_pel_enable;
    /*!< quarter_pel_enable Enable Quarter-Pixel MV Estimation*/
    int32_t quarter_pel_enable;
    /*!< search_range_x Integer MV Search Displacement X*/
    int32_t search_range_x;
    /*!< search_range_y Integer MV Search Displacement Y*/
    int32_t search_range_y;
    /*!< spatial_reg_mod_factor Spatial Noise Level to Regularization Factor*/
    int32_t spatial_reg_mod_factor;
    /*!< temporal_reg_mod_factor Temporal Noise Level to Regularization Factor*/
    int32_t temporal_reg_mod_factor;
    /*!< noise_confidence_factor Confidence Base Noise Scale Factor*/
    int32_t noise_confidence_factor;
    /*!< confidence_thr High Confidence Model Minimum Threshold*/
    int32_t confidence_thr;
    /*!< model_confidence_deadzone Valid Confidence Model Minimum Threshold*/
    int32_t model_confidence_deadzone;
    /*!< noise_thr_est_enable Enable Automatic Noise Level Estimation*/
    int32_t noise_thr_est_enable;
    /*!< noise_thr Characterization Specified Noise Level*/
    int32_t noise_thr;
    /*!< noise_apu_min Noise APU Minimum Threshold*/
    int32_t noise_apu_min;
    /*!< noise_apu_alpha_limit Noise APU Alpha Limit*/
    int32_t noise_apu_alpha_limit;
    /*!< noise_apu_alpha_power Noise APU Alpha Power*/
    int32_t noise_apu_alpha_power;
    /*!< predictor_enable Enable Predictor (Parametric Model)*/
    int32_t predictor_enable;
    /*!< model_valid SaveRestore Predictor Model Valid*/
    int32_t model_valid;
    /*!< model_confidence SaveRestore Predictor Model Confidence*/
    int32_t model_confidence;
    /*!< model_ax0 SaveRestore Predictor Model X Component Shift*/
    int32_t model_ax0;
    /*!< model_ay0 SaveRestore Predictor Model Y Component Shift*/
    int32_t model_ay0;
    /*!< model_ax1 SaveRestore Predictor Model X Component Scale*/
    int32_t model_ax1;
    /*!< model_ay1 SaveRestore Predictor Model Y Component Scale*/
    int32_t model_ay1;
    /*!< noise_estimator_level_valid SaveRestore Noise Estimator Level Valid*/
    int32_t noise_estimator_level_valid;
    /*!< noise_estimator_level SaveRestore Noise Estimator Level*/
    int32_t noise_estimator_level;

} ia_pal_isp_tnr7_cme_1_0_t;

/*! \isp struct tnr7_ims_1_0

*/
typedef struct
{
    /*!< enable block enable*/
    int32_t enable;
    /*!< update_limit Limit of S&R parameter update mechanism*/
    int32_t update_limit;
    /*!< update_coeff S&R parameter update coefficient*/
    int32_t update_coeff;
    /*!< do_update Enables S&R update mechanism for distance log-likelihood distribution*/
    int32_t do_update;
    /*!< d_ml[16] Maximum-likelihood of distance distribution*/
    int32_t d_ml[16];
    /*!< d_slopes[16] Distance log-likelihood slopes*/
    int32_t d_slopes[16];
    /*!< d_top[16] Distance log-likelihood constants*/
    int32_t d_top[16];
    /*!< outofbounds[16] Is ml value out-of-hostogram-bounds?*/
    int32_t outofbounds[16];
    /*!< d_ml_user[16] Maximum-likelihood of distance distribution (specified by user during offline calibration)*/
    int32_t d_ml_user[16];
    /*!< d_slopes_user[16] Distance log-likelihood slopes (specified by user during offline calibration)*/
    int32_t d_slopes_user[16];
    /*!< d_top_user[16] Distance log-likelihood constants (specified by user during offline calibration)*/
    int32_t d_top_user[16];
    /*!< gpu_mode meta parameter for controlling convolution implementation: 0 - HW implementation  1 - GPU implementation*/
    int32_t gpu_mode;
    /*!< mbd_enable Enable bit of motion boundary detection submodule*/
    int32_t mbd_enable;
    /*!< mbd_sensitivity Gradient threshold sensitivity modifer parameter U3.6*/
    int32_t mbd_sensitivity;
    /*!< mbd_gradient_threshold Automatically estimated gradient threshold U1.8*/
    int32_t mbd_gradient_threshold;
    /*!< mbd_global_mag Automatically estimated global motion vector magnitude U9.3*/
    int32_t mbd_global_mag;
    /*!< mbd_stationary_mag_offset Global motion soft threshold - offset U9.3*/
    int32_t mbd_stationary_mag_offset;
    /*!< mbd_stationary_mag_slope Global motion soft threshold - slope S+3.10*/
    int32_t mbd_stationary_mag_slope;
    /*!< mbd_gradient_percentile Gradient CDF search threshold U0.7*/
    int32_t mbd_gradient_percentile;
    /*!< mbd_gradient_thr_user 1) When > 0, statically specified gradient threshold 2) When == 0, dynamic threshold estimated from histogram U1.8*/
    int32_t mbd_gradient_thr_user;
    /*!< mbd_gradient_thr_update Gradient estimate update rate U1.6*/
    int32_t mbd_gradient_thr_update;
    /*!< mbd_threshold_slope Slope of normalized gradient mult&clamp curve*/
    int32_t mbd_threshold_slope;
    /*!< mbd_mag_alpha_limit Global magnitude APU alpha limit*/
    int32_t mbd_mag_alpha_limit;
    /*!< mbd_mag_alpha_power Global magnitude alpha power*/
    int32_t mbd_mag_alpha_power;
    /*!< mbd_safe_pixel_thr IMS threshold for rejecting safe pixels based on MBS score Rejected pixels are > mbd_safe_pixel_thr*/
    int32_t mbd_safe_pixel_thr;

} ia_pal_isp_tnr7_ims_1_0_t;

/*! \isp struct tnr7_ims_1_1

*/
typedef struct
{
    /*!< enable block enable*/
    int32_t enable;
    /*!< update_limit Limit of S&R parameter update mechanism*/
    int32_t update_limit;
    /*!< update_coeff S&R parameter update coefficient*/
    int32_t update_coeff;
    /*!< do_update Enables S&R update mechanism for distance log-likelihood distribution*/
    int32_t do_update;
    /*!< d_ml[16] Maximum-likelihood of distance distribution*/
    int32_t d_ml[16];
    /*!< d_slopes[16] Distance log-likelihood slopes*/
    int32_t d_slopes[16];
    /*!< d_top[16] Distance log-likelihood constants*/
    int32_t d_top[16];
    /*!< outofbounds[16] Is ml value out-of-hostogram-bounds?*/
    int32_t outofbounds[16];
    /*!< d_ml_user[16] Maximum-likelihood of distance distribution (specified by user during offline calibration)*/
    int32_t d_ml_user[16];
    /*!< d_slopes_user[16] Distance log-likelihood slopes (specified by user during offline calibration)*/
    int32_t d_slopes_user[16];
    /*!< d_top_user[16] Distance log-likelihood constants (specified by user during offline calibration)*/
    int32_t d_top_user[16];
    /*!< gpu_mode meta parameter for controlling convolution implementation: 0 - HW implementation  1 - GPU implementation*/
    int32_t gpu_mode;
    /*!< radial_start radial correction start (relative to frame size)*/
    int32_t radial_start;
    /*!< radial_coeff radial correction power*/
    int32_t radial_coeff;
    /*!< frame_center_y frame center vertical*/
    int32_t frame_center_y;
    /*!< frame_center_x frame center horizontal*/
    int32_t frame_center_x;
    /*!< r_coeff radius relative to frame size*/
    int32_t r_coeff;

} ia_pal_isp_tnr7_ims_1_1_t;

/*! \isp struct tnr7_mc_1_0

*/
typedef struct
{
    /*!< passThrough Passthrough (set the motion vectors to zero when enabled)*/
    int32_t passThrough;
    /*!< imageHeightFR Height (pixels) of the full-resolution image*/
    int32_t imageHeightFR;
    /*!< imageWidthFR Width (pixels) of the full-resolution image*/
    int32_t imageWidthFR;
    /*!< imageHeightDS Height (pixels) of the small-resoltion image*/
    int32_t imageHeightDS;
    /*!< imageWidthDS Width (pixels) of the small-resoltion image*/
    int32_t imageWidthDS;

} ia_pal_isp_tnr7_mc_1_0_t;

/*! \isp struct tnr7_rme_1_0

*/
typedef struct
{
    /*!< rme16_image_height The height of base16y_in*/
    int32_t rme16_image_height;
    /*!< rme16_image_width The width of base16y_in*/
    int32_t rme16_image_width;
    /*!< rme4_image_height The height of base4y_in*/
    int32_t rme4_image_height;
    /*!< rme4_image_width The width of base4y_in*/
    int32_t rme4_image_width;
    /*!< rme_mv64_grid_height The height of the input motion grid*/
    int32_t rme_mv64_grid_height;
    /*!< rme_mv64_grid_width The width of the input motion grid*/
    int32_t rme_mv64_grid_width;
    /*!< rme_mv16y_max Maximal |mv16y| value*/
    int32_t rme_mv16y_max;
    /*!< rme_mv16x_max Maximal |mv16x| value*/
    int32_t rme_mv16x_max;
    /*!< rme16_band_height The height of the band update by rem16. Valid values: 1, 2, 4*/
    int32_t rme16_band_height;
    /*!< rme16_n_iterations Number of update iterations for each window location of the rme16 run. 0 = bypass update stage.*/
    int32_t rme16_n_iterations;
    /*!< rme4_n_iterations Number of update iterations for each window location of the rme4 run. 0 = bypass update stage.*/
    int32_t rme4_n_iterations;
    /*!< rme16_sv_wd_int Motion regulation parameter for rme16: SvWd*/
    int32_t rme16_sv_wd_int;
    /*!< rme4_sv_wd_int Motion regulation parameter for rme4: SvWd*/
    int32_t rme4_sv_wd_int;
    /*!< rme16_sv2_inv_man_int Motion regulation parameter for rme16: sv2inv = sv2inv_man * 2^sv2inv_exp*/
    int32_t rme16_sv2_inv_man_int;
    /*!< rme4_sv2_inv_man_int Motion regulation parameter for rme4: sv2inv = sv2inv_man * 2^sv2inv_exp*/
    int32_t rme4_sv2_inv_man_int;
    /*!< rme16_sv2_inv_exp Motion regulation parameter for rme16: sv2inv = sv2inv_man * 2^sv2inv_exp*/
    int32_t rme16_sv2_inv_exp;
    /*!< rme4_sv2_inv_exp Motion regulation parameter for rme4: sv2inv = sv2inv_man * 2^sv2inv_exp*/
    int32_t rme4_sv2_inv_exp;
    /*!< rme16_median_enable Enable median for rme16, when rme is not in pass-through mode*/
    int32_t rme16_median_enable;
    /*!< rme4_median_enable Enable median for rme4, when rme is not in pass-through mode*/
    int32_t rme4_median_enable;
    /*!< rme_out_resample_enable enable down-sampling of the final output, when resampling is enabled. 0: disabled, base4 density. 1: enabled, base16 density*/
    int32_t rme_out_resample_enable;
    /*!< rme_out_down_sample_enable down-sampling ratio of the final output, when resampling is enabled. 0 means no down-sampling, i.e. base4 density. 1 means down sampling x4, i.e. base 16 density*/
    int32_t rme_out_down_sample_enable;
    /*!< rme16_mc_pass_through motion compensation in pass through mode during rme16 run (for validation purposes). 0: normal operation. 1: pass-through mode (assu,es zero motion)*/
    int32_t rme16_mc_pass_through;
    /*!< rme4_mc_pass_through motion compensation in pass through mode during rme4 run (for validation purposes). 0: normal operation. 1: pass-through mode (assu,es zero motion)*/
    int32_t rme4_mc_pass_through;

} ia_pal_isp_tnr7_rme_1_0_t;

/*! \isp struct tnr7_spatial_1_0

*/
typedef struct
{
    /*!< enable Enable TNR7 spatial fallback filter*/
    int32_t enable;
    /*!< noise_model_radius Controls noise model radius*/
    int32_t noise_model_radius;
    /*!< iir_luma_power iir luma filtering strength (0-only fir, 64-only iir)*/
    int32_t iir_luma_power;
    /*!< iir_chroma_power iir chroma filtering strength (0-only fir, 64-only iir)*/
    int32_t iir_chroma_power;
    /*!< luma_strength blending coef for luma channel (blend with input)*/
    int32_t luma_strength;
    /*!< chroma_strength blending coef for chroma channel (blend with input)*/
    int32_t chroma_strength;
    /*!< lumaLUT_v[16] self calibrating noise model (NM) state variables, luma*/
    int32_t lumaLUT_v[16];
    /*!< lumaLUT_v_bins[16] self calibrating noise model (NM) state variables, luma*/
    int32_t lumaLUT_v_bins[16];
    /*!< lumaLUT_v_limits[2] vertical luma NM limnits*/
    int32_t lumaLUT_v_limits[2];
    /*!< nmGain_h_limits[2] horizontal luma NM limnits*/
    int32_t nmGain_h_limits[2];
    /*!< nmGain_iir_limits[2] iir luma NM limnits*/
    int32_t nmGain_iir_limits[2];
    /*!< nmGain_h horizontal NM gain*/
    int32_t nmGain_h;
    /*!< nmGain_iir iir NM gain*/
    int32_t nmGain_iir;
    /*!< update_limit update rate of N lut (0-no update, 256-current frame only)*/
    int32_t update_limit;
    /*!< update_coeff slope of the update rate as a function of #samples*/
    int32_t update_coeff;

} ia_pal_isp_tnr7_spatial_1_0_t;

/*! \isp struct tvs_1_0
Trainable visual scaler
*/
typedef struct
{
    /*!< bypass Bypass TVS*/
    int32_t bypass;
    /*!< ds_bypass Bypass downscale computation in TVS*/
    int32_t ds_bypass;
    /*!< metadata_bypass Bypass metadata of TVS output*/
    int32_t metadata_bypass;
    /*!< ds_factor_hor_int Integer part of downscale factor in horizontal*/
    int32_t ds_factor_hor_int;
    /*!< ds_factor_hor_frac Fractional part of downscale factor in horizontal (Must be 0 when ds_factor_hor_int=1)*/
    int32_t ds_factor_hor_frac;
    /*!< ds_factor_ver_int Integer part of downscale factor in vertical*/
    int32_t ds_factor_ver_int;
    /*!< ds_factor_ver_frac Fractional part of downscale factor in vertical (Must be 0 when ds_factor_ver_int=1)*/
    int32_t ds_factor_ver_frac;
    /*!< input_frame_width Input frame width (must be even number)*/
    int32_t input_frame_width;
    /*!< input_frame_height Input frame height (must be even number)*/
    int32_t input_frame_height;
    /*!< csc_kernels[9] CSC layer kernel weights*/
    int32_t csc_kernels[9];
    /*!< csc_kernels_shift CSC layer kernels fixed point value shift*/
    int32_t csc_kernels_shift;
    /*!< csc_biases[3] CSC layer bias weights*/
    int32_t csc_biases[3];
    /*!< csc_biases_shift_offset CSC layer biases fixed point value shift offset compared with csc_kernels_shift*/
    int32_t csc_biases_shift_offset;
    /*!< csc_data_shift CSC layer output data value shift*/
    int32_t csc_data_shift;
    /*!< conv_depth_kernels[588] Conv layer deptheise kernel weights*/
    int32_t conv_depth_kernels[588];
    /*!< conv_depth_kernels_shift Conv layer depthwise kernels fixed point value shift*/
    int32_t conv_depth_kernels_shift;
    /*!< conv_point_kernels[360] Conv layer pointwise kernel weights*/
    int32_t conv_point_kernels[360];
    /*!< conv_point_kernels_shift Conv layer pointwise kernels fixed point value shift*/
    int32_t conv_point_kernels_shift;
    /*!< conv_biases[30] Conv layer bias weights*/
    int32_t conv_biases[30];
    /*!< conv_biases_shift_offset Conv layer biases fixed point value shift offset compared with conv_point_kernels_shift*/
    int32_t conv_biases_shift_offset;
    /*!< conv_data_shift Conv layer output data value shift*/
    int32_t conv_data_shift;
    /*!< cu_act_func_x[15] Activation function ConfigUnit x vector*/
    int32_t cu_act_func_x[15];
    /*!< cu_act_func_y[14] Activation function ConfigUnit y vector*/
    int32_t cu_act_func_y[14];
    /*!< cu_act_func_slope[14] Activation function ConfigUnit slope vector*/
    int32_t cu_act_func_slope[14];
    /*!< act_func_output_offset Offset after Activation function*/
    int32_t act_func_output_offset;
    /*!< avg_weights[30] Avg layer weights*/
    int32_t avg_weights[30];
    /*!< avg_weights_shift[3] Avg layer weights fixed point value shift for each output channel*/
    int32_t avg_weights_shift[3];
    /*!< avg_biases[3] Avg layer biases*/
    int32_t avg_biases[3];
    /*!< avg_biases_shift_offset[3] Avg layer biases fixed point value shift offet compared with avg_weights_shift for each output channel*/
    int32_t avg_biases_shift_offset[3];
    /*!< avg_data_shift[3] Weighted averaging fixed point value shift for each output channel*/
    int32_t avg_data_shift[3];
    /*!< output_format_420 Output data format (0: YUV444; 1: YUV420. It will be forced to 1 if either ds_bypass or bypass is enabled)*/
    int32_t output_format_420;
    /*!< output_bpp_scale Bit precision scale of output data (1: 2bpp; 2: 4bpp; 3:8bpp)*/
    int32_t output_bpp_scale;
    /*!< metadata_avg_factor Division approximated factor for metadata average*/
    int32_t metadata_avg_factor;
    /*!< metadata_avg_shift Division approximated shift for metadata average*/
    int32_t metadata_avg_shift;

} ia_pal_isp_tvs_1_0_t;

/*! \isp struct upscaler_1_0

*/
typedef struct
{
    /*!< upscale_enable enable scaling filter*/
    int32_t upscale_enable;
    /*!< scaling_ratio U5.16 , upscale - less than 1, equals to 1/uspcale_factor*/
    int32_t scaling_ratio;
    /*!< output_height Output height counted in number of lines*/
    int32_t output_height;
    /*!< output_width Output width counted in number of pixels components per line*/
    int32_t output_width;
    /*!< kernel_LUT[129] S1.10 Y+UV channels Interpolation vertical kernel coefficients for scaler*/
    int32_t kernel_LUT[129];
    /*!< chroma_kernel_LUT[129] S1.10 Y+UV channels Interpolation vertical kernel coefficients for scaler*/
    int32_t chroma_kernel_LUT[129];
    /*!< cropper_input_width cropper Input width counted in number of pixels components per line*/
    int32_t cropper_input_width;
    /*!< cropper_input_height cropper Input height counted in number of lines*/
    int32_t cropper_input_height;
    /*!< cropper_x_output_offset Output horizontal offset from the input, counted in number of pixels components per line, 16b signed (if negative padding is required)*/
    int32_t cropper_x_output_offset;
    /*!< cropper_y_output_offset cropper Output vertical offset from the input counted in number of lines, 16b signed*/
    int32_t cropper_y_output_offset;
    /*!< cropper_output_width cropper Output width ,, equals upscaler input height*/
    int32_t cropper_output_width;
    /*!< cropper_output_height cropper Output height , equals upscaler input height*/
    int32_t cropper_output_height;
    /*!< upscale_input_height upscaler input height, equals to cropper_output_height*/
    int32_t upscale_input_height;
    /*!< upscale_input_width upscaler input width, equals to cropper_output_width*/
    int32_t upscale_input_width;

} ia_pal_isp_upscaler_1_0_t;

/*! \isp struct vcr_3_1

*/
typedef struct
{
    /*!< enable enables the filter (YUV420 --> RGB444)*/
    int32_t enable;
    /*!< nb1 offset 1 yuv2rgb conversion, rgb = m * yuv + nb*/
    int32_t nb1;
    /*!< nb2 offset 2 yuv2rgb conversion, rgb = m * yuv + nb*/
    int32_t nb2;
    /*!< nb3 offset 3 yuv2rgb conversion, rgb = m * yuv + nb*/
    int32_t nb3;
    /*!< yuv2rgb_matrix[9] yuv to rgb conversion matrix, S4.11*/
    int32_t yuv2rgb_matrix[9];

} ia_pal_isp_vcr_3_1_t;

/*! \isp struct vcr3

*/
typedef struct
{
    /*!< bypass_0_1 Bypass VCR2*/
    int32_t bypass_0_1;
    /*!< input_format_420 0 - input 4:4:4 , 1 - input 4:2:0*/
    int32_t input_format_420;

} ia_pal_isp_vcr3_t;

/*! \isp struct vcsc_2_0

*/
typedef struct
{
    /*!< csc_c_matrix_arr[9] CSC Matrix components (S0.15)*/
    int32_t csc_c_matrix_arr[9];
    /*!< csc_b_vec_arr[3] CSC Vector components (S0.15)*/
    int32_t csc_b_vec_arr[3];
    /*!< chroma_ds_coeff_arr[8] Chroma downsample 4x2 filter coefficients (U2.0)*/
    int32_t chroma_ds_coeff_arr[8];
    /*!< chroma_ds_nf Chroma downsample 4x2 filter normalization factor*/
    int32_t chroma_ds_nf;
    /*!< enable Bypassing CSC. Outputting RGB to the Chroma downscale*/
    int32_t enable;
    /*!< uv_bin_output 0 = YUV4:2:0 output, 1 = YUV4:2:2 output*/
    int32_t uv_bin_output;

} ia_pal_isp_vcsc_2_0_t;

/*! \isp struct vertical_padding_1_0
padding
*/
typedef struct
{
    /*!< padding_top lines padding top*/
    int32_t padding_top;
    /*!< padding_bottom lines padding bottom*/
    int32_t padding_bottom;

} ia_pal_isp_vertical_padding_1_0_t;

/*! \isp struct vltm_1_0

*/
typedef struct
{
    /*!< bypass bypass*/
    int32_t bypass;
    /*!< alpha U4.12 boost factor*/
    int32_t alpha;
    /*!< alpha_shift_factor U4.0 shift_factor for fixed point conversion*/
    int32_t alpha_shift_factor;
    /*!< cu_vltm_x[6] U12.0 cu_vltm_x*/
    int32_t cu_vltm_x[6];
    /*!< cu_vltm_y[5] U12.0 cu_vltm_y*/
    int32_t cu_vltm_y[5];
    /*!< cu_vltm_slope[5] S.12.4 cu_vltm_slope (16 bits including sign)*/
    int32_t cu_vltm_slope[5];

} ia_pal_isp_vltm_1_0_t;

/*! \isp struct wb_1_1

*/
typedef struct
{
    /*!< bypass Bypass            {0,1}*/
    int32_t bypass;
    /*!< gainch0 Gain Channel0 (Gr) (U8.12)*/
    int32_t gainch0;
    /*!< gainch1 Gain Channel1 (Gb) (U8.12)*/
    int32_t gainch1;
    /*!< gainch2 Gain Channel2 (G)  (U8.12)*/
    int32_t gainch2;
    /*!< gainch3 Gain Channel3 (B)  (U8.12)*/
    int32_t gainch3;
    /*!< gainch4 Gain Channel4 (R)  (U8.12)*/
    int32_t gainch4;
    /*!< gainch5 Gain Channel5 (W)  (U8.12)*/
    int32_t gainch5;
    /*!< gainch6 Gain Channel6 (U8.12)*/
    int32_t gainch6;
    /*!< gainch7 Gain Channel7 (U8.12)*/
    int32_t gainch7;
    /*!< sensormode Sensor CFA size: 1x1 (0), 2x2 (1), 4x4 (2)*/
    int32_t sensormode;
    /*!< wbindmat[16] Vector WB matrix*/
    int32_t wbindmat[16];

} ia_pal_isp_wb_1_1_t;

/*! \isp struct wb_sis

*/
typedef struct
{
    /*!< m_bypass Bypass            {0,1}*/
    int32_t m_bypass;
    /*!< m_gainch0 Gain Channel0 (Gr) (U4.12)*/
    int32_t m_gainch0;
    /*!< m_gainch1 Gain Channel1 (Gb) (U4.12)*/
    int32_t m_gainch1;
    /*!< m_gainch2 Gain Channel2 (G)  (U4.12)*/
    int32_t m_gainch2;
    /*!< m_gainch3 Gain Channel3 (B)  (U4.12)*/
    int32_t m_gainch3;
    /*!< m_gainch4 Gain Channel4 (R)  (U4.12)*/
    int32_t m_gainch4;
    /*!< m_gainch5 Gain Channel5 (W)  (U4.12)*/
    int32_t m_gainch5;
    /*!< m_gainch6 Gain Channel6 (U4.12)*/
    int32_t m_gainch6;
    /*!< m_gainch7 Gain Channel7 (U4.12)*/
    int32_t m_gainch7;
    /*!< m_sensormode 1x1 (0), 2x2 (1), 4x4 (2)*/
    int32_t m_sensormode;
    /*!< m_wbindmat[16] Vector WB matrix*/
    int32_t m_wbindmat[16];

} ia_pal_isp_wb_sis_t;

/*! \isp struct x2i_md_1_0
Monocular Depth
*/
typedef struct
{
    /*!< bypass by pass*/
    int32_t bypass;
    /*!< ver_bin_bypass bypass vertical binning when input is 2x4 PDAF*/
    int32_t ver_bin_bypass;
    /*!< bin_only do binning only and not calculate depth information*/
    int32_t bin_only;
    /*!< depth_map_bypass bypass depth map generation*/
    int32_t depth_map_bypass;
    /*!< bayer2y_bypass bypass bayer2y estimation when input is single channel phase disparity*/
    int32_t bayer2y_bypass;
    /*!< is_sve is input sve signal? If not, use simple Y computation; otherwise, use special Y computation*/
    int32_t is_sve;
    /*!< ver_bin_by_averaging whether to do vertical binning by averaging (0: by adding; 1: by averaging)*/
    int32_t ver_bin_by_averaging;
    /*!< hor_bin_by_averaging whether to do horizontal binning by averaging (0: by adding; 1: by averaging)*/
    int32_t hor_bin_by_averaging;
    /*!< win_width sliding window width for SAD computation*/
    int32_t win_width;
    /*!< min_shift minimum possible phase shift that estimation process will search*/
    int32_t min_shift;
    /*!< max_shift maximum possible phase shift that estimation process will search*/
    int32_t max_shift;
    /*!< shift_steps phase shift candidate steps*/
    int32_t shift_steps;
    /*!< y_compute_weights[16] Weights for y computation 3x3 filter (row by row, 6th, 7th, 8th, 10th, 11th, 12th, 14th, 15th, and 16th elements are used) in 2PD/4PD mode or 4x4 filter (row by row) in SVE mode. Sum of weights should be power of 2.*/
    int32_t y_compute_weights[16];
    /*!< y_compute_shift_0 shift scale of weight value for y computation at first stage  (the shift before saving to local buffer). The bit precision in local buffer is S18.*/
    int32_t y_compute_shift_0;
    /*!< y_compute_shift_1 shift scale of weight value for y computation at second stage (the shift before outputing final value)*/
    int32_t y_compute_shift_1;
    /*!< min_depth minimum depth showed in depth map (uint: mm) for visualization purpose*/
    int32_t min_depth;
    /*!< max_depth maximum depth showed in depth map (uint: mm) for visualization purpose*/
    int32_t max_depth;
    /*!< mono_radius number of neighbors at each side of SAD minimum point is monotonously increasing to be regarded as valid estimation result*/
    int32_t mono_radius;
    /*!< sad_diff_thresh_scale local SAD difference threshold dividing factor of power 2*/
    int32_t sad_diff_thresh_scale;
    /*!< min_sad_diff_thresh minimum SAD difference threshold to be considered as valid point*/
    int32_t min_sad_diff_thresh;
    /*!< max_sad_diff_thresh maximum SAD difference threshold to be considered as valid point*/
    int32_t max_sad_diff_thresh;
    /*!< interp_div_value_shift shift scale of division result used in equi-angle v interpolation*/
    int32_t interp_div_value_shift;
    /*!< vcm_value_shift shift scale of VCM value*/
    int32_t vcm_value_shift;
    /*!< phase_vcm_mapping_grid_width grid width of phase shift vs VCM mapping slope table in power of 2*/
    int32_t phase_vcm_mapping_grid_width;
    /*!< phase_vcm_mapping_grid_height grid height of phase shift vs VCM mapping slope table in power of 2*/
    int32_t phase_vcm_mapping_grid_height;
    /*!< phase_vcm_mapping_grid_block_num_hor horizontal block number in grid of phase shift vs VCM mapping slope table*/
    int32_t phase_vcm_mapping_grid_block_num_hor;
    /*!< phase_vcm_mapping_grid_block_num_ver vertical block number in grid of phase shift vs VCM mapping slope table*/
    int32_t phase_vcm_mapping_grid_block_num_ver;
    /*!< phase_vcm_mapping_slope[256] phase shift vs VCM mapping slope table*/
    int32_t phase_vcm_mapping_slope[256];
    /*!< current_vcm current VCM value*/
    int32_t current_vcm;
    /*!< phase_value_shift shift scale of phase shift value*/
    int32_t phase_value_shift;
    /*!< depth_lut_size size of depth look-up table*/
    int32_t depth_lut_size;
    /*!< depth_lutbase_levels[2] base levels of depth look-up table*/
    int32_t depth_lutbase_levels[2];
    /*!< depth_lut_start_bins[2] number of bins in depth look-up table*/
    int32_t depth_lut_start_bins[2];
    /*!< depth_lut_steps[2] step sizes of bins in depth look-up table in power of 2*/
    int32_t depth_lut_steps[2];
    /*!< depth_lut_values[187] value of depth look-up tables*/
    int32_t depth_lut_values[187];

} ia_pal_isp_x2i_md_1_0_t;

/*! \isp struct xnr_5_1
Low Frequency Chroma Denoiser
*/
typedef struct
{
    /*!< top_frame_width XNR5 input frame width*/
    int32_t top_frame_width;
    /*!< top_frame_height XNR5 input frame height*/
    int32_t top_frame_height;
    /*!< top_xnr_bypass Bypass entire xnr*/
    int32_t top_xnr_bypass;
    /*!< vhf_frame_width XNR5 input frame width*/
    int32_t vhf_frame_width;
    /*!< vhf_frame_height XNR5 input frame height*/
    int32_t vhf_frame_height;
    /*!< vhf_low_band_disable Lower band is disabled and zero on inputs*/
    int32_t vhf_low_band_disable;
    /*!< vhf_low_band_only Lower band directly goes to output and other inputs are zeroes*/
    int32_t vhf_low_band_only;
    /*!< hf_frame_width XNR5 input frame width*/
    int32_t hf_frame_width;
    /*!< hf_frame_height XNR5 input frame height*/
    int32_t hf_frame_height;
    /*!< hf_low_band_disable Lower band is disabled and zero on inputs*/
    int32_t hf_low_band_disable;
    /*!< hf_low_band_only Lower band directly goes to output and other inputs are zeroes*/
    int32_t hf_low_band_only;
    /*!< hf_nr_bypass Input YUV goes directly to output after vertical delay*/
    int32_t hf_nr_bypass;
    /*!< hf_se_bypass Replace all SE outputs with se_bypass_val*/
    int32_t hf_se_bypass;
    /*!< hf_se_bypass_val SE bypass value*/
    int32_t hf_se_bypass_val;
    /*!< mf_frame_width XNR5 input frame width*/
    int32_t mf_frame_width;
    /*!< mf_frame_height XNR5 input frame height*/
    int32_t mf_frame_height;
    /*!< mf_low_band_disable Lower band is disabled and zero on inputs*/
    int32_t mf_low_band_disable;
    /*!< mf_low_band_only Lower band directly goes to output and other inputs are zeroes*/
    int32_t mf_low_band_only;
    /*!< mf_nr_bypass Input YUV goes directly to output after vertical delay*/
    int32_t mf_nr_bypass;
    /*!< mf_se_bypass Replace all SE outputs with se_bypass_val*/
    int32_t mf_se_bypass;
    /*!< mf_se_bypass_val SE bypass value*/
    int32_t mf_se_bypass_val;
    /*!< lf_frame_width XNR5 input frame width*/
    int32_t lf_frame_width;
    /*!< lf_frame_height XNR5 input frame height*/
    int32_t lf_frame_height;
    /*!< lf_low_band_disable Lower band is disabled and zero on inputs*/
    int32_t lf_low_band_disable;
    /*!< lf_low_band_only Lower band directly goes to output and other inputs are zeroes*/
    int32_t lf_low_band_only;
    /*!< lf_nr_bypass Input YUV goes directly to output after vertical delay*/
    int32_t lf_nr_bypass;
    /*!< lf_se_bypass Replace all SE outputs with se_bypass_val*/
    int32_t lf_se_bypass;
    /*!< lf_se_bypass_val SE bypass value*/
    int32_t lf_se_bypass_val;
    /*!< vlf_frame_width XNR5 input frame width*/
    int32_t vlf_frame_width;
    /*!< vlf_frame_height XNR5 input frame height*/
    int32_t vlf_frame_height;
    /*!< vlf_low_band_disable Lower band is disabled and zero on inputs*/
    int32_t vlf_low_band_disable;
    /*!< vlf_low_band_only Lower band directly goes to output and other inputs are zeroes*/
    int32_t vlf_low_band_only;
    /*!< vlf_nr_bypass Input YUV goes directly to output after vertical delay*/
    int32_t vlf_nr_bypass;
    /*!< vlf_se_bypass Replace all SE outputs with se_bypass_val*/
    int32_t vlf_se_bypass;
    /*!< vlf_se_bypass_val SE bypass value*/
    int32_t vlf_se_bypass_val;
    /*!< Bypass Deprecated bypass parameter - to be removed!*/
    int32_t Bypass;
    /*!< top_viir_coefs_b[3] Param_Top_VIIR_b*/
    int32_t top_viir_coefs_b[3];
    /*!< top_viir_coefs_a[2] Param_Top_VIIR_a*/
    int32_t top_viir_coefs_a[2];
    /*!< top_viir_offset Param_Top_VIIR_offset*/
    int32_t top_viir_offset;
    /*!< top_viir_alpha Param_Top_VIIR_alpha*/
    int32_t top_viir_alpha;
    /*!< top_hus_vlf_image_coefs[9] Param_Top_HUS_VLF_Image_func*/
    int32_t top_hus_vlf_image_coefs[9];
    /*!< top_hus_vlf_delta_coefs[9] Param_Top_HUS_VLF_Delta_func*/
    int32_t top_hus_vlf_delta_coefs[9];
    /*!< top_hus_lf_image_coefs[5] Param_Top_HUS_LF_Image_func*/
    int32_t top_hus_lf_image_coefs[5];
    /*!< top_hus_lf_delta_coefs[5] Param_Top_HUS_LF_Delta_func*/
    int32_t top_hus_lf_delta_coefs[5];
    /*!< top_hus_mf_image_coefs[5] Param_Top_HUS_MF_Image_func*/
    int32_t top_hus_mf_image_coefs[5];
    /*!< top_hus_mf_delta_coefs[5] Param_Top_HUS_MF_Delta_func*/
    int32_t top_hus_mf_delta_coefs[5];
    /*!< hf_blf_2dfir_filter_length Param_HFC_BLF_FIR_BfLen*/
    int32_t hf_blf_2dfir_filter_length;
    /*!< hf_blf_2dfir_dcdc_bypass_y Param_HFC_BLF_FIR_bypassDCDifferentialCompensationY*/
    int32_t hf_blf_2dfir_dcdc_bypass_y;
    /*!< hf_blf_2dfir_dcdc_thresh_y_y Param_HFC_BLF_FIR_DCDiffThYy*/
    uint32_t hf_blf_2dfir_dcdc_thresh_y_y;
    /*!< hf_blf_2dfir_dcdc_thresh_y_u Param_HFC_BLF_FIR_DCDiffThYu*/
    uint32_t hf_blf_2dfir_dcdc_thresh_y_u;
    /*!< hf_blf_2dfir_dcdc_thresh_y_v Param_HFC_BLF_FIR_DCDiffThYv*/
    uint32_t hf_blf_2dfir_dcdc_thresh_y_v;
    /*!< hf_blf_2dfir_dcdc_bypass_uv Param_HFC_BLF_FIR_bypassDCDifferentialCompensationUV*/
    int32_t hf_blf_2dfir_dcdc_bypass_uv;
    /*!< hf_blf_2dfir_dcdc_thresh_uv_y Param_HFC_BLF_FIR_DCDiffThUVy*/
    uint32_t hf_blf_2dfir_dcdc_thresh_uv_y;
    /*!< hf_blf_2dfir_dcdc_thresh_uv_u Param_HFC_BLF_FIR_DCDiffThUVu*/
    uint32_t hf_blf_2dfir_dcdc_thresh_uv_u;
    /*!< hf_blf_2dfir_dcdc_thresh_uv_v Param_HFC_BLF_FIR_DCDiffThUVv*/
    uint32_t hf_blf_2dfir_dcdc_thresh_uv_v;
    /*!< hf_blf_colorspace Param_HFC_BLF_colorspaceYRB*/
    int32_t hf_blf_colorspace;
    /*!< hf_blf_noisemodel_basefunc_y_a_x[5] Param_HFC_BLF_NoiseModel_sigmaParafacY_A_X*/
    int32_t hf_blf_noisemodel_basefunc_y_a_x[5];
    /*!< hf_blf_noisemodel_basefunc_y_a_y[4] Param_HFC_BLF_NoiseModel_sigmaParafacY_A_Y*/
    int32_t hf_blf_noisemodel_basefunc_y_a_y[4];
    /*!< hf_blf_noisemodel_basefunc_y_a_slope[4] Param_HFC_BLF_NoiseModel_sigmaParafacY_A_Slope*/
    int32_t hf_blf_noisemodel_basefunc_y_a_slope[4];
    /*!< hf_blf_noisemodel_basefunc_y_b_x[5] Param_HFC_BLF_NoiseModel_sigmaParafacY_B_X*/
    int32_t hf_blf_noisemodel_basefunc_y_b_x[5];
    /*!< hf_blf_noisemodel_basefunc_y_b_y[4] Param_HFC_BLF_NoiseModel_sigmaParafacY_B Config Unit Value*/
    int32_t hf_blf_noisemodel_basefunc_y_b_y[4];
    /*!< hf_blf_noisemodel_basefunc_y_b_slope[4] Slope*/
    int32_t hf_blf_noisemodel_basefunc_y_b_slope[4];
    /*!< hf_blf_noisemodel_basefunc_y_c_x[5] Param_HFC_BLF_NoiseModel_sigmaParafacY_C_X*/
    int32_t hf_blf_noisemodel_basefunc_y_c_x[5];
    /*!< hf_blf_noisemodel_basefunc_y_c_y[4] Param_HFC_BLF_NoiseModel_sigmaParafacY_C Config Unit Value*/
    int32_t hf_blf_noisemodel_basefunc_y_c_y[4];
    /*!< hf_blf_noisemodel_basefunc_y_c_slope[4] Slope*/
    int32_t hf_blf_noisemodel_basefunc_y_c_slope[4];
    /*!< hf_blf_noisemodel_basefunc_y_wbg Param_HFC_BLF_NoiseModel_sigmaParafacY_DEF*/
    int32_t hf_blf_noisemodel_basefunc_y_wbg;
    /*!< hf_blf_noisemodel_basefunc_u_a_x[5] Param_HFC_BLF_NoiseModel_sigmaParafacU_A_X*/
    int32_t hf_blf_noisemodel_basefunc_u_a_x[5];
    /*!< hf_blf_noisemodel_basefunc_u_a_y[4] Param_HFC_BLF_NoiseModel_sigmaParafacU_A Config Unit Value*/
    int32_t hf_blf_noisemodel_basefunc_u_a_y[4];
    /*!< hf_blf_noisemodel_basefunc_u_a_slope[4] Slope*/
    int32_t hf_blf_noisemodel_basefunc_u_a_slope[4];
    /*!< hf_blf_noisemodel_basefunc_u_b_x[5] Param_HFC_BLF_NoiseModel_sigmaParafacU_B_X*/
    int32_t hf_blf_noisemodel_basefunc_u_b_x[5];
    /*!< hf_blf_noisemodel_basefunc_u_b_y[4] Param_HFC_BLF_NoiseModel_sigmaParafacU_B Config Unit Value*/
    int32_t hf_blf_noisemodel_basefunc_u_b_y[4];
    /*!< hf_blf_noisemodel_basefunc_u_b_slope[4] Slope*/
    int32_t hf_blf_noisemodel_basefunc_u_b_slope[4];
    /*!< hf_blf_noisemodel_basefunc_u_c_x[5] Param_HFC_BLF_NoiseModel_sigmaParafacU_C_X*/
    int32_t hf_blf_noisemodel_basefunc_u_c_x[5];
    /*!< hf_blf_noisemodel_basefunc_u_c_y[4] Param_HFC_BLF_NoiseModel_sigmaParafacU_C Config Unit Value*/
    int32_t hf_blf_noisemodel_basefunc_u_c_y[4];
    /*!< hf_blf_noisemodel_basefunc_u_c_slope[4] Slope*/
    int32_t hf_blf_noisemodel_basefunc_u_c_slope[4];
    /*!< hf_blf_noisemodel_basefunc_u_wbg Param_HFC_BLF_NoiseModel_sigmaParafacU_DEF*/
    int32_t hf_blf_noisemodel_basefunc_u_wbg;
    /*!< hf_blf_noisemodel_basefunc_v_a_x[5] Param_HFC_BLF_NoiseModel_sigmaParafacV_A_X*/
    int32_t hf_blf_noisemodel_basefunc_v_a_x[5];
    /*!< hf_blf_noisemodel_basefunc_v_a_y[4] Param_HFC_BLF_NoiseModel_sigmaParafacV_A Config Unit Value*/
    int32_t hf_blf_noisemodel_basefunc_v_a_y[4];
    /*!< hf_blf_noisemodel_basefunc_v_a_slope[4] Slope*/
    int32_t hf_blf_noisemodel_basefunc_v_a_slope[4];
    /*!< hf_blf_noisemodel_basefunc_v_b_x[5] Param_HFC_BLF_NoiseModel_sigmaParafacV_B_X*/
    int32_t hf_blf_noisemodel_basefunc_v_b_x[5];
    /*!< hf_blf_noisemodel_basefunc_v_b_y[4] Param_HFC_BLF_NoiseModel_sigmaParafacV_B Config Unit Value*/
    int32_t hf_blf_noisemodel_basefunc_v_b_y[4];
    /*!< hf_blf_noisemodel_basefunc_v_b_slope[4] Slope*/
    int32_t hf_blf_noisemodel_basefunc_v_b_slope[4];
    /*!< hf_blf_noisemodel_basefunc_v_c_x[5] Param_HFC_BLF_NoiseModel_sigmaParafacV_C_X*/
    int32_t hf_blf_noisemodel_basefunc_v_c_x[5];
    /*!< hf_blf_noisemodel_basefunc_v_c_y[4] Param_HFC_BLF_NoiseModel_sigmaParafacV_C Config Unit Value*/
    int32_t hf_blf_noisemodel_basefunc_v_c_y[4];
    /*!< hf_blf_noisemodel_basefunc_v_c_slope[4] Slope*/
    int32_t hf_blf_noisemodel_basefunc_v_c_slope[4];
    /*!< hf_blf_noisemodel_basefunc_v_wbg Param_HFC_BLF_NoiseModel_sigmaParafacV_DEF*/
    int32_t hf_blf_noisemodel_basefunc_v_wbg;
    /*!< hf_blf_noisemodel_weight_uv_y Param_HFC_BLF_NoiseModel_sigmaWgtUVy*/
    int32_t hf_blf_noisemodel_weight_uv_y;
    /*!< hf_blf_noisemodel_weight_uv_u Param_HFC_BLF_NoiseModel_sigmaWgtUVu*/
    int32_t hf_blf_noisemodel_weight_uv_u;
    /*!< hf_blf_noisemodel_weight_uv_v Param_HFC_BLF_NoiseModel_sigmaWgtUVv*/
    int32_t hf_blf_noisemodel_weight_uv_v;
    /*!< hf_blf_noisemodel_radialdependent_bypass Param_HFC_BLF_NoiseModel_bypassRadialCorrection*/
    int32_t hf_blf_noisemodel_radialdependent_bypass;
    /*!< hf_blf_noisemodel_colordependent_bypass Param_HFC_BLF_NoiseModel_bypassColorDependent*/
    int32_t hf_blf_noisemodel_colordependent_bypass;
    /*!< hf_blf_noisemodel_graydependent_bypass Param_HFC_BLF_NoiseModel_bypassGrayDependent*/
    int32_t hf_blf_noisemodel_graydependent_bypass;
    /*!< hf_blf_noisemodel_radialdependent_x0_square Param_HFC_BLF_NoiseModel_radialDependent_x0_square*/
    int32_t hf_blf_noisemodel_radialdependent_x0_square;
    /*!< hf_blf_noisemodel_radialdependent_x0 Param_HFC_BLF_NoiseModel_radialDependent_x0*/
    int32_t hf_blf_noisemodel_radialdependent_x0;
    /*!< hf_blf_noisemodel_radialdependent_y0_square Param_HFC_BLF_NoiseModel_radialDependent_y0_square*/
    int32_t hf_blf_noisemodel_radialdependent_y0_square;
    /*!< hf_blf_noisemodel_radialdependent_y0 Param_HFC_BLF_NoiseModel_radialDependent_y0*/
    int32_t hf_blf_noisemodel_radialdependent_y0;
    /*!< hf_blf_noisemodel_radialdependent_rshift_norm_square_distance Param_HFC_BLF_NoiseModel_radialDependent_rshiftNormSquareDist*/
    int32_t hf_blf_noisemodel_radialdependent_rshift_norm_square_distance;
    /*!< hf_blf_noisemodel_radialdependent_gain_x[4] Param_HFC_BLF_NoiseModel_radialDependent_radialLut_X*/
    int32_t hf_blf_noisemodel_radialdependent_gain_x[4];
    /*!< hf_blf_noisemodel_radialdependent_gain_y[3] Param_HFC_BLF_NoiseModel_radialDependent_radialLut Config Unit Value*/
    int32_t hf_blf_noisemodel_radialdependent_gain_y[3];
    /*!< hf_blf_noisemodel_radialdependent_gain_slope[3] Slope*/
    int32_t hf_blf_noisemodel_radialdependent_gain_slope[3];
    /*!< hf_blf_noisemodel_colordependent_a[32] Param_HFC_BLF_NoiseModel_colorDependent_A*/
    int32_t hf_blf_noisemodel_colordependent_a[32];
    /*!< hf_blf_noisemodel_colordependent_b[32] Param_HFC_BLF_NoiseModel_colorDependent_B*/
    int32_t hf_blf_noisemodel_colordependent_b[32];
    /*!< hf_blf_noisemodel_colordependent_c[32] Param_HFC_BLF_NoiseModel_colorDependent_C*/
    int32_t hf_blf_noisemodel_colordependent_c[32];
    /*!< hf_blf_noisemodel_colordependent_norm_offset Param_HFC_BLF_NoiseModel_colorDependent_normalization_offset*/
    int32_t hf_blf_noisemodel_colordependent_norm_offset;
    /*!< hf_blf_noisemodel_colordependent_gain_x[6] Param_HFC_BLF_NoiseModel_colorDependent_Lut_X*/
    int32_t hf_blf_noisemodel_colordependent_gain_x[6];
    /*!< hf_blf_noisemodel_colordependent_gain_y[5] Param_HFC_BLF_NoiseModel_colorDependent_Lut Config Unit Value*/
    int32_t hf_blf_noisemodel_colordependent_gain_y[5];
    /*!< hf_blf_noisemodel_colordependent_gain_slope[5] Slope*/
    int32_t hf_blf_noisemodel_colordependent_gain_slope[5];
    /*!< hf_blf_noisemodel_graydependent_graylevel_thresh Param_HFC_BLF_NoiseModel_grayDependent_grayThrsh*/
    int32_t hf_blf_noisemodel_graydependent_graylevel_thresh;
    /*!< hf_blf_noisemodel_graydependent_graylevel_slope Param_HFC_BLF_NoiseModel_grayDependent_graySlope*/
    int32_t hf_blf_noisemodel_graydependent_graylevel_slope;
    /*!< hf_blf_noisemodel_graydependent_gain_x[6] Param_HFC_BLF_NoiseModel_grayDependent_transLut_X*/
    int32_t hf_blf_noisemodel_graydependent_gain_x[6];
    /*!< hf_blf_noisemodel_graydependent_gain_y[5] Param_HFC_BLF_NoiseModel_grayDependent_transLut Config Unit Value*/
    int32_t hf_blf_noisemodel_graydependent_gain_y[5];
    /*!< hf_blf_noisemodel_graydependent_gain_slope[5] Slope*/
    int32_t hf_blf_noisemodel_graydependent_gain_slope[5];
    /*!< hf_blf_noisemodel_normfactor_uv_y Param_HFC_BLF_NoiseModel_invSigmaUVy*/
    int32_t hf_blf_noisemodel_normfactor_uv_y;
    /*!< hf_blf_noisemodel_normfactor_uv_u Param_HFC_BLF_NoiseModel_invSigmaUVu*/
    int32_t hf_blf_noisemodel_normfactor_uv_u;
    /*!< hf_blf_noisemodel_normfactor_uv_v Param_HFC_BLF_NoiseModel_invSigmaUVv*/
    int32_t hf_blf_noisemodel_normfactor_uv_v;
    /*!< hf_blf_snrm_bypass Param_HFC_BLF_SNRM_bypassSNRManagement*/
    int32_t hf_blf_snrm_bypass;
    /*!< hf_blf_snrm_slope_uv Param_HFC_BLF_SNRM_slopeUV*/
    int32_t hf_blf_snrm_slope_uv;
    /*!< hf_blf_snrm_xoffset_uv Param_HFC_BLF_SNRM_xoffsetUV*/
    int32_t hf_blf_snrm_xoffset_uv;
    /*!< hf_blf_snrm_maxval_uv Param_HFC_BLF_SNRM_maxValUV*/
    int32_t hf_blf_snrm_maxval_uv;
    /*!< hf_blf_snrm_minval_uv Param_HFC_BLF_SNRM_minValUV*/
    int32_t hf_blf_snrm_minval_uv;
    /*!< hf_afc_bypass Param_HFC_AFC_bypassAntiFalseColor*/
    int32_t hf_afc_bypass;
    /*!< hf_afc_weight_snr Param_HFC_AFC_wgtSnr*/
    int32_t hf_afc_weight_snr;
    /*!< hf_afc_weight_chroma Param_HFC_AFC_wgtC*/
    int32_t hf_afc_weight_chroma;
    /*!< hf_min_distance_clamp Param_HFC_min_distance_clamp*/
    int32_t hf_min_distance_clamp;
    /*!< mf_blf_2dfir_filter_length Param_MF_BLF_FIR_BfLen*/
    int32_t mf_blf_2dfir_filter_length;
    /*!< mf_blf_2dfir_luma_coefs[10] Param_MF_BLF_FIR_Kn_coef*/
    int32_t mf_blf_2dfir_luma_coefs[10];
    /*!< mf_blf_2dfir_luma_denom_bits Param_MF_BLF_FIR_Kn_denom_bits*/
    int32_t mf_blf_2dfir_luma_denom_bits;
    /*!< mf_blf_2dfir_dcdc_bypass_y Param_MF_BLF_FIR_bypassDCDifferentialCompensationY*/
    int32_t mf_blf_2dfir_dcdc_bypass_y;
    /*!< mf_blf_2dfir_dcdc_thresh_y_y Param_MF_BLF_FIR_DCDiffThYy*/
    uint32_t mf_blf_2dfir_dcdc_thresh_y_y;
    /*!< mf_blf_2dfir_dcdc_thresh_y_u Param_MF_BLF_FIR_DCDiffThYu*/
    uint32_t mf_blf_2dfir_dcdc_thresh_y_u;
    /*!< mf_blf_2dfir_dcdc_thresh_y_v Param_MF_BLF_FIR_DCDiffThYv*/
    uint32_t mf_blf_2dfir_dcdc_thresh_y_v;
    /*!< mf_blf_2dfir_dcdc_bypass_uv Param_MF_BLF_FIR_bypassDCDifferentialCompensationUV*/
    int32_t mf_blf_2dfir_dcdc_bypass_uv;
    /*!< mf_blf_2dfir_dcdc_thresh_uv_y Param_MF_BLF_FIR_DCDiffThUVy*/
    uint32_t mf_blf_2dfir_dcdc_thresh_uv_y;
    /*!< mf_blf_2dfir_dcdc_thresh_uv_u Param_MF_BLF_FIR_DCDiffThUVu*/
    uint32_t mf_blf_2dfir_dcdc_thresh_uv_u;
    /*!< mf_blf_2dfir_dcdc_thresh_uv_v Param_MF_BLF_FIR_DCDiffThUVv*/
    uint32_t mf_blf_2dfir_dcdc_thresh_uv_v;
    /*!< mf_blf_2dfir_bypass_snr_y Param_MF_BLF_FIR_bypasssSnrY*/
    int32_t mf_blf_2dfir_bypass_snr_y;
    /*!< mf_blf_colorspace Param_MF_BLF_colorspaceYRB*/
    int32_t mf_blf_colorspace;
    /*!< mf_blf_noisemodel_basefunc_y_a_x[5] Param_MF_BLF_NoiseModel_sigmaParafacY_A_X*/
    int32_t mf_blf_noisemodel_basefunc_y_a_x[5];
    /*!< mf_blf_noisemodel_basefunc_y_a_y[4] Param_MF_BLF_NoiseModel_sigmaParafacY_A Config Unit Value*/
    int32_t mf_blf_noisemodel_basefunc_y_a_y[4];
    /*!< mf_blf_noisemodel_basefunc_y_a_slope[4] Slope*/
    int32_t mf_blf_noisemodel_basefunc_y_a_slope[4];
    /*!< mf_blf_noisemodel_basefunc_y_b_x[5] Param_MF_BLF_NoiseModel_sigmaParafacY_B_X*/
    int32_t mf_blf_noisemodel_basefunc_y_b_x[5];
    /*!< mf_blf_noisemodel_basefunc_y_b_y[4] Param_MF_BLF_NoiseModel_sigmaParafacY_B Config Unit Value*/
    int32_t mf_blf_noisemodel_basefunc_y_b_y[4];
    /*!< mf_blf_noisemodel_basefunc_y_b_slope[4] Slope*/
    int32_t mf_blf_noisemodel_basefunc_y_b_slope[4];
    /*!< mf_blf_noisemodel_basefunc_y_c_x[5] Param_MF_BLF_NoiseModel_sigmaParafacY_C_X*/
    int32_t mf_blf_noisemodel_basefunc_y_c_x[5];
    /*!< mf_blf_noisemodel_basefunc_y_c_y[4] Param_MF_BLF_NoiseModel_sigmaParafacY_C Config Unit Value*/
    int32_t mf_blf_noisemodel_basefunc_y_c_y[4];
    /*!< mf_blf_noisemodel_basefunc_y_c_slope[4] Slope*/
    int32_t mf_blf_noisemodel_basefunc_y_c_slope[4];
    /*!< mf_blf_noisemodel_basefunc_y_wbg Param_MF_BLF_NoiseModel_sigmaParafacY_DEF*/
    int32_t mf_blf_noisemodel_basefunc_y_wbg;
    /*!< mf_blf_noisemodel_basefunc_u_a_x[5] Param_MF_BLF_NoiseModel_sigmaParafacU_A_X*/
    int32_t mf_blf_noisemodel_basefunc_u_a_x[5];
    /*!< mf_blf_noisemodel_basefunc_u_a_y[4] Param_MF_BLF_NoiseModel_sigmaParafacU_A Config Unit Value*/
    int32_t mf_blf_noisemodel_basefunc_u_a_y[4];
    /*!< mf_blf_noisemodel_basefunc_u_a_slope[4] Slope*/
    int32_t mf_blf_noisemodel_basefunc_u_a_slope[4];
    /*!< mf_blf_noisemodel_basefunc_u_b_x[5] Param_MF_BLF_NoiseModel_sigmaParafacU_B_X*/
    int32_t mf_blf_noisemodel_basefunc_u_b_x[5];
    /*!< mf_blf_noisemodel_basefunc_u_b_y[4] Param_MF_BLF_NoiseModel_sigmaParafacU_B Config Unit Value*/
    int32_t mf_blf_noisemodel_basefunc_u_b_y[4];
    /*!< mf_blf_noisemodel_basefunc_u_b_slope[4] Slope*/
    int32_t mf_blf_noisemodel_basefunc_u_b_slope[4];
    /*!< mf_blf_noisemodel_basefunc_u_c_x[5] Param_MF_BLF_NoiseModel_sigmaParafacU_C_X*/
    int32_t mf_blf_noisemodel_basefunc_u_c_x[5];
    /*!< mf_blf_noisemodel_basefunc_u_c_y[4] Param_MF_BLF_NoiseModel_sigmaParafacU_C Config Unit Value*/
    int32_t mf_blf_noisemodel_basefunc_u_c_y[4];
    /*!< mf_blf_noisemodel_basefunc_u_c_slope[4] Slope*/
    int32_t mf_blf_noisemodel_basefunc_u_c_slope[4];
    /*!< mf_blf_noisemodel_basefunc_u_wbg Param_MF_BLF_NoiseModel_sigmaParafacU_DEF*/
    int32_t mf_blf_noisemodel_basefunc_u_wbg;
    /*!< mf_blf_noisemodel_basefunc_v_a_x[5] Param_MF_BLF_NoiseModel_sigmaParafacV_A_X*/
    int32_t mf_blf_noisemodel_basefunc_v_a_x[5];
    /*!< mf_blf_noisemodel_basefunc_v_a_y[4] Param_MF_BLF_NoiseModel_sigmaParafacV_A Config Unit Value*/
    int32_t mf_blf_noisemodel_basefunc_v_a_y[4];
    /*!< mf_blf_noisemodel_basefunc_v_a_slope[4] Slope*/
    int32_t mf_blf_noisemodel_basefunc_v_a_slope[4];
    /*!< mf_blf_noisemodel_basefunc_v_b_x[5] Param_MF_BLF_NoiseModel_sigmaParafacV_B_X*/
    int32_t mf_blf_noisemodel_basefunc_v_b_x[5];
    /*!< mf_blf_noisemodel_basefunc_v_b_y[4] Param_MF_BLF_NoiseModel_sigmaParafacV_B Config Unit Value*/
    int32_t mf_blf_noisemodel_basefunc_v_b_y[4];
    /*!< mf_blf_noisemodel_basefunc_v_b_slope[4] Slope*/
    int32_t mf_blf_noisemodel_basefunc_v_b_slope[4];
    /*!< mf_blf_noisemodel_basefunc_v_c_x[5] Param_MF_BLF_NoiseModel_sigmaParafacV_C_X*/
    int32_t mf_blf_noisemodel_basefunc_v_c_x[5];
    /*!< mf_blf_noisemodel_basefunc_v_c_y[4] Param_MF_BLF_NoiseModel_sigmaParafacV_C Config Unit Value*/
    int32_t mf_blf_noisemodel_basefunc_v_c_y[4];
    /*!< mf_blf_noisemodel_basefunc_v_c_slope[4] Slope*/
    int32_t mf_blf_noisemodel_basefunc_v_c_slope[4];
    /*!< mf_blf_noisemodel_basefunc_v_wbg Param_MF_BLF_NoiseModel_sigmaParafacV_DEF*/
    int32_t mf_blf_noisemodel_basefunc_v_wbg;
    /*!< mf_blf_noisemodel_weight_y_y Param_MF_BLF_NoiseModel_sigmaWgtYy*/
    int32_t mf_blf_noisemodel_weight_y_y;
    /*!< mf_blf_noisemodel_weight_y_u Param_MF_BLF_NoiseModel_sigmaWgtYu*/
    int32_t mf_blf_noisemodel_weight_y_u;
    /*!< mf_blf_noisemodel_weight_y_v Param_MF_BLF_NoiseModel_sigmaWgtYv*/
    int32_t mf_blf_noisemodel_weight_y_v;
    /*!< mf_blf_noisemodel_weight_uv_y Param_MF_BLF_NoiseModel_sigmaWgtUVy*/
    int32_t mf_blf_noisemodel_weight_uv_y;
    /*!< mf_blf_noisemodel_weight_uv_u Param_MF_BLF_NoiseModel_sigmaWgtUVu*/
    int32_t mf_blf_noisemodel_weight_uv_u;
    /*!< mf_blf_noisemodel_weight_uv_v Param_MF_BLF_NoiseModel_sigmaWgtUVv*/
    int32_t mf_blf_noisemodel_weight_uv_v;
    /*!< mf_blf_noisemodel_radialdependent_bypass Param_MF_BLF_NoiseModel_bypassRadialCorrection*/
    int32_t mf_blf_noisemodel_radialdependent_bypass;
    /*!< mf_blf_noisemodel_colordependent_bypass Param_MF_BLF_NoiseModel_bypassColorDependent*/
    int32_t mf_blf_noisemodel_colordependent_bypass;
    /*!< mf_blf_noisemodel_graydependent_bypass Param_MF_BLF_NoiseModel_bypassGrayDependent*/
    int32_t mf_blf_noisemodel_graydependent_bypass;
    /*!< mf_blf_noisemodel_radialdependent_x0_square Param_MF_BLF_NoiseModel_radialDependent_x0_square*/
    int32_t mf_blf_noisemodel_radialdependent_x0_square;
    /*!< mf_blf_noisemodel_radialdependent_x0 Param_MF_BLF_NoiseModel_radialDependent_x0*/
    int32_t mf_blf_noisemodel_radialdependent_x0;
    /*!< mf_blf_noisemodel_radialdependent_y0_square Param_MF_BLF_NoiseModel_radialDependent_y0_square*/
    int32_t mf_blf_noisemodel_radialdependent_y0_square;
    /*!< mf_blf_noisemodel_radialdependent_y0 Param_MF_BLF_NoiseModel_radialDependent_y0*/
    int32_t mf_blf_noisemodel_radialdependent_y0;
    /*!< mf_blf_noisemodel_radialdependent_rshift_norm_square_distance Param_MF_BLF_NoiseModel_radialDependent_rshiftNormSquareDist*/
    int32_t mf_blf_noisemodel_radialdependent_rshift_norm_square_distance;
    /*!< mf_blf_noisemodel_radialdependent_gain_x[4] Param_MF_BLF_NoiseModel_radialDependent_radialLut_X*/
    int32_t mf_blf_noisemodel_radialdependent_gain_x[4];
    /*!< mf_blf_noisemodel_radialdependent_gain_y[3] Param_MF_BLF_NoiseModel_radialDependent_radialLut Config Unit Value*/
    int32_t mf_blf_noisemodel_radialdependent_gain_y[3];
    /*!< mf_blf_noisemodel_radialdependent_gain_slope[3] Slope*/
    int32_t mf_blf_noisemodel_radialdependent_gain_slope[3];
    /*!< mf_blf_noisemodel_colordependent_a[32] Param_MF_BLF_NoiseModel_colorDependent_A*/
    int32_t mf_blf_noisemodel_colordependent_a[32];
    /*!< mf_blf_noisemodel_colordependent_b[32] Param_MF_BLF_NoiseModel_colorDependent_B*/
    int32_t mf_blf_noisemodel_colordependent_b[32];
    /*!< mf_blf_noisemodel_colordependent_c[32] Param_MF_BLF_NoiseModel_colorDependent_C*/
    int32_t mf_blf_noisemodel_colordependent_c[32];
    /*!< mf_blf_noisemodel_colordependent_norm_offset Param_MF_BLF_NoiseModel_colorDependent_normalization_offset*/
    int32_t mf_blf_noisemodel_colordependent_norm_offset;
    /*!< mf_blf_noisemodel_colordependent_gain_x[6] Param_MF_BLF_NoiseModel_colorDependent_Lut_X*/
    int32_t mf_blf_noisemodel_colordependent_gain_x[6];
    /*!< mf_blf_noisemodel_colordependent_gain_y[5] Param_MF_BLF_NoiseModel_colorDependent_Lut Config Unit Value*/
    int32_t mf_blf_noisemodel_colordependent_gain_y[5];
    /*!< mf_blf_noisemodel_colordependent_gain_slope[5] Slope*/
    int32_t mf_blf_noisemodel_colordependent_gain_slope[5];
    /*!< mf_blf_noisemodel_graydependent_graylevel_thresh Param_MF_BLF_NoiseModel_grayDependent_grayThrsh*/
    int32_t mf_blf_noisemodel_graydependent_graylevel_thresh;
    /*!< mf_blf_noisemodel_graydependent_graylevel_slope Param_MF_BLF_NoiseModel_grayDependent_graySlope*/
    int32_t mf_blf_noisemodel_graydependent_graylevel_slope;
    /*!< mf_blf_noisemodel_graydependent_gain_x[6] Param_MF_BLF_NoiseModel_grayDependent_transLut_X*/
    int32_t mf_blf_noisemodel_graydependent_gain_x[6];
    /*!< mf_blf_noisemodel_graydependent_gain_y[5] Param_MF_BLF_NoiseModel_grayDependent_transLut Config Unit Value*/
    int32_t mf_blf_noisemodel_graydependent_gain_y[5];
    /*!< mf_blf_noisemodel_graydependent_gain_slope[5] Slope*/
    int32_t mf_blf_noisemodel_graydependent_gain_slope[5];
    /*!< mf_blf_noisemodel_normfactor_y_y Param_MF_BLF_NoiseModel_invSigmaYy*/
    int32_t mf_blf_noisemodel_normfactor_y_y;
    /*!< mf_blf_noisemodel_normfactor_y_u Param_MF_BLF_NoiseModel_invSigmaYu*/
    int32_t mf_blf_noisemodel_normfactor_y_u;
    /*!< mf_blf_noisemodel_normfactor_y_v Param_MF_BLF_NoiseModel_invSigmaYv*/
    int32_t mf_blf_noisemodel_normfactor_y_v;
    /*!< mf_blf_noisemodel_normfactor_uv_y Param_MF_BLF_NoiseModel_invSigmaUVy*/
    int32_t mf_blf_noisemodel_normfactor_uv_y;
    /*!< mf_blf_noisemodel_normfactor_uv_u Param_MF_BLF_NoiseModel_invSigmaUVu*/
    int32_t mf_blf_noisemodel_normfactor_uv_u;
    /*!< mf_blf_noisemodel_normfactor_uv_v Param_MF_BLF_NoiseModel_invSigmaUVv*/
    int32_t mf_blf_noisemodel_normfactor_uv_v;
    /*!< mf_blf_snrm_bypass Param_MF_BLF_SNRM_bypassSNRManagement*/
    int32_t mf_blf_snrm_bypass;
    /*!< mf_blf_snrm_bypass_y Param_MF_BLF_SNRM_bypassY*/
    int32_t mf_blf_snrm_bypass_y;
    /*!< mf_blf_snrm_slope_y Param_MF_BLF_SNRM_slopeY*/
    int32_t mf_blf_snrm_slope_y;
    /*!< mf_blf_snrm_xoffset_y Param_MF_BLF_SNRM_xoffsetY*/
    int32_t mf_blf_snrm_xoffset_y;
    /*!< mf_blf_snrm_maxval_y Param_MF_BLF_SNRM_maxValY*/
    int32_t mf_blf_snrm_maxval_y;
    /*!< mf_blf_snrm_minval_y Param_MF_BLF_SNRM_minValY*/
    int32_t mf_blf_snrm_minval_y;
    /*!< mf_blf_snrm_slope_uv Param_MF_BLF_SNRM_slopeUV*/
    int32_t mf_blf_snrm_slope_uv;
    /*!< mf_blf_snrm_xoffset_uv Param_MF_BLF_SNRM_xoffsetUV*/
    int32_t mf_blf_snrm_xoffset_uv;
    /*!< mf_blf_snrm_maxval_uv Param_MF_BLF_SNRM_maxValUV*/
    int32_t mf_blf_snrm_maxval_uv;
    /*!< mf_blf_snrm_minval_uv Param_MF_BLF_SNRM_minValUV*/
    int32_t mf_blf_snrm_minval_uv;
    /*!< mf_afc_bypass Param_MF_AFC_bypassAntiFalseColor*/
    int32_t mf_afc_bypass;
    /*!< mf_afc_weight_snr Param_MF_AFC_wgtSnr*/
    int32_t mf_afc_weight_snr;
    /*!< mf_afc_weight_chroma Param_MF_AFC_wgtC*/
    int32_t mf_afc_weight_chroma;
    /*!< mf_min_distance_clamp Param_MF_min_distance_clamp*/
    int32_t mf_min_distance_clamp;
    /*!< lf_blf_fir_filter_length Param_LF_BLF_FIR_BfLen*/
    int32_t lf_blf_fir_filter_length;
    /*!< lf_blf_fir_luma_coefs[6] Param_LF_BLF_FIR_Kn_coef*/
    int32_t lf_blf_fir_luma_coefs[6];
    /*!< lf_blf_fir_luma_denom_bits Param_LF_BLF_FIR_Kn_denom_bits*/
    int32_t lf_blf_fir_luma_denom_bits;
    /*!< lf_blf_fir_bypass_snr_y Param_LF_BLF_FIR_bypasssSnrY*/
    int32_t lf_blf_fir_bypass_snr_y;
    /*!< lf_blf_colorspace Param_LF_BLF_colorspaceYRB*/
    int32_t lf_blf_colorspace;
    /*!< lf_blf_noisemodel_basefunc_y_a_x[5] Param_LF_BLF_NoiseModel_sigmaParafacY_A_X*/
    int32_t lf_blf_noisemodel_basefunc_y_a_x[5];
    /*!< lf_blf_noisemodel_basefunc_y_a_y[4] Param_LF_BLF_NoiseModel_sigmaParafacY_A Config Unit Value*/
    int32_t lf_blf_noisemodel_basefunc_y_a_y[4];
    /*!< lf_blf_noisemodel_basefunc_y_a_slope[4] Slope*/
    int32_t lf_blf_noisemodel_basefunc_y_a_slope[4];
    /*!< lf_blf_noisemodel_basefunc_y_b_x[5] Param_LF_BLF_NoiseModel_sigmaParafacY_B_X*/
    int32_t lf_blf_noisemodel_basefunc_y_b_x[5];
    /*!< lf_blf_noisemodel_basefunc_y_b_y[4] Param_LF_BLF_NoiseModel_sigmaParafacY_B Config Unit Value*/
    int32_t lf_blf_noisemodel_basefunc_y_b_y[4];
    /*!< lf_blf_noisemodel_basefunc_y_b_slope[4] Slope*/
    int32_t lf_blf_noisemodel_basefunc_y_b_slope[4];
    /*!< lf_blf_noisemodel_basefunc_y_c_x[5] Param_LF_BLF_NoiseModel_sigmaParafacY_C_X*/
    int32_t lf_blf_noisemodel_basefunc_y_c_x[5];
    /*!< lf_blf_noisemodel_basefunc_y_c_y[4] Param_LF_BLF_NoiseModel_sigmaParafacY_C Config Unit Value*/
    int32_t lf_blf_noisemodel_basefunc_y_c_y[4];
    /*!< lf_blf_noisemodel_basefunc_y_c_slope[4] Slope*/
    int32_t lf_blf_noisemodel_basefunc_y_c_slope[4];
    /*!< lf_blf_noisemodel_basefunc_y_wbg Param_LF_BLF_NoiseModel_sigmaParafacY_DEF*/
    int32_t lf_blf_noisemodel_basefunc_y_wbg;
    /*!< lf_blf_noisemodel_basefunc_u_a_x[5] Param_LF_BLF_NoiseModel_sigmaParafacU_A_X*/
    int32_t lf_blf_noisemodel_basefunc_u_a_x[5];
    /*!< lf_blf_noisemodel_basefunc_u_a_y[4] Param_LF_BLF_NoiseModel_sigmaParafacU_A Config Unit Value*/
    int32_t lf_blf_noisemodel_basefunc_u_a_y[4];
    /*!< lf_blf_noisemodel_basefunc_u_a_slope[4] Slope*/
    int32_t lf_blf_noisemodel_basefunc_u_a_slope[4];
    /*!< lf_blf_noisemodel_basefunc_u_b_x[5] Param_LF_BLF_NoiseModel_sigmaParafacU_B_X*/
    int32_t lf_blf_noisemodel_basefunc_u_b_x[5];
    /*!< lf_blf_noisemodel_basefunc_u_b_y[4] Param_LF_BLF_NoiseModel_sigmaParafacU_B Config Unit Value*/
    int32_t lf_blf_noisemodel_basefunc_u_b_y[4];
    /*!< lf_blf_noisemodel_basefunc_u_b_slope[4] Slope*/
    int32_t lf_blf_noisemodel_basefunc_u_b_slope[4];
    /*!< lf_blf_noisemodel_basefunc_u_c_x[5] Param_LF_BLF_NoiseModel_sigmaParafacU_C_X*/
    int32_t lf_blf_noisemodel_basefunc_u_c_x[5];
    /*!< lf_blf_noisemodel_basefunc_u_c_y[4] Param_LF_BLF_NoiseModel_sigmaParafacU_C Config Unit Value*/
    int32_t lf_blf_noisemodel_basefunc_u_c_y[4];
    /*!< lf_blf_noisemodel_basefunc_u_c_slope[4] Slope*/
    int32_t lf_blf_noisemodel_basefunc_u_c_slope[4];
    /*!< lf_blf_noisemodel_basefunc_u_wbg Param_LF_BLF_NoiseModel_sigmaParafacU_DEF*/
    int32_t lf_blf_noisemodel_basefunc_u_wbg;
    /*!< lf_blf_noisemodel_basefunc_v_a_x[5] Param_LF_BLF_NoiseModel_sigmaParafacV_A_X*/
    int32_t lf_blf_noisemodel_basefunc_v_a_x[5];
    /*!< lf_blf_noisemodel_basefunc_v_a_y[4] Param_LF_BLF_NoiseModel_sigmaParafacV_A Config Unit Value*/
    int32_t lf_blf_noisemodel_basefunc_v_a_y[4];
    /*!< lf_blf_noisemodel_basefunc_v_a_slope[4] Slope*/
    int32_t lf_blf_noisemodel_basefunc_v_a_slope[4];
    /*!< lf_blf_noisemodel_basefunc_v_b_x[5] Param_LF_BLF_NoiseModel_sigmaParafacV_B_X*/
    int32_t lf_blf_noisemodel_basefunc_v_b_x[5];
    /*!< lf_blf_noisemodel_basefunc_v_b_y[4] Param_LF_BLF_NoiseModel_sigmaParafacV_B Config Unit Value*/
    int32_t lf_blf_noisemodel_basefunc_v_b_y[4];
    /*!< lf_blf_noisemodel_basefunc_v_b_slope[4] Slope*/
    int32_t lf_blf_noisemodel_basefunc_v_b_slope[4];
    /*!< lf_blf_noisemodel_basefunc_v_c_x[5] Param_LF_BLF_NoiseModel_sigmaParafacV_C_X*/
    int32_t lf_blf_noisemodel_basefunc_v_c_x[5];
    /*!< lf_blf_noisemodel_basefunc_v_c_y[4] Param_LF_BLF_NoiseModel_sigmaParafacV_C Config Unit Value*/
    int32_t lf_blf_noisemodel_basefunc_v_c_y[4];
    /*!< lf_blf_noisemodel_basefunc_v_c_slope[4] Slope*/
    int32_t lf_blf_noisemodel_basefunc_v_c_slope[4];
    /*!< lf_blf_noisemodel_basefunc_v_wbg Param_LF_BLF_NoiseModel_sigmaParafacV_DEF*/
    int32_t lf_blf_noisemodel_basefunc_v_wbg;
    /*!< lf_blf_noisemodel_weight_y_y Param_LF_BLF_NoiseModel_sigmaWgtYy*/
    int32_t lf_blf_noisemodel_weight_y_y;
    /*!< lf_blf_noisemodel_weight_y_u Param_LF_BLF_NoiseModel_sigmaWgtYu*/
    int32_t lf_blf_noisemodel_weight_y_u;
    /*!< lf_blf_noisemodel_weight_y_v Param_LF_BLF_NoiseModel_sigmaWgtYv*/
    int32_t lf_blf_noisemodel_weight_y_v;
    /*!< lf_blf_noisemodel_weight_uv_y Param_LF_BLF_NoiseModel_sigmaWgtUVy*/
    int32_t lf_blf_noisemodel_weight_uv_y;
    /*!< lf_blf_noisemodel_weight_uv_u Param_LF_BLF_NoiseModel_sigmaWgtUVu*/
    int32_t lf_blf_noisemodel_weight_uv_u;
    /*!< lf_blf_noisemodel_weight_uv_v Param_LF_BLF_NoiseModel_sigmaWgtUVv*/
    int32_t lf_blf_noisemodel_weight_uv_v;
    /*!< lf_blf_noisemodel_radialdependent_bypass Param_LF_BLF_NoiseModel_bypassRadialCorrection*/
    int32_t lf_blf_noisemodel_radialdependent_bypass;
    /*!< lf_blf_noisemodel_colordependent_bypass Param_LF_BLF_NoiseModel_bypassColorDependent*/
    int32_t lf_blf_noisemodel_colordependent_bypass;
    /*!< lf_blf_noisemodel_graydependent_bypass Param_LF_BLF_NoiseModel_bypassGrayDependent*/
    int32_t lf_blf_noisemodel_graydependent_bypass;
    /*!< lf_blf_noisemodel_radialdependent_x0_square Param_LF_BLF_NoiseModel_radialDependent_x0_square*/
    int32_t lf_blf_noisemodel_radialdependent_x0_square;
    /*!< lf_blf_noisemodel_radialdependent_x0 Param_LF_BLF_NoiseModel_radialDependent_x0*/
    int32_t lf_blf_noisemodel_radialdependent_x0;
    /*!< lf_blf_noisemodel_radialdependent_y0_square Param_LF_BLF_NoiseModel_radialDependent_y0_square*/
    int32_t lf_blf_noisemodel_radialdependent_y0_square;
    /*!< lf_blf_noisemodel_radialdependent_y0 Param_LF_BLF_NoiseModel_radialDependent_y0*/
    int32_t lf_blf_noisemodel_radialdependent_y0;
    /*!< lf_blf_noisemodel_radialdependent_rshift_norm_square_distance Param_LF_BLF_NoiseModel_radialDependent_rshiftNormSquareDist*/
    int32_t lf_blf_noisemodel_radialdependent_rshift_norm_square_distance;
    /*!< lf_blf_noisemodel_radialdependent_gain_x[4] Param_LF_BLF_NoiseModel_radialDependent_radialLut_X*/
    int32_t lf_blf_noisemodel_radialdependent_gain_x[4];
    /*!< lf_blf_noisemodel_radialdependent_gain_y[3] Param_LF_BLF_NoiseModel_radialDependent_radialLut Config Unit Value*/
    int32_t lf_blf_noisemodel_radialdependent_gain_y[3];
    /*!< lf_blf_noisemodel_radialdependent_gain_slope[3] Slope*/
    int32_t lf_blf_noisemodel_radialdependent_gain_slope[3];
    /*!< lf_blf_noisemodel_colordependent_a[32] Param_LF_BLF_NoiseModel_colorDependent_A*/
    int32_t lf_blf_noisemodel_colordependent_a[32];
    /*!< lf_blf_noisemodel_colordependent_b[32] Param_LF_BLF_NoiseModel_colorDependent_B*/
    int32_t lf_blf_noisemodel_colordependent_b[32];
    /*!< lf_blf_noisemodel_colordependent_c[32] Param_LF_BLF_NoiseModel_colorDependent_C*/
    int32_t lf_blf_noisemodel_colordependent_c[32];
    /*!< lf_blf_noisemodel_colordependent_norm_offset Param_LF_BLF_NoiseModel_colorDependent_normalization_offset*/
    int32_t lf_blf_noisemodel_colordependent_norm_offset;
    /*!< lf_blf_noisemodel_colordependent_gain_x[6] Param_LF_BLF_NoiseModel_colorDependent_Lut_X*/
    int32_t lf_blf_noisemodel_colordependent_gain_x[6];
    /*!< lf_blf_noisemodel_colordependent_gain_y[5] Param_LF_BLF_NoiseModel_colorDependent_Lut Config Unit Value*/
    int32_t lf_blf_noisemodel_colordependent_gain_y[5];
    /*!< lf_blf_noisemodel_colordependent_gain_slope[5] Slope*/
    int32_t lf_blf_noisemodel_colordependent_gain_slope[5];
    /*!< lf_blf_noisemodel_graydependent_graylevel_thresh Param_LF_BLF_NoiseModel_grayDependent_grayThrsh*/
    int32_t lf_blf_noisemodel_graydependent_graylevel_thresh;
    /*!< lf_blf_noisemodel_graydependent_graylevel_slope Param_LF_BLF_NoiseModel_grayDependent_graySlope*/
    int32_t lf_blf_noisemodel_graydependent_graylevel_slope;
    /*!< lf_blf_noisemodel_graydependent_gain_x[6] Param_LF_BLF_NoiseModel_grayDependent_transLut_X*/
    int32_t lf_blf_noisemodel_graydependent_gain_x[6];
    /*!< lf_blf_noisemodel_graydependent_gain_y[5] Param_LF_BLF_NoiseModel_grayDependent_transLut Config Unit Value*/
    int32_t lf_blf_noisemodel_graydependent_gain_y[5];
    /*!< lf_blf_noisemodel_graydependent_gain_slope[5] Slope*/
    int32_t lf_blf_noisemodel_graydependent_gain_slope[5];
    /*!< lf_blf_noisemodel_normfactor_y_y Param_LF_BLF_NoiseModel_invSigmaYy*/
    int32_t lf_blf_noisemodel_normfactor_y_y;
    /*!< lf_blf_noisemodel_normfactor_y_u Param_LF_BLF_NoiseModel_invSigmaYu*/
    int32_t lf_blf_noisemodel_normfactor_y_u;
    /*!< lf_blf_noisemodel_normfactor_y_v Param_LF_BLF_NoiseModel_invSigmaYv*/
    int32_t lf_blf_noisemodel_normfactor_y_v;
    /*!< lf_blf_noisemodel_normfactor_uv_y Param_LF_BLF_NoiseModel_invSigmaUVy*/
    int32_t lf_blf_noisemodel_normfactor_uv_y;
    /*!< lf_blf_noisemodel_normfactor_uv_u Param_LF_BLF_NoiseModel_invSigmaUVu*/
    int32_t lf_blf_noisemodel_normfactor_uv_u;
    /*!< lf_blf_noisemodel_normfactor_uv_v Param_LF_BLF_NoiseModel_invSigmaUVv*/
    int32_t lf_blf_noisemodel_normfactor_uv_v;
    /*!< lf_blf_snrm_bypass Param_LF_BLF_SNRM_bypassSNRManagement*/
    int32_t lf_blf_snrm_bypass;
    /*!< lf_blf_snrm_bypass_y Param_LF_BLF_SNRM_bypassY*/
    int32_t lf_blf_snrm_bypass_y;
    /*!< lf_blf_snrm_slope_y Param_LF_BLF_SNRM_slopeY*/
    int32_t lf_blf_snrm_slope_y;
    /*!< lf_blf_snrm_xoffset_y Param_LF_BLF_SNRM_xoffsetY*/
    int32_t lf_blf_snrm_xoffset_y;
    /*!< lf_blf_snrm_maxval_y Param_LF_BLF_SNRM_maxValY*/
    int32_t lf_blf_snrm_maxval_y;
    /*!< lf_blf_snrm_minval_y Param_LF_BLF_SNRM_minValY*/
    int32_t lf_blf_snrm_minval_y;
    /*!< lf_blf_snrm_slope_uv Param_LF_BLF_SNRM_slopeUV*/
    int32_t lf_blf_snrm_slope_uv;
    /*!< lf_blf_snrm_xoffset_uv Param_LF_BLF_SNRM_xoffsetUV*/
    int32_t lf_blf_snrm_xoffset_uv;
    /*!< lf_blf_snrm_maxval_uv Param_LF_BLF_SNRM_maxValUV*/
    int32_t lf_blf_snrm_maxval_uv;
    /*!< lf_blf_snrm_minval_uv Param_LF_BLF_SNRM_minValUV*/
    int32_t lf_blf_snrm_minval_uv;
    /*!< lf_blf_iir_alpha_y Param_LF_BLF_IIR_alphaY*/
    int32_t lf_blf_iir_alpha_y;
    /*!< lf_blf_iir_alpha_uv Param_LF_BLF_IIR_alphaUV*/
    int32_t lf_blf_iir_alpha_uv;
    /*!< lf_cs_bypass Param_LF_CS_bypassChromaSuppression*/
    int32_t lf_cs_bypass;
    /*!< lf_cs_coef Param_LF_CS_coef*/
    int32_t lf_cs_coef;
    /*!< lf_min_distance_clamp Param_LF_min_distance_clamp*/
    int32_t lf_min_distance_clamp;
    /*!< vlf_blf_fir_filter_length Param_VLF_BLF_FIR_BfLen*/
    int32_t vlf_blf_fir_filter_length;
    /*!< vlf_blf_fir_luma_coefs[6] Param_VLF_BLF_FIR_Kn_coef*/
    int32_t vlf_blf_fir_luma_coefs[6];
    /*!< vlf_blf_fir_luma_denom_bits Param_VLF_BLF_FIR_Kn_denom_bits*/
    int32_t vlf_blf_fir_luma_denom_bits;
    /*!< vlf_blf_fir_bypass_snr_y Param_VLF_BLF_FIR_bypasssSnrY*/
    int32_t vlf_blf_fir_bypass_snr_y;
    /*!< vlf_blf_colorspace Param_VLF_BLF_colorspaceYRB*/
    int32_t vlf_blf_colorspace;
    /*!< vlf_blf_noisemodel_basefunc_y_a_x[5] Param_VLF_BLF_NoiseModel_sigmaParafacY_A_X*/
    int32_t vlf_blf_noisemodel_basefunc_y_a_x[5];
    /*!< vlf_blf_noisemodel_basefunc_y_a_y[4] Param_VLF_BLF_NoiseModel_sigmaParafacY_A Config Unit Value*/
    int32_t vlf_blf_noisemodel_basefunc_y_a_y[4];
    /*!< vlf_blf_noisemodel_basefunc_y_a_slope[4] Slope*/
    int32_t vlf_blf_noisemodel_basefunc_y_a_slope[4];
    /*!< vlf_blf_noisemodel_basefunc_y_b_x[5] Param_VLF_BLF_NoiseModel_sigmaParafacY_B_X*/
    int32_t vlf_blf_noisemodel_basefunc_y_b_x[5];
    /*!< vlf_blf_noisemodel_basefunc_y_b_y[4] Param_VLF_BLF_NoiseModel_sigmaParafacY_B Config Unit Value*/
    int32_t vlf_blf_noisemodel_basefunc_y_b_y[4];
    /*!< vlf_blf_noisemodel_basefunc_y_b_slope[4] Slope*/
    int32_t vlf_blf_noisemodel_basefunc_y_b_slope[4];
    /*!< vlf_blf_noisemodel_basefunc_y_c_x[5] Param_VLF_BLF_NoiseModel_sigmaParafacY_C_X*/
    int32_t vlf_blf_noisemodel_basefunc_y_c_x[5];
    /*!< vlf_blf_noisemodel_basefunc_y_c_y[4] Param_VLF_BLF_NoiseModel_sigmaParafacY_C Config Unit Value*/
    int32_t vlf_blf_noisemodel_basefunc_y_c_y[4];
    /*!< vlf_blf_noisemodel_basefunc_y_c_slope[4] Slope*/
    int32_t vlf_blf_noisemodel_basefunc_y_c_slope[4];
    /*!< vlf_blf_noisemodel_basefunc_y_wbg Param_VLF_BLF_NoiseModel_sigmaParafacY_DEF*/
    int32_t vlf_blf_noisemodel_basefunc_y_wbg;
    /*!< vlf_blf_noisemodel_basefunc_u_a_x[5] Param_VLF_BLF_NoiseModel_sigmaParafacU_A_X*/
    int32_t vlf_blf_noisemodel_basefunc_u_a_x[5];
    /*!< vlf_blf_noisemodel_basefunc_u_a_y[4] Param_VLF_BLF_NoiseModel_sigmaParafacU_A Config Unit Value*/
    int32_t vlf_blf_noisemodel_basefunc_u_a_y[4];
    /*!< vlf_blf_noisemodel_basefunc_u_a_slope[4] Slope*/
    int32_t vlf_blf_noisemodel_basefunc_u_a_slope[4];
    /*!< vlf_blf_noisemodel_basefunc_u_b_x[5] Param_VLF_BLF_NoiseModel_sigmaParafacU_B_X*/
    int32_t vlf_blf_noisemodel_basefunc_u_b_x[5];
    /*!< vlf_blf_noisemodel_basefunc_u_b_y[4] Param_VLF_BLF_NoiseModel_sigmaParafacU_B Config Unit Value*/
    int32_t vlf_blf_noisemodel_basefunc_u_b_y[4];
    /*!< vlf_blf_noisemodel_basefunc_u_b_slope[4] Slope*/
    int32_t vlf_blf_noisemodel_basefunc_u_b_slope[4];
    /*!< vlf_blf_noisemodel_basefunc_u_c_x[5] Param_VLF_BLF_NoiseModel_sigmaParafacU_C_X*/
    int32_t vlf_blf_noisemodel_basefunc_u_c_x[5];
    /*!< vlf_blf_noisemodel_basefunc_u_c_y[4] Param_VLF_BLF_NoiseModel_sigmaParafacU_C Config Unit Value*/
    int32_t vlf_blf_noisemodel_basefunc_u_c_y[4];
    /*!< vlf_blf_noisemodel_basefunc_u_c_slope[4] Slope*/
    int32_t vlf_blf_noisemodel_basefunc_u_c_slope[4];
    /*!< vlf_blf_noisemodel_basefunc_u_wbg Param_VLF_BLF_NoiseModel_sigmaParafacU_DEF*/
    int32_t vlf_blf_noisemodel_basefunc_u_wbg;
    /*!< vlf_blf_noisemodel_basefunc_v_a_x[5] Param_VLF_BLF_NoiseModel_sigmaParafacV_A_X*/
    int32_t vlf_blf_noisemodel_basefunc_v_a_x[5];
    /*!< vlf_blf_noisemodel_basefunc_v_a_y[4] Param_VLF_BLF_NoiseModel_sigmaParafacV_A Config Unit Value*/
    int32_t vlf_blf_noisemodel_basefunc_v_a_y[4];
    /*!< vlf_blf_noisemodel_basefunc_v_a_slope[4] Slope*/
    int32_t vlf_blf_noisemodel_basefunc_v_a_slope[4];
    /*!< vlf_blf_noisemodel_basefunc_v_b_x[5] Param_VLF_BLF_NoiseModel_sigmaParafacV_B_X*/
    int32_t vlf_blf_noisemodel_basefunc_v_b_x[5];
    /*!< vlf_blf_noisemodel_basefunc_v_b_y[4] Param_VLF_BLF_NoiseModel_sigmaParafacV_B Config Unit Value*/
    int32_t vlf_blf_noisemodel_basefunc_v_b_y[4];
    /*!< vlf_blf_noisemodel_basefunc_v_b_slope[4] Slope*/
    int32_t vlf_blf_noisemodel_basefunc_v_b_slope[4];
    /*!< vlf_blf_noisemodel_basefunc_v_c_x[5] Param_VLF_BLF_NoiseModel_sigmaParafacV_C_X*/
    int32_t vlf_blf_noisemodel_basefunc_v_c_x[5];
    /*!< vlf_blf_noisemodel_basefunc_v_c_y[4] Param_VLF_BLF_NoiseModel_sigmaParafacV_C Config Unit Value*/
    int32_t vlf_blf_noisemodel_basefunc_v_c_y[4];
    /*!< vlf_blf_noisemodel_basefunc_v_c_slope[4] Slope*/
    int32_t vlf_blf_noisemodel_basefunc_v_c_slope[4];
    /*!< vlf_blf_noisemodel_basefunc_v_wbg Param_VLF_BLF_NoiseModel_sigmaParafacV_DEF*/
    int32_t vlf_blf_noisemodel_basefunc_v_wbg;
    /*!< vlf_blf_noisemodel_weight_y_y Param_VLF_BLF_NoiseModel_sigmaWgtYy*/
    int32_t vlf_blf_noisemodel_weight_y_y;
    /*!< vlf_blf_noisemodel_weight_y_u Param_VLF_BLF_NoiseModel_sigmaWgtYu*/
    int32_t vlf_blf_noisemodel_weight_y_u;
    /*!< vlf_blf_noisemodel_weight_y_v Param_VLF_BLF_NoiseModel_sigmaWgtYv*/
    int32_t vlf_blf_noisemodel_weight_y_v;
    /*!< vlf_blf_noisemodel_weight_uv_y Param_VLF_BLF_NoiseModel_sigmaWgtUVy*/
    int32_t vlf_blf_noisemodel_weight_uv_y;
    /*!< vlf_blf_noisemodel_weight_uv_u Param_VLF_BLF_NoiseModel_sigmaWgtUVu*/
    int32_t vlf_blf_noisemodel_weight_uv_u;
    /*!< vlf_blf_noisemodel_weight_uv_v Param_VLF_BLF_NoiseModel_sigmaWgtUVv*/
    int32_t vlf_blf_noisemodel_weight_uv_v;
    /*!< vlf_blf_noisemodel_radialdependent_bypass Param_VLF_BLF_NoiseModel_bypassRadialCorrection*/
    int32_t vlf_blf_noisemodel_radialdependent_bypass;
    /*!< vlf_blf_noisemodel_colordependent_bypass Param_VLF_BLF_NoiseModel_bypassColorDependent*/
    int32_t vlf_blf_noisemodel_colordependent_bypass;
    /*!< vlf_blf_noisemodel_radialdependent_x0_square Param_VLF_BLF_NoiseModel_radialDependent_x0_square*/
    int32_t vlf_blf_noisemodel_radialdependent_x0_square;
    /*!< vlf_blf_noisemodel_radialdependent_x0 Param_VLF_BLF_NoiseModel_radialDependent_x0*/
    int32_t vlf_blf_noisemodel_radialdependent_x0;
    /*!< vlf_blf_noisemodel_radialdependent_y0_square Param_VLF_BLF_NoiseModel_radialDependent_y0_square*/
    int32_t vlf_blf_noisemodel_radialdependent_y0_square;
    /*!< vlf_blf_noisemodel_radialdependent_y0 Param_VLF_BLF_NoiseModel_radialDependent_y0*/
    int32_t vlf_blf_noisemodel_radialdependent_y0;
    /*!< vlf_blf_noisemodel_radialdependent_rshift_norm_square_distance Param_VLF_BLF_NoiseModel_radialDependent_rshiftNormSquareDist*/
    int32_t vlf_blf_noisemodel_radialdependent_rshift_norm_square_distance;
    /*!< vlf_blf_noisemodel_radialdependent_gain_x[4] Param_VLF_BLF_NoiseModel_radialDependent_radialLut_X*/
    int32_t vlf_blf_noisemodel_radialdependent_gain_x[4];
    /*!< vlf_blf_noisemodel_radialdependent_gain_y[3] Param_VLF_BLF_NoiseModel_radialDependent_radialLut Config Unit Value*/
    int32_t vlf_blf_noisemodel_radialdependent_gain_y[3];
    /*!< vlf_blf_noisemodel_radialdependent_gain_slope[3] Slope*/
    int32_t vlf_blf_noisemodel_radialdependent_gain_slope[3];
    /*!< vlf_blf_noisemodel_colordependent_a[32] Param_VLF_BLF_NoiseModel_colorDependent_A*/
    int32_t vlf_blf_noisemodel_colordependent_a[32];
    /*!< vlf_blf_noisemodel_colordependent_b[32] Param_VLF_BLF_NoiseModel_colorDependent_B*/
    int32_t vlf_blf_noisemodel_colordependent_b[32];
    /*!< vlf_blf_noisemodel_colordependent_c[32] Param_VLF_BLF_NoiseModel_colorDependent_C*/
    int32_t vlf_blf_noisemodel_colordependent_c[32];
    /*!< vlf_blf_noisemodel_colordependent_norm_offset Param_VLF_BLF_NoiseModel_colorDependent_normalization_offset*/
    int32_t vlf_blf_noisemodel_colordependent_norm_offset;
    /*!< vlf_blf_noisemodel_colordependent_gain_x[6] Param_VLF_BLF_NoiseModel_colorDependent_Lut_X*/
    int32_t vlf_blf_noisemodel_colordependent_gain_x[6];
    /*!< vlf_blf_noisemodel_colordependent_gain_y[5] Param_VLF_BLF_NoiseModel_colorDependent_Lut Config Unit Value*/
    int32_t vlf_blf_noisemodel_colordependent_gain_y[5];
    /*!< vlf_blf_noisemodel_colordependent_gain_slope[5] Slope*/
    int32_t vlf_blf_noisemodel_colordependent_gain_slope[5];
    /*!< vlf_blf_noisemodel_graydependent_gain_x[6] Param_VLF_BLF_NoiseModel_grayDependent_transLut_X*/
    int32_t vlf_blf_noisemodel_graydependent_gain_x[6];
    /*!< vlf_blf_noisemodel_graydependent_gain_y[5] Param_VLF_BLF_NoiseModel_grayDependent_transLut Config Unit Value*/
    int32_t vlf_blf_noisemodel_graydependent_gain_y[5];
    /*!< vlf_blf_noisemodel_graydependent_gain_slope[5] Slope*/
    int32_t vlf_blf_noisemodel_graydependent_gain_slope[5];
    /*!< vlf_blf_noisemodel_normfactor_y_y Param_VLF_BLF_NoiseModel_invSigmaYy*/
    int32_t vlf_blf_noisemodel_normfactor_y_y;
    /*!< vlf_blf_noisemodel_normfactor_y_u Param_VLF_BLF_NoiseModel_invSigmaYu*/
    int32_t vlf_blf_noisemodel_normfactor_y_u;
    /*!< vlf_blf_noisemodel_normfactor_y_v Param_VLF_BLF_NoiseModel_invSigmaYv*/
    int32_t vlf_blf_noisemodel_normfactor_y_v;
    /*!< vlf_blf_noisemodel_normfactor_uv_y Param_VLF_BLF_NoiseModel_invSigmaUVy*/
    int32_t vlf_blf_noisemodel_normfactor_uv_y;
    /*!< vlf_blf_noisemodel_normfactor_uv_u Param_VLF_BLF_NoiseModel_invSigmaUVu*/
    int32_t vlf_blf_noisemodel_normfactor_uv_u;
    /*!< vlf_blf_noisemodel_normfactor_uv_v Param_VLF_BLF_NoiseModel_invSigmaUVv*/
    int32_t vlf_blf_noisemodel_normfactor_uv_v;
    /*!< vlf_blf_iir_alpha_y Param_VLF_BLF_IIR_alphaY*/
    int32_t vlf_blf_iir_alpha_y;
    /*!< vlf_blf_iir_alpha_uv Param_VLF_BLF_IIR_alphaUV*/
    int32_t vlf_blf_iir_alpha_uv;
    /*!< vlf_cs_bypass Param_VLF_CS_bypassChromaSuppression*/
    int32_t vlf_cs_bypass;
    /*!< vlf_cs_coef Param_VLF_CS_coef*/
    int32_t vlf_cs_coef;
    /*!< vlf_min_distance_clamp Param_VLF_min_distance_clamp*/
    int32_t vlf_min_distance_clamp;
    /*!< vhf_blf_noisemodel_basefunc_y_a_x[5] Param_VHF_BLF_NoiseModel_sigmaParafacY_A_X*/
    int32_t vhf_blf_noisemodel_basefunc_y_a_x[5];
    /*!< vhf_blf_noisemodel_basefunc_y_a_y[4] Param_VHF_BLF_NoiseModel_sigmaParafacY_A Config Unit Value*/
    int32_t vhf_blf_noisemodel_basefunc_y_a_y[4];
    /*!< vhf_blf_noisemodel_basefunc_y_a_slope[4] Slope*/
    int32_t vhf_blf_noisemodel_basefunc_y_a_slope[4];
    /*!< vhf_blf_noisemodel_basefunc_y_wbg Param_VHF_BLF_NoiseModel_sigmaParafacY_DEF*/
    int32_t vhf_blf_noisemodel_basefunc_y_wbg;
    /*!< vhf_blf_noisemodel_weight_y_y Param_VHF_BLF_NoiseModel_sigmaWgtYy*/
    int32_t vhf_blf_noisemodel_weight_y_y;
    /*!< vhf_blf_noisemodel_radialdependent_bypass Param_VHF_BLF_NoiseModel_bypassRadialCorrection*/
    int32_t vhf_blf_noisemodel_radialdependent_bypass;
    /*!< vhf_blf_noisemodel_radialdependent_x0_square Param_VHF_BLF_NoiseModel_radialDependent_x0_square*/
    int32_t vhf_blf_noisemodel_radialdependent_x0_square;
    /*!< vhf_blf_noisemodel_radialdependent_x0 Param_VHF_BLF_NoiseModel_radialDependent_x0*/
    int32_t vhf_blf_noisemodel_radialdependent_x0;
    /*!< vhf_blf_noisemodel_radialdependent_y0_square Param_VHF_BLF_NoiseModel_radialDependent_y0_square*/
    int32_t vhf_blf_noisemodel_radialdependent_y0_square;
    /*!< vhf_blf_noisemodel_radialdependent_y0 Param_VHF_BLF_NoiseModel_radialDependent_y0*/
    int32_t vhf_blf_noisemodel_radialdependent_y0;
    /*!< vhf_blf_noisemodel_radialdependent_rshift_norm_square_distance Param_VHF_BLF_NoiseModel_radialDependent_rshiftNormSquareDist*/
    int32_t vhf_blf_noisemodel_radialdependent_rshift_norm_square_distance;
    /*!< vhf_blf_noisemodel_radialdependent_gain_x[4] Param_VHF_BLF_NoiseModel_radialDependent_radialLut_X*/
    int32_t vhf_blf_noisemodel_radialdependent_gain_x[4];
    /*!< vhf_blf_noisemodel_radialdependent_gain_y[3] Param_VHF_BLF_NoiseModel_radialDependent_radialLut Config Unit Value*/
    int32_t vhf_blf_noisemodel_radialdependent_gain_y[3];
    /*!< vhf_blf_noisemodel_radialdependent_gain_slope[3] Slope*/
    int32_t vhf_blf_noisemodel_radialdependent_gain_slope[3];
    /*!< vhf_blf_noisemodel_normfactor_y_y Param_VHF_BLF_NoiseModel_invSigmaYy*/
    int32_t vhf_blf_noisemodel_normfactor_y_y;
    /*!< vhf_blf_bypass Param_VHF_BLF_bypass*/
    int32_t vhf_blf_bypass;
    /*!< vhf_min_distance_clamp Param_VHF_min_distance_clamp*/
    int32_t vhf_min_distance_clamp;

} ia_pal_isp_xnr_5_1_t;

/*! \isp struct xnr_5_2
Low Frequency Chroma Denoiser
*/
typedef struct
{
    /*!< top_frame_width XNR5 input frame width*/
    int32_t top_frame_width;
    /*!< top_frame_height XNR5 input frame height*/
    int32_t top_frame_height;
    /*!< top_xnr_bypass Bypass entire xnr*/
    int32_t top_xnr_bypass;
    /*!< vhf_frame_width XNR5 input frame width*/
    int32_t vhf_frame_width;
    /*!< vhf_frame_height XNR5 input frame height*/
    int32_t vhf_frame_height;
    /*!< vhf_low_band_disable Lower band is disabled and zero on inputs*/
    int32_t vhf_low_band_disable;
    /*!< vhf_low_band_only Lower band directly goes to output and other inputs are zeroes*/
    int32_t vhf_low_band_only;
    /*!< hf_frame_width XNR5 input frame width*/
    int32_t hf_frame_width;
    /*!< hf_frame_height XNR5 input frame height*/
    int32_t hf_frame_height;
    /*!< hf_low_band_disable Lower band is disabled and zero on inputs*/
    int32_t hf_low_band_disable;
    /*!< hf_low_band_only Lower band directly goes to output and other inputs are zeroes*/
    int32_t hf_low_band_only;
    /*!< hf_nr_bypass Input YUV goes directly to output after vertical delay*/
    int32_t hf_nr_bypass;
    /*!< hf_se_bypass Replace all SE outputs with se_bypass_val*/
    int32_t hf_se_bypass;
    /*!< hf_se_bypass_val SE bypass value*/
    int32_t hf_se_bypass_val;
    /*!< mf_frame_width XNR5 input frame width*/
    int32_t mf_frame_width;
    /*!< mf_frame_height XNR5 input frame height*/
    int32_t mf_frame_height;
    /*!< mf_low_band_disable Lower band is disabled and zero on inputs*/
    int32_t mf_low_band_disable;
    /*!< mf_low_band_only Lower band directly goes to output and other inputs are zeroes*/
    int32_t mf_low_band_only;
    /*!< mf_nr_bypass Input YUV goes directly to output after vertical delay*/
    int32_t mf_nr_bypass;
    /*!< mf_se_bypass Replace all SE outputs with se_bypass_val*/
    int32_t mf_se_bypass;
    /*!< mf_se_bypass_val SE bypass value*/
    int32_t mf_se_bypass_val;
    /*!< lf_frame_width XNR5 input frame width*/
    int32_t lf_frame_width;
    /*!< lf_frame_height XNR5 input frame height*/
    int32_t lf_frame_height;
    /*!< lf_low_band_disable Lower band is disabled and zero on inputs*/
    int32_t lf_low_band_disable;
    /*!< lf_low_band_only Lower band directly goes to output and other inputs are zeroes*/
    int32_t lf_low_band_only;
    /*!< lf_nr_bypass Input YUV goes directly to output after vertical delay*/
    int32_t lf_nr_bypass;
    /*!< lf_se_bypass Replace all SE outputs with se_bypass_val*/
    int32_t lf_se_bypass;
    /*!< lf_se_bypass_val SE bypass value*/
    int32_t lf_se_bypass_val;
    /*!< vlf_frame_width XNR5 input frame width*/
    int32_t vlf_frame_width;
    /*!< vlf_frame_height XNR5 input frame height*/
    int32_t vlf_frame_height;
    /*!< vlf_low_band_disable Lower band is disabled and zero on inputs*/
    int32_t vlf_low_band_disable;
    /*!< vlf_low_band_only Lower band directly goes to output and other inputs are zeroes*/
    int32_t vlf_low_band_only;
    /*!< vlf_nr_bypass Input YUV goes directly to output after vertical delay*/
    int32_t vlf_nr_bypass;
    /*!< vlf_se_bypass Replace all SE outputs with se_bypass_val*/
    int32_t vlf_se_bypass;
    /*!< vlf_se_bypass_val SE bypass value*/
    int32_t vlf_se_bypass_val;
    /*!< Bypass Deprecated bypass parameter - to be removed!*/
    int32_t Bypass;
    /*!< top_viir_coefs_b[3] Param_Top_VIIR_b*/
    int32_t top_viir_coefs_b[3];
    /*!< top_viir_coefs_a[2] Param_Top_VIIR_a*/
    int32_t top_viir_coefs_a[2];
    /*!< top_viir_offset Param_Top_VIIR_offset*/
    int32_t top_viir_offset;
    /*!< top_viir_alpha Param_Top_VIIR_alpha*/
    int32_t top_viir_alpha;
    /*!< top_hus_vlf_image_coefs[9] Param_Top_HUS_VLF_Image_func*/
    int32_t top_hus_vlf_image_coefs[9];
    /*!< top_hus_vlf_delta_coefs[9] Param_Top_HUS_VLF_Delta_func*/
    int32_t top_hus_vlf_delta_coefs[9];
    /*!< top_hus_lf_image_coefs[5] Param_Top_HUS_LF_Image_func*/
    int32_t top_hus_lf_image_coefs[5];
    /*!< top_hus_lf_delta_coefs[5] Param_Top_HUS_LF_Delta_func*/
    int32_t top_hus_lf_delta_coefs[5];
    /*!< top_hus_mf_image_coefs[5] Param_Top_HUS_MF_Image_func*/
    int32_t top_hus_mf_image_coefs[5];
    /*!< top_hus_mf_delta_coefs[5] Param_Top_HUS_MF_Delta_func*/
    int32_t top_hus_mf_delta_coefs[5];
    /*!< hf_blf_2dfir_filter_length Param_HFC_BLF_FIR_BfLen*/
    int32_t hf_blf_2dfir_filter_length;
    /*!< hf_blf_2dfir_dcdc_bypass_y Param_HFC_BLF_FIR_bypassDCDifferentialCompensationY*/
    int32_t hf_blf_2dfir_dcdc_bypass_y;
    /*!< hf_blf_2dfir_dcdc_thresh_y_y Param_HFC_BLF_FIR_DCDiffThYy*/
    uint32_t hf_blf_2dfir_dcdc_thresh_y_y;
    /*!< hf_blf_2dfir_dcdc_thresh_y_u Param_HFC_BLF_FIR_DCDiffThYu*/
    uint32_t hf_blf_2dfir_dcdc_thresh_y_u;
    /*!< hf_blf_2dfir_dcdc_thresh_y_v Param_HFC_BLF_FIR_DCDiffThYv*/
    uint32_t hf_blf_2dfir_dcdc_thresh_y_v;
    /*!< hf_blf_2dfir_dcdc_bypass_uv Param_HFC_BLF_FIR_bypassDCDifferentialCompensationUV*/
    int32_t hf_blf_2dfir_dcdc_bypass_uv;
    /*!< hf_blf_2dfir_dcdc_thresh_uv_y Param_HFC_BLF_FIR_DCDiffThUVy*/
    uint32_t hf_blf_2dfir_dcdc_thresh_uv_y;
    /*!< hf_blf_2dfir_dcdc_thresh_uv_u Param_HFC_BLF_FIR_DCDiffThUVu*/
    uint32_t hf_blf_2dfir_dcdc_thresh_uv_u;
    /*!< hf_blf_2dfir_dcdc_thresh_uv_v Param_HFC_BLF_FIR_DCDiffThUVv*/
    uint32_t hf_blf_2dfir_dcdc_thresh_uv_v;
    /*!< hf_blf_colorspace Param_HFC_BLF_colorspaceYRB*/
    int32_t hf_blf_colorspace;
    /*!< hf_blf_noisemodel_basefunc_y_a_x[5] Param_HFC_BLF_NoiseModel_sigmaParafacY_A_X*/
    int32_t hf_blf_noisemodel_basefunc_y_a_x[5];
    /*!< hf_blf_noisemodel_basefunc_y_a_y[4] Param_HFC_BLF_NoiseModel_sigmaParafacY_A_Y*/
    int32_t hf_blf_noisemodel_basefunc_y_a_y[4];
    /*!< hf_blf_noisemodel_basefunc_y_a_slope[4] Param_HFC_BLF_NoiseModel_sigmaParafacY_A_Slope*/
    int32_t hf_blf_noisemodel_basefunc_y_a_slope[4];
    /*!< hf_blf_noisemodel_basefunc_y_b_x[5] Param_HFC_BLF_NoiseModel_sigmaParafacY_B_X*/
    int32_t hf_blf_noisemodel_basefunc_y_b_x[5];
    /*!< hf_blf_noisemodel_basefunc_y_b_y[4] Param_HFC_BLF_NoiseModel_sigmaParafacY_B Config Unit Value*/
    int32_t hf_blf_noisemodel_basefunc_y_b_y[4];
    /*!< hf_blf_noisemodel_basefunc_y_b_slope[4] Slope*/
    int32_t hf_blf_noisemodel_basefunc_y_b_slope[4];
    /*!< hf_blf_noisemodel_basefunc_y_c_x[5] Param_HFC_BLF_NoiseModel_sigmaParafacY_C_X*/
    int32_t hf_blf_noisemodel_basefunc_y_c_x[5];
    /*!< hf_blf_noisemodel_basefunc_y_c_y[4] Param_HFC_BLF_NoiseModel_sigmaParafacY_C Config Unit Value*/
    int32_t hf_blf_noisemodel_basefunc_y_c_y[4];
    /*!< hf_blf_noisemodel_basefunc_y_c_slope[4] Slope*/
    int32_t hf_blf_noisemodel_basefunc_y_c_slope[4];
    /*!< hf_blf_noisemodel_basefunc_y_wbg Param_HFC_BLF_NoiseModel_sigmaParafacY_DEF*/
    int32_t hf_blf_noisemodel_basefunc_y_wbg;
    /*!< hf_blf_noisemodel_basefunc_u_a_x[5] Param_HFC_BLF_NoiseModel_sigmaParafacU_A_X*/
    int32_t hf_blf_noisemodel_basefunc_u_a_x[5];
    /*!< hf_blf_noisemodel_basefunc_u_a_y[4] Param_HFC_BLF_NoiseModel_sigmaParafacU_A Config Unit Value*/
    int32_t hf_blf_noisemodel_basefunc_u_a_y[4];
    /*!< hf_blf_noisemodel_basefunc_u_a_slope[4] Slope*/
    int32_t hf_blf_noisemodel_basefunc_u_a_slope[4];
    /*!< hf_blf_noisemodel_basefunc_u_b_x[5] Param_HFC_BLF_NoiseModel_sigmaParafacU_B_X*/
    int32_t hf_blf_noisemodel_basefunc_u_b_x[5];
    /*!< hf_blf_noisemodel_basefunc_u_b_y[4] Param_HFC_BLF_NoiseModel_sigmaParafacU_B Config Unit Value*/
    int32_t hf_blf_noisemodel_basefunc_u_b_y[4];
    /*!< hf_blf_noisemodel_basefunc_u_b_slope[4] Slope*/
    int32_t hf_blf_noisemodel_basefunc_u_b_slope[4];
    /*!< hf_blf_noisemodel_basefunc_u_c_x[5] Param_HFC_BLF_NoiseModel_sigmaParafacU_C_X*/
    int32_t hf_blf_noisemodel_basefunc_u_c_x[5];
    /*!< hf_blf_noisemodel_basefunc_u_c_y[4] Param_HFC_BLF_NoiseModel_sigmaParafacU_C Config Unit Value*/
    int32_t hf_blf_noisemodel_basefunc_u_c_y[4];
    /*!< hf_blf_noisemodel_basefunc_u_c_slope[4] Slope*/
    int32_t hf_blf_noisemodel_basefunc_u_c_slope[4];
    /*!< hf_blf_noisemodel_basefunc_u_wbg Param_HFC_BLF_NoiseModel_sigmaParafacU_DEF*/
    int32_t hf_blf_noisemodel_basefunc_u_wbg;
    /*!< hf_blf_noisemodel_basefunc_v_a_x[5] Param_HFC_BLF_NoiseModel_sigmaParafacV_A_X*/
    int32_t hf_blf_noisemodel_basefunc_v_a_x[5];
    /*!< hf_blf_noisemodel_basefunc_v_a_y[4] Param_HFC_BLF_NoiseModel_sigmaParafacV_A Config Unit Value*/
    int32_t hf_blf_noisemodel_basefunc_v_a_y[4];
    /*!< hf_blf_noisemodel_basefunc_v_a_slope[4] Slope*/
    int32_t hf_blf_noisemodel_basefunc_v_a_slope[4];
    /*!< hf_blf_noisemodel_basefunc_v_b_x[5] Param_HFC_BLF_NoiseModel_sigmaParafacV_B_X*/
    int32_t hf_blf_noisemodel_basefunc_v_b_x[5];
    /*!< hf_blf_noisemodel_basefunc_v_b_y[4] Param_HFC_BLF_NoiseModel_sigmaParafacV_B Config Unit Value*/
    int32_t hf_blf_noisemodel_basefunc_v_b_y[4];
    /*!< hf_blf_noisemodel_basefunc_v_b_slope[4] Slope*/
    int32_t hf_blf_noisemodel_basefunc_v_b_slope[4];
    /*!< hf_blf_noisemodel_basefunc_v_c_x[5] Param_HFC_BLF_NoiseModel_sigmaParafacV_C_X*/
    int32_t hf_blf_noisemodel_basefunc_v_c_x[5];
    /*!< hf_blf_noisemodel_basefunc_v_c_y[4] Param_HFC_BLF_NoiseModel_sigmaParafacV_C Config Unit Value*/
    int32_t hf_blf_noisemodel_basefunc_v_c_y[4];
    /*!< hf_blf_noisemodel_basefunc_v_c_slope[4] Slope*/
    int32_t hf_blf_noisemodel_basefunc_v_c_slope[4];
    /*!< hf_blf_noisemodel_basefunc_v_wbg Param_HFC_BLF_NoiseModel_sigmaParafacV_DEF*/
    int32_t hf_blf_noisemodel_basefunc_v_wbg;
    /*!< hf_blf_noisemodel_weight_uv_y Param_HFC_BLF_NoiseModel_sigmaWgtUVy*/
    int32_t hf_blf_noisemodel_weight_uv_y;
    /*!< hf_blf_noisemodel_weight_uv_u Param_HFC_BLF_NoiseModel_sigmaWgtUVu*/
    int32_t hf_blf_noisemodel_weight_uv_u;
    /*!< hf_blf_noisemodel_weight_uv_v Param_HFC_BLF_NoiseModel_sigmaWgtUVv*/
    int32_t hf_blf_noisemodel_weight_uv_v;
    /*!< hf_blf_noisemodel_radialdependent_bypass Param_HFC_BLF_NoiseModel_bypassRadialCorrection*/
    int32_t hf_blf_noisemodel_radialdependent_bypass;
    /*!< hf_blf_noisemodel_colordependent_bypass Param_HFC_BLF_NoiseModel_bypassColorDependent*/
    int32_t hf_blf_noisemodel_colordependent_bypass;
    /*!< hf_blf_noisemodel_graydependent_bypass Param_HFC_BLF_NoiseModel_bypassGrayDependent*/
    int32_t hf_blf_noisemodel_graydependent_bypass;
    /*!< hf_blf_noisemodel_radialdependent_x0_square Param_HFC_BLF_NoiseModel_radialDependent_x0_square*/
    int32_t hf_blf_noisemodel_radialdependent_x0_square;
    /*!< hf_blf_noisemodel_radialdependent_x0 Param_HFC_BLF_NoiseModel_radialDependent_x0*/
    int32_t hf_blf_noisemodel_radialdependent_x0;
    /*!< hf_blf_noisemodel_radialdependent_y0_square Param_HFC_BLF_NoiseModel_radialDependent_y0_square*/
    int32_t hf_blf_noisemodel_radialdependent_y0_square;
    /*!< hf_blf_noisemodel_radialdependent_y0 Param_HFC_BLF_NoiseModel_radialDependent_y0*/
    int32_t hf_blf_noisemodel_radialdependent_y0;
    /*!< hf_blf_noisemodel_radialdependent_rshift_norm_square_distance Param_HFC_BLF_NoiseModel_radialDependent_rshiftNormSquareDist*/
    int32_t hf_blf_noisemodel_radialdependent_rshift_norm_square_distance;
    /*!< hf_blf_noisemodel_radialdependent_gain_x[4] Param_HFC_BLF_NoiseModel_radialDependent_radialLut_X*/
    int32_t hf_blf_noisemodel_radialdependent_gain_x[4];
    /*!< hf_blf_noisemodel_radialdependent_gain_y[3] Param_HFC_BLF_NoiseModel_radialDependent_radialLut Config Unit Value*/
    int32_t hf_blf_noisemodel_radialdependent_gain_y[3];
    /*!< hf_blf_noisemodel_radialdependent_gain_slope[3] Slope*/
    int32_t hf_blf_noisemodel_radialdependent_gain_slope[3];
    /*!< hf_blf_noisemodel_colordependent_a[32] Param_HFC_BLF_NoiseModel_colorDependent_A*/
    int32_t hf_blf_noisemodel_colordependent_a[32];
    /*!< hf_blf_noisemodel_colordependent_b[32] Param_HFC_BLF_NoiseModel_colorDependent_B*/
    int32_t hf_blf_noisemodel_colordependent_b[32];
    /*!< hf_blf_noisemodel_colordependent_c[32] Param_HFC_BLF_NoiseModel_colorDependent_C*/
    int32_t hf_blf_noisemodel_colordependent_c[32];
    /*!< hf_blf_noisemodel_colordependent_norm_offset Param_HFC_BLF_NoiseModel_colorDependent_normalization_offset*/
    int32_t hf_blf_noisemodel_colordependent_norm_offset;
    /*!< hf_blf_noisemodel_colordependent_gain_x[6] Param_HFC_BLF_NoiseModel_colorDependent_Lut_X*/
    int32_t hf_blf_noisemodel_colordependent_gain_x[6];
    /*!< hf_blf_noisemodel_colordependent_gain_y[5] Param_HFC_BLF_NoiseModel_colorDependent_Lut Config Unit Value*/
    int32_t hf_blf_noisemodel_colordependent_gain_y[5];
    /*!< hf_blf_noisemodel_colordependent_gain_slope[5] Slope*/
    int32_t hf_blf_noisemodel_colordependent_gain_slope[5];
    /*!< hf_blf_noisemodel_graydependent_graylevel_thresh Param_HFC_BLF_NoiseModel_grayDependent_grayThrsh*/
    int32_t hf_blf_noisemodel_graydependent_graylevel_thresh;
    /*!< hf_blf_noisemodel_graydependent_graylevel_slope Param_HFC_BLF_NoiseModel_grayDependent_graySlope*/
    int32_t hf_blf_noisemodel_graydependent_graylevel_slope;
    /*!< hf_blf_noisemodel_graydependent_gain_x[6] Param_HFC_BLF_NoiseModel_grayDependent_transLut_X*/
    int32_t hf_blf_noisemodel_graydependent_gain_x[6];
    /*!< hf_blf_noisemodel_graydependent_gain_y[5] Param_HFC_BLF_NoiseModel_grayDependent_transLut Config Unit Value*/
    int32_t hf_blf_noisemodel_graydependent_gain_y[5];
    /*!< hf_blf_noisemodel_graydependent_gain_slope[5] Slope*/
    int32_t hf_blf_noisemodel_graydependent_gain_slope[5];
    /*!< hf_blf_noisemodel_normfactor_uv_y Param_HFC_BLF_NoiseModel_invSigmaUVy*/
    int32_t hf_blf_noisemodel_normfactor_uv_y;
    /*!< hf_blf_noisemodel_normfactor_uv_u Param_HFC_BLF_NoiseModel_invSigmaUVu*/
    int32_t hf_blf_noisemodel_normfactor_uv_u;
    /*!< hf_blf_noisemodel_normfactor_uv_v Param_HFC_BLF_NoiseModel_invSigmaUVv*/
    int32_t hf_blf_noisemodel_normfactor_uv_v;
    /*!< hf_blf_snrm_bypass Param_HFC_BLF_SNRM_bypassSNRManagement*/
    int32_t hf_blf_snrm_bypass;
    /*!< hf_blf_snrm_slope_uv Param_HFC_BLF_SNRM_slopeUV*/
    int32_t hf_blf_snrm_slope_uv;
    /*!< hf_blf_snrm_xoffset_uv Param_HFC_BLF_SNRM_xoffsetUV*/
    int32_t hf_blf_snrm_xoffset_uv;
    /*!< hf_blf_snrm_maxval_uv Param_HFC_BLF_SNRM_maxValUV*/
    int32_t hf_blf_snrm_maxval_uv;
    /*!< hf_blf_snrm_minval_uv Param_HFC_BLF_SNRM_minValUV*/
    int32_t hf_blf_snrm_minval_uv;
    /*!< hf_afc_bypass Param_HFC_AFC_bypassAntiFalseColor*/
    int32_t hf_afc_bypass;
    /*!< hf_afc_weight_snr Param_HFC_AFC_wgtSnr*/
    int32_t hf_afc_weight_snr;
    /*!< hf_afc_weight_chroma Param_HFC_AFC_wgtC*/
    int32_t hf_afc_weight_chroma;
    /*!< hf_min_distance_clamp Param_HFC_min_distance_clamp*/
    int32_t hf_min_distance_clamp;
    /*!< mf_blf_2dfir_filter_length Param_MF_BLF_FIR_BfLen*/
    int32_t mf_blf_2dfir_filter_length;
    /*!< mf_blf_2dfir_luma_coefs[10] Param_MF_BLF_FIR_Kn_coef*/
    int32_t mf_blf_2dfir_luma_coefs[10];
    /*!< mf_blf_2dfir_luma_denom_bits Param_MF_BLF_FIR_Kn_denom_bits*/
    int32_t mf_blf_2dfir_luma_denom_bits;
    /*!< mf_blf_2dfir_dcdc_bypass_y Param_MF_BLF_FIR_bypassDCDifferentialCompensationY*/
    int32_t mf_blf_2dfir_dcdc_bypass_y;
    /*!< mf_blf_2dfir_dcdc_thresh_y_y Param_MF_BLF_FIR_DCDiffThYy*/
    uint32_t mf_blf_2dfir_dcdc_thresh_y_y;
    /*!< mf_blf_2dfir_dcdc_thresh_y_u Param_MF_BLF_FIR_DCDiffThYu*/
    uint32_t mf_blf_2dfir_dcdc_thresh_y_u;
    /*!< mf_blf_2dfir_dcdc_thresh_y_v Param_MF_BLF_FIR_DCDiffThYv*/
    uint32_t mf_blf_2dfir_dcdc_thresh_y_v;
    /*!< mf_blf_2dfir_dcdc_bypass_uv Param_MF_BLF_FIR_bypassDCDifferentialCompensationUV*/
    int32_t mf_blf_2dfir_dcdc_bypass_uv;
    /*!< mf_blf_2dfir_dcdc_thresh_uv_y Param_MF_BLF_FIR_DCDiffThUVy*/
    uint32_t mf_blf_2dfir_dcdc_thresh_uv_y;
    /*!< mf_blf_2dfir_dcdc_thresh_uv_u Param_MF_BLF_FIR_DCDiffThUVu*/
    uint32_t mf_blf_2dfir_dcdc_thresh_uv_u;
    /*!< mf_blf_2dfir_dcdc_thresh_uv_v Param_MF_BLF_FIR_DCDiffThUVv*/
    uint32_t mf_blf_2dfir_dcdc_thresh_uv_v;
    /*!< mf_blf_2dfir_bypass_snr_y Param_MF_BLF_FIR_bypasssSnrY*/
    int32_t mf_blf_2dfir_bypass_snr_y;
    /*!< mf_blf_colorspace Param_MF_BLF_colorspaceYRB*/
    int32_t mf_blf_colorspace;
    /*!< mf_blf_noisemodel_basefunc_y_a_x[5] Param_MF_BLF_NoiseModel_sigmaParafacY_A_X*/
    int32_t mf_blf_noisemodel_basefunc_y_a_x[5];
    /*!< mf_blf_noisemodel_basefunc_y_a_y[4] Param_MF_BLF_NoiseModel_sigmaParafacY_A Config Unit Value*/
    int32_t mf_blf_noisemodel_basefunc_y_a_y[4];
    /*!< mf_blf_noisemodel_basefunc_y_a_slope[4] Slope*/
    int32_t mf_blf_noisemodel_basefunc_y_a_slope[4];
    /*!< mf_blf_noisemodel_basefunc_y_b_x[5] Param_MF_BLF_NoiseModel_sigmaParafacY_B_X*/
    int32_t mf_blf_noisemodel_basefunc_y_b_x[5];
    /*!< mf_blf_noisemodel_basefunc_y_b_y[4] Param_MF_BLF_NoiseModel_sigmaParafacY_B Config Unit Value*/
    int32_t mf_blf_noisemodel_basefunc_y_b_y[4];
    /*!< mf_blf_noisemodel_basefunc_y_b_slope[4] Slope*/
    int32_t mf_blf_noisemodel_basefunc_y_b_slope[4];
    /*!< mf_blf_noisemodel_basefunc_y_c_x[5] Param_MF_BLF_NoiseModel_sigmaParafacY_C_X*/
    int32_t mf_blf_noisemodel_basefunc_y_c_x[5];
    /*!< mf_blf_noisemodel_basefunc_y_c_y[4] Param_MF_BLF_NoiseModel_sigmaParafacY_C Config Unit Value*/
    int32_t mf_blf_noisemodel_basefunc_y_c_y[4];
    /*!< mf_blf_noisemodel_basefunc_y_c_slope[4] Slope*/
    int32_t mf_blf_noisemodel_basefunc_y_c_slope[4];
    /*!< mf_blf_noisemodel_basefunc_y_wbg Param_MF_BLF_NoiseModel_sigmaParafacY_DEF*/
    int32_t mf_blf_noisemodel_basefunc_y_wbg;
    /*!< mf_blf_noisemodel_basefunc_u_a_x[5] Param_MF_BLF_NoiseModel_sigmaParafacU_A_X*/
    int32_t mf_blf_noisemodel_basefunc_u_a_x[5];
    /*!< mf_blf_noisemodel_basefunc_u_a_y[4] Param_MF_BLF_NoiseModel_sigmaParafacU_A Config Unit Value*/
    int32_t mf_blf_noisemodel_basefunc_u_a_y[4];
    /*!< mf_blf_noisemodel_basefunc_u_a_slope[4] Slope*/
    int32_t mf_blf_noisemodel_basefunc_u_a_slope[4];
    /*!< mf_blf_noisemodel_basefunc_u_b_x[5] Param_MF_BLF_NoiseModel_sigmaParafacU_B_X*/
    int32_t mf_blf_noisemodel_basefunc_u_b_x[5];
    /*!< mf_blf_noisemodel_basefunc_u_b_y[4] Param_MF_BLF_NoiseModel_sigmaParafacU_B Config Unit Value*/
    int32_t mf_blf_noisemodel_basefunc_u_b_y[4];
    /*!< mf_blf_noisemodel_basefunc_u_b_slope[4] Slope*/
    int32_t mf_blf_noisemodel_basefunc_u_b_slope[4];
    /*!< mf_blf_noisemodel_basefunc_u_c_x[5] Param_MF_BLF_NoiseModel_sigmaParafacU_C_X*/
    int32_t mf_blf_noisemodel_basefunc_u_c_x[5];
    /*!< mf_blf_noisemodel_basefunc_u_c_y[4] Param_MF_BLF_NoiseModel_sigmaParafacU_C Config Unit Value*/
    int32_t mf_blf_noisemodel_basefunc_u_c_y[4];
    /*!< mf_blf_noisemodel_basefunc_u_c_slope[4] Slope*/
    int32_t mf_blf_noisemodel_basefunc_u_c_slope[4];
    /*!< mf_blf_noisemodel_basefunc_u_wbg Param_MF_BLF_NoiseModel_sigmaParafacU_DEF*/
    int32_t mf_blf_noisemodel_basefunc_u_wbg;
    /*!< mf_blf_noisemodel_basefunc_v_a_x[5] Param_MF_BLF_NoiseModel_sigmaParafacV_A_X*/
    int32_t mf_blf_noisemodel_basefunc_v_a_x[5];
    /*!< mf_blf_noisemodel_basefunc_v_a_y[4] Param_MF_BLF_NoiseModel_sigmaParafacV_A Config Unit Value*/
    int32_t mf_blf_noisemodel_basefunc_v_a_y[4];
    /*!< mf_blf_noisemodel_basefunc_v_a_slope[4] Slope*/
    int32_t mf_blf_noisemodel_basefunc_v_a_slope[4];
    /*!< mf_blf_noisemodel_basefunc_v_b_x[5] Param_MF_BLF_NoiseModel_sigmaParafacV_B_X*/
    int32_t mf_blf_noisemodel_basefunc_v_b_x[5];
    /*!< mf_blf_noisemodel_basefunc_v_b_y[4] Param_MF_BLF_NoiseModel_sigmaParafacV_B Config Unit Value*/
    int32_t mf_blf_noisemodel_basefunc_v_b_y[4];
    /*!< mf_blf_noisemodel_basefunc_v_b_slope[4] Slope*/
    int32_t mf_blf_noisemodel_basefunc_v_b_slope[4];
    /*!< mf_blf_noisemodel_basefunc_v_c_x[5] Param_MF_BLF_NoiseModel_sigmaParafacV_C_X*/
    int32_t mf_blf_noisemodel_basefunc_v_c_x[5];
    /*!< mf_blf_noisemodel_basefunc_v_c_y[4] Param_MF_BLF_NoiseModel_sigmaParafacV_C Config Unit Value*/
    int32_t mf_blf_noisemodel_basefunc_v_c_y[4];
    /*!< mf_blf_noisemodel_basefunc_v_c_slope[4] Slope*/
    int32_t mf_blf_noisemodel_basefunc_v_c_slope[4];
    /*!< mf_blf_noisemodel_basefunc_v_wbg Param_MF_BLF_NoiseModel_sigmaParafacV_DEF*/
    int32_t mf_blf_noisemodel_basefunc_v_wbg;
    /*!< mf_blf_noisemodel_weight_y_y Param_MF_BLF_NoiseModel_sigmaWgtYy*/
    int32_t mf_blf_noisemodel_weight_y_y;
    /*!< mf_blf_noisemodel_weight_y_u Param_MF_BLF_NoiseModel_sigmaWgtYu*/
    int32_t mf_blf_noisemodel_weight_y_u;
    /*!< mf_blf_noisemodel_weight_y_v Param_MF_BLF_NoiseModel_sigmaWgtYv*/
    int32_t mf_blf_noisemodel_weight_y_v;
    /*!< mf_blf_noisemodel_weight_uv_y Param_MF_BLF_NoiseModel_sigmaWgtUVy*/
    int32_t mf_blf_noisemodel_weight_uv_y;
    /*!< mf_blf_noisemodel_weight_uv_u Param_MF_BLF_NoiseModel_sigmaWgtUVu*/
    int32_t mf_blf_noisemodel_weight_uv_u;
    /*!< mf_blf_noisemodel_weight_uv_v Param_MF_BLF_NoiseModel_sigmaWgtUVv*/
    int32_t mf_blf_noisemodel_weight_uv_v;
    /*!< mf_blf_noisemodel_radialdependent_bypass Param_MF_BLF_NoiseModel_bypassRadialCorrection*/
    int32_t mf_blf_noisemodel_radialdependent_bypass;
    /*!< mf_blf_noisemodel_colordependent_bypass Param_MF_BLF_NoiseModel_bypassColorDependent*/
    int32_t mf_blf_noisemodel_colordependent_bypass;
    /*!< mf_blf_noisemodel_graydependent_bypass Param_MF_BLF_NoiseModel_bypassGrayDependent*/
    int32_t mf_blf_noisemodel_graydependent_bypass;
    /*!< mf_blf_noisemodel_radialdependent_x0_square Param_MF_BLF_NoiseModel_radialDependent_x0_square*/
    int32_t mf_blf_noisemodel_radialdependent_x0_square;
    /*!< mf_blf_noisemodel_radialdependent_x0 Param_MF_BLF_NoiseModel_radialDependent_x0*/
    int32_t mf_blf_noisemodel_radialdependent_x0;
    /*!< mf_blf_noisemodel_radialdependent_y0_square Param_MF_BLF_NoiseModel_radialDependent_y0_square*/
    int32_t mf_blf_noisemodel_radialdependent_y0_square;
    /*!< mf_blf_noisemodel_radialdependent_y0 Param_MF_BLF_NoiseModel_radialDependent_y0*/
    int32_t mf_blf_noisemodel_radialdependent_y0;
    /*!< mf_blf_noisemodel_radialdependent_rshift_norm_square_distance Param_MF_BLF_NoiseModel_radialDependent_rshiftNormSquareDist*/
    int32_t mf_blf_noisemodel_radialdependent_rshift_norm_square_distance;
    /*!< mf_blf_noisemodel_radialdependent_gain_x[4] Param_MF_BLF_NoiseModel_radialDependent_radialLut_X*/
    int32_t mf_blf_noisemodel_radialdependent_gain_x[4];
    /*!< mf_blf_noisemodel_radialdependent_gain_y[3] Param_MF_BLF_NoiseModel_radialDependent_radialLut Config Unit Value*/
    int32_t mf_blf_noisemodel_radialdependent_gain_y[3];
    /*!< mf_blf_noisemodel_radialdependent_gain_slope[3] Slope*/
    int32_t mf_blf_noisemodel_radialdependent_gain_slope[3];
    /*!< mf_blf_noisemodel_colordependent_a[32] Param_MF_BLF_NoiseModel_colorDependent_A*/
    int32_t mf_blf_noisemodel_colordependent_a[32];
    /*!< mf_blf_noisemodel_colordependent_b[32] Param_MF_BLF_NoiseModel_colorDependent_B*/
    int32_t mf_blf_noisemodel_colordependent_b[32];
    /*!< mf_blf_noisemodel_colordependent_c[32] Param_MF_BLF_NoiseModel_colorDependent_C*/
    int32_t mf_blf_noisemodel_colordependent_c[32];
    /*!< mf_blf_noisemodel_colordependent_norm_offset Param_MF_BLF_NoiseModel_colorDependent_normalization_offset*/
    int32_t mf_blf_noisemodel_colordependent_norm_offset;
    /*!< mf_blf_noisemodel_colordependent_gain_x[6] Param_MF_BLF_NoiseModel_colorDependent_Lut_X*/
    int32_t mf_blf_noisemodel_colordependent_gain_x[6];
    /*!< mf_blf_noisemodel_colordependent_gain_y[5] Param_MF_BLF_NoiseModel_colorDependent_Lut Config Unit Value*/
    int32_t mf_blf_noisemodel_colordependent_gain_y[5];
    /*!< mf_blf_noisemodel_colordependent_gain_slope[5] Slope*/
    int32_t mf_blf_noisemodel_colordependent_gain_slope[5];
    /*!< mf_blf_noisemodel_graydependent_graylevel_thresh Param_MF_BLF_NoiseModel_grayDependent_grayThrsh*/
    int32_t mf_blf_noisemodel_graydependent_graylevel_thresh;
    /*!< mf_blf_noisemodel_graydependent_graylevel_slope Param_MF_BLF_NoiseModel_grayDependent_graySlope*/
    int32_t mf_blf_noisemodel_graydependent_graylevel_slope;
    /*!< mf_blf_noisemodel_graydependent_gain_x[6] Param_MF_BLF_NoiseModel_grayDependent_transLut_X*/
    int32_t mf_blf_noisemodel_graydependent_gain_x[6];
    /*!< mf_blf_noisemodel_graydependent_gain_y[5] Param_MF_BLF_NoiseModel_grayDependent_transLut Config Unit Value*/
    int32_t mf_blf_noisemodel_graydependent_gain_y[5];
    /*!< mf_blf_noisemodel_graydependent_gain_slope[5] Slope*/
    int32_t mf_blf_noisemodel_graydependent_gain_slope[5];
    /*!< mf_blf_noisemodel_normfactor_y_y Param_MF_BLF_NoiseModel_invSigmaYy*/
    int32_t mf_blf_noisemodel_normfactor_y_y;
    /*!< mf_blf_noisemodel_normfactor_y_u Param_MF_BLF_NoiseModel_invSigmaYu*/
    int32_t mf_blf_noisemodel_normfactor_y_u;
    /*!< mf_blf_noisemodel_normfactor_y_v Param_MF_BLF_NoiseModel_invSigmaYv*/
    int32_t mf_blf_noisemodel_normfactor_y_v;
    /*!< mf_blf_noisemodel_normfactor_uv_y Param_MF_BLF_NoiseModel_invSigmaUVy*/
    int32_t mf_blf_noisemodel_normfactor_uv_y;
    /*!< mf_blf_noisemodel_normfactor_uv_u Param_MF_BLF_NoiseModel_invSigmaUVu*/
    int32_t mf_blf_noisemodel_normfactor_uv_u;
    /*!< mf_blf_noisemodel_normfactor_uv_v Param_MF_BLF_NoiseModel_invSigmaUVv*/
    int32_t mf_blf_noisemodel_normfactor_uv_v;
    /*!< mf_blf_snrm_bypass Param_MF_BLF_SNRM_bypassSNRManagement*/
    int32_t mf_blf_snrm_bypass;
    /*!< mf_blf_snrm_bypass_y Param_MF_BLF_SNRM_bypassY*/
    int32_t mf_blf_snrm_bypass_y;
    /*!< mf_blf_snrm_slope_y Param_MF_BLF_SNRM_slopeY*/
    int32_t mf_blf_snrm_slope_y;
    /*!< mf_blf_snrm_xoffset_y Param_MF_BLF_SNRM_xoffsetY*/
    int32_t mf_blf_snrm_xoffset_y;
    /*!< mf_blf_snrm_maxval_y Param_MF_BLF_SNRM_maxValY*/
    int32_t mf_blf_snrm_maxval_y;
    /*!< mf_blf_snrm_minval_y Param_MF_BLF_SNRM_minValY*/
    int32_t mf_blf_snrm_minval_y;
    /*!< mf_blf_snrm_slope_uv Param_MF_BLF_SNRM_slopeUV*/
    int32_t mf_blf_snrm_slope_uv;
    /*!< mf_blf_snrm_xoffset_uv Param_MF_BLF_SNRM_xoffsetUV*/
    int32_t mf_blf_snrm_xoffset_uv;
    /*!< mf_blf_snrm_maxval_uv Param_MF_BLF_SNRM_maxValUV*/
    int32_t mf_blf_snrm_maxval_uv;
    /*!< mf_blf_snrm_minval_uv Param_MF_BLF_SNRM_minValUV*/
    int32_t mf_blf_snrm_minval_uv;
    /*!< mf_afc_bypass Param_MF_AFC_bypassAntiFalseColor*/
    int32_t mf_afc_bypass;
    /*!< mf_afc_weight_snr Param_MF_AFC_wgtSnr*/
    int32_t mf_afc_weight_snr;
    /*!< mf_afc_weight_chroma Param_MF_AFC_wgtC*/
    int32_t mf_afc_weight_chroma;
    /*!< mf_min_distance_clamp Param_MF_min_distance_clamp*/
    int32_t mf_min_distance_clamp;
    /*!< lf_blf_fir_filter_length Param_LF_BLF_FIR_BfLen*/
    int32_t lf_blf_fir_filter_length;
    /*!< lf_blf_fir_luma_coefs[6] Param_LF_BLF_FIR_Kn_coef*/
    int32_t lf_blf_fir_luma_coefs[6];
    /*!< lf_blf_fir_luma_denom_bits Param_LF_BLF_FIR_Kn_denom_bits*/
    int32_t lf_blf_fir_luma_denom_bits;
    /*!< lf_blf_fir_bypass_snr_y Param_LF_BLF_FIR_bypasssSnrY*/
    int32_t lf_blf_fir_bypass_snr_y;
    /*!< lf_blf_colorspace Param_LF_BLF_colorspaceYRB*/
    int32_t lf_blf_colorspace;
    /*!< lf_blf_noisemodel_basefunc_y_a_x[5] Param_LF_BLF_NoiseModel_sigmaParafacY_A_X*/
    int32_t lf_blf_noisemodel_basefunc_y_a_x[5];
    /*!< lf_blf_noisemodel_basefunc_y_a_y[4] Param_LF_BLF_NoiseModel_sigmaParafacY_A Config Unit Value*/
    int32_t lf_blf_noisemodel_basefunc_y_a_y[4];
    /*!< lf_blf_noisemodel_basefunc_y_a_slope[4] Slope*/
    int32_t lf_blf_noisemodel_basefunc_y_a_slope[4];
    /*!< lf_blf_noisemodel_basefunc_y_b_x[5] Param_LF_BLF_NoiseModel_sigmaParafacY_B_X*/
    int32_t lf_blf_noisemodel_basefunc_y_b_x[5];
    /*!< lf_blf_noisemodel_basefunc_y_b_y[4] Param_LF_BLF_NoiseModel_sigmaParafacY_B Config Unit Value*/
    int32_t lf_blf_noisemodel_basefunc_y_b_y[4];
    /*!< lf_blf_noisemodel_basefunc_y_b_slope[4] Slope*/
    int32_t lf_blf_noisemodel_basefunc_y_b_slope[4];
    /*!< lf_blf_noisemodel_basefunc_y_c_x[5] Param_LF_BLF_NoiseModel_sigmaParafacY_C_X*/
    int32_t lf_blf_noisemodel_basefunc_y_c_x[5];
    /*!< lf_blf_noisemodel_basefunc_y_c_y[4] Param_LF_BLF_NoiseModel_sigmaParafacY_C Config Unit Value*/
    int32_t lf_blf_noisemodel_basefunc_y_c_y[4];
    /*!< lf_blf_noisemodel_basefunc_y_c_slope[4] Slope*/
    int32_t lf_blf_noisemodel_basefunc_y_c_slope[4];
    /*!< lf_blf_noisemodel_basefunc_y_wbg Param_LF_BLF_NoiseModel_sigmaParafacY_DEF*/
    int32_t lf_blf_noisemodel_basefunc_y_wbg;
    /*!< lf_blf_noisemodel_basefunc_u_a_x[5] Param_LF_BLF_NoiseModel_sigmaParafacU_A_X*/
    int32_t lf_blf_noisemodel_basefunc_u_a_x[5];
    /*!< lf_blf_noisemodel_basefunc_u_a_y[4] Param_LF_BLF_NoiseModel_sigmaParafacU_A Config Unit Value*/
    int32_t lf_blf_noisemodel_basefunc_u_a_y[4];
    /*!< lf_blf_noisemodel_basefunc_u_a_slope[4] Slope*/
    int32_t lf_blf_noisemodel_basefunc_u_a_slope[4];
    /*!< lf_blf_noisemodel_basefunc_u_b_x[5] Param_LF_BLF_NoiseModel_sigmaParafacU_B_X*/
    int32_t lf_blf_noisemodel_basefunc_u_b_x[5];
    /*!< lf_blf_noisemodel_basefunc_u_b_y[4] Param_LF_BLF_NoiseModel_sigmaParafacU_B Config Unit Value*/
    int32_t lf_blf_noisemodel_basefunc_u_b_y[4];
    /*!< lf_blf_noisemodel_basefunc_u_b_slope[4] Slope*/
    int32_t lf_blf_noisemodel_basefunc_u_b_slope[4];
    /*!< lf_blf_noisemodel_basefunc_u_c_x[5] Param_LF_BLF_NoiseModel_sigmaParafacU_C_X*/
    int32_t lf_blf_noisemodel_basefunc_u_c_x[5];
    /*!< lf_blf_noisemodel_basefunc_u_c_y[4] Param_LF_BLF_NoiseModel_sigmaParafacU_C Config Unit Value*/
    int32_t lf_blf_noisemodel_basefunc_u_c_y[4];
    /*!< lf_blf_noisemodel_basefunc_u_c_slope[4] Slope*/
    int32_t lf_blf_noisemodel_basefunc_u_c_slope[4];
    /*!< lf_blf_noisemodel_basefunc_u_wbg Param_LF_BLF_NoiseModel_sigmaParafacU_DEF*/
    int32_t lf_blf_noisemodel_basefunc_u_wbg;
    /*!< lf_blf_noisemodel_basefunc_v_a_x[5] Param_LF_BLF_NoiseModel_sigmaParafacV_A_X*/
    int32_t lf_blf_noisemodel_basefunc_v_a_x[5];
    /*!< lf_blf_noisemodel_basefunc_v_a_y[4] Param_LF_BLF_NoiseModel_sigmaParafacV_A Config Unit Value*/
    int32_t lf_blf_noisemodel_basefunc_v_a_y[4];
    /*!< lf_blf_noisemodel_basefunc_v_a_slope[4] Slope*/
    int32_t lf_blf_noisemodel_basefunc_v_a_slope[4];
    /*!< lf_blf_noisemodel_basefunc_v_b_x[5] Param_LF_BLF_NoiseModel_sigmaParafacV_B_X*/
    int32_t lf_blf_noisemodel_basefunc_v_b_x[5];
    /*!< lf_blf_noisemodel_basefunc_v_b_y[4] Param_LF_BLF_NoiseModel_sigmaParafacV_B Config Unit Value*/
    int32_t lf_blf_noisemodel_basefunc_v_b_y[4];
    /*!< lf_blf_noisemodel_basefunc_v_b_slope[4] Slope*/
    int32_t lf_blf_noisemodel_basefunc_v_b_slope[4];
    /*!< lf_blf_noisemodel_basefunc_v_c_x[5] Param_LF_BLF_NoiseModel_sigmaParafacV_C_X*/
    int32_t lf_blf_noisemodel_basefunc_v_c_x[5];
    /*!< lf_blf_noisemodel_basefunc_v_c_y[4] Param_LF_BLF_NoiseModel_sigmaParafacV_C Config Unit Value*/
    int32_t lf_blf_noisemodel_basefunc_v_c_y[4];
    /*!< lf_blf_noisemodel_basefunc_v_c_slope[4] Slope*/
    int32_t lf_blf_noisemodel_basefunc_v_c_slope[4];
    /*!< lf_blf_noisemodel_basefunc_v_wbg Param_LF_BLF_NoiseModel_sigmaParafacV_DEF*/
    int32_t lf_blf_noisemodel_basefunc_v_wbg;
    /*!< lf_blf_noisemodel_weight_y_y Param_LF_BLF_NoiseModel_sigmaWgtYy*/
    int32_t lf_blf_noisemodel_weight_y_y;
    /*!< lf_blf_noisemodel_weight_y_u Param_LF_BLF_NoiseModel_sigmaWgtYu*/
    int32_t lf_blf_noisemodel_weight_y_u;
    /*!< lf_blf_noisemodel_weight_y_v Param_LF_BLF_NoiseModel_sigmaWgtYv*/
    int32_t lf_blf_noisemodel_weight_y_v;
    /*!< lf_blf_noisemodel_weight_uv_y Param_LF_BLF_NoiseModel_sigmaWgtUVy*/
    int32_t lf_blf_noisemodel_weight_uv_y;
    /*!< lf_blf_noisemodel_weight_uv_u Param_LF_BLF_NoiseModel_sigmaWgtUVu*/
    int32_t lf_blf_noisemodel_weight_uv_u;
    /*!< lf_blf_noisemodel_weight_uv_v Param_LF_BLF_NoiseModel_sigmaWgtUVv*/
    int32_t lf_blf_noisemodel_weight_uv_v;
    /*!< lf_blf_noisemodel_radialdependent_bypass Param_LF_BLF_NoiseModel_bypassRadialCorrection*/
    int32_t lf_blf_noisemodel_radialdependent_bypass;
    /*!< lf_blf_noisemodel_colordependent_bypass Param_LF_BLF_NoiseModel_bypassColorDependent*/
    int32_t lf_blf_noisemodel_colordependent_bypass;
    /*!< lf_blf_noisemodel_graydependent_bypass Param_LF_BLF_NoiseModel_bypassGrayDependent*/
    int32_t lf_blf_noisemodel_graydependent_bypass;
    /*!< lf_blf_noisemodel_radialdependent_x0_square Param_LF_BLF_NoiseModel_radialDependent_x0_square*/
    int32_t lf_blf_noisemodel_radialdependent_x0_square;
    /*!< lf_blf_noisemodel_radialdependent_x0 Param_LF_BLF_NoiseModel_radialDependent_x0*/
    int32_t lf_blf_noisemodel_radialdependent_x0;
    /*!< lf_blf_noisemodel_radialdependent_y0_square Param_LF_BLF_NoiseModel_radialDependent_y0_square*/
    int32_t lf_blf_noisemodel_radialdependent_y0_square;
    /*!< lf_blf_noisemodel_radialdependent_y0 Param_LF_BLF_NoiseModel_radialDependent_y0*/
    int32_t lf_blf_noisemodel_radialdependent_y0;
    /*!< lf_blf_noisemodel_radialdependent_rshift_norm_square_distance Param_LF_BLF_NoiseModel_radialDependent_rshiftNormSquareDist*/
    int32_t lf_blf_noisemodel_radialdependent_rshift_norm_square_distance;
    /*!< lf_blf_noisemodel_radialdependent_gain_x[4] Param_LF_BLF_NoiseModel_radialDependent_radialLut_X*/
    int32_t lf_blf_noisemodel_radialdependent_gain_x[4];
    /*!< lf_blf_noisemodel_radialdependent_gain_y[3] Param_LF_BLF_NoiseModel_radialDependent_radialLut Config Unit Value*/
    int32_t lf_blf_noisemodel_radialdependent_gain_y[3];
    /*!< lf_blf_noisemodel_radialdependent_gain_slope[3] Slope*/
    int32_t lf_blf_noisemodel_radialdependent_gain_slope[3];
    /*!< lf_blf_noisemodel_colordependent_a[32] Param_LF_BLF_NoiseModel_colorDependent_A*/
    int32_t lf_blf_noisemodel_colordependent_a[32];
    /*!< lf_blf_noisemodel_colordependent_b[32] Param_LF_BLF_NoiseModel_colorDependent_B*/
    int32_t lf_blf_noisemodel_colordependent_b[32];
    /*!< lf_blf_noisemodel_colordependent_c[32] Param_LF_BLF_NoiseModel_colorDependent_C*/
    int32_t lf_blf_noisemodel_colordependent_c[32];
    /*!< lf_blf_noisemodel_colordependent_norm_offset Param_LF_BLF_NoiseModel_colorDependent_normalization_offset*/
    int32_t lf_blf_noisemodel_colordependent_norm_offset;
    /*!< lf_blf_noisemodel_colordependent_gain_x[6] Param_LF_BLF_NoiseModel_colorDependent_Lut_X*/
    int32_t lf_blf_noisemodel_colordependent_gain_x[6];
    /*!< lf_blf_noisemodel_colordependent_gain_y[5] Param_LF_BLF_NoiseModel_colorDependent_Lut Config Unit Value*/
    int32_t lf_blf_noisemodel_colordependent_gain_y[5];
    /*!< lf_blf_noisemodel_colordependent_gain_slope[5] Slope*/
    int32_t lf_blf_noisemodel_colordependent_gain_slope[5];
    /*!< lf_blf_noisemodel_graydependent_graylevel_thresh Param_LF_BLF_NoiseModel_grayDependent_grayThrsh*/
    int32_t lf_blf_noisemodel_graydependent_graylevel_thresh;
    /*!< lf_blf_noisemodel_graydependent_graylevel_slope Param_LF_BLF_NoiseModel_grayDependent_graySlope*/
    int32_t lf_blf_noisemodel_graydependent_graylevel_slope;
    /*!< lf_blf_noisemodel_graydependent_gain_x[6] Param_LF_BLF_NoiseModel_grayDependent_transLut_X*/
    int32_t lf_blf_noisemodel_graydependent_gain_x[6];
    /*!< lf_blf_noisemodel_graydependent_gain_y[5] Param_LF_BLF_NoiseModel_grayDependent_transLut Config Unit Value*/
    int32_t lf_blf_noisemodel_graydependent_gain_y[5];
    /*!< lf_blf_noisemodel_graydependent_gain_slope[5] Slope*/
    int32_t lf_blf_noisemodel_graydependent_gain_slope[5];
    /*!< lf_blf_noisemodel_normfactor_y_y Param_LF_BLF_NoiseModel_invSigmaYy*/
    int32_t lf_blf_noisemodel_normfactor_y_y;
    /*!< lf_blf_noisemodel_normfactor_y_u Param_LF_BLF_NoiseModel_invSigmaYu*/
    int32_t lf_blf_noisemodel_normfactor_y_u;
    /*!< lf_blf_noisemodel_normfactor_y_v Param_LF_BLF_NoiseModel_invSigmaYv*/
    int32_t lf_blf_noisemodel_normfactor_y_v;
    /*!< lf_blf_noisemodel_normfactor_uv_y Param_LF_BLF_NoiseModel_invSigmaUVy*/
    int32_t lf_blf_noisemodel_normfactor_uv_y;
    /*!< lf_blf_noisemodel_normfactor_uv_u Param_LF_BLF_NoiseModel_invSigmaUVu*/
    int32_t lf_blf_noisemodel_normfactor_uv_u;
    /*!< lf_blf_noisemodel_normfactor_uv_v Param_LF_BLF_NoiseModel_invSigmaUVv*/
    int32_t lf_blf_noisemodel_normfactor_uv_v;
    /*!< lf_blf_snrm_bypass Param_LF_BLF_SNRM_bypassSNRManagement*/
    int32_t lf_blf_snrm_bypass;
    /*!< lf_blf_snrm_bypass_y Param_LF_BLF_SNRM_bypassY*/
    int32_t lf_blf_snrm_bypass_y;
    /*!< lf_blf_snrm_slope_y Param_LF_BLF_SNRM_slopeY*/
    int32_t lf_blf_snrm_slope_y;
    /*!< lf_blf_snrm_xoffset_y Param_LF_BLF_SNRM_xoffsetY*/
    int32_t lf_blf_snrm_xoffset_y;
    /*!< lf_blf_snrm_maxval_y Param_LF_BLF_SNRM_maxValY*/
    int32_t lf_blf_snrm_maxval_y;
    /*!< lf_blf_snrm_minval_y Param_LF_BLF_SNRM_minValY*/
    int32_t lf_blf_snrm_minval_y;
    /*!< lf_blf_snrm_slope_uv Param_LF_BLF_SNRM_slopeUV*/
    int32_t lf_blf_snrm_slope_uv;
    /*!< lf_blf_snrm_xoffset_uv Param_LF_BLF_SNRM_xoffsetUV*/
    int32_t lf_blf_snrm_xoffset_uv;
    /*!< lf_blf_snrm_maxval_uv Param_LF_BLF_SNRM_maxValUV*/
    int32_t lf_blf_snrm_maxval_uv;
    /*!< lf_blf_snrm_minval_uv Param_LF_BLF_SNRM_minValUV*/
    int32_t lf_blf_snrm_minval_uv;
    /*!< lf_blf_iir_alpha_y Param_LF_BLF_IIR_alphaY*/
    int32_t lf_blf_iir_alpha_y;
    /*!< lf_blf_iir_alpha_uv Param_LF_BLF_IIR_alphaUV*/
    int32_t lf_blf_iir_alpha_uv;
    /*!< lf_cs_bypass Param_LF_CS_bypassChromaSuppression*/
    int32_t lf_cs_bypass;
    /*!< lf_cs_coef Param_LF_CS_coef*/
    int32_t lf_cs_coef;
    /*!< lf_min_distance_clamp Param_LF_min_distance_clamp*/
    int32_t lf_min_distance_clamp;
    /*!< vlf_blf_fir_filter_length Param_VLF_BLF_FIR_BfLen*/
    int32_t vlf_blf_fir_filter_length;
    /*!< vlf_blf_fir_luma_coefs[6] Param_VLF_BLF_FIR_Kn_coef*/
    int32_t vlf_blf_fir_luma_coefs[6];
    /*!< vlf_blf_fir_luma_denom_bits Param_VLF_BLF_FIR_Kn_denom_bits*/
    int32_t vlf_blf_fir_luma_denom_bits;
    /*!< vlf_blf_fir_bypass_snr_y Param_VLF_BLF_FIR_bypasssSnrY*/
    int32_t vlf_blf_fir_bypass_snr_y;
    /*!< vlf_blf_colorspace Param_VLF_BLF_colorspaceYRB*/
    int32_t vlf_blf_colorspace;
    /*!< vlf_blf_noisemodel_basefunc_y_a_x[5] Param_VLF_BLF_NoiseModel_sigmaParafacY_A_X*/
    int32_t vlf_blf_noisemodel_basefunc_y_a_x[5];
    /*!< vlf_blf_noisemodel_basefunc_y_a_y[4] Param_VLF_BLF_NoiseModel_sigmaParafacY_A Config Unit Value*/
    int32_t vlf_blf_noisemodel_basefunc_y_a_y[4];
    /*!< vlf_blf_noisemodel_basefunc_y_a_slope[4] Slope*/
    int32_t vlf_blf_noisemodel_basefunc_y_a_slope[4];
    /*!< vlf_blf_noisemodel_basefunc_y_b_x[5] Param_VLF_BLF_NoiseModel_sigmaParafacY_B_X*/
    int32_t vlf_blf_noisemodel_basefunc_y_b_x[5];
    /*!< vlf_blf_noisemodel_basefunc_y_b_y[4] Param_VLF_BLF_NoiseModel_sigmaParafacY_B Config Unit Value*/
    int32_t vlf_blf_noisemodel_basefunc_y_b_y[4];
    /*!< vlf_blf_noisemodel_basefunc_y_b_slope[4] Slope*/
    int32_t vlf_blf_noisemodel_basefunc_y_b_slope[4];
    /*!< vlf_blf_noisemodel_basefunc_y_c_x[5] Param_VLF_BLF_NoiseModel_sigmaParafacY_C_X*/
    int32_t vlf_blf_noisemodel_basefunc_y_c_x[5];
    /*!< vlf_blf_noisemodel_basefunc_y_c_y[4] Param_VLF_BLF_NoiseModel_sigmaParafacY_C Config Unit Value*/
    int32_t vlf_blf_noisemodel_basefunc_y_c_y[4];
    /*!< vlf_blf_noisemodel_basefunc_y_c_slope[4] Slope*/
    int32_t vlf_blf_noisemodel_basefunc_y_c_slope[4];
    /*!< vlf_blf_noisemodel_basefunc_y_wbg Param_VLF_BLF_NoiseModel_sigmaParafacY_DEF*/
    int32_t vlf_blf_noisemodel_basefunc_y_wbg;
    /*!< vlf_blf_noisemodel_basefunc_u_a_x[5] Param_VLF_BLF_NoiseModel_sigmaParafacU_A_X*/
    int32_t vlf_blf_noisemodel_basefunc_u_a_x[5];
    /*!< vlf_blf_noisemodel_basefunc_u_a_y[4] Param_VLF_BLF_NoiseModel_sigmaParafacU_A Config Unit Value*/
    int32_t vlf_blf_noisemodel_basefunc_u_a_y[4];
    /*!< vlf_blf_noisemodel_basefunc_u_a_slope[4] Slope*/
    int32_t vlf_blf_noisemodel_basefunc_u_a_slope[4];
    /*!< vlf_blf_noisemodel_basefunc_u_b_x[5] Param_VLF_BLF_NoiseModel_sigmaParafacU_B_X*/
    int32_t vlf_blf_noisemodel_basefunc_u_b_x[5];
    /*!< vlf_blf_noisemodel_basefunc_u_b_y[4] Param_VLF_BLF_NoiseModel_sigmaParafacU_B Config Unit Value*/
    int32_t vlf_blf_noisemodel_basefunc_u_b_y[4];
    /*!< vlf_blf_noisemodel_basefunc_u_b_slope[4] Slope*/
    int32_t vlf_blf_noisemodel_basefunc_u_b_slope[4];
    /*!< vlf_blf_noisemodel_basefunc_u_c_x[5] Param_VLF_BLF_NoiseModel_sigmaParafacU_C_X*/
    int32_t vlf_blf_noisemodel_basefunc_u_c_x[5];
    /*!< vlf_blf_noisemodel_basefunc_u_c_y[4] Param_VLF_BLF_NoiseModel_sigmaParafacU_C Config Unit Value*/
    int32_t vlf_blf_noisemodel_basefunc_u_c_y[4];
    /*!< vlf_blf_noisemodel_basefunc_u_c_slope[4] Slope*/
    int32_t vlf_blf_noisemodel_basefunc_u_c_slope[4];
    /*!< vlf_blf_noisemodel_basefunc_u_wbg Param_VLF_BLF_NoiseModel_sigmaParafacU_DEF*/
    int32_t vlf_blf_noisemodel_basefunc_u_wbg;
    /*!< vlf_blf_noisemodel_basefunc_v_a_x[5] Param_VLF_BLF_NoiseModel_sigmaParafacV_A_X*/
    int32_t vlf_blf_noisemodel_basefunc_v_a_x[5];
    /*!< vlf_blf_noisemodel_basefunc_v_a_y[4] Param_VLF_BLF_NoiseModel_sigmaParafacV_A Config Unit Value*/
    int32_t vlf_blf_noisemodel_basefunc_v_a_y[4];
    /*!< vlf_blf_noisemodel_basefunc_v_a_slope[4] Slope*/
    int32_t vlf_blf_noisemodel_basefunc_v_a_slope[4];
    /*!< vlf_blf_noisemodel_basefunc_v_b_x[5] Param_VLF_BLF_NoiseModel_sigmaParafacV_B_X*/
    int32_t vlf_blf_noisemodel_basefunc_v_b_x[5];
    /*!< vlf_blf_noisemodel_basefunc_v_b_y[4] Param_VLF_BLF_NoiseModel_sigmaParafacV_B Config Unit Value*/
    int32_t vlf_blf_noisemodel_basefunc_v_b_y[4];
    /*!< vlf_blf_noisemodel_basefunc_v_b_slope[4] Slope*/
    int32_t vlf_blf_noisemodel_basefunc_v_b_slope[4];
    /*!< vlf_blf_noisemodel_basefunc_v_c_x[5] Param_VLF_BLF_NoiseModel_sigmaParafacV_C_X*/
    int32_t vlf_blf_noisemodel_basefunc_v_c_x[5];
    /*!< vlf_blf_noisemodel_basefunc_v_c_y[4] Param_VLF_BLF_NoiseModel_sigmaParafacV_C Config Unit Value*/
    int32_t vlf_blf_noisemodel_basefunc_v_c_y[4];
    /*!< vlf_blf_noisemodel_basefunc_v_c_slope[4] Slope*/
    int32_t vlf_blf_noisemodel_basefunc_v_c_slope[4];
    /*!< vlf_blf_noisemodel_basefunc_v_wbg Param_VLF_BLF_NoiseModel_sigmaParafacV_DEF*/
    int32_t vlf_blf_noisemodel_basefunc_v_wbg;
    /*!< vlf_blf_noisemodel_weight_y_y Param_VLF_BLF_NoiseModel_sigmaWgtYy*/
    int32_t vlf_blf_noisemodel_weight_y_y;
    /*!< vlf_blf_noisemodel_weight_y_u Param_VLF_BLF_NoiseModel_sigmaWgtYu*/
    int32_t vlf_blf_noisemodel_weight_y_u;
    /*!< vlf_blf_noisemodel_weight_y_v Param_VLF_BLF_NoiseModel_sigmaWgtYv*/
    int32_t vlf_blf_noisemodel_weight_y_v;
    /*!< vlf_blf_noisemodel_weight_uv_y Param_VLF_BLF_NoiseModel_sigmaWgtUVy*/
    int32_t vlf_blf_noisemodel_weight_uv_y;
    /*!< vlf_blf_noisemodel_weight_uv_u Param_VLF_BLF_NoiseModel_sigmaWgtUVu*/
    int32_t vlf_blf_noisemodel_weight_uv_u;
    /*!< vlf_blf_noisemodel_weight_uv_v Param_VLF_BLF_NoiseModel_sigmaWgtUVv*/
    int32_t vlf_blf_noisemodel_weight_uv_v;
    /*!< vlf_blf_noisemodel_radialdependent_bypass Param_VLF_BLF_NoiseModel_bypassRadialCorrection*/
    int32_t vlf_blf_noisemodel_radialdependent_bypass;
    /*!< vlf_blf_noisemodel_colordependent_bypass Param_VLF_BLF_NoiseModel_bypassColorDependent*/
    int32_t vlf_blf_noisemodel_colordependent_bypass;
    /*!< vlf_blf_noisemodel_radialdependent_x0_square Param_VLF_BLF_NoiseModel_radialDependent_x0_square*/
    int32_t vlf_blf_noisemodel_radialdependent_x0_square;
    /*!< vlf_blf_noisemodel_radialdependent_x0 Param_VLF_BLF_NoiseModel_radialDependent_x0*/
    int32_t vlf_blf_noisemodel_radialdependent_x0;
    /*!< vlf_blf_noisemodel_radialdependent_y0_square Param_VLF_BLF_NoiseModel_radialDependent_y0_square*/
    int32_t vlf_blf_noisemodel_radialdependent_y0_square;
    /*!< vlf_blf_noisemodel_radialdependent_y0 Param_VLF_BLF_NoiseModel_radialDependent_y0*/
    int32_t vlf_blf_noisemodel_radialdependent_y0;
    /*!< vlf_blf_noisemodel_radialdependent_rshift_norm_square_distance Param_VLF_BLF_NoiseModel_radialDependent_rshiftNormSquareDist*/
    int32_t vlf_blf_noisemodel_radialdependent_rshift_norm_square_distance;
    /*!< vlf_blf_noisemodel_radialdependent_gain_x[4] Param_VLF_BLF_NoiseModel_radialDependent_radialLut_X*/
    int32_t vlf_blf_noisemodel_radialdependent_gain_x[4];
    /*!< vlf_blf_noisemodel_radialdependent_gain_y[3] Param_VLF_BLF_NoiseModel_radialDependent_radialLut Config Unit Value*/
    int32_t vlf_blf_noisemodel_radialdependent_gain_y[3];
    /*!< vlf_blf_noisemodel_radialdependent_gain_slope[3] Slope*/
    int32_t vlf_blf_noisemodel_radialdependent_gain_slope[3];
    /*!< vlf_blf_noisemodel_colordependent_a[32] Param_VLF_BLF_NoiseModel_colorDependent_A*/
    int32_t vlf_blf_noisemodel_colordependent_a[32];
    /*!< vlf_blf_noisemodel_colordependent_b[32] Param_VLF_BLF_NoiseModel_colorDependent_B*/
    int32_t vlf_blf_noisemodel_colordependent_b[32];
    /*!< vlf_blf_noisemodel_colordependent_c[32] Param_VLF_BLF_NoiseModel_colorDependent_C*/
    int32_t vlf_blf_noisemodel_colordependent_c[32];
    /*!< vlf_blf_noisemodel_colordependent_norm_offset Param_VLF_BLF_NoiseModel_colorDependent_normalization_offset*/
    int32_t vlf_blf_noisemodel_colordependent_norm_offset;
    /*!< vlf_blf_noisemodel_colordependent_gain_x[6] Param_VLF_BLF_NoiseModel_colorDependent_Lut_X*/
    int32_t vlf_blf_noisemodel_colordependent_gain_x[6];
    /*!< vlf_blf_noisemodel_colordependent_gain_y[5] Param_VLF_BLF_NoiseModel_colorDependent_Lut Config Unit Value*/
    int32_t vlf_blf_noisemodel_colordependent_gain_y[5];
    /*!< vlf_blf_noisemodel_colordependent_gain_slope[5] Slope*/
    int32_t vlf_blf_noisemodel_colordependent_gain_slope[5];
    /*!< vlf_blf_noisemodel_graydependent_gain_x[6] Param_VLF_BLF_NoiseModel_grayDependent_transLut_X*/
    int32_t vlf_blf_noisemodel_graydependent_gain_x[6];
    /*!< vlf_blf_noisemodel_graydependent_gain_y[5] Param_VLF_BLF_NoiseModel_grayDependent_transLut Config Unit Value*/
    int32_t vlf_blf_noisemodel_graydependent_gain_y[5];
    /*!< vlf_blf_noisemodel_graydependent_gain_slope[5] Slope*/
    int32_t vlf_blf_noisemodel_graydependent_gain_slope[5];
    /*!< vlf_blf_noisemodel_normfactor_y_y Param_VLF_BLF_NoiseModel_invSigmaYy*/
    int32_t vlf_blf_noisemodel_normfactor_y_y;
    /*!< vlf_blf_noisemodel_normfactor_y_u Param_VLF_BLF_NoiseModel_invSigmaYu*/
    int32_t vlf_blf_noisemodel_normfactor_y_u;
    /*!< vlf_blf_noisemodel_normfactor_y_v Param_VLF_BLF_NoiseModel_invSigmaYv*/
    int32_t vlf_blf_noisemodel_normfactor_y_v;
    /*!< vlf_blf_noisemodel_normfactor_uv_y Param_VLF_BLF_NoiseModel_invSigmaUVy*/
    int32_t vlf_blf_noisemodel_normfactor_uv_y;
    /*!< vlf_blf_noisemodel_normfactor_uv_u Param_VLF_BLF_NoiseModel_invSigmaUVu*/
    int32_t vlf_blf_noisemodel_normfactor_uv_u;
    /*!< vlf_blf_noisemodel_normfactor_uv_v Param_VLF_BLF_NoiseModel_invSigmaUVv*/
    int32_t vlf_blf_noisemodel_normfactor_uv_v;
    /*!< vlf_blf_iir_alpha_y Param_VLF_BLF_IIR_alphaY*/
    int32_t vlf_blf_iir_alpha_y;
    /*!< vlf_blf_iir_alpha_uv Param_VLF_BLF_IIR_alphaUV*/
    int32_t vlf_blf_iir_alpha_uv;
    /*!< vlf_cs_bypass Param_VLF_CS_bypassChromaSuppression*/
    int32_t vlf_cs_bypass;
    /*!< vlf_cs_coef Param_VLF_CS_coef*/
    int32_t vlf_cs_coef;
    /*!< vlf_min_distance_clamp Param_VLF_min_distance_clamp*/
    int32_t vlf_min_distance_clamp;
    /*!< vhf_blf_noisemodel_basefunc_y_a_x[5] Param_VHF_BLF_NoiseModel_sigmaParafacY_A_X*/
    int32_t vhf_blf_noisemodel_basefunc_y_a_x[5];
    /*!< vhf_blf_noisemodel_basefunc_y_a_y[4] Param_VHF_BLF_NoiseModel_sigmaParafacY_A Config Unit Value*/
    int32_t vhf_blf_noisemodel_basefunc_y_a_y[4];
    /*!< vhf_blf_noisemodel_basefunc_y_a_slope[4] Slope*/
    int32_t vhf_blf_noisemodel_basefunc_y_a_slope[4];
    /*!< vhf_blf_noisemodel_basefunc_y_wbg Param_VHF_BLF_NoiseModel_sigmaParafacY_DEF*/
    int32_t vhf_blf_noisemodel_basefunc_y_wbg;
    /*!< vhf_blf_noisemodel_weight_y_y Param_VHF_BLF_NoiseModel_sigmaWgtYy*/
    int32_t vhf_blf_noisemodel_weight_y_y;
    /*!< vhf_blf_noisemodel_radialdependent_bypass Param_VHF_BLF_NoiseModel_bypassRadialCorrection*/
    int32_t vhf_blf_noisemodel_radialdependent_bypass;
    /*!< vhf_blf_noisemodel_radialdependent_x0_square Param_VHF_BLF_NoiseModel_radialDependent_x0_square*/
    int32_t vhf_blf_noisemodel_radialdependent_x0_square;
    /*!< vhf_blf_noisemodel_radialdependent_x0 Param_VHF_BLF_NoiseModel_radialDependent_x0*/
    int32_t vhf_blf_noisemodel_radialdependent_x0;
    /*!< vhf_blf_noisemodel_radialdependent_y0_square Param_VHF_BLF_NoiseModel_radialDependent_y0_square*/
    int32_t vhf_blf_noisemodel_radialdependent_y0_square;
    /*!< vhf_blf_noisemodel_radialdependent_y0 Param_VHF_BLF_NoiseModel_radialDependent_y0*/
    int32_t vhf_blf_noisemodel_radialdependent_y0;
    /*!< vhf_blf_noisemodel_radialdependent_rshift_norm_square_distance Param_VHF_BLF_NoiseModel_radialDependent_rshiftNormSquareDist*/
    int32_t vhf_blf_noisemodel_radialdependent_rshift_norm_square_distance;
    /*!< vhf_blf_noisemodel_radialdependent_gain_x[4] Param_VHF_BLF_NoiseModel_radialDependent_radialLut_X*/
    int32_t vhf_blf_noisemodel_radialdependent_gain_x[4];
    /*!< vhf_blf_noisemodel_radialdependent_gain_y[3] Param_VHF_BLF_NoiseModel_radialDependent_radialLut Config Unit Value*/
    int32_t vhf_blf_noisemodel_radialdependent_gain_y[3];
    /*!< vhf_blf_noisemodel_radialdependent_gain_slope[3] Slope*/
    int32_t vhf_blf_noisemodel_radialdependent_gain_slope[3];
    /*!< vhf_blf_noisemodel_normfactor_y_y Param_VHF_BLF_NoiseModel_invSigmaYy*/
    int32_t vhf_blf_noisemodel_normfactor_y_y;
    /*!< vhf_blf_bypass Param_VHF_BLF_bypass*/
    int32_t vhf_blf_bypass;
    /*!< vhf_min_distance_clamp Param_VHF_min_distance_clamp*/
    int32_t vhf_min_distance_clamp;
    /*!< hf_lcs_cu_slope[5] PARAM_HFC_LCS_CU_SLOPE*/
    int32_t hf_lcs_cu_slope[5];
    /*!< hf_lcs_cu_x[6] PARAM_HFC_LCS_CU_X*/
    int32_t hf_lcs_cu_x[6];
    /*!< hf_lcs_cu_y[5] PARAM_HFC_LCS_CU_Y*/
    int32_t hf_lcs_cu_y[5];
    /*!< hf_lcs_bypass Param_HFC_LCS_bypass*/
    int32_t hf_lcs_bypass;
    /*!< hf_lcs_thresh_high HFC_LCS_THRESHOLD_HIGH*/
    uint32_t hf_lcs_thresh_high;
    /*!< hf_lcs_thresh_low PARAM_HFC_LCS_THRESH_LOW*/
    uint32_t hf_lcs_thresh_low;
    /*!< hf_lcs_chm_gain PARAM_HFC_LCS_CHM_GAIN*/
    uint32_t hf_lcs_chm_gain;
    /*!< hf_lcs_ylocal_size ylocal filter size 0 - 5x5, 1 - 7x7*/
    uint32_t hf_lcs_ylocal_size;
    /*!< hf_lcs_chm_size chroma metric filter size 0 - 5x5, 1 - 7x7*/
    uint32_t hf_lcs_chm_size;
    /*!< vlf_power_uv VLF denoise power chroma*/
    int32_t vlf_power_uv;
    /*!< vlf_power_y VLF denoise power luma*/
    int32_t vlf_power_y;
    /*!< lf_power_uv LF denoise power chroma*/
    int32_t lf_power_uv;
    /*!< lf_power_y VLF denoise power luma*/
    int32_t lf_power_y;
    /*!< mf_power_uv MF denoise power chroma*/
    int32_t mf_power_uv;
    /*!< mf_power_y MF denoise power luma*/
    int32_t mf_power_y;
    /*!< hf_power_uv HF denoise power chroma*/
    int32_t hf_power_uv;
    /*!< vhf_power_y VHF denoise power luma*/
    int32_t vhf_power_y;
    /*!< top_ds_2x_coefs[5] 1:2 downscaling filter coefficients*/
    int32_t top_ds_2x_coefs[5];
    /*!< top_ds_4x_coefs[7] 1:4 downscaling filter coefficients*/
    int32_t top_ds_4x_coefs[7];

} ia_pal_isp_xnr_5_2_t;

/*! \isp struct xnr_dss
Scalable Chroma and Luma Denoise, Medium and High Frequency
*/
typedef struct
{
    /*!< jbl_mf_bypass_y Bypass JBL MF Luma*/
    int32_t jbl_mf_bypass_y;
    /*!< jbl_mf_bypass_c Bypass MF Chroma*/
    int32_t jbl_mf_bypass_c;
    /*!< noise_sigma_mf_y_y Noise Sigma MF Luma per Luma*/
    int32_t noise_sigma_mf_y_y;
    /*!< noise_sigma_mf_y_s Noise Sigma MF Luma per Satoration*/
    int32_t noise_sigma_mf_y_s;
    /*!< noise_sigma_mf_c_y Noise Sigma MF Chroma per Luma*/
    int32_t noise_sigma_mf_c_y;
    /*!< noise_sigma_mf_c_u Noise Sigma MF Chroma per U*/
    int32_t noise_sigma_mf_c_u;
    /*!< noise_sigma_mf_c_v Noise Sigma MF Chroma per V*/
    int32_t noise_sigma_mf_c_v;
    /*!< rad_noise_sigma_mf_y_y Noise Sigma MF Luma per Luma - radial*/
    int32_t rad_noise_sigma_mf_y_y;
    /*!< rad_noise_sigma_mf_y_s Noise Sigma MF Luma per Satoration - radial*/
    int32_t rad_noise_sigma_mf_y_s;
    /*!< rad_noise_sigma_mf_c_y Noise Sigma MF Chroma per Luma - radial*/
    int32_t rad_noise_sigma_mf_c_y;
    /*!< rad_noise_sigma_mf_c_u Noise Sigma MF Chroma per U - radial*/
    int32_t rad_noise_sigma_mf_c_u;
    /*!< rad_noise_sigma_mf_c_v Noise Sigma MF Chroma per V - radial*/
    int32_t rad_noise_sigma_mf_c_v;
    /*!< noise_epsilon_mf_y_y Luma min noise variance per Luma , Q12*/
    int32_t noise_epsilon_mf_y_y;
    /*!< noise_epsilon_mf_c_y Chroma min noise variance per Luma , Q12*/
    int32_t noise_epsilon_mf_c_y;
    /*!< noise_epsilon_mf_c_u Chroma min noise variance per U , Q12*/
    int32_t noise_epsilon_mf_c_u;
    /*!< noise_epsilon_mf_c_v Chroma min noise variance per V , Q12*/
    int32_t noise_epsilon_mf_c_v;
    /*!< rad_noise_epsilon_mf_y_y Luma min noise variance per Luma , Q12 - radial*/
    int32_t rad_noise_epsilon_mf_y_y;
    /*!< rad_noise_epsilon_mf_c_y Chroma min noise variance per Luma , Q12 - radial*/
    int32_t rad_noise_epsilon_mf_c_y;
    /*!< rad_noise_epsilon_mf_c_u Chroma min noise variance per U , Q12 - radial*/
    int32_t rad_noise_epsilon_mf_c_u;
    /*!< rad_noise_epsilon_mf_c_v Chroma min noise variance per V , Q12 - radial*/
    int32_t rad_noise_epsilon_mf_c_v;
    /*!< jbl_weight_th_mf_y Luma Weight threshold of MF JBL*/
    int32_t jbl_weight_th_mf_y;
    /*!< jbl_weight_th_mf_c Chroma Weight threshold of MF JBL*/
    int32_t jbl_weight_th_mf_c;
    /*!< lpf_mf_coef_y[49] MF JBL Spatial coefs for Luma*/
    int32_t lpf_mf_coef_y[49];
    /*!< lpf_mf_coef_c[49] MF JBL Spatial coefs for Chroma*/
    int32_t lpf_mf_coef_c[49];
    /*!< range_weight_lut[7] JBL range Weight LUT*/
    int32_t range_weight_lut[7];
    /*!< blend_mf_power_y MF denoise blending power y*/
    int32_t blend_mf_power_y;
    /*!< blend_mf_power_c MF denoise blending power chroma*/
    int32_t blend_mf_power_c;
    /*!< rad_blend_mf_power_y MF denoise blending power y - radial*/
    int32_t rad_blend_mf_power_y;
    /*!< rad_blend_mf_power_c MF denoise blending power chroma -radial*/
    int32_t rad_blend_mf_power_c;
    /*!< noise_beta_y_0 noise model for y - coef 0, Q12*/
    int32_t noise_beta_y_0;
    /*!< noise_beta_u_0 noise model for u - coef 0, Q12*/
    int32_t noise_beta_u_0;
    /*!< noise_beta_u_1 noise model for u - coef 1, Q12*/
    int32_t noise_beta_u_1;
    /*!< noise_beta_v_0 noise model for v - coef 0, Q12*/
    int32_t noise_beta_v_0;
    /*!< noise_beta_v_2 noise model for v - coef 2, Q12*/
    int32_t noise_beta_v_2;
    /*!< rad_center_x X location of the radial center location relative to the top left pixel*/
    int32_t rad_center_x;
    /*!< rad_center_y Y location of the radial center location relative to the top left pixel*/
    int32_t rad_center_y;
    /*!< rad_exp Radial scale bit into the Lut*/
    int32_t rad_exp;
    /*!< rad_lut[128] Radial LUT*/
    int32_t rad_lut[128];
    /*!< one_div_64_lut[64] 1/SQRT(x), first 64 values LUT*/
    int32_t one_div_64_lut[64];
    /*!< xcu_divsqrt_exp XCU divsqrt exponent*/
    int32_t xcu_divsqrt_exp;
    /*!< xcu_divsqrt_slp_a_res XCU divsqrt slope precision*/
    int32_t xcu_divsqrt_slp_a_res;
    /*!< xcu_divsqrt_offset[16] XCU divsqrt offset(y) vector*/
    int32_t xcu_divsqrt_offset[16];
    /*!< xcu_divsqrt_slope[16] XCU divsqrt slope vector*/
    int32_t xcu_divsqrt_slope[16];
    /*!< xcu_divsqrt_x[17] XCU divsqrt x points vector + maximal x value*/
    int32_t xcu_divsqrt_x[17];
    /*!< lcs_th_low Low Chroma Suppertion threshold for black level*/
    int32_t lcs_th_low;
    /*!< lcs_th_high_delta Low Chroma Suppertion threshold for white level (delta from black)*/
    int32_t lcs_th_high_delta;
    /*!< rad_lcs_th_low Low Chroma Suppertion threshold for black level - radial (delta from low)*/
    int32_t rad_lcs_th_low;
    /*!< rad_lcs_th_high_delta Low Chroma Suppertion threshold for white level -radial (delta form high delta)*/
    int32_t rad_lcs_th_high_delta;
    /*!< xcu_lcs_exp XCU ed exponent*/
    int32_t xcu_lcs_exp;
    /*!< xcu_lcs_slp_a_res XCU ed slope precision*/
    int32_t xcu_lcs_slp_a_res;
    /*!< xcu_lcs_offset[32] XCU ed offset(y) vector*/
    int32_t xcu_lcs_offset[32];
    /*!< xcu_lcs_slope[32] XCU ed slope vector*/
    int32_t xcu_lcs_slope[32];
    /*!< xcu_lcs_x[33] XCU ed x points vector + maximal x value*/
    int32_t xcu_lcs_x[33];
    /*!< hf_luma_power HF Luma denoise power, Q15*/
    int32_t hf_luma_power;
    /*!< blend_hf_power_y HF blending power luma*/
    int32_t blend_hf_power_y;
    /*!< blend_hf_power_c HF blending power chroma*/
    int32_t blend_hf_power_c;

} ia_pal_isp_xnr_dss_t;



/* System API Structs */

#pragma pack(push, 4)

typedef struct
{
    uint16_t system_api_uuid;
} ia_pal_system_api_record_header_t;

/*! \system api struct bnlm_3_3
noise reduction
*/
typedef struct
{
    /*!< YUV_processing indicates if input is YUV, otherwise Bayer*/
    uint8_t YUV_processing;

} ia_pal_system_api_bnlm_3_3_t;

/*! \system api struct compression

*/
typedef struct
{
    /*!< bitdepth[2] bitdepth of source*/
    int32_t bitdepth[2];
    /*!< bw_cmp_ratio_minus[2] Lower threshold on compression ratio - hysteresis.*/
    int32_t bw_cmp_ratio_minus[2];
    /*!< bw_cmp_ratio_plus[2] Upper bound on compression ratio + hysteresis.*/
    int32_t bw_cmp_ratio_plus[2];
    /*!< bw_inst_lower[2] Lower threshold for the instant compression value to QP generation*/
    int32_t bw_inst_lower[2];
    /*!< bw_inst_upper[2] Upper threshold for the instant compression value to QP generation*/
    int32_t bw_inst_upper[2];
    /*!< cmp_enable[2] When set, this frame is being compressed/decompressed.*/
    int32_t cmp_enable[2];
    /*!< enable When set, this frame is being compressed/decompressed.*/
    int32_t enable;
    /*!< fp_cmp_ratio[2] Specifies the hard constraint on the compressed size of each macro-page.*/
    int32_t fp_cmp_ratio[2];
    /*!< fp_comp_enable[2] when lossy is enabled, this decides if compression is BW or FP*/
    int32_t fp_comp_enable[2];
    /*!< fp_guard_band_log[2] Guard band for FP compression that reduces probability of needing evasive action towards the end of the macro-page*/
    int32_t fp_guard_band_log[2];
    /*!< init_history[2] Value with which the elements in the moving average window are initialized.*/
    int32_t init_history[2];
    /*!< init_qp[2] Specifies the value to which current QP is initialized at the beginning of each frame*/
    int32_t init_qp[2];
    /*!< lossy_cfg[2] decides lossless or lossy*/
    int32_t lossy_cfg[2];
    /*!< ma_win_size[2] Window size (i.e. number of history element) for moving average*/
    int32_t ma_win_size[2];
    /*!< max_qp[2] Specifies the minimum QP that the bitrate control algorithm is allowed to use*/
    int32_t max_qp[2];
    /*!< max_qp_dec[2] Counter that determines how quickly the upper limit of QP can be decreased after footprint is under control.*/
    int32_t max_qp_dec[2];
    /*!< max_qp_inc[2] Counter that determines how quickly the upper limit of QP can be increased to keep footprint under control.*/
    int32_t max_qp_inc[2];
    /*!< min_qp[2] Specifies the maximum QP that the bitrate control algorithm is allowed to use*/
    int32_t min_qp[2];
    /*!< qp_inc_rst_val[2] When maximal QP is incremented or decremented, the counters are initiated with this values*/
    int32_t qp_inc_rst_val[2];
    /*!< src_stride[2] Surface stride in bytes. Stride is the distance in bytes between the first pixel of the first tile to the first pixel is the tile which is below the first tile.*/
    int32_t src_stride[2];

} ia_pal_system_api_compression_t;

/*! \system api struct decompression

*/
typedef struct
{
    /*!< bitdepth[2] bitdepth of source*/
    int32_t bitdepth[2];
    /*!< cmp_enable[2] When set, this frame is being compressed/decompressed.*/
    int32_t cmp_enable[2];
    /*!< enable When set, this frame is being compressed/decompressed.*/
    int32_t enable;
    /*!< fp_cmp_ratio[2] Specifies the hard constraint on the compressed size of each macro-page.*/
    int32_t fp_cmp_ratio[2];
    /*!< fp_comp_enable[2] when lossy is enabled, this decides if compression is BW or FP*/
    int32_t fp_comp_enable[2];
    /*!< lossy_cfg[2] decides lossless or lossy*/
    int32_t lossy_cfg[2];
    /*!< src_stride[2] Surface stride in bytes. Stride is the distance in bytes between the first pixel of the first tile to the first pixel is the tile which is below the first tile.*/
    int32_t src_stride[2];

} ia_pal_system_api_decompression_t;

/*! \system api struct gdc7

*/
typedef struct
{
    /*!< gdc_sp_standalone indicated if gdc_sp is used in standalone mode ( 0: used with gdc_FP, 1: used in standalone)*/
    uint8_t gdc_sp_standalone;
    /*!< small_memory Indicates whether we work with small memory or not, to enable/disable max_distortion mechanism (enabled only when working with small memory)*/
    uint8_t small_memory;

} ia_pal_system_api_gdc7_t;

/*! \system api struct io_buffer

*/
typedef struct
{
    /*!< aligner_data_size amount of valid bits per valid cycle to be accumulate and use the aligner (valid when dpa_bypass is set). LSB represent 2b resolution (meaning value can be 2, 4, 6, 8, … up to 72 which is the size bus)*/
    int32_t aligner_data_size;
    /*!< arbiter_pin MIPI CSI arbiter pin location of the stream*/
    int32_t arbiter_pin;
    /*!< block_height buffer block height configuration in lines*/
    uint16_t block_height;
    /*!< block_width buffer block width configuration in pixels*/
    uint16_t block_width;
    /*!< buffer_1d_enable Valid only for 1 plane and 1 queue streams. 0-the buffer is described as 2D; 1-the buffer is described as 1D (continues from start to end w/o stride ignoring lines)*/
    uint8_t buffer_1d_enable;
    /*!< chroma_base_conversion chroma converted from zero-based to half-based or vice versa*/
    uint8_t chroma_base_conversion;
    /*!< chroma_duplication Valid when format 420 is configured to provide 422 (2P2Q with SIF count of 4 or 2). when reset - duplicate the chroma and provide the same value each two Y lines, when set - send the chroma components only with the even Y (at odd Y lines doesn’t send any chroma)*/
    uint8_t chroma_duplication;
    /*!< chroma_planes_order Chroma planes ordering: 0 - U before V; 1 - V before U (valid for half planer configuration)*/
    uint8_t chroma_planes_order;
    /*!< component_in_valid_pixel Provides amount of valid component per valid pixel*/
    uint8_t component_in_valid_pixel;
    /*!< component_precision Pixel element precision in bits: 0=>8b, 1=>10b, 2=>12b, 3=>16, 4=>32, 5=>2, 6=>4, 7..15=>reserved*/
    uint8_t component_precision;
    /*!< compression_mode Valid for streaming that are tiled: 1-the stream is written/fetched to/from DDR through compression engine; 0-not going through compression*/
    uint8_t compression_mode;
    /*!< dpa_bypass When set indicate the end of MIPI frame (used for MIPI CSI sub frames)*/
    uint8_t dpa_bypass;
    /*!< first_row_blocks_height buffer block height configuration in lines of all the blocks in the first row of blocks. If zero - use streaming_buffer_blocks_height*/
    uint16_t first_row_blocks_height;
    /*!< granularity_pointer_update Valid according the streaming mode: number of lines (LB)/lines of blocks (BB) to be written/release before sending a pointer update (reporting always done with producer view)*/
    uint16_t granularity_pointer_update;
    /*!< in_chroma_signed chroma in input is signed (1) or unsigned (0)*/
    uint8_t in_chroma_signed;
    /*!< in_luma_signed luma in input is signed (1) or unsigned (0)*/
    uint8_t in_luma_signed;
    /*!< last_row_blocks_height buffer block height configuration in lines of all the blocks in the last row of blocks. If zero - use streaming_buffer_blocks_height*/
    uint16_t last_row_blocks_height;
    /*!< local_link_id indicates the stream used at the current connectlon*/
    uint8_t local_link_id;
    /*!< luma_base_conversion luma converted from zero-based to half-based or vice versa*/
    uint8_t luma_base_conversion;
    /*!< max_credits provides the maximum amount of credits for eliminating the need to calculate it in HW according the next formula: (end_address-start_address)/Max_Stride*/
    uint32_t max_credits;
    /*!< max_stride provides the maximum stride value to be used at the connection*/
    uint32_t max_stride;
    /*!< middle_ack_enable If set, enable the mechansim to generate middle ack when consumed amount of configured lines*/
    uint8_t middle_ack_enable;
    /*!< middle_ack_line_number Valid if ack enable  If enabled, the device should generate middle ack when delivers the EOL of the configured line (global number) assuming the first line delievered at SOF is zero.  In case of multiple planes the counting is done using plane1 but only when all the planes are synced*/
    uint16_t middle_ack_line_number;
    /*!< middle_ack_mode_stall Valid only when ack_enable is set When set, the device should stall once sending the middle ack*/
    uint8_t middle_ack_mode_stall;
    /*!< mipi_csi_eof When set indicate the end of MIPI frame (used for MIPI CSI sub frames)*/
    uint8_t mipi_csi_eof;
    /*!< num_of_planes Amount of valid planes (supported 1, 2, 3, 4 - depends also on HW parameter of max planes and data type)*/
    uint8_t num_of_planes;
    /*!< num_of_queues Amount of total active queues (YUV FP - 4, YUV SP - 3 YUV SP Tile - 2. RGB - 1,1,1. Bayer -2). Must be up to amount of maximum queue supported. Can be changed per frame. At LBFF used dynamicly for PDAF*/
    uint8_t num_of_queues;
    /*!< onep_pixel_order Set the ordering of the first plane (lines-N, pixels-M) 4PPC: 0-(N, M), (N, M+1), (N+1, M), (N+1, M+1), horizontal raster; 1-(N, M), (N+1, M), (N, M+1), (N+1, M+1), vertical raster 2PPC: 0-first cyc: (N, M), (N+1, M), second cyc: (N, M+1), (N+1, M+1); 1-first cyc: (N, M), (N, M+1),*/
    uint8_t onep_pixel_order;
    /*!< out_chroma_signed chroma in output is signed (1) or unsigned (0)*/
    uint8_t out_chroma_signed;
    /*!< out_luma_signed luma in output is signed (1) or unsigned (0)*/
    uint8_t out_luma_signed;
    /*!< pace_message_pace_line Provides the line number indicating to stop measuring the activity and pace and sending pace meesage (at IFD - get the last data of the line, at ODR - getnon-buf ack on last data of the line)*/
    uint16_t pace_message_pace_line;
    /*!< pace_message_ref_line Provides the line number that when start indicating start measuring the pace and active  (ODR - send first WR of the line, IFD send first RD of line)*/
    uint16_t pace_message_ref_line;
    /*!< pixels_in_valid_cycle Provides amount of valid pixels per valid cycle*/
    uint8_t pixels_in_valid_cycle;
    /*!< plane_horiz_subsample_config[3] Plane Horiz subsample (width>>N).  Affect tile width and width resolution=>Bayer - 0, Y/UV at YUV SP - 0, Y at YUV FP -0, UV U/V at YUV FP-1)*/
    uint8_t plane_horiz_subsample_config[3];
    /*!< plane_max_burst_size[3] Plane maximum burst size: used to specify the transfer size in CL granularity (Max limited to 16, possible values - 1, 2, 4, 8, 16)*/
    uint8_t plane_max_burst_size[3];
    /*!< plane_offset_end_address[3] Per plane: End offset address of plane with regarding to the base_offset, in bytes, CL aligned, unsigned.*/
    uint32_t plane_offset_end_address[3];
    /*!< plane_offset_start_address[3] Per plane: Start offset address of plane with regarding to the base_offset, in bytes, CL aligned, unsigned.*/
    uint32_t plane_offset_start_address[3];
    /*!< plane_stride[3] Per plane: provides the difference between two horizontal pixels, in bytes, CL aligned, unsigned.  At tile mode - provide the difference between two lines of tiles in bytes*/
    uint32_t plane_stride[3];
    /*!< plane_tile_height[3] Per plane: buffer tile height configuration in lines*/
    uint8_t plane_tile_height[3];
    /*!< plane_tile_width[3] Per plane: buffer tile width configuration in bytes*/
    uint8_t plane_tile_width[3];
    /*!< plane_vert_subsample_config[3] Plane Vertical subsample (height>>N). Affect tile highet and highet resolution=>Bayer - 0, Y atYUV SP - 0, UV at YUV SP - 1, Y at YUV FP -0, U/V at YUV FP-1)*/
    uint8_t plane_vert_subsample_config[3];
    /*!< plane_zlr_granularity[3] Plane ZLR page granularity: if 0 - 4KB, if 1 - 2KB. Valid only if ZLR is enalbe*/
    uint8_t plane_zlr_granularity[3];
    /*!< ppc provides the amount of pixel per cycle*/
    uint8_t ppc;
    /*!< proc_ff_bypass when set indicates the FF in the pipe (FCVT & ESPA) need to be bypass*/
    uint8_t proc_ff_bypass;
    /*!< progress_message_line Provides the line number that when is done generate progress message (IFD - last byte of the line arrive, ODR - last byte of the line acked by nbuf)*/
    uint16_t progress_message_line;
    /*!< stream_dt stream data type as need to be used by the MIPI*/
    uint8_t stream_dt;
    /*!< stream_dt_for_mipi_packet stream data type as need to be used in the header of mipi packet - not affect the proc*/
    int32_t stream_dt_for_mipi_packet;
    /*!< stream_vc stream virtual channel number as need to be used in MIPI*/
    uint8_t stream_vc;
    /*!< stream_wc stream word count as need to be used by the MIPI*/
    uint16_t stream_wc;
    /*!< streaming_mode The streaming unified buffer protocol:  0-static offline (producer/consumer write/read from DDR after kick);  1-dynamic offline (producer/consumer send wr/rd EOF/SOF, producer write after kick, consumer read after full frame at DDR);  2-buffer chasing large memory (producer/consumer send wr/rd EOF/SOF, producer send wr update, consumer read according to wr update);  3-buffer chasing on small memory (producer/consumer send wr/rd EOF/SOF, producer write released buffers and sends wr pointers, consumer read valid buffer and sends rd pointer);  4-S&R like 3 with option to change the link (supporting modes 2 and 3 with dynamic change) 5-buffer chasing small memory - fix starting point, single buffer 6-buffer chasing small memory - float starting point 7-buffer chasing small memory - fix starting point, double buffer*/
    uint8_t streaming_mode;
    /*!< streaming_sw_managed When set - the SW verify the shared buffer is fully consumed by  the producer and can be written immediately*/
    uint8_t streaming_sw_managed;
    /*!< stride_ratio provides the BCSM max_stride/stride ratio with possible values of 1-8, 16, 32, 64, 128*/
    uint8_t stride_ratio;
    /*!< subsample_YUV444_to_YUV422 Used by ODR to convert YUV444 to YUV422: 0-use amount of element as written at components_in_valid_cycle, 1-drop the chroma components any odd cycle*/
    uint8_t subsample_YUV444_to_YUV422;
    /*!< tile_mode Valid for IO that can provide tile format: 0-no tiling; 1-the IO should use tiling with the configured height, width, and tiling type (internal tiling or external Tile-4)*/
    uint8_t tile_mode;
    /*!< tiling_type Tiling Type: 0 - internal tiling; 1 - external tiling (Tile-4)*/
    uint8_t tiling_type;
    /*!< unpack_alignment Valid for unpacked vectors: 0-element located at LSB and MSB is zero; 1-element located at MSB and LSB is zero*/
    uint8_t unpack_alignment;
    /*!< use_attributes This capability impact the ODR. When set, ODR should use the EOL/EOF attributes to detect frame dimensions. In general, this capability is used when the height or width or both are not known or cannot be expressed. Using this capability disable the option using crop/pad mechanism and force SW to provide the same dimension in input/output region (if known) and zero the offset values.*/
    uint8_t use_attributes;
    /*!< vector_format Vector CL format: 0-unpacked using 2B container; 1-packed*/
    uint8_t vector_format;
    /*!< vertical_ordering_enable If set, the walking order should be vertical using the sub_line value to indicate how many CL generate vertical movement*/
    uint8_t vertical_ordering_enable;
    /*!< vertical_ordering_sub_line valid when vertical_ordering is set, indicates the size of the sub line to generate vertical step in CL granularity*/
    uint8_t vertical_ordering_sub_line;
    /*!< zlr_transaction_enable when set enable sending zlr request for prefetch address translation and compression status*/
    uint8_t zlr_transaction_enable;

} ia_pal_system_api_io_buffer_t;

/*! \system api struct io_buffer_1_1

*/
typedef struct
{
    /*!< aligner_data_size amount of valid bits per valid cycle to be accumulate and use the aligner (valid when dpa_bypass is set). LSB represent 2b resolution (meaning value can be 2, 4, 6, 8, … up to 72 which is the size bus)*/
    int32_t aligner_data_size;
    /*!< arbiter_pin MIPI CSI arbiter pin location of the stream*/
    int32_t arbiter_pin;
    /*!< block_height buffer block height configuration in lines*/
    uint16_t block_height;
    /*!< block_width buffer block width configuration in pixels*/
    uint16_t block_width;
    /*!< buffer_1d_enable Valid only for 1 plane and 1 queue streams. 0-the buffer is described as 2D; 1-the buffer is described as 1D (continues from start to end w/o stride ignoring lines)*/
    uint8_t buffer_1d_enable;
    /*!< chroma_base_conversion chroma converted from zero-based to half-based or vice versa*/
    uint8_t chroma_base_conversion;
    /*!< chroma_duplication Valid when format 420 is configured to provide 422 (2P2Q with SIF count of 4 or 2). when reset - duplicate the chroma and provide the same value each two Y lines, when set - send the chroma components only with the even Y (at odd Y lines doesn’t send any chroma)*/
    uint8_t chroma_duplication;
    /*!< chroma_non_duplication_location Valid when format 420 is configured to provide 422 (2P2Q with SIF count of 4 or 2) and chroma_duplication is disabled. when reset - add the chroma lines w/ the even luma lines, when set - add the chroma lines w/ the odd luma lines*/
    uint8_t chroma_non_duplication_location;
    /*!< chroma_planes_order Chroma planes ordering: 0 - U before V; 1 - V before U (valid for half planer configuration)*/
    uint8_t chroma_planes_order;
    /*!< component_in_valid_pixel Provides amount of valid component per valid pixel*/
    uint8_t component_in_valid_pixel;
    /*!< component_precision Pixel element precision in bits: 0=>8b, 1=>10b, 2=>12b, 3=>16, 4=>32, 5=>2, 6=>4, 7..15=>reserved*/
    uint8_t component_precision;
    /*!< compression_mode Valid for streaming that are tiled: 1-the stream is written/fetched to/from DDR through compression engine; 0-not going through compression*/
    uint8_t compression_mode;
    /*!< dpa_bypass When set indicate the end of MIPI frame (used for MIPI CSI sub frames)*/
    uint8_t dpa_bypass;
    /*!< first_row_blocks_height buffer block height configuration in lines of all the blocks in the first row of blocks. If zero - use streaming_buffer_blocks_height*/
    uint16_t first_row_blocks_height;
    /*!< granularity_pointer_update Valid according the streaming mode: number of lines (LB)/lines of blocks (BB) to be written/release before sending a pointer update (reporting always done with producer view)*/
    uint16_t granularity_pointer_update;
    /*!< in_chroma_signed chroma in input is signed (1) or unsigned (0)*/
    uint8_t in_chroma_signed;
    /*!< in_luma_signed luma in input is signed (1) or unsigned (0)*/
    uint8_t in_luma_signed;
    /*!< last_row_blocks_height buffer block height configuration in lines of all the blocks in the last row of blocks. If zero - use streaming_buffer_blocks_height*/
    uint16_t last_row_blocks_height;
    /*!< local_link_id indicates the stream used at the current connectlon*/
    uint8_t local_link_id;
    /*!< luma_base_conversion luma converted from zero-based to half-based or vice versa*/
    uint8_t luma_base_conversion;
    /*!< max_credits provides the maximum amount of credits for eliminating the need to calculate it in HW according the next formula: (end_address-start_address)/Max_Stride*/
    uint32_t max_credits;
    /*!< max_stride provides the maximum stride value to be used at the connection*/
    uint32_t max_stride;
    /*!< middle_ack_enable If set, enable the mechansim to generate middle ack when consumed amount of configured lines*/
    uint8_t middle_ack_enable;
    /*!< middle_ack_line_number Valid if ack enable  If enabled, the device should generate middle ack when delivers the EOL of the configured line (global number) assuming the first line delievered at SOF is zero.  In case of multiple planes the counting is done using plane1 but only when all the planes are synced*/
    uint16_t middle_ack_line_number;
    /*!< middle_ack_mode_stall Valid only when ack_enable is set When set, the device should stall once sending the middle ack*/
    uint8_t middle_ack_mode_stall;
    /*!< mipi_csi_eof When set indicate the end of MIPI frame (used for MIPI CSI sub frames)*/
    uint8_t mipi_csi_eof;
    /*!< num_of_planes Amount of valid planes (supported 1, 2, 3, 4 - depends also on HW parameter of max planes and data type)*/
    uint8_t num_of_planes;
    /*!< num_of_queues Amount of total active queues (YUV FP - 4, YUV SP - 3 YUV SP Tile - 2. RGB - 1,1,1. Bayer -2). Must be up to amount of maximum queue supported. Can be changed per frame. At LBFF used dynamicly for PDAF*/
    uint8_t num_of_queues;
    /*!< onep_pixel_order Set the ordering of the first plane (lines-N, pixels-M) 4PPC: 0-(N, M), (N, M+1), (N+1, M), (N+1, M+1), horizontal raster; 1-(N, M), (N+1, M), (N, M+1), (N+1, M+1), vertical raster 2PPC: 0-first cyc: (N, M), (N+1, M), second cyc: (N, M+1), (N+1, M+1); 1-first cyc: (N, M), (N, M+1),*/
    uint8_t onep_pixel_order;
    /*!< out_chroma_signed chroma in output is signed (1) or unsigned (0)*/
    uint8_t out_chroma_signed;
    /*!< out_luma_signed luma in output is signed (1) or unsigned (0)*/
    uint8_t out_luma_signed;
    /*!< pace_message_pace_line Provides the line number indicating to stop measuring the activity and pace and sending pace meesage (at IFD - get the last data of the line, at ODR - getnon-buf ack on last data of the line)*/
    uint16_t pace_message_pace_line;
    /*!< pace_message_ref_line Provides the line number that when start indicating start measuring the pace and active  (ODR - send first WR of the line, IFD send first RD of line)*/
    uint16_t pace_message_ref_line;
    /*!< pixels_in_valid_cycle Provides amount of valid pixels per valid cycle*/
    uint8_t pixels_in_valid_cycle;
    /*!< plane_horiz_subsample_config[3] Plane Horiz subsample (width>>N).  Affect tile width and width resolution=>Bayer - 0, Y/UV at YUV SP - 0, Y at YUV FP -0, UV U/V at YUV FP-1)*/
    uint8_t plane_horiz_subsample_config[3];
    /*!< plane_max_burst_size[3] Plane maximum burst size: used to specify the transfer size in CL granularity (Max limited to 16, possible values - 1, 2, 4, 8, 16)*/
    uint8_t plane_max_burst_size[3];
    /*!< plane_offset_end_address[3] Per plane: End offset address of plane with regarding to the base_offset, in bytes, CL aligned, unsigned.*/
    uint32_t plane_offset_end_address[3];
    /*!< plane_offset_start_address[3] Per plane: Start offset address of plane with regarding to the base_offset, in bytes, CL aligned, unsigned.*/
    uint32_t plane_offset_start_address[3];
    /*!< plane_stride[3] Per plane: provides the difference between two horizontal pixels, in bytes, CL aligned, unsigned.  At tile mode - provide the difference between two lines of tiles in bytes*/
    uint32_t plane_stride[3];
    /*!< plane_tile_height[3] Per plane: buffer tile height configuration in lines*/
    uint8_t plane_tile_height[3];
    /*!< plane_tile_width[3] Per plane: buffer tile width configuration in bytes*/
    uint8_t plane_tile_width[3];
    /*!< plane_vert_subsample_config[3] Plane Vertical subsample (height>>N). Affect tile highet and highet resolution=>Bayer - 0, Y atYUV SP - 0, UV at YUV SP - 1, Y at YUV FP -0, U/V at YUV FP-1)*/
    uint8_t plane_vert_subsample_config[3];
    /*!< plane_zlr_granularity[3] Plane ZLR page granularity: if 0 - 4KB, if 1 - 2KB. Valid only if ZLR is enalbe*/
    uint8_t plane_zlr_granularity[3];
    /*!< ppc provides the amount of pixel per cycle*/
    uint8_t ppc;
    /*!< proc_ff_bypass when set indicates the FF in the pipe (FCVT & ESPA) need to be bypass*/
    uint8_t proc_ff_bypass;
    /*!< progress_message_line Provides the line number that when is done generate progress message (IFD - last byte of the line arrive, ODR - last byte of the line acked by nbuf)*/
    uint16_t progress_message_line;
    /*!< stream_dt stream data type as need to be used by the MIPI*/
    uint8_t stream_dt;
    /*!< stream_dt_for_mipi_packet stream data type as need to be used in the header of mipi packet - not affect the proc*/
    int32_t stream_dt_for_mipi_packet;
    /*!< stream_vc stream virtual channel number as need to be used in MIPI*/
    uint8_t stream_vc;
    /*!< stream_wc stream word count as need to be used by the MIPI*/
    uint16_t stream_wc;
    /*!< streaming_mode The streaming unified buffer protocol:  0-static offline (producer/consumer write/read from DDR after kick);  1-dynamic offline (producer/consumer send wr/rd EOF/SOF, producer write after kick, consumer read after full frame at DDR);  2-buffer chasing large memory (producer/consumer send wr/rd EOF/SOF, producer send wr update, consumer read according to wr update);  3-buffer chasing on small memory (producer/consumer send wr/rd EOF/SOF, producer write released buffers and sends wr pointers, consumer read valid buffer and sends rd pointer);  4-S&R like 3 with option to change the link (supporting modes 2 and 3 with dynamic change) 5-buffer chasing small memory - fix starting point, single buffer 6-buffer chasing small memory - float starting point 7-buffer chasing small memory - fix starting point, double buffer*/
    uint8_t streaming_mode;
    /*!< streaming_sw_managed When set - the SW verify the shared buffer is fully consumed by  the producer and can be written immediately*/
    uint8_t streaming_sw_managed;
    /*!< stride_ratio provides the BCSM max_stride/stride ratio with possible values of 1-8, 16, 32, 64, 128*/
    uint8_t stride_ratio;
    /*!< subsample_YUV444_to_YUV422 Used by ODR to convert YUV444 to YUV422: 0-use amount of element as written at components_in_valid_cycle, 1-drop the chroma components any odd cycle*/
    uint8_t subsample_YUV444_to_YUV422;
    /*!< tile_mode Valid for IO that can provide tile format: 0-no tiling; 1-the IO should use tiling with the configured height, width, and tiling type (internal tiling or external Tile-4)*/
    uint8_t tile_mode;
    /*!< tiling_type Tiling Type: 0 - internal tiling; 1 - external tiling (Tile-4)*/
    uint8_t tiling_type;
    /*!< unpack_alignment Valid for unpacked vectors: 0-element located at LSB and MSB is zero; 1-element located at MSB and LSB is zero*/
    uint8_t unpack_alignment;
    /*!< use_attributes This capability impact the ODR. When set, ODR should use the EOL/EOF attributes to detect frame dimensions. In general, this capability is used when the height or width or both are not known or cannot be expressed. Using this capability disable the option using crop/pad mechanism and force SW to provide the same dimension in input/output region (if known) and zero the offset values.*/
    uint8_t use_attributes;
    /*!< vector_format Vector CL format: 0-unpacked using 2B container; 1-packed*/
    uint8_t vector_format;
    /*!< vertical_ordering_enable If set, the walking order should be vertical using the sub_line value to indicate how many CL generate vertical movement*/
    uint8_t vertical_ordering_enable;
    /*!< vertical_ordering_sub_line valid when vertical_ordering is set, indicates the size of the sub line to generate vertical step in CL granularity*/
    uint8_t vertical_ordering_sub_line;
    /*!< zlr_transaction_enable when set enable sending zlr request for prefetch address translation and compression status*/
    uint8_t zlr_transaction_enable;

} ia_pal_system_api_io_buffer_1_1_t;

/*! \system api struct lsc_1_2
Lens shading correction up to 24 bit
*/
typedef struct
{
    /*!< ir_processing 0 - RGB processing or 1 - IR processing*/
    uint8_t ir_processing;

} ia_pal_system_api_lsc_1_2_t;

/*! \system api struct rgbs_grid_1_0
RGBS grid (AWB statistics)
*/
typedef struct
{
    /*!< is_fragmentation If no - min_out_bytes=0. Otherwise - calculate to fit grid to CL.*/
    uint8_t is_fragmentation;

} ia_pal_system_api_rgbs_grid_1_0_t;

/*! \system api struct tnr7_blend_1_0

*/
typedef struct
{
    /*!< enable_main_output Enable blend main output*/
    uint8_t enable_main_output;
    /*!< enable_vision_output Enable blend computer vision output*/
    uint8_t enable_vision_output;

} ia_pal_system_api_tnr7_blend_1_0_t;

/*! \system api struct tvs_1_0
Trainable visual scaler
*/
typedef struct
{
    /*!< output_420 Output data format (0: YUV444; 1: YUV420. It will be forced to 1 if either ds_bypass or bypass is enabled)*/
    uint8_t output_420;

} ia_pal_system_api_tvs_1_0_t;



#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif // IA_PAL_TYPES_ISP_PARAMETERS_AUTOGEN_H
