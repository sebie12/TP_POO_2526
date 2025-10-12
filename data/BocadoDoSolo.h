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
    Jardim * jardim;
    Planta * planta;
    Jardineiro * jardineiro;
    int agua, nutrientes;
public:
    BocadoDoSolo(int aguaMin, int aguaMax, int nutriMin, int nutriMax, Jardim * jardim);

    ~BocadoDoSolo();
    void iterate(int instante);
    int aguaDada(int percentagem);
    int nutrientesPerdidos(int unidades);
    static void feedFromDeadPlant(int nutrientes);
};


#endif //TP_POO_2526_BOCADODOSOLO_H