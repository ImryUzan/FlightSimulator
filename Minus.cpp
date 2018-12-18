//
// Created by imry on 12/13/18.
//
#include "Minus.h"

double Minus::Calculate() {
    return ((this->getLeft()->Calculate()) - (this->getRight()->Calculate()));
}
