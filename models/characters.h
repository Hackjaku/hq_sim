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
    int _attack;
    int _defence;
    int _health;
};

class Player {
public:
    Player(int attack, int defence, int health);
    std::vector<double> operator / (Monster &monster);

private:
    int _attack;
    int _defence;
    int _health;
};

#endif