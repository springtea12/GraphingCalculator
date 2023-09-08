#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <iomanip>
#include "constants.h"

using namespace std;

class Token
{
    public:
    Token();
    virtual void Print(ostream &outs) const;
    virtual TOKEN_TYPES TType(){};
    friend ostream& operator <<(ostream& outs, const Token* token);
    friend ostream& operator <<(ostream& outs, const Token &token);
};

#endif //TOKEN_H