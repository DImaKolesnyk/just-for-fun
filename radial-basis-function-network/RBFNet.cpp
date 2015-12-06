//
// Created by dima on 19.10.15.
//
#include "RBFNet.h"

RBFNet::RBFNet(unsigned int h, unsigned int o){

    outputNeurons.reserve(o);
    hiddenLayerCoefs.reserve(h);
}


void RBFNet::setHiddenCoefs(std::vector<std::pair<Point, double>> hidden_coefs) {
    hiddenLayerCoefs = hidden_coefs;
}

void RBFNet::setNeuron( Neuron* n) {
    outputNeurons.push_back(n);
}


int RBFNet::classify(const Point &p){

    std::vector<double> phi;
    int weig(0);
    unsigned int answer;

    for (int i = 0; i < hiddenLayerCoefs.size(); ++i) {
        phi.push_back( clacPhi(hiddenLayerCoefs[i].first, p, hiddenLayerCoefs[i].second));
    }

    for (int j = 0; j < outputNeurons.size(); ++j) {

        if( outputNeurons[j]->getWeightSumm(p) > weig ) {
            answer = j;
        }
    }

    return answer;
}