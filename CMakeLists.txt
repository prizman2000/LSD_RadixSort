cmake_minimum_required(VERSION 3.12)
project(RadixSort_LSD)

set(CMAKE_CXX_STANDARD 17)

add_executable(RadixSort_LSD main.cpp src/radixSort_LSD.cpp src/radixSort_LSD.h)