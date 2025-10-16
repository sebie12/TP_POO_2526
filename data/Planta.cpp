//
// Created by sebie on 07/10/2025.
//

#include "Planta.h"

#include <memory>

#include "Plantas/Cacto.h"
#include "Plantas/Erva.h"
#include "Plantas/Roseira.h"
class Cacto;
class Erva;
Planta::Planta(BocadoDoSolo * sitio,const int agua, const int nutrientes) : lastInstanceNoWater(-1), lastInstanceNoNutri(-1), lastInstanceExpansion(-1), aguaAtual(agua), nutriAtual(nutrientes), solo(sitio){
}

std::unique_ptr<Planta> Planta::createPlant(BocadoDoSolo * sitio, const char type) {
    switch (type) {
        case 'c':
            return std::make_unique<Cacto>(sitio);
        case 'e':
            return std::make_unique<Erva>(sitio);
        default:
            return nullptr;
    }
}

int Planta::tirarAgua(const int agua) {
    const int temp = solo->perdeAgua(agua);
    aguaAtual += temp;
    return temp;
}
int Planta::tirarNutrientes(const int nutrientes) {
    const int temp = solo->perdeNutrientes(nutrientes);
    nutriAtual += temp;
    return temp;
}

int Planta::getAguaSolo() const {
    return solo->getAgua();
}
int Planta::getNutrientesSolo() const {
    return solo->getNutrientes();
}


int Planta::getAgua() const {
    return aguaAtual;
}
int Planta::getNutrientes() const {
    return nutriAtual;
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

