cmake_minimum_required(VERSION 2.8)

find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(ode_lorenz ode_lorenz.cpp)
