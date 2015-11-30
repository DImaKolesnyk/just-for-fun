//
// Created by dima on 29.11.15.
//

#include "Parser.hpp"


Parser::Parser(std::istream &i) : input(i) {

}

std::vector<Cell> Parser::getGrid(int m, int n) {

    char ch_buff;
    std::vector<Cell > grid;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {

            input >> ch_buff;
            if ( ch_buff == '.' ) {
                grid.push_back( Cell(j, i, Status::DEAD) );
            } else {
                grid.push_back( Cell(j, i, Status::LIVE) );
            }
        }
    }

    return grid;
}