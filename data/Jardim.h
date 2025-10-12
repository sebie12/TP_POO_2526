//
// Created by sebie on 07/10/2025.
//

#ifndef TP_POO_2526_JARDIM_H
#define TP_POO_2526_JARDIM_H
#include <memory>

#include "BocadoDoSolo.h"
#include "Settings.h"


class Jardim {
    static constexpr int nLines = 5;
    static constexpr int nRows = 10;
    static constexpr int agua_min = Settings::Jardim::agua_min;
    static constexpr int agua_max = Settings::Jardim::agua_max;
    static constexpr int nutrientes_min = Settings::Jardim::nutrientes_min;
    static constexpr int nutrientes_max = Settings::Jardim::nutrientes_max;

    unique_ptr<BocadoDoSolo> area[nLines][nRows] = {};
    // Matrix para os "bocados do solo"
public:
    Jardim();
    void iterate(int instante) const;

};


#endif //TP_POO_2526_JARDIM_H