#ifndef RPN_H
#define RPN_H
#include "tokenizer.h"
#include "stack.h"
#include "queue.h"
#include "integer.h"
#include "operators.h"
#include "unaryop.h"
#include "constants.h"

class RPN
{
public:
    //evaluates the numbers in the queue using operators being passed in
    //post fix order
    RPN();
    RPN(Queue<Tokenizer *>& que);
    double evaluation(Queue<Tokenizer*> token, double x);
private:
    Queue<Tokenizer*> q;
    Stack<Tokenizer*> s;
    Operators op;
    Tokenizer* t;
    UnaryOp unary;
    int operand;
};

#endif // RPN_H
