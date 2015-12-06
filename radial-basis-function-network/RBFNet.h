//
// Created by dima on 19.10.15.
//

#ifndef RADIAL_BASIS_FUNCTION_NETWORK_RBFNET_H
#define RADIAL_BASIS_FUNCTION_NETWORK_RBFNET_H

#include "NeuronBuilder.hpp"
#include "Net.hpp"
#include "Creator.hpp"


class RBFNet : public Net {
private:
    std::vector<Neuron*> outputNeurons;
    std::vector<std::pair<Point, double>> hiddenLayerCoefs;

public:
    RBFNet() {}
    RBFNet(unsigned int h, unsigned int o);
    void setHiddenCoefs(std::vector<std::pair<Point, double>> h);
    void setNeuron(Neuron* n);
    int classify(const Point &a);
    std::vector<Neuron*>* getOutputNeurons() {
        return &outputNeurons;
    }
};

#endif //RADIAL_BASIS_FUNCTION_NETWORK_RBFNET_H
