//
// Created by sebie on 08/10/2025.
//

#ifndef TP_POO_2526_BOCADODOSOLO_H
#define TP_POO_2526_BOCADODOSOLO_H

#include <memory>
#include "Jardim.h"
#include "Planta.h"
#include "Interativos/Jardineiro.h"
#include "Interativos/Ferramenta.h"

class Jardim;
class Planta;

class BocadoDoSolo {
    Jardim * jardim{};
    std::unique_ptr<Planta> planta;
    std::shared_ptr<Jardineiro> jardineiro;
    std::unique_ptr<Ferramenta> ferramenta;
    int agua, nutrientes;
public:
    BocadoDoSolo(int aguaMin, int aguaMax, int nutriMin, int nutriMax);
    ~BocadoDoSolo();
    int iterate(int instante);
    void feedFromDeadPlant(int aguaDaPlanta, int nutriDaPlanta);
    void killPlanta();

    int perdeAgua(int unidades);
    int perdeNutrientes(int unidades);

    bool newPlant(char type);
    bool hasPlant()const;
    void feedPlanta(int novaAgua, int novosNutrientes) const;

    int getAgua()const;
    int getNutrientes()const;

    char getIdFromPlant()const;
    char getIdForPrint()const;

    std::string toString()const;

    BocadoDoSolo* operator>>(const BocadoDoSolo* outro);
};


#endif //TP_POO_2526_BOCADODOSOLO_H