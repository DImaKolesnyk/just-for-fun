//
// Created by dima on 04.12.15.
//

#ifndef RADIAL_BASIS_FUNCTION_NETWORK_CREATOR_HPP
#define RADIAL_BASIS_FUNCTION_NETWORK_CREATOR_HPP

#include "Net.hpp"
#include "NetBuilder.hpp"

class Creator {
public:
    Creator();
    Net * learn(NetBuilder builder, const Data &data );
};

#endif //RADIAL_BASIS_FUNCTION_NETWORK_CREATOR_HPP
