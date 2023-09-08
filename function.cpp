#include "function.h"

Function::Function(string value)
{
    func = value;
}

void Function::Print(ostream &outs) const
{
    outs << func;
}
