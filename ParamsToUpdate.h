//
// Created by imry on 12/18/18.
//

#ifndef SIMULATOR_PARAMSTOUPDATE_H
#define SIMULATOR_PARAMSTOUPDATE_H

#include <map>
#include "string.h"
#include <strings.h>
#include <iostream>
//#include "DataReaderServer.h"
using namespace std;

class ParamsToUpdate {
    int serverSocket;
    double port;
    map<string,double> varsValues;
public:
    ParamsToUpdate();
    void setPort(double thePort);
    void defineSocket(int serverSock);
    map<string,double>* getVarsValues();
    double getPort();
    int getSocket();
    string readFromSock(int nuberSocket);
};

#endif //SIMULATOR_PARAMSTOUPDATE_H
