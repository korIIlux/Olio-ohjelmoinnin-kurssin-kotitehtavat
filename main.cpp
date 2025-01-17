#include "pankkitili.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Pankki pankki;

    pankki.tiliTalletus("Alice", 500);
    pankki.tiliTalletus("Alice", -100);

    pankki.tiliNosto("Alice", 200);
    pankki.tiliNosto("Alice", 1000);

    pankki.luotonMaksu("Bob", 100);
    pankki.luotonMaksu("Bob", 5000);

    pankki.luotonNosto("Charlie", 500);
    pankki.luotonNosto("Charlie", 5000);

    double pankinVarat = pankki.getVarat();
    cout << "Pankin varat tällä hetkellä: " << pankinVarat << endl;

    cout << "\n** Tuntemattoman asiakkaan kasittely **" << endl;
    pankki.tiliTalletus("Daniel", 300);
    pankki.tiliNosto("Daniel", 100);

    cout << "\n-- Testaus paattyi --\n" << endl;

    return 0;
}

