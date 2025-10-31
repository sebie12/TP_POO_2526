//
// Created by sebie on 08/10/2025.
//

#ifndef TP_POO_2526_REGADOR_H
#define TP_POO_2526_REGADOR_H
#include "Settings.h"
#include "data/Interativos/Ferramenta.h"


class Regador final : public Ferramenta{
    static constexpr int capacidade = Settings::Regador::capacidade ;
    static constexpr int dose = Settings::Regador::dose;
    int aguaRestante;
public:
    Regador();
    ~Regador() override;
    void instante(BocadoDoSolo*posAtual) override;
};


#endif //TP_POO_2526_REGADOR_H