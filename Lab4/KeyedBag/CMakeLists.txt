cmake_minimum_required(VERSION 3.12)
project(KeyedBag)

set(CMAKE_CXX_STANDARD 14)

add_executable(KeyedBag keyed_bag_tester.cpp keyed_bag.cpp keyed_bag.h)