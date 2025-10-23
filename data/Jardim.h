//
// Created by sebie on 07/10/2025.
//

#ifndef TP_POO_2526_JARDIM_H
#define TP_POO_2526_JARDIM_H

#include <sstream>
#include "BocadoDoSolo.h"
#include "Settings.h"

class BocadoDoSolo;

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
        EXPAND = 0,
        DEAD = 1,
        ALIVE = 2,
        ROSEIRAVIZINHOS = 3,
        PLANTAEXOTICAEXPAND = 4,
        NONE = 5
    };
    Jardim(int linhas, int colunas);
    ~Jardim();
    void iterate(int instante) const;
    void processaCambio(int tipo, int linha, int col) const;
    void expand(int linha, int col) const;
    void expandPE(int linha, int col)const;
    std::string toString() const;
    void genRandPlants()const;
    std::string getDataFromBocado(int i, int j) const;
    bool hasFullViznhos(int linha, int col) const;
    std::array<int, 4> verificaLimites(int linha, int col) const;
    std::array<int, 4> verificaLimitesEsquinas(int linha, int col) const;
};


#endif //TP_POO_2526_JARDIM_H