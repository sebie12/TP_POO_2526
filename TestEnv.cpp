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
    auto * b1 = new BocadoDoSolo(agua_min, agua_max, nutrientes_min, nutrientes_max);
    auto * b2 = new BocadoDoSolo(agua_min, agua_max, nutrientes_min, nutrientes_max);

    b1->newPlant(Planta::plantTypes::CACTO);
    b2->newPlant(Planta::plantTypes::CACTO);
    for (int i = 1; i < 3; i++) {
        b1->iterate(i);
        b2->iterate(i);
    }
    cout << "Antes:" << endl;
    cout << b1->toString() << endl << endl << b2->toString();

    *b1 >> b2;
    cout << "Despues:" << endl;
    cout << b1->toString() << endl << endl << b2->toString();

    delete b1;
    delete b2;
    return 0;
}
