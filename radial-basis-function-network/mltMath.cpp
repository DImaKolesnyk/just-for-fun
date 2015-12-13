#include "mltMath.h"

double dist(const std::vector<double> &a, const std::vector<double> &b) {

    double dist = 0.0;
    for (int i = 0; i < a.size(); ++i) {
        dist += std::pow( (b[i] - a[i]), 2);
    }

    return sqrt(dist);
}


double weightSum(const std::vector<double> &weight, const Point &input) {

    if (weight.size() != input.dim()) throw WeightAndInputHaveWrongSizeInWeightSum();

    double sum = 0.0;
    for (int i = 0; i < weight.size(); ++i) {
        sum += weight[i]*input[i];
    }
    return sum;
}

Point average(const Data &a) {

    std::vector<double> av;
    double sum = 0.0;
    for (int i = 0; i < a[0].dim(); ++i) {
        for (int j = 0; j < a.size(); ++j) {
            sum+= a[j][i];
        }
        av.push_back(sum/a.size());
        sum = 0;
    }
    return Point(av);
}

// OK
double norm(const Point &a) {

    double b = 0.0;
    for (int i = 0; i < a.dim(); ++i) {
        b += pow(a[i], 2);
    }

    return sqrt(b);
}


double clacSigma(const Point &mu, const Data &classSet) {

    double sigma = 0.0;

    for (int i = 0; i < classSet.size(); ++i) {
        sigma += norm( classSet[i] - mu );
    }

    return (sigma/classSet.size());
}


double clacPhi(const Point &mu, const Point &x, double sigma) {

    double phi = 0.0;
//    phi = exp(
//            pow( (-1)*distance(x, mu),2)/
//                    (2*pow( sigma,2))
//    );

    for (int i = 0; i < mu.dim(); ++i) {
        phi += (double)pow((x[i] - mu[i]), 2)/(2*pow(sigma, 2));
    }

    phi = exp(-phi);
    return phi;
}

double distance(const Point &a, const Point &b) {

    double dist = 0.0;
    for (int i = 0; i < a.dim(); ++i) {
        dist += std::pow( (b[i] - a[i]), 2);
    }

    return sqrt(dist);
}


double costFunc(const Data &d, const std::vector<double> &w) {
    double costFunction = 0.0;
    for (int i = 0; i < d.size(); ++i) {
        costFunction += pow(d[i].getClass() - weightSum(w, d[i]), 2);
    }
    return costFunction/d.size();
}


double simpleAverage(const Data &d, const std::vector<double> &w, int k) {

    double av = 0.0;
    for (int i = 0; i < d.size(); ++i) {
        if(k == -1)
            av += (weightSum(w, d[i]) - d[i].getClass());
        else
            av += (weightSum(w, d[i]) - d[i].getClass())*d[i][k];
    }

    return ((double)av/d.size());
}