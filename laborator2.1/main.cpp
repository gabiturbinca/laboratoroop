#include "NumberList.h"

int main()
{
    NumberList a;
    a.Init();
    a.Add(3);
    a.Print();
    a.Add(4);
    a.Add(2);
    a.Print();
    a.Sort();
    a.Print();
    for(int i=1;i<=9;i++)
        a.Add(i);
    a.Print();
    a.Sort();
    a.Print();
    return 0;
}
