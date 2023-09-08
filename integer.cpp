#include "integer.h"

Integer::Integer(double val)
{
    i = val;
    inte = to_string(val);
}

Integer::Integer(string val)
{
    inte = val;
}

void Integer::Print(ostream &outs) const
{
    outs << i;
}
