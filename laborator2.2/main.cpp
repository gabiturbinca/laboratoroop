#include "students.h"
#include "gfunctii.h"

int main()
{
    student a,b,c;
    a.seteng(7);
    a.setmath(0);
    a.sethis(3);
    b.seteng(1);
    b.setmath(9.25);
    b.sethis(3.78);
    printf("%f\n",a.geteng());
    printf("%f\n",b.geteng());
    printf("%f\n",b.gethis());
    printf("%f\n",b.getmath());
    printf("%f\n",b.getavg());
    c=b;
    c.setmath(5.67);
    a.setname("awooga");
    printf("%s\n",a.getname());
    a.setname("mimi");
    printf("%s\n",a.getname());
    c.setname("zappy");
    b.setname("andra");
    printf("%d\n",cmpname(a,c));
    printf("%d\n",cmpname(a,b));
    printf("%d\n",cmpavggrade(a,c));
    printf("%d\n",cmpavggrade(c,a));
    printf("%d\n",cmpmathgrade(c,b));
    printf("%d\n",cmpenggrade(b,a));
    printf("%d\n",cmphisgrade(a,a));
    return 0;
}
