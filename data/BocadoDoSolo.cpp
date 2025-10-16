//
// Created by sebie on 08/10/2025.
//

#include "BocadoDoSolo.h"

#include "Rand.h"

BocadoDoSolo::BocadoDoSolo(const int aguaMin, const int aguaMax, const int nutriMin, const int nutriMax)
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
            feedFromDeadPlant(temp);
            planta = nullptr; // Se a planta morrer
            return Jardim::DEAD;
        }
        if (planta->verificaExpansão(agua,nutrientes)) {
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
void BocadoDoSolo::feedFromDeadPlant(int nutrientes) {
    this->nutrientes += nutrientes;
}
char BocadoDoSolo::getIdFromPlant() const {
    if (planta!= nullptr)
        return planta->getId();
    return 'n';
}
bool BocadoDoSolo::newPlant(const char type) {
    if (planta != nullptr)
        return false;
    planta = Planta::createPlant(this,type);
    return true;
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
    return ' ';
}


