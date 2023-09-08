#ifndef LEFTPAREN_H
#define LEFTPAREN_H

#include "token.h"
#include "constants.h"

using namespace std;

class LeftParen : public Token
{
    public:
        LeftParen();

        void Print(ostream &outs = cout) const;
        TOKEN_TYPES TType(){return LPAREN;}
};

#endif