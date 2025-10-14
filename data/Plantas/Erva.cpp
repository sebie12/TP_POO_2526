//
// Created by sebie on 07/10/2025.
//

#include "Erva.h"

Erva::Erva(): Planta(inicial_agua, inicial_nutrientes), instanteNascimento(-1){}

int Erva::pasaInstante(const int agua, const int nutrientes, const int instante) {
    if (verificaMorte(agua, nutrientes, instante)) {
        return getNutrientes();
    }
    alimentar(agua, nutrientes);
    return -1; // Planta está viva
}

bool Erva::verificaMorte(int agua, int nutrientes, const int instanteAtual) {
    if (instanteNascimento == -1) // está a -1 quando é criado
        instanteNascimento = instanteAtual; // Define o seu instante de nascimento
    return instanteAtual - instanteNascimento == 60; // se a diferença é igual 60 (se tem 60 instantes vivo) morre
}

bool Erva::verificaExpansão(int agua, int nutrientes) {

}

char Erva::getId() const {

}
