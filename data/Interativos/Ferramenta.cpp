//
// Created by sebie on 08/10/2025.
//

#include "Ferramenta.h"

#include "Ferramentas/Adubo.h"
#include "Ferramentas/FerramentaZ.h"
#include "Ferramentas/Regador.h"
#include "Ferramentas/TesouraDePoda.h"

Ferramenta::Ferramenta(const char nome) : nome(nome), empty(false) {
    if (!initialized) {
        N_SERIE_REF = 1;
        initialized = true;
    }
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
std::shared_ptr<Ferramenta> Ferramenta::createFerramenta(const char tipo) {
    switch (tipo) {
        case ADUBO:
            return std::make_shared<Adubo>();
        case REGADOR:
            return std::make_shared<Regador>();
        case TESOURA:
            return std::make_shared<TesouraDePoda>();
        case FERRAMENTAZ:
            return std::make_shared<FerramentaZ>();
        default:
            return nullptr;
    }
}