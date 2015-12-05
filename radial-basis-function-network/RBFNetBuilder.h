//
// Created by dima on 19.10.15.
//

#ifndef RADIAL_BASIS_FUNCTION_NETWORK_RBFNETCREATOR_H
#define RADIAL_BASIS_FUNCTION_NETWORK_RBFNETCREATOR_H

#include "Data.h"
#include "RBFNet.h"
#include "KMeansClustering.h"
#include "NetBuilder.hpp"

class RBFNetBuilder : public NetBuilder {
private:
    unsigned int hidden;
    unsigned int output;
    RBFNet net;

    void learnHidenLayer(const Data &d);
    void learnOutputLayer(const Data &d);
    std::vector<std::pair< Point, double>> coeffs;
public:

    RBFNetBuilder(unsigned int h, unsigned int o);
    void learn(const RBFNetBuilder &buildr, const Data &d );
    RBFNet * get();

};

#endif //RADIAL_BASIS_FUNCTION_NETWORK_RBFNETCREATOR_H
