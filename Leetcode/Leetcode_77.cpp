
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

void DFS(vector<vector<int>> &res, vector<int> &tempres, int step, int k, int n )
{
	if (step == k)
	{
		res.push_back(tempres);
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!tempres.empty() && i <= tempres[tempres.size() - 1]) continue;
		tempres.push_back(i);
		DFS(res, tempres, step + 1, k, n);
		tempres.pop_back();
	}
}

vector<vector<int>> combine(int n, int k) {
	vector < vector < int >> res;
	vector<int > tempres;
	DFS(res, tempres, 0, k, n);
	return res;
}

int main()
{
	vector < vector < int >> res;
	res = combine(3, 3);
	for (auto k : res)
	{
		for (auto m : k)
		{
			cout << m<< "  ";
		}
		cout << endl;
	}
	system("Pause");
	return 0;
}
*/