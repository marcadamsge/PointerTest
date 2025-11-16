cmake_minimum_required(VERSION 3.31)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

project("PointerTest")
enable_testing()

add_executable(pointer_test "pointer_test.cpp")
