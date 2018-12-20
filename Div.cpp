//
// Created by imry on 12/13/18.
//
#include "Div.h"

double Div::calculate() {
    return ((this->getLeft()->calculate()) / (this->getRight()->calculate()));
}