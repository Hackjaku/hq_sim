#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <vector>
#include <boost/numeric/ublas/matrix.hpp>
#include <time.h>

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
    Monster& operator /= (Player &player);
private:
    Calc _calc;
};

class Player : public Character {
public:
    Player(int attack, int defence, int health);
    Player& operator /= (Monster &monster);
private:
    Calc _calc;
};

#endif