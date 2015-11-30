//
// Created by dima on 29.11.15.
//

#ifndef GAME_OF_LIFE_CONTROLLER_HPP
#define GAME_OF_LIFE_CONTROLLER_HPP

#include <vector>
#include "Cell.hpp"
#include <stdlib.h>

class Controller {
private:
    unsigned int n;
    unsigned int m;
public:
    Controller() {}
    Controller(unsigned int n_, unsigned int m_) : m(m_), n(n_) {}
    bool NearbyToEdges(const Cell &c) const;
    bool neighbour(Cell a, Cell b) const;
    int numOfLiveNeighboud(const Cell &c, const std::vector<Cell> &cels ) const;
    bool survive(const Cell &c, const std::vector<Cell> &cels ) const;
    bool revives(const Cell &c, const std::vector<Cell> &cels ) const;
    std::vector<Cell> nextGenerations(const std::vector<Cell> &cels) const;

};


#endif //GAME_OF_LIFE_CONTROLLER_HPP
