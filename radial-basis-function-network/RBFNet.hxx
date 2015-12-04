//
// Created by dima on 19.10.15.
//


template<typename DataType, unsigned int dimension>
RBFNet<DataType, dimension>::RBFNet(unsigned int h, unsigned int o){

    outputNeurons.reserve(o);
    for (int i = 0; i < o; ++i) {
        outputNeurons.push_back(Neuron(hiddenLayerCoefs.size()));
    }
    hiddenLayerCoefs.reserve(h);
}

template<typename DataType, unsigned int dimension>
void RBFNet<DataType, dimension>::setHiddenCoefs(std::vector<std::pair<DataPoint<DataType, dimension>, double>> h) {
    hiddenLayerCoefs = h;
}

template<typename DataType, unsigned int dimension>
int RBFNet<DataType, dimension>::classify(const DataPoint<DataType, dimension> &a){

}