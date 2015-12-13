
#include "Neuron.h"


Neuron::Neuron(unsigned int inputSize) :input(inputSize) {

  //  weight.reserve(inputSize);
}

double Neuron::classify(const Point &p) const {

    double sum = 0;
    for (int i = 0; i < weight.size(); ++i) {
        sum += weight[i]*p[i];
    }

    return sum;
}

void Neuron::setWeight(const std::vector<double> &w) {
    weight = w;
}