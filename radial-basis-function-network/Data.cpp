//
// Created by dima on 18.10.15.
//
#include "Data.h"

Data::Data(const std::vector<Point> &d)
        : data(d) {
}


Point Data::operator[](std::size_t idx) const{
    return data[idx];
}


void Data::addPoint(const Point &p) {

    data.push_back(p);
}



unsigned int Data::size() const {
    return data.size();
}

std::ostream& operator<<(std::ostream& os, const Data& d)
{
    for(int j = 0; j < d.size(); ++j) {
        os << d[j] << std::endl;
    }
    return os;
}

Data Data::part(float first, float last) {
    std::vector<Point>::const_iterator f_it = data.begin() + data.size()*first;
    std::vector<Point>::const_iterator l_it = data.begin() + data.size()*last;
    return Data( std::vector<Point>( f_it, l_it ) );
}