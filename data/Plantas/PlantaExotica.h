//
// Created by sebie on 07/10/2025.
//

#ifndef TP_POO_2526_PLANTAEXOTICA_H
#define TP_POO_2526_PLANTAEXOTICA_H
#include "data/Planta.h"
// Expande uma raiz cada turno
// Pode se alimentar dos bocados adjacentes tmb
// Devido às suas raizes plantas não conseguem crescer nas posições adjacentes
// Absorve 5% dos nutrientes e 10% da agua em cada bocado
// Morre: se não conseguir expandir pelo menos 3 raizes em 5 turnos, ou se receber 0 de agua ou 0 de nutrientes
class Planta;
class BocadoDoSolo;
class RaizPlantaExotica;


class PlantaExotica final : public Planta{
    static constexpr char id = 'z';
    int nRaizes;
public:
    explicit PlantaExotica(BocadoDoSolo * sitio);
    ~PlantaExotica() override;
    char getId() const override;
    int pasaInstante(int instante) override;
    bool verificaMorte(int instanteAtual) override;
    bool verificaExpansao(int agua, int nutrientes, int instanteAtual) override;
    void alimentar() override;

    void addRaiz();

};


#endif //TP_POO_2526_PLANTAEXOTICA_H