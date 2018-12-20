
#include "DefineVarCommand.h"


int DefineVarCommand::doCommand(list<string>* list, int beginIndex,ParamsToUpdate* paramsToUpdate){
    string temp;
    string varName;
    string pathVal;
    double varVal;
    ::list<string>::iterator newIt = list->begin();
    advance(newIt,1);
    varName = *newIt;
    for(newIt; newIt != list->end(); ++newIt) {

        temp = *newIt;
        //if var is bind
        if (temp.compare("bind") == 0) {
            newIt++;

            paramsToUpdate->addValFromVarToPathMap(varName,newIt.operator*());
            paramsToUpdate->updateAllMaps();
            return 0;

            //if var isn't bind
        } else {
            string valueExp = "";
            valueExp = valueExp + *newIt + "";
            varVal = convertToDouble(valueExp);
            paramsToUpdate->addValVarsValues(varName,varVal);
        }
    }
    return 0;
}
DefineVarCommand:: DefineVarCommand(){

}

/*double DefineVarCommand:: GetValue(){
    return this->varVal;
}

void DefineVarCommand:: SetValue(double newVal){
    this->varVal = newVal;
    isBinded = false;
}*/

//check if worksssssssssssssssssssssssssssssssssssssssssssssss
double DefineVarCommand:: convertToDouble(string value){
    int i = 0;
    bool afterPoint = false;
    double float_num = 10;
    double val = 0;
    while (i < value.length() && isdigit(value[i])
           || value[i] == '.') {
        if (value[i] == '.') {
            afterPoint = true;
        } else {
            if (!afterPoint)
                val = (val * 10) + (value[i] - '0');
            else {
                val += (value[i] - '0') / float_num;
                float_num *= 10;
            }
        }
        i++;
    }
    return val;
}