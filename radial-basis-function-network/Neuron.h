//
// Created by dima on 16.11.15.
//

#ifndef RADIAL_BASIS_FUNCTION_NETWORK_NEURON_H
#define RADIAL_BASIS_FUNCTION_NETWORK_NEURON_H

#include <vector>
#include "mltMath.h"
#include "Net.hpp"

class Neuron : public Net{
private:
    unsigned int input;
    std::vector < double > weight;
public:
    Neuron() {}
    Neuron(unsigned int inputSize);
//    void learn(std::vector<double> phi, int realClass);
    int getWeightSumm(const Point &p) const;
};


#endif //RADIAL_BASIS_FUNCTION_NETWORK_NEURON_H
