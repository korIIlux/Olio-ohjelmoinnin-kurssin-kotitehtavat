#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Game::Game(int maxNumber) : maxNumber(maxNumber), playerGuess(0), numOfGuesses(0)
{
    cout << "[DEBUG] Pelin constructor kutstuttu. Max luku: " << maxNumber << endl;
    srand(std::time(nullptr));
    randomNumber = rand() % maxNumber + 1;
    cout << "[DEBUG] Random number generoitu: " << randomNumber << endl;
}

Game::~Game()
{
    cout << "[DEBUG] Game destrukttori kutsuttu." << std::endl;
}

void Game::play() {
    cout << "[DEBUG] play() kutsuttu. Aloitetaan peli." << endl;
    cout << "Arvaa luvun valilta 1 - " << maxNumber << "." << endl;

    do
    {
        cout << "Syota arvauksesi: ";
        cin >> playerGuess;
        numOfGuesses++;
        cout << "[DEBUG] Pelaja arvasi: " << playerGuess << endl;

        if (playerGuess < randomNumber)
        {
            cout << "Liian pieni luku!" << endl;
        }
        else if (playerGuess > randomNumber)
        {
            cout << "Liian suuri luku!" << endl;
        }
    }
    while (playerGuess != randomNumber);

    cout << "Jes! Arvasit oikein!" << endl;
    printGameResult();
}

void Game::printGameResult() {
    cout << "[DEBUG] printGameResult() kutsuttu." << endl;
    cout << "Oikea luku oli: " << randomNumber << endl;
    cout << "Sinä teit "  << numOfGuesses << " arvauksia ennen kuin voitit pelin." << endl;
}
