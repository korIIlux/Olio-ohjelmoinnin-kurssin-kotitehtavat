#ifndef PANKKITILI_H
#define PANKKITILI_H
#include "string"
using namespace std;

class Pankkitili
{
    public:
        Pankkitili(string);
        double getBalance();
        double deposit(double);
        double withdraw(double);
    protected:
        string omistaja;
        double saldo = 0;

};

class Luottotili: public Pankkitili
{
    public:
        Luottotili(string, double);
        double deposit(double);
        double withdraw(double);
    protected:
        double luottoRaja = 0;
};

class Asiakas
{
    public:
        Asiakas(string, double);
        string getNimi();
        double getTilisaldo();
        double getLuottosaldo();
        double tiliTalletus(double);
        double tiliNosto(double);
        double luotonMaksu(double);
        double luotonNosto(double);
    private:
        string name;
        Pankkitili kayttotili;
        Luottotili luottotili;
};

class Pankki
{
    public:
        Pankki();
        double getVarat();
        double tiliTalletus(string, double);
        double tiliNosto(string, double);
        double luotonMaksu(string, double);
        double luotonNosto(string, double);
    private:
        Asiakas a;
        Asiakas b;
        Asiakas c;
};

#endif // PANKKITILI_H
