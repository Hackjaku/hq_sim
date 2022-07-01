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

std::vector<double> Player::operator / (Monster &monster) {
    return _calc.calculate_hit_chances(0.5, 0.1666, _attack, monster._defense);
}

std::vector<double> Monster::operator / (Player &player) {
    return _calc.calculate_hit_chances(0.5, 0.3333, player._attack, _defense);
}

Monster::Monster(int attack, int defence, int health) {
    _attack = attack;
    _defense = defence;
    _health = health;
    _calc = Calc();
}

Player::Player(int attack, int defence, int health) {
    _attack = attack;
    _defense = defence;
    _health = health;
    _calc = Calc();
}