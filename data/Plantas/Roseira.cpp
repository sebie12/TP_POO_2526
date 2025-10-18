//
// Created by sebie on 07/10/2025.
//

#include "Roseira.h"
Roseira::Roseira(BocadoDoSolo *sitio) : Planta(sitio, inicial_agua, inicial_nutrientes){}

char Roseira::getId() const {
    return id;
}

int Roseira::pasaInstante(int instante) {

}
std::array<int, 2> Roseira::alimentar() {
    const std::array<int, 2> aguaEnutri =
    {tirarDoSoloAgua(absorcao_agua),
    tirarDoSoloNutrientes(absorcao_nutrientes)};
    return  aguaEnutri;
}

bool Roseira::verificaExpansao(int agua, int nutrientes, int instanteAtual) {
    if (getNutrientes() > multiplica_nutrientes_maior) {

    }
    return false;
}
bool Roseira::verificaMorte(int agua, int nutrientes, int nInstantes) {

}




