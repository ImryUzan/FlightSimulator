//
// Created by imry on 12/19/18.
//


#include "Connect.h"
#include "DataClient.h"

int Connect::doCommand(list<string>* list, int beginIndex, ParamsToUpdate* paramsToUpdate){
    //to update lexer
    const char* localHost;
    int port;
    DataClient dataClient;
    dataClient.start(paramsToUpdate);
    return 0;

}
