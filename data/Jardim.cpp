//
// Created by sebie on 07/10/2025.
//
#include <iostream>
#include "Jardim.h"
#include "Rand.h"
using namespace std;
Jardim::Jardim(const int linhas, const int colunas) {
    if (linhas > 26 || colunas > 26)
        throw "Invalid size"; // Placeholder
    nLines = linhas;
    nCols = colunas;
    area = new BocadoDoSolo**[linhas];
    for (int i = 0 ; i < linhas; i++) {
        area[i] = new BocadoDoSolo*[colunas];
        for (int j = 0; j < colunas; j++) {
            area[i][j] = new BocadoDoSolo(this, agua_min, agua_max, nutrientes_min, nutrientes_max);
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
    if (tipo == Jardim::EXPAND)
            expand(linha, col);
    else if (tipo == Jardim::ROSEIRAVIZINHOS) {

    }
}

std::array<int, 4> Jardim::verificaLimites(const int linha, const int col) const {
    const char tipo = area[linha][col]->getIdFromPlant();
    int directionsHorizontal[] = {1,-1}; // 1 verifiica a pos inferior e -1 a posição superior na matriz
    int directionsVertical[] = {1,-1}; // 1 verifica uma posição à direita, -1 verifica uma posição à esquerda
    if (linha == 0)
        directionsHorizontal[1] = 0; // como estou no topo não consigo ver acima
    else if (linha == nLines - 1)
        directionsHorizontal[0] = 0; // como estou no fim não consigo ver abaixo
    if (col == 0)
        directionsVertical[1] = 0; // mesma logica
    else if (col == nCols - 1)
        directionsVertical[0] = 0;
    // = {{directionsHorizontal[0],directionsVertical[1]}, {directionsVertical[0], directionsVertical[1]}}
    array<int, 4> retValue=  {directionsHorizontal[0],directionsVertical[1], directionsVertical[0], directionsVertical[1]};
    return retValue;
}


void Jardim::expand(const int linha, const int col) const {
    const char tipo = area[linha][col]->getIdFromPlant();
    const auto directions = verificaLimites(linha, col); // left right up down

    for (int i = 0; i < 4; i++) {
        const int vizinho = i < 2 ? linha + directions[i] : col + directions[i];

        if (area[vizinho][col]->newPlant(tipo)) {
            // Se a planta não for criada continua (retorna false nessa situação)
            *area[linha][col]>>area[vizinho][col]; // Vai passar a metade da agua duma planta para a outra
            return;
        }
    }


    /*for (auto i : directions) {
        const int vizinho = linha + i;
        if (area[vizinho][col]->newPlant(tipo)) {
            // Se a planta não for criada continua (retorna false nessa situação)
            *area[linha][col]>>area[vizinho][col]; // Vai passar a metade da agua duma planta para a outra
            return;
        }
    }

    for (const int i : directionsVertical) {
        const int vizinho = col + i;
        if (area[linha][vizinho]->newPlant(tipo))
            return;
    }*/
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
            switch (Rand::generate(0, 3)) {
                case 0:
                    area[i][j]->newPlant(Planta::plantTypes::CACTO);
                    break;
                case 1:
                    area[i][j]->newPlant(Planta::plantTypes::ERVA);
                    break;
                default:
                    break;
            }
        }
    }
}

bool Jardim::hasFullViznhos(const int linha, const int coluna) {
    int directionsHorizontal[] = {1,-1}; // 1 verifiica a pos inferior e -1 a posição superior na matriz
    int directionsVertical[] = {1,-1}; // 1 verifica uma posição à direita, -1 verifica uma posição à esquerda
    if (linha == 0)
        directionsHorizontal[1] = 0; // como estou no topo não consigo ver acima
    else if (linha == nLines - 1)
        directionsHorizontal[0] = 0; // como estou no fim não consigo ver abaixo

    if (coluna == 0)
        directionsVertical[1] = 0; // mesma logica
    else if (coluna == nCols - 1)
        directionsVertical[0] = 0;

    for (const int i : directionsHorizontal) {
        const int vizinho = linha + i;
        if (area[vizinho][coluna]->newPlant(tipo)) {
            // Se a planta não for criada continua (retorna false nessa situação)
            *area[linha][coluna]>>area[vizinho][coluna]; // Vai passar a metade da agua duma planta para a outra
        }
    }

    for (const int i : directionsVertical) {
        const int vizinho = coluna + i;
        if (area[linha][vizinho]->newPlant(tipo))
            return;
    }
}





