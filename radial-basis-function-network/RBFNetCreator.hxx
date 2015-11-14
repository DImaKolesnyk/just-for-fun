//
// Created by dima on 19.10.15.
//

#include "KMeansClustering.h"

template<typename DataType, unsigned int dimension>
RBFNetCreator<DataType, dimension>::RBFNetCreator(unsigned int h, unsigned int o)
        : hidden(h),
          output(o)
{

}

template<typename DataType, unsigned int dimension>
void RBFNetCreator<DataType, dimension>::learn(const Data<DataType, dimension> &d) {

}