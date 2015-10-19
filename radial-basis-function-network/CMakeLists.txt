cmake_minimum_required(VERSION 3.2)
project(radial_basis_function_network)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Data.hxx Data.h DataPoint.hxx DataPoint.h Parser.hxx Parser.h KMeansClustering.hxx KMeansClustering.h mltMath.h)
add_executable(radial_basis_function_network ${SOURCE_FILES})
target_link_libraries( radial_basis_function_network ${OpenCV_LIBS} )

