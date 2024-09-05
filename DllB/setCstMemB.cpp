#include "setCstMemB.h"

namespace dllB
{

void setCstMem()
{
    CUDA_CHECK_RETURN(cudaMemcpyToSymbol(getCstMem(), cst, sizeof(float)));
}

} // namespace dllB