//
// Created by sebie on 07/10/2025.
//

#ifndef TP_POO_2526_PLANTA_H
#define TP_POO_2526_PLANTA_H


class Planta {
    static const int absorcao_nutrientes;
    static const int multiplica_nutrientes_maior;
protected:
    Planta(int absorcao_nutrientes, int multiplica_nutrientes_maior)
    : absorcao_nutrientes(absorcao_nutrientes), multiplica_nutrientes_maior(multiplica_nutrientes_maior) {}
    // O construtor da planta atribui os valores as unicas constantes em comum
public:
    virtual void pasaInstante(); // virtual pq vai ser mudada em cada filho
    virtual bool verificaMorte();
};


#endif //TP_POO_2526_PLANTA_H