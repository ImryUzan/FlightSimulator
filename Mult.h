//
// Created by imry on 12/13/18.
//

#ifndef SIMULATOR_MULT_H
#define SIMULATOR_MULT_H

#include "BinaryExpression.h"

class Mult : public BinaryExpression{
   // Expression* left;
   // Expression* right;
public:
    Mult(Expression* first, Expression* sec) : BinaryExpression(first, sec){
       // left = first;
       // right = sec;
    }
    double calculate();
};

#endif //SIMULATOR_MULT_H
