#include "setCstMemA.h"
#include "cstMem.cuh"
#include "cuda_include.h"

namespace dllA
{

void setCstMem(float cst)
{
    CUDA_CHECK(cudaMemcpyToSymbol(getCstMem(), &cst, sizeof(float)));
}

} // namespace dllA