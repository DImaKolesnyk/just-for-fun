//
// Created by dima on 31.08.15.
//

#ifndef PERCEPTRON_PERCEPTRON_H
#define PERCEPTRON_PERCEPTRON_H

#include <vector>
#include <math.h>

enum act_func {SIGMOID, THRESGOLD};


class Perceptron {
private:
    int id;
    std::vector <double> weight;
    std::vector <double> signal;
    double output_signal;
    unsigned int type_act_func;

public:
    Perceptron (int);
    double activation_function(double, unsigned int);
};


#endif //PERCEPTRON_PERCEPTRON_H
