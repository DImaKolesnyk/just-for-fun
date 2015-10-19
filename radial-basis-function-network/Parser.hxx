//
// Created by dima on 18.10.15.
//

#include "Data.h"

using namespace mlt;

template <typename DataType, unsigned int dimension>
Parser<DataType, dimension>::Parser(const std::string &fn)
        : fileName(fn)
{
}


template <typename DataType, unsigned int dimension>
Data<DataType, dimension> Parser<DataType, dimension>::get() {

    std::ifstream F(fileName);
    DataType a;
    std::vector<DataType> buff;
    int i = 0;
    std::vector<DataPoint<DataType, dimension>> data;

    while (!F.eof()) {

        F >> a;
        buff.push_back(a);
        i += 1;

        if ( i%dimension == 0 ) {

            data.push_back(buff);
            buff.clear();
        }
    }
    return Data<DataType, dimension>(data);
}
