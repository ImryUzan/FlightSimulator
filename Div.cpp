//
// Created by imry on 12/13/18.
//
#include "Div.h"

double Div::Calculate() {
    return ((this->getLeft()->Calculate()) / (this->getRight()->Calculate()));
}