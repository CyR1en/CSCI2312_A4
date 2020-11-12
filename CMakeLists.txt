cmake_minimum_required(VERSION 3.17)
project(CSCI2312_A4)

set(CMAKE_CXX_STANDARD 11)
include_directories(include)
add_executable(CSCI2312_A4 src/main.cpp include/Creature.h src/Creature.cpp)