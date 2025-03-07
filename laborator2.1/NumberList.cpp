#include "NumberList.h"

void NumberList::Init()
{
    this->count=0;
}
bool NumberList::Add(int x)
{
    if(this->count==10)
        return false;
    this->numbers[this->count]=x;
    this->count++;
    return true;
}
void NumberList::Print()
{
    for(int i=0;i<this->count;i++)
    printf("%d ",this->numbers[i]);
    printf("\n");
}

void NumberList::Sort()
{
    for(int i=0;i<this->count;i++)
        for(int j=0;j<this->count-1;j++)
            if(this->numbers[j]>this->numbers[j+1])
                {
                    int aux=this->numbers[j];
                    this->numbers[j]=this->numbers[j+1];
                    this->numbers[j+1]=aux;
                }
}
