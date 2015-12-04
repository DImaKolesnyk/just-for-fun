//
// Created by dima on 19.10.15.
//

#ifndef RADIAL_BASIS_FUNCTION_NETWORK_RBFNETCREATOR_H
#define RADIAL_BASIS_FUNCTION_NETWORK_RBFNETCREATOR_H

#include "Data.h"
#include "RBFNet.h"
#include "KMeansClustering.h"


template<typename DataType, unsigned int dimension>
class RBFNetCreator {
private:
    unsigned int hidden;
    unsigned int output;
    RBFNet<DataType,dimension> net;

    void learnHidenLayer(const Data<DataType, dimension> &d);
    void learnOutputLayer(const Data<DataType, dimension> &d);
    std::vector<std::pair<DataPoint<DataType,dimension>, double>> coeffs;
public:
    //typedef RBFNet<DataType,dimension> Net;

    RBFNetCreator(unsigned int h, unsigned int o);
    void learn(const Data<DataType, dimension> &d );
    RBFNet<DataType,dimension> get();

};

#include "RBFNetCreator.hxx"

#endif //RADIAL_BASIS_FUNCTION_NETWORK_RBFNETCREATOR_H
