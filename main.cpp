#include "Game.h"
#include <iostream>
using namespace std;

int main() {
    cout << "[DEBUG] main() kutsuttu." << endl;

    int maxNumber;
    cout << "Syota max luku pelille: ";
    cin >> maxNumber;

    Game game(maxNumber);

    game.play();

    cout << "[DEBUG] main() lopetettu." << endl;
    return 0;
}
