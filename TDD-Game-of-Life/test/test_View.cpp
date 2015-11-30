//
// Created by dima on 29.11.15.
//

#include <gtest/gtest.h>
#include <string>
#include "../src/View.hpp"
#include "../src/Cell.hpp"

TEST(View, corrOutput) {

    std::vector<Cell> cell = {
            Cell(0, 0, Status::DEAD), Cell(1, 0, Status::DEAD), Cell(2, 0, Status::DEAD),
            Cell(0, 1, Status::DEAD), Cell(1, 1, Status::LIVE), Cell(2, 1, Status::DEAD),
            Cell(0, 2, Status::DEAD), Cell(1, 2, Status::LIVE), Cell(2, 2, Status::LIVE)
    };

    std::string corr_out( "...\n"".*.\n"".**");

    std::ostringstream out;
    View view(out, 3,3);
    view.print(cell);

    EXPECT_EQ(out.str(), corr_out);

}
