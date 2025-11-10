//
// Created by sebie on 07/10/2025.
//

#include <memory>
#include "data/Planta.h"
#include "Plantas/Cacto.h"
#include "Plantas/Erva.h"
#include "Plantas/Roseira.h"
#include "Plantas/PlantaExotica.h"

class Cacto;
class Erva;

Planta::Planta(const int agua, const int nutrientes) : lastInstanceNoWater(-1), lastInstanceNoNutri(-1), aguaAtual(agua), nutriAtual(nutrientes){
}

std::shared_ptr<Planta> Planta::createPlant( const char type) {
    switch (type) {
        case Planta::CACTO:
            return std::make_shared<Cacto>();
        case Planta::ERVA:
            return std::make_shared<Erva>();
        case Planta::ROSEIRA:
            return std::make_shared<Roseira>();
        case Planta::PLANTAEXOTICA:
            return std::make_shared<PlantaExotica>();
        default:
            return nullptr;
    }
}

int Planta::addAgua(const int agua) {
    if (agua<0)
        return 0;
    aguaAtual+=agua;
    return agua;
}
int Planta::addNutrientes(const int nutrientes ) {
    if (nutrientes<0)
        return 0;
    nutriAtual+=nutrientes;
    return nutrientes;
}

int Planta::perderAgua(const int agua) {
    if (agua<0)
        return 0;
    aguaAtual -= agua;
    return agua;
}

int Planta::perderNutri(const int nutri) {
    if (nutri<0)
        return 0;
    nutriAtual -= nutri;
    return nutri;
}

void Planta::setAgua(const int agua) {
    aguaAtual = agua;
}

void Planta::setNutri(const int nutri) {
    nutriAtual = nutri;
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
std::string Planta::toString() const {
    std::ostringstream oss;
    oss << "Agua Absorbida: " << aguaAtual<< " Nutrientes absorbidos: " << nutriAtual << "\n";
    return oss.str();
}



