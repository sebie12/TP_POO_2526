//
// Created by sebie on 07/10/2025.
//

#include "Roseira.h"
Roseira::Roseira(BocadoDoSolo *sitio) : Planta(sitio, inicial_agua, inicial_nutrientes){}

char Roseira::getId() const {
    return id;
}

int Roseira::pasaInstante(const int instante) {
    alimentar();
    if (verificaMorte(instante)) {
        return -1;
    }
    return 0;
}
std::array<int, 2> Roseira::alimentar() {
    const std::array<int, 2> aguaEnutri =
    {tirarDoSoloAgua(absorcao_agua),
    tirarDoSoloNutrientes(absorcao_nutrientes)};
    return  aguaEnutri;
}

bool Roseira::verificaExpansao(int agua, int nutrientes, int instanteAtual) {
    return getNutrientes() > multiplica_nutrientes_maior;
}
bool Roseira::verificaMorte(int nInstantes) {
    if (getAgua() <= morre_agua_menor || getNutrientes() <= morre_nutrientes_menor || getNutrientes() >= morre_nutrientes_menor) {
        return true;
    }
    return false;
}





