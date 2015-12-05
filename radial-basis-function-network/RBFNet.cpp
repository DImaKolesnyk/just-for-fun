//
// Created by dima on 19.10.15.
//


RBFNet::RBFNet(unsigned int h, unsigned int o){

    outputNeurons.reserve(o);
    for (int i = 0; i < o; ++i) {
        outputNeurons.push_back(Neuron(hiddenLayerCoefs.size()));
    }
    hiddenLayerCoefs.reserve(h);
}


void RBFNet::setHiddenCoefs(std::vector<std::pair<Point, double>> h) {
    hiddenLayerCoefs = h;
}


int RBFNet::classify(const Point &a){

}