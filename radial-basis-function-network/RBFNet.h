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
    std::vector<Net*> outputNeurons;
    std::vector<std::pair<Point, double>> hiddenLayerCoefs;

public:
    RBFNet() {}
    RBFNet(unsigned int h, unsigned int o);
    void setWeight(std::vector<std::pair<Point, double>> h, std::vector<Net*> n);
    double classify(const Point &a) const override;
};

#endif //RADIAL_BASIS_FUNCTION_NETWORK_RBFNET_H
