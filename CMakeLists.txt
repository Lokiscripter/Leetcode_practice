cmake_minimum_required(VERSION 3.20)
project(Leetcode_practice)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Leetcode_practice
        564-find-the-closest-palindrome/564-find-the-closest-palindrome.cpp
        6-zigzag-conversion/6-zigzag-conversion.cpp
        common.h)
