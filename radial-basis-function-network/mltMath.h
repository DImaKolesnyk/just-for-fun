//
// Created by dima on 18.10.15.
//

#ifndef RADIAL_BASIS_FUNCTION_NETWORK_MLTMATH_H
#define RADIAL_BASIS_FUNCTION_NETWORK_MLTMATH_H

#include "Data.h"
#include <cmath>

template <typename DataType, unsigned int dimension>
double distance(const DataPoint<DataType, dimension> &a, const DataPoint<DataType, dimension> &b) {

    double dist = 0.0;
    for (int i = 0; i < dimension; ++i) {
        dist += std::pow( (b[i] - a[i]), 2);
    }

    return sqrt(dist);
}

template <typename DataType, unsigned int dimension>
DataPoint<DataType, dimension> average( const Data<DataType, dimension> &a) {

    std::vector<DataType> av;
    double sum = 0.0;
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < a.size(); ++j) {
            sum+= a[j][i];
        }
        av.push_back(sum/a.size());
        sum = 0;
    }
    return DataPoint<DataType, dimension>(av);
}

#endif //RADIAL_BASIS_FUNCTION_NETWORK_MLTMATH_H
