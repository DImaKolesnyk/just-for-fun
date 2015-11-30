//
// Created by dima on 28.11.15.
//

#ifndef GAME_OF_LIFE_VIEW_HPP
#define GAME_OF_LIFE_VIEW_HPP


#include <vector>
#include <ostream>
#include "Cell.hpp"

class View {
private:
    std::ostream &output;
    unsigned int m_;
    unsigned int n_;
public:
    View(std::ostream &o, unsigned int m, unsigned int n) : output(o), m_(m), n_(n)  {}
    void print(const std::vector<Cell> &s) const;

};


#endif //GAME_OF_LIFE_VIEW_HPP
