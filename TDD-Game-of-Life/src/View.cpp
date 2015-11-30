//
// Created by dima on 28.11.15.
//

#include "View.hpp"
#include <iostream>


void View::print(const std::vector<Cell> &s) const {

    int count = 0;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < s.size(); ++j) {
            for (int k = 0; k < s.size(); ++k) {
                if ( s[i].x() == k && s[i].y() == j ) {
                    if(count%n_ == 0 && count != 0 ) output << std::endl;
                    output << (((int)(s[i]).status() == 0) ? "." : "*");
                    ++count;
                }
            }
        }
    }
}

