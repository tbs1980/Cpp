cmake_minimum_required(VERSION 2.8)
project(MPI_distribute_vector CXX)

find_package(Eigen3 3.1.2 REQUIRED)
find_package(MPI)
find_package(Boost COMPONENTS mpi  serialization)

include_directories(${EIGEN3_INCLUDE_DIR})
include_directories(${MPI_CXX_INCLUDE_PATH})
include_directories(${Boost_INCLUDE_DIRS})


add_executable(mpi_dist_vect mpi_dist_vect.cpp)
target_link_libraries(mpi_dist_vect ${MPI_CXX_LIBRARIES} ${Boost_LIBRARIES} ) 
