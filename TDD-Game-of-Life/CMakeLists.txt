cmake_minimum_required(VERSION 3.3)
project( game_of_life )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(test)

set(SOURCE_FILES
        src/main.cpp
        src/Game.cpp
        src/Game.hpp
        src/View.cpp
        src/View.hpp
        src/Parser.cpp
        src/Parser.hpp
        src/Cell.hpp
        src/Controller.hpp
        src/Controller.cpp
)


add_executable(game_of_life ${SOURCE_FILES})