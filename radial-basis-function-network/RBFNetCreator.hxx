//
// Created by dima on 19.10.15.
//

#include "KMeansClustering.h"

template<typename DataType, unsigned int dimension, unsigned int hidden>
RBFNetCreator<DataType, dimension>::RBFNetCreator( unsigned int o)
: output(o) {

}

template <typename DataType, unsigned int dimension, unsigned int hidden>
RBFNet RBFNetCreator<DataType, dimension, hidden>::learn( const Data <DataType, dimension> &d) {

}

template <typename DataType, unsigned int dimension, unsigned int hidden>
Data<DataType, hidden> RBFNetCreator<DataType, dimension, hidden>::learnHiddenLayer(const Data <DataType, dimension> &d) {

    KMeansClustering<DataType, dimension> kMeansClustering;
    Data<DataType, dimension> center = kMeansClustering.toCluster(hidden, d);

    std::vector<DataType> onep;
    onep.reserve(hidden);

    for (int j = 0; j < d.size(); ++j) {
        for (int i = 0; i < dimension; ++i) {

        }
    }

}