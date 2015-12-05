//
// Created by dima on 18.10.15.
//

#ifndef RADIAL_BASIS_FUNCTION_NETWORK_KMEANSCLUSTERING_H
#define RADIAL_BASIS_FUNCTION_NETWORK_KMEANSCLUSTERING_H

#include "IСlustering.h"
#include "Data.h"
#include "mltMath.h"
#include <stdlib.h>  /* srand, rand */
#include <time.h>



class KMeansClustering : public IClustering{
private:
    std::vector < Data > classSet;
public:
    Data toCluster(unsigned int k, const Data &d );
    unsigned int clusteringOnePoint(unsigned int k, const Point &x, const Data &mu);
    std::vector < Data > getClassSet();
};


#endif //RADIAL_BASIS_FUNCTION_NETWORK_KMEANSCLUSTERING_H
