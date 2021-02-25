#ifndef INTEGER_H
#define INTEGER_H
#include<string>
#include "tokenizer.h"
#include "constants.h"
#include <iostream>

using namespace std;

class Integer : public Tokenizer
{
public:
    //Child class from Tokenizer takes in a number and makes it into a
    //double even though it is called an Integer class
    //returns the type of Double
    Integer();
    Integer(double value);
    Integer(string value);
    void printer(ostream& outs) const;
    int TypeOf() {return INTEGER;}
    double IntegerOnly(){return i;}

private:
    double i;
};

#endif // INTEGER_H
