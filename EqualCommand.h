//
// Created by imry on 12/19/18.
//

#ifndef SIMULATOR_EQUALCOMMAND_H
#define SIMULATOR_EQUALCOMMAND_H

#include <list>
#include "string.h"
#include "Command.h"
#include "map"
using namespace std;
class EqualCommand : public Command{
public:
    int doCommand(list<string> list1, map<string, double> *map1, int index);
};
#endif //SIMULATOR_EQUALCOMMAND_H
