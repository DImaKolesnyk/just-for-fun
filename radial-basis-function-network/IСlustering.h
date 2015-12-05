//
// Created by dima on 18.10.15.
//

#ifndef RADIAL_BASIS_FUNCTION_NETWORK_IСLUSTERING_H
#define RADIAL_BASIS_FUNCTION_NETWORK_IСLUSTERING_H

#include "Data.h"
#include "mltMath.h"


class IClustering {
public:
    virtual Data toCluster(unsigned int k, const Data &d ) = 0;
};

#endif //RADIAL_BASIS_FUNCTION_NETWORK_IСLUSTERING_H
