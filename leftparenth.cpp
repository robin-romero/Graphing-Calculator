#include "leftparenth.h"

LeftParenth::LeftParenth()
{
}

LeftParenth::LeftParenth(string value)
{
    par = value;
}

void LeftParenth::printer(ostream &outs) const
{
    outs << par;
}
