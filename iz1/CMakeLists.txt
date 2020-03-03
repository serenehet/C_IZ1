cmake_minimum_required(VERSION 3.15)
project(iz1 C)

set(CMAKE_C_STANDARD 99)

add_executable(iz1 src/main.c include/dz.h src/dz.c)