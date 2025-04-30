#include <fstream>
#include <iostream>
#include <map>
#include <queue>
using namespace std;
ifstream fin("date.in");

map <string ,int> mymap;
bool isletter(char x)
{
    if('a'<=x&&x<='z')
        return 1;
    if('A'<=x&&'Z'>=x)
        return 1;
    return 0;
}
string tolower(string x)
{
    string u;
    for(char c:x)
    {
        if('a'<=c&&c<='z')
            u.push_back(c);
        if('A'<=c&&c<='Z')
            u.push_back(c-'A'+'a');
    }
    return u;
}
class compare
{
public:
    bool operator()(string &a,string &b)
    {
        return mymap[a]<mymap[b]||mymap[a]==mymap[b]&&a.compare(b)>0;
    }
};
int main()
{
    string s;
    string line;
    while(getline(fin,line))
    {
        s=s+line;
    }
    for(int i=0;i<s.size();i++)
    {
        if(i<s.size()&&isletter(s[i]))
        {
            string aux;
            while(isletter(s[i]))
            {
                aux.push_back(s[i]);
                i++;
            }
            aux=tolower(aux);
            mymap[aux]++;
        }
    }
    priority_queue <string,vector <string>,compare> mypq;
    for(auto p:mymap)
        mypq.push(p.first);
    while(!mypq.empty())
    {
        cout<<mypq.top()<<" => "<<mymap[mypq.top()]<<'\n';
        mypq.pop();
    }
    return 0;
}

