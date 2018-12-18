#include <iostream>
#include "string"
#include "ShutingYard.h"
#include "DataReaderServer.h"
#include "openDataServerCommand.h"

using namespace std;
int main() {
  /*  string s = "5+6*3";
    string s1 = "3*(0-1)+(0-1)";
   // string s1 = "5+(0-1)";
    ShutingYard c;
   // c.evaluate(s1);
    ShutingYard c1;
    //c1.evaluate(s1);
    //stack <string>* ggg = c.evaluate(s);
    std::cout << c.convertTOExpression(c.evaluate(s))->Calculate() << std::endl;*/
    ParamsToUpdate* args = new ParamsToUpdate;
    //list<string>* list, int beginIndex,ParamsToUpdate* paramsToUpdate
    list<string> list1;
    list1.push_back("openDataServer");
    list1.push_back("5400");
    list1.push_back("10");
    openDataServerCommand* vvv = new openDataServerCommand();
    vvv->doCommand(&list1,0,args);
    DataReaderServer drs(5400);
    drs.start(args);
   // args.readFromSock();
    return 0;
   // return 0;
}