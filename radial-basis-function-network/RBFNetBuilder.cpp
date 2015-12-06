//
// Created by dima on 19.10.15.
//

#include "RBFNetBuilder.h"
#include "KMeansClustering.h"


RBFNetBuilder::RBFNetBuilder(unsigned int h, unsigned int o)
        : hidden(h),
          output(o)
{
    net = new RBFNet(h,o);
}


void RBFNetBuilder::learn(const Data &d) {

    learnHidenLayer(d);
    learnOutputLayer(d);

}


void RBFNetBuilder::learnHidenLayer(const Data &d) {

    KMeansClustering kMClust;
    Data centr = kMClust.toCluster(hidden, d);
    std::vector< Data > allClassSet =  kMClust.getClassSet();

    for (int i = 0; i < hidden; ++i) {
        coeffs.push_back( std::make_pair(centr[i], clacSigma(centr[i], allClassSet[i])));
    }
    net->setHiddenCoefs(coeffs);
}


void RBFNetBuilder::learnOutputLayer(const Data &d) {

    std::vector<double> allPhi(hidden);

//    for (int k = 0; k < d.size(); ++k) {
//        for (int i = 0; i < output; ++i) {
//            for (int j = 0; j < hidden; ++j) {
//                allPhi[j] = clacPhi(coeffs[k].first, d[k], coeffs[k].second);
//            }
////            (*(net.getOutputNeurons()))[i].learn(allPhi, (int) (i == d[k].getClass()));
//
//
//        }
//    }

    std::vector<Point> phi(d.size());
    std::vector<double> newPoint(hidden);

    for (int i = 0; i < d.size(); ++i) {
        for (int j = 0; j < hidden; ++j) {
            newPoint[j] = clacPhi(coeffs[j].first, d[i], coeffs[j].second);
        }
        phi.push_back(Point(newPoint));
        phi[i].setClass(d[i].getClass());
        newPoint.clear();
    }

    for (int k = 0; k < output; ++k) {
        Net* neuron = Creator().learn( NeuronBuilder(1), phi );
        net->setNeuron(neuron);
    }

}


Net* RBFNetBuilder::get() {
    return net;
}