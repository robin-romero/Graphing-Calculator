#ifndef VECTORC_H
#define VECTORC_H
#include <assert.h>
#include <iostream>

using namespace std;

template<class T>
class VectorC
{
public:
    class Iterator
    {
    public:
        friend class VectorC;

        Iterator()
        {
            i_ptr = NULL;
        }

        Iterator(T* pointer)
        {
            i_ptr = pointer;
        }

        Iterator& operator ++()
        {
            i_ptr++;
            return Iterator(i_ptr);
        }

        friend Iterator operator ++(Iterator& it, int unused)
        {
            Iterator hold;
            hold = it;
            it.i_ptr++;
            return hold;
        }

        friend bool operator !=(const Iterator& lhs, const Iterator& rhs)
        {
            if (lhs.i_ptr != rhs.i_ptr)
                return true;
            else
                return false;
        }

        T operator *()
        {
            assert(i_ptr);
            return *i_ptr;
        }

    private:
        T* i_ptr;
    };

    VectorC();
    VectorC(int size);

    //big 3
    ~VectorC();
    VectorC(const VectorC<T> & copyThis);
    VectorC& operator =(const VectorC& rhs);

    Iterator begin() const;
    Iterator end() const;
    VectorC& operator +=(T coef);
    T& operator [](int index);
    void Pop_back();

    //array functions
    T* _allocate(int cap);
    T* _resize(T* resize, int cap);
    T* _copy(T* dest, T* src, int num);
    int Size() const;

    template<class U>
    friend ostream& operator <<(ostream& outs, const VectorC<U>& print);

private:
    T* vect;
    int capacity = 200;
    int num_used = 0;
};

template<class T>
inline VectorC<T>::VectorC()
{
    vect = _allocate(capacity);
}

template<class T>
inline VectorC<T>::VectorC(int size)
{
    capacity = size;
    vect = _allocate(capacity);
}

template<class T>
inline VectorC<T>::~VectorC()
{
    delete[] vect;
}

template<class T>
inline VectorC<T>::VectorC(const VectorC<T>& copyThis)
{
    vect = _copy(vect, copyThis.vect, copyThis.capacity);
    capacity = copyThis.capacity;
    num_used = copyThis.num_used;
}

template<class T>
inline VectorC<T> & VectorC<T>::operator=(const VectorC & rhs)
{
    delete[] vect;
    vect = _copy(vect, rhs.vect, rhs.capacity);
    capacity = rhs.capacity;
    num_used = rhs.num_used;
    return *this;
}

template<class T>
inline typename VectorC<T>::Iterator VectorC<T>::begin() const
{
    return Iterator(vect);
}

template<class T>
inline typename VectorC<T>::Iterator VectorC<T>::end() const
{
    T* walker = vect;
    for (int i = 0; i < num_used - 1; i++)
    {
        walker++;
    }
    return Iterator(walker);
}

template<class T>
inline VectorC<T>& VectorC<T>::operator+=(T coef)
{
    if (num_used >= capacity)
    {
        vect = _resize(vect, capacity);
        capacity = capacity * 2;
    }

    T* walker = vect;
    for (int i = 0; i < num_used; i++)
    {
        walker++;
    }
    *walker = coef;

    num_used++;

    return *this;
}

template<class T>
inline T & VectorC<T>::operator[](int index)
{
    if (index > capacity)
    {
        vect = _resize(vect, capacity);
    }

    T* walker = vect;
    for (int i = 0; i < index; i++)
    {
        walker++;
    }
    if (index > num_used)
    {
        num_used = index + 1;
    }

    return *walker;
}

template<class T>
inline T* VectorC<T>::_allocate(int cap)
{
    T* arr = new T[cap];
    T* wlk = arr;

    wlk = NULL;

    return arr;
}

template<class T>
inline T* VectorC<T>::_resize(T * resize, int cap)
{
    T* temp = _allocate(cap * 2);
    T* wlk = temp;
    for (int i = 0; i < cap; i++)
    {
        *wlk = *resize;
        wlk++;
        resize++;
    }

    return temp;
}

template<class T>
inline T* VectorC<T>::_copy(T * dest, T * src, int num)
{
    T* s_wlk = src;
    dest = _allocate(num);
    T* d_wlk = dest;
    T* temp = d_wlk;
    for (int i = 0; i < num; i++)
    {
        *d_wlk = *s_wlk;
        d_wlk++;
        s_wlk++;
    }
    return temp;
}

template<class U>
inline ostream & operator<<(ostream & outs, const VectorC<U>& print)
{
    U* walker = print.vect;
    for (int i = 0; i < print.num_used; i++)
    {
        outs << *walker;
        walker++;
    }
    return outs;
}

template<class T>
int VectorC<T>::Size() const
{
    if(num_used == 0)
    {
        return NULL;
    }
    else
        return num_used;
}

template<class T>
inline void VectorC<T>::Pop_back()
{
    T* walker = vect;
    for (int i = 0; i < num_used - 1; i++)
    {
        walker++;
    }

    num_used--;
}

#endif // VECTORC_H
