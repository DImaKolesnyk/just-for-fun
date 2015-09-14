//
// Created by dima on 31.08.15.
//

#ifndef PERCEPTRON_PERCEPTRON_H
#define PERCEPTRON_PERCEPTRON_H

#include <iostream>
#include <vector>

/**
 * Perceptron - is the model of hyperplane, which classifies of data.
 */

class Perceptron {
private:
    std::vector < double > weight; ///< Weights on perceptron synapses.
    double threshold; ///< Weights of bias input.

public:
    Perceptron (const std::vector < double > &w, double threshold);
    bool classification( const std::vector <double > &x );
    void setWeight(const std::vector <double> &w, double t );
    std::vector <double> getWeightAndThreshold();
    ~Perceptron();

};


#endif //PERCEPTRON_PERCEPTRON_H
