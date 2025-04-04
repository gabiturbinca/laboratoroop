//#include "Car.h"
#include "BMW.h"

BMW::BMW()
{
    fuelcap=103;
    fuelcom=521;
    speed[0]=12;
    speed[1]=11;
    speed[2]=11;
}

int BMW::gettime(int len,Weather cond)
{
    return len/speed[cond];
}

