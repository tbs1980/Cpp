cmake_minimum_required(VERSION 2.8)

set(CMAKE_MACOSX_RPATH 1)

project(BoostSharedObjectCreation)

find_package(Boost REQUIRED COMPONENTS serialization)

include_directories(${Boost_INCLUDE_DIRS})

if(APPLE)
    #set (CMAKE_SHARED_LINKER_FLAGS "-flat_namespace -undefined dynamic_lookup")
    set (CMAKE_SHARED_LINKER_FLAGS "-undefined dynamic_lookup")
endif(APPLE)

add_library(boost_serial SHARED boost_serial.cpp)
