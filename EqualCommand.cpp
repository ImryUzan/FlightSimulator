//
// Created by imry on 12/19/18.
//

#include "EqualCommand.h"

int EqualCommand::doCommand(list<string> list1, map<string, double> *map1, int index) {
    string valueExpr="";
    double val;
    //update the var in our map to according to the user change
    list<string>::iterator newIt = list1.begin();
    for(newIt; newIt != list1.end(); ++newIt){

            valueExpr=valueExpr+newIt.operator*()+"";

        }
        //TODO sent value to expression and save in val
        val = map1->at(list1.front());

        //TODO check if it bind
      /*  if(this->server1->getPath(vector1[index][0])!= ""){
            string s = "set ";
            s = s+this->server1->getPath(vector1[index][0]);
            //s = s+" "+vector1[index][0]+"\r\n";
            s = s+" "+to_string(val)+"\r\n";
            this->DataClient->setData(s);
        }*/

        return 0;
    }