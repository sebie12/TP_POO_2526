//
// Created by sebie on 07/10/2025.
//

#ifndef TP_POO_2526_CACTO_H
#define TP_POO_2526_CACTO_H
#include "Settings.h"
#include "data/Planta.h"


class Cacto : public Planta{
    static const int absorcao_agua_percentagem = Settings::Cacto::absorcao_agua_percentagem ;
    static const int morre_agua_solo_maior = Settings::Cacto::morre_agua_solo_maior;
    static const int morre_agua_solo_instantes = Settings::Cacto::morre_agua_solo_instantes;
    static const int morre_nutrientes_solo_menor = Settings::Cacto::morre_nutrientes_solo_instantes;
    static const int morre_nutrientes_solo_instantes = Settings::Cacto::morre_nutrientes_solo_instantes;
    static const int multiplica_agua_maior = Settings::Cacto::multiplica_agua_maior;
    // ------------------
public:
    Cacto(): Planta(Settings::Cacto::absorcao_nutrientes, Settings::Cacto::multiplica_nutrientes_maior){}
};


#endif //TP_POO_2526_CACTO_H