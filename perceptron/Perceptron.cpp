//
// Created by dima on 31.08.15.
//

#include "Perceptron.h"

Perceptron::Perceptron(int) {

}

double Perceptron::activation_function(double weighted_sum, unsigned int type) {

    double func_answer = 0;

    if ( type == 0 )
    {
        func_answer = 1 / ( 1 + exp(-weighted_sum));
    } else if ( type == 1 ) {

        if ( weighted_sum >= 0 ) {
            func_answer = 1;
        } else {
            func_answer = 0;
        }
    }

    return func_answer;
}