#ifndef LIST_H
#define LIST_H
#include "listfunctions.h"
#include <iostream>
#include <assert.h>

using namespace std;

template<class T>
class List
{
public:
    class Iterator
    {
    public:
        friend class List;//give access to List Class to access private iterator _ptr
        Iterator()
        {
            _ptr = NULL;
        }//default constructor

        Iterator(node<T>* pointer)
        {
            _ptr = pointer;

        }//point Iterator to where p is pointing to

        operator bool()
        {
            if (_ptr != NULL)
                return true;
            else
                return false;
        }// casting operator: true if _ptr not NUll

        T& operator *()
        {
//            assert(_ptr);
            return _ptr->_item;
        }//dereference operator

        T* operator ->()
        {
            return NULL;
        }//member access operator

        bool is_null()
        {
            if(_ptr == NULL)
                return true;
            else
                return false;
        }//true if _ptr is null

        friend bool operator !=(const Iterator& left, const Iterator& right)
        {
            if (left._ptr != right._ptr)
                return true;
            else
                return false;
        }//true if left != right

        friend bool operator ==(const Iterator& left, const Iterator& right)
        {
            if (left._ptr == right._ptr)
                return true;
            else
                return false;
        }//true if left == right

        Iterator& operator ++()
        {
            _ptr = _ptr->_next;
            return Iterator(_ptr);
        }//member operator: ++it, ++it = new_value

        friend Iterator operator ++(Iterator& it, int unused)
        {
            Iterator hold;
            hold = it;
            it._ptr++;
            return hold;
        }//friend operator: it++

    private:
        node<T>* _ptr;//pointer being encapsulated
    };
    List();

    ~List();
    List(const List<T>& copyThis);
    List& operator =(const List& RHS);

    Iterator ReturnHead();//returns the head
    Iterator InsertHead(const T& item);//insert i at the head of list
    Iterator InsertAfter(const T& item, Iterator iMarked);//insert item i after marked node
    Iterator InsertBefore(const T& item, Iterator iMarked);//insert item i before marked node
    Iterator InsertSorted(const T& item);//insert i assum sorted list
    T Delete(Iterator iMarked);//de;ete node pointed atby marked
    Iterator Search(const T& item);//return pointer address that has item looking for
    Iterator Previous(Iterator iMarked);//return address of node of previous marked
    T& operator [](int index);//return item at index
    Iterator Begin() const;//return head of list
    Iterator End() const;//return end of list
    void printList(Iterator cursor) const;

    int Size() const;

    template<class U>
    friend ostream& operator <<(ostream& outs,const List<U>& print);//print operator for list

private:
    node<T>* _head_ptr;
    int size = 0;
};

template<class T>
inline List<T>::List()
{
    _head_ptr = NULL;
}

template<class T>
inline List<T>::~List()
{
    size = 0;
    delete_all(_head_ptr);
}

template<class T>
inline List<T>::List(const List<T>& copyThis)
{
    _head_ptr = copy_list(copyThis._head_ptr);
    size = copyThis.size;
}

template<class T>
inline List<T>& List<T>::operator =(const List& RHS)
{
    size = RHS.size;

    if(this->Begin() != RHS.Begin())
    {
        delete_all(_head_ptr);
        _head_ptr = copy_list(RHS._head_ptr);
        return *this;
    }
    else
    {
        this->_head_ptr = RHS._head_ptr;
        return *this;
    }
}

template<class T>
inline typename List<T>::Iterator List<T>::ReturnHead()
{
    return Iterator(_head_ptr);
}

template<class T>
inline typename List<T>::Iterator List<T>::InsertHead(const T& item)
{
    size++;
    _head_ptr = insert_head(_head_ptr, item);

    return Iterator(_head_ptr);
}

template<class T>
inline typename List<T>::Iterator List<T>::InsertAfter(const T & item, Iterator iMarked)
{
    //node<T>* Marked = iMarked;
    size++;
    return Iterator(insert_after(_head_ptr, iMarked._ptr, item));
}

template<class T>
inline typename List<T>::Iterator List<T>::InsertBefore(const T& item, Iterator iMarked)
{
    /*node<T>* Marked = iMarked;*/
    size++;
    return Iterator(insert_before(_head_ptr, iMarked._ptr, item));
}

//template<class T>
//inline typename List<T>::Iterator List<T>::InsertSorted(const T & item)
//{
//    return Iterator(insert_sorted(_head_ptr, item, bool ascend));
//}

template<class T>
inline T List<T>::Delete(Iterator iMarked)
{
    /*node<T>* Marked = iMarked;*/
    size--;
    return _delete(_head_ptr, iMarked._ptr);
}

template<class T>
inline typename List<T>::Iterator List<T>::Search(const T & item)
{
    return Iterator(search_node(_head_ptr, item));
}

template<class T>
inline typename List<T>::Iterator List<T>::Previous(Iterator iMarked)
{
    //node<T>* Marked = iMarked;
    return Iterator(_previous(_head_ptr, iMarked._ptr));
}

template<class T>
inline T & List<T>::operator[](int index)
{
    node<T>* walker = _head_ptr;

    for (int i = 0; i < index; i++)
    {
        walker = walker->_next;
    }
    return walker->_item;
}

template<class T>
inline typename List<T>::Iterator List<T>::Begin() const
{
    return Iterator(_head_ptr);
}

template<class T>
inline typename List<T>::Iterator List<T>::End() const
{
    return Iterator(last_node(_head_ptr));
}

template <class T>
void List<T>::printList(Iterator cursor) const
{
    node<T>* walker = _head_ptr;

    cout << "Head->";
    while (walker != NULL)
    {
        if (walker == cursor)
        {
            cout << "{" << *walker << "}->";
        }
        else//walker != cursor
        {
            cout << "[" << *walker << "]->";
        }
        walker = walker->_next;
    }
    cout << "|||" << endl;
}

template<class U>
inline ostream & operator<<(ostream & outs,const  List<U>& print)
{
    return print_list(outs, print._head_ptr);
}


template<class T>
int List<T>::Size() const
{
    if(size == 0)
    {
        return NULL;
    }
    else
        return size;
}
#endif // LIST_H
