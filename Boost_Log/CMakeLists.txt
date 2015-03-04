cmake_minimum_required(VERSION 2.8)

find_package(Boost REQUIRED COMPONENTS log system thread)

include_directories(${Boost_INCLUDE_DIRS})

#add_definitions(-DBOOST_LOG_NO_THREADS)
add_executable(boostLogExample boostLogExample.cpp)

target_link_libraries(boostLogExample ${Boost_LIBRARIES})
