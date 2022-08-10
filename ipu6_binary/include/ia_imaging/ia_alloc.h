/*
 * Copyright 2018-2021 Intel Corporation
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
  * \file ia_alloc.h
  * \brief Linear scope stack allocator interface.
  */

#ifndef IA_ALLOC_H_
#define IA_ALLOC_H_

#include "ia_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*LDRA_INSPECTED 612 s */
typedef void(*finalizer_function)(void *ptr);
/*LDRA_INSPECTED 67 x */
typedef struct ia_alloc_t ia_alloc;

/*!
 *  Initializes the linear allocator.
 *
 *  \param [in] size Size of the allocator memory space.
 *                   If 0, no allocation is made at this point and memory must be reserved with ia_alloc_reserve().
 *
 *  \return A pointer to the allocator object, or NULL if errors.
 */
LIBEXPORT ia_alloc* ia_alloc_init(size_t size);

/*!
 *  Initializes the linear allocator using pre-allocated memory.
 *
 *  \param [in] buffer Pre-allocated memory buffer.
 *  \param [in] size   The size of the given buffer.
 *
 *  \return A pointer to the allocator object, or NULL if errors.
 */
LIBEXPORT ia_alloc* ia_alloc_init_from_memory(void* buffer, size_t size);

/*!
 *  Reserves memory for the allocator. Can also be used to increase the size of the allocation.
 *
 *  \param [in] alloc The allocator.
 *  \param [in] size  The size of the internal memory space to allocate.
 *
 *  \note Stack position is automatically rewound to the start of the allocator buffer.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_nomemory, if out of memory.
 *          ia_err_argument, if invalid allocator or the allocator used pre-allocated memory.
 */
/*LDRA_INSPECTED 25 x */
LIBEXPORT ia_err ia_alloc_reserve(ia_alloc* alloc, size_t size);

/*!
 *  Allocates a block of memory from the allocator memory space.
 *
 *  \param [in] alloc The allocator.
 *  \param [in] size  The size of the requested allocation.
 *
 *  \return A pointer to the allocation, or NULL, if ran out of allocator memory space.
 */
LIBEXPORT void* ia_alloc_allocate(ia_alloc* alloc, size_t size);

/*!
 *  Allocates a block of memory from the allocator with a custom specified finalizer for destruction.
 *
 *  \param [in] alloc The allocator.
 *  \param [in] size  The size of the requested allocation.
 *  \param [in] func  A pointer to the finalizer function.
 *
 *  \return A pointer to the allocation, or NULL, if ran out of allocator memory space.
 */
/*LDRA_INSPECTED 67 x */
LIBEXPORT void* ia_alloc_allocate_with_finalizer(ia_alloc* alloc, size_t size, finalizer_function func);

/*!
 *  Enters a new scope.
 *
 *  \param [in] alloc The allocator.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_internal, if maximum scope depth was reached.
 */
LIBEXPORT ia_err ia_alloc_enter_scope(ia_alloc* alloc);

/*!
*  Leaves a scope.
*
*  \param [in] alloc The allocator.
*
*  \return ia_err_none, if no errors.
*          ia_err_internal, if there is a mismatch between enter and leave calls.
*/
LIBEXPORT ia_err ia_alloc_leave_scope(ia_alloc* alloc);

/*!
 *  Deinitializes the linear allocator.
 *
 *  \param [in] alloc The allocator.
 */
LIBEXPORT void ia_alloc_deinit(ia_alloc* alloc);

#ifdef __cplusplus
}
#endif


#endif /* IA_ALLOC_H_ */
