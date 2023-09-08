#ifndef FUNCTION_H
#define FUNCTION_H

#include "token.h"
#include "constants.h"

using namespace std;

class Function : public Token
{
    public:
        Function(string value);

        void Print(ostream &outs = cout) const;
        TOKEN_TYPES TType(){return FUNCTION;}
        string FuncString(){return func;}

    private:
        string func;
};

#endif 