//
// Created by sebie on 08/10/2025.
//

#include "BocadoDoSolo.h"
BocadoDoSolo::BocadoDoSolo(int aguaMin, int aguaMax, int nutriMin, int nutriMax){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> randAgua(aguaMin,aguaMax);
    uniform_int_distribution<int> randNutrientes(nutriMin,nutriMax);

    agua = randAgua(gen);
    nutrientes = randNutrientes(gen);
    jardineiro = nullptr;
    planta = nullptr;
}
BocadoDoSolo::~BocadoDoSolo() {
    delete planta;
    delete jardineiro;

}
