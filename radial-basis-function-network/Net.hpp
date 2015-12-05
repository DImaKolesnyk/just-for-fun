//
// Created by dima on 04.12.15.
//

#ifndef RADIAL_BASIS_FUNCTION_NETWORK_NET_HPP
#define RADIAL_BASIS_FUNCTION_NETWORK_NET_HPP

#include "Data.h"

class Net
{
public:
    virtual int classify(const Point &a) = 0;
};

#endif //RADIAL_BASIS_FUNCTION_NETWORK_NET_HPP
