//
// Created by dima on 18.10.15.
//

#ifndef RADIAL_BASIS_FUNCTION_NETWORK_MLTMATH_H
#define RADIAL_BASIS_FUNCTION_NETWORK_MLTMATH_H

#include "Data.h"
#include <cmath>

class WeightAndInputHaveWrongSizeInWeightSum {};


double distance(const Point &a, const Point &b);
double dist(const std::vector<double> &a, const std::vector<double> &b);
Point average(const Data &a);
double norm(const Point &a);
double clacSigma(const Point &mu, const Data &classSet);
double clacPhi(const Point &mu, const Point &x, double sigma);
double weightSum(const std::vector<double> &weight, const std::vector<double> &input);
double costFunc(const Data &d, const std::vector<double> &w);
double simpleAverage(const Data &d, const std::vector<double> &w, int k);

#endif //RADIAL_BASIS_FUNCTION_NETWORK_MLTMATH_H
