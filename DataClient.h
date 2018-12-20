//
// Created by imry on 12/19/18.
//

#ifndef SIMULATOR_DATACLIENT_H
#define SIMULATOR_DATACLIENT_H
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "stdio.h"
#include "ParamsToUpdate.h"
#include <cstdlib>
#include <netdb.h>
#include <strings.h>
#include <string>
#include <iostream>
using namespace std;
class DataClient{
    int socketClient;
    struct sockaddr_in m_socket;
public:
    DataClient(){

    }
    int start(ParamsToUpdate* args);
    string set(int sockfd, string path);
};
#endif //SIMULATOR_DATACLIENT_H
