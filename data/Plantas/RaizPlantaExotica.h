//
// Created by sebie on 21/10/2025.
//

#ifndef TP_POO_2526_RAIZPLANTAEXOTICA_H
#define TP_POO_2526_RAIZPLANTAEXOTICA_H
#include "../Planta.h"
#include "PlantaExotica.h"
#include <array>
class RaizPlantaExotica : public Planta{
    BocadoDoSolo*soloPai{};
public:
    bool verificaExpansao(int agua, int nutrientes, int instanteAtual) override;
    int pasaInstante(int instante) override;
    bool verificaMorte(int nInstantes)override;
    char getId() const override;
    explicit RaizPlantaExotica(BocadoDoSolo*solo);
    std::array<int, 2> alimentar() override;

    void setSoloPai(BocadoDoSolo* pai);
};


#endif //TP_POO_2526_RAIZPLANTAEXOTICA_H