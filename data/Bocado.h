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
class Jardineiro;
class Ferramenta;

class Bocado {
    std::shared_ptr<Planta> planta;
    std::shared_ptr<Jardineiro> jardineiro;
    std::shared_ptr<Ferramenta> ferramenta;
    int agua, nutrientes;
public:
    Bocado(int aguaMin, int aguaMax, int nutriMin, int nutriMax);
    ~Bocado();
    int iterate(int instante);
    std::string toString()const;

    // PLant Logic
    void killPlanta(int aguaRetirada, int nutrientesRetirados);

    int perdeAgua(int unidades);
    int perdeNutrientes(int unidades);
    int ganhaAgua(int unidades);
    int ganhaNutrientes(int unidades);

    bool newPlant(const std::shared_ptr<Planta>& newPlanta);
    bool hasPlant()const;
    void feedPlanta(int novaAgua, int novosNutrientes) const;

    int getAgua()const;
    int getNutrientes()const;

    char getIdFromPlant()const;
    char getIdForPrint()const;

    int getAguaNutriMorte(int & outNutrientes) const;

    Bocado* operator>>(const Bocado* outro);

    // Ferramenta Logic
    void newFerramenta(char tipo);
   std::shared_ptr<Ferramenta> removeFerramenta();


};


#endif //TP_POO_2526_BOCADODOSOLO_H