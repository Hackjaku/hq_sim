#include "characters.h"

matrix<double> multiply(vector<double> &v1, vector<double> &v2) {
    matrix<double> result(v1.size(), v2.size());
    for (unsigned int i = 0; i < v1.size(); i++) {
        for (unsigned int j = 0; j < v2.size(); j++) {
            result(i, j) = v1[i] * v2[j];
        }
    }
    return result;
}

std::vector<double> Monster::operator / (Player &player) {
    std::vector<double> result(player._attack + 1);

    using namespace boost::numeric::ublas;

    vector<double> player_rolls(player._attack + 1); // le marginali dell'attaccante
    vector<double> monster_rolls(this->_defense + 1); // le marginali del difensore

    for (unsigned int i = 0; i <= player._attack; ++i) {
        // ? calcolo la probabilita' di ogni risultato positivo
        // la chance di attacco positivo e' 1/2 per ogni lancio
        player_rolls[i] = Calculator.bernoulli(player._attack, i, 0.5);
    }

    for (unsigned int i = 0; i <= this->_defense; ++i) {
        // ? calcolo la probabilita' di ogni risultato positivo
        // la chance di difesa positiva e' 1/6 per ogni lancio
        monster_rolls[i] = Calculator.bernoulli(this->_defense, i, 0.1666);
    }

    auto matrix = multiply(player_rolls, monster_rolls);

    for (unsigned int i = 0; i < player._attack + 1; ++i) {
        for (unsigned int j = 0; j < this->_defense + 1; ++j) {
            if (i - j <= 0) {
                result[i] += matrix(i, j);
            } else {
                result[i - j] += matrix(i, j);
            }
        }
    }
    
    return result;
}