//
// Created by dima on 06.09.15.
//

#ifndef PERCEPTRON_LEARNPERCEPTRON_H
#define PERCEPTRON_LEARNPERCEPTRON_H

#include "Perceptron.h"


class LearnPerceptron {
public:
    LearnPerceptron();
    Perceptron learn (std::vector < std::vector < double> > &train);
    virtual ~LearnPerceptron();
};


#endif //PERCEPTRON_LEARNPERCEPTRON_H
