//
// Created by sebie on 07/10/2025.
//

#include "Erva.h"

#include <iostream>

Erva::Erva(): Planta(inicial_agua,inicial_nutrientes) {
    instanteNascimento = -1;
    ultimaExpansao = 0;
}
Erva::~Erva() = default;

int Erva::getAguaNutriMorte(int & outNutrientes) const {
    outNutrientes = 0;
    return 0; // Morre sem nada
}

int Erva::verificaMorte(int aguaSolo, int nutriSolo, const int instanteAtual, int &outNutrientes) {
    if (instanteNascimento == -1) // está a -1 quando é criado
        instanteNascimento = instanteAtual; // Define o seu instante de nascimento
    if (instanteAtual - instanteNascimento == morre_instantes) {
        return getAguaNutriMorte(outNutrientes);; // Morre por idade
    }
    return  -1;
}

bool Erva::verificaExpansao(int agua, int nutrientes, const int instanteAtual) {
    if (getNutrientes() > multiplica_nutrientes_maior && (instanteAtual - ultimaExpansao) >= multiplica_instantes) {
        ultimaExpansao = instanteAtual;
        return true;
    }
    return false;
}

char Erva::getId() const {
    return id;
}


int Erva::instante(int aguaSolo, int nutriSolo, int &outNutrientes) {
    outNutrientes = absorcao_nutrientes;
    return absorcao_agua;
}


