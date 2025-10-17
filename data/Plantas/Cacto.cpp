//
// Created by sebie on 07/10/2025.
//
#include <cmath>
#include "Cacto.h"

// EM PRINCIPIO ACABADO

Cacto::Cacto(BocadoDoSolo * sitio) : Planta(sitio,0,0){}
Cacto::Cacto(BocadoDoSolo * sitio, const int agua, const int nutrientes): Planta(sitio,agua,nutrientes){}
Cacto::~Cacto() = default;

char Cacto::getId()const {
    return id;
}
int Cacto::pasaInstante(const int instante) {
    //const array<int,2> temp = alimentar(); // Primeira posição a agua absorbida, segunda nutrientes absorbidos
    alimentar();
    if (verificaMorte(getAguaSolo(), getNutrientesSolo(), instante)) {
        return getNutrientes();
    }
    return -1; // Planta está viva
}
bool Cacto::verificaMorte(const int agua, const int nutrientes, const int instanteAtual) {
    // Verifica a agua
    if (agua >= morre_agua_solo_maior) {
        if (getLastInstanceNoWater() == -1)
            setLastIntanceNoWater(instanteAtual);
        else if (std::abs(instanteAtual - getLastInstanceNoWater()) >= morre_agua_solo_instantes){}
            return true; // Morto por excesso de agua
    } else {
        setLastIntanceNoWater(-1);
    }
    // verifica os nutrientes
    if (nutrientes <= morre_nutrientes_solo_menor) {
        if (getLastInstanceNoNutri() == -1)
            setLastIntanceNoNutri(instanteAtual);
        else if (std::abs(instanteAtual - getLastInstanceNoNutri()) >= morre_nutrientes_solo_menor) {
            return true; // Morreu por falta de nutrientes
        }

    } else {
        setLastIntanceNoNutri(-1);
    }
    return false; // Ainda vivo
}
bool Cacto::verificaExpansão(const int agua, const int nutrientes) {
    return getAgua() >= multiplica_agua_maior && getNutrientes() >= multiplica_nutrientes_maior;
}

std::array<int, 2> Cacto::alimentar() {
    const float temp = static_cast<float>(getAguaSolo()) * (static_cast<float>(100 - absorcao_agua_percentagem)/100);
    const std::array<int, 2> aguaEnutri =
        {tirarDoSoloAgua(static_cast<int>(temp)),
        tirarDoSoloNutrientes(absorcao_nutrientes)};
    return aguaEnutri;
}






