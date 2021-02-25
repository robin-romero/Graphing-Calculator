#include "integer.h"

Integer::Integer()
{
}

Integer::Integer(double value)
{
    i = value;
}

Integer::Integer(string value)
{
    i = atoi(value.c_str());
}

void Integer::printer(ostream& outs) const
{
    outs << i;
}
