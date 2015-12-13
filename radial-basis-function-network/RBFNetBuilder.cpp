//
// Created by dima on 19.10.15.
//

#include "RBFNetBuilder.h"
#include "KMeansClustering.h"


RBFNetBuilder::RBFNetBuilder(unsigned int h, unsigned int o)
        : hidden(h),
          output(o),
          net(new RBFNet)
{

}


void RBFNetBuilder::learn(const Data &d) {

    learnHidenLayer(d);
    learnOutputLayer(d);

    net->setWeight(coeffs, neuron_all);
}


void RBFNetBuilder::learnHidenLayer(const Data &d) {

    KMeansClustering kMClust;
    Data centr = kMClust.toCluster(hidden, d);
    std::vector< Data > allClassSet =  kMClust.getClassSet();

    for (int i = 0; i < hidden; ++i) {
        coeffs.push_back( std::make_pair(centr[i], clacSigma(centr[i], allClassSet[i])));
    }
}


void RBFNetBuilder::learnOutputLayer(const Data &d) {

    std::vector<Net*> neurons;
    std::vector<double> allPhi(hidden+1);

    std::vector<Point> phi;
    std::vector<double> newPoint;
    Data dataPhi;
    Point buff;

    for (int i = 0; i < d.size(); ++i) {
        newPoint.push_back(1);
        for (int j = 0; j < hidden; ++j) {
            newPoint.push_back( clacPhi(coeffs[j].first, d[i], coeffs[j].second));
        }
        buff = Point(newPoint);
        buff.setDim(hidden+1);
        buff.setClass(d[i].getClass());
        phi.push_back(buff);
        newPoint.clear();
    }




    for (int k = 0; k < output; ++k) {

        dataPhi = Data(phi);

        for (int i = 0; i < dataPhi.size(); ++i) {

            if ( dataPhi[i].getClass() == k ) {
                dataPhi[i].setClass(1);
            } else {
                dataPhi[i].setClass(0);
            }
        }
        NeuronBuilder builder(1);
        Net* neuron = new Net;
        neuron = Creator().learn( builder, dataPhi );
        neurons.push_back(neuron);
    }

    neuron_all = neurons;
}


Net* RBFNetBuilder::get() const {
    return net;
}