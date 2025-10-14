//
// Created by sebie on 07/10/2025.
//

#ifndef TP_POO_2526_JARDIM_H
#define TP_POO_2526_JARDIM_H
#include <memory>

#include "BocadoDoSolo.h"
#include "Settings.h"


class Jardim {
    int nLines;
    int nCols;
    static constexpr int agua_min = Settings::Jardim::agua_min;
    static constexpr int agua_max = Settings::Jardim::agua_max;
    static constexpr int nutrientes_min = Settings::Jardim::nutrientes_min;
    static constexpr int nutrientes_max = Settings::Jardim::nutrientes_max;

    BocadoDoSolo ***area ;
    // Matrix para os "bocados do solo"
public:
    enum codeIt {
        EXPAND,
        DEAD,
        ALIVE,
        NONE
    };
    Jardim(int linhas, int colunas);
    ~Jardim();
    void iterate(int instante) const;
    void processaCambio(codeIt tipo, int linha, int col) const;

    void expand(int linha, int col) const;
};


#endif //TP_POO_2526_JARDIM_H