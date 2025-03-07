#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

class student
{
private:
    char *name;
    float mathgrade;
    float enggrade;
    float hisgrade;
public:
    void setmath(float x);
    void seteng(float x);
    void sethis(float x);
    void setname(char *nume);
    float getavg();
    float getmath();
    float geteng();
    float gethis();
    char *getname();
};
