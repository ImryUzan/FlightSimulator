#include "Mult.h"

double Mult::calculate() {
    return ((this->getLeft()->calculate()) * (this->getRight()->calculate()));
}
