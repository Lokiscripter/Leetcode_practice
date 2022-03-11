cmake_minimum_required(VERSION 3.20)
project(Leetcode_practice)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Leetcode_practice
        564-find-the-closest-palindrome/564-find-the-closest-palindrome.cpp
        6-zigzag-conversion/6-zigzag-conversion.cpp
        2104-sum-of-subarray-ranges/2104-sum-of-subarray-ranges.cpp
        258-add-digits/258-add-digits.cpp
        common.h main.cpp 2100-find-good-days-to-rob-the-bank/2100-find-good-days-to-rob-the-bank.cpp
        504-base-7/504-base-7.cpp
        2134-minimum-swaps-to-group-all-1s-together-ii/2134-minimum-swaps-to-group-all-1s-together-ii.cpp
        2055-plates-between-candles/2055-plates-between-candles.cpp
        209-minimum-size-subarray-sum/209-minimum-size-subarray-sum.cpp
        209-minimum-size-subarray-sum/209-minimum-size-subarray-sum2.cpp 589-n-ary-tree-preorder-traversal/589-n-ary-tree-preorder-traversal.cpp 2049-count-nodes-with-the-highest-score/2049-count-nodes-with-the-highest-score.cpp)
