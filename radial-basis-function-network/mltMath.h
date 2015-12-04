//
// Created by dima on 18.10.15.
//

#ifndef RADIAL_BASIS_FUNCTION_NETWORK_MLTMATH_H
#define RADIAL_BASIS_FUNCTION_NETWORK_MLTMATH_H

#include "Data.h"
#include <cmath>

class WeightAndInputHaveWrongSizeInWeightSum {};

template <typename DataType, unsigned int dimension>
double distance(const DataPoint<DataType, dimension> &a, const DataPoint<DataType, dimension> &b) {

    double dist = 0.0;
    for (int i = 0; i < dimension; ++i) {
        dist += std::pow( (b[i] - a[i]), 2);
    }

    return sqrt(dist);
}

double dist(const std::vector<double> &a, const std::vector<double> &b);

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

template <typename DataType, unsigned int dimension>
double norm(const DataPoint<DataType, dimension> &a) {

    double b = 0.0;
    for (int i = 0; i < dimension; ++i) {
        b += pow(a[i], 2);
    }

    return sqrt(b);
}

template <typename DataType, unsigned int dimension>
double clacSigma(const DataPoint<DataType, dimension> &mu,
                 const Data<DataType, dimension> &classSet) {

    double sigma = 0.0;

    for (int i = 0; i < classSet.size(); ++i) {
        sigma += norm( classSet[i] - mu );
    }

    return (1/classSet.size())*sigma;
}

template <typename DataType, unsigned int dimension>
double clacPhi(const DataPoint<DataType, dimension> &mu,
               const DataPoint<DataType, dimension> &x,
               double sigma) {

    double phi = 0.0;
    phi = exp((1/(2*pow( sigma,2)))*pow( distance(x, mu),2));
    return phi;
}

double weightSum(const std::vector<double> &weight, const std::vector<double> &input);

#endif //RADIAL_BASIS_FUNCTION_NETWORK_MLTMATH_H
