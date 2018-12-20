//
// Created by imry on 12/19/18.
//
#include <sys/time.h>
#include "DataClient.h"
int DataClient::start(ParamsToUpdate* args) {
    int  portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    /* Create a socket point */
    this->socketClient = socket(AF_INET, SOCK_STREAM, 0);
    args->defineSocketClient(this->socketClient);
    if (this->socketClient < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize m_socket structure */
    bzero((char *) &this->m_socket, sizeof(this->m_socket));
    portno = args->getPortClient();

    server = gethostbyname(args->getLocalHost());

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    /* Now connect to the server */
    if (connect(this->socketClient, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    return 0;
}


string DataClient::set(int sockfd, string path) {
    int n;
    char buffer[1000];

    //printf("Please enter the message: ");
    bzero(buffer, 1000);
    //fgets(buffer, BUF, stdin);

    size_t path_len = path.size();

    /* Send message to the server */
//    n = write(sockfd, buffer, strlen(buffer));
    n = write(sockfd, &path, path_len);

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
//-------------------------------------------------------------
    char msg[1500];
    int bytesRead, bytesWritten = 0;
    struct timeval start1, end1;
    gettimeofday(&start1, NULL);
    while (1) {
        cout << ">";
        string data;
        getline(cin, data);
        memset(&msg, 0, sizeof(msg));//clear the buffer
        strcpy(msg, data.c_str());
        if (data == "exit") {
            send(sockfd, (char *) &msg, strlen(msg), 0);
            break;
        }
        bytesWritten += send(sockfd, (char *) &msg, strlen(msg), 0);
        //-------------------------------------------------------------------
        /* Now read server response */
//    bzero(buffer, BUF);
//    n = read(sockfd, buffer, BUF - 1);
//
//    if (n < 0) {
//        perror("ERROR reading from socket");
//        exit(1);
//    }
//    cout << buffer << endl;
    }
}