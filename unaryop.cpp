#include "unaryop.h"
#include <math.h>
#include <iostream>

using namespace std;

//#define PI 3.14159265
//to use sin, cos, tan
//param = 30.0;
//result = sin (param*PI/180);

UnaryOp::UnaryOp()
{
}

UnaryOp::UnaryOp(string value)
{
    unary = value;
}

//does the evaluations of sin cos and tan
double UnaryOp::functEval(const double& num)
{
    double sum;

    if(unary == "sin" || unary == "Sin")
    {
        sum = sin(num);
    }
    else if(unary == "cos" || unary == "Cos")
    {
        sum = cos(num);
    }
    else if(unary == "tan" || unary == "Tan")
    {
        sum = tan(num);
    }
    else if(unary == "x" || unary == "X")
    {
        sum = num;
    }

    return sum;
}

int UnaryOp::precedence()
{
    if(unary == "sin" || unary == "Sin")
    {
        prec = SINCOSTAN;
    }
    else if(unary == "cos" || unary == "Cos")
    {
        prec = SINCOSTAN;
    }
    else if(unary == "tan" || unary == "Tan")
    {
        prec = SINCOSTAN;
    }

    return prec;
}

void UnaryOp::printer(ostream &outs) const
{
    outs << unary;
}
