#include <iostream>
#include <thread>
#include <chrono>
#include "models/characters.h"

using namespace std;

int main() {

    Player player1(3, 3, 8);
    Player player2(4, 2, 7);
    Player player3(2, 2, 6);
    Player player4(1, 2, 4);

    Monster monster1(4, 5, 4);
    Monster monster2(4, 4, 4);
    Monster monster3(3, 2, 2);
    Monster monster4(3, 2, 2);

    unsigned player_wins = 0, monster_wins = 0;
    float average_deaths = 0;
    for (int i = 0; i < 1500; ++i) {
        std::vector<Player> players = {player1, player2, player3, player4};
        std::vector<Monster> monsters = {monster1, monster2, monster3, monster4};
        while (players.size() > 0 && monsters.size() > 0) {
            for (auto &player : players) {
                monsters[0] /= player;
                if (monsters[0]._health <= 0) {
                    monsters.erase(monsters.begin());
                }
                if (monsters.size() == 0) {
                    break;
                }
            }

            for (auto &monster : monsters) {
                players[0] /= monster;
                if (players[0]._health <= 0) {
                    players.erase(players.begin());
                }
                if (players.size() == 0) {
                    break;
                }
            }
        }
        if (players.size() > 0) {
            ++player_wins;
            average_deaths += (4 - players.size());
        } else {
            ++monster_wins;
        }
    }

    std::cout << "Player wins: " << (float)(player_wins) / 15 << "%" << endl;
    std::cout << "Monster wins: " << (float)monster_wins / 15 << "%" << endl;

    std::cout << "Average deaths: " << (float)average_deaths / player_wins << endl;

    return 0;
}