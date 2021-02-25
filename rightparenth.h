#ifndef RIGHTPARENTH_H
#define RIGHTPARENTH_H
#include <iostream>
#include "tokenizer.h"
#include "constants.h"

using namespace std;

class RightParenth : public Tokenizer
{
public:
    RightParenth();
    RightParenth(string value);
    string StringOnly() {return Rpar;}
    int TypeOf(){return RIGHTPAR;}
    void printer(ostream& outs) const;

private:
    string Rpar;
};

#endif // RIGHTPARENTH_H
