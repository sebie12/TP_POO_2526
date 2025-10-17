//
// Created by sebie on 07/10/2025.
//

#include "Erva.h"

Erva::Erva(BocadoDoSolo * sitio): Planta(sitio,0,0) {
    instanteNascimento = -1;
}
Erva::~Erva() = default;


int Erva::pasaInstante(const int instante) {
    if (verificaMorte(getAguaSolo(), getNutrientesSolo(), instante)) {
        return getNutrientes();
    }
    alimentar();
    return -1; // Planta está viva
}

bool Erva::verificaMorte(int agua, int nutrientes, const int instanteAtual) {
    if (instanteNascimento == -1) // está a -1 quando é criado
        instanteNascimento = instanteAtual; // Define o seu instante de nascimento
    return instanteAtual - instanteNascimento == 60; // se a diferença é igual 60 (se tem 60 instantes vivo) morre
}

bool Erva::verificaExpansão(int agua, int nutrientes) {
    
    return false;
}

char Erva::getId() const {
    return id;
}

std::array<int, 2> Erva::alimentar() {
    return {1 ,1};
}

