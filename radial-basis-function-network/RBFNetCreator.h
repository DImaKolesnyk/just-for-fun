//
// Created by dima on 19.10.15.
//

#ifndef RADIAL_BASIS_FUNCTION_NETWORK_RBFNETCREATOR_H
#define RADIAL_BASIS_FUNCTION_NETWORK_RBFNETCREATOR_H

#include "Data.h"
#include "RBFNet.h"
#include "KMeansClustering.h"

template<typename DataType, unsigned int dimension, unsigned int hidden>
class RBFNetCreator {
private:
    unsigned int output;
    Data<DataType, hidden> learnHiddenLayer(const Data <DataType, dimension> &d);
public:
    RBFNetCreator(unsigned int output);
    RBFNet learn(const Data<DataType, dimension>  &d);

};

#include "RBFNetCreator.hxx"

#endif //RADIAL_BASIS_FUNCTION_NETWORK_RBFNETCREATOR_H
