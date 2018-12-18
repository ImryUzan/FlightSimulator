

#include <fstream>
#include "LexerClass.h"

list<string> LexerClass::Lexer() {
   //reading from file or console
   string i ="openDataServer 5400 10 connect 127.0.0.1 5402";
    return splitToCommand(i);
}

list<string> LexerClass:: splitToCommand(string line){
    size_t found;
    size_t begining;
    string myVal;
    list<string> resultArray;
    while (line.size() > 0) {
        found = line.find_first_of(" ");
        myVal = line.substr(0, found);
        begining = found + 1;
        line = line.substr(begining, line.size());
        resultArray.push_back(line);
    }
    return resultArray;
}

list<string>  LexerClass:: readFromFile(){
    string command;
    string line;
    string buffer;
    size_t found;
    size_t begining = 0;
    list<string> list;
    ifstream myfile ("Input.txt");
    ifstream myotherfile("Input.txt");
    if((myfile.good())&&(myotherfile.good())) {
        while (getline(myfile, line)) {
            found = line.find_first_of(" ");
            command = line.substr(0, found);
            begining = found + 1;
            line = line.substr(begining, line.size());
            list.push_back(line);
        }
    }
    return list;
}

