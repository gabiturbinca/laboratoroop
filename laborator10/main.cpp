#include <iostream>
#include <exception>
#include "myarray.h"

using namespace std;

class exceptie1 : public exception
{
    virtual const char* what() const throw()
    {
        return "Impartire la 0!";
    }
};

class exceptie2 : public exception
{
    virtual const char* what() const throw()
    {
        return "Indexul este inafara domeniului!";
    }
};

int main()
{

    return 0;
}
