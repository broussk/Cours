cmake_minimum_required(VERSION 3.15)
project(Set)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(catch)
add_executable(set  main.cpp Set.h ObjectCounters.h classA.h)
add_executable(main_avltree main_avltree.cpp Node.h AVLTree.h)