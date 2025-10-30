//
// Created by sebie on 07/10/2025.
//

#include "Erva.h"

#include <iostream>

Erva::Erva(BocadoDoSolo * sitio): Planta(sitio,inicial_agua,inicial_nutrientes) {
    instanteNascimento = -1;
    ultimaExpansao = 0;
}
Erva::~Erva() = default;

int Erva::pasaInstante(const int instante) {
    return -1; // Planta está viva
}

bool Erva::verificaMorte(const int instanteAtual) {
    return false;
}

bool Erva::verificaExpansao(int agua, int nutrientes, const int instanteAtual) {

    return false;
}

char Erva::getId() const {
    return id;
}

void Erva::alimentar() {

}

