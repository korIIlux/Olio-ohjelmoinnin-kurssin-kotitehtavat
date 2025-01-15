#include "chef.h"
#include <iostream>
#include <string>
using namespace std;

Chef::Chef(string name)
{
    cout << "[DEBUG] Chef Konstruktori kutsuttu." << endl;
    chefName = name;
}

Chef::~Chef()
{
    cout << "[DEBUG] Chef Destructor kutsuttu." << endl;
}

string Chef::getName()
{
    return chefName;
}

int Chef::makeSalad(int salad_maara)
{
    cout << "[DEBUG] makeSalad() kutsuttu." << endl;

    if (salad_maara < 5)
    {
        cout << "Kokki " << chefName << " ei valmistanut salattia. (Liian vähän ainesta)" << endl;
    }

    else
    {
        int salads = salad_maara / 5;
        cout << "Kokki " << chefName << " valmisti " << salad_maara << " aineksesta " << salads <<" salattia."<<endl;
    }

    return 0;
}

int Chef::makeSoup(int soup_maara)
{
    cout << "[DEBUG] makeSoup() kutsuttu." << endl;

    if (soup_maara < 3)
    {
        cout << "Kokki " << chefName << " ei valmistanut keittoa. (Liian vähän ainesta)" << endl;
    }

    else
    {
        int soups = soup_maara / 3;
        cout << "Kokki " << chefName << " valmisti " << soup_maara << " aineksesta " << soups <<" keittoa."<<endl;
    }

    return 0;
}

