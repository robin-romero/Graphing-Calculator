#ifndef LINKEDLISTFUNCT_H
#define LINKEDLISTFUNCT_H
#include "node.h"
#include <iostream>

using namespace std;

//=========
//Headers
//=========

template<class T>
node<T>* insert_head(node<T>*& head_ptr, const T& item);

template<class T>
node<T>* insert_after(node<T>*& head_ptr, node<T>* insert, T item);

template<class T>
node<T>* insert_before(node<T>*& head_ptr, node<T>* after, T item);

template<class T>
node<T>* _previous(node<T>*& head_ptr, node<T>* address);

template<class T>
T _delete(node<T>*& head_ptr, node<T>* mark);

template<class T>
node<T>* search_node(node<T>*& head_ptr, const T& item);

template<class T>
ostream& print_list(ostream& outs, node<T>* head_ptr);

template<class T>
void printList_backwards(node<T>* head_ptr);

template<class T>
node<T>* last_node(node<T>* head_ptr);

template<class T>
node<T>* delete_all(node<T>*& head_ptr);

template<class T>
inline node<T>* copy_list(node<T>* head_ptr);

template<class T>
inline node<T>* insert_sorted(node<T>*& head_ptr, T item, bool ascending);

//========================//
//Header Implementatios
//========================//
template<class T>
//pass templated item always const and pass by reference
node<T>* insert_head(node<T>*& head_ptr, const T& item)
{
    /*
    */
    //1. create a new node(item
    node<T>* temp = new node<T>(item);

    //2. Temp's next points to where head is pointing to;
    temp->_next = head_ptr;

    //3. Point head_ptr to this new node
    head_ptr = temp;

    return head_ptr;
}

template<class T>
node<T>* insert_after(node<T>*& head_ptr, node<T>* insert, T item)
{
    //1. create a new node(item
    node<T>* temp = new node<T>(item);
    //2. Temp's next points to where node you want to insert after is pointing to;
    temp->_next = insert->_next;
    //3. Point node inserted after to this new node
    insert->_next = temp;

    return temp;
}

template<class T>
node<T>* insert_before(node<T>*& head_ptr, node<T>* after, T item)
{
    node<T>* temp = _previous(head_ptr, after);
    if (temp != NULL)
    {
        return insert_after(head_ptr, temp, item);
    }
    else
        return insert_head(head_ptr, item);
}

template<class T>
node<T>* _previous(node<T>*& head_ptr, node<T>* address)
{
    node <T>* walker = head_ptr;
    if (head_ptr == address)
    {
        return NULL;
    }

    while (walker != NULL)
    {

        if (walker->_next == address)
        {
            return walker;
        }
        walker = walker->_next;
    }
}

template<class T>
T _delete(node<T>*& head_ptr, node<T>* mark)
{
    T hold;
    node<T>* prev = _previous(head_ptr, mark);

    prev->_next = mark->_next;
    hold = mark->_item;
    delete mark;
    return hold;
}

template<class T>
node<T>* search_node(node<T>*& head_ptr, const T& item)
{
    node<T>* wlk = head_ptr;

    if (wlk == NULL)
    {
        return NULL;
    }

    while (wlk != NULL)
    {
        if (wlk->_item == item)
        {
            return wlk;
        }
        wlk = wlk->_next;
        if (wlk == NULL)
            return NULL;
    }
}

template<class T>
ostream& print_list(ostream& outs, node<T>* head_ptr)
{
    //1. walker to head_ptr
    node<T>* walker = head_ptr;
    //loop and print until walker hits null

    outs << "Head->";
    walker = walker->_next;
    while (walker != NULL)
    {
        outs << "[" << *walker << "]->";//prints this node
        walker = walker->_next;//move onto the next node
    }
    outs << "|||" << endl;
    return outs;
}

template<class T>
void printList_backwards(node<T>* head_ptr)
{
    //1. walker to head_ptr
    node<T>* walker = head_ptr;
    //loop and print until walker hits null
    while (walker->_next != NULL)
    {
        walker = walker->_next;
    }

    cout << "|||->";
    while (walker != NULL)
    {
        cout << *walker;
        walker = _previous(head_ptr, walker);
    }
    cout << "Head" << endl;
}

template<class T>
inline node<T>* last_node(node<T>* head_ptr)
{
    node<T>* walker = head_ptr;

    while (walker->_next != NULL)
    {
        walker = walker->_next;
    }
    return walker;
}

template<class T>
inline node<T>* delete_all(node<T>*& head_ptr)
{
    node<T>* walker = head_ptr;
    while (head_ptr != NULL)
    {
        head_ptr = head_ptr->_next;
        delete walker;
        walker = NULL;
        walker = head_ptr;
    }
    walker = NULL;
    return walker;
}

template<class T>
inline node<T>* copy_list(node<T>* head_ptr)
{
    node<T>* temp = NULL;
    node<T>* walker = head_ptr;
    if (head_ptr == NULL)
    {
        return temp;
    }
    else
    {
        node<T>* temp_walk = insert_head(temp, walker->_item);
        walker = walker->_next;

        while (walker != NULL)
        {
            temp_walk = insert_after(temp, temp_walk, walker->_item);
            walker = walker->_next;
            temp_walk = temp_walk->_next;
        }
    }
    return temp;
}

template<class T>
inline node<T>* insert_sorted(node<T>*& head_ptr, T item, bool ascending)
{
    if (head_ptr == NULL)
    {
        insert_head(head_ptr, item);
    }

    node<T>* walker = head_ptr;
    walker = walker->_next;
    node<T>* prev_walker = head_ptr;
    if (ascending)
    {
        while (walker != NULL)
        {
            if (prev_walker->_item < item && walker->_item > item)
            {
                insert_after(head_ptr, prev_walker, item);
                return prev_walker;
            }
            walker = walker->_next;
            prev_walker = prev_walker->_next;
        }
    }
    else if (!ascending)
    {
        while (walker != NULL)
        {
            if (prev_walker->_item > item && walker->_item < item)
            {
                insert_after(head_ptr, prev_walker, item);
                return prev_walker;
            }
            walker = walker->_next;
            prev_walker = prev_walker->_next;
        }
    }
}
#endif // LINKEDLISTFUNCT_H
