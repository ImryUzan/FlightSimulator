#include <string>
#include <list>
#include <sstream>
#include <cstdio>
using namespace std;

#ifndef SIMULATOR_CONVERTTOCOMMAND_H
#define SIMULATOR_CONVERTTOCOMMAND_H
class LexerClass{

public:

    list<string> Lexer();
    list<string> splitToCommand (string line);
    list<list<string>> readFromFile();
};

#endif //SIMULATOR_CONVERTTOCOMMAND_H
