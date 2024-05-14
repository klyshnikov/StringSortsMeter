cmake_minimum_required(VERSION 3.28)
project(StringSortAnalyzer)

set(CMAKE_CXX_STANDARD 17)

add_executable(StringSortAnalyzer main.cpp
        algorithms/Algorithms.cpp
        algorithms/Algorithms.h
        generator/StringGenerator.cpp
        generator/StringGenerator.h
        metter/SortsMetter.cpp
        metter/SortsMetter.h)
