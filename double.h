#ifndef DOUBLE_H
#define DOUBLE_H
#include <iostream>
#include<string>
#include "tokenizer.h"

using namespace std;

class Double : public Tokenizer
{
public:
    Double();
    Double(double value);
    Double(string value);
    virtual void printer(ostream& outs) const;
    int TypeOf(){return DOUBLE;}
    double DoubleOnly(){return d;}

private:
    double d;
};

#endif // DOUBLE_H
