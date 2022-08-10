/*
* Copyright 2018 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

/*!
 * \file ia_aic_types.h
 * \brief AIC data types for external use
 */

#ifndef __IA_AIC_TYPES_HEADER__
#define __IA_AIC_TYPES_HEADER__

#include <ia_isp_types.h>
#include <ia_ob.h>
#include <ia_ltm.h>
#include <ia_view.h>
#include <ia_bcomp.h>
#include <ia_dvs.h>

/*
 * All that external parties needs to know about the AIC internals
 */
struct ia_aic_handle;
typedef struct ia_aic_handle ia_aic_handle_t;

class IaAic;
typedef class IaAic IaAicCtx;
typedef ia_rectangle IaRectangle;

/* Depricated */
typedef struct ia_isp_bxt_run_kernels ia_isp_bxt_run_kernels_t;
typedef struct ia_isp_bxt_resolution_info ia_isp_bxt_resolution_info_t;
typedef struct ia_isp_bxt_program_group ia_isp_bxt_program_group;
typedef struct ia_isp_bxt_input_params_v2 ia_isp_bxt_input_params_v2;

enum IaAicBufferTypes
{
    iaAicParamInBuffer = 0,
    iaAicParamOutBuffer,
    iaAicProgramBuffer,
    iaAicSpatialInBuffer,
    iaAicSpatialOutBuffer,
    iaAicFrameInBuffer,
    iaAicFrameOutBuffer
};

struct IaAicFragmentDesc
{
    unsigned int fragmentWidth;   /*!< The width of the fragment. */
    unsigned int fragmentHeight;  /*!< The height of the fragment. */
    unsigned int fragmentStartX;  /*!< The x offset from the top-left corner of the full image. */
    unsigned int fragmentStartY;  /*!< The y offset from the top-left corner of the full image. */
};

/*! AIC buffer descriptor
*
* A structure which descripes buffers between caller and AIC
*
*/
struct ia_aic_buffer;
struct IaAicBuffer
{
    unsigned int id;         /*! Buffer type identifier */
    size_t size;             /*! Size of the payload data */
    unsigned long minSeqNum; /*! Min assosiated sequence number */
    unsigned long maxSeqNum; /*! Max assosiated sequence number */
    void *payloadPtr;        /*! Pointer to payload data */
    union {                  /*! Reference to caller side. Caller may use this as it wants */
        void *ptr;
        uint64_t u64;
        uint32_t u32;
    } callerRef;

    LIBEXPORT
    IaAicBuffer &operator=(const ia_aic_buffer &from);
};

struct IaBinaryData
{
    void *data;
    unsigned int size;
};

/*!
* \brief Defines how ISP kernel should modify bit depth of image passing through it.
*/
struct ImagingKernelFormatInfo
{
    uint32_t inputFormat;  /*!< FourCC of format in input edge of the kernel
                                (can be used to retrieve full format descrition from ISP format bridge */
    uint32_t outputFormat; /*!< FourCC of format in output edge of the kernel */
};

/*!
* \brief Describes options for run-time kernel control.
*/
enum ImagingKernelEnableControl
{
    kernelPassthrough = 0,
    kernelEnable,
    kernelDisable
};

struct ImagingKernelResolutionInfo
{
    int inputWidth;          /*!< Input image width. */
    int inputHeight;         /*!< Input image height. */
    IaRectangle inputCrop;   /*!< Crop offsets for input image. Cropping happens before processing the input image. */
    int outputWidth;         /*!< Output image width. */
    int outputHeight;        /*!< Output image height. */
    IaRectangle outputCrop;  /*!< Crop offsets for output image. Cropping happens after scaling to output resolution. */

    LIBEXPORT
    ImagingKernelResolutionInfo &operator=(const ia_isp_bxt_resolution_info_t &from);
    LIBEXPORT
    void ToLegacy(ia_isp_bxt_resolution_info_t &r) const;
};

struct ImagingKernelInfo
{
    unsigned int uuid;                             /*!< ia_pal_uuid. ISP API (output) UUID */
    int enable;                                    /*!< Tristate control to 0-disable, 1-enable, 2-passthrough the kernel */
    int resolutionChanging;                        /*!< Indicate if the kernel responds to resolution change configuration */
    ImagingKernelResolutionInfo resolutionInfo;    /*!< Resolution change configuration */
    ImagingKernelResolutionInfo resolutionHistory; /*!< Cumulated resolution changes before the kernel */
    ImagingKernelFormatInfo bpp;                   /*!< Kernel input and output bits per pixel value */
    unsigned int streamId;                         /*!< Depricated. AIC doesn't use / need this. Use stream id in IKG instead */
    unsigned int branchId;                         /*!< Optional: Indicate that kernel branches its input to multiple outputs
                                                        (multiple entries of info exist per kernel) */
    unsigned int srcPeerUuid;                      /*!< Indicate that kernel's input is at edge and connected to other kernel, default 0.
                                                        (non-zero mandatory for edges of kernel group / unit-of-execution) */
    unsigned int sinkPeerUuid;                     /*!< Indicate that kernel's output is at edge and connected to other kernel, default 0.
                                                        (non-zero mandatory for edges of kernel group / unit-of-execution) */
    uint32_t metadata[4];                          /*!< Kernel specific metadata */
};

struct ImagingKernelGroup
{
    unsigned int kernelCount;                       /*!< Number of kernels in the kernelList .*/
    ImagingKernelInfo *kernelList;                  /*!< Array of kernels in the group. */
    unsigned int operationMode;                     /*!< Operation mode for selecting proper tunings. Is usually associated to different resolutions. */
    unsigned int streamId;                          /*!< Indicate predefined tuning id to use with this group */

    LIBEXPORT
    void ImportLegacy(const ia_isp_bxt_program_group &pg, ImagingKernelInfo *kernelList);
    LIBEXPORT
    void ToLegacy(ia_isp_bxt_program_group &r,
             ia_isp_bxt_run_kernels_t *run_kernels,
             ia_isp_bxt_resolution_info_t *res_info,
             ia_isp_bxt_resolution_info_t *res_history) const;
};

struct IaAicInputParams
{
    /* Mandatory parameters */
    ia_aiq_frame_params *sensorFrameParams;         /*!< Mandatory. Sensor frame parameters. Describe frame scaling/cropping done in sensor. */
    ia_aiq_awb_results *awbResults;                 /*!< Mandatory. WB results which are to be used to calculate next ISP parameters (WB gains, color matrix,etc). */
    ia_aiq_gbce_results *gbceResults;               /*!< Mandatory. GBCE Gamma tables which are to be used to calculate next ISP parameters.*/
    ia_aiq_ae_results *aeResults;                   /*!< Mandatory. Exposure results which are to be used to calculate next ISP parameters.
                                                                     Currently only exposure times, analog and digital gains are used. For convenience reasons AIC takes
                                                                     ae results and not only needed parameters. */
    ia_aiq_pa_results_v1 *paResults;                /*!< Mandatory. Parameter adaptor results from AIQ. */
    ia_aiq_sa_results_v1 *saResults;                /*!< Mandatory. Shading adaptor results from AIQ. */
    ia_aiq_hist_weight_grid *weightGrid;            /*!< Mandatory. Weight map to be used in the next frame histogram calculation. */
    ia_isp_feature_setting nrSetting;               /*!< Mandatory. Feature setting for noise reduction algorithms. */
    ia_isp_feature_setting eeSetting;               /*!< Mandatory. Feature setting for edge enhancement algorithms. */
    ia_ltm_results *ltmResults;                     /*!< Mandatory. Local tone mapping results from LTM. */
    ia_ltm_drc_params *ltmDrcParams;                /*!< Mandatory. DRC parameters from LTM. */
    unsigned long long timestamp;                   /*!< Mandatory. Current timestamp (is microseconds) when ia_isp_bxt_run function is called. AIC uses timestamp to decide what
                                                                     calculations are done based on tunable run rate for each ISP configuration algorithm. */
    ia_dvs_image_transformation *gdcTransformation; /*!< Mandatory. Image transformation parameters for GDC5 ISP FW. This feature replaces the need for morph_table usage.*/
    ia_media_format mediaFormat;                    /*!< Mandatory. Selected Digital television output format.(e.g. BT709) */

    /* Optional parameters */
    char manualBrightness;                          /*!< Optional. Manual brightness value range [-128,127]. Value 0 means no change. */
    char manualContrast;                            /*!< Optional. Manual contrast value range [-128,127]. Value 0 means no change. */
    char manualHue;                                 /*!< Optional. Manual hue value range [-128,127]. Value 0 means no change.
                                                                    Value -96 means red become blue, green become red, blue become green */
    char manualSaturation;                          /*!< Optional. Manual saturation value range [-128,127]. Value 0 means no change. */
    ia_isp_effect effects;                          /*!< Optional. Manual setting for special effects. Combination of ia_isp_effect enums.*/
    ia_isp_custom_controls *customControls;         /*!< Optional. Custom control parameter for interpolating between different tunings.
                                                                    If custom controls are not used, pointer can be set as null.*/
    float manualDigitalGain;                        /*!< Optional. Additional digital gain that is applied to all color channels of the image before ISP statistics collection.
                                                                    Values less than 1.0 means no additional gain. */
    ia_ob_output obBlackLevel;                      /*!< Optional. Black level values calculated on-the-fly when the sensor supports. */
    ia_view_config_t* const *viewParams;             /*!< Optional. View parameters for running in GDC5 mode.*/
    ia_bcomp_results const *bcompResults;           /*!< Optional.  bit-compression curves. */

    LIBEXPORT
    IaAicInputParams &operator=(const ia_isp_bxt_input_params_v2 &from);
    LIBEXPORT
    void ToLegacy(ia_isp_bxt_input_params_v2 &r) const;
};

/** \todo replace dummy stats store datatype with ccat definition once ready */
struct IaCcatStatistics
{
    char reserved[4096];
};

// ==========================================================================
// Depricated interface
// ==========================================================================

typedef class IaAic ia_aic_ctx_t;

struct ia_atbx_statistics
{
    char reserved[4096];
};

typedef struct ia_aic_buffer
{
    uint32_t id;       /*! Buffer type identifier */
    size_t size;       /*! Size of the payload data */
    void *payload_ptr; /*! Pointer to payload data */
    union {            /*! Reference to caller side. Caller may use this as it wants */
        void *ptr;
        uint64_t u64;
        uint32_t u32;
    } caller_ref;

    ia_aic_buffer &operator=(const IaAicBuffer &from);
} ia_aic_buffer_t;

typedef struct ia_aic_fragment_desc
{
    uint16_t fragment_width;   /*!< The width of the fragment. */
    uint16_t fragment_height;  /*!< The height of the fragment. */
    uint16_t fragment_start_x; /*!< The x offset from the top-left corner of the full image. */
    uint16_t fragment_start_y; /*!< The y offset from the top-left corner of the full image. */
} ia_aic_fragment_desc_t;

typedef enum ia_aic_buffer_types
{
    ia_aic_param_in_buffer = iaAicParamInBuffer,
    ia_aic_program_buffer = iaAicProgramBuffer,
    ia_aic_spatial_in = iaAicSpatialInBuffer,
    ia_aic_spatial_out = iaAicSpatialOutBuffer,
} ia_aic_buffer_types_t;

#endif

