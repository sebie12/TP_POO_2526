//
// Created by sebie on 07/10/2025.
//

#ifndef TP_POO_2526_JARDINEIRO_H
#define TP_POO_2526_JARDINEIRO_H
#include "Ferramenta.h"
#include "../BocadoDoSolo.h"
#include "Settings.h"
#include <vector>

class Jardineiro {
    static constexpr int max_movimentos = Settings::Jardineiro::max_movimentos ;
    static constexpr int max_entradas_saidas = Settings::Jardineiro::max_entradas_saidas ;
    static constexpr int max_plantacoes = Settings::Jardineiro::max_plantacoes;
    static constexpr int max_colheitas = Settings::Jardineiro::max_colheitas;
// Acabam as constantes
    BocadoDoSolo * posAtual;
    Ferramenta ** ferr{}; // Array de ponteiros para ferramentas
    int ferrEquipada;
public:
    Jardineiro();
    ~Jardineiro();
    void newPosicao(BocadoDoSolo * posNova);
    void pegaFerramenta(const std::shared_ptr<Ferramenta>& novaFerramenta);
    void equipaFerramenta(int id);
    void descartaFerramenta();
    int buscaFerramenta(int id) const;
    void usaFerramenta();
};


#endif //TP_POO_2526_JARDINEIRO_H