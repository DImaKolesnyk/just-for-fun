//
// Created by dima on 14.09.15.
//

#ifndef PERCEPTRON_PARSER_H
#define PERCEPTRON_PARSER_H

#include <vector>
#include <fstream>

class Parser {
private:
    const char *file;
public:
    Parser(const char *f) : file(f) { };
    std::vector < std::vector <double> > getData();

};


#endif //PERCEPTRON_PARSER_H
