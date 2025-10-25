//
// Created by sebie on 08/10/2025.
//

#include "Ferramenta.h"
Ferramenta::Ferramenta(const char id) : id(id), empty(false) {}
Ferramenta::~Ferramenta() = default;

char Ferramenta::getId() const {
    return id;
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
            return std::make_shared<Ferramenta>(ADUBO);
        case REGADOR:
            return std::make_shared<Ferramenta>(REGADOR);
        case TESOURA:
            return std::make_shared<Ferramenta>(TESOURA);
        case FERRAMENTAZ:
            return std::make_shared<Ferramenta>(FERRAMENTAZ);
        default:
            return nullptr;
    }
}