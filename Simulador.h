//
// Created by sebie on 07/10/2025.
//

#ifndef TP_POO_2526_SIMULADOR_H
#define TP_POO_2526_SIMULADOR_H
#include "data/Jardim.h"


class Simulador {
    Jardim *jardim;
    int instante;
    // Define on instante atual
public:
    Simulador();
    ~Simulador();
    Simulador(int n1, int n2);

    void Run();
    void readCommand(const std::string& comm);

};


#endif //TP_POO_2526_SIMULADOR_H