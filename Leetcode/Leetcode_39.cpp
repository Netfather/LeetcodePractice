
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

// 候选者列表，目标，候补index, 当前解
void rec(vector<int>& candidates, int target, int index_can, vector<int>& sol_pre, vector<vector<int>> &res)
{
	if (target == 0)
	{
		res.push_back(sol_pre);
		return;
	}
	int length = candidates.size();
	for (int i = index_can; i < length;i++)
	{
		if (target - candidates[i] < 0) return;
		else
		{
			sol_pre.push_back(candidates[i]);
			rec(candidates, target - candidates[i], i, sol_pre, res);
			sol_pre.pop_back;
		}
	}
	return;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> res;
	vector<int> sol_pre;
	rec(candidates, target,0, sol_pre,res);
	return res;
}

int main()
{
	vector<vector<int>> res;
	vector<int> candidates = { 2, 3, 6, 7 };
	res = combinationSum(candidates, 7);
	cout << res.size() << endl;
	if (!res.empty()) cout << res[0].size() << endl;
	system("Pause");

	return 0;
}

*/