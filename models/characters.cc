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

Player& Player::operator /= (Monster &monster) {
    auto chance_vector = _calc.calculate_hit_chances(0.5, 0.3333, monster._attack, _defense);
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    srand((time_t)ts.tv_nsec);
    auto roll = (float) rand() / RAND_MAX;
    float cumulative_chance = 0;
    for (int i = 0; i < chance_vector.size(); ++i) {
        cumulative_chance += chance_vector[i];
        if (roll <= cumulative_chance) {
            _health -= i;
            break;
        }
    }
    return *this;
}

Monster& Monster::operator /= (Player &player) {
    auto chance_vector = _calc.calculate_hit_chances(0.5, 0.1666, player._attack, _defense);
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    srand((time_t)ts.tv_nsec);
    auto roll = (float) rand() / RAND_MAX;
    float cumulative_chance = 0;
    for (int i = 0; i < chance_vector.size(); ++i) {
        cumulative_chance += chance_vector[i];
        if (roll <= cumulative_chance) {
            _health -= i;
            break;
        }
    }
    return *this;
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