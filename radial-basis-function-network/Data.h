//
// Created by dima on 18.10.15.
//

#ifndef RADIAL_BASIS_FUNCTION_NETWORK_DATA_H
#define RADIAL_BASIS_FUNCTION_NETWORK_DATA_H

#include "Point.h"

    class Data {
    private:
        std::vector<Point> data;
    public:

        Data(){};
        Data(const std::vector<Point> &d);
        Point operator[](std::size_t idx) const;
        friend std::ostream& operator<<(std::ostream& os, const Data& obj);

        Data part(float first, float last);
        unsigned int size() const;
        void addPoint(const Point &);
    };

#endif //RADIAL_BASIS_FUNCTION_NETWORK_DATA_H

