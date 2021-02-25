#ifndef QUEUE_H
#define QUEUE_H
#include "list.h"
#include <iostream>
#include <assert.h>

using namespace std;

template<class T>
class Queue
{
public:
    Queue();

    //big 3
    //~Queue();
    Queue(const Queue<T>& other);
    Queue& operator = (const Queue<T>& rhs);

    void push(const T& i);
    T first() const;
    T pop_front();
    bool isEmpty();
    int size() const;

    template<class U>
    friend ostream& operator <<(ostream& outs, const Queue<U>& print);

private:
    List<T> ptr;
    typename List<T>::Iterator front;
    typename List<T>::Iterator rear;
};

template<class T>
Queue<T>::Queue()
{
    List<T> list_ptr;
}

//template<class T>
//Queue<T>::~Queue()
//{
//    for(int i = 0; i < ptr.Size(); i++)
//    {
//        ptr.Delete(front);
//    }
//}

template<class T>
Queue<T>::Queue(const Queue<T>& other)
{
    ptr = other.ptr;
    front = ptr.Begin();
    rear = ptr.End();
}

template<class T>
Queue<T>& Queue<T>::operator =(const Queue<T>& rhs)
{
    ptr = rhs.ptr;
    front = ptr.Begin();
    rear = ptr.End();
    return *this;
}

template<class T>
void Queue<T>::push(const T &i)
{
    if(front.is_null())
    {
       front = ptr.InsertHead(i);
       rear = front;
    }
    else
    {
        rear = ptr.InsertAfter(i, rear);
    }
}

template<class T>
T Queue<T>::first() const
{
    return *ptr.Begin();
}

template<class T>
T Queue<T>::pop_front()
{
    T item = ptr.Delete(front);
    front = ptr.Begin();
    return item;
}

template<class T>
bool Queue<T>::isEmpty()
{
    if(front.is_null())
    {
        return true;
    }
    else
        return false;
}

template<class T>
int Queue<T>::size() const
{
    if(ptr.Size() == NULL)
    {
        return NULL;
    }
    else
        return ptr.Size();
}

template<class U>
ostream& operator <<(ostream& outs, const Queue<U>& print)
{
    outs << print.ptr;
    return outs;
}

#endif // QUEUE_H
