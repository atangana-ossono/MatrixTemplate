cmake_minimum_required(VERSION 3.10)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp MatrixTest.cpp OperatorTest.cpp)
add_executable(runMatrixTests ${TEST_SOURCE_FILES})
target_link_libraries(runMatrixTests gtest gtest_main core)