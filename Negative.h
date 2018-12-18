//
// Created by imry on 12/17/18.
//

#ifndef SIMULATOR_NEGATIVE_H
#define SIMULATOR_NEGATIVE_H

#include "Expression.h"
class Negative{
    Expression* exp;
public:
    Negative (Expression* val){
        exp = val;
    }
    double Calculate();
};
#endif //SIMULATOR_NEGATIVE_H
