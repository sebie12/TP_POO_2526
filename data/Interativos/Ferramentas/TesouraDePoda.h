//
// Created by sebie on 08/10/2025.
//

#ifndef TP_POO_2526_TESOURADEPODA_H
#define TP_POO_2526_TESOURADEPODA_H
#include "data/Interativos/Ferramenta.h"


class TesouraDePoda final : public Ferramenta {
public:
    TesouraDePoda();
    ~TesouraDePoda() override;
    void instante(Bocado*posAtual) override;
};


#endif //TP_POO_2526_TESOURADEPODA_H