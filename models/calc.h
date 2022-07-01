#ifndef CALC_H
#define CALC_H

#include <boost/numeric/ublas/matrix.hpp>

using namespace boost::numeric::ublas;

class Calc {
public:
    double binomial(unsigned int n, unsigned int k);
    long long unsigned factorial(unsigned int n);
    double bernoulli(unsigned int n, unsigned int k, double p);
    matrix<double> multiply (vector<double> &v1, vector<double> &v2);
};

#endif