cmake_minimum_required(VERSION 3.21)
project(DSA_bag2)

set(CMAKE_CXX_STANDARD 14)

add_executable(DSA_bag2 main.cpp Bag.cpp Bag.h BagIterator.cpp BagIterator.h ExtendedTest.cpp ExtendedTest.h ShortTest.cpp ShortTest.h)
