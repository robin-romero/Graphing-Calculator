#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <iostream>
#include "constants.h"
#include "queue.h"
#include <string>

using namespace std;

class Tokenizer
{
public:
    Tokenizer();
    Tokenizer(string math);
    friend ostream& operator <<(ostream& outs, const Tokenizer& print);
    friend ostream& operator <<(ostream& outs, Tokenizer* print);
    virtual void printer(ostream& outs) const;
    virtual int TypeOf(){}
    virtual int precedence(){}

private:
    string value;
};

#endif // TOKENIZER_H
