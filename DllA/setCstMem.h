#pragma once
#include "dll_framework.h"

namespace dllA
{

PLUGIN_INTERFACE_EXPORT void setCstMem(float cst)
{
    CUDA_CHECK_RETURN(cudaMemcpyToSymbol(getCstMem(), cst, sizeof(float)));
}

} // namespace dllA