cmake_minimum_required(VERSION 3.2)
project(perceptron)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(perceptron ${SOURCE_FILES} Perceptron.cpp Perceptron.h LearnPerceptron.cpp LearnPerceptron.h Visualizer.cpp Visualizer.h ILinearClassificationLearner.h Parser.cpp Parser.h)

##--------------------------------------Qt
find_package( Qt5Core REQUIRED )
find_package( Qt5Widgets REQUIRED )
find_package( Qt5Gui REQUIRED )
qt5_use_modules( perceptron Core Widgets Gui )