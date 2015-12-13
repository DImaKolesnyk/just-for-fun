//
// Created by dima on 06.12.15.
//

#include "NeuronBuilder.hpp"

NeuronBuilder::NeuronBuilder(unsigned int o) : output(o), net(new Neuron) {

}

void NeuronBuilder::learn(const Data &d) {

    unsigned  int dimension = d[0].dim();
    std::vector < double > weight(dimension, 0);
    for (int k = 0; k < dimension; ++k) {
        weight[k] = 1;
    }
    net->setWeight(weight);

        double oldCostF(0.);
        std::vector<double> oldWeight;
//       do {


   for (int j = 0; j < 2500; ++j) {

        //oldCostF = costFunc(d, weight);
        oldWeight = weight;
        weight[0] = weight[0] - 0.01 * simpleAverage(d, oldWeight, -1);
        for (int i = 1; i < weight.size(); ++i) {
            weight[i] = weight[i] - 0.01 * simpleAverage(d, oldWeight, i);
        }

    }

 //       } while (abs(oldCostF - costFunc(d, weight)) > 0.01);



    net->setWeight(weight);
}

Net * NeuronBuilder::get() const {
    return net;
}