//
// Created by sebie on 07/10/2025.
//

#ifndef TP_POO_2526_ERVA_H
#define TP_POO_2526_ERVA_H
#include "Settings.h"
#include "Settings.h"
#include "Settings.h"
#include "data/Planta.h"


class Erva : public Planta{
    static constexpr char id = 'e';
    static const int inicial_agua = Settings::ErvaDaninha::inicial_agua ;
    static const int inicial_nutrientes = Settings::ErvaDaninha::inicial_nutrientes;
    static const int absorcao_agua = Settings::ErvaDaninha::absorcao_agua;
    static const int morre_instantes = Settings::ErvaDaninha::morre_instantes;
    static const int multiplica_instantes = Settings::ErvaDaninha::multiplica_instantes;
    static const int nova_nutrientes = Settings::ErvaDaninha::nova_nutrientes;
    static const int original_nutrientes = Settings::ErvaDaninha::original_nutrientes;
    // ------------------
public:
    Erva(): Planta(Settings::ErvaDaninha::absorcao_nutrientes, Settings::ErvaDaninha::multiplica_nutrientes_maior){}
};


#endif //TP_POO_2526_ERVA_H