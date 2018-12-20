//
// Created by imry on 12/19/18.
//

#ifndef SIMULATOR_CONNECT_H
#define SIMULATOR_CONNECT_H

#include "Command.h"
#include "ParamsToUpdate.h"

class Connect : public Command{
public:
    int doCommand(list<string>* list, int beginIndex,ParamsToUpdate* paramsToUpdate);
};
#endif //SIMULATOR_CONNECT_H
