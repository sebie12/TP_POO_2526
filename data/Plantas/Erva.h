//
// Created by sebie on 07/10/2025.
//

#ifndef TP_POO_2526_ERVA_H
#define TP_POO_2526_ERVA_H
#include "Settings.h"
#include "data/Planta.h"
#include "../Bocado.h"


class Erva final : public Planta{
    static constexpr char id = 'e';
    static constexpr int inicial_agua = Settings::ErvaDaninha::inicial_agua ;
    static constexpr int inicial_nutrientes = Settings::ErvaDaninha::inicial_nutrientes;
    static constexpr int absorcao_agua = Settings::ErvaDaninha::absorcao_agua;
    static constexpr int morre_instantes = Settings::ErvaDaninha::morre_instantes;
    static constexpr int multiplica_instantes = Settings::ErvaDaninha::multiplica_instantes;
    static constexpr int nova_nutrientes = Settings::ErvaDaninha::nova_nutrientes;
    static constexpr int original_nutrientes = Settings::ErvaDaninha::original_nutrientes;
    static constexpr int absorcao_nutrientes = Settings::ErvaDaninha::absorcao_nutrientes;
    static constexpr int multiplica_nutrientes_maior = Settings::ErvaDaninha::multiplica_nutrientes_maior;

    int instanteNascimento, ultimaExpansao;
    // ------------------
public:
    explicit Erva();
    ~Erva() override;
    char getId() const override;
    int verificaMorte(int aguaSolo, int nutriSolo, int instanteAtual, int & outNutrientes) override;
    bool verificaExpansao(int agua, int nutrientes, int instanteAtual) override;
    int alimentar(int aguaSolo, int nutriSolo, int & outNutrientes) override;
    int getAguaNutriMorte(int & outNutrientes) const override;
};


#endif //TP_POO_2526_ERVA_H