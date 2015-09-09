//
// Created by dima on 31.08.15.
//

#include "Perceptron.h"

Perceptron::Perceptron(const std::vector<double> &w, double t) : weight(w), threshold(t) {

}

Perceptron::~Perceptron() {

}

bool Perceptron::classification(const std::vector< double > &x) {

    bool a;
    double weightSum = -threshold;

    for (int i = 0; i < x.size(); ++i) {

        weightSum += weight[i]*x[i];
    }

    if (weightSum >= 0 ) {
        a = 1;
    } else {
        a = 0;
    }

    return a;
}

