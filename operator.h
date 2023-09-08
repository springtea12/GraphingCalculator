#ifndef OPERATOR_H
#define OPERATOR_H

#include "token.h"
#include "constants.h"

using namespace std;

class Operator : public Token
{
    public:
        Operator();
        Operator(string val);

        void Print(ostream &outs = cout) const;
        TOKEN_TYPES TType(){return OPERATOR;}
        string OperString(){return i;}
        int precedence();
    
    private:
        string i;
};

#endif