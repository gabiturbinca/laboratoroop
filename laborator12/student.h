#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "materie.h"
using namespace std;

class student
{
private:
    string nume;
    string matricol;
    string prog;
public:
    bool operator<(const student &other)const
    {
        return nume<other.nume;
    }
    student(string S,string t,string u)
    {
        nume=S;
        matricol=t;
        prog=u;
    }
    string getnume()
    {
        return nume;
    }
    string getsp()
    {
        return prog;
    }
    string getmatricol()
    {
        return matricol;
    }
};
