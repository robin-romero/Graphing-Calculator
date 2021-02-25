#ifndef OPERATORS_H
#define OPERATORS_H
#include<iostream>
#include "tokenizer.h"
#include "integer.h"
#include "constants.h"

using namespace std;

class Operators : public Tokenizer
{
public:
    //Child class from Tokenizer takes in a string and makes it into a
    //operator
    //returns the type of OPERATOR
    Operators();
    Operators(string value);
    int TypeOf();
    double Evaluation(const double& num1, const double& num2);
    void printer(ostream &outs) const;
    string StringOnly(){return op;}
    int precedence();

//private:
    string op;
    int prec;
    int type;
};

#endif // OPERATORS_H
