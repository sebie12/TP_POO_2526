//
// Created by sebie on 07/10/2025.
//

#include "Jardineiro.h"

Jardineiro::Jardineiro(): posAtual(nullptr), ferrEquipada(-1){}
Jardineiro::~Jardineiro() = default;

void Jardineiro::newPosicao(BocadoDoSolo *posNova) {
    posAtual = posNova;
}
void Jardineiro::equipaFerramenta(const int id) {
    ferrEquipada = buscaFerramenta(id); // Atualiza o indice da ferramenta equipada
}
int Jardineiro::buscaFerramenta(const int id) const { // Busca o Indice da ferramente que tem o id igual ao argumento
    for (int i = 0; i < ferr.size(); i++) {
        if (ferr[i]->getId() == id) {
            return i;
        }
    }
    return -1;
}
void Jardineiro::pegaFerramenta(const std::shared_ptr<Ferramenta>& novaFerramenta) {
    ferr.push_back(novaFerramenta);
}
void Jardineiro::descartaFerramenta() {
    if (ferrEquipada != -1) {
        ferr.erase(ferr.begin() + ferrEquipada);
        ferrEquipada = -1;
    }
}
void Jardineiro::usaFerramenta(){
    if (ferrEquipada == -1) {
        return;
    }
    if (ferr[ferrEquipada]->getEmpty()) {
        descartaFerramenta();
    }
    ferr[ferrEquipada]->instante(posAtual); // Aplica o efeito da ferramenta na posição atual do jardineiro
}


