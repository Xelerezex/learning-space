cmake_minimum_required(VERSION 3.16)
project(HashPoint)

# CXX=clang++ CC=clang cmake ..
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread -Og -ggdb3 -pipe -O2 -Wall -Werror -Wextra")

set(SOURCES hash_point.cpp)

add_executable(HashPoint ${SOURCES})
