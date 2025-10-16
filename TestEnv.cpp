//
// Created by sebie on 16/10/2025.
//

#include "iostream"
#include "data/Jardim.h"

using namespace std;

int main() {
    cout << "VA A COMEZAR QUEEEEE" << endl;
    const Jardim a(5,5);
    a.genRandPlants();
    cout << a.toString();
    cout << a.getDataFromBocado(0,0);
    a.iterate(1);
    a.iterate(2);
    a.iterate(3);
    a.iterate(4);
    cout << a.getDataFromBocado(0,0);
    cout << a.toString();
    return 0;
}
