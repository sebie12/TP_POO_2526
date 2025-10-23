//
// Created by sebie on 07/10/2025.
//

#include "PlantaExotica.h"

PlantaExotica::PlantaExotica(BocadoDoSolo *sitio) : Planta(sitio, 0, 0), nRaizes(0){

}
PlantaExotica::~PlantaExotica() = default;

void PlantaExotica::absorbeNasRaizes() {
    for (const auto& it : raizes) {
        auto temp = it->alimentar();
        addAgua(temp[0]);
        addNutrientes(temp[1]);
    }
}

bool PlantaExotica::verificaExpansao(int agua, int nutrientes, int instanteAtual) {
    return false;
}

int PlantaExotica::pasaInstante(int instante) {
    return 0;
}

bool PlantaExotica::verificaMorte(const int instanteAtual) {
    if (instanteAtual == 5 && nRaizes < 3) {
        return true;
    }
    return false;
}

char PlantaExotica::getId() const {
    return id;
}

void PlantaExotica::novaRaiz(std::shared_ptr<RaizPlantaExotica> novaRaiz) {
    raizes.emplace_back(novaRaiz);
    nRaizes++;
}

std::array<int, 2> PlantaExotica::alimentar() {
    return {0,0};
}
