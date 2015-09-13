//
// Created by dima on 13.09.15.
//

#ifndef PERCEPTRON_LINEARCLASSIFICATIONLEARNER_H
#define PERCEPTRON_LINEARCLASSIFICATIONLEARNER_H

#include "Perceptron.h"


class ILinearClassificationLearner {
public:
    virtual Perceptron learn (std::vector < std::vector < double> > &train) = 0;
    virtual ~ILinearClassificationLearner() {};

};


#endif //PERCEPTRON_LINEARCLASSIFICATIONLEARNER_H
