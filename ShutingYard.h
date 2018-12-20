

#ifndef SIMULATOR_SHUTINGYARD_H
#define SIMULATOR_SHUTINGYARD_H
/*#include <bits/stdc++.h>
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
};*/

//#include "BinaryExpressions/PlusExpression.h"
#include "Num.h"
//#include "BinaryExpressions/MinusExpression.h"
//#include "BinaryExpressions/MultiplyExpression.h"
//#include "BinaryExpressions/DivideExpression.h"
#include "Expression.h"
#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class ShutingYard {
    map<string,double> var_to_val;
    int precedence(char op);

public:
    ShutingYard(map<string, double> &var_to_val);

private:
    Expression* applyOp(double a, double b, char op);
    vector<string> splitLine(const string &str, char sign);

    double calculate(string tokens);
    double evaluate(string tokens);

public:
    double virtual operator()(char* str);
    double virtual operator()(string str);

};

#endif //SIMULATOR_SHUTINGYARD_H
