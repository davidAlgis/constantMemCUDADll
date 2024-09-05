#pragma once
#include "cuda_runtime.h"
#include <iostream>
#include <stdexcept>
/**
 * @brief      Check if a cuda function has succeed and log the cuda error if
 * it's not the case
 *
 * @param      ans   A function that return a cudaError_t
 *
 * @return     a cast into int of the return code (cudaError_t)
 * 0 if it's a success and >0 if it's an error
 */
#define CUDA_CHECK(ans) cudaAssert((ans), __FILE__, __LINE__)

/**
 * @brief      Check if a cuda function has succeed. If it doesn't log the cuda
 * error  and return the error code
 *
 * @param      ans   A function that return a cudaError_t
 *
 */
#define CUDA_CHECK_RETURN(ans)                                                 \
    {                                                                          \
        int ret = cudaAssert((ans), __FILE__, __LINE__);                       \
        if (ret != 0)                                                          \
            return ret;                                                        \
    }

/**
 * @brief      Check if a cuda function has succeed. If it doesn't log the cuda
 * error and a msg and return;
 *
 * @param      ans   The return code of the cuda function
 * @param      msg   A string to log
 *
 */
#define CUDA_CHECK_RETURN_VOID(ans, msg)                                       \
    {                                                                          \
        int ret = cudaAssert((ans), __FILE__, __LINE__);                       \
        if (ret != 0)                                                          \
        {                                                                      \
            Log::log().debugLogError(msg);                                     \
            return;                                                            \
        }                                                                      \
    }

/**
 * @brief      Check if a cuda function has succeed. If it doesn't log the cuda
 * error and a msg and return false.
 *
 * @param      ans   The return code of the cuda function
 *
 */
#define CUDA_CHECK_RETURN_BOOL(ans)                                            \
    {                                                                          \
        int ret = cudaAssert((ans), __FILE__, __LINE__);                       \
        if (ret != 0)                                                          \
        {                                                                      \
            return false;                                                      \
        }                                                                      \
    }

/**
 * @brief      Check if a cuda function has succeed. If it doesn't log the
 * cuda error and throw a runtime error
 *
 * @param      ans   A function that return a cudaError_t
 */
#define CUDA_CHECK_THROW(ans)                                                  \
    {                                                                          \
        int ret = cudaAssert((ans), __FILE__, __LINE__);                       \
        if (ret != 0)                                                          \
            throw std::runtime_error(cudaGetErrorString(ans));                 \
    }

/**
 * @brief      Log an error associated to cuda library if there has been an
 * error during a cuda function
 *
 * @param[in]  code  A return code of a function of cuda library
 * @param[in]  file  The file associated to the function call
 * @param[in]  line  The line associated to the function call
 *
 * @return     the return code
 */
inline int cudaAssert(cudaError_t code, const char *file, int line)
{
    if (code != cudaSuccess)
    {
        char buffer[2048];
        snprintf(buffer, sizeof(buffer), "Cuda error: %i %s %s %d\n", code,
                 cudaGetErrorString(code), file, line);
        std::string strError(buffer);
        std::cout << buffer << '\n';
    }
    return (int)code;
}
