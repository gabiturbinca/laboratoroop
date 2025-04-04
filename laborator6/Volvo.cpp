//#include "Car.h"
#include "Volvo.h"
Volvo::Volvo()
{
    fuelcap=10;
    fuelcom=5;
    speed[0]=1;
    speed[1]=1;
    speed[2]=1;
}

int Volvo::gettime(int len,Weather cond)
{
    return len/speed[cond];
}
