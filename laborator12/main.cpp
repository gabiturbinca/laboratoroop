#include <iostream>
#include "student.h"
#include "materie.h"
#include "catalog.h"
using namespace std;

int main()
{
    catalogen a;
    student b("alex","001","ro");
    a.adaugstud(b);
    mate *x;
    rom *y;
    a.putmat(x);
    a.putmat(y);
    a.putgrade(b,x,10);
    a.putgrade(b,y,5);
    cout<<a.getmean(b)<<'\n';
    student c("ion","0020","en");
    a.adaugstud(c);
    a.putgrade(c,x,5);
    a.putgrade(c,y,2);
    cout<<a.getmean(c)<<'\n';
    a.getrank();
    a.filter([&](student alfa){return a.getmean(alfa)>5;});
    return 0;
}
