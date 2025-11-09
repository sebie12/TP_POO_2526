 //
// Created by sebie on 08/10/2025.
//

#ifndef TP_POO_2526_FERRAMENTA_H
#define TP_POO_2526_FERRAMENTA_H
#include <memory>

#include "data/BocadoDoSolo.h"


 class Ferramenta {
    static int N_SERIE_REF;
    int id;
    const char nome;
    bool empty;
public:
    virtual ~Ferramenta();
    enum TipoFerramenta { // Assim obtemos os Ids
        ADUBO = 'a',
        REGADOR = 'g',
        TESOURA = 't',
        FERRAMENTAZ = 'z'
    };
    explicit Ferramenta(char nome);
    virtual void instante(BocadoDoSolo * posAtual) = 0; // Está igual a 0 pq só vai ser definida nos filhos
    char getNome() const;
    int getId() const;
    bool getEmpty() const; // Verifica se ja se esgotou o conteudo ou se é inutil (não aplica na tesoura)
    void changeEmpty();
    static std::shared_ptr<Ferramenta> createFerramenta(char tipo);
};


#endif //TP_POO_2526_FERRAMENTA_H