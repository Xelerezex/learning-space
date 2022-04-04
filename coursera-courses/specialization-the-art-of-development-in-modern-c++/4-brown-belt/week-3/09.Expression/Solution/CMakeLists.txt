cmake_minimum_required(VERSION 3.16)
project(Expression)


# set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Og")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra")


set(CMAKE_INCLUDE_CURRENT_DIR ON)


add_executable(${PROJECT_NAME}
  	main.cpp
	Common.h
	profile.h
	test_runner.h
	headers.h
)
