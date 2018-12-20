//
// Created by imry on 12/18/18.
//
#include <unistd.h>
#include "ParamsToUpdate.h"

ParamsToUpdate :: ParamsToUpdate(){
}

void ParamsToUpdate :: setPortServer(double thePort){
    portServer = thePort;

}

void ParamsToUpdate :: setPortClient(double thePort){
    portClient = thePort;

}

char* ParamsToUpdate :: setLocalHost(char* theHost){
    localHost = theHost;

}

void ParamsToUpdate :: defineSocketServer(int serverSock){
    serverSocket = serverSock;
}

map<string,double>& ParamsToUpdate :: getVarsValues(){
    return varsValues;
}

map<string,double>* ParamsToUpdate :: getPathsValues(){
    return &pathsMap;
}

map<string,string>* ParamsToUpdate ::getVarToPathsValues() {
    return &fromVarToPathMap;
}

double ParamsToUpdate :: getPortServer(){
    return portServer;

}

int ParamsToUpdate ::getSocketServer() {
    return serverSocket;

}

double ParamsToUpdate :: getPortClient(){
    return portClient;

}

const char* ParamsToUpdate :: getLocalHost(){
    return localHost;

}

int ParamsToUpdate ::getSocketClient() {
    return clientSocket;

}

void ParamsToUpdate :: defineSocketClient(int clientSock){
    clientSocket = clientSock;
}

string ParamsToUpdate::readFromSock(int nuberclient) const {
//todo while
    char buffer[1000];
    ssize_t bytes_read;
    bytes_read = read(nuberclient, buffer, 999);
    if (bytes_read < 0) {
        // TODO error
    }   else if (bytes_read == 0)   {
        // TODO connection closed
        int y = 0;
    } else  {
        buffer[bytes_read] = NULL;
        //ללללללללללללללממממממממממממממממחחחחחחחחחחחחחחוווווווווווווווווווווקקקקקק את זה
        cout << buffer;
        return buffer;
    }
    return "";
}

list<string>  ParamsToUpdate::splitInformation(string toParse){
    size_t found;
    size_t begining;
    string myVal;
    list<string> resultArray;
    while (toParse.size()> 0) {

        found = toParse.find_first_of("\n");
        begining = found + 1;
        toParse = toParse.substr(begining, toParse.size()-1);

        found = toParse.find_first_of(",");
        myVal = toParse.substr(0, found);
        begining = found + 1;
        toParse = toParse.substr(begining, toParse.size()-1);
        found = myVal.find("\n");
        if(found != std::string::npos){
            myVal = myVal.substr(0, found);
            resultArray.push_back(myVal);
            break;
        }

        resultArray.push_back(myVal);

    }
    return resultArray;
}

void ParamsToUpdate:: updateMaps(list<string> parsingStr){
    double  val = atof(parsingStr.back().c_str());
    this->pathsMap.at("/engines/engine/rpm") = val;
    parsingStr.pop_back();
    val = atof(parsingStr.back().c_str());
    this->pathsMap.at("/controls/engines/engine/throttle")=val;
    parsingStr.pop_back();
    val = atof(parsingStr.back().c_str());
    this->pathsMap.at("/controls/flight/flaps")=val;
    parsingStr.pop_back();
    val = atof(parsingStr.back().c_str());
    this->pathsMap.at("/controls/flight/rudder")=val;
    parsingStr.pop_back();
    val = atof(parsingStr.back().c_str());
    this->pathsMap.at("/controls/flight/elevator")=val;
    parsingStr.pop_back();
    val = atof(parsingStr.back().c_str());
    this->pathsMap.at("/controls/flight/aileron")=val;
    parsingStr.pop_back();
    val = atof(parsingStr.back().c_str());
    this->pathsMap.at("/instrumentation/vertical-speed-indicator/indicated-speed-fpm")=val;
    parsingStr.pop_back();
    val = atof(parsingStr.back().c_str());
    this->pathsMap.at("/instrumentation/turn-indicator/indicated-turn-rate")=val;
    parsingStr.pop_back();
    val = atof(parsingStr.back().c_str());
    this->pathsMap.at("/instrumentation/slip-skid-ball/indicated-slip-skid")=val;
    parsingStr.pop_back();
    val = atof(parsingStr.back().c_str());
    this->pathsMap.at("/instrumentation/magnetic-compass/indicated-heading-deg")=val;
    parsingStr.pop_back();
    val = atof(parsingStr.back().c_str());
    this->pathsMap.at("/instrumentation/heading-indicator/indicated-heading-deg")=val;
    parsingStr.pop_back();
    val = atof(parsingStr.back().c_str());
    this->pathsMap.at("/instrumentation/gps/indicated-vertical-speed")=val;
    parsingStr.pop_back();
    val = atof(parsingStr.back().c_str());
    this->pathsMap.at("/instrumentation/gps/indicated-ground-speed-kt")=val;
    parsingStr.pop_back();
    val = atof(parsingStr.back().c_str());
    this->pathsMap.at("/instrumentation/gps/indicated-altitude-ft")=val;
    parsingStr.pop_back();
    val = atof(parsingStr.back().c_str());
    this->pathsMap.at("/instrumentation/encoder/pressure-alt-ft")=val;
    parsingStr.pop_back();
    val = atof(parsingStr.back().c_str());
    this->pathsMap.at("/instrumentation/encoder/indicated-altitude-ft")=val;
    parsingStr.pop_back();
    val = atof(parsingStr.back().c_str());
    this->pathsMap.at("/instrumentation/attitude-indicator/internal-roll-deg")=val;
    parsingStr.pop_back();
    val = atof(parsingStr.back().c_str());
    this->pathsMap.at("/instrumentation/attitude-indicator/internal-pitch-deg")=val;
    parsingStr.pop_back();
    val = atof(parsingStr.back().c_str());
    this->pathsMap.at("/instrumentation/attitude-indicator/indicated-roll-deg")=val;
    parsingStr.pop_back();
    val = atof(parsingStr.back().c_str());
    this->pathsMap.at("/instrumentation/attitude-indicator/indicated-pitch-deg")=val;
    parsingStr.pop_back();
    val = atof(parsingStr.back().c_str());
    this->pathsMap.at("/instrumentation/altimeter/pressure-alt-ft")=val;
    parsingStr.pop_back();
    val = atof(parsingStr.back().c_str());
    this->pathsMap.at("/instrumentation/altimeter/indicated-altitude-ft")=val;
    parsingStr.pop_back();
    val = atof(parsingStr.back().c_str());
    this->pathsMap.at("/instrumentation/airspeed-indicator/indicated-speed-kt")=val;
    parsingStr.pop_back();
}

void ParamsToUpdate::intelizeMap(){
    this->pathsMap.insert(pair<string,double>("/instrumentation/airspeed-indicator/indicated-speed-kt",0));
    this->pathsMap.insert(pair<string,double>("/instrumentation/altimeter/indicated-altitude-ft",0));
    this->pathsMap.insert(pair<string,double>("/instrumentation/altimeter/pressure-alt-ft",0));
    this->pathsMap.insert(pair<string,double>("/instrumentation/attitude-indicator/indicated-pitch-deg",0));
    this->pathsMap.insert(pair<string,double>("/instrumentation/attitude-indicator/indicated-roll-deg",0));
    this->pathsMap.insert(pair<string,double>("/instrumentation/attitude-indicator/internal-pitch-deg",0));
    this->pathsMap.insert(pair<string,double>("/instrumentation/attitude-indicator/internal-roll-deg",0));
    this->pathsMap.insert(pair<string,double>("/instrumentation/encoder/indicated-altitude-ft",0));
    this->pathsMap.insert(pair<string,double>("/instrumentation/encoder/pressure-alt-ft",0));
    this->pathsMap.insert(pair<string,double>("/instrumentation/gps/indicated-altitude-ft",0));
    this->pathsMap.insert(pair<string,double>("/instrumentation/gps/indicated-ground-speed-kt",0));
    this->pathsMap.insert(pair<string,double>("/instrumentation/gps/indicated-vertical-speed",0));
    this->pathsMap.insert(pair<string,double>("/instrumentation/heading-indicator/indicated-heading-deg",0));
    this->pathsMap.insert(pair<string,double>("/instrumentation/magnetic-compass/indicated-heading-deg",0));
    this->pathsMap.insert(pair<string,double>("/instrumentation/slip-skid-ball/indicated-slip-skid",0));
    this->pathsMap.insert(pair<string,double>("/instrumentation/turn-indicator/indicated-turn-rate",0));
    this->pathsMap.insert(pair<string,double>("/instrumentation/vertical-speed-indicator/indicated-speed-fpm",0));
    this->pathsMap.insert(pair<string,double>("/controls/flight/aileron",0));
    this->pathsMap.insert(pair<string,double>("/controls/flight/elevator",0));
    this->pathsMap.insert(pair<string,double>("/controls/flight/rudder",0));
    this->pathsMap.insert(pair<string,double>("/controls/flight/flaps",0));
    this->pathsMap.insert(pair<string,double>("/controls/engines/engine/throttle",0));
    this->pathsMap.insert(pair<string,double>("/engines/engine/rpm",0));
}

void ParamsToUpdate:: sendMsg(){
    /* Now ask for a message from the user, this message
   * will be read by server
*/
 /*   int n;
    char buffer[1024];
    //printf("Please enter the message: ");
    bzero(buffer,1024);
    //fgets(buffer,255,stdin);

    *//* Send message to the server *//*
    size_t lenPath = path.size();
    *//*for(int i= 0;i<lenPath;i++){
        buffer[i]=path[i];
    }*//*
    n = write(this->serverSocket,&path,lenPath);

    if (n < 0) {
        __throw_bad_exception();
    }*/
}

void ParamsToUpdate::addValVarsValues(string varName, double val) {
    varsValues.insert(pair<string, double>(varName, val));
}

void ParamsToUpdate::addValPathsMap(string varName, double val) {
    pathsMap.insert(pair<string, double>(varName, val));
}

void ParamsToUpdate::addValFromVarToPathMap(string varName, string varPath) {
   fromVarToPathMap.insert(pair<string, string>(varName, varPath));
}

void ParamsToUpdate::updateAllMaps() {
    map<string, string>::iterator it = this->fromVarToPathMap.begin();
    for (it; it != this->fromVarToPathMap.end(); ++it) {
        string path = (*it).second;
        string varName = (*it).first;
        double val = this->pathsMap.at(path);
        this->varsValues.at(varName) = val;
    }
}