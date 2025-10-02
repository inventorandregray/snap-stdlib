cmake_minimum_required(VERSION 2.6)
project(snap_stdlib)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2")

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(test examples/test.cpp)
