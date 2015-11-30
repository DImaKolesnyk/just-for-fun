//
// Created by dima on 29.11.15.
//

#include "Controller.hpp"
#include <iostream>

bool Controller::NearbyToEdges(const Cell &c) const {

    return (c.x() == 0 ||
            c.y() == 0 ||
            c.x() == n-1 ||
            c.y() == m-1);
}

bool Controller::neighbour(Cell a, Cell b) const {
    return abs(a.x() - b.x()) <= 1 &&
           abs(a.y() - b.y()) <= 1 &&
           !(a.x() == b.x() && a.y() == b.y());
}

int Controller::numOfLiveNeighboud(const Cell &c, const std::vector<Cell> &cels) const {

    int count = 0;
    for (int i = 0; i < cels.size(); ++i) {
        if( neighbour(c, cels[i]) && cels[i].status() == Status::LIVE) {
            ++count;
        }
    }

    return count;
}

bool Controller::survive(const Cell &c, const std::vector<Cell> &cels) const {

    return (numOfLiveNeighboud(c, cels) == 3 ||
             numOfLiveNeighboud(c, cels) == 2) &&
            !NearbyToEdges(c);
}

bool Controller::revives(const Cell &c, const std::vector<Cell> &cels) const {

    return c.status() == Status::DEAD &&
           numOfLiveNeighboud(c, cels) == 3 &&
           !NearbyToEdges(c);
}

std::vector<Cell> Controller::nextGenerations(const std::vector<Cell> &cels) const {

    std::vector<Cell> new_cels(cels);

    for (int i = 0; i < cels.size(); ++i) {

        if (revives(cels[i], cels )) {
            new_cels[i].setStatus(Status::LIVE);
        }
        if (!survive(cels[i], cels) || NearbyToEdges(cels[i])) {
                new_cels[i].setStatus(Status::DEAD);
        }

    }

    return new_cels;
}