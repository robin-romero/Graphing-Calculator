#include "operators.h"
#include "operatorprec.h"
#include "constants.h"
#include <math.h>


Operators::Operators()
{
    op="NO_OP";
}

Operators::Operators(string value)
{
    op = value;
}

double Operators::Evaluation(const double& num1, const double& num2)
{
    double sum;
    if(op == "+")
    {
        sum = num2 + num1;
    }
    else if(op == "-")
    {
        sum = num2 - num1;
    }
    else if(op == "*")
    {
        sum = num2 * num1;
    }
    else if(op == "/")
    {
        sum = num2 / num1;
    }
    else if(op == "^")
    {
        sum = pow(num2, num1);
    }

    return sum;
}

int Operators::precedence()
{
    if(op == "+")
    {
        prec = ADDSUB;
    }
    else if(op == "-")
    {
        prec = ADDSUB;
    }
    else if(op == "*")
    {
        prec = MULTDIV;
    }
    else if(op == "/")
    {
        prec = MULTDIV;
    }
    else if(op == "^")
    {
        prec = EXPONENT;
    }
    else if(op == "(")
    {
        prec = LEFTPAR;
    }
    else if(op == ")")
    {
        prec = RIGHTPAR;
    }

    return prec;
}

int Operators::TypeOf()
{
    if(op == "(")
    {
        type = LEFTPAR;
    }
    else if(op == ")")
    {
        type = RIGHTPAR;
    }
    else
    {
        type = OPERATORS;
    }
    return type;
}

void Operators::printer(ostream &outs) const
{
    outs << op;
}


