//
// Created by dima on 04.12.15.
//

#ifndef RADIAL_BASIS_FUNCTION_NETWORK_NETBUILDER_HPP
#define RADIAL_BASIS_FUNCTION_NETWORK_NETBUILDER_HPP

#include "Net.hpp"

class NetBuilder {
public:
    virtual void learn(const NetBuilder &builder, const Data &d);
    virtual Net * get();
    virtual ~NetBuilder();
};

#endif //RADIAL_BASIS_FUNCTION_NETWORK_NETBUILDER_HPP
