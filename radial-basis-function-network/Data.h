//
// Created by dima on 18.10.15.
//

#ifndef RADIAL_BASIS_FUNCTION_NETWORK_DATA_H
#define RADIAL_BASIS_FUNCTION_NETWORK_DATA_H

#include <iostream>
#include "DataPoint.h"
#include "Parser.h"
#include "KMeansClustering.h"

namespace mlt {

    template <typename DataType, unsigned int dimension>
    class Data {
    private:
        std::vector <DataPoint<DataType, dimension> > data;
    public:
        typedef Parser<DataType, dimension> TParser;

        Data<DataType, dimension>(){};
        Data<DataType, dimension>(const std::vector <DataPoint<DataType, dimension> > &d);
        DataPoint<DataType, dimension> operator[](std::size_t idx) const;
        friend std::ostream& operator<<(std::ostream& os, const std::vector <DataPoint<DataType, dimension> >& obj);

        unsigned int size() const;
        void addPoint(const  DataPoint<DataType, dimension> &);
    };

}

#include "Data.hxx"

#endif //RADIAL_BASIS_FUNCTION_NETWORK_DATA_H

