using namespace std;
#define MAX_CONNECTED_CLIENTS 1


#include "DataReaderServer.h"


DataReaderServer::DataReaderServer(double portVal/*, double timeVal*/)/*: port(port), serverSocket(serverSoc)*/ {
    this->port = portVal;
}


int DataReaderServer:: getClint(){
    return this->clientSock;
}

void DataReaderServer::start(ParamsToUpdate* args) {
// Create a socket point
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw "Error opening socket";
    }
    args->defineSocketServer(serverSocket);
    // Start listening to incoming connections
    //listen(serverSocket, MAX_CONNECTED_CLIENTS);
    // Define the client socket's structures
    struct sockaddr_in serverAddress;
    bzero((void *)&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("ERROR on binding");
        exit(1);
    }
    listen(serverSocket, MAX_CONNECTED_CLIENTS);
    accept(args);
// Define the client socket's structures
/*    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen = sizeof (clientAddress);
    while (true) {
        cout << "Waiting for client connections..." << endl;
        // Accept a new client connection
        int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressLen);
        cout << "Client connected" << endl;
        if (clientSocket == -1)
            throw "Error on accept";
        handleClient(clientSocket);
        // Close communication with the client
        close(clientSocket);
    }*/
}

void DataReaderServer::accept(ParamsToUpdate* args){
    std::cout << "Waiting for connection..." << endl;
    sockaddr_in client_sock;
    int clilen;
    this->clientSock = ::accept(args->getSocketServer(), (struct sockaddr*) &client_sock, (socklen_t *)&clilen);
    if ( this->clientSock < 0) {
        // TODO error
    }
    std::cout << "hi" << std::endl;

}

/*
// Handle requests from a specific client
void DataReaderServer::handleClient(int clientSocket) {
    int arg1, arg2;
    char op;
    int n = read(clientSocket, &arg2, sizeof(arg2));
    if (n == -1) {
        cout << "Error reading arg2" << endl;
        return;
    }
    while (true) {
// Read new exercise arguments
        int n = read(clientSocket, &arg1, sizeof(arg1));
        if (n == -1) {
            cout << "Error reading arg1" << endl;
            return;
        }
        if (n == 0) {
            cout << "Client disconnected" << endl;
            return;
        }
        n = read(clientSocket, &op, sizeof(op));
        if (n == -1) {
            cout << "Error reading operator" << endl;
            return;
        }
        cout << "Got exercise: " << arg1 << op << arg2 <<
             endl;
        int result = calc(arg1, op, arg2);
// Write the result back to the client
        n = write(clientSocket, &result, sizeof(result));
        if (n == -1) {
            cout << "Error writing to socket" << endl;
            return;
        }
    }
}

//מיותר??
int DataReaderServer::calc(int arg1, const char op, int arg2) const {
    switch (op) {
        case '+':
            return arg1 + arg2;
        case '-':
            return arg1 - arg2;
        case '*':
            return arg1 * arg2;
        case '/':
            return arg1 / arg2;
        default:
            cout << "Invalid operator" << endl;
            return 0;
    }
}*/
/*
void DataReaderServer::stop() {
    close(serverSocket);
}
*/




/*void DataReaderServer::start() {
// Create a socket point
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw "Error opening socket";
    }
    // Start listening to incoming connections
    //listen(serverSocket, MAX_CONNECTED_CLIENTS);
    // Define the client socket's structures
    struct sockaddr_in serverAddress;
    bzero((void *)&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error on binding";
    }
    listen(serverSocket, MAX_CONNECTED_CLIENTS);
// Define the client socket's structures
*//*    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen = sizeof (clientAddress);
    while (true) {
        cout << "Waiting for client connections..." << endl;
        // Accept a new client connection
        int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressLen);
        cout << "Client connected" << endl;
        if (clientSocket == -1)
            throw "Error on accept";
        handleClient(clientSocket);
        // Close communication with the client
        close(clientSocket);
    }*//*
}*/
