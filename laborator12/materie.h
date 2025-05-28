#pragma once
#include <string>
#include <iostream>

using namespace std;

class materie
{
protected:
    string nume;
    string tip;
    int nrcred;
public:
    virtual string getnume()=0;
};
class mate:public materie
{
public:
    mate()
    {
        nume="mate";
        tip="obl";
        nrcred=6;
    }
    ~mate()
    {
        cout<<"s-a terminaaaat";
    };
    string getnume()
    {
        return "mate";
    }
};
class rom:public materie
{
public:
    rom()
    {
        nume="rom";
        tip="obl";
        nrcred=3;
    }
    ~rom()
    {
        cout<<"s-a terminaaaat";
    };
    string getnume()
    {
        return "rom";
    }
};
