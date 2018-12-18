//
// Created by imry on 12/13/18.
//

#ifndef SIMULATOR_NUM_H
#define SIMULATOR_NUM_H

#include "string"
#include "BinaryExpression.h"

class Num : public Expression{
    double numberVal;
public:
    Num(string num);

    double Calculate();
};
#endif //SIMULATOR_NUM_H
