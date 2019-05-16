cmake_minimum_required(VERSION 3.10)
project(MatrixAbsFactory)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES main.cpp MatrixTemplate.h headers.h MatrixFactory.h MatrixFactoryType.h)
add_executable(MatrixAbsFactory main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(MatrixAbsFactory core)
