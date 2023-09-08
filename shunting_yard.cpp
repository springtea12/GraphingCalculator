#include "shunting_yard.h"
#include <string>
#include <cmath>

ShuntingYard::ShuntingYard(){}

ShuntingYard::ShuntingYard(const Queue<Token*>& input_q)
{
    queue = input_q;
}

void ShuntingYard::infix(const Queue<Token*>& input_q)
{
    queue = input_q;
}

Queue<Token*> ShuntingYard::postfix()
{
    return shunting_yard();
}

Queue<Token*> ShuntingYard::postfix(const Queue<Token*>& input_q)
{
    queue = input_q;
    return shunting_yard();
}

Queue<Token*> ShuntingYard::shunting_yard()
{
    Queue<Token*> output;
    Queue<Token*> infix = queue;
    Stack<Token*> opers;
    
    while(!infix.empty())
    {
        Token* temp = infix.front();
        infix.pop();
        if(temp->TType() == INTEGER)
            output.push(temp);
        else if(temp->TType() == FUNCTION)
            opers.push(temp);
        else if(temp->TType() == OPERATOR)
        {
            while(!opers.empty() 
            && (opers.top()->TType() != LPAREN && opers.top()->TType() == OPERATOR)
            && ((static_cast<Operator*>(opers.top())->precedence() > static_cast<Operator*>(temp)->precedence()) 
            || (static_cast<Operator*>(opers.top())->precedence() >= static_cast<Operator*>(temp)->precedence() 
            && static_cast<Operator*>(temp)->OperString() != "^")))
            {
                output.push(opers.top());
                opers.pop();
            }
            opers.push(temp);
        }
        else if(temp->TType() == LPAREN)
        {
            opers.push(temp);
        }
        else if(temp->TType() == RPAREN)
        {
            while(!opers.empty() && (opers.top())->TType() != LPAREN)
            {
                output.push(opers.top());
                opers.pop();
            }
            opers.pop();
            if(!opers.empty() && (opers.top())->TType() == FUNCTION)
            {
                output.push(opers.top());
                opers.pop();
            }
        }
    }
    while(!opers.empty())
    {
        output.push(opers.top());
        opers.pop();
    }
    return output;
}

ShuntingYard::ShuntingYard(string input)
{
    int count = 0;
    Queue<Token*> infix;
    for(int i = 0; i < input.length(); i++)
    {
        char temp = input[i];
        if(temp - '0' >= 0 && temp-'0' <= 9)
        {
            double value = temp - '0';
            i++;
            int power = 1;
            temp = input[i];
            while(temp - '0' >= 0 && temp-'0' <=9)
            {
                value *= pow(10, power);
                value += temp-'0';
                power += 1;
                i++;
            }
            i--;
            infix.push(new Integer(value));
        }
        else if(temp == '+')
            infix.push(new Operator("+"));
        else if(temp == '-')
            infix.push(new Operator("-"));
        else if(temp == '/')
            infix.push(new Operator("/"));
        else if(temp == '*')
            infix.push(new Operator("*"));
        else if(temp == '^')
            infix.push(new Operator("^"));
        else if(temp == 'x' || temp == 'X')
            infix.push(new Function("x"));
        else if(temp == 's' || temp == 'S')
        {
            infix.push(new Function("sin"));
            i += 2;
        }
        else if(temp == 'c' || temp == 'C')
        {
            infix.push(new Function("cos"));
            i += 2;
        }
        else if(temp == 't' || temp == 'T')
        {
            infix.push(new Function("tan"));
            i += 2;
        }
        else if(temp == 'm' || temp == 'M')
        {
            infix.push(new Function("Max"));
            i += 2;
        }
        else if(temp == '(')
            infix.push(new LeftParen());
        else if(temp == ')')
            infix.push(new RightParen());
        else if(temp == 'p')
        {
            infix.push(new Integer(3.14));
            i += 1;
        }
        else if(temp == 'e')
            infix.push(new Integer(2.718));
        else if((temp == 'L'|| temp == 'l') && input[i+1] == 'o')
        {
            infix.push(new Function("log"));
            i += 2;
        }
        else if((temp == 'l' || temp == 'L') && input[i+1] == 'n')
        {
            infix.push(new Function("ln"));
            i += 1;
        }
        else if(temp == 'a')
        {
            infix.push(new Function("abs"));
            i += 2;
        }
    }
    queue = infix;
}