//
// Created by imry on 12/13/18.
//

#ifndef SIMULATOR_BINARYEXPRESSION_H
#define SIMULATOR_BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression{
    Expression *left;
    Expression *right;
public:
    BinaryExpression(Expression* first, Expression* sec){
        left = first;
        right = sec;
    }
    virtual double calculate()=0;
    Expression* getLeft();
    Expression* getRight();

};

#endif //SIMULATOR_BINARYEXPRESSION_H
