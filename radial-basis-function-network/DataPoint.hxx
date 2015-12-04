//
// Created by dima on 18.10.15.
//

using namespace mlt;

template <typename DataType, unsigned int dimension>
DataPoint<DataType, dimension>::DataPoint(const std::vector<DataType> &p)
        : point(p), reallClass(-1){

    if (p.size() != dimension) {
        throw WrongPointSizeException();
    }
}

template <typename DataType, unsigned int dimension>
DataType DataPoint<DataType, dimension>::operator[](std::size_t idx) const {
    return point[idx];
}

template <typename DataType, unsigned int dimension>
void DataPoint<DataType, dimension>::setClass(int c) {
    reallClass = c;
}

template <typename DataType, unsigned int dimension>
DataPoint<DataType, dimension> DataPoint<DataType, dimension>::operator-(
        const mlt::DataPoint<DataType, dimension> &r_point) {

    std::vector<DataType> n_point;
    for (int i = 0; i < dimension; ++i) {
        n_point.push_back( point[i] - r_point[i] );
    }

    return DataPoint<DataType, dimension>(n_point);
}