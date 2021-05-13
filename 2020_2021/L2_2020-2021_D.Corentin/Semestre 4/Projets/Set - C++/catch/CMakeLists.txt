cmake_minimum_required(VERSION 3.9)
project(Devel)

set(CMAKE_CXX_STANDARD 17)
add_executable(catch-sample        unit-test.cpp catch.h)
