#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <functional>
#include "student.h"
using namespace std;
class Catalog
{
protected:
    vector <student> mystud;
    vector <materie *>mymat;
    map<student,map<materie*,float>> note;
public:
    void adaugstud(student a)
    {
        mystud.push_back(a);
    };
    void getgrades(student a)
    {
        for(auto p:note[a])
        {
            cout<<p.first->getnume()<<": ";
            cout<<p.second;
            cout<<'\n';
        }
    }
    float getmean(student a)
    {
        float sz=note[a].size();
        float sum=0;
        for(auto p:note[a])
            sum+=p.second;
        return sum/sz;
    }
    void putgrade(student a,materie* b,float c)
    {
        note[a][b]=c;
    }
    void putmat(materie *a)
    {
        mymat.push_back(a);
    }
    virtual void getrank()=0;
    void filter(const function<bool (student)>f)
    {
        for(auto p:mystud)
            if(f(p)==1)
        {
            cout<<p.getnume()<<'\n';
        }
    }
};
class catalogro:public Catalog
{
public:
    void getrank()
    {
        vector <pair<float,student>> gets;
        for(auto p:note)
            gets.push_back({getmean(p.first),p.first});
        sort(gets.begin(),gets.end());
        reverse(gets.begin(),gets.end());
        for(auto p:gets)
            cout<<p.second.getnume()<<' '<<p.first<<'\n';
    }
};
class catalogen:public Catalog
{
public:
    void getrank()
    {
        vector <pair<float,student>> gets;
        for(auto p:note)
            gets.push_back({getmean(p.first),p.first});
        sort(gets.begin(),gets.end());
        for(auto p:gets)
            cout<<p.second.getnume()<<' '<<p.second.getmatricol()<<' '<<p.first<<'\n';
    }
};
