//
// Created by imry on 12/13/18.
//

#ifndef SIMULATOR_MINUS_H
#define SIMULATOR_MINUS_H

#include "BinaryExpression.h"

class Minus : public BinaryExpression{
   // Expression* left;
   // Expression* right;
public:
    Minus(Expression* first, Expression* sec) : BinaryExpression(first, sec){
        //left = first;
        //right = sec;
    }
    double calculate();
};

#endif //SIMULATOR_MINUS_H
