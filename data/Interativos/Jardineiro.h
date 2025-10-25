//
// Created by sebie on 07/10/2025.
//

#ifndef TP_POO_2526_JARDINEIRO_H
#define TP_POO_2526_JARDINEIRO_H
#include "Ferramenta.h"
#include <vector>
#include "Settings.h"


class Jardineiro {
    static const int max_movimentos = Settings::Jardineiro::max_movimentos ;
    static const int max_entradas_saidas = Settings::Jardineiro::max_entradas_saidas ;
    static const int max_plantacoes = Settings::Jardineiro::max_plantacoes;
    static const int max_colheitas = Settings::Jardineiro::max_colheitas;
// Acabam as constantes
    std::vector<std::shared_ptr<Ferramenta>> ferr;
    int ferrEquipada;

};


#endif //TP_POO_2526_JARDINEIRO_H