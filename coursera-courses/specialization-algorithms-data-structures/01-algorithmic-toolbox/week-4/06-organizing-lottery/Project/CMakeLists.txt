cmake_minimum_required(VERSION 3.16)
project(OrganizingLottery)

# CXX=clang++ CC=clang
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread -Og -ggdb3 -pipe -O2 -Wall -Werror -Wextra")

set(SOURCES 06-organizing-lottery.cpp)

add_executable(OrganizingLottery ${SOURCES})
