#include "cstMem.cuh"

namespace dllA
{

__constant__ float cstMem;

__device__ __host__ float *getCstMem()
{
    return &cstMem;
}

__global__ void retrieveCstMem(float* output)
{
    *output = *getCstMem();
}

float kernelCallerRetrieveCstMem()
{
    float* d_output;
    float* h_output = new float();
    CUDA_CHECK(cudaMalloc(&d_output, sizeof(float)));
    
    retrieveCstMem<<<1,1>>>(d_output);

    CUDA_CHECK(cudaMemcpy(h_output,d_output, sizeof(float), cudaMemcpyDeviceToHost));
    CUDA_CHECK(cudaFree(d_output));
    float ret = *h_output;
    delete(h_output);
    return ret;
}
} // namespace dllA