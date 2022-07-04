#include <iostream>
#include "models/characters.h"

using namespace std;

int main() {
    Player player(2, 3, 6);
    Monster monster(2, 4, 6);

    monster /= player;
    cout << "Monster health: " << monster._health << endl;
    return 0;
}