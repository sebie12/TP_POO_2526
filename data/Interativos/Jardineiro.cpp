//
// Created by sebie on 07/10/2025.
//

#include "Jardineiro.h"

Jardineiro::Jardineiro(): posAtual(nullptr), ferrEquipada(-1){}
Jardineiro::~Jardineiro() = default;

void Jardineiro::newPosicao(Bocado *posNova) {
    posAtual = posNova;
}
void Jardineiro::equipaFerramenta(const int id) {
    ferrEquipada = buscaFerramenta(id); // Atualiza o indice da ferramenta equipada
}
int Jardineiro::buscaFerramenta(const int id) const { // Busca o Indice da ferramente que tem o id igual ao argumento

}
void Jardineiro::pegaFerramenta(const std::shared_ptr<Ferramenta>& novaFerramenta) {

}
void Jardineiro::descartaFerramenta() {

}
void Jardineiro::usaFerramenta(){

}


