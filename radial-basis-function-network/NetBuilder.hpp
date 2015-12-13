//
// Created by dima on 04.12.15.
//

#ifndef RADIAL_BASIS_FUNCTION_NETWORK_NETBUILDER_HPP
#define RADIAL_BASIS_FUNCTION_NETWORK_NETBUILDER_HPP

#include "Net.hpp"

class NetBuilder {
public:
    virtual void learn(const Data &d) = 0;
    virtual Net* get() const = 0;
    virtual ~NetBuilder() {};
};

#endif //RADIAL_BASIS_FUNCTION_NETWORK_NETBUILDER_HPP
