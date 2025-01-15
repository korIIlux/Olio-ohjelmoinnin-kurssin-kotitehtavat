#ifndef CHEF_H
#define CHEF_H

#include <string>
#include <iostream>

using namespace std;

class Chef
{
public:
    Chef(string name);
    ~Chef();

    string getName();
    void setName(string name);
    int makeSalad(int salad_maara);
    int makeSoup(int soup_maara);

private:
    string chefName;
};

#endif
