//
// Created by dima on 18.10.15.
//

#ifndef RADIAL_BASIS_FUNCTION_NETWORK_DATAPOINT_H
#define RADIAL_BASIS_FUNCTION_NETWORK_DATAPOINT_H

#include <iostream>
#include <vector>
#include <iomanip>

    class WrongPointSizeException {};

    class Point {
    private:
        unsigned int dimension;
        std::vector<double> point;
        int reallClass;
    public:
        Point() {}
        Point(unsigned int d) : dimension(d) { point.reserve(dimension); }
        Point(const std::vector<double> &p);
        double operator[](std::size_t idx) const;
        friend std::ostream& operator<<(std::ostream& os, const Point& obj);
        Point operator-(const Point &r_point) const;
        void setClass(int c);
        int getClass() const { return reallClass; }
        unsigned int dim() const { return point.size(); }
        void setDim(unsigned int dim) { dimension = dim;  }
    };


#endif //RADIAL_BASIS_FUNCTION_NETWORK_DATAPOINT_H
