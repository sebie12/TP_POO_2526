//
// Created by sebie on 16/10/2025.
//

#include "iostream"
#include "data/Jardim.h"

using namespace std;

int main() {
    cout << "VA A COMEZAR QUEEEEE" << endl;
    static constexpr int agua_min = Settings::Jardim::agua_min;
    static constexpr int agua_max = Settings::Jardim::agua_max;
    static constexpr int nutrientes_min = Settings::Jardim::nutrientes_min;
    static constexpr int nutrientes_max = Settings::Jardim::nutrientes_max;
    Jardim j(10,10);
    int i = 0, num;
    j.genRandPlants();
    do {
        cout << j.toString();
        j.iterate(i++);
        cin >> num;
    }while (num == 0);




    return 0;
}
