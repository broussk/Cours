cmake_minimum_required(VERSION 3.9)
project(TP)

set(CMAKE_CXX_STANDARD 17)


add_executable(Ex1a TP1/Ex1a.cpp)
add_executable(Ex1b TP1/Ex1b.cpp)
add_executable(Ex2 TP1/Ex2.cpp)
add_executable(Ex3a TP1/Ex3a.cpp)
add_executable(Ex3b TP1/Ex3b.cpp)
add_executable(mod1 TP1/mod1.cpp)
add_executable(mod2 TP1/mod2.cpp)
add_executable(prog TP1/prog.cpp)
add_executable(Exo1 TP2/Exo1.cpp)
add_executable(Exo2 TP2/Exo2.cpp)

add_executable(tp3 TP3/tp3.cpp TP3/Color.h TP3/SVGstream.h)

add_executable(tp5 TP5/tp5.cpp TP5/StaticArray.h)