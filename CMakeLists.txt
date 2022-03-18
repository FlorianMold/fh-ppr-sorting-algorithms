cmake_minimum_required(VERSION 3.21)
project(fh_ppr_sorting_algorithms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

add_executable(fh_ppr_sorting_algorithms main.cpp MergeSort.cpp MergeSort.h QuickSort.cpp QuickSort.h)
