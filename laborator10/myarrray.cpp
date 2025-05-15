#include "myarray.h"
#include <exception>
#include <iostream>
using namespace std;
class exceptieout:public exception
{
    virtual const char* what() const throw()
    {
        return "Indexul este inafara domeniului!";
    }
};
class exceptieiese:public exception
{
    virtual const char* what() const throw()
    {
        return "Indexul va iesi inafara domeniului!";
    }
};
class exceptiefull:public exception
{
    virtual const char* what() const throw()
    {
        return "Arrayul este plin nu se poate insera";
    }
};
template <class T>
ArrayIterator<T>& ArrayIterator<T>::operator++()
{
    exceptieiese nu;
    try
    {
        if(Current==sz-1)
            throw nu;
        Current++;
    }
    catch(exception &e)
    {
        cout<<e.what()<<'\n';
    }
    return *this;
}
template <class T>
ArrayIterator<T>& ArrayIterator<T>::operator--()
{
    exceptieiese nu;
    try
    {
        if(Current==0)
            throw nu;
        Current--;
    }
    catch(exception &e)
    {
        cout<<e.what()<<'\n';
    }
    return *this;
}
template <class T>
ArrayIterator<T>& ArrayIterator<T>::operator=(ArrayIterator<T> & x)
{
    Current=x.Current;
    sz=x.sz;
    return *this;
}
template <class T>
bool  ArrayIterator<T>::operator!=(ArrayIterator<T> & x)
{
    return (Current!=x.Current||sz!=x.sz);
}
template <class T>
T* ArrayIterator<T>::GetElement()
{
    return arr[Current];
}
template <class T>
Array<T>::Array()
{
    List=new T*[500];
    Capacity=500;
    Size=0;
}
template <class T>
Array<T>::~Array()
{
    for(int i=0;i<Size;i++)
        delete List[i];
    delete [] List;
    List=nullptr;
}
template <class T>
Array<T>::Array(int cap)
{
    List=new T*[cap];
    Capacity=cap;
    Size=0;
}
template <class T>
Array<T>::Array(const Array<T> &otherArray)
{
    List=new T*[otherArray.Capacity];
    Capacity=otherArray.Capacity;
    Size=otherArray.Size;
    for(int i=0;i<otherArray.Size;i++)
        List[i]=otherArray.List[i];
}
template <class T>
T& Array<T>::operator[](int index)
{
    exceptieout nu;
    try
    {
        if(index>=Size||index<0)
            throw nu;
        return *(List[index]);
    }
    catch(exception &e)
    {
        cout<<e.what()<<'\n';
    }
}
template <class T>
const Array<T>& Array<T>::operator+=(const T &newElem)
{
    List[Size]=new T;
    *(List[Size])=newElem;
    Size++;
    return *this;
}
template <class T>
const Array<T>& Array<T>::Insert(int index,const T &newElem)
{
    exceptieout nu;
    try
    {
        if(index<0||index>=Size)
            throw nu;
        List[Size]=new T;

        for(int i=Size;i>index;i--)
        List[i]=List[i-1];
        *(List[index])=newElem;
        Size++;
        return *this;
    }
    catch(exception &e)
    {
        cout<<e.what()<<'\n';
    }
}
template <class T>
const Array<T>& Array<T>::Insert(int index, const Array<T> otherArray)
{
    exceptieout nu;
    try
    {
        if(index<0||index>=Size)
            throw nu;
        int nsz=otherArray.Size;
        for(int i=0;i<nsz;i++)
        {
            List[Size]=new T;
            Size++;
        }
        for(int i=Size-1;i>=index+nsz+1;i--)
            List[i]=List[i-nsz];
        for(int i=index+1;i<=index+nsz;i++)
            List[i]=otherArray.List[i-index-1];
        return *this;
    }
    catch(exception &e)
    {
        cout<<e.what()<<'\n';
    }
}
template <class T>
const Array<T>& Array<T>::Delete(int index)
{
    exceptieout nu;
    try
    {
        if(index<0||index>=Size)
            throw nu;
        T* mlb=List[index];
        for(int i =index;i<Size-1;i++)
            List[i]=List[i+1];
        Size--;
        delete mlb;
    }
    catch(exception &e)
    {
        cout<<e.what()<<'\n';
    }
}
template <class T>
const Array<T>& Array<T>::operator=(const Array<T> &otherArray)
{

}
template <class T>
ArrayIterator<T> Array<T>::GetBeginIterator()
{
    ArrayIterator<T> myit;
    myit=&List[0];
    return myit;
}
template <class T>
ArrayIterator<T> Array<T>::GetEndIterator()
{
    ArrayIterator<T> myit;
    myit=&List[Size];
    return myit;
}
template <class T>
int Array<T>::GetSize()
{
    return Size;
}
template <class T>
int Array<T>::GetCapacity()
{
    return Capacity;
}

