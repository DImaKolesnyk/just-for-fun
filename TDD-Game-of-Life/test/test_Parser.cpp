//
// Created by dima on 29.11.15.
//

#include <gtest/gtest.h>
#include "../src/Parser.hpp"
#include "../src/Cell.hpp"

TEST(Parser, correctParsCels) {


    int m(3), n(3);
    std::istringstream inp( "...\n"
                            ".*.\n"
                            ".**");

   std::vector<Cell> corr_cell = {
            Cell(0, 0, Status::DEAD), Cell(1, 0, Status::DEAD), Cell(2, 0, Status::DEAD),
            Cell(0, 1, Status::DEAD), Cell(1, 1, Status::LIVE), Cell(2, 1, Status::DEAD),
            Cell(0, 2, Status::DEAD), Cell(1, 2, Status::LIVE), Cell(2, 2, Status::LIVE)
    };

    Parser parser(inp);
std::vector<Cell> g_inp = parser.getGrid(m, n);

    EXPECT_EQ(g_inp, corr_cell);
}
