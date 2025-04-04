#pragma once
#include "Circuit.h"
#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
void Circuit::AddCar(Car *c)
{
    masini[nrm++]=c;
    endtimes[nrm-1]=-1;
}
void Circuit::SetLength(int val)
{
    dist=val;
}
void Circuit::SetWeather(Weather a)
{
    this->condition=a;
}
Circuit::Circuit()
{
    nrm=0;
}
void Circuit::Race()
{
    for(int i=0;i<nrm;i++)
    {
        endtimes[i]=masini[i]->gettime(dist,condition);
    }
}
void Circuit::ShowFinalRanks()
{
    std::vector <std::pair<int,int>> a;
    for(int i=0;i<nrm;i++)
        if(endtimes[i]!=-1)
    a.push_back({endtimes[i],i});
    sort(a.begin(),a.end());
    int poz[100];
    for(int i=0;i<a.size();i++)
    poz[a[i].second]=i+1;
    for(int i=0;i<nrm;i++)
        if(endtimes[i]==-1)
        std::cout<<a.size()+1;
    else
        std::cout<<poz[i]<<' ';
    std::cout<<'\n';
}
void Circuit::ShowWhoDidNotFinish()
{
    this->Race();
    for(int i=0;i<nrm;i++)
    {
        if(endtimes[i]==-1)
            printf("%d\n",i);
    }
}
