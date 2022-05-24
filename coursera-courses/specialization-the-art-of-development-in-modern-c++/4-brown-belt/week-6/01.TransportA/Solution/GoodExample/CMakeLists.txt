cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ENABLE_EXPORTS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_BUILD_TYPE Debug)

set(this_project transport_guide)

set(utility ~/workspace/cpp-brown-belt/utility)
include_directories(${utility})

project(${this_project} CXX)

set(headers
  bus.h
  stop_manager.h
  transport_manager.h
  transport_manager_command.h
  json.h
  json_parser.h
  graph.h
  router.h
  )

set(sources
  bus.cpp
  stop_manager.cpp
  transport_manager.cpp
  json.cpp
  json_parser.cpp
  ${this_project}.cpp
  )

add_executable(${this_project} ${sources} ${headers})

