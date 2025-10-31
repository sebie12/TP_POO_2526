//
// Created by sebie on 07/10/2025.
//
#include <iostream>
#include "Jardim.h"
#include "Rand.h"
#include "Plantas/PlantaExotica.h"
using namespace std;
Jardim::Jardim(const int linhas, const int colunas) {
    if (linhas > 26 || colunas > 26) {
        nLines = 10;nCols=10;
    }
    nLines = linhas;
    nCols = colunas;
    area = new BocadoDoSolo**[linhas];
    for (int i = 0 ; i < linhas; i++) {
        area[i] = new BocadoDoSolo*[colunas];
        for (int j = 0; j < colunas; j++) {
            area[i][j] = new BocadoDoSolo(agua_min, agua_max, nutrientes_min, nutrientes_max);
        }
    }

}
Jardim::~Jardim() {
    for (int i = 0; i < nLines; i++) {
        for (int j = 0; j < nCols; j++) {
            delete area[i][j];
        }
        delete[] area[i];
    }
    delete[] area;
}

void Jardim::iterate(const int instante) const {
    for (int i = 0; i < nLines; i++) {
        for (int j = 0; j < nCols; j++) {
            processaCambio(area[i][j]->iterate(instante), i, j);
        }
    }
}
void Jardim::processaCambio(const int tipo, const int linha, const int col) const {

}


void Jardim::expand(const int linha, const int col) const {
    // Procura um bocado vazio na vizinhança
}


bool Jardim::hasFullViznhos(const int linha, const int col) const {

    return true;
}
std::string Jardim::getDataFromBocado(const int i, const int j) const { // Esta a dar coisa mala
    if (area[i][j] == nullptr) {
        return "Empty";
    }
    return area[i][j]->toString();
}

string Jardim::toString() const {
    ostringstream oss;
    for (int i = 0; i < nLines; i++) {
        for (int j = 0; j < nCols; j++) {
            oss << area[i][j]->getIdForPrint() << ' ';
        }
        oss << endl;
    }
    return oss.str();
}
void Jardim::genRandPlants() const {
    for (int i = 0; i < nLines; i++) {
        for (int j = 0; j < nCols; j++) {
            switch (Rand::generate(0, 5)) {
                case 0:
                    area[i][j]->newPlant(Planta::plantTypes::CACTO);
                    break;
                case 1:
                    area[i][j]->newPlant(Planta::plantTypes::ERVA);
                    break;
                case 2:
                    area[i][j]->newPlant(Planta::plantTypes::ROSEIRA);
                case 3:
                    area[i][j]->newPlant(Planta::plantTypes::PLANTAEXOTICA);
                default:
                    break;
            }
        }
    }
}

Jardim &Jardim::operator=(const Jardim &outro) {
    // Para a copia
}









