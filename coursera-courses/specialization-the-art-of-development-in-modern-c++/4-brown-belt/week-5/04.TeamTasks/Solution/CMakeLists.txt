cmake_minimum_required(VERSION 3.16)
project(TeamTask)

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

# Debug mode ON
# -DCMAKE_BUILD_TYPE=Debug
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(
 	libraries
	SHARED
		test_runner.h
		profile.h
		headers.h
)

add_executable(${PROJECT_NAME}
  	team_task.cpp
)

# If there is no cpp file in add_library
set_target_properties(libraries PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${PROJECT_NAME} PUBLIC libraries)
