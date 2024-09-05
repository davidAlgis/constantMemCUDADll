cmake_minimum_required(VERSION 3.18)
project(constantMemCUDADll)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(UTILITIES_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/Utilities")

# cf. https://stackoverflow.com/questions/31006581/cuda-device-unresolved-extern-function
set(CMAKE_CUDA_SEPARABLE_COMPILATION ON)
enable_language(CUDA)
set(CMAKE_CUDA_FLAGS_RELEASE "${CMAKE_CUDA_FLAGS_RELEASE} -O3 -use_fast_math")
set(CMAKE_CUDA_FLAGS_DEBUG "${CMAKE_CUDA_FLAGS_DEBUG} -G")

add_subdirectory(Utilities)
add_subdirectory(DllA)
add_subdirectory(DllB)
add_subdirectory(Exe)


