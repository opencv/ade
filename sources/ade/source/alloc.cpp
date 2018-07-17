// Copyright (C) 2018 Intel Corporation
//
//
// SPDX-License-Identifier: Apache-2.0
//

#include "ade/memory/alloc.hpp"

#include <malloc.h>

#include "ade/util/math.hpp"
#include "ade/util/assert.hpp"

namespace ade
{

void* aligned_alloc(std::size_t size, std::size_t alignment)
{
    ADE_ASSERT(util::is_pow2(alignment));
#ifdef WIN32
    return _aligned_malloc(size, alignment);
#else
    return memalign(alignment, size);
#endif
}

void aligned_free(void* ptr)
{
#ifdef WIN32
    return _aligned_free(ptr);
#else
    return free(ptr);
#endif
}

}
