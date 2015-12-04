//
// Created by dima on 16.11.15.
//

#ifndef RADIAL_BASIS_FUNCTION_NETWORK_NEURON_H
#define RADIAL_BASIS_FUNCTION_NETWORK_NEURON_H

#include <vector>
#include "mltMath.h"

class Neuron {
private:
    unsigned int input;
    std::vector < double > weight;
public:
    Neuron(unsigned int inputSize);
    void learn(std::vector<double> phi, int realClass);
};


#endif //RADIAL_BASIS_FUNCTION_NETWORK_NEURON_H
