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