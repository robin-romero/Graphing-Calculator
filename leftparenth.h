#ifndef LEFTPARENTH_H
#define LEFTPARENTH_H
#include <iostream>
#include "tokenizer.h"
#include "constants.h"

using namespace std;


class LeftParenth : public Tokenizer
{
public:
    LeftParenth();
    LeftParenth(string value);
    string StringOnly(){return par;}
//    int TypeOf(){return LEFTPAR;}
    void printer(ostream& outs) const;

private:
    string par;
};

#endif // LEFTPARENTH_H
