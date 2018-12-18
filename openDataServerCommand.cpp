

#include "openDataServerCommand.h"
#include "ParamsToUpdate.h"

void* openTread(void* arg)
{
    ParamsToUpdate* args = (ParamsToUpdate*)arg;
    DataReaderServer dataReaderServer(args->getPort());
    dataReaderServer.start(args);
    while (true)    {
        auto x = args->readFromSock(args->getSocket());
        std::cout<<"ppp"<<std::endl;
        if (x == "exit") break;
    }
    return nullptr;
}

int openDataServerCommand::doCommand(list<string>* list, int beginIndex,ParamsToUpdate* paramsToUpdate) {
    string portVal;
    string serverSocket;
    ShutingYard yard;
    pthread_t thread;

    
  /*  int howMuchArgs = 0;
    if(beginIndex > list->size()){
        throw invalid_argument("no parameters for command");
    }
    std::list<string>::iterator it = list->begin();
    std::advance(it, beginIndex);
    while (howMuchArgs < 2){
        if(!it->empty() && howMuchArgs < 1){
            portVal = it.operator*();
            beginIndex++;
        } else  if(!it->empty() && howMuchArgs < 2){
            serverSocket = it.operator*();
            beginIndex++;
        }
    howMuchArgs++;
    }*/
    double port = yard.convertTOExpression(yard.evaluate(portVal))->Calculate();
    double serverSoc = yard.convertTOExpression(yard.evaluate(serverSocket))->Calculate();
    paramsToUpdate->setPort(port);
    pthread_create(&thread, nullptr , openTread, paramsToUpdate);
    return beginIndex;
}