//
// Created by imry on 12/13/18.
//

#ifndef SIMULATOR_DIV_H
#define SIMULATOR_DIV_H

#include "BinaryExpression.h"

class Div : public BinaryExpression{
  //  Expression* left;
   // Expression* right;
public:
    Div(Expression* first, Expression* sec) : BinaryExpression(first, sec){
       // left = first;
        //right = sec;
    }
    double calculate();
};

#endif //SIMULATOR_DIV_H
