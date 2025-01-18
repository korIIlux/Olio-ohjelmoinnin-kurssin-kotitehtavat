#include "seuraaja.h"
#include <iostream>
#include <string>
using namespace std;


Seuraaja::Seuraaja(string s)
{
    cout<<"Luodaan seuraaja "<<s<<endl;
    nimi = s;
}

string Seuraaja::getNimi()
{
    return nimi;
}

void Seuraaja::paivitys(string message)
{
    cout<<"Seuraaja "<<nimi<<" sai viestin"<<message<<endl;;
}

Notifikaattori::Notifikaattori()
{
    cout<<"Luodaan notifikaattori"<<endl;
}

void Notifikaattori::lisaa(Seuraaja* n1)
{
    if(!n1)
    {
        return;
    }
    n1->next = seuraajat;
    seuraajat = n1;
    cout<<"Notifikaattori lisaa seuraajan "<<n1<<endl;
}

void Notifikaattori::poista(Seuraaja* n)
{
    if (!n || !seuraajat) //jos poistettava on listan ensimmäinen
    {
        cout<<"Notifikaattori poistaa seuraajan "<<n<<endl;
        seuraajat = seuraajat->next;
        delete n;
        return;
    }

    Seuraaja* edellinen = seuraajat;
    while (edellinen->next != nullptr && edellinen->next != n)
    {
        edellinen = edellinen->next;
    }

    if(edellinen->next == n)
    {
        cout<<"Notifikaattori poistaa seuraajan "<<n<<endl;
        edellinen->next = n->next;
        delete n;
    }
}

void Notifikaattori::tulosta()
{
    Seuraaja* nykyinen = seuraajat;
    cout<<"Notifikaattorin seuraajat:"<<endl;
    while (nykyinen != nullptr)
    {
        cout << "Seuraaja " << nykyinen->getNimi() << endl;
        nykyinen = nykyinen->next;
    }
}

void Notifikaattori::postita(string message)
{
    cout<<"Notifikaattori postaa viestin: "<<message<<endl;
    Seuraaja* nykyinen = seuraajat;
    while (nykyinen != nullptr)
    {
        nykyinen->paivitys(message);
        nykyinen = nykyinen->next;
    }
}
