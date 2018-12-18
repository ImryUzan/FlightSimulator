
#ifndef SIMULATOR_OPENDATASERVERCOMMAND_H
#define SIMULATOR_OPENDATASERVERCOMMAND_H
#include "Command.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <list>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <sstream>
#include "ShutingYard.h"
#include "DataReaderServer.h"
#include <pthread.h>
#include "ParamsToUpdate.h"
using namespace std;

class openDataServerCommand : public Command{
public:
    openDataServerCommand(){

    }
    int doCommand(list<string>* list, int beginIndex,ParamsToUpdate* paramsToUpdate);
    string readFromSock(int nuberSocket);
    //void* openTread(void* arg);
};

#endif //SIMULATOR_OPENDATASERVERCOMMAND_H
