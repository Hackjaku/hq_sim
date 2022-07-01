#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <vector>
#include <boost/numeric/ublas/matrix.hpp>

#include "calc.h"

class Player;
class Monster;

class Character {
public:
    int _attack;
    int _defense;
    int _health;
};

class Monster : public Character {
public:
    Monster(int attack, int defence, int health);
    std::vector<double> operator / (Player &player);
};

class Player : public Character {
public:
    Player(int attack, int defence, int health);
    std::vector<double> operator / (Monster &monster);
};

#endif