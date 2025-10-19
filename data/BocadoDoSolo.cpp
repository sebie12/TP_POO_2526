//
// Created by sebie on 08/10/2025.
//

#include "BocadoDoSolo.h"
#include "sstream"
#include "Rand.h"

#include <iostream>

BocadoDoSolo::BocadoDoSolo( const int aguaMin, const int aguaMax, const int nutriMin, const int nutriMax)
: planta(nullptr), jardineiro(nullptr)
{
    agua = Rand::generate(aguaMin,aguaMax) ;
    nutrientes = Rand::generate(nutriMin,nutriMax);
}
BocadoDoSolo::~BocadoDoSolo() = default;

int BocadoDoSolo::iterate(const int instante) {
    if (planta != nullptr) {
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
void BocadoDoSolo::feedFromDeadPlant(const int aguaDaPlanta, const int nutriDaPlanta) {
    if (planta->getId() == Planta::CACTO) {
        this->nutrientes += nutriDaPlanta;
    }
    else if (planta->getId() == Planta::ROSEIRA) {
        this->agua += aguaDaPlanta/2;
        this->nutrientes += nutriDaPlanta/2;
    }
}
char BocadoDoSolo::getIdFromPlant() const {
    if (planta!= nullptr)
        return planta->getId();
    return 'n';
}
bool BocadoDoSolo::newPlant(const char type) {
    if (planta != nullptr && type != Planta::plantTypes::ERVA)
        return false;
    planta = Planta::createPlant(this,type);
    return true;
}

bool BocadoDoSolo::hasPlant() const {
    return planta != nullptr;
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

    }else if (planta != nullptr) {
        return getIdFromPlant();
    }
    else if(ferramenta != nullptr) {
        return 'f';
    }
    return '+';
}

std::string BocadoDoSolo::toString() const {
    std::ostringstream oss;
    oss << "Agua: " << agua << " Nutrientes: " << nutrientes << "\n";
    oss << "Planta: " << (planta != nullptr ? getIdFromPlant() : 'N') << "\n";
    oss << planta->toString() << "\n";
    oss << "Jardineiro: " << (jardineiro != nullptr ? 'Y' : 'N') << "\n";
    oss << "Ferramenta: " << (ferramenta != nullptr ? 'Y' : 'N') << "\n";

    return oss.str();
}

BocadoDoSolo *BocadoDoSolo::operator>>(BocadoDoSolo *outro) {
    const int tempAgua = planta->getAgua() / 2;
    const int tempNutrientes = planta->getNutrientes() / 2;


    if (planta->getId() == Planta::CACTO) {
        planta->perderAgua(tempAgua);
        outro->planta->addAgua(tempAgua);

        planta->perderNutri(tempNutrientes);
        outro->planta->addNutrientes(tempNutrientes);
    }
    else if (planta->getId() == Planta::ROSEIRA) {
        planta->perderAgua(tempAgua);
        outro->planta->setAgua(tempAgua);

        planta->setNutri(Settings::Roseira::original_nutrientes);
        outro->planta->setNutri(Settings::Roseira::nova_nutrientes);
    }
    return this;
}

void BocadoDoSolo::killPlanta() {
    feedFromDeadPlant(planta->getAgua(), planta->getNutrientes());
    planta = nullptr;
}



