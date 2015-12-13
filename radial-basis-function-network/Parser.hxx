//
// Created by dima on 18.10.15.
//


template <typename DataType, unsigned int dimension>
Parser<DataType, dimension>::Parser(const std::string &fn)
        : fileName(fn)
{
}


template <typename DataType, unsigned int dimension>
Data Parser<DataType, dimension>::get() {

    std::ifstream F(fileName);
    DataType a;
    std::vector<DataType> buff;
    int i = 0;
    std::vector<Point> data;
    Point currPoint;

    while (F >> a) {

        i += 1;
        if( i%(dimension+1) == 0) {
            currPoint = Point(buff);
            currPoint.setDim(dimension);
            buff.clear();
            currPoint.setClass(a);
            data.push_back( currPoint );
        } else {
            buff.push_back(a);
        }
    }
    return Data(data);
}
