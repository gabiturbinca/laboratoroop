#pragma once
#include <iostream>
#include <vector>

using namespace std;
template <class T>
void mysort(vector <T>& a);
template <class T>
void mysort(vector <T>& a)
{
    for (int i = 0; i < a.size() - 1; i++)
    {
        for (int j = i; j < a.size() - 2; j++)
            if (a[i] < a[j])
                swap(a[i], a[j + 1]);
    }
    for (int i = 0; i < a.size() / 2; i++)
        swap(a[i], a[a.size() - i -1]);
    a.pop_back();
    sort(a.begin(),a.end());
    if(a.size()%2==0)
        swap(a[0],a[a.size()-1]);
};
