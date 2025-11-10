//
// Created by sebie on 07/10/2025.
//
#include <cmath>
#include "Cacto.h"

// EM PRINCIPIO ACABADO

Cacto::Cacto() : Planta(0,0), expanded(false){}
Cacto::Cacto(const int agua, const int nutrientes): Planta(agua,nutrientes), expanded(false){}
Cacto::~Cacto() = default;

char Cacto::getId()const {
    return id;
}

int Cacto::getAguaNutriMorte(int & outNutrientes) const {
    outNutrientes = getNutrientes();
    return 0; // Morto por excesso de agua
}


int Cacto::verificaMorte(const int aguaSolo,const int nutriSolo, const int instanteAtual, int & outNutrientes) {
    // Verifica a agua
    if (aguaSolo >= morre_agua_solo_maior) {
        if (getLastInstanceNoWater() == -1)
            setLastIntanceNoWater(instanteAtual);
        else if (std::abs(instanteAtual - getLastInstanceNoWater()) >= morre_agua_solo_instantes) {
            return getAguaNutriMorte(outNutrientes);; // Morto por excesso de agua
        }
    } else {
        setLastIntanceNoWater(-1);
    }
    // verifica os nutrientes
    if (nutriSolo <= morre_nutrientes_solo_menor) {
        if (getLastInstanceNoNutri() == -1)
            setLastIntanceNoNutri(instanteAtual);
        else if (std::abs(instanteAtual - getLastInstanceNoNutri()) >= morre_nutrientes_solo_menor) {
            return getAguaNutriMorte(outNutrientes); // Morreu por falta de nutrientes
        }
    } else {
        setLastIntanceNoNutri(-1);
    }
    return -1; // Ainda vivo
}

bool Cacto::verificaExpansao(int agua, int nutrientes, int instanteAtual) {
    if (getAgua() >= multiplica_agua_maior && getNutrientes() >= multiplica_nutrientes_maior && !expanded) {
        expanded=!expanded;
        return true;
    }
    return false;
}

int Cacto::alimentar(const int aguaSolo, int nutriSolo, int & outNutrientes) {
    const float temp = static_cast<float>(aguaSolo) * (static_cast<float>(100 - absorcao_agua_percentagem)/100);
    outNutrientes = absorcao_nutrientes;
    return static_cast<int>(temp);

}








