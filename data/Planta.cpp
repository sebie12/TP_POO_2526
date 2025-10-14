//
// Created by sebie on 07/10/2025.
//

#include "Planta.h"

#include <memory>

#include "Plantas/Cacto.h"
#include "Plantas/Erva.h"
#include "Plantas/Roseira.h"

Planta::Planta() : lastInstanceNoWater(-1), lastInstanceNoNutri(-1), lastInstanceExpansion(-1), agua(0), nutrientes(0){
}

std::unique_ptr<Planta> Planta::createPlant(const char type) {
    switch (type) {
        case 'c':
            return std::make_unique<Cacto>();
        case 'e':
            return std::make_unique<Erva>();
        case 'r':
            return std::make_unique<Roseira>();
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
