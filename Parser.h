//
// Created by imry on 12/18/18.
//

#ifndef SIMULATOR_PARSER_H
#define SIMULATOR_PARSER_H

#include "string.h"
#include "Expression.h"
#include "CommandExpression.h"
#include <map>
#include <list>

using namespace std;

class Parser{
public:
    Parser(){
    }
    void parseTheString(list<string>* listOfString);
};
#endif //SIMULATOR_PARSER_H
