
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})


# Add test cpp file
add_executable( runUnitTests
        test_Game.cpp
        test_Parser.cpp
        test_View.cpp
        test_Controller.cpp
        ../src/Game.cpp
        ../src/Game.hpp
        ../src/Cell.hpp
        ../src/Parser.hpp
        ../src/Parser.cpp
        ../src/View.cpp
        ../src/View.hpp
        ../src/Controller.hpp
        ../src/Controller.cpp
        )
# Link test executable against gtest & gtest_main
target_link_libraries(runUnitTests gtest gtest_main)
add_test( runUnitTests runUnitTests )