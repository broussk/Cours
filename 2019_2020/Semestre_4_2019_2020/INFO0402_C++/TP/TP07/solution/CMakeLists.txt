cmake_minimum_required(VERSION 3.9)
project(Devel)

set(CMAKE_CXX_STANDARD 17)

add_executable(solve07-static main-static.cpp Array.h classA.h ObjectCounters.h)
add_executable(solve07-fixed main-fixed.cpp Array.h classA.h ObjectCounters.h)
add_executable(solve07-dynamic main-dynamic.cpp Array.h classA.h ObjectCounters.h)
