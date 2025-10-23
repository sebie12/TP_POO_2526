//
// Created by sebie on 21/10/2025.
//

#include "RaizPlantaExotica.h"

RaizPlantaExotica::RaizPlantaExotica(BocadoDoSolo *solo) : Planta(solo, 0, 0){
}
char RaizPlantaExotica::getId() const {
    return '/';
}
std::array<int, 2> RaizPlantaExotica::alimentar() {
    const int agua = getAguaSolo() * static_cast<float> (Settings::PlantaExotica::per_absorcao_agua_raiz);
    const int nutrientes = getNutrientesSolo() * static_cast<float> (Settings::PlantaExotica::per_absorcao_nutrientes_raiz);

    return {tirarDoSoloAgua(agua), tirarDoSoloNutrientes(nutrientes)};
}

