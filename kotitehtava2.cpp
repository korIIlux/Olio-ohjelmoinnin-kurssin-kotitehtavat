#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int game();

int main()
{
    int arvausten_maara = game();

    cout << "Arvasit oikean luvun " << arvausten_maara << " arvauksella!" << endl;

    return 0;
}

int game()
{
    int luku;
    int user_luku;
    int arvausten_maara = 0;


    srand(time(0));
    luku = rand() % 20 + 1;

    cout << "Arvaa tietokoneen arpoma luku (valilta 1-20)" << endl;

    do
    {
        cout << "Syota arvauksesi: ";
        cin >> user_luku;

        arvausten_maara++;

        if (luku > user_luku)
        {
            cout << "Luku on suurempi!" << endl;
        }
        else if (luku < user_luku)
        {
            cout << "Luku on pienempi!" << endl;
        }
        else
        {
            cout << "Oikea vastaus!" << endl;
        }

    }
    while (luku != user_luku);

    return arvausten_maara;
}
