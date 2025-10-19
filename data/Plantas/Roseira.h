//
// Created by sebie on 07/10/2025.
//

#ifndef TP_POO_2526_ROSEIRA_H
#define TP_POO_2526_ROSEIRA_H
#include "Roseira.h"
#include "Settings.h"
#include "data/Planta.h"

class Roseira : public Planta{
    static constexpr char id = 'r';
    static constexpr int inicial_agua = Settings::Roseira::inicial_agua; // us
    static constexpr int inicial_nutrientes = Settings::Roseira::inicial_nutrientes; // us
    static constexpr int perda_agua = Settings::Roseira::perda_agua;
    static constexpr int perda_nutrientes = Settings::Roseira::perda_nutrientes;
    static constexpr int absorcao_agua = Settings::Roseira::absorcao_agua;
    static constexpr int absorcao_nutrientes = 8;
    static constexpr int morre_agua_menor = Settings::Roseira::morre_agua_menor;
    static constexpr int morre_nutrientes_menor = Settings::Roseira::morre_nutrientes_menor;
    static constexpr int morre_nutrientes_maior = Settings::Roseira::morre_nutrientes_maior;
    static constexpr int multiplica_nutrientes_maior = 100;
    static constexpr int nova_nutrientes = Settings::Roseira::nova_nutrientes;
    static constexpr int nova_agua_percentagem = Settings::Roseira::inicial_agua;
    static constexpr int original_nutrientes = Settings::Roseira::original_nutrientes;
    static constexpr int original_agua_percentagem = Settings::Roseira::original_agua_percentagem;


    // ------------------
public:
    explicit Roseira(BocadoDoSolo * sitio);
    int pasaInstante(int instante) override; // virtual pq vai ser mudada em cada filho
    bool verificaMorte(int nInstantes) override;
    bool verificaExpansao(int agua, int nutrientes, int instanteAtual) override; // Verifica se a planta vai se expandir num bocado vizinho
    std::array<int, 2> alimentar()override;
    char getId() const override;

};


#endif //TP_POO_2526_ROSEIRA_H