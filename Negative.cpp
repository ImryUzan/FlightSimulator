
#include "Negative.h"
#include "Minus.h"
#include "Num.h"

double Negative::Calculate() {
    Expression* num = new Num("0");
    Expression* result = new Minus(num, exp);
    return result->Calculate();
}