//
// Created by sebie on 07/10/2025.
//

#include "Planta.h"

#include "Plantas/Cacto.h"
#include "Plantas/Erva.h"
#include "Plantas/Roseira.h"

Planta::Planta() : lastInstanceNoWater(-1), lastInstanceNoNutri(-1), lastInstanceExpansion(-1), agua(0), nutrientes(0){
}

Planta *Planta::createPlant(const plantTypes type) {
    switch (type) {
        case CACTO:
            return new Cacto();
        case ERVA:
            return new Erva();
        case ROSEIRA:
            return new Roseira();
        default:
            return nullptr;
    }
}
int Planta::getLastInstanceNoWater() const {
    return lastInstanceNoWater;
}
void Planta::setLastIntanceNoWater(const int n) {
    lastInstanceNoWater = n;
}
int Planta::getLastInstanceNoNutri() const {
    return lastInstanceNoNutri;
}
void Planta::setLastIntanceNoNutri(const int n) {
    lastInstanceNoNutri = n;
}
