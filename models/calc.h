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
    std::vector<double> calculate_hit_chances(double attack_chance, double defense_chance, int attack, int defense);
};

#endif