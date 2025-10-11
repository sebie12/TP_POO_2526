//
// Created by sebie on 07/10/2025.
//

#include "Cacto.h"
char Cacto::getId()const {
    return id;
}
void Cacto::pasaInstante() {

}
bool Cacto::verificaMorte(const int agua, const int nutrientes, const int nInstantes) {
    return nInstantes == 3 && agua > 100 || nutrientes <= 0;
}

