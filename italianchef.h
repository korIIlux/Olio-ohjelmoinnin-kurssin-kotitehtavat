#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H
#include <iostream>
#include <string>
#include "chef.h"

class ItalianChef: private Chef
{
    public:
        ItalianChef(string);
        ~ItalianChef();
        bool askSecret(string, int, int);
    private:
        string password ="pizza";
        int flour;
        int water;
        int makepizza(int,int);

};

#endif // ITALIANCHEF_H
