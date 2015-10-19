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
void Data<DataType, dimension>::consolePrint() {

    for(auto &x: data) {
        for (int i = 0; i < dimension; ++i) {
            std::cout << x[i] << ", ";
        }
        std::cout << std::endl;
    }
}

template <typename DataType, unsigned int dimension>
unsigned int Data<DataType, dimension>::size() const {
    return data.size();
};