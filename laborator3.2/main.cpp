#include "Canvas.h"
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
using namespace std;

int main()
{

    Canvas a(10,10);
    a.DrawRect(2,2,5,5,'a');
    a.Print();
    Canvas b(5,5);
    b.DrawRect(2,2,4,4,'b');
    b.Print();
    a.FillCircle(4,4,3,'u');
    a.Print();
    Canvas c(20,20);
    c.DrawCircle(5,5,3,'p');
    c.Print();
    c.DrawLine(1,3,4,2,'o');
    c.Print();
    a.Clear();
    a.Print();
    a.FillRect(1,1,3,5,'k');
    a.Print();
    a.DrawLine(1,6,5,1,'l');
    a.Print();
    a.DrawRect(1,1,3,4,'i');
    a.Print();
    a.SetPoint(1,1,'o');
    a.Print();
    return 0;
}
