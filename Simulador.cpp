//
// Created by sebie on 07/10/2025.
//

#include "Simulador.h"
Simulador::Simulador(const int n1, const int n2) : jardim(new Jardim(n1,n2)) {
    instante = 0;
}
Simulador::~Simulador() {
    delete jardim;
}


void Simulador::Run() {

}

void Simulador::readCommand(const std::string& comm) {

}

