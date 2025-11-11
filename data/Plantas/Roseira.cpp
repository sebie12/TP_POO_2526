//
// Created by sebie on 07/10/2025.
//

#include "Roseira.h"

#include <iostream>
Roseira::Roseira() : Planta(inicial_agua, inicial_nutrientes){}

char Roseira::getId() const {
    return id;
}
int Roseira::instante(const int aguaSolo, const int nutriSolo, int & outNutrientes) {
    constexpr auto tempAgua = absorcao_agua;
    constexpr auto tempNutrientes = absorcao_nutrientes;
    const auto aguaAbsorvida = std::min(tempAgua, aguaSolo);
    outNutrientes = std::min(tempNutrientes, nutriSolo);
    perderAgua(perda_agua);
    perderNutri(perda_nutrientes);
    return aguaAbsorvida;
}
int Roseira::getAguaNutriMorte(int & outNutrientes) const {
    outNutrientes = getNutrientes()/2;
    return getAgua()/2;
}

bool Roseira::verificaExpansao(int agua, int nutrientes, int instanteAtual) {
    return getNutrientes() > multiplica_nutrientes_maior;
}
int Roseira::verificaMorte(int aguaSolo, int nutriSolo, int instanteAtual, int & outNutrientes) {
    if (getAgua() <= morre_agua_menor || getNutrientes() <= morre_nutrientes_menor || getNutrientes() >= morre_nutrientes_maior) {
        return getAguaNutriMorte(outNutrientes); // Morreu
    }
    return -1; // Ainda vivo
}





