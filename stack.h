#ifndef STACK_H
#define STACK_H
#include "vectorc.h"
#include<iostream>

using namespace std;

template <class T>
class Stack
{
public:
    Stack();
    void Push(const T&i);
    T Top() const;//peeks at what is at the top of list
    T pop();//returns item at the top of the list
    bool isEmpty();//returns true if list is empty
    int size() const;//how many in the list

    template<class U>
    friend ostream& operator <<(ostream& outs, const Stack<U>& print);

private:
    VectorC<T> ptr;
};

template<class T>
Stack<T>::Stack()
{
    VectorC<T> vect_ptr;
}

template<class T>
void Stack<T>::Push(const T &i)
{
    ptr += i;
}

template<class T>
T Stack<T>::Top() const
{
    return *ptr.end();
}


template<class T>
T Stack<T>::pop()
{
    T item = *ptr.end();

    ptr.Pop_back();
    return item;
}

template<class T>
bool Stack<T>::isEmpty()
{
    if(ptr.Size() == NULL)
        return true;
    else
        return false;
}

template<class T>
int Stack<T>::size() const
{
    if(ptr.Size() == NULL)
    {
        return NULL;
    }
    else
        return ptr.Size();
}

template<class U>
ostream& operator <<(ostream& outs, const Stack<U>& print)
{
    VectorC<U> walker = print.ptr;
    for(int i = print.size() - 1; i >= 0; i--)
    {
        outs << walker[i];
    }
    return outs;
}

#endif // STACK_H
