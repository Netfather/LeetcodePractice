
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

void BFS_search(vector<int> & candidates, int search_index,int target, vector<int> &pre_sol, vector<vector<int>> &res)
{
	int flag = 0;
	if (target == 0)
	{
		for (vector<int> check : res)
		{
			if (pre_sol == check)
			{
				flag = 1;
				break;
			}
		}
		if (flag = 0) res.push_back(pre_sol);
		return;
	}
	for (int i = search_index; i < candidates.size(); i++)
	{
		if (target - candidates[i] < 0) return;
		else
		{
			pre_sol.push_back(candidates[i]);
			BFS_search(candidates, i + 1, target - candidates[i], pre_sol, res);
			pre_sol.pop_back();
		}
	}
	return;
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<int> pre_sol;
	vector<vector<int>> res;
	if (target <= 0 || candidates.size() == 0) return res;

	sort(candidates.begin(), candidates.end());
	BFS_search(candidates, 0, target, pre_sol, res);
	return res;
}

int main()
{
	vector<vector<int>> res;
	vector<int> candidates = { 10, 1, 2, 7, 6, 1, 5 };
	res = combinationSum2(candidates, 8);
	cout << res.size() << endl;
	if (!res.empty()) cout << res[0].size() << endl;
	system("Pause");

	return 0;

	return 0;
}

*/