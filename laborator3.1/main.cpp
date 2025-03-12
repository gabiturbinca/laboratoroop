#include "Math.h"
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
using namespace std;

int main()
{
    printf("%d\n",Math::Add(3,5));
    printf("%f\n",Math::Add(3.3,5.6));
    printf("%s\n",Math::Add("2004","8006"));
    printf("%d\n",Math::Add(3,5,9));
    printf("%d\n",Math::Add(5,1,2,3,4,5));
    printf("%f\n",Math::Add(3.1,5.2,3.9));
    printf("%d\n",Math::Mul(3,9));
    printf("%d\n",Math::Mul(3,9,9));
    printf("%f\n",Math::Mul(3.3,9.3));
    printf("%f\n",Math::Mul(3.3,9.3,3.3));
    printf("%s\n",Math::Add("8004","8006"));
    printf("%s\n",Math::Add("1009004","8006"));

    return 0;
}
