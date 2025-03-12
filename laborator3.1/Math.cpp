#include "Math.h"
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
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
    char *c=(char *)malloc(sizeof(char)*(a+b));
    for(int i=0;i<a;i++)
        c[i]=x[i];
    for(int i=a;i<a+b;i++)
        c[i]=y[i-a];
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
