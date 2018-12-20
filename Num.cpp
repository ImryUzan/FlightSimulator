//
// Created by imry on 12/13/18.
//

#include "Num.h"
#include <stdlib.h>
double Num::calculate() {
    return this->numberVal;
}

Num::Num(string numVal) {

    int z = stoi(numVal);
    this->numberVal = z;
}

Num::Num(double num) {
    this->numberVal= num;
}
