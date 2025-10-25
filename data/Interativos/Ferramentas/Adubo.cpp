//
// Created by sebie on 07/10/2025.
//

#include "Adubo.h"

Adubo::Adubo() : Ferramenta(Ferramenta::ADUBO), nutrientesRestantes(capacidade) {}
Adubo::~Adubo() = default;

int Adubo::instante() { // Esta função tem de ser redeclarada em cada ferramenta (usando override)
    if (nutrientesRestantes - dose >= 0) {
        nutrientesRestantes -= dose;
        return dose;
    }
    nutrientesRestantes = 0;
    changeEmpty();
    return 0;
}