//
// Created by dima on 31.08.15.
//

#ifndef PERCEPTRON_PERCEPTRON_H
#define PERCEPTRON_PERCEPTRON_H

#include <vector>
#include <math.h>
#include <map>

enum act_func {SIGMOID, THRESGOLD};


class Perceptron {
private:
    std::vector <double> weight;
    std::vector <double> signal_set;
    double output_signal;
    unsigned int type_act_func;

public:
    Perceptron ();
    void learn (std::map < std::vector, bool > );
    void signal (std::vector);
    bool answer();
    double activation_function(double, unsigned int);
};


#endif //PERCEPTRON_PERCEPTRON_H
