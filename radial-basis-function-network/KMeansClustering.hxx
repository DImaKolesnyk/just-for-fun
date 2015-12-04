//
// Created by dima on 18.10.15.
//

template <typename DataType, unsigned int dimension>
unsigned int KMeansClustering<DataType, dimension>::clusteringOnePoint(unsigned int k, const DataPoint<DataType, dimension> &x,
                                                  const Data<DataType, dimension> &mu) {

    double d = distance(x, mu[0]);
    unsigned int PointKlass = 0;

    for (int i = 1; i < k; ++i) {
        if (distance(x, mu[i]) < d) {
            d = distance(x, mu[i]);
            PointKlass = i;
        }
    }
    return PointKlass;
}

template <typename DataType, unsigned int dimension>
Data<DataType, dimension> KMeansClustering<DataType, dimension>::toCluster(unsigned int k, const Data<DataType, dimension> &data) {

    classSet.reserve(k);
    std::vector<DataPoint<DataType, dimension>> centers;
    centers.reserve(k);
    for (int i = 0; i < k; ++i) { centers.push_back(data[(rand() % (int)(data.size() + 1))]); }

    bool changeMu = true;
    std::vector < Data<DataType, dimension> > clSet(k);
    unsigned int classNum;
    while (changeMu) {
        changeMu = false;
        for (int i = 0; i < data.size(); ++i) {
            classNum = clusteringOnePoint(k,data[i], Data<DataType, dimension>(centers));
            clSet[ classNum ].addPoint(data[i]);
        }
        for (int j = 0; j < k; ++j) { // j e K
            if ( distance(centers[j], average(clSet[j])) > 0.2) { changeMu = true; }
            centers[j] = average(clSet[j]);
            classSet[j] = clSet[j];
        }
        clSet = std::vector < Data<DataType, dimension> >(k);
    }
    return centers;
}

template <typename DataType, unsigned int dimension>
std::vector< Data<DataType, dimension> > KMeansClustering<DataType, dimension>::getClassSet() {
    return classSet;
}