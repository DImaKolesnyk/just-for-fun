//
// Created by dima on 06.09.15.
//

#include "LearnPerceptron.h"
#include <stdlib.h>

LearnPerceptron::LearnPerceptron() {

}

LearnPerceptron::~LearnPerceptron() {

}

Perceptron LearnPerceptron::learn(std::vector<std::vector<double> > &train) {

    std::vector < double > weight;
    weight.push_back(rand());
    weight.push_back(rand());
    Perceptron perceptron(weight, rand());

    bool error;

    return perceptron;

}