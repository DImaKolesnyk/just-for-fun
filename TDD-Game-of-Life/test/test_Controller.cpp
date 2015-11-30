//
// Created by dima on 29.11.15.
//

#include <gtest/gtest.h>
#include "../src/Cell.hpp"
#include "../src/Controller.hpp"

TEST(Controller, NearbyToEdgesTrue) {

    Cell c = Cell(0, 0, Status::LIVE);
    Controller controller( 3, 3);
    bool answ = controller.NearbyToEdges(c);

    EXPECT_EQ( answ, true );

}

TEST(Controller, NearbyToEdgesFalse) {

    Cell c = Cell(1, 1, Status::LIVE);
    Controller controller( 3, 3);
    bool answ = controller.NearbyToEdges(c);

    EXPECT_EQ( answ, false );
}


TEST(Controller, isNeighbourTrue) {
    Cell ca(1,1,Status::DEAD);
    Cell cb(1,0,Status::DEAD);
    Controller c;

    EXPECT_EQ(c.neighbour(ca, cb), true);
}

TEST(Controller, isNeighbourFalse) {
    Cell ca(1,1,Status::DEAD);
    Cell cb(10,0,Status::DEAD);
    Controller c;

    EXPECT_EQ(c.neighbour(ca, cb), false);
}

TEST(Controller, numOfLiveNeighboud) {

    std::vector<Cell> cell = {
            Cell(0, 0, Status::DEAD), Cell(1, 0, Status::DEAD), Cell(2, 0, Status::DEAD),
            Cell(0, 1, Status::DEAD), Cell(1, 1, Status::LIVE), Cell(2, 1, Status::DEAD),
            Cell(0, 2, Status::DEAD), Cell(1, 2, Status::DEAD), Cell(2, 2, Status::DEAD)
    };

    Controller c;
    int num = c.numOfLiveNeighboud(Cell(0, 0, Status::DEAD), cell);

    EXPECT_EQ(num, 1);
}

TEST(Controller, numOfManyLiveNeighboud) {

    std::vector<Cell> cell = {
            Cell(0, 0, Status::DEAD), Cell(1, 0, Status::DEAD), Cell(2, 0, Status::DEAD),
            Cell(0, 1, Status::LIVE), Cell(1, 1, Status::LIVE), Cell(2, 1, Status::DEAD),
            Cell(0, 2, Status::DEAD), Cell(1, 2, Status::LIVE), Cell(2, 2, Status::DEAD)
    };

    Controller c(3,3);
    int num = c.numOfLiveNeighboud(Cell(0, 2, Status::DEAD), cell);

    EXPECT_EQ(num, 3);
}

TEST(Controller, numOfManyManyLiveNeighboud) {

    std::vector<Cell> cell = {
            Cell(0, 0, Status::DEAD), Cell(1, 0, Status::LIVE), Cell(2, 0, Status::DEAD),
            Cell(0, 1, Status::LIVE), Cell(1, 1, Status::DEAD), Cell(2, 1, Status::LIVE),
            Cell(0, 2, Status::LIVE), Cell(1, 2, Status::LIVE), Cell(2, 2, Status::DEAD)
    };

    Controller c(3,3);
    int num = c.numOfLiveNeighboud(Cell(1,1, Status::DEAD), cell);

    EXPECT_EQ(num, 5);
}

TEST(Controller, surviveFalse) {

    std::vector<Cell> cell = {
            Cell(0, 0, Status::DEAD), Cell(1, 0, Status::DEAD), Cell(2, 0, Status::DEAD),
            Cell(0, 1, Status::DEAD), Cell(1, 1, Status::LIVE), Cell(2, 1, Status::DEAD),
            Cell(0, 2, Status::DEAD), Cell(1, 2, Status::DEAD), Cell(2, 2, Status::DEAD)
    };

    Controller c(3, 3);
    bool surv = c.survive(Cell(1, 1, Status::LIVE), cell);

    EXPECT_EQ(surv, false);
}

TEST(Controller, surviveNearbyToEdgesFalse) {

    std::vector<Cell> cell = {
            Cell(0, 0, Status::LIVE), Cell(1, 0, Status::DEAD), Cell(2, 0, Status::DEAD),
            Cell(0, 1, Status::DEAD), Cell(1, 1, Status::LIVE), Cell(2, 1, Status::DEAD),
            Cell(0, 2, Status::DEAD), Cell(1, 2, Status::DEAD), Cell(2, 2, Status::DEAD)
    };

    Controller c(3, 3);
    bool surv = c.survive(Cell(0, 0, Status::LIVE), cell);

    EXPECT_EQ(surv, false);
}

TEST(Controller, surviveTrue) {

    std::vector<Cell> cell = {
            Cell(0, 0, Status::DEAD), Cell(1, 0, Status::LIVE), Cell(2, 0, Status::DEAD),
            Cell(0, 1, Status::DEAD), Cell(1, 1, Status::LIVE), Cell(2, 1, Status::LIVE),
            Cell(0, 2, Status::DEAD), Cell(1, 2, Status::LIVE), Cell(2, 2, Status::DEAD)
    };

    Controller c(3, 3);
    bool surv = c.survive(Cell(1, 1, Status::LIVE), cell);

    EXPECT_EQ(surv, true);
}

TEST(Controller, surviveFalseAnother) {

    std::vector<Cell> cell = {
            Cell(0, 0, Status::DEAD), Cell(1, 0, Status::LIVE), Cell(2, 0, Status::DEAD),
            Cell(0, 1, Status::DEAD), Cell(1, 1, Status::DEAD), Cell(2, 1, Status::LIVE),
            Cell(0, 2, Status::DEAD), Cell(1, 2, Status::LIVE), Cell(2, 2, Status::DEAD)
    };

    Controller c(3, 3);
    bool surv = c.survive(Cell(1, 0, Status::LIVE), cell);

    EXPECT_EQ(surv, false);
}

TEST(Controller, revivesTrue) {

    std::vector<Cell> cell = {
            Cell(0, 0, Status::DEAD), Cell(1, 0, Status::LIVE), Cell(2, 0, Status::DEAD),
            Cell(0, 1, Status::DEAD), Cell(1, 1, Status::DEAD), Cell(2, 1, Status::LIVE),
            Cell(0, 2, Status::DEAD), Cell(1, 2, Status::LIVE), Cell(2, 2, Status::DEAD)
    };

    Controller c(3, 3);
    bool surv = c.revives(Cell(1, 1, Status::DEAD), cell);

    EXPECT_EQ(surv, true);
}

TEST(Controller, revivesFalse) {

    std::vector<Cell> cell = {
            Cell(0, 0, Status::DEAD), Cell(1, 0, Status::LIVE), Cell(2, 0, Status::DEAD),
            Cell(0, 1, Status::DEAD), Cell(1, 1, Status::DEAD), Cell(2, 1, Status::LIVE),
            Cell(0, 2, Status::DEAD), Cell(1, 2, Status::DEAD), Cell(2, 2, Status::DEAD)
    };

    Controller c(3, 3);
    bool surv = c.revives(Cell(1, 1, Status::DEAD), cell);

    EXPECT_EQ(surv, false);
}

TEST(Controller, nextGenerations) {

    std::vector<Cell> cell = {
            Cell(0, 0, Status::DEAD), Cell(1, 0, Status::LIVE), Cell(2, 0, Status::DEAD),
            Cell(0, 1, Status::DEAD), Cell(1, 1, Status::DEAD), Cell(2, 1, Status::LIVE),
            Cell(0, 2, Status::DEAD), Cell(1, 2, Status::LIVE), Cell(2, 2, Status::DEAD)
    };

    std::vector<Cell> corr_next_cell = {
            Cell(0, 0, Status::DEAD), Cell(1, 0, Status::DEAD), Cell(2, 0, Status::DEAD),
            Cell(0, 1, Status::DEAD), Cell(1, 1, Status::LIVE), Cell(2, 1, Status::DEAD),
            Cell(0, 2, Status::DEAD), Cell(1, 2, Status::DEAD), Cell(2, 2, Status::DEAD)
    };

    Controller c(3, 3);
    auto next_cell = c.nextGenerations(cell);

    EXPECT_EQ(next_cell, corr_next_cell);
}

TEST(Controller, nextGenerationsConfiguration) {

    std::vector<Cell> cell = {
            Cell(0, 0, Status::DEAD), Cell(1, 0, Status::DEAD), Cell(2, 0, Status::DEAD), Cell(3, 0, Status::DEAD),
            Cell(0, 1, Status::DEAD), Cell(1, 1, Status::LIVE), Cell(2, 1, Status::LIVE), Cell(3, 1, Status::DEAD),
            Cell(0, 2, Status::DEAD), Cell(1, 2, Status::LIVE), Cell(2, 2, Status::DEAD), Cell(3, 2, Status::DEAD),
            Cell(0, 3, Status::DEAD), Cell(1, 3, Status::DEAD), Cell(2, 3, Status::DEAD), Cell(3, 3, Status::DEAD)
    };

    std::vector<Cell> corr_cell = {
            Cell(0, 0, Status::DEAD), Cell(1, 0, Status::DEAD), Cell(2, 0, Status::DEAD), Cell(3, 0, Status::DEAD),
            Cell(0, 1, Status::DEAD), Cell(1, 1, Status::LIVE), Cell(2, 1, Status::LIVE), Cell(3, 1, Status::DEAD),
            Cell(0, 2, Status::DEAD), Cell(1, 2, Status::LIVE), Cell(2, 2, Status::LIVE), Cell(3, 2, Status::DEAD),
            Cell(0, 3, Status::DEAD), Cell(1, 3, Status::DEAD), Cell(2, 3, Status::DEAD), Cell(3, 3, Status::DEAD)
    };

    Controller c(4, 4);
    auto next_cell = c.nextGenerations(cell);

    EXPECT_EQ(next_cell, corr_cell);
}


TEST(Controller, finalTest_Any_live_cell_with_fewer_than_two_live_neighbours_dies  ) {

    std::vector<Cell> cell = {
            Cell(0, 0, Status::DEAD), Cell(1, 0, Status::DEAD), Cell(2, 0, Status::DEAD), Cell(3, 0, Status::DEAD),
            Cell(0, 1, Status::DEAD), Cell(1, 1, Status::LIVE), Cell(2, 1, Status::LIVE), Cell(3, 1, Status::DEAD),
            Cell(0, 2, Status::DEAD), Cell(1, 2, Status::DEAD), Cell(2, 2, Status::DEAD), Cell(3, 2, Status::DEAD),
            Cell(0, 3, Status::DEAD), Cell(1, 3, Status::DEAD), Cell(2, 3, Status::DEAD), Cell(3, 3, Status::DEAD)
    };

    std::vector<Cell> corr_cell = {
            Cell(0, 0, Status::DEAD), Cell(1, 0, Status::DEAD), Cell(2, 0, Status::DEAD), Cell(3, 0, Status::DEAD),
            Cell(0, 1, Status::DEAD), Cell(1, 1, Status::DEAD), Cell(2, 1, Status::DEAD), Cell(3, 1, Status::DEAD),
            Cell(0, 2, Status::DEAD), Cell(1, 2, Status::DEAD), Cell(2, 2, Status::DEAD), Cell(3, 2, Status::DEAD),
            Cell(0, 3, Status::DEAD), Cell(1, 3, Status::DEAD), Cell(2, 3, Status::DEAD), Cell(3, 3, Status::DEAD)
    };

    Controller c(4, 4);
    auto next_cell = c.nextGenerations(cell);

    EXPECT_EQ(next_cell, corr_cell);
}

TEST(Controller, finalTest_Any_live_cell_with_more_than_three_live_neighbours_dies  ) {

    std::vector<Cell> cell = {
            Cell(0, 0, Status::DEAD), Cell(1, 0, Status::DEAD), Cell(2, 0, Status::DEAD), Cell(3, 0, Status::DEAD), Cell(4, 0, Status::DEAD),
            Cell(0, 1, Status::DEAD), Cell(1, 1, Status::LIVE), Cell(2, 1, Status::LIVE), Cell(3, 1, Status::DEAD), Cell(4, 1, Status::DEAD),
            Cell(0, 2, Status::DEAD), Cell(1, 2, Status::LIVE), Cell(2, 2, Status::LIVE), Cell(3, 2, Status::DEAD), Cell(4, 2, Status::DEAD),
            Cell(0, 3, Status::DEAD), Cell(1, 3, Status::LIVE), Cell(2, 3, Status::DEAD), Cell(3, 3, Status::DEAD), Cell(4, 3, Status::DEAD),
            Cell(0, 4, Status::DEAD), Cell(1, 4, Status::DEAD), Cell(2, 4, Status::DEAD), Cell(3, 4, Status::DEAD), Cell(4, 4, Status::DEAD)
    };

    std::vector<Cell> corr_cell = {
            Cell(0, 0, Status::DEAD), Cell(1, 0, Status::DEAD), Cell(2, 0, Status::DEAD), Cell(3, 0, Status::DEAD), Cell(4, 0, Status::DEAD),
            Cell(0, 1, Status::DEAD), Cell(1, 1, Status::LIVE), Cell(2, 1, Status::LIVE), Cell(3, 1, Status::DEAD), Cell(4, 1, Status::DEAD),
            Cell(0, 2, Status::DEAD), Cell(1, 2, Status::DEAD), Cell(2, 2, Status::DEAD), Cell(3, 2, Status::DEAD), Cell(4, 2, Status::DEAD),
            Cell(0, 3, Status::DEAD), Cell(1, 3, Status::LIVE), Cell(2, 3, Status::LIVE), Cell(3, 3, Status::DEAD), Cell(4, 3, Status::DEAD),
            Cell(0, 4, Status::DEAD), Cell(1, 4, Status::DEAD), Cell(2, 4, Status::DEAD), Cell(3, 4, Status::DEAD), Cell(4, 4, Status::DEAD)
    };

    Controller c(5, 5);
    auto next_cell = c.nextGenerations(cell);

    EXPECT_EQ(next_cell, corr_cell);
}


TEST(Controller, finalTest_Any_live_cell_with_two_or_three_live_neighbours_lives  ) {

    std::vector<Cell> cell = {
            Cell(0, 0, Status::DEAD), Cell(1, 0, Status::DEAD), Cell(2, 0, Status::DEAD), Cell(3, 0, Status::DEAD),
            Cell(0, 1, Status::DEAD), Cell(1, 1, Status::LIVE), Cell(2, 1, Status::LIVE), Cell(3, 1, Status::DEAD),
            Cell(0, 2, Status::DEAD), Cell(1, 2, Status::LIVE), Cell(2, 2, Status::DEAD), Cell(3, 2, Status::DEAD),
            Cell(0, 3, Status::DEAD), Cell(1, 3, Status::DEAD), Cell(2, 3, Status::DEAD), Cell(3, 3, Status::DEAD)
    };

    std::vector<Cell> corr_cell = {
            Cell(0, 0, Status::DEAD), Cell(1, 0, Status::DEAD), Cell(2, 0, Status::DEAD), Cell(3, 0, Status::DEAD),
            Cell(0, 1, Status::DEAD), Cell(1, 1, Status::LIVE), Cell(2, 1, Status::LIVE), Cell(3, 1, Status::DEAD),
            Cell(0, 2, Status::DEAD), Cell(1, 2, Status::LIVE), Cell(2, 2, Status::LIVE), Cell(3, 2, Status::DEAD),
            Cell(0, 3, Status::DEAD), Cell(1, 3, Status::DEAD), Cell(2, 3, Status::DEAD), Cell(3, 3, Status::DEAD)
    };

    Controller c(4, 4);
    auto next_cell = c.nextGenerations(cell);

    EXPECT_EQ(next_cell, corr_cell);
}