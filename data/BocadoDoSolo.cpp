//
// Created by sebie on 08/10/2025.
//

#include "BocadoDoSolo.h"
BocadoDoSolo::BocadoDoSolo(const int aguaMin, const int aguaMax, const int nutriMin, const int nutriMax, Jardim *jardim)
: jardim(jardim), planta(nullptr), jardineiro(nullptr)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> randAgua(aguaMin,aguaMax);
    uniform_int_distribution<int> randNutrientes(nutriMin,nutriMax);

    agua = randAgua(gen);
    nutrientes = randNutrientes(gen);
}
BocadoDoSolo::~BocadoDoSolo() {
    delete planta;
    delete jardineiro;
}
void BocadoDoSolo::iterate(const int instante) {
    if (planta != nullptr) {
        const auto temp = planta->pasaInstante(agua,nutrientes,instante);
        if (temp != -1) {
            feedFromDeadPlant(temp);
            planta = nullptr;
            return;
        }
        if (planta->verificaExpansão(agua,nutrientes)) {

        }
    }
}
int BocadoDoSolo::aguaDada(const int percentagem) {
    // Verifica se vai subtrair até ficar menor a 0 (não devia mas ok)
    const auto valor = agua - agua * percentagem < 0 ? agua : agua - agua * percentagem;
    if (agua > 0)
        agua -= valor;
    return valor;
}
int BocadoDoSolo::nutrientesPerdidos(const int unidades) {
    // Verifica se vai subtrair até ficar menor a 0
    const auto valor = nutrientes - unidades <= 0 ? nutrientes : nutrientes - unidades;
    if (nutrientes > 0)
        nutrientes = valor;
    return valor;
}
void BocadoDoSolo::feedFromDeadPlant(int nutrientes) {
    nutrientes += nutrientes;
}




