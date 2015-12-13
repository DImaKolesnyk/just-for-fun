//
// Created by dima on 04.12.15.
//

#ifndef RADIAL_BASIS_FUNCTION_NETWORK_NET_HPP
#define RADIAL_BASIS_FUNCTION_NETWORK_NET_HPP

#include "Data.h"

class Net
{
public:
    virtual void setWeight() {};
    virtual void setWeight(const std::vector < double > &weight) {}
    virtual double classify(const Point &a) const {};
    virtual void setWeight(std::vector<std::pair<Point, double>> h, std::vector<Net*> n) {}
};

#endif //RADIAL_BASIS_FUNCTION_NETWORK_NET_HPP
