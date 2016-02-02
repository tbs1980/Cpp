cmake_minimum_required(VERSION 2.8)

find_package(Boost REQUIRED  COMPONENTS date_time)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(dateTime dateTime.cpp)
target_link_libraries(dateTime ${Boost_LIBRARIES})
