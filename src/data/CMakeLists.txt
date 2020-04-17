cmake_minimum_required(VERSION 3.10)

project(data)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES make_dataset.cpp)

add_executable(data ${SOURCE_FILES})