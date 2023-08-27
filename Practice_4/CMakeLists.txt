cmake_minimum_required(VERSION 3.24)
project(Practice_4)

set(CMAKE_CXX_STANDARD 17)

add_executable(Practice_4 main.cpp
        Blocks/Blocks.hpp)

file(COPY "blocks.txt"  DESTINATION  "/")
