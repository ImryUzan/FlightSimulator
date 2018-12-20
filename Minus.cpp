//
// Created by imry on 12/13/18.
//
#include "Minus.h"

double Minus::calculate() {
    return ((this->getLeft()->calculate()) - (this->getRight()->calculate()));
}
