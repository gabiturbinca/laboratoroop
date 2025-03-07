#include "students.h"

int cmpname(student a,student b)
{
    char *x=a.getname(),*y=b.getname();
    return strcmp(x,y);
}
int cmpmathgrade(student a,student b)
{
    float x=a.getmath(),y=b.getmath();
    if(x==y)
        return 0;
    if(x<y)
        return -1;
    return 1;
}
int cmpavggrade(student a,student b)
{
    float x=a.getavg(),y=b.getavg();
    if(x==y)
        return 0;
    if(x<y)
        return -1;
    return 1;
}
int cmphisgrade(student a,student b)
{
    float x=a.gethis(),y=b.gethis();
    if(x==y)
        return 0;
    if(x<y)
        return -1;
    return 1;
}
int cmpenggrade(student a,student b)
{
    float x=a.geteng(),y=b.geteng();
    if(x==y)
        return 0;
    if(x<y)
        return -1;
    return 1;
}

