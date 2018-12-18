

#ifndef SIMULATOR_SHUTINGYARD_H
#define SIMULATOR_SHUTINGYARD_H
#include <bits/stdc++.h>
#include "Expression.h"
using namespace std;

class ShutingYard{
    stack <string> values;
    bool firseTime = true;
public:
    Expression* convertTOExpression(stack <string>* values);
    int precedence(char op);
    stack <string>* evaluate(string tokens);
    int applyOp(int a, int b, char op);
};

#endif //SIMULATOR_SHUTINGYARD_H
