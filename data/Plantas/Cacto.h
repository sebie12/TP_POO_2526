//
// Created by sebie on 07/10/2025.
//

#ifndef TP_POO_2526_CACTO_H
#define TP_POO_2526_CACTO_H
#include "Cacto.h"
#include "Settings.h"
#include "data/Planta.h"
#include "array"


class Cacto final : public Planta{
    static constexpr char id = 'c';
    static constexpr int absorcao_agua_percentagem = Settings::Cacto::absorcao_agua_percentagem ;
    static constexpr int morre_agua_solo_maior = Settings::Cacto::morre_agua_solo_maior;
    static constexpr int morre_agua_solo_instantes = Settings::Cacto::morre_agua_solo_instantes;
    static constexpr int morre_nutrientes_solo_menor = Settings::Cacto::morre_nutrientes_solo_instantes;
    static constexpr int morre_nutrientes_solo_instantes = Settings::Cacto::morre_nutrientes_solo_instantes;
    static constexpr int multiplica_agua_maior = Settings::Cacto::multiplica_agua_maior;
    static constexpr int absorcao_nutrientes = Settings::Cacto::absorcao_nutrientes;
    static constexpr int multiplica_nutrientes_maior = Settings::Cacto::multiplica_nutrientes_maior;

    // ------------------
public:
    explicit Cacto(BocadoDoSolo*sitio);
    explicit Cacto(BocadoDoSolo*sitio, int agua, int nutrientes);
    ~Cacto() override;
    char getId() const override;
    int pasaInstante(int instante) override;
    bool verificaMorte(int agua, int nutrientes, int instanteAtual) override;
    bool verificaExpansao(int agua, int nutrientes, int instanteAtual) override;
    std::array<int, 2> alimentar() override;
};


#endif //TP_POO_2526_CACTO_H