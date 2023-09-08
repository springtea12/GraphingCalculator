#include "operator.h"

Operator::Operator(){}

Operator::Operator(string val)
{
    i = val;
}

void Operator::Print(ostream &outs) const
{
    outs << i;
}

int Operator::precedence()
{
    if(i == "+" || i == "-")
        return 1;
    else if(i == "/" || i == "*")
        return 2;
    else if(i == "^")
        return 3;
    else
        return 4;
}