//
// Created by sebie on 07/10/2025.
//

#ifndef TP_POO_2526_PLANTA_H
#define TP_POO_2526_PLANTA_H
#include <array>
#include <memory>
#include "BocadoDoSolo.h"

class BocadoDoSolo;

class Planta {
    int lastInstanceNoWater, lastInstanceNoNutri, lastInstanceExpansion;
    int aguaAtual, nutriAtual;
    BocadoDoSolo*solo;
 public:
    Planta(BocadoDoSolo* sitio,int agua, int nutrientes);
    virtual ~Planta() = default;

    enum plantTypes{
        CACTO = 'c',
        ERVA = 'e',
        PLANTAEXOTICA = 'x',
        ROSEIRA = 'r',
        NONE = 'n'
    };
    static std::unique_ptr<Planta> createPlant(BocadoDoSolo * sitio, char type); // Função statica para a criação das plantas

    virtual int pasaInstante(int instante) = 0; // virtual pq vai ser mudada em cada filho
    virtual bool verificaMorte(int agua, int nutrientes, int nInstantes) = 0;
    virtual bool verificaExpansão(int agua, int nutrientes) = 0; // Verifica se a planta vai se expandir num bocado vizinho
    virtual char getId() const = 0;
    virtual std::array<int, 2> alimentar() = 0;
    // acabam as virtuais

    int getAgua()const;
    int getNutrientes()const;

    int getAguaSolo()const;
    int getNutrientesSolo()const;

    int tirarAgua(int agua);;
    int tirarNutrientes(int nutrientes);

    int getLastInstanceNoWater() const;
    int getLastInstanceNoNutri() const;

    void setLastIntanceNoWater(int n);
    void setLastIntanceNoNutri(int n);
};


#endif //TP_POO_2526_PLANTA_H