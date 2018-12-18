#include "Plus.h"

double Plus::Calculate() {
    return ((this->getLeft()->Calculate()) + (this->getRight()->Calculate()));
}
