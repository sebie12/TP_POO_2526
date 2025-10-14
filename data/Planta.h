//
// Created by sebie on 07/10/2025.
//

#ifndef TP_POO_2526_PLANTA_H
#define TP_POO_2526_PLANTA_H
#include <memory>

 class Planta {
    int lastInstanceNoWater, lastInstanceNoNutri, lastInstanceExpansion;
    int agua, nutrientes;

 public:
     Planta();
    virtual ~Planta() = default;

    enum plantTypes{
        CACTO = 'c',
        ERVA = 'e',
        PLANTAEXOTICA = 'x',
        ROSEIRA = 'r',
        NONE = 'n'
    };
    static std::unique_ptr<Planta> createPlant(char type); // Função statica para a criação das plantas

    virtual int pasaInstante(int agua, int nutrientes, int instante); // virtual pq vai ser mudada em cada filho
    virtual bool verificaMorte(int agua, int nutrientes, int nInstantes);
    virtual bool verificaExpansão(int agua, int nutrientes); // Verifica se a planta vai se expandir num bocado vizinho
    virtual char getId() const;

    int getLastInstanceNoWater() const;
    void setLastIntanceNoWater(int n);
    int getLastInstanceNoNutri() const;
    void setLastIntanceNoNutri(int n);
};


#endif //TP_POO_2526_PLANTA_H