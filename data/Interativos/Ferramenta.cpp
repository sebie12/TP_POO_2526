//
// Created by sebie on 08/10/2025.
//

#include "Ferramenta.h"

#include "Ferramentas/Adubo.h"
#include "Ferramentas/FerramentaZ.h"
#include "Ferramentas/Regador.h"
#include "Ferramentas/TesouraDePoda.h"

int Ferramenta::N_SERIE_REF = 0;

Ferramenta::Ferramenta(const char nome) : nome(nome), empty(false) {
    id = N_SERIE_REF++;
}

Ferramenta::~Ferramenta() = default;

int Ferramenta::getId() const {
    return id;
}
char Ferramenta::getNome() const {
    return nome;
}

bool Ferramenta::getEmpty() const {
    return empty;
}
void Ferramenta::changeEmpty() {
    empty = !empty;
}
 Ferramenta* Ferramenta::createFerramenta(const char tipo) {
    switch (tipo) {
        case ADUBO:
            return new Adubo();
        case REGADOR:
            return new Regador();
        case TESOURA:
            return new TesouraDePoda();
        case FERRAMENTAZ:
            return new FerramentaZ();
        default:
            return nullptr;
    }
}