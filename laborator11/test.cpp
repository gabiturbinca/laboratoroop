#include "pch.h"
#include "badsort.h"
#include <algorithm>
#include <map>
TEST(Sortatcorect, increasing) {
	
	for (int n = 4; n <= 10; n++)
	{
		vector <int> v(n, 0);
		for (int i = 0; i < n; i++)
			v[i] = rand() % 100000;
		Sort(v);
		for (int i = 0; i < v.size() - 1; i++)
		{
			EXPECT_TRUE(v[i] < v[i + 1]);
		}
	}
}
TEST(Sortat, samevect) {

	for (int n = 4; n <= 20; n++)
	{
		vector <int> v(n, 0);
		for (int i = 0; i < n; i++)
			v[i] = rand() % 100000;
		map <int, int> f;
		vector <int> u = v;
		int nr = v.size();

		for (int i : v)
			f[i]++;
		Sort(v);
		EXPECT_TRUE(v.size() == nr);
		for (int i : v)
		{
			f[i]--;
			EXPECT_TRUE(f[i] >= 0);
		}
		for (int i : u)
		{
			EXPECT_TRUE(f[i] == 0);
		}
	}
}