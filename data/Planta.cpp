//
// Created by sebie on 07/10/2025.
//

#include "Planta.h"

#include "Plantas/Cacto.h"
#include "Plantas/Erva.h"
#include "Plantas/Roseira.h"

Planta *Planta::createPlant(plantTypes type) {
    switch (type) {
        case CACTO:
            return new Cacto();
        case ERVA:
            return new Erva();
        case ROSEIRA:
            return new Roseira();
        default:
            return nullptr;
    }
}
