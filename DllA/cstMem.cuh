#pragma once
#include "cuda_include.h" // IWYU pragma: keep
#include "dll_framework.h"
namespace dllA
{

PLUGIN_INTERFACE_EXPORT __device__ __host__ float *getCstMem();

namespace
{
__forceinline__ __device__ float useCstMem(float addToCstMem)
{
    return addToCstMem + *getCstMem();
}
} // namespace

float kernelCallerRetrieveCstMem();
} // namespace dllA