//
// Created by sebie on 08/10/2025.
//

#ifndef TP_POO_2526_FERRAMENTAZ_H
#define TP_POO_2526_FERRAMENTAZ_H
#include "data/Interativos/Ferramenta.h"

// Comportamento definido por nós
class FerramentaZ final : public Ferramenta {

public:
    FerramentaZ();
    ~FerramentaZ() override;
    void instante(Bocado*posAtual) override;
};


#endif //TP_POO_2526_FERRAMENTAZ_H