//
// Created by dima on 31.08.15.
//

#ifndef PERCEPTRON_PERCEPTRON_H
#define PERCEPTRON_PERCEPTRON_H

#include <iostream>
#include <vector>


class Perceptron {
private:
    std::vector < double > weight;
    double threshold;

public:
    Perceptron (const std::vector < double > &w, double threshold);
    bool classification( const std::vector <double > &x );
    void setWeight(const std::vector <double> &w, double t );
    std::vector <double> getWeightAndThreshold();
    ~Perceptron();

};


#endif //PERCEPTRON_PERCEPTRON_H
