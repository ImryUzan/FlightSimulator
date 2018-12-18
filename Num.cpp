//
// Created by imry on 12/13/18.
//

#include "Num.h"
#include <stdlib.h>
double Num::Calculate() {
    return this->numberVal;
}

Num::Num(string numVal) {

    int z = stoi(numVal);
    this->numberVal = z;
}
