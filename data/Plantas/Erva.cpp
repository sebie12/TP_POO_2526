//
// Created by sebie on 07/10/2025.
//

#include "Erva.h"

#include <iostream>

Erva::Erva(BocadoDoSolo * sitio): Planta(sitio,inicial_agua,inicial_nutrientes) {
    instanteNascimento = -1;
    ultimaExpansao = 0;
}
Erva::~Erva() = default;

int Erva::pasaInstante(const int instante) {
    if (verificaMorte(instante)) {
        return getNutrientes();
    }
    alimentar();
    return -1; // Planta está viva
}

bool Erva::verificaMorte(const int instanteAtual) {
    if (instanteNascimento == -1) // está a -1 quando é criado
        instanteNascimento = instanteAtual; // Define o seu instante de nascimento
    return instanteAtual - instanteNascimento == morre_instantes ; // se a diferença é igual 60 (se tem 60 instantes vivo) morre
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

std::array<int, 2> Erva::alimentar() {
    const auto tempAgua = tirarDoSoloAgua(absorcao_agua);
    const auto tempNutrientes = tirarDoSoloNutrientes(absorcao_nutrientes);
    return {addAgua(tempAgua) ,addNutrientes(tempNutrientes)};
}

