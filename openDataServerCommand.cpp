

#include "openDataServerCommand.h"
#include "ParamsToUpdate.h"

void* openTread(void* arg)
{
    auto args = static_cast<ParamsToUpdate*>(arg);
    DataReaderServer dataReaderServer(args->getPortServer());
    dataReaderServer.start(args);
    while (true)    {
       // int f = args->getSocketServer();
        string x = args->readFromSock(dataReaderServer.getClint());
        list<string> parse = args->splitInformation(x);
        args->updateMaps(parse);
        if (x == "exit") break;
    }
    return nullptr;
}

int openDataServerCommand::doCommand(list<string>* list, int beginIndex,ParamsToUpdate* paramsToUpdate) {
    paramsToUpdate->intelizeMap();
    string portVal;
    string serverSocket;
    ShutingYard yard(paramsToUpdate->getVarsValues());

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
  //  double port = yard.convertTOExpression(yard.evaluate(portVal))->calculate();
   // double serverSoc = yard.convertTOExpression(yard.evaluate(serverSocket))->calculate();
    //paramsToUpdate->setPortServer(port);

    pthread_create(&thread, nullptr , openTread, paramsToUpdate);
    return beginIndex;
}
