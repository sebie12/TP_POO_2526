//
// Created by sebie on 07/10/2025.
//

#include "PlantaExotica.h"

#include <iostream>

PlantaExotica::PlantaExotica() : Planta(0, 0), nRaizes(0){

}
PlantaExotica::~PlantaExotica() = default;

bool PlantaExotica::verificaExpansao(int agua, int nutrientes, int instanteAtual) {
    return false;
}

int PlantaExotica::verificaMorte(int aguaSolo, int nutriSolo, int instanteAtual, int & outNutrientes) {
    return 0;
}

char PlantaExotica::getId() const {
    return id;
}

int PlantaExotica::alimentar(int aguaSolo, int nutriSolo, int & outNutrientes) {
    outNutrientes = 0;
    return 0;
}
int PlantaExotica::getAguaNutriMorte(int &outNutrientes) const {
    return 0;
}

void PlantaExotica::addRaiz() {
    nRaizes++;
}
