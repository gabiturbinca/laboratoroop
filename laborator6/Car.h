#pragma once
#include "Weather.h"
class Car
{
protected:
    int fuelcap;
    int fuelcom;
    int speed[3];
public:
    virtual int gettime(int len,Weather cond)=0;

};
