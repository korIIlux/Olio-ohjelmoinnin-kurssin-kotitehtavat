#include "italianchef.h"

ItalianChef::ItalianChef(string name) : Chef(name)
{
    cout << "[DEBUG] ItalianChef konstruktori." << endl;
}

ItalianChef::~ItalianChef()
{
    cout<<"[DEBUG] ItalianChef Destruktori kutsuttu."<<endl;
}

bool ItalianChef::askSecret(string passw, int aines1, int aines2)
{
    cout<<"[DEBUG]askSecret() kutsuttu."<<endl;

    bool check = false;
    if (passw == password)
    {
        check = true;
        cout<<"[DEBUG] check = true. Kutsutaan makepizza()."<<endl;
    }
    if (check)
    {
        makepizza(aines1, aines2);
    }
    return check;
}

int ItalianChef::makepizza(int jauho, int vesi)
{
    cout << "[DEBUG] makepizza() kutsuttu." << endl;

    if (jauho < 5 && vesi < 5)
    {
        cout << "Kokki " << getName() << " ei valmistanut pizzaa. (Liian vahan ainesta)" << endl;
        return 0;
    }
    else
    {
        int pizzas = min(jauho / 5, vesi / 5);
        cout << "Kokki "<<getName()<<" valmisti "<<jauho+vesi<<" aineksesta " << pizzas << " pizzaa." << endl;
        return pizzas;
    }
}
