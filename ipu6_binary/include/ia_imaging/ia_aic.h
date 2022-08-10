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
 * \file ia_aic.h
 * \brief AIC main header file.
 */

#ifndef __IA_AIC_HEADER__
#define __IA_AIC_HEADER__

#include "ia_aic_types.h"

/*! Create AIC context and initialize AIC
*
* Create new AIC context for the pipeline. Performs basic initialization of the context
*
* \param [in] aiqbData          Tuning data information
*
* \return                       Pointer to new context, Null if failed
*/
LIBEXPORT
IaAicCtx *iaAicInit(
    const IaBinaryData *aiqbData);

/*! Configure statistics
*
* Configure statistics for the context. This API changes
* while the implementation of the statistics part progress
*
* \param [in] ctx               Pointer to AIC context created using ia_aic_init
* \param [in] iaCmc             Sensor characterization information
* \param [in] maxStatsWidth     Maximum statistics width
* \param [in] maxStatsHeight    Maximum statistics height
* \param [in] maxNumStatsIn     Maximum number of statistics
*
* \return ia_error_none / error code on failure
*/
LIBEXPORT
ia_err iaAicStatisticsInit(
    IaAicCtx *ctx,
    ia_cmc_t *iaCmc,
    unsigned int maxStatsWidth,
    unsigned int maxStatsHeight,
    unsigned int maxNumStatsIn);

/*! Uninitilize everything from AIC context
 *
 * \param [in] ctx              Pointer to AIC context created using ia_aic_init
 */
LIBEXPORT
void iaAicDeinit(IaAicCtx *ctx);

/*! Run AIC common for the pipeline
 *
 * Run common part of the AIC. Call processes input parameters from
 * the 3A+ algoritms and performs tuning interpolation
 * for the all the kernels which are registered to this context.
 *
 * This call is not thread safe. Only one instance may be running at the same time.
 *
 * Caller must guarantee following:
 * Input data buffers pointed by pointers in input_params retains unmodified until
 * ia_aic_run_kernels calls for all registered CB/PG's have been run. ia_aic_run_aic doesn't
 * make internal copies of the large tables pointed by input_params.
 *
 * \param [in] ctx              Pointer to AIC context created using ia_aic_init
 * \param [in] sequenceId       Sequence number of this AicRun
 * \param [in] inputParams     Pointer to AIC input parameter structure
 *
 * \return ia_error_none / error code on failure
 *
 */
LIBEXPORT
ia_err iaAicRunAic(
    IaAicCtx *ctx,
    unsigned long long sequenceId,
    const IaAicInputParams *inputParams);

/*! Process all kernels from group registered as group_id
 *
 *  Run all kernels from group known as group_id in this context.
 *
 * \param [in] ctx          Pointer to AIC context created using ia_aic_init
 * \param [in] groupId      PG / CB ID given at registration time
 * \param [out] outputData  Provide a way to have read-only access to ISP API simulation format data
 *
 * return ia_err_none in success. Errorcode on failure
 */
LIBEXPORT
ia_err iaAicRunKernels(
    IaAicCtx *ctx,
    int groupId,
    IaBinaryData *outputData);

/*! Register fragment descriptor for a kernel
 *
 * Register fragment descriptor for a kernel with uuid in CB/PG group_id.
 *
 * \param [in] ctx          Pointer to AIC context created using ia_aic_init
 * \param [in] uuid         Kernel identifier (PAL UUID)
 * \param [in] groupId      CB/PG id given at registration phase
 * \param [in] fragd        Fragment descriptor
 *
 * return ia_err_none in success. Errorcode on failure
 *
 */
LIBEXPORT
ia_err iaAicRegisterKernelFragmentDescriptor(
    IaAicCtx *ctx,
    int uuid,
    int groupId,
    IaAicFragmentDesc *fragd);

/*! Register section offsets for the kernel
 *
 * Register section offsets for kernel "uuid" in CB/PG "group_id" for fragment "fragment"
 * Offsets are byte offsets from the beginning of the terminal buffer.
 * This call forms internally relationship between section offsets, kernel and terminal.
 *
 * This function must be called for every kernel in CB/PG and for every terminal related
 * to the kernel.
 *
 * \param [in] ctx              Pointer to AIC context created using ia_aic_init
 * \param [in] uuid             Kernel identifier (PAL UUID)
 * \param [in] groupId          CB/PG id given at registration phase
 * \param [in] terminalType     Type of terminal (param, program, spatial)
 * \param [in] terminalIndex    terminal index of where this call is tied to
 * \param [in] offsets          Array of section byte offsets
 * \param [in] numOffsets       Number of offsets in offsets array
 * \param [in] fragment         Fragment number
 *
 * return ia_err_none in success. Errorcode on failure
 *
 */
LIBEXPORT
ia_err iaAicRegisterKernelOffset(
    IaAicCtx *ctx,
    int uuid,
    int groupId,
    IaAicBufferTypes terminalType,
    uint32_t terminalIndex,
    uint32_t *offsets,
    uint32_t numOffsets,
    uint32_t fragment);

/*! Configure CB/PG to AIC context
 *
 * Configure a CB/PG using kernel run list. This function creates internal
 * context for a CB/PG in this context. CB/PG is known as group_id from now on.
 *
 * Note: Kernel list is fixed after this call. Kernel must cover all kernels in
 * CB/PG and it may not contain any extra kernel.
 *
 * \param [in] ctx              Pointer to AIC context created using ia_aic_init
 * \param [in] groupId          unique identifier for this group of kernels in this context
 * \param [in] fragmentCount    Number of fragments in this group
 * \param [in] kernelGroup      List of kernels in this group with per kernel configuration data
 *
 * return ia_err_none in success. Errorcode on failure
 */
LIBEXPORT
ia_err iaAicConfigure(
    IaAicCtx *ctx,
    int groupId,
    int fragmentCount,
    ImagingKernelGroup *kernelGroup);

/*! Register HW register format output buffer
 *
 * Register a buffer to AIC context. All but pixel buffers must be registered to the context
 * before the streaming starts.
 *
 * \param [in] ctx              Pointer to AIC context created using ia_aic_init
 * \param [in] groupId          unique identifier for this group of kernels in this context
 * \param [in] terminalIndex    index to terminal.
 * \param [in] buffer           Buffer descriptor
 *
 * return ia_err_none in success. Errorcode on failure
 *
 */
LIBEXPORT
ia_err iaAicRegisterBuffer(
    IaAicCtx *ctx,
    int groupId,
    uint32_t terminalIndex,
    IaAicBuffer *buffer);

/*! Get current buffer
 *
 * Get current output buffer for terminal. Same buffer can be returned several times
 * if the content hasn't been updated.
 *
 * \param [in] ctx              Pointer to AIC context created using ia_aic_init
 * \param [in] groupId          unique identifier for this group of kernels in this context
 * \param [in] terminalIndex    index to terminal
 * \param [in] target           Pointer to buffer desciptor where this function stores the buffer information
 *
 * return ia_err_none in success. Errorcode on failure
 *
 */
LIBEXPORT
ia_err iaAicGetBuffer(
    IaAicCtx *ctx,
    int groupId,
    uint32_t terminalIndex,
    IaAicBuffer *target);

/*! Get terminal payload buffer size requirement
 *
 * Get buffer size requirement that satisfies \see ia_aic_register_buffer().
 *
 * \note Essentially, this is convenience function that cumulates sizes of
 *       sections registered per terminal. Where dynamic size is applicable a
 *       kernel specific routines may be bound to the routine.
 *
 * \param [in] ctx              Pointer to AIC context created using ia_aic_init
 * \param [in] groupId          unique identifier for this group of kernels in this context
 * \param [in] terminalIndex    index to terminal
*
 * return size requirement in success. Zero on failure
 *
 */
LIBEXPORT
size_t iaAicGetBufferSize(IaAicCtx *ctx,
                          int groupId,
                          uint32_t terminalIndex);

/*! Decode statistics
 *
 * Decodes statistics produced by kernels within the group
 *
 * \param [in] ctx         Pointer to AIC context created using ia_aic_init
 * \param [in] groupId     unique identifier for this group of kernels in this context
 * \param [in] sequenceId  sequence id of the frame to decode from
 * \param [out] stats      pointer to statistics store where to decode to
 *
 * \todo consider input requirements of statistics decode operations, i.e.
 *       RGB-IR, SVE, HDR, DOL. Shouldn't AIC context hold all this information?
 *       Caller ensures input parameters ownership deferring until decode
 *       returns (for bufferset corresponding to sequence_id).
 *
 * return ia_err_none in success. Error code on failure
 */
LIBEXPORT
ia_err iaAicDecodeStatistics(IaAicCtx *ctx,
                             int groupId,
                             uint32_t sequenceId,
                             IaCcatStatistics *stats);

/* =========================================================================== */
/* Depricated interface. Once users of these are removed these will be removed */
/* =========================================================================== */
LIBEXPORT
void iaAicRunKernelsToImagingKernelInfo(ia_isp_bxt_run_kernels_t *from,
                                        ImagingKernelInfo *to);

LIBEXPORT
ia_aic_ctx_t *
ia_aic_init(
    const ia_binary_data *aiqb_data);

LIBEXPORT
ia_err ia_aic_statistics_init(
    ia_aic_ctx_t *ctx,
    ia_cmc_t *ia_cmc,
    unsigned int max_stats_width,
    unsigned int max_stats_height,
    unsigned int max_num_stats_in);

LIBEXPORT
void ia_aic_deinit(ia_aic_ctx_t *ctx);

LIBEXPORT
ia_err ia_aic_run_aic(
    ia_aic_ctx_t *ctx,
    const ia_isp_bxt_input_params_v2 *input_params);

LIBEXPORT
ia_err ia_aic_run_kernels(
    ia_aic_ctx_t *ctx,
    int group_id,
    ia_binary_data *output_data);

LIBEXPORT
ia_err ia_aic_run_ate(
    ia_aic_ctx_t *ctx,
    const ia_isp_bxt_input_params_v2 *input_params,
    ia_binary_data *output_data);

LIBEXPORT
ia_err ia_aic_register_kernel_fragment_descriptor(
    ia_aic_ctx_t *ctx,
    int uuid,
    int group_id,
    ia_aic_fragment_desc_t *fragd);

LIBEXPORT
ia_err ia_aic_register_kernel_offset(
    ia_aic_ctx_t *ctx,
    int uuid,
    int group_id,
    ia_aic_buffer_types_t terminal_type,
    uint32_t terminal_index,
    uint32_t *offsets,
    uint32_t num_offsets,
    uint32_t fragment);

LIBEXPORT
ia_err ia_aic_configure(
    ia_aic_ctx_t *ctx,
    int group_id,
    int fragmentCount,
    ia_isp_bxt_program_group *pg);

LIBEXPORT
ia_err ia_aic_configure(
    ia_aic_ctx_t *ctx,
    int group_id,
    int fragmentCount,
    ia_isp_bxt_program_group *pg,
    const ia_isp_bxt_input_params_v2 *input_params);

LIBEXPORT
ia_err ia_aic_register_buffer(
    ia_aic_ctx_t *ctx,
    int group_id,
    uint32_t terminal_index,
    ia_aic_buffer *buffer);

LIBEXPORT
ia_err ia_aic_get_buffer(
    ia_aic_ctx_t *ctx,
    int group_id,
    uint32_t terminal_index,
    ia_aic_buffer *target);

LIBEXPORT
size_t ia_aic_get_buffer_size(ia_aic_ctx_t *ctx,
                              int group_id,
                              uint32_t terminal_index);

LIBEXPORT
ia_err ia_aic_decode_statistics(ia_aic_ctx_t *ctx,
                                int group_id,
                                uint32_t sequence_id,
                                ia_atbx_statistics *stats);

#endif
