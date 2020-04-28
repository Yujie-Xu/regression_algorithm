cmake_minimum_required(VERSION 3.10)

project(data)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES make_dataset.cpp CSV_reader.cpp CSV_reader.h test.cpp dataset.cpp dataset.h)

add_executable(data ${SOURCE_FILES})