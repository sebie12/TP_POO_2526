//
// Created by sebie on 07/10/2025.
//

#ifndef TP_POO_2526_SIMULADOR_H
#define TP_POO_2526_SIMULADOR_H
#include "data/Jardim.h"
#include <string>
#include <vector>
#include <sstream>


class Simulador {
    Jardim *jardim;
    int instante; // Define on instante atual
    bool terminou = false;
public:
    Simulador();
    ~Simulador();

    void run();// loop principal
    bool interpretaComando(std::istringstream &iss);  // valida e executa comandos
    static void mostraAjuda() ;           // imprime lista de comandos

};


#endif //TP_POO_2526_SIMULADOR_H