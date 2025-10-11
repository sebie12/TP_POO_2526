//
// Created by sebie on 07/10/2025.
//

#ifndef TP_POO_2526_PLANTA_H
#define TP_POO_2526_PLANTA_H
#include <iosfwd>


 class Planta {
    const int absorcao_nutrientes;
    const int multiplica_nutrientes_maior;
public:
    enum plantTypes{
        CACTO,
        ERVA,
        PLANTAEXOTICA,
        ROSEIRA
    };
    Planta(int absorcao_nutrientes, int multiplica_nutrientes_maior)
    : absorcao_nutrientes(absorcao_nutrientes), multiplica_nutrientes_maior(multiplica_nutrientes_maior) {}
    // O construtor da planta atribui os valores as unicas constantes em comum
    virtual ~Planta() = default;

    static Planta* createPlant(plantTypes type); // Função statica para a criação das plantas
    virtual void pasaInstante(); // virtual pq vai ser mudada em cada filho
    virtual bool verificaMorte(int agua, int nutrientes, int nInstantes);
    virtual char getId() const;
};


#endif //TP_POO_2526_PLANTA_H