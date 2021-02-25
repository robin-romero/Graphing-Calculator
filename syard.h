#ifndef SYARD_H
#define SYARD_H
#include "operators.h"
#include "unaryop.h"
#include "integer.h"
#include "queue.h"
#include "stack.h"
#include <iostream>
#include <string>

using namespace std;

class SYard
{
public:
    SYard();
    //converts prefix ordered queues into post fix order for rpn to calculate
    Queue<Tokenizer*> PostFix(Queue<Tokenizer*>&
                              token);

private:
    Stack<Tokenizer*> operat;
    Queue<Tokenizer*> qu;
    Operators op;

};

#endif // SYARD_H
