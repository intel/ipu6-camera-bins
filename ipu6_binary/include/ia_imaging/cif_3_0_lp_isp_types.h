/*
 ****************************************************************
 *
 *  Component: CIF driver
 *
 *  Copyright (C) 2011 Intel Mobile Communications GmbH
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License Version 2
 *  as published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 *  You should have received a copy of the GNU General Public License Version 2
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 ****************************************************************
 */

#ifndef _XGOLD_ISP_IOCTL_H
#define _XGOLD_ISP_IOCTL_H

#ifdef __cplusplus
extern "C" {
#endif

enum cifisp_colorfx {
        CIFISP_COLORFX_NONE = 0,
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

#define CIFISP_CTK_COEFF_MAX   0x400
#define CIFISP_CTK_OFFSET_MAX 0x800

#define CIFISP_AE_MEAN_MAX 25
#define CIFISP_HIST_BIN_N_MAX 128
#define CIFISP_AFM_MAX_WINDOWS 3

#define CIFISP_BDM_MAX_TH 0xFF
/* Maximum filtering modes supported*/
#define CIFISP_FILT_MODE_MAX                0x2
/* Maximum chrominance filter modes supported */
#define CIFISP_FILT_CH_MODE_MAX             0x3
/* Maximum Diagonal sharpening modes supported*/
#define CIFISP_FILT_DIAG_SHARP_MAX          0x1
#define CIFISP_FILT_DIAG_TH_MAX             0x3FF

/* Number of elements in the bad pixel table*/
#define CIFISP_BP_MAX_TBL_NUM               128
/* Max number of newly detected bad pixels*/
#define CIFISP_BP_NEW_DET_MAX_NUM             8
/*[31]pix_type  Bad pixel type*/
#define CIFISP_BP_PIX_TYP                  (0x80000000)
/*[26:16]v_addr Bad Pixel vertical address*/
#define CIFISP_BP_V_ADDR                   (0x07FF0000)
#define CIFISP_BP_V_ADDR_SHIFT             (16)
/*[11:0]h_addr  Bad Pixel horizontal address*/
#define CIFISP_BP_H_ADDR                   (0x00000FFF)
#define CIFISP_BP_HOT_THRESH_MAX            0x00000FFF
#define CIFISP_BP_DEAD_THRESH_MAX           0x00000FFF

/* maximum value for horizontal start address*/
#define CIFISP_BLS_START_H_MAX             (0x00000FFF)
/* maximum value for horizontal stop address */
#define CIFISP_BLS_STOP_H_MAX              (0x00000FFF)
/* maximum value for vertical start address*/
#define CIFISP_BLS_START_V_MAX             (0x00000FFF)
/* maximum value for vertical stop address*/
#define CIFISP_BLS_STOP_V_MAX              (0x00000FFF)
/* maximum is 2^18 = 262144*/
#define CIFISP_BLS_SAMPLES_MAX             (0x00000012)
/* maximum value for fixed black level*/
#define CIFISP_BLS_FIX_SUB_MAX             (0x00000FFF)
/* minimum value for fixed black level*/
#define CIFISP_BLS_FIX_SUB_MIN             (0xFFFFF000)
/* 13 bit range (signed)*/
#define CIFISP_BLS_FIX_MASK                (0x00001FFF)

#define CIFISP_AWB_GAINS_MAX_VAL           (0x000003FF)
#define CIFISP_AWB_GRID_MAX_OFFSET         (0x00001FFF)
#define CIFISP_AWB_GRID_MAX_DIM            (0x0000003F)
#define CIFISP_AWB_WINDOW_MAX_SIZE         (0x00001FFF)
#define CIFISP_AWB_GRID_MAX_DIST           (0x00001FFF)
#define CIFISP_AWB_CBCR_MAX_REF            (0x000000FF)
#define CIFISP_AWB_THRES_MAX_YC            (0x000000FF)
#define CIFISP_AWB_MAX_SAT                 (0x00000FFF)
#define CIFISP_AWB_MAX_GRID                384
#define CIFISP_AWB_MAX_FRAMES              7

/* number of windows in a row*/
#define CIFISP_EXP_ROW_NUM                 (5)
/* number of windows in a column*/
#define CIFISP_EXP_COLUMN_NUM              (5)
#define CIFISP_EXP_NUM_LUMA_REGS           (CIFISP_EXP_ROW_NUM *\
		CIFISP_EXP_COLUMN_NUM)
#define CIFISP_EXP_MAX_HOFFS               (2424)
#define CIFISP_EXP_MAX_VOFFS               (1806)
#define CIFISP_EXP_MAX_HSIZE               (520)
#define CIFISP_EXP_MIN_HSIZE               (35)
#define CIFISP_EXP_MAX_VSIZE               (390)
#define CIFISP_EXP_MIN_VSIZE               (28)
/* isp_exp_v_size 32-bit mask */
#define CIFISP_EXP_HEIGHT_MASK             (0x000001FE)
/* isp_exp_h_offset 32-bit mask */
#define CIFISP_EXP_MAX_HOFFSET             (0x00000FFF)
/* isp_exp_v_offset 32-bit mask*/
#define CIFISP_EXP_MAX_VOFFSET             (0x000007FF)
#define CIFISP_MAX_HIST_PREDIVIDER         (0x0000007F)
#define CIFISP_HIST_WINDOW_RESERVED        (0xFFFFF000)

/* AWB */

/* Gamma out*/
/* Maximum number of color samples supported*/
#define CIFISP_GAMMA_OUT_MAX_SAMPLES       257
#define CIFISP_GAMMA_OUT_MAX_ADDR          128
/* LSC */
#define CIFISP_LSC_MIN_XSECT_SIZE          11
#define CIFISP_LSC_MAX_XSECT_SIZE          1024
#define CIFISP_LSC_MIN_YSECT_SIZE          9
#define CIFISP_LSC_MAX_YSECT_SIZE          1024
#define CIFISP_LSC_GRAD_TBL_SIZE           16
#define CIFISP_LSC_SIZE_TBL_SIZE           16
/* The following matches the tuning process,
 * not the max capabilites of the chip. */
#define	CIFISP_LSC_DATA_TBL_SIZE           221//17x13

/* BPC */
/* Max Divider (shift) configuration for the calculated turbulence value
 * used by hot pixel detection.*/
#define CIFISP_BPC_MAX_HOT_TB_SHIFT       (7)
/* Divider (shift) configuration for the calculated turbulence value
 * used by dead pixel detection.*/
#define CIFISP_BPC_MAX_DEAD_TB_SHIFT      (7)
/* Max amount of gradients - exceeding the threshold triggers
 * hot pixel detection*/
#define CIFISP_BPC_MAX_HOT_GRAD_TRIG      (7)
/* Max amount of gradients - exceeding the threshold triggers
 * dead pixel detection*/
#define CIFISP_BPC_MAX_DEAD_GRAD_TRIG     (7)

#define CIFISP_TONE_MAP_TABLE_SIZE		257

enum cifisp_histogram_mode {
	CIFISP_HISTOGRAM_MODE_DISABLE         = 0,
	CIFISP_HISTOGRAM_MODE_RGB_COMBINED    = 1,
	CIFISP_HISTOGRAM_MODE_R_HISTOGRAM     = 2,
	CIFISP_HISTOGRAM_MODE_G_HISTOGRAM     = 3,
	CIFISP_HISTOGRAM_MODE_B_HISTOGRAM     = 4,
	CIFISP_HISTOGRAM_MODE_Y_HISTOGRAM     = 5,
	CIFISP_HISTOGRAM_MODE_RGBY_HISTOGRAM  = 6,
	CIFISP_HISTOGRAM_MODE_RGB_COMBINED_NEW= 7
};

enum cifisp_exp_ctrl_autostop {
	CIFISP_EXP_CTRL_AUTOSTOP_0 = 0,
	CIFISP_EXP_CTRL_AUTOSTOP_1 = 1
};

struct cifisp_window {
	unsigned short h_offs;
	unsigned short v_offs;
	unsigned short h_size;
	unsigned short v_size;
};

enum cifisp_awb_mode_type {
	CIFISP_AWB_MODE_MANUAL  = 0,
	CIFISP_AWB_MODE_RGB     = 1,
	CIFISP_AWB_MODE_YCBCR   = 2
};


/*! bad pixel element attribute*/
enum cifisp_bp_type {
	CIFISP_BP_TYPE_HOT,      /* hot pixel */
	CIFISP_BP_TYPE_DEAD    /* dead pixel */
};


/*! possible bad pixel correction type*/
enum cifisp_bp_corr_type {
	CIFISP_BP_CORR_TYPE_TABLE, /* correction of bad pixel from the table*/
	CIFISP_BP_CORR_TYPE_DIRECT /* direct detection and correction*/
};

/*! possible bad pixel replace approach*/
enum cifisp_bp_corr_rep {
	CIFISP_BP_CORR_REP_NB,      /* nearest neighbour approach*/
	CIFISP_BP_CORR_REP_LIN      /* simple bilinear interpolation approach*/
};

/*! possible bad pixel correction mode*/
enum  cifisp_bp_corr_mode {
	CIF_ISP_BP_CORR_HOT_EN,         /* hot pixel correction*/
	CIF_ISP_BP_CORR_DEAD_EN,     /* dead pixel correction*/
	CIF_ISP_BP_CORR_HOT_DEAD_EN  /* hot and dead pixel correction*/
};

enum cifisp_stat_type {
	CIFISP_STAT_AWB, /*!< AWB callback*/
	CIFISP_STAT_AUTOEXP, /*!< Auto Exposure callback*/
	CIFISP_STAT_AFM_FIN /*!, Autofocus call back */
};

enum cifisp_bls_win_enable {
	ISP_BLS_CTRL_WINDOW_ENABLE_0 = 0,
	ISP_BLS_CTRL_WINDOW_ENABLE_1 = 1,
	ISP_BLS_CTRL_WINDOW_ENABLE_2 = 2,
	ISP_BLS_CTRL_WINDOW_ENABLE_3 = 3
};

struct cifisp_ie_config {
	enum cifisp_colorfx effect;
	unsigned short color_sel;
	/*3x3 Matrix Coefficients for Emboss Effect 1*/
	unsigned short eff_mat_1;
	/*3x3 Matrix Coefficients for Emboss Effect 2*/
	unsigned short eff_mat_2;
	/*3x3 Matrix Coefficients for Emboss 3/Sketch 1*/
	unsigned short eff_mat_3;
	/*3x3 Matrix Coefficients for Sketch Effect 2*/
	unsigned short eff_mat_4;
	/*3x3 Matrix Coefficients for Sketch Effect 3*/
	unsigned short eff_mat_5;
	/*Chrominance increment values of tint (used for sepia effect)*/
	unsigned short eff_tint;
};

typedef struct {
	unsigned char mean_y;
	unsigned char mean_cb;
	unsigned char mean_cr;
} cifisp_awb_meas_ycrcb;

typedef struct {
	unsigned short mean_r;
	unsigned short mean_b;
	unsigned short mean_gb;
	unsigned short mean_gr;
} cifisp_awb_meas_rgb;

struct cifisp_awb_meas {
	unsigned int cnt;
	union {
		cifisp_awb_meas_ycrcb ycrcb;
		cifisp_awb_meas_rgb   rggb;
	};
};

typedef struct
{
    unsigned short bins[CIFISP_AWB_MAX_GRID]; /*!< Histogram data. */
    unsigned int bin_count;                   /*!< Number of bins in the histogram. */
    unsigned int element_count;               /*!< Number of elements in the histogram. */
} cifisp_histogram_unit;

struct cifisp_histogram {
    cifisp_histogram_unit r;
    cifisp_histogram_unit g;
    cifisp_histogram_unit b;
    union {
        cifisp_histogram_unit rgb_combined;
        cifisp_histogram_unit y;
    };
};

struct cifisp_awb_stat {
	struct cifisp_awb_meas awb_mean[CIFISP_AWB_MAX_GRID];
    struct cifisp_histogram hist_bins;
};

/*! BLS mean measured values*/
struct cifisp_bls_meas_val {
	/*! Mean measured value for Bayer pattern position A.*/
	unsigned short meas_a;
	/*! Mean measured value for Bayer pattern position B.*/
	unsigned short meas_b;
	/*! Mean measured value for Bayer pattern position C.*/
	unsigned short meas_c;
	/*! Mean measured value for Bayer pattern position D.*/
	unsigned short meas_d;
};

struct cifisp_ae_stat {
	unsigned char exp_mean[CIFISP_AE_MEAN_MAX];
	struct cifisp_bls_meas_val bls_val; /*available wit exposure results*/
};

struct cifisp_af_meas_val {
	unsigned int sum;
	unsigned int lum;
};

struct cifisp_af_stat {
	struct cifisp_af_meas_val window[CIFISP_AFM_MAX_WINDOWS];
};

union cifisp_stat {
	struct cifisp_awb_stat awb;
	struct cifisp_ae_stat ae;
	struct cifisp_af_stat af;
};

struct cifisp_stat_buffer {
	enum cifisp_stat_type meas_type;
	union cifisp_stat params;
};

/*! new table element*/
struct cifisp_bp_table_elem {
	unsigned short bp_ver_addr; /* Bad Pixel vertical address*/
	unsigned short bp_hor_addr; /* Bad Pixel horizontal address*/
	/* value of fixed pixel (in) or type dead(0)/hot(1) (out)*/
	unsigned char bp_val;
};

/*! Bad Pixel table */
struct cifisp_bp_table {
	/* Pointer to BP Table */
	struct cifisp_bp_table_elem bp_tbl[CIFISP_BP_MAX_TBL_NUM];
	unsigned int bp_tbl_elem_num;/* Number of Table elements*/
};

/*! configuration for detection of bad pixel block*/
struct cifisp_bp_detection_config {
	/*Enables the turbulence based gradient adjustment for hot pixels*/
	bool bp_hot_turbulence_adj_en;
	/*Enables the turbulence based gradient adjustment for dead pixels*/
	bool bp_dead_turbulence_adj_en;
	/*Enables/disables the sign sensitivity for hot gradient evaluation*/
	bool bp_dev_hot_sign_sens;
	/*Enables/disables the sign sensitivity for dead gradient evaluation.*/
	bool bp_dev_dead_sign_sens;
	/* Divider (shift) configuration for the calculated turbulence value
	 *  used by hot pixel detection*/
	unsigned char   bp_hot_turbulence_shift;
	/*Divider (shift) configuration for the calculated turbulence value
	 *  used by dead pixel detection.*/
	unsigned char   bp_dead_turbulence_shift;
	/*The amount of gradients - exceeding the threshold - which triggers
	 *  a hot pixel detection.*/
	unsigned char   bp_dev_hot_grad_trig_lvl;
	/*The amount of gradients - exceeding the threshold - which triggers
	 *  a dead pixel detection .*/
	unsigned char   bp_dev_dead_grad_trig_lvl;
};

/*! configuration for correction of bad pixel block*/
struct cifisp_bp_correction_config {
	enum cifisp_bp_corr_type corr_type; /* bad pixel correction type*/
	enum cifisp_bp_corr_rep corr_rep; /* replace approach*/
	enum cifisp_bp_corr_mode corr_mode;   /* bad pixel correction mode*/
	unsigned char new_acc_thresh;
	unsigned short abs_hot_thres;  /* Absolute hot pixel threshold*/
	unsigned short abs_dead_thres; /* Absolute dead pixel threshold*/
	unsigned short dev_hot_thres;  /* Hot Pixel deviation Threshold*/
	unsigned short dev_dead_thres; /* Dead Pixel deviation Threshold*/
	struct cifisp_bp_table bp_corr_tbl;
};



/*! BLS fixed subtraction values. The values will be subtracted from the sensor
 *  values. Therefore a negative value means addition instead of subtraction!*/
struct cifisp_bls_fixed_val {
	/*! Fixed (signed!) subtraction value for Bayer pattern position A.*/
	signed short fixed_a;
	/*! Fixed (signed!) subtraction value for Bayer pattern position B.*/
	signed short fixed_b;
	/*! Fixed (signed!) subtraction value for Bayer pattern position C.*/
	signed short fixed_c;
	/*! Fixed (signed!) subtraction value for Bayer pattern position D.*/
	signed short fixed_d;
};

struct cifisp_gamma_curve_x_axis_pnts {
	unsigned int  gamma_dx0;
	unsigned int  gamma_dx1;
};

/* Configuration used by bad pixel detection & correction */
struct cifisp_bpc_config {
	struct cifisp_bp_correction_config corr_config;
	struct cifisp_bp_detection_config det_config;
};

/* Configuration used by black level subtraction */
struct cifisp_bls_config {
	/*! Automatic mode activated means that the measured values
	 * are subtracted.Otherwise the fixed subtraction
	 * values will be subtracted.*/
	bool enable_auto;
	unsigned char en_windows;
	struct cifisp_window bls_window1;      /*!< Measurement window 1.*/
	struct cifisp_window bls_window2;      /*!< Measurement window 2*/
	/*! Set amount of measured pixels for each Bayer position
	 * (A, B,C and D) to 2^bls_samples.*/
	unsigned char bls_samples;
	struct cifisp_bls_fixed_val fixed_val; /*!< Fixed subtraction values.*/
};

/* Configuration used by sensor degamma */
struct cifisp_sdg_config {
	unsigned short curve_r[257];
	unsigned short curve_gb[257];
	unsigned short curve_gr[257];
	unsigned short curve_b[257];
	struct cifisp_gamma_curve_x_axis_pnts xa_pnts;// unused.
};

/* Configuration used by Lens shading correction */
struct cifisp_lsc_config {
    /*
     * Data table should be uint32_t according to spec.
     * Considering the limited ram size of GSD, odd and
     * even area will apply the same uint16_t value
     */
    unsigned short r_data_tbl[CIFISP_LSC_DATA_TBL_SIZE];
    unsigned short gr_data_tbl[CIFISP_LSC_DATA_TBL_SIZE];
    unsigned short gb_data_tbl[CIFISP_LSC_DATA_TBL_SIZE];
    unsigned short b_data_tbl[CIFISP_LSC_DATA_TBL_SIZE];
    unsigned int x_grad_tbl[CIFISP_LSC_GRAD_TBL_SIZE];
    unsigned int y_grad_tbl[CIFISP_LSC_GRAD_TBL_SIZE];
    unsigned int x_size_tbl[CIFISP_LSC_SIZE_TBL_SIZE];
    unsigned int y_size_tbl[CIFISP_LSC_SIZE_TBL_SIZE];
	unsigned short config_width;
	unsigned short config_height;
};

/* Configuration used by auto white balance */
struct cifisp_awb_meas_config {
	/*! white balance measurement window (in pixels)
	 * Note: currently the h and v offsets are mapped to grid offsets*/
	struct cifisp_window awb_wnd;
	enum cifisp_awb_mode_type awb_mode;
	/*! only pixels values < max_y contribute to awb measurement
	 * (set to 0 to disable this feature)*/
	unsigned char    max_y;
	/*! only pixels values > min_y contribute to awb measurement*/
	unsigned char    min_y;
	/*! Chrominance sum maximum value, only consider pixels with Cb+Cr
	 *  smaller than threshold for awb measurements*/
	unsigned char    max_csum;
	/*! Chrominance minimum value, only consider pixels with Cb/Cr
	 *  each greater than threshold value for awb measurements*/
	unsigned char    min_c;
	/*! number of frames - 1 used for mean value calculation
	 *  (ucFrames=0 means 1 Frame)*/
	unsigned char    frames;
	/*! reference Cr value for AWB regulation, target for AWB*/
	unsigned char    awb_ref_cr;
	/*! reference Cb value for AWB regulation, target for AWB*/
	unsigned char    awb_ref_cb;
	unsigned short     gb_sat;
	unsigned short     gr_sat;
	unsigned short     b_sat;
	unsigned short     r_sat;
	unsigned char     grid_h_dim;
	unsigned char     grid_v_dim;
	unsigned short   grid_h_dist;
	unsigned short   grid_v_dist;
	bool enable_ymax_cmp;
	/*before(1) or after(0) white balance gains adjustment*/
	bool rgb_meas_pnt;
};

struct cifisp_awb_gain_config {
	unsigned short  gain_red;
	unsigned short  gain_green_r;
	unsigned short  gain_blue;
	unsigned short  gain_green_b;
};

/* Configuration used by ISP filtering */
struct cifisp_flt_config {
	unsigned int flt_mask_sharp0;
	unsigned int flt_mask_sharp1;
	unsigned int flt_mask_diag;
	unsigned int flt_mask_blur_max;
	unsigned int flt_mask_blur;
	unsigned int flt_mask_lin;
	unsigned int flt_mask_orth;
	unsigned int flt_mask_v_diag;
	unsigned int flt_mask_h_diag;
	unsigned int flt_lum_weight;
	unsigned short flt_blur_th0;
	unsigned short flt_blur_th1;
	unsigned short flt_sharp0_th;
	unsigned short flt_sharp1_th;
	unsigned char  flt_chrom_h_mode;    /* ISP_FILT_MODE register fields*/
	unsigned char  flt_chrom_v_mode;    /* ISP_FILT_MODE register fields*/
	unsigned char  flt_diag_sharp_mode; /* ISP_FILT_MODE register fields*/
	unsigned char  flt_mode;            /* ISP_FILT_MODE register fields*/
};

/* Configuration used by Bayer DeMosaic */
struct cifisp_bdm_config {
	unsigned char demosaic_th;
};

/* Configuration used by Cross Talk correction */
struct cifisp_ctk_config {
	unsigned short coeff0;
	unsigned short coeff1;
	unsigned short coeff2;
	unsigned short coeff3;
	unsigned short coeff4;
	unsigned short coeff5;
	unsigned short coeff6;
	unsigned short coeff7;
	unsigned short coeff8;
	/* offset for the crosstalk correction matrix */
	unsigned short ct_offset_r;
	unsigned short ct_offset_g;
	unsigned short ct_offset_b;
};

/* Configuration used by Gamma Out correction */
struct cifisp_goc_config {
	unsigned short gamma[CIFISP_GAMMA_OUT_MAX_SAMPLES];
};

/* Multi Axis Color Control Structures - MACC */
struct cifisp_macc_coeff {
	/*! Macc coefficients. Refer to equation 23 in datasheet */
	unsigned int coeff0;
	/*! Macc coefficients. Refer to equation 23 in datasheet */
	unsigned int coeff1;
};

struct cifisp_macc_config {
	struct cifisp_macc_coeff seg0; /*!< Macc coefficients for segment */
	struct cifisp_macc_coeff seg1;
	struct cifisp_macc_coeff seg2;
	struct cifisp_macc_coeff seg3;
	struct cifisp_macc_coeff seg4;
	struct cifisp_macc_coeff seg5;
	struct cifisp_macc_coeff seg6;
	struct cifisp_macc_coeff seg7;
	struct cifisp_macc_coeff seg8;
	struct cifisp_macc_coeff seg9;
	struct cifisp_macc_coeff seg10;
	struct cifisp_macc_coeff seg11;
	struct cifisp_macc_coeff seg12;
	struct cifisp_macc_coeff seg13;
	struct cifisp_macc_coeff seg14;
	struct cifisp_macc_coeff seg15;
};

/* CCM (Color Correction) */
struct cifisp_cproc_config {
	unsigned char c_out_range;
	unsigned char y_in_range;
	unsigned char y_out_range;
	unsigned char contrast;
	unsigned char brightness;
	unsigned char sat;
	unsigned char hue;
};

struct cifisp_tmap_config {
	unsigned short tmap_y[CIFISP_TONE_MAP_TABLE_SIZE];
	unsigned short tmap_c[CIFISP_TONE_MAP_TABLE_SIZE];
};

/* Configuration used by Histogram */
struct cifisp_hst_config {
	enum cifisp_histogram_mode mode;
	unsigned char histogram_predivider;
	struct cifisp_window meas_window;
};

/* Configuration used by Auto Exposure Control */
struct cifisp_aec_config {
	enum cifisp_exp_ctrl_autostop autostop;
	struct cifisp_window meas_window;
};

/* YC FLT */
struct cifisp_ycflt_config {
	unsigned int ctrl;
	unsigned int chr_ss_ctrl;
	unsigned int chr_ss_fac;
	unsigned int chr_ss_offs;
	unsigned int chr_nr_ctrl;
	unsigned int lum_eenr_edge_gain;
	unsigned int lum_eenr_corner_gain;
	unsigned int lum_eenr_fc_crop_pos;
	unsigned int lum_eenr_fc_crop_neg;
	unsigned int lum_eenr_fc_gain_pos;
	unsigned int lum_eenr_fc_gain_neg;
};

struct cifisp_last_capture_config {
	struct cifisp_ycflt_config ycflt;
	struct cifisp_tmap_config  tmap;
	struct cifisp_cproc_config cproc;
	struct cifisp_macc_config  macc;
	struct cifisp_goc_config   goc;
	struct cifisp_ctk_config   ctk;
	struct cifisp_bdm_config   bdm;
	struct cifisp_flt_config   flt;
	struct cifisp_awb_gain_config awb_gain;
	struct cifisp_awb_meas_config awb_meas;
	struct cifisp_lsc_config lsc;
	struct cifisp_sdg_config sdg;
	struct cifisp_bls_config bls;
};

struct cifisp_afc_config {
		unsigned char num_afm_win; /* max CIFISP_AFM_MAX_WINDOWS */
		struct cifisp_window afm_win[CIFISP_AFM_MAX_WINDOWS];
		unsigned int thres;
		unsigned int var_shift;
};

/*Private IOCTLs for Marvin ISP */
/* Bad Pixel detection & Correction*/
#define CIFISP_IOC_G_BPC \
	_IOR('v', BASE_VIDIOC_PRIVATE + 0, struct cifisp_bpc_config)
#define CIFISP_IOC_S_BPC \
	_IOW('v', BASE_VIDIOC_PRIVATE + 1, struct cifisp_bpc_config)
/* Black Level Subtraction */
#define CIFISP_IOC_G_BLS \
	_IOR('v', BASE_VIDIOC_PRIVATE + 2, struct cifisp_bls_config)
#define CIFISP_IOC_S_BLS \
	_IOW('v', BASE_VIDIOC_PRIVATE + 3, struct cifisp_bls_config)
/* Sensor DeGamma */
#define CIFISP_IOC_G_SDG \
	_IOR('v', BASE_VIDIOC_PRIVATE + 4, struct cifisp_sdg_config)
#define CIFISP_IOC_S_SDG \
	_IOW('v', BASE_VIDIOC_PRIVATE + 5, struct cifisp_sdg_config)
/* Lens Shading Correction */
#define CIFISP_IOC_G_LSC \
	_IOR('v', BASE_VIDIOC_PRIVATE + 6, struct cifisp_lsc_config)
#define CIFISP_IOC_S_LSC \
	_IOW('v', BASE_VIDIOC_PRIVATE + 7, struct cifisp_lsc_config)
/* Auto White Balance */
#define CIFISP_IOC_G_AWB_MEAS \
	_IOR('v', BASE_VIDIOC_PRIVATE + 8, struct cifisp_awb_meas_config)
#define CIFISP_IOC_S_AWB_MEAS \
	_IOW('v', BASE_VIDIOC_PRIVATE + 9, struct cifisp_awb_meas_config)
/* ISP Filtering( Sharpening & Noise reduction */
#define CIFISP_IOC_G_FLT \
	_IOR('v', BASE_VIDIOC_PRIVATE + 10, struct cifisp_flt_config)
#define CIFISP_IOC_S_FLT \
	_IOW('v', BASE_VIDIOC_PRIVATE + 11, struct cifisp_flt_config)
/* Bayer Demosaic */
#define CIFISP_IOC_G_BDM \
	_IOR('v', BASE_VIDIOC_PRIVATE + 12, struct cifisp_bdm_config)
#define CIFISP_IOC_S_BDM \
	_IOW('v', BASE_VIDIOC_PRIVATE + 13, struct cifisp_bdm_config)
/* Cross Talk correction */
#define CIFISP_IOC_G_CTK \
	_IOR('v', BASE_VIDIOC_PRIVATE + 14, struct cifisp_ctk_config)
#define CIFISP_IOC_S_CTK \
	_IOW('v', BASE_VIDIOC_PRIVATE + 15, struct cifisp_ctk_config)
/* Gamma Out Correction */
#define CIFISP_IOC_G_GOC \
	_IOR('v', BASE_VIDIOC_PRIVATE + 16, struct cifisp_goc_config)
#define CIFISP_IOC_S_GOC \
	_IOW('v', BASE_VIDIOC_PRIVATE + 17, struct cifisp_goc_config)
/* Histogram Measurement */
#define CIFISP_IOC_G_HST \
	_IOR('v', BASE_VIDIOC_PRIVATE + 18, struct cifisp_hst_config)
#define CIFISP_IOC_S_HST \
	_IOW('v', BASE_VIDIOC_PRIVATE + 19, struct cifisp_hst_config)
/* Auto Exposure Measurements */
#define CIFISP_IOC_G_AEC \
	_IOR('v', BASE_VIDIOC_PRIVATE + 20, struct cifisp_aec_config)
#define CIFISP_IOC_S_AEC \
	_IOW('v', BASE_VIDIOC_PRIVATE + 21, struct cifisp_aec_config)
#define CIFISP_IOC_G_BPL \
	_IOR('v', BASE_VIDIOC_PRIVATE + 22, struct cifisp_aec_config)
#define CIFISP_IOC_G_AWB_GAIN \
	_IOR('v', BASE_VIDIOC_PRIVATE + 23, struct cifisp_awb_gain_config)
#define CIFISP_IOC_S_AWB_GAIN \
	_IOW('v', BASE_VIDIOC_PRIVATE + 24, struct cifisp_awb_gain_config)
#define CIFISP_IOC_G_CPROC \
	_IOR('v', BASE_VIDIOC_PRIVATE + 25, struct cifisp_cproc_config)
#define CIFISP_IOC_S_CPROC \
	_IOW('v', BASE_VIDIOC_PRIVATE + 26, struct cifisp_cproc_config)
#define CIFISP_IOC_G_MACC \
	_IOR('v', BASE_VIDIOC_PRIVATE + 27, struct cifisp_macc_config)
#define CIFISP_IOC_S_MACC \
	_IOW('v', BASE_VIDIOC_PRIVATE + 28, struct cifisp_macc_config)
#define CIFISP_IOC_G_TMAP \
	_IOR('v', BASE_VIDIOC_PRIVATE + 29, struct cifisp_tmap_config)
#define CIFISP_IOC_S_TMAP \
	_IOW('v', BASE_VIDIOC_PRIVATE + 30, struct cifisp_tmap_config)
#define CIFISP_IOC_G_YCFLT \
	_IOR('v', BASE_VIDIOC_PRIVATE + 31, struct cifisp_ycflt_config)
#define CIFISP_IOC_S_YCFLT \
	_IOW('v', BASE_VIDIOC_PRIVATE + 32, struct cifisp_ycflt_config)
#define CIFISP_IOC_G_AFC \
	_IOR('v', BASE_VIDIOC_PRIVATE + 33, struct cifisp_afc_config)
#define CIFISP_IOC_S_AFC \
	_IOW('v', BASE_VIDIOC_PRIVATE + 34, struct cifisp_afc_config)
#define CIFISP_IOC_G_IE \
	_IOR('v', BASE_VIDIOC_PRIVATE + 35, struct cifisp_ie_config)
#define CIFISP_IOC_S_IE \
	_IOW('v', BASE_VIDIOC_PRIVATE + 36, struct cifisp_ie_config)
#define CIFISP_IOC_G_LAST_CONFIG \
	_IOR('v', BASE_VIDIOC_PRIVATE + 37, struct cifisp_last_capture_config)

/*  CIF-ISP Private control IDs */
#define V4L2_CID_CIFISP_BPC    (V4L2_CID_PRIVATE_BASE + 0)
#define V4L2_CID_CIFISP_BLS    (V4L2_CID_PRIVATE_BASE + 1)
#define V4L2_CID_CIFISP_SDG    (V4L2_CID_PRIVATE_BASE + 2)
#define V4L2_CID_CIFISP_LSC    (V4L2_CID_PRIVATE_BASE + 3)
#define V4L2_CID_CIFISP_AWB_MEAS    (V4L2_CID_PRIVATE_BASE + 4)
#define V4L2_CID_CIFISP_FLT    (V4L2_CID_PRIVATE_BASE + 5)
#define V4L2_CID_CIFISP_BDM    (V4L2_CID_PRIVATE_BASE + 6)
#define V4L2_CID_CIFISP_CTK    (V4L2_CID_PRIVATE_BASE + 7)
#define V4L2_CID_CIFISP_GOC    (V4L2_CID_PRIVATE_BASE + 8)
#define V4L2_CID_CIFISP_HST    (V4L2_CID_PRIVATE_BASE + 9)
#define V4L2_CID_CIFISP_AEC    (V4L2_CID_PRIVATE_BASE + 10)
#define V4L2_CID_CIFISP_AWB_GAIN    (V4L2_CID_PRIVATE_BASE + 11)
#define V4L2_CID_CIFISP_CPROC    (V4L2_CID_PRIVATE_BASE + 12)
#define V4L2_CID_CIFISP_MACC    (V4L2_CID_PRIVATE_BASE + 13)
#define V4L2_CID_CIFISP_TMAP    (V4L2_CID_PRIVATE_BASE + 14)
#define V4L2_CID_CIFISP_YCFLT    (V4L2_CID_PRIVATE_BASE + 15)
#define V4L2_CID_CIFISP_AFC    (V4L2_CID_PRIVATE_BASE + 16)
#define V4L2_CID_CIFISP_IE    (V4L2_CID_PRIVATE_BASE + 17)

/* Camera Sensors' running modes */
#define CI_MODE_PREVIEW	0x8000
#define CI_MODE_VIDEO	0x4000
#define CI_MODE_STILL_CAPTURE	0x2000
#define CI_MODE_CONTINUOUS	0x1000
#define CI_MODE_NONE	0x0000
#ifdef __cplusplus
}
#endif

#endif
