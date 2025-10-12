//
// Created by sebie on 07/10/2025.
//

#include "Jardim.h"
Jardim::Jardim() {
    for (auto & i : area) {
        for (auto & j : i) {
            j = make_unique<BocadoDoSolo>(agua_min, agua_max, nutrientes_min, nutrientes_max, this);
        }
    }
}
void Jardim::iterate(int instante) const {
    for (const auto & i : area) {
        for (int j = 0; j < nLines; j++) {
            i[j]->iterate(instante);
        }
    }
}

