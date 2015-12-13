//
// Created by dima on 19.10.15.
//
#include "RBFNet.h"

RBFNet::RBFNet(unsigned int h, unsigned int o){

    outputNeurons.reserve(o);
    hiddenLayerCoefs.reserve(h);
}


void RBFNet::setWeight(std::vector<std::pair<Point, double>> h, std::vector<Net *> n) {

    outputNeurons = n;
    hiddenLayerCoefs = h;
}


double RBFNet::classify(const Point &p) const{

    std::vector<double> phi;
    double weig_buff(0);
    double weig;
    int answer(-1);

    phi.push_back(1);
    for (int i = 0; i < hiddenLayerCoefs.size(); ++i) {
        phi.push_back( clacPhi(hiddenLayerCoefs[i].first, p, hiddenLayerCoefs[i].second));
    }

    Point phi_p = Point(phi);
    for (int j = 0; j < outputNeurons.size(); ++j) {
        weig = outputNeurons[j]->classify(phi_p);
        std::cout << j << ") " << weig << std::endl;

        if( weig - weig_buff > 0  ) {
            weig_buff = weig;
            answer = j;
        }
    }

    return answer;
}