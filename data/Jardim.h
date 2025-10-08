//
// Created by sebie on 07/10/2025.
//

#ifndef TP_POO_2526_JARDIM_H
#define TP_POO_2526_JARDIM_H
#include "BocadoDoSolo.h"
#include "Settings.h"


class Jardim {
    static const int agua_min = Settings::Jardim::agua_min;
    static const int agua_max = Settings::Jardim::agua_max;
    static const int nutrientes_min = Settings::Jardim::nutrientes_min;
    static const int nutrientes_max = Settings::Jardim::nutrientes_max;

    // Matrix para os "bocados do solo"

    BocadoDoSolo espaço[10][10];

};


#endif //TP_POO_2526_JARDIM_H