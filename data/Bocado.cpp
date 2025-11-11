//
// Created by sebie on 08/10/2025.
//

#include "Bocado.h"
#include "sstream"
#include "Rand.h"

#include <iostream>

Bocado::Bocado( const int aguaMin, const int aguaMax, const int nutriMin, const int nutriMax)
: planta(nullptr), jardineiro(nullptr)
{
    agua = Rand::generate(aguaMin,aguaMax) ;
    nutrientes = Rand::generate(nutriMin,nutriMax);
}
Bocado::~Bocado() = default;

int Bocado::iterate(const int instante) {
    int returnValue = Jardim::NONE;
    if (planta != nullptr) {
        if (jardineiro != nullptr) {
            jardineiro->usaFerramenta();
        }
        else if (ferramenta != nullptr) {
            if (ferramenta->getEmpty()) {

            }
        }
        int tempNutri = 0;
        int tempAgua = planta->verificaMorte(getAgua(), getNutrientes(), instante, tempNutri);
        if (tempAgua != -1) {
            std::cout << "Morreu " << planta->getId() << std::endl;
            killPlanta(tempAgua, tempNutri);// Se a planta morrer
            return Jardim::DEAD;
        }
        // Alimenta a planta
        tempAgua = planta->instante(getAgua(), getNutrientes(), tempNutri);
        perdeAgua(planta->addAgua(tempAgua));
        perdeNutrientes(planta->addNutrientes(tempNutri));

        if (planta->verificaExpansao(agua, nutrientes, instante)) {
            returnValue = Jardim::EXPAND;
        }
        if (planta->getId() == Planta::PLANTAEXOTICA) {
            std::cout << "PE wants to expand!" << std::endl;
            returnValue = Jardim::PLANTAEXOTICAEXPAND;
        }
    }
    return returnValue;
}
int Bocado::perdeAgua(const int unidades) {
    // Verifica se vai subtrair até ficar menor a 0 (não devia mas ok)
    const auto valor = agua - unidades < 0 ? agua : agua - unidades;
    if (agua > 0)
        agua -= valor;
    return valor;
}

int Bocado::perdeNutrientes(const int unidades) {
    // Verifica se vai subtrair até ficar menor a 0
    const auto valor = nutrientes - unidades <= 0 ? nutrientes : nutrientes - unidades;
    if (nutrientes > 0)
        nutrientes = valor;
    return valor;
}

int Bocado::ganhaAgua(const int unidades) {
    agua += unidades;
    return agua;
}

int Bocado::ganhaNutrientes(const int unidades) {
    nutrientes += unidades;
    return nutrientes;
}

int Bocado::getAgua() const {
    return agua;
}

int Bocado::getNutrientes() const {
    return nutrientes;
}

char Bocado::getIdForPrint() const {
    if (jardineiro!=nullptr) {
        return 'j';
    }
    if (planta != nullptr) {
        return getIdFromPlant();
    }
    if(ferramenta != nullptr) {
        return ferramenta->getNome();
    }
    return ' ';
}

std::string Bocado::toString() const {
    std::ostringstream oss;
    oss << "Agua: " << agua << " Nutrientes: " << nutrientes << "\n";
    oss << "Planta: " << (planta != nullptr ? getIdFromPlant() : 'N') << "\n";
    oss << planta->toString() << "\n";
    oss << "Jardineiro: " << (jardineiro != nullptr ? 'Y' : 'N') << "\n";
    oss << "Ferramenta: " << (ferramenta != nullptr ? 'Y' : 'N') << "\n";

    return oss.str();
}

// ----------------- Plant Logic -----------------------------

char Bocado::getIdFromPlant() const {
    if (planta!= nullptr) {
        return planta->getId();
    }
    return ' ';
}
bool Bocado::newPlant(const std::shared_ptr<Planta>& newPlanta) {
    if (planta != nullptr)
        return false;
    planta = newPlanta;
    return true;
}

bool Bocado::hasPlant() const {
    return planta != nullptr;
}

void Bocado::feedPlanta(const int novaAgua, const int novosNutrientes) const {
    if (planta == nullptr)
        return;
    planta->addAgua(novaAgua);
    planta->addNutrientes(novosNutrientes);
}

Bocado *Bocado::operator>>(const Bocado *outro) {
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

void Bocado::killPlanta(const int aguaRetirada, const int nutrientesRetirados) {
    ganhaAgua(aguaRetirada);
    ganhaNutrientes(nutrientesRetirados);
    planta = nullptr;
    std::cout << "muerta"<< std::endl;
}

int Bocado::getAguaNutriMorte(int &outNutrientes) const {
    return planta->getAguaNutriMorte(outNutrientes);
}

//  ------------- Ferramenta Logic -----------------------------

void Bocado::newFerramenta(const char tipo) {
    ferramenta = Ferramenta::createFerramenta(tipo);
}
std::shared_ptr<Ferramenta> Bocado::removeFerramenta() {
    const auto temp = ferramenta;
    ferramenta = nullptr;
    return temp;
}






