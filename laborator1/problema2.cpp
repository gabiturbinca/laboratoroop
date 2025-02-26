
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
char mat[100][100];
int mar[100];
char prop[1005];
char aux[1005];
int lene(char *s)
{
    int val=0;
    while(s[val]!='\0')
        val++;
    return val;
}
bool alfab(char *a,char *b,int val)
{
    for(int i=0;i<val;i++)
        if(a[i]<b[i])
        return 1;
    else
        if(a[i]>b[i])
        return 0;
    return 1;
}
bool cmp(int i,int j)
{
    return mar[i]>mar[j]||mar[i]==mar[j]&&alfab(mat[i],mat[j],mar[i]);
}
void schimb(int i,int j)
{
    int v1=mar[i];
    int v2=mar[j];
    for(int k=0;k<=v1;k++)
        aux[i]='\0';
    for(int k=0;k<=v1;k++)
        aux[k]=mat[i][k];
    for(int k=0;k<=max(v1,v2);k++)
        mat[i][k]='\0';
    for(int k=0;k<=v2;k++)
        mat[i][k]=mat[j][k];
    for(int k=0;k<=max(v1,v2);k++)
        mat[j][k]='\0';
    for(int k=0;k<=v1;k++)
        mat[j][k]=aux[k];
    swap(mar[i],mar[j]);
}
int main()
{
	char x;
	int nr=0;

	fgets(prop,1000,stdin);

    for(int i=0;i<lene(prop);i++)
    {
        if (prop[i]==' ')
            continue;
        nr++;
        int sz=0;
        while(i<lene(prop)&&prop[i]!=' ')
        {
            mat[nr][sz]=prop[i];
            sz++;
            i++;
        }
        mar[nr]=sz;
    }
    mat[nr][mar[nr]-1]='\0';
    for(int i=1;i<=nr;i++)
        for(int j=1;j<nr;j++)
        if(!cmp(j,j+1))
    {
        schimb(j,j+1);
    }
    for(int i=1;i<=nr;i++)
        printf("%s\n",mat[i]);
}
