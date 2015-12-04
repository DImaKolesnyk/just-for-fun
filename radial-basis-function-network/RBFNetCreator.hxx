//
// Created by dima on 19.10.15.
//


#include "KMeansClustering.h"

template<typename DataType, unsigned int dimension>
RBFNetCreator<DataType, dimension>::RBFNetCreator(unsigned int h, unsigned int o)
        : hidden(h),
          output(o)
{
    net = RBFNet<DataType, dimension>(h,o);
}

template<typename DataType, unsigned int dimension>
void RBFNetCreator<DataType, dimension>::learn(const Data<DataType, dimension> &d) {

    learnHidenLayer(d);
    //learnOutputLayer(d);


}

template<typename DataType, unsigned int dimension>
void RBFNetCreator<DataType, dimension>::learnHidenLayer(const Data<DataType, dimension> &d) {

    KMeansClustering<double,dimension> kMClust;
    mlt::Data<DataType, dimension> centr = kMClust.toCluster(hidden,d);
//    std::vector< Data<DataType, dimension> > allClassSet =  kMClust.getClassSet();

//    for (int i = 0; i < hidden; ++i) {
//        coeffs.push_back( std::make_pair(centr[i], clacSigma(centr[i], allClassSet[i])));
//    }
//
//    net.setHiddenCoefs(coeffs);
}

template<typename DataType, unsigned int dimension>
void RBFNetCreator<DataType, dimension>::learnOutputLayer(const Data<DataType, dimension> &d) {

    std::vector<double> allPhi(hidden);

    for (int k = 0; k < d.size(); ++k) {
        for (int i = 0; i < output; ++i) {
            for (int j = 0; j < hidden; ++j) {
                allPhi[j] = clacPhi(coeffs[k].first, d[k], coeffs[k].second);
            }
            (*(net.getOutputNeurons()))[i].learn(allPhi, (int) (i == d[k].getClass()));

        }
    }
}

template<typename DataType, unsigned int dimension>
RBFNet<DataType, dimension> RBFNetCreator<DataType, dimension>::get() {
    return net;
}