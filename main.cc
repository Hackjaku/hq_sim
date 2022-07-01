#include <iostream>
#include "models/characters.h"

using namespace std;

int main() {
    Player player(2, 3, 6);
    Monster monster(2, 4, 6);
    auto vector = monster / player;

    for (auto i : vector) {
        cout << i << endl;
    }
    return 0;
}