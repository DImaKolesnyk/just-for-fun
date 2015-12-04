#include "mltMath.h"

double dist(const std::vector<double> &a, const std::vector<double> &b) {

    double dist = 0.0;
    for (int i = 0; i < a.size(); ++i) {
        dist += std::pow( (b[i] - a[i]), 2);
    }

    return sqrt(dist);
}


double weightSum(const std::vector<double> &weight, const std::vector<double> &input) {

    if (weight.size() != input.size()) throw WeightAndInputHaveWrongSizeInWeightSum();

    double sum = 0.0;
    for (int i = 0; i < weight.size(); ++i) {
        sum += weight[i]*input[i];
    }
    return sum;
}
