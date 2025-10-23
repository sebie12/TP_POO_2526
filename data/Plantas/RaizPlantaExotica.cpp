//
// Created by sebie on 21/10/2025.
//

#include "RaizPlantaExotica.h"

RaizPlantaExotica::RaizPlantaExotica(BocadoDoSolo *solo) : Planta(solo, 0, 0), soloPai(nullptr) {
}
char RaizPlantaExotica::getId() const {
    return '/';
}
std::array<int, 2> RaizPlantaExotica::alimentar() {
    const int agua = getAguaSolo() * static_cast<float> (Settings::PlantaExotica::per_absorcao_agua_raiz);
    const int nutrientes = getNutrientesSolo() * static_cast<float> (Settings::PlantaExotica::per_absorcao_nutrientes_raiz);

    return {tirarDoSoloAgua(agua), tirarDoSoloNutrientes(nutrientes)};
}
int RaizPlantaExotica::pasaInstante(const int instante) {
    if (verificaMorte(instante)) {
        return getNutrientes();
    }
    const auto temp = alimentar();
    // Envia a agua e nutrientes para a planta exotica pai
    if (soloPai != nullptr && soloPai->hasPlant()) {
        soloPai->feedPlanta(temp[0], temp[1]);
    }
    return -1;
}
bool RaizPlantaExotica::verificaMorte(int nInstantes) {
    return getAgua()<10 && getNutrientes()<10;
}
bool RaizPlantaExotica::verificaExpansao(int agua, int nutrientes, int instanteAtual) {
    return false;
}
void RaizPlantaExotica::setSoloPai(BocadoDoSolo *pai) {
    soloPai = pai;
}


