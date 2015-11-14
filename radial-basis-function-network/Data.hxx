//
// Created by dima on 18.10.15.
//

using namespace mlt;

template <typename DataType, unsigned int dimension>
Data<DataType, dimension>::Data(const std::vector<DataPoint<DataType, dimension> > &d)
        : data(d) {

}

template <typename DataType, unsigned int dimension>
DataPoint<DataType, dimension> Data<DataType, dimension>::operator[](std::size_t idx) const{
    return data[idx];
}

template <typename DataType, unsigned int dimension>
void Data<DataType, dimension>::addPoint(const DataPoint<DataType, dimension> &p) {

    data.push_back(p);
}


template <typename DataType, unsigned int dimension>
unsigned int Data<DataType, dimension>::size() const {
    return data.size();
};

template <typename DataType, unsigned int dimension>
std::ostream& operator<<(std::ostream& os, const Data<DataType, dimension>& d)
{
    for(int j = 0; j < d.size(); ++j) {
        for (int i = 0; i < dimension; ++i) {
            os << d[j][i] << ", ";
        }
        os << "Class: " << d[j].getClass();
        os << std::endl;
    }
    return os;
}
