#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

template<class T>
struct node
{
public:
    T _item;
    node<T>* _next;
    node(T item = T());
    template <class U>
    friend ostream& operator <<(ostream& outs, const node<U>& print_me);
};

template<class T>
node<T>::node(T item) : _item(item), _next(NULL) { }

template <class U>
ostream& operator <<(ostream& outs, const node<U>& print_me)
{
    outs << print_me._item;
    return outs;
}


#endif // NODE_H
