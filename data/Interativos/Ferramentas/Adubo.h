//
// Created by sebie on 07/10/2025.
//

#ifndef TP_POO_2526_ADUBO_H
#define TP_POO_2526_ADUBO_H
#include "Settings.h"
#include "data/Interativos/Ferramenta.h"


class Adubo : public Ferramenta {
    static constexpr int capacidade = Settings::Adubo::capacidade;
    static constexpr int dose = Settings::Adubo::dose;

    int nutrientesRestantes;
public:
    Adubo();
    ~Adubo();
    int instante() override;
};



#endif //TP_POO_2526_ADUBO_H