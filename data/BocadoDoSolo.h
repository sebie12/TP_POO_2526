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
    int aguaDada(int percentagem);
    int nutrientesPerdidos(int unidades);
    static void feedFromDeadPlant(int nutrientes);
    char getIdFromPlant()const;
    bool newPlant(char type);
};


#endif //TP_POO_2526_BOCADODOSOLO_H