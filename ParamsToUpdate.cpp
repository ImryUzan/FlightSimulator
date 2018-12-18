//
// Created by imry on 12/18/18.
//
#include <unistd.h>
#include "ParamsToUpdate.h"

ParamsToUpdate :: ParamsToUpdate(){
}

void ParamsToUpdate :: setPort(double thePort){
    port = thePort;

}

void ParamsToUpdate :: defineSocket(int serverSock){
    serverSocket =serverSock;
}

map<string,double>* ParamsToUpdate :: getVarsValues(){
    return &varsValues;
}

double ParamsToUpdate :: getPort(){
    return port;

}

int ParamsToUpdate ::getSocket() {
    return serverSocket;

}

string ParamsToUpdate::readFromSock(int nuberSocket){
//todo while
    char buffer[1024];
    ssize_t bytes_read;
    bytes_read = read(nuberSocket, buffer, 999);
    if (bytes_read < 0) {
        // TODO error
    }   else if (bytes_read == 0)   {
        // TODO connection closed
        int y = 0;
    } else  {
        buffer[bytes_read] = NULL;
        cout << buffer;
    }
   // std::cout<<buffer<<std::endl;
    return "";

}