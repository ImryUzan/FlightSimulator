#include "Plus.h"

double Plus::calculate() {
    return ((this->getLeft()->calculate()) + (this->getRight()->calculate()));
}
