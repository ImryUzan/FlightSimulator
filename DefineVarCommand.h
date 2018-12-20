//
// Created by imry on 12/17/18.
//

#ifndef SIMULATOR_VAR_H
#define SIMULATOR_VAR_H

#include <string>
#include "Command.h"

using namespace std;

class DefineVarCommand : public Command {
/*    double varVal;
    bool isBinded;
    string bindPath;*/
public:
    int doCommand(list<string>* list, int beginIndex,ParamsToUpdate* paramsToUpdate);
    DefineVarCommand();
    double convertToDouble(string value);
   /* double GetValue();
    void SetValue(double newVal);*/
};
#endif //SIMULATOR_VAR_H
