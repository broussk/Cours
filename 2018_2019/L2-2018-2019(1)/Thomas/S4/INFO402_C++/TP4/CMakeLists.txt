cmake_minimum_required(VERSION 3.13)
project(TP4)

set(CMAKE_CXX_STANDARD 14)

include_directories(partie1)

add_executable(TP4
        partie1/main.cpp
        partie1/tp.cpp
        partie1/tp.hpp)
