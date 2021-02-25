#include "tokenizer.h"
#include "unaryop.h"
#include "operators.h"
#include "integer.h"
#include <algorithm>

//parent class of operator, integer, and unary op
//does the conversion of string to tokens(If i can freaking understand and do this shite)
Tokenizer::Tokenizer()
{
}

Tokenizer::Tokenizer(string math)
{
   value = math;
}

ostream& operator <<(ostream& outs, const Tokenizer& print)
{
    print.printer(outs);
    return outs;
}

ostream& operator <<(ostream& outs, Tokenizer* print)
{
    print->printer(outs);
    return outs;
}

void Tokenizer::printer(ostream& outs) const
{
    outs << "Don't Print Me" << endl;
}
