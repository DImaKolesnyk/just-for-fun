//
// Created by dima on 06.12.15.
//

#ifndef RADIAL_BASIS_FUNCTION_NETWORK_NEURONBUILDER_HPP
#define RADIAL_BASIS_FUNCTION_NETWORK_NEURONBUILDER_HPP

#include "NetBuilder.hpp"
#include "Neuron.h"

class NeuronBuilder : public NetBuilder{
private:
    unsigned int output;
    Net* net;
public:
    NeuronBuilder(unsigned int output);
    void learn(const Data &d);
    Net * get() const ;
};


#endif //RADIAL_BASIS_FUNCTION_NETWORK_NEURONBUILDER_HPP
