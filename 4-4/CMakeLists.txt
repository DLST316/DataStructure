cmake_minimum_required(VERSION 3.27)
project(4_4 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(4_4
        DisjoingSet.c
        DisjoingSet.h
        DStest.c)
