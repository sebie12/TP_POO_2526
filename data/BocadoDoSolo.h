//
// Created by sebie on 08/10/2025.
//

#ifndef TP_POO_2526_BOCADODOSOLO_H
#define TP_POO_2526_BOCADODOSOLO_H
#include <random>

#include "Planta.h"
#include "Interativos/Jardineiro.h"
using namespace std;

class BocadoDoSolo {
    Planta * planta;
    Jardineiro * jardineiro;
    int agua, nutrientes;
public:
    BocadoDoSolo(int aguaMin, int aguaMax, int nutriMin, int nutriMax);
    ~BocadoDoSolo();
};


#endif //TP_POO_2526_BOCADODOSOLO_H