//
// Created by dima on 18.10.15.
//
#include "Point.h"

Point::Point(const std::vector<double> &p)
        : point(p), reallClass(-1){
    dimension = p.size();
    if (p.size() != dimension) {
        throw WrongPointSizeException();
    }
}

double Point::operator[](std::size_t idx) const {
    return point[idx];
}


void Point::setClass(int c) {
    reallClass = c;
}


Point Point::operator-( const Point &r_point ) const {

    std::vector<double> n_point;
    for (int i = 0; i < dimension; ++i) {
        n_point.push_back( point[i] - r_point[i] );
    }

    return Point(n_point);
}

std::ostream& operator<<(std::ostream& os, const Point& p)
{

        for (int i = 0; i < p.dim(); ++i) {
            os << std::fixed << std::setprecision(1);
            os << p[i] << " | ";
        }
        os << "Class: " << p.getClass() << " | ";
        os << "dimension: " << p.dim();

    return os;
}
