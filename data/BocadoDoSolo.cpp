//
// Created by sebie on 08/10/2025.
//

#include "BocadoDoSolo.h"
#include "sstream"
#include "Rand.h"

#include <iostream>

BocadoDoSolo::BocadoDoSolo( const int aguaMin, const int aguaMax, const int nutriMin, const int nutriMax)
: planta(nullptr), jardineiro(nullptr), ferramenta(nullptr)
{
    agua = Rand::generate(aguaMin,aguaMax) ;
    nutrientes = Rand::generate(nutriMin,nutriMax);
}
BocadoDoSolo::~BocadoDoSolo() {
    delete planta;
    delete ferramenta;
    delete jardineiro;
};

int BocadoDoSolo::iterate(const int instante) {
    if (planta != nullptr) {
        if (jardineiro != nullptr) {
            jardineiro->usaFerramenta();
        }
        else if (ferramenta != nullptr) {
            if (ferramenta->getEmpty()) {

            }
        }
        const auto temp = planta->pasaInstante(instante);
        if (temp != -1) {
            killPlanta();// Se a planta morrer
            return Jardim::DEAD;
        }
        if (planta->getId() == Planta::ROSEIRA) {
            return Jardim::ROSEIRAVIZINHOS;
        }
        if (planta->verificaExpansao(agua, nutrientes, instante)) {
            return Jardim::EXPAND;
        }
        if (planta->getId() == Planta::PLANTAEXOTICA) {
            std::cout << "PE wants to expand!" << std::endl;
            return Jardim::PLANTAEXOTICAEXPAND;
        }
        return Jardim::ALIVE;
    }
    return Jardim::NONE;
}
int BocadoDoSolo::perdeAgua(const int unidades) {
    // Verifica se vai subtrair até ficar menor a 0 (não devia mas ok)
    const auto valor = agua - unidades < 0 ? agua : agua - unidades;
    if (agua > 0)
        agua -= valor;
    return valor;
}

int BocadoDoSolo::perdeNutrientes(const int unidades) {
    // Verifica se vai subtrair até ficar menor a 0
    const auto valor = nutrientes - unidades <= 0 ? nutrientes : nutrientes - unidades;
    if (nutrientes > 0)
        nutrientes = valor;
    return valor;
}

int BocadoDoSolo::ganhaAgua(const int unidades) {
    agua += unidades;
    return agua;
}

int BocadoDoSolo::ganhaNutrientes(const int unidades) {
    nutrientes += unidades;
    return nutrientes;
}

int BocadoDoSolo::getAgua() const {
    return agua;
}

int BocadoDoSolo::getNutrientes() const {
    return nutrientes;
}

char BocadoDoSolo::getIdForPrint() const {
    if (jardineiro!=nullptr) {
        return 'j';
    }
    if (planta != nullptr) {
        return getIdFromPlant();
    }
    if(ferramenta != nullptr) {
        return ferramenta->getId();
    }
    return ' ';
}

std::string BocadoDoSolo::toString() const {
    const std::string temp = planta != nullptr ? planta->toString(): " ";
    std::ostringstream oss;
    oss << "Agua: " << agua << " Nutrientes: " << nutrientes << "\n";
    oss << "Planta: " << (planta != nullptr ? getIdFromPlant() : 'N') << "\n";
    oss << temp  << "\n";
    oss << "Jardineiro: " << (jardineiro != nullptr ? 'Y' : 'N') << "\n";
    oss << "Ferramenta: " << (ferramenta != nullptr ? 'Y' : 'N') << "\n";

    return oss.str();
}

// ----------------- Plant Logic -----------------------------

void BocadoDoSolo::feedFromDeadPlant(const int aguaDaPlanta, const int nutriDaPlanta) {
}
char BocadoDoSolo::getIdFromPlant() const {
    if (planta!= nullptr)
        return planta->getId();
    return 'n';
}
bool BocadoDoSolo::newPlant(const char type) {
    if (planta == nullptr || type == Planta::ERVA) {
        planta = nullptr;
        planta = Planta::createPlant(this,type);
        return true;
    }
    return false;
}

bool BocadoDoSolo::hasPlant() const {
    return planta != nullptr;
}

void BocadoDoSolo::feedPlanta(const int novaAgua, const int novosNutrientes) const {

}

BocadoDoSolo *BocadoDoSolo::operator>>(const BocadoDoSolo *outro) {

    return this;
}

void BocadoDoSolo::killPlanta() {
    feedFromDeadPlant(planta->getAgua(), planta->getNutrientes());
    planta = nullptr;
}

//  ------------- Ferramenta Logic -----------------------------

void BocadoDoSolo::newFerramenta(const char tipo) {
    ferramenta = Ferramenta::createFerramenta(tipo);
}
Ferramenta * BocadoDoSolo::removeFerramenta() {
    const auto temp = ferramenta;
    ferramenta = nullptr;
    return temp;
}






