
#ifndef SIMULATOR_PLUS_H
#define SIMULATOR_PLUS_H

#include "BinaryExpression.h"

class Plus : public BinaryExpression{
    //Expression* left;
    //Expression* right;
public:
    Plus(Expression* first, Expression* sec) : BinaryExpression(first, sec){
       // left = first;
       // right = sec;
    }
    double Calculate();
};

#endif //SIMULATOR_PLUS_H
