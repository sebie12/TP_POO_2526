//
// Created by sebie on 08/10/2025.
//

#ifndef TP_POO_2526_BOCADODOSOLO_H
#define TP_POO_2526_BOCADODOSOLO_H
#include <random>

#include "Jardim.h"
#include "Planta.h"
#include "Interativos/Jardineiro.h"
using namespace std;

class BocadoDoSolo {
    unique_ptr<Planta> planta;
    shared_ptr<Planta> jardineiro;
    int agua, nutrientes;
public:
    BocadoDoSolo(int aguaMin, int aguaMax, int nutriMin, int nutriMax);
    ~BocadoDoSolo();
    Jardim::codeIt iterate(int instante);
    static void feedFromDeadPlant(int nutrientes);

    int perdeAgua(int unidades);
    int perdeNutrientes(int unidades);

    char getIdFromPlant()const;
    bool newPlant(char type);

    int getAgua()const;
    int getNutrientes()const;
};


#endif //TP_POO_2526_BOCADODOSOLO_H