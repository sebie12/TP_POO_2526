//
// Created by sebie on 07/10/2025.
//

#include "PlantaExotica.h"

#include <iostream>

PlantaExotica::PlantaExotica(BocadoDoSolo *sitio) : Planta(sitio, 0, 0), nRaizes(0){

}
PlantaExotica::~PlantaExotica() = default;



bool PlantaExotica::verificaExpansao(int agua, int nutrientes, int instanteAtual) {
    return false;
}

int PlantaExotica::pasaInstante(const int instante) {
    if (verificaMorte(instante)) {
        return getNutrientes();
    }
    return -1;
}

bool PlantaExotica::verificaMorte(const int instanteAtual) {
    if (instanteAtual == 5 && nRaizes < 3) {
        return true;
    }
    return false;
}

char PlantaExotica::getId() const {
    return id;
}


std::array<int, 2> PlantaExotica::alimentar() {
    return {0,0};
}

void PlantaExotica::addRaiz() {
    nRaizes++;
}
