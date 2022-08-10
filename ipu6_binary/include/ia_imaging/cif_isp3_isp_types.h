/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2014-2017 Intel Corporation
 * All Rights Reserved.
 *
 * The source code contained or described herein and all documents related to
 * the source code ("Material") are owned by Intel Corporation or its
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
 * this notice or any other notice embedded in Materials by Intel or Intels
 * suppliers or licensors in any way.
 */

#ifndef _CIF_ISP_TYPES_H
#define _CIF_ISP_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#define CIFISP_AWB_MAX_GRID 4800
#define CIFISP_HIST_BIN_N_MAX 512
#define CIFISP_AFM_MAX_GRID 1200
#define CIFISP_AE_MEAN_MAX 25
#define CIFISP_GAMMA_OUT_TBL_SIZE 259
#define CIFISP_DEGAMMA_TBL_SIZE 257
#define CIFISP_TONE_MAP_TABLE_SIZE 257
#define CIFISP_BNR_LUT_SIZE 33
#define CIFISP_AFM_FILTER_SIZE 9
#define CIFISP_AFM_COEFFS_SIZE 3
#define CIFISP_COLOR_TONE_TABLE_SIZE 33
#define CIFISP_BNR_TABLE_SIZE 33
#define CIFISP_CORR_DATA_TBL_SIZE 561
#define CIFISP_MACC_SEGMENTS 16
#define CIFISP_CTK_TBL_SIZE 9
#define CIFISP_IE_TBL_SIZE 3

enum cifisp_histogram_mode {
	CIFISP_HISTOGRAM_MODE_RGB_COMBINED_LEGACY = 1,
	CIFISP_HISTOGRAM_MODE_R_HISTOGRAM         = 2,
	CIFISP_HISTOGRAM_MODE_G_HISTOGRAM         = 3,
	CIFISP_HISTOGRAM_MODE_B_HISTOGRAM         = 4,
	CIFISP_HISTOGRAM_MODE_Y_HISTOGRAM         = 5,
	CIFISP_HISTOGRAM_MODE_RGBY_HISTOGRAM      = 6,
	CIFISP_HISTOGRAM_MODE_RGB_COMBINED        = 7
};

struct cifisp_window {
	uint16_t h_offs;
	uint16_t v_offs;
	uint16_t h_size;
	uint16_t v_size;
};

enum cifisp_awb_mode_type {
	CIFISP_AWB_MODE_MANUAL  = 0,
	CIFISP_AWB_MODE_RGB     = 1,
	CIFISP_AWB_MODE_YCBCR   = 2
};

/*! possible bad pixel correction mode*/
enum  cifisp_bls_mode {
	CIF_ISP_BLS_FIXED,
	CIF_ISP_BLS_AUTO,
	CIF_ISP_BLS_LOCAL,
	CIF_ISP_BLS_MIXED
};

enum cifisp_stat_type {
	CIFISP_STAT_AWB,
	CIFISP_STAT_EXP,
	CIFISP_STAT_AFM,
	CIFISP_STAT_HIST
};

enum cifisp_colorfx {
	CIFISP_COLORFX_BW = 1,
	CIFISP_COLORFX_SEPIA = 2,
	CIFISP_COLORFX_NEGATIVE = 3,
	CIFISP_COLORFX_EMBOSS = 4,
	CIFISP_COLORFX_SKETCH = 5,
	CIFISP_COLORFX_SKY_BLUE = 6,
	CIFISP_COLORFX_GRASS_GREEN = 7,
	CIFISP_COLORFX_SKIN_WHITEN = 8,
	CIFISP_COLORFX_VIVID = 9,
	CIFISP_COLORFX_AQUA = 10,
	CIFISP_COLORFX_ART_FREEZE = 11,
	CIFISP_COLORFX_SILHOUETTE = 12,
	CIFISP_COLORFX_SOLARIZATION = 13,
	CIFISP_COLORFX_ANTIQUE = 14,
	CIFISP_COLORFX_SET_CBCR = 15
};

struct cifisp_ie_config {
	uint8_t on; /* 1 if block shall be enabled, 0 if switched off*/
	int32_t effect; /* enum cifisp_colorfx */
	/*
	* 3x3 Matrix Coefficients for Emboss/Sketch,
	* or [0] for tint,
	* or [0] for color_sel.
	*/
	uint16_t effect_cfg[CIFISP_IE_TBL_SIZE];
};

struct cifisp_awb_meas_yc {
	uint32_t cnt;
	uint8_t mean_y;
	uint8_t mean_cb;
	uint8_t mean_cr;
};

struct cifisp_awb_meas_bayer {
	uint32_t cnt;
	uint16_t mean_r;
	uint16_t mean_b;
	uint16_t mean_gr;
	uint16_t mean_gb;
};

struct cifisp_awb_stat {
	union {
		struct cifisp_awb_meas_bayer bayer[CIFISP_AWB_MAX_GRID];
		struct cifisp_awb_meas_yc yc[CIFISP_AWB_MAX_GRID];
	} awb_mean;
};

struct cifisp_hist_stat {
	uint16_t bin[CIFISP_HIST_BIN_N_MAX];
};

struct cifisp_ae_stat {
	uint8_t exp_mean[CIFISP_AE_MEAN_MAX];
};

struct cifisp_af_meas_val {
	uint32_t afm_result1;
	uint32_t afm_result2;
	uint32_t afm_lum;
};

struct cifisp_af_stat {
	struct cifisp_af_meas_val af[CIFISP_AFM_MAX_GRID];
};

union cifisp_stat {
	struct cifisp_awb_stat awb;
	struct cifisp_ae_stat ae;
	struct cifisp_af_stat af;
	struct cifisp_hist_stat hist;
};

/* Always center based measurements */
struct cifisp_meas_grid {
	uint16_t h_coverage; /* 0 - 8192 */
	uint16_t v_coverage; /* 0 - 8192 */
	uint16_t h_dim;
	uint16_t v_dim;
};

struct cifisp_stat_buffer {
	int32_t meas_type; /* enum cifisp_stat_type */
	union cifisp_stat params;
	/*actually used grid, absolute coverage size */
	struct cifisp_meas_grid grid;
};

struct cifisp_corr_grid {
	uint32_t r_data_tbl[CIFISP_CORR_DATA_TBL_SIZE];
	uint32_t gr_data_tbl[CIFISP_CORR_DATA_TBL_SIZE];
	uint32_t gb_data_tbl[CIFISP_CORR_DATA_TBL_SIZE];
	uint32_t b_data_tbl[CIFISP_CORR_DATA_TBL_SIZE];
	uint16_t width;
	uint16_t height;
};

/*! configuration for detection of bad pixel block*/
struct cifisp_bp_detection_config {
	/*Enables the turbulence based gradient adjustment for hot pixels*/
	uint8_t bp_hot_turbulence_adj_en;
	/*Enables the turbulence based gradient adjustment for dead pixels*/
	uint8_t bp_dead_turbulence_adj_en;
	/*Enables/disables the sign sensitivity for hot gradient evaluation*/
	uint8_t bp_dev_hot_sign_sens;
	/*Enables/disables the sign sensitivity for dead gradient evaluation.*/
	uint8_t bp_dev_dead_sign_sens;
	/*
	* Divider (shift) configuration for the calculated turbulence value
	* used by hot pixel detection
	*/
	uint8_t   bp_hot_turbulence_shift;
	/*
	* Divider (shift) configuration for the calculated turbulence value
	* used by dead pixel detection.
	*/
	uint8_t   bp_dead_turbulence_shift;
	/*
	* The amount of gradients - exceeding the threshold - which triggers
	* a hot pixel detection.
	*/
	uint8_t   bp_dev_hot_grad_trig_lvl;
	/*
	* The amount of gradients - exceeding the threshold - which triggers
	* a dead pixel detection .
	*/
	uint8_t   bp_dev_dead_grad_trig_lvl;
};

struct cifisp_bp_direct {
	uint16_t abs_hot_thres;  /* Absolute hot pixel threshold*/
	uint16_t abs_dead_thres; /* Absolute dead pixel threshold*/
	uint16_t dev_hot_thres;  /* Hot Pixel deviation Threshold*/
	uint16_t dev_dead_thres; /* Dead Pixel deviation Threshold*/
	uint8_t w0;
	uint8_t w1;
	uint16_t th0;
	uint32_t offset;
};

/*! configuration for correction of bad pixel block*/
struct cifisp_bp_correction_config {
	uint8_t corr_type; /* bad pixel correction type*/
	uint8_t corr_rep; /* replace approach*/
	uint8_t corr_mode; /* bad pixel correction mode*/
	struct cifisp_bp_direct bp_corr_direct;
};

/* Configuration used by bad pixel detection & correction */
struct cifisp_bpc_config {
	uint8_t on; /* 1 if block shall be enabled, 0 if switched off*/
	struct cifisp_bp_correction_config corr_config;
	struct cifisp_bp_detection_config det_config;
};

/*
* BLS fixed subtraction values. The values will be subtracted from the sensor
* values. Therefore a negative value means addition instead of subtraction
*/
struct cifisp_bls_fixed_config {
	/*! Fixed (signed!) subtraction value for Bayer pattern position A.*/
	uint16_t fixed_a;
	/*! Fixed (signed!) subtraction value for Bayer pattern position B.*/
	uint16_t fixed_b;
	/*! Fixed (signed!) subtraction value for Bayer pattern position C.*/
	uint16_t fixed_c;
	/*! Fixed (signed!) subtraction value for Bayer pattern position D.*/
	uint16_t fixed_d;
};

struct cifisp_bls_meas_config {
	struct cifisp_window bls_window1;
	struct cifisp_window bls_window2;
	uint8_t bls_samples;
	uint8_t window_enable;
};

struct cifisp_bls_local_config {
	struct cifisp_corr_grid corr;
};

struct cifisp_bls_mixed_config {
	struct cifisp_bls_local_config local;
	struct cifisp_bls_fixed_config fixed;
};

/* Configuration used by black level subtraction */
struct cifisp_bls_config {
	uint8_t on; /* 1 if block shall be enabled, 0 if switched off*/
	int32_t mode; /* enum cifisp_bls_mode */
	union {
		struct cifisp_bls_fixed_config fixed;
		struct cifisp_bls_meas_config meas;
		struct cifisp_bls_local_config local;
		struct cifisp_bls_mixed_config mixed;
	} config;
};

/* Configuration used by sensor degamma */
struct cifisp_sdg_config {
	uint8_t on; /* 1 if block shall be enabled, 0 if switched off*/
	uint16_t gamma_gr[CIFISP_DEGAMMA_TBL_SIZE];
	uint16_t gamma_gb[CIFISP_DEGAMMA_TBL_SIZE];
	uint16_t gamma_b[CIFISP_DEGAMMA_TBL_SIZE];
	uint16_t gamma_r[CIFISP_DEGAMMA_TBL_SIZE];
};

/* Configuration used by Lens shading correction */
struct cifisp_lsc_config {
	uint8_t on; /* 1 if block shall be enabled, 0 if switched off*/
	struct cifisp_corr_grid corr;
};

struct cifisp_awb_yc_meas_config {
	/*
	* only pixels values < max_y contribute to awb measurement
	* (set to 0 to disable this feature)
	*/
	uint8_t max_y;
	/*! only pixels values > min_y contribute to awb measurement*/
	uint8_t min_y;
	/*
	* Chrominance sum maximum value, only consider pixels with Cb+Cr
	* smaller than threshold for awb measurements
	*/
	uint8_t max_csum;
	/*
	* Chrominance minimum value, only consider pixels with Cb/Cr
	* each greater than threshold value for awb measurements
	*/
	uint8_t min_c;
	/*! reference Cr value for AWB regulation, target for AWB*/
	uint8_t awb_ref_cr;
	/*! reference Cb value for AWB regulation, target for AWB*/
	uint8_t awb_ref_cb;
	uint8_t enable_ymax_cmp;
	/*before(1) or after(0) white balance gains adjustment*/
};

struct cifisp_awb_bayer_meas_config {
	uint16_t gb_sat;
	uint16_t gr_sat;
	uint16_t b_sat;
	uint16_t r_sat;
	uint8_t rgb_meas_pnt;
	uint8_t awbm_before_lsc;
	uint8_t rgb_include_sat_pix;
};

/* Configuration used by auto white balance */
struct cifisp_awb_meas_config {
	uint8_t on; /* 1 if block shall be enabled, 0 if switched off*/
	int32_t awb_mode; /* enum cifisp_awb_mode_type */
	union {
		struct cifisp_awb_yc_meas_config yc;
		struct cifisp_awb_bayer_meas_config bayer;
	} config;
	/*
	* number of frames - 1 used for mean value calculation
	*  (ucFrames=0 means 1 Frame)
	*/
	uint8_t frames;
	struct cifisp_meas_grid grid;
};

struct cifisp_awb_gain_config {
	uint8_t on; /* 1 if block shall be enabled, 0 if switched off*/
	uint16_t  gain_red;
	uint16_t  gain_green_r;
	uint16_t  gain_blue;
	uint16_t  gain_green_b;
};

/*Configuration used by BNR in cif3.1 */

struct cifisp_gd_config {
	uint8_t on; /* 1 if block shall be enabled, 0 if switched off*/
	uint8_t clip;
	uint32_t rgbd_coeffs;
	uint32_t config;
};

struct cifisp_bnr_config {
	uint8_t on; /* 1 if block shall be enabled, 0 if switched off*/
	uint32_t weight;
	uint32_t antishading;
	uint32_t coeffs;
	uint32_t wb_gain;
	uint16_t lut[CIFISP_BNR_TABLE_SIZE];
	struct cifisp_gd_config gd;
};

/* Configuration used by ISP filtering */
struct cifisp_flt_config {
	uint8_t on; /* 1 if block shall be enabled, 0 if switched off*/
	uint32_t flt_mask_sharp0;
	uint32_t flt_mask_sharp1;
	uint32_t flt_mask_diag;
	uint32_t flt_mask_blur_max;
	uint32_t flt_mask_blur;
	uint32_t flt_mask_lin;
	uint32_t flt_mask_orth;
	uint32_t flt_mask_v_diag;
	uint32_t flt_mask_h_diag;
	uint32_t flt_lum_weight;
	uint16_t flt_blur_th0;
	uint16_t flt_blur_th1;
	uint16_t flt_sharp0_th;
	uint16_t flt_sharp1_th;
	uint16_t flt_cas_enable;
	uint16_t flt_cas_lowlevel;
	uint16_t flt_cas_th0;
	uint16_t flt_cas_th1;
	uint16_t flt_cas_inverse;
	uint8_t demosaic_th;
	uint8_t chrom_h_mode;
	uint8_t chrom_v_mode;
	uint8_t diag_sharp_mode;
	uint8_t flt_mode;
};

/* Configuration used by Cross Talk correction */
struct cifisp_ctk_config {
	uint8_t on; /* 1 if block shall be enabled, 0 if switched off*/
	uint16_t coeff[CIFISP_CTK_TBL_SIZE];
	/* offset for the crosstalk correction matrix */
	uint16_t ct_offset_r;
	uint16_t ct_offset_g;
	uint16_t ct_offset_b;
};

/* Configuration used by Gamma Out correction */
struct cifisp_goc_config {
	uint8_t on; /* 1 if block shall be enabled, 0 if switched off*/
	uint32_t gamma_rgb[CIFISP_GAMMA_OUT_TBL_SIZE];
};

/* Multi Axis Color Control Structures - MACC */
struct cifisp_macc_coeff {
	uint32_t coeff0;
	uint32_t coeff1;
};

struct cifisp_macc_config {
	uint8_t on; /* 1 if block shall be enabled, 0 if switched off*/
	struct cifisp_macc_coeff seg[CIFISP_MACC_SEGMENTS];
};

/* CCM (Color Correction) */
struct cifisp_cproc_config {
	uint8_t on; /* 1 if block shall be enabled, 0 if switched off*/
	uint8_t contrast;
	uint8_t brightness;
	uint8_t sat;
	uint8_t hue;
};

struct cifisp_tmap_config {
	uint8_t on; /* 1 if block shall be enabled, 0 if switched off*/
	uint16_t tmap_y[CIFISP_TONE_MAP_TABLE_SIZE];
	uint16_t tmap_c[CIFISP_TONE_MAP_TABLE_SIZE];
};

/* Configuration used by Histogram */
struct cifisp_hist_config {
	uint8_t on; /* 1 if block shall be enabled, 0 if switched off*/
	uint8_t predivider;
	int32_t mode; /* enum cifisp_histogram_mode */
	struct cifisp_meas_grid grid;
};

/* Configuration used by Auto Exposure Control */
struct cifisp_aem_config {
	uint8_t on; /* 1 if block shall be enabled, 0 if switched off*/
	uint8_t autostop;
	struct cifisp_meas_grid grid;
};

/* YC FLT */
struct cifisp_ycflt_config {
	uint8_t on; /* 1 if block shall be enabled, 0 if switched off*/
	uint32_t ctrl;
	uint32_t ss_ctrl;
	uint32_t ss_fac;
	uint32_t ss_offs;
	uint32_t chr_nr_ctrl;
	uint32_t lum_eenr_edge_gain;
	uint32_t lum_eenr_corner_gain;
	uint32_t lum_eenr_fc_crop_pos;
	uint32_t lum_eenr_fc_crop_neg;
	uint32_t lum_eenr_fc_gain_pos;
	uint32_t lum_eenr_fc_gain_neg;
	uint32_t lum_nr_ctrl;
	uint32_t lum_eenr_fc_coring_pos;
	uint32_t lum_eenr_fc_coring_neg;
	uint32_t color_tone_y_lut[CIFISP_COLOR_TONE_TABLE_SIZE];
	uint32_t color_tone_cb_lut[CIFISP_COLOR_TONE_TABLE_SIZE];
	uint32_t color_tone_cr_lut[CIFISP_COLOR_TONE_TABLE_SIZE];
	uint32_t color_tone_s_lut[CIFISP_COLOR_TONE_TABLE_SIZE];
	uint32_t color_tone_norm_offs;
};

struct cifisp_afm_config {
	uint8_t on; /* 1 if block shall be enabled, 0 if switched off*/
	struct cifisp_meas_grid grid;
	uint32_t afm_result1_thres;
	uint32_t afm_result2_thres;
	uint8_t afm_result1_rshift;
	uint8_t afm_result2_rshift;
	uint8_t afm_lum_rshift;
	uint32_t afm_filter_coeffs_matx[CIFISP_AFM_FILTER_SIZE];
	uint32_t afm_filter_coeffs_maty[CIFISP_AFM_FILTER_SIZE];
	uint32_t afm_bayer2y_coeffs[CIFISP_AFM_COEFFS_SIZE];
};

struct cifisp_crop_config {
	int32_t left;
	int32_t top;
	uint32_t width;
	uint32_t height;
};

#ifdef __cplusplus
}
#endif

#endif
