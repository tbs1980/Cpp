cmake_minimum_required(VERSION 2.8)
project(mpi_isend_ireceive CXX)

find_package(MPI)
find_package(Boost COMPONENTS mpi)

include_directories(${MPI_CXX_INCLUDE_PATH})
include_directories(${Boost_INCLUDE_DIRS})

add_executable(test_isend_ireceive test_isend_ireceive.cpp)
target_link_libraries(test_isend_ireceive ${Boost_LIBRARIES} ${MPI_CXX_LIBRARIES})
