/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2017-2021 Intel Corporation
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
#ifndef IA_TIME_MEAS_H_
#define IA_TIME_MEAS_H_
/* Enable time measurement instrumentation manually */
#if 0
#define ENABLE_IA_TIME_MEAS
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef ENABLE_IA_TIME_MEAS

/*!
* \brief Start time measuremet
* Start high resulution time measurement
*
* \param[in] slot                          Mandatory. slot number used in measurement
*
*/
void ia_time_start_meas(unsigned int slot);

/*!
* \brief End time measuremet
* Stop high resolution time measurement
*
* \param[in] slot                          Mandatory. slot number used in measurement
*
*/
void ia_time_stop_meas(unsigned int slot);

/*!
* \brief Calculate time in microseconds
* Calculate time delta in microseconds which was spend between ia_time_start_meas and
* ia_time_stop_meas calls
*
* \param[in] iters                         Mandatory. Number of iterations. use 1 to print absolute time.
* \param[in] slot                          Mandatory. slot number used in measurement
*
* \return Calculated time delta in microseconds
*/
unsigned long long int ia_time_calculate(int iters, unsigned int slot);

/*!
* \brief Print time in microseconds
* Print time delta in microseconds which was spend between ia_time_start_meas and
* ia_time_stop_meas calls
*
* \param[in] comm                          Mandatory. string to be printed before measurement result
* \param[in] iters                         Mandatory. Number of iterations. use 1 to print absolute time.
* \param[in] slot                          Mandatory. slot number used in measurement
*/
void ia_time_print(const char* comm, int iters, unsigned int slot);

/*!
* \brief Temporarily put measurement on hold
* Measurement can be put on hold if some part of code is excluded from the measurement
*
* \param[in] slot                          Mandatory. slot number used in measurement
*
*/
void ia_time_hold_meas(unsigned int slot);

/*!
* \brief Continue temporarily paused measurement
* Resume measurement which was put on hold using ia_time_hold_meas call
*
* \param[in] slot                          Mandatory. slot number used in measurement
*
*/
void ia_time_resume_meas(unsigned int slot);

/*!
* \brief Start time measurement and put it on hold
* Start high resulution time measurement and put in on hold immediately
*
* \param[in] slot                          Mandatory. slot number used in measurement
*
*/
void ia_time_start_and_hold_meas(unsigned int slot);


/*!
* \brief Allocate measurement slots
* Allocate measurement slots to be used in measurement. Call is thread safe
*
* \param[in] num_slot                      Mandatory. Number of slots requested
*
*\return first reserved slot number
*/
unsigned int ia_time_alloc_slots(unsigned int num_slots);

/*!
* \brief Release allocated measurement slots
* Release slots which were allocated using ia_time_alloc_slots
*
* \param[in] slot                          Mandatory. number of the first allocated slot
* \param[in] numslots                      Mandatory. number of slots allocated
*
*/
void ia_time_free_slots(unsigned int slot, unsigned int numslots);

/*!
* \brief Initialize measurement system
* Called before measurement can be done
*
*/
void ia_time_meas_init(void);

/*!
* \brief Uninitialize measurement system
* Called to release resources allocated in init call
*
*/
void ia_time_meas_uninit(void);

#else

#define ia_time_start_meas(slot)
#define ia_time_stop_meas(slot)
#define ia_time_calculate(iters, slot) (unsigned long long int)0
#define ia_time_print(comm, iters, slot)
#define ia_time_hold_meas(slot)
#define ia_time_resume_meas(slot)
#define ia_time_start_and_hold_meas(slot)
#define ia_time_alloc_slots(num_slots) 0
#define ia_time_free_slots(slot, numslots)
#define ia_time_meas_init()
#define ia_time_meas_uninit()

#endif
#ifdef __cplusplus
}
#endif
#endif
