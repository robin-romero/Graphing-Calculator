#include "rpn.h"
#include <iostream>
#include <string>

using namespace std;

RPN::RPN()
{
}

RPN::RPN(Queue<Tokenizer*>& que)
{
    q = que;
}

double RPN::evaluation(Queue<Tokenizer*> token, double x)
{
//    cout << "Postfix que in RPN: " << token;
    //takes in a queue from shunting yard and does all the calculations by putting
    //Doubles into the a stack and popping when an operator is read, calculates the different
    //operators using the popped numbers
    //returns a double as the Y value for plotter;
    double num1;
    double num2;
    double num3;
    double sum;
    double answer;
    Tokenizer* x_holder;
    Tokenizer* temp;
    Tokenizer* hold;
    Tokenizer* result;

    while (!token.isEmpty())
    {
        //checks to see if the queue being passed in is empty
        if(token.first()->TypeOf() == INTEGER)
        {
            //if first token in queue is a number push into the stack
            s.Push(token.pop_front());

        }
        else if(token.first()->TypeOf() == OPERATORS)
        {
            //if first token in queue is an operator pop numbers from stack
            //calculate answer and push answer back into the stack
            temp = s.pop();
            hold = s.pop();

            num1 = static_cast<Integer*>(temp)->IntegerOnly();
            num2 = static_cast<Integer*>(hold)->IntegerOnly();

            sum = static_cast<Operators*>(token.pop_front())->Evaluation(num1, num2);
            result = new Integer(sum);
            s.Push(result);
        }
        else if(token.first()->TypeOf() == UNARY)
        {
            //if first token in queue is a unary operator(sin, cos, tan) using x variable
            //push an inputted number into the stack and calculate the number by using
            //the unary operator evaluation function
            //push result into the stack
            if(static_cast<UnaryOp*>(token.first())->StringOnly() == "x"
               || static_cast<UnaryOp*>(token.first())->StringOnly() == "X")
            {
                s.Push(new Integer(x));
            }
            temp = s.pop();
            num3 = static_cast<Integer*>(temp)->IntegerOnly();
            sum = static_cast<UnaryOp*>(token.pop_front())->functEval(num3);
            result = new Integer(sum);
            s.Push(result);
        }
    }
    //final answer left in the stack must be popped out as y value for plotter
    answer = static_cast<Integer*>(s.pop())->IntegerOnly();

    return answer;
}
