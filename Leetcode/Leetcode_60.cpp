/*
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <stdlib.h>
#include <math.h>
using namespace std;

//n表示数2的最大值， k表示第k个，step表示当前DFS所在树的层数
///*
map<int, int> Jiecheng = { { 0, 1 }, { 1, 1 }, { 2, 2 }, { 3, 6 }, { 4, 24 }, { 5, 120 }, { 6, 720 }, { 7, 5040 }, { 8, 40320 }, { 9, 362880 } };
void DFS(int n, int k, int step, int &cnt, string &s)
{
	if (step == n) return;
	for (int i = 1; i <= n; i++)
	{
		int flag = 0;
		for (char j : s)
		{
			if (i == (j - 48))
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1) continue;
		s = s + to_string(i);
		if (cnt + Jiecheng[n - step - 1] >= k) DFS(n, k, step + 1, cnt, s);
		else cnt = cnt + Jiecheng[n - step - 1];
		if (s.length() == n) break;
		s.pop_back();
	}
	return;
}


string getPermutation(int n, int k) {
	string s;
	int cnt = 0;
	DFS(n, k, 0, cnt, s);
	return s;
}
*/
