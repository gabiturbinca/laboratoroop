#include <iostream>

using namespace std;
float operator"" _Kelvin(const char *x)
{
    int i=0;
    float val=0;
    while(x[i]!='\0')
    {
        val=val*10+x[i]-'0';
        i++;
    }
    return val-273.15;
}

float operator"" _Fahrenheit(const char *x)
{
    int i=0;
    float val=0;
    while(x[i]!='\0')
    {
        val=val*10+x[i]-'0';
        i++;
    }
    return (val-32)*5/9;
}
int main()
{
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    cout<<a<<'\n'<<b;
    return 0;
}
