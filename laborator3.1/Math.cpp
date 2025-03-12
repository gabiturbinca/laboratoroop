#include "Math.h"
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>
int Math::Add(int x,int y)
{
    return x+y;
}
char *Math::Add(const char *x,const char *y)
{
    if(x==nullptr||y==nullptr)
        return nullptr;
    int a=strlen(x);
    int b=strlen(y);
    if(a<b)
    {
        std::swap(a,b);
        std::swap(x,y);
    }
    char *c=(char *)malloc(sizeof(char)*(std::max(a,b)+2));
    int t=0;
    int sz=0;
    for(int i=0;i<b;i++)
    {
        t+=x[a-i-1]-'0'+y[b-i-1]-'0';
        c[sz]=t%10+'0';
        t/=10;
        sz++;
    }
    for(int i=b;i<a;i++)
    {
        t+=x[a-i-1]-'0';
        c[sz]=t%10+'0';
        t/=10;
        sz++;
    }
    if(t>0)
        {
            c[sz]=t+'0';
            sz++;
        }
    for(int i=0;i<sz/2;i++)
        std::swap(c[i],c[sz-i-1]);
    return c;
}
int Math::Add(int x,int y,int z)
{
    return x+y+z;
}
double Math::Add(double x,double y,double z)
{
    return x+y+z;
}
double Math::Add(double x,double y)
{
    return x+y;
}
int Math::Mul(int x,int y)
{
    return x*y;
}
double Math::Mul(double x,double y,double z)
{
    return x*y*z;
}
double Math::Mul(double x,double y)
{
    return x*y;
}
int Math::Mul(int x,int y,int z)
{
    return x*y*z;
}
int Math::Add(int count,...)
{
    int sum=0;
    va_list arr;
    va_start(arr,count);
    for(int i=0;i<count;i++)
        sum+=va_arg(arr,int);
    va_end(arr);
    return sum;
}
