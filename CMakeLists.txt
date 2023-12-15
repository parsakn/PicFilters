cmake_minimum_required(VERSION 3.26)
project(P6)

set(CMAKE_CXX_STANDARD 20)

add_executable(P6 src/main.cpp
        include/bmp.hpp
        src/bmp.cpp
        src/Filter.cpp
        src/Filter.h
        src/manual.h
)
