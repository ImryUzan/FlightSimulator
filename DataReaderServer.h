//
// Created by imry on 12/18/18.
//

#ifndef SIMULATOR_DATAREADERSERVER_H
#define SIMULATOR_DATAREADERSERVER_H
#include "Command.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "stdio.h"
#include "ParamsToUpdate.h"
using namespace std;
class DataReaderServer {
    double port;
    double time; // the socket's file descriptor
    int clientSock;
public:
    DataReaderServer(double portVal);
    void start(ParamsToUpdate* args);
    void stop();
    void handleClient(int clientSocket);
    int calc(int arg1, const char op, int arg2) const;
    void accept(ParamsToUpdate* args);
};
#endif //SIMULATOR_DATAREADERSERVER_H
