#include <fstream>
#include <iostream>
#include <map>
#include <queue>
using namespace std;
ifstream fin("date.in");

map <string ,int> mymap;
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
    string delim=",.?! ";
    int pozd=0,pozl=0;
    while(true)
    {
        pozl=s.find_first_not_of(delim,pozd);
        pozd=s.find_first_of(delim,pozl);
        if(pozl!=string::npos)
        {
            string aux=s.substr(pozl,pozd-pozl);
            aux=tolower(aux);
            mymap[aux]++;
        }
        else
            break;
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

