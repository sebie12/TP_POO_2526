//
// Created by sebie on 07/10/2025.
//

#ifndef TP_POO_2526_ROSEIRA_H
#define TP_POO_2526_ROSEIRA_H
#include "Roseira.h"
#include "Settings.h"
#include "data/Planta.h"

class Roseira : public Planta{
    static const int inicial_agua = Settings::Roseira::inicial_agua;
    static const int inicial_nutrientes = Settings::Roseira::inicial_nutrientes;
    static const int perda_agua = Settings::Roseira::perda_agua;
    static const int perda_nutrientes = Settings::Roseira::perda_nutrientes;
    static const int absorcao_agua = Settings::Roseira::absorcao_agua;
    static const int morre_agua_menor = Settings::Roseira::morre_agua_menor;
    static const int morre_nutrientes_menor = Settings::Roseira::morre_nutrientes_menor;
    static const int morre_nutrientes_maior = Settings::Roseira::morre_nutrientes_maior;
    static const int nova_nutrientes = Settings::Roseira::nova_nutrientes;
    static const int nova_agua_percentagem = Settings::Roseira::inicial_agua;
    static const int original_nutrientes = Settings::Roseira::original_nutrientes;
    static const int original_agua_percentagem = Settings::Roseira::original_agua_percentagem;
    // ------------------
    Roseira(): Planta(Settings::Roseira::absorcao_nutrientes, Settings::Roseira::multiplica_nutrientes_maior){}
};


#endif //TP_POO_2526_ROSEIRA_H