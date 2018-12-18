#include "Mult.h"

double Mult::Calculate() {
    return ((this->getLeft()->Calculate()) * (this->getRight()->Calculate()));
}
