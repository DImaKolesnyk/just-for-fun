//
// Created by dima on 19.10.15.
//

#ifndef RADIAL_BASIS_FUNCTION_NETWORK_RBFNET_H
#define RADIAL_BASIS_FUNCTION_NETWORK_RBFNET_H

#include "Neuron.h"

template<typename DataType, unsigned int dimension>
class RBFNet {
private:
    std::vector<Neuron> outputNeurons;
    std::vector<std::pair<DataPoint<DataType,dimension>, double>> hiddenLayerCoefs;

public:
    RBFNet() {}
    RBFNet(unsigned int h, unsigned int o);
    void setHiddenCoefs(std::vector<std::pair<DataPoint<DataType,dimension>, double>> h);
    int classify(const DataPoint<DataType, dimension> &a);
    std::vector<Neuron>* getOutputNeurons() {
        return &outputNeurons;
    }
};

#include "RBFNet.hxx"

#endif //RADIAL_BASIS_FUNCTION_NETWORK_RBFNET_H
