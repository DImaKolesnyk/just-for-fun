
#include "Neuron.h"


Neuron::Neuron(unsigned int inputSize) :input(inputSize) {

    weight.reserve(inputSize+1);
    for (int i=0;i<weight.size();i++) {
        weight.at(i) = (rand()/(double)RAND_MAX)*2;
    }
}

void Neuron::learn(std::vector<double> phi, int realClass) {

    double oldWeightSum = weightSum(weight, phi);
    std::vector<double> oldWeight;
    for (auto x : oldWeight) {
        x = 0.0;
    }

//    while ( norm(
//            Point<double, input>(oldWeight) - Point<double, input>(weight)  ) > 0.01 ) {

    while ( dist(oldWeight, weight) > 0.01 ) {
        weight[0] = weight[0] + 0.5 * (realClass - oldWeightSum);
        for (int i = 1; i < phi.size(); ++i) {

            weight[i] = weight[i] + 0.5 * (realClass - oldWeightSum) * phi[i];
        }

        oldWeightSum = weightSum(weight, phi);
    }

}
