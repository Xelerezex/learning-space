enable_testing()

add_executable(tests tests.cpp)

target_link_libraries(tests gtest gmock pthread)