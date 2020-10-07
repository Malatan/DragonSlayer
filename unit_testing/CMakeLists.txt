cmake_minimum_required(VERSION 3.15)
# 'unit_testing' is the subproject name
project(unit_testing)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib/googletest-master)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(unit_testing_run mainTest.cpp test.cpp)

target_link_libraries(unit_testing_run gtest gtest_main)

