//
// Created by dima on 14.09.15.
//

#include "Parser.h"

std::vector < std::vector <double> > Parser::getData() {

    std::ifstream F(file);
    double a;
    std::vector <double > buff;
    int i = 0;
    std::vector < std::vector <double> > data;

    while (!F.eof())
    {
        F>>a;
        buff.push_back(a);
        i+=1;

        if ( i%3 == 0 ) {
            data.push_back(buff);
            buff.clear();
        }
    }

    return data;
}