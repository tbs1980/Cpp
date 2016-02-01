cmake_minimum_required(VERSION 2.8)

find_package(Boost REQUIRED  COMPONENTS program_options)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(programOptions programOptions.cpp)
target_link_libraries(programOptions ${Boost_LIBRARIES})
