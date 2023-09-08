#ifndef INTEGER_H
#define INTEGER_H

#include "token.h"
#include "constants.h"

using namespace std;

class Integer : public Token
{
    public:
        Integer(double val);
        Integer(string val);

        void Print(ostream &outs = cout) const;
        TOKEN_TYPES TType(){return INTEGER;}
        double IntVal(){return i;}
    private:
        double i;
        string inte;
};

#endif