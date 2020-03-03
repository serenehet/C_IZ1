cmake_minimum_required(VERSION 3.15)
project(dz1 C)

set(CMAKE_C_STANDARD 99)

include_directories("${PROJECT_SOURCE_DIR}/include")

file(GLOB sources
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.c")

add_executable(C_IZ1 ${sources})