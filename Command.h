//
// Created by imry on 12/13/18.
//

#ifndef SIMULATOR_COMMAND_H
#define SIMULATOR_COMMAND_H
#include <string>
#include <list>
#include "ParamsToUpdate.h"

using namespace std;

class Command{
public:
    virtual int doCommand(list<string>* list, int beginIndex,ParamsToUpdate* paramsToUpdate)=0;
};

#endif //SIMULATOR_COMMAND_H
