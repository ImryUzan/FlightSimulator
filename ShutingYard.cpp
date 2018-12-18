// CPP program to evaluate a given
// expression where tokens are
// separated by space.
#include "ShutingYard.h"
#include "Plus.h"
#include "Minus.h"
#include "Mult.h"
#include "Div.h"
#include "Num.h"

// Function to find precedence of
// operators.

int ShutingYard:: precedence(char op){
    if(op == '+'||op == '-')
        return 1;
    if(op == '*'||op == '/')
        return 2;
    if ((op == ' ') || (op == '(') || (op == ')'))
        return -1;
    //has to be a number
    return 0;
}

// Function to perform arithmetic operations.
int ShutingYard:: applyOp(int a, int b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}
//1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
// Function that returns value of
// expression after evaluation.
stack <string>* ShutingYard:: evaluate(string tokens){
    int i;
    string val;
    // stack to store integer values.
   // stack <string> values;

    // stack to store operators.
    stack <char> ops;
    stack <char> opsTemp;

    for(i = 0; i < tokens.length(); i++){

        // Current token is a whitespace,
        // skip it.
        if(tokens[i] == ' ')
            continue;

            // Current token is an opening
            // brace, push it to 'ops'
        else if(tokens[i] == '('){
            ops.push(tokens[i]);
        }

            // Current token is a number, push
            // it to stack for numbers.
            else if(precedence(tokens[i]) == 0){
                val = tokens[i];
            while(i+1 < tokens.length() && precedence(tokens[i+1]) == 0)
                {
                    val = val + tokens[i];
                    i++;
                }
                values.push(val);
            }


            // Closing brace encountered, solve
            // entire brace.
        else if(tokens[i] == ')')
        {
            while(!ops.empty() && ops.top() != '(')
            {
                string val2;
                val2.push_back(ops.top());
                ops.pop();
                values.push(val2);

            }

            // pop opening brace.
            ops.pop();
        }

            // Current token is an operator.
        else
        {
            // While top of 'ops' has same or greater
            // precedence to current token, which
            // is an operator. Apply operator on top
            // of 'ops' to top two elements in values stack.


            while(!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])){

            /*    int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop(*/

                char op = ops.top();
                ops.pop();
                opsTemp.push(op);

                //values.push(applyOp(val1, val2, op));
            }
            // Push current token to 'ops'.
            ops.push(tokens[i]);
            if(!opsTemp.empty()){
                while (!opsTemp.empty()){
                    char opTemp = opsTemp.top();
                    opsTemp.pop();
                    ops.push(opTemp);

                }
            }
        }
    }

    // Entire expression has been parsed at this
    // point, apply remaining ops to remaining
    // values.
    while(!ops.empty()){
        char opsVal = ops.top();
        ops.pop();
        string insertToValue;
        insertToValue.push_back(opsVal);
        values.push(insertToValue);
        //ops.push(opTemp);
       /* int val2 = values.top();
        values.pop();

        int val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));*/
    }

    // Top of 'values' contains result, return it.
    return &values;
}

Expression* ShutingYard:: convertTOExpression(stack <string>* values){
    while (!values->empty()) {
        string check = values->top();
        if (check == "+") {
            values->pop();
            Expression *right = convertTOExpression(values);
            values->pop();
            Expression *left = convertTOExpression(values);
            return new Plus(left, right);
        } else if (check == "-") {
            values->pop();
            Expression *right = convertTOExpression(values);
            values->pop();
            Expression *left = convertTOExpression(values);
            return new Minus(left, right);
        } else if (check == "*") {
            values->pop();
            Expression *right = convertTOExpression(values);
            values->pop();
            Expression *left = convertTOExpression(values);
            return new Mult(left, right);
        } else if (check == "/") {
            values->pop();
            Expression *right = convertTOExpression(values);
            values->pop();
            Expression *left = convertTOExpression(values);
            return new Div(left, right);
        } else {
            string num = values->top();
            //  values->pop();
            return new Num(num);
        }
    }
}
/*

Expression* ShutingYard:: convertTOExpression(stack <string>* values){
    int count = 0;
    string save1;
    string save0;
    string save2;
    int howManyRuns = 0;
    while(!values->empty() && howManyRuns !=3){
        char v = values->top().at(0);
        if((precedence(v) == 1) || (precedence(v) == 2)){
            if(count == 0){
                save0 = values->top();
                values->pop();
               // count++;
            }
            else if (count == 1){
                save1 = values->top();
                values->pop();
                //count++;
            }
            else if (count == 2){
                save2 = values->top();
                values->pop();
                break;
            }
            else {
                break;
            }
        }
        count++;
        howManyRuns++;
    }
     if (count == 1) {
         values->push(save1);
         values->push(save0);
         while (!values->empty()) {
             string check = values->top();
             if (check == "+") {
                 values->pop();
                 Expression *right = convertTOExpression(values);
                 values->pop();
                 Expression *left = convertTOExpression(values);
                 return new Plus(left, right);
             } else if (check == "-") {
                 values->pop();
                 Expression *right = convertTOExpression(values);
                 values->pop();
                 Expression *left = convertTOExpression(values);
                 return new Minus(left, right);
             } else if (check == "*") {
                 values->pop();
                 Expression *right = convertTOExpression(values);
                 values->pop();
                 Expression *left = convertTOExpression(values);
                 return new Mult(left, right);
             } else if (check == "/") {
                 values->pop();
                 Expression *right = convertTOExpression(values);
                 values->pop();
                 Expression *left = convertTOExpression(values);
                 return new Div(left, right);
             } else {
                 string num = values->top();
                 //  values->pop();
                 return new Num(num);
             }
         }
     }
     if((count == 2) || (count == 0)) {
         if(count == 2) {
             values->push(save2);
             values->push(save1);
         }
         values->push(save0);
         while (!values->empty()) {
             string check = values->top();
             if (check == "+") {
                 values->pop();
                 string save = values->top();
                 if (save == "+" || save == "*" || save == "/" || save == "-") {
                     values->pop();
                     Expression *left = convertTOExpression(values);
                     values->pop();
                     values->push(save);
                     Expression *right = convertTOExpression(values);
                     return new Plus(left, right);
                 } else {
                     Expression *right = convertTOExpression(values);
                     values->pop();
                     Expression *left = convertTOExpression(values);
                     return new Plus(left, right);
                 }
             } else if (check == "-") {
                 values->pop();
                 string save = values->top();
                 if (save == "+" || save == "*" || save == "/" || save == "-") {
                     values->pop();
                     Expression *left = convertTOExpression(values);
                     values->pop();
                     values->push(save);
                     Expression *right = convertTOExpression(values);
                     return new Minus(left, right);
                 } else {
                     Expression *right = convertTOExpression(values);
                     values->pop();
                     Expression *left = convertTOExpression(values);
                     return new Minus(left, right);
                 }
             } else if (check == "*") {
                 values->pop();
                 string save = values->top();
                 if (save == "+" || save == "*" || save == "/" || save == "-") {
                     values->pop();
                     Expression *left = convertTOExpression(values);
                     values->pop();
                     values->push(save);
                     Expression *right = convertTOExpression(values);
                     return new Mult(left, right);
                 } else {
                     Expression *right = convertTOExpression(values);
                     values->pop();
                     Expression *left = convertTOExpression(values);
                     return new Mult(left, right);
                 }

             } else if (check == "/") {
                 values->pop();
                 string save = values->top();
                 values->pop();
                 Expression *right = convertTOExpression(values);
                 values->pop();
                 values->push(save);
                 Expression *left = convertTOExpression(values);
                 return new Div(left, right);
             } else {
                 string num = values->top();
                 //  values->pop();
                 return new Num(num);
             }
         }
     }
}*/
