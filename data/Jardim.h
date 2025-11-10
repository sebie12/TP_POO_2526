//
// Created by sebie on 07/10/2025.
//

#ifndef TP_POO_2526_JARDIM_H
#define TP_POO_2526_JARDIM_H
#include "Bocado.h"
#include "Settings.h"

class Bocado;

class Jardim {
    static constexpr int agua_min = Settings::Jardim::agua_min;
    static constexpr int agua_max = Settings::Jardim::agua_max;
    static constexpr int nutrientes_min = Settings::Jardim::nutrientes_min;
    static constexpr int nutrientes_max = Settings::Jardim::nutrientes_max;

    // Matrix para os "bocados do solo"

    Bocado ***area;
    int nLines;
    int nCols;

public:
    Jardim(int linhas, int colunas);
    ~Jardim();

    enum acoesBocado {
        NONE = 0,
        ALIVE = 1,
        DEAD = 2,
        EXPAND = 3,
        ROSEIRAVIZINHOS = 4,
        PLANTAEXOTICAEXPAND = 5
    };

    void iterate(int instante) const;
    void processaCambio(int tipo, int linha, int col) const;
    void expand(int linha, int col) const;
    bool hasFullViznhos(int linha, int col) const;
    std::array<int,4> verificaLimites(int linha, int col) const;
    std::string getDataFromBocado(int i, int j) const;
    std::string toString() const;
    void sowPlant(char type, int linha, int col) const;
    void genRandPlants() const;

    int getLinhas() const;
    int getColunas() const;

};


#endif //TP_POO_2526_JARDIM_H