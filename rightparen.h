#ifndef RIGHTPAREN_H
#define RIGHTPAREN_H

#include "token.h"
#include "constants.h"

using namespace std;

class RightParen : public Token
{
    public:
        RightParen();

        void Print(ostream &outs = cout) const;
        TOKEN_TYPES TType(){return RPAREN;}
};

#endif