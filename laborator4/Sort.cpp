#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>
#include "Sort.h"
#include <time.h>
Sort::Sort(int nr,int mini,int maxi)
{
    this->n=nr;
    v=new int[nr];
    for(int i=0;i<n;i++)
    {
        v[i]=mini+rand()%(maxi-mini+1);
    }
}
Sort::Sort(int *v,int nr)
{
    this->n=nr;
    this->v=new int[nr];
    for(int i=0;i<n;i++)
        this->v[i]=v[i];
}
Sort::Sort(int count,...)
{
    this->n=count;
    this->v=new int[count];
    va_list arr;
    va_start(arr,count);
    for(int i=0;i<count;i++)
        this->v[i]=va_arg(arr,int);
    va_end(arr);
}
Sort::Sort(char *c)
{
    int val=strlen(c);
    int nr=0;
    for(int i=0;i<val;i++)
        nr+=(c[i]==',');
    nr++;
    int nnr=0;
    this->n=nr;
    this->v=new int[nr];
    for(int i=0;i<val;i++)
        if(c[i]>='0'&&c[i]<='9')
            {
                int nval=0;
                while(i<val&&c[i]>='0'&&c[i]<='9')
                {
                    nval=nval*10+c[i]-'0';
                    i++;
                }
                this->v[nnr]=nval;
                nnr++;
            }
}
void Sort::InsertSort(bool asc)
{
    for(int i=1;i<n;i++)
    {
        int poz=i;
        while(poz>0&&v[poz]<v[poz-1])
            {
                std::swap(v[poz],v[poz-1]);
                poz--;
            }
    }
    if(!asc)
    for(int i=0;i<n/2;i++)
        std::swap(v[i],v[n-i-1]);

}
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
void Sort::BubbleSort(bool asc)
{
    bool flag =true;
    while(flag)
    {
        flag=false;
        for(int i=0;i+1<n;i++)
            if(v[i]>v[i+1])
            flag=true,std::swap(v[i],v[i+1]);
    }
    if(!asc)
    for(int i=0;i<n/2;i++)
        std::swap(v[i],v[n-i-1]);
}
void Sort::QuickSort(bool asc)
{
    qsort(this->v,this->n,sizeof(int),compare);
    if(!asc)
    for(int i=0;i<n/2;i++)
        std::swap(v[i],v[n-i-1]);
}
void Sort::Print()
{
    for(int i=0;i<n;i++)
        printf("%d ",this->v[i]);
    printf("\n");
}
int Sort::GetElementFromIndex(int id)
{
    return this->v[id];
}
int Sort::GetElementsCount()
{
    return this->n;
}
