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

std::vector<double> Calc::calculate_hit_chances(double attack_chance, double defense_chance, int attack, int defense) {

    std::vector<double> result(attack + 1);

    using namespace boost::numeric::ublas;

    vector<double> player_rolls(attack + 1); // le marginali dell'attaccante
    vector<double> monster_rolls(defense + 1); // le marginali del difensore

    for (unsigned int i = 0; i <= attack; ++i) {
        // ? calcolo la probabilita' di ogni risultato positivo
        // la chance di attacco positivo e' 1/2 per ogni lancio
        player_rolls[i] = bernoulli(attack, i, attack_chance);
    }

    for (unsigned int i = 0; i <= defense; ++i) {
        // ? calcolo la probabilita' di ogni risultato positivo
        // la chance di difesa positiva e' 1/6 per ogni lancio
        monster_rolls[i] = bernoulli(defense, i, defense_chance);
    }

    auto matrix = multiply(player_rolls, monster_rolls);

    for (int i = 0; i < attack + 1; ++i) {
        for (int j = 0; j < defense + 1; ++j) {
            auto xxx = matrix(i, j);
            if (i - j <= 0) {
                result[0] += matrix(i, j);
            } else {
                result[i - j] += matrix(i, j);
            }
        }
    }
    return result;
}