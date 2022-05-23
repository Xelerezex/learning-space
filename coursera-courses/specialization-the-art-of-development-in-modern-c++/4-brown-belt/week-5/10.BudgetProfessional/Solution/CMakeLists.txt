cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ENABLE_EXPORTS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_BUILD_TYPE Debug)

set(BUDGET_TEST true)
add_compile_options(-Wall -Wextra -pedantic -Werror)

set(this_project budget)

set(utility ~/workspace/cpp-brown-belt/utility)
include_directories(${utility})

project(${this_project} CXX)

set(headers
  date.h
  budget_system.h
  )

set(sources
  ${this_project}.cpp
  date.cpp
  budget_system.cpp
  )

if(BUDGET_TEST)
  add_definitions(-DBUDGET_TEST)
  list(APPEND headers budget_test.h)
  list(APPEND sources budget_test.cpp)
endif(BUDGET_TEST)

add_executable(${this_project} ${sources} ${headers})

