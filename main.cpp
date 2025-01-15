#include <iostream>

using namespace std;
#include "chef.h"
#include "italianchef.h"

int main()
{
    Chef chef_obj("Toni");
    chef_obj.makeSalad(15);
    chef_obj.makeSoup(9);

    ItalianChef ital_chef_obj("Mario");
    ital_chef_obj.askSecret("pizza", 10, 15);


}
