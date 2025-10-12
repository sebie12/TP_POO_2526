//
// Created by sebie on 07/10/2025.
//
#include <cmath>
#include "Cacto.h"
Cacto::Cacto() : Planta() {}

char Cacto::getId()const {
    return id;
}
int Cacto::pasaInstante(const int agua, const int nutrientes, const int instante) {
    if (verificaMorte(agua, nutrientes, instante)) {
        return nutrientes;
    }
    return -1; // Planta está viva
}
bool Cacto::verificaMorte(const int agua, const int nutrientes, const int instanteAtual) {
    // Verifica a agua
    if (agua >= morre_agua_solo_maior) {
        if (getLastInstanceNoWater() == -1)
            setLastIntanceNoWater(instanteAtual);
        else if (std::abs(instanteAtual - getLastInstanceNoWater()) >= morre_agua_solo_instantes)
            return true; // Morto por falta de agua
    } else {
        setLastIntanceNoWater(-1);
    }
    // verifica os nutrientes
    if (nutrientes <= morre_nutrientes_solo_menor) {
        if (getLastInstanceNoNutri() == -1)
            setLastIntanceNoNutri(instanteAtual);
        else if (std::abs(instanteAtual - getLastInstanceNoNutri()) >= morre_nutrientes_solo_menor)
            return true; // Morreu por falta de nutrientes
    } else {
        setLastIntanceNoNutri(-1);
    }
    return false; // Ainda vivo
}
bool Cacto::verificaExpansão(const int agua, const int nutrientes) {
    return agua >= multiplica_agua_maior && nutrientes >= multiplica_nutrientes_maior;
}


