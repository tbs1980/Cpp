cmake_minimum_required(VERSION 2.8)

find_package(Boost)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(exponentialIntegral exponentialIntegral.cpp )
