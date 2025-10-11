//
// Created by sebie on 07/10/2025.
//

#include "Jardim.h"
Jardim::Jardim() {
    for (int i = 0; i < nLines; i++) {
        for (int j = 0; j < nRows; j++) {
            area[i][j] = new BocadoDoSolo(agua_min, agua_max, nutrientes_min, nutrientes_max);
        }
    }
}
Jardim::~Jardim() {
    delete[][]area;
}

