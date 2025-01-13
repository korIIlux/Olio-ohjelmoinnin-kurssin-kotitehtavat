#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int game(int maxnum);

int main()
{
    int maxnum;

    cout << "Syota suurin etsittava luku: ";
    cin >> maxnum;

    int arvausten_maara = game(maxnum);

    cout << "Arvasit oikean luvun " << arvausten_maara << " arvauksella!" << endl;

    return 0;
}

int game(int maxnum)
{
    int luku;
    int user_luku;
    int arvausten_maara = 0;

    srand(time(0));
    luku = rand() % maxnum + 1;

    cout << "Arvaa tietokoneen arpoma luku (valilta 1-" << maxnum << ")" << endl;

    do
    {
        cout << "Syata arvauksesi: ";
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
        else {
            cout << "Oikea vastaus!" << endl;
        }

    }
    while (luku != user_luku);

    return arvausten_maara;
}
