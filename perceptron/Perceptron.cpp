//
// Created by dima on 31.08.15.
//

#include "Perceptron.h"

Perceptron::Perceptron(const std::vector<double> &w, double t) : weight(w), threshold(t) {

}

Perceptron::~Perceptron() {
    std::vector<double>().swap(weight);
}

void Perceptron::setWeight(const std::vector<double> &w, double t) {

    weight = w;
    threshold = t;
}

std::vector <double> Perceptron::getWeightAndThreshold() {

    std::vector<double> a(weight.size() + 1);
    a = weight;
    a.push_back(threshold);

    return a;

}

bool Perceptron::classification(const std::vector< double > &x) {

    double weightSum = -threshold;
    std::vector<double>::const_iterator xit = x.begin();
    for ( const double& w: weight) {
        weightSum += w * (*xit);
        ++xit;
    }

    return (weightSum >= 0.0);
}

