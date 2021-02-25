#include "syard.h"
#include <iostream>
#include "constants.h"
#include "operatorprec.h"

using namespace std;

SYard::SYard()
{
}

Queue<Tokenizer *> SYard::PostFix(Queue<Tokenizer*>& token)
{
    //Takes in a pre fix queue and finds specific types of tokens to put into the queue
    //or the operators stack
//    cout <<"queue in syard prefix: " << token << endl;
    while(!token.isEmpty())
    {
        //checks if queue is empty
        if(token.first()->TypeOf() == INTEGER)
        {
            //if first token is a number push into the final queue
            qu.push(token.pop_front());
        }
        else if(token.first()->TypeOf() == OPERATORS)
        {
            //if operator is first token in queue check if stack is empty
            if(operat.isEmpty())
            {
                //if empty push into the operator stack
                operat.Push(token.pop_front());
            }
            else if(token.first()->precedence() > operat.Top()->precedence())
            {
                //check the precedence of the stack top and first token
                //if token has higher precedence push token into stack
                operat.Push(token.pop_front());
            }
            else if(token.first()->precedence() < operat.Top()->precedence())
            {
                //if token has lower precedence pop stack operator into queue and
                //push token into the operator stack
                if(operat.Top()->TypeOf() == LEFTPAR)
                {
                    //since Left Parenthesis( has higher prec must be checked if it is
                    //a ( then it is pushed into stack
                    operat.Push(token.pop_front());
                }
                else
                {
                    qu.push(operat.pop());
                    operat.Push(token.pop_front());
                }
            }
            else if(token.first()->precedence() == operat.Top()->precedence())
            {
                //if prec is the same just push token into stack
                operat.Push(token.pop_front());
            }
        }
        else if(token.first()->TypeOf() == LEFTPAR)
        {
            operat.Push(token.pop_front());
        }
        else if(token.first()->TypeOf() == RIGHTPAR)
        {
            //if token is right parenthesis pop the token and pop all operators in stack
            //until a left parenth is read, then pop left parenth
            token.pop_front();
            while(operat.Top()->TypeOf() != LEFTPAR)
            {
                qu.push(operat.pop());
            }
            operat.pop();
        }
        else if(token.first()->TypeOf() == UNARY)
        {
            //if its a unary operator push the x into the queue
            if(static_cast<UnaryOp*>(token.first())->StringOnly() == "x"
               || static_cast<UnaryOp*>(token.first())->StringOnly() == "X")
            {
                qu.push(token.pop_front());
            }
            else
            {
                //else if its a sin cos tan push it into the operator stack
                operat.Push(token.pop_front());
            }
        }
    }

    while(!operat.isEmpty())
    {
        //making sure the stack isnt empty pop all remaining operators in the
        //stack into the queue
        qu.push(operat.pop());
    }

//    cout << "Final queue going to rpn: " << qu << endl;
    return qu;
}

/*
1.  While there are tokens to be read:
2.        Read a token
3.        If it's a number add it to queue
4.        If it's an operator
5.               While there's an operator on the top of the stack with greater precedence:
6.                       Pop operators from the stack onto the output queue
7.               Push the current operator onto the stack
8.        If it's a left bracket push it onto the stack
9.        If it's a right bracket
10.            While there's not a left bracket at the top of the stack:
11.                     Pop operators from the stack onto the output queue.
12.             Pop the left bracket from the stack and discard it
13. While there's operators on the stack, pop them to the queue
*/
