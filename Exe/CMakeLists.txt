cmake_minimum_required(VERSION 3.18)
project(Exe)

# Find CUDA package
find_package(CUDAToolkit REQUIRED)

# Define the executable target
file(GLOB SOURCES "*.cpp")
file(GLOB HEADER "*.h")

add_executable(Exe ${SOURCES} ${HEADER})

target_include_directories(Exe PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_directories(Exe PUBLIC 
    ${CUDAToolkit_LIBRARY_DIR})

target_link_libraries(Exe PUBLIC 
    DllA
    DllB
)


# Set properties for Debug/Release configurations
set_target_properties(Exe PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_NAME}/../../"
    LIBRARY_OUTPUT_DIRECTORY "${PROJECT_NAME}/../../"
    ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_NAME}/../../"
    DEBUG_OUTPUT_NAME "d_${PROJECT_NAME}"
    RELEASE_OUTPUT_NAME "${PROJECT_NAME}"
    MINSIZEREL_OUTPUT_NAME "${PROJECT_NAME}"
    RELWITHDEBINFO_OUTPUT_NAME "${PROJECT_NAME}"
)

