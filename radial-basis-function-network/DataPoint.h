//
// Created by dima on 18.10.15.
//

#ifndef RADIAL_BASIS_FUNCTION_NETWORK_DATAPOINT_H
#define RADIAL_BASIS_FUNCTION_NETWORK_DATAPOINT_H

#include <vector>

namespace mlt {

    class WrongPointSizeException {};

    template<typename DataType, unsigned int dimension>
    class DataPoint {
    private:
        std::vector<DataType> point;
    public:
        DataPoint<DataType, dimension>(const std::vector<DataType> &p);
        DataType operator[](std::size_t idx) const;
    };

}
#include "DataPoint.hxx"

#endif //RADIAL_BASIS_FUNCTION_NETWORK_DATAPOINT_H
