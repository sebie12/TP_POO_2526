//
// Created by sebie on 07/10/2025.
//
#include <iostream>
#include "Jardim.h"
#include "Rand.h"
#include "Plantas/PlantaExotica.h"
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
    if (tipo == Jardim::EXPAND)
            expand(linha, col);
    else if (tipo == Jardim::ROSEIRAVIZINHOS) {
        if (hasFullViznhos(linha, col))
            area[linha][col]->killPlanta();
    }
    else if (tipo == Jardim::PLANTAEXOTICAEXPAND) {
        cout << "Expanding PE at " << linha << "," << col << endl;
        expandPE(linha, col);
    }
}

std::array<int, 4> Jardim::verificaLimites(const int linha, const int col) const {
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
    const array<int, 4> retValue=  {directionsHorizontal[0],directionsHorizontal[1], directionsVertical[0], directionsVertical[1]};
    return retValue;
}
std::array<int, 4> Jardim::verificaLimitesEsquinas(int linha, int col) const {

}



void Jardim::expand(const int linha, const int col) const {
    const char tipo = area[linha][col]->getIdFromPlant();
    const auto directions = verificaLimites(linha, col); // left right up down

    for (int i = 0; i < 4; i++) {
        const int linhaNova = i < 2 ? linha + directions[i] : linha;
        const int colunaNova = i < 2 ? col : col + directions[i];
        if (area[linhaNova][colunaNova]->newPlant(tipo)) {
            // Se a planta não for criada continua (retorna false nessa situação)
            *area[linha][col]>>area[linhaNova][colunaNova]; // Vai passar a metade da agua duma planta para a outra
            return;
        }
    }

}
void Jardim::expandPE(const int linha, const int col) const {
    constexpr char tipo = Planta::RAIZPE;
    const auto directions = verificaLimites(linha, col); // left right up down

    const int random = Rand::generate(0, 3);

    const int linhaNova = random < 2 ? linha + directions[random] : linha;
    const int colunaNova = random < 2 ? col : col + directions[random];
    if (!area[linhaNova][colunaNova]->hasPlant()) {
        // Cria raiz
        //area[linhaNova][colunaNova]->newPlant(tipo);
        //area[linhaNova][colunaNova]
        //static_cast<PlantaExotica> (area[linha][col]).addRaiz();
    }
}

bool Jardim::hasFullViznhos(const int linha, const int col) const {
    const auto directions = verificaLimites(linha, col); // {down, up, right, left}

    for (int i = 0; i < 4; ++i) {
        // se não há vizinho nessa direção, não tem "full"
        if (directions[i] == 0) continue;

        const int linhaNova = i < 2 ? linha + directions[i] : linha;
        const int colunaNova = i < 2 ? col : col + directions[i];

        if (!area[linhaNova][colunaNova]->hasPlant()) return false;

        // corners: para vizinhos verticais (i < 2) usar right/left;
        // para vizinhos horizontais (i >= 2) usar down/up
        const int corner1 = (i < 2) ? directions[2] : directions[0];
        const int corner2 = (i < 2) ? directions[3] : directions[1];

        // se algum dos cantos está fora (offset == 0) não há "full"
        if (corner1 == 0 || corner2 == 0) continue;

        // verificar os dois cantos diagonais
        const int linhaCanto1 = i < 2 ? linhaNova : linha + corner1;
        const int colunaCanto1 = i < 2 ? col + corner1 : colunaNova;
        if (!area[linhaCanto1][colunaCanto1]->hasPlant()) return false;

        const int linhaCanto2 = i < 2 ? linhaNova : linha + corner2;
        const int colunaCanto2 = i < 2 ? col + corner2 : colunaNova;
        if (!area[linhaCanto2][colunaCanto2]->hasPlant()) return false;
    }

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
                /*case 3:
                    area[i][j]->newPlant(Planta::plantTypes::PLANTAEXOTICA);*/
                default:
                    break;
            }
        }
    }
}







