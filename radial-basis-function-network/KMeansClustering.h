//
// Created by dima on 18.10.15.
//

#ifndef RADIAL_BASIS_FUNCTION_NETWORK_KMEANSCLUSTERING_H
#define RADIAL_BASIS_FUNCTION_NETWORK_KMEANSCLUSTERING_H

//#include "IСlustering.h"
#include "Data.h"
#include "mltMath.h"


template <typename DataType, unsigned int dimension>
class KMeansClustering {
public:
    virtual Data<DataType, dimension> toCluster(unsigned int k, const Data<DataType, dimension> &d );
    unsigned int clusteringOnePoint(unsigned int k, const DataPoint<DataType, dimension> &x, const Data<DataType, dimension> &mu);
};

#include "KMeansClustering.hxx"

#endif //RADIAL_BASIS_FUNCTION_NETWORK_KMEANSCLUSTERING_H
