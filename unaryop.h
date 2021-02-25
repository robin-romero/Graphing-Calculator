#ifndef UNARYOP_H
#define UNARYOP_H
#include <string>
#include "tokenizer.h"
#include "constants.h"
#include "operatorprec.h"
#include <iostream>

using namespace std;

class UnaryOp : public Tokenizer
{
public:
    //Child class from Tokenizer takes in a string and makes it into a
    //Unary operator
    //returns the type of Unary Operator
    UnaryOp();
    UnaryOp(string value);
    double functEval(const double& num);
    void printer(ostream& outs) const;
    int TypeOf() {return UNARY;}
    string StringOnly() {return unary;}
    int precedence();

private:
    string unary;
    int prec;
};

#endif // UNARYOP_H
