//
// Created by sebie on 08/10/2025.
//

#ifndef TP_POO_2526_REGADOR_H
#define TP_POO_2526_REGADOR_H
#include "Settings.h"
#include "data/Interativos/Ferramenta.h"


class Regador : public Ferramenta{
    static const int capacidade = Settings::Regador::capacidade ;
    static const int dose = Settings::Regador::dose;
};


#endif //TP_POO_2526_REGADOR_H