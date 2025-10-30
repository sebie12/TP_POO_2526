//
// Created by sebie on 07/10/2025.
//
#include <cmath>
#include "Cacto.h"

// EM PRINCIPIO ACABADO

Cacto::Cacto(BocadoDoSolo * sitio) : Planta(sitio,0,0), expanded(false){}
Cacto::Cacto(BocadoDoSolo * sitio, const int agua, const int nutrientes): Planta(sitio,agua,nutrientes), expanded(false){}
Cacto::~Cacto() = default;

char Cacto::getId()const {
    return id;
}
int Cacto::pasaInstante(const int instante) {
    return -1; // Planta está viva
}
bool Cacto::verificaMorte(const int instanteAtual) {

    return false;
}

bool Cacto::verificaExpansao(int agua, int nutrientes, int instanteAtual) {

    return false;
}
void Cacto::alimentar() {

}






