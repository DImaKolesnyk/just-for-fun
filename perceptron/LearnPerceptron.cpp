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

    double threshold = 0.5;
    std::vector < double > weight;
    weight.push_back(0.3);
    weight.push_back(0.7);
    Perceptron perceptron(weight, threshold);

    bool myAnswer;

    for (int j = 0; j < 5; ++j) {
        for (int i = 0; i < 80; ++i) {
            myAnswer = perceptron.classification(train[i]);
            if ( myAnswer != train[i][2]){
                //-----
//                std::cout << perceptron.classification(train[i]) << "=?" << train[i][2] << std::endl;
//                std::cout << "weight vector: " << weight[0] << "," << weight[1] << "; " << std::endl;
//                std::cout << "train " << train[i][0] << ", " << train[i][1] << "; " << std::endl;
                //-----
                weight[0] = weight[0] + 0.5*(train[i][2] -  myAnswer)*train[i][0];
                weight[1] = weight[1] + 0.5*(train[i][2] -  myAnswer)*train[i][1];
//                std::cout << "New weight vector: " << weight[0] << "," << weight[1] << "; " << std::endl;
                threshold = threshold + 0.18*(train[i][2] -  myAnswer);
                perceptron.setWeight(weight, threshold);

            }
        }
    }

    return perceptron;

}