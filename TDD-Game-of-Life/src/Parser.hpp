//
// Created by dima on 29.11.15.
//

#ifndef GAME_OF_LIFE_PARSER_HPP
#define GAME_OF_LIFE_PARSER_HPP

#include <istream>
#include "Cell.hpp"
#include <vector>


class Parser {
    std::istream &input;
public:
    Parser(std::istream &i);
    std::vector<Cell> getGrid(int m, int n);

};


#endif //GAME_OF_LIFE_PARSER_HPP
