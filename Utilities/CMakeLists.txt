cmake_minimum_required(VERSION 3.18)
project(Utilities)

# Find CUDA package
find_package(CUDAToolkit REQUIRED)


# Define the executable target
file(GLOB SOURCES "*.cpp")
file(GLOB SOURCES_CU "*.cu")

file(GLOB HEADER "*.h")
file(GLOB HEADER_CU "*.cuh")

add_library(Utilities INTERFACE 
    ${SOURCES} 
    ${SOURCES_CU}
    ${HEADER} 
    ${HEADER_CU})


target_include_directories(Utilities INTERFACE .)

target_link_directories(Utilities INTERFACE 
    ${CUDAToolkit_LIBRARY_DIR})

target_link_libraries(Utilities INTERFACE 
    CUDA::cudart
)


# Set properties for Debug/Release configurations
set_target_properties(Utilities PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_NAME}/../../"
    LIBRARY_OUTPUT_DIRECTORY "${PROJECT_NAME}/../../"
    ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_NAME}/../../"
    DEBUG_OUTPUT_NAME "d_${PROJECT_NAME}"
    RELEASE_OUTPUT_NAME "${PROJECT_NAME}"
    MINSIZEREL_OUTPUT_NAME "${PROJECT_NAME}"
    RELWITHDEBINFO_OUTPUT_NAME "${PROJECT_NAME}"
)