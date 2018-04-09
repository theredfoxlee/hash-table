cmake_minimum_required(VERSION 3.9.1)
project(sdizo)

include_directories(include)
FILE(GLOB SOURCES src/*.cpp)

SET(GCC_COVERAGE_COMPILE_FLAGS "-std=c++17 -Wall -pedantic")

add_executable(sdizo ${SOURCES})
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})
