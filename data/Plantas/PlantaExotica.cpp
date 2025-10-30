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

    return -1;
}

bool PlantaExotica::verificaMorte(const int instanteAtual) {

    return false;
}

char PlantaExotica::getId() const {
    return id;
}


void PlantaExotica::alimentar() {
}
void PlantaExotica::addRaiz() {
    nRaizes++;
}
