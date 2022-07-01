#include "calc.h"
#include <math.h>

long long unsigned Calc::factorial(unsigned int n) {
    long long unsigned result = 1;
    for (unsigned int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

double Calc::binomial(unsigned int n, unsigned int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

double Calc::bernoulli(unsigned int n, unsigned int k, double p) {
    return binomial(n, k) * pow(p, k) * pow(1 - p, n - k);
}

matrix<double> Calc::multiply(vector<double> &v1, vector<double> &v2) {
    matrix<double> result(v1.size(), v2.size());
    for (unsigned int i = 0; i < v1.size(); i++) {
        for (unsigned int j = 0; j < v2.size(); j++) {
            result(i, j) = v1[i] * v2[j];
        }
    }
    return result;
}