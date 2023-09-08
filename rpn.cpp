#include "rpn.h"

RPN::RPN(){}

RPN::RPN(const Queue<Token*>& input_q)
{
    queue = input_q;
}

void RPN::set_input(const Queue<Token*>& input_q)
{
    queue = input_q;
}

double RPN::operator()(double value)
{
    return rpn(value);
}

double RPN::rpn(double value)
{
    Stack<Token*> output;
    Queue<Token*> q = queue;
    while(!q.empty())
    {
        Token* qTop = q.front();
        q.pop();
        if(qTop->TType() == INTEGER)
        {
            output.push(qTop);
        }
        else if(qTop->TType() == OPERATOR)
        {
            Token* right = output.top();
            output.pop();
            Token* left = output.top();
            output.pop();
            string operation = static_cast<Operator*>(qTop)->OperString();
            if(operation == "+")
                output.push(new Integer(static_cast<Integer*>(left)->IntVal() + static_cast<Integer*>(right)->IntVal()));
            else if(operation == "-")
                output.push(new Integer(static_cast<Integer*>(left)->IntVal() - static_cast<Integer*>(right)->IntVal()));
            else if(operation == "*")
                output.push(new Integer(static_cast<Integer*>(left)->IntVal() * static_cast<Integer*>(right)->IntVal()));
            else if(operation == "/")
                output.push(new Integer(static_cast<Integer*>(left)->IntVal() / static_cast<Integer*>(right)->IntVal()));
            else if(operation == "^")
                output.push(new Integer(pow(static_cast<Integer*>(left)->IntVal(), static_cast<Integer*>(right)->IntVal())));
        }
        else if(qTop->TType() == FUNCTION)
        {
            string temp = static_cast<Function*>(qTop)->FuncString();
            if(temp == "x" || temp == "X")
                output.push(new Integer(value));
            else if(temp == "Sin" || temp == "sin")
            {
                Token* right = output.top();
                output.pop();
                double val = sin(static_cast<Integer*>(right)->IntVal());
                output.push(new Integer(val));
            }
            else if(temp == "Cos" || temp == "cos")
            {
                Token* right = output.top();
                output.pop();
                output.push(new Integer(cos(static_cast<Integer*>(right)->IntVal())));
            }
            else if(temp == "Tan" || temp == "tan")
            {
                Token* right = output.top();
                output.pop();
                output.push(new Integer(tan(static_cast<Integer*>(right)->IntVal())));
            }
            else if(temp == "max" || temp == "Max")
            {
                Token* right = output.top();
                output.pop();
                Token* left = output.top();
                output.pop();
                output.push(new Integer(max(static_cast<Integer*>(right)->IntVal(), static_cast<Integer*>(left)->IntVal())));
            }
            else if(temp == "log" || temp == "Log")
            {
                Token* right = output.top();
                output.pop();
                output.push(new Integer(log10(static_cast<Integer*>(right)->IntVal())));
            }
            else if(temp == "ln" || temp == "Ln")
            {
                Token* right = output.top();
                output.pop();
                output.push(new Integer(log(static_cast<Integer*>(right)->IntVal())));
            }
            else if(temp == "abs")
            {
                Token* right = output.top();
                output.pop();
                output.push(new Integer(abs(static_cast<Integer*>(right)->IntVal())));
            }
        }
    }
    return static_cast<Integer*>(output.top())->IntVal();
}