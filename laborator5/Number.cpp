#include "Number.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
int Number::GetBase()
{
    return this->base;
}
int Number::GetDigitsCount()
{
    return this->nr;
}
void Number::Print()
{
    printf("%s\n",this->val);
}
int fct(char x)
{
    if('0'<=x&&'9'>=x)
        return x-'0';
    return x-'A'+10;
}
char nfct(int x)
{
    if(x<=9)
        return x+'0';
    else
        return x-10+'A';
}
int trans(char *x,int base,int len)
{
    int val=0;
    int pw=1;
    for(int i=0;i<len;i++)
    {
        val=val+fct(x[len-i-1])*pw;
        pw*=base;
    }
    return val;
}
char *ntrans(int val,int base)
{
    int vval=val;
    int nnr=0;
    if(vval==0)
        nnr++;
    while(vval)
    {
        vval/=base;
        nnr++;
    }
    char *p=new char[nnr];
    for(int i=1;i<=nnr;i++)
    {
        p[nnr-i]=nfct(val%base);
        val/=base;
    }
    return p;
}
void Number::SwitchBase(int nb)
{
    int val=trans(this->val,this->base,this->nr);
    this->base=nb;
    delete[] this->val;
    this->val=ntrans(val,nb);
    this->nr=strlen(this->val);
}
Number::Number(const char *x,int base)
{
    this->nr=strlen(x);
    this->base=base;
    char *p =new char[this->nr+1];
    this->val=p;
    for(int i=0;i<this->nr;i++)
        this->val[i]=x[i];
}
Number::~Number()
{
    delete[] this->val;
    this->val=nullptr;
}
Number& Number:: operator =(int val)
{
    this->val=ntrans(val,10);
    this->base=10;
    this->nr=strlen(this->val);
    return *this;
}
Number& Number:: operator =(char *x)
{
    this->nr=strlen(x);
    //delete[] this->val;
    this->val=new char[this->nr+1];
    this->val=x;
}
Number operator +(Number a,Number b)
{
    int val1=trans(a.val,a.base,a.nr);
    int val2=trans(b.val,b.base,b.nr);
    val1+=val2;
    Number x(ntrans(val1,std::max(a.base,b.base)),std::max(a.base,b.base));
    return x;
}
Number operator -(Number a,Number b)
{
    int val1=trans(a.val,a.base,a.nr);
    int val2=trans(b.val,b.base,b.nr);
    val1-=val2;
    Number x(ntrans(val1,std::max(a.base,b.base)),std::max(a.base,b.base));
    return x;
}
bool Number::operator ==(const Number & other)
{
    int v1=trans(this->val,this->base,this->nr);
    int v2=trans(other.val,other.base,other.nr);
    v1-=v2;
    return v1==v2;
}
bool Number::operator <(const Number & other)
{
    int v1=trans(this->val,this->base,this->nr);
    int v2=trans(other.val,other.base,other.nr);
    v1-=v2;
    return v1<0;
}
bool Number::operator >(const Number & other)
{
    int v1=trans(this->val,this->base,this->nr);
    int v2=trans(other.val,other.base,other.nr);
    v1-=v2;
    return v1>0;
}
bool Number::operator >=(const Number & other)
{
    int v1=trans(this->val,this->base,this->nr);
    int v2=trans(other.val,other.base,other.nr);
    v1-=v2;
    return v1>=0;
}
char Number::operator [](int index)
{
    return this->val[index];
}
Number::Number(int val)
{
    this->val=ntrans(val,10);
    this->base=10;
    this->nr=strlen(this->val);
}
Number::Number(const Number&other)
{
    this->nr=other.nr;
    this->base=other.base;
    this->val=new char[this->nr+1];
    for(int i=0;i<this->nr;i++)
        this->val[i]=other.val[i];
}
Number::Number(Number && d)
{
    this->nr=d.nr;
    this->base=d.base;
    char * temp=d.val;
    d.val=nullptr;
    this->val=temp;
}
Number& Number:: operator+=(Number &other)
{
    int val1=trans(this->val,this->base,this->nr);
    int val2=trans(other.val,other.base,other.nr);
    val1+=val2;
    delete[] this->val;
    this->val=ntrans(val1,this->base);
    this->nr=strlen(this->val);
    return *this;
}
Number& Number::operator =(const Number &other)
{
    if(this==&other)
        return *this;
    delete[] this->val;
    this->nr=other.nr;
    this->base=other.base;
    this->val=new char[this->nr+1];
    for(int i=0;i<=this->nr;i++)
        this->val[i]=other.val[i];
    return *this;
}
bool Number::operator--()
{
    char *p =new char[this->nr];
    for(int i=1;i<this->nr;i++)
        p[i-1]=this->val[i];
    p[this->nr-1]='\0';
    delete[] this->val;
    this->val=p;
    this->nr--;
    return true;
}
bool Number::operator--(int val)
{
    char *p=new char[this->nr];
    for(int i=0;i<this->nr-1;i++)
        p[i]=this->val[i];
    p[this->nr-1]='\0';
    delete[] this->val;
    this->nr--;
    this->val=p;
    return false;
}

