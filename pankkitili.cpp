#include "pankkitili.h"
#include <iostream> // Debug-tulostuksia varten
#include <string.h>
using namespace std;

Pankkitili::Pankkitili(string nimi): omistaja(nimi), saldo(0)
{
    cout << "Pankkitili luotu: " << nimi << ", saldo: " << saldo << endl;
}

double Pankkitili::getBalance()
{
    cout << "Tilin saldo kysytty: " << omistaja << ", saldo: " << saldo << endl;
    return saldo;
}

double Pankkitili::deposit(double amount)
{
    if (amount < 0)
    {
        cout << "Virhe: Negatiivinen talletusyritys tilille " << omistaja << ", summa: " << amount << endl;
        return -1;
    }
    saldo += amount;
    cout << "Talletus tilille " << omistaja << ": " << amount << ", uusi saldo: " << saldo << endl;
    return saldo;
}

double Pankkitili::withdraw(double amount)
{
    if (amount < 0 || amount > saldo)
    {
        cout << "Virhe: Nostoyritys epäonnistui tililta " << omistaja
             << ", summa: " << amount << ", saldo: " << saldo << endl;
        return -1;
    }
    saldo -= amount;
    cout << "Nosto tililta " << omistaja << ": " << amount << ", uusi saldo: " << saldo << endl;
    return saldo;
}

Luottotili::Luottotili(string nimi, double luottoraja): Pankkitili(nimi), luottoRaja(-luottoraja)
{
    cout << "Luottotili luotu: " << nimi << ", luottoraja: " << luottoraja << endl;
}

double Luottotili::deposit(double amount)
{
    if (amount < 0)
    {
        cout << "Virhe: Negatiivinen talletusyritys luottotilille " << omistaja
             << ", summa: " << amount << endl;
        return -1;
    }
    if (saldo + amount > 0)
    {
        cout << "Virhe: Luoton maksaminen liikaa luottotilille " << omistaja
             << ", summa: " << amount << endl;
        return -1;
    }
    saldo += amount;
    cout << "Luoton maksu tilille " << omistaja << ": " << amount << ", uusi saldo: " << saldo << endl;
    return saldo;
}

double Luottotili::withdraw(double amount)
{
    if (amount < 0 || saldo - amount < luottoRaja)
    {
        cout << "Virhe: Nostoyritys epaonnistui luottotililta " << omistaja
             << ", summa: " << amount << ", saldo: " << saldo
             << ", luottoraja: " << luottoRaja << endl;
        return -1;
    }
    saldo -= amount;
    cout << "Luoton nosto tililta " << omistaja << ": " << amount << ", uusi saldo: " << saldo << endl;
    return saldo;
}


Asiakas::Asiakas(string nimi, double luottoraja): name(nimi), kayttotili(nimi), luottotili(nimi, luottoraja)
{
    cout << "Asiakas luotu: " << nimi << ", luottoraja: " << luottoraja << endl;
}

string Asiakas::getNimi()
{
    return name;
}

double Asiakas::getTilisaldo()
{
    double saldo = kayttotili.getBalance();
    cout << "Asiakkaan " << name << " tilisaldo: " << saldo << endl;
    return saldo;
}

double Asiakas::getLuottosaldo()
{
    double saldo = luottotili.getBalance();
    cout << "Asiakkaan " << name << " luottosaldo: " << saldo << endl;
    return saldo;
}

double Asiakas::tiliTalletus(double summa)
{
    cout << "Asiakas " << name << " tallettaa tilille: " << summa << endl;
    return kayttotili.deposit(summa);
}

double Asiakas::tiliNosto(double summa)
{
    cout << "Asiakas " << name << " nostaa tililta: " << summa << endl;
    return kayttotili.withdraw(summa);
}

double Asiakas::luotonMaksu(double summa)
{
    cout << "Asiakas " << name << " maksaa luottoa: " << summa << endl;
    return luottotili.deposit(summa);
}

double Asiakas::luotonNosto(double summa)
{
    cout << "Asiakas " << name << " nostaa luottoa: " << summa << endl;
    return luottotili.withdraw(summa);
}


Pankki::Pankki(): a("Alice", 2000), b("Bob", 2000), c("Charlie", 2000)
{
    cout << "Pankki luotu kolmella asiakkaalla: Alice, Bob, Charlie, luottoraja: 2000" << endl;
}

double Pankki::getVarat()
{
    double tilienSaldot = a.getTilisaldo() + b.getTilisaldo() + c.getTilisaldo();
    double luottovelat = -(a.getLuottosaldo() + b.getLuottosaldo() + c.getLuottosaldo());
    double varat = tilienSaldot - luottovelat;

    cout << "Pankin varat laskettiin: " << varat
         << " (tilien saldot: " << tilienSaldot
         << ", luottovelat: " << luottovelat << ")" << endl;
    return varat;
}

double Pankki::tiliTalletus(string nimi, double summa)
{
    cout << "Pankki: Talletus asiakkaalle " << nimi << ", summa: " << summa << endl;
    if (nimi == "Alice")
    {
        return a.tiliTalletus(summa);
    }
    else if (nimi == "Bob")
    {
        return b.tiliTalletus(summa);
    }
    else if (nimi == "Charlie")
    {
        return c.tiliTalletus(summa);
    }
    else
    {
        cout << "Virhe: Asiakasta " << nimi << " ei loytynyt!" << endl;
        return -1;
    }
}

double Pankki::tiliNosto(string nimi, double summa)
{
    cout << "Pankki: Nosto asiakkaalle " << nimi << ", summa: " << summa << endl;
    if (nimi == "Alice")
    {
        return a.tiliNosto(summa);
    }
    else if (nimi == "Bob")
    {
        return b.tiliNosto(summa);
    }
    else if (nimi == "Charlie")
    {
        return c.tiliNosto(summa);
    }
    else
    {
        cout << "Virhe: Asiakasta " << nimi << " ei loytynyt!" << endl;
        return -1;
    }
}

double Pankki::luotonMaksu(string nimi, double summa)
{
    cout << "Pankki: Luoton maksu asiakkaalle " << nimi << ", summa: " << summa << endl;
    if (nimi == "Alice")
    {
        return a.luotonMaksu(summa);
    }
    else if (nimi == "Bob")
    {
        return b.luotonMaksu(summa);
    }
    else if (nimi == "Charlie")
    {
        return c.luotonMaksu(summa);
    }
    else
    {
        cout << "Virhe: Asiakasta " << nimi << " ei loytynyt!" << endl;
        return -1;
    }
}

double Pankki::luotonNosto(string nimi, double summa)
{
    cout << "Pankki: Luoton nosto asiakkaalle " << nimi << ", summa: " << summa << endl;
    if (nimi == "Alice")
    {
        return a.luotonNosto(summa);
    }
    else if (nimi == "Bob")
    {
        return b.luotonNosto(summa);
    }
    else if (nimi == "Charlie")
    {
        return c.luotonNosto(summa);
    }
    else
    {
        cout << "Virhe: Asiakasta " << nimi << " ei loytynyt!" << endl;
        return -1;
    }
}

