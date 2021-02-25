#include "rightparenth.h"

RightParenth::RightParenth()
{
}

RightParenth::RightParenth(string value)
{
    Rpar = value;
}

void RightParenth::printer(ostream &outs) const
{
    outs << Rpar;
}
