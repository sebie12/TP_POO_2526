//
// Created by sebie on 07/10/2025.
//

#include "Roseira.h"
Roseira::Roseira() : Planta(inicial_agua, inicial_nutrientes){}

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
void Roseira::alimentar() {
    tirarDoSoloAgua(absorcao_agua);
    tirarDoSoloNutrientes(absorcao_nutrientes);
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





