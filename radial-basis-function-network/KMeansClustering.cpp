//
// Created by dima on 18.10.15.
//
#include "KMeansClustering.h"

unsigned int KMeansClustering::clusteringOnePoint(unsigned int k, const Point &x, const Data &mu) {

    double d = distance(x, mu[0]);
    unsigned int PointKlass = 0;

    for (int i = 1; i < k; ++i) {

        if (distance(x, mu[i]) - d < 0.0001) {
//        if (distance(x, mu[i]) < d) {
            d = distance(x, mu[i]);
            PointKlass = i;
        }
    }
    return PointKlass;
}


Data KMeansClustering::toCluster(unsigned int k, const Data &data) {

    classSet.reserve(k);
    std::vector<Point> centers;
    centers.reserve(k);
    srand(time(NULL));
    for (int i = 0; i < k; ++i) { centers.push_back(data[
                                                            ( rand() % (int)(data.size() + 1))
                                                    ]); }

    bool changeMu = true;
    std::vector < Data > clSet(k);
    unsigned int classNum;
    while (changeMu) {
        changeMu = false;
        for (int i = 0; i < data.size(); ++i) {
            classNum = clusteringOnePoint(k,data[i], Data(centers));
            clSet[ classNum ].addPoint(data[i]);
        }
        for (int j = 0; j < k; ++j) { // j e K
            if ( distance(centers[j], average(clSet[j])) > 0.002) { changeMu = true; }
            centers[j] = average(clSet[j]);
        }

        if (changeMu == false) {
            classSet = clSet;
        }
        clSet = std::vector < Data >(k);
    }
    return centers;
}


std::vector< Data > KMeansClustering::getClassSet() {
    return classSet;
}