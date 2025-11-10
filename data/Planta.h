//
// Created by sebie on 07/10/2025.
//

#ifndef TP_POO_2526_PLANTA_H
#define TP_POO_2526_PLANTA_H
#include <string>
#include <sstream>
#include <array>
#include <memory>
#include "Bocado.h"

class Bocado;

class Planta {
    int lastInstanceNoWater, lastInstanceNoNutri;
    int aguaAtual, nutriAtual;
 public:
    Planta(int agua, int nutrientes);
    virtual ~Planta() = default;
    enum plantTypes{
        CACTO = 'c',
        ERVA = 'e',
        PLANTAEXOTICA = 'x',
        ROSEIRA = 'r',
        NONE = 'n'
    };
    static std::shared_ptr<Planta> createPlant(char type); // Função statica para a criação das plantas

    virtual int verificaMorte(int aguaSolo, int nutriSolo, int nInstantes, int & outNutrientes) = 0;
    virtual bool verificaExpansao(int agua, int nutrientes, int instanteAtual) = 0; // Verifica se a planta vai se expandir num bocado vizinho
    virtual char getId() const = 0;
    virtual int alimentar(int aguaSolo, int nutriSolo, int & outNutrientes) = 0;
    virtual int getAguaNutriMorte(int & nutrientes) const = 0;
    // acabam as virtuais

    int getAgua()const;
    int getNutrientes()const;

    int addNutrientes(int nutrientes);
    int addAgua(int agua);
    int perderAgua(int agua);
    int perderNutri(int nutri);
    void setAgua(int agua);
    void setNutri(int nutri);

    int getLastInstanceNoWater() const;
    int getLastInstanceNoNutri() const;

    void setLastIntanceNoWater(int n);
    void setLastIntanceNoNutri(int n);

    std::string toString() const;
};


#endif //TP_POO_2526_PLANTA_H