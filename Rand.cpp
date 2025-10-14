//
// Created by sebie on 14/10/2025.
//
#include "Rand.h"
#include "random"
int Rand::generate(const int floor, const int roof) {
    if (floor>roof)
        return -1;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> rand(floor,roof);
    return rand(gen);
}
