#include <gtest/gtest.h>
#include "../src/Game.hpp"

TEST(GameTest, uncorrectParam) {

    int argc(2);
    char* argv[] = { "game", "4"};


    ASSERT_THROW({
                     Game g;
                     g.run(argc, argv);
                 }, std::invalid_argument);
}


