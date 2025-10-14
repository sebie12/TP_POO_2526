//
// Created by sebie on 07/10/2025.
//

#include "Jardim.h"

Jardim::Jardim(const int linhas, const int colunas) {
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
void Jardim::processaCambio(const codeIt tipo, const int linha, const int col) const {
    switch (tipo) {
        case Jardim::EXPAND:
            expand(linha, col);
        default: ;
    }
}

void Jardim::expand(const int linha, const int col) const {
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

    // As direções ficam a 0 quando está a fazer a verificação pq ...
    // assim ele vai-se verificar assim proprio e (em princípio) sempre vai haver uma planta, ou seja, não cria nada.

    for (const int i : directionsHorizontal) {
        const int vizinho = linha + i;
        if (area[vizinho][col]->newPlant(tipo)) // Se a planta não for criada continua (retorna false nessa situação)
            return;
    }

    for (const int i : directionsVertical) {
        const int vizinho = col + i;
        if (area[linha][vizinho]->newPlant(tipo))
            return;
    }
}


