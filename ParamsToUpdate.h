//
// Created by imry on 12/18/18.
//

#ifndef SIMULATOR_PARAMSTOUPDATE_H
#define SIMULATOR_PARAMSTOUPDATE_H

#include <map>
#include "string.h"
//#include "CommandExpression.h"
#include <strings.h>
#include <iostream>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include "DataReaderServer.h"
using namespace std;

class ParamsToUpdate {
    int serverSocket;
    double portServer;
    char* localHost;
    int clientSocket;
    double portClient;
    map<string,double> varsValues;
    map<string,double> pathsMap;
    map<string, string> fromVarToPathMap;
//    map<string, CommandExpression> commandMap;
public:
    void intelizeMap();
    ParamsToUpdate();
    void setPortServer(double thePort);
    void setPortClient(double thePort);
    const char* getLocalHost();
    void defineSocketServer(int serverSock);
    map<string,double>& getVarsValues();
    void defineSocketClient(int clientSocket);
    double getPortServer();
    int getSocketServer();
    double getPortClient();
    int getSocketClient();
    string readFromSock(int nuberSocket) const;
    list<string> splitInformation(string toParse);
    void updateMaps(list<string> parsingStr);
    char* setLocalHost(char* theHost);
    void sendMsg();
    map<string,double>* getPathsValues();
    map<string,string>* getVarToPathsValues();

    void addValVarsValues(string varName, double val);

    void addValPathsMap(string varName, double val);

    void addValFromVarToPathMap(string varName, string varPath);

    void updateAllMaps();
};

#endif //SIMULATOR_PARAMSTOUPDATE_H
