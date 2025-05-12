#include <bits/stdc++.h>

using namespace std;
template <class T1,class T2>
struct mytuple
{
    T1 key;
    T2 val;
    int id;
};
template <class T1,class T2>
class Map
{
private:
    mytuple<T1,T2> v[100];
    int sz;
public:
    Map ()
    {
        sz=0;
    }
    mytuple<T1,T2>* begin()
    {
        return &v[0];
    }
    mytuple<T1,T2>* end()
    {
        return &v[sz];
    }
    T2& operator [](T1 cheie)
    {
        for(int i=0;i<sz;i++)
            if(v[i].key==cheie)
            return v[i].val;
        sz++;
        v[sz-1].key=cheie;
        v[sz-1].id=sz-1;
        return v[sz-1].val;
    }
    void Set(T1 cheie,T2 val)
    {
        for(int i=0;i<sz;i++)
            if(v[i].key==cheie)
            {
                v[i].val=val;
                return;
            }
        sz++;
        v[sz-1].key=cheie;
        v[sz-1].id=sz-1;
        v[sz-1].val=val;
    }
    bool Get(const T1& key, T2& val)
    {
        for(int i=0;i<sz;i++)
            if(v[i].key==key)
        {
            val=v[i].val;
            return true;
        }
        return false;
    }
    int Count()
    {
        return sz;
    }
    bool Delete(const T1& key)
    {
        for(int i=0;i<sz;i++)
            if(v[i].key==key)
        {
            for(int j=i;j<sz-1;j++)
                {
                    v[j]=v[j+1];
                    v[j].id--;
                }
            sz--;
            return true;
        }
        return false;
    }
    bool Includes(const Map<T1,T2>& othermap)
    {
        for(int i=0;i<othermap.sz;i++)
            {
                bool fnd=false;
                for(int j=0;j<sz;j++)
                {
                    if(v[j].key==othermap.v[i].key)
                        fnd=true;
                }
                if(!fnd)
                    return fnd;
            }
        return true;
    }
    void Clear()
    {
        sz=0;
    }
};
int main()
{

    Map<int, const char *> m;
    Map<int, const char *> m2;
    Map<int, const char *> m3;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m.Set(10,"ulala");
    const char * x;
    cout<<m[10]<<'\n';
    m.Get(30,x);
    cout<<x<<'\n';
    m[40]="hoho";
    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m.Delete(20);
    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m3[10]="mama";
    m2[50]="tata";
    cout<<boolalpha<<m.Includes(m3)<<'\n';
    cout<<boolalpha<<m.Includes(m2)<<'\n';
    return 0;
}
