#ifndef SEURAAJA_H
#define SEURAAJA_H
#include<string>

using namespace std;

class Seuraaja
{
public:
    Seuraaja(string);
    Seuraaja* next = nullptr;
    string getNimi();
    void paivitys(string);
private:
    string nimi;
};

class Notifikaattori
{
public:
    Notifikaattori();
    void lisaa(Seuraaja *);
    void poista(Seuraaja *);
    void tulosta();
    void postita(string);
private:
    Seuraaja* seuraajat = nullptr;
};

#endif // SEURAAJA_H
