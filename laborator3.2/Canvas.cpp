#include "Canvas.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
Canvas::Canvas(int width,int height)
{
    mat=new char*[height];
    for(int i=0;i<height;i++)
        mat[i]=new char[width];
    for(int i=0;i<height;i++)
        for(int j=0;j<width;j++)
        mat[i][j]=' ';
    w=width;
    h=height;
}
void Canvas::DrawRect(int left,int top,int right,int bottom,char ch)
{
    for(int i=left;i<=right;i++)
        this->mat[top][i]=this->mat[bottom][i]=ch;
    for(int i=top;i<=bottom;i++)
        this->mat[i][left]=this->mat[i][right]=ch;
}
void Canvas::FillRect(int left,int top,int right,int bottom,char ch)
{
    for(int i=top;i<=bottom;i++)
        for(int j=left;j<=right;j++)
        this->mat[i][j]=ch;
}
void Canvas::SetPoint(int x,int y,char ch)
{
    this->mat[x][y]=ch;
}
void Canvas::Clear()
{
    for(int i=0;i<this->h;i++)
        for(int j=0;j<this->w;j++)
        this->mat[i][j]=' ';
}
void Canvas::Print()
{
    for(int i=0;i<this->h;i++,printf("\n"))
        for(int j=0;j<this->w;j++)
        printf("%c ",this->mat[i][j]);
}
void Canvas::DrawCircle(int x,int y,int ray, char ch)
{
    for(int i=0;i<this->h;i++)
        for(int j=0;j<this->w;j++)
    {
        if(abs(ray*ray-(x-i)*(x-i)-(y-j)*(y-j))<=2*std::__lg(ray))
            this->mat[i][j]=ch;
    }
}
void Canvas::FillCircle(int x,int y,int ray, char ch)
{
    for(int i=0;i<this->h;i++)
        for(int j=0;j<this->w;j++)
    {
        if((x-i)*(x-i)+(y-j)*(y-j)<=ray*ray+2*std::__lg(ray)+1)
            this->mat[i][j]=ch;
    }
}
void Canvas::DrawLine(int x1,int x2,int y1,int y2,char ch)
{
    if(x1==x2)
        {
            for(int i=std::min(y1,y2);i<=std::max(y1,y2);i++)
                this->mat[x1][i]=ch;
            return;
        }
    if(x1>x2)
    {
        std::swap(x1,x2);
        std::swap(y1,y2);
    }
    double m=(double)(y2-y1)/(double)(x2-x1);
    for(int i=x1;i<=x2;i++)
        mat[i][(int)(double(m*(i-x1))+(double)y1)]=ch;
}
