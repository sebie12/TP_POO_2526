//
// Created by sebie on 21/10/2025.
//

#ifndef TP_POO_2526_RAIZPLANTAEXOTICA_H
#define TP_POO_2526_RAIZPLANTAEXOTICA_H
#include "PlantaExotica.h"

class RaizPlantaExotica : public Planta{
public:
    bool verificaExpansao(int agua, int nutrientes, int instanteAtual) override = 0;
    char getId() const override;
    explicit RaizPlantaExotica(BocadoDoSolo*solo);
    std::array<int, 2> alimentar() override;
};


#endif //TP_POO_2526_RAIZPLANTAEXOTICA_H