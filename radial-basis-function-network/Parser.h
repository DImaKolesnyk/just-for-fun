//
// Created by dima on 18.10.15.
//

#ifndef RADIAL_BASIS_FUNCTION_NETWORK_PARSER_H
#define RADIAL_BASIS_FUNCTION_NETWORK_PARSER_H

#include <string>
#include <fstream>


namespace mlt {
    template <typename DataType, unsigned int dimension>
    class Data;

    template<typename DataType, unsigned int dimension>
    class Parser {
    private:
        std::string fileName;
    public:
        Parser(const std::string &fn);
        Data<DataType, dimension> get();
    };

}

#include "Parser.hxx"

#endif //RADIAL_BASIS_FUNCTION_NETWORK_PARSER_H
