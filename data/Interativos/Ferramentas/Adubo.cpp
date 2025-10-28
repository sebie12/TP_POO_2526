//
// Created by sebie on 07/10/2025.
//

#include "Adubo.h"

Adubo::Adubo() : Ferramenta(Ferramenta::ADUBO), nutrientesRestantes(capacidade) {}
Adubo::~Adubo() = default;

void Adubo::instante(BocadoDoSolo*posAtual) { // Esta função tem de ser redeclarada em cada ferramenta (usando override)
    if (nutrientesRestantes - dose >= 0) {
        nutrientesRestantes -= dose;
        posAtual->ganhaNutrientes(dose);
        return;
    }
    posAtual->ganhaNutrientes(nutrientesRestantes);
    nutrientesRestantes = 0;
    changeEmpty();
}