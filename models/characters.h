#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <vector>

class Player;
class Monster;

class Monster {
public:
    Monster(int attack, int defence, int health);
    std::vector<double> operator / (Player &player);

private:
    int attack;
    int defence;
    int health;
};

class Player {
public:
    Player(int attack, int defence, int health);
    std::vector<double> operator / (Monster &monster);

private:
    int attack;
    int defence;
    int health;
};

#endif