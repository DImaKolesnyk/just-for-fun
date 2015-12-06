cmake_minimum_required(VERSION 3.2)
project(radial_basis_function_network)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp
        Data.cpp
        Data.h
        Point.cpp
        Point.h
        Parser.hxx
        Parser.h
        NetBuilder.hpp
        Net.hpp
        mltMath.h
        mltMath.cpp
        RBFNetBuilder.cpp
        RBFNetBuilder.h
        RBFNet.cpp
        RBFNet.h
        KMeansClustering.cpp
        KMeansClustering.h
        IСlustering.h
        Creator.cpp
        Creator.hpp
        Neuron.h
        Neuron.cpp
        NeuronBuilder.cpp
        NeuronBuilder.hpp
)
add_executable(radial_basis_function_network ${SOURCE_FILES})
target_link_libraries( radial_basis_function_network ${OpenCV_LIBS} )

