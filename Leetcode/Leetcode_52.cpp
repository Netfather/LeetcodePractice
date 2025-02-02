
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

bool check(vector<string> &tempres, int k, int step, int n) //k表示当前行放入皇后的是k列
{
	int i = step;
	int j = k;
	int l = k;
	while (step > 0 && --i >= 0)
	{
		if (tempres[i].at(k) == 'Q') return false;
		if (--j >= 0 && tempres[i].at(j) == 'Q') return false;
		if (++l < n && tempres[i].at(l) == 'Q') return false;
	}
	return true;
}

void DFS(int &cnt, vector<string> &tempres, int step, int n)
{
	if (step == n)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		//构造tempres
		string tmp(n, '.');
		tmp.at(i) = 'Q';
		tempres.push_back(tmp);
		if (check(tempres, i, step, n)) DFS(cnt, tempres, step + 1, n);
		tempres.pop_back();
	}
	return;
}

int totalNQueens(int n) {
	if (n == 1) return 1;
	if (n < 4) return 0;
	int cnt = 0;
	vector<string> tempres;
	DFS(cnt, tempres, 0, n);
	return cnt;
}

*/

