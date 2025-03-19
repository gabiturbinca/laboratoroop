#include "Sort.h"
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
using namespace std;

int main()
{
    Sort v("32,21,456");
    v.Print();
    Sort c(3,1,2,3);
    c.Print();
    Sort d(2,3,4);
    d.Print();
    int f[]={6,4,3,4,5,6};
    Sort e(f,6);
    e.Print();
    e.InsertSort();
    e.Print();
    int u[]={1,2,3,4,5,6};
    Sort g(u,6);
    g.BubbleSort();
    g.Print();
    Sort h(7,1,9,2,3,4,6,1);
    h.QuickSort();
    h.Print();
    return 0;
}
