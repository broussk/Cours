cmake_minimum_required(VERSION 3.9)
project(Devel)

set(CMAKE_CXX_STANDARD 17)

add_executable(TP5-solve
        Array.h
        Curve.cpp
        Curve.h
        Figure.cpp
        Figure.h
        GeomBase.cpp
        GeomBase.h
        Surface.cpp
        Surface.h
        SVG.cpp
        SVG.h
        main.cpp
)
