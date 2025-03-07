#include "students.h"

void student::seteng(float val)
{
    this->enggrade=val;
}
float student::geteng()
{
    return this->enggrade;
}
void student::setmath(float val)
{
    this->mathgrade=val;
}
float student::getmath()
{
    return this->mathgrade;
}
void student::sethis(float val)
{
    this->hisgrade=val;
}
float student::gethis()
{
    return this->hisgrade;
}
float student::getavg()
{
    float sum=0;
    sum+=this->enggrade;
    sum+=this->mathgrade;
    sum+=this->hisgrade;
    sum/=3.0;
    return sum;
}
void student::setname(char *nume)
{
    this->name=nume;
}
char *student::getname()
{
    return this->name;
}
