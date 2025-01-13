#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int luku;
    int user_luku;

    srand(time(0));
    luku = rand() % 20 + 1;

    cout << "Arvaa tietokoneen arpoma luku (valilta 1-20)" << endl;

    do
    {
        cout << "Syota arvauksesi: ";
        cin >> user_luku;

        if (luku > user_luku) {
            cout << "Luku on suurempi!" << endl;
        } else if (luku < user_luku) {
            cout << "Luku on pienempi!" << endl;
        } else {
            cout << "Oikea vastaus!" << endl;
        }

    }
    while (luku != user_luku);

    return 0;
}
