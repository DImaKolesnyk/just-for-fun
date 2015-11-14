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
    DataPoint<DataType, dimension> currPoint;

    while (F >> a) {

        i += 1;
        if( i%(dimension+1) == 0) {
            currPoint = DataPoint<DataType, dimension>(buff);
            buff.clear();
            currPoint.setClass(a);
            data.push_back( currPoint );
        } else {
            buff.push_back(a);
        }
    }
    return Data<DataType, dimension>(data);
}
